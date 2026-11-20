#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L01_00305880);

INCLUDE_ASM("asm/levels", func_L01_00305970);

INCLUDE_ASM("asm/levels", func_L01_00305AB8);
