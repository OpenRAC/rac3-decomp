/* func_003A8500 (frontbin): near miss, 48 differences (tools/check.py) with its file's flags
   (src/frontbin/3A8308.c, -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as),
   measured on upstream 878f66d7 (NM-R14, 2026-11-22; on upstream 6de86dfe FE-1's draft measured
   62 and NM-FE5's form 48). All 48 come from one tool limit; the C is
   otherwise byte-exact.

   It binds the SIF RPC client at D_001D4B08 to server 0x11 (func_00122630; a negative result hangs),
   polls func_00122A10 until it is free, retries after a 0x10000-count delay while the client's word
   at +0x24 is 0, then calls function 2 for three words, stores them, and clears the 64 16-byte
   entries of D_0022DF20 (the tail is func_003A8630's body). Compiled code, not hand-written. Its jr
   delay slot (addiu $sp) is the 4-byte LINKER_REMNANT func_003A8628, which goes when this becomes C.
   Its boot_elf twin func_003A8900 is a 300-byte LINKER_REMNANT.

   The client is declared small data, `__attribute__((section(".sdata")))`
   (docs/wiki/Matching-Patterns.md, "Declarations and address forms (round 3)"): gcc then emits one
   `la` macro at each use, which Ps2EeAs expands to retail's adjacent lui/addiu; every larger or
   unsized declaration lets gcse/cse keep the address in $s0 (73). `while (1) { ... break; }` gives
   retail's delay-slot fill. One counter `i` for the delay loop and the clear loop gives retail's
   registers in the delay loop ($a2 counter, -1 in $v0); the clear loop written with an index
   (`D_0022DF20[i * 4]`) and the stores in this order give retail's registers after the RPC call.

   What still differs: the poll loop `while (func_00122A10(&D_001D4B08) != 0)` holds the `la` macro.
   tools/asm_filter.py's insn_count cannot count an `la`, so the filter leaves that loop to Ps2EeAs,
   which pads every loop to 7 words where retail has 6; every later word shifts (48). With insn_count
   counting such an `la` as 2 words under @ps2as reorder mode (a local diagnostic, not committed:
   `if m and m.group(1) == "la" and ps2as and not noreorder: n += 2; continue` before the
   SIMPLE_OPS test), this C is 1 difference: the epilogue's `addiu $sp`, which is the remnant
   func_003A8628. As a diagnostic, that filter change with this C in 3A8308.c in place of the
   INCLUDE_ASM and the LINKER_REMNANT (and tools/resolve_symbols.py --target frontbin) gave the full
   build's MATCH for frontbin, boot_elf and i5bootn; the same tree with the stock filter fails
   frontbin's check_match. An early `.extern D_001D4B08, 40` hint does not help (48), nor does
   --mode S or N. This needs a tools/ change, which a match batch does not make. */

typedef struct { u8 pad0[0x24]; s32 serve; } Cd_3A8500;
extern Cd_3A8500 D_001D4B08 __attribute__((section(".sdata")));
extern s32 D_001D4B00;
extern s32 D_001D4B04;
extern s32 D_001D4B30;
extern s32 D_001D4B34;
extern s32 D_001D4B38;
extern s32 D_0022DF20[256];
extern void func_00121FE8(s32);
extern s32 func_00122630(void *, s32, s32);
extern s32 func_00122A10(void *);
extern s32 func_00122810(void *, s32, s32, void *, s32, void *, s32, void *, void *);
void func_003A8500(void) {
    s32 r[4];
    s32 i;
    func_00121FE8(0);
    while (1) {
        if (func_00122630(&D_001D4B08, 0x11, 1) < 0) {
            while (1) {
            }
        }
        while (func_00122A10(&D_001D4B08) != 0) {
        }
        if (D_001D4B08.serve != 0) {
            break;
        }
        for (i = 0xFFFF; i != -1; i--) {
        }
    }
    func_00122810(&D_001D4B08, 2, 0, 0, 0, r, 0x10, 0, 0);
    D_001D4B00 = r[0];
    D_001D4B04 = r[1];
    D_001D4B34 = 0;
    D_001D4B30 = D_001D4B00;
    D_001D4B38 = r[2];
    for (i = 0; i < 0x40; i++) {
        D_0022DF20[i * 4] = 0;
        D_0022DF20[i * 4 + 1] = 0;
    }
}
