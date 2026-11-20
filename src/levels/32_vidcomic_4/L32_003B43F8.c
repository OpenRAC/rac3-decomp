#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L32_003B41E8.c, which this file was cut from */
extern s32 D_L32_001DED54;
extern u8 D_L32_001E2440[] __attribute__((section(".sdata")));
extern void func_L32_003B43F8(u8 *, u8 *);

INCLUDE_ASM("asm/levels", func_L32_003B43F8);
