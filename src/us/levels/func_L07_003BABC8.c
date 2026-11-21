#include "common.h"

/* NTSC-U counterpart of func_L07_003BC4D8 (src/levels/07_annihilation_nation/L07_003BC4D8.c): 0.00502655 -> 0.00349066; 0.00392 -> 0.00272222; 0.125664 -> 0.10472 */
/* localdecomp:start func_L07_003BABC8 */
typedef int Q_003BC4D8 __attribute__((mode(TI)));
extern void func_L01_00442E08(void *, s32);
extern s32 func_L07_003C01A8(void);
extern f32 func_L07_003C01F0(s32);
extern void func_L01_00442F20(void *, s32, s32);
extern void func_L07_003BB470(void *);
/* localdecomp:start func_L07_003BABC8 */
void func_L07_003BABC8(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    u8 *sub;
    u8 *g;
    u8 *other;
    s32 mode;
    f32 scale;
    func_L01_00442E08(obj, 0x19D2);
    sub = p + 0x120;
    mode = func_L07_003C01A8();
    scale = func_L07_003C01F0(mode);
    *(s16 *)(sub + 4) = (s16)(*(s16 *)(p + 0x124) * scale);
    *(f32 *)(p + 0x120) = *(s16 *)(sub + 4);
    sub[0x14] = (u8)(p[0x134] * scale);
    sub[0x15] = (u8)(p[0x135] * scale);
    sub[0x16] = (u8)(p[0x136] * scale);
    if (mode == 1 || mode == 3) func_L01_00442F20(obj, 0x1D88, 0x19D2);
    sub[0x28] = 20;
    sub[0x2A] = 14;
    *(f32 *)(sub + 0x10) = 0.25f;
    sub[9] = 0;
    *(Q_003BC4D8 *)(p + 0x240) = *(Q_003BC4D8 *)(obj + 0x10);
    *(Q_003BC4D8 *)(p + 0x250) = *(Q_003BC4D8 *)(obj + 0xF0);
    other = p + 0x160;
    other[0x10] = 7;
    other[0x48] = 255;
    other[0x11] = 255;
    other[0x12] = 255;
    g = p + 0x30;
    *(f32 *)(p + 0x30) = 0.8f;
    *(u32 *)(g + 0x38) |= 0x404;
    *(f32 *)(g + 4) = -0.3f;
    *(f32 *)(g + 0x34) = 0.3f;
    *(f32 *)(g + 0x2C) = 0.00272222236f;
    *(f32 *)(g + 0xB4) = 0.104719765f;
    *(f32 *)(g + 0x14) = 0.00349065871f;
    *(f32 *)(g + 0x18) = 0.00349065871f;
    *(s32 *)(g + 0xEC) = 0;
    obj[0x62] = 0;
    func_L07_003BB470(obj);
}
/* localdecomp:end func_L07_003BABC8 */
