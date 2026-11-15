#include "common.h"

/* localdecomp:start func_L30_004CD998 */
#include "vu0.h"

typedef int s128_004CD998 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x80];
    union { s128_004CD998 q; f32 f[4]; } u80;
    u8 pad90[0x40];
    s128_004CD998 qD0;
    s128_004CD998 qE0;
    s128_004CD998 qF0;
    u8 pad100[0x70];
    f32 f170;
    u8 pad174[0x10];
    f32 f184;
    u8 pad188[0x30];
    s32 w1B8;
    s32 w1BC;
    s32 w1C0;
    s32 w1C4;
    s32 w1C8;
    s32 w1CC;
    s16 h1D0;
    s16 h1D2;
    s32 w1D4;
    s32 w1D8;
    s16 h1DC;
    s16 h1DE;
    s16 h1E0;
    u8 pad1E2[0x2];
    s16 h1E4;
    s16 h1E6;
    s32 w1E8;
    s16 h1EC;
    s16 h1EE;
    s16 h1F0;
    s16 h1F2;
    s16 h1F4;
    s16 h1F6;
    s16 h1F8;
    s16 h1FA;
    s16 h1FC;
    s16 h1FE;
    s16 h200;
    s16 h202;
    s16 h204;
    s16 h206;
    s16 h208;
    s16 h20A;
    s16 h20C;
    s16 h20E;
    s16 h210;
    s16 h212;
    s16 h214;
    s16 h216;
    s16 h218;
    s16 h21A;
    s16 h21C;
    u8 pad21E[0x4];
    s16 h222;
    s16 h224;
    s16 h226;
    s16 h228;
    s16 h22A;
    s16 h22C;
    u8 pad22E[0x2];
    s32 w230;
    s32 w234;
    s32 w238;
    u8 pad23C[0xB4];
    s128_004CD998 q2F0;
    u8 pad300[0x3C];
    f32 f33C;
    u8 pad340[0x20];
    s32 w360;
    u8 pad364[0x4];
    s16 h368;
    u8 pad36A[0x4];
    s16 h36E;
    u8 pad370[0xEA0];
    s32 w1210;
    u8 pad1214[0x14];
    s32 w1228;
    u8 pad122C[0x208];
    s16 h1434;
    u8 pad1436[0x27A];
    s32 w16B0;
    u8 pad16B4[0x32C];
    s32 w19E0;
    u8 pad19E4[0x65C];
    s128_004CD998 v2040[32];
    u8 pad2240[0xA0];
    s128_004CD998 q22E0;
    u8 pad22F0[0x2D0];
    void *p25C0;
    s32 w25C4;
    u8 pad25C8[0x4];
    s32 w25CC;
    u8 pad25D0[0x14];
    u8 b25E4;
    u8 pad25E5[0x1];
    u8 b25E6;
    u8 pad25E7[0x2];
    u8 b25E9;
    u8 pad25EA[0x4];
    u8 b25EE;
    u8 pad25EF[0x5];
    u8 b25F4;
    u8 pad25F5[0xFF];
    s32 w26F4;
    s32 w26F8;
    u8 pad26FC[0x128];
    f32 f2824;
    f32 f2828;
    u8 pad282C[0x24];
    s32 w2850;
    u8 pad2854[0x10];
    f32 f2864;
    u8 pad2868[0x24];
    s16 h288C;
    u8 pad288E[0x3A];
    u8 b28C8;
    u8 b28C9;
} S_004CD998;
extern S_004CD998 D_001A4BE0;
extern u8 *D_001D52FC;
extern s32 D_001D545C;
extern s32 D_L30_001D6694;
extern s32 D_L30_001DF2C0;
extern f32 D_L30_001DF0D0;
extern f32 D_L30_001DF0D8;
typedef struct {
    u8 pad0[0x40];
    u16 h40;
    u8 pad42[0x36];
    u16 h78;
} U_004CD998;
extern U_004CD998 D_00142660;
extern u8 D_001439F4[];
extern u8 D_00142CA7[];
extern u8 *D_L30_0021C860[];
typedef struct {
    s32 w0;
    u8 pad4[0x6C];
} T_004CD998;
extern T_004CD998 D_L30_002F2A90[];

void func_L01_004F45F0(void);
s32 func_0038CB00(s16 *);
s32 func_0038CAD0(s32 *);
s32 func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
void func_L01_004AAC98(s32, s32, void *, s32);
void func_L01_00425A08(s32);
s32 func_L01_004BA800(void);
s32 func_L01_0041A4F0(void);
void func_003E54E0(s32);
s32 func_003A3BB8(s32, s32);
void func_L01_004E3268(void);
void func_L01_004ED658(s32);
s32 func_L01_004606E8(s32, s32, s32, s32);
void func_L01_004F5DC8(void);
s32 func_003C4B50(void *);
s32 func_00382468(s32);
f32 func_L01_0040E548(void *, void *);
void func_0038CF68(void *, void *, f32);
void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
f32 func_L01_005114B0(void *);
void func_0038CE20(void *, void *, f32);
f32 func_0038CEA8(void *);
void func_L01_004EDE10(void);
void func_L01_004FF3D0(void);
void func_L01_005110E8(void *, s32, f32, f32, f32);
void func_L01_00511158(void *, void *, f32);

void func_L30_004CD998(void) {
    vu0_v4 v;
    vu0_v4 d;
    u8 *m;
    s32 t;
    s32 i;
    s32 n;

    if (D_001A4BE0.b25E4 != 5 && D_001A4BE0.b25EE == 0) {
        func_L01_004F45F0();
    }
    (D_001A4BE0.w1B8)++;
    (D_001A4BE0.w1BC)++;
    (D_001A4BE0.w1C0)++;
    (D_001A4BE0.w1C4)++;
    func_0038CB00(&D_001A4BE0.h1E0);
    func_0038CB00(&D_001A4BE0.h1DC);
    func_0038CB00(&D_001A4BE0.h1D2);
    func_0038CB00(&D_001A4BE0.h1E4);
    func_0038CB00(&D_001A4BE0.h1F8);
    func_0038CB00(&D_001A4BE0.h1FE);
    func_0038CAD0(&D_001A4BE0.w1D4);
    func_0038CB00(&D_001A4BE0.h210);
    func_0038CB00(&D_001A4BE0.h1D0);
    func_0038CB00(&D_001A4BE0.h1F4);
    func_0038CB00(&D_001A4BE0.h1F6);
    func_0038CB00(&D_001A4BE0.h204);
    func_0038CB00(&D_001A4BE0.h206);
    func_0038CB00(&D_001A4BE0.h1F0);
    func_0038CB00(&D_001A4BE0.h1EC);
    func_0038CB00(&D_001A4BE0.h1EE);
    func_0038CB00(&D_001A4BE0.h208);
    func_0038CB00(&D_001A4BE0.h200);
    func_0038CB00(&D_001A4BE0.h20E);
    func_0038CB00(&D_001A4BE0.h20A);
    func_0038CB00(&D_001A4BE0.h214);
    func_0038CB00(&D_001A4BE0.h212);
    func_0038CB00(&D_001A4BE0.h1FC);
    func_0038CB00(&D_001A4BE0.h216);
    func_0038CB00(&D_001A4BE0.h1FA);
    func_0038CB00(&D_001A4BE0.h218);
    func_0038CB00(&D_001A4BE0.h1F2);
    func_0038CB00(&D_001A4BE0.h21A);
    func_0038CB00(&D_001A4BE0.h21C);
    func_0038CB00(&D_001A4BE0.h1DE);
    func_0038CB00(&D_001A4BE0.h1E6);
    func_0038CB00(&D_001A4BE0.h222);
    func_0038CB00(&D_001A4BE0.h224);
    func_0038CB00(&D_001A4BE0.h226);
    func_0038CB00(&D_001A4BE0.h22C);
    func_0038CAD0(&D_001A4BE0.w234);
    func_0038CAD0(&D_001A4BE0.w238);

    if (D_001D545C == 2 || D_001D545C == 4) {
        D_001A4BE0.h1FE = 8;
    }
    if (D_001A4BE0.w2850 <= 0 && D_001A4BE0.w234 >= 2) {
        D_001A4BE0.w234 = 1;
    }
    if (D_001A4BE0.w234 >= 2) {
        func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
        D_001A4BE0.b25E6 = 1;
        D_001A4BE0.b28C9 = 1;
    }
    t = D_001A4BE0.w234;
    if (t == 250 || t == 200 || t == 150 || t == 100 || t == 50 || t == 1) {
        func_L01_004AAC98(1, 0, D_001A4BE0.p25C0, 0x1F8);
        if (D_001A4BE0.w234 == 1) {
            D_00142660.h40 = D_00142660.h78;
            func_L01_00425A08(0);
            D_001A4BE0.b28C9 = 0;
        }
    }
    if (func_L01_004BA800() != 0 && D_001A4BE0.w234 != 0) {
        D_00142660.h40 = D_00142660.h78;
        func_L01_00425A08(0);
        D_001A4BE0.b28C9 = 0;
        D_001A4BE0.w234 = 1;
    }
    t = D_001A4BE0.w230;
    if (t == 250 || t == 200 || t == 150 || t == 100 || t == 50 || t == 1) {
        if (func_L01_0041A4F0() == 0) {
            func_L01_004AAC98(1, 0, D_001A4BE0.p25C0, 0x1F7);
        }
    }
    if (D_L30_001D6694 != 4) {
        func_0038CAD0(&D_001A4BE0.w230);
    }
    if (D_001A4BE0.w230 == 0) {
        D_001A4BE0.b28C8 = 0;
    } else {
        func_003E54E0(0x96);
    }
    if (!(*(s32 *)(D_001D52FC + 0x1A0) & func_003A3BB8(4, 0))) {
        D_001A4BE0.h20C = 0;
    }
    if (D_001A4BE0.h21C != 0) {
        func_L01_004E3268();
    }
    if (D_001A4BE0.b25E9 != 0) {
        (D_001A4BE0.w1D8)++;
    } else {
        D_001A4BE0.w1D8 = 0;
    }
    if (D_001439F4[0] != 0 && (D_001A4BE0.w1210 & 0x20)) {
        D_001A4BE0.w1210 |= 8;
    } else {
        D_001A4BE0.w1210 &= ~8;
    }
    if (D_001A4BE0.h288C != 0 && func_0038CB00(&D_001A4BE0.h288C) != 0
        && D_001A4BE0.w2850 != 0 && D_L30_001D6694 == 0 && D_001A4BE0.h368 == 0) {
        if (D_001A4BE0.b25E4 == 3) {
            func_L01_004ED658(0);
            if (func_L01_004606E8(0x80, 0xF, 0, 0) != 0) {
                D_001A4BE0.b25E6 = 1;
            }
        } else {
            func_L01_004F5DC8();
        }
    }
    if (*(s32 *)(D_001D52FC + 0x1D4) != 0) {
        D_001A4BE0.w1C8 = 0;
        (D_001A4BE0.w1CC)++;
    } else {
        (D_001A4BE0.w1C8)++;
        D_001A4BE0.w1CC = 0;
    }
    if (D_001A4BE0.b25F4 != 0 && D_001A4BE0.w25CC == 0 && D_001A4BE0.w360 != 0
        && D_001A4BE0.f170 < 0.002f && D_001A4BE0.f184 < 0.002f) {
        D_001A4BE0.u80.q = D_001A4BE0.q22E0;
    }
    if (D_001A4BE0.h1434 != 0) {
        D_001A4BE0.w1E8 = 0;
    } else if (D_001A4BE0.w16B0 == 1 && func_L01_004606E8(0x28, 2, 0, 0) != 0) {
        D_001A4BE0.w1E8 = 0;
    } else {
        (D_001A4BE0.w1E8)++;
    }
    if (D_L30_001D6694 == 0) {
        if (D_L30_001DF0D0 > 0.0f) {
            (D_001A4BE0.h22A)++;
        } else {
            D_001A4BE0.h22A = 0;
        }
        if (D_001A4BE0.h22A > 100) {
            D_L30_001DF0D0 = 0.0f;
            D_001A4BE0.h22A = 0;
        }
        if (D_L30_001DF0D8 > 0.0f) {
            (D_001A4BE0.h228)++;
        } else {
            D_001A4BE0.h228 = 0;
        }
        if (D_001A4BE0.h228 > 100) {
            D_001A4BE0.h228 = 0;
            D_L30_001DF0D8 = 0.0f;
        }
    }
    if (D_001A4BE0.h224 != 0 && D_001A4BE0.w1228 == 9) {
        for (i = 0; (m = D_L30_0021C860[i]) != 0; i++) {
            if (func_003C4B50(m) != 0
                || (m != 0 && *(u8 **)(m + 0x24) != 0 && (*(u8 **)(m + 0x24))[0x46] == 0x16)) {
                if (*(s16 *)(m + 0xAA) != 0x1F8) {
                    if ((D_L30_001DF2C0 & 7) == (((s32)m >> 8) & 7) || func_00382468(4) == 0) {
                        if (func_L01_0040E548(&D_001A4BE0.u80.q, m + 0x10) < 236.23689f) {
                            vec_sub_ab(&v, m + 0x10, &D_001A4BE0.u80.q);
                            func_0038CF68(&v, &v, 1.7f);
                            func_L01_00446A70(m, D_001A4BE0.p25C0, 0x8000000, &D_001A4BE0.u80.q, &v, 1.0f);
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < 4; i++) {
        func_0038CAD0((s32 *)&D_L30_002F2A90[i]);
    }
    D_001A4BE0.f2864 = 9999.0f;
    if (D_001A4BE0.w25C4 != 0x31 && D_001A4BE0.h36E != 0
        && func_L01_005114B0(&D_001A4BE0.qF0) < -0.0001f) {
        if (D_001A4BE0.w26F8 == 0x20) {
            n = 8;
            qzero(&v);
            for (i = 0; i < n; i++) {
                s32 a = (D_001A4BE0.w26F4 - i + 31) % 32;
                s32 b = (D_001A4BE0.w26F4 - i + 30) % 32;
                vec_sub_ab(&d, &D_001A4BE0.v2040[a], &D_001A4BE0.v2040[b]);

                vec_add_ab(&v, &v, &d);
            }
            func_0038CE20(&v, &v, 1.0f / n);
            if (func_0038CEA8(&v) < 0.020000001f) {
                (D_001A4BE0.h202)++;
            } else {
                D_001A4BE0.h202 = 0;
            }
        }
    } else {
        D_001A4BE0.h202 = 0;
    }
    if (D_001A4BE0.w25C4 == 0x7B || D_001A4BE0.w25CC == 2 || D_001A4BE0.w25CC == 4) {
        if (D_001A4BE0.h202 > 200) {
            func_L01_004EDE10();
        }
    }
    func_L01_004FF3D0();
    switch (D_001A4BE0.b25E4) {
    case 1:
        func_L01_005110E8(&D_001A4BE0.qE0, 1, 0.0f, 0.0f, 0.4f);
        break;
    case 5:
        func_L01_005110E8(&D_001A4BE0.qE0, 1, 0.0f, 0.0f, 0.7f);
        break;
    default:
        func_L01_005110E8(&D_001A4BE0.qE0, 1, 0.0f, 0.0f, 0.7f);
        break;
    }
    if ((D_L30_001DF2C0 & 3) == 0) {
        if (D_001A4BE0.b25E4 == 1) {
            D_001A4BE0.f2824 = 2.125f;
            D_001A4BE0.f2828 = 1.25f;
        } else if (D_00142CA7[0] != 0) {
            D_001A4BE0.f2824 = 17.0f;
            D_001A4BE0.f2828 = 4.5f;
        } else {
            D_001A4BE0.f2824 = 8.7f;
            D_001A4BE0.f2828 = 3.0f;
        }
    }
    if (D_001A4BE0.w19E0 == 0) {
        if (D_001A4BE0.f33C < 4.0f) {
            D_001A4BE0.qD0 = D_001A4BE0.q2F0;
            func_L01_00511158(&D_001A4BE0.qD0, &D_001A4BE0.qD0, 0.5f);
        } else {
            D_001A4BE0.qD0 = D_001A4BE0.qE0;
        }
    }
    if (D_001A4BE0.w25C4 == 0xA1 && D_001A4BE0.w1B8 >= 0x33) {
        func_L01_004EDE10();
    }
    if (D_001A4BE0.u80.f[2] < 1.0f) {
        func_L01_004EDE10();
    }
}
/* localdecomp:end func_L30_004CD998 */
