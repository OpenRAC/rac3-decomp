#include "common.h"

/* NTSC-U counterpart of func_L36_0034E8C0 (src/levels/36_vidcomic_1_special_edition/L36_0034E8C0.c) */
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

/* localdecomp:start func_L36_0034DBD0 */
__asm__(".extern D_L36_001DD404_pD3C4, 4");
__asm__(".extern D_L36_001DD3A0, 4");
__asm__(".extern D_L36_001DD39C, 4");
__asm__(".extern D_L36_001DD400_pD3C0, 4");
__asm__(".extern D_L36_001DD3FC_pD3BC, 4");
__asm__(".extern D_L36_001DD408_pD3C8, 4");
__asm__(".extern D_L36_001DD3A4, 4");
__asm__(".extern D_L36_001DD398_0034DBD0, 4");
__asm__(".extern D_L36_001DD41C_pD3DC, 4");
__asm__(".extern D_L36_001DD464, 4");
__asm__(".extern D_L36_001DD45C, 4");
__asm__(".extern D_L36_001DD474, 4");
__asm__(".extern D_L36_001DD46C, 4");
__asm__(".extern D_L36_001DD478, 4");
__asm__(".extern D_L36_001DD470, 4");
__asm__(".extern D_L36_001DD468, 4");
__asm__(".extern D_L36_001DD3BC_pD37C, 4");
__asm__(".extern D_L36_001DD3C0_pD380, 4");
__asm__(".extern D_L36_001DD420_0034DBD0, 4");
__asm__(".extern D_L36_001DD424_pD3E4, 4");
__asm__(".extern D_L36_001DD428_pD3E8, 4");
__asm__(".extern D_L36_001DD42C_pD3EC, 4");
__asm__(".extern D_L36_001DD430_pD3F0, 4");
__asm__(".extern D_L36_001DD434_pD3F4, 4");
__asm__(".extern D_L36_001DD438_pD3F8, 4");
__asm__(".extern D_L36_001DD43C, 4");
__asm__(".extern D_L36_001DD440_pD400, 4");
__asm__(".extern D_L36_001DD444, 4");
__asm__(".extern D_L36_001DD448, 4");
__asm__(".extern D_L36_001DD418_0034DBD0, 4");
extern s32 D_L36_001DD404_pD3C4;
extern s32 D_L36_001DD3A0;
extern s32 D_L36_001DD39C;
extern f32 D_L36_001DD400_pD3C0;
extern f32 D_L36_001DD3FC_pD3BC;
extern s32 D_L36_001DD408_pD3C8;
extern f32 D_L36_001DD3A4;
extern f32 D_L36_001DD398_0034DBD0;
extern f32 D_L36_001DD41C_pD3DC;
extern f32 D_L36_001DD464;
extern f32 D_L36_001DD45C;
extern s32 D_L36_001DD474;
extern f32 D_L36_001DD46C;
extern f32 D_L36_001DD478;
extern f32 D_L36_001DD470;
extern s32 D_L36_001DD468;
extern f32 D_L36_001DD3BC_pD37C;
extern f32 D_L36_001DD3C0_pD380;
extern s32 D_L36_001DD420_0034DBD0;
extern s32 D_L36_001DD424_pD3E4;
extern s32 D_L36_001DD428_pD3E8;
extern s32 D_L36_001DD42C_pD3EC;
extern s32 D_L36_001DD430_pD3F0;
extern s32 D_L36_001DD434_pD3F4;
extern s32 D_L36_001DD438_pD3F8;
extern s32 D_L36_001DD43C;
extern s32 D_L36_001DD440_pD400;
extern s32 D_L36_001DD444;
extern s32 D_L36_001DD448;
extern s32 D_L36_001DD418_0034DBD0;
extern f32 D_L36_001E1870_0034DBD0;
extern f32 D_L36_001E1874_0034DBD0;
extern f32 D_L36_001E1878_0034DBD0;
extern f32 D_L36_001E187C_0034DBD0;
extern f32 D_L36_001E1880_0034DBD0;
extern f32 D_L36_001E1884_0034DBD0;
extern s32 D_L36_001DEEEC;
extern u8 *D_L36_001DFB28_0034DBD0;
extern u8 *D_L36_001DFB1C_0034DBD0;
extern u8 *D_L36_001DFC00_0034DBD0;
extern s32 D_L36_001DF6C0_0034DBD0;
typedef struct S_0034E8C0 {
    s32 v[4];
} S_0034E8C0;
extern S_0034E8C0 D_L36_001DD480;
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
extern s32 func_L01_00452EC8(u8 *);
extern void func_L01_00452F40(void *, s32);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_0032FE90(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004A6DF8(u8 *a0, s32 a1);
extern void func_L36_0034F640(u8 *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00389410(f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_003BEB48(f32, f32, f32);
extern s32 func_00388398(void *);
extern void func_003BDA38(void *, s32, void *);
extern f32 func_003887C8(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L31_00346DD8(void *, void *, void *, f32, f32, f32, f32, f32, f32, f32, s32);
extern void func_003BEC60(void *, void *, f32, f32, f32, f32);
extern void func_L36_00353E08(u8 *);
extern void func_L36_00354668(u8 *, void *);
extern u8 *func_L36_00354610(u8 *, s32);
extern s32 func_L31_003488D0(void *, s32);
extern void func_L36_0034EC60(U_0034F950 *);
extern void func_L36_0034ED20(u8 *, s32);
extern void func_L36_0034EE30(u8 *);
extern void func_L36_0034F188(u8 *);
extern s32 func_0037E0F0(void *, s32, s32);

void func_L36_0034DBD0(u8 *a0) {
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
        if (func_L01_00452EC8(a0)) {
            func_0039FE80(3, 0, a0);
            D_00142732[0] = 1;
            for (p = D_L36_001DFB28_0034DBD0; p != 0; p = *(u8 **)(p + 0x28)) {
                if (*(s16 *)(p + 0xAA) == 0x1644 && (*(s32 *)(*(u8 **)(p + 0x68) + 0xA0) & 2)) {
                    func_L01_00441FB8(p, 0x42, -1);
                }
            }
            func_L01_0032FE90(a0 + 0x10, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 0.9f, 0.0f, 0.0f, 2.0f,
                              1, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & ~0x1000;
            func_L01_004A6DF8(a0, 1);
        }
        break;
    case 0:
        func_L36_0034F640(a0);
        func_L01_00441FB8(a0, 5, -1);
        break;
    case 1:
        if (func_L01_00452EC8(a0)) {
            s->fD0 = D_L36_001DD404_pD3C4;
            a0[0xBC] = 0;
            if (a0[0x43] != 1) {
                func_003BE4F0(a0, 1, 0, D_L36_001DD3A0);
            }
            a0[0x31] = 1;
            *(u16 *)(a0 + 0x34) &= ~1;
        }
        if (a0[0xBC] == 0) {
            a0[0x23] = (1.0f - (f32)s->fD0 / (f32)D_L36_001DD404_pD3C4) * 128.0f;
            x = func_00389410((f32)(s->fD0 % D_L36_001DD39C) * 6.2831855f / (f32)D_L36_001DD39C);
            s->fB0.x = func_003BEB48(s->f114, s->f118,
                                               D_L36_001DD3FC_pD3BC + D_L36_001DD400_pD3C0 * func_00388960(x));
            hero = D_001A4BE0;
            s->fB0.y = *(f32 *)(hero + 0x84);
            s->fB0.z = func_003BEB48(s->f11C, s->f120,
                                               D_L36_001DD3FC_pD3BC + D_L36_001DD400_pD3C0 * func_00388978(x));
            if (func_00388398(&s->fD0)) {
                s->fB0.x = func_003BEB48(s->f114, s->f118, 0.5f);
                s->fB0.y = *(f32 *)(hero + 0x84);
                s->fB0.z = func_003BEB48(s->f11C, s->f120, 0.5f);
                s->fD0 = D_L36_001DD408_pD3C8;
                a0[0xBC] = 1;
            }
        } else if (a0[0xBC] == 1) {
            if (func_00388398(&s->fD0)) {
                if (a0[0x43] != 3) {
                    func_003BE4F0(a0, 3, 0, D_L36_001DD3A0);
                }
                func_003BDA38(s->f128, 2, &s->fB0);
                s->fB0.y = D_001A4C64[0];
                a0[0xBC] = 2;
            }
        } else {
            {
            vu0_v4 v;

            v.x = func_003BEB48(s->f114, s->f118, 0.5f);
            v.y = D_001A4C64[0];
            v.z = func_003BEB48(s->f11C, s->f120, 0.5f);
            d = func_003887C8(a0 + 0x10, &s->fB0);
            a0[0x23] = d * 128.0f / func_003887C8(&v, &s->fB0);
            }
            if (func_003887C8(a0 + 0x10, &s->fB0) < D_L36_001DD3A4) {
                f32 h;
                f32 t;

                *(s32 *)(a0 + 0x98) = 0;
                *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & ~0x1000;
                func_L01_004A6DF8(a0, 1);
                h = s->f34;
                t = (*(P_0034E8C0 **)(s->f128 + 0x68))->f04;
                D_L36_001E1884_0034DBD0 = h;
                D_L36_001E1880_0034DBD0 = h;
                D_L36_001E1874_0034DBD0 = t;
                D_L36_001E1870_0034DBD0 = t;
                D_L36_001E187C_0034DBD0 = t;
                D_L36_001E1878_0034DBD0 = t;
                func_L01_00441FB8(a0, 3, -1);
            }
        }
        vec_sub_ba(&w, &s->fB0, a0 + 0x10);
        func_00388830(&w, &w, D_L36_001DD398_0034DBD0);
        vec_add_ab(&s->fC0, &s->fC0, &w);
        func_L31_00346DD8(a0, a0 + 0x10, &s->fC0, 0.0f,
                          D_L36_001DD41C_pD3DC * *(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24),
                          D_L36_001DD464, D_L36_001DD464, D_L36_001DD464, D_L36_001DD45C, 0.0f, 0);
        break;
    case 2:
        if (func_L01_00452EC8(a0)) {
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
                    v.z = *(f32 *)(s->f110 + 0x38) + D_L36_001DD46C;
                    v.z = v.z + D_L36_001DD478 * func_00388960((f32)(D_L36_001DF6C0_0034DBD0 % D_L36_001DD474) * 6.2831855f /
                                                               (f32)D_L36_001DD474);
                    func_003BEC60(s->f134[i] + 0x18, &s->f144[i], v.z, 0.004166666883975267f, 0.004166666883975267f,
                                  0.0833333358168602f);
                    if (func_003887C8(&v, s->f134[i] + 0x10) < D_L36_001DD470 &&
                        func_00388398(&s->f154[i])) {
                        func_L36_00353E08(s->f134[i]);
                        vec_sub_ab(&w2, &D_001A4C60, &(*(E_0034E8C0 **)(s->f134[i] + 0x68))->f00);
                        func_00388830(&w2, &w2, 0.1666666716337204f);
                        func_L36_00354668(s->f134[i], &w2);
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
                s->f154[k] = D_L36_001DD468;
            }
        }
        switch (s->fD8) {
        case 0:
            if (s->fD4) {
                s->fD4 = 0;
                if (a0[0x43] != 1) {
                    func_003BE4F0(a0, 1, 0, D_L36_001DD3A0);
                }
                s->fD0 = D_L36_001DD420_0034DBD0;
            }
            s->fB0 = D_001A4C60;
            if (func_00388398(&s->fD0)) {
                func_L36_0034EC60((U_0034F950 *)a0);
            }
            break;
        case 3:
            if (s->fD4) {
                s->fD4 = 0;
                s->fE4 = 0;
                if (a0[0x43] != 2) {
                    func_003BE4F0(a0, 2, 0, D_L36_001DD3A0);
                }
                func_L36_0034ED20(a0, 5);
                func_L01_00452F40(s->f130, 1);
                (*(Q_0034E8C0 **)(s->f130 + 0x68))->f78 = D_L36_001DD444;
                s->fD0 = 5;
            }
            if (s->fE4) {
                if (func_00388398(&s->fD0)) {
                    func_L36_0034EC60((U_0034F950 *)a0);
                }
            } else if (func_00388398(&s->fD0) && (s->f130)[0x20] == 0x42) {
                s->fE4 = s->fE4 + 1;
                s->fD0 = D_L36_001DD440_pD400;
                if (a0[0x43] != 1) {
                    func_003BE4F0(a0, 1, 0, D_L36_001DD3A0);
                }
            }
            break;
        case 1:
            if (s->fD4) {
                s->fD4 = 0;
                s->fE4 = 0;
                if (a0[0x43] != 3) {
                    func_003BE4F0(a0, 3, 0, D_L36_001DD3A0);
                }
                func_L36_0034ED20(a0, 7);
                s->fD0 = D_L36_001DD438_pD3F8;
            }
            if (func_00388398(&s->fD0)) {
                if (s->fE4 < D_L36_001DD434_pD3F4) {
                    func_L31_003488D0(D_L36_001DFC00_0034DBD0 +
                                          ((*(P_0034E8C0 **)(s->f128 + 0x68))->f84[s->fE4 % 2]
                                           << 7) +
                                          0x30,
                                      -1);
                    if (++s->fE4 == D_L36_001DD434_pD3F4) {
                        if (a0[0x43] != 1) {
                            func_003BE4F0(a0, 1, 0, D_L36_001DD3A0);
                        }
                        s->fD0 = D_L36_001DD430_pD3F0;
                    } else {
                        s->fD0 = D_L36_001DD438_pD3F8;
                    }
                } else {
                    func_L36_0034EC60((U_0034F950 *)a0);
                }
            }
            break;
        case 2:
            if (s->fD4) {
                s->fD4 = 0;
                s->fD0 = D_L36_001DD42C_pD3EC;
                s->fE4 = 0;
                if (a0[0x43] != 3) {
                    func_003BE4F0(a0, 3, 0, D_L36_001DD3A0);
                }
                func_L36_0034ED20(a0, 7);
            }
            if (func_00388398(&s->fD0) && s->fE4 < D_L36_001DD428_pD3E8) {
                if (s->f134[s->fE4] == 0) {
                    S_0034E8C0 tbl = D_L36_001DD480;

                    s->f134[s->fE4] =
                        func_L36_00354610(s->f128, tbl.v[s->fE4]);
                }
                if (++s->fE4 == D_L36_001DD428_pD3E8) {
                    if (a0[0x43] != 1) {
                        func_003BE4F0(a0, 1, 0, D_L36_001DD3A0);
                    }
                    s->fD0 = D_L36_001DD424_pD3E4;
                } else {
                    s->fD0 = D_L36_001DD42C_pD3EC;
                }
            }
            if (s->fD0 == 0 && s->f134[0] == 0 && s->f134[1] == 0 &&
                s->f134[2] == 0 && s->f134[3] == 0) {
                func_L36_0034EC60((U_0034F950 *)a0);
            }
            break;
        case 4:
            if (s->fD4) {
                s->fD4 = 0;
                func_0039FE80(4, 0, a0);
                if (a0[0x43] != 4) {
                    func_003BE4F0(a0, 4, 0, D_L36_001DD3A0);
                }
                if (s->fDC == 3) {
                    (*(Q_0034E8C0 **)(s->f130 + 0x68))->f78 = 0;
                }
                func_L36_0034ED20(a0, 7);
            }
            if (a0[0x60] & 2) {
                if (s->fDC == 0 || s->fDC == 2) {
                    s->fD8 = s->fDC;
                    func_L36_0034EC60((U_0034F950 *)a0);
                } else {
                    if (a0[0x43] != 3) {
                        func_003BE4F0(a0, 3, 0, D_L36_001DD3A0);
                    }
                    s->fD8 = s->fDC;
                    s->fDC = 4;
                }
            }
            break;
        }
        if (func_003BEB48(s->f114, s->f118, 1.0f - D_L36_001DD3BC_pD37C) < s->fB0.x) {
            s->fB0.x = func_003BEB48(s->f114, s->f118, 1.0f - D_L36_001DD3BC_pD37C);
        } else if (s->fB0.x < func_003BEB48(s->f114, s->f118, D_L36_001DD3BC_pD37C)) {
            s->fB0.x = func_003BEB48(s->f114, s->f118, D_L36_001DD3BC_pD37C);
        }
        if (func_003BEB48(s->f11C, s->f120, 1.0f - D_L36_001DD3C0_pD380) < s->fB0.z) {
            s->fB0.z = func_003BEB48(s->f11C, s->f120, 1.0f - D_L36_001DD3C0_pD380);
        } else if (s->fB0.z < func_003BEB48(s->f11C, s->f120, D_L36_001DD3C0_pD380)) {
            s->fB0.z = func_003BEB48(s->f11C, s->f120, D_L36_001DD3C0_pD380);
        }
        func_L36_0034EE30(a0);
        break;
    case 3:
        if (func_L01_00452EC8(a0)) {
            P_0034E8C0 *m = *(P_0034E8C0 **)(s->f128 + 0x68);

            m->f00 = m->f04;
            func_L01_00452F40(s->f128, 1);
        } else if ((s->f128)[0x20] == 0x42) {
            s->fEC = s->fEC + 1;
            func_003BDA38(s->f128, 0, s->f130 + 0x10);
            *(f32 *)(s->f130 + 0x14) = D_001A4C64[0];
            func_003BDA38(s->f128, 4, a0 + 0x10);
            if (s->fEC >= D_L36_001DD418_0034DBD0) {
                func_L01_00441FB8(a0, 2, -1);
            } else {
                func_L01_00441FB8(a0, 4, -1);
            }
        }
        if ((s->f128)[0x20] != 0x42) {
            if (s->fEC == 0) {
                D_L36_001E1870_0034DBD0 = (*(P_0034E8C0 **)(s->f128 + 0x68))->f00 < 0.0f ? 0.0f : (*(P_0034E8C0 **)(s->f128 + 0x68))->f00;
            } else {
                D_L36_001E1878_0034DBD0 = (*(P_0034E8C0 **)(s->f128 + 0x68))->f00 < 0.0f ? 0.0f : (*(P_0034E8C0 **)(s->f128 + 0x68))->f00;
            }
        } else if (s->fEC == 1) {
            D_L36_001E1870_0034DBD0 = 0.0f;
        } else {
            D_L36_001E1878_0034DBD0 = 0.0f;
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
            func_L01_004A6DF8(s->f130, 1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(a0)) {
            *(u16 *)(s->f130 + 0x34) &= ~0x41;
            *(u16 *)(s->f130 + 0x34) |= *(u16 *)(*(u8 **)(s->f130 + 0x24) + 0x44) & 0x1000;
            *(s32 *)(s->f130 + 0x98) = *(s32 *)(*(u8 **)(s->f130 + 0x24) + 0x10);
            func_L01_00452F40(s->f130, 1);
            (*(Q_0034E8C0 **)(s->f130 + 0x68))->f78 = D_L36_001DD43C;
        } else if ((s->f130)[0x20] == 0x42) {
            func_L01_00441FB8(a0, 3, -1);
        }
        break;
    case 5:
        if (func_L01_00452EC8(a0)) {
            a0[0x31] = 0;
            *(u16 *)(a0 + 0x34) |= 1;
        }
        if (func_0037E0F0(&D_001A4C60, s->fF0, 0)) {
            func_L01_00441FB8(a0, 6, -1);
        }
        break;
    case 6:
        if (func_L01_00452EC8(a0)) {
            (*(R_0034E8C0 **)(s->f100 + 0x68))->f40[s->f108].f0C = 1.0f;
            (*(R_0034E8C0 **)(s->f100 + 0x68))->f40[s->f104].f0C = 0.0f;
            D_L36_001DEEEC = 0;
            func_L01_00452F40(D_L36_001DFB1C_0034DBD0 + s->fF8 * 0x100, 1);
            s->fD0 = D_L36_001DD448;
        }
        if (func_00388398(&s->fD0)) {
            a0[0x23] = 0x80;
            func_L01_00441FB8(a0, 1, -1);
        }
        break;
    }
    func_L36_0034F188(a0);
}
/* localdecomp:end func_L36_0034DBD0 */
