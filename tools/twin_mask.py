"""twin_mask.py: relocation-masked words of a MIPS (EE) function, for comparing one function's code
across programs and games (tools/sister_twins.py, docs/contributing/sister-twins.md).

masked(code) keeps every word of the function except the fields a relocation fills, so two copies
of one function compare equal whatever their relocations resolve to. The same rule runs on both
sides of a comparison, from the raw bytes alone (no symbols, no relocation tables):

  * j / jal: the 26-bit target;
  * lui: the immediate, when the register it sets reaches the base of a load/store or the source of
    addi/addiu/daddi/daddiu, directly or through addu/daddu/or/add/dadd, before it is overwritten
    (an address %hi). A lui whose value only feeds mtc1, ori or other arithmetic is a constant and
    stays;
  * the imm16 of a load/store/addi/addiu/daddi/daddiu whose base or source is such a %hi register
    (the %lo half), or is $gp (a gp_rel / sda slot).

The %hi registers are followed along the function's control flow, delay slots included: a register
holds a lui's value when it does on some path (may-reach), and a call clobbers the caller-saved
registers after its delay slot. Branch offsets, registers, struct offsets and constants are kept.

check_mask() measures the rule against splat's relocation annotations in the generated assembly
(%hi, %lo, %gp_rel, _sda, j/jal operands, $gp bases): `tools/sister_twins.py --check-mask`.
"""
import glob
import os
import re
import struct

LOADSTORE = frozenset([0x1A, 0x1B, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
                       0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x31, 0x35, 0x36, 0x37, 0x39,
                       0x3D, 0x3E, 0x3F])
ADDIMM = frozenset([0x08, 0x09, 0x18, 0x19])          # addi addiu daddi daddiu
# stores, and loads into FPU/VU0 registers: no general register written
STORE_NOWRITE = frozenset([0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x39, 0x3D, 0x3E, 0x3F, 0x1F,
                           0x31, 0x35, 0x36])
PROPAGATE = frozenset([0x21, 0x2D, 0x25, 0x20, 0x2C])  # SPECIAL addu daddu or add dadd
SPECIAL_NO_RD = frozenset([0x08, 0x0C, 0x0D, 0x0F, 0x11, 0x13])   # jr syscall break sync mthi mtlo
WRITE_RT = frozenset([0x0A, 0x0B, 0x0C, 0x0D, 0x0E])   # slti sltiu andi ori xori
CALLER_SAVED = frozenset([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 31])
LIKELY = frozenset([0x14, 0x15, 0x16, 0x17])
GP = 28


def words_of(code):
    """The little-endian 32-bit words of code (a trailing partial word is dropped)."""
    return struct.unpack("<%dI" % (len(code) // 4), code[:len(code) // 4 * 4])


def key_of(words):
    return struct.pack("<%dI" % len(words), *words)


def strip_padding(words):
    """Drop trailing zero words (alignment padding: projects differ on whether a function's size
    counts it), keeping at least one word."""
    k = len(words)
    while k > 1 and words[k - 1] == 0:
        k -= 1
    return words[:k]


def _successors(w):
    """Instruction-level successors (with MIPS delay slots) and the delay slots of calls."""
    n = len(w)
    succ = [None] * n
    call_slot = set()
    for i, x in enumerate(w):
        if succ[i] is not None:
            continue
        op = x >> 26
        rs, rt = (x >> 21) & 31, (x >> 16) & 31
        fn = x & 63
        imm = x & 0xFFFF
        off = imm - 0x10000 if imm & 0x8000 else imm
        kind = None
        if op in (0x04, 0x05, 0x06, 0x07) or op in LIKELY:
            kind = "b" if (op == 0x04 and rs == 0 and rt == 0) else ("bl" if op in LIKELY else "bc")
        elif op == 0x01 and rt in (0, 1, 2, 3, 0x10, 0x11, 0x12, 0x13):
            kind = "bl" if rt in (2, 3, 0x12, 0x13) else ("call" if rt in (0x10, 0x11) else "bc")
            if rt == 1 and rs == 0:
                kind = "b"
        elif op in (0x11, 0x12) and rs == 0x08:
            kind = "bl" if rt & 2 else "bc"
        elif op == 0x02:
            kind = "exit"                      # j: a tail call
        elif op == 0x03:
            kind = "call"
        elif op == 0 and fn == 0x08:
            kind = "exit" if rs == 31 else "jtab"
        elif op == 0 and fn == 0x09:
            kind = "call"
        if kind is None or i + 1 >= n:
            succ[i] = [i + 1] if i + 1 < n else []
            continue
        tgt = i + 1 + off
        tg = [tgt] if 0 <= tgt < n else []
        nxt = [i + 2] if i + 2 < n else []
        succ[i] = [i + 1]
        if kind == "b":
            succ[i + 1] = tg
        elif kind == "bc":
            succ[i + 1] = tg + nxt
        elif kind == "bl":
            succ[i] = [i + 1] + nxt
            succ[i + 1] = tg
        elif kind == "exit":
            succ[i + 1] = []
        elif kind == "jtab":
            succ[i + 1] = list(range(i + 2, n))
        elif kind == "call":
            succ[i + 1] = nxt
            call_slot.add(i + 1)
    return succ, call_slot


def masked(code):
    """Relocation-masked words (a tuple of ints) of the function whose bytes are code."""
    w = words_of(code)
    n = len(w)
    if n == 0:
        return ()
    succ, call_slot = _successors(w)
    ins = [None] * n
    ins[0] = {}
    work = [0]
    reach = set()           # lui whose value reaches an address use
    lo = set()              # loads/stores/adds whose base or source holds such a value
    while work:
        i = work.pop()
        st = dict(ins[i])
        x = w[i]
        op = x >> 26
        rs, rt, rd = (x >> 21) & 31, (x >> 16) & 31, (x >> 11) & 31
        if op == 0x0F:
            if rt:
                st[rt] = frozenset([i])
        elif op in LOADSTORE or op in ADDIMM:
            if rs in st:
                reach |= st[rs]
                lo.add(i)
            if op not in STORE_NOWRITE:
                st.pop(rt, None)
        elif op == 0:
            f = x & 63
            if f in PROPAGATE:
                t = st.get(rs, frozenset()) | st.get(rt, frozenset())
                if t and rd:
                    st[rd] = t
                else:
                    st.pop(rd, None)
            elif f not in SPECIAL_NO_RD:
                st.pop(rd, None)
        elif op in WRITE_RT:
            st.pop(rt, None)
        elif op in (0x11, 0x12) and rs in (0x00, 0x01, 0x02):   # mfc1/dmfc1/cfc1, qmfc2/cfc2
            st.pop(rt, None)
        elif op == 0x1C:                                          # MMI: rd written
            st.pop(rd, None)
        elif op == 0x03:                                          # jal: ra written
            st.pop(31, None)
        if i in call_slot:
            for r in CALLER_SAVED:
                st.pop(r, None)
        for j in succ[i]:
            old = ins[j]
            if old is None:
                ins[j] = st
                work.append(j)
                continue
            new = None
            for r, s in st.items():
                o = old.get(r)
                if o is None or not s <= o:
                    if new is None:
                        new = dict(old)
                    new[r] = s | o if o else s
            if new is not None:
                ins[j] = new
                work.append(j)
    out = list(w)
    for i, x in enumerate(w):
        op = x >> 26
        if op in (0x02, 0x03):
            out[i] = x & 0xFC000000
        elif op == 0x0F and i in reach:
            out[i] = x & 0xFFFF0000
        elif (op in LOADSTORE or op in ADDIMM) and (i in lo or ((x >> 21) & 31) == GP):
            out[i] = x & 0xFFFF0000
    return tuple(out)


# ------------------------------------------------------------- the check against splat's asm
ASM_LINE = re.compile(r"/\*\s+[0-9A-F]+\s+([0-9A-F]{8})\s+([0-9A-F]{8})\s+\*/\s*(.*)")


def asm_function(lines):
    """-> (code bytes, relocated flags) of one splat .s function: each instruction's word and
    whether splat wrote a relocation for it (%hi, %lo, %gp_rel, _sda, a j/jal operand, a $gp base)."""
    words, relocated = [], []
    for ln in lines:
        if "endlabel" in ln:
            break
        m = ASM_LINE.search(ln)
        if not m:
            continue
        text = m.group(3)
        op = text.split()[0] if text else ""
        words.append(bytes.fromhex(m.group(2)))
        relocated.append("%hi" in text or "%lo" in text or "%gp_rel" in text or "_sda" in text
                         or op in ("jal", "j") or "($28)" in text or "($gp)" in text)
    return b"".join(words), relocated


def compare_mask(code, relocated):
    """-> per-word counts {masked_reloc, masked_plain, reloc_kept, plain} of masked(code) against
    the relocated flags. reloc_kept counts only words whose relocated field is not already zero."""
    c = dict(masked_reloc=0, masked_plain=0, reloc_kept=0, plain=0)
    for x, y, r in zip(words_of(code), masked(code), relocated):
        hidden = x != y
        if hidden and r:
            c["masked_reloc"] += 1
        elif hidden:
            c["masked_plain"] += 1
        elif r:
            if (x >> 26) in (2, 3) or (x & 0xFFFF):
                c["reloc_kept"] += 1
        else:
            c["plain"] += 1
    return c


def check_mask(asm_dir, pattern="boot_elf/nonmatchings/*/*.s"):
    """Runs compare_mask() over the splat functions under asm_dir: -> totals, with the number of
    functions and of functions whose mask equals the relocations, and up to 15 that do not."""
    tot = dict(masked_reloc=0, masked_plain=0, reloc_kept=0, plain=0, functions=0, agree=0)
    differ = []
    for p in sorted(glob.glob(os.path.join(asm_dir, pattern))):
        with open(p, encoding="utf-8", errors="replace") as f:
            code, relocated = asm_function(f)
        if not code:
            continue
        c = compare_mask(code, relocated)
        for k, v in c.items():
            tot[k] += v
        tot["functions"] += 1
        if c["masked_plain"] or c["reloc_kept"]:
            if len(differ) < 15:
                differ.append(os.path.basename(p))
        else:
            tot["agree"] += 1
    tot["examples"] = differ
    return tot
