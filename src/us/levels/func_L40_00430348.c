#include "common.h"

/* NTSC-U counterpart of func_L05_003AFC08 (src/levels/05_daxx/L05_003AFC08.c) */
#include "vu0.h"

/* localdecomp:start func_L40_00430348 */
/* func_L40_00430348: from the staged near miss. func_L01_0032FE90 takes its float second and
   func_L01_00472438 its int after the three floats (the order of the argument moves); the fabs
   is include/vu0.h's fabs_asm, which retail's abs.s after func_003886E8 is scheduled as. */
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_L39_005B2498(s32);
extern s32 func_L39_005B24C8(s32, s32);
extern f32 func_L39_005B2510(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_003D72E0(void *, void *, f32, f32, s32, f32, s32, s32, s32, void *, s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_0032FE90(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 D_001DC2C4_sda;
__asm__(".extern D_001DC2C4_sda, 4");
extern f32 D_001DC2D0_sda;
__asm__(".extern D_001DC2D0_sda, 4");
extern f32 D_001DC2D4_sda;
__asm__(".extern D_001DC2D4_sda, 4");
extern f32 D_001DC2D8_sda;
__asm__(".extern D_001DC2D8_sda, 4");
extern f32 D_001DC2DC_sda;
__asm__(".extern D_001DC2DC_sda, 4");
extern f32 D_001DC2E8_sda;
__asm__(".extern D_001DC2E8_sda, 4");
extern f32 D_001DC2EC_sda;
__asm__(".extern D_001DC2EC_sda, 4");
extern s32 D_001DC2CC_sda;
__asm__(".extern D_001DC2CC_sda, 4");
extern s32 D_001DC2C8_sda;
__asm__(".extern D_001DC2C8_sda, 4");
extern s32 D_001DC2E0_sda;
__asm__(".extern D_001DC2E0_sda, 4");
extern s32 D_001DC2E4_sda;
__asm__(".extern D_001DC2E4_sda, 4");
extern s32 D_001DC2F0_sda;
__asm__(".extern D_001DC2F0_sda, 4");
extern u8 D_L40_0029B0D8[];
__asm__(".extern D_L40_0029B0D8, 16");

void func_L40_00430348(f32 x, u8 *p, s32 n, u8 *a, s32 cnt) {
    u8 loc[0x10];
    u8 *r;
    s32 k;
    f32 f22, f20, f21, f23, t;
    s32 v;

    func_0037E2F0(loc, (D_001DC2C4_sda * 0.5f)*0.016666668f, D_001DC2C4_sda*0.016666668f);
    func_L01_003D72E0(p, loc, -1e+05f, x * D_001DC2D0_sda, D_001DC2CC_sda, -5.0f, 7, 5, D_001DC2C8_sda, a, 0);
    if (cnt > 0) {
        if (func_L39_005B2498(cnt) == 0) {
            func_L01_0032FE90(p, x*0.6f, 0, 2, 2, 2, 1, 2, 1, 0.0f, 0.0f, 0.0f,
                0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
    }
    if (n > 0) {
        u8 *tb = D_L40_0029B0D8;
        cnt = n;
        v = 0xF2;
        do {
            func_0037E2F0(loc, (D_001DC2D4_sda*0.5f)*0.016666668f, D_001DC2D4_sda*0.016666668f);
            k = func_L39_005B24C8(-2, 2);
            f23 = (D_001DC2DC_sda * x) * 2.1e+05f;
            t = func_L39_005B2510(D_001DC2E8_sda*0.6f, D_001DC2E8_sda);
            r = func_L01_00472438(p, loc, D_001DC2E0_sda, k, 0x7F407FFF, 0x407FFF, f23, f23, t, 0);
            if (r != 0) {
                r[9] = (u8)v;
                r[3] = func_L39_005B2498(D_001DC2F0_sda) ? 0x44 : 0x48;
                r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
            }
            if(func_L39_005B2498(4)) {
            func_003886E8(loc, loc, D_001DC2D8_sda);
            *(f32 *)(loc + 8) = fabs_asm(*(f32 *)(loc + 8));
            k = func_L39_005B24C8(-2, 2);
            f22 = D_001DC2DC_sda * x;
            f21 = (f22 * 0.3f) * 2.1e+05f;
            f20 = (f22 * 0.04f) * 2.1e+05f;
            t = func_L39_005B2510(D_001DC2EC_sda*0.6f, D_001DC2EC_sda);
            r = func_L01_00472438(p, loc, D_001DC2E4_sda, k, 0x7F0048FF, 0x48FF, f21, f20, t, 0);
            if (r != 0) {
                r[9] = (u8)v;
                r[3] = func_L39_005B2498(D_001DC2F0_sda) ? 0x44 : 0x48;
                r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
            }
            }
            cnt--;
        } while (cnt != 0);
    }
}
/* localdecomp:end func_L40_00430348 */
