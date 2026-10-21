/* Near miss of func_003B7F80 with its file's own flags: tools/check.py reports 6 diff
   (the US draft it started from: 19).
   What differs: retail is the split-address form (all five %hi's first, then the %lo's, the
   last %lo in the jal delay slot); under this file's -mno-split-addresses gcc keeps every
   symbol's %hi/%lo pair in one parallel, so the faithful symbol form (the same call shape as
   the matched twin func_003B4FD0 in the split-mode file 3B3050.c) can never separate the pairs
   and leaves 19 diffs; passing the addresses as literal constants does give the split form
   under -mno-split-addresses, but gcc then builds each low half with "ori" (mips_olo) instead
   of "addiu" (mips_lo) and puts the $gp-relative first argument...
*/

/* func_003B7F80 (frontbin, PAL 0x003B7F80, 0x58 bytes)
 *
 * Retail shape (work/target.s):
 *   lui $a1..$t1, %hi(f1..f5)      <- the five %hi halves first
 *   addiu $a1, $a1, %lo(f1) ...    <- then the %lo halves
 *   addiu $a0, $gp, -0x2728        <- &D_001DA188
 *   jal func_003E6FA0
 *   addiu $t1, $t1, %lo(f5)        <- last %lo in the call's delay slot
 *
 * That is the split-address (default) form: each address is two independent
 * instructions, so the scheduler floats all five %hi's up and drops the last
 * %lo into the jal delay slot.  With this file's -mno-split-addresses gcc
 * keeps every %hi/%lo pair in one parallel, so the pairs can never be
 * separated and the delay slot stays a nop.
 *
 * Passing the addresses as literal constants does give the split form under
 * -mno-split-addresses (gcc splits a constant into hi/lo), but gcc then
 * builds the low half with "ori" (mips_olo) instead of "addiu" (mips_lo).
 * This is the closest plain-C form: only the five low halves and the
 * position of the $gp-relative first argument still differ from retail.
 *
 * The faithful form (symbol names, as in the twin function func_003B4FD0 of
 * the split-mode file 3B3050.c, which matches retail exactly) is kept below.
 */
/* localdecomp:start func_003B7F80 */
extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA1A0;
extern s32 D_001DA188[2];
s32 func_003B7F80(void) {
    if (D_001DA1A0 == 0) {
        func_003E6FA0(D_001DA188, (s32)0x3B77A0, (s32)0x3B7E38, (s32)0x3B7C88, (s32)0x3B7F08, (s32)0x3B7F30);
        D_001DA1A0 = 1;
    }
    return (s32)D_001DA188;
}
/* localdecomp:end func_003B7F80 */
