#include "common.h"

typedef struct {
    u8 pad0[152];
    float f98;
    u8 pad1[400 - 156];
    u8 sub190[16];
    float f1A0;
    u8 pad2[5172 - 420];
    s16 h1434;
    u8 pad3;
    u8 b1437;
    u8 pad4[5808 - 5176];
    s32 mode;
    u8 pad5[9716 - 5812];
    u8 b25F4;
} Veldin1A4BE0;
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec_4FB8C8;
typedef union {
    s128 q;
    Vec_4FB8C8 v;
} Q_4FB8C8;
typedef struct {
    u8 pad0[28];
    s32 x28;
    f32 f32;
} Pvar_4FB8C8;
typedef struct {
    u8 pad0[16];
    s128 pos;
    u8 pad32[17];
    u8 b49;
    u8 pad50[2];
    u16 h52;
    u8 pad54[50];
    Pvar_4FB8C8 *pv;
} Moby_4FB8C8;
typedef struct {
    u8 pad0[128];
    s128 v128;
    u8 pad144[8];
    f32 f152;
    u8 pad156[374];
    s16 h530;
    u8 pad532[2108];
    Moby_4FB8C8 *target;
    u8 pad2644[4];
    f32 f2648;
    u8 pad2652[2];
    s16 h2654;
    u8 pad2656[7012];
    s32 x9668;
} Player_4FB8C8;
typedef struct {
    u8 p0[16];
    s128 pos;
    u8 p20[17];
    u8 b49;
    u8 p50;
    u16 h52;
    u8 p54[116];
    s16 h170;
} M_4FBE48;
typedef struct {
    u8 p0[128];
    s128 v128;
    u8 p90[8];
    float f152;
    u8 p9C[1360];
    float f1516;
    u8 p5F0[1184];
    M_4FBE48 *f2704;
    s32 f2708;
    u8 pA98[6964];
    s32 f9676;
} G_4FBE48;
typedef struct {
    u8 p0[9540];
    s32 f9540;
} H_4FBE48;
typedef struct {
    u8 pad0[0x1B8];
    s32 x1B8;
    u8 pad1BC[0x23D4 - 0x1BC];
    s32 x23D4[16];
    s32 x2414[16];
    s32 x2454[16];
    s32 x2494;
    u8 pad2498[0x25C4 - 0x2498];
    s32 x25C4;
    s32 x25C8;
    s32 x25CC;
    s32 x25D0;
    s32 x25D4;
    s32 x25D8;
    s32 x25DC;
    s32 x25E0;
} G_4FC2D0;
typedef struct {
    u8 pad0[440];
    s32 start;
    u8 pad1[9172 - 444];
    s32 ids[32];
    s32 lens[16];
    s32 count;
} S_4FC388;
typedef struct {
    u8 p0[0x1A0];
    s32 w1A0;
} S_00502368;
typedef struct {
    u8 p0[0x1434];
    s16 h1434;
    u8 p1436[0x16B0 - 0x1436];
    s32 w16B0;
    u8 p16B4[0x2838 - 0x16B4];
    f32 f2838;
} G_00502368;

typedef struct {
    u8 pad0[0x284];
    f32 scale;
    u8 pad288[0x298 - 0x288];
    f32 height;
    u8 pad29C[4];
    f32 angle;
    u8 first_flag;
    u8 second_flag;
    u8 pad2A6[2];
    f32 distance;
    f32 clearance;
    s32 valid;
    u8 pad2B4[0x360 - 0x2B4];
    s32 enabled;
    u8 pad364[0x25C0 - 0x364];
    s32 object;
    u8 pad25C4[0x25EE - 0x25C4];
    u8 gate;
} Gate_004FE668;
typedef struct {
    u8 pad0[0x18];
    s32 object;
    u8 pad1C[4];
    f32 hit_position[4];
    u8 pad30[0x10];
    f32 direction[4];
} Dir_004FE668;

/* localdecomp:start func_L01_004FE668 */
extern Gate_004FE668 D_1A4BE0;
extern Dir_004FE668 D_L01_001EAA00;
extern s32 D_L01_001DFB40;

extern void func_L01_004F0B78(void);
extern s32 func_L01_004E63F0(f32 *, f32, f32);
extern f32 func_0038CED8(f32 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern s32 func_003C4B50(s32);
extern void func_L01_005110E8(f32 *, f32, f32, f32, s32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern s32 func_L01_003FB640(f32 *, s32, s32, f32);

void func_L01_004FE668(void)
{
    f32 first[4], second[4], probe[4];
    if (D_1A4BE0.gate != 0) return;
    func_L01_004F0B78();
    if (D_L01_001DFB40 % 3 == 0) {
        D_1A4BE0.height = 4.0f;
        D_1A4BE0.first_flag = 0;
        D_1A4BE0.second_flag = 0;
        if (func_L01_004E63F0(&D_1A4BE0.height, 0.7f, 4.0f)) {
            D_1A4BE0.angle = func_0038D160(D_L01_001EAA00.direction[2], func_0038CED8(D_L01_001EAA00.direction));
            if (D_L01_001EAA00.object) {
                D_1A4BE0.second_flag = 1;
                if (func_003C4B50(D_L01_001EAA00.object)) D_1A4BE0.first_flag = 1;
            }
        }
    }
    if (D_L01_001DFB40 % 5 == 0) {
        s32 hit;
        f32 distance, offset;
        D_1A4BE0.valid = 0;
        D_1A4BE0.distance = 0.0f;
        if (D_1A4BE0.enabled == 0) return;
        func_L01_005110E8(first, 1.1f, 0.0f, 1.0f, 1);
        func_L01_005110E8(second, 1.1f, 0.0f, -20.0f, 1);
        if (second[2] < 0.5f) second[2] = 0.5f;
        distance = 20.0f;
        hit = func_003D3CB0(first, second, 2, D_1A4BE0.object, 0);
        if (hit) distance = func_0038CF00(first, D_L01_001EAA00.hit_position);
        if (!hit || 3.0f < distance) {
            offset = -0.4f;
            do {
                func_L01_005110E8(probe, offset + 1.1f, 0.0f, 0.0f, 1);
                if (!func_L01_003FB640(probe, 2, 0, D_1A4BE0.scale)) {
                    D_1A4BE0.valid = 1;
                    if (!hit) D_1A4BE0.distance = 20.0f;
                    else D_1A4BE0.distance = distance;
                    D_1A4BE0.clearance = D_1A4BE0.scale + offset;
                    if (D_1A4BE0.clearance < 0.0f) D_1A4BE0.clearance = 0.0f;
                    return;
                }
                offset += 0.1f;
            } while (offset < 0.5f);
        }
    }
}
/* localdecomp:end func_L01_004FE668 */

/* localdecomp:start func_L01_004FE920 */
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
extern S_004CD998 D_001A4BE0_004FE920;
extern u8 *D_001D52FC_004FE920;
extern s32 D_001D545C;
extern s32 D_L01_001D6694;
extern s32 D_L01_001DFB40;
extern f32 D_L01_001DF950;
extern f32 D_L01_001DF958;
typedef struct {
    u8 pad0[0x40];
    u16 h40;
    u8 pad42[0x36];
    u16 h78;
} U_004CD998;
extern U_004CD998 D_00142660;
extern u8 D_001439F4[];
extern u8 D_00142CA7[];
extern u8 *D_L01_0021E860[];
typedef struct {
    s32 w0;
    u8 pad4[0x6C];
} T_004CD998;
extern T_004CD998 D_L01_002F4390[];

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
s32 func_00382468(s32);
f32 func_L01_0040E548(void *, void *);
void func_0038CF68(void *, void *, f32);
void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
f32 func_L01_005114B0(void *);
void func_0038CE20(void *, void *, f32);
f32 func_0038CEA8(void *);
void func_L01_004EDE10(void);
void func_L01_004FF3D0(void);
void func_L01_00511158(void *, void *, f32);

void func_L01_004FE920(void) {
    vu0_v4 v;
    vu0_v4 d;
    u8 *m;
    s32 t;
    s32 i;
    s32 n;

    if (D_001A4BE0_004FE920.b25EE == 0) {
        func_L01_004F45F0();
    }
    (D_001A4BE0_004FE920.w1B8)++;
    (D_001A4BE0_004FE920.w1BC)++;
    (D_001A4BE0_004FE920.w1C0)++;
    (D_001A4BE0_004FE920.w1C4)++;
    func_0038CB00(&D_001A4BE0_004FE920.h1E0);
    func_0038CB00(&D_001A4BE0_004FE920.h1DC);
    func_0038CB00(&D_001A4BE0_004FE920.h1D2);
    func_0038CB00(&D_001A4BE0_004FE920.h1E4);
    func_0038CB00(&D_001A4BE0_004FE920.h1F8);
    func_0038CB00(&D_001A4BE0_004FE920.h1FE);
    func_0038CAD0(&D_001A4BE0_004FE920.w1D4);
    func_0038CB00(&D_001A4BE0_004FE920.h210);
    func_0038CB00(&D_001A4BE0_004FE920.h1D0);
    func_0038CB00(&D_001A4BE0_004FE920.h1F4);
    func_0038CB00(&D_001A4BE0_004FE920.h1F6);
    func_0038CB00(&D_001A4BE0_004FE920.h204);
    func_0038CB00(&D_001A4BE0_004FE920.h206);
    func_0038CB00(&D_001A4BE0_004FE920.h1F0);
    func_0038CB00(&D_001A4BE0_004FE920.h1EC);
    func_0038CB00(&D_001A4BE0_004FE920.h1EE);
    func_0038CB00(&D_001A4BE0_004FE920.h208);
    func_0038CB00(&D_001A4BE0_004FE920.h200);
    func_0038CB00(&D_001A4BE0_004FE920.h20E);
    func_0038CB00(&D_001A4BE0_004FE920.h20A);
    func_0038CB00(&D_001A4BE0_004FE920.h214);
    func_0038CB00(&D_001A4BE0_004FE920.h212);
    func_0038CB00(&D_001A4BE0_004FE920.h1FC);
    func_0038CB00(&D_001A4BE0_004FE920.h216);
    func_0038CB00(&D_001A4BE0_004FE920.h1FA);
    func_0038CB00(&D_001A4BE0_004FE920.h218);
    func_0038CB00(&D_001A4BE0_004FE920.h1F2);
    func_0038CB00(&D_001A4BE0_004FE920.h21A);
    func_0038CB00(&D_001A4BE0_004FE920.h21C);
    func_0038CB00(&D_001A4BE0_004FE920.h1DE);
    func_0038CB00(&D_001A4BE0_004FE920.h1E6);
    func_0038CB00(&D_001A4BE0_004FE920.h222);
    func_0038CB00(&D_001A4BE0_004FE920.h224);
    func_0038CB00(&D_001A4BE0_004FE920.h226);
    func_0038CB00(&D_001A4BE0_004FE920.h22C);
    func_0038CAD0(&D_001A4BE0_004FE920.w234);
    func_0038CAD0(&D_001A4BE0_004FE920.w238);

    if (D_001D545C == 2 || D_001D545C == 4) {
        D_001A4BE0_004FE920.h1FE = 8;
    }
    if (D_001A4BE0_004FE920.w2850 <= 0 && D_001A4BE0_004FE920.w234 >= 2) {
        D_001A4BE0_004FE920.w234 = 1;
    }
    if (D_001A4BE0_004FE920.w234 >= 2) {
        func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
        D_001A4BE0_004FE920.b25E6 = 1;
        D_001A4BE0_004FE920.b28C9 = 1;
    }
    t = D_001A4BE0_004FE920.w234;
    if (t == 250 || t == 200 || t == 150 || t == 100 || t == 50 || t == 1) {
        func_L01_004AAC98(1, 0, D_001A4BE0_004FE920.p25C0, 0x1F8);
        if (D_001A4BE0_004FE920.w234 == 1) {
            D_00142660.h40 = D_00142660.h78;
            func_L01_00425A08(0);
            D_001A4BE0_004FE920.b28C9 = 0;
        }
    }
    if (func_L01_004BA800() != 0 && D_001A4BE0_004FE920.w234 != 0) {
        D_00142660.h40 = D_00142660.h78;
        func_L01_00425A08(0);
        D_001A4BE0_004FE920.b28C9 = 0;
        D_001A4BE0_004FE920.w234 = 1;
    }
    t = D_001A4BE0_004FE920.w230;
    if (t == 250 || t == 200 || t == 150 || t == 100 || t == 50 || t == 1) {
        if (func_L01_0041A4F0() == 0) {
            func_L01_004AAC98(1, 0, D_001A4BE0_004FE920.p25C0, 0x1F7);
        }
    }
    if (D_L01_001D6694 != 4) {
        func_0038CAD0(&D_001A4BE0_004FE920.w230);
    }
    if (D_001A4BE0_004FE920.w230 == 0) {
        D_001A4BE0_004FE920.b28C8 = 0;
    } else {
        func_003E54E0(0x96);
    }
    if (!(*(s32 *)(D_001D52FC_004FE920 + 0x1A0) & func_003A3BB8(4, 0))) {
        D_001A4BE0_004FE920.h20C = 0;
    }
    if (D_001A4BE0_004FE920.h21C != 0) {
        func_L01_004E3268();
    }
    if (D_001A4BE0_004FE920.b25E9 != 0) {
        (D_001A4BE0_004FE920.w1D8)++;
    } else {
        D_001A4BE0_004FE920.w1D8 = 0;
    }
    if (D_001439F4[0] != 0 && (D_001A4BE0_004FE920.w1210 & 0x20)) {
        D_001A4BE0_004FE920.w1210 |= 8;
    } else {
        D_001A4BE0_004FE920.w1210 &= ~8;
    }
    if (D_001A4BE0_004FE920.h288C != 0 && func_0038CB00(&D_001A4BE0_004FE920.h288C) != 0
        && D_001A4BE0_004FE920.w2850 != 0 && D_L01_001D6694 == 0 && D_001A4BE0_004FE920.h368 == 0) {
        if (D_001A4BE0_004FE920.b25E4 == 3) {
            func_L01_004ED658(0);
            if (func_L01_004606E8(0x80, 0xF, 0, 0) != 0) {
                D_001A4BE0_004FE920.b25E6 = 1;
            }
        } else {
            func_L01_004F5DC8();
        }
    }
    if (*(s32 *)(D_001D52FC_004FE920 + 0x1D4) != 0) {
        D_001A4BE0_004FE920.w1C8 = 0;
        (D_001A4BE0_004FE920.w1CC)++;
    } else {
        (D_001A4BE0_004FE920.w1C8)++;
        D_001A4BE0_004FE920.w1CC = 0;
    }
    if (D_001A4BE0_004FE920.b25F4 != 0 && D_001A4BE0_004FE920.w25CC == 0 && D_001A4BE0_004FE920.w360 != 0
        && D_001A4BE0_004FE920.f170 < 0.002f && D_001A4BE0_004FE920.f184 < 0.002f) {
        D_001A4BE0_004FE920.u80.q = D_001A4BE0_004FE920.q22E0;
    }
    if (D_001A4BE0_004FE920.h1434 != 0) {
        D_001A4BE0_004FE920.w1E8 = 0;
    } else if (D_001A4BE0_004FE920.w16B0 == 1 && func_L01_004606E8(0x28, 2, 0, 0) != 0) {
        D_001A4BE0_004FE920.w1E8 = 0;
    } else {
        (D_001A4BE0_004FE920.w1E8)++;
    }
    if (D_L01_001D6694 == 0) {
        if (D_L01_001DF950 > 0.0f) {
            (D_001A4BE0_004FE920.h22A)++;
        } else {
            D_001A4BE0_004FE920.h22A = 0;
        }
        if (D_001A4BE0_004FE920.h22A > 100) {
            D_L01_001DF950 = 0.0f;
            D_001A4BE0_004FE920.h22A = 0;
        }
        if (D_L01_001DF958 > 0.0f) {
            (D_001A4BE0_004FE920.h228)++;
        } else {
            D_001A4BE0_004FE920.h228 = 0;
        }
        if (D_001A4BE0_004FE920.h228 > 100) {
            D_001A4BE0_004FE920.h228 = 0;
            D_L01_001DF958 = 0.0f;
        }
    }
    if (D_001A4BE0_004FE920.h224 != 0 && D_001A4BE0_004FE920.w1228 == 9) {
        for (i = 0; (m = D_L01_0021E860[i]) != 0; i++) {
            if (func_003C4B50((s32)m) != 0
                || (m != 0 && *(u8 **)(m + 0x24) != 0 && (*(u8 **)(m + 0x24))[0x46] == 0x16)) {
                if (*(s16 *)(m + 0xAA) != 0x1F8) {
                    if ((D_L01_001DFB40 & 7) == (((s32)m >> 8) & 7) || func_00382468(4) == 0) {
                        if (func_L01_0040E548(&D_001A4BE0_004FE920.u80.q, m + 0x10) < 236.23689f) {
                            vec_sub_ab(&v, m + 0x10, &D_001A4BE0_004FE920.u80.q);
                            func_0038CF68(&v, &v, 1.7f);
                            func_L01_00446A70(m, D_001A4BE0_004FE920.p25C0, 0x8000000, &D_001A4BE0_004FE920.u80.q, &v, 1.0f);
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < 4; i++) {
        func_0038CAD0((s32 *)&D_L01_002F4390[i]);
    }
    D_001A4BE0_004FE920.f2864 = 9999.0f;
    if (D_001A4BE0_004FE920.w25C4 != 0x31 && D_001A4BE0_004FE920.h36E != 0
        && func_L01_005114B0(&D_001A4BE0_004FE920.qF0) < -0.0001f) {
        if (D_001A4BE0_004FE920.w26F8 == 0x20) {
            n = 8;
            qzero(&v);
            for (i = 0; i < n; i++) {
                s32 a = (D_001A4BE0_004FE920.w26F4 - i + 31) % 32;
                s32 b = (D_001A4BE0_004FE920.w26F4 - i + 30) % 32;
                vec_sub_ab(&d, &D_001A4BE0_004FE920.v2040[a], &D_001A4BE0_004FE920.v2040[b]);

                vec_add_ab(&v, &v, &d);
            }
            func_0038CE20(&v, &v, 1.0f / n);
            if (func_0038CEA8(&v) < 0.020000001f) {
                (D_001A4BE0_004FE920.h202)++;
            } else {
                D_001A4BE0_004FE920.h202 = 0;
            }
        }
    } else {
        D_001A4BE0_004FE920.h202 = 0;
    }
    if (D_001A4BE0_004FE920.w25C4 == 0x7B || D_001A4BE0_004FE920.w25CC == 2 || D_001A4BE0_004FE920.w25CC == 4) {
        if (D_001A4BE0_004FE920.h202 > 200) {
            func_L01_004EDE10();
        }
    }
    func_L01_004FF3D0();
    if (D_001A4BE0_004FE920.b25E4 == 1) {
        func_L01_005110E8((f32 *)&D_001A4BE0_004FE920.qE0, 0.0f, 0.0f, 0.4f, 1);
    } else {
        func_L01_005110E8((f32 *)&D_001A4BE0_004FE920.qE0, 0.0f, 0.0f, 0.7f, 1);
    }
    if ((D_L01_001DFB40 & 3) == 0) {
        if (D_001A4BE0_004FE920.b25E4 == 1) {
            D_001A4BE0_004FE920.f2824 = 2.125f;
            D_001A4BE0_004FE920.f2828 = 1.25f;
        } else if (D_00142CA7[0] != 0) {
            D_001A4BE0_004FE920.f2824 = 17.0f;
            D_001A4BE0_004FE920.f2828 = 4.5f;
        } else {
            D_001A4BE0_004FE920.f2824 = 8.7f;
            D_001A4BE0_004FE920.f2828 = 3.0f;
        }
    }
    if (D_001A4BE0_004FE920.w19E0 == 0) {
        if (D_001A4BE0_004FE920.f33C < 4.0f) {
            D_001A4BE0_004FE920.qD0 = D_001A4BE0_004FE920.q2F0;
            func_L01_00511158(&D_001A4BE0_004FE920.qD0, &D_001A4BE0_004FE920.qD0, 0.5f);
        } else {
            D_001A4BE0_004FE920.qD0 = D_001A4BE0_004FE920.qE0;
        }
    }
    if (D_001A4BE0_004FE920.u80.f[2] < 1.0f) {
        func_L01_004EDE10();
    }
}
/* localdecomp:end func_L01_004FE920 */

/* localdecomp:start func_L01_004FF3D0 */
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_004482A0(f32 *value, f32 target, f32 *rate, f32 gain, f32 damping, f32 cap);

void func_L01_004FF3D0(void)
{
    u8 *p = (u8 *)&D_1A4BE0;
    f32 v;
    f32 dist, range, ang;

    if (*(u8 *)(p + 0x2A7) != 0) {
        if (0.0f < *(f32 *)(p + 0x33C)) {
            if (*(f32 *)(p + 0x170) < 0.060000002f) {
                dist = func_0038CEA8(p + 0xF0);
                if (dist < 0.060000002f) {
                    if (*(f32 *)(p + 0x2838) < 0.2f) {
                        int state = *(int *)(p + 0x25CC);

                        if (state == 0 || state == 2 || state == 4 || state == 10
                            || state == 1) {
                            u8 *q = (u8 *)&D_1A4BE0;

                            *(short *)(q + 0x20A) = 4;
                        }
                    }
                }
            }
        }
    }
    p = (u8 *)&D_1A4BE0;
    if (*(short *)(p + 0x20A) != 0) {
        dist = func_0038CF38(p + 0x80, p + 0x260);
        range = *(f32 *)(p + 0x284) * 0.9f;
        if (dist < range) {
            f32 dx = *(f32 *)(p + 0x80) - *(f32 *)(p + 0x260);
            f32 dy = *(f32 *)(p + 0x84) - *(f32 *)(p + 0x264);

            ang = func_0038D160(dx, dy);
            if (dist < *(f32 *)(p + 0x284) * 0.05f)
                ang = *(f32 *)(p + 0x98);
            v = dist - range;
            func_L01_004482A0(&v, 0.0f, (f32 *)(p + 0x294), 0.0432f, 0.43200003f, 0.056f);
            *(f32 *)(p + 0x100) = func_0038D098(ang) * *(f32 *)(p + 0x294);
            *(f32 *)(p + 0x104) = func_0038D0B0(ang) * *(f32 *)(p + 0x294);
            *(f32 *)(p + 0x108) = 0.0f;
        }
    } else {
        *(int *)(p + 0x294) = 0;
    }
}
/* localdecomp:end func_L01_004FF3D0 */

/* localdecomp:start func_L01_004FF5D8 */
extern s32 func_L01_004FF610(void);

s32 func_L01_004FF5D8(void) {
    s32 n = 10;
    s32 x = func_L01_004FF610();

    goto test;
zero:
    n = 0;
    goto done;
test:
    if (x == 2)
        goto zero;
done:
    return n;
}
/* localdecomp:end func_L01_004FF5D8 */

/* localdecomp:start func_L01_004FF610 */

extern Veldin1A4BE0 D_001A4BE0;
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern void func_L01_004EE850(s32, float);
extern float func_L01_004F4E20(void *, s32);
extern float func_0038DB00(float, float);
extern float func_0038DBA0(float, float);
s32 func_L01_004FF610(void) {
    s32 r = 2;
    s32 c;
    float a;
    float k;

    if (D_001A4BE0.h1434 != 0 || (D_001A4BE0.mode == 1 && func_L01_004606E8(40, 2, 0, 0) != 0)) {
        c = D_001A4BE0.b1437;
        if (c == 0) {
            r = 0;
        } else if (c == 3) {
            r = 3;
        } else if (c == 2) {
            r = 2;
        } else {
            r = 1;
        }
    } else {
        func_L01_004EE850(0, 1.0f);
        if (D_001A4BE0.b25F4 != 0) {
            a = func_L01_004F4E20(D_001A4BE0.sub190, 0);
        } else {
            a = func_0038DB00(D_001A4BE0.f1A0, D_001A4BE0.f98);
        }
        k = 0.7853982f;
        if (func_0038DBA0(a, 3.1415927f) < k) {
            r = 3;
        } else if (func_0038DBA0(a, -1.5707964f) < k) {
            r = 1;
        } else if (func_0038DBA0(a, 1.5707964f) < k) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L01_004FF610 */

/* localdecomp:start func_L01_004FF780 */
extern Veldin1A4BE0 D_001A4BE0;






extern Moby_4FB8C8 *D_L01_001F02E8[];
extern f32 func_0038CF00(void *a, void *b);
extern f32 func_L01_004E9470(f32 a, f32 b, f32 c, f32 d, Moby_4FB8C8 *m, s32 *out);
extern s32 func_00382380(void *v, s32 a, s32 b);
extern s32 func_003D3CB0(void *a, void *b, s32 c, s32 d, s32 e);

void func_L01_004FF780(void) {
    Player_4FB8C8 *pl;
    Player_4FB8C8 *pe;
    Player_4FB8C8 *pk;
    Moby_4FB8C8 *m;
    Moby_4FB8C8 *best_m;
    Pvar_4FB8C8 *pv;
    f32 best;
    f32 d;
    f32 lim;
    f32 a2;
    f32 c;
    f32 a;
    f32 b;
    f32 score;
    s32 i;
    Q_4FB8C8 v0;
    Q_4FB8C8 v1;

    ((Player_4FB8C8 *)&D_001A4BE0)[0].h2654 = 0;
    if (((Player_4FB8C8 *)&D_001A4BE0)[0].h530 != 0) {
        return;
    }
    best = 100000000.0f;
    best_m = 0;
    for (i = 0; i < 32; i++) {
        s32 flag;

        m = D_L01_001F02E8[i];
        if (m == 0) {
            break;
        }
        pv = m->pv;
        if (m->h52 & 1) {
            continue;
        }
        if (!(m->h52 & 0x1000)) {
            continue;
        }
        pl = ((Player_4FB8C8 *)&D_001A4BE0);
        if (3.0f < ((Vec_4FB8C8 *)&pl->v128)->z - ((Vec_4FB8C8 *)&m->pos)->z) {
            continue;
        }
        d = func_0038CF00(&pl->v128, &m->pos);
        if (pv->f32 != 0.0f && pv->f32 < d) {
            continue;
        }
        if (16.0f < d) {
            continue;
        }
        a = 1.2217305f;
        if (pl->x9668 == 44) {
            a = 1.5707964f;
        }
        b = 1.3962634f;
        if (pl->x9668 == 1 || pl->x9668 == 29) {
            b = 0.08726646f;
            a = b;
        }
        a2 = pv->f32;
        pk = ((Player_4FB8C8 *)&D_001A4BE0);
        c = pk->f152;
        lim = 16.0f;
        if (a2 != 0.0f) {
            lim = a2;
        }
        score = func_L01_004E9470(c, lim, a, b, m, &flag);
        if (flag != 0) {
            continue;
        }
        if (m->b49 == 0) {
            score += 10.0f;
        }
        if (pv->x28 >= 0 && func_00382380(&pk->v128, pv->x28, 0)) {
            continue;
        }
        if (score < best) {
            best = score;
            best_m = m;
        }
    }
    pe = ((Player_4FB8C8 *)&D_001A4BE0);
    pe->target = best_m;
    if (best_m != 0) {
        v0.q = pe->v128;
        v0.v.z += 0.5f;
        v1.q = best_m->pos;
        if (func_003D3CB0(&v0, &v1, 2, 0, 0) == 0) {
            pe->f2648 = best;
            pe->h2654 = 1;
        }
    }
}
/* localdecomp:end func_L01_004FF780 */

/* localdecomp:start func_L01_004FFA10 */
typedef struct {
    s32 x0;
    f32 f4;
    s32 x8;
    u8 pad0C[0x1C - 0xC];
    s32 x1C;
    f32 f20;
} Pv_4FFA10;
typedef struct {
    u8 p0[16];
    s128 pos;
    u8 p20[17];
    u8 b49;
    u8 p50[2];
    u16 h52;
    u8 p54[50];
    Pv_4FFA10 *pv;
} M_4FFA10;
typedef struct {
    u8 p0[0x80];
    s128 v128;
    u8 p90[8];
    f32 f152;
    u8 p9C[0x212 - 0x9C];
    s16 h530;
    u8 p214[0x5EC - 0x214];
    f32 f1516;
    u8 p5F0[0xA24 - 0x5F0];
    M_4FFA10 *target;
    s32 found;
    u8 pA2C[0xA38 - 0xA2C];
    s32 xA38;
    u8 pA3C[4];
    f32 fA40;
    f32 fA44;
    u8 pA48[0x25CC - 0xA48];
    s32 mode;
} G_4FFA10;

extern Veldin1A4BE0 D_001A4BE0;
extern H_4FBE48 D_001A4C60;
extern M_4FFA10 *D_L01_001F0368[];
extern f32 func_L01_004E9470(f32 a, f32 b, f32 c, f32 d, Moby_4FB8C8 *m, s32 *out);
extern float func_0038CF00(void *, void *);
extern float func_0038CF38(void *, void *);
extern s32 func_00382380(void *v, s32 a, s32 b);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);

s32 func_L01_004FFA10(void) {
    M_4FFA10 *m;
    Pv_4FFA10 *pv;
    float bestDist, d, a, c, e, lim, score;
    s32 out;
    s128 v[2];
    M_4FFA10 *best;
    s32 i;

    if ((*(G_4FFA10 *)&D_001A4BE0).mode == 13) return (*(G_4FFA10 *)&D_001A4BE0).found;
    (*(G_4FFA10 *)&D_001A4BE0).found = 0;
    if ((*(G_4FFA10 *)&D_001A4BE0).h530 != 0) return 0;
    bestDist = 100000000.0f;
    best = 0;
    for (i = 0; i < 32; i++) {
        m = D_L01_001F0368[i];
        if (m == 0) break;
        if (m->h52 & 1) continue;
        if (!(m->h52 & 0x1000)) continue;
        pv = m->pv;
        if (pv->x0 != 0) continue;
        d = func_0038CF00(&D_001A4C60, &m->pos);
        if (pv->f20 != 0.0f && pv->f20 < d) continue;
        if (30.0f < d) continue;
        c = 0.52359879f;
        e = -1.0f;
        if (D_001A4C60.f9540 == 1 || D_001A4C60.f9540 == 29) {
            c = e = 0.08726646f;
        }
        a = (*(G_4FFA10 *)&D_001A4BE0).f152;
        if ((*(G_4FFA10 *)&D_001A4BE0).mode == 15) a = (*(G_4FFA10 *)&D_001A4BE0).f1516;
        lim = 30.0f;
        if (pv->f20 != 0.0f) lim = pv->f20;
        score = func_L01_004E9470(a, lim, c, e, (Moby_4FB8C8 *)m, &out);
        if (out != 0) continue;
        if (func_0038CF38(&(*(G_4FFA10 *)&D_001A4BE0).v128, &m->pos) < 4.0f) continue;
        if (m->b49 == 0) score += 10.0f;
        if (pv->x1C >= 0 && func_00382380(&(*(G_4FFA10 *)&D_001A4BE0).v128, pv->x1C, 0)) continue;
        if (score < bestDist) {
            bestDist = score;
            best = m;
        }
    }
    if (best) {
        Pv_4FFA10 *bp;

        v[0] = (*(G_4FFA10 *)&D_001A4BE0).v128;
        (*(G_4FFA10 *)&D_001A4BE0).target = best;
        ((float *)&v[0])[2] += 0.5f;
        v[1] = best->pos;
        bp = best->pv;
        (*(G_4FFA10 *)&D_001A4BE0).xA38 = bp->x8;
        (*(G_4FFA10 *)&D_001A4BE0).fA40 = bp->f4;
        (*(G_4FFA10 *)&D_001A4BE0).fA44 = bestDist;
        if (func_003D3CB0(&v[0], &v[1], 2, 0, 0) == 0) (*(G_4FFA10 *)&D_001A4BE0).found = 1;
    }
    return (*(G_4FFA10 *)&D_001A4BE0).found;
}
/* localdecomp:end func_L01_004FFA10 */

/* localdecomp:start func_L01_004FFD00 */
extern f32 func_L01_004E9470(f32 a, f32 b, f32 c, f32 d, Moby_4FB8C8 *m, s32 *out);
extern Veldin1A4BE0 D_001A4BE0;




extern H_4FBE48 D_001A4C60;
extern M_4FBE48 *D_L01_001F03E8[];
extern s32 func_L01_00456250(M_4FBE48 *);
extern float func_0038CF00(void *, void *);
extern float func_0038CF38(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);

s32 func_L01_004FFD00(void) {
    M_4FBE48 *best;
    M_4FBE48 *m;
    s32 i;
    float bestDist, d, a, c, e;
    s32 out;
    s128 v[2];

    if ((*(G_4FBE48 *)&D_001A4BE0).f9676 == 33) return (*(G_4FBE48 *)&D_001A4BE0).f2708;
    (*(G_4FBE48 *)&D_001A4BE0).f2708 = 0;
    best = 0;
    bestDist = 100000000.0f;
    for (i = 0; i < 32; i++) {
        m = D_L01_001F03E8[i];
        if (m == 0) break;
        if (m->h170 != 2461) continue;
        if (m->h52 & 1) continue;
        if (func_L01_00456250(m)) continue;
        if (func_0038CF00(&D_001A4C60, &m->pos) > 30.0f) continue;
        c = 0.52359879f;
        e = -1.0f;
        if (D_001A4C60.f9540 == 1 || D_001A4C60.f9540 == 29) {
            c = e = 0.08726646f;
        }
        a = (*(G_4FBE48 *)&D_001A4BE0).f152;
        if ((*(G_4FBE48 *)&D_001A4BE0).f9676 == 15) a = (*(G_4FBE48 *)&D_001A4BE0).f1516;
        d = ((float (*)(float, float, float, float, M_4FBE48 *, s32 *))func_L01_004E9470)(a, 30.0f, c, e, m, &out);
        if (out != 0) continue;
        if (func_0038CF38(&(*(G_4FBE48 *)&D_001A4BE0).v128, &m->pos) < 4.0f) continue;
        if (m->b49 == 0) d += 10.0f;
        if (d < bestDist) {
            bestDist = d;
            best = m;
        }
    }
    if (best) {
        v[0] = (*(G_4FBE48 *)&D_001A4BE0).v128;
        (*(G_4FBE48 *)&D_001A4BE0).f2704 = best;
        ((float *)&v[0])[2] += 0.5f;
        v[1] = best->pos;
        if (func_003D3CB0(&v[0], &v[1], 2, 0, 0) == 0) (*(G_4FBE48 *)&D_001A4BE0).f2708 = 1;
    }
    return (*(G_4FBE48 *)&D_001A4BE0).f2708;
}
/* localdecomp:end func_L01_004FFD00 */

/* localdecomp:start func_L01_004FFF58 */
typedef struct {
    u8 pad0[0x10]; s128 pos; u8 state; u8 pad21[0x10]; u8 active;
    u8 pad32[2]; u16 flags; u8 pad36[0x32]; u8 *pvar;
    u8 pad6C[0x3E]; s16 class_id;
} M_004FFF58;
typedef struct {
    u8 pad0[0xAC0]; M_004FFF58 *target; s32 valid; f32 distance;
    u8 padACC[0x25C0-0xACC]; M_004FFF58 *object;
} H_004FFF58;
typedef union { s128 q; f32 v[4]; } Q_004FFF58;
extern Veldin1A4BE0 D_001A4BE0;
extern M_004FFF58 *D_L01_001F0468[];
extern const f32 D_L01_001DC028[];
extern s32 D_001D545C;
extern Dir_004FE668 D_L01_001EAA00;
extern u8 D_L01_001E2A40[];
s32 func_L01_004FFF58(void) {
    extern u8 *func_00382348(void *);
    extern s32 func_0038DC20(void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern f32 func_0038CF00_004FFF58(void *, void *);
    M_004FFF58 *best;
    M_004FFF58 *m;
    s32 i;
    f32 dist;
    f32 radius;
    f32 d;
    u8 *info;
    Q_004FFF58 pos;
    best=0;
    dist=D_L01_001DC028[0];
    ((H_004FFF58 *)&D_001A4BE0)->valid = 0;
    for (i=0; i<32; i++) {
        s32 allow;
        m=D_L01_001F0468[i];
        if (m==0) break;
        if (m->flags & 1) continue;
        if (m->active==0) continue;
        if (m->state==2 || m->state==3) continue;
        pos.q=m->pos;
        pos.v[3]=0.5f;
        radius=32.0f;
        if (m->class_id==0xCB5 || m->class_id==0x952) {
            radius=*(f32 *)(m->pvar+0x78);
        } else {
            info=func_00382348(m);
            if (info) radius=info[0xA]*0.125f;
        }
        if (D_001D545C!=11 && func_0038DC20(&pos,radius)==-1) continue;
        allow=1;
        if (func_003D3CB0(D_L01_001E2A40,&m->pos,6,(s32)m,0)) {
            if (D_L01_001EAA00.object==0 || (s32)((H_004FFF58 *)&D_001A4BE0)->object!=D_L01_001EAA00.object)
                allow=0;
        }
        if (!allow) continue;
        d=func_0038CF00_004FFF58(&m->pos,(u8 *)((H_004FFF58 *)&D_001A4BE0)->object+0x10);
        if (d<dist) { best=m; dist=d; }
    }
    if (best) {
        ((H_004FFF58 *)&D_001A4BE0)->target=best;
        ((H_004FFF58 *)&D_001A4BE0)->distance=dist;
        ((H_004FFF58 *)&D_001A4BE0)->valid=1;
    } else {
        ((H_004FFF58 *)&D_001A4BE0)->target=0;
        ((H_004FFF58 *)&D_001A4BE0)->distance=D_L01_001DC028[0];
        ((H_004FFF58 *)&D_001A4BE0)->valid=0;
    }
    return ((H_004FFF58 *)&D_001A4BE0)->valid;
}
/* localdecomp:end func_L01_004FFF58 */

/* localdecomp:start func_L01_00500188 */
extern Veldin1A4BE0 D_001A4BE0;
void func_L01_00500188(void) {
    s32 n = (*(G_4FC2D0 *)&D_001A4BE0).x2494;
    s32 i;
    if (n >= 16) {
        n = 15;
    }
    for (i = n - 1; i >= 0; i--) {
        (*(G_4FC2D0 *)&D_001A4BE0).x23D4[i + 1] = (*(G_4FC2D0 *)&D_001A4BE0).x23D4[i];
        (*(G_4FC2D0 *)&D_001A4BE0).x2414[i + 1] = (*(G_4FC2D0 *)&D_001A4BE0).x2414[i];
        (*(G_4FC2D0 *)&D_001A4BE0).x2454[i + 1] = (*(G_4FC2D0 *)&D_001A4BE0).x2454[i];
    }
    (*(G_4FC2D0 *)&D_001A4BE0).x23D4[0] = (*(G_4FC2D0 *)&D_001A4BE0).x25C4;
    (*(G_4FC2D0 *)&D_001A4BE0).x2414[0] = (*(G_4FC2D0 *)&D_001A4BE0).x25CC;
    (*(G_4FC2D0 *)&D_001A4BE0).x2454[0] = (*(G_4FC2D0 *)&D_001A4BE0).x1B8;
    (*(G_4FC2D0 *)&D_001A4BE0).x2494++;
    if ((*(G_4FC2D0 *)&D_001A4BE0).x2494 > 16) {
        (*(G_4FC2D0 *)&D_001A4BE0).x2494 = 16;
    }
    (*(G_4FC2D0 *)&D_001A4BE0).x25DC = (*(G_4FC2D0 *)&D_001A4BE0).x25D0;
    (*(G_4FC2D0 *)&D_001A4BE0).x25E0 = (*(G_4FC2D0 *)&D_001A4BE0).x25D4;
    (*(G_4FC2D0 *)&D_001A4BE0).x25D8 = (*(G_4FC2D0 *)&D_001A4BE0).x1B8;
    (*(G_4FC2D0 *)&D_001A4BE0).x25D0 = (*(G_4FC2D0 *)&D_001A4BE0).x25C4;
    (*(G_4FC2D0 *)&D_001A4BE0).x25D4 = (*(G_4FC2D0 *)&D_001A4BE0).x25CC;
}
/* localdecomp:end func_L01_00500188 */

/* localdecomp:start func_L01_00500240 */
extern Veldin1A4BE0 D_001A4BE0;
s32 func_L01_00500240(s32 a0, s32 a1) {
    s32 i;
    s32 acc = (*(S_4FC388 *)&D_001A4BE0).start;
    for (i = 0; i < (*(S_4FC388 *)&D_001A4BE0).count; i++) {
        if (a1 < acc) return 0;
        if ((*(S_4FC388 *)&D_001A4BE0).ids[i] == a0) return 1;
        acc += (*(S_4FC388 *)&D_001A4BE0).lens[i];
    }
    return 0;
}
/* localdecomp:end func_L01_00500240 */

/* localdecomp:start func_L01_005002B8 */
extern s32 D_L01_001D6694;

typedef struct {
    u8 pad0[0x25CC];
    s32 state;
    u8 pad25D0[0x2850 - 0x25D0];
    s32 w2850;
} H_005002B8;

s32 func_L01_005002B8(s32 id, s32 kind) {
    s32 s;

    if (kind == 3) {
        return 1;
    }
    if ((*(H_005002B8 *)&D_001A4BE0).state == 20) {
        if (id != 0x65 || kind != 2) {
            return 0;
        }
    }
    if (D_L01_001D6694 == 2 || D_L01_001D6694 == 6) {
        if (kind != 2) {
            return 0;
        }
    }
    if ((*(H_005002B8 *)&D_001A4BE0).w2850 == 0) {
        s = (*(H_005002B8 *)&D_001A4BE0).state;
        if (s == 2 || s == 7) {
            if (id != 6 && id != 0x39 && id != 0x43 && id != 0x56 && id != 0x63 && id != 0x9F && id != 0xA0
                && id != 0x79 && id != 0x7D && id != 0x7E && id != 0x81 && id != 0x50 && id != 0x6C
                && id != 0x82 && id != 0x84) {
                return 0;
            }
        }
    }
    return 1;
}
/* localdecomp:end func_L01_005002B8 */

/* localdecomp:start func_L01_005003D0 */
/* func_L01_005003D0: hero state entry, Holostar Studios (Clank)'s copy (family C, docs/prep/FAMILIES.md; root
   func_L08_004DD0C0, src/levels/08_aquatos/L08_004DD0C0.c). Opus family C, 2026-11-08: the root's C with
   this level's data, callee names and jump-table order, corrected case by case against retail.
   Build needs, as the root: "-mvu0-use-vf0-vf2 ... @ps2as" on this file, its config/levels/divs_nops.txt
   row, include/vu0.h (vec_add_ab, qzero, fabs_asm) and the two .data core externs (docs/GLOBALS.md).
   The root's last fixes carry over (func_L01_004E93F8 takes one argument; the 7-group's parameter-block
   order; the head's zero stores before f[0x135]; 0x11's 7.0 limit as a local).
   Corrected from retail as in L19, plus 0x61's frame count as an int chosen before the stores (retail
   converts it at the call) and 0x5A's store order.
*/
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));



typedef u128_t V4_F6a70b950;
typedef struct {
    char pad0[35];        /* 0   */
    unsigned char f35;    /* 35  */
    char pad36[8];        /* 36  */
    float f44;            /* 44  */
    unsigned char f48;    /* 48  */
    unsigned char f49;    /* 49  */
    unsigned short f50;   /* 50  */
    unsigned short f52;   /* 52  */
    char pad54[2];        /* 54  */
    long long f56;        /* 56  */
    char pad64[34];       /* 64  */
    unsigned char f98;    /* 98  */
    char pad99[21];       /* 99  */
    int f120;             /* 120 */
    unsigned short f124;  /* 124 */
    char pad126[26];      /* 126 */
    int f152;             /* 152 */
    char pad156[14];      /* 156 */
    short f170;           /* 170 */
} Src_F66766f2b;

typedef struct {
    char pad0[256];       /* 0   */
    int a[4];             /* 256 */
    int b[4];             /* 272 */
    Src_F66766f2b *c[4];            /* 288 */
    float d[4];           /* 304 */
    int pad320;           /* 320 */
    Src_F66766f2b *src;             /* 324 */
    int count;            /* 328 */
} List_F66766f2b;
extern char D_00189F30[];
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_0038CB78(unsigned int *, unsigned int, int);
extern u8 D_L30_001DBCC8[8];
extern u8 D_L30_001DBCE8[8];
extern s32 D_L01_002F62D0[][11];
extern s32 D_L22_001A9010;
extern s32 D_L30_001D6740;
extern f32 D_L30_001DBBA8;
extern f32 D_L30_001DBBAC;
extern f32 D_L01_002F6460[][25];
extern s32 D_L01_002F62D0[][11];
extern f32 func_00282C48(f32);
extern void func_L01_00476498(s32, f32 *, s32 *, f32 *, s32, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_L01_00443A18(f32, f32);
extern void *func_L01_00447490(void *, u32, s32);
extern void func_003C4BB0(float *, float);
extern s32 func_L01_004DFE80(s32);
extern void func_L01_004E67C0(void);
extern u32 func_L01_004E9200(s32);
extern s32 func_L01_004E9308(void);
extern f32 func_L01_004E93F8(s32);
extern void func_L01_004EAA80(void);
extern s32 func_L01_004EDFA8(u8 *);
extern void func_L01_004F1190(f32);
extern void func_L01_004ED5F8(void);
extern void func_L01_004F4EF8(void);
extern void func_L01_00513FD8(void);
extern f32 func_L01_004F4E20(void *, int);
extern int func_L01_004F4E70(int, int);
extern int func_L01_004FF610(void);
extern void func_L01_0050FE88(s32, s32);
extern f32 func_L01_00511408(char *);
extern void func_L01_00511508(V4_F6a70b950 *, V4_F6a70b950 *, float);
extern int func_L01_003F1F20(unsigned int, int);
extern void func_L01_004E7C88(void);
extern void func_L01_0044E318(void *, char *);
extern void func_L01_0044E340(List_F66766f2b *, int, int, float);
extern void func_L01_0044E740(void *);
extern int func_L00_0035F5A0(int, int, int);
extern void func_L01_00504E38(int);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_003C3A10(void *, int, int, int);
/* These calls use side effects only; their original scalar return contracts remain unqualified. */
extern void func_L01_004C67A0(void *, s32, u32, f32, f32, f32, f32);
extern void func_L01_004DFEA0(int);
extern void func_L01_004E11C0(int, int, int, int);
extern void func_L01_004E1560(void);
extern void func_L01_004E5EB8(int, int, int);
extern void func_L01_004EA638(int, int);
extern void func_L01_004EE850(int, f32);
extern void func_L01_004F2880(f32, f32, f32);
extern s32 func_L01_005119E0(s32);
extern int func_L01_00507268(void);
extern void func_L01_0050FB40(int, int, f32);
extern void func_L00_0041E958(f32, f32, f32);
extern s32 func_L01_004DFDB0(int);
extern s32 D_001D4C38;
extern s32 D_001A7B90;
extern u8 D_001D5464[8];
extern u8 *D_L01_001E1090;
extern s32 D_L01_001E1098;
extern u32 D_001D545C_005003D0;
typedef struct { u16 count; u16 pad; u32 maximum; u32 levels; } Statistics;
extern Statistics D_001A7C10[];
extern s32 D_L30_001DBCC0[2];
extern f32 D_L01_002F6460[][25];
extern u8 D_L22_0025FD30[];
typedef struct { u8 pad0[8]; f32 f8; u8 padC[0x450 - 0xC]; s32 i450; } L19State_1B9900;
extern s32 func_L01_005002B8(s32, s32);
extern void func_L01_00500188(void);
extern void func_L01_003F1F60(s32);
extern L19State_1B9900 D_L01_001E2A40_005003D0;



/* All resident fields below are views of the single player-state object. */
typedef union { u8 b[0x2A00]; s16 h[0x1500]; u16 uh[0x1500]; s32 i[0xA80]; u32 u[0xA80]; f32 f[0xA80]; u8 *ptr[0xA80]; u128_t q[0x2A0]; } Hero;
extern Hero D_001A4BE0_005003D0;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
extern f32 D_L01_001DBCF0, D_L01_001DBCF4, D_L01_001DBCF8, D_L01_001DBD28, D_L01_001DBD2C;
__asm__(".extern D_L01_001DBCF0, 4");
__asm__(".extern D_L01_001DBCF4, 4");
__asm__(".extern D_L01_001DBCF8, 4");
__asm__(".extern D_L01_001DBD28, 4");
__asm__(".extern D_L01_001DBD2C, 4");
extern u8 D_L01_001DBE38[8];
__asm__(".extern D_L01_001DBE38, 8");
extern u8 D_L01_001DBE58[8];
__asm__(".extern D_L01_001DBE58, 8");
extern s32 D_L01_001D6740;
__asm__(".extern D_L01_001D6740, 4");
extern u8 D_001439F4_005003D0 __attribute__((section(".data")));
extern s32 D_00143950 __attribute__((section(".data")));
extern u8 D_001D545C_b[] __attribute__((section(".sdata")));
extern void func_L01_004606A8(s32);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 D_L01_001DD67C;
extern void func_L01_005118D0(s32, s32);
extern void func_L01_004F5AE8(void);
extern void func_L01_004F5810(void);
extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
extern f32 D_L01_001DBD0C;
__asm__(".extern D_L01_001DBD0C, 4");
extern s32 func_L01_00500240(s32, s32);
extern s32 func_L30_004E6DC8(s32);
extern s32 D_L01_001DBE30[2];
__asm__(".extern D_L01_001DBE30, 8");
extern s32 func_L01_004DFD60(void);
extern void func_L01_00412E70(void *, V4 *, f32, u8 *, f32);
extern void func_L01_00412FE0(void *, V4 *, f32, f32);



extern u8 D_00142660_005003D0[];
/* Changes the player's action, initializes its movement parameters and selects animation. */
s32 func_L01_005003D0(s32 action, s32 animate) {
    f32 dir[4];
    f32 pos[4];
    u8 *objectSnapshot;
    u8 *hit_10, *hit_29, *hit_44, *hit_45, *hit_52;
    s32 oldStep;
    u8 wasGliding;
    u8 oldWeapon;
    s32 current, mode, index;
    f32 angle_13;
    u32 animation_13;
    u32 animation_14;
    s32 selected_13;
    s32 selected_14;
    s32 selected_15;
    s32 selected_83;
    s32 selected_8, selected_9, selected_18, selected_21, selected_22, selected_52;
    u32 animation_16, animation_21, animation_22, animation_41, animation_43, animation_53;
    f32 frames;
    f32 angle_53;
    f32 value_18, value_21, value_22, value_37;
    u8 wasFlag;
    if (!func_L01_005002B8(action, animate)) return 0;
    objectSnapshot = D_001A4BE0_005003D0.ptr[0x970];
    func_L01_00500188();
    oldStep = D_001A4BE0_005003D0.i[0x972];
    wasGliding = D_001A4BE0_005003D0.b[0x25e8];
    wasFlag = D_001A4BE0_005003D0.b[0x25e7];
    D_001A4BE0_005003D0.i[0x971] = action;
    D_001A4BE0_005003D0.i[0x972] = 0;
    if (D_001A4BE0_005003D0.b[0x25e5] == 1) D_001A4BE0_005003D0.b[0x25e5] = 0;
    D_001A4BE0_005003D0.b[0x25ed] = 0;
    if (D_001A4BE0_005003D0.b[0x25e4] == 0) {
        *(s32 *)(D_001A4BE0_005003D0.ptr[0x970] + 0x9C) = 0;
        D_001A4BE0_005003D0.b[0x25ee] = 0;
        D_001A4BE0_005003D0.b[0x25e8] = 0;
        D_001A4BE0_005003D0.b[0x25f3] = 0;
        D_001A4BE0_005003D0.b[0x25f0] = 0;
        if (D_001A4BE0_005003D0.i[0xd8]) D_001A4BE0_005003D0.b[0x25e7] = 0;
        func_L01_0044E740((void *)(D_001A4BE0_005003D0.b + 0x1b90));
    }
    if (D_001A4BE0_005003D0.h[0xfd] == 0) func_L01_003F1F60(0);
    if (D_001A4BE0_005003D0.b[0x25e4] == 3 && (u32)(D_001A4BE0_005003D0.i[0x971] - 0x51) >= 9 && (u32)(D_001A4BE0_005003D0.i[0x971] - 0x66) >= 4 &&
        D_001A4BE0_005003D0.i[0x971] != 0 && D_001A4BE0_005003D0.i[0x971] != 1) { func_L01_004E7C88(); D_001A4BE0_005003D0.i[0x971] = action; }
    func_L01_004EA638(D_001A4BE0_005003D0.i[0x974], D_001A4BE0_005003D0.i[0x971]);
    D_001A4BE0_005003D0.i[0x45a] = 0;
    switch (action) {
    case 0xaf:
        D_001A4BE0_005003D0.b[0x25e4] = 0;
        goto finish;
    case 0x0:
        D_001A4BE0_005003D0.i[0x973] = 0;
        D_001A4BE0_005003D0.u[0xa03] = 0;
        if (D_001A4BE0_005003D0.i[0x48a] == 0x27) func_L01_004EAA80();
        D_001A4BE0_005003D0.b[0x2877] = 0;
        D_001A4BE0_005003D0.i[0x460] = func_00382498(0x2a, 0x53);
        func_L01_004E67C0();
        if (D_001A4BE0_005003D0.b[0x25e4]) { func_L01_00504E38(0); return 1; }
        (*(u128_t *)(D_001A4BE0_005003D0.b + 0x160) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120));
        if (D_001A4BE0_005003D0.b[0x1474] && func_0038CED8(D_001A4BE0_005003D0.b + 0x160) > 0.010000001f) { func_L01_005003D0(0x2e, 1); return 0; }
        if (D_001A4BE0_005003D0.b[0x147c] && D_001A4BE0_005003D0.h[0x1b6] == 0) { func_L01_005003D0(0x7b, 1); return 0; }
        D_001A4BE0_005003D0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        if (func_L01_004DFDB0(0) == 0x4a) func_L01_0050FB40(func_L01_004DFDB0(0), 0, 15.0f); else func_L01_0050FB40(func_L01_004DFDB0(0), 0, -1.0f);
        goto finish;
    case 0x68:
        D_001A4BE0_005003D0.i[0x973] = 0;
        qzero(D_001A4BE0_005003D0.b + 0x160);
        D_001A4BE0_005003D0.u[0xa03] = 0;
        func_L01_004F1190(0.0f);
        D_001A4BE0_005003D0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        if (func_L01_004DFDB0(0) == 0x4a) func_L01_0050FB40(func_L01_004DFDB0(0), 0, 15.0f); else func_L01_0050FB40(func_L01_004DFDB0(0), 0, -1.0f);
        goto finish;
    case 0x3d:
        func_L01_0050FB40(func_L01_004DFDB0(0), 0, 7.0f);
        if (D_001A4BE0_005003D0.ptr[0x681]) func_003C3A10(D_001A4BE0_005003D0.ptr[0x681], 0, 0, 7);
        goto finish;
    case 0x39:
        D_001A4BE0_005003D0.i[0x973] = 20; (*(u128_t *)(D_001A4BE0_005003D0.b + 0x160) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120)); D_001A4BE0_005003D0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x40, 0, 10.0f); goto finish;
    case 0x82:
        func_L01_004E7C88();
        D_001A4BE0_005003D0.i[0x973] = 20; D_001A4BE0_005003D0.u[0xa03] = 0; D_001A4BE0_005003D0.i[0xa14] = 0; (*(u128_t *)(D_001A4BE0_005003D0.b + 0x160) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120));
        func_003C4BB0((f32 *)(D_001A4BE0_005003D0.b + 0x160), 0.07000001f);
        if (!animate) goto finish;
        func_L01_0050FB40(0x63, 0, 10.0f); goto finish;
    case 0xb1:
        D_001A4BE0_005003D0.i[0x973] = 7; D_001A4BE0_005003D0.u[0xa03] = 0;
        func_L01_004ED5F8();
        func_L01_004F4EF8();
        if (!animate) goto finish;
        func_L01_0050FB40(0x63, 0, 10.0f); goto finish;
    case 0x81:
        D_001A4BE0_005003D0.i[0x973] = 20; D_001A4BE0_005003D0.u[0xa03] = 0;
        D_001A4BE0_005003D0.f[0x1cb] = D_001A4BE0_005003D0.f[0xd4] - 0.37f; D_001A4BE0_005003D0.i[0xa14] = 0;
        D_001A4BE0_005003D0.f[0x1c9] = D_001A4BE0_005003D0.f[0x46] * 0.2f;
        if (D_001A4BE0_005003D0.f[0x1c9] < -0.14000002f) D_001A4BE0_005003D0.f[0x1c9] = -0.14000002f;
        D_001A4BE0_005003D0.b[0x25e8] = 1; D_001A4BE0_005003D0.f[0x1c8] = D_001A4BE0_005003D0.f[0x22] - D_001A4BE0_005003D0.f[0x1cb]; D_001A4BE0_005003D0.u[0x1cc] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x5b, 0, 9.0f); goto finish;
    case 0x50:
        D_001A4BE0_005003D0.i[0x973] = 20; D_001A4BE0_005003D0.uh[0xf8] = 10000; D_001A4BE0_005003D0.u[0xa03] = 0;
        D_001A4BE0_005003D0.f[0x1cb] = D_001A4BE0_005003D0.f[0xd4] - 0.15f; D_001A4BE0_005003D0.i[0xa14] = 0;
        D_001A4BE0_005003D0.f[0x1c9] = D_001A4BE0_005003D0.f[0x46] * 0.2f;
        if (D_001A4BE0_005003D0.f[0x1c9] < -0.14000002f) D_001A4BE0_005003D0.f[0x1c9] = -0.14000002f;
        D_001A4BE0_005003D0.u[0x1cc] = 0; D_001A4BE0_005003D0.f[0x1c8] = D_001A4BE0_005003D0.f[0x22] - D_001A4BE0_005003D0.f[0x1cb];
        if (!animate) goto finish;
        func_L01_0050FB40(0x23, 0, 9.0f); goto finish;
    case 0x32: {
        s32 n;
        D_001A4BE0_005003D0.i[0x973] = 17; D_001A4BE0_005003D0.u[0xa03] = 11; D_001A4BE0_005003D0.b[0x25e8] = 1; D_001A4BE0_005003D0.u[0x26f] = 0;
        if (D_001A4BE0_005003D0.i[0x975] == 0x12) { func_L01_004F4E70(3, 0); D_001A4BE0_005003D0.i[0x972] = 1; }
        else D_001A4BE0_005003D0.i[0x26d] = 37;
        D_001A4BE0_005003D0.i[0x45a] = 0x68; D_001A4BE0_005003D0.u[0x268] = 0;
        n = 10;
        if (!animate) goto finish;
        func_L01_0050FB40(0x36, 0, n); goto finish; }
    case 0x34: {
        s32 f;
        D_001A4BE0_005003D0.i[0x973] = 17; D_001A4BE0_005003D0.u[0xa03] = 11; D_001A4BE0_005003D0.b[0x25e8] = 1; D_001A4BE0_005003D0.i[0x26d] = 50;
        if (D_001A4BE0_005003D0.i[0x975] == 0x12) { func_L01_004F4E70(3, 0); D_001A4BE0_005003D0.i[0x972] = 1; }
        D_001A4BE0_005003D0.i[0x45a] = 0x68; D_001A4BE0_005003D0.u[0x268] = 0;
        f = D_001A4BE0_005003D0.i[0x974] == 0x32 ? 12 : 9;
        if (animate) func_L01_0050FB40(0x38, 0, f);
        goto finish;
    }
    case 0x33:
        D_001A4BE0_005003D0.i[0x973] = 17; D_001A4BE0_005003D0.u[0xa03] = 11; D_001A4BE0_005003D0.b[0x25e8] = 1;
        (*(u128_t *)(D_001A4BE0_005003D0.b + 0x160) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120)); D_001A4BE0_005003D0.i[0x45a] = 0x68;
        selected_8 = D_001A4BE0_005003D0.i[0x974] == 0x34 ? -2 : 29;
        if (!animate) goto finish;
        func_L01_0050FB40(0x37, 0, (f32)selected_8); goto finish;
    case 0x36:
        D_001A4BE0_005003D0.i[0x973] = 18; D_001A4BE0_005003D0.b[0x25e8] = 1; D_001A4BE0_005003D0.u[0xa03] = 0; D_001A4BE0_005003D0.uh[0x4e5] = 0;
        if (D_001A4BE0_005003D0.i[0x975] == 0x11) {
            func_L01_004E5EB8(3, 10, 0);
            if (D_L01_001E1090) func_L01_004C67A0(D_L01_001E1090, D_L01_001E1098, 0, D_001A4BE0_005003D0.f[0x20], D_001A4BE0_005003D0.f[0x21], 0.4f, 0.3f);
        } else if (D_001A4BE0_005003D0.f[0x46] < -0.010000001f) {
            selected_9 = (s32)(fabs_asm(D_001A4BE0_005003D0.f[0x46]) * 300.0f);
            if (selected_9 > 40) selected_9 = 40;
            func_L01_004E5EB8(3, selected_9, 1);
            if (D_L01_001E1090) func_L01_004C67A0(D_L01_001E1090, D_L01_001E1098, 0, D_001A4BE0_005003D0.f[0x20], D_001A4BE0_005003D0.f[0x21], 0.5f, -0.4f);
            D_001A4BE0_005003D0.uh[0x4e5] = 62;
        }
        D_001A4BE0_005003D0.f[0x1c9] = D_001A4BE0_005003D0.f[0x46] * 0.37f; D_001A4BE0_005003D0.i[0x1ca] = 0;
        if (D_001A4BE0_005003D0.f[0x1c9] < -0.14000002f) D_001A4BE0_005003D0.f[0x1c9] = -0.14000002f;
        D_001A4BE0_005003D0.f[0x1cb] = D_001A4BE0_005003D0.f[0xd4]; D_001A4BE0_005003D0.u[0x1cc] = 0;
        D_001A4BE0_005003D0.f[0x1c8] = (D_001A4BE0_005003D0.f[0x22] - D_001A4BE0_005003D0.f[0xd4]) - -0.12f;
        (*(u128_t *)(D_001A4BE0_005003D0.b + 0x160) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120)); D_001A4BE0_005003D0.f[0x5a] = 0;
        func_003C4BB0((f32 *)(D_001A4BE0_005003D0.b + 0x160), 0.11000001f);
        D_001A4BE0_005003D0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        func_L01_0050FB40(0x35, 0, 18.0f); goto finish;
    case 0x77: case 0x78:
        D_001A4BE0_005003D0.i[0x973] = 7; D_001A4BE0_005003D0.u[0xa03] = 0;
        func_L01_004F1190(0.5f); D_001A4BE0_005003D0.b[0x25e8] = 1; (*(u128_t *)(D_001A4BE0_005003D0.b + 0xf0) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x110));
        hit_10 = func_L01_00447490(D_001A4BE0_005003D0.ptr[0x970], 1, 0);
        if (hit_10) func_L01_004DFEA0((s32)(*(f32 *)(hit_10 + 0x2C)));
        else func_L01_004DFEA0(1);
        D_001A4BE0_005003D0.uh[0xee] = 64;
        if (animate) {
            if (D_001A4BE0_005003D0.i[0x971] == 0x77) func_L01_0050FB40(0x57, 3, -3.0f);
            else func_L01_0050FB40(0x56, 3, -3.0f);
            *(f32 *)(D_001A4BE0_005003D0.ptr[0x970] + 0x44) = D_L01_002F6460[D_001A4BE0_005003D0.i[0x304]][D_001A4BE0_005003D0.i[0x305]++];
            goto finish;
        }
        goto finish;
    case 0x35:
        D_001A4BE0_005003D0.i[0x973] = 18; D_001A4BE0_005003D0.u[0xa03] = 0; D_001A4BE0_005003D0.u[0x26f] = 0;
        D_001A4BE0_005003D0.b[0x25e8] = 1; D_001A4BE0_005003D0.i[0x1ca] = 37; D_001A4BE0_005003D0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        func_L01_0050FB40(0x52, 0, 14.0f); goto finish;
    case 0x6c:
        D_001A4BE0_005003D0.i[0x973] = 20; D_001A4BE0_005003D0.b[0x25e8] = 1; D_001A4BE0_005003D0.u[0xa03] = 0;
        if (D_001A4BE0_005003D0.h[0x4e7] > 42 && D_001A7C10[12].count < 0xFFFF) D_001A7C10[12].count++;
        if (D_001A7C10[12].maximum < (D_001D4C38 * 5 + 2) / 6) D_001A7C10[12].maximum = (D_001D4C38 * 5 + 2) / 6;
        D_001A7C10[12].levels = (D_001A7C10[12].levels | (1u << D_001D545C_005003D0)) | 0x80000000u;
        if (D_001A4BE0_005003D0.i[0x274] > 2 && D_001A7C10[29].count < 0xFFFF) D_001A7C10[29].count++;
        if (D_001A7C10[29].maximum < (D_001D4C38 * 5 + 2) / 6) D_001A7C10[29].maximum = (D_001D4C38 * 5 + 2) / 6;
        D_001A7C10[29].levels = (D_001A7C10[29].levels | (1u << D_001D545C_005003D0)) | 0x80000000u;
        (*(u128_t *)(D_001A4BE0_005003D0.b + 0x160) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050FB40(0x4f, 0, 8.0f); goto finish;
    case 0x84:
        D_001A4BE0_005003D0.i[0x973] = 20; (*(u128_t *)(D_001A4BE0_005003D0.b + 0x160) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120)); D_001A4BE0_005003D0.b[0x25e8] = 1; D_001A4BE0_005003D0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x64, 0, 8.0f); goto finish;
    case 0x1:
        D_001A4BE0_005003D0.u[0xa03] = 4;
        D_001A4BE0_005003D0.i[0x973] = 0;
        if (D_001A4BE0_005003D0.b[0x25e4]) {
            func_0038CF68(dir, D_001A4BE0_005003D0.b + 0x20, D_001A4BE0_005003D0.f[0x5b3]);
            vec_add_ab(dir, dir, D_001A4BE0_005003D0.b + 0x80);
            func_L01_00412E70(D_001A4BE0_005003D0.b + 0x1540, (V4 *)dir, D_001A4BE0_005003D0.f[0x26], D_001A4BE0_005003D0.ptr[0x970], 0.0f);
            func_L01_00412FE0(D_001A4BE0_005003D0.b + 0x1540, (V4 *)dir, D_001A4BE0_005003D0.f[0x26], 0.0f);
            func_L01_00513FD8();
        }
        if (D_001A4BE0_005003D0.b[0x25eb]) goto finish;
        animation_16 = func_L01_004DFDB0(1);
        if (D_001A4BE0_005003D0.ptr[0x970][0x43] == animation_16 || !animate) goto finish;
        func_L01_0050FB40(animation_16, 0, 15.0f); goto finish;
    case 0x2f:
        D_001A4BE0_005003D0.i[0x973] = 8; (*(u128_t *)(D_001A4BE0_005003D0.b + 0x160) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x110)); D_001A4BE0_005003D0.u[0xa03] = 0;
        func_L01_0050FB40(func_L01_004DFDB0(0), 0, 4.0f); D_001A4BE0_005003D0.uh[0xf6] = 6;
        goto finish;
    case 0x2: case 0x2e: case 0x75:
        D_001A4BE0_005003D0.i[0x973] = 1;
        D_001A4BE0_005003D0.u[0xa03] = 0;
        if (D_001A4BE0_005003D0.i[0x975] != 0x4 && D_001A4BE0_005003D0.i[0x978] != 0x4) D_001A4BE0_005003D0.f[0x6d] = func_L01_00511408((char *)(D_001A4BE0_005003D0.b + 0x120));
        (*(u128_t *)(D_001A4BE0_005003D0.b + 0x3d0) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x0));
        D_001A4BE0_005003D0.u[0xfc] = 0;
        D_001A4BE0_005003D0.f[0xfa] = D_001A4BE0_005003D0.f[0x26];
        if (D_001A4BE0_005003D0.f[0x6d] > 0.14000002f) D_001A4BE0_005003D0.f[0x6d] = 0.14000002f;
        D_001A4BE0_005003D0.b[0x3ef] = 0;
        func_L01_004EE850(0, 1.0f);
        value_18 = func_0038DBA0(D_001A4BE0_005003D0.f[0x26], D_001A4BE0_005003D0.f[0x68]);
        if (value_18 > 1.5707964f &&
            (D_001A4BE0_005003D0.i[0x975] == 0x4 || D_001A4BE0_005003D0.i[0x974] == 0x3 || D_001A4BE0_005003D0.i[0x977] == 0x3)) D_001A4BE0_005003D0.f[0x6d] = 0;
        D_001A4BE0_005003D0.i[0x45a] = 0x68;
        if (D_001A4BE0_005003D0.b[0x147c]) {
            if (D_001A4BE0_005003D0.h[0x1b6] == 0 || D_001A4BE0_005003D0.f[0xcf] < 0.3f) { func_L01_005003D0(0x7b, 1); return 0; }
        }
        if (D_001A4BE0_005003D0.b[0x1474] || D_001A4BE0_005003D0.i[0x971] == 0x2e) {
            if (D_001A4BE0_005003D0.f[0x6d] > 0.15400001f) D_001A4BE0_005003D0.f[0x6d] = 0.15400001f;
            D_001A4BE0_005003D0.u[0x3e] = 0;
            func_003C4BB0((f32 *)(D_001A4BE0_005003D0.b + 0xf0), 0.15400001f);
            D_001A4BE0_005003D0.i[0x971] = 0x2e; D_001A4BE0_005003D0.u[0xf9] = 0;
            if ((D_001A4BE0_005003D0.h[0xa1a] || (D_001A4BE0_005003D0.i[0x5ac] == 1 && func_L01_004606E8(0x28, 2, 0, 0))) && D_001A4BE0_005003D0.b[0x1436]) func_L01_0050FB40(0x7b, 0, 7.0f);
            else func_L01_0050FB40(0x32, 0, 7.0f);
            goto finish;
        }
        if (D_001A4BE0_005003D0.b[0x25ea] || D_001A4BE0_005003D0.i[0x971] == 0x75) {
            D_001A4BE0_005003D0.i[0x971] = 0x75;
            func_L01_0050FB40(!*(s32 *)(*(u8 **)(D_001A4BE0_005003D0.ptr[0x970] + 0x24) + 0x188) ? 3 : 0x50, 0, 7.0f); goto finish;
        }
        D_001A4BE0_005003D0.i[0x972] = 0;
        D_001A4BE0_005003D0.b[0x3ec] = 0; D_001A4BE0_005003D0.b[0x3ee] = 0;
        if (!animate) goto finish;
        selected_18 = 7;
        if (func_L01_004DFD60()) selected_18 = 10;
        if (D_001A4BE0_005003D0.i[0x977] == 0x22 || D_001A4BE0_005003D0.i[0x974] == 0x22) selected_18 = 12;
        if (D_001A4BE0_005003D0.i[0x977] == 0x88 || D_001A4BE0_005003D0.i[0x974] == 0x88) selected_18 = 12;
        if (D_001A4BE0_005003D0.i[0x974] == 0x13) selected_18 = 11;
        if (D_001A4BE0_005003D0.i[0x977] == 0x6 || D_001A4BE0_005003D0.i[0x977] == 0x2c) selected_18 = 15;
        if (D_001A4BE0_005003D0.i[0x978] == 0x4 && D_001A4BE0_005003D0.b[0x46c] > 4) selected_18 = 11;
        func_L01_0050FB40(D_001A4BE0_005003D0.i[0x972] + 3, D_L01_001DBE30[D_001A4BE0_005003D0.i[0x972]], (f32)selected_18); goto finish;
    case 0x80: {
        s32 n;
        D_001A4BE0_005003D0.i[0x973] = 28; D_001A4BE0_005003D0.i[0x45a] = 0x68; (*(u128_t *)(D_001A4BE0_005003D0.b + 0xf0) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x110)); D_001A4BE0_005003D0.u[0xa03] = 0;
        D_001A4BE0_005003D0.i[0x261] = 0;
        if (D_001A4BE0_005003D0.i[0x49e] != 0x1d) { D_001A4BE0_005003D0.i[0x98d] = D_001A4BE0_005003D0.i[0x49e]; D_001A4BE0_005003D0.i[0x97f] = 0x1d; }
        n = -2;
        if (!animate) goto finish;
        func_L01_0050FB40(0x69, 0, n); goto finish; }
    case 0x66:
        D_001A4BE0_005003D0.i[0x973] = 1; D_001A4BE0_005003D0.u[0xa03] = 0; D_001A4BE0_005003D0.f[0x6d] = func_0038CED8((D_001A4BE0_005003D0.b + 0x120));
        D_001A4BE0_005003D0.b[0x25ed] = 1;
        if (!D_001A4BE0_005003D0.b[0x25e4]) func_L01_004EAA80();
        if (!animate) goto finish;
        if (D_001A4BE0_005003D0.b[0x25e4] == 3) { func_L01_0050FB40(5, 0, 7.0f); goto finish; }
        if (D_001A4BE0_005003D0.b[0x25e4] == 1) { func_L01_0050FB40(0x19, 0, 7.0f); goto finish; }
        if (D_001A4BE0_005003D0.b[0x25e4] != 0) goto finish;
        func_L01_0050FB40(D_001A4BE0_005003D0.i[0x972] + 3, D_L01_001DBE30[D_001A4BE0_005003D0.i[0x972]], 7.0f); goto finish;
    case 0x30:
        D_001A4BE0_005003D0.i[0x973] = 16; D_001A4BE0_005003D0.u[0xa03] = 3; D_001A4BE0_005003D0.b[0x25e8] = 1;
        func_0038CB78((unsigned int *)(D_001A4BE0_005003D0.b + 0xb20), 0, 0x20);
        (*(u128_t *)(D_001A4BE0_005003D0.b + 0x160) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x110));
        if (!animate) goto finish;
        func_L01_0050FB40(0x51, 0, 12.0f); goto finish;
    case 0x3:
        D_001A4BE0_005003D0.i[0x973] = 1; D_001A4BE0_005003D0.u[0xa03] = 0;
        (*(u128_t *)(D_001A4BE0_005003D0.b + 0x160) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120));
        if (D_001A4BE0_005003D0.b[0x1474]) { func_L01_005003D0(0x2e, 1); return 0; }
        if (D_001A4BE0_005003D0.b[0x147c] && D_001A4BE0_005003D0.h[0x1b6] == 0) { func_L01_005003D0(0x7b, 1); return 0; }
        if (func_L01_00507268()) return 0;
        if (func_L01_004DFDB0(0) == 0x4a) {
            if (!animate) goto finish;
            if (func_L01_005003D0(0x0, 0)) func_L01_0050FB40(func_L01_004DFDB0(0), 0, 15.0f);
            return 0;
        }
        if (!animate) goto finish;
        animation_21 = objectSnapshot[0x42];
        {
            value_21 = D_001A4BE0_005003D0.f[0x306]; selected_21 = 6;
            if (func_L01_004DFE80(animation_21) == 4 && value_21 > 3.0f && value_21 < 16.0f) selected_21 = 5;
            func_L01_0050FB40(selected_21, 4, 7.0f);
            goto finish;
        }
    case 0x67:
        D_001A4BE0_005003D0.i[0x973] = 1; D_001A4BE0_005003D0.u[0xa03] = 0;
        D_001A4BE0_005003D0.f[0x6d] = func_L01_00511408((char *)(D_001A4BE0_005003D0.b + 0x120)); (*(u128_t *)(D_001A4BE0_005003D0.b + 0x160) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120));
        if (!animate) goto finish;
        animation_22 = objectSnapshot[0x42]; {
            value_22 = D_001A4BE0_005003D0.f[0x306]; selected_22 = 6;
            if (func_L01_004DFE80(animation_22) == 4 && value_22 > 3.0f && value_22 < 16.0f) selected_22 = 5;
            func_L01_0050FB40(selected_22, 4, 7.0f);
            goto finish;
        }
    case 0x4:
        D_001A4BE0_005003D0.i[0x973] = 12; D_001A4BE0_005003D0.u[0xa03] = 0;
        D_001A4BE0_005003D0.f[0x6d] = func_0038CED8((D_001A4BE0_005003D0.b + 0x120));
        if (D_001A4BE0_005003D0.f[0x6d] > 0.14000002f) D_001A4BE0_005003D0.f[0x6d] = 0.14000002f;
        if (D_001A4BE0_005003D0.b[0x147c] && D_001A4BE0_005003D0.h[0x1b6] == 0) { func_L01_005003D0(0x7b, 1); return 0; }
        D_001A4BE0_005003D0.i[0x45a] = 0x68;
        (*(u128_t *)(D_001A4BE0_005003D0.b + 0x160) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120));
        func_003C4BB0((float *)(D_001A4BE0_005003D0.b + 0x160), 0.14000002f);
        if (D_001A4BE0_005003D0.f[0x5e] > 0.07000001f) func_L01_004F4E70(9, 0);
        if (animate) {
            if (D_001A4BE0_005003D0.ptr[0x970][0x42] == func_L01_004DFDB0(0)) func_L01_0050FB40(13, 2, 7.0f);
            else func_L01_0050FB40(13, 2, 12.0f);
            func_L01_0050FE88(3, 18);
        }
        goto finish;
    case 0x8f:
        D_001A4BE0_005003D0.i[0x973] = 33; D_001A4BE0_005003D0.u[0xa03] = 0;
        
        D_001A4BE0_005003D0.f[0x68] = func_0038D160(*(f32 *)(D_001A4BE0_005003D0.ptr[0x2a4] + 0x10) - D_001A4BE0_005003D0.f[0x20],
                                    *(f32 *)(D_001A4BE0_005003D0.ptr[0x2a4] + 0x14) - D_001A4BE0_005003D0.f[0x21]);
        D_001A4BE0_005003D0.u[0x2a7] = 0; { if (animate) { func_L01_0050FB40(0x2a, 2, 4.0f); func_L01_0050FE88(10, 14); } goto finish; }
    case 0x90:
        D_001A4BE0_005003D0.i[0x973] = 33; D_001A4BE0_005003D0.b[0x25ed] = 1; D_001A4BE0_005003D0.u[0xa03] = 0;
        goto finish;
    case 0x23:
        D_001A4BE0_005003D0.i[0x973] = 13; D_001A4BE0_005003D0.u[0xa03] = 7;
        
        D_001A4BE0_005003D0.f[0x68] = func_0038D160(*(f32 *)(D_001A4BE0_005003D0.ptr[0x289] + 0x10) - D_001A4BE0_005003D0.f[0x20],
                                    *(f32 *)(D_001A4BE0_005003D0.ptr[0x289] + 0x14) - D_001A4BE0_005003D0.f[0x21]);
        if (D_001A4BE0_005003D0.i[0x974] == 0x28) (*(u128_t *)(D_001A4BE0_005003D0.b + 0x160) = *(u128_t *)(D_001A4BE0_005003D0.b + 0xf0));
        { if (animate) { func_L01_0050FB40(0x2a, 2, 4.0f); func_L01_0050FE88(10, 14); } goto finish; }
    case 0x24:
        D_001A4BE0_005003D0.i[0x973] = 13;
        D_001A4BE0_005003D0.u[0xa03] = 7;
        D_001A4BE0_005003D0.i[0x288] = 0;
        D_001A4BE0_005003D0.i[0x28d] = 0;
        D_001A4BE0_005003D0.b[0x25ed] = 1;
        if (!animate) goto finish;
        func_L01_0050FB40(0x2b, 0, 8.0f); goto finish;
    case 0x25:
        D_001A4BE0_005003D0.i[0x973] = 13; D_001A4BE0_005003D0.u[0xa03] = 7; D_001A4BE0_005003D0.b[0x25ed] = 1; D_001A4BE0_005003D0.i[0x288] = 0; D_001A4BE0_005003D0.i[0x28d] = 0;
        D_001A4BE0_005003D0.f[0x28f] = func_0038CF00(D_001A4BE0_005003D0.b + 0x80, D_001A4BE0_005003D0.ptr[0x289] + 0x10);
        if (!animate) goto finish;
        func_L01_0050FB40(0x2b, 1, 4.0f); goto finish;
    case 0x2b: {
        u8 *p = D_001A4BE0_005003D0.ptr[0x294], *q; f32 t;
        D_001A4BE0_005003D0.u[0x29a] = 0; D_001A4BE0_005003D0.i[0x973] = 14; D_001A4BE0_005003D0.u[0xa03] = 7; D_001A4BE0_005003D0.ptr[0x295] = p; D_001A4BE0_005003D0.uh[0x52e] = 0;
        D_001A4BE0_005003D0.uh[0x53e] = 0; D_001A4BE0_005003D0.uh[0x53f] = 1; D_001A4BE0_005003D0.b[0x25ed] = 1; D_001A4BE0_005003D0.u[0x29d] = 0; D_001A4BE0_005003D0.u[0x29e] = 0;
        q = *(u8 **)(p + 0x68);
        D_001A4BE0_005003D0.f[0x298] = *(f32 *)(q + 4);
        if (*(f32 *)(q + 0x10) == D_001A4BE0_005003D0.f[0x29a]) *(f32 *)(q + 0x14) = *(f32 *)(q + 0xc); else *(f32 *)(q + 0x14) = *(f32 *)(q + 0x10);
        D_001A4BE0_005003D0.f[0x2a1] = 0.036000002f; D_001A4BE0_005003D0.f[0x2a2] = 0.47520003f; qzero(D_001A4BE0_005003D0.b + 0xa0); D_001A4BE0_005003D0.f[0x2a3] = 0.22000001f;
        D_001A4BE0_005003D0.uh[0x103] = 0x21;
        if (*(f32 *)(q + 0x24) != 0.0f) D_001A4BE0_005003D0.f[0x2a1] = *(f32 *)(q + 0x24);
        if (*(f32 *)(q + 0x28) != 0.0f) D_001A4BE0_005003D0.f[0x2a2] = *(f32 *)(q + 0x28);
        if (*(f32 *)(q + 0x2c) != 0.0f) D_001A4BE0_005003D0.f[0x2a3] = *(f32 *)(q + 0x2c);
        D_001A4BE0_005003D0.f[0x29b] = func_0038D160(*(f32 *)(D_001A4BE0_005003D0.ptr[0x295] + 0x10) - D_001A4BE0_005003D0.f[0x20], *(f32 *)(D_001A4BE0_005003D0.ptr[0x295] + 0x14) - D_001A4BE0_005003D0.f[0x21]);
        D_001A4BE0_005003D0.f[0x299] = func_0038CF00(D_001A4BE0_005003D0.b + 0x80, D_001A4BE0_005003D0.ptr[0x295] + 0x10);
        D_001A4BE0_005003D0.f[0x29c] = 0.0108f;
        if (D_001A4BE0_005003D0.i[0x975] == 4) D_001A4BE0_005003D0.f[0x29c] = D_001A4BE0_005003D0.f[0x13c];
        else if (D_001A4BE0_005003D0.i[0x975] == 2) D_001A4BE0_005003D0.f[0x29c] = D_001A4BE0_005003D0.f[0x280];
        if (!animate) goto finish;
        func_L01_0050FB40(0x2f, 0, 9.0f); D_001A4BE0_005003D0.f[0x300] = 0.7f;
        goto finish; }
    case 0x2c:
        D_001A4BE0_005003D0.i[0x973] = 2; qzero(D_001A4BE0_005003D0.b + 0xa0); D_001A4BE0_005003D0.u[0xa03] = 7; (*(u128_t *)(D_001A4BE0_005003D0.b + 0xf0) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050FB40(0xb, 0, 12.0f); goto finish;
    case 0x27: {
        s32 count;
        f32 value;
        f32 start;
        D_001A4BE0_005003D0.i[0x973] = 15; D_001A4BE0_005003D0.u[0xa03] = 3; D_001A4BE0_005003D0.i[0x45a] = 0x68; D_001A4BE0_005003D0.i[0x17a] = 1; D_001A4BE0_005003D0.f[0x17e] = -1.5707964f; D_001A4BE0_005003D0.i[0x178] = 0; D_001A4BE0_005003D0.i[0x19a] = 0; D_001A4BE0_005003D0.i[0x17f] = 0;
        if (D_001A4BE0_005003D0.i[0x975] != 0xf) { D_001A4BE0_005003D0.i[0x185] = 0; D_001A4BE0_005003D0.i[0x187] = -1; D_001A4BE0_005003D0.f[0x188] = 0.0f; }
        start = D_001A4BE0_005003D0.f[0x176]; D_001A4BE0_005003D0.i[0x194] = 0; D_001A4BE0_005003D0.i[0x195] = 0; D_001A4BE0_005003D0.uh[0x32f] = 0; D_001A4BE0_005003D0.i[0x189] = 0; D_001A4BE0_005003D0.i[0x18a] = 0; D_001A4BE0_005003D0.uh[0x316] = 0; D_001A4BE0_005003D0.i[0x18c] = 0; count = D_001A4BE0_005003D0.i[0x175]; value = start;
        func_L01_00476498(D_001A4BE0_005003D0.i[0x174], pos, &count, &value, D_001A4BE0_005003D0.i[0x17d], 1.0f);
        vec_sub_ab(dir, pos, D_001A4BE0_005003D0.b + 0x80);
        if (func_0038CEA8(dir) > 0.001f) {
            func_0038CF68(dir, dir, 1.0f);
            if (D_001A4BE0_005003D0.i[0x975] != 0xf) D_001A4BE0_005003D0.f[0x188] = func_0038CE68((D_001A4BE0_005003D0.b + 0x110), dir);
        }
        if (D_001A4BE0_005003D0.ptr[0x192]) {
            f32 toward = func_0038D160(*(f32 *)(D_001A4BE0_005003D0.ptr[0x192] + 0x10) - D_001A4BE0_005003D0.f[0x20], *(f32 *)(D_001A4BE0_005003D0.ptr[0x192] + 0x14) - D_001A4BE0_005003D0.f[0x21]);
            if (func_0038DBA0(toward, func_0038DAB8(D_001A4BE0_005003D0.f[0x17e], func_0038D160(dir[0], dir[1]))) > 1.5707964f) {
                D_001A4BE0_005003D0.f[0x17e] = 1.5707964f; D_001A4BE0_005003D0.i[0x17f] = 1;
            }
        }
        if (!animate) goto finish;
        func_L01_0050FB40(D_001A4BE0_005003D0.i[0x17f] + 0x2c, 0, 5.0f); goto finish; }
    case 0x76: {
        s32 count;
        f32 value;
        f32 start;
        D_001A4BE0_005003D0.i[0x973] = 26; D_001A4BE0_005003D0.u[0xa03] = 3; D_001A4BE0_005003D0.b[0x25e8] = 1; D_001A4BE0_005003D0.i[0x45a] = 0x68; D_001A4BE0_005003D0.i[0x1a8] = 0; D_001A4BE0_005003D0.i[0x1ae] = 0;
        start = D_001A4BE0_005003D0.f[0x1a6]; count = D_001A4BE0_005003D0.i[0x1a5]; value = start;
        func_L01_00476498(D_001A4BE0_005003D0.i[0x1a4], pos, &count, &value, D_001A4BE0_005003D0.i[0x1ab], 1.0f);
        vec_sub_ab(dir, pos, D_001A4BE0_005003D0.b + 0x80);
        if (func_0038CEA8(dir) > 0.001f) {
            func_0038CF68(dir, dir, 1.0f);
            D_001A4BE0_005003D0.f[0x1a9] = func_0038CE68((D_001A4BE0_005003D0.b + 0x110), dir);
        }
        D_001A4BE0_005003D0.f[0x1a9] = D_001A4BE0_005003D0.f[0x1a9] * 0.5f;
        if (D_001A4BE0_005003D0.f[0x1a9] < 0.0f) D_001A4BE0_005003D0.f[0x1a9] = 0.0f;
        func_L01_0050FB40(0x5a, 0, 7.0f); goto finish; }
    case 0x17:
        D_001A4BE0_005003D0.i[0x973] = 3; D_001A4BE0_005003D0.u[0xa03] = 13;
        D_001A4BE0_005003D0.f[0x14b] = 0.0088f; D_001A4BE0_005003D0.f[0x14c] = D_001A4BE0_005003D0.f[0x22];
        if (D_001A4BE0_005003D0.i[0x975] == 0x4) { D_001A4BE0_005003D0.f[0x14b] = D_001A4BE0_005003D0.f[0x13c]; D_001A4BE0_005003D0.f[0x14c] = D_001A4BE0_005003D0.f[0x118]; }
        D_001A4BE0_005003D0.b[0x25f0] = 1; D_001A4BE0_005003D0.b[0x25ed] = 1;
        if (!animate) goto finish;
        if (D_001A4BE0_005003D0.f[0x5d] > 0.07000001f) func_L01_0050FB40(0x20, 0, 7.0f);
        else func_L01_0050FB40(0x20, 1, 9.0f);
        goto finish;
    case 0x18:
        D_001A4BE0_005003D0.i[0x973] = 3; D_001A4BE0_005003D0.b[0x25f0] = 1; D_001A4BE0_005003D0.u[0xa03] = 13;
        D_001A4BE0_005003D0.b[0x25ed] = 1; D_001A4BE0_005003D0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        func_L01_0050FB40(0x21, 0, 5.0f); goto finish;
    case 0x19:
        D_001A4BE0_005003D0.i[0x973] = 3; D_001A4BE0_005003D0.u[0xa03] = 13; D_001A4BE0_005003D0.b[0x25f0] = 1; D_001A4BE0_005003D0.b[0x25ed] = 1;
        if (!animate) goto finish;
        func_L01_0050FB40(0x24, 0, 5.0f); goto finish;
    case 0x1a:
        D_001A4BE0_005003D0.i[0x973] = 3; D_001A4BE0_005003D0.u[0xa03] = 13; D_001A4BE0_005003D0.b[0x25f0] = 1; D_001A4BE0_005003D0.b[0x25ed] = 1;
        if (!animate) goto finish;
        func_L01_0050FB40(0x25, 0, 5.0f); goto finish;
    case 0x7b:
        D_001A4BE0_005003D0.i[0x973] = 2; (*(u128_t *)(D_001A4BE0_005003D0.b + 0xf0) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120)); D_001A4BE0_005003D0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(11, 0, 10.0f); goto finish;
    case 0x6: case 0x79:
        D_001A4BE0_005003D0.i[0x973] = 2; D_001A4BE0_005003D0.u[0xa03] = 0;
        if (D_001A4BE0_005003D0.i[0x971] == 0x79) D_001A4BE0_005003D0.i[0x973] = 0x14;
        D_001A4BE0_005003D0.f[0x280] = 0.0088f;
        D_001A4BE0_005003D0.f[0x281] = 0.0028000001f;
        if (D_001A4BE0_005003D0.i[0x971] == 0x79) {
            if (!D_001A4BE0_005003D0.b[0x25e4]) D_001A4BE0_005003D0.uh[0x142d] = func_L01_004F4E70(14, 0x20);
            D_001A4BE0_005003D0.f[0x284] = func_L01_00443A18(0.06283186f, 0.08726647f);
            D_001A4BE0_005003D0.f[0x285] = func_L01_00443A18(0.06283186f, 0.08726647f);
        }
        D_001A4BE0_005003D0.i[0x45a] = 0x68; D_001A4BE0_005003D0.i[0x972] = 0;
        (*(u128_t *)(D_001A4BE0_005003D0.b + 0xf0) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120));
        if (!animate) goto finish;
        if (D_001A4BE0_005003D0.b[0x25e4] == 1) { func_L01_0050FB40(4, 0, 7.0f); return 1; }
        if (D_001A4BE0_005003D0.b[0x25e4] == 3) { func_L01_0050FB40(0x15, 0, 7.0f); return 1; }
        if (D_001A4BE0_005003D0.f[0xcf] > 1.75f) { func_L01_0050FB40(11, 0, 10.0f); D_001A4BE0_005003D0.i[0x972] = 1; goto finish; }
        func_L01_0050FB40(10, 0, 8.0f); goto finish;
    case 0xb0:
        D_001A4BE0_005003D0.i[0x973] = 0x25; qzero(D_001A4BE0_005003D0.b + 0xf0); D_001A4BE0_005003D0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x7a, 0, 6.0f); goto finish;
    case 0x8: {
        s32 n = -2;
        D_001A4BE0_005003D0.i[0x973] = 5; D_001A4BE0_005003D0.i[0x45a] = 0x68; D_001A4BE0_005003D0.u[0xa03] = 0;
        if (D_001A4BE0_005003D0.f[0x5c] > 0.09f) func_L01_004F1190(0.09f / D_001A4BE0_005003D0.f[0x5c]);
        D_001A4BE0_005003D0.i[0xa13] = 0; (*(u128_t *)(D_001A4BE0_005003D0.b + 0xf0) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x110));
        if (!animate) goto finish;
        func_L01_0050FB40(0x13, 0, n); goto finish; }
    case 0x7: case 0x9: case 0xa: case 0xb: case 0xc: case 0xd: case 0xe: case 0xf: case 0x10: case 0x11: case 0x12: case 0x1b: case 0x28: case 0x29: case 0x38: case 0x45: case 0x48: case 0x54: case 0x5f: case 0x69: case 0x6b: case 0x73: case 0x86: case 0xa2: case 0xa7: case 0xac:
        if (D_001A4BE0_005003D0.i[0x971] != 0x86 && D_001A4BE0_005003D0.ptr[0xd7] &&
            (*(s16 *)(D_001A4BE0_005003D0.ptr[0xd7] + 0xAA) == 0x9B9 || *(s16 *)(D_001A4BE0_005003D0.ptr[0xd7] + 0xAA) == 0xF05)) {
            func_L01_005003D0(0x86, 1); return 0;
        }
        if (D_001A4BE0_005003D0.b[0x147c] && D_001A4BE0_005003D0.h[0x101] < 12) {
            if (D_001A4BE0_005003D0.h[0x1b6] == 0 || D_001A4BE0_005003D0.f[0xcf] < 1.0f) { func_L01_005003D0(0x7b, 1); return 0; }
        }
        if (D_001A4BE0_005003D0.i[0x971] != 0x73 && D_001A4BE0_005003D0.h[0x1b4] == 1 && action != 0xe &&
            action != 0x38 && !D_L01_001D6740) { func_L01_005003D0(0x73, 1); return 0; }
        if (D_001A4BE0_005003D0.i[0x974] == 0x11 && !D_001A4BE0_005003D0.b[0x285e]) D_001A4BE0_005003D0.b[0x285f]++;
        else D_001A4BE0_005003D0.b[0x285f] = 0;
        if (D_001A4BE0_005003D0.h[0x109]) {
            D_001A4BE0_005003D0.i[0x971] = D_001A4BE0_005003D0.i[0x974]; D_001A4BE0_005003D0.i[0x972] = oldStep; D_001A4BE0_005003D0.i[0x6e] = D_001A4BE0_005003D0.i[0x976];
            return 0;
        }
        D_001A4BE0_005003D0.i[0x973] = 4;
        if ((u32)(action - 0x28) < 2) D_001A4BE0_005003D0.u[0xa03] = 3; else D_001A4BE0_005003D0.u[0xa03] = 0x50;
        if (D_001A4BE0_005003D0.i[0x971] == 0x7 || D_001A4BE0_005003D0.i[0x971] == 0xf || D_001A4BE0_005003D0.i[0x971] == 0xd ||
            (D_001A4BE0_005003D0.i[0x971] == 0xb && D_001A4BE0_005003D0.i[0x975] != 0x4) || D_001A4BE0_005003D0.i[0x971] == 0x69) {
            oldWeapon = D_001A4BE0_005003D0.b[0x147f];
            func_L01_004E11C0(oldWeapon, 0, 0, 30);
            func_L01_004E11C0(oldWeapon, 1, 0, 30);
        }
        (*(u128_t *)(D_001A4BE0_005003D0.b + 0xf0) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120));
        if (D_001A4BE0_005003D0.i[0x971] != 0x12 && D_001A4BE0_005003D0.b[0x1476] && D_001A4BE0_005003D0.f[0x22] < D_001A4BE0_005003D0.f[0xd4] + 0.5f)
            func_L01_004E5EB8(3, 0x10, 0);
        if (D_001A4BE0_005003D0.i[0x971] == 0x6b) func_L01_004F4E70(8, 0);
        D_001A4BE0_005003D0.f[0x118] = D_001A4BE0_005003D0.f[0x22]; D_001A4BE0_005003D0.f[0x13c] = 0.011880001f; D_001A4BE0_005003D0.i[0x106] = -1; D_001A4BE0_005003D0.f[0x134] = 0.008f; D_001A4BE0_005003D0.b[0x46e] = 0; D_001A4BE0_005003D0.b[0x46c] = 0; D_001A4BE0_005003D0.u[0x120] = 0; D_001A4BE0_005003D0.u[0x121] = 0; D_001A4BE0_005003D0.b[0x46d] = 0; D_001A4BE0_005003D0.f[0x135] = 0.0044f; D_001A4BE0_005003D0.f[0x138] = 2.5f; D_001A4BE0_005003D0.uh[0x27c] = D_001A4BE0_005003D0.b[0x1474]; D_001A4BE0_005003D0.uh[0x275] = 0x43; D_001A4BE0_005003D0.uh[0x27a] = 0; D_001A4BE0_005003D0.b[0x4fc] = 0; D_001A4BE0_005003D0.b[0x4fe] = 0; D_001A4BE0_005003D0.b[0x4ff] = 0; D_001A4BE0_005003D0.uh[0x27d] = 0x3a; D_001A4BE0_005003D0.uh[0x27b] = 0; D_001A4BE0_005003D0.f[0x139] = 0.5f; D_001A4BE0_005003D0.f[0x11d] = 0.12340001f; D_001A4BE0_005003D0.f[0x119] = 0.30019665f; D_001A4BE0_005003D0.f[0x11c] = 1.0000001f; D_001A4BE0_005003D0.f[0x10a] = 0.0f; D_001A4BE0_005003D0.b[0x46f] = 0; D_001A4BE0_005003D0.uh[0x142e] = 0;
        if (D_001A4BE0_005003D0.i[0x971] == 0x7 || D_001A4BE0_005003D0.i[0x971] == 0x69) {
            D_001A4BE0_005003D0.f[0x11e] = 1.42f; D_001A4BE0_005003D0.f[0x122] = 0.6f; D_001A4BE0_005003D0.f[0x126] = 18.0f; D_001A4BE0_005003D0.f[0x127] = 30.0f;
            D_001A4BE0_005003D0.f[0x128] = 12.0f; D_001A4BE0_005003D0.f[0x137] = 2.7f; D_001A4BE0_005003D0.f[0x136] = 1.42f; D_001A4BE0_005003D0.uh[0x274] = 14; D_001A4BE0_005003D0.h[0x23e] = 1;
            D_001A4BE0_005003D0.b[0x4fc] = 1; D_001A4BE0_005003D0.b[0x4fe] = 1; D_001A4BE0_005003D0.b[0x4ff] = 1;
            if (D_001D545C_005003D0 == 0) {
                D_001A4BE0_005003D0.f[0x136] = D_L01_001DBCF0; D_001A4BE0_005003D0.uh[0x27b] = 0x8e; D_001A4BE0_005003D0.uh[0x27d] = 0x8e; D_001A4BE0_005003D0.f[0x137] = D_L01_001DBCF4;
                D_001A4BE0_005003D0.f[0x11e] = D_L01_001DBCF0; D_001A4BE0_005003D0.f[0x13c] = D_L01_001DBCF8 * 0.00040000002f; D_001A4BE0_005003D0.u[0xa03] = 0;
            }
            D_001A4BE0_005003D0.f[0x10a] = D_001A4BE0_005003D0.f[0x13c] * 1.17f;
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0x86) {
            D_001A4BE0_005003D0.f[0x11e] = D_L01_001DBD28; D_001A4BE0_005003D0.h[0x23e] = 1; D_001A4BE0_005003D0.f[0x122] = 0.6f; D_001A4BE0_005003D0.f[0x126] = 18.0f;
            D_001A4BE0_005003D0.f[0x127] = 30.0f; D_001A4BE0_005003D0.f[0x128] = 12.0f; D_001A4BE0_005003D0.f[0x137] = D_L01_001DBD28 + 0.5f;
            D_001A4BE0_005003D0.f[0x136] = D_L01_001DBD28; D_001A4BE0_005003D0.uh[0x274] = 14; D_001A4BE0_005003D0.uh[0x275] = 333; D_001A4BE0_005003D0.f[0x138] = 300.0f;
            D_001A4BE0_005003D0.f[0x13c] = D_L01_001DBD2C * 0.00040000002f; D_001A4BE0_005003D0.uh[0x27b] = 1000; D_001A4BE0_005003D0.uh[0x27d] = 1000;
            D_001A4BE0_005003D0.f[0x11d] = 0.14000002f;
            if (D_001439F4_005003D0 != 2) {
                func_L01_0044E318(D_001A4BE0_005003D0.ptr[0x970], (char *)(D_001A4BE0_005003D0.b + 0x1b90));
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0_005003D0.b + 0x1b90), 70, 2, 0.0f);
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0_005003D0.b + 0x1b90), 35, 4, 0.0f);
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0_005003D0.b + 0x1b90), 17, 6, 0.0f);
            }
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0x12) {
            D_001A4BE0_005003D0.f[0x11e] = 0.1f; D_001A4BE0_005003D0.h[0x23e] = 2; D_001A4BE0_005003D0.f[0x122] = 0.6f; D_001A4BE0_005003D0.f[0x126] = 18.0f; D_001A4BE0_005003D0.f[0x127] = 28.0f;
            D_001A4BE0_005003D0.f[0x128] = 14.0f; D_001A4BE0_005003D0.f[0x137] = 0.2f; D_001A4BE0_005003D0.f[0x136] = 0.1f; D_001A4BE0_005003D0.uh[0x274] = 8; D_001A4BE0_005003D0.b[0x4ff] = 1;
            if (D_001A4BE0_005003D0.f[0xa12] < 1.25f) {
                D_001A4BE0_005003D0.f[0x136] = 1.95f; D_001A4BE0_005003D0.h[0x23e] = 4; D_001A4BE0_005003D0.f[0x137] = 1.98f; D_001A4BE0_005003D0.f[0x11e] = D_001A4BE0_005003D0.f[0x136];
            } else {
                func_L01_00511508((V4_F6a70b950 *)(D_001A4BE0_005003D0.b + 0xf0), (V4_F6a70b950 *)(D_001A4BE0_005003D0.b + 0xf0), D_001A4BE0_005003D0.f[0x120]);
                D_001A4BE0_005003D0.f[0x136] = 1.95f; D_001A4BE0_005003D0.h[0x23e] = 4; D_001A4BE0_005003D0.f[0x137] = 1.98f; D_001A4BE0_005003D0.f[0x11e] = D_001A4BE0_005003D0.f[0x136];
            }
            D_001A4BE0_005003D0.b[0x25e8] = 1;
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0x38) {
            D_001A4BE0_005003D0.f[0x11e] = 5.5f; D_001A4BE0_005003D0.h[0x23e] = 4; D_001A4BE0_005003D0.f[0x122] = 0.6f; D_001A4BE0_005003D0.f[0x126] = 18.0f;
            D_001A4BE0_005003D0.f[0x127] = 26.0f; D_001A4BE0_005003D0.f[0x128] = 13.0f; D_001A4BE0_005003D0.f[0x137] = 5.55f; D_001A4BE0_005003D0.f[0x136] = 5.5f;
            D_001A4BE0_005003D0.uh[0x274] = 2; D_001A4BE0_005003D0.uh[0x275] = 100; D_001A4BE0_005003D0.b[0x46f] = 1;
            func_L01_004DFEA0(1);
            D_00142660_005003D0[0x5a] = 0; D_00142660_005003D0[0x5b] = 0;
            if (func_L01_00500240(0x38, 100) || D_001A4BE0_005003D0.i[0xa14] == 0) {
                D_001A4BE0_005003D0.i[0x6dc]++;
                if (D_001A4BE0_005003D0.i[0x6dc] > 2 || D_001A4BE0_005003D0.i[0xa14] == 0) {
                    if (*(s32 *)(*(u8 **)(D_001A4BE0_005003D0.ptr[0x970] + 0x24) + 0x1A8)) func_L01_005003D0(0x7e, 1);
                    else func_L01_005003D0(0x39, 1);
                    return 0;
                }
            } else D_001A4BE0_005003D0.i[0x6dc] = 0;
            D_001A4BE0_005003D0.uh[0x27d] = 125; D_001A4BE0_005003D0.f[0x13c] = 0.006f; D_001A4BE0_005003D0.uh[0x276] = 4; D_001A4BE0_005003D0.uh[0x277] = 3;
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0x6b) {
            f32 height;
            D_001A4BE0_005003D0.i[0x973] = 25;
            if (D_001A4BE0_005003D0.f[0x22] < D_001A4BE0_005003D0.f[0xd5]) height = D_001A4BE0_005003D0.f[0xd5] - D_001A4BE0_005003D0.f[0x22]; else height = D_001A4BE0_005003D0.f[0x120];
            D_001A4BE0_005003D0.f[0x11e] = height + 1.7f; D_001A4BE0_005003D0.h[0x23e] = 4; D_001A4BE0_005003D0.f[0x122] = 0.6f; D_001A4BE0_005003D0.f[0x126] = 18.0f; D_001A4BE0_005003D0.f[0x127] = 30.0f;
            D_001A4BE0_005003D0.f[0x128] = 12.0f; D_001A4BE0_005003D0.f[0x137] = height + 1.75f; D_001A4BE0_005003D0.f[0x136] = height + 1.7f; D_001A4BE0_005003D0.uh[0x274] = 16; D_001A4BE0_005003D0.b[0x46f] = 1;
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0x28) {
            D_001A4BE0_005003D0.f[0x11e] = 2.4f; D_001A4BE0_005003D0.h[0x23e] = 4; D_001A4BE0_005003D0.f[0x122] = 0.8f; D_001A4BE0_005003D0.f[0x126] = 18.0f;
            D_001A4BE0_005003D0.f[0x127] = 28.0f; D_001A4BE0_005003D0.f[0x128] = 14.0f; D_001A4BE0_005003D0.f[0x137] = 2.45f; D_001A4BE0_005003D0.f[0x136] = 2.4f;
            D_001A4BE0_005003D0.uh[0x274] = 14; D_001A4BE0_005003D0.i[0x973] = 15; D_001A4BE0_005003D0.f[0x13c] = 0.0108f; D_001A4BE0_005003D0.i[0x18d] = 0;
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0x29) {
            D_001A4BE0_005003D0.f[0x11e] = 2.5f; D_001A4BE0_005003D0.h[0x23e] = 2; D_001A4BE0_005003D0.f[0x122] = 0.8f; D_001A4BE0_005003D0.f[0x126] = 18.0f;
            D_001A4BE0_005003D0.f[0x127] = 31.0f; D_001A4BE0_005003D0.f[0x128] = 14.0f; D_001A4BE0_005003D0.f[0x137] = 2.55f; D_001A4BE0_005003D0.f[0x136] = 2.5f;
            D_001A4BE0_005003D0.uh[0x274] = 8; D_001A4BE0_005003D0.i[0x973] = 15; D_001A4BE0_005003D0.f[0x13c] = 0.0096f; D_001A4BE0_005003D0.i[0x18d] = 0;
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0x9) {
            D_001A4BE0_005003D0.f[0x11e] = 1.42f; D_001A4BE0_005003D0.h[0x23e] = 1; D_001A4BE0_005003D0.f[0x122] = 0.6f; D_001A4BE0_005003D0.f[0x126] = 18.0f;
            D_001A4BE0_005003D0.f[0x127] = 29.0f; D_001A4BE0_005003D0.f[0x128] = 11.0f; D_001A4BE0_005003D0.f[0x137] = 2.7f; D_001A4BE0_005003D0.f[0x136] = 1.42f;
            D_001A4BE0_005003D0.uh[0x274] = 14; D_001A4BE0_005003D0.f[0x11d] = 0.12340001f;
            if (D_001D545C_005003D0 == 0) {
                D_001A4BE0_005003D0.f[0x136] = D_L01_001DBCF0; D_001A4BE0_005003D0.uh[0x27b] = 0x8e; D_001A4BE0_005003D0.uh[0x27d] = 0x8e; D_001A4BE0_005003D0.f[0x137] = D_L01_001DBCF4;
                D_001A4BE0_005003D0.f[0x11e] = D_L01_001DBCF0; D_001A4BE0_005003D0.f[0x13c] = D_L01_001DBCF8 * 0.00040000002f;
            }
            D_001A4BE0_005003D0.b[0x4fc] = 1;
            D_001A4BE0_005003D0.b[0x4fe] = 1;
            D_001A4BE0_005003D0.b[0x4ff] = 1;
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0x73) {
            D_001A4BE0_005003D0.f[0x122] = 0.6f; D_001A4BE0_005003D0.f[0x126] = 18.0f; D_001A4BE0_005003D0.f[0x127] = 30.0f; D_001A4BE0_005003D0.f[0x128] = 12.0f; D_001A4BE0_005003D0.f[0x137] = 2.75f; D_001A4BE0_005003D0.f[0x11e] = 2.7f; D_001A4BE0_005003D0.h[0x23e] = 4; D_001A4BE0_005003D0.f[0x136] = 2.7f; D_001A4BE0_005003D0.uh[0x274] = 4; D_001A4BE0_005003D0.b[0x4fc] = 1; D_001A4BE0_005003D0.b[0x46f] = 1; D_001A4BE0_005003D0.b[0x4fe] = 0; D_001A4BE0_005003D0.b[0x4ff] = 0;
            if (D_001D545C_005003D0 == 0x15) {
                D_001A4BE0_005003D0.f[0x11d] = 0.070338f;
                if (D_001A4BE0_005003D0.f[0x6d] > 0.070338f) D_001A4BE0_005003D0.f[0x6d] = 0.070338f;
            }
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0x45) {
            D_001A4BE0_005003D0.f[0x11e] = 1.8f; D_001A4BE0_005003D0.h[0x23e] = 1; D_001A4BE0_005003D0.f[0x122] = 0.6f; D_001A4BE0_005003D0.f[0x126] = 15.0f; D_001A4BE0_005003D0.f[0x127] = 22.0f;
            D_001A4BE0_005003D0.f[0x128] = 12.0f; D_001A4BE0_005003D0.f[0x137] = 1.85f; D_001A4BE0_005003D0.f[0x136] = 1.8f; D_001A4BE0_005003D0.uh[0x274] = 12;
            D_001A4BE0_005003D0.f[0x13c] = 0.0076f;
            func_L01_004606A8(0);
            D_001A4BE0_005003D0.f[0x135] = 0.020000001f; D_001A4BE0_005003D0.f[0x11d] = 0.06600001f;
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0x54) {
            D_001A4BE0_005003D0.f[0x11e] = 2.7f; D_001A4BE0_005003D0.f[0x127] = 20.0f; D_001A4BE0_005003D0.h[0x23e] = 1; D_001A4BE0_005003D0.f[0x122] = 0.5f; D_001A4BE0_005003D0.f[0x126] = 15.5f;
            D_001A4BE0_005003D0.f[0x128] = 20.0f; D_001A4BE0_005003D0.f[0x137] = 2.75f; D_001A4BE0_005003D0.f[0x136] = 2.7f; D_001A4BE0_005003D0.uh[0x274] = 8;
            D_001A4BE0_005003D0.f[0x13c] = 0.010000001f; D_001A4BE0_005003D0.f[0x139] = 1.0f; D_001A4BE0_005003D0.f[0x135] = 0.020000001f; D_001A4BE0_005003D0.f[0x11d] = 0.10000001f;
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0xa) {
            D_001A4BE0_005003D0.f[0x11e] = 1.9f; D_001A4BE0_005003D0.h[0x23e] = 4; D_001A4BE0_005003D0.f[0x122] = 0.6f; D_001A4BE0_005003D0.f[0x126] = 18.0f; D_001A4BE0_005003D0.f[0x127] = 29.0f;
            D_001A4BE0_005003D0.f[0x128] = 10.0f; D_001A4BE0_005003D0.f[0x137] = 1.95f; D_001A4BE0_005003D0.f[0x136] = 1.9f; D_001A4BE0_005003D0.uh[0x274] = 12;
            D_001A4BE0_005003D0.f[0x13c] = 0.0044f; D_001A4BE0_005003D0.b[0x4fe] = 1; D_001A4BE0_005003D0.uh[0x275] = 100; D_001A4BE0_005003D0.uh[0x27d] = 75;
            D_001A4BE0_005003D0.uh[0x27b] = 0x3a;
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0x10) {
            D_001A4BE0_005003D0.h[0x23e] = 4; D_001A4BE0_005003D0.f[0x11e] = 1.5f; D_001A4BE0_005003D0.f[0x122] = 0.8f; D_001A4BE0_005003D0.f[0x126] = 18.0f; D_001A4BE0_005003D0.f[0x127] = 30.0f;
            D_001A4BE0_005003D0.f[0x128] = 11.0f; D_001A4BE0_005003D0.f[0x137] = 1.55f; D_001A4BE0_005003D0.f[0x136] = 1.5f; D_001A4BE0_005003D0.uh[0x274] = 1;
            func_L01_003F1F20(20, 0);
            D_001A4BE0_005003D0.f[0x137] = 0.9f; D_001A4BE0_005003D0.f[0x11e] = 0.4f; D_001A4BE0_005003D0.f[0x136] = 0.4f;
            if (D_001A4BE0_005003D0.f[0x61] < 0.40000004f && D_001439F4_005003D0 != 2) {
                func_L01_0044E318(D_001A4BE0_005003D0.ptr[0x970], (char *)(D_001A4BE0_005003D0.b + 0x1b90));
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0_005003D0.b + 0x1b90), 40, 2, 0.0f);
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0_005003D0.b + 0x1b90), 20, 4, 0.0f);
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0_005003D0.b + 0x1b90), 10, 6, 0.0f);
            }
            D_001A4BE0_005003D0.b[0x4fe] = 1; D_001A4BE0_005003D0.f[0x109] = 0.23000002f; D_001A4BE0_005003D0.f[0x13c] = 0.0034000003f; D_001A4BE0_005003D0.f[0x134] = 0.0176f;
            D_001A4BE0_005003D0.f[0x135] = 0.020000001f;
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0x1b) {
            D_001A4BE0_005003D0.f[0x11e] = 2.0f; D_001A4BE0_005003D0.h[0x23e] = 3; D_001A4BE0_005003D0.f[0x122] = 0.85f; D_001A4BE0_005003D0.f[0x126] = 20.0f;
            D_001A4BE0_005003D0.f[0x127] = 29.0f; D_001A4BE0_005003D0.f[0x128] = 19.0f; D_001A4BE0_005003D0.f[0x137] = 2.05f; D_001A4BE0_005003D0.f[0x136] = 2.0f;
            D_001A4BE0_005003D0.f[0x139] = 1.0f; D_001A4BE0_005003D0.f[0x13c] = 0.010000001f; D_001A4BE0_005003D0.uh[0x274] = 1; D_001A4BE0_005003D0.i[0x123] = 0;
            D_001A4BE0_005003D0.b[0x46f] = 1; D_001A4BE0_005003D0.b[0x25f0] = 1; D_001A4BE0_005003D0.b[0x25ed] = 1; D_001A4BE0_005003D0.b[0x4fe] = 1;
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0x48) {
            D_001A4BE0_005003D0.f[0x11e] = 1.55f; D_001A4BE0_005003D0.f[0x127] = 14.0f; D_001A4BE0_005003D0.h[0x23e] = 11; D_001A4BE0_005003D0.f[0x122] = 0.85f;
            D_001A4BE0_005003D0.f[0x126] = 8.0f; D_001A4BE0_005003D0.f[0x128] = 14.0f; D_001A4BE0_005003D0.f[0x137] = 1.59f; D_001A4BE0_005003D0.f[0x136] = 1.55f;
            D_001A4BE0_005003D0.uh[0x274] = 1; D_001A4BE0_005003D0.i[0x123] = 0; D_001A4BE0_005003D0.f[0x13c] = 0.0112000005f;
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0x11) {
            D_001A4BE0_005003D0.h[0x23e] = 7; D_001A4BE0_005003D0.f[0x122] = 0.6f; D_001A4BE0_005003D0.f[0x126] = 12.0f; D_001A4BE0_005003D0.f[0x127] = 20.0f;
            D_001A4BE0_005003D0.f[0x128] = 10.0f; D_001A4BE0_005003D0.uh[0x274] = 10;
            if (D_001A4BE0_005003D0.b[0x285e]) {
                f32 lim = 7.0f, w = D_001A4BE0_005003D0.f[0xa18];
                D_001A4BE0_005003D0.f[0x11a] = 0.09800001f; D_001A4BE0_005003D0.f[0x137] = 3.35f; D_001A4BE0_005003D0.f[0x136] = 3.3f;
                if (w > lim) {
                    f32 t = (w - lim) / 4.2f;
                    if (t > 0.7f) t = 0.7f;
                    t += 1.0f;
                    D_001A4BE0_005003D0.f[0x11a] = t * 0.09800001f;
                }
            } else {
                D_001A4BE0_005003D0.f[0x11a] = 0.034f; D_001A4BE0_005003D0.f[0x137] = 1.85f; D_001A4BE0_005003D0.f[0x136] = 1.8f;
            }
            D_001A4BE0_005003D0.b[0x46f] = 1; D_001A4BE0_005003D0.f[0x11e] = D_001A4BE0_005003D0.f[0x136];
            func_L01_003F1F20(0x1b, 0);
            D_001A4BE0_005003D0.uh[0x27d] = 0x43; D_001A4BE0_005003D0.f[0x13c] = 0.011600001f; (*(u128_t *)(D_001A4BE0_005003D0.b + 0x4c0) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x4b0));
            D_001A4BE0_005003D0.uh[0x142e] = 1; D_001A4BE0_005003D0.b[0x25e8] = 1; D_001A4BE0_005003D0.b[0x4fc] = 1;
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0xd) {
            D_001A4BE0_005003D0.h[0x23e] = 7; D_001A4BE0_005003D0.f[0x122] = 0.6f; D_001A4BE0_005003D0.f[0x126] = 26.0f; D_001A4BE0_005003D0.f[0x127] = 38.0f;
            D_001A4BE0_005003D0.f[0x128] = 18.0f; D_001A4BE0_005003D0.f[0x137] = 4.07f; D_001A4BE0_005003D0.uh[0x274] = 12; D_001A4BE0_005003D0.f[0x11e] = 4.0f;
            D_001A4BE0_005003D0.f[0x136] = 4.0f;
            func_L01_003F1F20(20, 0);
            D_001A4BE0_005003D0.f[0x138] = 4.5f; D_001A4BE0_005003D0.uh[0x275] = 100; D_001A4BE0_005003D0.f[0x11d] = 0.038000003f; D_001A4BE0_005003D0.uh[0x27b] = 31;
            if (D_001A4BE0_005003D0.f[0x61] < 0.40000004f && D_001439F4_005003D0 != 2) {
                func_L01_0044E318(D_001A4BE0_005003D0.ptr[0x970], (char *)(D_001A4BE0_005003D0.b + 0x1b90));
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0_005003D0.b + 0x1b90), 40, 3, 0.0f);
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0_005003D0.b + 0x1b90), 20, 5, 0.0f);
            }
            D_001A4BE0_005003D0.b[0x4fe] = 1;
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0xf) {
            D_001A4BE0_005003D0.f[0x11e] = 1.65f; D_001A4BE0_005003D0.h[0x23e] = 7; D_001A4BE0_005003D0.f[0x122] = 0.6f; D_001A4BE0_005003D0.f[0x126] = 50.0f;
            D_001A4BE0_005003D0.f[0x127] = 64.0f; D_001A4BE0_005003D0.f[0x128] = 28.0f; D_001A4BE0_005003D0.f[0x137] = 1.7f; D_001A4BE0_005003D0.f[0x136] = 1.65f;
            D_001A4BE0_005003D0.uh[0x274] = 4; D_001A4BE0_005003D0.f[0x138] = 4.5f; D_001A4BE0_005003D0.uh[0x275] = 0x6c; D_001A4BE0_005003D0.f[0x11d] = 0.06600001f;
            D_001A4BE0_005003D0.uh[0x27b] = 0x47; D_001A4BE0_005003D0.uh[0xe8] = 0x3a; D_001A4BE0_005003D0.b[0x46d] = 1;
            if (D_00143950) D_001A4BE0_005003D0.i[0x100] = 0x1c; else D_001A4BE0_005003D0.i[0x100] = 0x1d;
            D_001A4BE0_005003D0.i[0x101] = D_001A4BE0_005003D0.i[0x100] + 0x1e;
            D_001A4BE0_005003D0.f[0x102] = 29.0f;
            D_001A4BE0_005003D0.f[0x103] = 50.0f;
            D_001A4BE0_005003D0.u[0x104] = 0x48;
            D_001A4BE0_005003D0.ptr[0x105] = D_L01_001DBE58;
            D_001A4BE0_005003D0.b[0x4fe] = 1;

        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0xe) {
            f32 h = D_001A4BE0_005003D0.f[0xcf], v = 0.7f;
            if (h < 2.0f) v = (2.5f - h) * 0.5f + v;
            D_001A4BE0_005003D0.f[0x11e] = v; D_001A4BE0_005003D0.h[0x23e] = -1; D_001A4BE0_005003D0.f[0x122] = 0.6f; D_001A4BE0_005003D0.f[0x126] = 32.0f; D_001A4BE0_005003D0.f[0x127] = 43.0f; D_001A4BE0_005003D0.f[0x128] = 19.0f; D_001A4BE0_005003D0.f[0x137] = v + 0.05f; D_001A4BE0_005003D0.f[0x136] = v; D_001A4BE0_005003D0.uh[0x274] = 12; D_001A4BE0_005003D0.f[0x139] = 1.0f; D_001A4BE0_005003D0.f[0x11d] = 0.095000006f; D_001A4BE0_005003D0.uh[0x27b] = 0x19;
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0xb) {
            D_001A4BE0_005003D0.f[0x11e] = 3.2f; D_001A4BE0_005003D0.h[0x23e] = 1; D_001A4BE0_005003D0.f[0x122] = 0.6f; D_001A4BE0_005003D0.f[0x126] = 18.0f; D_001A4BE0_005003D0.f[0x127] = 31.0f; D_001A4BE0_005003D0.f[0x128] = 24.0f; D_001A4BE0_005003D0.f[0x137] = 3.25f; D_001A4BE0_005003D0.f[0x136] = 3.2f; D_001A4BE0_005003D0.uh[0x274] = 12; D_001A4BE0_005003D0.f[0x138] = 4.5f; D_001A4BE0_005003D0.uh[0x27d] = 0x2a; D_001A4BE0_005003D0.f[0x139] = 1.0f; D_001A4BE0_005003D0.b[0x46f] = 1;
            D_001A4BE0_005003D0.f[0x125] = func_L01_004E93F8(8);
            (*(u128_t *)(D_001A4BE0_005003D0.b + 0x450) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x0));
            D_001A4BE0_005003D0.i[0x129] = func_L01_004FF610();
            D_001A4BE0_005003D0.f[0x124] = D_001A4BE0_005003D0.f[0x68];
            (*(u128_t *)(D_001A4BE0_005003D0.b + 0x440) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x190));
            if (D_001A4BE0_005003D0.f[0x5d] > 0.030000001f) D_001A4BE0_005003D0.f[0x12a] = D_001A4BE0_005003D0.f[0x5d];
            else D_001A4BE0_005003D0.f[0x12a] = 0.0f;
            D_001A4BE0_005003D0.u[0x12b] = 0;
            D_001A4BE0_005003D0.b[0x4fc] = 1;
            if ((D_001A4BE0_005003D0.h[0xa1a] || (D_001A4BE0_005003D0.i[0x5ac] == 1 && func_L01_004606E8(0x28, 2, 0, 0))) && D_001A4BE0_005003D0.f[0xa0e] > 0.3f) {
                func_L01_004EE850(0, D_001A4BE0_005003D0.f[0x6c]);

                D_001A4BE0_005003D0.f[0x124] = D_001A4BE0_005003D0.f[0x68];
                (*(u128_t *)(D_001A4BE0_005003D0.b + 0x440) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x1420));
                D_001A4BE0_005003D0.f[0x12b] = 0.10000001f;
                D_001A4BE0_005003D0.b[0x4fd] = 1;
            } else D_001A4BE0_005003D0.b[0x4fd] = 0;
            D_001A4BE0_005003D0.b[0x4fe] = 1;
        }
        if (D_001A4BE0_005003D0.f[0x138] == 0.0f) D_001A4BE0_005003D0.f[0x138] = D_001A4BE0_005003D0.f[0x11e] * 1.5f;
        if (!animate) goto finish;
        if (D_001A4BE0_005003D0.i[0x971] == 0x7 || D_001A4BE0_005003D0.i[0x971] == 0x69) func_L01_0050FB40(7, 1, -4.0f);
        else if (D_001A4BE0_005003D0.i[0x971] == 0x73) func_L01_0050FB40(7, 0, 4.0f);
        else if (D_001A4BE0_005003D0.i[0x971] == 0x86) func_L01_0050FB40(7, 0, 4.0f);
        else if (D_001A4BE0_005003D0.i[0x971] == 0x12) func_L01_0050FB40(0x59, 1, -4.0f);
        else if (D_001A4BE0_005003D0.i[0x971] == 0x38) func_L01_0050FB40(0x3e, 0, 3.0f);
        else if (D_001A4BE0_005003D0.i[0x971] == 0x6b) func_L01_0050FB40(7, 0, 4.0f);
        else if (D_001A4BE0_005003D0.i[0x971] == 0x28) func_L01_0050FB40(0x48, 4, 4.0f);
        else if (D_001A4BE0_005003D0.i[0x971] == 0x29) {
            s32 turn = 0x1e;
            if (func_0038DBA0(D_001A4BE0_005003D0.f[0x26], func_0038D160(D_001A4BE0_005003D0.f[0x15c] - D_001A4BE0_005003D0.f[0x16c], D_001A4BE0_005003D0.f[0x15d] - D_001A4BE0_005003D0.f[0x16d])) > 1.5707964f) turn = 0x1f;
            func_L01_0050FB40(turn, 0, 4.0f);
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0x9) {
            index = (s32)D_001A4BE0_005003D0.f[0x306];
            animation_41 = 8;
            if (func_L01_004DFE80(objectSnapshot[0x42]) == 4) animation_41 = D_L01_001DBE38[index];
            func_L01_0050FB40(animation_41, 0, 4.0f);
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0x45) func_L01_0050FB40(0x16, 5, 4.0f);
        else if (D_001A4BE0_005003D0.i[0x971] == 0x54) func_L01_0050FB40(3, 5, 2.0f);
        else if (D_001A4BE0_005003D0.i[0x971] == 0xa) func_L01_0050FB40(0x12, 0, 4.0f);
        else if (D_001A4BE0_005003D0.i[0x971] == 0x10) {
            if (D_001A4BE0_005003D0.i[0x975] == 4 || (D_001A4BE0_005003D0.i[0x974] == 4 && D_001A4BE0_005003D0.i[0x6e] < 6)) {
                func_L01_0050FB40(0x26, 0, 7.0f);
                D_001A4BE0_005003D0.uh[0x23e] += 2;
            } else func_L01_0050FB40(0x26, 0, 4.0f);
        }
        else if (D_001A4BE0_005003D0.i[0x971] == 0x1b) func_L01_0050FB40(0x22, 2, 2.0f);
        else if (D_001A4BE0_005003D0.i[0x971] == 0x48) func_L01_0050FB40(9, 0, 3.0f);
        else if (D_001A4BE0_005003D0.i[0x971] == 0x11) func_L01_0050FB40(0x23, 2, 6.0f);
        else if (D_001A4BE0_005003D0.i[0x971] == 0xd) func_L01_0050FB40(0x11, 0, 4.0f);
        else if (D_001A4BE0_005003D0.i[0x971] == 0xe) { func_L01_0050FB40(0x16, 3, 6.0f); D_001A4BE0_005003D0.f[0x300] = 0.96000004f; }
        else if (D_001A4BE0_005003D0.i[0x971] == 0xf) func_L01_0050FB40(0x15, 0, 4.0f);
        else if (D_001A4BE0_005003D0.i[0x971] == 0xb) {
            s32 a = D_001A4BE0_005003D0.i[0x129] + 0x1c;
            if (D_001D545C_b[0xd]) {
                if (a == 0x1c) a = 0x1d;
                else if (a == 0x1d) a = 0x1c;
            }
            if (D_001A4BE0_005003D0.i[0x975] == 4) { func_L01_0050FB40(a, 1, 3.0f); D_001A4BE0_005003D0.h[0x23e] = 1; }
            else func_L01_0050FB40(a, 0, 4.0f);
        }
        goto finish;
    case 0x13: case 0x14: case 0x15: case 0x22: case 0x4d: case 0x88:
        if (D_001A4BE0_005003D0.h[0x1445] && D_001A4BE0_005003D0.i[0x971] == 0x15) {
            D_001A4BE0_005003D0.i[0x971] = D_001A4BE0_005003D0.i[0x974]; D_001A4BE0_005003D0.i[0x972] = oldStep; D_001A4BE0_005003D0.i[0x6e] = D_001A4BE0_005003D0.i[0x976];
            return 0;
        }
        D_001A4BE0_005003D0.i[0x973] = 6;
        if (D_001A4BE0_005003D0.i[0x5ac] == 2 && (u32)(D_001A4BE0_005003D0.i[0x971] - 0x13) < 3) {
            if (D_001A7C10[1].count < 0xFFFF) D_001A7C10[1].count++;
            if (D_001A7C10[1].maximum < (D_001D4C38 * 5 + 2) / 6) D_001A7C10[1].maximum = (D_001D4C38 * 5 + 2) / 6;
            D_001A7C10[1].levels = (D_001A7C10[1].levels | (1u << D_001D545C_005003D0)) | 0x80000000u;
            if (D_001A4BE0_005003D0.i[0x48a] == 0x7f && func_L01_005119E0(-1)) func_L01_004F5AE8();
            else func_L01_004F5810();
            D_001A4BE0_005003D0.i[0x971] = D_001A4BE0_005003D0.i[0x974]; D_001A4BE0_005003D0.i[0x973] = D_001A4BE0_005003D0.i[0x975];
            return 0;
        }
        if (D_001A4BE0_005003D0.i[0x48a] == 0x7f && !func_L01_005119E0(-1)) {
            D_001A4BE0_005003D0.i[0x971] = D_001A4BE0_005003D0.i[0x974]; D_001A4BE0_005003D0.i[0x973] = D_001A4BE0_005003D0.i[0x975];
            return 0;
        }
        if (action != 0x88) D_001A4BE0_005003D0.u[0xa03] = 0;
        D_001A4BE0_005003D0.f[0x2f5] = 1.0f; D_001A4BE0_005003D0.i[0x2f2] = 0; D_001A4BE0_005003D0.u[0x2f1] = 0; D_001A4BE0_005003D0.uh[0x5ef] = 0;
        switch (D_001A4BE0_005003D0.i[0x971]) {
        case 0x14:
            if (D_001A7C10[0].count < 0xFFFF) D_001A7C10[0].count++;
            if (D_001A7C10[0].maximum < (D_001D4C38 * 5 + 2) / 6) D_001A7C10[0].maximum = (D_001D4C38 * 5 + 2) / 6;
            D_001A7C10[0].levels = (D_001A7C10[0].levels | (1u << D_001D545C_005003D0)) | 0x80000000u;
            D_001A4BE0_005003D0.u[0xa03] = 0x50; D_001A4BE0_005003D0.h[0x5ee] = 4; D_001A4BE0_005003D0.i[0x98c] = 0;
            func_L01_004F2880(8.0f, 1.0471976f, -1.0f); D_001A4BE0_005003D0.u[0x2f8] = 0;
            if (animate) {
                selected_14 = D_001A4BE0_005003D0.i[0x974] == 0xb && D_001A4BE0_005003D0.i[0x976] < 35 ? 14 : 9;
                func_L01_005118D0(-1, 1);
                D_L01_001DD67C = 1;
                func_L01_0050FB40(0x28, 4, (f32)selected_14);
                animation_14 = func_L01_004E9200(0);
                if (func_L01_004EDFA8((u8 *)animation_14)) func_003C3A10((u8 *)animation_14, 10, 4, selected_14 + 2);
            }
            goto finish;
        case 0x15:
            if (D_001A7C10[1].count < 0xFFFF) D_001A7C10[1].count++;
            if (D_001A7C10[1].maximum < (D_001D4C38 * 5 + 2) / 6) D_001A7C10[1].maximum = (D_001D4C38 * 5 + 2) / 6;
            D_001A7C10[1].levels = (D_001A7C10[1].levels | (1u << D_001D545C_005003D0)) | 0x80000000u;
            D_001A4BE0_005003D0.h[0x5ee] = 3; D_001A4BE0_005003D0.i[0x98c] = 0;
            func_L01_004F2880(14.0f, 0.5235988f, -1.0f);
            D_001A4BE0_005003D0.u[0x2fb] = D_001A4BE0_005003D0.u[0x2fb] == 0;
            if (D_001A4BE0_005003D0.h[0xa1a] || (D_001A4BE0_005003D0.i[0x5ac] == 1 && func_L01_004606E8(0x28, 2, 0, 0))) {
                D_001A4BE0_005003D0.i[0x2f2] = 1; D_001A4BE0_005003D0.f[0x2f3] = D_001A4BE0_005003D0.f[0x26];
            }
            if (animate) {
                selected_15 = D_001A4BE0_005003D0.ptr[0x970][0x43] == 0x1A ? 2 : 4;
                if (D_001A4BE0_005003D0.i[0x974] == 0x1) selected_15 = 14;
                func_L01_0050FB40(0x1A, 0, (f32)selected_15); func_L01_0050FE88(6, 21);
            }
            goto finish;
        case 0x88:
            D_001A4BE0_005003D0.h[0x5ee] = 3;
            if (animate) {
                selected_83 = D_001A4BE0_005003D0.ptr[0x970][0x43] == 0x1A ? 2 : 8;
                if (D_001A4BE0_005003D0.i[0x974] == 0x1) selected_83 = 14;
                func_L01_0050FB40(0x1A, 0, (f32)selected_83);
            }
            goto finish;
        case 0x13:
        {
        s32 *entry = D_L01_002F62D0[D_001A4BE0_005003D0.h[0x5ee]];
        D_001A4BE0_005003D0.i[0x98c] = 0; mode = 0;
        if ((D_001A4BE0_005003D0.i[0x974] == 0x13 && (f32)entry[2] > D_001A4BE0_005003D0.f[0x306]) ||
            (D_001A4BE0_005003D0.i[0x977] == 0x13 && D_001A4BE0_005003D0.i[0x6e] + D_001A4BE0_005003D0.i[0x976] < 22)) mode = (entry[1] + 1) % 3;
        }
        D_001A4BE0_005003D0.h[0x5ee] = mode;
        func_L01_004F2880(5.0f, 0.7853982f, 0.7853982f);
        if (animate) {
            current = 0;
            if (mode == 0) { func_L01_005118D0(-1, 1); selected_13 = 4; D_L01_001DD67C = 1; }
            else if (mode == 1) { func_L01_005118D0(-1, 1); current = 2; D_L01_001DD67C = 1; selected_13 = 6; }
            else { func_L01_005118D0(-1, 1); current = 4; D_L01_001DD67C = 1; selected_13 = 6; }
            if (D_001A4BE0_005003D0.i[0x2f2] && mode < 2) {
                if (D_001A4BE0_005003D0.b[0x25f4]) angle_13 = func_L01_004F4E20((D_001A4BE0_005003D0.b + 0xba0), 0);
                else angle_13 = func_0038DBA0(D_001A4BE0_005003D0.f[0x2f3], D_001A4BE0_005003D0.f[0x26]);
                selected_13 += (s32)(angle_13 * 1.5f);
            }
            current /= 2;
            func_L01_0050FB40(mode + 0x17, current, (f32)selected_13);
            animation_13 = func_L01_004E9200(0);
            if (func_L01_004EDFA8((u8 *)animation_13)) func_L01_00444F38((u8 *)animation_13, mode + 3, current, selected_13, 0x10);
        }
        goto finish;
        case 0x4d: {
            s32 m4d;
            s32 *row = D_L01_002F62D0[D_001A4BE0_005003D0.h[0x5ee]];
            m4d = 0;
            if ((D_001A4BE0_005003D0.i[0x975] == 0x6 || (D_001A4BE0_005003D0.i[0x978] == 0x6 && (u32)(D_001A4BE0_005003D0.ptr[0x970][0x43] - 15) < 2)) &&
                row[0] == 0 && (f32)row[2] > D_001A4BE0_005003D0.f[0x306]) m4d = (row[1] + 1) % 2;
            D_001A4BE0_005003D0.h[0x5ee] = m4d + 7;
            func_L01_004F2880(5.0f, 0.7853982f, 0.7853982f);
            if (animate) func_L01_0050FB40(m4d + 0xF, 2, 3.0f);
            goto finish; }
        case 0x22:
            if (animate) func_L01_0050FB40(0x29, 7, 7.0f);
            goto finish;
        }
        goto finish;
    case 0x72:
        D_001A4BE0_005003D0.i[0x973] = 6; D_001A4BE0_005003D0.uh[0x5ef] = 0;
        if (D_001A4BE0_005003D0.i[0x974] == 0x72) D_001A4BE0_005003D0.h[0x5ee] = D_L01_002F62D0[D_001A4BE0_005003D0.h[0x5ee]][1] == 0 ? 6 : 5;
        else D_001A4BE0_005003D0.h[0x5ee] = 5;
        {
            s32 kind = D_L01_002F62D0[D_001A4BE0_005003D0.h[0x5ee]][1];
            s32 still;
            u32 object;
            if (!animate) goto finish;
            still = kind == 0;
            func_L01_0050FB40(kind + 0x17, still, 4.0f);
            object = func_L01_004E9200(0);
            if (func_L01_004EDFA8((u8 *)object)) func_003C3A10((u8 *)object, kind + 0xC, still, 4);
        }
        goto finish;
    case 0x2a:
        D_001A4BE0_005003D0.i[0x973] = 15; D_001A4BE0_005003D0.uh[0x5ef] = 0;
        if (D_001A4BE0_005003D0.i[0x974] == 0x2a) D_001A4BE0_005003D0.h[0x5ee] = D_001A4BE0_005003D0.h[0x5ee] == 0; else D_001A4BE0_005003D0.h[0x5ee] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(D_001A4BE0_005003D0.h[0x5ee] + 0x46, 0, 3.0f);
        {
            u32 object = func_L01_004E9200(0);
            if (func_L01_004EDFA8((u8 *)object)) func_003C3A10((u8 *)object, D_001A4BE0_005003D0.h[0x5ee] + 0xC, 0, 3);
        }
        goto finish;
    case 0x7c:
        D_001A4BE0_005003D0.i[0x973] = 10; D_001A4BE0_005003D0.u[0xa03] = 0;
        D_001A4BE0_005003D0.f[0x2f4] = func_0038DAB8(D_001A4BE0_005003D0.f[0x26], 3.1415927f);
        func_0038CE20((D_001A4BE0_005003D0.b + 0xbb0), (D_001A4BE0_005003D0.b + 0x0), -1.0f); D_001A4BE0_005003D0.f[0x6d] = 0.18f;
        if (!animate) goto finish;
        func_L01_0050FB40(0x27, 5, 7.0f); goto finish;
    case 0x16:
        D_001A4BE0_005003D0.u[0xa03] = 0; D_001A4BE0_005003D0.i[0x973] = 7;
        func_L01_004F1190(0.5f); func_L01_003F1F20(18, 0);
        D_001A4BE0_005003D0.uh[0x107] = 0x25; (*(u128_t *)(D_001A4BE0_005003D0.b + 0xf0) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120)); func_003C4BB0((f32 *)(D_001A4BE0_005003D0.b + 0xf0), 0.14000002f);
        hit_44 = func_L01_00447490(D_001A4BE0_005003D0.ptr[0x970], 1, 0);
        if (hit_44) func_L01_004DFEA0((s32)(*(f32 *)(hit_44 + 0x2C)));
        else func_L01_004DFEA0(1);
        D_001A4BE0_005003D0.uh[0xee] = 64;
        if (!animate) goto finish;
        func_L01_0050FB40(0x10, 3, -3.0f);
        *(f32 *)(D_001A4BE0_005003D0.ptr[0x970] + 0x44) = D_L01_002F6460[D_001A4BE0_005003D0.i[0x304]][D_001A4BE0_005003D0.i[0x305]++];
        goto finish;
    case 0x91:
        D_001A4BE0_005003D0.i[0x973] = 7; D_001A4BE0_005003D0.u[0xa03] = 0; func_L01_004F1190(0.5f);
        D_001A4BE0_005003D0.b[0x25ed] = 1; func_L01_003F1F20(18, 0);
        hit_45 = func_L01_00447490(D_001A4BE0_005003D0.ptr[0x970], 8, 0);
        if (hit_45) func_L01_004DFEA0((s32)(*(f32 *)(hit_45 + 0x2C)));
        else func_L01_004DFEA0(1);
        D_001A4BE0_005003D0.uh[0xee] = 64;
        if (!animate) goto finish;
        func_L01_0050FB40(0x74, 1, -3.0f);
        *(f32 *)(D_001A4BE0_005003D0.ptr[0x970] + 0x44) = D_L01_002F6460[D_001A4BE0_005003D0.i[0x304]][D_001A4BE0_005003D0.i[0x305]++];
        goto finish;
    case 0x6a:
        D_001A4BE0_005003D0.i[0x973] = 0x19; D_001A4BE0_005003D0.u[0xa03] = 0; D_001A4BE0_005003D0.i[0x6dc]++;
        func_L01_004F4E70(7, 0);
        D_001A4BE0_005003D0.i[0xf0] = 0; D_001A4BE0_005003D0.u[0x6c] = 0; D_001A4BE0_005003D0.u[0x6d] = 0; D_001A4BE0_005003D0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        func_L01_0050FB40(0x58, 0, 7.0f); goto finish;
    case 0x7d:
        D_001A4BE0_005003D0.i[0x973] = 0x19; D_001A4BE0_005003D0.uh[0xf8] = 10000; D_001A4BE0_005003D0.u[0xa03] = 0;
        func_L01_004F4E70(7, 0);
        D_001A4BE0_005003D0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        func_L01_0050FB40(0x58, 0, 7.0f); goto finish;
    case 0x7e:
        D_001A4BE0_005003D0.i[0x973] = 20; D_001A4BE0_005003D0.f[0xd5] = D_001A4BE0_005003D0.f[0xce]; D_001A4BE0_005003D0.uh[0xf8] = 10000;
        D_001A4BE0_005003D0.i[0xa14] = 0; D_001A4BE0_005003D0.u[0xa03] = 0; func_L01_004F4E70(7, 0);
        if (!animate) goto finish;
        func_L01_0050FB40(0x58, 0, 7.0f); goto finish;
    case 0x7f:
        D_001A4BE0_005003D0.i[0x973] = 20; D_001A4BE0_005003D0.uh[0xf8] = 10000; D_001A4BE0_005003D0.f[0xd5] = D_001A4BE0_005003D0.f[0xce];
        D_001A4BE0_005003D0.u[0xa03] = 0; D_001A4BE0_005003D0.i[0xa14] = 0;
        *(u128_t *)(D_001A4BE0_005003D0.ptr[0x2fe] + 0x10) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x80);
        func_003A52A0(7, 0, D_001A4BE0_005003D0.ptr[0x2fe]);
        if (!animate) goto finish;
        func_L01_0050FB40(0x11, 0, 7.0f); goto finish;
    case 0x3f:
        D_001A4BE0_005003D0.i[0x973] = 0; D_001A4BE0_005003D0.u[0xa03] = 0;
        if (D_001A4BE0_005003D0.b[0x147c] && D_001A4BE0_005003D0.h[0x1b6] == 0) { func_L01_005003D0(0x4e, 1); return 0; }
        if (!animate) goto finish;
        func_L01_0050FB40(func_L01_004DFDB0(0), 0, 7.0f); goto finish;
    case 0x4b:
        D_001A4BE0_005003D0.i[0x973] = 5; D_001A4BE0_005003D0.u[0xa03] = 0;
        if (D_001A4BE0_005003D0.f[0x5c] > 0.09f) func_L01_004F1190(0.09f / D_001A4BE0_005003D0.f[0x5c]);
        (*(u128_t *)(D_001A4BE0_005003D0.b + 0xf0) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x110));
        if (!animate) goto finish;
        func_L01_0050FB40(14, 0, 10.0f); goto finish;
    case 0x4f:
        D_001A4BE0_005003D0.i[0x973] = 0; D_001A4BE0_005003D0.u[0xa03] = 0; qzero(D_001A4BE0_005003D0.b + 0xf0);
        if (!animate) goto finish;
        func_L01_0050FB40(0x20, 2, 3.0f); goto finish;
    case 0x41:
        D_001A4BE0_005003D0.i[0x973] = 2; (*(u128_t *)(D_001A4BE0_005003D0.b + 0xf0) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120)); D_001A4BE0_005003D0.f[0x281] = 0.0028000001f; D_001A4BE0_005003D0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(4, 0, 7.0f); goto finish;
    case 0x44:
        D_001A4BE0_005003D0.i[0x973] = 2; D_001A4BE0_005003D0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(4, 0, 7.0f); goto finish;
    case 0x4e:
        D_001A4BE0_005003D0.i[0x973] = 2; (*(u128_t *)(D_001A4BE0_005003D0.b + 0xf0) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120)); D_001A4BE0_005003D0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(4, 0, 10.0f); goto finish;
    case 0x42:
        D_001A4BE0_005003D0.i[0x973] = 7; D_001A4BE0_005003D0.u[0xa03] = 0;
        func_L01_004F1190(0.5f);
        (*(u128_t *)(D_001A4BE0_005003D0.b + 0xf0) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120)); func_003C4BB0((f32 *)(D_001A4BE0_005003D0.b + 0xf0), 0.10000001f);
        hit_52 = func_L01_00447490(D_001A4BE0_005003D0.ptr[0x970], 1, 0);
        if (hit_52) func_L01_004DFEA0((s32)(*(f32 *)(hit_52 + 0x2C)));
        else func_L01_004DFEA0(1);
        D_001A4BE0_005003D0.uh[0x107] = 0x25;
        if (D_001A4BE0_005003D0.i[0xa14] <= 0) { func_L01_005003D0(0x43, 1); func_L01_003F1F20(18, 0); return 0; }
        func_L01_003F1F20(18, 0);
        D_001A4BE0_005003D0.uh[0xee] = 0x2a;
        if (!animate) goto finish;
        func_L01_0050FB40(6, 3, -3.0f);
        *(f32 *)(D_001A4BE0_005003D0.ptr[0x970] + 0x44) = D_L01_002F6460[D_001A4BE0_005003D0.i[0x304]][D_001A4BE0_005003D0.i[0x305]++];
        goto finish;
    case 0x40:
        if (D_001A4BE0_005003D0.b[0x147c] && D_001A4BE0_005003D0.h[0x1b6] == 0) { func_L01_005003D0(0x4e, 1); return 0; }
        D_001A4BE0_005003D0.i[0x973] = 1; D_001A4BE0_005003D0.u[0xa03] = 0;
        D_001A4BE0_005003D0.f[0x6d] = func_0038CED8((D_001A4BE0_005003D0.b + 0x120));
        if (D_001A4BE0_005003D0.i[0x974] == 0x3) D_001A4BE0_005003D0.u[0x6d] = 0;
        if (D_001A4BE0_005003D0.i[0x975] == 0x0) D_001A4BE0_005003D0.f[0x6d] = func_0038CED8((D_001A4BE0_005003D0.b + 0x160));
        D_001A4BE0_005003D0.b[0x3ec] = 0; D_001A4BE0_005003D0.b[0x3ef] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x19, 0, 7.0f); goto finish;
    case 0x43:
        D_001A4BE0_005003D0.i[0x973] = 20; (*(u128_t *)(D_001A4BE0_005003D0.b + 0x160) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120)); D_001A4BE0_005003D0.i[0xa14] = 0; D_001A4BE0_005003D0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(5, 2, 3.0f); goto finish;
    case 0x46:
        D_001A4BE0_005003D0.i[0x973] = 3; D_001A4BE0_005003D0.u[0xa03] = 13;
        D_001A4BE0_005003D0.f[0x14b] = 0.0048f; D_001A4BE0_005003D0.f[0x14c] = D_001A4BE0_005003D0.f[0x22];
        if (D_001A4BE0_005003D0.i[0x975] == 0x4) { D_001A4BE0_005003D0.f[0x14b] = D_001A4BE0_005003D0.f[0x13c]; D_001A4BE0_005003D0.f[0x14c] = D_001A4BE0_005003D0.f[0x118]; }
        if (!animate) goto finish;
        func_L01_0050FB40(8, 14, 6.0f); goto finish;
    case 0x47:
        D_001A4BE0_005003D0.i[0x973] = 3; D_001A4BE0_005003D0.u[0xa03] = 13;
        if (!animate) goto finish;
        func_L01_0050FB40(10, 0, 5.0f); goto finish;
    case 0x49:
        D_001A4BE0_005003D0.i[0x973] = 3; D_001A4BE0_005003D0.u[0xa03] = 13;
        if (!animate) goto finish;
        func_L01_0050FB40(11, 0, 5.0f); goto finish;
    case 0x4a:
        D_001A4BE0_005003D0.i[0x973] = 3; D_001A4BE0_005003D0.u[0xa03] = 13;
        if (!animate) goto finish;
        func_L01_0050FB40(12, 0, 5.0f); goto finish;
    case 0x51:
        D_001A4BE0_005003D0.i[0x973] = 0; D_001A4BE0_005003D0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(1, 0, 12.0f); goto finish;
    case 0x59:
        D_001A4BE0_005003D0.i[0x973] = 0; D_001A4BE0_005003D0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x12, 0, 6.0f); func_L01_0050FE88(12, 19); goto finish;
    case 0x57:
        D_001A4BE0_005003D0.i[0x973] = 2; (*(u128_t *)(D_001A4BE0_005003D0.b + 0xf0) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120)); D_001A4BE0_005003D0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x15, 0, 10.0f); goto finish;
    case 0x58:
        D_001A4BE0_005003D0.i[0x973] = 9; qzero(D_001A4BE0_005003D0.b + 0xf0); D_001A4BE0_005003D0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(1, 0, 6.0f); goto finish;
    case 0x53:
        D_001A4BE0_005003D0.i[0x973] = 2; D_001A4BE0_005003D0.u[0xa03] = 0; D_001A4BE0_005003D0.f[0x280] = 0.0088f; D_001A4BE0_005003D0.f[0x281] = 0.0028000001f;
        (*(u128_t *)(D_001A4BE0_005003D0.b + 0xf0) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050FB40(0x15, 0, 6.0f); goto finish;
    case 0x52:
        D_001A4BE0_005003D0.i[0x973] = 1; D_001A4BE0_005003D0.u[0xa03] = 0;
        D_001A4BE0_005003D0.f[0x6d] = func_0038CED8((D_001A4BE0_005003D0.b + 0x120));
        if (D_001A4BE0_005003D0.f[0x6d] > 0.10000001f) D_001A4BE0_005003D0.f[0x6d] = 0.10000001f;
        D_001A4BE0_005003D0.b[0x3ec] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(5, 0, 7.0f); goto finish;
    case 0x56:
        D_001A4BE0_005003D0.i[0x973] = 20; (*(u128_t *)(D_001A4BE0_005003D0.b + 0x160) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120)); D_001A4BE0_005003D0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x14, 0, 10.0f); goto finish;
    case 0x55:
        D_001A4BE0_005003D0.i[0x973] = 7; D_001A4BE0_005003D0.u[0xa03] = 0;
        func_L01_004F1190(0.5f);
        (*(u128_t *)(D_001A4BE0_005003D0.b + 0xf0) = *(u128_t *)(D_001A4BE0_005003D0.b + 0x120)); func_003C4BB0((f32 *)(D_001A4BE0_005003D0.b + 0xf0), 0.10000001f);
        hit_29 = func_L01_00447490(D_001A4BE0_005003D0.ptr[0x970], 1, 0);
        if (hit_29) func_L01_004DFEA0((s32)(*(f32 *)(hit_29 + 0x2C)));
        else func_L01_004DFEA0(1);
        D_001A4BE0_005003D0.uh[0xee] = 64;
        if (!animate) goto finish;
        func_L01_0050FB40(0x13, 3, -3.0f);
        *(f32 *)(D_001A4BE0_005003D0.ptr[0x970] + 0x44) = D_L01_002F6460[D_001A4BE0_005003D0.i[0x304]][D_001A4BE0_005003D0.i[0x305]++];
        goto finish;
    case 0x3e:
        D_001A4BE0_005003D0.i[0x973] = 15; D_001A4BE0_005003D0.u[0xa03] = 0;
        if (!D_001A4BE0_005003D0.i[0x178]) {
            if (D_001A4BE0_005003D0.ptr[0x199]) { func_L01_004DFEA0((s32)(*(f32 *)(D_001A4BE0_005003D0.ptr[0x199] + 0x2C))); D_001A4BE0_005003D0.ptr[0x199] = 0; }
            else func_L01_004DFEA0(1);
        }
        func_L01_004F4E70(20, 0);
        if (D_001A4BE0_005003D0.i[0xa14] < 1) {
            angle_53 = func_0038DAB8(func_0038D160(D_001A4BE0_005003D0.f[0x3c], D_001A4BE0_005003D0.f[0x3d]), 3.1415927f);
            angle_53 = func_0038DAB8(angle_53, func_L01_00443A18(0.5235988f, 0.61086524f));
            D_001A4BE0_005003D0.f[0x48] = func_0038D098(angle_53) * (D_001A4BE0_005003D0.f[0x179] * 0.7f);
            D_001A4BE0_005003D0.f[0x49] = func_0038D0B0(angle_53) * (D_001A4BE0_005003D0.f[0x179] * 0.7f); D_001A4BE0_005003D0.f[0x4a] = 0.09f;
            if (D_001A4BE0_005003D0.i[0x178] > 12 && D_001A4BE0_005003D0.i[0xa14] < 2) D_001A4BE0_005003D0.i[0xa14] = 2;
            D_001A4BE0_005003D0.ptr[0x970][0xA8] = 255; func_L01_005003D0(0x16, 1); D_001A4BE0_005003D0.uh[0xfa] = 0x7d; D_001A4BE0_005003D0.uh[0xe8] = 0x3a;
            return 0;
        }
        D_001A4BE0_005003D0.uh[0xee] = 64; D_001A4BE0_005003D0.f[0x18f] = 0.050000004f;
        if (D_001A4BE0_005003D0.f[0x188] > 0.050000004f) D_001A4BE0_005003D0.f[0x188] = 0.050000004f;
        qzero(D_001A4BE0_005003D0.b + 0xf0); D_001A4BE0_005003D0.u[0x185] = 0; qzero(D_001A4BE0_005003D0.b + 0x110);
        D_001A4BE0_005003D0.f[0x3e] = 0.22000001f; D_001A4BE0_005003D0.f[0x4a] = 0.22000001f;
        if (!animate) goto finish;
        func_L01_0050FB40(0x10, 2, -3.0f); goto finish;
    case 0x1c:
        D_001A4BE0_005003D0.i[0x973] = 9; D_001A4BE0_005003D0.b[0x25ed] = 1; D_001A4BE0_005003D0.u[0xa03] = 0;
        func_L01_0050FB40(func_L01_004DFDB0(0), 0, 8.0f); goto finish;
    case 0x1d:
        D_001A4BE0_005003D0.u[0xa03] = 0x51; D_001A4BE0_005003D0.i[0x973] = 0;
        if (func_L01_004DFE80(D_001A4BE0_005003D0.ptr[0x970][0x42]) == func_L01_004DFDB0(0)) goto finish;
        func_L01_0050FB40(func_L01_004DFDB0(0), 0, 4.0f); goto finish;
    case 0x1e:
        D_001A4BE0_005003D0.i[0x973] = 9; D_001A4BE0_005003D0.u[0xa03] = 0;
        func_L01_0050FB40(func_L01_004DFDB0(0), 0, 8.0f); goto finish;
    case 0x74:
        D_001A4BE0_005003D0.i[0x973] = 9; D_001A4BE0_005003D0.b[0x25ed] = 1; D_001A4BE0_005003D0.u[0xa03] = 0;
        func_L01_004EAA80();
        if (!animate) goto finish;
        func_L01_0050FB40(func_L01_004DFDB0(0), 0, 8.0f); goto finish;
    case 0x31:
        D_001A4BE0_005003D0.i[0x973] = 9; D_001A4BE0_005003D0.u[0xa03] = 0; D_001A4BE0_005003D0.b[0x25e8] = 1;
        D_001A4BE0_005003D0.b[0x25ee] = 1; D_001A4BE0_005003D0.b[0x25ed] = 1; func_L01_0044E740((void *)(D_001A4BE0_005003D0.b + 0x1ce0));
        if (!animate) goto finish;
        func_L01_0050FB40(func_L01_004DFDB0(0), 0, -1.0f); goto finish;
    case 0x7a:
        D_001A4BE0_005003D0.i[0x973] = 9; D_001A4BE0_005003D0.u[0xa03] = 0; D_001A4BE0_005003D0.b[0x25e8] = 1; D_001A4BE0_005003D0.b[0x25ed] = 1; qzero(D_001A4BE0_005003D0.b + 0xf0);
        if (!animate) goto finish;
        func_L01_0050FB40(11, 0, -1.0f); goto finish;
    case 0x37:
        D_001A4BE0_005003D0.i[0x973] = 9; D_001A4BE0_005003D0.b[0x25e8] = 1; D_001A4BE0_005003D0.b[0x25ed] = 1;
        func_L01_0050FB40(0x3f, 2, 7.0f);
        { u8 *a = D_001A4BE0_005003D0.ptr[0x480]; if (func_L01_004EDFA8(a)) func_003C3A10(a, 11, 2, 11); }
        goto finish;
    case 0x64: case 0x65:
        D_001A4BE0_005003D0.i[0x973] = 24; D_001A4BE0_005003D0.b[0x25ed] = 1;
        func_L01_0044E740((void *)(D_001A4BE0_005003D0.b + 0x1ce0)); func_L01_004EAA80();
        if (animate) func_L01_0050FB40(func_L01_004DFDB0(0), 0, -1.0f);
        goto finish;
    default:
        goto finish;
    }
finish:
    if (wasGliding && !D_001A4BE0_005003D0.b[0x25e8]) D_001A4BE0_005003D0.i[0x993] = 1;
    if (wasFlag && !D_001A4BE0_005003D0.b[0x25e7]) D_001A4BE0_005003D0.i[0x993] = 1;
    if (D_001A4BE0_005003D0.i[0x975] == 0x1A && D_001A4BE0_005003D0.i[0x973] != D_001A4BE0_005003D0.i[0x975] && D_001A4BE0_005003D0.i[0x98d]) D_001A4BE0_005003D0.i[0x993] = 1;
    if (D_001A4BE0_005003D0.h[0x1b4] == 0 && D_001A4BE0_005003D0.i[0x49e] == 0xD && D_001A4BE0_005003D0.i[0x98d]) D_001A4BE0_005003D0.i[0x994] = 1;
    if ((u32)(D_001A4BE0_005003D0.i[0x973] - 13) > 2 && (D_001A4BE0_005003D0.i[0x971] != 6 || D_001A4BE0_005003D0.i[0x974] != 0x24) &&
        D_001A4BE0_005003D0.i[0x49e] == 0xE && D_001A4BE0_005003D0.i[0x98d]) D_001A4BE0_005003D0.i[0x994] = 1;
    if (D_001A4BE0_005003D0.i[0x973] == 20) { func_L01_004EAA80(); D_001A4BE0_005003D0.b[0x25ed] = 1; }
    if ((!func_L01_004E9308() || D_001A4BE0_005003D0.i[0x973] == 18) &&
        (D_001A4BE0_005003D0.f[0xd4] < D_L01_001E2A40_005003D0.f8 || D_001A4BE0_005003D0.i[0x973] == 0)) D_L01_001E2A40_005003D0.i450 = 0;
    if (D_001A4BE0_005003D0.i[0x973] != D_001A4BE0_005003D0.i[0x975]) func_L01_004E1560();
    D_001A4BE0_005003D0.i[0x6e] = 0;
    D_001A4BE0_005003D0.u[0x70] = 0;
    if (D_001A4BE0_005003D0.i[0x973] != D_001A4BE0_005003D0.i[0x975]) D_001A4BE0_005003D0.u[0x6f] = 0;
    D_001A4BE0_005003D0.u[0x71] = 0;
    return 1;
}
/* localdecomp:end func_L01_005003D0 */

/* localdecomp:start func_L01_00504E38 */
extern u8 D_001A71C4[];
extern void func_L01_005003D0_00504E38(s32, s32);

void func_L01_00504E38(s32 arg0)
{
    s32 mode;

    mode = 1;
    if (arg0 != 0) {
        mode = 2;
    }
    switch (D_001A71C4[0]) {
    case 0:
        func_L01_005003D0_00504E38(0, mode);
        break;
    case 3:
        func_L01_005003D0_00504E38(81, mode);
        break;
    case 1:
        func_L01_005003D0_00504E38(63, mode);
        break;
    }
}
/* localdecomp:end func_L01_00504E38 */

/* localdecomp:start func_L01_00504EC0 */
extern void func_L01_004EAA80(void);

s32 func_L01_00504EC0(void) {
    u8 *p = ((u8 *)&D_001A4BE0);
    s32 state = *(s32 *)(p + 0x25C4);

    if (state != 2 && state != 3 && state != 0) {
        return 0;
    }
    if (p[0x25E9] == 0) {
        return 0;
    }
    if (*(s32 *)(p + 0x1D8) >= 5) {
        return 0;
    }
    if (*(f32 *)(p + 0x2838) < 0.7f) {
        if (p[0x25EC] != 0) {
            return 0;
        }
        func_L01_004EAA80();
        *(s32 *)(p + 0xE84) = 2;
        func_L01_005003D0_00504E38(0x22, 1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00504EC0 */

/* localdecomp:start func_L01_00504F70 */
extern Veldin1A4BE0 D_001A4BE0;
extern s32 D_L01_001E2E90[];
extern void func_L01_005003D0_00504E38(s32 a0, s32 a1);

s32 func_L01_00504F70(void) {
    u8 *p = ((u8 *)&D_001A4BE0);
    if (*(s32 *)(p + 9676) != 17) {
        return 0;
    }
    if (!(*(f32 *)(p + 848) + 0.4f < *(f32 *)(p + 136))) {
        return 0;
    }
    D_L01_001E2E90[0] = 0;
    func_L01_005003D0_00504E38(6, 1);
    return 1;
}
/* localdecomp:end func_L01_00504F70 */

/* localdecomp:start func_L01_00504FE0 */
typedef struct {
    u8 pad0[0x88];
    f32 feet;              /* 0x88: pos.z, the height of his feet */
    u8 pad8C[0xF8 - 0x8C];
    f32 intended_vel_z;    /* 0xF8 */
    u8 padFC[0x118 - 0xFC];
    f32 vel_z;             /* 0x118 */
    u8 pad11C[0x23C - 0x11C];
    s32 drown_counter;     /* 0x23C */
    u8 pad240[0x350 - 0x240];
    f32 surface;           /* 0x350: the water's surface under him */
    u8 pad354[0x46E - 0x354];
    u8 past_apex;          /* 0x46E: the jump is on its way down */
    u8 pad46F[0x1476 - 0x46F];
    u8 water;              /* 0x1476: water under him */
    u8 pad1477[0x25C0 - 0x1477];
    s32 hero_moby;         /* 0x25C0 */
    s32 state;             /* 0x25C4 */
    s32 substate;          /* 0x25C8 */
    s32 state_type;        /* 0x25CC */
    u8 pad25D0[0x2848 - 0x25D0];
    f32 depth;             /* 0x2848: the surface less the floor */
    u8 pad284C[0x2850 - 0x284C];
    s32 health;            /* 0x2850 */
} H_504FE0;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} V_504FE0;
extern s32 D_L01_001DFB40; /* the frame counter */
extern f32 D_L01_001EAA20[]; /* the last probe's hit point */
extern void func_L01_004EF6F0(V_504FE0 *from, V_504FE0 *to, s32 a2, f32 length, f32 height);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern s32 func_003D5630(void);
extern s32 func_L01_004F4E70(s32 a0, s32 a1);
extern s32 func_L01_005003D0(s32, s32);

/* from rac2-decomp's func_L00_002C8E10 */
/* hero_enter_water: puts a hero in water into surface idle (54), or surfaces one rising under
   it; every 16 frames, a hero over ground he can't stand on under the water sinks (51). */
s32 func_L01_00504FE0(void) {
    s32 gets_in;
    f32 slack;
    V_504FE0 from;
    V_504FE0 to;
    f32 length;

    if ((*(H_504FE0 *)&D_001A4BE0).state == 121 || (*(H_504FE0 *)&D_001A4BE0).state == 108) {
        return 0;
    }
    gets_in = 0;
    if ((*(H_504FE0 *)&D_001A4BE0).water != 0) {
        if ((*(H_504FE0 *)&D_001A4BE0).state_type == 17) {
            /* under water: surfaces rising within 0.4 u of the top */
            if ((*(H_504FE0 *)&D_001A4BE0).substate != 1 && (*(H_504FE0 *)&D_001A4BE0).vel_z > 0.0f &&
                (*(H_504FE0 *)&D_001A4BE0).surface - 0.4f < (*(H_504FE0 *)&D_001A4BE0).feet) {
                gets_in = 1;
            }
        } else if ((*(H_504FE0 *)&D_001A4BE0).state_type != 18 && (*(H_504FE0 *)&D_001A4BE0).state_type != 3) {
            /* 0.2 u of slack, or this frame's fall and 0.07 u */
            slack = 0.2f;
            if (slack < __builtin_fabsf((*(H_504FE0 *)&D_001A4BE0).intended_vel_z) + 0.07f) {
                slack = __builtin_fabsf((*(H_504FE0 *)&D_001A4BE0).intended_vel_z) + 0.07f;
            }
            /* falling with his feet about 0.45 u under in water over 0.8 u deep */
            if (__builtin_fabsf((*(H_504FE0 *)&D_001A4BE0).surface - ((*(H_504FE0 *)&D_001A4BE0).feet + 0.45f)) < slack &&
                ((*(H_504FE0 *)&D_001A4BE0).state_type != 4 || (*(H_504FE0 *)&D_001A4BE0).past_apex != 0) &&
                (*(H_504FE0 *)&D_001A4BE0).depth > 0.8f && (*(H_504FE0 *)&D_001A4BE0).vel_z < 0.0f) {
                gets_in = 1;
            }
            /* or more than 0.8 u under */
            if ((*(H_504FE0 *)&D_001A4BE0).feet < (*(H_504FE0 *)&D_001A4BE0).surface - 0.8f &&
                ((*(H_504FE0 *)&D_001A4BE0).state_type != 4 || (*(H_504FE0 *)&D_001A4BE0).past_apex != 0)) {
                gets_in = 1;
            }
        }
    }
    /* a clamp whose result nothing reads (rac2's func_L00_002C8E10 has it too, with a call) */
    slack = 0.27f;
    if (slack < __builtin_fabsf((*(H_504FE0 *)&D_001A4BE0).intended_vel_z) + 0.07f) {
        slack = __builtin_fabsf((*(H_504FE0 *)&D_001A4BE0).intended_vel_z) + 0.07f;
    }
    /* a water jump back down, 0.7 u under */
    if ((*(H_504FE0 *)&D_001A4BE0).state == 18 && (*(H_504FE0 *)&D_001A4BE0).past_apex != 0 &&
        (*(H_504FE0 *)&D_001A4BE0).feet < (*(H_504FE0 *)&D_001A4BE0).surface - 0.7f) {
        gets_in = 1;
    }
    if ((*(H_504FE0 *)&D_001A4BE0).state_type != 17 && (*(H_504FE0 *)&D_001A4BE0).state_type != 18 &&
        (*(H_504FE0 *)&D_001A4BE0).state_type != 7 && (*(H_504FE0 *)&D_001A4BE0).state != 18 &&
        (D_L01_001DFB40 & 0xF) == 0) {
        length = 4.0f;
        if (D_L01_001DFB40 % 63 == 0) {
            length = 16.0f;
        }
        func_L01_004EF6F0(&from, &to, 0, length, 1.3f);
        if (func_003D3CB0(&from, &to, 2, (*(H_504FE0 *)&D_001A4BE0).hero_moby, 0) != 0 && func_003D5630() == 0) {
            from.z = D_L01_001EAA20[2] - 0.01f;
            if (func_003D3CB0(&from, &to, 2, (*(H_504FE0 *)&D_001A4BE0).hero_moby, 0) == 0) {
                if ((*(H_504FE0 *)&D_001A4BE0).state_type == 20 || (*(H_504FE0 *)&D_001A4BE0).health == 0) {
                    func_L01_005003D0_00504E38(108, 1);
                } else {
                    func_L01_005003D0_00504E38(51, 1);
                }
                return 1;
            }
        }
    }
    if (gets_in != 0) {
        if ((*(H_504FE0 *)&D_001A4BE0).state_type == 20 || (*(H_504FE0 *)&D_001A4BE0).health == 0) {
            if (((s32 (*)(s32, s32))func_L01_005003D0)(108, 3) != 0) {
                (*(H_504FE0 *)&D_001A4BE0).drown_counter = 58;
            }
        } else {
            func_L01_005003D0_00504E38(54, 1);
        }
        func_L01_004F4E70(3, 0);
    }
    return gets_in;
}
/* localdecomp:end func_L01_00504FE0 */

/* localdecomp:start func_L01_00505380 */
/* The bob's fabs is the game's fabs_asm (include/vu0.h). */
#include "vu0.h"
typedef struct {
    u8 pad0[0x88];
    f32 pos_z;
    u8 pad8C[0x1B8 - 0x8C];
    s32 state_timer;
    u8 pad1BC[0x350 - 0x1BC];
    f32 water_height;
    u8 pad354[0x720 - 0x354];
    f32 bob;
    f32 bob_rate;
    u8 pad728[0x72C - 0x728];
    f32 float_height;
    f32 float_rate;
    u8 pad734[0x9BC - 0x734];
    f32 bob_spring_rate;
    u8 pad9C0[0x25C4 - 0x9C0];
    s32 state;
    u8 pad25C8[0x25D4 - 0x25C8];
    s32 prev_state_type;
    u8 pad25D8[0x25E0 - 0x25D8];
    s32 prev_state_type_b;
    u8 critter_mode;
} H_505380;
extern f32 func_003C4138(f32 *value, f32 target, f32 step);

/* hero_surface_float: sets the hero's height on the surface: a tracked surface height
   (spring 0.0389, 0.432) less 0.12, plus a bobbing offset with its own rate. */
void func_L01_00505380(void) {
    if ((*(H_505380 *)&D_001A4BE0).state_timer > 8 || (*(H_505380 *)&D_001A4BE0).bob < 0.0f ||
        (*(H_505380 *)&D_001A4BE0).prev_state_type == 17 || (*(H_505380 *)&D_001A4BE0).prev_state_type_b == 17) {
        if ((*(H_505380 *)&D_001A4BE0).state == 53) {
            /* the surface swim springs the bob to 0 */
            func_L01_004482A0(&(*(H_505380 *)&D_001A4BE0).bob, 0.0f, &(*(H_505380 *)&D_001A4BE0).bob_spring_rate,
                              0.0432000011f, 0.432000041f, 0.0300000012f);
            (*(H_505380 *)&D_001A4BE0).bob_rate = 0.0f;
        } else {
            /* a damped spring: stiffness 0.0072, damping 0.054 */
            f32 rate = (*(H_505380 *)&D_001A4BE0).bob_rate;
            f32 bob = (*(H_505380 *)&D_001A4BE0).bob;
            rate -= bob * 0.00720000034f + rate * 0.0540000051f;
            (*(H_505380 *)&D_001A4BE0).bob_rate = rate;
            if (fabs_asm(bob) < 0.00100000005f && rate < 9.99999975e-05f) {
                (*(H_505380 *)&D_001A4BE0).bob_rate = 0.0f;
            }
        }
    }
    (*(H_505380 *)&D_001A4BE0).bob += (*(H_505380 *)&D_001A4BE0).bob_rate;
    if ((*(H_505380 *)&D_001A4BE0).state == 53 && (*(H_505380 *)&D_001A4BE0).bob > 0.0f) {
        if ((*(H_505380 *)&D_001A4BE0).bob_rate > 0.0f) {
            (*(H_505380 *)&D_001A4BE0).bob_rate = 0.0f;
        }
        func_003C4138(&(*(H_505380 *)&D_001A4BE0).bob, 0.0f, 0.0140000004f); /* sinks 0.014 a tick */
    }
    if ((*(H_505380 *)&D_001A4BE0).state != 0x81 && (*(H_505380 *)&D_001A4BE0).state != 0x50) {
        func_L01_004482A0(&(*(H_505380 *)&D_001A4BE0).float_height, (*(H_505380 *)&D_001A4BE0).water_height,
                          &(*(H_505380 *)&D_001A4BE0).float_rate, 0.0388800018f, 0.432000041f, 0.0f);
    }
    /* the feet rest 0.12 u under the surface (0.05 as Clank) */
    if ((*(H_505380 *)&D_001A4BE0).critter_mode == 0) {
        (*(H_505380 *)&D_001A4BE0).pos_z = (*(H_505380 *)&D_001A4BE0).float_height + -0.119999997f + (*(H_505380 *)&D_001A4BE0).bob;
    } else {
        (*(H_505380 *)&D_001A4BE0).pos_z = (*(H_505380 *)&D_001A4BE0).float_height + -0.0500000007f + (*(H_505380 *)&D_001A4BE0).bob;
    }
}
/* localdecomp:end func_L01_00505380 */

/* localdecomp:start func_L01_005055A0 */
/* Hero button checks for the aquatos levels (08, 27). D_001D4C40 is a two-word pair: [1] is read through the
 * symbol+4 macro load (lui form). The D_001A4BE0_005055A0.234 test's empty-looking else (k = 0, dead) is what keeps cse's path from
 * running past it into the switch, so the hero base is rebuilt before `old` as in retail. */
extern char D_001A4BE0_005055A0[];
extern u8 *D_001D52FC_005055A0;
extern s32 D_001D4C40[2];
extern s32 D_L01_001DBCFC;
__asm__(".extern D_L01_001DBCFC, 4");
extern u8 D_00142CBD[];
extern u8 D_001439F4[];
extern u8 D_L01_002F62D0_005055A0[];

s32 func_003A3BB8(s32 a0, s32 a1);
s32 func_L01_004EDFA8(u8 *object);
void func_L01_004F5810(void);
void func_L01_004F5AE8(void);
s32 func_L01_004EC598(void);


extern void func_L01_004EA7D8(s32);

s32 func_L01_005055A0(void) {
    s32 sp0;
    s32 sp4;
    s32 st;
    s32 mask;
    s32 old;
    u8 *o;
    u8 *e;
    u8 *e2;
    s32 n2;
    s32 c2;
    s32 n;
    s32 b;
    s32 c;
    s32 z;
    s32 z2;
    s32 k;
    f32 lim;

    if ((((struct { u8 pad[0x25ED]; u8 v; } *)(D_001A4BE0_005055A0))->v) != 0) {
        if ((((struct { u8 pad[0x1228]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 9) {
            return 0;
        }
        if ((((struct { u8 pad[0x368]; s16 v; } *)(D_001A4BE0_005055A0))->v) != 1) {
            return 0;
        }
    }
    if ((((struct { u8 pad[0x25E4]; u8 v; } *)(D_001A4BE0_005055A0))->v) != 0) {
        return 0;
    }
    if ((((struct { u8 pad[0x1200]; u8 * v; } *)(D_001A4BE0_005055A0))->v) == 0) {
        return 0;
    }
    if ((((struct { u8 pad[0x121A]; u8 v; } *)(D_001A4BE0_005055A0))->v) != 0) {
        return 0;
    }
    if ((((struct { u8 pad[0x1224]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 2) {
        return 0;
    }
    st = (((struct { u8 pad[0x1228]; s32 v; } *)(D_001A4BE0_005055A0))->v);
    mask = (((struct { u8 pad[0x1210]; s32 v; } *)(D_001A4BE0_005055A0))->v);
    if (D_001439F4[0] != 0 && (mask & 0x20)) {
        mask |= 8;
    }
    if ((((struct { u8 pad[0x234]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 0) {
        if (mask & 0x80) {
            mask |= 0x20;
        }
    } else {
        k = 0;
    }
    old = (((struct { u8 pad[0x1B8]; s32 v; } *)(D_001A4BE0_005055A0))->v);
    switch (st) {
    case 9:
        if ((((struct { u8 pad[0x147C]; u8 v; } *)(D_001A4BE0_005055A0))->v) != 0) {
            break;
        }
        if ((((struct { u8 pad[0x1E0]; s16 v; } *)(D_001A4BE0_005055A0))->v) != 0) {
            break;
        }
        if ((u32)(((struct { u8 pad[0x25CC]; s32 v; } *)(D_001A4BE0_005055A0))->v) < 2 || ((((struct { u8 pad[0x25CC]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 4 && (((struct { u8 pad[0x46C]; u8 v; } *)(D_001A4BE0_005055A0))->v) != 0)) {
            if (func_L01_004606E8(mask, 8, (s32)&sp0, 0) == 0) {
                break;
            }
            o = (((struct { u8 pad[0x1200]; u8 * v; } *)(D_001A4BE0_005055A0))->v);
            if (o == 0) {
                break;
            }
            if (func_L01_004EDFA8(o) == 0) {
                break;
            }
            if (o[0x20] != 0) {
                break;
            }
            if ((b = (((struct { u8 pad[0x1A0]; s32 v; } *)(D_001D52FC_005055A0))->v), (((struct { u8 pad[0x16B0]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0 ? b & func_003A3BB8(8, 0) : b & 0xA) == 0) {
                if (((((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 1 && (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 0x1D) || (((struct { u8 pad[0x1B8]; s32 v; } *)(D_001A4BE0_005055A0))->v) < 0x12) {
                    func_L01_005003D0(0x13, 1);
                    break;
                }
            }
            if (((((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 1 && (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 0x1D) || (((struct { u8 pad[0x1B8]; s32 v; } *)(D_001A4BE0_005055A0))->v) < 0x12) {
                func_L01_005003D0(0x15, 1);
                break;
            }
            func_L01_004F5810();
            break;
        }
        if (((((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 7 || (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 9 || (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0xF || (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0xA
             || (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0xD || (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 8 || (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 6
             || ((((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0xE && 32.0f < (((struct { u8 pad[0xC18]; f32 v; } *)(D_001A4BE0_005055A0))->v))
             || ((((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0xB && (((((struct { u8 pad[0x4A4]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 3 && 18.0f < (((struct { u8 pad[0xC18]; f32 v; } *)(D_001A4BE0_005055A0))->v))
                                             || (*(s32 *)(D_001A4BE0_005055A0 + 0x4A4) == 3 && 20.0f < (((struct { u8 pad[0xC18]; f32 v; } *)(D_001A4BE0_005055A0))->v))))
             || (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0x2C || (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0x11)
            && (((struct { u8 pad[0x1B8]; s32 v; } *)(D_001A4BE0_005055A0))->v) >= 9) {
            k = 0xC;
            if ((((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0xB || (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0xE) {
                k = 0xF;
            }
            if (func_L01_004606E8(mask, k, 0, 0) == 0) {
                break;
            }
            if (((((struct { u8 pad[0x46E]; u8 v; } *)(D_001A4BE0_005055A0))->v) == 0 ? 0.1f < (((struct { u8 pad[0x33C]; f32 v; } *)(D_001A4BE0_005055A0))->v) : 0.57f < (((struct { u8 pad[0x33C]; f32 v; } *)(D_001A4BE0_005055A0))->v))
                || ((((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 8 && 0.57f < (((struct { u8 pad[0x33C]; f32 v; } *)(D_001A4BE0_005055A0))->v))) {
                if ((((struct { u8 pad[0x69C]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0) {
                    func_L01_005003D0(0x14, 1);
                }
            } else {
                func_L01_005003D0(0x13, 1);
            }
            break;
        }
        if ((((struct { u8 pad[0x25CC]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 6) {
            break;
        }
        e = D_L01_002F62D0_005055A0 + (((struct { u8 pad[0xBDC]; s16 v; } *)(D_001A4BE0_005055A0))->v) * 0x2C;
        if ((((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0x15 && (((struct { u8 pad[0x1B8]; s32 v; } *)(D_001A4BE0_005055A0))->v) >= 0x1A && (((struct { u8 pad[0x121A]; u8 v; } *)(D_001A4BE0_005055A0))->v) == 0) {
            if ((((struct { u8 pad[0xC0C]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 0) {
                break;
            }
            if ((f32)(((struct { u8 pad[0x10]; s32 v; } *)(e))->v) <= (((struct { u8 pad[0xC18]; f32 v; } *)(D_001A4BE0_005055A0))->v)
                && (b = (((struct { u8 pad[0x1A0]; s32 v; } *)(D_001D52FC_005055A0))->v), (((struct { u8 pad[0x16B0]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0 ? b & func_003A3BB8(8, 0) : b & 0xA)
                && func_L01_004606E8(mask, 0xC, 0, 0) != 0) {
                func_L01_005003D0(0x15, 1);
                break;
            }
        }
        if ((((struct { u8 pad[0xC0C]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 0) {
            break;
        }
        if ((z = (((struct { u8 pad[0x121A]; u8 v; } *)(D_001A4BE0_005055A0))->v)) != 0) {
            break;
        }
        if (!((f32)(((struct { u8 pad[0x10]; s32 v; } *)(e))->v) <= (((struct { u8 pad[0xC18]; f32 v; } *)(D_001A4BE0_005055A0))->v))) {
            break;
        }
        n = ((s32)(((struct { u8 pad[0xC18]; f32 v; } *)(D_001A4BE0_005055A0))->v) - (((struct { u8 pad[0xC]; s32 v; } *)(e))->v)) * 2;
        c = 1;
        if (n > z) {
            c = n;
        }
        if (c > 12) {
            c = 12;
        }
        if (func_L01_004606E8(mask, c, 0, 0) == 0) {
            break;
        }
        func_L01_005003D0((b = (((struct { u8 pad[0x1A0]; s32 v; } *)(D_001D52FC_005055A0))->v), (((struct { u8 pad[0x16B0]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0 ? b & func_003A3BB8(8, 0) : b & 0xA) ? 0x15 : 0x13, 1);
        break;
    case 0x7F:
        if ((((struct { u8 pad[0x147C]; u8 v; } *)(D_001A4BE0_005055A0))->v) != 0) {
            break;
        }
        if ((u32)(((struct { u8 pad[0x25CC]; s32 v; } *)(D_001A4BE0_005055A0))->v) < 2 || ((((struct { u8 pad[0x25CC]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 4 && (((struct { u8 pad[0x46C]; u8 v; } *)(D_001A4BE0_005055A0))->v) != 0)) {
            if (func_L01_004606E8(mask, 8, (s32)&sp4, 0) == 0) {
                break;
            }
            o = (((struct { u8 pad[0x1200]; u8 * v; } *)(D_001A4BE0_005055A0))->v);
            if (o == 0) {
                break;
            }
            if (func_L01_004EDFA8(o) == 0) {
                break;
            }
            if (o[0x20] != 0) {
                break;
            }
            if (((((struct { u8 pad[0x1A0]; s32 v; } *)(D_001D52FC_005055A0))->v) & func_003A3BB8(8, 0)) == 0) {
                if (((((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 1 && (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 0x1D) || (((struct { u8 pad[0x1B8]; s32 v; } *)(D_001A4BE0_005055A0))->v) < 0x12) {
                    func_L01_005003D0(0x13, 1);
                    break;
                }
            }
            if (((((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 1 && (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 0x1D) || (((struct { u8 pad[0x1B8]; s32 v; } *)(D_001A4BE0_005055A0))->v) < 0x12) {
                func_L01_005003D0(0x15, 1);
                break;
            }
            func_L01_004F5AE8();
            break;
        }
        if (((((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 7 || (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 9 || (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 8 || (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 6
             || ((((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0xE && 32.0f < (((struct { u8 pad[0xC18]; f32 v; } *)(D_001A4BE0_005055A0))->v))
             || ((((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0xB && (((((struct { u8 pad[0x4A4]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 3 && 18.0f < (((struct { u8 pad[0xC18]; f32 v; } *)(D_001A4BE0_005055A0))->v))
                                             || (*(s32 *)(D_001A4BE0_005055A0 + 0x4A4) == 3 && 20.0f < (((struct { u8 pad[0xC18]; f32 v; } *)(D_001A4BE0_005055A0))->v))))
             || (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0x2C || (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0x11)
            && (((struct { u8 pad[0x1B8]; s32 v; } *)(D_001A4BE0_005055A0))->v) >= 9) {
            k = 0xC;
            if ((((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0xB || (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0xE) {
                k = 0xF;
            }
            if (func_L01_004606E8(mask, k, 0, 0) == 0) {
                break;
            }
            if (((((struct { u8 pad[0x46E]; u8 v; } *)(D_001A4BE0_005055A0))->v) == 0 ? 0.1f < (((struct { u8 pad[0x33C]; f32 v; } *)(D_001A4BE0_005055A0))->v) : 0.57f < (((struct { u8 pad[0x33C]; f32 v; } *)(D_001A4BE0_005055A0))->v))
                || ((((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 8 && 0.57f < (((struct { u8 pad[0x33C]; f32 v; } *)(D_001A4BE0_005055A0))->v))) {
                if ((((struct { u8 pad[0x69C]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0) {
                    func_L01_005003D0(0x14, 1);
                }
            } else {
                func_L01_005003D0(0x13, 1);
            }
            break;
        }
        if ((((struct { u8 pad[0x25CC]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 6) {
            break;
        }
        e2 = D_L01_002F62D0_005055A0 + (((struct { u8 pad[0xBDC]; s16 v; } *)(D_001A4BE0_005055A0))->v) * 0x2C;
        if ((((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0x15 && (((struct { u8 pad[0x1B8]; s32 v; } *)(D_001A4BE0_005055A0))->v) >= 0x1A && (((struct { u8 pad[0x121A]; u8 v; } *)(D_001A4BE0_005055A0))->v) == 0) {
            if ((((struct { u8 pad[0xC0C]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 0) {
                break;
            }
            if ((f32)(((struct { u8 pad[0x10]; s32 v; } *)(e2))->v) <= (((struct { u8 pad[0xC18]; f32 v; } *)(D_001A4BE0_005055A0))->v)
                && ((((struct { u8 pad[0x1A0]; s32 v; } *)(D_001D52FC_005055A0))->v) & func_003A3BB8(8, 0))
                && func_L01_004606E8(mask, 0xC, 0, 0) != 0) {
                func_L01_005003D0(0x15, 1);
                break;
            }
        }
        if ((((struct { u8 pad[0xC0C]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 0) {
            break;
        }
        if ((z2 = (((struct { u8 pad[0x121A]; u8 v; } *)(D_001A4BE0_005055A0))->v)) != 0) {
            break;
        }
        if (!((f32)(((struct { u8 pad[0x10]; s32 v; } *)(e2))->v) <= (((struct { u8 pad[0xC18]; f32 v; } *)(D_001A4BE0_005055A0))->v))) {
            break;
        }
        n2 = ((s32)(((struct { u8 pad[0xC18]; f32 v; } *)(D_001A4BE0_005055A0))->v) - (((struct { u8 pad[0xC]; s32 v; } *)(e2))->v)) * 2;
        c2 = 1;
        if (n2 > z2) {
            c2 = n2;
        }
        if (c2 > 12) {
            c2 = 12;
        }
        if (func_L01_004606E8(mask, c2, 0, 0) == 0) {
            break;
        }
        if ((((struct { u8 pad[0x1A0]; s32 v; } *)(D_001D52FC_005055A0))->v) & func_003A3BB8(8, 0)) {
            func_L01_005003D0(0x15, 1);
        } else {
            func_L01_005003D0(0x13, 1);
        }
        break;
    case 0xB: {
        s32 cc;
        s32 btn;
        if (mask != 0) {
            btn = 0xE;
        } else {
            btn = 0xE;
        }
        if ((((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0x27 && ((((struct { u8 pad[0xA5E]; s16 v; } *)(D_001A4BE0_005055A0))->v) != 0 || (((struct { u8 pad[0xA28]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 0)) {
            if (func_L01_004606E8(mask, btn, 0, 0) != 0 || (((((struct { u8 pad[0x1A0]; s32 v; } *)(D_001D52FC_005055A0))->v) & mask) && (((struct { u8 pad[0x1220]; s32 v; } *)(D_001A4BE0_005055A0))->v) >= 0xD)) {
                func_L01_005003D0(0x28, 1);
                break;
            }
        }
        cc = (((struct { u8 pad[0x25CC]; s32 v; } *)(D_001A4BE0_005055A0))->v);
        if ((u32)cc < 2 || cc == 0xC || cc == 4 || cc == 2 || cc == 0x1E || cc == 5
            || ((((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0x28 && (((struct { u8 pad[0x1B8]; s32 v; } *)(D_001A4BE0_005055A0))->v) >= 5) || (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0x1D) {
            if (func_L01_004606E8(mask, btn, 0, 0) == 0 && (((((struct { u8 pad[0x1A4]; s32 v; } *)(D_001D52FC_005055A0))->v) & mask) == 0 || (((struct { u8 pad[0x1220]; s32 v; } *)(D_001A4BE0_005055A0))->v) < 0xD)) {
                break;
            }
            if ((((struct { u8 pad[0xA5E]; s16 v; } *)(D_001A4BE0_005055A0))->v) != 0) {
                if ((((struct { u8 pad[0xA28]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 0) {
                    if ((((struct { u8 pad[0xA58]; f32 v; } *)(D_001A4BE0_005055A0))->v) < (((struct { u8 pad[0xA44]; f32 v; } *)(D_001A4BE0_005055A0))->v)) {
                        (((struct { u8 pad[0xA28]; s32 v; } *)(D_001A4BE0_005055A0))->v) = 0;
                    } else {
                        (((struct { u8 pad[0xA5E]; s16 v; } *)(D_001A4BE0_005055A0))->v) = 0;
                    }
                }
                if ((((struct { u8 pad[0xA5E]; s16 v; } *)(D_001A4BE0_005055A0))->v) != 0 && (((struct { u8 pad[0x206]; s16 v; } *)(D_001A4BE0_005055A0))->v) == 0 && (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 0x2B) {
                    func_L01_005003D0(0x2B, 1);
                    break;
                }
            }
            if ((((struct { u8 pad[0xA28]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 0 && (((struct { u8 pad[0x206]; s16 v; } *)(D_001A4BE0_005055A0))->v) == 0) {
                func_L01_005003D0(0x23, 1);
                break;
            }
            if ((((struct { u8 pad[0xA94]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 0) {
                func_L01_005003D0(0x8F, 1);
                break;
            }
            if ((((struct { u8 pad[0xAC4]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 0) {
                (((struct { u8 pad[0xACC]; s32 v; } *)(D_001A4BE0_005055A0))->v) = 1;
                func_L01_004EA7D8(0x12);
            }
        }
        break;
    }
    case 0x1E:
        if ((((struct { u8 pad[0x25E4]; u8 v; } *)(D_001A4BE0_005055A0))->v) != 0) {
            break;
        }
        if (func_L01_004EC598() == 0) {
            break;
        }
        if (func_L01_004606E8(mask, 6, 0, 0) == 0) {
            break;
        }
        if (D_001D4C40[0] != 0x1E) {
            break;
        }
        if ((((struct { u8 pad[0xAA]; s16 v; } *)((((struct { u8 pad[0x1200]; u8 * v; } *)(D_001A4BE0_005055A0))->v)))->v) != 0x1D7E) {
            break;
        }
        if ((((struct { u8 pad[0x288C]; s16 v; } *)(D_001A4BE0_005055A0))->v) != 0) {
            break;
        }
        (((struct { u8 pad[0x2888]; s16 v; } *)(D_001A4BE0_005055A0))->v) = 1;
        (((struct { u8 pad[0x288C]; s16 v; } *)(D_001A4BE0_005055A0))->v) = 0x12;
        (((struct { u8 pad[0x288A]; s16 v; } *)(D_001A4BE0_005055A0))->v) = 1;
        break;
    }
    if ((((struct { u8 pad[0x1B8]; s32 v; } *)(D_001A4BE0_005055A0))->v) == old && D_00142CBD[0] != 0 && D_001D4C40[1] == 0x1D
        && (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 0x1D && (((struct { u8 pad[0x25C4]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 1
        && ((((struct { u8 pad[0x210]; unsigned long v; } *)(D_001A4BE0_005055A0))->v) & 0xFFFFFFFF00000000UL) == 0) {
        func_0038CAD0(&D_L01_001DBCFC);
        if (D_L01_001DBCFC != 0) {
            if ((u32)(((struct { u8 pad[0x25CC]; s32 v; } *)(D_001A4BE0_005055A0))->v) < 2 || (((struct { u8 pad[0x25CC]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 0xC
                || (((((struct { u8 pad[0x25CC]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 2 || (((struct { u8 pad[0x25CC]; s32 v; } *)(D_001A4BE0_005055A0))->v) == 4) && (((struct { u8 pad[0x360]; s32 v; } *)(D_001A4BE0_005055A0))->v) != 0)) {
                if (((((struct { u8 pad[0x1A0]; s32 v; } *)(D_001D52FC_005055A0))->v) & func_003A3BB8(8, 0)) && ((((struct { u8 pad[0x1A4]; s32 v; } *)(D_001D52FC_005055A0))->v) & func_003A3BB8(8, 0))) {
                    func_L01_005003D0(0x80, 1);
                }
            }
        }
        if ((((struct { u8 pad[0x1A4]; s32 v; } *)(D_001D52FC_005055A0))->v) & func_003A3BB8(8, 0)) {
            D_L01_001DBCFC = 0xC;
        }
    }
    return (((struct { u8 pad[0x1B8]; s32 v; } *)(D_001A4BE0_005055A0))->v) < old;
}
/* localdecomp:end func_L01_005055A0 */

/* localdecomp:start func_L01_00506298 */
extern Veldin1A4BE0 D_001A4BE0;
extern s32 func_L01_004606E8(s32, s32, s32, s32);


extern s32 func_003A3BB8(s32, s32);
extern s32 func_L01_004FF5D8(void);
extern s32 func_L01_00460778(s32, s32, s32, s32, s32);
extern s32 func_L01_004FF610(void);
extern void func_L01_005003D0_00504E38(s32, s32);
extern S_00502368 *D_001D52FC;

s32 func_L01_00506298(s32 a, s32 b) {
    u8 buf[16];
    s32 n;
    if (((s32 (*)(s32, s32, void *, s32))func_L01_004606E8)(func_003A3BB8(64, 0), a, buf, 0) == 0) {
        return 0;
    }
    n = func_L01_004FF5D8();
    if ((D_001D52FC->w1A0 & func_003A3BB8(8, 0)) && n > 0
        && func_L01_00460778(func_003A3BB8(64, 0), 0x1F000, a + n, n, 0) != 0) {
        func_L01_005003D0_00504E38(11, 1);
        return 1;
    }
    if (((*(G_00502368 *)&D_001A4BE0).h1434 != 0 || ((*(G_00502368 *)&D_001A4BE0).w16B0 == 1 && ((s32 (*)(s32, s32, void *, s32))func_L01_004606E8)(40, 2, 0, 0) != 0))
        && (*(G_00502368 *)&D_001A4BE0).f2838 > 0.9f && func_L01_004FF610() != 2) {
        func_L01_005003D0_00504E38(11, 1);
        return 1;
    }
    if (b != 0) {
        return 0;
    }
    func_L01_005003D0_00504E38(7, 1);
    return 1;
}
/* localdecomp:end func_L01_00506298 */
