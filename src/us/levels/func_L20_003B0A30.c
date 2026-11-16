#include "common.h"

/* NTSC-U counterpart of func_L20_003B2200 (src/levels/20_final_boss/L20_003AF880.c) */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_004A6DF8(void *, s32);
extern void func_L20_003B0E48(void *, s32, s32, s32);
#include "vu0.h"
extern s32 func_L20_003B0A30(u8 *);

/* localdecomp:start func_L20_003B0A30 */
extern u8 *func_003BCFB0(s32, s32);
extern void func_L01_00452E70(u8 *, u8 *);
extern void func_L01_00458A70(u8 *, f32, f32, f32, f32);
extern s32 func_L01_00417EA0(void);
extern void func_L01_00441FB8(void *, s32, s32);

s32 func_L20_003B0A30(u8 *a0) {
    u8 *p;
    u8 *o;

    a0[0x30] = 0xFF;
    *(s16 *)(a0 + 0x32) = 0xFF;
    p = *(u8 **)(a0 + 0x68);
    o = func_003BCFB0(0x199B, 0x80);
    *(u8 **)(p + 0x2E0) = o;
    if (o != 0) func_L01_00452E70(o, a0);
    o = func_003BCFB0(0x199C, 0x80);
    *(u8 **)(p + 0x2E4) = o;
    if (o != 0) func_L01_00452E70(o, a0);
    *(s16 *)(a0 + 0x32) = 500;
    *(s16 *)(*(u8 **)(p + 0x2E4) + 0x32) = 500;
    *(s16 *)(*(u8 **)(p + 0x2E0) + 0x32) = 500;
    p[0x1DB] = 0xFF;
    p[0x1D7] = 1;
    p[0x1D8] = 0;
    p[0x1D9] = 0;
    p[0x1DA] = 0;
    p[0x170] = 0x10;
    p[0x1A8] = 3;
    *(f32 *)(p + 0x19C) = 0.15f;
    *(f32 *)(p + 0x70) = 0.7f;
    *(f32 *)(p + 0x78) = *(f32 *)(p + 0x74) = *(f32 *)(p + 0x194) = *(f32 *)(p + 0x190) = 0.5f;
    *(f32 *)(p + 0x7C) = 1.0f;
    *(f32 *)(p + 0x80) = 0.7853982f;
    *(f32 *)(p + 0xA0) = 0.34906584f;
    *(f32 *)(p + 0x9C) = 0.002722222358f;
    func_L01_00458A70(a0, 0.004444444552f, 0.1000000089f, 0.00698131742f, 0.209439531f);
    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    if (*(s16 *)(p + 0x34) == 0) {
        *(s16 *)(p + 0x34) = 32000;
        *(f32 *)(p + 0x30) = 32000.0f;
    }
    if (func_L01_00417EA0() != 0) {
        *(s16 *)(p + 0x34) = 32000;
        *(f32 *)(p + 0x30) = 32000.0f;
    }
    if (p[0x44] == 0) {
        p[0x44] = 0x2D;
        p[0x45] = 0x2D;
        p[0x46] = 0x2D;
    }
    p[0x39] = 1;
    *(f32 *)(p + 0x40) = 2.0f;
    p[0x3E] = 1;
    *(s32 *)(a0 + 0x98) = 0;
    *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & ~0x1000;
    func_L01_004A6DF8(a0, 1);
    *(u16 *)(*(u8 **)(p + 0x2E4) + 0x34) |= 0x41;
    *(u16 *)(*(u8 **)(p + 0x2E4) + 0x34) &= ~0x1000;
    *(s32 *)(*(u8 **)(p + 0x2E4) + 0x98) = 0;
    func_L01_004A6DF8(*(u8 **)(p + 0x2E4), 1);
    *(u16 *)(*(u8 **)(p + 0x2E0) + 0x34) |= 0x41;
    *(u16 *)(*(u8 **)(p + 0x2E0) + 0x34) &= ~0x1000;
    *(s32 *)(*(u8 **)(p + 0x2E0) + 0x98) = 0;
    func_L01_004A6DF8(*(u8 **)(p + 0x2E0), 1);
    func_L01_00441FB8(a0, 1, 0);
    func_L20_003B0E48(a0, 1, 0, 0);
    func_L01_00441FB8(a0, 0x11, 4);
    return 0;
}
/* localdecomp:end func_L20_003B0A30 */
