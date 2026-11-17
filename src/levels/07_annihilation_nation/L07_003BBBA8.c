#include "common.h"

typedef struct { f32 f0; s16 h4; } P_003BB1F0;

typedef struct S_003BB7A8 {
    u8 pad[0xA4];
    u16 flags;
} S_003BB7A8;

/* declared by functions of L07_003BB360.c, which this file was cut from */
extern s32 func_L07_003A2380_003BB840(s32, s32, s32, s32) __asm__("func_L07_003A2380");

INCLUDE_ASM("asm/levels", func_L07_003BBBA8);
