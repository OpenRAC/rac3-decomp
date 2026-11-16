#include "common.h"

/* NTSC-U counterpart of func_L20_003F4CC8 (src/levels/20_final_boss/L20_003F4CC8.c) */
/* localdecomp:start func_L20_003F2B60 */
#include "vu0.h"
extern s32 D_L20_001DEC30;
extern void func_L01_004A6DF8(void *, s32);
extern s32 func_L01_00452F60(void *);
extern void func_00388830(void *, void *, f32);
void func_L20_003F2B60(u8 *self) {
    s32 *p;
    u8 *q;
    vu0_v4 d;
    p = *(s32 **)(self + 0x68);
    if (*p != 0 && self[0x20] == 0) {
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & ~0x1000;
        *(s32 *)(self + 0x98) = 0;
        func_L01_004A6DF8(self, 1);
        self[0x20] = 1;
    }
    if (self[0x20] == 1 && D_L20_001DEC30 != 0) {
        q = *(u8 **)(self + 0x24);
        *(u16 *)(self + 0x34) &= ~0x41;
        *(u16 *)(self + 0x34) |= *(u16 *)(q + 0x44) & 0x1000;
        *(s32 *)(self + 0x98) = *(s32 *)(q + 0x10);
        *p = 0;
        self[0x20] = 0;
    }
    if (func_L01_00452F60(self) != 0) {
        self[0x20] = 2;
    }
    if (self[0x20] == 2) {
        func_00388830(&d, self + 0xC0, -0.13333334028720856f);
        vec_add_ba(self + 0x10, &d, self + 0x10);
        if (++*(u16 *)(self + 0x96) > 60) {
            self[0x20] = 3;
        }
    }
    if (self[0x20] == 3 && D_L20_001DEC30 != 0) {
        self[0x20] = 4;
    }
    if (self[0x20] == 4) {
        func_00388830(&d, self + 0xC0, 0.13333334028720856f);
        vec_add_ba(self + 0x10, &d, self + 0x10);
        if (--*(u16 *)(self + 0x96) == 0) {
            self[0x20] = 5;
        }
    }
}
/* localdecomp:end func_L20_003F2B60 */
