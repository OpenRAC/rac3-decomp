#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union { u128_t q; f32 f[4]; } Vec4;

INCLUDE_ASM("asm/levels", func_L30_003A14F8);
