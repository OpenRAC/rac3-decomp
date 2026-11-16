#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3AC810;

/* declared by functions of L13_003ADA98.c, which this file was cut from */
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L13_003AEB48(void *);
extern void func_L13_003AEBC8(void *);

INCLUDE_ASM("asm/levels", func_L13_003AEB48);

INCLUDE_ASM("asm/levels", func_L13_003AEBC8);

INCLUDE_ASM("asm/levels", func_L13_003AEC48);

INCLUDE_ASM("asm/levels", func_L13_003AECE0);

INCLUDE_ASM("asm/levels", func_L13_003AEDD8);

INCLUDE_ASM("asm/levels", func_L13_003AEEB0);
