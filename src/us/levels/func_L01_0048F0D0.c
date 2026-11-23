#include "common.h"

/* NTSC-U counterpart of func_L01_004928C8 (src/levels/shared/L01_004928C8.c): 8 -> 10 */
extern void *func_003AED40(s32);
extern s32 func_L01_00512D70(s32, s32);
extern s32 func_0037DF98(s32);
extern void func_L01_0048F0D0();

/* localdecomp:start func_L01_0048F0D0 */
extern s32 D_L01_001D8E9C;
__asm__(".extern D_L01_001D8E9C, 4");
extern s32 D_L01_001D8EA8_0048F0D0;
extern f32 D_L01_001DC128;
extern u8 D_L01_002EB538[];
extern void func_L01_0048F7E8(void);
extern void func_00389920(s32);
extern s32 func_0037DF98(s32);
extern s32 func_00389D18(s32, s32, f32);
extern f32 func_003BEB48(f32, f32, f32);
extern void func_003B3DB8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_003E3A80(s32, s32, s32, f32, f32, f32, f32);
extern void func_003E29B8(s32, s32);
extern void func_003E30C8(s32, s32);
extern void func_L01_00513548(s32, f32, f32);
extern void func_L01_0048F508(void *);
extern void func_003E2DE0(s32, s32);
extern void func_003E31A8(s32, void *);
extern s32 func_L01_00512D70(s32, s32);
extern void func_003E3250(s32, s32, s32);
extern void func_L01_0048F9E8(void);

/* same shape as func_L01_0049D5E8 in L01_0049D5E8.c */
void func_L01_0048F0D0(void) {
    s32 scale = 0;
    f32 width;
    f32 ratio;
    f32 maxWidth = 0.49f;
    f32 low = 6.0f;
    f32 high = 11.0f;
    f32 zoom = 0.0f;
    f32 zero = 0.0f;
    D_L01_001D8E9C = -1;
    D_L01_001D8EA8_0048F0D0 = 0;
    func_L01_0048F7E8();
    func_00389920(0);
    ratio = (f32)func_00389D18(func_0037DF98(0x162), -1, 1.2f) / D_L01_001DC128;
    if (ratio > maxWidth) {
        scale = 1;
        zoom = 0.58800006f / ratio;
        ratio = maxWidth;
    }
    width = func_003BEB48(low, high, (ratio - zero) / maxWidth);
    if (width > high) width = high;
    else if (width < low) width = low;
    func_003B3DB8(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005,
        0xD0008, func_0037DF98(0x162), 0xD0006, 0x124, 0xD0007, 0xCD5, width);
    func_003E3A80(0xD0009, func_0037DF98(0x1B80), 0x8066CCFF, 0.035f, 0.5f, 1.0f, 1.0f);
    func_003E29B8(0xD0009, 1);
    func_003E30C8(0xD000B, 0xD0009);
    if (scale) func_L01_00513548(0xD0005, zoom, zoom);
    func_L01_0048F508(D_L01_002EB538);
    func_003E2DE0(0x11, 0x1C0000);
    func_003E31A8(0x1C0003, func_003AED40(0));
    func_L01_00512D70(0x1C0003, 0);
    func_003E3250(0x1C0003, 1, 10);
    func_L01_0048F9E8();
}
/* localdecomp:end func_L01_0048F0D0 */
