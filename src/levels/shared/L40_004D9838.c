#include "common.h"

/* localdecomp:start func_L40_004D9838 */
__asm__(".extern D_001D9FC4_sda, 4");
__asm__(".extern D_001D9FC8_sda, 4");
__asm__(".extern D_001D9FCC_sda, 4");
__asm__(".extern D_001D9FD0_sda, 4");
__asm__(".extern D_001D9FD4_sda, 4");
__asm__(".extern D_001D9FD8_sda, 4");
extern f32 D_001D9FC4_sda;
extern f32 D_001D9FC8_sda;
extern f32 D_001D9FCC_sda;
extern f32 D_001D9FD0_sda;
extern s32 D_001D9FD4_sda;
extern s32 D_001D9FD8_sda;
extern s32 D_L40_00248240;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_004D2118(void *, void *, s32, s32, s32, s32);

void func_L40_004D9838(void *a0, void *a1, s32 a2, s32 a3, s32 a4) {
    u32 i;
    s32 lvl;
    f32 sx, sy, c, d;
    f32 ang, pi, half, rad;
    s32 x, y;

    if (D_L40_00248240 != 0) {
        lvl = **(s32 **)0x241120;
        sx = D_001D9FC4_sda;
        sy = D_001D9FC8_sda;
        c = D_001D9FCC_sda;
        d = D_001D9FD0_sda;
        if (lvl >= 2) {
            if (lvl >= 3) {
                sx = sy = 0.65f;
                c = 60.0f;
                d = 17.5f;
            } else {
                sx = sy = 0.727f;
                c = 110.0f;
                d = -2.0f;
            }
        }
        pi = 3.1415927f;
        half = 1.5707964f;
        rad = 74.0f;
        for (i = 0; i < 8; i++) {
            ang = (f32)i * 2.0f * pi / (f32)D_L40_00248240 - pi + half;
            x = (s32)((f32)a2 + c + (f32)(s32)(func_0038D098(ang) * rad * sx));
            y = (s32)((f32)a3 + d + (f32)(s32)(func_0038D0B0(ang) * rad * sy));
            if (i == D_001D9FD8_sda)
                func_L01_004D2118(a0, a1, i, x, y + D_001D9FD4_sda, a4);
            else
                func_L01_004D2118(a0, a1, i, x, y, a4);
        }
    }
}
/* localdecomp:end func_L40_004D9838 */
