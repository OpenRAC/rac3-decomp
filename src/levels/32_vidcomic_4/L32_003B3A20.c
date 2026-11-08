#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L32_003B3A20);

INCLUDE_ASM("asm/levels", func_L32_003B3D88);

INCLUDE_ASM("asm/levels", func_L32_003B40F0);

INCLUDE_ASM("asm/levels", func_L32_003B41E8);

INCLUDE_ASM("asm/levels", func_L32_003B4310);

INCLUDE_ASM("asm/levels", func_L32_003B43F8);

/* localdecomp:start func_L32_003B47A0 */
extern f32 D_L32_001DED14;
extern u8 *func_003C24B0(s32, s32);
void func_L01_004450F0(s32, s32, s32);

u8 *func_L32_003B47A0(u128_t *a0, u128_t *a1, f32 f12) {
    u8 *obj = func_003C24B0(0x1C1C, 0x50);
    u8 *p;
    if (obj == 0)
        return 0;
    obj[0x30] = 0xFF;
    *(s16 *)(obj + 0x32) = 0x40;
    *(f32 *)(obj + 0x2C) = D_L32_001DED14 * *(f32 *)(*(u8 **)(obj + 0x24) + 0x24);
    p = *(u8 **)(obj + 0x68);
    *(u128_t *)p = *a0;
    *(u128_t *)(p + 0x10) = *a1;
    *(f32 *)(p + 0x30) = f12;
    func_L01_004450F0((s32)obj, 0, -1);
    return obj;
}
/* localdecomp:end func_L32_003B47A0 */

INCLUDE_ASM("asm/levels", func_L32_003B4850);
