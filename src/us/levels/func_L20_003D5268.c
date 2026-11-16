#include "common.h"

/* NTSC-U counterpart of func_L20_003D6D18 (src/levels/20_final_boss/L20_003D6BF8.c) */
/* localdecomp:start func_L20_003D5268 */
extern s32 func_00388398(void *);
extern s32 func_003883C8(void *);
extern void func_L01_0044EB78(void *, void *, s32, s32, f32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern u8 D_L20_001E2E80_003D5268[];

void func_L20_003D5268(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);

    func_00388398(v + 0x2D0);
    func_003883C8(v + 0x2D4);
    func_00388398(v + 0x664);
    if (*(u16 *)(a0 + 0x96) < 0xFFFF) {
        *(u16 *)(a0 + 0x96) += 1;
    }
    func_L01_0044EB78(a0, v + 0x240, 10, 1, 2.5f);
    if (a0[0x31] != 0) {
        if (func_L01_0040C018(D_L20_001E2E80_003D5268, a0 + 0x10) < 8100.0f) {
            func_L01_00444188(a0);
            a0[0x6F] = 0x54;
        }
    }
    func_L01_0044B5C8(a0, v + 0x330, 4, 0.03f, 0.3f);
    func_L01_0044B5C8(a0, v + 0x3B0, 5, 0.03f, 0.3f);
    func_L01_0044B5C8(a0, v + 0x430, 6, 0.03f, 0.3f);
    func_L01_0044B5C8(a0, v + 0x4B0, 7, 0.03f, 0.3f);
    func_L01_0044B5C8(a0, v + 0x530, 8, 0.03f, 0.3f);
}
/* localdecomp:end func_L20_003D5268 */
