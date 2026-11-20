#include "common.h"

typedef struct Obj_003A2C98 {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0xC];
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    u8 pad34[0x20];
    f32 f54;
    f32 f58;
    u8 pad5C[4];
    f32 f60[1];
} Obj_003A2C98;

/* declared by functions of L02_003A2C98.c, which this file was cut from */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

INCLUDE_ASM("asm/levels", func_L02_003A2EC8);
