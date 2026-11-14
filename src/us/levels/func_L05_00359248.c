#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L05_0035A380 (src/levels/shared/L05_0035A380.c) */
/* localdecomp:start func_L05_00359248 */
typedef int s128 __attribute__((mode(TI)));

extern void func_00388BD0(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE418(void *, s32, s32);

void func_L05_00359248(u8 *self, s128 *pos, s32 a2, f32 f12) {
    f32 v[4] __attribute__((aligned(16)));
    u8 *s;

    qzero(v);
    v[2] = f12;
    s = *(u8 **)(self + 0x68);
    *(s128 *)(self + 0x10) = *pos;
    *(s128 *)(self + 0xF0) = *(s128 *)v;
    func_00388BD0(self + 0xC0, v);
    *(s128 *)(*(u8 **)(s + 0x3EC) + 0x10) = *pos;
    *(s128 *)(*(u8 **)(s + 0x3EC) + 0xF0) = *(s128 *)v;
    func_00388BD0(*(u8 **)(s + 0x3EC) + 0xC0, v);
    *(u16 *)(self + 0x34) &= 0xFFBE;
    *(u16 *)(self + 0x34) |= *(u16 *)(*(u8 **)(self + 0x24) + 0x44) & 0x1000;
    *(s32 *)(self + 0x98) = *(s32 *)(*(u8 **)(self + 0x24) + 0x10);
    *(u16 *)(*(u8 **)(s + 0x3EC) + 0x34) &= 0xFFBE;
    *(u16 *)(*(u8 **)(s + 0x3EC) + 0x34) |= *(u16 *)(*(u8 **)(*(u8 **)(s + 0x3EC) + 0x24) + 0x44) & 0x1000;
    *(s32 *)(*(u8 **)(s + 0x3EC) + 0x98) = *(s32 *)(*(u8 **)(*(u8 **)(s + 0x3EC) + 0x24) + 0x10);
    (*(u8 **)(s + 0x3EC))[0x20] = 0xC;
    *(u16 *)(*(u8 **)(s + 0x3EC) + 0x34) &= 0xFFFD;
    *(u16 *)(*(u8 **)(s + 0x3EC) + 0x34) &= 0xFFFB;
    *(f32 *)(s + 0x3B0) = 0.5f;
    *(f32 *)(self + 0x2C) = *(f32 *)(*(u8 **)(self + 0x24) + 0x24) * *(f32 *)(s + 0x3B0);
    *(f32 *)(*(u8 **)(s + 0x3EC) + 0x2C) = *(f32 *)(*(u8 **)(*(u8 **)(s + 0x3EC) + 0x24) + 0x24) * *(f32 *)(s + 0x3B0);
    *(s32 *)(s + 0x3F0) = a2;
    func_003886E8(s + 0x110, self + 0xC0, 0.06666667f);
    *(s32 *)(s + 0x100) = 0;
    *(s32 *)(s + 0xF8) = 0;
    *(s32 *)(s + 0xFC) = 0;
    *(f32 *)(s + 0x118) = 0.033333335f;
    qzero(s + 0xC0);
    *(s32 *)(s + 0x148) = -1;
    func_L01_00441FB8(self, 8, 5);
    func_003BE418(self, 0x11, 1);
    func_003BE418(*(u8 **)(s + 0x3EC), 0x11, 1);
}
/* localdecomp:end func_L05_00359248 */
