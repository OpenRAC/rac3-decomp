#include "common.h"

/* NTSC-U counterpart of func_L08_0039E658 (src/levels/08_aquatos/L08_0039D188.c); cf. func_L28_0039E8B8 */
#include "vu0.h"

/* localdecomp:start func_L08_0039CB58 */
typedef int u128_0039CB58 __attribute__((mode(TI)));
extern void func_00388BD0(void *, void *);
extern f32 func_0037E2A8(void);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_004A6DF8(void *, s32);
extern f32 func_003BE7F0(void *, f32, s32, s32);

s32 func_L08_0039CB58(u8 *self) {
    u8 *t;
    f32 f;
    f32 g;
    f32 h;
    u8 *pos;

    t = *(u8 **)(self + 0x68);
    pos = self + 0x10;
    *(u128_0039CB58 *)(t + 0x1A0) = *(u128_0039CB58 *)pos;
    if (*(s16 *)(self + 0xB2) == 0) {
        *(s32 *)(t + 0x1C0) = -1;
        *(s32 *)(t + 0x1C8) = -1;
    }
    *(s32 *)(self + 0xF0) = 0;
    *(s32 *)(self + 0xF4) = 0;
    func_00388BD0(self + 0xC0, self + 0xF0);
    f = func_0037E2A8();
    *(f32 *)(t + 0x70) = 0.5f;
    *(f32 *)(t + 0x1D0) = f;
    *(f32 *)(t + 0x74) = 0.25f;
    *(f32 *)(t + 0x78) = 1.25f;
    *(f32 *)(t + 0x7C) = 1.5f;
    *(f32 *)(t + 0x80) = 1.57079637f;
    *(f32 *)(t + 0xA0) = 0.34906584f;
    *(f32 *)(t + 0x9C) = 0.00272222236f;
    func_L01_00458A70(self, 0.00444444455f, 0.0666666701f, 0.00698131742f, 0.209439531f);
    t[0x58] = 0x14;
    t[0x5A] = 0xE;
    if (*(s16 *)(t + 0x34) == 0) {
        *(s16 *)(t + 0x34) = 1;
        *(f32 *)(t + 0x30) = 1.0f;
    }
    if (t[0x44] == 0) {
        t[0x44] = 5;
        t[0x45] = 5;
        t[0x46] = 5;
    }
    *(f32 *)(t + 0x40) = 0.5f;
    t[0x3F] = 0;
    t[0x39] = 1;
    t[0x64] = 1;
    t[0x3E] = 1;
    func_L01_00441FB8(self, 3, 0);
    if (self[0x43] != 1) {
        func_003BE4F0(self, 1, 0, 0);
    }
    if (*(s32 *)(t + 0x1C0) != -1 || *(s32 *)(t + 0x1C8) != -1) {
        func_L01_00441FB8(self, 0xA, 4);
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(self + 0x98) = 0;
        func_L01_004A6DF8(self, 1);
    } else if (*(s32 *)(t + 0x1C4) == 1) {
        g = func_003BE7F0(pos, 0.5f, 0, 0);
        h = *(f32 *)(self + 0x18);
        if (3.0f < h - g) {
            g = h;
        }
        *(f32 *)(self + 0x18) = g - 1.0f;
        *(s32 *)(self + 0x98) = 0;
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
        func_L01_004A6DF8(self, 1);
    }
    return 0;
}
/* localdecomp:end func_L08_0039CB58 */
