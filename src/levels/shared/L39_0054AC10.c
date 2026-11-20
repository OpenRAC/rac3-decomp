#include "common.h"

/* declared by functions of L39_0054A250.c, which this file was cut from */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[0x28 - 0x22];
    f32 f28;
    u8 pad2C[0x80 - 0x2C];
} T_0054A250;
extern f32 *func_00382348(void *);
extern s32 func_L39_00648AE0(void *, s32);
extern u8 D_L39_004997E0[];
extern T_0054A250 D_L39_0049C890[];
extern s32 D_L39_003BDD20[][24];

INCLUDE_ASM("asm/levels", func_L39_0054AC10);

INCLUDE_ASM("asm/levels", func_L39_0054B4B8);
