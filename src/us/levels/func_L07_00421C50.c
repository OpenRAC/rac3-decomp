#include "common.h"

/* NTSC-U counterpart of func_L07_004249A0 (src/levels/shared/L07_004249A0.c) */
/* localdecomp:start func_L07_00421C50 */
#include "vu0.h"

typedef struct { u8 pad0[0x34]; s32 f34; u8 pad38[0x1A0 - 0x38]; u8 *f1A0[1]; } S_004249A0;

extern S_004249A0 D_L07_001E6200_00421C50;
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void *func_L01_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);

void func_L07_00421C50(s32 a0, s32 a1) {
    vu0_v4 p;
    vu0_v4 s;
    vu0_v4 b;
    u8 *m;
    s32 i;
    f32 r;
    f32 f;
    f32 a;

    if (D_L07_001E6200_00421C50.f34 == a0) {
        m = D_L07_001E6200_00421C50.f1A0[a1];
        qzero(&b);
        b.z = 0.6f;
        vec_add_ab(&b, m + 0x10, &b);
        r = 0.1f;
        for (i = 0; i < 8; i++) {
            p = b;
            func_003BF6A8(&p, 0.6f);
            qzero(&s);
            s.z = func_0037E250(0.0f, 0.008333334f);
            func_L01_00468DC0(&p, &s, 0x60008060, func_0037E250(1.5f, 2.5f), 100, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
        }
        qzero(&b);
        b.z = 0.90000004f;
        vec_add_ab(&b, m + 0x10, &b);
        for (i = 0; i < 720; i += 10) {
            f = (f32)i;
            p = b;
            a = f * 0.017453292f;
            p.x += r * func_00388960(a);
            p.y += r * func_00388978(a);
            p.z -= f * 0.003f;
            r += 0.015f;
            qzero(&s);
            s.z = 0.021666666f;
            func_L01_00468DC0(&p, &s, 0x50008030, func_0037E250(0.2f, 0.5f), 100, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
        }
    }
}
/* localdecomp:end func_L07_00421C50 */
