#include "common.h"

/* NTSC-U counterpart of func_L02_004D1C60 (src/levels/shared/L02_004D1C60.c) */
/* localdecomp:start func_L02_004CD958 */
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
extern s32 D_L02_001D6694_004CD958;
extern s32 D_L02_001DE540;
extern f32 D_L02_001DE350;
extern f32 D_L02_001DE358;
typedef struct {
    u8 pad0[0x40];
    u16 h40;
    u8 pad42[0x36];
    u16 h78;
} U_004CD998;
extern U_004CD998 D_00142660;
extern u8 D_001439F4[];
extern u8 D_00142CA7[];
extern u8 *D_L02_0021B920[];
typedef struct {
    s32 w0;
    u8 pad4[0x6C];
} T_004CD998;
extern T_004CD998 D_L02_002F1E50[];

void func_L01_004F07E8(void);
s32 func_003883C8(s16 *);
s32 func_00388398(s32 *);
s32 func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
void func_L01_004A72A8(s32, s32, void *, s32);
void func_L01_00422C60(s32);
s32 func_L01_004B6C68(void);
s32 func_L01_00417EA0(void);
void func_003DFF90(s32);
s32 func_0039E928(s32, s32);
void func_L01_004DF4A0(void);
void func_L02_004BEAD0(s32);
s32 func_L01_0045D358(s32, s32, s32, s32);
void func_L01_004F1FC0(void);
s32 func_003BF5E0(void *);
s32 func_0037E1D8(s32);
f32 func_L01_0040C018(void *, void *);
void func_00388830(void *, void *, f32);
void func_L01_00443938(void *, void *, s32, void *, void *, f32);
f32 func_L01_0050D4D8(void *);
void func_003886E8(void *, void *, f32);
f32 func_00388770(void *);
void func_L01_004EA040(void);
void func_L01_004FB518(void);
void func_L01_0050D110(void *, s32, f32, f32, f32);
void func_L01_0050D180(void *, void *, f32);

void func_L02_004CD958(void) {
    vu0_v4 v;
    vu0_v4 d;
    u8 *m;
    s32 t;
    s32 i;
    s32 n;

    if (D_001A4BE0.b25EE == 0) {
        func_L01_004F07E8();
    }
    (D_001A4BE0.w1B8)++;
    (D_001A4BE0.w1BC)++;
    (D_001A4BE0.w1C0)++;
    (D_001A4BE0.w1C4)++;
    func_003883C8(&D_001A4BE0.h1E0);
    func_003883C8(&D_001A4BE0.h1DC);
    func_003883C8(&D_001A4BE0.h1D2);
    func_003883C8(&D_001A4BE0.h1E4);
    func_003883C8(&D_001A4BE0.h1F8);
    func_003883C8(&D_001A4BE0.h1FE);
    func_00388398(&D_001A4BE0.w1D4);
    func_003883C8(&D_001A4BE0.h210);
    func_003883C8(&D_001A4BE0.h1D0);
    func_003883C8(&D_001A4BE0.h1F4);
    func_003883C8(&D_001A4BE0.h1F6);
    func_003883C8(&D_001A4BE0.h204);
    func_003883C8(&D_001A4BE0.h206);
    func_003883C8(&D_001A4BE0.h1F0);
    func_003883C8(&D_001A4BE0.h1EC);
    func_003883C8(&D_001A4BE0.h1EE);
    func_003883C8(&D_001A4BE0.h208);
    func_003883C8(&D_001A4BE0.h200);
    func_003883C8(&D_001A4BE0.h20E);
    func_003883C8(&D_001A4BE0.h20A);
    func_003883C8(&D_001A4BE0.h214);
    func_003883C8(&D_001A4BE0.h212);
    func_003883C8(&D_001A4BE0.h1FC);
    func_003883C8(&D_001A4BE0.h216);
    func_003883C8(&D_001A4BE0.h1FA);
    func_003883C8(&D_001A4BE0.h218);
    func_003883C8(&D_001A4BE0.h1F2);
    func_003883C8(&D_001A4BE0.h21A);
    func_003883C8(&D_001A4BE0.h21C);
    func_003883C8(&D_001A4BE0.h1DE);
    func_003883C8(&D_001A4BE0.h1E6);
    func_003883C8(&D_001A4BE0.h222);
    func_003883C8(&D_001A4BE0.h224);
    func_003883C8(&D_001A4BE0.h226);
    func_003883C8(&D_001A4BE0.h22C);
    func_00388398(&D_001A4BE0.w234);
    func_00388398(&D_001A4BE0.w238);

    if (D_001D545C == 2 || D_001D545C == 4) {
        D_001A4BE0.h1FE = 10;
    }
    if (D_001A4BE0.w2850 <= 0 && D_001A4BE0.w234 >= 2) {
        D_001A4BE0.w234 = 1;
    }
    if (D_001A4BE0.w234 >= 2) {
        func_L01_0044F2E8(0, 5, 0, 1, 0, 0, 0);
        D_001A4BE0.b25E6 = 1;
        D_001A4BE0.b28C9 = 1;
    }
    t = D_001A4BE0.w234;
    if (t == 300 || t == 240 || t == 180 || t == 120 || t == 60 || t == 1) {
        func_L01_004A72A8(1, 0, D_001A4BE0.p25C0, 0x1F8);
        if (D_001A4BE0.w234 == 1) {
            D_00142660.h40 = D_00142660.h78;
            func_L01_00422C60(0);
            D_001A4BE0.b28C9 = 0;
        }
    }
    if (func_L01_004B6C68() != 0 && D_001A4BE0.w234 != 0) {
        D_00142660.h40 = D_00142660.h78;
        func_L01_00422C60(0);
        D_001A4BE0.b28C9 = 0;
        D_001A4BE0.w234 = 1;
    }
    t = D_001A4BE0.w230;
    if (t == 300 || t == 240 || t == 180 || t == 120 || t == 60 || t == 1) {
        if (func_L01_00417EA0() == 0) {
            func_L01_004A72A8(1, 0, D_001A4BE0.p25C0, 0x1F7);
        }
    }
    if (D_L02_001D6694_004CD958 != 4) {
        func_00388398(&D_001A4BE0.w230);
    }
    if (D_001A4BE0.w230 == 0) {
        D_001A4BE0.b28C8 = 0;
    } else {
        func_003DFF90(0xB4);
    }
    if (!(*(s32 *)(D_001D52FC + 0x1A0) & func_0039E928(4, 0))) {
        D_001A4BE0.h20C = 0;
    }
    if (D_001A4BE0.h21C != 0) {
        func_L01_004DF4A0();
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
    if (D_001A4BE0.h288C != 0 && func_003883C8(&D_001A4BE0.h288C) != 0
        && D_001A4BE0.w2850 != 0 && D_L02_001D6694_004CD958 == 0 && D_001A4BE0.h368 == 0) {
        if (D_001A4BE0.b25E4 == 3) {
            func_L02_004BEAD0(0);
            if (func_L01_0045D358(0x80, 0x12, 0, 0) != 0) {
                D_001A4BE0.b25E6 = 1;
            }
        } else {
            func_L01_004F1FC0();
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
        && D_001A4BE0.f170 < 0.0016666668f && D_001A4BE0.f184 < 0.0016666668f) {
        D_001A4BE0.u80.q = D_001A4BE0.q22E0;
    }
    if (D_001A4BE0.h1434 != 0) {
        D_001A4BE0.w1E8 = 0;
    } else if (D_001A4BE0.w16B0 == 1 && func_L01_0045D358(0x28, 2, 0, 0) != 0) {
        D_001A4BE0.w1E8 = 0;
    } else {
        (D_001A4BE0.w1E8)++;
    }
    if (D_L02_001D6694_004CD958 == 0) {
        if (D_L02_001DE350 > 0.0f) {
            (D_001A4BE0.h22A)++;
        } else {
            D_001A4BE0.h22A = 0;
        }
        if (D_001A4BE0.h22A > 120) {
            D_L02_001DE350 = 0.0f;
            D_001A4BE0.h22A = 0;
        }
        if (D_L02_001DE358 > 0.0f) {
            (D_001A4BE0.h228)++;
        } else {
            D_001A4BE0.h228 = 0;
        }
        if (D_001A4BE0.h228 > 120) {
            D_001A4BE0.h228 = 0;
            D_L02_001DE358 = 0.0f;
        }
    }
    if (D_001A4BE0.h224 != 0 && D_001A4BE0.w1228 == 9) {
        for (i = 0; (m = D_L02_0021B920[i]) != 0; i++) {
            if (func_003BF5E0(m) != 0
                || (m != 0 && *(u8 **)(m + 0x24) != 0 && (*(u8 **)(m + 0x24))[0x46] == 0x16)) {
                if (*(s16 *)(m + 0xAA) != 0x1F8) {
                    if ((D_L02_001DE540 & 7) == (((s32)m >> 8) & 7) || func_0037E1D8(4) == 0) {
                        if (func_L01_0040C018(&D_001A4BE0.u80.q, m + 0x10) < 236.23689f) {
                            vec_sub_ab(&v, m + 0x10, &D_001A4BE0.u80.q);
                            func_00388830(&v, &v, 1.7f);
                            func_L01_00443938(m, D_001A4BE0.p25C0, 0x8000000, &D_001A4BE0.u80.q, &v, 1.0f);
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < 4; i++) {
        func_00388398((s32 *)&D_L02_002F1E50[i]);
    }
    D_001A4BE0.f2864 = 9999.0f;
    if (D_001A4BE0.w25C4 != 0x31 && D_001A4BE0.h36E != 0
        && func_L01_0050D4D8(&D_001A4BE0.qF0) < -0.0001f) {
        if (D_001A4BE0.w26F8 == 0x20) {
            n = 8;
            qzero(&v);
            for (i = 0; i < n; i++) {
                s32 a = (D_001A4BE0.w26F4 - i + 31) % 32;
                s32 b = (D_001A4BE0.w26F4 - i + 30) % 32;
                vec_sub_ab(&d, &D_001A4BE0.v2040[a], &D_001A4BE0.v2040[b]);

                vec_add_ab(&v, &v, &d);
            }
            func_003886E8(&v, &v, 1.0f / n);
            if (func_00388770(&v) < 0.016666668f) {
                (D_001A4BE0.h202)++;
            } else {
                D_001A4BE0.h202 = 0;
            }
        }
    } else {
        D_001A4BE0.h202 = 0;
    }
    if (D_001A4BE0.w25C4 == 0x7B || D_001A4BE0.w25CC == 2 || D_001A4BE0.w25CC == 4) {
        if (D_001A4BE0.h202 > 240) {
            func_L01_004EA040();
        }
    }
    func_L01_004FB518();
    func_L01_0050D110(&D_001A4BE0.qE0, 1, 0.0f, 0.0f, 0.7f);
    if ((D_L02_001DE540 & 3) == 0) {
        if (D_00142CA7[0] != 0) {
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
            func_L01_0050D180(&D_001A4BE0.qD0, &D_001A4BE0.qD0, 0.5f);
        } else {
            D_001A4BE0.qD0 = D_001A4BE0.qE0;
        }
    }
    if (D_001A4BE0.u80.f[2] < 1.0f) {
        func_L01_004EA040();
    }
}
/* localdecomp:end func_L02_004CD958 */
