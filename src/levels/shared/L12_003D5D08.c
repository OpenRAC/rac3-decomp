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

/* localdecomp:start func_L12_003D5D08 */
typedef struct { f32 x, y, z, w; } V_003D5D08;
extern s32 D_001D52F0;
__asm__(".extern D_001D52F0, 16");
extern E_003D63D8 D_L12_001E2780[];
extern T_003D63D8 D_L12_00220DD8;
extern s32 D_L12_001DEFB4;
__asm__(".extern D_L12_001DEFB4, 4");
extern s32 D_L12_001DEFB8;
__asm__(".extern D_L12_001DEFB8, 4");
extern s32 D_L12_001DEFBC;
__asm__(".extern D_L12_001DEFBC, 4");
extern u32 D_L12_001DEFE4;
__asm__(".extern D_L12_001DEFE4, 4");
extern u32 D_L12_001DEFE8;
__asm__(".extern D_L12_001DEFE8, 4");
extern u32 D_L12_001DEFEC;
__asm__(".extern D_L12_001DEFEC, 4");
extern u32 D_L12_001DEFF0;
__asm__(".extern D_L12_001DEFF0, 4");
extern f32 func_L12_003D5A20(void);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
/* the same function with its int argument after the floats (EABI: the same registers) */
typedef u8 *(*Spawn_003D5D08)(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);

void func_L12_003D5D08(void *o, void *unused) {
    u8 *self = o;
    V_003D5D08 pos;
    V_003D5D08 vel;
    E_003D63D8 *p;
    f32 ang;
    f32 a;
    f32 s;
    f32 t;
    s32 n;
    s32 i;
    s32 j;
    s32 life;
    u8 *q;

    p = &D_L12_001E2780[D_001D52F0];
    ang = func_0038D160(p->x - *(f32 *)(self + 0x10), p->y - *(f32 *)(self + 0x14));
    for (i = 0; i < D_L12_001DEFB4; i++) {
        u8 *g = D_L12_00220DD8.p0;
        n = func_L01_00443A18(2.0f, 5.0f);
        pos.x = *(f32 *)(self + 0x10) + func_L12_003D5A20() * 0.1f * 1.75f;
        pos.y = *(f32 *)(self + 0x14) + func_L12_003D5A20() * 0.1f * 1.75f;
        pos.z = *(f32 *)(self + 0x18) + func_L12_003D5A20() * 0.1f * 1.75f * 0.25f;
        s = func_003824E0(0.6f, 1.0f) * 1.75f;
        t = func_003824E0(9.0f, 12.0f) * 1.75f;
        a = func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.3962634f));
        t *= 0.020000001f;
        vel.x = func_0038D098(a) * t;
        vel.y = func_0038D0B0(a) * t;
        vel.z = 0.0f;
        t = func_003824E0(0.0f, 12.0f) * 1.75f;
        vel.z = t * 0.020000001f * 0.25f;
        ((Spawn_003D5D08)func_L01_004713C8)(&pos, &vel, (func_00382498(30, 50) * 5 + 2) / 6, D_L12_001DEFE4, n, 0x7F, 0x7F,
                          s * 210000.0f, 3675.0f, 0.00584f, 1);
        n = -(n * 2);
        life = (func_00382498(30, 50) * 5 + 2) / 6;
        s *= 6.0f;
        q = ((Spawn_003D5D08)func_L01_004713C8)(&pos, &vel, life, D_L12_001DEFE8, n, 0x30, 0x30,
                              s * 210000.0f, 7350.0f, 0.00584f, 0);
        if (q != 0) {
            q[2] = (*(u8 **)(g + 0xD4))[0];
        }
    }
    for (j = 0; j < D_L12_001DEFB8; j++) {
        n = func_L01_00443A18(2.0f, 5.0f);
        pos.x = *(f32 *)(self + 0x10) + func_L12_003D5A20() * 0.1f * 1.75f;
        pos.y = *(f32 *)(self + 0x14) + func_L12_003D5A20() * 0.1f * 1.75f;
        pos.z = *(f32 *)(self + 0x18) + func_L12_003D5A20() * 0.1f * 1.75f * 0.25f;
        s = func_003824E0(0.75f, 1.5f) * 1.75f;
        t = func_003824E0(9.0f, 12.0f) * 1.75f;
        a = func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.3962634f));
        t *= 0.020000001f;
        vel.x = func_0038D098(a) * t;
        vel.y = func_0038D0B0(a) * t;
        vel.z = 0.0f;
        t = func_003824E0(0.0f, 12.0f) * 1.75f;
        vel.z = t * 0.020000001f * 0.25f;
        ((Spawn_003D5D08)func_L01_004713C8)(&pos, &vel, (func_00382498(30, 50) * 5 + 2) / 6, D_L12_001DEFEC, n, 0x7F, 0x7F,
                          s * 210000.0f, 3675.0f, 0.00584f, 5);
    }
    for (j = 0; j < D_L12_001DEFBC; j++) {
        n = func_L01_00443A18(2.0f, 5.0f);
        pos.x = *(f32 *)(self + 0x10) + func_L12_003D5A20() * 0.1f * 1.75f;
        pos.y = *(f32 *)(self + 0x14) + func_L12_003D5A20() * 0.1f * 1.75f;
        pos.z = *(f32 *)(self + 0x18) + func_L12_003D5A20() * 0.1f * 1.75f * 0.25f;
        s = func_003824E0(0.6f, 1.0f) * 1.75f;
        t = func_003824E0(9.0f, 12.0f) * 1.75f;
        a = func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.3962634f));
        t *= 0.020000001f;
        vel.x = func_0038D098(a) * t;
        vel.y = func_0038D0B0(a) * t;
        vel.z = 0.0f;
        t = func_003824E0(0.0f, 12.0f) * 1.75f;
        vel.z = t * 0.020000001f * 0.25f;
        ((Spawn_003D5D08)func_L01_004713C8)(&pos, &vel, (func_00382498(30, 50) * 5 + 2) / 6, D_L12_001DEFF0, n, 0x7F, 0x7F,
                          s * 210000.0f, 3675.0f, 0.00584f, 3);
    }
}
/* localdecomp:end func_L12_003D5D08 */

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
extern void func_L12_003D6C70(u8 *);

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

/* localdecomp:start func_L12_003D6C70 */
typedef struct {
    f32 m[4][4];
    s32 c40, c44, c48, c4C;
    s32 x50, x54, x58;
    f32 x5C, x60;
    s32 x64;
    f32 x68, x6C;
    long x70, x78, x80, x88;
    vu0_v4 axis;
    vu0_v4 r[6];
} S_3D6C70;
extern s32 D_L12_001DEFCC;
__asm__(".extern D_L12_001DEFCC, 4");
extern f32 D_L12_001DF000;
__asm__(".extern D_L12_001DF000, 4");
extern f32 D_L12_001DF004;
__asm__(".extern D_L12_001DF004, 4");
extern s32 D_L12_001DEFD0;
__asm__(".extern D_L12_001DEFD0, 4");
extern f32 D_L12_001DF008;
__asm__(".extern D_L12_001DF008, 4");
__asm__(".extern D_001D52F0, 16");
typedef struct {
    u8 pad0[0x150];
    s16 h150;
    s16 h152;
} G_3D6C70;
extern G_3D6C70 D_001CFEC0;
extern void func_003A9440(s32, u32);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern void func_L12_003D6FC0(void *, s32, f32, f32);
extern void func_003C5180(void *, void *, s32);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0(S_3D6C70 *, vu0_v4 *, s32);

void func_L12_003D6C70(u8 *o) {
    S_3D6C70 s;
    u8 *d;
    s32 n;
    s32 col;
    f32 f;
    f32 k;

    d = *(u8 **)(o + 0x68);
    if (D_L12_001DEFCC != 0) {
        if (0x32 - *(s32 *)(d + 0x24) < 2 && *(s32 *)(d + 0x34) != 0) {
            func_003A9440(0x42, 0x48);
            func_0038AF30(0, D_001CFEC0.h152, 0, D_001CFEC0.h150, (s32)0x80808080);
        }
    }
    if (*(s32 *)(d + 0x30) != 0) {
        n = 0x32 - *(s32 *)(d + 0x24);
        if (n < 10) {
            f = D_L12_001DF000 + (D_L12_001DF004 - D_L12_001DF000) * ((f32)n / 10.0f);
            func_L12_003D6FC0(o + 0x10, 0x3B, f, 0.5f);
        } else if ((u32)(*(s32 *)(d + 0x24) - 0x2E) < 4) {
            n = *(s32 *)(d + 0x24) - 0x2D;
            f = D_L12_001DF000 + (D_L12_001DF004 - D_L12_001DF000) * ((f32)n / 10.0f);
            func_L12_003D6FC0(o + 0x10, 0x3B, f, 0.5f);
        }
    }
    if (D_L12_001DEFD0 != 0) {
        if (*(s32 *)(d + 0x34) != 0) {
            func_003C5180(o + 0x10, &s.axis, 1);
            f = (f32)*(s32 *)(d + 0x34);
            f = f * D_L12_001DF008;
            func_003D93B0(&s, 0xB, 4, 0x80);
            col = ((s32)(f * 255.0f) << 24) | 0xFFFFFF;
            k = 0.075f;
            s.x50 = 0;
            s.x54 = 0;
            s.x58 = 0;
            s.x5C = 1.0f;
            s.x60 = 1.0f;
            s.c4C = col;
            s.c48 = col;
            s.c44 = col;
            s.c40 = col;
            s.x64 = 0;
            s.x68 = 1.0f;
            s.x6C = 1.0f;
            vec_sub_ab(&s.r[0], o + 0x10, &D_L12_001E2780[D_001D52F0]);
            func_0038CF68(&s.r[1], &s.r[0], 0.1f);
            vec_add_ba(&s.r[2], &D_L12_001E2780[D_001D52F0], &s.r[1]);
            func_0038CE90(&s.r[3], &s.r[0], &s.axis);
            func_0038CF68(&s.r[3], &s.r[3], k);
            func_0038CE90(&s.r[4], &s.r[3], &s.r[0]);
            func_0038CF68(&s.r[4], &s.r[4], k);
            vec_add_ab(&s.r[5], &s.r[2], &s.r[4]);
            vec_add_ab(&s.m[0], &s.r[5], &s.r[3]);
            vec_sub_ab(&s.m[1], &s.r[5], &s.r[3]);
            vec_sub_ab(&s.r[5], &s.r[2], &s.r[4]);
            vec_add_ba(&s.m[2], &s.r[5], &s.r[3]);
            vec_sub_ab(&s.m[3], &s.r[5], &s.r[3]);
            func_003D2DA0(&s, 0, 0);
        }
    }
}
/* localdecomp:end func_L12_003D6C70 */

/* localdecomp:start func_L12_003D6FC0 */
typedef struct { f32 u, v; } UV_003D6FC0;
typedef struct {
    vu0_v4 v[4];
    u32 col[4];
    UV_003D6FC0 uv[4];
    long x70, x78, x80, x88;
} Q_003D6FC0;

typedef struct { vu0_v4 pos; u8 p10[0x1C0]; vu0_v4 up; u8 p1E0[0x460 - 0x1E0]; } Cam_003D6FC0;

extern vu0_v4 D_L12_001D7B50[4];
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_00389478(void *, f32 *, f32 *);
/* func_003A9440(s32, u32) as this file declares it; its definition in frontbin takes unsigned long
 * and retail sets $a1 the 64-bit way, so the calls cast to that */
extern void func_003A9440(s32, u32);

void func_L12_003D6FC0(void *p, s32 n, f32 f, f32 g) {
    Q_003D6FC0 q;
    vu0_v4 m[4];
    vu0_v4 x;
    s32 i;
    s32 j;
    Cam_003D6FC0 *c;

    func_003D93B0(&q, n, 1, 0x80);
    q.x88 = 0x800000004A;
    m[3] = *(vu0_v4 *)p;
    q.col[3] = 0x80808080;
    q.col[2] = 0x80808080;
    q.col[1] = 0x80808080;
    q.col[0] = 0x80808080;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    vec_sub_ba(&m[0], &D_L12_001E2780[D_001D52F0], &m[3]);
    func_0038CF68(&m[0], &m[0], 1.0f);
    c = &((Cam_003D6FC0 *)D_L12_001E2780)[D_001D52F0];
    func_0038CE90(&m[1], &m[0], &c->up);
    func_0038CF68(&m[1], &m[1], 1.0f);
    func_0038CE90(&m[2], &m[1], &m[0]);
    m[0].z *= 0.25f;
    m[1].z *= 0.25f;
    m[2].z *= 0.25f;
    func_0038CE20(&x, &m[0], g);
    vec_add_ab(&m[3], &m[3], &x);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&q.v[i], &D_L12_001D7B50[i], f);
        func_0038D028(&q.v[i], &q.v[i], m);
    }
    ((void (*)(s32, unsigned long))func_003A9440)(0x47, 0x31001);
    func_003D2DA0((void *)&q, 0, 0);
    for (j = 0; j < 4; j++) {
        func_00389478(&q.v[j], &q.uv[j].u, &q.uv[j].v);
        if (q.uv[j].u > 1.0f) {
            q.uv[j].u = 1.0f;
        } else if (q.uv[j].u < 0.0f) {
            q.uv[j].u = 0.0f;
        }
        if (q.uv[j].v > 1.0f) {
            q.uv[j].v = 1.0f;
        } else if (q.uv[j].v < 0.0f) {
            q.uv[j].v = 0.0f;
        }
    }
    func_003D93B0(&q, -1, 1, 0x80);
    q.x88 = 0x8000000054;
    ((void (*)(s32, unsigned long))func_003A9440)(0x47, 0x53001);
    func_003D2DA0((void *)&q, 0, 0);
    ((void (*)(s32, unsigned long))func_003A9440)(0x47, 0x5360B);
}
/* localdecomp:end func_L12_003D6FC0 */
