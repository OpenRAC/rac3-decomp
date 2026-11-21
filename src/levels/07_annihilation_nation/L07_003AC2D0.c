#include "common.h"

/* localdecomp:start func_L07_003AC2D0 */
extern s32 func_L07_003C1AF8(void);
extern f32 func_L07_003C1B40(s32);
extern void func_L01_00446058(void *, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
void func_L07_003ACA00(void *);
void func_L07_003ACA48(void *);

void func_L07_003AC2D0(u8 *self) {
    u8 *v = *(u8 **)(self + 0x68);
    s32 mode = func_L07_003C1AF8();
    u8 *p = v + 0x30;
    f32 factor = func_L07_003C1B40(mode);
    *(s16 *)(p + 4) = *(s16 *)(v + 0x34) * factor;
    *(f32 *)(v + 0x30) = *(s16 *)(p + 4);
    p[0x14] = v[0x44] * factor;
    p[0x15] = v[0x45] * factor;
    p[0x16] = v[0x46] * factor;
    if (mode == 1 || mode == 3) func_L01_00446058(self, 0x1D89, 0x19BE);
    p[0x28] = 20;
    p[0x2A] = 14;
    *(f32 *)(p + 0x10) = 1.0f;
    p[0xF] = 0;
    p[9] = 0;
    *(f32 *)(v + 0xA0) = 1.0f;
    *(f32 *)(v + 0xA4) = 0.5f;
    *(f32 *)(v + 0xAC) = 0.15f;
    *(f32 *)(v + 0x158) = 0.5f;
    v[0xB8] = 255;
    v[0x80] = 5;
    *(f32 *)(v + 0x120) = 1.0f;
    *(s32 *)(v + 0x124) |= 1;
    *(f32 *)(v + 0x150) = 0.9749999642372131f;
    *(f32 *)(v + 0x154) = 0.15f;
    *(f32 *)(v + 0x15C) = 0.5f;
    *(f32 *)(v + 0x160) = 3.1415927f;
    *(f32 *)(v + 0x180) = 0.7853982f;
    *(f32 *)(v + 0x17C) = 0.003920000046491623f;
    *(s32 *)(v + 0x23C) = 0;
    *(void (**)(void *))(v + 0x244) = func_L07_003ACA48;
    *(void (**)(void *))(v + 0x248) = func_L07_003ACA00;
    v[0x25D] = 0;
    *(s16 *)(v + 0x24C) = -1;
    v[0x25F] = 7;
    *(s16 *)(v + 0x564) = 0;
    func_L01_0045BD78(self, 0.0014000000664964318f, 0.07000000774860382f, 0.005026548635214567f, 0.12566371262073517f);
    func_L07_003ACA00(self);
}
/* localdecomp:end func_L07_003AC2D0 */

INCLUDE_ASM("asm/levels", func_L07_003AC500);
