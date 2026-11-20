#include "common.h"

typedef struct {
    u8 pad[0x2850];
    s32 w2850;
} Hero2850;

/* declared by functions of L20_003D61B8.c, which this file was cut from */
extern s32 func_L20_003D65D0(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 D_L20_001D67A8;
extern s32 D_L20_001DEBEC;

INCLUDE_ASM("asm/levels", func_L20_003D65D0);
