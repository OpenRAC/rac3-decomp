# Level 39's protected DNAS blocks

Level 39 (the multiplayer menu) links Sony's DNAS client library, the code that authenticates the
disc with Sony's servers before going online. 112 runs of that library's code are stored
**encrypted** in the level's `.text`. Each run (a *block*) sits inside a function, between a stub
that decrypts it when the function is entered and, for 94 of them, one that encrypts it again
before the function returns. 97 functions of the catalogue hold a block: 58,100 bytes, of
which 23,944 are encrypted.

These functions were C. They are matched as C, with two macros around each block
(`include/dnas.h`) and a build step that does to the compiled object what Sony's tool did to
its objects (`tools/dnas.py`). This page says what is in the program, what the build does, and
how to write such a function.

Everything here was measured from the two retail level-39 programs (2026-11-14). No Sony
source, header or sample was used: the cipher was read from the level's own routines, and the
macros' text is ours.

## What is in the program

Per block, in address order:

| Words | What |
| --- | --- |
| `la $v1, record; lw $v0, 0($v1); bnez $v0, skip; la $a0, block; lw ...; jal driver; lw ...` | the first stub: decrypt the block unless the record's flag says it is decrypted |
| `b +0xC; nop` | jump over the next eleven words, to the block |
| 6 words | filler: random words that decode as instructions; nothing reads them |
| 5 words | record 1: `flag (0), k2, k3, k1, 0` |
| `len` bytes | **the block**, encrypted |
| `b +0xB; nop` | jump over the next ten words |
| 6 words | filler |
| 4 words | record 2: `k2e, k3e, k1e, 0` |
| `la $v0, record2; la $a0, block end; lw ...; jal driver; lw ...` | the second stub: encrypt the block again (94 blocks; the allocator's 18 have none) |

The driver is `func_L39_004BD350` in the first library (63 blocks) and `func_L39_004F7890` in the
second (49): `driver(block, k1, k2, k3)`.

- `len = k1 ^ k2`; `k3 & 1` is the direction (0 decrypt `[block, block + len)`, 1 encrypt
  `[block - len, block)`); `k3 >> 1` is a key id.
- The key id names an entry of a key table in `.text` (one per library): a list of offsets of
  words the cipher **leaves alone**. They are exactly the words a linker relocates (`jal`,
  `lui`, `%lo` users): Sony's tool encrypted object files before linking, and a relocated word
  that had been encrypted would be garbage after it. A block with no relocated word has key 0.
- The schedule comes from `k2`: `(k2 >> 28) & 7` steps (5 when that is 0), step `i` applying
  transform `(k2 >> 4i) & 7` to every word not left alone. There are eight transforms of one
  32-bit word, built from two XOR constants, two rotations and one byte permutation
  (`tools/dnas.py`, `E` and `D`).
- Encrypting and decrypting both run their steps first to last, so record 2 holds record 1's
  schedule reversed: `k2e` is `k2` with its low `steps` nibbles in reverse order.

Checked on all 112 blocks of both discs (`tools/dnas_blocks.py --check` repeats it on your disc):
decrypting a block and encrypting it again gives the stored words, and both records are what
`tools/dnas.py` computes from `k2`, `k3` and the length.

## What a build cannot compute: the tables

Fifteen words per block were drawn at random when Sony's tool ran: **`k2`**, **`k3`** and the
**twelve filler words**. They are not functions of the code: the first library was built once
per region, and 60 of its 63 blocks have identical plaintext on the two discs and different
`k2`, key ids and filler. (The second library is the same object code on both discs, words
included.) So each version has a table of them:

| Version | Table |
| --- | --- |
| PAL | `config/levels/dnas_blocks.tsv` |
| NTSC-U | `config/us/levels/dnas_blocks.tsv` |

One line per block, tab-separated:

    function  block  offset  length  k2  k3  six filler words  six filler words

- `function`: the catalogue name of the function the block is in, **on that disc**
  (`config/levels/functions.tsv`, `config/us/levels/functions.tsv`), as
  `config/us/levels/boundaries.tsv` names NTSC-U's rows;
- `block`: its number in the function, in address order, from 0;
- `offset`, `length`: where the block starts in the function and how long it is, in bytes
  (retail's layout; the build does not need them, `check.py` uses them to say when your block
  is somewhere else);
- `k2`, `k3`, the six filler words before record 1 and the six before record 2, in hexadecimal.

Everything else in the stubs follows: `k1 = k2 ^ len`, `k2e`, `k3e = k3 | 1`,
`k1e = k2e ^ len`, and the flag and pad words are 0.

**These two tables are the one exception to "never commit game data"** (the lead maintainer's
ruling, 2026-11-14): 1,680 words per disc that no source can produce. Nothing else from a disc
is committed: not the plaintext, not the key tables (they are plain data in `.text` and stay
assembly), not the ciphertext.

    python3 tools/dnas_blocks.py --write                 # the PAL table, from baserom/levels/
    python3 tools/dnas_blocks.py --version us --write    # NTSC-U's, from baserom/us/levels/
    python3 tools/dnas_blocks.py [--version us] --check  # the committed table is your disc's
    python3 tools/dnas_blocks.py [--version us] --list   # every block: function, number, place, length

`--write` and `--check` first check every block of the disc as above and stop on any that is
not as `tools/dnas.py` computes it, or that crosses a function boundary of the catalogue.
**Write both tables again whenever the catalogue's rows for level 39 change**
(`tools/levels.py catalogue` after a `boundaries.tsv` edit): the lines are keyed by catalogue
name, so a row that is cut or renamed moves its blocks to another key.
`tests/test_dnas.py` checks, with no disc, that both tables parse, are as `--write` writes them
and describe the same 112 blocks.

## The build step

`tools/dnas.py`, `protect_object()`, on an assembled object, before anything links it:

1. it finds every block from its stub and its two records (`b +0xC; nop`, a record whose
   `k1 ^ k2` leads to `b +0xB; nop` and a second record that agrees), and names it from the
   label the macros give it, `dnas_blk_<function>_<n>`;
2. it takes that block's line from the version's table and writes the twelve filler words and
   both records;
3. it encrypts every word of the block that carries no relocation, with `k2e`: what the
   driver's encrypt direction does at run time.

A block the assembler emitted from an `INCLUDE_ASM` function has no label and is retail's
stored words already: it is left alone. The step stops the build when a block made by the
macros has no line in the table, when a label has no whole block (a `DNAS_BEGIN` without its
`DNAS_END`, or the compiler moved code out of the block), or when `DNAS_BEGIN` names another
function than the one it is in.

Where it runs:

| Build | Where |
| --- | --- |
| a level (`tools/build_levels.py`, `tools/build.py --target level_39`) | `tools/build_text.py`, right after assembling a file, whichever assembler its line names (`@newas`, `@eeas`). `tools/level_symbols.py` then lays the protected object over retail's `.text` as it does any object: the words without relocations must be retail's stored words |
| one function (`tools/check.py`, `tools/try_in_context.py`) | on the object just compiled, before the diff: `MATCH` is against retail's stored bytes |
| NTSC-U (`tools/c_objects.py`, `tools/asm_build.py --version us --c`) | through `check.py --version us`, which takes NTSC-U's table; the function's line is under its twin's NTSC-U name (`config/us/map.tsv`). The object `c_objects.py` keeps is the protected one |

It is the same kind of step as `tools/asm_filter.py` ([build-fidelity.md](build-fidelity.md),
rule 3): it changes what the compiler emitted only in the way a tool of the original build
did, and the result is still judged by the full build's `MATCH`.

**One source for both discs.** The C names a block and never holds its words, so the first
library's functions are one source for PAL and NTSC-U like any shared code. Their stored bytes
differ between the discs, which the catalogue's identity cannot see through, so
`tools/version_map.py` pairs a protected function with the NTSC-U function in its place that
has the same blocks (same offsets and lengths, same size) and makes it a twin (`match`) when
the shared C checks MATCH there. A source file with `DNAS_BEGIN` hashes together with both
tables in `config/us/map.tsv`, so writing a table again is a change `tools/version_map.py
--check` asks to carry, like a change to the C.

## Why the stub is C plus two address loads

`include/dnas.h` has the evidence in full. In short: every block decrypts to ordinary ee-gcc
2.96 `-O2 -G0` output and the function around it is one frame; the stub always sits at a
statement boundary with nothing live in a caller-saved register across it, as around a call;
the compiler's own instructions are scheduled between the stub's argument loads in several
functions, so the flag test, the loads and the call were compiled; but the two address loads
are always an adjacent `lui`/`addiu` (an assembler `la`) where the compiler's own are split
and scheduled apart, and no compiler emits a `b` over data. So the macros are C for the test
and the call, and asm only for the two `la` and for the `b`, filler and record. This is the
fifth allowed kind of asm in `AGENTS.md` ("Matching rules"): in that one header, for these
blocks only.

## Writing a protected function

1. **Read it decrypted.**

       python3 tools/dnas_blocks.py --show func_L39_004B4620

   prints the function's words with its blocks decrypted and marked: each stub, the filler and
   records, and `block N` on the words the C between the macros must compile to (`relocated`
   on the ones stored as they are). Its `.s` under `asm/` shows the ciphertext, which decodes
   as nonsense (MMI, VU0, `syscall`): ignore it.

2. **Write the C** in the function's file. The file's prelude includes the header and declares
   its library's driver once:

       #include "common.h"
       #include "dnas.h"

       /* the first library's driver: driver(block, k1, k2, k3) (include/dnas.h) */
       extern void func_L39_004BD350(s32, s32, s32, u32);

   and the function puts the macros where retail has the stubs:

       /* localdecomp:start func_L39_004B4620 */
       extern u8 D_L39_00464634;

       s32 func_L39_004B4620(u8 *a0) {
           DNAS_BEGIN(func_L39_004B4620, 0, func_L39_004BD350);
           D_L39_00464634 = *a0;
           DNAS_END(func_L39_004B4620, 0, func_L39_004BD350);
           return 1;
       }
       /* localdecomp:end func_L39_004B4620 */

   - The first argument is the function's own name, the second the block's number
     (`--show` prints both), the third the driver the stub calls (`jal` in the stub:
     `func_L39_004BD350` or `func_L39_004F7890`).
   - What retail does before the first stub goes before `DNAS_BEGIN` (a local initialised in
     the prologue, `s32 ret = -1;`), what it does after the second call goes after `DNAS_END`
     (`return ret;`).
   - A block with no second call (the allocator's, `--show` prints no `jal` after record 2)
     ends with `DNAS_END_ONCE(function, n);`.

3. **Check it** on both discs, as any level function:

       python3 tools/check.py FILE.c func_L39_004B4620
       python3 tools/check.py --version us FILE.c func_L39_004B4620

   `MATCH` means the compiled function, protected with that disc's words, equals retail's
   stored bytes. When it does not match, the listing shows both sides with their blocks
   decrypted (`**` marks a word whose stored form differs), and a `note:` says when your block
   has another length or place than retail's: fix the code before the block first, then the
   block.

4. The file's flags are the library's, `@ee296 ... -O2 -G0` with the assembler its line names.
   A protected function in a file with other flags (`@ee29`) belongs to a file of its own that
   starts at it, like any code built with other flags ([build-fidelity.md](build-fidelity.md),
   rule 1).

5. Then the full build of level 39, as for any match: the function counts when it says `MATCH`.

## What is not covered yet

- Text and tables inside a block (30 + 2 blocks: the allocator's messages, the HTTP strings, DER
  data), each behind its own `b` and read through a `la`: the C must not have data of its own
  ([levels.md](levels.md)), so these need a macro of their own.
- The one first stub with a compiler instruction between its `jal` and its `b`
  (`func_L39_004B6108`'s second block at 0x4B61E8).
- The block of length 0 (`func_L39_004D9508`): the macros compile to it, no function with it
  is matched yet.
