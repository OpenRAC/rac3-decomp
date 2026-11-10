#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L24_003B7820);

INCLUDE_ASM("asm/levels", func_L24_003B7A70);

INCLUDE_ASM("asm/levels", func_L24_003B7B88);

INCLUDE_ASM("asm/levels", func_L24_003B7DE8);

INCLUDE_ASM("asm/levels", func_L24_003B7F00);

INCLUDE_ASM("asm/levels", func_L24_003B8160);

INCLUDE_ASM("asm/levels", func_L24_003B8278);

/* localdecomp:start func_L24_003B87F0 */
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

u8 *func_L24_003B87F0(u8 *src, float f) {
    u8 *obj = func_003C24B0(0x1B9B, 0x80);
    float *sub;

    if (obj != 0) {
        sub = *(float **)(obj + 0x68);
        func_L01_00456160(obj, src);
        *(u128_t *)(obj + 0x10) = *(u128_t *)(src + 0x10);
        sub[2] = f;
        *(u8 **)(obj + 0xB8) = src;
        func_L01_004450F0(obj, 2, -1);
    }
    return obj;
}
/* localdecomp:end func_L24_003B87F0 */
