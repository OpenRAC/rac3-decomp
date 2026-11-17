#include "common.h"

/* localdecomp:start func_L07_004249A0 */
#include "vu0.h"

typedef struct { u8 pad0[0x34]; s32 f34; u8 pad38[0x1A0 - 0x38]; u8 *f1A0[1]; } S_004249A0;

extern S_004249A0 D_L07_001E6200;
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void *func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L07_004249A0(s32 a0, s32 a1) {
    vu0_v4 p;
    vu0_v4 s;
    vu0_v4 b;
    u8 *m;
    s32 i;
    f32 r;
    f32 f;
    f32 a;

    if (D_L07_001E6200.f34 == (a0 * 5 + 2) / 6) {
        m = D_L07_001E6200.f1A0[a1];
        qzero(&b);
        b.z = 0.6f;
        vec_add_ab(&b, m + 0x10, &b);
        r = 0.1f;
        for (i = 0; i < 8; i++) {
            p = b;
            func_003C4C18(&p, 0.6f);
            qzero(&s);
            s.z = func_003824E0(0.0f, 0.010000001f);
            func_L01_0046C470(&p, &s, 0x60008060, func_003824E0(1.5f, 2.5f), 100, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
        }
        qzero(&b);
        b.z = 0.90000004f;
        vec_add_ab(&b, m + 0x10, &b);
        for (i = 0; i < 720; i += 10) {
            f = (f32)i;
            p = b;
            a = f * 0.017453292f;
            p.x += r * func_0038D098(a);
            p.y += r * func_0038D0B0(a);
            p.z -= f * 0.003f;
            r += 0.015f;
            qzero(&s);
            s.z = 0.026f;
            func_L01_0046C470(&p, &s, 0x50008030, func_003824E0(0.2f, 0.5f), 100, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
        }
    }
}
/* localdecomp:end func_L07_004249A0 */
