#include "common.h"

/* NTSC-U counterpart of func_L30_00427F30 (src/levels/30_vidcomic_unnamed/L30_00427F30.c) */
/* localdecomp:start func_L30_00424D30 */
typedef int u128_t_00427F30 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00427F30;
extern f32 func_L01_00440918(f32, f32);
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern u8 *func_L01_004633E8(void *, f32, f32, f32, f32, s32, void *, u32, s32);

void func_L30_00424D30(void *pos, s32 n, u32 colour, f32 radius, f32 spread, f32 lo, f32 hi) {
    V4_00427F30 vel;
    s32 i;
    s32 k;
    f32 ang;
    f32 r;
    f32 tau;
    f32 sc;
    u8 *p;
    u8 *q;

    *(u128_t_00427F30 *)&vel = 0;
    vel.w = 1.0f;
    for (i = 0; i < n; i++) {
        tau = 6.2831855f;
        ang = (f32)i / (f32)n * tau;
        r = radius * 0.0166666675f + func_L01_00440918(0.0f, spread * 0.0166666675f);
        vel.x = r * func_00388978(ang);
        vel.y = r * func_00388960(ang);
        k = func_0037E208(0, 2) - 1;
        sc = 210000.0f;
        p = func_L01_004633E8(pos, 0.1f, 1.0f, 1.0f, func_0037E250(lo, hi) * sc, k, &vel,
                              colour | 0x7F7F7F, 0);
        if (p != 0) {
            q = p + 0x20;
            *(s16 *)(p + 0xA) = 0x3C;
            *(s32 *)(q + 4) = 2;
            q[0xA] = colour;
            q[0xB] = p[0xA];
        }
    }
}
/* localdecomp:end func_L30_00424D30 */
