#include "common.h"

typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; void *w68; } M_3D5548;
typedef struct {
    void (*fn0)(void *);
} Iface;
typedef struct {
    char pad0[0x30];
    int timer;
    char pad34[0x3E - 0x34];
    unsigned char b62;
    char pad3F[0x40 - 0x3F];
    float f64;
} Vars;
typedef struct {
    char pad0[0x30];
    unsigned char b48;
    char pad31[0x32 - 0x31];
    short h50;
} Obj;

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L12_003D4B18.c, which this file was cut from */
extern f32 func_0038D160(f32, f32);

typedef struct {
    f32 x, y, z, w;
    u8 p10[0x460 - 0x10];
} E_003D63D8;
typedef struct {
    u8 p0[0x170];
    u8 *p170;
} T_003D63D8;

INCLUDE_ASM("asm/levels", func_L12_003D5D08);

/* localdecomp:start func_L12_003D63D8 */
#include "vu0.h"


extern s32 D_001D52F0;
extern E_003D63D8 D_L12_001E2780[];
extern vu0_v4 D_L12_001EA780[];
extern T_003D63D8 D_L12_00220DD8;
extern s32 D_001A71A0[];
extern s32 D_L12_001DEFC0;
__asm__(".extern D_L12_001DEFC0, 4");
extern s32 D_L12_001DEFC4;
__asm__(".extern D_L12_001DEFC4, 4");
extern s32 D_L12_001DEFD4;
__asm__(".extern D_L12_001DEFD4, 4");
extern s32 D_L12_001DEFD8;
__asm__(".extern D_L12_001DEFD8, 4");
extern u32 D_L12_001DEFF4;
__asm__(".extern D_L12_001DEFF4, 4");
extern u32 D_L12_001DEFF8;
__asm__(".extern D_L12_001DEFF8, 4");
extern s32 D_L12_001DEFFC;
__asm__(".extern D_L12_001DEFFC, 4");

extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern f32 func_0038D160(f32, f32);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern void *func_L01_00470668(void *, void *, s32, f32);
extern f32 func_L12_003D5A20(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern f32 func_00382538(void);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_003FB640(void *, f32, s32, void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L12_003D6C70(void);

void func_L12_003D63D8(u8 *m, u8 *v) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 g;
    f32 yaw;
    f32 ang;
    s32 i1, i2, i3, i4, i5;
    u8 *p1, *p2, *p3, *p4;

    if (func_0038CAD0(v + 0x24) == 0) {
    {
        E_003D63D8 *e = &D_L12_001E2780[D_001D52F0];
        yaw = func_0038D160(e->x - *(f32 *)(m + 0x10), e->y - *(f32 *)(m + 0x14));
    }
    if (*(s32 *)(v + 0x24) == 0x3A) {
        for (i1 = 0; i1 < D_L12_001DEFC4; i1++) {
            func_00382580(&a, 0.52500004f, 0.70000005f);
            a.z *= 0.25f;
            func_L01_00470668(m + 0x10, &a, (func_00382498(0x19, 0x28) * 5 + 2) / 6, 0.00584f);
        }
    }
    if (*(s32 *)(v + 0x24) == 0x39) {
        s32 sign = 1;
        for (i2 = 0; i2 < D_L12_001DEFC0; i2++) {
            f32 sp, pitch, roll;
            sign = -sign;
            a.x = *(f32 *)(m + 0x10) + func_L12_003D5A20() * 1.75f;
            a.y = *(f32 *)(m + 0x14) + func_L12_003D5A20() * 1.75f;
            a.z = *(f32 *)(m + 0x18) + func_L12_003D5A20() * 1.75f * 0.25f;
            sp = func_003824E0(0.020000001f, 0.040000003f) * 1.75f;
            pitch = func_L01_00443A18(0.0f, 1.3962634f);
            roll = func_0038DAB8(yaw, func_L01_00443A18(0.0f, 1.5707964f));
            func_00382760(&b, sp, roll, pitch);
            b.z *= 0.25f;
            p1 = func_L01_004669B0(&a, 0.0f, 1.0f, 1.01f, 551250.0f, sign, &b, D_L12_001DEFF4, 0);
            if (p1 != 0) {
                s32 n = func_00382498(0x28, 0x46);
                u8 *q = p1 + 0x20;
                *(u8 *)(p1 + 9) = 0x44;
                *(s16 *)(p1 + 0xA) = (n * 5 + 2) / 6;
                *(s32 *)(q + 4) = 3;
                n = func_00382498(1, 10);
                *(u8 *)(q + 0xA) = 0x40;
                *(f32 *)(q + 0x1C) = (f32)((n * 5 + 2) / 6);
                *(u8 *)(q + 0xB) = *(u8 *)(p1 + 0xA);
            }
        }
    }
    if (*(s32 *)(v + 0x24) == 0x37 && D_L12_001DEFD8 != 0) {
        ang = func_00382538();
        func_00382580(&a, 1.0f, 1.0f);
        vec_sub_ba(&b, &D_L12_001E2780[D_001D52F0], m + 0x10);
        func_0038CE90(&c, &b, &a);
        func_0038CF68(&c, &c, 1.0f);
        for (i3 = 0; i3 < 100; i3++) {
            s32 k = (s32)func_L01_00443A18(2.0f, 5.0f);
            func_0038D890(&d, &c, &a, ang);
            func_0038CF68(&d, &d, 0.52500004f);
            d.z *= 0.25f;
            p2 = func_L01_004713C8(m + 0x10, &d, (func_00382498(0x14, 0x1B) * 5 + 2) / 6, D_L12_001DEFF8, k, 0x4F, 0, 1,
                                  404250.0f, 441000.03f, 0.0f);
            if (p2 != 0) {
                p2[2] = *D_L12_00220DD8.p170;
            }
            ang = func_0038DAB8(ang, 0.06346652f);
        }
    }
    if (*(s32 *)(v + 0x24) == 0x36 && D_L12_001DEFD4 != 0) {
        ang = func_00382538();
        if (func_L01_003FB640(m + 0x10, 1.0f, 0x14, (void *)D_001A71A0[0]) != 0) {
            a = D_L12_001EA780[0];
            b = D_L12_001EA780[-2];
        } else {
            func_00382580(&a, 1.0f, 1.0f);
            b = *(vu0_v4 *)(m + 0x10);
        }
        func_0038CF68(&a, &a, 0.05f);
        vec_add_ba(&b, &b, &a);
        func_0038CF68(&a, &a, 1.0f);
        vec_sub_ba(&c, &D_L12_001E2780[D_001D52F0], m + 0x10);
        func_0038CE90(&d, &c, &a);
        func_0038CF68(&d, &d, 1.0f);
        if (D_L12_001DEFFC != 0) {
            for (i4 = 0; i4 < 100; i4++) {
                s32 k = (s32)func_L01_00443A18(2.0f, 5.0f);
                func_0038D890(&g, &d, &a, ang);
                func_0038CF68(&g, &g, func_003824E0(5.0f, 9.0f) * 0.020000001f * 1.75f);
                g.z *= 0.25f;
                if (i4 % 3 == 0) {
                    p3 = func_L01_004713C8(&b, &g, (func_00382498(0x14, 0x1B) * 5 + 2) / 6, D_L12_001DEFF8, k, 0x4F, 0, 1,
                                          404250.0f, 441000.03f, 0.0f);
                    if (p3 != 0) {
                        p3[2] = *D_L12_00220DD8.p170;
                    }
                }
                ang = func_0038DAB8(ang, 0.06346652f);
            }
        } else {
            for (i5 = 0; i5 < 100; i5++) {
                s32 k = (s32)func_L01_00443A18(2.0f, 5.0f);
                func_0038D890(&g, &d, &a, ang);
                func_0038CF68(&g, &g, 0.52500004f);
                g.z *= 0.25f;
                p4 = func_L01_004713C8(&b, &g, (func_00382498(0x14, 0x1B) * 5 + 2) / 6, D_L12_001DEFF8, k, 0x4F, 0, 1,
                                      404250.0f, 441000.03f, 0.0f);
                if (p4 != 0) {
                    p4[2] = *D_L12_00220DD8.p170;
                }
                ang = func_0038DAB8(ang, 0.06346652f);
            }
        }
    }
    func_0038CAD0(v + 0x34);
    func_L01_00404A10(func_L12_003D6C70, m);
    } else {
        func_003C2880(m);
    }
}
/* localdecomp:end func_L12_003D63D8 */

INCLUDE_ASM("asm/levels", func_L12_003D6C70);

INCLUDE_ASM("asm/levels", func_L12_003D6FC0);
