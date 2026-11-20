#include "common.h"

/* declared by functions of L39_0062AD60.c, which this file was cut from */
typedef int q128 __attribute__((mode(TI)));
typedef struct {
    char pad0[0xA0];
    q128 cur;
    char padB0[0x1DC0 - 0xB0];
    q128 hist[32];
    char pad1FC0[0x2348 - 0x1FC0];
    s32 pos;
    s32 count;
} Obj;
extern s32 func_L39_0062AE10(Obj *, s32);

INCLUDE_ASM("asm/levels", func_L39_0062AE10);
