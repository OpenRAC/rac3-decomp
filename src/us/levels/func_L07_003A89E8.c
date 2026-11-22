#include "common.h"

/* NTSC-U counterpart of func_L07_003AA228 (src/levels/07_annihilation_nation/L07_003A9DB0.c): 0.00392 -> 0.00272222; 0.0014 -> 0.000972222; 0.07 -> 0.0583333; 0.00502655 -> 0.00349066; 0.125664 -> 0.10472 */
/* localdecomp:start func_L07_003A89E8 */
extern s32 func_L07_003C01A8(void);
extern f32 func_L07_003C01F0(s32);
extern void func_L01_00442F20(void *, s32, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
void func_L07_003A9180(void *);
void func_L07_003A91C8(void *);

void func_L07_003A89E8(u8 *self) {
    u8 *v = *(u8 **)(self + 0x68);
    s32 mode = func_L07_003C01A8();
    u8 *p = v + 0x30;
    f32 factor = func_L07_003C01F0(mode);
    *(s16 *)(p + 4) = *(s16 *)(v + 0x34) * factor;
    *(f32 *)(v + 0x30) = *(s16 *)(p + 4);
    p[0x14] = v[0x44] * factor;
    p[0x15] = v[0x45] * factor;
    p[0x16] = v[0x46] * factor;
    if (mode == 1 || mode == 3) func_L01_00442F20(self, 0x1D8A, 0x19BD);
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
    *(f32 *)(v + 0x17C) = 0.00272222236f;
    *(s32 *)(v + 0x23C) = 0;
    *(void (**)(void *))(v + 0x244) = func_L07_003A91C8;
    *(void (**)(void *))(v + 0x248) = func_L07_003A9180;
    v[0x25D] = 1;
    *(s16 *)(v + 0x24C) = -1;
    v[0x25F] = 7;
    func_L01_00458A70(self, 0.000972222246f, 0.0583333373f, 0.00349065871f, 0.104719765f);
    func_L07_003A9180(self);
}
/* localdecomp:end func_L07_003A89E8 */
