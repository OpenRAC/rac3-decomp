/* func_L08_00313F20: 226 diff with the file's flags (default assembler); 147 with --as ps2as (retail needs @ps2as: gp in delay slots, lui elsewhere for D_001D545C). With ps2as only register allocation differs: retail keeps the constant 1 in $s0 (shared by "1 << D_001D545C" via sllv and q[0x74]=1; ours gives srav/andi unless the AND result goes into a local, which then costs a 6th saved reg), D_142CA0 hi in $s4 and D_1A4C60 hi in $s3 (q2 in $s2 after o dies). D_L08_001DF300 as struct-array pointer gives retail's base reg. */
#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L08_001D6694;
extern f32 D_L08_001E1D40[];
extern s32 D_L08_001DBB3C;
extern u8 D_001D558C;
extern u8 D_001D5579;
extern s32 D_001D545C;
extern s32 D_001D4CF0;
extern u8 D_001BBC40[][16];
extern u8 D_00142CA0[];
extern u8 D_001426E0[];
extern u8 D_001A4C60[];
extern s32 D_001A8240[];
extern s32 D_001A809C[];
extern s32 D_001A84B0[];
extern u16 D_001A7C94;
extern s32 D_L08_001DEDC0;
typedef struct { u8 p0[0x30]; u8 f30[0x40]; u8 p70[0x10]; } S_DF300;
extern S_DF300 *D_L08_001DF300;
extern u8 *D_L08_001DF21C;
extern void func_L01_004B0EE0(void);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_0041A5B0(s32, s32);
extern s32 func_00382380(void *, s32, s32);

void func_L08_00313F20(u8 *o) {
    s32 *v;
    u8 *q;
    u8 *r;

    v = *(s32 **)(o + 0x68);
    if (D_L08_001D6694 == 0 && D_L08_001E1D40[2] > 423.0f) {
        D_L08_001DBB3C = 1;
    }
    if (o[0x20] == 0) {
        if (D_001D558C != 0) {
            if ((D_001BBC40[D_001D545C][v[0x11]] & 0x80) == 0) {
                func_L01_004B0EE0();
                func_L01_004F50C8(D_L08_001DF300[v[0x10]].f30, D_L08_001DF300[v[0x10]].p70, 0, 1);
            }
        }
        o[0x30] = 0xFF;
        o[0x20] = 1;
        if (D_00142CA0[0x21] != 0) {
            q = D_001426E0;
            if (q[0x74] == 0) {
                if ((D_001A8240[0] & (1 << D_001D545C)) == 0) {
                    func_L01_0041A5B0(0xC94, 0x58);
                }
                q[0x74] = 1;
            }
        }
        if (D_001D558C != 0) {
            *(u128_t *)(D_L08_001DF21C + (v[0x12] << 8) + 0x10) = *(u128_t *)D_L08_001DF300[v[0x13]].f30;
        }
        if (D_001D5579 != 0) {
            func_L01_004F50C8(D_L08_001DF300[v[0x14]].f30, D_L08_001DF300[v[0x14]].p70, 0, 1);
        }
    }
    if (D_L08_001DEDC0 < 200) {
        if ((D_001D558C != 0 && (D_001BBC40[D_001D545C][v[0x11]] & 0x80) == 0) || D_001D4CF0 == 0x1C) {
            func_L01_004B0EE0();
        }
    }
    *(u16 *)(o + 0x96) += 1;
    if (func_00382380(D_001A4C60, v[0x15], 0) != 0) {
        if ((u32)(*(s32 *)(D_001A4C60 + 0x254C) - 0x11) < 2 && D_001A7C94 == 0
            && (D_001A809C[0] & (1 << D_001D545C)) == 0) {
            func_L01_0041A5B0(0xB92, 0x35);
        }
    }
    if (func_00382380(D_001A4C60, v[0x16], 0) != 0) {
        if ((D_001A84B0[0] & (1 << D_001D545C)) == 0) {
            func_L01_0041A5B0(0xCE3, 0x8C);
        }
    }
    if (D_00142CA0[0x21] != 0) {
        q = D_001426E0;
        if (q[0x74] == 0) {
            if ((D_001A8240[0] & (1 << D_001D545C)) == 0) {
                func_L01_0041A5B0(0xC94, 0x58);
            }
            q[0x74] = 1;
        }
    }
    r = D_001A4C60;
    if (func_00382380(r, v[0xE], 0) != 0) {
        *(f32 *)(r + 0x2D0) = 346.0f;
    }
    if (func_00382380(r, v[0xF], 0) != 0) {
        *(f32 *)(r + 0x2D0) = 349.0f;
    }
}
