#include "common.h"

/* NTSC-U counterpart of func_L12_003D63D8 (src/levels/shared/L12_003D5D08.c) */
extern f32 func_00388A28(f32, f32);
typedef struct {
    f32 x, y, z, w;
    u8 p10[0x460 - 0x10];
} E_003D63D8;
typedef struct {
    u8 p0[0x170];
    u8 *p170;
} T_003D63D8;
extern s32 D_001D52F0;
extern E_003D63D8 D_L12_001E2800[];
extern T_003D63D8 D_L12_00220E58;
extern f32 func_L12_003D3D70(void);
extern f32 func_00388A28(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00389380(f32, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);

/* localdecomp:start func_L12_003D46D0 */
#include "vu0.h"


extern s32 D_001D52F0;
extern E_003D63D8 D_L12_001E2800[];
extern vu0_v4 D_L12_001EA800[];
extern T_003D63D8 D_L12_00220E58;
extern s32 D_001A71A0[];
extern s32 D_L12_001DF000_003D46D0;
__asm__(".extern D_L12_001DF000_003D46D0, 4");
extern s32 D_L12_001DF004_003D46D0;
__asm__(".extern D_L12_001DF004_003D46D0, 4");
extern s32 D_L12_001DF014;
__asm__(".extern D_L12_001DF014, 4");
extern s32 D_L12_001DF018_003D46D0;
__asm__(".extern D_L12_001DF018_003D46D0, 4");
extern u32 D_L12_001DF034;
__asm__(".extern D_L12_001DF034, 4");
extern u32 D_L12_001DF038;
__asm__(".extern D_L12_001DF038, 4");
extern s32 D_L12_001DF03C_003D46D0;
__asm__(".extern D_L12_001DF03C_003D46D0, 4");

extern s32 func_00388398(void *);
extern void func_003BD360(void *);
extern f32 func_00388A28(f32, f32);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E208(s32, s32);
extern void *func_L01_0046CF70(void *, void *, s32, f32);
extern f32 func_L12_003D3D70(void);
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern u8 *func_L01_004633E8(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern f32 func_0037E2A8(void);
extern void func_00388758(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_00389158(void *, void *, void *, f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_003F9498(void *, f32, s32, void *);
extern void func_L01_004026A0(void *, void *);
extern void func_L12_003D4ED0(u8 *);

void func_L12_003D46D0(u8 *m, u8 *v) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 g;
    f32 yaw;
    f32 ang;
    s32 i1, i2, i3, i4, i5;
    u8 *p1, *p2, *p3, *p4;

    if (func_00388398(v + 0x24) == 0) {
    {
        E_003D63D8 *e = &D_L12_001E2800[D_001D52F0];
        yaw = func_00388A28(e->x - *(f32 *)(m + 0x10), e->y - *(f32 *)(m + 0x14));
    }
    if (*(s32 *)(v + 0x24) == 0x3A) {
        for (i1 = 0; i1 < D_L12_001DF004_003D46D0; i1++) {
            func_0037E2F0(&a, 0.4375f, 0.58333337f);
            a.z *= 0.25f;
            func_L01_0046CF70(m + 0x10, &a, func_0037E208(0x19, 0x28), 0.0040555559f);
        }
    }
    if (*(s32 *)(v + 0x24) == 0x39) {
        s32 sign = 1;
        for (i2 = 0; i2 < D_L12_001DF000_003D46D0; i2++) {
            f32 sp, pitch, roll;
            sign = -sign;
            a.x = *(f32 *)(m + 0x10) + func_L12_003D3D70() * 1.75f;
            a.y = *(f32 *)(m + 0x14) + func_L12_003D3D70() * 1.75f;
            a.z = *(f32 *)(m + 0x18) + func_L12_003D3D70() * 1.75f * 0.25f;
            sp = func_0037E250(0.016666668f, 0.033333335f) * 1.75f;
            pitch = func_L01_00440918(0.0f, 1.3962634f);
            roll = func_00389380(yaw, func_L01_00440918(0.0f, 1.5707964f));
            func_0037E4B8(&b, sp, roll, pitch);
            b.z *= 0.25f;
            p1 = func_L01_004633E8(&a, 0.0f, 1.0f, 1.01f, 551250.0f, sign, &b, D_L12_001DF034, 0);
            if (p1 != 0) {
                s32 n = func_0037E208(0x28, 0x46);
                u8 *q = p1 + 0x20;
                *(u8 *)(p1 + 9) = 0x44;
                *(s16 *)(p1 + 0xA) = n;
                *(s32 *)(q + 4) = 3;
                n = func_0037E208(1, 10);
                *(u8 *)(q + 0xA) = 0x40;
                *(f32 *)(q + 0x1C) = (f32)(n);
                *(u8 *)(q + 0xB) = *(u8 *)(p1 + 0xA);
            }
        }
    }
    if (*(s32 *)(v + 0x24) == 0x37 && D_L12_001DF018_003D46D0 != 0) {
        ang = func_0037E2A8();
        func_0037E2F0(&a, 1.0f, 1.0f);
        vec_sub_ba(&b, &D_L12_001E2800[D_001D52F0], m + 0x10);
        func_00388758(&c, &b, &a);
        func_00388830(&c, &c, 1.0f);
        for (i3 = 0; i3 < 100; i3++) {
            s32 k = (s32)func_L01_00440918(2.0f, 5.0f);
            func_00389158(&d, &c, &a, ang);
            func_00388830(&d, &d, 0.4375f);
            d.z *= 0.25f;
            p2 = func_L01_0046DCB8(m + 0x10, &d, func_0037E208(0x14, 0x1B), D_L12_001DF038, k, 0x4F, 0, 1,
                                  404250.0f, 441000.03f, 0.0f);
            if (p2 != 0) {
                p2[2] = *D_L12_00220E58.p170;
            }
            ang = func_00389380(ang, 0.06346652f);
        }
    }
    if (*(s32 *)(v + 0x24) == 0x36 && D_L12_001DF014 != 0) {
        ang = func_0037E2A8();
        if (func_L01_003F9498(m + 0x10, 1.0f, 0x14, (void *)D_001A71A0[0]) != 0) {
            a = D_L12_001EA800[0];
            b = D_L12_001EA800[-2];
        } else {
            func_0037E2F0(&a, 1.0f, 1.0f);
            b = *(vu0_v4 *)(m + 0x10);
        }
        func_00388830(&a, &a, 0.05f);
        vec_add_ba(&b, &b, &a);
        func_00388830(&a, &a, 1.0f);
        vec_sub_ba(&c, &D_L12_001E2800[D_001D52F0], m + 0x10);
        func_00388758(&d, &c, &a);
        func_00388830(&d, &d, 1.0f);
        if (D_L12_001DF03C_003D46D0 != 0) {
            for (i4 = 0; i4 < 100; i4++) {
                s32 k = (s32)func_L01_00440918(2.0f, 5.0f);
                func_00389158(&g, &d, &a, ang);
                func_00388830(&g, &g, func_0037E250(5.0f, 9.0f) * 0.016666668f * 1.75f);
                g.z *= 0.25f;
                if (i4 % 3 == 0) {
                    p3 = func_L01_0046DCB8(&b, &g, func_0037E208(0x14, 0x1B), D_L12_001DF038, k, 0x4F, 0, 1,
                                          404250.0f, 441000.03f, 0.0f);
                    if (p3 != 0) {
                        p3[2] = *D_L12_00220E58.p170;
                    }
                }
                ang = func_00389380(ang, 0.06346652f);
            }
        } else {
            for (i5 = 0; i5 < 100; i5++) {
                s32 k = (s32)func_L01_00440918(2.0f, 5.0f);
                func_00389158(&g, &d, &a, ang);
                func_00388830(&g, &g, 0.4375f);
                g.z *= 0.25f;
                p4 = func_L01_0046DCB8(&b, &g, func_0037E208(0x14, 0x1B), D_L12_001DF038, k, 0x4F, 0, 1,
                                      404250.0f, 441000.03f, 0.0f);
                if (p4 != 0) {
                    p4[2] = *D_L12_00220E58.p170;
                }
                ang = func_00389380(ang, 0.06346652f);
            }
        }
    }
    func_00388398(v + 0x34);
    func_L01_004026A0(func_L12_003D4ED0, m);
    } else {
        func_003BD360(m);
    }
}
/* localdecomp:end func_L12_003D46D0 */
