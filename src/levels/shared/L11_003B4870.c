#include "common.h"

typedef int Quad_3B4FB0 __attribute__((mode(TI)));
typedef struct Vars_3B4FB0 {
    s32 w0;
    f32 f4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
} Vars_3B4FB0;
typedef struct Rec_3B4FB0 {
    u8 pad0[0x10];
    f32 e10[4];
    f32 e20[4];
    Quad_3B4FB0 pos;
    u8 pad40[0x40];
} Rec_3B4FB0;

INCLUDE_ASM("asm/levels", func_L11_003B4870);
