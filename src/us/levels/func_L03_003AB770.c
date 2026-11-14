#include "common.h"

/* NTSC-U counterpart of func_L03_003AD098 (src/levels/shared/L03_003AAD60.c) */
/* localdecomp:start func_L03_003AB770 */
typedef struct B_003AB770 {
    u8 pad0[0xC0];
    u8 xC0[0x30];
    f32 fF0;
} B_003AB770;

typedef struct A_003AB770 {
    B_003AB770 *x0;
    u8 pad4[0x14];
    s32 x18;
    s32 x1C;
    u8 pad20[0x48 - 0x20];
    f32 f48;
    u8 pad4C[0x150 - 0x4C];
    f32 f150;
    u8 pad154[0x1D0 - 0x154];
    f32 f1D0;
} A_003AB770;

typedef struct C_003AB770 {
    f32 f0;
    f32 f4;
    s32 x8;
} C_003AB770;

typedef struct G_003AB770 {
    u8 pad0[0xD0];
    u8 bD0;
    u8 padD1[0xDC - 0xD1];
    void *xDC;
} G_003AB770;

typedef struct O_003AB770 {
    u8 pad0[0x68];
    A_003AB770 *x68;
} O_003AB770;

extern u8 D_001A30B0[];
extern f32 D_001DE608_sda;
__asm__(".extern D_001DE608_sda, 4");
extern f32 func_L03_003AB708(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_L01_0044B5C8(s32, void *, s32, f32, f32);
extern void func_00388BD0(void *, void *);
extern s32 func_0039FE80(s32, s32, void *);

s32 func_L03_003AB770(O_003AB770 *o) {
    A_003AB770 *a = o->x68;
    C_003AB770 *c = *(C_003AB770 **)((u8 *)a->x0 + 0x68);

    switch (c->x8) {
    case 0:
        if (a->x18 == -1 || ((G_003AB770 *)(D_001A30B0 + (a->x18 << 7)))->xDC != o || ((G_003AB770 *)(D_001A30B0 + (a->x18 << 7)))->bD0 == 0) {
            a->x18 = func_0039FE80(1, 4, o);
        }
        a->f48 = func_L03_003AB708(a->f48, 10.0f) ;
        a->f150 = func_00389380(0.0f, a->f48 * 0.017453292f);
        func_L01_0044B5C8(a->x1C, (u8 *)a + 0xF0, 0, 2.0f, 2.0f);
        a->f1D0 = func_00389380(0.0f, a->f48 * 0.017453292f);
        func_L01_0044B5C8(a->x1C, (u8 *)a + 0x170, 1, 2.0f, 2.0f);
        c->f4 = func_L03_003AB708(c->f4, -D_001DE608_sda);
        break;
    case 1:
        if (a->x18 == -1 || ((G_003AB770 *)(D_001A30B0 + (a->x18 << 7)))->xDC != o || ((G_003AB770 *)(D_001A30B0 + (a->x18 << 7)))->bD0 == 0) {
            a->x18 = func_0039FE80(0, 4, o);
        }
        a->f48 = func_L03_003AB708(a->f48, -10.0f) ;
        a->f150 = func_00389380(0.0f, a->f48 * 0.017453292f);
        func_L01_0044B5C8(a->x1C, (u8 *)a + 0xF0, 0, 2.0f, 2.0f);
        a->f1D0 = func_00389380(0.0f, a->f48 * 0.017453292f);
        func_L01_0044B5C8(a->x1C, (u8 *)a + 0x170, 1, 2.0f, 2.0f);
        c->f4 = func_L03_003AB708(c->f4, D_001DE608_sda);
        break;
    case 2:
        if (a->x18 == -1 || ((G_003AB770 *)(D_001A30B0 + (a->x18 << 7)))->xDC != o || ((G_003AB770 *)(D_001A30B0 + (a->x18 << 7)))->bD0 == 0) {
            a->x18 = func_0039FE80(1, 4, o);
        }
        a->f48 = func_L03_003AB708(a->f48, 20.0f) ;
        a->f150 = func_00389380(0.0f, a->f48 * 0.017453292f);
        func_L01_0044B5C8(a->x1C, (u8 *)a + 0xF0, 0, 2.0f, 2.0f);
        a->f1D0 = func_00389380(0.0f, a->f48 * 0.017453292f);
        func_L01_0044B5C8(a->x1C, (u8 *)a + 0x170, 1, 2.0f, 2.0f);
        c->f4 = func_L03_003AB708(c->f4, -D_001DE608_sda * 2.0f);
        break;
    case 3:
        if (a->x18 == -1 || ((G_003AB770 *)(D_001A30B0 + (a->x18 << 7)))->xDC != o || ((G_003AB770 *)(D_001A30B0 + (a->x18 << 7)))->bD0 == 0) {
            a->x18 = func_0039FE80(0, 4, o);
        }
        a->f48 = func_L03_003AB708(a->f48, -20.0f) ;
        a->f150 = func_00389380(0.0f, a->f48 * 0.017453292f);
        func_L01_0044B5C8(a->x1C, (u8 *)a + 0xF0, 0, 2.0f, 2.0f);
        a->f1D0 = func_00389380(0.0f, a->f48 * 0.017453292f);
        func_L01_0044B5C8(a->x1C, (u8 *)a + 0x170, 1, 2.0f, 2.0f);
        c->f4 = func_L03_003AB708(c->f4, D_001DE608_sda * 2.0f);
        break;
    default:
        break;
    }
    a->x0->fF0 = func_00389380(0.0f, c->f4 * 0.017453292f);
    func_00388BD0((u8 *)a->x0 + 0xC0, (u8 *)a->x0 + 0xF0);
    if (c->f4 == c->f0) {
        c->x8 = 4;
        func_0039FE80(2, 0, o);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L03_003AB770 */
