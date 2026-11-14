#include "common.h"

/* localdecomp:start func_L30_00427F30 */
typedef int u128_t_00427F30 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00427F30;
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);

void func_L30_00427F30(void *pos, s32 n, u32 colour, f32 radius, f32 spread, f32 lo, f32 hi) {
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
        r = radius * 0.020000001f + func_L01_00443A18(0.0f, spread * 0.020000001f);
        vel.x = r * func_0038D0B0(ang);
        vel.y = r * func_0038D098(ang);
        k = func_00382498(0, 2) - 1;
        sc = 210000.0f;
        p = func_L01_004669B0(pos, 0.1f, 1.0f, 1.0f, func_003824E0(lo, hi) * sc, k, &vel,
                              colour | 0x7F7F7F, 0);
        if (p != 0) {
            q = p + 0x20;
            *(s16 *)(p + 0xA) = 0x32;
            *(s32 *)(q + 4) = 2;
            q[0xA] = colour;
            q[0xB] = p[0xA];
        }
    }
}
/* localdecomp:end func_L30_00427F30 */

LINKER_REMNANT("asm/levels", func_L30_00428120);
