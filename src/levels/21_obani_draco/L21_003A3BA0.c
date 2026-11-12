#include "common.h"

INCLUDE_ASM("asm/levels", func_L21_003A3BA0);

INCLUDE_ASM("asm/levels", func_L21_003A3DE8);

INCLUDE_ASM("asm/levels", func_L21_003A3F30);

/* localdecomp:start func_L21_003A4148 */
typedef int u128_t __attribute__((mode(TI)));

extern void func_L01_0043A430(u8 *a0, s32 a1, u8 *a2);
extern s32 func_00382468(s32 a0);
extern f32 func_003824E0(f32 a0, f32 a1);
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);

void func_L21_003A4148(u8 *arg0, u8 *arg1) {
    f32 x;
    func_L01_0043A430(arg0, 0, arg1);
    *(u8 *)(arg0 + 0x62) = 0xFF;
    *(u128_t *)(arg1 + 0x40) = *(u128_t *)(arg0 + 0x10);
    x = *(f32 *)(arg1 + 0x48);
    *(f32 *)(arg1 + 0x48) = x - 1.0f;
    *(f32 *)(arg1 + 0x54) = func_003824E0(0.05f, 0.001f);
    *(f32 *)(arg1 + 0x54) = (f32)(func_00382468(2) + 1) * *(f32 *)(arg1 + 0x54);
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L21_003A4148 */

INCLUDE_ASM("asm/levels", func_L21_003A41F8);

INCLUDE_ASM("asm/levels", func_L21_003A43E8);

INCLUDE_ASM("asm/levels", func_L21_003A4500);
