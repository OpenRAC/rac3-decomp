#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    u8 b0C;
    u8 b0D;
    u8 b0E;
} S_006618D8;
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x128 - 8];
    s32 w128;
    u8 pad12C[0x170 - 0x12C];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} S_1A5CD0_006618D8;

/* declared by functions of L39_0065D0A0.c, which this file was cut from */
extern u8 D_L39_004997E0[];

INCLUDE_ASM("asm/levels", func_L39_00661488);
