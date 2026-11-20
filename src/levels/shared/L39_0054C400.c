#include "common.h"

/* declared by functions of L39_0054A250.c, which this file was cut from */
typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[0x28 - 0x22];
    f32 f28;
    u8 pad2C[0x80 - 0x2C];
} T_0054A250;
extern s32 func_L39_00648AE0(void *, s32);
extern T_0054A250 D_L39_0049C890[];
typedef int u128_0054C2B0 __attribute__((mode(TI)));
extern void func_0038CE20(u128_0054C2B0 *, u128_0054C2B0 *, f32);

INCLUDE_ASM("asm/levels", func_L39_0054C400);
