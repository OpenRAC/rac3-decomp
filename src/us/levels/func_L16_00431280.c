#include "common.h"

/* NTSC-U counterpart of func_L16_00434290 (src/levels/16_kerwan/L16_00434290.c): 0.004 -> 0.00333333; 0.002 -> 0.00166667 */
/* localdecomp:start func_L16_00431280 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00434290;
typedef struct { V4_00434290 v[2]; } L_00434290;
typedef struct {
    s16 life;
    s16 life2;
    f32 w;
    f32 h;
    f32 spin;
    f32 spread;
    s32 c0;
    s32 c1;
    s32 n;
} P_00434290;
extern const L_00434290 D_L16_001D6C20;
extern void func_003BF6A8(f32 *v, f32 r);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L16_00431280(void) {
    V4_00434290 v;
    V4_00434290 d;
    P_00434290 p;
    L_00434290 l;
    s32 i;

    p.c0 = 0x23802020;
    p.c1 = 0x202020;
    p.life = 0x78;
    p.life2 = 0x5A;
    p.n = 5;
    p.w = 0.6f;
    p.spin = 0.00333333365f;
    p.spread = 0.00166666682f;
    l = D_L16_001D6C20;
    p.h = 0.0f;
    for (i = 0; i < 2; i++) {
        v = l.v[i];
        func_003BF6A8(&v.x, 0.15f);
        d.x = func_0037E250(-p.spread, p.spread);
        d.y = func_0037E250(-p.spread, p.spread);
        d.z = func_0037E250(p.spin, p.spin + p.spin);
        func_L01_00472438(&v, &d, func_0037E208(p.life2, p.life), 0, p.c0, p.c1,
                          (s32)(p.w * 210000.0f), (s32)(p.h * 210000.0f), 0.0f, 1);
    }
}
/* localdecomp:end func_L16_00431280 */
