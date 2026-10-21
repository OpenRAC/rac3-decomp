/* US draft of func_00391408 (rac3-uya-decomp func_0038CBD0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00391408 */
extern s32 D_001D4D08_00391408;
extern s32 D_001D4D0C_00391408;
extern void func_00391398(void);
void func_00391408(s32 dx, s32 dy, s32 clamp) {
    D_001D4D08_00391408 += dx; D_001D4D0C_00391408 += dy; if (clamp) { s32 x = D_001D4D08_00391408 >= 0 ? D_001D4D08_00391408 : 0; s32 y = D_001D4D0C_00391408 >= 0 ? D_001D4D0C_00391408 : 0; D_001D4D08_00391408 = x <= 3000 ? x : 3000; D_001D4D0C_00391408 = y <= 450 ? y : 450; }
    func_00391398();
}
/* localdecomp:end func_00391408 */
