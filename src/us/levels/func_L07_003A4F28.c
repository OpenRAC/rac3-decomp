#include "common.h"

/* localdecomp:start func_L07_003A4F28 */
#include "vu0.h"
__asm__(".extern D_L07_001DEF40, 4");
extern s32 D_L07_001DEF40;
extern u8 *D_L07_001ECC80[];
extern s32 D_00142660[];
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
extern s32 func_L07_003B9310(s32, s32);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern s32 func_00388398(void *);
extern void func_L07_003A5720(void *);
extern s32 func_L01_004A72A8(s32, s32, u8 *, s32);
extern void func_L01_004A6D70(s32, void *);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);
extern s32 func_003CF790(void *, s32, void *, s32, f32);
extern f32 func_00388730(void *, void *);
extern void func_L01_00443938(u8 *, u8 *, s32, void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern void func_L01_00463938(void *, void *, s32, f32, f32);
extern u8 *func_L01_0046CA58(void *, void *, s32, s32, s32, f32, f32, s32, s32, s32, s32, s32, f32);
extern void func_L07_003A57F0(u8 *, s32);
extern void func_L01_0044EB38(void *, void *, s32, s32, f32);

void func_L07_003A4F28(u8 *self) {
    vu0_v4 velocity;
    vu0_v4 v;
    u8 *s = *(u8 **)(self + 0x68);
    s32 i;
    s32 count;
    f32 size;
    f32 step;

    if (self[0x20] != 0 && *(s32 *)(s + 0x74) != 0 && !func_L07_003B9310(*(s32 *)(s + 0x74), *(s32 *)(s + 0x70))) return;
    if (self[0x20] == 3 && *(s16 *)(s + 0x7C) == 0) func_L01_00441FB8(self, 2, -1);
    if (self[0x20] == 2 && *(s16 *)(s + 0x78) == 0) func_L01_00441FB8(self, 4, -1);
    switch (self[0x20]) {
    case 0:
        self[0x30] = 0xFF;
        *(s16 *)(self + 0x32) = 0x40;
        self[0x31] = 0;
        *(s32 *)(s + 0x74) = 0;
        *(s32 *)(s + 0x70) = -1;
        func_L01_00441FB8(self, 1, -1);
        break;
    case 1:
        if (*(s32 *)(s + 0x70) != -1) func_L01_00441FB8(self, 2, -1);
        break;
    case 2:
        if (func_L01_00452EC8(self)) *(s32 *)(s + 0x84) = *(s16 *)(s + 0x78);
        if (func_00388398(s + 0x84)) func_L01_00441FB8(self, 4, -1);
        else if (*(s32 *)(s + 0x84) < 40 && (D_L07_001DEF40 & 3) == (((s32)self >> 8) & 3)) func_L07_003A5720(self);
        break;
    case 4:
        if (func_L01_00452EC8(self)) {
            *(s32 *)(s + 0x84) = *(s16 *)(s + 0x7A);
            func_L01_004A72A8(0, 4, self, 0x197E);
        }
        if (*(s32 *)(s + 0x84) < 3) func_L07_003A5720(self);
        if (func_00388398(s + 0x84)) {
            func_L01_004A6D70(0, self);
            func_L01_00441FB8(self, 3, -1);
            break;
        }
        *(vu0_q *)&v = 0;
        v.x = func_L01_00440918(0.0f, 0.02f);
        v.y = func_L01_00440918(0.0f, 0.02f);
        v.z = func_0037E250(0.06666667f, 0.10000001f);
        *(vu0_q *)&velocity = *(vu0_q *)&v;
        size = func_0037E250(0.6f, 1.2f) * 210000.0f;
        step = size * 0.25f;
        for (i = 0; i < 9; i++) {
            func_L01_0046C468(s + 0xA0 + i * 16, &velocity, func_0037E208(8, 16), 0x7F7F7F, 1, 0x7F, 0,
                              size, step, 0, -0.003f);
        }
        count = func_003CF790(self + 0x10, 0, self, 0, 2.9f);
        for (i = 0; i < count; i++) {
            __asm__ __volatile__(
                "lqc2 $vf2, 16(%1)\n"
                "lqc2 $vf1, 16(%2)\n"
                "vsub.xyz $vf1, $vf1, $vf2\n"
                "sqc2 $vf1, %0\n"
                : "=m"(v) : "r"(self), "r"(D_L07_001ECC80[i]) : "memory");
            if (v.z >= 0.0f && v.z < 1.0f && fabs_asm(func_00388730(&v, self + 0xC0)) < 2.0f &&
                fabs_asm(func_00388730(&v, self + 0xD0)) < 2.0f) {
                func_L01_00443938(D_L07_001ECC80[i], self, 0x10001, D_L07_001ECC80[i] + 0x10, D_L07_001D66B0,
                                  (f32)D_00142660[2] * 0.25f);
            }
        }
        if (func_0037E1D8(4) == 0) func_L01_00463938(s + 0xA0 + func_0037E1D8(9) * 16, &velocity, 0, -1.0f, 0.0f);
        for (i = 0; i < 9; i++) {
            func_L01_0046CA58(s + 0xA0 + i * 16, 0, 0x20204080, -1, 1, 315000.0f, 1.0f, 3, 0, -1, 0, 0, 1.0f);
        }
        break;
    case 3:
        if (func_L01_00452EC8(self)) {
            *(s32 *)(s + 0x84) = *(s16 *)(s + 0x7C);
            if (*(s32 *)(s + 0x84) < 0) *(s32 *)(s + 0x84) = 0;
            func_L07_003A57F0(self, 1);
        }
        if (func_00388398(s + 0x84)) func_L01_00441FB8(self, 2, -1);
        else if (*(s32 *)(s + 0x84) + *(s16 *)(s + 0x78) < 40 && (D_L07_001DEF40 & 3) == (((s32)self >> 8) & 3)) func_L07_003A5720(self);
        break;
    case 5:
    default:
        break;
    }
    if (self[0x31]) func_L01_0044EB38(self, s + 0x154, 0x80A0A0A0, 0x80202020, 0.122173056f);
    func_L07_003A57F0(self, 0);
}
/* localdecomp:end func_L07_003A4F28 */
