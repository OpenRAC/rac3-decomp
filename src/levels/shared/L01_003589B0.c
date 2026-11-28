#include "common.h"

/* localdecomp:start func_L01_003589B0 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

typedef struct {
    Vec4 v;
    u8 *o;
    s32 pad14;
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[20];
} S_357DC0;

extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_L01_00446760(S_357DC0 *s, u8 *o, s32 a, Vec4 *v, f32 f);
extern s32 func_003D3CB0(s32 a, s32 b, s32 c, u8 *o, S_357DC0 *s);
extern u8 D_001A4BE0[];

s32 func_L01_003589B0(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f12, f32 f13) {
    Vec4 v;
    S_357DC0 s;
    u8 *b;
    u8 *p;
    s32 r;

    if (*(u16 *)(a0 + 52) & 0x100) {
        v.q = *(u128_t *)(a0 + 192);
    } else {
        v.f[0] = func_0038D098(*(f32 *)(a0 + 248));
        v.f[1] = func_0038D0B0(*(f32 *)(a0 + 248));
        v.f[2] = 0.0f;
    }
    func_0038CE20(v.f, v.f, f13);
    v.f[2] = 1.0f;
    v.f[3] = 5627.9248046875f;
    func_L01_00446760(&s, a0, a3, &v, f12);
    b = D_001A4BE0;
    s.b18 = a4;
    s.b19 = a5;
    s.h1A = *(u16 *)(a0 + 170);
    s.o = a0;
    *(s32 *)(*(u8 **)(b + 9664) + 152) = 0;
    r = func_003D3CB0(a1, a2, a6, a0, &s);
    p = *(u8 **)(b + 9664);
    *(s32 *)(p + 152) = *(s32 *)(*(u8 **)(p + 36) + 16);
    return r;
}
/* localdecomp:end func_L01_003589B0 */

/* localdecomp:start func_L01_00358B00 */
#include "vu0.h"

typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[0x6A];
    f32 f6C;
    u8 pad70[0x80];
} Row_00358B00;
typedef struct {
    u8 pad[0x24];
    u8 *p24;
} T_00358B00;
typedef struct {
    u8 pad[0x18];
    T_00358B00 *p18;
} D_00358B00;

extern u8 D_0014263F[];
extern u8 D_001425C0[];
extern Row_00358B00 D_L01_002C5600_00358B00[];
extern Vec4 D_L01_00284310[];
extern Vec4 D_L01_00284320_00358B00[];
typedef struct {
    u8 p0[0x80];
    Vec4 v80;
    u8 p90[0x128];
    s32 f1B8;
    u8 p1BC[0x2408];
    s32 f25C4;
    u8 p25C8[0x25];
    u8 b25ED;
} H_00358B00;
extern H_00358B00 D_001A4BE0_00358B00;
__asm__(".extern D_001A4BE0_00358B00, 16");
extern u8 *D_L01_001E1A20_00358B00[2];
extern u8 *D_L01_001E1A24_00358B00[2];
extern s32 D_L01_001E1A20;
extern u8 *D_L01_001E1A24;
__asm__(".extern D_L01_001E1A24, 16");
extern u8 *D_L01_001E1A3C_00358B00[1];
extern u8 *D_L01_001E1A40_00358B00[1];
extern u8 D_L01_001E1A60_00358B00[8];
extern Vec4 D_L01_001EAA20[];
extern D_00358B00 D_L01_001EAA00[];
extern u8 D_L01_002B2B00[];
extern u8 *D_L01_00221098[];
extern u8 D_L01_001D66B0[8];
extern s32 D_L01_001DD658;
extern f32 D_L01_001DD650;
extern s32 D_L01_001DD688;
extern s32 D_L01_001DD68C;
__asm__(".extern D_L01_001DD658, 4");
__asm__(".extern D_L01_001DD650, 4");
__asm__(".extern D_L01_001DD688, 4");
__asm__(".extern D_L01_001DD68C, 4");

extern s32 func_0013D3E0(void);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2F58(s32, s32, void *);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_00358338(void *, void *, s32, void *, s32, s32);
extern s32 func_L01_003589B0(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f12, f32 f13);
extern void func_L01_003586F8(f32 *);
extern void func_L01_0035AC28(s32, f32 *, Vec4 *, Vec4 *);
extern s32 func_L01_003F2058(void *, void *);
extern void func_L01_003F2278(s32, void *);
extern void func_L01_00404808(void *, void *);
extern void func_L01_0044FD88(void *, void *, s32, s32);
extern void func_L01_004C7D98(void *, void *);
extern u8 *func_L01_004669B0(f32, f32, f32, f32, void *, s32, void *, u32, s32);
extern void func_L01_00466F50(void *, void *, s32, f32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_004739D8(void *, void *, s32, f32, s32, s16, s32);
extern void func_L01_00359E10(u8 *);

void func_L01_00358B00(u8 *a0) {
    Vec4 v0, v10, v20, v30, v40;
    s32 i = 1, t, ta, tb, col, n;
    u8 *q = *(u8 **)(a0 + 0x68);
    s32 k = D_L01_002C5600_00358B00[D_0014263F[0]].b1;
    u8 *obj;
    s32 particle_col;
    u8 **p;
    s32 nin = 19;
    s32 one = 1;
    s32 lim = -1;
    s32 zero = 0;
    s32 C;
    Vec4 *w;
    f32 *e;
    f32 *e2;
    D_00358B00 *d;
    Vec4 *p60;

    for (; i < 10; i++) {
        s32 skip = 0;
        if (D_L01_001DD658 != 0 && D_001A4BE0_00358B00.f25C4 == nin) {
            skip = zero; if (i <= lim) skip = one;
        }
        if (*(f32 *)(q + 0x14) >= D_L01_001DD650 && skip == 0) {
            v0.q = D_L01_00284320_00358B00[i].q;
            func_L01_00358338(D_L01_001E1A24_00358B00[i - 2], D_L01_001E1A24_00358B00[i - 1], 0, &v0, i, D_L01_001E1A20);
        } else {
            func_L01_0044FD88(D_L01_001E1A24_00358B00[i - 2], D_L01_001E1A24_00358B00[i - 1], 0, 0);
        }
    }
    {
    s32 j2, j3;
    if ((D_001A4BE0_00358B00.f25C4 == 19 && D_001A4BE0_00358B00.f1B8 >= 6) ||
        (D_001A4BE0_00358B00.f25C4 == 20 && D_001A4BE0_00358B00.f1B8 >= 18) ||
        *(s32 *)(q + 0x20) != 0) {
        w = D_L01_001EAA20;
        d = (D_00358B00 *)((u8 *)w - 0x20);
        p60 = (Vec4 *)D_L01_001E1A60_00358B00;
        for (j2 = 1; j2 < 10; j2++) {
            col = 0x10000;
            if ((k == 0 || k == 1)) {
                col = 0x110000;
            } else if (k == 2 || k == 3) {
                col = 0x210000;
            } else if (k >= 4) {
                col = 0x210000;
            }
            func_003C2F58((s32)D_L01_001E1A20_00358B00[j2 - 1], 0, &v0);
            func_003C2F58((s32)D_L01_001E1A20_00358B00[j2], 1, &v10);
            if (D_L01_001E1A24 != 0 && (D_L01_001E1A24[0x34] ^ 1) & 1) {
                if (j2 == 8) {
                    func_003C2F58((s32)D_L01_001E1A3C_00358B00[0], 0, &v20);
                    func_003C2F58((s32)D_L01_001E1A40_00358B00[0], 1, &v30);
                    vec_sub_ab(&v40, &v30, &v20);
                    func_0038CE20(v40.f, &v40, 1.5f);
                    vec_add_ab(&v30, &v40, &v20);
                    func_L01_003589B0(a0, (s32)&v20, (s32)&v30, col, 1, 3, 0, (D_L01_002C5600_00358B00 + D_001425C0[0x7F])->f6C, 0.75f);
                }
                if (func_L01_003589B0(a0, (s32)&v0, (s32)&v10, col, 1, 3, 0, (D_L01_002C5600_00358B00 + D_001425C0[0x7F])->f6C, 0.75f)) {
                    p60->q = w[0].q;
                    v20.q = w[2].q;
                    e = v30.f;
                    for (n = 0; n < 10; n++) {
                        func_0038CDF8(v30.f, ((Vec4 *)((u8 *)D_L01_001E1A24_00358B00 + 0x3c)), (Vec4 *)((u8 *)D_L01_001EAA00 + 0x20), func_003824E0(0.0f, 1.0f));
                        func_L01_003586F8(v30.f);
                    }
                    func_0038CDF8(e, p60, w, func_003824E0(0.0f, 1.0f));
                    if (!(d->p18 != 0 && d->p18->p24 != 0 && d->p18->p24[0x46] == 5)) {
                        func_L01_0035AC28((s32)a0, e, &v20, (Vec4 *)D_L01_001D66B0);
                    }
                    func_003A52A0(6, 0, a0);
                    if (*(s32 *)(q + 0x20) == 0) {
                        *(s32 *)(q + 0x2C) = func_L01_003F2058(D_L01_002B2B00, 0);
                    }
                }
            }
        }
    }
    if (D_001A4BE0_00358B00.b25ED == 0 && D_L01_001E1A24 != 0 && (D_L01_001E1A24[0x34] ^ 1) & 1) {
        s32 m;
        m = 0;
        func_L01_004C7D98(&D_001A4BE0_00358B00.v80, &v0);
        if ((k == 0 || k == 1)) {
            C = k < 4;
        } else if (k == 2 || k == 3) {
            C = k < 4;
            m = 1;
        } else {
            m = (k < 4) ^ 1;
            C = k < 4;
        }
        for (j3 = 2; j3 < 10; j3++) {
            if (D_001A4BE0_00358B00.f25C4 == 19 || D_001A4BE0_00358B00.f25C4 == 20 || *(s32 *)(q + 0x20) != 0) {
                for (t = 0; t < 8; t++) {
                    s32 six = 6;
                    obj = 0;
                    if (C) {
                        func_0038CDF8(&v10, &D_L01_00284310[j3], &D_L01_00284320_00358B00[j3], func_003824E0(0.0f, 1.0f));
                        if ((k == 0 || k == 1)) {
                            obj = func_L01_004713C8(&v10, D_L01_001D66B0, (func_00382498(2, 3) * 5 + 2) / six, func_00382498(0x40, 0x64) | 0x5F404000, 1, 0x4F, 0, 42000.0f, 63000.004f, 0.0f, 1);
                        } else if (k == 2 || k == 3) {
                            obj = func_L01_004713C8(&v10, D_L01_001D66B0, (func_00382498(2, 3) * 5 + 2) / six, 0x5FC8C8C8, 1, 0x4F, 0, 52500.0f, 73500.0f, 0.0f, 1);
                        }
                    }
                    if (obj != 0) {
                        obj[2] = D_L01_00221098[91][m];
                        if (k >= 2) {
                            obj[3] = func_00382468(4) ? 0x48 : 0x44;
                        }
                    }
                    if (!C) {
                        func_0038CDF8(&v10, &D_L01_00284310[j3], &D_L01_00284320_00358B00[j3], func_003824E0(0.0f, 1.0f));
                        obj = func_L01_004713C8(&v10, D_L01_001D66B0, (func_00382498(2, 3) * 5 + 2) / 6, 0, (s32)func_L01_00443A18(2.0f, 3.0f), 0x7F, 0x7F, func_003824E0(0.4f, 0.7f) * 210000.0f, 6300.0f, 0.0f, 6);
                        if (obj != 0) {
                            obj[3] = 0x44;
                            obj[2] = *D_L01_00221098[53];
                        }
                        obj = func_L01_004713C8(&v10, D_L01_001D66B0, (func_00382498(2, 3) * 5 + 2) / 6, 0x7C0030, (s32)func_L01_00443A18(2.0f, 3.0f), 0x30, 0x30, func_003824E0(0.4f, 0.7f) * 210000.0f * 1.3f, 12600.0f, 0.0f, 0);
                        if (obj != 0) {
                            obj[3] = 0x44;
                            obj[2] = *D_L01_00221098[53];
                        }
                    }
                }
                for (ta = 0; ta < 2; ++ta) {
                    func_0038CDF8(&v10, &D_L01_00284310[j3], &D_L01_00284320_00358B00[j3], func_003824E0(0.0f, 1.0f));
                    func_0038CF68(&v0, &v0, func_003824E0(0.0025f, 0.01f));
                    if ((k == 0 || k == 1)) {
                        if (func_0013D3E0() % 100 == 0) {
                            func_L01_00466F50(&v10, &v0, 0, -1.0f, 0.0f);
                        }
                    } else if (k == 2 || k == 3) {
                        if (func_0013D3E0() % 200 == 0) {
                            func_L01_004739D8(&v10, &v0, (func_00382498(0x40, 0x64) << 16) | 0x64004040, func_003824E0(0.1f, 0.2f) * 210000.0f, 0xFF0A0A, (s16)((func_00382498(0x78, 0xF0) * 5 + 2) / 6), 0);
                        }
                    } else if (!C) {
                        if (func_0013D3E0() % 200 == 0) {
                            func_L01_004739D8(&v10, &v0, (func_00382498(0x40, 0x64) << 16) | 0x64004040, func_003824E0(0.1f, 0.2f) * 210000.0f, 0xFF0A0A, (s16)((func_00382498(0x78, 0xF0) * 5 + 2) / 6), 0);
                        }
                    }
                }
            } else {
                if (*(s32 *)(q + 0x2C) >= 0) {
                    func_L01_003F2278(*(s32 *)(q + 0x2C), 0);
                    *(s32 *)(q + 0x2C) = -1;
                }
                for (tb = 0; tb < 2; tb++) {
                    f32 fa, fb;
                    particle_col = func_00382498(0x40, 0x64) | 0x5F404000;
                    fa = 0.1f;
                    fb = 0.22f;
                    if (!C) {
                        particle_col = 0x3F804020;
                        fa = 0.11f;
                        fb = 0.2f;
                    }
                    if (tb == 0 && !C) {
                        func_0038CDF8(&v10, &D_L01_00284310[j3], &D_L01_00284320_00358B00[j3], func_003824E0(0.0f, 1.0f));
                        obj = func_L01_004713C8(&v10, D_L01_001D66B0, (func_00382498(6, 12) * 5 + 2) / 6, particle_col, 1, 0x3F, 0, fa * 210000.0f, fb * 210000.0f, 0.0f, 1);
                        if (obj != 0) {
                            obj[2] = D_L01_00221098[104][func_00382498(0, 3)];
                        }
                    } else {
                        func_0038CDF8(&v10, &D_L01_00284310[j3], &D_L01_00284320_00358B00[j3], func_003824E0(0.0f, 1.0f));
                        obj = func_L01_004713C8(&v10, D_L01_001D66B0, (func_00382498(6, 12) * 5 + 2) / 6, particle_col, 1, 0x3F, 0, fa * 210000.0f, fb * 210000.0f, 0.0f, 1);
                        if (obj != 0) {
                            obj[2] = D_L01_00221098[91][m];
                        }
                    }
                    if (!C) {
                        func_0038CDF8(&v10, &D_L01_00284310[j3], &D_L01_00284320_00358B00[j3], func_003824E0(0.0f, 1.0f));
                        obj = func_L01_004713C8(&v10, D_L01_001D66B0, 7, 0, (s32)func_L01_00443A18(2.0f, 3.0f), 0x7F, 0x7F, func_003824E0(0.25f, 0.35f) * 210000.0f, 2100.0f, 0.0f, 6);
                        if (obj != 0) {
                            obj[3] = 0x44;
                            obj[2] = D_L01_00221098[D_L01_001DD688][D_L01_001DD68C];
                        }
                        obj = func_L01_004713C8(&v10, D_L01_001D66B0, 7, 0x7C0030, (s32)func_L01_00443A18(2.0f, 3.0f), 0x30, 0, func_003824E0(0.25f, 0.35f) * 210000.0f * 1.1f, 4200.0f, 0.0f, 0);
                        if (obj != 0) {
                            obj[3] = 0x44;
                            obj[2] = D_L01_00221098[D_L01_001DD688][D_L01_001DD68C];
                        }
                    }
                    if (tb == 0 && k != 4) {
                        func_0038CF68(&v0, &v0, func_003824E0(0.0025f, 0.01f));
                        if ((k == 0 || k == 1)) {
                            n = func_00382468(5) + 1;
                            obj = func_L01_004669B0(0.0f, 0.99f, 0.995f, func_003824E0(0.1f, 0.2f) * 210000.0f, &v10, n, &v0, func_00382498(0x46, 0x96) | 0x404000, 2);
                        } else if (k == 2 || k == 3) {
                            n = func_00382468(5) + 1;
                            obj = func_L01_004669B0(0.0f, 0.99f, 0.995f, func_003824E0(0.1f, 0.2f) * 210000.0f, &v10, n, &v0, 0x606060, 2);
                            if (obj != 0) {
                                obj[2] = D_L01_00221098[91][m];
                            }
                        } else if (!C) {
                            n = func_00382468(5) + 1;
                            obj = func_L01_004669B0(0.0f, 0.99f, 0.995f, func_003824E0(0.1f, 0.2f) * 210000.0f, &v10, n, &v0, 0x606060, 2);
                            if (obj != 0) {
                                obj[2] = D_L01_00221098[91][m];
                            }
                        }
                        if (obj != 0) {
                            obj[3] = func_00382468(3) ? 0x48 : 0x44;
                        }
                    }
                    func_0038CF68(&v0, &v0, func_003824E0(0.0025f, 0.01f));
                    if ((k == 0 || k == 1)) {
                        if (func_0013D3E0() % 100 == 0) {
                            func_L01_00466F50(&v10, &v0, 0, -1.0f, 0.0f);
                        }
                    } else if (k == 2 || k == 3) {
                        if (func_0013D3E0() % 200 == 0) {
                            func_L01_004739D8(&v10, &v0, (func_00382498(0x40, 0x64) << 16) | 0x64004040, func_003824E0(0.1f, 0.2f) * 210000.0f, 0xFF4646, (s16)((func_00382498(0x78, 0xF0) * 5 + 2) / 6), 1);
                        }
                    } else if (!C) {
                        if (func_0013D3E0() % 200 == 0) {
                            func_L01_004739D8(&v10, &v0, (func_00382498(0x40, 0x64) << 16) | 0x64004040, func_003824E0(0.1f, 0.2f) * 210000.0f, 0xFF4646, (s16)((func_00382498(0x78, 0xF0) * 5 + 2) / 6), 1);
                        }
                    }
                }
            }
        }
        func_L01_00404808(func_L01_00359E10, a0);
    }
    }
}
/* localdecomp:end func_L01_00358B00 */

LINKER_REMNANT("asm/levels", func_L01_00359E08);

/* localdecomp:start func_L01_00359E10 */
extern u8 D_0014263F[];
typedef struct { u8 b0, b1; u8 pad[0xEE]; } R240_00359E10;
extern R240_00359E10 D_L01_002C5600[];
extern s32 D_L01_001E1A20;
extern s32 *D_L01_001E1A20_00359E10[2];
typedef struct { f32 x, y, z, w; } V4_359E10;
typedef union { u8 b[0x2600]; s32 i[0x980]; } H_359E10;
extern H_359E10 D_001A4BE0_00359E10;
extern V4_359E10 D_L01_00284460[];
extern u8 D_L01_00284320[];
extern f32 func_003824E0(f32, f32);
extern void func_003C2F58(s32, s32, void *);
extern void func_L01_0035B0A0(u8 *);
extern void func_L01_0035A6B0(u8 *, void *, void *);
extern void func_L01_0035A218(u8 *, s32, s32, s32, s32, s32, f32, f32);

void func_L01_00359E10(u8 *a0) {
    f32 v0[4] __attribute__((aligned(16)));
    f32 v1[4] __attribute__((aligned(16)));
    u8 *o;
    s32 t;
    s32 i, j, k;
    s32 c1;
    s32 c2;
    s32 c3;
    f32 f, g;
    f32 hi, lo;
    f32 h;
    s32 **pp;

    func_L01_0035B0A0(a0);
    o = *(u8 **)(a0 + 104);
    h = *(f32 *)(o + 16) + 0.1f;
    t = ((R240_00359E10 *)(D_0014263F[0] * sizeof(R240_00359E10) + (s32)D_L01_002C5600))->b1;
    *(f32 *)(o + 16) = h;
    if (h >= 4.0f) {
        *(f32 *)(o + 16) = h - 4.0f;
    }
    pp = (s32 **)D_L01_001E1A20_00359E10;
    for (i = 1; i < 10; i++) {
        func_003C2F58((s32)pp[i - 1], 0, v0);
        func_003C2F58((s32)pp[i], 1, v1);
        func_L01_0035A6B0(a0, v0, v1);
    }
    for (j = 0; j < 10; j++) {
        ((u128_t *)D_L01_00284460)[j] = ((u128_t *)D_L01_00284320)[j];
    }
    f = func_003824E0(0.03f, 0.05f);
    g = func_003824E0(3.0f, 5.0f);
    if ((u32)(D_001A4BE0_00359E10.i[0x25C4 / 4] - 0x13) < 2 || *(s32 *)(o + 32) != 0) {
        f = func_003824E0(0.01f, 0.03f);
        g = func_003824E0(3.0f, 5.0f);
    }
    func_003C2F58(D_L01_001E1A20, 0, (void *)D_L01_00284460);
    c1 = 0;
    c2 = 0;
    if (t < 2) {
        c1 = 0x7F7F7F;
        c2 = 0x2020FF;
    } else if ((u32)(t - 2) < 2) {
        c1 = 0x7F7F7F;
        c2 = 0xFF8040;
    } else if (t >= 4) {
        c1 = 0xFF0000;
        c2 = 0xFF1010;
    }
    func_L01_0035A218((u8 *)D_L01_00284460, 9, 0x4F, c1, c2, 0, f, g);
    if (t >= 3) {
        c3 = 0x2020FF;
        if (t >= 4) {
            c3 = 0xFF2020;
        }
        hi = 0.12f;
        if ((u32)(D_001A4BE0_00359E10.i[0x25C4 / 4] - 0x13) < 2 || *(s32 *)(o + 32) != 0) {
            hi = 0.15f;
        }
        lo = -hi;
        for (k = 0; k < 10; k++) {
            D_L01_00284460[k].x += func_003824E0(lo, hi);
            D_L01_00284460[k].y += func_003824E0(lo, hi);
            D_L01_00284460[k].z += func_003824E0(lo, hi);
        }
        func_L01_0035A218((u8 *)D_L01_00284460, 9, 0x4F, 0x7F7F7F, c3, 0, 0.032f, 1.2f);
    }
}
/* localdecomp:end func_L01_00359E10 */

/* localdecomp:start func_L01_0035A190 */
void func_L01_0035A190(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0035A190 */

/* localdecomp:start func_L01_0035A218 */
#include "vu0.h"
typedef struct {
    Vec4 v[4];
    s32 col[4];
    f32 uv[4][2];
    long f70, f78, f80, f88;
} S_35A218;

extern u8 D_L01_001E29C0_0035A218[];
extern s32 D_L01_001DD690;
extern s32 D_L01_001DD694;
__asm__(".extern D_L01_001DD690, 4");
__asm__(".extern D_L01_001DD694, 4");
extern long func_00389598(s32);
extern void func_L01_0035A190_0035A218(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0();

void func_L01_0035A218(u8 *a0, s32 n, s32 a2, s32 a3, s32 a4, s32 a5, f32 f12, f32 f13) {
    Vec4 v0, v1, v2, v3;
    S_35A218 A;
    S_35A218 B;
    Vec4 q0, q1;
    s32 i;
    f32 x, y;

    A.f78 = func_00389598(D_L01_001DD690);
    A.f80 = 0xFF9000000260;
    A.f88 = ((long)a2 << 32) | 0x68;
    A.col[3] = a3;
    A.col[2] = a3;
    A.col[1] = a3;
    A.col[0] = a3;
    A.f70 = 0;
    func_L01_0035A190_0035A218(&A);
    A.uv[0][0] = 0.0f;
    A.uv[0][1] = 0.0f;
    A.uv[1][0] = 0.0f;
    A.uv[1][1] = 1.0f;
    A.uv[2][0] = 1.0f;
    A.uv[2][1] = 0.0f;
    A.uv[3][0] = 1.0f;
    A.uv[3][1] = 1.0f;
    B.f78 = func_00389598(D_L01_001DD690);
    B.f80 = 0xFF9000000260;
    B.col[3] = a4;
    B.col[2] = a4;
    B.col[1] = a4;
    B.col[0] = a4;
    B.f70 = 0;
    B.f88 = ((long)(a2 / 3) << 32) | 0x68;
    func_L01_0035A190_0035A218(&B);
    q0.q = 0;
    q1.q = 0;
    B.uv[0][0] = 0.0f;
    B.uv[0][1] = 0.0f;
    B.uv[1][0] = 0.0f;
    B.uv[1][1] = 1.0f;
    B.uv[2][0] = 0.33f;
    B.uv[2][1] = 0.0f;
    B.uv[3][0] = 0.33f;
    B.uv[3][1] = 1.0f;
    q0.f[3] = 1.0f;
    q1.f[3] = 1.0f;
    q0.f[2] = f12;
    q1.f[2] = f12 * f13;
    vec_sub_ba(&v0, a0 + 16, a0);
    func_0038CF68(&v0, &v0, 1.0f);
    vec_sub_ba(&v1, D_L01_001E29C0_0035A218, a0);
    func_0038CE90(&v2, &v1, &v0);
    func_0038CF68(&v2, &v2, 1.0f);
    func_0038CE90(&v1, &v0, &v2);
    A.v[0].q = q0.q;
    v3.q = *(u128_t *)a0;
    func_0038CE20(A.v[1].f, &A.v[0], -1.0f);
    func_0038D028(&A.v[0], &A.v[0], &v0);
    func_0038D028(&A.v[1], &A.v[1], &v0);
    B.v[0].q = q1.q;
    func_0038CE20(B.v[1].f, &B.v[0], -1.0f);
    func_0038D028(&B.v[0], &B.v[0], &v0);
    func_0038D028(&B.v[1], &B.v[1], &v0);
    for (i = 1; i < n; i++) {
        A.v[2].q = q0.q;
        func_0038CE20(A.v[3].f, &A.v[2], -1.0f);
        B.v[2].q = q1.q;
        func_0038CE20(B.v[3].f, &B.v[2], -1.0f);
        vec_sub_ab(&v0, a0 + i * 16 + 16, a0 + i * 16);
        func_0038CF68(&v0, &v0, 1.0f);
        vec_sub_ab(&v1, D_L01_001E29C0_0035A218, a0 + i * 16);
        func_0038CE90(&v2, &v1, &v0);
        func_0038CF68(&v2, &v2, 1.0f);
        func_0038CE90(&v1, &v0, &v2);
        v3.q = *(u128_t *)(a0 + i * 16);
        func_0038D028(&A.v[2], &A.v[2], &v0);
        func_0038D028(&A.v[3], &A.v[3], &v0);
        func_0038D028(&B.v[2], &B.v[2], &v0);
        func_0038D028(&B.v[3], &B.v[3], &v0);
        if (i == n - 1) {
            A.col[2] = 0;
            A.col[3] = 0;
            B.col[2] = 0;
            B.col[3] = 0;
        }
        A.f78 = func_00389598(D_L01_001DD694);
        A.f88 = ((long)a2 << 32) | 0x68;
        A.f78 = func_00389598(0x2B);
        func_003D2DA0(&A, 0, 0);
        func_003D2DA0(&B, 0, 0);
        x = i * 0.33f;
        y = x + 0.33f;
        if (x >= 1.0f) {
            x -= 1.0f;
            y -= 1.0f;
        }
        B.uv[0][0] = x;
        B.uv[2][0] = y;
        B.uv[1][0] = x;
        B.uv[3][0] = y;
        A.v[0].q = A.v[2].q;
        A.v[1].q = A.v[3].q;
        B.v[0].q = B.v[2].q;
        B.v[1].q = B.v[3].q;
    }
}
/* localdecomp:end func_L01_0035A218 */

/* localdecomp:start func_L01_0035A6B0 */
typedef struct { f32 u, v; } UV_0035A6B0;
typedef struct { vu0_v4 p[4]; s32 c[4]; UV_0035A6B0 uv[4]; u8 p70[0x20]; } Q_0035A6B0;
typedef struct { u8 p0[0x10]; f32 f10; } S_0035A6B0;
extern u8 D_0014263F[];
extern R240_00359E10 D_L01_002C5600[];
extern H_359E10 D_001A4BE0_00359E10;
extern u8 D_L01_001E29C0_0035A6B0[];
extern s32 D_L01_001DD698;
extern s32 D_L01_001DD69C;
extern f32 D_L01_001DD6A0;
extern f32 D_L01_001DD6A4;
extern s32 D_L01_001DD6A8;
__asm__(".extern D_L01_001DD698, 4");
__asm__(".extern D_L01_001DD69C, 4");
__asm__(".extern D_L01_001DD6A0, 4");
__asm__(".extern D_L01_001DD6A4, 4");
__asm__(".extern D_L01_001DD6A8, 4");
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0();

void func_L01_0035A6B0(u8 *o, void *pa, void *pb) {
    extern void func_003D93B0(void *, s32, s32, s32);
    vu0_v4 ca;
    vu0_v4 cb;
    vu0_v4 *a;
    vu0_v4 *b;
    Q_0035A6B0 q;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 d;
    vu0_v4 t;
    vu0_v4 u;
    S_0035A6B0 *s;
    R240_00359E10 *ent;
    s32 b1;
    s32 small;
    s16 flag;
    s32 i;
    f32 w;

    ent = &D_L01_002C5600[D_0014263F[0]];
    ca = *(vu0_v4 *)pa;
    a = &ca;
    cb = *(vu0_v4 *)pb;
    b = &cb;
    s = *(S_0035A6B0 **)(o + 0x68);
    b1 = ent->b1;
    if ((u32)(D_001A4BE0_00359E10.i[0x25C4 / 4] - 0x13) >= 2) {
        if (!(small = (b1 < 4))) {
            w = 0.06f;
            goto wdone;
        }
    } else {
        if (!(small = (b1 < 4))) {
            w = 0.09f;
            goto wdone;
        }
    }
    w = 0.12f;
wdone:
    D_L01_001DD6A4 = D_L01_001DD6A0 = w;
    if (b1 == 0 || b1 == 1) {
        D_L01_001DD698 = 0x5F204080;
        D_L01_001DD69C = 0x5F202080;
    } else if (b1 == 2 || b1 == 3) {
        D_L01_001DD69C = D_L01_001DD698 = 0x5F804020;
    } else if (!small) {
        D_L01_001DD69C = D_L01_001DD698 = 0x7F000000;
    }
    flag = small;
    func_003D93B0(&q, D_L01_001DD6A8, small, 0x80);
    q.c[3] = D_L01_001DD698;
    q.c[2] = D_L01_001DD698;
    q.c[1] = D_L01_001DD698;
    q.c[0] = D_L01_001DD698;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    for (i = 0; i < 4; i++) {
        q.uv[i].u -= s->f10;
        if (q.uv[i].u <= 7.0f) {
            q.uv[i].u += 7.0f;
        }
    }
    vec_sub_ba(&d, a, b);
    func_0038CF68(&d, &d, 1.0f);
    vec_sub_ba(&e, a, D_L01_001E29C0_0035A6B0);
    vec_sub_ba(&f, b, D_L01_001E29C0_0035A6B0);
    func_0038CE90(&e, &e, &d);
    func_0038CF68(&e, &e, D_L01_001DD6A0);
    func_0038CE90(&f, &f, &d);
    func_0038CF68(&f, &f, D_L01_001DD6A4);
    vec_sub_ba(&u, a, &e);
    t = u;
    q.p[0] = t;
    vec_add_ba(&u, a, &e);
    t = u;
    q.p[1] = t;
    vec_sub_ba(&u, b, &f);
    t = u;
    q.p[2] = t;
    vec_add_ba(&u, b, &f);
    t = u;
    q.p[3] = t;
    func_003D2DA0(&q, 0, 0);

    func_003D93B0(&q, 0xE, flag, 0x80);
    q.c[3] = D_L01_001DD69C;
    q.c[2] = D_L01_001DD69C;
    q.c[1] = D_L01_001DD69C;
    q.c[0] = D_L01_001DD69C;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    for (i = 0; i < 4; i++) {
        q.uv[i].u -= s->f10;
        if (q.uv[i].u <= 7.0f) {
            q.uv[i].u += 7.0f;
        }
    }
    vec_sub_ba(&d, a, b);
    func_0038CF68(&d, &d, 1.0f);
    vec_sub_ba(&e, a, D_L01_001E29C0_0035A6B0);
    vec_sub_ba(&f, b, D_L01_001E29C0_0035A6B0);
    func_0038CE90(&e, &e, &d);
    func_0038CF68(&e, &e, D_L01_001DD6A0 * 0.5f);
    func_0038CE90(&f, &f, &d);
    func_0038CF68(&f, &f, D_L01_001DD6A4 * 0.5f);
    vec_sub_ba(&u, a, &e);
    t = u;
    q.p[0] = t;
    vec_add_ba(&u, a, &e);
    t = u;
    q.p[1] = t;
    vec_sub_ba(&u, b, &f);
    t = u;
    q.p[2] = t;
    vec_add_ba(&u, b, &f);
    t = u;
    q.p[3] = t;
    func_003D2DA0(&q, 0, 0);
}
/* localdecomp:end func_L01_0035A6B0 */

/* localdecomp:start func_L01_0035AB50 */
/* Ported from rac2-decomp rac2-decomp/src/levels/shared/L00_003EA0E0.c:145-165. */

void func_L01_0035AB50(char *quadPacket)
{
    *(long *)(quadPacket + 112) = 0;
    *(float *)(quadPacket + 8) = -1.0f;
    *(float *)(quadPacket + 24) = 1.0f;
    *(float *)(quadPacket + 40) = -1.0f;
    *(float *)(quadPacket + 56) = 1.0f;
    *(float *)(quadPacket + 4) = -1.0f;
    *(float *)(quadPacket + 36) = 1.0f;
    *(float *)(quadPacket + 52) = 1.0f;
    *(int *)(quadPacket + 0) = 0;
    *(int *)(quadPacket + 16) = 0;
    *(int *)(quadPacket + 32) = 0;
    *(int *)(quadPacket + 48) = 0;
    *(float *)(quadPacket + 12) = 1.0f;
    *(float *)(quadPacket + 28) = 1.0f;
    *(float *)(quadPacket + 44) = 1.0f;
    *(long *)(quadPacket + 128) = 0x0000FF9000000260L;
    *(float *)(quadPacket + 20) = -1.0f;
    *(float *)(quadPacket + 60) = 1.0f;
}
/* localdecomp:end func_L01_0035AB50 */

/* localdecomp:start func_L01_0035ABB8 */
void func_L01_0035ABB8(char *packet)
{
    *(long *)(packet + 112) = 0L;
    *(int *)(packet + 8) = 0;
    *(float *)(packet + 24) = 2.0f;
    *(int *)(packet + 40) = 0;
    *(float *)(packet + 4) = -1.0f;
    *(float *)(packet + 36) = 1.0f;
    *(float *)(packet + 52) = 1.0f;
    *(int *)(packet + 0) = 0;
    *(int *)(packet + 16) = 0;
    *(int *)(packet + 32) = 0;
    *(int *)(packet + 48) = 0;
    *(float *)(packet + 12) = 1.0f;
    *(float *)(packet + 28) = 1.0f;
    *(float *)(packet + 44) = 1.0f;
    *(long *)(packet + 128) = 0x0000FF9000000260L;
    *(float *)(packet + 56) = 2.0f;
    *(float *)(packet + 20) = -1.0f;
    *(float *)(packet + 60) = 1.0f;
}
/* localdecomp:end func_L01_0035ABB8 */

/* localdecomp:start func_L01_0035AC28 */
typedef struct {
    f32 f[36];
} Pk_35AC28_0035AC28;

typedef struct {
    Vec4 a;
    Vec4 b;
    Vec4 pos[2];
    u8 pad40[0x20];
    Pk_35AC28_0035AC28 pk[8];
    s32 r[4];
    f32 vel[4];
    f32 off[4];
    s32 x510, x514, x518, x51C;
    u8 pad520[0x10];
} Rec_35AC28_0035AC28;

extern Rec_35AC28_0035AC28 D_L01_00284500_0035AC28[];
extern void func_L01_0035ABB8_0035AC28(char *packet);
extern f32 func_003824E0(f32, f32);
extern s32 func_0013D3E0(void);

void func_L01_0035AC28(s32 unused, f32 *pos, Vec4 *a, Vec4 *b) {
    int index, k;
    Rec_35AC28_0035AC28 *rec;
    Rec_35AC28_0035AC28 *base = D_L01_00284500_0035AC28;
    f32 f, g;
    char *p;

    for (index = 0; index < 25; index++) {
        rec = &base[index];
        if (rec->x514 != 0)
            continue;
        for (k = 0; k < 2; k++) {
            p = (char *)rec + k * 0x90;
            func_L01_0035ABB8_0035AC28((char *)rec + (k * 0x90 + 0x2A0));
            func_L01_0035ABB8_0035AC28((char *)rec + (k * 0x90 + 0x60));
            f = func_003824E0(0.3f, 0.5f);
            ((f32 *)(p + 0x60))[1] *= f;
            ((f32 *)(p + 0x60))[5] *= f;
            ((f32 *)(p + 0x60))[9] *= f;
            ((f32 *)(p + 0x60))[13] *= f;
            g = func_003824E0(0.2f, 1.3f);
            ((f32 *)(p + 0x60))[6] *= g;
            ((f32 *)(p + 0x60))[14] *= g;
            ((f32 *)(p + 0x60))[5] *= 0.4f;
            ((f32 *)(p + 0x60))[13] *= 0.4f;
            rec->pos[k].f[0] = pos[0] + func_003824E0(-0.1f, 0.1f);
            rec->pos[k].f[1] = pos[1] + func_003824E0(-0.1f, 0.1f);
            rec->pos[k].f[2] = pos[2];
            rec->pos[k].f[3] = 1.0f;
            rec->vel[k] = func_003824E0(-0.03f, -0.01f);
            rec->off[k] = func_003824E0(-7.99f, 0.0f);
            rec->r[k] = func_0013D3E0() % 2;
        }
        rec->x510 = 0;
        rec->x514 = 1;
        rec->x518 = 0;
        rec->x51C = 0;
        rec->b.q = b->q;
        rec->a.q = a->q;
        return;
    }
}
/* localdecomp:end func_L01_0035AC28 */

/* localdecomp:start func_L01_0035AEB8 */
extern u8 D_L01_00284500[];
extern void func_L01_004CAB30(void *, void *);
extern void func_L01_004482A0(f32 *, f32, f32 *, f32, f32, f32);
extern s32 func_0038CAD0(s32 *);

void func_L01_0035AEB8(void)
{
    int index, axis;
    char *record;
    float *position, *velocity, value, cur;

    char *base = (char *)D_L01_00284500;

    for (index = 0; index < 25; index++) {
        record = (char *)(index * 0x530 + (int)base);
        if (*(int *)(record + 0x514) != 1)
            continue;
        velocity = (float *)(record + 0x4f0);
        position = (float *)(record + 0x500);
        for (axis = 0; axis < 2; axis++) {
            func_L01_004CAB30(record + 0x20 + axis * 16, record + 0x20 + axis * 16);
            cur = position[axis];
            value = cur + velocity[axis];
            position[axis] = value;
            if (value <= -8.0f)
                position[axis] = value + 8.0f;
        }
        if (*(int *)(record + 0x518) == 0) {
            func_L01_004482A0((float *)(record + 0x510), 0.5f, (float *)(record + 0x51c), 0.0024f, 0.00024000001f, 0.024f);
            cur = *(float *)(record + 0x510);
            if (cur == 0.5f) {
                *(int *)(record + 0x518) = 2;
                *(int *)(record + 0x520) = 50;
            }
        } else if (*(int *)(record + 0x518) == 1) {
            func_L01_004482A0((float *)(record + 0x510), 0.0f, (float *)(record + 0x51c), 0.0024f, 0.00024000001f, 0.024f);
            cur = *(float *)(record + 0x510);
            if (cur == 0.0f)
                *(int *)(record + 0x514) = 0;
        } else if (func_0038CAD0((int *)(record + 0x520))) {
            *(int *)(record + 0x518) = 1;
        }
    }
}
/* localdecomp:end func_L01_0035AEB8 */

INCLUDE_ASM("asm/levels", func_L01_0035B0A0);

/* localdecomp:start func_L01_0035B5A0 */
typedef struct {
    f32 m[4][4];
    s32 c40, c44, c48, c4C;
    s32 x50, x54, x58;
    f32 x5C, x60;
    s32 x64;
    f32 x68, x6C;
    long x70, x78, x80, x88;
    f32 r[4][4];
    f32 rot[4];
} S_35A8A0;

extern void func_L01_0035AB50_0035B5A0(S_35A8A0 *);
extern long func_00389598(s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(f32 *);
extern void func_0038D328(f32 *, f32 *);
extern void func_003D2DA0(S_35A8A0 *, f32 *, s32);

void func_L01_0035B5A0(s32 unused, f32 *pos, f32 *dir, s32 color, f32 scale) {
    S_35A8A0 s;

    func_L01_0035AB50_0035B5A0(&s);
    s.x50 = 0;
    s.x5C = 1.0f;
    s.x60 = 1.0f;
    s.x68 = 1.0f;
    s.x6C = 1.0f;
    s.x54 = 0;
    s.x58 = 0;
    s.x64 = 0;
    s.x78 = func_00389598(11);
    s.x80 = 0xFF9000000260L;
    s.x88 = 0x8000000048L;
    s.x70 = 0;
    s.c4C = color;
    s.c48 = color;
    s.c44 = color;
    s.c40 = color;
    s.rot[3] = 0.0f;
    s.rot[2] = func_0038D160(dir[0], dir[1]);
    s.rot[1] = -func_0038D160(func_0038CED8(dir), dir[2]);
    s.rot[0] = 0.0f;
    func_0038D328(s.r[0], s.rot);
    s.r[3][3] = 1.0f;
    s.r[3][0] = pos[0];
    s.r[3][1] = pos[1];
    s.r[3][2] = pos[2];
    func_0038CE20(s.m[0], s.m[0], scale);
    func_0038CE20(s.m[1], s.m[1], scale);
    func_0038CE20(s.m[2], s.m[2], scale);
    func_0038CE20(s.m[3], s.m[3], scale);
    func_003D2DA0(&s, s.r[0], 0);
}
/* localdecomp:end func_L01_0035B5A0 */
