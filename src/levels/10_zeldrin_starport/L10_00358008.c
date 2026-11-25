#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L10_00358008 */
extern u8 D_001A4C60[];
extern u8 *D_L10_001DF380[] __attribute__((section(".sdata")));
extern f32 func_0038CF00(void *, void *);

s32 func_L10_00358008(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    f32 d;
    f32 z;
    f32 h;
    f32 a;
    f32 b;
    s32 r;

    if (*(s32 *)(v + 0x90) != -1) {
        d = func_0038CF00(D_001A4C60, v + 0x70);
        b = func_0038CF00(D_001A4C60, D_L10_001DF380[0] + *(s32 *)(v + 0x90) * 0x80 + 0x30);
        a = d;
        r = 0;
        if (!(b < a)) {
            r = 1;
        }
        return r;
    }
    if (*(f32 *)(v + 0xA0) == 0.0f) {
        return 2;
    }
    z = *(f32 *)(m + 0x18);
    h = *(f32 *)(D_001A4C60 + 8);
    a = fabs_asm(h - z);
    b = fabs_asm(h - (z + *(f32 *)(v + 0xA0)));
    r = 0;
    if (!(b < a)) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L10_00358008 */

/* localdecomp:start func_L10_003580D8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3580D8;
typedef struct { u8 pad0[0x80]; u8 f80[8]; f32 f88; u8 pad8C[0x2D0]; u8 *f35C; s32 f360; u8 pad364[0xA]; s16 f36E; } G_3580D8;
extern G_3580D8 D_001A4BE0;
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
extern void func_L01_004450F0(void *, s32, s32);

void func_L10_003580D8(u8 *m) {
    u8 *v;
    V4_3580D8 op;
    V4_3580D8 orot;
    V4_3580D8 d;
    s32 t;
    u8 *e;
    s32 k;
    s32 r;
    u8 ok;

    op = *(V4_3580D8 *)(m + 0x10);
    orot = *(V4_3580D8 *)(m + 0xF0);
    v = *(u8 **)(m + 0x68);
    if (D_001A4BE0.f35C == m && D_001A4BE0.f360 >= 2 && D_001A4BE0.f36E <= 0) {
        v[0x9F]++;
    } else if (D_001A4BE0.f35C != m && v[0x9F] != 0) {
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
        *(V4_3580D8 *)(v + 0x80) = *(V4_3580D8 *)(m + 0xF0);
        v[0x9E] = 0;
        if (v[0x9C] != 0) {
            *(V4_3580D8 *)(m + 0x10) = *(V4_3580D8 *)(D_L10_001DF380[0] + 0x30 + (*(s32 *)(v + 0x90) << 7));
            *(V4_3580D8 *)(m + 0xF0) = *(V4_3580D8 *)(D_L10_001DF380[0] + 0x70 + (*(s32 *)(v + 0x90) << 7));
            *(f32 *)(v + 0x8C) = 1.0f;
            func_L01_004450F0(m, 3, -1);
        } else {
            *(f32 *)(v + 0x8C) = 0.0f;
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        ok = func_L10_00358008(m) == 0;
        if (v[0x9E] == 0 && (func_L01_00456250(m) != 0 || ok != 0 || v[0x9F] >= 8)) {
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
        r = func_L10_00358008(m);
        if (r == 1) {
            t = 1;
        } else {
            t = 0;
        }
        if ((v[0xA8] == 1 || func_L01_00445AD0(*(s32 *)(v + 0xA4), -1, 0) == 0) && v[0x9E] == 0 &&
            (func_L01_00456250(m) != 0 || t != 0 || v[0x9F] >= 8)) {
            v[0x9E] = 1;
            v[0xA8] = 1;
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
        t = 0;
        if (*(s32 *)(v + 0x98) != -1 && D_001A4BE0.f88 < *(f32 *)(m + 0x18)) {
            if (func_00382380(D_001A4BE0.f80, *(s32 *)(v + 0x98), 0) != 0 || func_00382380(D_L10_001E1BC0, *(s32 *)(v + 0x98), 0) != 0) {
                t = 1;
            }
        }
        if (t == 0) {
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
