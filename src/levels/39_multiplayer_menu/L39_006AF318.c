#include "common.h"

typedef struct {
    u8 pad0[0x20];
    void (*f20)(void *, s32, s32);
    u8 pad24[0x4C - 0x24];
    void (*f4C)(void *, s32, s32);
} VT_006AEF20;
typedef struct {
    u8 pad0[0x60];
    VT_006AEF20 *vt;
} OBJ_006AEF20;

INCLUDE_ASM("asm/levels", func_L39_006AF318);
