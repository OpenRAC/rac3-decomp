#include "common.h"

/* NTSC-U counterpart of func_L08_003C7828 (src/levels/08_aquatos/L08_003C7660.c): the timer is 30 frames, not 25 */
/* localdecomp:start func_L08_003C5510 */
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

extern void func_00388BD0(void *, void *);
extern s32 func_00388398(void *);
extern s32 func_L02_003E4788(f32, void *, void *);
extern f32 func_00388730(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_0039BEC0(s32, s32, s32, s32, u8 *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00417F60(s32, s32);

void func_L08_003C5510(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 0x68);
    f32 f;
    vu0_v4 d;

    switch (a0[0x20]) {
    case 0:
        *(s32 *)(a0 + 0xF8) = 0;
        func_00388BD0(a0 + 0xC0, a0 + 0xF0);
        func_L01_00441FB8(a0, 1, -1);
        break;
    case 1:
        if (func_00388398(p) == 0)
            break;
        if (func_L02_003E4788(4.0f, &D_001A4BE0.pos, a0 + 0x10) == 0)
            break;
        D_L08_001E1748 = func_00388730(a0 + 0xD0, (u8 *)D_001A4BE0.hero_moby + 0xC0);
        vec_sub_ab(&d, &D_001A4BE0.pos, a0 + 0x10);
        func_00388830(&d, &d, 1.0f);
        f = func_00388730(a0 + 0xD0, &d);
        D_L08_001E174C = f;
        if (D_001A4BE0.body_kind != 0)
            break;
        if (D_001A4BE0.guise_timer != 0)
            break;
        if (D_L08_001E1748 > 0.25f && f < -0.25f) {
            if (*(s32 *)((u8 *)&D_001A4BE0 + 0x360) != 0) {
                func_L01_0044F2E8(0, 1, 0x856, 1, 0, 0, 0);
                if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) {
                    func_0039BEC0(5, 1, 6, 0, 0);
                    p[0] = 0x1E;
                    func_L01_00441FB8(a0, 2, -1);
                }
            }
        }
        break;
    case 2:
        if (D_L08_00242140.s68 >= 0 && D_L08_00242140.s774 != 0) {
            if (D_001A7E18.hBF4 == 0) {
                if (func_L01_00417F60(0x13CB, 0xFF) != 0)
                    p[1] = 1;
            } else if (D_001A7E18.hD20 == 0) {
                if (func_L01_00417F60(0x149F, 0x118) != 0)
                    p[1] = 1;
            } else if (D_001A7E18.hC0C == 0) {
                if (func_L01_00417F60(0x13CD, 0x101) != 0)
                    p[1] = 1;
            } else if (D_001A7E18.hC18 == 0) {
                if (func_L01_00417F60(0x13CE, 0x102) != 0)
                    p[1] = 1;
            } else if (D_001A7E18.hC24 == 0) {
                if (func_L01_00417F60(0x13CF, 0x103) != 0)
                    p[1] = 1;
            }
        }
        if (func_00388398(p) != 0 || p[1] != 0)
            func_L01_00441FB8(a0, 1, -1);
        break;
    }
}
/* localdecomp:end func_L08_003C5510 */
