#include "common.h"

/* declared by functions of L40_00424920.c, which this file was cut from */
extern s32 func_L40_00424B10(void *arg0);
extern u8 *D_L40_0024845C;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct { u8 pad[0x2A0]; s32 f2A0; } V_424328;
typedef struct { u8 pad[0x20]; u8 state; u8 p21[0x47]; V_424328 *vars; } S_424328;
extern void func_L01_004450F0(S_424328 *, s32, s32);

INCLUDE_ASM("asm/levels", func_L40_004255A0);
