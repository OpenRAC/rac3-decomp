#include "common.h"

/* NTSC-U counterpart of func_L41_0041B308 (src/levels/shared/L41_0041B308.c) */
/* localdecomp:start func_L41_0041ACB0 */
__asm__(".extern D_001DCB3C_sda, 4");
extern s32 *D_L41_002412A0;
extern f32 D_001DCB3C_sda;
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B25C8_0041ACB0(void);
extern s32 func_L39_005B2498(s32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern u8 *func_L01_00329470(void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);

/* When fewer than 3 are active, spawns one debris moby at a0 with a random launch speed scaled by
 * scale and random angles, and scales its field +0x2C by a random factor between lo and hi. */
void func_L41_0041ACB0(u8 *a0, f32 scale, f32 lo, f32 hi) {
    u8 *p;
    s32 s1;
    f32 f20;
    f32 f21;
    f32 vec[4];

    if (*D_L41_002412A0 < 3) {
        s1 = 0;
        f20 = func_L39_005B2510(10.0f, 20.0f) * 0.016666668f * scale;
        f21 = func_L39_005B25C8_0041ACB0();
        func_0037E4B8(vec, f20, f21, func_L39_005B2510(0.4363323152065277f, 0.7853981852531433f));
        if (func_L39_005B2498(3) != 0) {
            if (D_001DCB3C_sda < 0.8f) {
                s1 = 1;
            }
        }
        p = func_L01_00329470(a0, vec, func_L39_005B24C8(0x78, 0x96), 3, s1, 0x80808080, 0, 1, 0x32, 0x78, 1.0f, 14.6f);
        if (p != 0) {
            *(f32 *)(p + 0x2C) = *(f32 *)(p + 0x2C) * func_L39_005B2510(lo, hi);
        }
    }
}
/* localdecomp:end func_L41_0041ACB0 */
