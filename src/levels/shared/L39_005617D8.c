#include "common.h"

/* declared by functions of L39_00561630.c, which this file was cut from */
typedef struct {
    u8 pad0[0x18];
    s32 x18;
    u8 pad1C[0x10];
    f32 x2C;
} S_00561630;
typedef struct {
    u8 pad0[0x68];
    S_00561630 *p68;
} O_00561630;

INCLUDE_ASM("asm/levels", func_L39_005617D8);
