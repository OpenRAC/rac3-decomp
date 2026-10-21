/* US draft of func_00393670 (rac3-uya-decomp func_003935B0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_00393670 */
extern s32 D_00227600[];
extern s32 D_001D9E98;
extern s32 D_001D9E9C;
void func_00393670(void) {
    s32 a = D_00227600[0];
    D_001D9E98 = a;
    *(volatile s32 *)&D_001D9E9C = a + 0x64000;
}
/* localdecomp:end func_00393670 */
