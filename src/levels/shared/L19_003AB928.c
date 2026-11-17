#include "common.h"

/* declared by functions of L19_003AB7D0.c, which this file was cut from */
typedef struct { f32 x; f32 y; f32 z; f32 w; } V4_3A9BF8;
typedef struct {
    u8 p0[0x10]; V4_3A9BF8 pos; u8 b20; u8 p21[0x47]; void *w68; u8 p6C[0x29]; u8 b95; u8 p96[0x14]; s16 hAA;
} M_3A9BF8;
extern void func_L19_003AB928(M_3A9BF8 *);

INCLUDE_ASM("asm/levels", func_L19_003AB928);
