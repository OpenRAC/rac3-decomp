#include "common.h"

/* NTSC-U counterpart of func_L22_003BCFF8 (src/levels/22_mylon/L22_003BCF38.c) */
#include "vu0.h"

/* localdecomp:start func_L22_003BB6E8 */
__asm__(".extern D_L22_001DE704, 4");
__asm__(".extern D_L22_001DE708, 4");
__asm__(".extern D_L22_001DE70C, 4");
__asm__(".extern D_L22_001DE710, 4");
__asm__(".extern D_L22_001DE714, 4");
extern f32 D_L22_001DE704;
extern s32 D_L22_001DE708;
extern f32 D_L22_001DE70C;
extern s32 D_L22_001DE710;
extern f32 D_L22_001DE714;
extern s32 D_001A71A0[];
extern u8 D_001A4C60[];
extern u8 D_001A4BE0[];
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C;
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_L01_00402498(void *, void *);
extern void func_L22_003BB628(u8 *);
extern void func_L22_003BBB00(void *);
extern s32 func_L01_00452EC8(void *);
extern void func_003BE418(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388A28(f32, f32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern s32 func_00388398(void *);
extern void func_003BD9A0(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern u8 *func_L22_00343770(void *, void *, void *, s32, s32, s32, f32, f32);
typedef struct { u8 pad[0x134]; s32 x134; } S_3BCFF8;
void func_L22_003BB6E8(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    vu0_v4 m[4];
    vu0_v4 p2, p1, d;
    u8 *hero;
    if (*(s32 *)(st + 0x138) != -1 && *(s32 *)(st + 0x130) == 0) {
        hero = D_001A4C60;
        if (func_0037E0F0(hero, *(s32 *)(st + 0x138), 0) != 0 && hero[0x2564] != 3) {
            *(s32 *)(st + 0x170) = 0;
            *(s32 *)(st + 0x178) = 1;
            *(s32 *)(st + 0x130) = 1;
        }
    }
    if (*(s32 *)(st + 0x130) != 0 && *(s32 *)(st + 0x138) != -1) {
        if (func_0037E0F0(D_001A4C60, *(s32 *)(st + 0x138), 0) == 0) {
            *(s32 *)(st + 0x130) = 0;
            *(s32 *)(st + 0x13C) = 0;
        }
    }
    if (*(s32 *)(st + 0x130) != 0 || *(s32 *)(st + 0x170) != 0) {
        if (*(s32 *)(st + 0x130) == 0 && *(s32 *)(st + 0x178) != -1) *(s32 *)(st + 0x178) = -1;
        func_L01_00402498(func_L22_003BB628, a0);
    }
    switch (a0[0x20]) {
    case 0:
        func_L22_003BBB00(a0);
        func_L01_00441FB8(a0, 1, -1);
        break;
    case 1:
        if (func_L01_00452EC8(a0) != 0) func_003BE418(a0, 0, 0);
        if (*(s32 *)(st + 0x130) != 0) func_L01_00441FB8(a0, 2, -1);
        break;
    case 2:
        if (func_L01_00452EC8(a0) != 0 && a0[0x43] != 1) func_003BE4F0(a0, 1, 0, 6);
        if (*(s32 *)(st + 0x130) == 0) func_L01_00441FB8(a0, 5, -1);
        if (a0[0x60] & 2) {
            func_003BE418(a0, 2, 0);
            func_L01_00441FB8(a0, 3, -1);
        }
        break;
    case 3:
        if (func_L01_00452EC8(a0) != 0) {
            ((S_3BCFF8 *)st)->x134 = 0x84;
            if (D_001D545C == 0x16 && *(s32 *)(st + 0x13C) != 0) ((S_3BCFF8 *)st)->x134 = 0x3c;
            func_003BE418(a0, 2, 0);
        }
        if (*(s32 *)(st + 0x130) == 0) func_L01_00441FB8(a0, 5, -1);
        {
        u8 *h = D_001A4BE0;
        *(f32 *)(st + 0x118) = func_00388A28(*(f32 *)(h + 0x80) - *(f32 *)(a0 + 0x10), *(f32 *)(h + 0x84) - *(f32 *)(a0 + 0x14)) - (*(f32 *)(a0 + 0xF8) - 1.5707964f);
        }
        func_L01_0044B5C8(a0, st + 0xB0, 0, 0.03f, 0.3f);
        if (func_00388398(st + 0x134) != 0) func_L01_00441FB8(a0, 4, -1);
        break;
    case 4:
        if (func_L01_00452EC8(a0) != 0) {
            *(s32 *)(st + 0x13C) = 1;
            if (a0[0x43] != 3) func_003BE4F0(a0, 3, 0, 6);
            func_003BD9A0(a0, 1, m);
            func_00388830(&p1, &m[1], -2.0f);
            vec_add_ba(&p1, &p1, &m[3]);
            func_00388830(&p2, &m[1], -120.0f);
            vec_add_ba(&p2, &p2, &m[3]);
            vec_sub_ab(&d, &p2, &m[3]);
            func_00388830(&d, &d, D_L22_001DE704);
            func_L22_00343770(a0, &m[3], &d, D_L22_001DE708, D_L22_001DE710, D_001A71A0[0], D_L22_001DE714, D_L22_001DE70C);
        }
        if (a0[0x60] & 2) func_L01_00441FB8(a0, 3, -1);
        break;
    case 5:
        if (func_L01_00452EC8(a0) != 0 && a0[0x43] != 4) func_003BE4F0(a0, 4, 0, 6);
        if (*(s32 *)(st + 0x130) != 0) func_L01_00441FB8(a0, 2, -1);
        if (a0[0x60] & 2) func_L01_00441FB8(a0, 1, -1);
        break;
    }
}
/* localdecomp:end func_L22_003BB6E8 */
