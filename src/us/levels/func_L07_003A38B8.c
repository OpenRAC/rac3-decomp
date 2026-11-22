#include "common.h"

/* NTSC-U counterpart of func_L07_003A5078, with regional timing constants. */
/* localdecomp:start func_L07_003A38B8 */
extern s32 func_L07_003C01A8(void);
extern f32 func_L07_003C01F0(s32);
extern void func_L01_00442F20(void *, s32, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L07_003A3E18(void *);
extern void func_L07_003A3EB0(void *);

void func_L07_003A38B8(u8 *self) {
    u8 *v = *(u8 **)(self + 0x68);
    s32 mode = func_L07_003C01A8();
    u8 *p = v + 0x30;
    f32 factor = func_L07_003C01F0(mode);
    *(s16 *)(p + 4) = *(s16 *)(v + 0x34) * factor;
    *(f32 *)(v + 0x30) = *(s16 *)(p + 4);
    p[0x14] = v[0x44] * factor;
    p[0x15] = v[0x45] * factor;
    p[0x16] = v[0x46] * factor;
    if (mode == 1 || mode == 3) func_L01_00442F20(self, 0x1D8C, 0x195E);
    p[0x28] = 20;
    p[0x2A] = 14;
    *(f32 *)(p + 0x10) = 1.25f;
    p[0xF] = 0;
    p[9] = 1;
    v[0x80] = 5;
    v[0x240] = 0xB0;
    v[0x241] = 0x50;
    v[0x242] = 0x80;
    v[0x244] = v[0x243] = 0xE0;
    v[0xB8] = 255;
    *(f32 *)(v + 0x120) = 1.0f;
    *(s32 *)(v + 0x124) |= 1;
    *(f32 *)(v + 0x150) = 0.65f;
    *(f32 *)(v + 0xA4) = *(f32 *)(v + 0xA0) = 0.5f;
    *(f32 *)(v + 0x154) = *(f32 *)(v + 0xAC) = 0.15f;
    *(f32 *)(v + 0x15C) = *(f32 *)(v + 0x158) = 0.5f;
    *(f32 *)(v + 0x160) = 3.1415927f;
    *(f32 *)(v + 0x180) = 0.7853982f;
    *(f32 *)(v + 0x17C) = 0.0027222224f;
    *(f32 *)(v + 0x184) = 0.2f;
    func_L01_00458A70(self, 0.0013888889f, 0.03666667f, 0.0034906587f, 0.104719765f);
    v[0x28D] = 5;
    *(s32 *)(v + 0x498) = 0;
    *(s32 *)(v + 0x264) = 0;
    *(s32 *)(v + 0x494) = 0;
    *(void **)(v + 0x274) = func_L07_003A3EB0;
    *(void **)(v + 0x278) = func_L07_003A3E18;
    *(s16 *)(v + 0x27C) = -1;
    v[0x28F] = 7;
    *(s32 *)(v + 0x260) = 0;
    func_L07_003A3E18(self);
}
/* localdecomp:end func_L07_003A38B8 */
