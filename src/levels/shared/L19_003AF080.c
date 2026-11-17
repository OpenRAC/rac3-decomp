#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

typedef int Q __attribute__((mode(TI)));
typedef struct {u8 pad[0x30]; Q pos; u8 tail[0x40];} Rec;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad14[0xC];
    s32 ids[8];
    u8 quads[0x80];
} P_003AD358;

/* declared by functions of L19_003ADE70.c, which this file was cut from */
extern u8 *D_L19_001DF71C_003AD358;

INCLUDE_ASM("asm/levels", func_L19_003AF080);
