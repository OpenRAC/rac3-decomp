/* near miss (level 10, Zeldrin Starport): first full draft, 379 differences counted (tools/check.py at level 10 with the VU0 flag set and a divs_nops row 'func_L10_003580D8 0 0 2 0'), most from a one-instruction offset: the six-state lift (jump table) is in retail's block order, but retail keeps the hero struct's high half (lui) in $s1 for case 4's re-addressing, and several case bodies differ in register choice and store order. Needs -mvu0-use-vf0-vf2 ... @ps2as on src/levels/10_zeldrin_starport/L10_00358008.c (vec_sub_ba; the file is @ps2as with vu0.h already) and the divs_nops row above. Not tuned further */
#include "common.h"

/* localdecomp:start func_L10_003580D8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3580D8;
extern u8 D_001A4BE0[];
extern u8 D_001A30B0[];
extern u8 D_L10_001E1BC0[];
extern s32 func_L10_00358008(u8 *);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern f32 func_0038D098(f32);
extern void func_L05_004512F8(void *, void *, void *, s32, f32);
extern s32 func_00382380(void *, s32, s32);
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L10_003580D8(u8 *m) {
    u8 *v;
    V4_3580D8 op;
    V4_3580D8 orot;
    V4_3580D8 d;
    s32 t;
    s32 ok;
    u8 *e;
    s32 k;

    op = *(V4_3580D8 *)(m + 0x10);
    orot = *(V4_3580D8 *)(m + 0xF0);
    v = *(u8 **)(m + 0x68);
    if (*(u8 **)(D_001A4BE0 + 0x35C) == m && *(s32 *)(D_001A4BE0 + 0x360) >= 2 && *(s16 *)(D_001A4BE0 + 0x36E) <= 0) {
        v[0x9F]++;
    } else if (*(u8 **)(D_001A4BE0 + 0x35C) != m && v[0x9F] != 0) {
        v[0x9F]--;
    }
    if (v[0x9F] > 8) {
        v[0x9F] = 8;
    }
    switch (m[0x20]) {
    case 0:
        if (v == 0) {
            func_L01_004450F0(m, 6, -1);
            return;
        }
        if (*(s32 *)(v + 0x90) == -1) {
            *(u16 *)(m + 0x34) |= 2;
            func_L01_004450F0(m, 6, -1);
            return;
        }
        v[0xA8] = 0;
        *(s32 *)(v + 0x6C) |= 1;
        *(V4_3580D8 *)(v + 0x70) = *(V4_3580D8 *)(m + 0x10);
        v[0x9E] = 0;
        *(V4_3580D8 *)(v + 0x80) = *(V4_3580D8 *)(m + 0xF0);
        if (v[0x9C] != 0) {
            *(V4_3580D8 *)(m + 0x10) = *(V4_3580D8 *)(D_L10_001DF380[0] + (*(s32 *)(v + 0x90) << 7) + 0x30);
            *(V4_3580D8 *)(m + 0xF0) = *(V4_3580D8 *)(D_L10_001DF380[0] + (*(s32 *)(v + 0x90) << 7) + 0x70);
            *(f32 *)(v + 0x8C) = 1.0f;
            func_L01_004450F0(m, 3, -1);
        } else {
            *(f32 *)(v + 0x8C) = 0.0f;
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        t = func_L10_00358008(m) == 0;
        if (v[0x9E] == 0 && (func_L01_00456250(m) != 0 || t != 0 || v[0x9F] >= 8)) {
            v[0x9E] = 1;
            func_L01_004450F0(m, 2, -1);
            break;
        }
        if (func_L01_00456250(m) == 0 && v[0x9F] == 0) {
            v[0x9E] = 0;
        }
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
            if (v[0xAA] != 0) {
                *(s32 *)(v + 0xAC) = func_003A52A0(v[0xA9], 4, m);
            } else {
                func_003A52A0(v[0xA9], 0, m);
            }
        }
        *(f32 *)(v + 0x8C) += 1.0f / ((*(f32 *)(v + 0x94) * 5.0f + 2.0f) / 6.0f);
        if (1.0f < *(f32 *)(v + 0x8C)) {
            *(f32 *)(v + 0x8C) = 1.0f;
        }
        func_L05_004512F8(m, v + 0x70, v + 0x80, *(s32 *)(v + 0x90), (1.0f - func_0038D098(*(f32 *)(v + 0x8C) * 3.1415927f)) * 0.5f);
        if (1.0f <= *(f32 *)(v + 0x8C)) {
            if (v[0xAA] != 0) {
                k = *(s32 *)(v + 0xAC);
                if (k != -1) {
                    e = D_001A30B0 + (k << 7);
                    if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                        func_003A4F28(k);
                    }
                }
                *(s32 *)(v + 0xAC) = -1;
            }
            *(f32 *)(v + 0x8C) = 1.0f;
            if (v[0x9D] != 0) {
                func_L01_004450F0(m, 5, -1);
            } else {
                func_L01_004450F0(m, 3, -1);
            }
        }
        break;
    case 3:
        t = func_L10_00358008(m) == 1;
        if ((v[0xA8] == 1 || func_L01_00445AD0(*(s32 *)(v + 0xA4), -1, 0) == 0) && v[0x9E] == 0 &&
            (func_L01_00456250(m) != 0 || t != 0 || v[0x9F] >= 8)) {
            v[0xA8] = 1;
            v[0x9E] = 1;
            func_L01_004450F0(m, 4, -1);
            break;
        }
        if (func_L01_00456250(m) == 0 && v[0x9F] == 0) {
            v[0x9E] = 0;
        }
        break;
    case 4:
        if (func_L01_004561B8(m) != 0) {
            if (v[0xAA] != 0) {
                *(s32 *)(v + 0xAC) = func_003A52A0(v[0xA9], 4, m);
            } else {
                func_003A52A0(v[0xA9], 0, m);
            }
        }
        ok = 0;
        if (*(s32 *)(v + 0x98) != -1 && *(f32 *)(D_001A4BE0 + 0x88) < *(f32 *)(m + 0x18)) {
            if (func_00382380(D_001A4BE0 + 0x80, *(s32 *)(v + 0x98), 0) != 0) {
                ok = 1;
            } else if (func_00382380(D_L10_001E1BC0, *(s32 *)(v + 0x98), 0) != 0) {
                ok = 1;
            }
        }
        if (ok == 0) {
            *(f32 *)(v + 0x8C) -= 1.0f / ((*(f32 *)(v + 0x94) * 5.0f + 2.0f) / 6.0f);
            if (*(f32 *)(v + 0x8C) < 0.0f) {
                *(f32 *)(v + 0x8C) = 0.0f;
            }
            func_L05_004512F8(m, v + 0x70, v + 0x80, *(s32 *)(v + 0x90), (1.0f - func_0038D098(*(f32 *)(v + 0x8C) * 3.1415927f)) * 0.5f);
        }
        if (*(f32 *)(v + 0x8C) <= 0.0f) {
            if (v[0xAA] != 0) {
                k = *(s32 *)(v + 0xAC);
                if (k != -1) {
                    e = D_001A30B0 + (k << 7);
                    if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                        func_003A4F28(k);
                    }
                }
                *(s32 *)(v + 0xAC) = -1;
            }
            *(f32 *)(v + 0x8C) = 0.0f;
            if (v[0x9D] != 0) {
                func_L01_004450F0(m, 5, -1);
            } else {
                func_L01_004450F0(m, 1, -1);
            }
        }
        break;
    case 5:
        *(u16 *)(m + 0x34) |= 2;
        break;
    }
    if (m[0x20] < 5) {
        vec_sub_ba(&d, m + 0x10, &op);
        func_003C4DA8(v + 0x30, &d, &orot, m + 0xF0);
    }
}
/* localdecomp:end func_L10_003580D8 */
