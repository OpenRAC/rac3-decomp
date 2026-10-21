/* US draft of func_0038A3B8 (rac3-uya-decomp func_00385CE0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0038A3B8 */
extern s32 D_001D4D40_0038A3B8;
extern s32 D_00225734_0038A3B8[];
extern s32 D_001D55E8_0038A3B8;
extern s32 D_00143950[];
extern f32 func_0038D098(f32);
extern void func_0038DBD8(s32, s32, f32);
extern void func_0038E150(s32);
extern s32 func_00381FF0(s32);
extern void func_0038E7E8_0038A3B8(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
void func_0038A3B8(void) {
    f32 f, y;
    s32 old, n;
    if (D_001D4D40_0038A3B8 == 1) {
        n = ((u8 *)D_00143950)[0xAD] ? 0x30 : 0x5A;
        f = (f32)(D_00225734_0038A3B8[0] % 100) / 50.0f - 1.0f;
        if (f < -1.0f) f = -1.0f;
        if (1.0f < f) f = 1.0f;
        y = n;
        f = func_0038D098(f * 3.1415927f);
        n = ((s32 (*)(s32, s32, f32))func_0038DBD8)(0x7FE0E0E0, 0x5F66CCFF, (f + 1.0f) * 0.5f);
        old = D_001D55E8_0038A3B8;
        func_0038E150(0);
        func_0038E7E8_0038A3B8(480.0f, y, 1.0f, n, func_00381FF0(0x244), -1, 1.0f, 2, 1, 0x80000000, 1.0f, 1.0f);
        func_0038E150(old);
    }
}
/* localdecomp:end func_0038A3B8 */
