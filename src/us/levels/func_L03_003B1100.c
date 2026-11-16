#include "common.h"

/* NTSC-U counterpart of func_L03_003B2C30 (src/levels/shared/L03_003B2C30.c) */
/* localdecomp:start func_L03_003B1100 */
typedef int u128_003B2C30 __attribute__((mode(TI)));
extern u8 D_00142700[];
extern void func_003BD360(void *);
extern void func_00388BD0(void *, void *);
extern void func_L03_003B1308(u8 *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern f32 func_00389468(f32, f32);

void func_L03_003B1100(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 0:
        if (D_00142700[0] != 0) {
            func_003BD360(m);
            return;
        }
        func_00388BD0(m + 0xC0, m + 0xF0);
        *(u128_003B2C30 *)(v + 0x20) = *(u128_003B2C30 *)(m + 0xC0);
        *(f32 *)(v + 0xC) = *(f32 *)(m + 0xF8);
        func_L03_003B1308(m);
        func_L01_00441FB8(m, 1, -1);
        break;
    case 1:
        func_L01_00445758(m + 0xF8, *(f32 *)(v + 0xC), v, 0.000872664677445f, 0.00174532935489f, 0.122173056006f, 0);
        func_00388BD0(m + 0xC0, m + 0xF0);
        *(s32 *)(v + 4) = 0;
        break;
    case 2:
        func_L01_00445758(m + 0xF8, *(f32 *)(v + 8), v, 0.000872664677445f, 0.00174532935489f, 0.122173056006f, 0);
        func_00388BD0(m + 0xC0, m + 0xF0);
        *(s32 *)(v + 4) = func_00389468(*(f32 *)(m + 0xF8), *(f32 *)(v + 8)) < 0.05f;
        break;
    }
}
/* localdecomp:end func_L03_003B1100 */
