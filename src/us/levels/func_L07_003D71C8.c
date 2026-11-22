#include "common.h"

/* NTSC-U counterpart of func_L07_003D8E28. */
/* localdecomp:start func_L07_003D71C8 */
void func_L07_003D71C8(s32 self) {
    extern void func_L07_003D7448(s32);
    extern s32 func_L07_003D79D0(u8 *);
    extern void func_L01_00441FB8(s32, s32, s32);
    extern void func_L07_003D7638(s32);
    extern void func_L07_003D76D0(s32);
    u8 *v;
    func_L07_003D7448(self);
    v = *(u8 **)(self + 0x68);
    switch (*(u8 *)(self + 0x20)) {
    case 1: break;
    case 2:
        if (*(f32 *)(v + 0x2C) != 0.0f) {
            *(f32 *)(v + 0x2C) -= 0.0149999997f;
            if (*(f32 *)(v + 0x2C) <= 0.0f) *(f32 *)(v + 0x2C) = 0.0f;
        }
        if (func_L07_003D79D0((u8 *)self)) func_L01_00441FB8(self, 7, -1);
        func_L07_003D7638(self);
        break;
    case 3:
        if (func_L07_003D79D0((u8 *)self)) func_L01_00441FB8(self, 6, -1);
        break;
    case 4:
        *(f32 *)(v + 0x2C) += 0.0149999997f;
        if (*(f32 *)(v + 0x2C) > 1.0f) {
            *(f32 *)(v + 0x2C) = 1.0f;
            if (v[0x3C]) func_L01_00441FB8(self, 5, -1);
            else func_L01_00441FB8(self, 3, -1);
        }
        func_L07_003D7638(self);
        break;
    case 5:
        *(f32 *)(v + 0x28) += 0.00999999978f;
        if (*(f32 *)(v + 0x28) > 1.0f) {
            *(f32 *)(v + 0x28) = 1.0f;
            func_L01_00441FB8(self, 2, -1);
        }
        func_L07_003D76D0(self);
        break;
    case 6:
        *(f32 *)(v + 0x2C) -= 0.0149999997f;
        if (*(f32 *)(v + 0x2C) <= 0.0f) {
            *(f32 *)(v + 0x2C) = 0.0f;
            func_L01_00441FB8(self, 1, -1);
        }
        func_L07_003D7638(self);
        break;
    case 7:
        if (*(f32 *)(v + 0x2C) != 0.0f) {
            *(f32 *)(v + 0x2C) -= 0.0149999997f;
            if (*(f32 *)(v + 0x2C) <= 0.0f) *(f32 *)(v + 0x2C) = 0.0f;
            func_L07_003D7638(self);
        }
        *(f32 *)(v + 0x28) += 0.00999999978f;
        if (*(f32 *)(v + 0x28) >= 2.0f && *(f32 *)(v + 0x2C) <= 0.0f) {
            *(f32 *)(v + 0x28) = 0.0f;
            func_L01_00441FB8(self, 1, -1);
        }
        func_L07_003D76D0(self);
        break;
    }
}
/* localdecomp:end func_L07_003D71C8 */
