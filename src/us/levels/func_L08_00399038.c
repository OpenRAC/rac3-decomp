#include "common.h"

/* NTSC-U counterpart of func_L08_0039AA38 (src/levels/08_aquatos/L08_0039A9D8.c) */
void func_L01_00441FB8(s32, s32, s32);

/* localdecomp:start func_L08_00399038 */
typedef int q_0039AA38 __attribute__((mode(TI)));
extern void func_00388440(void *, s32, s32);
extern u8 *func_003BCFB0(s32, s32);
extern void func_L01_00452E70(u8 *, u8 *);
extern void func_003C26C8(void *);

s32 func_L08_00399038(u8 *a) {
    u8 *p;
    u8 *c;

    if (a[0x20] >= 2) {
        return 0;
    }
    if (a == 0) {
        return 0;
    }
    c = *(u8 **)(a + 0x24);
    p = *(u8 **)(a + 0x68);
    *(u16 *)(a + 0x34) &= 0xFFBC;
    *(u16 *)(a + 0x34) |= *(u16 *)(c + 0x44) & 0x1000;
    *(s32 *)(a + 0x98) = *(s32 *)(c + 0x10);
    *(s16 *)(p + 0x108) = 0;
    p[0xE0] = 0xFF;
    p[0x118] = 0xFF;
    p[0xE1] = 0xFF;
    p[0xE2] = 0xFF;
    *(f32 *)(p + 0x100) = 0.5f;
    p[0x147] = 1;
    p[0x38] = 1;
    p[0xE6] = 0xFF;
    *(f32 *)(p + 0x104) = 0.5f;
    *(f32 *)(p + 0x10C) = 0.15f;
    *(f32 *)(p + 0x190) = 0.4f;
    *(f32 *)(p + 0x194) = 0.3f;
    *(f32 *)(p + 0x198) = 2.2f;
    *(f32 *)(p + 0x19C) = 2.0f;
    *(f32 *)(p + 0x1A0) = 1.3089969f;
    *(f32 *)(p + 0x1C0) = 3.1415927f;
    *(f32 *)(p + 0x1BC) = 0.0027222223579883575f;
    *(f32 *)(p + 0x1C4) = 1.0f;
    *(s32 *)(p + 0x1C8) |= 2;
    *(f32 *)(p + 0x40) = 1.5f;
    p[0x39] = 1;
    p[0x3F] = 0;
    if (*(s16 *)(p + 0x34) == 0 || *(f32 *)(p + 0x30) <= 0.0f) {
        *(s16 *)(p + 0x34) = 100;
        *(f32 *)(p + 0x30) = 100.0f;
    }
    p[0x58] = 20;
    p[0x5A] = 14;
    *(s32 *)(p + 0x3AC) = 0;
    *(q_0039AA38 *)(p + 0x4B0) = *(q_0039AA38 *)(a + 0x10);
    *(q_0039AA38 *)(p + 0x4C0) = *(q_0039AA38 *)(a + 0xF0);
    func_00388440(p + 0x4D0, 0, 0x80);
    if (*(u8 **)(p + 0x5D0) == 0) {
        *(u8 **)(p + 0x5D0) = func_003BCFB0(0x1ADF, 0x80);
        func_L01_00452E70(*(u8 **)(p + 0x5D0), a);
    }
    func_L01_00441FB8((s32)a, 2, -1);
    func_003C26C8(a);
    return 1;
}
/* localdecomp:end func_L08_00399038 */
