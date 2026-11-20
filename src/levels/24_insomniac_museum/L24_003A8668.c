#include "common.h"

typedef struct Obj_003A88E8 {
    u8 pad0[0x94C];
    s16 f94C;
    u8 pad94E[0x0E];
    s32 f95C;
    u8 pad960[0x20];
    s32 f980;
    s32 f984;
} Obj_003A88E8;


typedef struct {
    u8 pad0[0x954];
    s32 f0;
    f32 f4;
} S_3A8998;

INCLUDE_ASM("asm/levels", func_L24_003A8668);
