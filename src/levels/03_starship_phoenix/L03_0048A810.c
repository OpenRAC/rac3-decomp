#include "common.h"

typedef struct {
    s32 active;
    s32 pad4;
    s32 pad8;
    u32 *list;
    u32 type;
    u8 flag;
    u8 pad15[3];
} S_0048A810;

INCLUDE_ASM("asm/levels", func_L03_0048A810);
