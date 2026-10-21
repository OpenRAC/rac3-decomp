/* US draft of func_003917E8 (rac3-uya-decomp func_00391728, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003917E8 */
extern s32 D_001D4D08_003917E8;
extern s32 D_001D4D0C_003917E8;
extern void func_00391778(void);
void func_003917E8(s32 dx, s32 dy, s32 clamp) {
    D_001D4D08_003917E8 += dx; D_001D4D0C_003917E8 += dy; if (clamp) { s32 x = D_001D4D08_003917E8 >= 0 ? D_001D4D08_003917E8 : 0; s32 y = D_001D4D0C_003917E8 >= 0 ? D_001D4D0C_003917E8 : 0; D_001D4D08_003917E8 = x <= 3000 ? x : 3000; D_001D4D0C_003917E8 = y <= 450 ? y : 450; }
    func_00391778();
}
/* localdecomp:end func_003917E8 */
