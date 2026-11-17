#include "common.h"

/* localdecomp:start func_L08_003C7660 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C7660;
extern u8 D_001A30B0[];
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L08_003C73B8(void *, void *, void *);
extern s32 func_0038CAD0(void *);
extern void func_003A4F28(s32);

void func_L08_003C7660(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    V4_3C7660 a;
    s32 idx;
    u8 *e;

    switch (m[0x20]) {
    case 0:
        *(f32 *)(v + 0x14) = *(f32 *)(m + 0x2C) / *(f32 *)(*(u8 **)(m + 0x24) + 0x24);
        func_0038CE20(v, m + 0xD0, -1.0f);
        *(s32 *)(v + 0x10) = (func_00382498(0x5A, 0xAA) * 5 + 2) / 6;
        func_L01_004450F0(m, 1, -1);
        break;
    case 1: {
        s32 i = *(s32 *)(v + 0x18);
        if (i == -1 || (e = D_001A30B0 + (i << 7), *(void **)(e + 0xDC) != m) || e[0xD0] == 0) {
            *(s32 *)(v + 0x18) = func_003A52A0(0, 4, m);
        }
        func_0038CE20(&a, m + 0xD0, *(f32 *)(v + 0x14) * -0.75199997f);
        vec_add_ba(&a, m + 0x10, &a);
        func_L08_003C73B8(m, &a, v);
        if (func_0038CAD0(v + 0x10) != 0) {
            func_L01_004450F0(m, 2, -1);
        }
    }
    case 2:
        idx = *(s32 *)(v + 0x18);
        if (idx != -1) {
            e = D_001A30B0 + (idx << 7);
            if (*(void **)(e + 0xDC) == m && e[0xD0] != 0) {
                func_003A4F28(idx);
            }
        }
        *(s32 *)(v + 0x18) = -1;
        break;
    }
    m[0xA8] = 0xFF;
}
/* localdecomp:end func_L08_003C7660 */

/* localdecomp:start func_L08_003C7828 */
#include "vu0.h"
#include "structs/hero.h"

typedef struct {
    u8 pad_0[0x68];
    s32 s68;
    u8 pad_6C[0x774 - 0x6C];
    s32 s774;
} G_003C7828;

typedef struct {
    u8 pad_0[0xBF4];
    u16 hBF4;
    u8 pad_BF6[0xC0C - 0xBF6];
    u16 hC0C;
    u8 pad_C0E[0xC18 - 0xC0E];
    u16 hC18;
    u8 pad_C1A[0xC24 - 0xC1A];
    u16 hC24;
    u8 pad_C26[0xD20 - 0xC26];
    u16 hD20;
} H_003C7828;

extern struct Hero D_001A4BE0;
extern G_003C7828 D_L08_00242140;
extern H_003C7828 D_001A7E18;
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern f32 D_L08_001E1748;
extern f32 D_L08_001E174C;
__asm__(".extern D_L08_001E1748, 4");
__asm__(".extern D_L08_001E174C, 4");

extern void func_0038D308(void *, void *);
extern s32 func_0038CAD0(void *);
extern s32 func_L02_003E71A8(f32, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_0041A5B0(s32, s32);

void func_L08_003C7828(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 0x68);
    f32 f;
    vu0_v4 d;

    switch (a0[0x20]) {
    case 0:
        *(s32 *)(a0 + 0xF8) = 0;
        func_0038D308(a0 + 0xC0, a0 + 0xF0);
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_0038CAD0(p) == 0)
            break;
        if (func_L02_003E71A8(4.0f, &D_001A4BE0.pos, a0 + 0x10) == 0)
            break;
        D_L08_001E1748 = func_0038CE68(a0 + 0xD0, (u8 *)D_001A4BE0.hero_moby + 0xC0);
        vec_sub_ab(&d, &D_001A4BE0.pos, a0 + 0x10);
        func_0038CF68(&d, &d, 1.0f);
        f = func_0038CE68(a0 + 0xD0, &d);
        D_L08_001E174C = f;
        if (D_001A4BE0.body_kind != 0)
            break;
        if (D_001A4BE0.guise_timer != 0)
            break;
        if (D_L08_001E1748 > 0.25f && f < -0.25f) {
            if (*(s32 *)((u8 *)&D_001A4BE0 + 0x360) != 0) {
                func_L01_00452560(0, 1, 0x856, 1, 0, 0, 0);
                if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) {
                    func_003A0EC0(5, 1, 6, 0, 0);
                    p[0] = 0x19;
                    func_L01_004450F0(a0, 2, -1);
                }
            }
        }
        break;
    case 2:
        if (D_L08_00242140.s68 >= 0 && D_L08_00242140.s774 != 0) {
            if (D_001A7E18.hBF4 == 0) {
                if (func_L01_0041A5B0(0x13CB, 0xFF) != 0)
                    p[1] = 1;
            } else if (D_001A7E18.hD20 == 0) {
                if (func_L01_0041A5B0(0x149F, 0x118) != 0)
                    p[1] = 1;
            } else if (D_001A7E18.hC0C == 0) {
                if (func_L01_0041A5B0(0x13CD, 0x101) != 0)
                    p[1] = 1;
            } else if (D_001A7E18.hC18 == 0) {
                if (func_L01_0041A5B0(0x13CE, 0x102) != 0)
                    p[1] = 1;
            } else if (D_001A7E18.hC24 == 0) {
                if (func_L01_0041A5B0(0x13CF, 0x103) != 0)
                    p[1] = 1;
            }
        }
        if (func_0038CAD0(p) != 0 || p[1] != 0)
            func_L01_004450F0(a0, 1, -1);
        break;
    }
}
/* localdecomp:end func_L08_003C7828 */

/* localdecomp:start func_L08_003C7AC0 */
#include "vu0.h"
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 b20; u8 b21; u8 p22[0x74]; u16 h96; u8 p98[0x24]; u8 bBC; u8 pBD[3];
    vu0_v4 vC0; u8 pD0[0x10]; vu0_v4 vE0;
} M_003C7AC0;
extern u8 D_001A4C60[];
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00445BE0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);

void func_L08_003C7AC0(M_003C7AC0 *a0) {
    vu0_v4 a;
    vu0_v4 b;

    if (a0->b20 == 0) {
        if (a0->b21 != 0xFF) {
            if (a0->bBC != 0) {
                if (a0->bBC != 2) {
                    func_003A52A0(0, 0, a0);
                    func_L01_00445BE0(a0->b21, 2);
                }
                func_L01_004450F0(a0, 1, -1);
                func_L01_00456230(a0, 1);
            }
        } else if (func_0038CF38(&a0->pos, D_001A4C60) < 7.0f) {
            func_003A52A0(0, 0, a0);
            func_L01_004450F0(a0, 1, -1);
            func_L01_00456230(a0, 1);
        }
    }
    if (a0->b20 == 1) {
        a0->h96++;
        func_0038CF68(&a, &a0->vE0, 0.070000008f);
        func_0038CF68(&b, &a0->vC0, -0.070000008f);
        vec_add_ab(&a0->pos, &a0->pos, &a);
        vec_add_ab(&a0->pos, &a0->pos, &b);
        if (a0->h96 > 30) {
            func_L01_004450F0(a0, 2, -1);
        }
    }
}
/* localdecomp:end func_L08_003C7AC0 */
