/* NTSC-U draft (2026-11-14, Claude worker): C of func_L03_003B1100, the NTSC-U twin of func_L03_003B2C30, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L03_003B2C30.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L03_003B2C30 (src/levels/shared/L03_003B2C30.c) */
/* localdecomp:start func_L03_003B1100 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 D_00142700[];
extern void func_003BD360(void *);
extern void func_00388BD0(void *, void *);
extern void func_L03_003B1308(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern f32 func_00389468(f32, f32);

void func_L03_003B1100(u8 *self) {
    u8 *s = *(u8 **)(self + 0x68);

    switch (self[0x20]) {
    case 0:
        if (D_00142700[0] != 0) {
            func_003BD360(self);
            return;
        }
        func_00388BD0(self + 0xC0, self + 0xF0);
        *(u128_t *)(s + 0x20) = *(u128_t *)(self + 0xC0);
        *(f32 *)(s + 0xC) = *(f32 *)(self + 0xF8);
        func_L03_003B1308(self);
        func_L01_00441FB8(self, 1, -1);
        break;
    case 1:
        func_L01_00445758(self + 0xF8, *(f32 *)(s + 0xC), s, 0.000872664677f, 0.00174532935f, 0.122173056f, 0);
        func_00388BD0(self + 0xC0, self + 0xF0);
        *(s32 *)(s + 4) = 0;
        break;
    case 2:
        func_L01_00445758(self + 0xF8, *(f32 *)(s + 8), s, 0.000872664677f, 0.00174532935f, 0.122173056f, 0);
        func_00388BD0(self + 0xC0, self + 0xF0);
        *(s32 *)(s + 4) = func_00389468(*(f32 *)(self + 0xF8), *(f32 *)(s + 8)) < 0.05f;
        break;
    }
}
/* localdecomp:end func_L03_003B1100 */
