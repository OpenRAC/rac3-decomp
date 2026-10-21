/* Near miss of func_003B42C0 with its file's own flags: tools/check.py reports 6 diff
   (the version it replaces: 8).
*/

/* PAL candidate for func_003B42C0 (US draft of rac3-uya-decomp func_003AED08).

   Retail reaches the two globals at 0x001DA10C and 0x001DA110 with absolute
   addressing (lui $at %hi / sw %lo($at)), not with the compiler's own split
   form (lui $v1 / sw %lo($v1)).  A named global's address is split by gcc
   into a register of its own; a literal address is materialised in $at with
   its low half folded into the store, which is what retail has
   (docs/wiki/Matching-Patterns.md, and func_003B3378 in this same file).
   The two flags at 0x001DA108 and 0x001DA114 are small data and stay in $gp. */

/* localdecomp:start func_003B42C0 */
extern s32 D_001DA114;
extern s32 D_001DA108;
extern u8 *D_001DA10C[];
extern s32 D_001DA110[];
extern u8 D_001D8918[];
s32 *func_003B42C0(void) {
    if (D_001DA114 == 0) {
        *(u8 **)0x001DA10C = D_001D8918;
        D_001DA114 = 1;
        D_001DA108 = 1;
        *(s32 *)0x001DA110 = 0;
    }
    return &D_001DA108;
}
/* localdecomp:end func_003B42C0 */
