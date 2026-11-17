#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of PAL func_L07_00352758. */
/* localdecomp:start func_L07_00351A58 */
void func_L07_00351A58(u8 *self)
{
    extern u8 D_L07_001E1EC0[];
    extern s32 func_L01_0044FCD0(u8 *, u8 *, s32, s32, s32);
    extern void func_L07_00332CB8(s32, f32, f32);
    extern void func_L07_00333E48(u8 *);
    extern void func_L01_00443938(u8 *, u8 *, s32, void *, void *, f32);
    extern void func_L07_00330E70(u8 *);
    extern void func_L07_00330A18(u8 *);
    extern void func_L01_00402498(void *, void *);
    extern void func_L07_00353110(u8 *);
    extern void func_003BDA38(u8 *, s32, void *);
    extern f32 func_00388A28(f32, f32);
    extern f32 func_003893C8(f32, f32);
    extern f32 func_00388800(void *, void *);
    extern void func_L01_0044B5C8(u8 *, u8 *, s32, f32, f32);
    extern void func_L07_0044F0E8(u8 *, s32, u8 *, f32);
    extern f32 func_L01_0040C018(void *, void *);
    extern void func_L01_00444188(u8 *);
    extern void func_L01_00443648(u8 *, u8 *, s32, f32, f32, f32, s32, s32, s32);
    vu0_v4 pos;
    u8 *p = *(u8 **)(self + 0x68);
    f32 health, angle;
    if (self[0x20] == 1) return;
    health = *(f32 *)(p + 0x30);
    if (func_L01_0044FCD0(self, p + 0x70, 0, 0, 0)) {
        func_L07_00332CB8(*(s32 *)(p + 0x240), health, *(f32 *)(p + 0x30));
        p[0x467] = 0;
        func_L07_00333E48(self);
    }
    if (*(s32 *)(p + 0x228) == 1) {
        qzero(&pos);
        func_L01_00443938(self, self, 0x10000, &pos, &pos, *(s16 *)(p + 0x34));
    } else if (p[0x5E] || p[0x60] || p[0x3E] == 2) {
        func_L07_00330E70(self);
        return;
    }
    func_L07_00330A18(self);
    *(f32 *)(p + 0x460) -= -0.1f;
    if (*(f32 *)(p + 0x460) < 0.0f) *(f32 *)(p + 0x460) += 1.0f;
    func_L01_00402498(func_L07_00353110, self);
    if (*(s16 *)(p + 0x144) == 1) {
        func_003BDA38(self, 9, &pos);
        angle = func_00388A28(*(f32 *)(*(u8 **)(p + 0x140) + 0x10) - pos.x,
                             *(f32 *)(*(u8 **)(p + 0x140) + 0x14) - pos.y);
        *(f32 *)(p + 0x2C8) = func_003893C8(angle, *(f32 *)(self + 0xF8));
        if (*(f32 *)(p + 0x2C8) > 0.78539819f) *(f32 *)(p + 0x2C8) = 0.78539819f;
        else if (*(f32 *)(p + 0x2C8) < -0.78539819f) *(f32 *)(p + 0x2C8) = -0.78539819f;
        angle = func_00388800(&pos, *(u8 **)(p + 0x140) + 0x10);
        *(f32 *)(p + 0x2C4) = -func_00388A28(angle, *(f32 *)(*(u8 **)(p + 0x140) + 0x18) - pos.z);
        if (*(f32 *)(p + 0x2C4) > 0.52359879f) *(f32 *)(p + 0x2C4) = 0.52359879f;
        else if (*(f32 *)(p + 0x2C4) < -0.52359879f) *(f32 *)(p + 0x2C4) = -0.52359879f;
    }
    func_L01_0044B5C8(self, p + 0x260, 9, 0.03f, 0.3f);
    func_L07_0044F0E8(self, 10, p + 0x2E0, 2.5f);
    if (self[0x31] && func_L01_0040C018(D_L07_001E1EC0, self + 0x10) < 576.0f) {
        func_L01_00444188(self);
        self[0x6F] = 22;
    }
    func_L01_00443648(self, self + 0x10, 0x8000000, 0.8f, 1.0f, 1.0f, 0, 1, 0);
}
/* localdecomp:end func_L07_00351A58 */
