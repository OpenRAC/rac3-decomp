/* functional: medium. lui-addressed globals are unsized arrays and the gp-relative D_L01_001DCF80/84/88 and D_L01_001D6690 plain externs (-G8 makes them gp-relative; an explicit .sdata section made the gate's -G0 rebuild link them 0x4000 low). Written from the PAL asm with the jump table (jtbl_002BEB90 read from the level ELF: 0->336EAC, 1->337018, 2->337208, 3/default->return, 4->33770C). Each branch, constant, offset and the call sequence (86 jal sites in the same order) checked; the draw-callback tail is repeated in states 1, 2, 4 as in retail. Unverified: meaning of some absolute globals (D_001A8658/89B8/89A0/89AC u16, D_00142CB0/B6/B3 u8 are retail lui-addressed; named by address). func_0038CF68 gets the leftover f12=1.95 as scale (register passthrough made explicit). 684 words differ. */
/* localdecomp:start func_L01_00336D90 */
#include "vu0.h"
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00336D90;
extern u8 D_001A4BE0[];
extern f32 D_001A4C60[];
extern s32 D_001D545C;
extern u8 *D_001D52FC;
extern s32 D_L01_001D673C;
extern s32 D_L01_001D6694;
extern s32 D_L01_001DFB40;
extern u16 D_001A8658[];
extern u16 D_001A89B8[];
extern u16 D_001A89A0[];
extern u16 D_001A89AC[];
extern u8 D_00142CB0[];
extern u8 D_00142CB6[];
extern u8 D_00142CB3[];
extern s32 D_L01_002E5F30[];
extern u8 D_L01_00244E18[];
extern s32 D_L01_002D15F0[];
extern f32 D_L01_001DCF88;
extern f32 D_L01_001DCF80;
extern f32 D_L01_001DCF84;
extern s32 D_L01_001D6690;
void func_L01_00336D90(u8 *m)
{
    extern s32 func_0038DBD8(f32, u32, u32);
    extern s32 func_L01_00451CD8(s32, s32, s32, s32);
    extern s32 func_L01_0041A4F0(void);
    extern void func_003C2880(u8 *);
    extern u8 *func_003C24B0(s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_0043A430(void *, s32, void *);
    extern void func_003C7C38(void *);
    extern f32 func_0038CF38(void *, void *);
    extern void func_L01_004BAF50(void);
    extern void func_L01_004C0F28(s32, s32);
    extern void func_L01_0041A5B0(s32, s32);
    extern void func_L01_00404A10(void *, void *);
    extern void func_L01_003365C0(u8 *);
    extern void func_0038D750(void *, s32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DBA0(f32, f32);
    extern void func_L01_004450F0(u8 *, s32, s32);
    extern s32 func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
    extern s32 func_L01_00513EF0(void);
    extern s32 func_003A0EC0(s32, s32, u8 *, s32, s32);
    u8 *p = *(u8 **)(m + 0x68);
    u8 *child;
    V4_00336D90 tmp;
    f32 f, dist, dz, ang;
    s32 r, i, a, b, c, x, y, code;
    u32 col;

    D_L01_001DCF88 += 0.05f;
    if (3.14f < D_L01_001DCF88) D_L01_001DCF88 = -3.14f;
    r = func_0038DBD8(0.5f, 0x802299DE, 0);
    col = 0x802299DE;
    if (*(s32 *)(p + 0x94) == 2) {
        r = 0x101;
        col = 0x8080;
    }
    *(s32 *)(m + 0x78) = func_L01_00451CD8(((D_L01_001DFB40 & 0x3F) * 5 + 2) / 6, 0x34, r, col);
    if (*(u8 **)(p + 0xC) != 0) {
        *(u32 *)(*(u8 **)(p + 0xC) + 0x78) = col | 0x80000000;
    }
    switch (m[0x20]) {
    case 0:
        if (*(s32 *)(p + 0x98) != 0 && func_L01_0041A4F0() == 0) {
            func_003C2880(m);
            return;
        }
        m[0x20] = 1;
        *(s32 *)(p + 0) = 0;
        *(s32 *)(p + 4) = 0;
        child = func_003C24B0(0x477, 0x80);
        *(u8 **)(p + 0xC) = child;
        *(u16 *)(child + 0x34) |= 0x12;
        child = *(u8 **)(p + 0xC);
        *(u16 *)(child + 0x32) = 0x40;
        child = *(u8 **)(p + 0xC);
        *(f32 *)(child + 0x10) = *(f32 *)(m + 0x10);
        child = *(u8 **)(p + 0xC);
        *(f32 *)(child + 0x14) = *(f32 *)(m + 0x14);
        child = *(u8 **)(p + 0xC);
        *(f32 *)(child + 0x18) = *(f32 *)(m + 0x18) + 1.95f;
        *(u16 *)(m + 0x34) |= 0x10;
        if (D_L01_001D673C != 0) {
            tmp = *(V4_00336D90 *)(m + 0xE0);
            func_0038CF68(&tmp, &tmp, 1.95f);
            /* retail's VU0 vadd (vf1 = m+0x10 + tmp, vf2 = tmp), so the VU0 state callees see is retail's */
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(tmp) : "m"(*(V4_00336D90 *)(m + 0x10)), "m"(tmp) : "vf1", "vf2");
            child = *(u8 **)(p + 0xC);
            *(V4_00336D90 *)(child + 0x10) = tmp;
            child = *(u8 **)(p + 0xC);
            *(V4_00336D90 *)(child + 0xF0) = *(V4_00336D90 *)(m + 0xF0);
        }
        if (*(s32 *)(p + 0x94) == 3) {
            child = *(u8 **)(p + 0xC);
            *(f32 *)(child + 0x18) -= 30.0f;
            *(u16 *)(m + 0x34) |= 0x80;
        }
        child = *(u8 **)(p + 0xC);
        child[0x63] = 0x20;
        *(f32 *)(p + 0x90) = 0.3f;
        for (i = 0; i < 2; i++) {
            func_L01_0043A430(*(u8 **)(p + 0xC), i, p + 0x10 + i * 0x40);
        }
        func_003C7C38(*(u8 **)(p + 0xC));
        return;
    case 1:
        f = *(f32 *)(p + 0x90);
        if (0.0f < f) *(f32 *)(p + 0x90) = f - 0.1f;
        child = *(u8 **)(p + 0xC);
        *(s32 *)(child + 0x98) = 0;
        if (*(f32 *)(p + 0x90) <= 0.0f) {
            child = *(u8 **)(p + 0xC);
            *(u16 *)(child + 0x34) |= 1;
        }
        if ((D_L01_001DFB40 & 7) == 0) {
            if (func_0038CF38(m + 0x10, D_001A4C60) <= 16.0f) {
                f = *(f32 *)(m + 0x18);
                if (fabs_asm(f - D_001A4C60[2]) <= 8.0f) {
                    if (!(f + 1.0f < D_001A4C60[2]) || !(func_0038CF38(m + 0x10, D_001A4C60) < 0.8f)) {
                        m[0x20] = 2;
                        child = *(u8 **)(p + 0xC);
                        *(u16 *)(child + 0x34) &= 0xFFFE;
                        if (*(s32 *)(p + 0x94) == 2) func_L01_004BAF50();
                        func_L01_004C0F28(D_001D545C, *(s32 *)(p + 0x94));
                    }
                }
            }
        }
        if (*(s32 *)(p + 0x94) == 3) return;
        func_L01_00404A10(func_L01_003365C0, m);
        func_0038D750(p + 0x20, 2, D_L01_001DCF80);
        func_0038D750(p + 0x60, 2, D_L01_001DCF84);
        D_L01_001DCF80 = func_0038DAB8(D_L01_001DCF80, 0.01f);
        D_L01_001DCF84 = func_0038DAB8(D_L01_001DCF84, -0.02f);
        child = *(u8 **)(p + 0xC);
        *(f32 *)(child + 0x2C) = (*(f32 *)(p + 0x90) * *(f32 *)(*(u8 **)(child + 0x24) + 0x24)) * 2.0f;
        func_003C7C38(*(u8 **)(p + 0xC));
        return;
    case 2:
        dist = func_0038CF38(m + 0x10, D_001A4C60);
        f = *(f32 *)(p + 0x90);
        dz = fabs_asm(*(f32 *)(m + 0x18) - D_001A4C60[2]);
        if (f < 1.0f) *(f32 *)(p + 0x90) = f + 0.1f;
        child = *(u8 **)(p + 0xC);
        *(u16 *)(child + 0x34) &= 0xFFFE;
        child = *(u8 **)(p + 0xC);
        child[0x31] = 1;
        if (D_001D545C == 2) {
            if (D_001A8658[0] == 0 && func_L01_0041A4F0() != 0) func_L01_0041A5B0(0x1041, 0xB0);
        } else if (D_001D545C == 0xE) {
            if (D_001A89B8[0] == 0 && D_00142CB0[0] == 0) func_L01_0041A5B0(0x13C4, 0xF8);
        } else if (D_001D545C == 0x16) {
            if (D_001A89A0[0] == 0 && D_00142CB6[0] == 0) func_L01_0041A5B0(0x13C2, 0xF6);
        } else if (D_001D545C == 0x13) {
            if (D_001A89AC[0] == 0 && D_00142CB3[0] == 0) func_L01_0041A5B0(0x13C3, 0xF7);
        }
        f = func_0038CF38(m + 0x10, D_001A4C60);
        child = *(u8 **)(p + 0xC);
        if (f < 1.08f) {
            *(s32 *)(child + 0x98) = 0;
        } else {
            *(s32 *)(child + 0x98) = *(s32 *)(*(u8 **)(child + 0x24) + 0x10);
        }
        if (*(f32 *)(m + 0x18) + 1.0f < *(f32 *)(D_001A4BE0 + 0x88)) {
            if (func_0038CF38(m + 0x10, D_001A4BE0 + 0x80) < 0.8f) func_L01_004450F0(m, 1, -1);
        }
        if ((D_L01_001DFB40 & 7) == 0) {
            if (18.0f < dist || 10.0f < dz) {
                m[0x20] = 1;
                return;
            }
        }
        if (*(s32 *)(p + 0x94) != 3) {
            func_L01_00404A10(func_L01_003365C0, m);
            func_0038D750(p + 0x20, 2, D_L01_001DCF80);
            func_0038D750(p + 0x60, 2, D_L01_001DCF84);
            D_L01_001DCF80 = func_0038DAB8(D_L01_001DCF80, 0.01f);
            D_L01_001DCF84 = func_0038DAB8(D_L01_001DCF84, -0.02f);
            child = *(u8 **)(p + 0xC);
            *(f32 *)(child + 0x2C) = (*(f32 *)(p + 0x90) * *(f32 *)(*(u8 **)(child + 0x24) + 0x24)) * 2.0f;
            func_003C7C38(*(u8 **)(p + 0xC));
        }
        a = 1;
        b = 1;
        x = *(s32 *)(D_001A4BE0 + 0x25CC);
        if (x != 0) {
            y = *(s32 *)(D_001A4BE0 + 0x25C4);
            if (y != 3 && y != 4 && x != 1) {
                a = 0;
                b = 0;
            }
        }
        y = *(s32 *)(D_001A4BE0 + 0x25C4);
        if (y == 0x1C || y == 0x31) {
            a = 0;
            b = 0;
        }
        if (D_001A4BE0[0x25E4] != 0) {
            a = 0;
            b = 0;
        } else if (*(s16 *)(D_001A4BE0 + 0x288C) != 0) {
            a = 0;
            b = 0;
        } else if (D_L01_001D6694 == 1 || D_L01_001D6694 == 2) {
            a = 0;
            b = 0;
        } else if (D_L01_001D6690 == 1 || D_L01_001D6690 == 2) {
            a = 0;
            b = 0;
        }
        if (4.0f < dist) {
            a = 0;
            b = 0;
        } else if (2.0f < dz) {
            a = 0;
            b = 0;
        }
        ang = func_0038D160(*(f32 *)(m + 0x10) - *(f32 *)(D_001A4BE0 + 0x80),
                            *(f32 *)(m + 0x14) - *(f32 *)(D_001A4BE0 + 0x84));
        ang = func_0038DBA0(*(f32 *)(D_001A4BE0 + 0x98), ang);
        if (1.5707964f < ang) {
            a = 0;
            b = 0;
        }
        if (D_L01_002E5F30[0] != 0 || D_L01_002E5F30[9] != -1) {
            a = 0;
            b = 0;
        }
        c = 0;
        if (D_L01_00244E18[0] != 0) {
            m[0x20] = 4;
            return;
        }
        if (b != 0) {
            if (*(s32 *)(p + 0x94) == 2) code = 0x8BB;
            else if (*(s32 *)(p + 0x94) == 4) code = 0x8BC;
            else code = 0x856;
            c = func_L01_00452560(0, 1, code, 1, 0, 0, 0) != 0;
        }
        if (!(*(s32 *)(D_001D52FC + 0x1A4) & 0x10)) return;
        if (a == 0) return;
        if (c == 0) return;
        m[0x20] = 4;
        D_L01_002D15F0[0] = 5;
        D_L01_002D15F0[2] = 10;
        return;
    case 4:
        D_L01_002D15F0[0] = 5;
        D_L01_002D15F0[2] = 10;
        f = *(f32 *)(p + 0x90);
        if (0.0f < f) *(f32 *)(p + 0x90) = f - 0.1f;
        if (*(f32 *)(p + 0x90) <= 0.0f) {
            child = *(u8 **)(p + 0xC);
            *(u16 *)(child + 0x34) |= 1;
            if (func_L01_00513EF0() == 0) {
                func_003A0EC0(5, 1, m, 0, 0);
                m[0x20] = 3;
            } else {
                func_003A0EC0(5, 1, 0, 0, 0);
                m[0x20] = 2;
            }
            return;
        }
        if (*(s32 *)(p + 0x94) == 3) return;
        func_L01_00404A10(func_L01_003365C0, m);
        func_0038D750(p + 0x20, 2, D_L01_001DCF80);
        func_0038D750(p + 0x60, 2, D_L01_001DCF84);
        D_L01_001DCF80 = func_0038DAB8(D_L01_001DCF80, 0.01f);
        D_L01_001DCF84 = func_0038DAB8(D_L01_001DCF84, -0.02f);
        child = *(u8 **)(p + 0xC);
        *(f32 *)(child + 0x2C) = (*(f32 *)(p + 0x90) * *(f32 *)(*(u8 **)(child + 0x24) + 0x24)) * 2.0f;
        func_003C7C38(*(u8 **)(p + 0xC));
        return;
    default:
        return;
    }
}
/* localdecomp:end func_L01_00336D90 */
