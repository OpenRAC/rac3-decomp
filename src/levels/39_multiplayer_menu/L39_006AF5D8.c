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

/* declared by functions of L39_006AF570.c, which this file was cut from */
typedef struct {
    u8 pad0[0x2C];
    u8 f2C;
} B_006AF570;
typedef struct {
    u8 pad0[0x30];
    B_006AF570 *f30;
    u8 pad34[0x54 - 0x34];
    void *f54;
} G_006AF570;
extern G_006AF570 *D_L39_0024D760;

INCLUDE_ASM("asm/levels", func_L39_006AF5D8);
