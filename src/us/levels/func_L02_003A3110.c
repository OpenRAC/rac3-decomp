#include "common.h"

/* NTSC-U counterpart of func_L02_003A5030 (src/levels/shared/L02_003A5030.c) */
/* localdecomp:start func_L02_003A3110 */
extern s32 func_00388398(void *);
extern s32 func_003883C8(void *);
extern void func_L01_0044EB78(void *, void *, s32, s32, f32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_L01_0044B860(void *, void *, void *, f32, f32, f32);
extern void func_L02_003A1AB8(void *, void *, f32);
extern u8 D_L02_001E1380[];
extern f32 D_L02_001DDD64, D_L02_001DDD68;
__asm__(".extern D_L02_001DDD64, 4");
__asm__(".extern D_L02_001DDD68, 4");

void func_L02_003A3110(u8 *a0)
{
    u8 *p = *(u8 **)(a0 + 0x68);
    u16 value;

    func_00388398(p + 0x2D0);
    func_003883C8(p + 0x2D4);
    value = *(u16 *)(a0 + 0x96);
    if (value <= 0xFFFEu) {
        *(u16 *)(a0 + 0x96) = value + 1;
    }
    func_L01_0044EB78(a0, p + 0x240, 1, 1, 2.5f);
    if (a0[0x31] != 0) {
        if (func_L01_0040C018(D_L02_001E1380, a0 + 0x10) < 576.0f) {
            func_L01_00444188(a0);
            a0[0x6F] = 0x16;
        }
    }
    func_L01_0044B860(a0, p + 0x308, p + 0x30C, D_L02_001DDD64, D_L02_001DDD68 * 0.017453292f * 0.0166666675f, -1.0f);
    func_L02_003A1AB8(a0, p + 0x110, *(f32 *)(p + 0x124));
}
/* localdecomp:end func_L02_003A3110 */
