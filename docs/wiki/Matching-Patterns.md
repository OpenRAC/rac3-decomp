> **Rule (2026-11-06):** matched C may not use `volatile`, inline asm (other than `__asm__(".extern X, N")` size hints), `#define` aliases or hardcoded addresses, except `volatile` where it describes the memory (AGENTS.md) and, since 2026-11-14, EE hardware registers (`0x1000xxxx`) and the scratchpad (`0x70000000`) read and written at their literal addresses (`*(volatile u32 *)0x10000800`). Entries below marked as history record what once reproduced retail's bytes; they are no longer acceptable, and a function that needs one stays a near miss in `nonmatching/`.

# Matching patterns

> **PAL repository.** These pages come from rac3-uya-decomp, the US project this repository was made
> from (CREDITS.md). The workflow and the matching patterns apply unchanged; function addresses in
> examples are mostly the US ones, and flags here are per source file, never per function
> (docs/build/build-fidelity.md). The level code and the self-hosted progress job are not part of this
> repository yet.

What makes SN ee-gcc 2.95.3 produce retail's exact code, collected from the ~1400 frontbin functions matched so far (and boot_elf's). The research behind it (compiler comparisons, how the assemblers were identified) is in [`docs/compiler_matrix_findings.md`](https://github.com/OpenRAC/rac3-uya-decomp-pal/blob/master/docs/compiler_matrix_findings.md).

Every frontbin and boot_elf range already builds with `-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division`, so `$s` registers saved with `sd` in 8-byte slots and `div` without the trap come out right on their own. The VU0 flag (since 2026-10-07, see [VU0 j-form](#vu0-j-form-one-asm-statement-per-instruction)) also changes ordinary loop code, so measure drafts with it. What varies per function is how globals are declared, split vs no-split addresses, and which assembler runs.

## Globals: gp vs lui

`-G8` lets the compiler address any object of 8 bytes or less relative to `$gp`. Retail only did that for some variables. Match each global's declaration to how retail reaches it:

| Retail access | Declaration | Use |
|---|---|---|
| `lw $v0, -0x3e40($gp)` | `extern s32 D_001D8A70;` (sized) | `D_001D8A70` |
| `lui $v0, %hi(D_X)` + `lw $v0, %lo(D_X)($v0)` | `extern s32 D_001DA0D0[];` (no size) | `D_001DA0D0[0]` |
| Struct or table through `lui`/`addiu` | `extern S_Foo D_00142430[];` or `extern S_Foo D_00142430;` (size > 8) | `p = D_00142430; p->x` |

The address of a `$gp` access is `0x1DC8B0 + offset` (offsets are negative). Name the symbol `D_` plus 8 hex digits: `-0x5b0c($gp)` is `D_001D6DA4`. In code a multiplayer level has (`$gp` `0x247FC0` there), name the slot instead: `D_001D6DA4_sda` is `$gp - 0x5B0C` in every program (docs/build/globals.md).

An unsized array is never small data, so it always gets `lui`. To keep existing code readable you can alias the element:

```c
extern u8 D_00142734[];
#define D_00142734 (D_00142734[0])
```

## Mixed access in one function

Sometimes retail reads a variable through `lui` and writes it through `$gp` in the same function, or uses `$gp` only for the access that sits in a branch delay slot. No single declaration does that with the default assembler. The cause is SN's own assembler, Ps2EeAs, which retail was built with:

- It is **single-pass**. It uses `$gp` for a symbol only if it already knows the symbol is small at that point in the file. gcc writes its `.extern` size hints at the end of the file, too late.
- In a branch delay slot it can't expand a two-instruction `lui` access, so it uses `$gp` there regardless.

**Option A (preferred): natural C with `@ps2as`.** Declare everything with its natural sized type and assemble with Ps2EeAs. For the variables retail does reach through `$gp` everywhere in the function, tell the assembler their size before the function:

```c
/* Ps2EeAs only uses $gp for these if it knows they are small before the use. */
__asm__(".extern D_001D62FC, 4");
__asm__(".extern D_001D6308, 2");
extern void (*D_001D62FC)(void);
extern u16 D_001D6308;
```

`.extern` only declares a size. It creates no storage. Examples: `func_003969B8`, `func_003D3050`. The bitfield writes to `D_001D4CEC` (`flags.b5 = 0;`) and the GIF packet writers (`p[0] = ...; p += 4;`) are this pattern too.

**Option B: two declarations with the default assembler.** An unsized array for the `lui` accesses plus a sized alias for the `$gp` ones:

```c
extern s32 D_001D4CE8[];       /* lui reads */
extern s32 D_001D4CE8_g;       /* $gp writes */
```

The alias needs an address in `config/frontbin/symbol_addrs_resolved.txt` (`D_001D4CE8_g = 0x1D4CE8;`) or the link fails.

## Plain names first, per-function aliases only when needed

Use the plain name (`D_00142430`, `func_003E8320`). A source file is one translation unit: every block sees the earlier blocks' declarations in its file, plus, at the top, the declarations from earlier files of names the file uses without declaring them itself. Other files' declarations never reach a file that declares the name itself.

An alias is needed only when two blocks **in the same file** need different types for one symbol (a different struct type, sized vs unsized, a function used once as an array to take its address), or as one of the code-generation techniques on this page (a second symbol at the same address to get `lui` where the plain name gets `$gp`, and the like). Then don't change the shared declaration; declare a per-function alias named after the function address:

```c
typedef struct { u8 pad[0x18]; u16 h18; ... } S_3969B8;
extern S_3969B8 D_00142430_003969B8[];
```

and add `D_00142430_003969B8 = 0x142430;` to `config/frontbin/symbol_addrs_resolved.txt` (and a `D_00142430 = 0x142430;` line for the plain name if it's the first use of the address). `pr_check.py` flags any alias without an address, and `try_in_context.py` / `pr_check.py` report a clash that needs one.

Until 2026-10-04 aliases were the default, a leftover of the single `text.c`, where every declaration stayed in scope to the end. That day 646 of the 941 were renamed back to plain names; the 295 left are the ones where a block in the same file really uses another type, or where the alias changes the generated code.

To pass a function's address, use the function's own name (`func_003E8320`), declared the way the sources already declare it, not an `extern u8 func_003E8320_x[];` array alias.

Name typedefs uniquely the same way (`S_3969B8`, `S_142430x`). Two blocks defining the same typedef name with different bodies is the most common full-build error.

## Never define variables

The source files must only produce `.text`. Every variable is `extern`:

- `s32 D_X;`, `static s32 D_X = 3;` and `void (*D_X)(void);` without `extern` are definitions. They create `.data`, `.sdata` or `.bss`, which shifts the retail layout or fails the link with `multiple definition`.
- String literals and float constants that the compiler puts in `.rodata` or `.lit4` have the same problem. See floats below.
- `pr_check.py --obj build/src/text.c.o` lists any data section that sneaks in.

## Split vs no-split addresses

Retail was built from many source files, and some used `-mno-split-addresses` (N) while others used the default (S). They form address runs, recorded in `config/frontbin/text_parts.txt`:

- **S:** `lui $v0, %hi(X)` + `lw $v0, %lo(X)($v0)`, and array bases as `lui` + `addiu`.
- **N:** the compiler emits `lw $v0, X` and the assembler expands it, so you see `lui $at` pairs and loads that fold the offset differently.

A function's mode only shows when it touches a global. If the diff is all about how addresses are formed, run `check.py --all-modes`. Known N-only shapes: constructors that return `p`, destructors that save `ra` with `sd`, and the "no-split global load" class.

## Choosing the assembler

| Assembler | Selected by | When |
|---|---|---|
| `bin/ee-as.exe` (Aug 2000) | default | Almost everything. It inserts the `nop` after `mtc1` that retail has. |
| `ee/bin/Ps2EeAs.exe` (SN ps2eeas 1.9.25) | `@ps2as` | Mixed gp/lui access (above); float constants built inline with `lui`/`ori`/`mtc1`; `mtc1` hazard `nop`s that depend on whether the next instruction uses the register |
| `ee/bin/as.exe` (May 2001) | `@newas` | Rare; try it when both of the others are one instruction off |
| Sony's `ee-as` 2.10-ee-001003-1 | `@eeas` | Sony's library code (`@ee29`, `@ee296` files) whose `jal`/`jr` delay slot holds the last instruction of an expanded macro (`lw` of a far offset, `la`, `dli`) where SN's assemblers leave a `nop` (Toolchain-and-Build, `@eeas`) |

Ps2EeAs can't read the GNU `macro.inc`, so a range assembled with it must not contain any `INCLUDE_ASM` stub. Give the function its own single-function range (the build then compiles it as a separate slice of its file) (see [Toolchain and build](Toolchain-and-Build#text_partstxt)).

## Floats

### Early extern sizes for Ps2EeAs

Ps2EeAs can select `lui/lo` instead of `$gp` when GCC places its scalar
`.extern symbol, size` declaration after the first access. An isolated probe
with four real four-byte scalars and a float constant demonstrated both
`GPREL16` access and inline constants once the same size metadata was made
visible early. Alignment attributes alone did not change that result.

For a scoped candidate, `tools/check.py` accepts repeated
`--early-extern-size SYMBOL=SIZE` options, for example:

```text
python tools/check.py scratch/candidate.c --mode N --as ps2as --early-extern-size D_001DB6DC=4
```

The helper requires a positive size exactly present in the compiler's own
generated assembly. It duplicates only those declarations immediately before
the first `.ent`, preserving the initial header, instructions, and late
declarations. Missing symbols, different/conflicting sizes, malformed requests
and missing function entries are rejected. No source inline ASM, register
constraint, storage or instruction substitution is introduced.

This is an opt-in compiler-metadata experiment, not a matching result. Recheck
the full function's symbol type/size, payload, all resolved retail bytes and
raw object encoding. The current full-project builder does not automatically
enable this command-line option; successful candidates need a reproducible
build integration before promotion. Never guess a different data width merely
to influence GP selection.

- `li.s` constants: retail usually builds them inline (`lui $at, 0x3f80` / `ori` / `mtc1`). Only Ps2EeAs does that. With the default assembler, the constant goes to a `.lit4` pool and the link fails with `R_MIPS_LITERAL lit4`. Use `@ps2as`.
- Read the constant's value from the asm: `lui $at, 0x3f46` + `ori $at, $at, 0x6666` is `0x3F466666`, which is `0.775f`. Write it with enough digits that it rounds to the same bits.
- Float arguments need prototypes. Without one, a `float` argument is promoted to `double` (you'll see `cvt.d.s` and the wrong registers). Declare it (`extern f32 func_00388A28(f32, f32);`) or cast at the call (`((void (*)(void *, f32))func_00388830)(a, f)`).
- 64-bit values (`sd`, `ld`, `dsll32`, `dsra32`) are `long` or `unsigned long` in this compiler, not `s32`.

### Floats read through $gp

A float loaded through `$gp` (`lwc1 $f12, -0x33a4($gp)`) is a small-data global in frontbin's `.lit` segment (0x1D5680 to 0x1D9900), not a literal. Declare it sized, like any `$gp` variable:

```c
extern f32 D_001D950C;           /* 0x1DC8B0 - 0x33A4 */
```

A few such loads reach below 0x1D5680, into the main executable's small data; declare those the same way. Constants written in the source come out inline (`lui`/`ori`/`mtc1`) and need `@ps2as`, as above.

## Code from another compiler (`sibcall`)

A function that ends `ld $ra, ...; j func_X; addiu $sp, $sp, N` (or `j func_X` straight after the `$ra` reload) makes a sibling call: it jumps to its last callee instead of calling it and returning. SN ee-gcc 2.95.3 never does that (it emits `jal` and `jr $ra`), and frontbin has no such function. boot_elf's engine core has 43 and i5bootn 3. Sony's library compiler, ee-gcc 2.9-ee-991111, does make them (i5bootn's compiler matrix matched them with it, and with nothing newer), and so do 2.96 and 3.2 (about 11% of functions in the 2026-10-07 calibration builds; boot_elf's newlib region looks like 2.96, see `docs/boot_elf.md`). So a sibling call only says "not our compiler". `tools/todo.py` puts them in the `sibcall` bucket. See `docs/compiler_matrix_i5bootn.md`, which also lists the libgcc code (byte-identical to the prebuilt `libgcc.a`) in i5bootn and boot_elf's core.

Two Sony compilers are in the toolchain now, and the frame tells them apart:

- **2.9-ee-991111 (`@ee29`)**: each saved register in a 16-byte slot, `$ra` restored first. Level 39's SSL-C/RCOM and libinsck files (0x4B3100 onward, population A), i5bootn's libgcc and the Sony libraries in boot_elf. Flags `@ee29 -O2 -G8 -fno-strict-aliasing` in level 39.
- **2.96-ee-001003-1 (`@ee296`)**: 8-byte slots with `$ra` saved and restored last, sibling calls, argument moves hoisted above the branch (`li $v0, 0x206; move $a0, $s1` before a `beqz`), an alignment `nop` after every `b` whose next label isn't 8-aligned, `nop; nop` before `div.s`, and `float` to `unsigned` inline. Level 39's DNAS2 library (20 files, population B, about 0x4B3100 to 0x51A3B8 interleaved with A), i5bootn's newlib `exit()` and boot_elf's newlib region. Flags **`@ee296 @newas -O2 -G0`** (Toolchain-and-Build: `@newas` because the default assembler adds `nop`s after `mtc1`/`mfc1`). Measured 2026-11-14: six of six test functions byte-identical, four of them with the C the workers had written for SN, and 17 of the 35 held DNAS functions with their workers' C unchanged. Write plain C: the hoisting and the slots are the compiler's, not a wording to find. Where a 2.96 draft is off only in which register holds a value, the usual wording changes work (`func_L39_004D5A40` matched once the buffer had a pointer variable, `func_L39_005070D0` with an early return).

## boot_elf's engine core

- Some core functions start on a 4-byte boundary. A source file's object starts 8-aligned, so a file can only begin at an 8-aligned function; inside a file gcc places the functions itself.
- Some core code reloads `$gp` (`lw $gp, %lo(sym)($v0)`): it is library code that switches small-data bases. Leave those as INCLUDE_ASM for now.
- `core.rdata` isn't split, so a core function with a `switch` (a `jtbl_` in its `.s`) stays INCLUDE_ASM until it is.
- Most of the core is Sony library code built with another compiler (region map in `docs/boot_elf.md`). Signs that a function is library code and not worth a C attempt yet (k1, 83 of 200 small core functions skipped for these):
  - each saved register in its own 16-byte slot with `sd`, `$ra` highest (our gcc gives 8-byte `sd` slots with `-fopt-stack` and `sq` without it; the `sq_ra_funcs.txt` rewrite only produces `sq`);
  - sibling calls;
  - a short loop whose branch delay slot is left empty, with `nop`s before the branch (padded to 7 words; neither Ps2EeAs nor `-fno-delayed-branch` reproduces it);
  - an alignment `nop` after a `b`;
  - newlib reent wrappers that keep `&errno` as a full address in a register (our gcc folds the low half into the offset);
  - varargs functions that save none or all eight FP argument registers (ours saves four);
  - `mult $0` + `mflo` (our gcc always uses the 3-operand `mult`).
- Three core functions (`func_00122278`, `func_0013A9F0`, `func_00136010`) match with SN gcc only with `-mcheck-zero-division` (the project's `-mno-check-zero-division` dropped), which suggests libraries built with their compiler's default flags. They have single-function overrides.
- 989snd's EE side (0x13B330 to 0x13D420) is SN code at `-O2 -G8 -fopt-stack` and matches with our toolchain; start core work there.
- **Not allowed now (history; the function stays a near miss):** **A wait loop that re-reads a `$gp` global with `lui`** (`func_0013BD58`, `@ps2as`): retail tests `D_1D4A00` through `$gp`, then polls it in a 6-word loop with `lui`/`lw`. Write the first test plainly and the loop's read as a volatile cast, `do { func_0011F0A0(0); } while (*(volatile u32 *)&D_1D4A00 == 0xFFFFFFFF);`. With an unsized alias or a literal address, gcc builds the address in a register before the loop, and a `goto` loop gets merged with the first test. The loop's load is an assembler macro, which `tools/asm_filter.py` counts as two words in `@ps2as` ranges (see [Tools](Tools#asm_filterpy)).

## Switch statements

`switch` works in C. The jump tables used to sit inside the data blob; since `tools/migrate_jtbls.py` they come from the source files, in function order, exactly where retail has them (the start of `.data`). Each asm function with a table has an `INCLUDE_RODATA(...)` line right after its `INCLUDE_ASM`. When you convert the function, delete both lines: gcc's table takes the same place. `pr_check.py` catches a leftover `INCLUDE_RODATA`.

Getting the table to start at the right index: if retail's table has entries for 0 and 1 that go to the default code, list them with the default at the end, as in `func_003B0FC8`:

```c
switch (D_00143A07[0]) {
case 2: return 0x151;
...
case 6: case 7: return 0x150;
case 0: case 1: default: return 0x150;
}
```

## VU0 code: inline asm

> **Allowed again since 2026-11-08, for VU0 only** (AGENTS.md, Matching rules): asm for the VU0 macro-mode/COP2 instructions the compiler cannot emit, one block per VU0 sequence with real operands and clobbers (or shared helpers in a header), as the original source plausibly had it. Never asm for ordinary EE instructions or to steer allocation, scheduling or delay slots. Between 2026-11-06 and 2026-11-08 it was not allowed.

Insomniac wrote VU0 math as inline assembly inside C functions, so that is the matching form too. Two forms match retail. Where retail keeps a VU0 sequence together (leaves, and blocks with no ordinary instruction between the VU0 ones), one volatile block with explicit registers matches, as below. Where retail interleaves VU0 instructions with ordinary code (argument moves, constants, `lq`/`sq`), use the [j-form](#vu0-j-form-one-asm-statement-per-instruction): a volatile asm is a scheduling barrier, so one block can't reproduce that.

For the one-block form, use explicit `$vfN` registers in the template and pass pointers as `"r"` operands:

```c
void func_00388698(void *o, void *a, void *b) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0(%1)\n"
        "lqc2 $vf2, 0(%2)\n"
        "vmini.xyzw $vf1, $vf1, $vf2\n"
        "nop\n"
        "sqc2 $vf1, 0(%0)\n"
        : : "r"(o), "r"(a), "r"(b) : "memory");
}
```

Keep any `nop` retail has between VU0 instructions in the template.

Most VU0 functions are pure assembly leaves: a few `lqc2` loads, vector math, an `sqc2` store. For those, transcribe every instruction into one `__asm__ __volatile__` block in retail's order and let gcc emit the return. The details that decide whether it matches:

- **Raw `.word` lines.** `tools/fix_quadword_ops.py` writes `lqc2`, `sqc2`, `lq` and `sq` as raw words so the GNU assembler can't pad them. Decode them back to real instructions in your C (`.word 0xD8A10000` is `lqc2 $vf1, 0($5)`); a `.word` inside inline asm assembles fine but is unreadable.
- **The delay slot decides the assembler.** gcc ends the function with its own `j $31`. With the default assembler in reorder mode, the assembler moves your block's last instruction into that delay slot. When retail has that instruction in the delay slot, the default assembler is right; when retail has `jr $ra` followed by `nop`, use `@ps2as`, which leaves the order alone. Try both.
- **Branches inside the block** need `.set noreorder` around the part that contains the label, or the assembler re-pads the branch.
- Functions that end by moving a value into `$f0` (`mtc1 $at, $f0`) still don't match: retail has that instruction in the delay slot and neither assembler puts it there, since gcc, not the assembler, owns the return value. Those need the value returned from C instead of from the asm block.

## The assert trap

`func_L39_0067BCA8` opens with a type check that executes `break 1` when it fails: the game's
assert, left in one function. No C reaches that instruction (`__builtin_trap` is "not supported by
this target" in both compilers; a division gives only `break 7`), and of the 52 functions in all
programs that have a `break`, this is the only compiled one that is not a divide-by-zero trap.
Write it with `ASSERT(c)` from `include/assert.h`: `do { if (!(c)) __asm__ __volatile__("break 1"); }
while (0)`. The loop is part of the match: the `nop` retail has after the trap is the alignment of
its end label, and a bare `if` with the asm leaves a `$s0`/`$s1` swap (19 lines). The macro is for
places where retail's compiled code has `break 1`, and for nothing else.

## Protected DNAS blocks (level 39)

A function of level 39's DNAS library whose `.s` shows a stub (`lui`/`addiu`, `lw`, `bnez`, `jal
func_L39_004BD350` or `func_L39_004F7890`, `b +0xC`), then words that decode as MMI, VU0 or
`syscall` nonsense, then a second `jal` of the same driver, is not handwritten and not blocked: the
words between are **encrypted** C. 112 such blocks, in 97 functions.

- `python3 tools/dnas_blocks.py --show func_L39_XXXXXXXX` prints the function with its blocks
  decrypted. Match that.
- Write `DNAS_BEGIN(func_L39_XXXXXXXX, n, driver);` and `DNAS_END(func_L39_XXXXXXXX, n, driver);`
  (`include/dnas.h`) where the stubs are, with the function's own name, the block's number and the
  driver the stub calls; `DNAS_END_ONCE(function, n);` where no second call follows the block.
  The file's prelude has `#include "dnas.h"` and the driver's declaration.
- `tools/check.py` protects the compiled object with the disc's words before it compares
  (`tools/dnas.py`), so `MATCH` is against the stored bytes; a diff is listed decrypted. Check
  `--version us` too: the same C must give NTSC-U's bytes with NTSC-U's table.
- The stub is a call to the compiler: a value needed after it is in a saved register (a
  parameter moved to `$s0` in the prologue), a local set before it stays set (`s32 ret = -1;`
  before `DNAS_BEGIN`), the return value is produced after `DNAS_END`.

- Text inside a block (`b`, `nop`, two zero words, the text, a `nop`, `lui`/`addiu` of its
  address; all 65 text sites of the 30 blocks with text have it) is `DNAS_STRING("text")` where
  the code uses the address: only inside a block, with one string literal (no concatenation, no
  `%`), and never for the DER blocks' binary tables. The allocator's `malloc`
  and `free` (`func_L39_004B7748`, `func_L39_004B7A80`) show it, with a `goto` out of a block
  and the unlock written `do { func_00126280(D_L39_003E4398); } while (0);`.

[docs/build/dnas.md](../build/dnas.md) has the layout, the tables and the evidence. Binary
tables inside a block are not covered yet. The allocator's `abort()` loop of five `nop`s is
plain C, `for (;;) { }`: Sony's compilers pad a short loop to six instructions themselves
(`func_L39_004B5F68`).

## Vector-library asm macros

Besides VU0 code, `include/vu0.h` holds the few small helpers that retail proves were asm in the
original's headers: `qzero` (`sq $0`), `fabs_asm` (`abs.s`), `sqrt_asm` (`sqrt.s`), `fmax_asm`
(`max.s`) and `abs_asm` (the integer abs). The evidence rule for each: the compiler cannot produce
the instruction or its placement (retail never puts it in a delay slot, or the compiler cannot emit
it at all), the helper is defined once there, and a file uses it at all of its sites or none.

### Integer abs

Retail's integer abs is `blezl $x, 1f` with `neg $x, $x` (the trapping `sub`) in its slot, always
in place (343 times in the levels' unmatched code, also in core handwritten code). Use `abs_asm(x)`.

- SN cc1 never emits it. Its `abssi2` is `bltzl`/`subu` (that is the `abs()` builtin; retail has it
  too, 23 times in the levels, and the compiler folds it away where it knows the sign), and none of
  its patterns emits `sub`.
- No assembler expands it. An asm `abs` gives `bgez`/`nop`/`neg` (in place) or `bgez`/`move`/`neg`
  with every assembler here: ee-as, ee/bin/as, Ps2EeAs (both versions), the 2.10-ee ee-as and
  rac1's dtls GNU as. None uses a branch-likely.
- The compiler never folds it: `func_L01_0032A0C8` tests `n > 0` and then still runs the pair on
  `n`, and `func_L02_003484D8` runs it on the 0/1 result of a float comparison
  (`abs_asm(pos.z - ground < 0.1f)`, the original's misplaced parenthesis).
- The template needs `.set noreorder` around the branch, or the assembler pads the branch-likely
  with a `nop`. It assembles the same with GNU as and Ps2EeAs.
- spimdisasm marks a function "Handwritten" for the `neg` alone. Such a function is still C.

## Not everything is C

- **Trailing padding is part of the layout.** A function's `.s` file also holds the padding words that follow it (`func_0039BD08` is 0x24 bytes with 5 `nop`s after it, because the next function starts at 0x39BD40). Converting such a function to C drops that padding and shifts everything after it, which changes every `jal` target in the build even though the function itself is byte-exact and `check.py` says MATCH. Before converting, check the gap to the next function's address; if there is one, the padding has to be reproduced or the function left as asm.
- **Linker remnants** (the `remnant` bucket in `todo.py`, about 200 entries). Retail has about 620 single instructions, each followed by a `nop`, between functions. Nothing references them, and 449 of them are `addiu $sp, $sp, N`, a function epilogue. They are what the original linker left behind when it stripped unused functions: the final odd instruction plus its alignment `nop`. They are not source code: they live in `asm/remnants/` and are included with `LINKER_REMNANT(...)`. Don't write C for them.

  A C function whose whole body is one `asm volatile("addiu $sp, $sp, 0x50")` looks like a match in localdecomp but is not one: gcc still appends `j $31` and a `nop`, which shifts every later function. 26 of these were scored 0 before localdecomp stopped trimming real instructions past the target size; `pr_check.py` now warns when its count runs ahead of the sources.
- **Handwritten assembly** (the `handwritten` bucket, 100 functions). spimdisasm flags them (`addi`, `$at`, unusual registers). The original was a `.s` file, so their `.s` in `asm/handwritten/` is the source, included with `ASM_FUNC(...)`. The same goes for VU0 leaves whose last instruction sits in the `jr $ra` delay slot after a dependent instruction (`mtc1 $4, $f0` after `qmfc2 $4`, `ppacb` after `ppach`): neither assembler nor gcc will put it there, even when gcc emits the `mtc1` itself, so the original wrote the whole function, `jr` included, in assembly.

## Codegen tricks that matter

When the instructions are right but their order or registers aren't:

- **Independent stores get rotated by the scheduler.** gcc emits the last store of a run to the same base first. For retail's order A, B, C, D write B, C, D, A (`func_003A61D0`, `func_003A6888`). The scheduler issues at most one memory access per cycle; between equal priorities it prefers the instruction with more dependents, then the one that frees a register, then source order (found by the NTSC decomp).
- **`addu` operand order is picked by the access form, not by the order you write the `+`.** gcc canonicalises the addition. `p = (u8 *)T + i * 4` and `b = table + i` give index first; `T[i].field`, `S.arr[i]` and `table[i]` give base first (rac1-decomp). A field at a fixed offset from an indexed table (`sw $a0, 0x34($v0)` after `addu base, idx`) is an array member of a struct: `extern T D_X; D_X.arr[i] = v;` (`func_00395958`).
- **Two registers holding the same pointer.** Retail computing `base + i * 4` into one register and copying it to another before the second store (`addu $v0, $a0, $a1; move $a0, $v0`) is two arrays in one struct: `s->a[i] = x; s->b[i] = y;` (`func_003A7FC8`). Pointer variables, `volatile` and return tricks don't produce it.
- **Callee prototypes decide argument code.** Use the declaration the sources already have instead of an alias with guessed types. A `long` / `unsigned long` parameter builds its constant as one macro that can move (`func_003A3EF0`, `func_003D47A0`); a callee declared with too many arguments leaves extra `move`s (`func_0037EAA0`). A function that ignores its argument in retail may still be called with one: `func_003E16B8(&D_001DA9B8)` is what keeps the pointer in `$v0` in `func_003E2D90`.
- **Not allowed now (history; the function stays a near miss):** **`volatile` pins accesses.** reorg never moves a volatile access into a delay slot, and volatile stores keep their order against the epilogue (rac1-decomp). Try it before an `__asm__` fence when retail leaves a slot empty.
- **Not allowed now (history; the function stays a near miss):** **`fabsf` that isn't scheduled.** When retail's `abs.s` sits before `jr $ra` instead of in its delay slot, write `__asm__("abs.s %0, %1" : "=f"(r) : "f"(x))` (`func_003BEBF8`, `func_0037E920`).
- **Check m2c's pointer arithmetic.** It writes `D_X + 0x40` or `p->f4 + 0x20` on struct or `s32 *` types, which scales the offset. Cast to `u8 *` first (`func_0039D510`, `func_003E16B8`).
- **Early `return` vs `if/else`** changes block layout and which branch is likely (`beql`/`bnel`).
- **`x = c ? a : b` vs `if`** produce different code (`movz`/`movn` vs branches). Try both.
- **Declaration order of locals** can swap registers.
- **Signedness** picks `slt` vs `sltu` and `sra` vs `srl`. `u8` vs `s32` for a flag changes `andi` masks.
- **A copy of a parameter** (`s32 id = arg;`) sometimes changes which register holds it.
- **Pointer vs index loops** (`p++` vs `a[i]`) produce different induction code.

Stop after a handful of attempts on the same register difference. Leave it as a partial and move on: breadth gets more done.

## Register allocation near misses

When every instruction is right but a variable sits in another register, `python tools/regalloc.py scratch/func_X.c` prints gcc's global allocation order: for each variable its reference count, live length, priority (about `refs * log2(refs) / live`) and the register it got. gcc allocates in decreasing priority, and a variable takes the first register not used by anything live at the same time that was already allocated; a parameter prefers its incoming register but loses it to a higher-priority local that overlaps it. So to move a parameter, change what outranks it or what overlaps it:

- Give the competing local a shorter live range (compute it later, or inline it into its single use), or one more or fewer use.
- Declare a temporary in a different block, or turn an `if` that sets it into a conditional expression: both change the live length and reference count the priority uses.
- Declaration order of locals only matters as a tie-break when priorities are equal.

Change the C, re-run the tool, and compare the `->` registers with retail before spending a build on it.

## Patterns from the m2c-assisted pass (2026-10)

m2c (`--target mipsee-gcc-c --valid-syntax`) gets the logic right for many functions but needs the fixes below before it matches. Each was confirmed on a real function.

- **m2c names parameters by register, C by position.** A function that only uses `$a0` and `$a3` must still declare `arg1` and `arg2`, or its arguments land in the wrong registers (`func_003ACED0`).
- **Virtual calls pass the object as the first argument.** m2c drops it when `$a0` already holds it: `(*vtbl[0x10])(obj, D_x)`, not `(*vtbl[0x10])(D_x)` (`func_003E7028`, `func_003E7D68`). The branch is also usually positive: `if (call(...) != 0) { ...; return 1; } return 0;`.
- **Early return versus a result variable changes the branch layout.** If only the branch shape differs, try `if (!cond) return 0; ...; return 1;` (`func_003B4220`).
- **Narrow argument types.** A `s8` parameter makes gcc sign-extend at entry. If retail only stores the byte, declare the parameter `s32` and let the store narrow it (`func_003B4220`).
- **Keep one base register with a struct pointer.** m2c repeats `M2C_FIELD(&D_x, ..., off)`, which gcc folds into the address. Declare a struct with the fields at their offsets, take `S *p = D_x;` once and write `p->field` (`func_003B8700`, `func_0039C710`).
- **`(x > -1 ? x : x + 0xFF) >> 8 << 8` is `(x / 256) * 256`** (signed). The same for 1024 (`func_003AAD40`, `func_003AAEC8`).
- **A callee's parameter order sets how its arguments are scheduled.** Registers are assigned by type independently (ints and floats separately), so a prototype can list parameters in a different order than their registers, and that changes which argument setup lands in the `jal` delay slot (`func_0038C840`, `func_0038C718`).
- **128-bit copies (`lq`/`sq`):** `typedef int u128_t __attribute__((mode(TI)));` and `*(u128_t *)p = *(u128_t *)q;`.
- **Unaligned 16-byte copies (`ldl`/`ldr`/`sdl`/`sdr`):** assign a struct of `u8 b[16]` (alignment 1): `V16 v = D_x;` (`func_003E5D08` and its four siblings, with `-O2 -G8` split addresses).
- **Singleton lookup template (`func_003E24B0` and six siblings).** Retail is split-address (`-G8`, no `-mno-split-addresses`), the singleton is a struct object with a local pointer, and the check is a conditional expression:
  ```c
  p = D_001DA9B8_x;            /* typedef struct { s32 x0, x4, x8, xC; } S; extern S D_...[]; */
  if (p->x4) q = p; else q = func_003E16B8(p);
  t = (void *)func_003E0E28(func_003E1898(q), arg0);
  v = (t != 0 && vcall(t, g) != 0) ? t : 0;
  ```
  Separate `t` and `v` are needed here: retail keeps the tested object in `$a0`.
- **Pointer-count loops over a table of function pointers** keep one outer struct pointer: `p->q->fn[i]` rather than caching `p->q` (`func_003E15D8`).

- **Not allowed now (history; the function stays a near miss):** **Loop padding no assembler mode reproduces** (retail has `jal; nop; nop; nop; bnez`): `do { r = f(); __asm__ volatile("nop\n\tnop\n\tnop"); } while (r);` (`func_003B6488`, `func_003AB100`). This is an inline-asm hack. `tools/asm_filter.py` now counts `jal`/`jalr` when it pads short loops (see "Loop padding with a call in the body" below), so try the plain loop first; it may make the hack unnecessary.
- **64-bit constants and `lwu`:** declare the callee parameter and the struct field as `unsigned long` (`func_00386608`, needs `@ps2as`).
- **Under `@ps2as`, a scalar `extern s32 X;` gets the non-gp form** (`lui; lw`, or `lui $at; sw`). Add `__asm__(".extern X, 4");` only for symbols retail reaches through `$gp` (`func_003A3220`, `func_003D3C80`).
- **Check the raw words for `lq`/`sq`** (`.word 0x78..`/`0x7C..`) before rewriting a copy loop (`func_0037F550`).
- **Singleton-style load through a different address form:** a second symbol alias at the same address (`D_001D52FC_003B42D0`, unsized array) gives retail's `lui`/`lw` where the plain name gives `$gp` (`func_003B42D0`).

## Patterns from the hand pass (2026-10, 50 functions)

Each of these fixed a real near miss.

- **Toggle a callee between `void` and `s32`.** Retail's register choice depends on whether the callee's result is live in `$v0`. A call whose result is discarded but declared `s32` kept `$v0` busy and moved a following `lui` from `$v0` to `$v1` (`func_003AE098`, `func_003B12C8`, `func_003CB890`, `func_003BC0F0`, `func_003B62E8`). If another block in the same part already declares it `void`, call through a cast (`((s32 (*)(s32))func_0039D6C8)(1)`) instead of redeclaring.
- **Scalar versus array decides who splits the address.** Under `@ps2as`, `extern s32 X;` becomes the assembler macro (`lui $a0; lw $a0, lo($a0)`, destination reused) and `extern s32 X[]` / `X[0]` becomes gcc's split form (`lui $v1; lw $v0, lo($v1)`). When a near miss differs only in which register holds the high half, flip that global (`func_003958A0`, `func_00396F18`, `func_003ADF88`). Add `.extern X, 4` for the symbols retail reaches through `$gp`.
- **Singleton vtable wrappers (the `D_001DA9B8` family) match in plain `S` mode** (no `-mno-split-addresses`). The key is a temporary for the virtual call's result: `t = vcall(p); cb = lookup(table, t); r = cb(p, ...)`. Twelve functions follow this template (`func_003E2728`, `func_003E2808`, `func_003E28E0`, `func_003E1E50`, `func_003E2028`, `func_003E2C88`, `func_003E22D0`, `func_003E23C0`, `func_003E2B98`, `func_003E21F8`, `func_003E2618`, `func_003E2A90`), and the permuter found the same template for `func_003E2118`, `func_003E29B8` and `func_003E30C8`. The lookup functions are defined later in the same part, so call them through an alias symbol and a cast.
- **Index first in an address sum.** `(i << 2) + (s32)base` gives `addu idx, base`, the order retail has; `base + i * 4` gives the other (`func_003E8EC8`, `func_00392108`).
- **A callee that returns its argument.** Use the result (`b = f(b, 1)`), or the pointer needs its own callee-saved register (`func_003DFB40` family).
- **Separate return variable, single return.** `func_003ABE98` and `func_003AD520` only match with one `return r;` at the end and no early return inside the else branch; early returns let gcc fold `r` to a constant and free the register.
- **Hash-style update `off = (key & 1) + (off + 1)`** gets reassociated; a temporary (`t = off + 1; off = (key & 1) + t;`) keeps retail's order. With it plus the init-order fix below, the lookups `func_003E4890`, `func_003E4918` and `func_003E4DA0` match; the inserts `func_003E5F00`, `func_003E6680` and `func_003E67B8` are still open (setup moves hoisted in a different order).
- **Chains of `!= 0` tests combined with `&`** (`func_003E34F0`, `func_003E3580`, `func_003E3630`): `r = f(a, b) != 0; t = f(a, c) != 0; r = r & t; ...`. A single expression gives conditional moves instead.
- **A switch whose table starts at 0** needs `case 0:` sharing the `default:` body (`func_003AE368`); without it gcc subtracts 1 and builds a shorter table.
- **Not allowed now (history; the function stays a near miss):** **A reload that retail really performs** after a store to the same global needs `volatile` on that global (`func_00395FF0`, `D_001D4CEC`); a second alias symbol is scheduled above the store instead.
- **Not allowed now (history; the function stays a near miss):** **Object-array initialisers** (`if (flag == 0) { for (...) init(p++); flag = 1; } return &array[i];`): retail has one `nop` in the loop that neither `S` nor `@ps2as` reproduces, so they need `i--; __asm__ volatile("nop"); p++;` (`func_003E13D0`, `func_003AD820`, `func_003AEDF8`, as in `func_003B46F0`). That is an inline-asm hack.
- **Order of independent stores** can only be found by search. A statement-order hill climb on the store lines found `func_003AC0D8`. decomp-permuter finds the same kind of change; it also tends to introduce `do { ... } while (0)` and `new_var` temporaries, which are harmless, but check that it did not change what the code does (it once moved an assignment into an `if`).

### Functions that save `$ra` with `sq`

Thirteen retail functions (`func_003869E8`, `0038C888`, `0038C9D8`, `003A6C30`, `003A9E60`, `003AAF88`, `003B3DB8`, `003B82C0`, `003BA5B8`, `003C0B10`, `003C1130`, `003D1B10`, `003D2370`) save `$ra` with `sq` in a 16-byte slot. gcc 2.95.3 writes `sd`, and when the function also saves `$s` registers it puts `$ra` in the lowest slot, where retail puts it in the highest (`$s0` lowest, ascending). No compiler or flag we have gives retail's layout, so `tools/asm_filter.py` rewrites it: list the function in `config/frontbin/sq_ra_funcs.txt` and every callee-saved save and restore is moved to retail's slot (same slot set, same frame size) as `sq`/`lq`. Write the C normally.

- A function with `$s` registers also needs the `-fopt-stack` flag removed, because retail's `$s` saves are `sq`, not `sd`: flags are per file, so it goes in a file of its own without `-fopt-stack` (as boot_elf's `0x0038B500`, `0x003BFE80`; docs/build/build-fidelity.md, rule 1).
- **Level functions** are listed by catalogue name in `config/levels/sq_ra_funcs.txt`; `tools/level_tree.py` writes each level's copy under its names, and `check.py` reads the table as it is (docs/build/levels.md). Check one with `--flags=-fno-opt-stack` until it has its file.
- Under `@ps2as`, a `$ra` save in a branch delay slot is written as `sq $31,N($sp)` rather than the raw word: Ps2EeAs crashes on a `.word` in a delay slot (check.py says COMPILE ERROR with no message).
- `func_0038C888` and `func_0038C9D8` are done this way. `func_003A9E60` has the right slots and call; only its argument-copy registers differ (retail gives `$a0` the first temp, gcc gives it the last).
- A 64-bit argument that is moved with `daddu` must be `long`, not `s64` (`s64` produced a 128-bit `por`).

## Patterns from the third hand pass (2026-10, 13 functions)

- **Read a struct-typed global through its fields, with locals for the early reads.** `func_003A13B0` only matched once the two reads of `D_00225780` (`f30`, `f6C`) were locals at the top and the indexed table was a struct array (`D_160C40.e[idx].v[a]`, entry type 0x14C bytes) instead of pointer arithmetic. Retail's base-register reuse (`$a1` holds one global, then the other) follows from that.
- **Do not cache a field chain if retail re-reads it** (`func_003C0B10`): `obj->set->n` and `obj->set->arr[j]->e` written out each time matched; a local for `obj->set` did not. The same holds for plain fields: `func_003AC6F0` matched with `p->f8`, `p->f0` written at each use, where locals for them rotated `$a2`/`$a3`/`$t0`.
- **A base pointer that is hoisted to the top** (`addiu $a1, $a0, 0x70` before anything else) is a local `u8 *b = p->b;` declared first (`func_003932B0`).
- **Assign first, then test** (`func_003932B0`): `p->f74 = t; if (a < t) p->f74 = a; else if (t < 0) p->f74 = 0;` puts the first store in the branch's delay slot the way retail has it. The if/else form with the store inside each arm does not.
- **Boolean return from a comparison: write `if (r < 0) return 0; return 1;`** (`func_003AAAC8`). `return r >= 0;` (and `!(r < 0)`, `(r < 0) ^ 1`) compile to `nor`/`srl`, retail has `slti` + `xori 1`.
- **Search loops** (`func_0038EC80`, `func_00395BC0`): `for (i = 0; i < N; i++) if (tab[i].k == key) break;` followed by `if (i == N) return;`/`if (i < N)` gives retail's rotated loop. They need a struct with the exact element stride; the function itself is easy once the stride is right.
- **Loop over an index range** (`func_0039B0F8`): `for (i = lo; i < hi; i++) { dst[i].x = ...; }` with `lo`/`hi` read from a table matched; the pointer-walking version with `n = hi - lo` did not.
- **Float immediates and `$gp` floats together** (`func_003A3028`): `@ps2as` plus `__asm__(".extern X, 4");` for each `$gp` float/pointer global; initialise a loop offset inside the `if` that guards the loop (`off = 0;` before the `if` moves the `move` above the branch).
- **Typedef and extern names collide within a file.** A block's typedefs and `extern`s stay visible to every later block in the same source file, so give each function's types a suffix (`S_395BC0`), and give a global an alias symbol (`D_160C40_00395BC0` plus a line in `symbol_addrs_resolved.txt`) only when another block of the file declares it differently.
- **Not allowed now (history; the function stays a near miss):** **VU0 code that is not a pure leaf** (`func_003BFD10`): C around one `__asm__` block with `lqc2`/`vadd.xyz`/`sqc2` matched in no-split mode; a callee that other matched code declares with fewer arguments needs an alias symbol (`func_003BFC18_003BFD10`).
- **`div.s` with `nop`s in front** (`func_00393380`): matched as plain C once `config/frontbin/divs_nops.txt` handled the padding (see the `div.s` entry under Known open problems). Don't use the old inline-asm `nop; nop; div.s` workaround; it changes the register choice.
## More patterns from the third hand pass (switches, delay slots, aliasing)

- **Switch functions work now.** Write the `switch`; the compiler emits its own jump table in `.rodata`, so delete the `INCLUDE_RODATA(... jtbl_XXXXXXXX)` line after the function (`func_003A0178`, `func_0039BD48`). Case numbers must follow the retail table, not the order of the code: read `asm/nonmatchings/text/rodata/jtbl_*.s`, find which index points at each body, and put the bodies in address order. gcc only builds a table when at least five non-merged case nodes exist and it deletes cases that lead to the same place as `default`; to get retail's long table add cases that `break` but are not adjacent (`case 0: case 2: case 4: case 18: break;`), which keeps a 19-entry table.
- **Not allowed now (history; the function stays a near miss):** **A store that gcc pulls into a branch delay slot but retail does not** (`func_003ADBB0`): make that store volatile, `*(volatile s32 *)&D_001D9F40 = 0;`. Retail put the epilogue's first load there instead.
- **A reload of a pointer global after every store** (`func_00385570`, `func_00387B10`, GIF packet writers): declare the pointer global `s32` and write through casts of it (`*(s32 *)(D + 0x64) = a;`). An `s32` store may alias an `s32` global, so gcc reloads it; a store through a typed struct pointer does not reload.
- **Boolean ANDs of call results** (`func_003E3A80`): `t = f() != 0; ok = ok & t;` with a temporary matches `sltu` + `and`. Writing `ok &= f() != 0` makes gcc use `movz`.
- **Two arms where retail's branch-likely goes to the later block** (`func_003AAC70`): put the `!=` case first (`if (b->f4 != 4) {A} else {B}`), and the arm that falls through first in the second `if`.
- **Pointer arithmetic order** (`func_003AAC70`): `(s32)((u8 *)b + 8 + b->f30)` gives `addiu` before `addu`; `(s32)b + b->f30 + 8` gives the opposite.
- **Loop padding with a call in the body** (`func_003BD360`): `tools/asm_filter.py` now counts `jal`/`jalr` as one instruction when it pads short loops to 6.
- **A call with no argument moves** (`func_003E11D0`, `func_003E5F00`): retail's `jal` follows the prologue with `$a0`/`$a1` untouched even though the callee takes them. The original called it with the incoming registers still live, so call it through a zero-argument declaration: `extern void *func_003E1150_003E11D0();` (alias symbol, K&R, no prototype) and write `func_003E1150_003E11D0()`. gcc then emits no `move $a0, $s1`.
- **Boolean from a compare** (`func_003AAAC8`): `if (r < 0) return 0; return 1;`, not `return r >= 0;`.

## Patterns from the large-function pass (2026-10-02)

Five functions between 0x600 and 0x96C bytes (`func_0039DB38`, `func_003E3F08`, `func_003DF038`, `func_003DE8F0`, `func_00384420`), all S mode with `@ps2as`.

- **Small objects get the assembler's `la`, not gcc's split.** Under `@ps2as`, gcc treats an object of 8 bytes or less as small data and emits one `la`/`lw` macro, which Ps2EeAs expands to `lui`/`addiu` (adjacent, same register) when it has no `.extern` hint. A larger or unsized object gets gcc's split form instead (`lui` and `addiu` scheduled apart, `%hi` CSE'd). So when retail's `lui`/`addiu` for an address are adjacent, and the same address is rebuilt at every use instead of kept in a register, declare the object with its real small size: `extern s32 D_001DA868[2];` (an 8-byte buffer cleared with `func_00388440(p, 0, 8)`) or the 0x20-spaced hash tables at 0x1DA9C8 in `func_003E3F08`.
- **Which addresses stay in `$s` registers is gcc's allocation priority.** In a long run of calls that reuse table addresses (`func_003E3F08`), each repeated address is one pseudo; the ones with many uses over a short span win the callee-saved registers and the rest are rebuilt with `lui`/`addiu` at each use. If the wrong ones are cached, look for an object that is really small data (previous point) before reordering calls.
- **Not allowed now (history; the function stays a near miss):** **`volatile` on a global that is saved and restored around a call** (`t = D_001D9F40; f(); D_001D9F40 = t;` in `func_00384420`). Retail keeps both accesses out of the call delay slots, which only happens for a volatile access.
- **A hardware register read with the full address in a register** (`lui; ori 0x800; lw 0($v0)`): `*(volatile u32 *)0x10000800`. Without `volatile` gcc folds the low half into the load offset. Allowed again since 2026-11-14 for EE hardware registers (`0x1000xxxx`) and the scratchpad (`0x70000000`) only (AGENTS.md, `volatile`); a named extern cannot give the constant load.
- **A byte constant address that must not land in a delay slot**: `*(u8 *)0x1D5477` instead of a declared global (`func_0039DB38`). A declared scalar is small data, so reorg puts its load in a delay slot and Ps2EeAs turns it into `$gp`.
  - The same works without a constant address when the variable is the next word of a declared global: `(&D_1D4A40)[1] = b;` instead of `D_1D4A44 = b;` keeps the store as `lui; sw` before the branch, where `D_1D4A44` goes into the delay slot as a `$gp` store (`func_0013B918`).
- **Loop-invariant copies come from member access in the loop.** Retail's `move $t0, $t2` before each loop (`func_0039DB38`) is loop.c hoisting `o + 0x38C` out of `o->an[o->idx][i]`. A local pointer (`an = o->an`) makes it disappear. Likewise a pointer that loop strength reduction creates (`lbu 4($a2)` with `$a2` stepping) comes from indexing (`raw[i + 4]`), not from a pointer variable in the source.
- **One variable per loop counter.** A counter shared by a loop with calls and a loop without moves both into a callee-saved register; give each loop its own variable. The same goes for a temporary reused for unrelated values (a save/restore temp and a swap temp in `func_00384420`).
- **Stores to one struct in retail's order A..J**: the "write B, C, ..., A" rotation applied to `func_0039DB38`'s ten stores only after a statement-order search; try permutations of the stores before anything else.
- **`(x ^ 1) == 0` and `(x ^ 1) & 1`** give retail's `xori` test where `x == 1` or `!(x & 1)` give `li`/`bne` or `andi`/`bnez` (`func_003DE8F0`, `func_00384420`). Bit 0 of a flags word read with `lbu` is `*(u8 *)&flags`.
- **Blocks of the same function with their own locals**: two branches that each pass `&w` to a callee use two stack slots in retail (`sp0`, `sp4`), so each branch declares its own `f32 w;` (`func_003DE8F0`).
- **`div.s` right after `mtc1` under `@ps2as`**: Ps2EeAs adds its own `mtc1` hazard `nop`, so the `config/frontbin/divs_nops.txt` count for that `div.s` is one less than retail's `nop` count (`func_00384420`).
- **`sqrt.s` that spimdisasm prints as `c1 0x504`** is missed by `gen_divs_nops.py`; check the table line has one count per `sqrt.s` too (`func_0038F3F8`, `func_00390730`). With the default flags, `sqrtf()` adds an errno check and a fallback call. The existing inline form is `__asm__("sqrt.s %0, %1" : "=f"(r) : "f"(sum));` with a separate input variable. For a plain-C candidate, see the native compiler probe below before adding assembly.

### Native single-precision square root

SN ee-gcc 2.95.3 v1.36 can emit `sqrt.s` from plain C. An isolated probe on
2026-10-03 compiled `sqrtf(value)` and `__builtin_sqrtf(value)` with the existing
`-O2 -G8 -mno-split-addresses -fopt-stack -mno-check-zero-division` flags:

| Additional flags | Function size | Native `sqrt.s` | Calls in that function |
|---|---:|---:|---:|
| none | 44 bytes | 1 | 1, errno/fallback path |
| `-ffast-math` | 12 bytes | 1 | 0 |
| `-O3 -ffast-math` | 12 bytes | 1 | 0 |

The source used a correctly typed `extern f32 sqrtf(f32);` declaration and no
inline assembly, forced register or approximation. The correctly typed double
`sqrt` probe still needed conversions/calls, not the same single-precision leaf.
The spelling `__builtin_sqrt` remained an undefined symbol in a separate probe;
no supported double-precision builtin ABI is inferred from that result.
`-fno-math-errno` is not accepted by this
compiler's `cc1`.

This proves compiler capacity, **not** a matching game function or numerical
equivalence for arbitrary inputs. `-ffast-math` may also alter surrounding
floating-point evaluation and NaN/unordered comparisons. Try it only as a
scoped candidate configuration; compare the complete compiled function,
including padding, all branches and fully resolved relocations, against retail.
Never remove an errno/libm call by relabeling it as a native instruction or
replace square root with an approximate routine to obtain a match.

### Declarations in the source files

A function sees the declarations at the top of its file (from earlier files), every earlier block of its own file, and nothing from later files. A file with mixed flags is compiled in slices, and a slice only sees the *declarations* of the file's earlier blocks, never their definitions. So:

- A call to a function that is defined in another file, or in another slice of the same file, still needs its own `extern`.
- An `extern` in your block must agree with that function's definition if both end up in the same file (or slice). When they differ, use the definition's types and cast at the call, or align the other `extern` lines to yours (callers that ignore the result are unaffected when the return type changes from `void` to `s32`).
- A K&R declaration `extern s32 f();` followed by a prototyped definition with `u8` or `s16` parameters is a conflict; use a prototype.
- A function called with a different argument count than its existing prototype needs a cast call: `((s32 (*)())f)(a, b)`.

## Families

Many functions are near-copies. Once one is matched, the rest usually go fast:

- **`isA` checks through a vtable at `+8`:** `if ((*(VT_E **)(p + 8))->isA(p, D_001D97D0_g)) { func_X(p, a, b); return 1; } return 0;`
- **8-slot hash tables (`HT_8`/`HE_8`):** `h = ((key & 7) + ((key % 7) * i + i)) & 7;` over 8 probes, with a sentinel value.
- **Getters/setters on the big state struct at `0x142430`**, each with its own aliased declaration.

If you find a family, say so in your PR. It helps the next person.

## Known open problems

Leave these for now, or open an issue if you crack one:

- **Resolved (hand-written): `lwc1 $fN, off($gp)` followed by `nop`** (`func_003882D0`, `func_00388308`, `func_00388340`, `func_00388378`, `func_00388388`). Not a C problem. Retail has the same load-then-jump-then-use shape unpadded 19 other times, so the `nop` is not something a compiler or assembler adds: SN gcc's `-S` output has none, and neither GNU `as` (any `-mips`/`-mcpu`) nor Ps2EeAs inserts one. The five sit in the hand-written math range (0x3882D0 to 0x388388) between functions already classified as hand-written, so they are `ASM_FUNC` now instead of C plus an `__asm__("nop")` hack.
- **Resolved:** 64-bit constant synthesis `li 0x8000; dsll 24` (`func_00383B08`): pass the constant as an `unsigned long` literal with `@ps2as`.
- **Resolved: `div.s`/`sqrt.s` `nop` padding** (`func_003E1D18` and 69 other functions). Retail pads most `div.s`/`sqrt.s` with 0 to 3 `nop`s; no rule predicts the count, and both assemblers delete explicit `nop`s in reorder mode. `tools/asm_filter.py` now puts them back as raw `.word 0` lines, driven by `config/frontbin/divs_nops.txt` (one line per function: `func_0037E568 2`, one count per `div.s`/`sqrt.s` in order). Run `python tools/gen_divs_nops.py` to add lines for every function that is still `INCLUDE_ASM`; existing lines are kept so a function keeps its padding after it is decompiled. If the number of `div.s`/`sqrt.s` in your C differs from the table, the function is left unpadded. First function matched this way: `func_0037E568`. Functions that were already in C without the table are not in it.
- **Resolved 2026-10-06: register allocation where retail keeps an argument in a temporary (`move $t3, $a0` at entry) while `$a0` holds something else** (`func_0039BEC0`): solvable in C. The cause is gcc's priority order (see `tools/regalloc.py`): a block-local temporary outranks the parameter and overlaps it, so the parameter is pushed out of its incoming register. Two changes reproduce retail's exact allocation for `func_0039BEC0` (`screenId` `$t3`, the `-2` constant `$a0`, `result` `$t2`, `flag` `$t1`): declare `D_001A7430` unsized (`extern s32 D_001A7430[];`, read as `D_001A7430[0]`), because retail reaches it with a compiler `lui`, and write the flag as `s32 flag = (screenId >= 0) ? D_001D5B78[screenId] : 0;`. That takes the diff from 1,680 to 210; what is left is the branch shape (which instruction lands in the `bltz` delay slot). The forms that get the registers right changed the branch layout, and the forms that got the layout right changed the registers. It matched in the first final pass under `@ps2as`, with a one-element alias of `D_001DA050` and `do { flag = 0; } while (0);` (found with f2's `do { } while (0)` brute force).
- **Resolved: "a match in isolation can still differ in the full build".** `func_003AEDC8` and `func_003AED08` passed `check.py` but failed the full build with two `$gp` stores swapped. The cause was the tool, not the build: it masked every relocated field, and two stores through `$gp` differ only in their relocated offsets, so the wrong order looked identical. `check.py` now fills relocations in with the symbols' real addresses and compares them in full (checked against all 617 previously matched blocks: no false failures). The `#define D_001D5B34 ...` hack macros above some functions still replace a later `extern` of the same name; `#undef` it in your block (see `func_00389908`).
- About 20 matched functions use inline `__asm__` or a hand-rolled `$gp` register. That is not allowed now; they are clean-up candidates and must become plain C or near misses.
- **Init order before a loop:** loop-invariant constants gcc hoists (a divisor `3`, a `&symbol`) land between the loop variable's init and the other inits. To reproduce retail's order, name them as locals and assign in retail's order (`i = 0; three = 3; sent = &sym; off = 0;`, then `for (; i < 3; i++)`). Matched the three 3-slot hash lookups func_003E4890/4918/4DA0.
- **Not allowed now (history; the function stays a near miss):** **A quad store that the scheduler moves behind a narrow store:** make that one `sq` store volatile (`*(volatile u128_t *)(d + 0) = ...`) and keep the narrow stores plain; retail's `sq, sb, sh` order then holds (`func_0037FEE8`). Also: a down-counting `n` that retail keeps in the callee-saved register ahead of a copy of `q + 0x41DC` wants `n--` in the loop instead of `m = n - 1; n = m` (`func_003E0478`). A `do { h = f(&s, 1); } while (h == 0);` poll loop followed by `do {} while (g(h) >= 0);` matches the retail pair of raw-branch loops (`func_003AB180`).
- **`D[idx].field` against a cached pointer:** `&D[idx].f380` folds the field offset into the symbol (`lui; addiu D+0x380; addu idx*size`), while `p + 0x380` from a cached `p = &D[idx]` adds it to the register. When retail shows an extra copy of the element address, or an argument built as `(D + off) + idx*size`, write that access as `D[idx]...` with a struct type for the element instead of reusing `p` (`func_003809F0`; also matched with `u128_t` fields for the `lq`/`sq` pairs). A 16-byte struct of `u8[16]` assigned through a local gives the `ldl/ldr, sdl/sdr` pairs (`func_003E0930`). Passing the callee's float arguments before its integer ones in the prototype moved a `mov.s` into the right slot (`func_0038CA08`).

### Forms this compiler has never been seen to produce (2026-10)

Two shapes showed up while trying to match the smallest functions still filed as `plain`.
Neither is a C problem: if your target's `.s` contains one of them, move on to another
function rather than rewriting the C.

- **`lq $at` - `$at` as a data register.** Compiling the same three-quadword copy
  (`*(u128_t *)` at 0x00/0x10/0x20) with the range's flags allocates `$2`, `$3`, `$6`;
  `$at` is not something this compiler hands to a value. In `frontbin.elf` the only
  files containing `lq $at` are the nine under `asm/handwritten/`, plus
  `func_00388E58` and `func_00388E38`, which are now `ASM_FUNC` there too (2026-10-05:
  `tools/todo.py` files `lq`/`sq $at` and the COP0 performance-counter ops as hand-written).
- **`sq $zero` - a 128-bit zero store.** `*(u128_t *)p = 0;`, `(u128_t)0` and a named
  `register u128_t z = 0;` all compile to `por $2,$zero,$zero` followed by `sq $2,0($a0)`:
  the TImode zero is materialised in a register first, so retail's single `sq $zero` is out
  of reach from plain C. It was matched on 2026-10-05 with a `QZERO` inline-asm macro (see the
  blocker pass below), which is not allowed now: such a function stays a near miss.

A third shape from the same pass, `sq $31` / `lq $31`, has a workaround rather than a dead
end - list the function in `config/frontbin/sq_ra_funcs.txt` (*Functions that save `$ra` with `sq`*
above); `tools/pr_check.py` now warns when a function that is C in `src/frontbin/` has the
signature in retail and is missing from that list. What the pass did settle is that no flag on this compiler produces it, which is
what the next section is about.

Reproduce any of them from the repo root:

```
python tools/check.py <your attempt>.c func_XXXXXXXX      # the ordinary judge
python tools/check.py <your attempt>.c func_XXXXXXXX --all-modes   # 4 flag/assembler combos
```

Two more things worth knowing before a long session: `sizeof(long)` is 8 here, so the
64-bit type is `unsigned long` (`long long`, and therefore `u64`, is 16 bytes and any
arithmetic on it fails with `unsupported wide integer operation`), and the literal suffix
`ULL` is rejected by this compiler - use `UL` or a cast.

#### The SN ProDG 2.0 package emits the `sq`/`lq` saves natively

The `sq $31` layout is not only reachable through `asm_filter`: the **SN ProDG 2.0**
package's `ee-gcc295.exe` (gcc 2.95.2, SN build v2.73a - a separate download, not the
3.01 package this repo builds with) emits `sq $31` / `lq $31` by default, puts `$ra` in
the highest callee-saved slot with `$s0` lowest, and does not know `-fopt-stack` at all
(`cc1.exe: Invalid option`).

Measured on the C bodies of `func_0038C888` and `func_0038C9D8`, **assembled and compared
word for word** rather than read off the `.s`: 2.0's output for both is byte-identical to
retail, the `jal` operand aside, while 3.01 at the project flags differs in the two `$ra`
accesses only. Nothing in 3.01's flag space moves those two: `-O1/-O2/-O3/-Os`,
`-G0/-G8/-G16/-G24`, `-mgp64`, `-mips3`, `-mips4` and `-fopt-stack`/`-fno-opt-stack` all
keep `sd $31`. On this compiler `-fopt-stack` only governs the **`$s` slots** (16-byte
`sq` without it, 8-byte `sd` with it), never `$ra` - which is why the layout the filter
reproduces was never a flag away.

The same test on the two larger matched functions, `func_003AAF88` and `func_003C0B10`,
splits the claim in two. 2.0 gets retail's **frame** right with no filter at all: same
frame size, `$sN` in the 16-byte `sq` slot at `0x10*N`, `$ra` highest - where 3.01 needs
`-fopt-stack` removed and the filter's rewrite to get there. But it does not emit them in
retail's order: retail saves the registers ascending by slot, 2.0 descending (on
`func_003AAF88`, 2.0 saves `$s3, $s1, $s0`, retail `$s3, $s0, $s1`). Those two bodies are
the C that makes 3.01 match, so a compiler swap would mean re-tuning them, and re-tuning is
what the filter avoids. 2.0 also emits the `lq $at` bodies above exactly as 3.01 does, and
the `sq $zero` body too (`por $2,$zero,$zero` + `sq $2,0($a0)`, unchanged), so the package
is a stack-slot signature and nothing else.

One of those tests is done: `func_003A9E60` (0x8C, reconstructed from its retail
disassembly alone, flags `-O2 -G8 -mno-split-addresses -mno-check-zero-division` plus the
unsized `D_001D5C78[]` declaration the range needs) comes out with retail's frame and slots
under 2.0 and with 3.01's layout under 3.01 - but both compilers leave the **same 22 of 35
words** different, all of them the argument-copy registers (`a0` lands in `$s1` where retail
uses `$t5`, and the `lui` takes `$2` where retail takes `$12`). So 2.0 does not fix this
one's schedule either; that half looks like allocation, not a compiler version.

So the layout is a real version signature and the arithmetic is unsettled. It is four
functions, and only the two wrappers are byte-exact; nine of the 13 still have no C block
at all. Most of the file still matches 3.01 at the project flags, so retail only
**possibly** looks like an intermediate SN release - 2.95.3-era instruction selection with
the older 16-byte stack slots - rather than a mix of two packages. Writing C for more of the
13 and running the 2.0 package against them is the cheap next test; the compiler/flag
matrix in `docs/compiler_matrix_findings.md` (15 builds) does not include this package.

## Patterns from the first agent batches (2026-10-03)

Each was confirmed by a function that now matches in the full build.

- **Pass the incoming parameter to a K&R call that doesn't need it.** In `func_003B7568`, `cb(a)` instead of `cb()` raises the parameter's priority, which flips which of two saved registers it gets.
- **Two loops, two counters.** Reusing one `i` for both loops of `func_003B2958` swapped `$s0`/`$s1`. A separate `j` for the second loop, indexing a `[2]`-sized `$gp` array as `D_arr[j]`, gives retail's pointer plus count-down loop (`bgezl`).
- **Table walk with an end marker:** `for (p = arr; *p >= 0; p++)` gives `move; lw; bgez; addiu` with the increment in the delay slot (`func_003D46E0`). A do-while with `v = *p++` doesn't.
- **`lui $v0; lh $v1, %lo(X)($v0)`** (the load into a different register than the `lui`) comes from reading through an unsized array alias, `X[0]`, not a raw `*(s16 *)0x1CD018` (`func_003A3430`).
- **Reuse the incoming pointer as the walking pointer** (`arg += 8; ... func(arg, arg + b, ...)`) instead of new `p`/`q` locals, which add a `move` and change register numbers (`func_003972A0`).
- **A select assigned to a new local** (`q2 = q - w`) changes which instruction fills the `jal` delay slot (`func_003ABB60`).
- **Two reads of the same `lui` global around calls** need a scalar `extern s32 X;` under `@ps2as`; an unsized array shares one `lui` across the calls (`func_003ABB60`).
- **`(flag >> 24)`** gives a bare `sra` where retail has one; the callee's parameter order sets the order of float register setup (`func_003A4DC8`).
- **Declaring a callee `s32` instead of `void`** changes the `$v0`/`$v1` choice around the call; a K&R zero-argument declaration leaves the argument registers untouched (`func_003B8968`).
- **Index an array in a loop instead of walking a pointer** (`func_003C1950`): `e[i].t`, `e[i].id` let gcc strength-reduce to a pointer whose start sits in a temp and is `move`d into the saved register, as retail does. A hand-written walking pointer gets other registers.
- **Count-down loops written `for (i = N; i != -1; i--)`, one counter per loop** (`func_003A9768`, `func_003A8060`): this decides which register holds the `-1` constant.
- **Store order sets delay-slot filling** (`func_003A5A90`): zero stores written `t[1]`, `t[2]`, `t[3]`, `t[0]` matched; ascending order did not.
- **K&R definition** when callers use an unprototyped `extern void f();` with another argument count (`func_003A5A90`); a prototyped definition makes those callers fail with "too few arguments".
- **64-bit values are `long` / `unsigned long`**, not `u64`/`s64`, or gcc reports an unsupported wide integer operation (`func_003D14D0`).
- **Float arguments need a prototype for the callee**, or gcc promotes them to double (`func_003A5DF0` went from 33 to 63 diffs without one).

## Patterns from agent batches 4 to 17 (2026-10-04)

Each was confirmed by a function that now matches in the full build.

- **The callee's return type changes the caller.** `extern void f();` versus `extern s32 f();` (or the real `s32 *`) moves registers and scheduling even when the result is unused. It was the deciding change for `func_003B0608`, `00397380`, `003C8D50`, `00384C98` and `003E0FC8`. Try the callee's real prototype, or `s32`, before anything else.
- **Size hints choose the address form of a scalar extern:** `__asm__(".extern X, 4");` before first use gives `$gp`; `.extern X, 16` gives the macro `lui` form even for a scalar; an unsized array read as `X[0]` gives the split `%hi`/`%lo` form (`func_003C8D50`, `003B0608`, `0039AAF0`, `0039C028`).
- **One variable, two address forms:** when retail reads the same address through both `$gp` and `lui`, declare two names for it and give only one the `.extern X, 4` hint (`func_003968F8`, `00396120`, `00396680`, `0038EB10`). This is one of the cases where an alias is a real technique, not a leftover.
- **Adjacent `$gp` objects need separate names**: an array base for several of them gets shared by gcc (batch 15).
- **A switch tree with `slti`:** a `switch` with only `case 1` and `case 2` gives `beq; beq`; retail's `beq 1; slti 2; ...` tree appears when the switch also has a `case 0:` (`func_003A6520`).
- **A one-element array declaration** (`u8 D_X[1]`, or a sized `T D_X[2]`) instead of `u8 D_X[]` changes whether the address is built before the call or split around its delay slot (`func_003E1F40`).
- **Calling a K&R extern with fewer arguments than it reads** matches retail where it passes only some registers; adding the extra arguments adds instructions (`func_003BE418`, `func_0039C028`).
- **Reuse the parameter as the working pointer** (`a0 = ...; a0[0] = ...`) to keep it in `$a0`; a fresh local lands in `$v1` (`func_0039C028`).
- **Early returns:** a `bnel` followed directly by the "return 0" block comes from `if (x == 0) return 0;`, not from nesting (`func_003822C8`).
- **Stores of different constants to one global in several branches:** write the separate stores with no result variable; gcc tail-merges them into one `sw` with retail's registers (`func_00396680`).
- **Index a struct-array member each time** (`D.row[a].f`) rather than taking a row pointer once; the pointer form folds the member offset into the base register (`func_00395AC8`).
- **Same family, different data:** adapt a matched sibling and change only the callee and the table global (`func_003E1F40` from `func_003E1E50`).
- **Extra compiler flags are a per-file question, not a per-function trick.** The original build set flags per source file, so a flag a function needs must also leave every other function in its file matching. Check that before adding one: compile the file's other C functions with it (`check.py --flags="-fno-..."` on each).
  - `-fno-force-mem` (needed by `func_0039A040`): all 88 C functions in `3958F0.c` still match with it, and 1069 of all 1123 do. It's the flag on `3958F0.c`'s file line. It is **not** file-wide in practice: `func_00397490`, `func_0039ABB0`, `func_00399C90`, `func_003959A8` and `func_0039A3B0` need `-fforce-mem` (the default) and each has a single-function override without it (see the `func_00397490` section below; the `or`/`addu` operand order shows it). So either the file boundaries there are wrong or the original did not set it per file.
  - `-fno-schedule-insns` (now only `func_003C8D50` and `func_00384C98`; `func_003AD650` lost its override, see the blocker pass below): 524 of the 1123 C functions change with it, so it wasn't a project-wide flag. Around those two, the C functions that still match with it form runs of only 3 and 1, so each would have to be its own small source file. That is possible (our file boundaries are estimates), but unproven. They stay single-function overrides; if more neighbours turn out to need the flag, that's evidence for a small file there. A test on 44 scheduling near misses (`tools/check.py --flags="-fno-schedule-insns"`): 0 matched and 44 got worse, so the flag is not a general fix for instruction-order near misses.
  - `-fno-schedule-insns2` was on: only 392 of the 1123 C functions still match without it.

## Patterns from agent batch 19 (2026-10-05)

- **A `long` working variable keeps a `movz` chain:** with `int`, gcc folds `r = 1; if (x == -2) r = 0;` into `xor`/`sltu`; with `long` (and a `long` return) it emits retail's `movz` chain.
- **`t = &A; p = &B; if (a0 == 0) p = t;`** loads the two addresses in the same order as retail's `movz $a2, $a1, $a0`; a ternary or if/else swaps them.
- **Statement-order search pays off early:** the order of a function's first few statements alone moved results between 5 and 46 differing words; a brute-force search over them matched `func_00394B38` and `func_00394F78`, and a random-swap search over store order matched `func_0039C7B0` and `func_0039C8A8`.
- **`for` versus `do { } while`** can change which registers a loop counter and its copy get (`func_003D98D0` needed `for`). Try both.
- **Not allowed now (history; the function stays a near miss):** **A guarded hardware wait loop:** `if (r & 0xF0) { do {} while (r & 0xF0); }` with `r` a `volatile` hardware register read gives retail's shape; a plain `while` gives the unguarded form (`func_003AC5E0`).
- **Callees with float arguments:** if retail loads `$f13` before a call, the callee's real prototype has more float parameters than the call seems to need. Check its definition.
- **No `#define` in a function block:** `split_text.py --refresh` copies a block's macros into later files like any declaration.
- **`-fno-schedule-insns` never helped a near miss:** tried on about 25 near misses, it made all but one worse and fixed none. The remaining differences in near misses are register allocation and statement order, not scheduling.
## Patterns from the blocker pass (2026-10-05)

A pass over the remaining `INCLUDE_ASM` functions, sorted by what each one needs. Each item below was confirmed by a function that now matches in the full build.

- **Not allowed now (history; the function stays a near miss):** **`sq $zero` is inline asm, resolved.** The compiler never stores a quadword zero directly: a zeroed `u128_t` always comes out as `por $v0, $zero, $zero; sq $v0`. Retail's bare `sq $zero, off(reg)` (the 16-byte zeroing loops in `func_003A0010` and `func_003A2DF8`) therefore came from an inline-asm macro in the original source, the same conclusion Lombyte's `qzero.h` reached for other Insomniac binaries. Use

  ```c
  #define QZERO(p) __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(p))
  ```

  An asm with no outputs is implicitly volatile, so the `__volatile__` is just documentation; the `"=m"` output form is the only one that is not. Write the loop with the index in the address, `QZERO(D_1A3100 + i * 0x10)` for `i = 3; i >= 0; i--`, not with a running pointer: the running pointer makes gcc keep a second `lui` in a saved register and grows the frame (`func_003A0010`).
- **Which register comes first in `addu`.** For a C pointer plus an integer gcc always puts the pointer first in the tree, so `base + off` gives `addu $v0, $base, $off`. When retail has the offset register first, write the sum as integers with the offset on the left: `(u8 *)(off + (s32)b)`. For a loaded base, load it into a local first (`g = *(s32 *)0x1D4B38; base = g + off;`). Matched `func_0037F4F8` (a VU0 function: `lqc2`/`vadd.xyz`/`sqc2` in `__asm__` around plain `u128_t` copies).
- **A `do { } while (0)` macro changes scheduling.** Wrapping the loop's increment in a statement macro, `#define ADVANCE(o) do { (o) += 0x27E40; } while (0)`, reorders gcc 2.95's output enough that `func_003AD650` matches at the project flags; it needed `-fno-schedule-insns` before. Try this before reaching for a flag when the diff is only the position of an increment or a store.
- **Hand-written code the tools now flag.** `tools/todo.py` classifies as hand-written any function that reads or writes the COP0 performance counters (`mfpc`/`mtpc`, which spimdisasm cannot decode) or that uses `$at` as the data register of `lq`/`sq`; no compiler emits either. Seven functions moved to `asm/handwritten/` on that rule: `func_0039BC18`, `0039BC40`, `0039BC70`, `0039BC80`, `0039BCC8` (performance counters) and `func_00388E38`, `func_00388E58` (`$at` quadword copies).
- **Keep one prototype per callee across files.** The split build copies declarations from earlier files, so `extern void func_13B620();` in one file and `extern s32 func_13B620(void);` in another is a compile error in `pr_check.py` and the file check of `try_in_context.py`. Fix the older declaration (it was `void` only because that file ignored the result) rather than adding an alias.

## Patterns from `func_00397490` (2026-10-05, 0x21CC bytes)

The memory card state machine in `3958F0.c`, the largest function that was still `INCLUDE_ASM`: an outer 32-way switch on the state field and seven nested switches (9 jump tables, now emitted by gcc). Matched at `@ps2as` without `-fno-force-mem`.

- **`-fno-force-mem` shows as operand order.** `D.f188 += x` compiles to `addu rd, f188, x` in retail. Under `-fno-force-mem`, gcc's `expand_binop` swaps commutative operands while the first one is still a memory reference, giving `addu rd, x, f188`. Dropping the flag for this function took it from 280 to 238 aligned diffs.
- **An address-taken small-data symbol under `@ps2as` is one `la` macro.** Declaring `D_001D545C` as a scalar `extern u32` (its real type) instead of an unsized array gave retail's register allocation: `la` is one instruction (one pseudo) to gcc, the split `%hi`/`%lo` form is two. `&D_001D6318` in the same function is reached through `$gp`, so it gets `__asm__(".extern D_001D6318, 4");`. That pair is what identified `@ps2as`.
- **Where retail recomputes the global base (`addiu $X, $s2, 0x2430`) only after a join, the source has a real if/else join; where it reuses the case's base register, the source has separate exits** (duplicate tails ending in `break`) that gcc tail-merges. Write the struct accesses directly (`D.field`), no local pointer.
- **Cross-jumping keeps the later copy.** An earlier duplicate tail becomes a jump into the later one, so when retail jumps forward into another case's code, both tails must be byte-identical (same store order and registers).
- **Error-code chains store the field in every arm** (`if (r == -5) D.f16C = 0x15; else if ...`). An `e` temporary turns the last arm into a `movz`.
- **Reset-store order:** retail's `f154, f15C, f14C` comes from source order `f15C = 0; f14C = 0; f154 = 0;` (the store rotation documented above). Most of the last 150 diffs were store order.
- **No shared temporaries across the cases of a big switch.** One function-level `s32 t` reused in several cases pushed values into callee-saved registers everywhere; making them block-local took the diff from 544 to 278.
- **Strength-reduced loop pointers:** retail keeps three pointers into a 0x40-byte table (`entry`, `entry+0x20`, `entry+0x25`). That came from `de = &tbl[i]` for `de->size`/`de->name[4]` plus `tbl[i].name` for the string arguments; other combinations gave two pointers.
- Smaller ones: `func_11B2E8` (sprintf-like) must return `s32`, and `func_0038E6D0` is called through an `s32` cast, to keep `$v0` live. A `total + 1` that retail evaluates first needs its own temporary, since gcc reassociates `total + 1 + q`.
- **Tooling for very large functions:** `check.py`'s positional diff is unusable until the size matches. An aligned diff (difflib over the disassembly, branch targets mapped to labels) made progress measurable from 883 diffs to 0.

## Patterns from batch 21 (MMI bucket, 2026-10-06)

Each was confirmed by a function that now matches in the full build.

- **Check drafts with `try_in_context.py`, not only `check.py`.** `check.py` sees the extern declarations of earlier blocks but not their definitions, so a callee defined earlier in the file becomes an implicit `int` and gives false diffs (`func_003D1650` went from 23 diffs to MATCH in context; `func_0037F588`).
- **GS/GIF packet writers:** `long **pp` with `*(*pp)++ = value;` under `@ps2as` matches quickly. If callers declare the first parameter `s32`, define it `s32` and cast inside (`func_003D1E68`).
- **An earlier block's `.extern X, N` hint forces `$gp` for the rest of the file.** Where retail uses `lui` later in the file, use a per-function alias with no hint. Ps2EeAs still uses `$gp` in delay slots (`func_003D2878`).
- **Not allowed now (history; the function stays a near miss):** **A volatile read steers delay-slot filling**, since gcc keeps volatile loads out of delay slots (`func_00380AB0`).
- **Write symbol+offset constants inline** so related-value CSE picks retail's anchor register (`func_00381F18`).
- **`$s` registers saved with `sq` but no `$ra`** take the same fix as the sq-`$ra` functions: an entry in `config/frontbin/sq_ra_funcs.txt` and no `-fopt-stack` (`func_003D1978`, `func_003D3780`).
- **Rebase:** a `u8`-array access to `X + off` followed by stores through a local struct pointer gives retail's `addiu $s0, $s0, -off` (`func_003B8168`).
- **Chained assignment** `a = b = f()` gives retail's store order (`func_003BA490`).
- **Ps2EeAs fingerprint:** it expands the constant `1 << 63` as `addiu -1; dsll32 31` (`func_003B82C0`).
- **Not allowed now (history; the function stays a near miss):** **`plzcw`** has no C form: `__asm__("plzcw %0, %1" : "=r"(d) : "r"(d)); d = 30 - d;` (`func_003D1650`, `func_003D1E68`).
- **A dead 16-byte stack copy** is an aligned 4-float struct local, not a volatile `u128` (`func_003CB748`).
- **Open question:** `func_003CB5B0` declares `D_001D9350` as `s32[2]` with `.extern D_001D9350, 8` to get the `$gp` form, but retail reads 16 bytes from it with `lq`. The 8 steers codegen and is probably not the real size.
- **Fixed (batch 29):** the sq-`$ra` rewrite in `asm_filter.py` used to treat `ld $16/$17` stack-argument loads as restores. It now counts only loads of a saved (register, slot) pair, and `func_00386D98` matched.

## VU0 j-form: one asm statement per instruction

> **Allowed again since 2026-11-08, for VU0 only** (AGENTS.md, Matching rules): asm for the VU0 macro-mode/COP2 instructions the compiler cannot emit, one block per VU0 sequence with real operands and clobbers (or shared helpers in a header), as the original source plausibly had it. Never asm for ordinary EE instructions or to steer allocation, scheduling or delay slots. Between 2026-11-06 and 2026-11-08 it was not allowed.

Status (2026-10-07): the leading explanation for VU0 code that is interleaved with ordinary code, and kept in the build. The maintainer has not formally approved it yet: each such block starts with a `PROVISIONAL, VU0 j-constraint form` comment, its override line in `config/frontbin/text_parts.txt` says `PROVISIONAL VU0 j-constraint form`, and agents commit each one separately as `func_X (jform)` so it can be dropped. `grep -rn "PROVISIONAL" src/frontbin config/frontbin/text_parts.txt` lists them. 38 frontbin functions are matched this way (first `func_003DCD08`, `func_003C0188`, `func_003813E0`; then 27 in round d and more in the final passes). Flag any new use in the PR.

### The form

Each VU0 instruction is its own **non-volatile** `__asm__` statement. VU0 values are TImode variables, and their operands use the `j` constraint, which is SN cc1's VU0 register class:

```c
typedef int Q_3DCD08 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3DCD08;
Q_3DCD08 x, y, r;
__asm__("lqc2 %0, %1" : "=j"(y) : "m"(D.v0));
__asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001D9E90));
__asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(y), "j"(x));
__asm__("sqc2 %1, %0" : "=m"(*(V4_3DCD08 *)b) : "j"(r));
```

gcc allocates the `$vf` registers and its scheduler moves ordinary instructions between the VU0 ones, the way retail does. A volatile asm is a scheduling barrier in gcc 2.95, and a non-volatile `sqc2` asm without a register input ties with a neighbouring move and keeps source order; with `j` operands the `sqc2` depends on the `vsub` result, so the move goes first, exactly as retail (`func_003C0188`: the best volatile form stops at 2 diffs, the j-form matches). The one-block volatile form in [VU0 code: inline asm](#vu0-code-inline-asm) still matches where retail keeps the VU0 sequence together; try the j-form when retail has argument moves, constants or `lq`/`sq` copies between VU0 instructions.

- gcc prints the registers as `vf1` (no `$`); Ps2EeAs accepts that.
- The `"m"` operand's type decides the address form. A struct of four floats (BLKmode) gives retail's split form, `lqc2 vf1, %lo(D_00222480)($16)` with the `%hi` kept in a saved register. A TImode operand gets its full address in a register (`addiu; lqc2 0($r)`). A small-data scalar (`extern f32 D_001D9E90;`) is printed as the bare symbol and Ps2EeAs expands it with `$at` (`func_003DCD08`). Vectors that are `lqc2` operands on the stack need `__attribute__((aligned(16)))`.
- A `j` value that is live across a `jal` is spilled with `sqc2`/`lqc2` to the stack (vf1 to vfN are call-clobbered, there are no callee saves), which is where many of retail's `sqc2`/`lqc2` to `$sp` come from.
- Struct arguments passed by value are passed by reference under EABI and copied by the callee. Retail's `sqc2` into a temporary before such a call is written as an `sqc2` with an `"=m"` output into a local, then a by-value call (`func_00383BB0`).

### Getting retail's registers

- **Statement order matters**, and so does which variable each temporary and result uses. Write the statements in retail's order. Give each `vsub` a **fresh output variable** rather than writing the result back into an input (`func_00383BB0`: `y0`, `y2` for the two differences of the cross product). `func_003DCD08` needed a separate result variable per operation in one case and the result in the first operand's variable in another; try both.
- **The load order decides the vf1/vf2 roles.** When the same VU0 sequence appears with the roles swapped, use two `static __inline__` helpers that differ only in which operand they load first (`vaddA_383BB0` loads `a` then `b`, `vaddB_383BB0` loads `b` then `a`; `func_003869E8`'s helpers load `a` then `b`).
- **Block-local temporaries** let repeated blocks get different registers, the way retail's do (`func_003B92B8`, `func_003B9DA8`).

### `-mvu0-use-vf0-vfN`: what it is, and why N = 2

SN's cc1 only accepts `j` with the target option `-mvu0-use-vf0-vfN`; without it any `j` operand fails ("fixed or forbidden register ... for class VU_REGS"). Since 2026-10-07 every frontbin and boot_elf line in `text_parts.txt` carries `-mvu0-use-vf0-vf2`, so the j-form needs no extra flag. What agent m1 found (round k):

- **Origin.** The cc1 help text is "Specify the range of vu0 registers to use", and the cc1 binary's build path is `C:\usr\PS2\gcc-2.95.3\gcc`: it is Sony's own gcc patch set, not an SN addition. `j` selects register class `VU_REGS` and is the only VU0 constraint letter SN has; there are no other `-mvu0-*` options.
- **Parsing.** The text after `vf0-` is compared with the names `vf0` to `vf31`; on a match vf1 to vfN become allocatable. Anything else (`vf32`, `vf99`, `31`, `abc`, empty) silently means vf31. `vf0-vf0` gives no registers, so every `j` asm fails. Only `vf0-` is accepted as the lower bound (`-mvu0-use-vf1-vf8` is rejected). vf0 is always fixed.
- **It never makes the compiler use VU registers on its own:** TImode copies stay `lq`/`sq`. Explicit `"vfK"` clobbers work with or without it.
- **Other compilers.** Sony's Windows builds (2.9-ee-991111 Win, 2.95.2-273a/274, 2.95.3-107/114/136) accept the option and `j` with identical behaviour. 3.2-040921 has a rewritten version (`-mvu0-use-REG1-REG2`, class `VU0_REGS`, letters `j` and `C` plus Q/R/Y/Z for the VU0 special registers). The Linux builds (990721, 991111-01, -dtls, 991111a, 2.96) reject it.
- **N changes ordinary code.** The range adds N to `n_non_fixed_regs`. In GCC 2.95.3's loop.c, `scan_loop` hoists invariants against a threshold of `(call ? 1 : 2) * (1 + n_non_fixed_regs)` and `strength_reduce` uses `(call ? 1 : 2) * (3 + n_non_fixed_regs)`, so N moves loop-invariant hoisting and induction-variable reduction in functions with no VU0 code at all. Examples: `func_003BAE98` has 122 diffs with vf31 (`i < 2` is hoisted out of the inner loop) and matches with vf2; `func_003A1438` has 234 with vf31; `func_003D3FA0` stays at 4 with vf31 and matches with vf2. Old drafts measured with vf31 or without the flag must be re-measured.
- **Only N = 2 fits everything.** A sweep of the 38 frontbin j-form matches over N = 1 to 32: 31 match at 2 to 32, three only at 2 (`func_00383BB0`, `func_00392A40`, `func_00392DD8`: at N >= 3 the allocator uses vf3 where retail has vf2), `func_003A1438` at 2 to 24, `func_003BAE98` at 2 to 28, `func_0039EB98` at 1 to 32. N = 1 can't compile 37 of them.
- **Global builds.** With the flag on every line: at N = 2 only `func_003B22C0` (and its boot_elf twin `func_003B7A80`) break, two prologue constants hoisted in swapped order; at N = 3 or 4 five functions break, including `func_00381A50`, which has no VU0 code; at N = 31, 22 break. i5bootn matches at every N. `func_003B22C0` matches under vf2 once the struct global is used directly instead of through a local pointer (`D_00160C40_003B22C0->f4954, (s32)D_00160C40_003B22C0->f7080` in the call, no `S_B22C0 *p` local); that form matches at no flag, vf1 and vf2 and fails from vf3, another N <= 2 bound. The same edit fixed `func_003B7A80`.
- **Retail evidence.** All compiler-allocated VU0 code in retail (37 matched j-form functions and 13 j-form near misses) uses only vf1 and vf2; hand-written code goes up to vf31. The functions that match only at N = 2 show the allocator really had just two registers.
- **What the source probably was** (m1's guess, not proven): SCE or Insomniac vector macros or inline functions written with `"j"` operands, compiled everywhere with `-mvu0-use-vf0-vf2`.

**Adding the flag to a line.** It is placed first on lines that did not have it before. Appending it instead changes which neighbouring lines have equal flag lists; `build_text.py` merges runs of equal lists into one slice, which exposes declaration conflicts (the first one is `func_003A0D58` in `39FFC8.c`). When you add an override, copy the neighbouring line's flags as they are written.

## Patterns from batch 23 (MMI bucket, 2026-10-06)

Each was confirmed by a function that now matches in the full build.

- **Not allowed now (history; the function stays a near miss):** **`sq $0` as non-volatile asm with a memory output**, `__asm__("sq $0,%0" : "=m"(*(u128_t *)(p + off)));`, schedules like an ordinary store. The volatile `"r"` form of `QZERO` blocks scheduling around it (`func_003BD668`; `func_003B7B50` went from 43 to 5 diffs). Use the `"=m"` form when retail moves other instructions across the store.
- **Adjacent `@ps2as` overrides merge into one slice**, and an earlier block's `.extern` hints then reach the later functions of that slice. After adding an override, run the full build, and fix any function it breaks with per-function alias names (`func_003D2F90`, after `func_003D2878`'s override). `try_in_context.py` checks only the target function, so only the full build catches this.
- **A loop-invariant constant that retail adds with `addu`:** declare it as a `long` local before the loop and add `(s32)` of it: `long base = 0x590000; id = i + (s32)base;` (`func_003B3DB8`).
- **`addu` operand order:** read back the field you just stored, `p->h0 = c; p->h2 = p->h0 + p->hE;` (`func_003A6C30`).
- **A nested select's branch layout:** put the inner test's xor in its own block-local temporary, `else { s32 e = k ^ 0x259; m = e ? 0 : 8; }` (`func_003B8440`).
- **The callee's return type again:** declaring `func_12A9F0` as `s32` instead of `void` fixed a `$v0`/`$v1` swap in a final 64-bit pack (`func_00393E90`; its sibling `func_00393A18` needs the same).
- **An indexed loop with two increments**, `for (i = 0; i < n; i++, list++)`, matched where a single induction variable didn't (`func_003936A8`). A second index incremented in a call argument, `f(o, 0, i++)` next to loop counter `j`, is the same lever (`func_003B07B8`; using `j` there left 159 diffs).
- **Integration note:** `config/frontbin/divs_nops.txt` is keyed by function. When a patch changes a function's `div.s` padding count, that line has to travel with the function; a stale count makes the function longer by 4 bytes per `nop` and shifts everything after it (`func_0037D200`, 2 to 1).
- **Tool note:** `try_in_context.py` ignores `config/frontbin/localdecomp_flags.txt`, so an `@ps2as` candidate can only be checked in place once its `text_parts.txt` override exists.

## Patterns from large-function batch 3 (2026-10-06)

From the agents' reports and near-miss headers; each was found while matching or nearly matching a large function.

- **One C variable reused for unrelated values** decides close register ties.
- **Callee prototypes decide scheduling:** float/int parameter order and `long` parameters change the caller; when unsure, try every order.
- **Declare temporaries inside the one branch arm that uses them.**
- **Loop invariants hoisted by the second loop pass take the first callee-saved registers.**
- **Constants fold into adds but not multiplies** (`i * lh` keeps its register).
- **Many "mmi" bucket functions are plain C**: their 128-bit ops are `-fcaller-saves` spills of ordinary values, not MMI code.

## Patterns from batches 27 and 29 (2026-10-06)

Each was confirmed by a function that now matches in the full build.

- **Read the assembler off the retail bytes.** No `nop` after an `mfc1` whose result is used by the next instruction means Ps2EeAs (`@ps2as`). `func_0038BB50` (0x86C) had stalled for several batches on the default assembler; with `@ps2as` it matched.
- **A `do { ... } while (0)` around a loop** changed loop alignment and register weights enough to finish `func_0038BB50`, with no empty asm needed.
- **Two stores to the same object can be written in either order;** try both (`func_00386D98`: the `q+0x10` store comes after `q+0x48`).
- **Struct-member reads vs cast-pointer reads.** This gcc runs without strict aliasing, so a load through a cast pointer is untyped memory and the scheduler keeps stores to plain globals after it. Struct-member loads don't conflict with stores to fixed scalar globals. Reading a header through `struct { s32 x[0x27]; }` instead of `((s32 *)hdr)[i]` was the biggest gain on `func_003B6528`.
- **Float constants:** write the exact decimal of retail's bits, including truncated ones (`0.0749999955f` is `0x3D999999`, not `0.075f`) (`func_003A0EB0`).
- **decomp-permuter is useful once its score is replaced** with `check.py`'s own metric (relocations resolved against retail). Its default score tracked `try_func` diffs poorly; with the replacement it improved 9 of 11 near misses in under an hour. Check the semantics of its rewrites before building on them.

## Patterns from rounds d, f, g and k and the large-function batches (2026-10-05 to 10-07)

From the agent reports of the 19-agent round (d), the two final passes (f, g), round k and the large-function batches. Each item names the function that proved it; "near miss" means it was found on a function that still doesn't match.

### Forms still under review

These produce retail's bytes and are in the build, each in its own commit, but the maintainer has not approved them. Mention them in the PR if you use one; prefer a plain-C form when you find one.

- **The VU0 j-form** (section above).
- **Not allowed now (history; the function stays a near miss):** **Empty asm barrier,** `__asm__("" : "+r"(e));` on a computed store pointer: stops combine folding a base offset (-0x1C0) into the `sq` (`func_0037F7A8`). A volatile store also blocks the fold but stays out of delay slots.
- **`cvt.w.s` / `cvt.s.w` as two one-instruction asm statements** (`func_003A4860`, `@ps2as`). Retail keeps `(s32)t` in an FPU register for `t - (f32)(s32)t`; SN gcc always converts through a general register (`mfc1`/`mtc1`), and no other place in retail does this.
- **Not allowed now (history; the function stays a near miss):** **A non-volatile one-block VU0 asm** with explicit `$vf` registers and `"m"` operands (`func_003C0E10`). The volatile version is 8 diffs, all in the prologue save order: a volatile asm cuts the prologue scheduling region, so retail's early register saves need the non-volatile block.
- **One-block VU0 asm with `"m"` operands** of a 4-float struct instead of `"r"` pointers (`func_003E0190`): gives retail's `%lo(D)($hi)` addressing, where a 128-bit operand puts the full address in a register.

### Globals and declarations

- **Not allowed now (history; the function stays a near miss):** **Constant-address globals: `*(T *)0xADDR`.** Spot them by a retail `lui` of `(0xADDR >> 16)` with no relocation. The access is one 2-word macro that reorg never puts in a delay slot and that never uses `$gp`. It replaced every volatile alias in the drafts (`func_003BB398`, `func_003BA108`, `func_003B7EB0`, `func_003BA748`, `func_003B8F50`, `func_003BBFC8`); in `func_003BB398`/`func_003BA108` it let reorg produce retail's `bnel ... sltu`. An earlier example: `*(u8 *)0x1D5477` (`func_0039DB38`).
- **Declared size picks the address form, in both directions.** Under `@ps2as`, an object declared 8 bytes or smaller (`u8[8]`, `s32[2]`, a `fnptr[2]` table, or a one-element alias `T X_f[1]`) is one `la` macro that Ps2EeAs expands to adjacent `lui`/`addiu`, even for a large table reached through an alias (`func_0037F0D8`, `func_0037E878`, `func_003B8F50`, `func_003B5F88`, `func_003B6F28`, `func_003B8440`, `func_00382458`). The `la` is one pseudo, so it also changes local allocation. Because it is one insn, cse or loop can hoist it far from its use; when retail builds the address right at the use, declare the object larger instead (`func_003A1AD0`).
- **A scalar alias, not an array, fixes load order** when one load must stay a single macro (`func_003A2028`: `extern E *D_001DA51C_3A2028;`).
- **A buffer reached from two bases: make it a struct member.** When retail addresses a buffer directly (`sym`) for some accesses but through a register holding `sym - K` for others, declare a struct at `sym - K` with the buffer as a member at offset K: `typedef struct { u8 pad[0x7F00]; u8 buf[0x100]; } S;` at 0x2224A0 for the buffer at 0x22A3A0. Plain writes to the buffer, or a `u8` array at the lower address, get the base wrong. A local `u8 *h = D.buf;` then kept the hoisted `+0x7F00` register (143 diffs without it) (`func_003AB3A8`).
- **Each single-function override needs its own `.extern X, 4` hints** inside its block (s5's batch).
- **A `$gp` load in a short poll loop** used to make `asm_filter.py` give up on the loop (Ps2EeAs then padded it to 7 words). Since round k the filter counts a load or store of a symbol with an earlier `.extern SYM, N` (N <= 8) as one word, so write the loop plainly (`func_003B8840`). The older workaround, the default assembler plus two names for the global (an `.extern X, 16` alias for the `lui`/`lw` macro, the sized name for `$gp`), is what `func_003AD288` and `func_003AFF20` use.
- **Unreferenced rodata after a jump table.** When converting a switch function whose `jtbl_*.s` also holds data words no code references, write those words as a `const` array right after the function (a definition, but in `.rodata`, where retail has those words), so they keep their place when the `INCLUDE_RODATA` line goes: `const u32 D_00318A18[42] = {...};` after `func_003BC218` (0x318A18 to 0x318ABC). With that, the build differs only inside the function itself.

### Callee prototypes and arguments

- **Implicit-int callees in override slices.** A function with its own override slice can't see same-file definitions in other slices, so every same-file callee needs a prototype in the block. Without one the call silently becomes `int f()`: float arguments go as doubles and `$v0` stays busy. `--flags=-Werror-implicit-function-declaration` on `check.py` lists them. Declaring the callee alone took `func_003A0EB0` from 190 to 78 diffs; several old drafts had been measured with implicit-int calls (`func_0039C548` 27 to 25, `func_0039EE68` 411 to 398).
- **Extra callee arguments.** A value retail keeps in an argument register for no visible reason can be an extra argument of the callee: `func_003E8FB0` (the `f44` virtual call takes `s` third), `func_0039E4B0` (a third argument to `func_12F9E0`), `func_00394A20` (`func_00394660` reads a 6th argument from `$t1`). Read the callee before trusting a caller's argument count.
- **Ignored callee arguments still set registers.** When retail loads argument registers the callee ignores, pass them through a per-function alias prototype: `func_0037DCF0_0039A3B0(a0, a2)` (`func_0039A3B0`).
- **Pass-through arguments.** When retail keeps a copy of the first argument in a higher argument register, the function has extra parameters it passes untouched to its callee: `f(p, b, c)` calls `g(p, b, c)` (`func_00135E40`, boot_elf).
- **Stale or missing arguments.** When retail never sets an argument register, the source passed the stale incoming parameter (`func_003E8590(o, ...)` in `func_003EA078`) or nothing at all (`func_003E16B8()` in `func_003DFE10`).
- **Int/float order in prototypes, both the callee's and your own.** Ints and floats get registers independently under EABI, so reordering a prototype keeps the ABI but changes the order (and schedule) of the argument moves. When only argument moves are misordered, sweep the interleavings: one of 35 matched `func_003A0EB0`, 60 were tried for `func_0037D200`'s 12-parameter callee, and `func_003813E0`, `func_003A7090`, `func_003B16B0` and `func_003DBEC8` needed their callee's floats or ints moved. The function's own parameter order works the same way: `f32 g` before `s32 n` gave `func_003A0D58` retail's `$f24`/`$f25`, `f32 f0` before `a3` matched `func_003BA5B8`.
- **Take a callee's parameter order from another matched caller** when the callee is still assembly and callers disagree (`func_003BBFC8`, via an alias of `func_00389FB8` with `func_0038BB50`'s order).
- **`long` locals and parameters.** A `long x = (s32)scr[0];` passed to an `s32` parameter gives retail's `dsll32`/`dsra32` truncation pair after the next call (`func_003813E0`); a `long` result passed to a `long` parameter avoids that pair (`func_003B7378`). A `long` 5th parameter moved `| 0x400000` into retail's slot (`func_003BC568`).
- **Declare operator new as `malloc`.** `func_003ECDC0` is operator new (size, heap). gcc gives a function named `malloc` a result that aliases nothing, so declaring it inside the function as `extern void *malloc(s32, s32) __asm__("func_003ECDC0");` lets the stores that fill the new object move past the store of its pointer into `p->f2C`, as in retail. Under its own name gcc assumes the result may alias `p` and keeps those stores in source order; `__attribute__((malloc))` on the plain name has no effect with this compiler (`func_003EB180`, `func_003E89F0`).
- **A 64-bit return type on a callee whose result is unused.** Declaring `func_13CDF0` as returning `long` (alias `func_13CDF0_003A21C0`) gave retail's `$v1` choices in `func_003A21C0`; with `s32` or `void` local-alloc picks other registers. Try it alongside the `void`-to-`s32` change for `func_12A9F0` (`func_00393E90`) when only the registers around a call differ.
- **K&R `s16` parameter.** A K&R definition with an `s16` parameter stays compatible with an `(s32, s32, s32)` prototype and gives `(s16)(kind - 1)` as `sll`/`sra` for a switch index (`func_0039A3B0`).

### Statement order, combine and scheduling

- **Hide a value from combine.** In `e = A; for (i = 0; ...)`, combine knows `e`'s sign and turns `blez` into `beqz`. `i = 0; e = A;` hides it (`func_003B5D10`).
- **Operand order sets local-alloc ties.** `combine_regs` ties an output to operand 1, so `k = C; k *= t;` (constant as operand 1) gives retail's register where `k = C * t` doesn't (`func_003A73A0`).
- **gcse constant propagation of float constants.** gcse's cprop copies a float constant into call-argument moves in other blocks whenever its set is available on entry, so `1.0` gets rebuilt at every call, where retail keeps it in `$f22`/`$f23`. Assign the constant inside the loop, in the same basic block as its use: gcse doesn't propagate within a block, cse keeps the register, and loop.c hoists the set to the preheader (`func_003AF2C0`, `zero = 0.0f; one2 = 1.0f;` in the loop's else arm). A second, dead assignment does not help here, because availability still holds.
- **A dead second store keeps a constant inside the loop.** A block-local constant with a second, dead assignment has two sets, so loop.c won't hoist it: `{ s32 lim = -1; if (i <= lim) i = 3; lim = 0; }` reproduces retail's `li -1` rebuilt in the loop body (`func_003B23F8`).
- **Loop constants and clamps.** A loop constant retail keeps in a callee-saved register is a variable declared before the loop (`s32 one = 1;`, `func_003947B0`); the literal is neither hoisted nor kept. A clamp `c = K - x; if (v >= c) v = c;` needs a block-local limit variable to get K's register (`func_0039FBD8`).
- **Separate variables for identical constant arguments.** `k1 = 0x98; k2 = 0x98;` passed as two stack arguments stay two pseudos into sched1, so each `li` has one dependent and no longer outranks other instructions (`func_003D1D40`). In the same function, writing `w2 >> 6` inline in the call instead of a precomputed variable moved the operand's last use and fixed the stack-argument store order.
- **Not allowed now (history; the function stays a near miss):** **An empty volatile asm orders two loads.** `b = e->f0; __asm__ __volatile__(""); h = e->f38;` keeps `b`'s load ahead of `h`'s, so `b`'s live range overlaps `e`'s and `b` takes retail's `$v1` (`func_00391E78`). In the same function, the constant 2 that a byte is compared against landed in retail's `$a0` by sharing a variable with the id later passed to `func_0038ED78` (`id = 2; if (b == id) { id = D_001D5EA0; ... }`).
- **Anti-dependence ordering by reusing one variable.** `t = G; H = t; t += 0x10; G = t;` keeps the first store ahead of the later ones (`func_00384B68`).
- **Two sched1 tie-breakers decide most remaining store and load orders** (g4's reading of the scheduler dumps, `-dS -dR`): sched1 prefers the instruction that ends a register's life, then the one with more dependents (`func_003E89F0`, `func_003C9078`, `func_003EB180`, all near misses). `func_003C8ED0` matched once the pointer arguments of both calls were computed into variables before the first call, in retail's load order (`c = b + e->h1C; a0 = b + e->h18; d = b + e->h1A;`, with `c` and `d` used only by the second call): setting `c` and `d` after the first call, or writing them inline, gave 93 diffs, and any other order of the three (or `a0` inline) gave 6 or 7, in the order of the loads and `addu`s and their registers. Compare the store-rotation note under "Codegen tricks that matter".
- **New variables after calls.** A new variable that doesn't cross a call keeps its computation after the call; sched1 hoists the sets of pseudos that do cross calls (`func_003869E8`).
- **Moving one load decides the `jal`-slot argument.** `h = o->f60` moved after an `if (r) {...}` block fixed which argument move lands in the delay slot (`func_003EAAD0`).
- **A store written before the last call fills its delay slot** (`func_003AA0B8`). Halves computed into new variables before a call (`h2 = hh >> 1;`) give retail's `sra` before the `jal` plus one in its delay slot (`func_003BC568`).
- **A load retail repeats** is not CSE'd because of a mode difference or a block boundary: `w = e->bC; w -= 6; if (w < 0) w = 0;` as three statements kept retail's separate load (`func_00384EC0`).

### `do { } while (0)` as a lever

Wrapping one statement or a range in `do { ... } while (0)` (or `for (;;) { ...; break; }`) changes more than it looks:

- **Reference weight.** flow.c adds the loop depth to a register's reference count, so each wrap (or nested wrap) makes those uses count more in register allocation. `do { do { d = D_0037B7D0; } while (0); } while (0);` lifted a table base above the loop counter (`func_003B0A60`, 12 to 2); wrapping the loop's `e` load and update fixed `func_003A2028`; wraps matched `func_0039BEC0` and `func_00391B70`, `func_003E98B8` (permuter find, probably a macro) and moved a prologue `addiu` in `func_00121D70`/`func_00121DB0` (boot_elf). f2's scripts `dwrap.py` (single lines) and `dwrap2.py` (brace-balanced ranges) brute-force the position.
- **Scheduling barrier.** Its loop notes stop the scheduler moving instructions across that point. They cut CSE as well, so a high half shared across the barrier gets recomputed (`func_003A21C0`, near miss).
- **Side effect: `.p2align 3`.** A label right after the loop-begin note is aligned, which can add a padding `nop` (also at the continue label of `do { call } while (0)`). Wrap only the range that needs it.
- Around a loop, it makes loop.c hoist invariant addresses into `$s` registers (`func_00383FD8`, near miss) and can change loop alignment (`func_0038BB50`).

### Register allocation

- **Global-alloc priority** is `refs * floor_log2(refs) / live`; `allocno_compare` truncates it to an integer (x10000) and breaks ties by the lower pseudo number. `tools/regalloc.py` shows it. Splitting a statement raises a variable's refs (f1 on `func_00389D18`); an extra dummy pointer with an initializer, used once after the loop, lengthened live ranges by 2 so two constants tied the way retail's do (`func_003B16B0`, a permuter find).
- **Every pseudo is an allocno, local ones included.** A local's hard-register preferences can push a global off `$a2`/`$a3` in global.c's first pass (`func_003AC6F0`, near miss). Global-alloc also merges the preferences of a pseudo that dies in an insn into the pseudo that insn sets, so a function-scope temporary inherits a register from whatever it dies into; declared block-local in each arm, it is a local pseudo and reuses the dying input's register (`func_003D2878`, per-arm `plzcw` results).
- **Loop invariants hoisted by loop.c's second pass** get the highest priority, because they are hoisted closest to the loop. A movable with a short lifetime fails the first pass's `threshold * savings * lifetime >= insn_count` test; shortening one constant's lifetime (`h = D_001D8B0C - 0.007f;` before the call) moved it to the second pass and to retail's `$f23` (`func_003B16B0`). `-dL` shows the loop dump.
- **Shared versus block-local variables in big switches.** Shared function-level temporaries push values into callee-saved registers (block-local per case fixed `func_00397490` and `func_003B2F50`). But where retail keeps one stack address or value in the same saved register across cases, it is one function-level variable reused (`func_003DBEC8`), and values that share a register are often one variable (`cx = a->f10; cx = (b2 - b0) * cx + b0;`, `func_003EC960`). Separate variables instead of reuse matched `func_0037FF90`.
- **Parameter copy placement.** A copy made right after a parameter's first use (`d = x1 - x0; x = x0;`) keeps the parameter in its incoming register (`func_003D14D0`).
- **Stack slot order follows when a variable becomes addressable**, not its declaration: gcc 2.95 moves a scalar to the stack when it first sees `&x`, while arrays get their slot at the declaration. One `u8 cc[2]` array declared first, instead of two `u8` scalars, put the bytes at retail's 0x20/0x21 (`func_003C0188`, 198 to 62).
- **Function-level locals for stack buffers.** Block-local arrays get separate slots in gcc 2.95; retail shares slots between cases or loops, so declare them once at the top (`func_003DCD08`, `func_00382458`, `func_003A4A78`).
- **Inline helper parameters.** integrate.c copies every non-const formal into a fresh pseudo before the body, so the order of a `static __inline__` helper's formal parameters sets the schedule of those copies (`func_003EB728`, found by a climb over parameter orders).
- **Float constants named as locals.** Two float constants stored into a stack struct, declared as initialised locals at the top (`f32 c1 = 0.572f;`, then `s.f1C = c1;`), gave retail's `$f` registers; writing the literals in the stores left 17 diffs, all `$f`/`$a` register numbers (`func_003B07B8`).

### Control flow, switches and loops

- **Branch versus conditional move.** gcc only turns `if (a < b) a = b;` into a conditional move when the source value is already in a register at that point; a memory source keeps the branch (from the `func_003921D8` analysis). `if (x != -2) r = 1; else r = 0;` goes through jump.c's conditional-move conversion and keeps the constant 1 in a register a later cmove shares (`func_0039BF98`). `if (a != b) c = f(..); else c = a;` puts `move c, a` in the `beq` delay slot (`func_0039FBD8`). `if (x) c = f(A); else c = f(B);` gives a branch where any selected-id form gives `movz` (`func_003B2AF8`).
- **Selector type sets if/else layout.** An `s32` selector gives `beq` with the then-assignment in its delay slot; a `u8` (or other narrow) selector gives `bne`/`b` (`func_003B8440`).
- **Cross-jumping keeps the later copy** (see `func_00397490`). To stop it merging duplicated tails, use block-local temporaries per case and a `goto` into the shared tail (`func_00391B70`), or reorder one arm (`func_003A4A78`). To get a merge retail has, write the shared body out in each case (`func_003A73A0`, `func_003C79F0`) or end both arms the same way and let gcc merge them (`func_003C0188`'s two shared tails).
- **An instruction duplicated into both arms comes from after the if/else.** When retail has the same `sll` at the end of both arms (in the `b` delay slot and in the else arm), reorg filled the delay slot with the join block's first instruction: write the shift once, after the if/else (`if (a1) s = h; else s = h*0x73/0xA0;`, then `s * 8` in the uses). Writing `<< 3` in each arm left 13-16 diffs (`func_0038CC68`).
- **A dead test whose arms do the same thing.** When retail loads and tests a flag but both paths then run the same code, write the test with two identical arms: `if (D_001D5BDC == 0) D_001D888C++; else D_001D888C++;`. gcc merges the arms but keeps the load of the flag (`func_003AE8A8`, case 22).
- **Switch trees.** `case 2: default:` gave retail's `beq 1 / slti 2 / bnez` tree (`func_003813E0`); an extra `case 3: break;` picks another root (`func_003DCD08`, `func_003DBEC8`).
- **Error-code chains** (`func_00397490`, above) and **block order:** writing the `== 0` or bad case first gives retail's layout in several boot_elf functions: `if (D == 0) return f(); ...` (`func_0013CEB0`, `func_0013CF40`), `if (i < 0 || i >= n) return f(p); return ok;` (`func_001222A8`). A single result variable, `if (f() != 0) r = D; else {...} return r;`, fixed a `lui` register (`func_0013A930`, `func_0013A880`, `func_0013A988`), and `if (call) r = 0; else r = 0x800;` keeps a constant out of `$s0` where setting it before the call doesn't (`func_001223B8`, `func_00122520`).
- **Loop shapes.**
  - A loop that re-reads `self->field` each pass is left alone by loop.c, which is why retail reloads the bound and indexes with `sll`/`addu` (`func_003E8838`).
  - Count-up loops that gcc would reverse: `i = 0; if (n > i) { do { ... } while (...); }` (`func_0038E030`, permuter find).
  - A goto loop with the test wrapped in `do { } while (0)` gives a rotated loop with duplicated exit tests and an unconditional back branch (`func_003A54A0`). An early-exit test at the top of the body is a rotated `for` condition: `for (i = 0; i < N && !(test); i++)` (h05's batch).
  - `for (...; i++, q += 0x20, fl++)` puts loop.c's derived-pointer increment right after `i++` (`func_003C9078`, near miss).
  - Separate block-local pointers for separate loops (f2), and one counter per loop (`func_003A4A78`, `func_00393878`).
  - `-fno-rerun-loop-opt` as a single-function override kept an up-counting `slti` loop that the second loop pass reversed (`func_00394060`); its neighbour `func_00393C98` needs the second pass, so it can't be file-wide.

### GS/GIF packet writers and 64-bit values

- **`*(*pp)++ = v;`** with `s32` parameters widened by `(long)x << n` at the use (`func_003D3148`, 147 to 0, then four siblings).
- **One pointer variable per step** when retail repeats `p = D_001DA0D0; D_001DA0D0 = p + 0x10; ...` blocks (`p1, p2, q1, q2`): reusing one `p` changes allocation priorities (`func_003867F8` 53 to 0, `func_00387B10`). Separate pointer variables per group let the last access of each group update the pointer in place (`func_003A7090`).
- **Constant first in OR chains:** `0xA | (x << 4) | ...` keeps retail's grouping; with the constant in the middle gcc reassociates it (`func_003872F8`, `func_00386F38`). For TEX0 values, write the full `SCE_GS_SET_TEX0` expansion with all 12 fields, constants included, inline in the block (no `#define`): constant folding then groups the chain as retail (`func_00384EC0`).
- **`(1L << 63)` and other 64-bit constants need `@ps2as`.** Ps2EeAs builds `1L << 63` as `addiu -1; dsll32 31` (retail), the default assembler as `ori 0x8000; dsll32 16`. Keep `(x << 37) | 0x400000000L` as its own operand or statement, or gcc merges the constants (s3's batch, `func_00392DD8`). `u32 == 0xFFFFFFFF` makes Ps2EeAs build `lui 0xffff; ori 0xffff` like retail.
- **`lw` + `dsrl` + `andi` on a 32-bit global:** `unsigned long t = D[0]; if (!((t >> 6) & 1)) break;` with a separate 64-bit temporary (`func_0037D200`); one expression narrows to an SImode `sra`.

### Small forms that matched

- **A float constant reused as a variable:** `bx = 1.0f; by = bx - ay; bx = bx - ax;` where `1.0f - ay` doesn't (`func_003875A0`).
- **A dead store gcc would drop** is kept when it has a different mode from the later one: write the first stores as `f32 0.0f` (`func_003A6A00`).
- **Dead compare loads before a rounding expression:** `(D_001DA0F0 == 1 ? z0 : z1)` with two local zeros `z0 = z1 = 0.0f` (`func_003DBEC8`, `func_003A5DF0`); a literal `? 0.0f : 0.0f` folds away completely.
- **`(x & 0xFF) < (y & 0xFF)`** keeps a signed `slt` where two `u8` fields compare `sltu`; a boolean helper returning `u8` reproduces a `daddu` copy of the result before each loop test (h05's batch).
- **Struct copies as statements, declared in slot order**, so other stores can sit between them (`func_003C1130`, near miss, 49 to 8).
- **Start over.** A clean rewrite, or a copy of an already matched sibling, often beats tuning an old draft: `func_003A3FB0` went from 46 to 0 with a plain rewrite, `func_00392400` from 89 to 0 copied from `func_00392878`.

## Patterns from level 1 (Veldin, PAL)

Found while matching 20 functions of `src/levels/01_veldin/` and 20 shared level 1 functions of `src/levels/shared/` (each one verified at every level that has it). Names are catalogue names (`func_L01_XXXXXXXX`).

### Quadword copies and aggregates

- **`lq`/`sq` copy:** `typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;` and assignment between locals (`V4 a = *p; ...`) compiles to `lq`/`sq`. Passing the struct by value or by pointer does not copy; make local copies (`x = t.b; y = t.a;`) and pass their addresses (`func_L01_003E32F8`, `func_L01_003E34F0`).
- **Unaligned plain struct** assignment gives `ldl`/`ldr`/`sdl`/`sdr`, so use the aligned typedef only where retail has `lq`/`sq`.
- **Zeroing a quadword with a bare `sq $zero`** is not reachable from plain C (gcc emits `por` + `sq`). Use `qzero()` from `include/vu0.h` (see Vector-library asm macros): `func_L01_00423E20`, `func_L01_00356818`, `func_L01_003569A0` and `func_L01_004C98A8` match with it.
- **A single `s128` member** (`typedef int Q __attribute__((mode(TI)))`) copies with one `lq`/`sq` pair (`func_L01_00475C60`); its fourth float is written with `((f32 *)&q->v)[3] = ...`.

### Globals

- **`$gp` slots:** the address of a slot is `0x1DC8B0 + offset` for level 1 (offset `0x376C` is `0x1E001C`, `0x37A8` is `0x1E0058`), so the alias is `D_001E001C_sda` / `D_001E0058_sda` with `extern T X; __asm__(".extern X, 4");`. A wrong name makes `level_symbols.py` fail in the build.
- **`lui` form:** one alias per use with `.extern X, 16` (`D_L01_001E001C_6668`, `D_L01_001E001C_E1C8_a/_b`); an unsized array read at `[0]` makes gcc hoist the `lui`. Same recipe as in frontbin.
- **A `$gp` slot that moves between levels is level data:** name it `D_L01_XXXXXXXX` (its level 01 address), not `D_XXXXXXXX_sda`. The `_sda` name matched level 01 and differed in all nine other places (1 word, `lw 0x37a8($gp)` against `0x3528($gp)`) in `func_L01_00325570`; the `D_L01_` name matches all ten.
- **A front-end callee is `fe_func_XXXXXXXX`:** the plain `func_XXXXXXXX` passes levels 01-49 and fails the multiplayer ones, whose copy of the front-end function sits at another address (`0x491c50` against `0x443948` in `func_L01_00475128`, levels 50-53).

### Aliases for per-level callees and data

- **A callee whose target differs per level:** call it through a `<name>_<caller>` alias. `func_L01_004E27A0_004E2C48` (level 01 calls `func_L01_004E27A0`; the other 29 places `func_L01_004D8A68`), `func_L01_00404A10_0031C1D0` and `func_L01_00404A10_002FC910` (levels 03, 11, 16 and 23 call `func_L01_004048D0`). check.py masks an alias at a level that does not hold the encoded address, so verify level 01 and one of the levels that differs.
- **A data name whose type clashes in the owner:** suffix the array with the caller: `D_L01_0029EFA0_00391610`/`D_L01_0029F1E0_00391610` (`func_L01_00391610`), `D_L01_00273B80_00319718` (`s8` against the file's `u8[0x420]`), `D_L01_002C5600_00507268` (the file's `T_503930`).
- **A callee that takes more arguments than its prototype:** keep the file's prototype and call a second name with the extra parameters. The name is `<callee address>_<caller address>`, e.g. `extern void func_L01_004C9848_004C98A8(u8 *, s32);` (`func_L01_004C98A8`) or `extern void func_L01_004783E0_004784C0(s32, s32, s32, f32, f32);` (`func_L01_004784C0`); the digits must be the callee's, or check.py resolves the alias to the caller. No asm label is needed.

### Loops and tables

- **List-search family:** `while ((idx & 0xFF) != 0xFF && idx <= D_001E0058_sda && q != 0 && (q[-1] >= 0 || q == D_L01_0021DE20[idx]))`, reloading the index from memory every pass (`func_L01_003B0498`, `func_L01_003B0D48`).
- **Table walk:** `while (tab[i].f0 != 0)` with `n = i + 1;` in each case and `i = n;` at the end (`func_L01_0049DE10`).
- **A pointer to the table entry** instead of indexing twice; `for (i = 0; i < n; i++)` instead of a down-counting loop.
- **Switches:** write every consecutive case, even empty ones (`case 1: break;`), or gcc emits a compare chain instead of a jump table. Delete the `INCLUDE_RODATA` jtbl line after the function.
- **Case order follows the jump table:** read the `jtbl` targets and write the cases in that order (`func_L01_005143C0`, `case 4,0,1,5,2,3`; 0..5 in order came out 0..5).
- **`movz` from two compares:** a block-scoped `s32 is = (global == k);` plus `result = (field == v) & is;` gives `movz` and fixes the `xori`/`sltiu` pair (`func_L01_005143C0`); `&&` or `?:` branch instead.

### Arguments and constants

- **Callee prototype order:** declaring the callee with ints before floats fixes the scheduling of argument moves (`func_L01_0040D338`). Very wide calls need the full prototype (30 parameters for `func_L01_003303B8`).
- **Floats need exact bit patterns:** `0.080000005f`, not `0.08f`.
- **The callee's return type decides argument scheduling:** a callee whose result retail tests must be declared `s32`, not `void` (`func_L01_0031C100`, 24 words). When the file's prototype is shared and must stay `void`, cast the call instead: `((s32 (*)(...))func_X)(...)` (`func_L01_003A6F80`, 6 words).
- **Interleave a float between two pointers** in the prototype to put its `$f12` move before the next integer argument (`func_L01_004F45F0`, `(ptr, f32, ptr, f32, f32, f32, s32)`; ABI-equivalent to the file's other callers).
- **Assignment chain direction:** `byte = u16 = 255` shares one `addiu` for both stores; `u16 = byte = 255` emits two and shifts the block (`func_L01_003E0058`). For two separate `0xFF` constants, write the byte store before the halfword store (`func_L01_0031C1D0`).
- **Float constants:** declare them without an initialiser and assign them in the retail order; the `li.s` order follows the assignments while the registers follow the declarations (`func_L01_002FC910`).
- **`@ps2as` is per file** and also moves every `INCLUDE_ASM` block of that file to GNU as; check the neighbours (`L01_00356588.c` breaks). It was needed for `L01_003E32F8.c` and `L01_0035B710.c`.

### Open problems (drafts in `nonmatching/levels/`)

- A `LINKER_REMNANT` right after `jr` can be the function's own delay slot, so the catalogue size and the C disagree by one insn (`func_L01_00350040`, 1 diff).
- gcc coalesces `n = i + 1` into `i` where retail keeps two registers (`func_L01_0049CD08`, `func_L01_0049BBD8`).
- Argument-move scheduling and one `ori` position (`func_L01_003B1128`; `func_L01_003D9428` matches now), saved-register rotation (`func_L01_003E36E8`), jump-table address build (`func_L01_003E1CD0`), loop hoisting (`func_L01_00356748`).
- An unsigned loop counter keeps gcc from reversing the loop but emits `sltiu` where retail has `slti` (`func_L01_002FD818`, `func_L01_00319718`, 1 diff).
- Two strength-reduced giv inits in a preheader are scheduled in the order that puts flow2's `REG_DEAD` on the wrong giv (`func_L01_0030AA38`, 2 diffs).
- A pointer copied in a loop and reloaded after it is one global pseudo; a fresh copy after the loop merges with its consumer and cascades the allocation (`func_L01_00326898`, 5 diffs).
- `lq`/`sq` copies and an adjacent `sw` are ordered by a sched1 tie whose two demands cannot both hold (`func_L01_003949E8`, 3 diffs).
- local-alloc rematerialises a one-instruction literal inside the branch block (`func_L01_00318AF8`, 14 diffs) and decides integer-quantity-0 pseudos through an unstable qsort tie (`func_L01_0042D798`, 15 diffs).
- A result pseudo in `$a0` with a final `move`, and a shared `return 1` block that cross-jumping folds to the top (`func_L01_005002B8`, 9 diffs); an `mfc1`+`daddu` temporary that drops `value` below `vars` in priority (`func_L01_003291D0`, 17 diffs).
- A loop-invariant `0.0` that retail reloads at the loop tail stays in another register here (`func_L01_003ABD60`, 13 diffs); the clamp value and its two limits move registers together (`func_L01_004F3F40`, 77 diffs).
- A `while` whose first test is register-only moves the loop head behind the test (`func_L01_003A6DA8`, 39 diffs).
- VU0 code interleaved with ordinary instructions matches only with per-instruction volatile asm and a scheduling lever, which the rules do not allow; the single-block form stays 19 diffs (`func_L01_003EB5E0`).
- `sq`/`lq` saves need `config/levels/sq_ra_funcs.txt` and a file without `-fopt-stack`, so a function that shares its file with C that needs the flag is held (`func_L01_0035F340`, `func_L01_0038B9A8`, `func_L01_00409428`, `func_L01_00465738`, `func_L01_00447718`); split-address mode S has the same file-boundary problem (`func_L01_0044FC48`).

## Patterns from level 2 (Florana, PAL)

Found while matching 23 functions of `src/levels/02_florana/`. Names are catalogue names (`func_L02_XXXXXXXX`).

### Names and files

- **Level data is `D_L02_<address>`, core data is `D_<address>`.** Level 2's `.lit` starts at 0x1D5680, its `.bss` at 0x1DE100 and its `.data` at 0x2A3100 (`config/levels/levels.tsv`): every address from 0x1D5680 up is the level's own data and is written `D_L02_001DE99C`, with aliases as `D_L02_001D66B0_3519F0`. Below 0x1D5680 it is the resident core (`D_001A4C60`, `D_00142BA0`, `D_001D545C`). `$gp` slots stay `D_XXXXXXXX_sda`. `tools/lk.py`-style lookups only know functions, so a data address they do not find is not necessarily core: check the section ranges. The build cannot catch a wrong spelling in a level-only function, both resolve to the same value.
- **`@ps2as` is per file, and the build is the check.** `check.py` refuses a `src/` file that still has `INCLUDE_ASM`, and it only sees the declarations before the function, so a prototype that conflicts with a later function of the same file shows up only in the full build (`conflicting types for ...`). Float constants built inline (`lui`/`ori`/`mtc1`) need `@ps2as`; six files here have it and the C and `INCLUDE_ASM` blocks next to the new functions still built. When two functions declare one callee differently, use `void *` for the pointer parameter and a typed local inside.
- `check.py` prints `0 diff` as part of `10 diff`; test for `MATCH`.

### Frames, copies and stores

- **A frame bigger than the code needs** (`addiu $sp,-0x30` with `$ra` at 0x20 around a plain call) is an unused local, `char buf[0x20];` (`func_L02_003AB1F0`).
- **Quadword copy:** `typedef int u128_t __attribute__((mode(TI)));`, or the aligned four-float struct, copied directly (`b->v = a->v;`). A local temporary adds a stack slot. An unused `V4 tmp; tmp = *c;` at the end of a block is where a dead `lq`/`sq` to `[sp+0]` and the 0x50 frame come from (`func_L02_0039CD18`).
- **Under `@ps2as` an 8-byte extern with no `.extern` hint** gives the adjacent `lui`/`addiu` (the `la` macro); the 16-byte hint gives gcc's split form (`func_L02_003519F0`). A `$gp` and a `lui` access to the same address in one function are two aliases, one hinted 4 and one hinted 16 (`func_L02_0034FE10`: the first loop reads the limit through `$gp`, the second through `lui`).
- **Order of independent stores** is found by search: all permutations of four stores (`func_L02_0039CD18`, `func_L02_003FC828`), and for a run of 19 stores a random move-one-statement search of about 160 compiles (`func_L02_003514D0`). The flag byte stores of the small state functions are usually in the other order from the assembly (`f30` before `f20`, `func_L02_0032F1C8`).
- **A local's address kept in a saved register** while the field stores stay `$sp`-relative: declare `S *ps;` without an initializer and assign `ps = &s;` inside the `if`, before the first store; only the call uses `ps` (`func_L02_003BB620`). Using `pv = &v` for every access gives `move $s2,$sp` (`func_L02_004BE7A8`).
- **A `u8` read through a `$gp`-free table:** `struct { u8 pad[0x464]; u8 spent[1]; }` with `.extern X, 16` keeps the base in `addiu` and the offset in the access; a `u8[]` folds the offset into the `lui` (`func_L02_0034F710`).

### Control flow

- **Flags as `a || b`:** `D[i].flag = bit_test || call();` gives the `bnel`/`beql` form with `0` in the delay slot; an `if`/`else` gives `movz` (`func_L02_004722E0`). Index the table directly (`D[i].field`, no entry pointer) and write the outer loop as `for (i = 0; D[i].f0; i++)`; that reproduced the hoisted address registers. The Veldin shape (`n = i + 1` in each case, `i = n;` at the end, a pointer to the entry) matched the twin that has it (`func_L02_00474518` is `func_L01_0049DE10` with other symbols), so copy the sibling first.
- **State dispatch:** copy the `u8` state into an `int s` before the tests to get `slti` instead of `sltiu`, and write the `!=` arm first (`func_L02_003A2620`).
- **List walks** (`q[-1] >= 0 || q == tab[idx]`, the level-1 search family): declare the two pointers inside each branch, not at function scope, and keep the index reloaded from memory (`func_L02_0032EF80`, `func_L02_00350030`).
- **Cross-jumped tails:** write every `call(x, 1); return;` out one by one and gcc merges them into the shared tail as retail does; one variable for the argument gives `movn` (`func_L02_004BDA00`). `__builtin_fabsf` gives `abs.s` there.
- **A callee's return type moves registers:** declaring a callee `s32` although its result is ignored moved a `lui` and an `lbu` from `$v0` to `$v1` (`func_L02_0034F710`); declare the others the same way before trying aliases.
- **A float argument list needs its own prototype:** four `lui`/`ori`/`mtc1` into `$f12..$f15` before a call are its float arguments (`func_L02_003514D0`, `func_L02_0034F958`); use the shortest decimal that gives the bit pattern (`0.34906584f`, `0.0432f` is 0x3D30F27C, `0.432f` is not).

- **Natural loops:** `for (i = 0; i < 4; i++) f(&p->v[i], ...)` reproduces retail's countdown loop and its register order (`$s0` pointer, `$s3` counter); a hand-made pointer loop rotated `$s2`/`$s3` for hundreds of differences. Where several loops share a function, which of them share a counter variable decides the `self` register: loops 1 and 2 use `i`, loop 3 and the tail use `j` (`func_L02_0039EF28`, found by trying every grouping).
- **Floats in the middle of a prototype:** int and float argument registers are allocated separately, and gcc emits the argument moves in prototype order, so the prototype lists the floats where retail places them (`(void *, void *, s32 x5, f32, f32, s32, f32)`); that fixed every `mov.s $f13` position.
- **A float comparison kept as a value:** `far = d > 18.0f; if (far == 0) { B } else { A }` gives the materialised `c.olt` / `bnez` form with `B` first.
- **A pointer global read as `X[0][0]`:** declare it `u8 *X[]` with `.extern X, 16`; a plain `extern u8 *X` is small data and becomes a `$gp` load. A 0x80-stride table with fields at +0xD0/+0xDC is `(u8 *)D + (idx << 7)` with byte offsets, because a struct array would have size 0x80.
- **Quadword zero:** `*(u128_t *)&w = 0;` gives `por` + `sq` to the stack slot (not a bare `sq $zero`, which stays out of reach). A 64-bit field read is `unsigned long`; `long long` fails with "wide integer operation".
- **Big switches are matchable:** `func_L02_0039EF28` (555 instructions, six cases) matched once the cases were written in retail's block order (3, 4, 5, 6, 1, 2) and the repeated tail was written out in full in each case so gcc cross-jumps it. `func_L02_004DA1D0` (5650 instructions, a 0xB2-entry switch, about 390 calls) was judged too large for one pass and not attempted.

### Open problems (drafts in `nonmatching/levels/`)

- **Saved-register layout (`sq_ra` class):** retail's 16-byte `sq` slots with a 0xD0 frame against our 8-byte `sd` slots (`func_L02_004BE7A8`, 22 diff, everything else matches). Levels have no `sq_ra_funcs` table.
- **In-place `i++`:** gcc emits `addiu $s4,$s2,1; move $s2,$s4` where retail has `addiu $s2,$s2,1` (`func_L02_00473410`, 13 diff). Level 11 matched its twin `func_L11_00472AD8` with the gcse PRE recipe ("Loops and scheduling (round 3)" there); not yet tried here.
- **Switch dispatch registers:** `lbu $v0; addiu $a0,$v0,-1; sltiu $v1,$a0,6` against our `$v1`/`$v0` (`func_L02_0039D200`, 5 diff); store and constant-register order (`func_L02_003A2320`, 4 diff; `func_L02_00351208`, 2 diff; `func_L02_003523D0`, 4 diff); a constant (309.0f) retail reloads at a join and gcc CSEs (`func_L02_0034BF90`).
- **A one-instruction shift in a 448-instruction function** (`func_L02_00313B38`, about 208 diff counted, one cause): retail puts `lhu` in a `beqz` delay slot where this C has `lui`.
- **Real VU0:** `func_L02_0039CE20` needs a `vadd.xyz` in the middle of a switch case.
## Patterns from level 3 (Starship Phoenix, PAL)

Found while matching 69 functions of `src/levels/03_starship_phoenix/`. Only what is new compared with the level 1 and level 2 sections above.

### Names, flags and prototypes

- **A callee's name depends on what it is.** The `.s` names a call by its level-3 address (`func_004326F0`). Look the address up in `config/levels/functions.tsv` (level 03 column): a shared function is written with its catalogue name (`func_L01_004450F0`), a front-end one with the frontbin name (`func_003C3A10` for level address `0x432390`), a level one `func_L03_XXXXXXXX`. The bare address spelling also builds, but it is not the convention.
- **A callee or global the file already declares differently gets an alias, not a cast.** The build stops with `conflicting types` when two functions of one file declare a name differently, and a non-prototype `()` redeclaration after a prototype keeps the prototype (`too many arguments`). Declare your own copy as `func_L03_XXXXXXXX_<yourfunc>` (or `D_L03_XXXXXXXX_<yourfunc>`): the suffix makes a name of its own with the same address (`func_L03_003AFCB8_003AFFB8`, `D_001CCFD0_003AFE60`). When the function being matched is defined before the one it calls, declare the callee with `void *` and use a typed local.
- **`@ps2as` is a file decision, and the build is the judge.** Five level-3 files got it (inline `lui`/`ori`/`mtc1` float constants) and their matched neighbours still built. One refused: with `@ps2as` on `L03_0032C3A8.c`, the already matched `func_L03_0032C8F8` differed at word +0x8, so the function that needed it stayed a near miss.
- **Check a data address against `.lit` before naming it.** `0x1DF99C`, `0x1E7000`, `0x21C620` and `0x2AE4D0` are level data (`D_L03_`); `0x1426E0`, `0x1A4BE0` and `0x1D5530` are core (`D_`). Both spellings resolve to the same value, so the build does not catch a wrong one.

### Globals

- **A `$gp`-range array indexed at run time needs a sized declaration:** `extern u8 X[4]; __asm__(".extern X, 4");`. Unsized with hint 4 gives `lui`/absolute.
- **A word read as `lw` + `dsrl` + `andi`:** `unsigned long t = D[0]; if (((t >> n) & 1) == 1)` with `extern s32 D[]` and hint 16. The plain expression gives `sra` or `srl` (`func_L03_00397CF8`, `func_L03_003AFD48`).
- **A bit test with `xori`/`andi`:** `if (((mask >> i) ^ 1) & 1)` (`func_L03_003AFFB8`, `func_L03_0032F520`).

### Shapes

- **The level-2 list walk, as one `while` condition:** `while ((idx & 0xFF) != 0xFF && limit >= idx && cur != 0 && (cur[-1] >= 0 || cur == tab[idx]))` reproduced the block order of `func_L03_0032EB30` and `func_L03_0032EF78`; early `return`s or `break`s inside the loop did not. A `for` whose skips are `continue` puts `cur++` in the branch delay slots (`func_L03_0032D8C0`).
- **A typed array fixes `addu` operand order and registers:** `struct { char pad[0x160]; int arr[1]; } *p; p->arr[c]`, an element type of exactly the retail stride (`E[idx]` with a 0x100-byte `E`), or two `f32[4]` arrays in a struct (`dst->a[i] += c; dst->b[i] += d;`). A pad inside the element (`pad1[0x50 - 12]`) makes `(E *)((u8 *)e + 0x50)` the stride (`func_L03_003A2A10`).
- **Shared tails in a switch:** write each tail once and `goto` it from the other cases (`func_L03_00397CF8`); an `if`/`else` chain of the same logic was 66 diff against the `switch` that matched at once (`func_L03_00399278`). Case bodies with an identical `return` written out separately give retail's binary tree (`func_L03_0032F6A8`).
- **Twins:** `func_L03_003A02B0` and `func_L03_003A13E8`, `func_L03_0039F2C8` and `func_L03_003A16D8`, `func_L03_003B28A8` and `func_L03_003B2C08` are one source with other offsets. Copy the matched sibling first.

### Open problems (drafts in `nonmatching/levels/`)

- **Two retail `nop`s before `div.s`**: a row in `config/levels/divs_nops.txt` gives them, as `config/frontbin/divs_nops.txt` does in frontbin. `func_L03_003A04D0`, `func_L03_003A16D8` and `func_L03_0039D038` match with one; `func_L03_00395CA8` is still 11 diff with its row (prologue scheduling).
- **Float argument load order:** retail loads `$f13`/`$f14` through `lui $at` first and the `$gp` `$f12` in the `jal` delay slot; the C loads the `$gp` one first (`func_L03_003AF7F0`, `func_L03_003B27D0`, `func_L03_003B2B30`, 6 diff each).
- **The catalogue size cuts a delay slot** (`func_L03_0046FF38`, `func_L03_0040FEE8`, 1 diff each, same class as level 1's `func_L01_00350040`).
- **Bare `sq $zero`**: `qzero()`, as in levels 1 and 2 (`func_L03_003A1C60`, `func_L03_0032FE10`, `func_L03_0039D380` match with it).
- **Register choice that no wording moved:** `func_L03_003A1A78` (2 diff, `lui` in `$v1`), `func_L03_0032EE30` (58 diff, saved-register choice in the list walk).

## Patterns from level 4 (Marcadia, PAL)

Found while matching 18 functions of `src/levels/04_marcadia/`. Only what is new compared with the level 1, 2, 3 and 5 sections.

### Before writing C

- **Look for a byte twin first.** Two of the 14 small candidates were twins of already matched functions once linker-filled fields are masked: `func_L04_0042A9A0` is `func_L05_00413A00` and `func_L04_004AB470` is `func_L02_004722E0`. Copying the C and renaming the data gave `MATCH` on the first compile. The twin's file flags come with it (`@ps2as` for the first).
- **Add the `divs_nops.txt` row before chasing anything else.** In `func_L04_003E1B88` the draft looked one `nop` short before an 8-aligned loop label as well as before the `div.s`. With the row `func_L04_003E1B88 1` the same C matched: the first missing `nop` had shifted the loop label, so the second one was never a C problem.

### Shapes

- **One callee, one prototype per file.** `func_L04_003ECE58` and `func_L04_003ED190` both call `func_L01_00451FE0` with 18 arguments. The prototype that matched is `(void *, s32, void *, s32, s32, s32, s32, s32, f32 x8, s32, s32)`: eight floats in `$f12`..`$f19`, then the two stack ints last.
- **A quadword zero, one float, then a copy for the argument:** `*(u128_t *)&src = 0; src.z = X; dst = src; f(..., &dst);`, with `dst` declared before `src` so that `dst` gets the lower stack slot (`func_L04_003ED190`).
- **A flag that is a test and a call:** `*(s16 *)(s + 0x30C) = (*(s32 *)(s + 0x304) != -1) && (f(...) != 0);`. The `if (x != -1) r = f(...) != 0;` form gives a different `sltu` register (`func_L04_003CE120`).
- **A base pointer the code reloads:** write `*(u8 **)(s + 0x300)` again after each call instead of keeping it in a local; retail reloads it from memory (`func_L04_003CE120`).
- **An early `i++` in one switch case:** retail does `addiu $s2,$s2,1` right after it computes the entry address and then jumps back to the loop test. `s32 j = i++;` with `D[j]` in the case body and `continue` at its end reproduced the control flow (71 to 37 differences). The register rotation is still open, see below.

- **Postfix increment of a narrow field can keep the old value in the right register.** In case 6 of `func_L04_003E5250`, `s32 old = a0->f96++;` (with `f96` a `u16`) matched where separate load and increment statements left a register swap. Give each case its own `old`; a function-wide temporary kept the wrong allocation. Together with the already documented small-object `la` declaration, this resolved the 17-difference draft. Changing the file to `@ps2as` also required early four-byte hints for the two `$gp` float globals in its already matched `func_L04_003E5FB8`; the full level build then printed `MATCH`.

- **Load a quadword source before an intervening narrow store.** `position = *(u128_3CE348 *)(a0 + 0x10); s1->f198 = 0; s1->f2D0 = position;` gives retail's `lq`/`sh`/`sq` order in `func_L04_003CE348`. A direct aggregate copy after the halfword store changes the initial scheduling and register allocation. Together with grouping repeated constants in the initializer, the full level matches.
- **Load a GP float before preparing the other call arguments.** In `func_L04_00366AC8`, `f32 turn = D_001DD7F4_sda; turn *= 0.020000001f;` before the flag update gives retail's early GP load and leaves the flag store in the call's delay slot. Copying both vectors before writing the final state flag also fixes the preceding call's argument move. The configuration stores use source order `0x34, 0x38, 0x30, 0x3C, 0x40, 0x60, 0x64`; store order changes float registers even when constant-load order stays the same.

### Open problems (drafts in `nonmatching/levels/`)

- **Stack-argument store order** (`func_L04_003ECE58`, 7 diff): with the prototype above, `sw $v0,8($sp)` and `sw $zero,0($sp)` are scheduled earlier than in retail. Its sibling `func_L04_003ED190`, with other float values, matches.
- **Register and scheduling differences:** counter copies and an inner boolean in `func_L04_004AC5A0` (28), and the base/saved-register order in `func_L04_00434098` (37).

## Patterns from level 5 (Daxx, PAL)

Found while matching 17 functions of `src/levels/05_daxx/` (one function per agent). Only what is new compared with the level 1 to 3 sections above.

### Tables and twins

- **Levels now have a `div.s` nop table.** `config/levels/divs_nops.txt` lists, for each level function, the `nop`s retail has before each `div.s`/`sqrt.s`, in order (`func_L05_003B1450 2`, `func_L01_003386E0 0 1`). Count them in the `.s`: a `nop` in a `bc1f` delay slot before a `div.s` is not padding, so `func_L05_0047FF20` is `2 0 2`, not `2 1 2`. With the row, `func_L05_003B1450` went from 59 differences (all one 8-byte shift) to a match. The level-3 open problem "two retail `nop`s before `div.s`" is solvable this way.
- **Look for a matched twin in another level first.** Compare every remaining function with the C already in `src/` by instructions with only linker-filled fields masked (rac2-decomp's `cross_identity()`): `func_L05_004950C0` is `func_L02_004722E0` and `func_L05_004972F8` is `func_L02_00474518` with other data, and both matched at once with the level-2 C renamed. Inside the level, `func_L05_003B24B8` is `func_L05_00360868`. A twin of the same family but other code (`func_L05_004961F0`) does not fit: try it, but expect nothing.

### Prototypes and declarations

- **A struct pointer forward declaration must be at file scope.** To call a function defined later in the file with `S_362968 *`, write `struct S_362968;` on its own line and then the prototype. `struct S_362968 *` inside a parameter list alone declares a new type with prototype scope, and the build stops with `conflicting types` (`func_L05_00362810`).
- **Float-first prototypes.** Where level 1 needed ints before floats, two level-5 calls needed the opposite: declaring `func_L05_003B27F8(u8 *, f32, f32, f32, s32)` and `func_L01_00456C98(void *, f32, f32, f32, s32 ...)` with the floats first put `mov.s $f14` (or `$f13`) before the `$a1` move as retail does. The register mapping is the same either way, so try both orders.

### Shapes

- **Guard a loop count on the call result, then copy it:** `r = f(4, 8); if (r > 0) { n = r; do { ... } while (--n != 0); }`. Guarding on `n = f()` directly puts `move $s1,$v0` before the `blez` (14 differences; `func_L05_00360868`, `func_L05_003B24B8`).
- **A struct with padding for a global read at several offsets:** `typedef struct { u8 p0[0x35C]; s32 a35C; s32 a360; u8 p1[0x6F0]; s32 aA54; ... } B; extern B D_001A4BE0;` with `.extern X, 16` gives retail's `lui` + `addiu` base and offset loads; byte casts on a `u8[]` folded every offset into the `lui` (37 differences to a match, `func_L05_00360070`).
- **The bare `sq $zero` is `qzero()`** from `include/vu0.h` (allowed by AGENTS.md, all of a file's sites or none): `f32 loc[4]; f32 *lp = loc; qzero(lp);`, with the pointer local keeping `&loc` in a saved register (`func_L05_0035F360`, 63 to 0).
- **Write the test the way retail branches:** `if (off == a1 || tab[off] != 0) return 1; return 0;` instead of `if (off != a1 && tab[off] == 0) return 0; return 1;` fixed a register swap in a table walk (`func_L05_00413A00`). An `int off = idx * 0x460;` local put a `mult` in the argument register retail uses (`func_L05_003E63C0`).
- **Prototype parameter order follows where retail passes each argument:** `func_L01_003303B8` takes its float second here (`(void *, f32, s32, ...)`); declaring it in the int-first order of other files left 20 differences in `func_L05_003AFC08`.
- **Keep a global's base in a register:** `typedef struct { u8 pad[0x144]; s32 v; } S; extern S D; __asm__(".extern D, 16");` and read `D.v` gives `lui`/`addiu` + `lw 0x144`; a `u8[]` or `s32 *` folds the offset into the `lui` (`func_L05_003B1100`). A local `u8 *c = D_001A7C10;` taken before the reads does the same for several fields (`func_L05_00332598`).
- **Early `return 1` in a branch** instead of `r = (x != -1)` or `if (x != m) r = 1;`: the latter give `nor`/`sltu` (`func_L05_00360280`).
- **Four consecutive cases without a jump table:** a `switch` with `case 0` to `case 3` in source order gives gcc's compare tree with retail's block layout; other orders were 21 to 49 differences (`func_L05_003DC900`).
- **A `u16` counter incremented in an `s32`:** `s32 v = p->f96 + 1; p->f96 = v; if ((u16)v >= 0x1E)` gives retail's `andi` into a second register (`func_L05_003DC900`).
- **Null check with fall-through:** `if (s != 0) { ...; return s; } return 0;` gives retail's `beqz` layout (`func_L05_003DB1C0`).
- **Load a pointer field before the flag test** (`p = a0->f68; if (a0->f20 == 0) { ... }`) when retail has the `lw` in the `bnez` delay slot; reading it inside the branch gives `bnel` and another order (`func_L05_00362968`, `func_L05_003DDCC8`).
- **Write retail's redundant arithmetic as it is:** `cs = 1.0f - cs; idx = (s32)((1.0f - cs) * 128.0f);` keeps both `sub.s` (`func_L05_003B2668`).
- **A byte stored from a parameter:** declare the parameter `s32`, not `u8`; a `u8` parameter adds an `andi` (`func_L05_003DB1C0`).
- **One value in two float argument slots:** retail's `mov.s $f14,$f13` in a delay slot is the same local passed twice (`f(&a, &b, x, t, t, u)`, `func_L05_00362810`).
- **Loop counter decrement after the body's last `if`:** moving `cnt--` below the `if (r != 0) {...}` block took `func_L05_003AFC08` from 75 to 20 differences.

- **Saved FP registers come from a priority you can steer.** global-alloc ranks a value by `floor_log2(refs) * refs / live_length`, with refs weighted by loop depth, so wrapping statements in `do { } while (0)` doubles the weight of the values used inside: the clamp of `func_L05_0047FF20` in `do { ... } while (0)` gave retail's `$f20`/`$f21`/`$f22`. In a single basic block local-alloc decides instead, and writing every float constant inline (no named locals) let the scheduler's load order give retail's registers (`func_L05_003DB9F8`).
- **Argument moves follow parameter order:** gcc emits a call's argument moves in prototype order, so where retail has `mov.s $f12` before `move $a2`, declare the first float before the third pointer (`func_L02_003E2E38(void *, void *, f32, void *, s32, ...)`, `func_L05_003DC320`, `func_L05_003DB9F8`). The int and float registers do not change.
- **A store in the assembler's `lui $at` form, kept out of a delay slot:** declare the global as part of a struct that starts at an earlier symbol (`struct { s16 f0; s16 f2; s32 f4; } D_L05_001DF8B4;` with `.extern X, 16`) and store to `.f4`. The base stays small data (gcc does not split it) and the access counts as two instructions, so reorg leaves it before the `jal` (`func_L05_003DD3C8`).

### Open problems (drafts in `nonmatching/levels/`)

- **The catalogue cuts the function's own delay slot:** `func_L05_0047FF20` matches every instruction, but the catalogue gives it 0x11C bytes and a `LINKER_REMNANT` on its `jr` delay slot, so the 0x120-byte C shifts the next function (same class as `func_L01_00350040`).
- **Scheduler ties** that no wording or prototype order moved: `func_L05_003AFC08` (2: `abs.s` against `addiu $a1,$zero,2`), `func_L05_003DC5B8` (2: a stack-argument `sw` against a `lui`, 512 prototype orders tried).
- **cse merges a base address across blocks:** `func_L05_003E63C0` (10): retail recomputes `base + off` base-first in the second block; every form tried was merged with the first block's sum or folded the offset into the constant.

## Patterns from level 6 (Starship Phoenix Under Attack, PAL)

- **A loop bound loaded in skip-branch delay slots can be a direct global condition.** In `func_L06_0032E168`, write `if (e < D_L06_001DEDA0)` and `do { ...; e = (Entry *)((u8 *)e + 0x100); } while (e < D_L06_001DEDA0);`. Declare the bound as an ordinary pointer global with no early size hint under `@ps2as`. This lets the compiler duplicate the condition's load into the skip branches and lets Ps2EeAs use `$gp` there while retaining the `lui` load after the call. Caching the bound in an `end` local, even when explicitly reloading it, left the old draft at 13 differences. The initial entry pointer has its own `.extern ..., 16` hint. No second name for the bound is needed.
- **`la` expansions need `@ps2as` even when nothing else does.** `func_L07_003318D8` differs only in the `la` expansion: ee-as writes `lui $2,%hi; addiu $3,$2,%lo` where Ps2EeAs writes the same-register `lui $3,%hi; addiu $3,$3,%lo` that retail has. A file with no float constants may still need `@ps2as` for one global address.
- **An address-suffixed alias with a size hint gives the `lui` form** when the file's plain name is an unsized array: `extern s32 D_L07_001DF41C_00331FA0;` with `__asm__(".extern D_L07_001DF41C_00331FA0, 16");` produced retail's `lui`/`lw` for `func_L07_00331FA0` without changing the split form the file's other block uses. `func_L07_003A3B40` needs both forms of one address in one function: the hinted name for the `lui` read and `D_L07_001DF41C_sda` with `.extern ..., 4` for the `$gp` one.
- **An `__asm__("symbol")` label keeps a per-function scalar hint when a later block declares the same address as an array.** `func_L07_00335448` needs `&D_L07_001E0D10` as a scalar (the address-of form orders the two `la` pairs the way retail does), but the later `func_L07_003354A0` block declares the address `u8[]`; `extern u8 D_L07_001E0D10_00335448 __asm__("D_L07_001E0D10");` plus the 16-byte hint gave the scalar form and kept both blocks in one translation unit.
- **A definition repeats an earlier block's arity even when the extra parameter is unused.** `func_L07_003C8B18` calls `func_L07_003C8B60` with two arguments, so defining it `(void *arg0)` is a `conflicting types` build error; `(void *arg0, void *arg1)` with the same body compiles to the same bytes because retail never reads the second register.
- **A selector local written as a comparison selects the `movn` form.** In `func_L07_003B3798`, `s32 s = p[0x1AE] == 0 ? 4 : 5;` gives retail's `move $a1,$a3` + `movn` and keeps `arg0` in `$v0`; the `if`/`else` form and passing `4` as an extra call argument both differ.
- **Give a small table its real size under `@ps2as` when retail's `lui`/`addiu` are adjacent.** `func_L07_00333C70` needs `extern s32 D_L07_001DF600[2];`: the unsized `[]` leaves gcc's split pair scheduled apart (2 differences), while the two-element declaration is one `la` macro that Ps2EeAs expands adjacently.
- **Resolved in the second retry: a table's high temp can take the loop counter's register.**
  `func_L07_003328D0` now uses an unsized `D_L07_001E0CD0[]` with `section(".sdata")`.
  Its address is one `la` rather than two independently allocated address instructions, restoring
  retail's source `$5`, counter `$4`, and table `$6` (11 to 0; full PAL level `MATCH`). This
  applies the level-11 incomplete-array recipe without inventing a smaller array size; the
  earlier 90 pointer/index/CFG variants had left the address representation unchanged.
- **Split a byte swap into two named `u8` locals.** `func_L07_00334968` needs `u8 a = arg0[i]; u8 b = arg0[j]; arg0[j] = a; arg0[i] = b;`; writing the swap inline or through one temporary left 4 differences in the load/store assignment and registers.

## Patterns from level 11 (Obani Moons, PAL)

Found while matching 17 functions of `src/levels/11_obani_moons/` (one function per agent; 14 of
them in the third round, 9 of those real VU0 written with `include/vu0.h` and j-form statements)
and leaving 7 in assembly (one of them, `func_L11_003C3650`, comes from the later catalogue fix
and was not attempted). Only what is new compared with the level 1 to 5 sections above.

### Declarations and codegen

- **A dead load/test pair can come from two identical `if`/`else` arms.** In
  `func_L11_00433210`, retail keeps `lw $v1,0x38($s0)` / `andi $v1,$v1,0x400` before a call and
  never uses the result. The source is an `if (p->f38 & 0x400) d = f(...); else d = f(...);`
  with the same call in both arms: gcc merges the arms but the pre-merge load and `and` survive.
  The pair lands in `$v1` (not `$v0`) only when the *preceding* path-helper call is declared
  with a non-void return and called as a bare statement: its `$v0` result keeps `$v0`
  unavailable in that block. `void` gives 2 differences, all in the dead pair.
- **A constant with a zero low half is inline even with the default assembler.**
  `func_L11_00433210` writes `0.5f` and the default `ee-as` produces retail's
  `lui $at, 0x3F000000` / `mtc1` with no `@ps2as` and no `.lit4`. Check the generated bytes
  before adding `@ps2as` for a lone float constant; the other constants in the level (0.15f,
  0.7f, ...) do need it.
- **One scalar extern can serve both address forms.** Under `@ps2as`, `extern s32 X;` gives the
  `lui`/`lw` macro at normal sites and the `$gp` form in a branch delay slot, so the older
  "two aliases with hints 4 and 16" recipe is not always needed (`func_L11_003FCBD0` keeps one
  name for `D_L11_001DEC30`). Keep two names only when the same address is also read as a
  multi-word object with a different form.
- **A value needed only on a join path sinks into a `bnel` delay slot.** In
  `func_L11_003FCBD0` the top test is a `bnel` whose delay slot loads the flag again after the
  `if`. Write the flag into a local before the `if`, store `1` in the body, and read the global
  again after the `if`; testing the global directly gives a plain `bne`.
- **Inline float stores make the FP register numbers follow the store permutation.** In
  `func_L11_003A9B30` the constants are inline (`lui`/`ori`/`mtc1`) and their `$f` numbers are
  assigned by the scheduler's load order, so the permutation that fixes the store order also
  fixes `$f1`/`$f2`. Search the independent stores, and judge the `$f` numbering on the same
  run rather than separately.
- **A sized array can make a call argument's address adjacent.** `extern u8 X[8]` (no
  `.extern` hint) gives the one-pseudo `la` that Ps2EeAs expands to adjacent `lui`/`addiu` for
  the two `func_L01_0046A610` call sites of `func_L11_003A9E60`; an unsized `X[]` hoists the
  base into a saved register and adds a `move` at each site.

### Register weight and allocation

- **Superseded for the twins (they matched with `section(".sdata")`, below):** **One extra
  reference moves a source address into a callee-saved register.** In the twins
  `func_L11_003BDED0` and `func_L11_003FCBD0`, retail keeps `addiu $sN, $gp, off` (the address
  of the 16-byte `$gp` source) across the outer loop and loads it with `lq`. Routing the TImode
  copy through a temp inside a dead `do { t = SRC[0]; } while (0); DST = t;` gives the address
  pseudo 6 references instead of 5; at that weight it outranks the hoisted literal 12 and wins
  the saved register. With 5 references it is rematerialised at the `lq`.
- **A dead second set keeps a literal out of a saved register.** `s32 m = 240; ...; m = 0;` as
  a block-local makes loop.c rebuild 240 in the loop body (retail's `$t1`) instead of hoisting
  it into `$fp`, which then holds the literal 12 as retail.
- **A shared local can outrank the function's arguments.** In `func_L11_003A2DB0` a `path`
  local used across several switch cases (9 refs) pushed `a0`/`v` out of `$s3`/`$s2`; writing
  `v + 0x220`, `v + 0x300` and `v + 0x2E0` inline at each use (separate pseudos) restored
  retail's entry allocation and the prologue.
- **A block-scoped `s32 one = 1;` produces `movz`.** In `func_L11_003A9E60`, with `one`
  declared in a block right before the first switch, `t = (f(...) == 0) ? one : 0;` compiles to
  retail's `move $a0,$zero; b; movz $a0,$s1,$v0`, and `one` lands in `$s1`. Function-scope
  `one` goes to `$s4`; `long one` emits `dli`. Bool expressions, `c ? 1 : 0` and `&&`/`!` all
  fold to `sltiu`/`movn`.
- **Superseded: in-place `i++` from entry addresses computed first.** Computing
  `e = &D[i]; pp = &D[i].fC; i++;` gives the in-place `addiu` but loses the index's register
  (107 differences); `func_L11_00472AD8` matched with the gcse PRE recipe under "Loops and
  scheduling" below.

### Switches

- **Empty cases fill out the table, and a separate pointer local reuses the dead loop index.**
  `func_L11_003A9260` needs cases 1, 2 and 5 written (empty) to get retail's 5-entry table, and
  its post-loop lookup needs its own pointer local (`p`) instead of reusing the loop's `e`; with
  one variable gcc allocates `$s4` where retail reuses the dead loop index `$s1`.
- **The second distance call goes before the store.** In the nearest-node loop,
  `best = distance(...); *(s32 *)(v + 0x2E8) = i;` matches; the store first pins the `sw` ahead
  of the `jal`.

### Declarations and address forms (round 3)

- **A level table retail builds with adjacent `lui`/`addiu` in one register, even in the
  prologue: `extern T X[] __attribute__((section(".sdata")));` with no `.extern` hint.** gcc
  treats it as small data and emits one `la` insn (Ps2EeAs expands it), without lying about the
  size the way `extern u8 X[8]` does; gcse PRE then hoists that one insn to the entry block, which
  is where retail's `la $s6` / `addiu $s7,$gp` come from. Mark the destination of the `sq` the same
  way. With an `.extern X, 4` hint the same declaration gives `addiu $r,$gp,off` for a 32-byte
  array. `func_L11_003BDED0` and its twin `func_L11_003FCBD0` (41 to 0; this replaced the dead
  `do`/`while` copy and dead-second-set recipes above), `func_L11_003AFF60`. The existing
  `func_L11_003BE100` block already declared `D_L11_001DE3D0_003BE100` this way.
- **A byte retail loads with `lui`/`lbu` at a branch target, never in the delay slot: read it
  as the next byte of a declared global.** `extern u8 D_001D5470;` and `(&D_001D5470)[1]` for
  the byte at 0x1D5471 (`func_L11_003AE290`, 2 to 0). A scalar, an unsized array, a 16-byte
  struct and aliases with hints 1 and 16 all let reorg put a `$gp` `lbu` in the slot. This is
  the large-function pass's "next word of a declared global", for a byte load.
- **A store through a cast pointer holds later global loads behind it; write it as a struct
  member.** `*(f32 *)(a0 + 0xF8) = f(...)` is untyped memory, so the following `lui`/`lw` of a
  pointer global may not pass it and a longer-path index load issues first;
  `((M *)a0)->angle = f(...)` lets the pointer load go first, and local-alloc then gives the
  index, the quadword and the pointer retail's `$v0`/`$v1`/`$a0` (`func_L11_00350EE0`, 13 to 0;
  the store-side counterpart of "Struct-member reads vs cast-pointer reads"). The same fixed the
  store block of `func_L11_00348538` (`v->f40->f0 = D;` with no temporaries).
- **A pointer global indexed as a typed struct gives the index-first `addu`.** `extern T *P;`
  and `P[n].f30` (or `((T *)P)[n].f10`) give `sll; addu idx, base`; `(u8 *)P + (n << 7) + 0x30`
  gives base first (`func_L11_00348538`, `func_L11_003A9E60`). The "addu operand order is picked
  by the access form" rule, for a table reached through a pointer. A table whose fields lie past
  the stride (`i << 7`, fields at 0xD0/0xDC) needs a local `(E *)(base + (i << 7))`, or gcc
  folds the offset into the `%lo`.
- **A callee that takes two small constants with `addiu $a0` in the `jal` delay slot:**
  declare the parameters `long, long` (`func_003A9440(long, long)` in `func_L11_00350360`;
  `s32` and `u32` give the other order).

### Quadword copies (round 3)

- **Copy quadwords from and to global tables through a small inline helper.**
  `static __inline__ void vcopy_3AF6B8(vu0_v4 *d, vu0_v4 *s) { *(vu0_q *)d = *(vu0_q *)s; }`
  (plain C, a per-function suffix). The table address becomes an argument, so gcc sums the
  indices first and builds the symbol's `lui`/`addiu` last; its `lo_sum` lives one insn and
  loop.c reports it "not desirable", so the address is built at the use as in retail. A direct
  `*(vu0_q *)&D[i][k]` loads the symbol before the shifts, and loop.c hoists, spills and
  rematerialises it (`func_L11_003AF6B8`). In `func_L11_003798E8` the same helper works the other
  way: the formal copy lengthens the high part's life, loop.c hoists it to the outer preheader,
  global-alloc leaves it unallocated and reload rebuilds it at the use with retail's register.
- **`*(vu0_q *)&d = *(vu0_q *)&s` instead of a `vu0_v4` struct assignment.** The TI copy
  depends on the `f32` stores to the same region, so the `lq` stays after them, and it folds into
  an induction variable (`0x200($s0)`) where a struct copy hoisted and spilled the second array's
  base (`func_L11_003AF6B8`, 340 to 118; `func_L11_00316318`, 235 to 137).
- **One shared TI temporary decides an `sq` against an argument move.** `row = *(vu0_q *)&t0;
  *(vu0_q *)&m[2] = row;` with `row` assigned again later in the same block gives the `sq` one
  more dependent, so it wins sched2 over a `move $a2,$s2` (`func_L11_003AF6B8`).
- **In j-form, a shared `lqc2` that feeds two `vadd`s:** write the result back into the first
  operand's variable (`x = vadd(x, y)`), or use a fresh variable for the second load, to keep
  the source load order (`func_L11_00348538`). An extension of "Getting retail's registers".

### Loops and scheduling (round 3)

- **In-place `i++` in a loop with a switch: it is gcse PRE's temporary for `i + 1`.** Retail's
  `addiu $s2,$s2,1` against our `addiu $s4,$s2,1; move $s2,$s4` is the PRE copy (`-da`, `.gcse`:
  "PRE/HOIST ... copying expression"; in `tools/regalloc.py` a high pseudo number with few
  references). It gets two references per predecessor block of the shared `i++`. Write one
  `i++` at the end of the body (`next: i++;`, cases end in `break` or fall into `next`) and end
  one case with `do { do { goto next; } while (0); } while (0);`: PRE inserts before that block's
  final jump, so the insertion sits two loop levels deep and the temporary reaches 12 references,
  between `e` (0.828) and the flag (0.750), and shares `$s2` with `i` (`func_L11_00472AD8`, 13 to
  0). The window is narrow (11 references are too few, 13 steal `$s1`); check it with
  `regalloc.py`. Wrapping the jump of a case whose next label is aligned adds a `.p2align` `nop`.
  This resolves the open problem of the same name below and very likely level 2's
  `func_L02_00473410` and its level 27 twin (untested).
- **A single `n++` at the end of the body, with `goto next` from every skip**, instead of
  `continue` or the `for` increment: the counter has fewer references, which reorders the
  priorities of the saved registers (`func_L11_003510D0`, 125 to 17). Tail blocks placed inside
  the loop before `next:` and reached by `goto`, each ending in `return`, give retail's block
  order.
- **A candidate file flag: `-fno-sched-interblock` on `L11_003AE1B0.c`.** In
  `func_L11_003AFF60` the two inner loops are haifa regions of 79 and 81 insns, under
  `MAX_RGN_INSNS` (100), so sched1 moves the `mtc1`/`cvt.s.w` and the `j++` into the loop head;
  retail has them in the tail and the `andi` in the `beqz` delay slot. With
  `-fno-sched-interblock` the C matches (218 differences without it), and the file's nine other C
  functions match with and without it. It is one function's evidence, so it is committed on its
  own. Diagnose it with `check.py --flags=-fno-sched-interblock`; a sharp drop points to it
  (in `func_L11_0034C8A0`, a 448-insn loop, it changes nothing).
- **Integer reloads pick registers in turn** (`$v0`, `$v1`, `$a0`, skipping busy ones): one
  reload more or fewer shifts every later one. `func_L11_003798E8`'s five differences were one
  missing reload; the `.greg` dump shows the sequence. An address in an unexpected register just
  before an `lq` is the sign.
- **A field load moved before a call** (`v = *(arg + 0x68)` before `func_00382498(n1, n2)`)
  fixed a whole prologue (`func_L11_003AF6B8`). The load counterpart of "A store written before
  the last call fills its delay slot". Computing the two quotients `(g * 5 + 2) / 6` into locals
  before a float constant store swapped `$f25`/`$f26` back.
- **Scalar and vector locals too, not only stack buffers:** "Function-level locals for stack
  buffers" (rounds d to k) holds for the scalars and vectors of sibling blocks as well; gcc 2.95
  never shares their slots, so `func_L11_00316318` declares them once at function level and
  reuses them in both blocks.
- **A tail `if (G != n) { f(n); G = n; }` written in each arm** (with `n = 4` and `n = 3`)
  instead of after the join gives retail's `beq`/`b`/`nop` (`func_L11_00316318`).
- **A pointer argument next to an argument that contains a call** (`f(v + 0x100, e, ang,
  g() * c)`): compute the inner call into a local first, or gcc builds the pointer before it in a
  saved register (`func_L11_003AE290`).
- **The inner loop as `i = 0; while (call(...) != 0 && ++i < 7) { ... }`**, with `continue` and
  `break` in the body, reproduces retail's jump-to-test loop and keeps the compared literals out
  of saved registers (`func_L11_003798E8`). `V4 *pp = &pos;` at the top with every access through
  `pp` keeps `&pos` in `$s3`, where direct `pos.x` rematerialises it.

### Open problems (drafts in `nonmatching/levels/`)

- **Incoming callee-saved register:** `func_L11_003C7B60` reads `$s3` before writing it (the
  catalogue keeps it; the sole caller does not set it). Reproducing it needs an uninitialized
  local, which is undefined behaviour and the AGENTS stop signal; the function stays a near
  miss. A K&R definition is required there too, because a later block of the file calls it with
  no arguments.
- **Resolved: the twins' remaining 63** (`func_L11_003BDED0`, `func_L11_003FCBD0`) with
  `section(".sdata")` above, and **the in-place `i++` residual** (`func_L11_00472AD8`) with
  the gcse PRE recipe above.
- **Saved registers in 16-byte `sq` slots** (`func_L11_003BDA60`, `func_L11_0034F0F0`): the
  level-2 `sq_ra` class; levels have no `sq_ra_funcs` table, so they were not attempted.
- **Resolved by the catalogue: the cut delay slot** of `func_L11_004AFFF0`: the catalogue fix
  that keeps delay slots out of data-pointer starts (59329b99) joined it to the function before.
- **Large reconstructions:** `func_L11_003A2DB0` (428 diff, was 1034: float register allocation
  and spills, the idx loops gcc strength-reduces), `func_L11_0034F5E0` (470, was 474: loop.c
  hoists `&vel`), `func_L11_0034C8A0` (667, first attempt: allocation and hoisting with the
  control flow right). Their headers in `nonmatching/levels/` list what is left.

## Patterns from level 7 (Annihilation Nation, PAL)

Found while matching the remaining functions of `src/levels/07_annihilation_nation/` in a
continued pass (79 matches and eleven near misses so far; the first pass recorded 23 in this same
section). Only what is new compared with the sections above.

### Switches

- **Adjacent cases with the same destination must stay separate `case` labels, each with its own
  `return`.** The compiler's `group_case_nodes` merges stacked labels and `case A ... B:` into a
  range node, which moves the tree's root: `func_L07_00333918` came out with the root at `0x1A18`
  instead of retail's `0x1A1C` and 53 differences. Thirteen separate `case` labels returning the
  same pointer made it `MATCH`; the compiler then merges the identical `return` blocks itself and
  the `lw 0x68($4)` lands in the annulled `beql` delay slots. The level 6 note on `movn` still
  applies to the selector form.
- **The order of the `case` labels in the source sets the body layout.** `func_L07_003C12A8`
  needs `case 2 / case 0 / case 1` (retail's order); numeric order lays the bodies out
  numerically and inverts the tree's branches. Scalar externs with a 16-byte hint
  (`D_001D553D_003C12A8`, `D_001D5551_003C12A8`) then fixed the flag `lbu` register.

### Globals and flags

- **A `.lit` pointer read through `$gp` needs its `_sda` name to stay `$gp`-relative under
  `@ps2as`.** `func_L07_003C1C88` matched with plain flags through `extern W *D_L07_001DE550;`
  (ee-as turns it into `lw 0x1CA0($gp)`), but under `@ps2as` the same declaration becomes
  `lui $v0,0x1E; lw $v0,-0x1AB0($v0)` (52 differences). `extern W *D_001DE550_sda;` with
  `__asm__(".extern D_001DE550_sda, 4");` restores the `$gp` load and matches under either
  assembler. This is the `$gp`-slot side of "Globals: gp vs lui".
- **`@ps2as` is a file decision and can break an `INCLUDE_ASM` neighbour** (the level 1 and level 3
  notes above; confirmed again here). `func_L07_003C1360` matches under `@ps2as` but
  `L07_003C0710.c` also holds `func_L07_003C1DC8` as `INCLUDE_ASM`, and switching the file to
  Ps2EeAs changed that function's bytes at word `+0x50`, failing the build. The flag was reverted
  and `003C1360` stays a near miss. Test the flags alone, on a tree with no new C, before
  integrating: a flag-only build proves the neighbours before the new blocks are in.
- **A read-only loop keeps a repeated field in registers, not `lbu`.** In a loop with no stores,
  writing `a0[0x21]` literally makes gcse replace the repeats with register copies
  (`move $a2,$a0; move $t1,$a2`), while the storing sibling `func_L07_003CE940` reloads with
  `lbu` each iteration from the same source shape (`func_L07_003CE858`, 49 differences with a
  cached local, `MATCH` with the literal repeats). This is the integer-field variant of the gcse
  entries above; the fix is to write the access the way retail repeats it, not to cache it.
- **A float literal retail keeps across a `jal` comes from a named local initialised before the
  call.** `func_L07_003A6110` needs `f32 num = 1.8133334f; ... a = num / d;`: the direct
  `1.8133334f / d` reloads the literal after the call (47 differences) and `a = 1.8133334f; a /= d;`
  reuses the numerator's register (6). The named local keeps it in `$f20` across the call. Variant
  of the gcse float-constant recipe above, for one value read on both sides of a call.
- **Start from the NTSC-U draft when it exists.** `src/us/levels/func_L07_003AEDE0.c` is the
  NTSC-U twin of `func_L07_003B0660` and gave the body shape on the first compile; rename the
  catalogue names and swap the PAL constants (the same recipe as "Look for a matched twin",
  extended to the `src/us/` drafts). `func_L07_00330748` likewise started from its NTSC-U draft
  and needed only the PAL constants changed (`0x3E8`/`0x7D0` against US `0x4B0`/`0x960`).

### More shapes and scheduling

- **Two identical consecutive stores reproduce a `lw/sw; lw/sw` pair.** `func_L07_003B90F0`
  writes the same `p->f98 = a24->f10;` twice; the intervening store to `0x98` invalidates the
  load's CSE, and the reorg moves the second `sw` into the `jal` delay slot. Collapsing the pair
  into one statement loses the reload.
- **`f32 field = 0;` on a struct member emits `sw $0, off` and a following `lwc1`.** `func_L07_003DD6D8`
  reads the field again after storing zero; writing the zero as a float assignment gives the
  store/load pair without a union or bit cast.
- **Name the fold result in a block local.** `func_L07_003B48E8` needs
  `f32 u = (t - 0.4f) * 0.5f + 0.4f; if (0.5f < u) u = 0.5f; t = u;`: naming the result (not the
  constant) moves the `0.4f` literal to `$f12`, and `t = u` coalesces without an extra `mov.s`.
- **A typed struct store stops the alias assumption.** In `func_L07_00332BE0`,
  `*(s32 *)(e + 0x98) = 0;` makes gcc keep the loop-invariant global loads inside the loops
  (67 differences); `e->f98 = 0;` with a struct pointer lets them hoist to the preheaders and
  matches.
- **`for (n = 3; n > 0; n--)` with `n - 1` in the body fuses the decrement into the argument
  register.** `func_L07_00353498` keeps the counter in `$a1` with `move $s2,$a1` in the `jal`
  delay slot and `move $a1,$s2` after, instead of a callee-saved counter.
- **Two loops over one struct need distinct counters.** Reusing one counter puts the struct
  pointer in `$s2`; `i` and `j` in `func_L07_003B12D8` put it in `$s1` as retail has. Counter-
  example to "A float literal retail keeps across a `jal`": the `36.0f` in the same function
  needs no named local.
- **o64 stack argument slots step 8 bytes.** In a 13-argument call (`func_L07_003AF678`) the two
  trailing integers are `sw $0, 0x0($sp)` and `sw $0, 0x8($sp)`; the missing `sw` at `0x4` is
  the slot step, not a lost argument.
- **A `.lit` base above the `jal` needs the one-instruction `la`.** `func_L07_00353378` gets
  `lui`/`addiu` from `section(".sdata")` on an incomplete type with no size hint, and sched1
  hoists it above the call; a plain array extern emits two RTL insns and stays in the preheader.
  If the preamble already declares the symbol, the `section` attribute on the later declaration
  is ignored: use an address-suffixed alias (`D_L07_001DD604_sdata`).
- **Index a strided element pointer, not `(u8 *)base + (idx << 8)`.** `func_L07_003D9330` needs
  `D[idx]` on a 0x100-stride element type so the `sll` comes from type scaling and the index
  inherits the dead `$v0`; the explicit shift leaves six differences.


### More notes from the continued pass

- **o64 passes eight integer arguments in registers**, `$a0-$a3` then `$t0-$t3`, before any stack
  slot. A callee with extra integer parameters keeps them in `$t0-$t3`; their argument count is
  real even when the code never reads them (`func_L07_0035CAB8`). This extends the o64 stack-slot
  step note above.
- **Stacked `case` labels are fine when grouping cannot move the tree's root.** `func_L07_003BAC58`
  matches with `case A: case B: case C: return f();` (fourteen values in six groups); the separate-
  labels rule above only matters when the grouping would change the comparison tree.
- **An index on the symbol keeps the `la` and the biv separate.** `D_001426E0[0x8E + i]` emits
  `la` plus `addiu p,base,0x8E`; `u8 *p = D_001426E0 + 0x8E` folds the offset into the `%lo` and
  loses one instruction (`func_L07_003C0FC8`).
- **A load written above the call lands in its delay slot.** Reading the object pointer before the
  `jal` that retail schedules it into lets the reorg use that slot and fixes the argument order of
  the callee that follows (`func_L07_00330828`, 10 differences to `MATCH`).
- **A `divs_nops` row of 0 when the only retail nop is the `mtc1` hazard.** `func_L07_00332F90`
  had a row of 1 and a single retail nop before its `div.s`; the assembler emits that hazard
  itself, so the correct row is `0` (all 344 bytes then match).
- **Index the NULL-terminated table when retail sets the loop pointer after the entry test.**
  `func_L07_003A7C10` and `func_L07_003DC6E8` walk `D_L07_0021C460[]`: the pointer form
  `for (p = D; (m = *p) != 0; p++)` puts the `addiu` for `&D` in the prologue block, which adds a
  dependent to the `$s` save, reorders the prologue saves and moves `mov.s $f20,$f0` out of the
  `beqz` slot (5 differences); `for (i = 0; (m = D[i]) != 0; i++)` lets loop strength reduction
  set the pointer up in the preheader, as retail does. A refinement of "Pointer vs index loops".
- **A float call that feeds a later call gets its own statement.** In `func_L07_003E3388`,
  `func_0038CE20(&dir, &m.r[2], -func_003824E0(0.18f, 0.24000001f))` computes the address
  arguments into saved registers before the inner call (51 differences, a 0xA0 frame);
  `f = func_003824E0(...);` first, then the call with `-f`, matches.
- **A third file takes the proven vf2 + `@ps2as` line.** `func_L07_003A79F0` (VU0, `vec_sub_ab`
  and `vec_add_ab`) matches only with `-mvu0-use-vf0-vf2 ... @ps2as` on `L07_003A70B0.c`
  (the vf2 class for the interleaved `move $s3,$a3`, Ps2EeAs for retail's `jal; nop`) and a
  `divs_nops` row of 2. The full PAL level build with the flag change, which assembles the
  file's four `INCLUDE_ASM` neighbours with GNU as, still matched. Its byte twin
  `func_L07_003DC4C8` (`L07_003DBE28.c`) now also matches with that line and row.
  Ps2EeAs initially changed the existing `003DBE28` pointer addresses from `$gp` to
  `lui`/`addiu`; early `.extern D_L07_001DE908, 4` and `.extern D_L07_001DE928, 4`
  hints, matching their declared scalar sizes, keep the retail forms. The full PAL
  level build matched with flags/metadata before the new functions were integrated,
  and again afterwards. `003DBF10` and `003DC040` in that file also match; `003A7378`
  and `003A7558` reuse the already proven `L07_003A70B0.c` flags. The latter repeats
  its four-byte hint for `D_L07_001DE350_sda` so isolated checks preserve the same context.
- **A fourth file takes the vf2 + `@ps2as` line, and a size hint unblocks a fifth.**
  `func_L07_003D5008` (VU0, `vec_add_ab`) matches with `-mvu0-use-vf0-vf2 ... -mno-split-addresses
  @ps2as` on `L07_003D48D0.c` (the default assembler pools `1.2566371f` in `.lit4`, and the
  volatile-block form cannot interleave `move $a0,$s0` between the `lqc2`s); the full PAL level
  build matched. For `L07_003CC2B0.c`, `@ps2as` used to break the matched `func_L07_003CD9F8`
  (its `$gp` table `D_L07_001DE6F0` became `lui`/`addiu`); `__asm__(".extern D_L07_001DE6F0, 8");`
  (the declared `[1]` of an 8-byte struct) keeps it `$gp`-relative under both assemblers, which
  would let the file take the same line for `func_L07_003CD7E0`, `003CDB30` and `003CDC80`
  (drafts; not yet built).

### Open problems (drafts in `nonmatching/levels/`)

- **`@ps2as` blocked by a neighbour:** `func_L07_003C1360` (31 differences with the owning
  file's plain flags: inline float constants load from `.lit4` through `$gp`). It matches under
  Ps2EeAs, but `L07_003C0710.c`'s `INCLUDE_ASM` function `func_L07_003C1DC8` changes assembler
  and differs, so the flag is not added. The third retry found `003C1DC8` now in C but the
  blocker moved: with `@ps2as` the now-matched C `func_L07_003C1138` differs at word `+0x154`
  in the full level build, so the flag stays off.
- **Resolved in the retry: branch-likely tied to a local allocation.**
  `func_L07_003C0F40` now matches with `e->h2` passed directly in both call arms, including
  the zero-arm callee that ignores this parameter. A shared `kind` local gave two flag-register
  differences; the repeated field expression lets gcc hoist the load into a non-annulled
  `bnez` slot while keeping the flag in `$a0` (1 to 0, full PAL level `MATCH`). The callee's
  reconstructed signature includes the unused parameter; no incompatible function cast is
  needed. This is a variant of the existing ignored-callee-arguments and repeated-access
  recipes, not a reason to force branch instructions with assembly.
- **Resolved counter allocation, literal assembler blocker remains:** `func_L07_003CDB30`
  improves from 44 to 28 raw differences with unchanged plain flags by using matched twin
  `func_L07_00353498`'s `for (count = 3; count > 0; count--)` and passing `count - 1`.
  The `$a1` counter and `$s2` save/restore pair now match: the earlier unreachable-C claim
  was incorrect. Only the default assembler's `1.8f` literal-pool expansion remains; its
  two missing words shift the suffix. This applies "More shapes and scheduling" above,
  not `-fcaller-saves` (the historical trial of that flag had no effect).
- **Resolved in the fourth retry: the former scheduler ties.** `func_L07_003AD088` (31
  differences; 18 under a file-level `-fno-sched-interblock`, which the file's neighbours do not
  allow) matches in the full PAL level build when written in the loop form of its twin
  `func_L07_003BE9B8` (below), with only the offsets changed. Neither function was a scheduler
  tie; the level 7 interblock-motion class has no remaining member.
- **Two TI arrays in one ring buffer:** `func_L07_003CE330` (newly reconstructed, 1 difference:
  `addu $a0,$a3,$v1` against retail's `addu $a0,$v1,$a3` at `+0x5C`) has the same residual as its
  116-byte siblings `func_L07_00353D98` and `func_L07_003A63E8`. Index-first address forms fix the
  `addu` but drop the `move $v1,$a0` pointer copy; three other wordings gave identical bytes.
- **Resolved in the third retry: `func_L07_003BE9B8`** (21 differences to full PAL level
  `MATCH`). The RTL `sched` dump showed per-block regions, so no interblock motion was
  involved. Naming the address `u8 *t = q + i;` at the top of the `if` body puts its `addu`
  before the inner join (in retail's `beqz` slot), and bumping the byte counter as
  `if (++p[i - 2] > 10)` stores the sum before zero-extension and compares a zero-extended
  copy, where `u8 v = p[i - 2] + 1; p[i - 2] = v; if (v > 10)` stores the zero-extended value
  (a byte variant of "A `u16` counter incremented in an `s32`").
- **Resolved in the third retry: one-instruction delay-slot shift.** `func_L07_003C0BE8` (15
  differences to full PAL level `MATCH`): the moving `lui` was `D_001D553D`'s. Reading the flag
  as `D_001D5530[0xD]` with `extern u8 D_001D5530[] __attribute__((section(".sdata")));` makes
  the load one `la`-based macro that gcc counts as two instructions (symbol plus nonzero
  offset), so reorg fills the `beqz` slot from the target as retail does. The same declaration
  read at offset 0 (`D_001D553D[0]`) gave the original 15 differences: the nonzero offset is
  what keeps the load out of the slot. The original note follows.
- `func_L07_003C0BE8` (15 differences, before the fix above) came from the
  `DJ_001426E0[0x91]` `beqz` slot: retail has `daddu` in the slot and the `lui` after the branch.
- **Resolved in the retry: register tie on a short literal.** The saved draft of
  `func_L07_003B6CD8` declared `func_L07_003A2380` as returning `void`, conflicting with
  the current owner's correct `s32` prototype. Restoring the real return type fixes the timer
  literal and store registers (2 to 0, full PAL level `MATCH`), an application of "The
  callee's return type changes the caller" above. Literal-type/layout searches were unnecessary.
- **Scheduler and allocation residues:** `func_L07_003B3C78` (36 differences: `$s0/$s1` swap and
  the `i == 0` arm's `bc1fl`), `func_L07_003CD6A8` (6: `sll; lui; addiu` versus
  `lui; addiu; sll`) and `func_L07_003CDC80` (35 raw positional differences in the retry,
  historically reported as three localized literal differences: the default assembler's
  `0.7f` pool load shortens the body by 12 bytes and shifts the suffix). The latter needs
  `@ps2as`, but the same file's already matched C `func_L07_003CD9F8` needs the plain
  assembler, so mixed assembly slicing does not remove this restriction.
- **Resolved in the retry: float/int argument interleaving.** `func_L07_003CDF40`
  uses the argument order of matched caller `func_L07_00353980`: three integer arguments,
  three floats, then the remaining three integers. A caller-suffixed declaration preserves
  the earlier caller's different order in the same file. This fixes the second call's four
  scheduling differences with the existing `@ps2as` flags; the full PAL level build matches.
  The callee's own floats-first order instead gave 17 differences, and copying the twin's
  `if`/`else if` structure left four. This applies the existing parameter-order recipe.
- **Resolved in the retries: the guarded quadword-copy family.** `func_L07_003A6EA8`,
  `func_L07_003A71E8`, and its later retried byte twin `func_L07_003BA098` all went from
  7 differences to full PAL level `MATCH` with
  `extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));`. This applies the existing
  one-instruction `la` recipe from "Globals and flags": the source address no longer has a
  separately schedulable `lui` that occupies the branch slot, and the object's register becomes
  `$a2`. The first file's existing `@ps2as -fno-sched-interblock` flags and the second file's
  default assembler flags are unchanged; `003BA098` also keeps its default assembler flags.
  A plain inline copy helper alone changed neither original twin.
- **Resolved in the third retry: quadword-copy scheduling.** `func_L07_003A8D70` (2 differences:
  `move $a1,$zero` and `lw $a3,0x68($t0)` exchanged) matches in the full PAL level build with
  the same `extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));` as its sibling
  `func_L07_003BA098`. The earlier typed-pvars and aligned-aggregate wordings had left the
  address as a split pair; the one-instruction `la` is what moves the argument setup.
- **Resolved: `func_L07_003328D0`**, the table high-temp problem described in the level 6
  section above. Its source table now uses the incomplete-array `.sdata` recipe; two
  address-suffixed aliases preserve the different table/word types that later owner blocks use.
  `func_L07_00332848`, the 10-difference preheader-order problem on the same table, resolved
  in the third retry with the same `extern s32 D_L07_001E0CD0[] __attribute__((section(".sdata")));`
  (full PAL level `MATCH`): a hoisted table address that gcc splits is a candidate for this
  recipe even when the residual looks like loop-invariant ordering rather than registers.

- **VU0 interleaving needs a proven file-wide vf2 flag:** `func_L07_003B4308` and
  `func_L07_003C8CF8` match with the existing j-form recipe and
  `-mvu0-use-vf0-vf2` on their owning files `L07_003AF398.c` and `L07_003C7468.c`.
  The flag-only full PAL level build matched before either function was integrated;
  the full build also matched after both integrations. Opaque VU0 blocks left six and
  two differences respectively because retail puts an ordinary argument move inside
  the sequence. `003B4308` reuses `vec_add_ba`; `003C8CF8` reuses `vec_sub_ab` and
  `vec_add_ab` with real operands.
  These are whole-file decisions, with no per-function flag or ordinary EE asm.
- **Two-array copy address order remains open:** newly reconstructed
  `func_L07_00353D98` and `func_L07_003A63E8` both improve from 30 to one word with their
  existing flags. A divisor `ten` local to the overflow branch shares the clamp and modulo
  materialization without hoisting it to the join. A struct containing the two TI arrays
  keeps retail's duplicated pointer, but the final `addu` has reversed operands. Pointer,
  TI and aggregate address forms correct that order while losing the pointer copy; they
  do not resolve the function. No division-padding table applies to integer divisions.

- **Literal-pool near miss:** newly reconstructed `func_L07_003CD610` improves from
  17 to 15 raw positional differences with its unchanged plain flags. An incomplete
  `.sdata` table declaration keeps the entry `lui`/`addiu` together. Only the default
  assembler's `0.15f` pool expansion remains (eight bytes shorter, shifting the suffix);
  the Ps2EeAs diagnostic is exact. The documented eight-byte hint for `003CD9F8` above
  is a possible whole-file route, still requiring its own full build. No division-padding
  row applies. `nonmatching/levels/func_L07_003CD610.c` preserves the best draft.

## Patterns from level 27 (Aquatos Base, PAL)

Found while matching 24 functions of `src/levels/27_aquatos_base/` (one function per agent,
across two passes; the two 178-case giants came last) and leaving one near miss. Only what is
new compared with the level 1 to 6 sections above.

### Declarations and address forms

- **`u128_t` casts, not a struct copy, for `lq`/`sq` when the pointer globals must be reloaded.**
  `*(u128_t *)dst = *(u128_t *)src;` does not let gcc CSE two function-pointer globals across
  the store, so retail's reloads survive; a `vu0_v4` struct assignment does (`func_L27_003A17B0`,
  and the same cast is what makes `func_L27_003A1B30` reload `d->f78` and `D_L27_001DEE00`
  after the copy).
- **A 4-byte pointer read in a `bltz` delay slot becomes `$gp` under `@ps2as`.** Add
  `__attribute__((section(".data")))` to the declaration to keep retail's `lui`/`lw` pair
  (`func_L27_003A2548`).
- **A negative constant must be written as a negative literal.** `... / 90.0f + -3.1415927f`
  emits `add.s` with `0xC0490FDB`, and `a.z += -15.0f` emits `add.s -15.0`; writing
  `- 3.1415927f` or `-=` gives `sub.s` with the positive constant (`func_L27_003A3498`,
  `func_L27_003A1B30`).
- **A 32-bit sign mask as a `long`.** `(x & 0x80000000) == 0` folds to `bltz`; write
  `long m = -2147483648; if ((v & m) == 0)` to get retail's single `lui` mask, `and`, `bne`
  (`func_L27_003A2548`).
- **A separate tail pointer local changes the tail's allocation.** In `func_L27_003FCDE0`,
  reusing the loop's `u8 *m` for the `mobys[2]` load gives a three-word diff; a new tail local
  `u8 *p` matches (the level 11 twin, `func_L11_003FCE88`, has the same shape).
- **A `%hi`/`%lo` pair 0x10000 away from the name is a wrong symbol, not an allocation diff.**
  A one-instruction difference on an `lui` high half means the signed `%lo` carried into the
  high half: retail's pair pointed at `0x001A818C`, so the C name had to be `D_001A818C`, not
  `D_001B818C` (`func_L27_003A1B30`).
- **`lw 0x68($sN)` where `$sN` holds a state struct is a back-pointer field of that struct.**
  Declaring it as the struct itself changes the argument and the delay slot; `S *f68` at 0x68
  (`func_L27_003A1B30`) is the form retail has.

### Switches

- **SN cc1's switch threshold is 5.** `HAVE_casesi` is 0, so `CASE_VALUES_THRESHOLD` is 5: a
  switch with 5 grouped case nodes and a dense span (range <= 10 * count) becomes a jump table,
  while 4 nodes or a wide span becomes a balanced compare tree. Retail's 5-way type dispatch in
  `func_L27_0041F918` is a tree, so the source needs a raised node count: adding two far empty
  labels (`case 100: case 101: break;`, which `group_case_nodes` merges into a range node)
  reproduces retail's tree shape. Both of its switches need this.
- **Shared tails in a tree-ish dispatch are explicit `goto`s.** Retail shares the `4pi/3*r^3`
  block between types 0/1 and 2, and the rejection-sampling block between types 0/1/2; writing
  the shared bodies once and jumping to them saved about 45 instructions (`func_L27_0041F918`).
- **The in-place `i++` class is the sibling draft's `n = i + 1; ... i = n;` form.** With
  `i++`/`i++; continue;` gcc emits `addiu $s4,$s2,1` early and `move $s2,$s4` at the end of the
  body; the level 1 table-walk form copies `i + 1` into a second variable and assigns it back,
  and copy propagation coalesces it into retail's `addiu $s2,$s2,1` in place
  (`func_L27_00473230`, which was 13 differences as `i++` and matched this way). The level 2
  recursion through `continue` is the variant this function needs in case 1.
- **A 178-way state switch is one table plus a state map.** Decode both level-27 and level-08
  jump tables and check `pairmap[l08_target[s]] == l27_target[s]` for every state (176 of 178
  here): only the set that leaves for `default` and the extra bodies differ. That is the
  worklist for a port, and it says exactly which bodies to transcribe from retail
  (`func_L27_004CA9C8`, `func_L27_004D7CD8`).

### Families and ports

- **Port the matched family root, using the unmatched blocks as the worklist.** The two giants
  are the level-27 variants of the level-8 roots `L08_004D6580` (`func_L27_004CA9C8`, 0.991
  identical) and `L08_004E36C0` (`func_L27_004D7CD8`). Align the two retail disassemblies on
  mnemonics with registers and numbers masked (an extension of the aligned-diff tooling in
  "Tooling for very large functions"), rename the level data and callees of the aligned sites,
  then transcribe only the blocks the alignment leaves unmatched (44 L27-only and 50 L08-only
  instructions for the first; 106/55 for the second). Both matched in three porting passes.
  Removing one L08-only group and adding two L27-only cases is not a rewrite.
- **An extra `s32` local used only by a new state still occupies its stack slot.** In
  `func_L27_004D7CD8` the level-27-only state needs one more `s32` than the level-8 body; declare
  it in the sibling's declaration order (`sp30..sp44`) and every following local moves 4 bytes,
  to retail's offsets. The eight remaining differences before the match were only
  `0x34/38/3C/40` against `0x38/3C/40/44`.
- **A store before the pointer computations orders two global loads.** Writing
  `d->f70 = 0;` before computing `o0`/`o4` makes the `D_L27_001DEE00` load precede the moby base
  load, as retail has it (`func_L27_003A1B30`).
- **One block-local index per state.** A single function-level `s32 i = d->fXX;` stays in `$a1`
  across the blocks; each state with its own block-scoped `i` gets `$v1`/`$a0`/`$a1` per block,
  which is retail's allocation (`func_L27_003A1B30`).

### Open problems (drafts in `nonmatching/levels/`)

- **Prologue allocation and scheduler ties:** `func_L27_00375CD0` is 194 diff of 437 words
  (down from 389). The prologue's 0.5f is scheduled above the callee-saves, GPR temporaries
  swap around `D_L27_001D673C` and `&D_001A4BE0`, three float constants take `$f1` instead of
  `$f0`, and the `v250` address plus the `move $s2` around the first dot call are one slot off.
  Its `divs_nops` row `2 1 2` is correct and is not the residual. The function needs `@ps2as`
  and `-mvu0-use-vf0-vf2` if a later form matches.

## Patterns from level 30 (Vid-comic unnamed, PAL)

Found while matching one function of `src/levels/30_vidcomic_unnamed/` (one function per
agent), after attempting all three unclaimed functions and escalating two near misses.
The other 41 local `INCLUDE_ASM` functions were reserved and were not attempted. Only
what is new compared with the sections above.

### Address expressions

- **Integer address arithmetic can change the base's scratch register, not just the
  `addu` operand order.** This is an allocation variant of "Which register comes first
  in `addu`" above. In `func_L30_003496D8`, compare the object's signed halfword against
  `*(s16 *)((*(s32 *)(p + 0x104) << 8) + (s32)D_001DF71C_sda + 0xAA)` rather than a
  pointer-based table expression. The integer form gives the loaded table base `$a0`
  and leaves the compared object in `$v1`; keeping the object's field on the left of
  `==` also gives retail's `beql $a1,$v1`. Together with a `void` return and the
  block-local float load before the byte store, the draft went from 26 differences
  to `MATCH`, confirmed by the complete level build. The existing file flags suffice.

### Open problems (drafts in `nonmatching/levels/`)

- **Independent VU0 stores and epilogue restores:** `func_L30_003427F8` is five
  differences of 98 words with the owning file's flags plus `-mvu0-use-vf0-vf2`
  (the file already uses `@ps2as`). Retail stores the quadword at `sp+0x40` before
  `sp+0x20`; the draft reverses them and restores `$s2`/`$ra` earlier. Tail statement,
  load and helper-order permutations did not move this scheduler tie. No `div.s`
  or `sqrt.s` is involved. The owning file's flags are unchanged.
- **High-address and reload register choice:** `func_L30_0037E5D0` is four differences
  of 437 words with `@ps2as` and `-mvu0-use-vf0-vf2`. A scalar declaration for
  `D_L30_001D673C` and reuse of the copied object's pointer reduced seven differences
  to four, applying the existing scalar/array and variable-reuse recipes. The high
  temporary at `0x0037EB6C/70` and the `out3` reload/store register at
  `0x0037EBC4/0x0037EBE8` still differ after three formulations with identical residual
  bytes. Its counted `divs_nops` row `2 1 2` is present and is not the residual.
  The owning file's flags are unchanged.
