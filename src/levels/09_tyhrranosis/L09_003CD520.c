#include "common.h"

typedef struct {
    u8 pad[4];
    s32 (*f4)(void *);
    s32 (*f8)(void *);
} V_003CDA30;

typedef struct {
    s32 (*f0)(void *);
    u8 pad[4];
    s32 (*f8)(void *);
} V_003CD520;

INCLUDE_ASM("asm/levels", func_L09_003CD520);
