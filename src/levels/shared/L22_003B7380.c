#include "common.h"

typedef struct {
    u8 p0[4];
    s32 n[16];
    s32 b[16];
    s32 a[16];
    u8 p1[0x188 - 0xC4];
} Rec188;

INCLUDE_ASM("asm/levels", func_L22_003B7380);

INCLUDE_ASM("asm/levels", func_L22_003B7A70);

INCLUDE_ASM("asm/levels", func_L22_003B7C20);
