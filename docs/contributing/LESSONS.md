# Matching lessons

The rules agents keep rediscovering, in one place. Read this once before the first function.
It does not replace [AGENTS.md](../../AGENTS.md) (the rules), [Matching patterns](../wiki/Matching-Patterns.md)
(the long catalogue, by level and date) or [docs/build/](../build/) (how the build works); it
is the short list of causes that closed real matches, ordered by what you see in the diff.

Maintenance: when a function closes (or stays open) for a reason that is not here, add one row to
the right table with the function and file. Keep entries to a line or two and link, don't copy.
The evidence for an entry lives in the commit message or in the draft's header under
`nonmatching/`.

## Before you write any C

1. **Look for a twin first.** Most matches in the last rounds were ports, not rewrites.
   - Another level's copy, or the frontbin/boot_elf copy, already matched: `tools/sister_twins.py`,
     `tools/twin_mask.py`, `tools/port_verify.py`.
   - The same engine routine in rac2 or rac4 (moby motion, gravity, explosions, particles, level
     setup, beams): read their matched C, find the counterpart by structure and call pattern, port
     it with rac3's constants and prototypes ([sister-twins.md](sister-twins.md)). Example:
     `func_L19_00302998` is rac2's `func_L01_00390A50`.
   - NTSC-U's C for the same function ([versions.md](../build/versions.md),
     `tools/port_from_us.py`). PAL has its own constants: the x1.2 rounding makes `0.060000002f`,
     not `0.06f`. This took `func_L01_0039FEB0` from 104 aligned diffs to 0.
2. **Start from the draft.** `nonmatching/levels/<func>.c` and `nonmatching/functional/` are the
   brief: the header lists what was tried, so do not repeat it.
3. **Check the real flags.** A diff that starts in the prologue, or has constants in the wrong
   place everywhere, is usually the file's flag line, not the C (see "Flags and file cuts").
4. **Verify the right way.** `tools/check.py` at every place of the function in
   `config/levels/functions.tsv` (all in parallel), plus the file's other C functions whenever you
   change a flag line or a shared declaration. Snippet mode drops the file's earlier `.extern`
   size hints: repeat each hint a block needs inside the block. A match that passes alone can
   still fail the full build (see "Declarations that break the file").
5. **Is it C at all?** Retail code with no prologue, `$at` as a working register, trapping
   `addi`, direct GIF/VIF DMA writes: hand-written, see "Hand-written assembly".

## Symptoms in the diff

### Calls, arguments, return values

| You see | Cause | C that fixes it | Example |
| --- | --- | --- | --- |
| Argument loads in the wrong order before a `jal`; `$a0`/`$a1` swapped | The expand order of the arguments is the load order, and both schedulers keep it when instructions tie. A prototype with the wrong parameter order is wrong. | Use the parameter order the matched callers use. When two orders are EABI-equivalent, only one matches: try them all (35 orders for one function). | `func_L19_00332948` (`func_L01_00451FE0` takes the order level 28's matched callers use); `func_L01_00448890` and `func_L01_0046B458` (zero int argument after the floats) |
| `cvt.d.s`, a float in the wrong register, wrong arguments | No prototype: `float` is promoted to `double` | Declare the callee with its float parameters (`extern f32 f(f32, f32);`), or cast the call | Matching-Patterns, "Floats" |
| Result moved into the wrong register, an extra `move`, a result that retail ignores is kept | Wrong return type. `void` vs `int` vs `u8 *` changes whether the value is live and how it is allocated | Declare the real return type. A callee used as `s32` in one function and `void` in the file: call it through a per-function alias with the other type | `func_L05_0035B3F0` (`func_0038CB00`, `func_0038CAD0` called through `_0035B3F0` aliases); `func_L01_00455550` (float functions were implicitly `int`) |
| Argument moves fill the wrong branch delay slot | The moves keep their expand order through both schedulers | Usually a prototype or the argument order, not a barrier. If five wordings give the same bytes, park it | `func_L05_00359C78` (19 left) |
| A result gets passed on through an extra temporary | Random-call results should go straight into the next call's arguments | Pass the call as the argument | `func_L01_0039FEB0` |

[return-types.md](../build/return-types.md) says how return types are set in the shared headers.

### Globals: `$gp` against `lui`/`addiu`

`-G8` makes gcc address any object of 8 bytes or less through `$gp` and anything bigger or
unsized through `%hi`/`%lo`. Retail did not always. The declaration decides, not the access.
Full rules: [globals.md](../build/globals.md).

| You see in retail | You get | Declaration that fixes it | Example |
| --- | --- | --- | --- |
| `lw $v0, -0x3e40($gp)` | `lui` + `lw` | A sized scalar: `extern s32 D_001D8A70;` | |
| `lui $v0, %hi(X)` + `lw %lo(X)($v0)` | `$gp` load | An unsized array read as `X[0]`: `extern s32 X[];`. Not `*(T *)0xADDR` and not a `#define` | `func_L01_0044F450` (loads the address as split `lui`/`addiu`, which `-mno-split-addresses` cannot produce) |
| `lui $at; sw` before the `jal`, not in its delay slot | The store was moved into the slot | Small data **at an offset**: gcc keeps `symbol+offset` unsplit but never fills a delay slot with it. Declare a run of values as one array and index it | `D_L09_001DBDCC[3]`, globals.md "Small data at an offset" |
| `$gp` where `lui` is produced | An object too big for small data | `__attribute__((section(".sdata")))` on the `extern`, with the real type. Never change a type's size to steer `-G` | `D_L01_001E001C` |
| `lui` where `$gp` is produced | The reverse | `section(".data")` on the extern | `D_00142725` |
| Adjacent `lui`/`addiu` rebuilt at every use, address not kept in a register | The address is a small object (assembler `la`), not gcc's split form | Declare it with its real small size (`extern u8 X[8];`) and add `.extern X, 16` | `D_001D5570[8]` and `D_001D5470[8]` in `func_L01_003F08C8` (30 to 14 rows) |
| `lbu $v0, sym+6` expanded as `lui` + load, `nop` slots around it | A small-symbol + offset address: gcc gives it length 8, so reorg never uses it as a filler, and the assembler expands it with `lui` once it has a size hint | `extern u8 D_001D5470_003B8E60[8]; __asm__(".extern D_001D5470_003B8E60, 16");` and read `[6]` | `func_L01_003B8E60` (21 to 8 rows) |
| A load that is `$gp` in one level and `lui` in another | One name for two different slots | Level data: `D_LNN_XXXXXXXX`, its own address per level. A `$gp` slot the multiplayer levels also read: `D_XXXXXXXX_sda` | `D_L01_001E0020` (`func_L01_002F88E0`) |
| Same constant read once through `$gp` and twice with `lui` | One global needed two spellings in one function | A per-function alias (`D_001D545C_003C0EA8`): 913 differences with the plain name | `func_L05_003C0EA8` |
| `.extern` hint needed by NTSC-U or another level's build but missing | Check.py's snippet mode drops hints, and the multiplayer trees take a function without the block that carried the hint | Repeat `__asm__(".extern X, N");` in the function's own block | `func_L01_00331230` (`D_L01_001DCF00, 4`) |

Pitfalls: an `.extern X, N` size hint only helps when its size matches an access that really
exists; a hint placed after the first access is too late (Ps2EeAs sees it early only if the
declaration comes first). Scalars declared as arrays, or the reverse, are the most common reason a
whole file needed `-mno-split-addresses`: declare the globals as the scalars they are first (the
file `L01_0044E130.c` dropped the flag that way).

### `div.s`, `sqrt.s` and the `mtc1` nop

| You see | Cause | Fix |
| --- | --- | --- |
| `jal; x; nop; nop; div.s` in retail, the function is otherwise exact | Retail pads most `div.s`/`sqrt.s` with 0-3 `nop`s, which neither gcc nor the assemblers keep. `tools/asm_filter.py` puts them back from `config/levels/divs_nops.txt` (frontbin: `config/frontbin/divs_nops.txt`). The function may only be missing its row | Add the row: `func_NAME c1 c2 ...`, one count per `div.s`/`sqrt.s` in order |
| `div.s` right after the `mtc1` that set its register, under `@ps2as` | Ps2EeAs adds its own hazard `nop` | The row's count is one less than retail's (`func_00381250`: 2 to 1) |
| `sqrt.s` printed as a raw `c1` word by the disassembler | Missed by older table generators | Check the row has one count per `sqrt.s` too |
| The function got 4 bytes longer per `nop` and everything after it shifted | A stale row | The row travels with the function: change it when the count changes |

Compute the counts with `tools/gen_divs_nops.counts()` (it reads retail's from the function's
`.s`). **Never run `tools/gen_divs_nops.py` with no arguments:** it rewrites
`config/frontbin/divs_nops.txt`. The row is only read when the function is compiled from C, so a
row can sit ahead of the match. A draft's header should say which row it needs.

### Conditional moves and compares

| You see | Cause | C that fixes it | Example |
| --- | --- | --- | --- |
| Retail `movn`/`movz` where you get a branch (or the reverse) | `x = c ? a : b` and `if/else` compile differently; so do `x = 0; if (c) x = 1;` and a selector local written as a comparison | Try both. A local written as `s32 s = p[0x1AE] == 0 ? 4 : 5;` gives `move` + `movn`; `x = 0; if (c) x = 1;` gives `movn`; a block-scoped `s32 one = 1;` gives `movz` | `func_L07_003B3798`; `func_L11_003A9E60` |
| `xori`/`sltu` where retail has a `movz` chain | With `int`, gcc folds `r = 1; if (x == -2) r = 0;` into `xor`/`sltu` | A `long` working variable keeps the `movz` chain | Matching-Patterns, batch 21 |
| `sltu` against `slt`, `srl` against `sra`, `andi` masks | Signedness of the variable | Use the signedness retail shows: `u8` vs `s32` flag, `u32` array for `sllv`/`and` bit tests (an `s32` array gives `srav`/`andi 1`) | `func_L09_00316710` (bit-mask tables) |
| `sltu` + `and` where you get `movz` | `ok &= f() != 0` makes gcc use `movz` | A temporary: `t = f() != 0; ok = ok & t;` | `func_003E3A80` |
| `nor`/`sltu` pair for `r = (x != -1)` | The comparison form | An early `return 1` in the branch | `func_L05_00360280` |
| `xori; li; move; movz` in retail but your registers roles are reversed | cse2 rewrites `b = a` after the insn that set `a` | Not found yet: needs a constant cse1 does not fold into `b = a`, and a `b = a` not right after the setter | `func_L01_003F08C8` (14 rows) |

### Branches, delay slots, early returns

| You see | Cause | C that fixes it | Example |
| --- | --- | --- | --- |
| `beql`/`bnel` with a store in the delay slot where you get `bnez` + `nop` | Retail flags as `a || b` / early exits; the annulled form comes from the shape of the test | `D[i].flag = bit_test \|\| call();` gives `bnel`/`beql` with `0` in the slot; an `if/else` gives `movz`. An early `return` and an `if/else` give different `beql`/`bnel` use | `func_L02_004722E0`; Matching-Patterns, "Early `return` vs `if/else`" |
| An `&&` chain evaluated into a register and then tested | gcc folds `s0 = a && b; if (s0)` into direct branches | Every spelling tried folds it. Leave it parked | `func_L09_00316710` |
| Retail has one shared tail, you have two | Cross-jumping merges only **identical** tails | Write both arms out with identical statements (the same helper, e.g. `vec_sub_ab` / `vec_add_ab` from `include/vu0.h`, in both). With `call(x, 1); return;` written out arm by arm, gcc merges them; one variable for the argument gives `movn` instead | `func_L05_003560C8` (shared vsub/sqc2 tail); `func_L05_003CA628`; `func_L02_004BDA00` |
| Retail loads a constant in each arm (`li 6` twice), you share it | A variable kept the constant alive | Compute it in both arms; cross-jumping then merges the rest, leaving the constant in each arm as retail has it | `func_L01_0039A320` (frame count `(D * 5 + 2) / 6`) |
| Found-exit blocks (`p94 = e; break;`) land after loop 1, retail has them after the early `return 0` | loop.c puts each exit block at the nearest BARRIER before its jump target, at the target's loop depth | Write the exits as `goto`s to labelled blocks placed after the early return; the shape of the loop (`while` vs `for (;;)` with a leading test) decides whether cse follows the first test into arm 2 | `func_L04_003D0C40` (89 to 24 rows, header has the mechanism) |
| A condition is reloaded in an `else` branch where you keep it in a register | `n` assigned in the test makes gcc keep the first load for the whole chain (264 diffs) | Read the field in place in each test (89) | `func_L04_003D0C40` |

### Loops and induction variables

| You see | Cause | C that fixes it | Example |
| --- | --- | --- | --- |
| A count-down pointer loop (`bgez`) where you get an up-counting `slti` loop | Indexed vs pointer-walk loop shapes compile differently | `fl = p->f1C; for (i = 0; i < 4; i++) { if (*fl) n++; fl++; }` | `func_L09_00316710` (678 to 636 raw) |
| The loop pointer's `move` lands in the delay slot of the wrong branch, or in the wrong block | loop.c makes a walked pointer a giv whose init goes to the preheader after the copied exit test | Index with `p[i]` instead of walking a pointer | `func_L01_003B8E60` (8 to 6 rows) |
| A loop counter sits in the wrong place after the hoisted constants | Where the counter starts | A variable that starts as 0 at the top of the function (`start`) changes the register's place | `func_L01_003DF1B0` |
| Two giv increments in the wrong order (destination before source) | LUID of the sched tie = loop.c creation order = reverse giv discovery order; the store's DEST_ADDR giv is found after the load's | Nothing found: 96+ forms tried. Park it (4 raw left) | `func_L01_003B8E60` |
| A pointer hoisted out of the loop, retail reloads it, or the reverse | Store through a typed struct is `MEM_IN_STRUCT_P`, so loop.c can hoist the global pointer's load out | Store through a typed struct field, as the header describes. A base that must not hoist: take the row pointer after the last call in the loop | `func_L09_00316710`; the homing-missile update (`Row (base + index)->field`) |
| A local declared inside the loop body changes the preheader | The inner loop.c hoists a block-scope pointer to its own preheader and keeps it as a separate pseudo | Declare `R *vp = &V[2];` inside the loop body (not at the block top, not just before the loop) | `func_L01_003B8E60` |
| `for` header against separate counters | Retail has one counter per loop, not a shared one | Separate loop counters; a shared one changes allocation | `func_L01_0039FEB0` |

### Register allocation and spill order (gcse, global.c)

The global allocator orders pseudos by priority (refs / live length) and breaks ties by creation
order. Both are functions of the source. `tools/regalloc.py` prints each pseudo's refs, live
length, priority and register, in allocation order (`-dlg`). `tools/sched_explain.py` explains one
scheduler decision. Use them instead of guessing: a hand rewrite is blind.

| You see | Cause | C that fixes it | Example |
| --- | --- | --- | --- |
| A value in a saved register in retail (`lw $s1, 0x34($sp)`), you rematerialise it | gcse PRE inserts the expression before the test, spills it, and the else branch reads it through a copy | Reassign the pointer as the first statement under the `if` (`p = s + 0xB0;`) so it joins the PRE register; one pseudo with `p` outranks `s` for `$s1`. A separate variable gives 86 diffs | `func_L04_0035BC10` (84 to 0) |
| `&dest`/`&vel` kept in a saved register in retail | gcse keeps an address expression live across a call | A shared block: several tests jump to one lost-target block so the GCSE'd `&vel` spills as retail | the homing-missile update, `func_L05_003CA628` (declare `dest` before `old`) |
| One register for an address, retail copies it in the loop's preheader | `pos = o + 0x10` used only for one copy | Use the same expression for the later calls so gcse keeps one register (`o + 0x10` passed to the distance calls) | `func_L05_0035B3F0` (519 to 1) |
| A pointer (`s`, `p`) swap in `$s0`/`$s1` | Which pseudo ranks first | Reuse one variable for both roles, or the reverse. Check priorities with `tools/regalloc.py` before editing | `func_L04_0035BC10` |
| Which saved register holds which hoisted high half (`lui`) | The last pseudos allocated, in the order gcse created them = order of expressions in its hash table, a function of the symbol **names** | Not controllable by declaration order (24 orders tried). Park it | `func_L09_00316710` (about 50 rows) |
| A constant kept in `$s0` for the whole function (or rematerialised in loop tests) | The file was built without gcse (`li $17,16` held for a loop bound; constants rematerialised in tests) | A file cut with `-fno-gcse` on its own `text_parts.txt` line, the way three level files already are, then recheck the neighbours | `func_L01_003E25B8` (`-fno-gcse`); `func_L01_00369E28` reaches 27 rows that way |
| Copies of the same constant not shared, `$f20` not reused | cse flushes its hash table every 1000 insns, so the exact RTL count of the source decides which copies survive | Write statements the way the original would; duplicated statements that gcc later merges (cross-jump) raise the RTL count at gcse and can fix spill order | `func_L39_006BE7E0` (header) |
| `x = 20.0` for a call and `1.0` later, retail reuses `$f20` | cse keeps the pseudo for the argument and combine folds `20.0` into the move because the variable dies at the call | Not reachable by variable use alone: park it | `func_L05_0032A4D8` |
| A frame 0x10 bigger than retail | Locals not in retail's slot order, or temporaries that share no slot | See "Stack layout" | `func_L01_0038BB10` (0x120 vs 0x110) |

How to diagnose: compile the function with the file's flags and ask cc1 for dumps (`-da`, or
`-dG` for gcse, `-dj` jump, `-ds` cse, `-dL` loop, `-dg`/`-dlg` global). The notes in
`nonmatching/levels/func_L04_003D0C40.c`, `func_L01_003B8E60.c` and `func_L09_00316710.c` show what
each pass decided and the C that moved it. `tools/flags_probe.py` tests a flag line.

### Stack layout

| You see | Cause | C that fixes it | Example |
| --- | --- | --- | --- |
| Locals at the wrong frame offsets | Slots are assigned in declaration order | Declare the locals in retail's slot order (read the offsets from the asm) | `func_L01_0038BB10`; `func_L39_006BE7E0` (every item its own local, in creation order, matches retail offsets 0, 0x50, 0xA0, ...) |
| Two locals that never live together share one slot in retail | Block-scope locals reuse slots when their scopes are disjoint | Put each in its own block `{ ... }`: three block-scoped spark temporaries per emitter (93 to 22 rows) | a level 1 near-miss draft that calls `func_L01_00448890` |
| Two differently typed locals at one offset | Retail overlays them | A `union { Colors c; vu0_v4 old; } temporary;` | `func_L01_002F78B0` (`temporary`) |
| A struct reused as scratch space | Retail passes the hit record to a helper as storage | Reuse the existing local as scratch | `func_L01_0038BB10` |
| Spilled pointer at a different slot after you add a helper | A static inline helper that took `&v` forced the variable to memory | Write the shared sequence out in place instead of passing `&v90`/`&vA0` | `func_L05_0035B3F0` |
| A `u8` local becomes `sll`/`sra` | A `u8` local is promoted to SImode | Not fixable that way (280 diffs): retail has `andi` | `func_L03_003C2C18` |

### Static inline helpers and hoisting

A `static __inline__` helper in the file often reproduces retail's hoisting and spills (a
wrapper around `func_0038CF68` for gcse PRE of `&dest` in `func_L05_003CA628`; a local
quadword-copy helper in `func_L01_00348A98`, whose parameter copy is retail's `move`). It is a
tool, not a rule: sometimes the same code written in place is what matches (`func_L05_0035B3F0`),
and a helper taking addresses of locals spills them. Try both.

### VU0

| You see | Cause | Fix |
| --- | --- | --- |
| `vadd`/`lqc2`/`sqc2` where the compiler emits scalar code | It cannot emit COP2 | Use the helpers in `include/vu0.h` (`vec_add_ab`, `vec_sub_ab`, `vec_copy`, `qzero`, `mat_scale`, ...), or one asm block per VU0 sequence with real operands and clobbers (AGENTS.md lists the allowed cases) |
| The `vf` register roles or `vf0`/`vf2` differ everywhere, or the shared `sqc2` + call tail will not cross-jump | The file needs `-mvu0-use-vf0-vf2`; the helper's j-form lets the shared tail cross-jump as in retail | Add the flag on the file's own `text_parts.txt` line (cut the file) and recheck its other functions. Examples: `func_L39_00552920`, `func_L01_003241A0` |
| A VU0 value live across a branch in your draft | A "j" variable shared between separate asm blocks | Keep every VU0 value in real operands; use the helper in both arms |
| The `lqc2` of a copy is hoisted into the `vadd` stall, spill | sched1 hoists it when the copy comes before the add's `sqc2` | The copy writes into the add's second operand (anti-dependence keeps it after the `vadd`); write the `sub` back into its `p` operand; `t` and `d` as TImode memory operands (`*(vu0_q *)&t`) not BLKmode | `func_L05_0035AFB8` (jform) |
| `vec_copy` for `lqc2` + `sqc2` copies | The original's macro | Use it at every site of the file or none |

## Flags and file cuts

A file has exactly one flag line in `config/*/text_parts.txt`; there are no per-function flags
([build-fidelity.md](../build/build-fidelity.md)). When one function needs other flags, **cut the
file**: the function gets its own `.c` and its own line, and the following functions go in a tail
file back on the old line. The neighbours must be rechecked (every function of every touched
file at every place).

| Flag | When | Example |
| --- | --- | --- |
| `@ps2as` | Constants as `lui/ori/mtc1`, retail's `li.s` expansion; needed by most of the level code | `func_L01_0044AF78` (cut into its own `@ps2as` file) |
| `-mvu0-use-vf0-vf2` | VU0 helper code (see VU0) | `func_L39_00552920` |
| `-fno-gcse` | Constants held in saved registers | `func_L01_003E25B8` |
| `-fno-strict-aliasing` | Library code from open source (`-O0` files with `$fp` frames: `@ee29 @eeas -O0 -G8 -fno-strict-aliasing`, SSLeay/OpenSSL RC2) | the level 39 RC2 file cut in k8 batch 1 |
| `-fno-strength-reduce` | Loops without induction pointers | `func_L39_00508690` (20 rows) |
| `-mno-split-addresses` | Retail loads addresses with `lui $at` unsplit | `func_L39_006BE7E0` (needs it plus `@ps2as`) |
| `-fopt-stack` | Present on most level lines; a function that saves `$s` with `sq` has none and gets its own file plus `sq_ra_funcs.txt` | `func_L01_0044A030` |

Cut files must start 8-aligned: Ps2EeAs pads a slice's text to 8 bytes, and the GNU-as slice of an
`INCLUDE_ASM` before it can shift every later function by 4 or 8 bytes (the `382410.c` fix:
`func_003824D0` alone got an `@ps2as` file). A near-miss that needs a flag no file line carries
goes in the draft header with the flag line it wants.

Match flags to the code that was really compiled: look for `-O0` library code (`$fp` frames),
SSLeay/OpenSSL (read the open source for the spelling), and BSD malloc.

## Declarations that break the file

A function that checks alone can fail the full build, or NTSC-U's carry, which compiles the
**whole file** or a block alone. Seen again and again:

- **Conflicting types.** A later block redeclares a name an earlier block of the same file
  declares with another type (`D_L05_001DFC80`, nine names in `func_L05_0035B3F0`; prototypes in
  `L06_00351930.c`). Use the file's own prototypes, or a per-function alias
  (`name_<FUNC>`, [levels.md](../build/levels.md)) whose type differs.
- **Implicit declaration.** The block compiles alone with no declaration in front of it (NTSC-U
  carry): give the call an alias, or declare the callee at file scope in the file
  (`func_L01_005003D0` before `func_L01_00505380`).
- **A name with two values.** `D_001E0020` read as `_sda` in one level and data elsewhere:
  `func_L01_002F88E0` became level data `D_L01_001E0020`.
- **A function only matched compiled after its neighbour's C.** `func_L01_00455550` matched only
  after `func_L01_00454728`'s prototypes: alone in its slice every level differed from `+0xF4`.
  Put the prototypes in the function's own block.
- **One read-only data place.** Jump tables of C functions join the file's `.rodata`; if retail keeps the
  tables of assembly functions between them, the file has no single place for its `.rodata`
  (`func_L01_002F78B0`: its table and `func_L01_002FC910`'s, with `func_L01_002FA1F8` and `func_L01_002FAAA0` in between).
- **A jump table's unreferenced tail.** Some tables carry words no code refers to; deleting the
  `INCLUDE_RODATA` line drops them. A `const u32 D_...[42]` after the function checks MATCH but
  is a variable definition and `pr_check.py` rejects it: leave those `INCLUDE_ASM`.
- **A declared name the carry reads wrongly.** An asm-label declaration (`extern T f(...)
  __asm__("g")`) was taken for its name by `split_text.py --refresh` and copied into later files.

## Per-level and per-place problems

- **Catalogue false folds.** `tools/level_catalogue.py` counts two places as one function when
  they are equal apart from linking. A field offset on a register reloaded later
  (`lw $v1, 0x68($a0); sw $v0, 0x2D8($v1)`) can hide a real difference between levels. Such places
  are listed in `config/levels/split_places.tsv` (one line per group: row, places, offsets that
  differ), and `func_L01_003A6BB0` has several (`+64:0x2D8`, `0x2E0`, `0x45C`, ...). When a function
  checks at 33 of 34 places, read the failing place's offsets before rewriting anything.
- **Multiplayer twins that differ.** Levels 39-53 have their own rows for a few functions whose
  story twin has other bytes (struct 0x30 smaller, `0x45E0` against `0x4610`): they are separate
  functions. Before adding a row, check that the C itself is right: `func_L39_00548648` and
  `func_L39_0058ACE0` looked like such twins (level 39 right, 40-52 off) but were one missing
  `divs_nops.txt` row and one `$gp`-small alias used for stores retail makes with `lui`.
- **Different callees by level.** One level's copy calls another twin: call through an alias
  (`func_L01_0038B988_0035BC10`: level 06 calls `0x36C318`, the catalogue says `0x38F4A8`;
  the plain name gave 1 diff there).
- **Two `$gp` values.** Multiplayer levels have `$gp` 0x247FC0 (PAL 39-53): a core name read
  through `$gp` there is refused; use `D_XXXXXXXX_sda` ([globals.md](../build/globals.md)).
- **A level function that cannot be linked.** `func_L39_005001E8`, `func_L39_004BA208`: their
  read-only data and the file's are apart in retail. They were reverted to `INCLUDE_ASM` after the
  full build. (`func_L39_004D7770`, reverted with them for a jump table loaded with `lui`, links
  as it was written: level 39's full build takes it.)

## Hand-written assembly (`ASM_FUNC`)

Mark a function `ASM_FUNC` only on evidence, never because it resisted matching:

- no prologue, or it saves `$ra`, `$fp`, `$sp`, `$s0`-`$s7` into the scratchpad by hand;
- `$at` used as a working register; trapping `addi` that gcc never emits (215 of them in
  `func_L39_005B25C8`);
- direct GIF/VIF1 DMA register writes; COP2 code in sequences no helper covers;
- it reads registers it never sets, or has no `jr $ra`.

Examples marked so: `func_L39_005B25C8`, `func_L39_005ACB68`, `func_L01_00440AD8`. A run of
functions that looks like compiled code but uses `sq`-saved `$ra` is not hand-written: it is
`sq_ra_funcs.txt`. Stop on a function when three different wordings compile to the same wrong
bytes or after about ten compiles without getting closer: record it in the draft header.

## Cross-game twins (rac2, rac4)

- rac2's and rac4's matched C is the first place to look for engine routines. Map their names to
  rac3's by call pattern and constants; rac3's flags differ (`@ps2as`, `-mvu0-use-vf0-vf2`).
- A construct that rac2 uses only to steer codegen is a precedent you may cite, never a lever you
  may invent: see the honesty rules below.
- Opcode-level near-twin search (`opnear.py` in the swarm's scratch) finds ports that exact-twin
  search misses; `exact_twins.py` + `port.py` do the renaming; `port_fe.py` maps relocations.
- When a twin is 95% or more equal but not exact, the diff is the constants and offsets: PAL has
  its own (x1.2 rounding, other struct layouts).

## The honesty rules

[AGENTS.md](../../AGENTS.md) is the authority; these are the ways the rules most often bite.

1. **No steering.** No variables, dead stores, dummy reads or barriers whose only job is to move
   registers or scheduling. A variable is fine when the original plausibly had it (a loop
   counter, a row pointer, a scoped temporary that makes the stack layout right).
2. **Codegen-only constructs** (`do { } while (0)`, statement expressions, comma conditions):
   only when rac2's matched C uses the same construct for the same effect, and the function's
   comment cites that rac2 file. Precedent: rac2 `src/core/00124568.c` `cd_shutdown` wraps a store
   in `do { } while (0)` as a scheduler barrier. No precedent, not a match.
3. **Uninitialised reads** where retail reads an unset local: only with a rac2 precedent for the
   same pattern, cited in a comment. Precedent: rac2 `src/pal/game/002C19C0-flags.c`
   `part_update_fading_split_spark_pal` scales an unset stack struct in place.
4. **No permuter artifacts.** Reject duplicated calls in both branches, dead stores,
   uninitialised reads and casts that no human would write. Accept only plausible C.
5. **No inline asm** except `.extern` hints, the helpers in `include/vu0.h` and `include/cpu.h`,
   VU0/COP2 sequences, the assert trap and the DNAS stubs. No `volatile` as a barrier. No
   `#define` aliases. No hardcoded addresses (except hardware registers and the scratchpad).
6. **No per-function flags.** Cut the file (see Flags and file cuts).
7. **A match is `MATCH` from `tools/check.py` at every place**, then the full build once, at the
   end. Report exactly what you ran.

## What does not work

| Idea | Why not | Do instead |
| --- | --- | --- |
| The permuter on `vu0.h` code | The helpers and VU0 asm are opaque to it; candidates mostly break the function or add the artifacts above. It also left orphaned workers on every machine and found nothing usable in the last rounds. The lead's rule since 2026-11-27: do not run the permuter (stock or `tools/permuter_engine.py`) | Work by hand with `check.py`, `regalloc.py`, `sched_explain.py` |
| Chasing a register-only diff past about 90 minutes | A last-register difference is usually one allocation order decided by gcse hash-table order, a LUID tie, or the symbol names; `func_L01_00304C48`, `func_L01_003F08C8`, `func_L01_003B8E60`, `func_L09_00316710` each spent hours there | Time-box at about 90 minutes without progress, write what differs and what was tried in the draft header, park it |
| Declaration order of symbols to change gcse order | The order follows the names' hash table (24 orders tried) | Different C structure, or park |
| `goto`s everywhere | Sometimes closes found-exit placement (`func_L04_003D0C40`) but only where retail's block layout shows it | Use the plain loop shape first |
| A `u8` local for a flag | Promoted to SImode: 280 diffs | `s32` or a typed field |
| A static inline helper that takes `&local` | Forces the local to memory | Write the sequence in place |
| `-O3`, `-Os`, `-G0`, other global flags | Do not match (`-O3` equals `-O2`) | The file's line plus `@ps2as` |
| Expecting the US function's C to check on PAL | Constants (x1.2), offsets and layouts differ | Port, then fix by the diff |
| Running `gen_divs_nops.py` bare | Rewrites `config/frontbin/divs_nops.txt` | `gen_divs_nops.counts()` for one function |

## Order of work, in one paragraph

Twin or draft first; flags and prototypes from matched callers next (these two close most of a
diff at once); then globals and sizes (`$gp` vs `lui`, `.extern` hints); then `divs_nops` rows;
only then statement order, loop shape, stack layout and allocation, with `regalloc.py` instead of
guessing. Time-box, document the best draft in its header, and keep the function's row in
`nonmatching/README.md` current.
