#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));

/* declared by functions of L01_003002A8.c, which this file was cut from */
extern u8 *func_003C24B0(s32, s32);

INCLUDE_ASM("asm/levels", func_L01_00301798);

LINKER_REMNANT("asm/levels", func_L01_003018B0);

INCLUDE_ASM("asm/levels", func_L01_003018B8);
