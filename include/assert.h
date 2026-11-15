#ifndef ASSERT_H
#define ASSERT_H

/* The game's assert, as retail compiled it: a test that executes `break 1` when it fails. Only this
 * may emit a trap in matched C (AGENTS.md, "Matching rules").
 *
 * The evidence (2026-11-14; every function of every program read from the retail ELFs, PAL and
 * NTSC-U: 18,831 functions, 52 of them with a `break`):
 * - all but one are the compiler's own divide-by-zero trap (`break 7` in the delay slot after a
 *   `div`), hand-written assembly (func_003A9C40 and two kernel stubs) or data;
 * - func_L39_0067BCA8 is the only compiled function with another: it opens with
 *   `if (!(a->type == 6 || a->type == 7))` around `break 1` and a `nop`, both skipped by the `bnez`;
 * - neither compiler can emit `break 1` from C: `__builtin_trap` is "not supported by this target"
 *   in SN ee-gcc 2.95.3 and in ee-gcc 2.9-ee-991111, and a division gives only `break 7`;
 * - the `do { } while (0)` is part of what retail shows: the `nop` after the trap is the alignment
 *   of that loop's end label (no assembler adds one after `break`), and without the loop the
 *   function's $s0/$s1 allocation differs from retail's. With this macro the function matches
 *   under the default assembler, ps2as and newas.
 *
 * Use it only where retail's compiled code has `break 1` at that place. */
#define ASSERT(c) do { if (!(c)) __asm__ __volatile__("break 1"); } while (0)

#endif
