/* Near miss of func_003B4380 with its file's own flags: tools/check.py reports 5 diff
   (the US draft it started from: 6).
   What differs: retail bytes are no-split (-mno-split-addresses) shaped: the store to
   D_001DA124 is an assembler-expanded "lui $at / sw %lo($at)" pair and the constant 1 sits in
   the bnez delay slot. Best candidate (5 of 12 words differ) reaches the same instruction set
   by storing through the literal address 0x001DA124 (gcc keeps it in the memory operand, the
   assembler expands it to lui $at / sw %lo($at)), but under the file's split-address flags gcc
   splits the address of D_001D88B8 into two real instructions before scheduling, so the lui
   $v0 lands in the delay slot instead of the constant, and the...
*/

/* US draft of func_003B4380 (rac3-uya-decomp func_003AEDC8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` (a single-function override).

   Best plain-C candidate found with the file's own flags (split addresses, -mvu0-use-vf0-vf2 -O2 -G8
   -fopt-stack -mno-check-zero-division): 5 of 12 words differ from retail.

   The store to D_001DA124 is written through a literal address so that gcc keeps the address in the
   memory operand; the assembler then expands it into the retail "lui $at / sw %lo($at)" pair.  With a
   declared global the compiler splits the address itself (lui $v1 / sw %lo($v1)), which is the no-split
   shape this function needs.  What is left is the order of the same twelve instructions: retail keeps
   the constant 1 in the branch delay slot and puts both $gp stores after the pointer store, while the
   split-address build puts the lui of D_001D88B8 in the delay slot and interleaves the stores. */


/* localdecomp:start func_003B4380 */
extern s32 D_001DA12C;
extern s32 D_001DA120;
extern u8 *D_001DA124[];
extern u8 D_001D88B8[];
s32 *func_003B4380(void) {
    if (D_001DA12C == 0) {
        *(u8 **)0x001DA124 = D_001D88B8;
        D_001DA120 = 1;
        D_001DA12C = 1;
    }
    return &D_001DA120;
}
/* localdecomp:end func_003B4380 */
