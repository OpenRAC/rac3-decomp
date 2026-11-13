#include "common.h"
#include "vu0.h"

typedef struct T_0034F950 {
    u8 pad_00[0xD4];
    s32 f_D4;
    s32 f_D8;
    s32 f_DC;
} T_0034F950;
typedef struct U_0034F950 {
    u8 pad_00[0x68];
    T_0034F950 *f_68;
} U_0034F950;

/* localdecomp:start func_L36_0034E8C0 */
__asm__(".extern D_L36_001DD3C4, 4");
__asm__(".extern D_L36_001DD360, 4");
__asm__(".extern D_L36_001DD35C, 4");
__asm__(".extern D_L36_001DD3C0, 4");
__asm__(".extern D_L36_001DD3BC, 4");
__asm__(".extern D_L36_001DD3C8, 4");
__asm__(".extern D_L36_001DD364, 4");
__asm__(".extern D_L36_001DD358, 4");
__asm__(".extern D_L36_001DD3DC, 4");
__asm__(".extern D_L36_001DD424, 4");
__asm__(".extern D_L36_001DD41C, 4");
__asm__(".extern D_L36_001DD434, 4");
__asm__(".extern D_L36_001DD42C, 4");
__asm__(".extern D_L36_001DD438, 4");
__asm__(".extern D_L36_001DD430, 4");
__asm__(".extern D_L36_001DD428, 4");
__asm__(".extern D_L36_001DD37C, 4");
__asm__(".extern D_L36_001DD380, 4");
__asm__(".extern D_L36_001DD3E0, 4");
__asm__(".extern D_L36_001DD3E4, 4");
__asm__(".extern D_L36_001DD3E8, 4");
__asm__(".extern D_L36_001DD3EC, 4");
__asm__(".extern D_L36_001DD3F0, 4");
__asm__(".extern D_L36_001DD3F4, 4");
__asm__(".extern D_L36_001DD3F8, 4");
__asm__(".extern D_L36_001DD3FC, 4");
__asm__(".extern D_L36_001DD400, 4");
__asm__(".extern D_L36_001DD404, 4");
__asm__(".extern D_L36_001DD408, 4");
__asm__(".extern D_L36_001DD3D8, 4");
extern s32 D_L36_001DD3C4;
extern s32 D_L36_001DD360;
extern s32 D_L36_001DD35C;
extern f32 D_L36_001DD3C0;
extern f32 D_L36_001DD3BC;
extern s32 D_L36_001DD3C8;
extern f32 D_L36_001DD364;
extern f32 D_L36_001DD358;
extern f32 D_L36_001DD3DC;
extern f32 D_L36_001DD424;
extern f32 D_L36_001DD41C;
extern s32 D_L36_001DD434;
extern f32 D_L36_001DD42C;
extern f32 D_L36_001DD438;
extern f32 D_L36_001DD430;
extern s32 D_L36_001DD428;
extern f32 D_L36_001DD37C;
extern f32 D_L36_001DD380;
extern s32 D_L36_001DD3E0;
extern s32 D_L36_001DD3E4;
extern s32 D_L36_001DD3E8;
extern s32 D_L36_001DD3EC;
extern s32 D_L36_001DD3F0;
extern s32 D_L36_001DD3F4;
extern s32 D_L36_001DD3F8;
extern s32 D_L36_001DD3FC;
extern s32 D_L36_001DD400;
extern s32 D_L36_001DD404;
extern s32 D_L36_001DD408;
extern s32 D_L36_001DD3D8;
extern f32 D_L36_001E1870;
extern f32 D_L36_001E1874;
extern f32 D_L36_001E1878;
extern f32 D_L36_001E187C;
extern f32 D_L36_001E1880;
extern f32 D_L36_001E1884;
extern s32 D_L36_001DEEAC;
extern u8 *D_L36_001DFB28;
extern u8 *D_L36_001DFB1C;
extern u8 *D_L36_001DFC00;
extern s32 D_L36_001DF6C0;
typedef struct S_0034E8C0 {
    s32 v[4];
} S_0034E8C0;
extern S_0034E8C0 D_L36_001DD440;
typedef struct E_0034E8C0 {
    vu0_v4 f00;
    u8 pad_10[0x5C - 0x10];
    s32 f5C;
} E_0034E8C0;
typedef struct P_0034E8C0 {
    f32 f00;
    s16 f04;
    u8 pad_06[0x84 - 0x06];
    s32 f84[2];
} P_0034E8C0;
typedef struct A_0034E8C0 {
    u8 pad_00[0xC];
    f32 f0C;
    u8 pad_10[0x10];
} A_0034E8C0;
typedef struct R_0034E8C0 {
    u8 pad_00[0x40];
    A_0034E8C0 f40[1];
} R_0034E8C0;
typedef struct Q_0034E8C0 {
    u8 pad_00[0x60];
    vu0_v4 f60;
    u8 pad_70[0x78 - 0x70];
    s32 f78;
    s32 f7C;
} Q_0034E8C0;
typedef struct V_0034E8C0 {
    u8 pad_00[0x34];
    s16 f34;
    u8 pad_36[0xB0 - 0x36];
    vu0_v4 fB0;
    vu0_v4 fC0;
    s32 fD0;
    s32 fD4;
    s32 fD8;
    s32 fDC;
    u8 pad_E0[4];
    s32 fE4;
    u8 pad_E8[4];
    s32 fEC;
    s32 fF0;
    u8 pad_F4[4];
    s32 fF8;
    u8 pad_FC[4];
    u8 *f100;
    s32 f104;
    s32 f108;
    u8 pad_10C[4];
    u8 *f110;
    f32 f114;
    f32 f118;
    f32 f11C;
    f32 f120;
    u8 pad_124[4];
    u8 *f128;
    u8 pad_12C[4];
    u8 *f130;
    u8 *f134[4];
    s32 f144[4];
    s32 f154[4];
} V_0034E8C0;
extern u8 D_00142732[];
extern u8 D_001A4BE0[];
extern vu0_v4 D_001A4C60;
extern f32 D_001A4C64[];
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_00456230(void *, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004AA7E8(u8 *a0, s32 a1);
extern void func_L36_00350330(u8 *);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_0038CAD0(void *);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L31_003478E8(void *, void *, void *, f32, f32, f32, f32, f32, f32, f32, s32);
extern void func_003C41A0(void *, void *, f32, f32, f32, f32);
extern void func_L36_00354B28(u8 *);
extern void func_L36_00355388(u8 *, void *);
extern u8 *func_L36_00355330(u8 *, s32);
extern s32 func_L31_003494B0(void *, s32);
extern void func_L36_0034F950(U_0034F950 *);
extern void func_L36_0034FA10(u8 *, s32);
extern void func_L36_0034FB20(u8 *);
extern void func_L36_0034FE78(u8 *);
extern s32 func_00382380(void *, s32, s32);

void func_L36_0034E8C0(u8 *a0) {
    V_0034E8C0 *s;
    u8 *p;
    u8 *hero;
    f32 x;
    f32 d;
    s32 i;
    s32 k;
    vu0_v4 w;

    s = *(V_0034E8C0 **)(a0 + 0x68);
    switch (a0[0x20]) {
    case 0x42:
        if (func_L01_004561B8(a0)) {
            func_003A52A0(3, 0, a0);
            D_00142732[0] = 1;
            for (p = D_L36_001DFB28; p != 0; p = *(u8 **)(p + 0x28)) {
                if (*(s16 *)(p + 0xAA) == 0x1644 && (*(s32 *)(*(u8 **)(p + 0x68) + 0xA0) & 2)) {
                    func_L01_004450F0(p, 0x42, -1);
                }
            }
            func_L01_003303B8(a0 + 0x10, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 0.9f, 0.0f, 0.0f, 2.0f,
                              1, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & ~0x1000;
            func_L01_004AA7E8(a0, 1);
        }
        break;
    case 0:
        func_L36_00350330(a0);
        func_L01_004450F0(a0, 5, -1);
        break;
    case 1:
        if (func_L01_004561B8(a0)) {
            s->fD0 = D_L36_001DD3C4;
            a0[0xBC] = 0;
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, D_L36_001DD360);
            }
            a0[0x31] = 1;
            *(u16 *)(a0 + 0x34) &= ~1;
        }
        if (a0[0xBC] == 0) {
            a0[0x23] = (1.0f - (f32)s->fD0 / (f32)D_L36_001DD3C4) * 128.0f;
            x = func_0038DB48((f32)(s->fD0 % D_L36_001DD35C) * 6.2831855f / (f32)D_L36_001DD35C);
            s->fB0.x = func_003C4088(s->f114, s->f118,
                                               D_L36_001DD3BC + D_L36_001DD3C0 * func_0038D098(x));
            hero = D_001A4BE0;
            s->fB0.y = *(f32 *)(hero + 0x84);
            s->fB0.z = func_003C4088(s->f11C, s->f120,
                                               D_L36_001DD3BC + D_L36_001DD3C0 * func_0038D0B0(x));
            if (func_0038CAD0(&s->fD0)) {
                s->fB0.x = func_003C4088(s->f114, s->f118, 0.5f);
                s->fB0.y = *(f32 *)(hero + 0x84);
                s->fB0.z = func_003C4088(s->f11C, s->f120, 0.5f);
                s->fD0 = D_L36_001DD3C8;
                a0[0xBC] = 1;
            }
        } else if (a0[0xBC] == 1) {
            if (func_0038CAD0(&s->fD0)) {
                if (a0[0x43] != 3) {
                    func_003C3A10(a0, 3, 0, D_L36_001DD360);
                }
                func_003C2F58(s->f128, 2, &s->fB0);
                s->fB0.y = D_001A4C64[0];
                a0[0xBC] = 2;
            }
        } else {
            {
            vu0_v4 v;

            v.x = func_003C4088(s->f114, s->f118, 0.5f);
            v.y = D_001A4C64[0];
            v.z = func_003C4088(s->f11C, s->f120, 0.5f);
            d = func_0038CF00(a0 + 0x10, &s->fB0);
            a0[0x23] = d * 128.0f / func_0038CF00(&v, &s->fB0);
            }
            if (func_0038CF00(a0 + 0x10, &s->fB0) < D_L36_001DD364) {
                f32 h;
                f32 t;

                *(s32 *)(a0 + 0x98) = 0;
                *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & ~0x1000;
                func_L01_004AA7E8(a0, 1);
                h = s->f34;
                t = (*(P_0034E8C0 **)(s->f128 + 0x68))->f04;
                D_L36_001E1884 = h;
                D_L36_001E1880 = h;
                D_L36_001E1874 = t;
                D_L36_001E1870 = t;
                D_L36_001E187C = t;
                D_L36_001E1878 = t;
                func_L01_004450F0(a0, 3, -1);
            }
        }
        vec_sub_ba(&w, &s->fB0, a0 + 0x10);
        func_0038CF68(&w, &w, D_L36_001DD358);
        vec_add_ab(&s->fC0, &s->fC0, &w);
        func_L31_003478E8(a0, a0 + 0x10, &s->fC0, 0.0f,
                          D_L36_001DD3DC * *(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24),
                          D_L36_001DD424, D_L36_001DD424, D_L36_001DD424, D_L36_001DD41C, 0.0f, 0);
        break;
    case 2:
        if (func_L01_004561B8(a0)) {
            *(u16 *)(a0 + 0x34) &= ~0x41;
            *(u16 *)(a0 + 0x34) |= *(u16 *)(*(u8 **)(a0 + 0x24) + 0x44) & 0x1000;
            *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
            *(u16 *)(s->f130 + 0x34) &= ~0x41;
            *(u16 *)(s->f130 + 0x34) |= *(u16 *)(*(u8 **)(s->f130 + 0x24) + 0x44) & 0x1000;
            *(s32 *)(s->f130 + 0x98) = *(s32 *)(*(u8 **)(s->f130 + 0x24) + 0x10);
            qzero(&s->fC0);
            a0[0x23] = 0x80;
            s->fD4 = 1;
            s->fDC = -1;
            s->fD8 = 3;
        }
        if (s->fD8 == 2) {
            for (i = 0; i < 4; i++) {
                u8 *e = s->f134[i];

                if (e != 0 && (*(E_0034E8C0 **)(e + 0x68))->f5C == 1) {
                    vu0_v4 v;
                    vu0_v4 w2;

                    v = *(vu0_v4 *)(e + 0x10);
                    v.z = *(f32 *)(s->f110 + 0x38) + D_L36_001DD42C;
                    v.z = v.z + D_L36_001DD438 * func_0038D098((f32)(D_L36_001DF6C0 % D_L36_001DD434) * 6.2831855f /
                                                               (f32)D_L36_001DD434);
                    func_003C41A0(s->f134[i] + 0x18, &s->f144[i], v.z, 0.006f, 0.006f,
                                  0.10000001f);
                    if (func_0038CF00(&v, s->f134[i] + 0x10) < D_L36_001DD430 &&
                        func_0038CAD0(&s->f154[i])) {
                        func_L36_00354B28(s->f134[i]);
                        vec_sub_ab(&w2, &D_001A4C60, &(*(E_0034E8C0 **)(s->f134[i] + 0x68))->f00);
                        func_0038CF68(&w2, &w2, 0.20000002f);
                        func_L36_00355388(s->f134[i], &w2);
                        s->f134[i] = 0;
                    }
                }
            }
        } else {
            for (k = 0; k < 4; k++) {
                if (s->f134[k] != 0) {
                    (*(E_0034E8C0 **)(s->f134[k] + 0x68))->f5C = 0;
                }
                s->f134[k] = 0;
                s->f144[k] = 0;
                s->f154[k] = D_L36_001DD428;
            }
        }
        switch (s->fD8) {
        case 0:
            if (s->fD4) {
                s->fD4 = 0;
                if (a0[0x43] != 1) {
                    func_003C3A10(a0, 1, 0, D_L36_001DD360);
                }
                s->fD0 = D_L36_001DD3E0;
            }
            s->fB0 = D_001A4C60;
            if (func_0038CAD0(&s->fD0)) {
                func_L36_0034F950((U_0034F950 *)a0);
            }
            break;
        case 3:
            if (s->fD4) {
                s->fD4 = 0;
                s->fE4 = 0;
                if (a0[0x43] != 2) {
                    func_003C3A10(a0, 2, 0, D_L36_001DD360);
                }
                func_L36_0034FA10(a0, 5);
                func_L01_00456230(s->f130, 1);
                (*(Q_0034E8C0 **)(s->f130 + 0x68))->f78 = D_L36_001DD404;
                s->fD0 = 5;
            }
            if (s->fE4) {
                if (func_0038CAD0(&s->fD0)) {
                    func_L36_0034F950((U_0034F950 *)a0);
                }
            } else if (func_0038CAD0(&s->fD0) && (s->f130)[0x20] == 0x42) {
                s->fE4 = s->fE4 + 1;
                s->fD0 = D_L36_001DD400;
                if (a0[0x43] != 1) {
                    func_003C3A10(a0, 1, 0, D_L36_001DD360);
                }
            }
            break;
        case 1:
            if (s->fD4) {
                s->fD4 = 0;
                s->fE4 = 0;
                if (a0[0x43] != 3) {
                    func_003C3A10(a0, 3, 0, D_L36_001DD360);
                }
                func_L36_0034FA10(a0, 7);
                s->fD0 = D_L36_001DD3F8;
            }
            if (func_0038CAD0(&s->fD0)) {
                if (s->fE4 < D_L36_001DD3F4) {
                    func_L31_003494B0(D_L36_001DFC00 +
                                          ((*(P_0034E8C0 **)(s->f128 + 0x68))->f84[s->fE4 % 2]
                                           << 7) +
                                          0x30,
                                      -1);
                    if (++s->fE4 == D_L36_001DD3F4) {
                        if (a0[0x43] != 1) {
                            func_003C3A10(a0, 1, 0, D_L36_001DD360);
                        }
                        s->fD0 = D_L36_001DD3F0;
                    } else {
                        s->fD0 = D_L36_001DD3F8;
                    }
                } else {
                    func_L36_0034F950((U_0034F950 *)a0);
                }
            }
            break;
        case 2:
            if (s->fD4) {
                s->fD4 = 0;
                s->fD0 = D_L36_001DD3EC;
                s->fE4 = 0;
                if (a0[0x43] != 3) {
                    func_003C3A10(a0, 3, 0, D_L36_001DD360);
                }
                func_L36_0034FA10(a0, 7);
            }
            if (func_0038CAD0(&s->fD0) && s->fE4 < D_L36_001DD3E8) {
                if (s->f134[s->fE4] == 0) {
                    S_0034E8C0 tbl = D_L36_001DD440;

                    s->f134[s->fE4] =
                        func_L36_00355330(s->f128, tbl.v[s->fE4]);
                }
                if (++s->fE4 == D_L36_001DD3E8) {
                    if (a0[0x43] != 1) {
                        func_003C3A10(a0, 1, 0, D_L36_001DD360);
                    }
                    s->fD0 = D_L36_001DD3E4;
                } else {
                    s->fD0 = D_L36_001DD3EC;
                }
            }
            if (s->fD0 == 0 && s->f134[0] == 0 && s->f134[1] == 0 &&
                s->f134[2] == 0 && s->f134[3] == 0) {
                func_L36_0034F950((U_0034F950 *)a0);
            }
            break;
        case 4:
            if (s->fD4) {
                s->fD4 = 0;
                func_003A52A0(4, 0, a0);
                if (a0[0x43] != 4) {
                    func_003C3A10(a0, 4, 0, D_L36_001DD360);
                }
                if (s->fDC == 3) {
                    (*(Q_0034E8C0 **)(s->f130 + 0x68))->f78 = 0;
                }
                func_L36_0034FA10(a0, 7);
            }
            if (a0[0x60] & 2) {
                if (s->fDC == 0 || s->fDC == 2) {
                    s->fD8 = s->fDC;
                    func_L36_0034F950((U_0034F950 *)a0);
                } else {
                    if (a0[0x43] != 3) {
                        func_003C3A10(a0, 3, 0, D_L36_001DD360);
                    }
                    s->fD8 = s->fDC;
                    s->fDC = 4;
                }
            }
            break;
        }
        if (func_003C4088(s->f114, s->f118, 1.0f - D_L36_001DD37C) < s->fB0.x) {
            s->fB0.x = func_003C4088(s->f114, s->f118, 1.0f - D_L36_001DD37C);
        } else if (s->fB0.x < func_003C4088(s->f114, s->f118, D_L36_001DD37C)) {
            s->fB0.x = func_003C4088(s->f114, s->f118, D_L36_001DD37C);
        }
        if (func_003C4088(s->f11C, s->f120, 1.0f - D_L36_001DD380) < s->fB0.z) {
            s->fB0.z = func_003C4088(s->f11C, s->f120, 1.0f - D_L36_001DD380);
        } else if (s->fB0.z < func_003C4088(s->f11C, s->f120, D_L36_001DD380)) {
            s->fB0.z = func_003C4088(s->f11C, s->f120, D_L36_001DD380);
        }
        func_L36_0034FB20(a0);
        break;
    case 3:
        if (func_L01_004561B8(a0)) {
            P_0034E8C0 *m = *(P_0034E8C0 **)(s->f128 + 0x68);

            m->f00 = m->f04;
            func_L01_00456230(s->f128, 1);
        } else if ((s->f128)[0x20] == 0x42) {
            s->fEC = s->fEC + 1;
            func_003C2F58(s->f128, 0, s->f130 + 0x10);
            *(f32 *)(s->f130 + 0x14) = D_001A4C64[0];
            func_003C2F58(s->f128, 4, a0 + 0x10);
            if (s->fEC >= D_L36_001DD3D8) {
                func_L01_004450F0(a0, 2, -1);
            } else {
                func_L01_004450F0(a0, 4, -1);
            }
        }
        if ((s->f128)[0x20] != 0x42) {
            if (s->fEC == 0) {
                D_L36_001E1870 = (*(P_0034E8C0 **)(s->f128 + 0x68))->f00 < 0.0f ? 0.0f : (*(P_0034E8C0 **)(s->f128 + 0x68))->f00;
            } else {
                D_L36_001E1878 = (*(P_0034E8C0 **)(s->f128 + 0x68))->f00 < 0.0f ? 0.0f : (*(P_0034E8C0 **)(s->f128 + 0x68))->f00;
            }
        } else if (s->fEC == 1) {
            D_L36_001E1870 = 0.0f;
        } else {
            D_L36_001E1878 = 0.0f;
        }
        if ((s->f128)[0x20] == 5) {
            Q_0034E8C0 *q = *(Q_0034E8C0 **)(s->f130 + 0x68);

            (s->f130)[0x20] = 5;
            q->f7C = 1;
            q->f60 = *(vu0_v4 *)(s->f128 + 0x10);
        }
        if ((s->f128)[0x20] == 6) {
            *(u16 *)(s->f130 + 0x34) |= 0x41;
            *(u16 *)(s->f130 + 0x34) &= ~0x1000;
            *(s32 *)(s->f130 + 0x98) = 0;
            func_L01_004AA7E8(s->f130, 1);
        }
        break;
    case 4:
        if (func_L01_004561B8(a0)) {
            *(u16 *)(s->f130 + 0x34) &= ~0x41;
            *(u16 *)(s->f130 + 0x34) |= *(u16 *)(*(u8 **)(s->f130 + 0x24) + 0x44) & 0x1000;
            *(s32 *)(s->f130 + 0x98) = *(s32 *)(*(u8 **)(s->f130 + 0x24) + 0x10);
            func_L01_00456230(s->f130, 1);
            (*(Q_0034E8C0 **)(s->f130 + 0x68))->f78 = D_L36_001DD3FC;
        } else if ((s->f130)[0x20] == 0x42) {
            func_L01_004450F0(a0, 3, -1);
        }
        break;
    case 5:
        if (func_L01_004561B8(a0)) {
            a0[0x31] = 0;
            *(u16 *)(a0 + 0x34) |= 1;
        }
        if (func_00382380(&D_001A4C60, s->fF0, 0)) {
            func_L01_004450F0(a0, 6, -1);
        }
        break;
    case 6:
        if (func_L01_004561B8(a0)) {
            (*(R_0034E8C0 **)(s->f100 + 0x68))->f40[s->f108].f0C = 1.0f;
            (*(R_0034E8C0 **)(s->f100 + 0x68))->f40[s->f104].f0C = 0.0f;
            D_L36_001DEEAC = 0;
            func_L01_00456230(D_L36_001DFB1C + s->fF8 * 0x100, 1);
            s->fD0 = D_L36_001DD408;
        }
        if (func_0038CAD0(&s->fD0)) {
            a0[0x23] = 0x80;
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    }
    func_L36_0034FE78(a0);
}
/* localdecomp:end func_L36_0034E8C0 */

/* localdecomp:start func_L36_0034F950 */
/* Ps2EeAs only uses $gp for this if it knows the size before the use. */
__asm__(".extern D_L36_001DD3A8, 8");
extern f32 func_003824E0(f32, f32);
extern f32 D_L36_001DD3A8[2];

void func_L36_0034F950(U_0034F950 *a0) {
    T_0034F950 *s;
    s32 i;
    s32 old;
    f32 r;
    f32 x;

    i = 0;
    s = a0->f_68;
    s->f_D4 = 1;
    old = s->f_D8;
    s->f_DC = old;
    x = 1.0f;
    if (old != 4) {
        x = x - D_L36_001DD3A8[old];
    }
    r = func_003824E0(0.0f, x);
    if (0.0f <= r) {
        do {
            if (i != s->f_DC) {
                r = r - D_L36_001DD3A8[i];
            }
            i++;
        } while (0.0f <= r);
    }
    s->f_D8 = i - 1;
}
/* localdecomp:end func_L36_0034F950 */

/* localdecomp:start func_L36_0034FA10 */
__asm__(".extern D_L36_001DD388, 8");
__asm__(".extern D_L36_001DD398, 8");
extern f32 func_003824E0(f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 D_L36_001DD388[2];
extern f32 D_L36_001DD398[2];
extern f32 D_001A4C64[];
void func_L36_0034FA10(u8 *a0, s32 a1) {
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 i = 0;
    f32 best;
    f32 r;
    best = func_003824E0(0.0f, 1.0f);
    r = func_003824E0(0.0f, 1.0f);
    if (best < r) {
        if (a1 & 2) {
            best = r;
            i = 1;
        }
    }
    r = func_003824E0(0.0f, 1.0f);
    if (best < r) {
        if (a1 & 4) {
            best = r;
            i = 2;
        }
    }
    *(f32 *)(s + 0xB0) = func_003C4088(*(f32 *)(s + 0x114), *(f32 *)(s + 0x118), D_L36_001DD388[i]);
    *(f32 *)(s + 0xB4) = D_001A4C64[0];
    *(f32 *)(s + 0xB8) = func_003C4088(*(f32 *)(s + 0x11C), *(f32 *)(s + 0x120), D_L36_001DD398[i]);
}
/* localdecomp:end func_L36_0034FA10 */

/* localdecomp:start func_L36_0034FB20 */
__asm__(".extern D_L36_001DD35C, 4");
__asm__(".extern D_L36_001DD350, 4");
__asm__(".extern D_L36_001DD354, 4");
__asm__(".extern D_L36_001DD378, 4");
__asm__(".extern D_L36_001DD420, 4");
__asm__(".extern D_L36_001DD374, 4");
__asm__(".extern D_L36_001DD3D0, 4");
__asm__(".extern D_L36_001DD3DC, 4");
__asm__(".extern D_L36_001DD3B8, 4");
__asm__(".extern D_L36_001DD41C, 4");
extern s32 D_L36_001DF6C0;
extern s32 D_L36_001DD35C;
extern f32 D_L36_001DD350;
extern f32 D_L36_001DD354;
extern s32 D_L36_001DD378;
extern f32 D_L36_001DD420;
extern f32 D_L36_001DD374;
extern f32 D_L36_001DD3D0;
extern f32 D_L36_001DD3DC;
extern f32 D_L36_001DD3B8;
extern f32 D_L36_001DD41C;
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L31_003478E8(void *, void *, void *, f32, f32, f32, f32, f32, f32, f32, s32);

void func_L36_0034FB20(u8 *a0) {
    u8 *s;
    f32 t;
    f32 l;
    f32 r;
    f32 m;
    f32 q;
    f32 w;
    f32 h;
    f32 spd;
    vu0_v4 proj;
    vu0_v4 perp;
    vu0_v4 b;
    vu0_v4 a;
    vu0_v4 d;
    vu0_v4 p;

    s = *(u8 **)(a0 + 0x68);
    t = (f32)(D_L36_001DF6C0 % D_L36_001DD35C) / (f32)D_L36_001DD35C;
    t = func_003C4088(D_L36_001DD354, D_L36_001DD350, func_0038D098(func_0038DB48(t * 6.2831855f)) * 0.5f + 0.5f);
    spd = D_L36_001DD420;
    p = *(vu0_v4 *)(s + 0xB0);
    p.z = p.z + D_L36_001DD374 * func_0038D0B0(func_0038DB48((f32)(D_L36_001DF6C0 % D_L36_001DD378) * 6.2831855f / (f32)D_L36_001DD378));
    vec_sub_ba(&d, &p, a0 + 0x10);
    func_0038CE20(&proj, &d, func_0038CE68(&d, s + 0xC0) / func_0038CE68(&d, &d));
    vec_sub_ab(&perp, s + 0xC0, &proj);
    if (0.0f < func_0038CEA8(&proj)) {
        r = func_0038CEA8(&d) / func_0038CEA8(&proj);
    } else {
        r = 10000.0f;
    }
    w = (D_L36_001DD3D0 * t < func_0038CEA8(&perp) * 2.0f / r) ? D_L36_001DD3D0 * t : func_0038CEA8(&perp) * 2.0f / r;
    l = sqrt_asm(t * t - w * w);
    h = func_0038CEA8(&proj);
    q = func_0038CEA8(&proj) / l;
    h = h * 0.5f;
    m = q * h + h;
    func_0038CF68(&a, &perp, w);
    func_0038CE20(&a, &a, -1.0f);
    func_0038CF68(&b, &d, l);
    if (func_0038CEA8(&d) < m && 0.0f < func_0038CE68(&proj, &d)) {
        func_0038CE20(&b, &b, -1.0f);
    }
    vec_add_ba(s + 0xC0, s + 0xC0, &a);
    vec_add_ab(s + 0xC0, s + 0xC0, &b);
    func_L31_003478E8(a0, a0 + 0x10, s + 0xC0, D_L36_001DD3B8, D_L36_001DD3DC * *(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24), spd, spd, spd, D_L36_001DD41C, 0.0f, 0);
}
/* localdecomp:end func_L36_0034FB20 */

/* localdecomp:start func_L36_0034FE78 */
__asm__(".extern D_L36_001DD3CC, 4");
__asm__(".extern D_L36_001DD368, 4");
__asm__(".extern D_L36_001DD420, 4");
__asm__(".extern D_L36_001DD418, 4");
__asm__(".extern D_L36_001DD40C, 4");
__asm__(".extern D_L36_001DD410, 4");
__asm__(".extern D_L36_001DD414, 4");
__asm__(".extern D_L36_001DD3D4, 4");
__asm__(".extern D_L36_001DD3DC, 4");
extern s32 D_L36_001DD3CC;
extern f32 D_L36_001DD368;
extern f32 D_L36_001DD420;
extern f32 D_L36_001DD418;
extern f32 D_L36_001DD40C;
extern f32 D_L36_001DD410;
extern f32 D_L36_001DD414;
extern f32 D_L36_001DD3D4;
extern f32 D_L36_001DD3DC;
extern f32 D_L36_001E1880;
extern u8 D_001A4BE0[];
extern vu0_v4 D_001A4C60;
extern s32 func_0038CAD0(void *);
extern void func_L01_0044ABD0(void *, void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4A40(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L30_0034CB68(u8 *, void *, s32, s32, s32, s32, f32, f32);
void func_L36_0034FE78(u8 *a0) {
    u8 *s;
    u8 *t;
    u8 *hero;
    vu0_v4 v;
    vu0_v4 w;
    f32 a;
    f32 b;
    f32 x;
    f32 dmg;
    s16 id;

    s = *(u8 **)(a0 + 0x68);
    func_0038CAD0(s + 0xE8);
    func_L01_0044ABD0(a0, s + 0x70);
    t = func_L01_00447490(a0, 0x10000, 0);
    if (t != 0) {
        a0[0xA8] = 0xFF;
        dmg = *(f32 *)(t + 0x2C);
        if (0.0f < dmg) {
            id = *(s16 *)(*(u8 **)(t + 0x20) + 0xAA);
            if (id != 0x167E && id != 0x1903 && id != 0x1644 && a0[0x20] == 2 && *(s32 *)(s + 0xE8) <= 0) {
                f32 push = D_L36_001DD368;
                *(s32 *)(s + 0xE8) = D_L36_001DD3CC;
                *(f32 *)(s + 0x30) = *(f32 *)(s + 0x30) - dmg;
                v = *(vu0_v4 *)(t + 0x10);
                func_0038CF68(&v, &v, push);
                vec_add_ab(s + 0xC0, s + 0xC0, &v);
                if (*(s32 *)(s + 0xD8) != 4) {
                    *(s32 *)(s + 0xDC) = *(s32 *)(s + 0xD8);
                    *(s32 *)(s + 0xD4) = 1;
                    *(s32 *)(s + 0xD8) = 4;
                }
                s[0x77] = 0xFF;
                func_003C4A40(a0, s + 0x70);
                if (*(f32 *)(s + 0x30) <= 0.0f) {
                    func_L01_004450F0(a0, 0x42, -1);
                }
            }
        }
    }
    hero = D_001A4BE0;
    *(f32 *)(a0 + 0x14) = *(f32 *)(hero + 0x84);
    if (a0[0x43] == 1) {
        x = *(f32 *)(s + 0xC8) * 0.5f / D_L36_001DD420 + 0.5f;
        if (1.0f < x) {
            x = 1.0f;
        } else if (x < 0.0f) {
            x = 0.0f;
        }
        a = func_003C4088(D_L36_001DD418, D_L36_001DD40C, x);
        x = *(f32 *)(s + 0xC0) * 0.5f / D_L36_001DD420 + 0.5f;
        if (1.0f < x) {
            x = 1.0f;
        } else if (x < 0.0f) {
            x = 0.0f;
        }
        b = func_003C4088(D_L36_001DD410, D_L36_001DD414, x);
    } else {
        vec_sub_ab(&w, hero + 0x80, a0 + 0x10);
        func_0038CF68(&w, &w, 1.0f);
        a = func_003C4088(D_L36_001DD418, D_L36_001DD40C, w.z * 0.5f + 0.5f);
        b = func_003C4088(D_L36_001DD410, D_L36_001DD414, w.x * 0.5f + 0.5f);
    }
    if (((D_L36_001DD418 < *(f32 *)(a0 + 0xF4) + D_L36_001DD3D4) ? D_L36_001DD418 : *(f32 *)(a0 + 0xF4) + D_L36_001DD3D4) < a) {
        a = (D_L36_001DD418 < *(f32 *)(a0 + 0xF4) + D_L36_001DD3D4) ? D_L36_001DD418 : *(f32 *)(a0 + 0xF4) + D_L36_001DD3D4;
    } else if (a < ((*(f32 *)(a0 + 0xF4) - D_L36_001DD3D4 < D_L36_001DD40C) ? D_L36_001DD40C : *(f32 *)(a0 + 0xF4) - D_L36_001DD3D4)) {
        a = (*(f32 *)(a0 + 0xF4) - D_L36_001DD3D4 < D_L36_001DD40C) ? D_L36_001DD40C : *(f32 *)(a0 + 0xF4) - D_L36_001DD3D4;
    }
    if (((D_L36_001DD414 < *(f32 *)(a0 + 0xF8) + D_L36_001DD3D4) ? D_L36_001DD414 : *(f32 *)(a0 + 0xF8) + D_L36_001DD3D4) < b) {
        b = (D_L36_001DD414 < *(f32 *)(a0 + 0xF8) + D_L36_001DD3D4) ? D_L36_001DD414 : *(f32 *)(a0 + 0xF8) + D_L36_001DD3D4;
    } else if (b < ((*(f32 *)(a0 + 0xF8) - D_L36_001DD3D4 < D_L36_001DD410) ? D_L36_001DD410 : *(f32 *)(a0 + 0xF8) - D_L36_001DD3D4)) {
        b = (*(f32 *)(a0 + 0xF8) - D_L36_001DD3D4 < D_L36_001DD410) ? D_L36_001DD410 : *(f32 *)(a0 + 0xF8) - D_L36_001DD3D4;
    }
    *(f32 *)(a0 + 0xF4) = a;
    *(f32 *)(a0 + 0xF8) = b;
    if (a0[0x20] == 2 && *(s32 *)(s + 0xD8) != 4) {
        vec_sub_ba(&v, &D_001A4C60, a0 + 0x10);
        func_0038CF68(&v, &v, 1.0f);
        func_L30_0034CB68(a0, &v, 1, -1, 0, 0, (f32)s[0x44],
                          D_L36_001DD3DC * *(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24));
    }
    D_L36_001E1880 = *(f32 *)(s + 0x30);
}
/* localdecomp:end func_L36_0034FE78 */

/* localdecomp:start func_L36_00350330 */
typedef int Q_00350330 __attribute__((mode(TI)));
extern u8 *D_L36_001DFC00;
extern u8 *D_L36_001DFB1C;
extern u8 *D_L36_001DFB28;
__asm__(".extern D_L36_001DFC00, 16");
__asm__(".extern D_L36_001DFB1C, 16");
__asm__(".extern D_L36_001DFB28, 16");
extern f32 func_0038CE68(void *, void *);

typedef struct {
    char pad0[0xA0];
    Q_00350330 vA0;
    Q_00350330 vB0;
    Q_00350330 vC0;
    s32 fD0;
    s32 fD4;
    s32 fD8;
    s32 fDC;
    char padE0[8];
    s32 fE8;
    s32 fEC;
    s32 fF0;
    u8 *fF4;
    s32 fF8;
    u8 *fFC;
    u8 *f100;
    char pad104[8];
    s32 f10C;
    u8 *f110;
    f32 f114;
    f32 f118;
    f32 f11C;
    f32 f120;
    s32 f124;
    u8 *f128;
    s32 f12C;
    u8 *f130;
} S_00350330;

void func_L36_00350330(u8 *a0) {
    S_00350330 *s;
    u8 *p;
    u8 *t;
    f32 v[4] __attribute__((aligned(16)));
    Q_00350330 x;

    a0[0x30] = 0xFF;
    s = *(S_00350330 **)(a0 + 0x68);
    x = *(Q_00350330 *)(a0 + 0x10);
    qzero((u8 *)s + 0xC0);
    *(Q_00350330 *)((u8 *)s + 0xA0) = x;
    *(Q_00350330 *)((u8 *)s + 0xB0) = x;
    s->fD0 = 0;
    s->fD4 = 0;
    s->fD8 = -1;
    s->fDC = -1;
    s->fE8 = 0;
    s->fEC = 0;
    s->fF4 = D_L36_001DFC00 + s->fF0 * 0x80;
    s->fFC = D_L36_001DFB1C + s->fF8 * 0x100;
    for (p = D_L36_001DFB28; p != 0; p = *(u8 **)(p + 0x28)) {
        if (*(s16 *)(p + 0xAA) == 0x1B55) {
            s->f100 = p;
        }
    }
    s->f110 = D_L36_001DFC00 + s->f10C * 0x80;
    qzero(v);
    v[0] = 1.0f;
    s->f114 = *(f32 *)(s->f110 + 0x30) - func_0038CE68(s->f110, v);
    s->f118 = *(f32 *)(s->f110 + 0x30) + func_0038CE68(s->f110, v);
    qzero(v);
    v[2] = 1.0f;
    s->f11C = *(f32 *)(s->f110 + 0x38) - func_0038CE68(s->f110 + 0x20, v);
    s->f120 = *(f32 *)(s->f110 + 0x38) + func_0038CE68(s->f110 + 0x20, v);
    s->f128 = D_L36_001DFB1C + s->f124 * 0x100;
    s->f130 = D_L36_001DFB1C + s->f12C * 0x100;
    t = *(u8 **)(s->f130 + 0x68);
    *(f32 *)(t + 0x88) = s->f120;
    *(f32 *)(t + 0x80) = s->f114 + 5.0f;
    *(f32 *)(t + 0x84) = s->f118 - 5.0f;
}
/* localdecomp:end func_L36_00350330 */
