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

/* declared by functions of L39_006AE3D8.c, which this file was cut from */
extern s32 *D_L39_00241120;
extern u8 *func_00381FF0(s32);

INCLUDE_ASM("asm/levels", func_L39_006AEF70);
