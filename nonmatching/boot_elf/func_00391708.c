/* US draft of func_00391708 (rac3-uya-decomp func_00391648, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_00391708 */
extern s32 D_00143950[];
extern s32 D_001D5520;
extern void func_12A950(void);
extern void func_12BEE8(s32, s32, s32, s32);
void func_00391708(void) {
    func_12A950();
    if (D_00143950[0]) D_001D5520 = 0;
    if (D_001D5520) func_12BEE8(0, 0, 0x50, 1);
    else func_12BEE8(0, 1, D_00143950[0] ? 3 : 2, 0);
}
/* localdecomp:end func_00391708 */
