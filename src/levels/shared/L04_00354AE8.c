#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_00354AE8 */
extern vu0_v4 D_L04_001E27C0;
extern u8 D_L04_001D66B0;
__asm__(".extern D_L04_001D66B0, 64");
extern u8 *D_L04_0021FC18[];
extern u8 *D_L04_0021FD84[];
extern u8 *D_L04_0021FD88[];
extern u8 *D_L04_0021FD9C[];

extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_00470668(void *, void *, s32, f32);
extern u8 *func_L01_00470C78(void *, s32, f32, f32, s32, s32, s32, void *, s32, s32, s32, s32);

void func_L04_00354AE8(void *self, s32 a1, s32 a2, s32 a3, f32 ang, s32 p5, s32 p6) {
    u8 *o = self;
    vu0_v4 d;
    vu0_v4 e;
    f32 base;
    f32 sa;
    f32 sb;
    f32 raw;
    f32 th;
    s32 life;
    s32 n;
    s32 m;
    s32 i1;
    s32 i2;
    u8 *p;
    u8 *q;

    vec_sub_ab(&d, &D_L04_001E27C0, o);
    base = func_0038D160(d.x, d.y);
    for (n = 5; n >= 0; n--) {
        life = (s32)func_L01_00443A18(2.0f, 5.0f);
        sa = func_003824E0(0.6f, 1.0f) * 0.3f;
        raw = func_003824E0(9.0f, 12.0f) * 0.3f;
        th = func_0038DAB8(base, func_L01_00443A18(0.0f, 1.3962634f));
        sb = raw * 0.020000001f;
        e.x = func_0038D098(th) * sb;
        e.y = func_0038D0B0(th) * sb;
        e.z = 0.0f;
        raw = func_003824E0(0.0f, 12.0f) * 0.3f;
        e.z = raw * 0.020000001f;
        i1 = func_00382498(30, 50);
        func_L01_004713C8(o, &e, (i1 * 5 + 2) / 6, a2, life, 0x7F, 0x7F, sa * 210000.0f, 630.0f, 0.00584f, 1);
        life = -(life << 1);
        i2 = func_00382498(30, 50);
        sa = sa * 6.0f;
        q = func_L01_004713C8(o, &e, (i2 * 5 + 2) / 6, a2, life, 0x30, 0x30, sa * 210000.0f, 1260.0f, 0.00584f, 0);
        if (q != 0) {
            q[2] = *D_L04_0021FC18[0xD4 / 4];
        }
    }
    vec_sub_ba(&e, &D_L04_001E27C0, o);
    func_0038CF68(&e, &e, func_003824E0(0.05f, 0.1f));
    for (m = 0; m < 6; m++) {
        e.x += func_003824E0(-0.03f, 0.03f);
        e.y += func_003824E0(-0.03f, 0.03f);
        e.z += func_003824E0(0.0f, 0.03f);
        func_L01_00470668(o, &e, (func_00382498(25, 40) * 5 + 2) / 6, 0.00584f);
    }
    func_L01_00470C78(o, 0x21, 0.1f, 0.85f, a3, 2, 4, &D_L04_001D66B0, 0, 1, 6, 1);
    p = func_L01_00470C78(o, 0x19, 0.4f, 1.75f, p5, 2, 0, &D_L04_001D66B0, 0, 0, 6, 1);
    if (p != 0) {
        p[2] = D_L04_0021FD9C[0][2];
    }
    func_L01_00470C78(o, 0x21, 0.15f, 1.35f, p6, 0, 2, &D_L04_001D66B0, 0, 4, 6, 1);
    p = func_L01_00470C78(o, 0x16, 0.5f, ang, a1, 2, 0, &D_L04_001D66B0, 3, 0, 6, 1);
    if (p != 0) {
        p[2] = D_L04_0021FD84[0][2];
    }
    p = func_L01_00470C78(o, 0x16, 0.3f, ang - 0.5f, a1, 1, -2, &D_L04_001D66B0, 3, 4, 6, 1);
    if (p != 0) {
        p[2] = D_L04_0021FD88[0][4];
    }
}
/* localdecomp:end func_L04_00354AE8 */
