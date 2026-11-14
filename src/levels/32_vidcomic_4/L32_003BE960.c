#include "common.h"

typedef struct S_003BED60 {
    u8 pad00[4];
    u8 f04[8];
    f32 f0C;
    f32 f10;
    u8 pad14[0x28];
    s32 f3C;
} S_003BED60;
typedef struct S_003BED60_arg {
    u8 pad00[0x68];
    S_003BED60 *f68;
} S_003BED60_arg;

/* declared by functions of L32_003BE008.c, which this file was cut from */
void func_L32_003BED60(void *);
void func_L01_004450F0(void *, s32, s32);

INCLUDE_ASM("asm/levels", func_L32_003BE960);
