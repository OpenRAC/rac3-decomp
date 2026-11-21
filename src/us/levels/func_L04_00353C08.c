#include "common.h"

/* NTSC-U counterpart of func_L04_00354AE8 (src/levels/shared/L04_00354AE8.c) */
#include "vu0.h"

/* localdecomp:start func_L04_00353C08 */
extern vu0_v4 D_L04_001E2840_00353C08;
extern u8 D_L04_001D66B0_00353C08;
__asm__(".extern D_L04_001D66B0_00353C08, 64");
extern u8 *D_L04_0021FC98[];
extern u8 *D_L04_0021FE04[];
extern u8 *D_L04_0021FE08[];
extern u8 *D_L04_0021FE1C[];

extern f32 func_00388A28(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_00388830(void *, void *, f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_0046CF70(void *, void *, s32, f32);
extern u8 *func_L01_0046D570(void *, s32, f32, f32, s32, s32, s32, void *, s32, s32, s32, s32);

void func_L04_00353C08(void *self, s32 a1, s32 a2, s32 a3, f32 ang, s32 p5, s32 p6) {
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

    vec_sub_ab(&d, &D_L04_001E2840_00353C08, o);
    base = func_00388A28(d.x, d.y);
    for (n = 5; n >= 0; n--) {
        life = (s32)func_L01_00440918(2.0f, 5.0f);
        sa = func_0037E250(0.6f, 1.0f) * 0.3f;
        raw = func_0037E250(9.0f, 12.0f) * 0.3f;
        th = func_00389380(base, func_L01_00440918(0.0f, 1.3962634f));
        sb = raw * 0.016666668f;
        e.x = func_00388960(th) * sb;
        e.y = func_00388978(th) * sb;
        e.z = 0.0f;
        raw = func_0037E250(0.0f, 12.0f) * 0.3f;
        e.z = raw * 0.016666668f;
        i1 = func_0037E208(30, 50);
        func_L01_0046DCB8(o, &e, i1, a2, life, 0x7F, 0x7F, sa * 210000.0f, 630.0f, 0.0040555559f, 1);
        life = -(life << 1);
        i2 = func_0037E208(30, 50);
        sa = sa * 6.0f;
        q = func_L01_0046DCB8(o, &e, i2, a2, life, 0x30, 0x30, sa * 210000.0f, 1260.0f, 0.0040555559f, 0);
        if (q != 0) {
            q[2] = *D_L04_0021FC98[0xD4 / 4];
        }
    }
    vec_sub_ba(&e, &D_L04_001E2840_00353C08, o);
    func_00388830(&e, &e, func_0037E250(0.05f, 0.1f));
    for (m = 0; m < 6; m++) {
        e.x += func_0037E250(-0.03f, 0.03f);
        e.y += func_0037E250(-0.03f, 0.03f);
        e.z += func_0037E250(0.0f, 0.03f);
        func_L01_0046CF70(o, &e, func_0037E208(25, 40), 0.0040555559f);
    }
    func_L01_0046D570(o, 0x28, 0.1f, 0.85f, a3, 2, 4, &D_L04_001D66B0_00353C08, 0, 1, 6, 1);
    p = func_L01_0046D570(o, 0x1E, 0.4f, 1.75f, p5, 2, 0, &D_L04_001D66B0_00353C08, 0, 0, 6, 1);
    if (p != 0) {
        p[2] = D_L04_0021FE1C[0][2];
    }
    func_L01_0046D570(o, 0x28, 0.15f, 1.35f, p6, 0, 2, &D_L04_001D66B0_00353C08, 0, 4, 6, 1);
    p = func_L01_0046D570(o, 0x1B, 0.5f, ang, a1, 2, 0, &D_L04_001D66B0_00353C08, 3, 0, 6, 1);
    if (p != 0) {
        p[2] = D_L04_0021FE04[0][2];
    }
    p = func_L01_0046D570(o, 0x1B, 0.3f, ang - 0.5f, a1, 1, -2, &D_L04_001D66B0_00353C08, 3, 4, 6, 1);
    if (p != 0) {
        p[2] = D_L04_0021FE08[0][4];
    }
}
/* localdecomp:end func_L04_00353C08 */
