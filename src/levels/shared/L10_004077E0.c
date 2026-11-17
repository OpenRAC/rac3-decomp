#include "common.h"

typedef struct { u8 pad[0x34]; s32 frame; } S_Game;
typedef struct { u8 pad[0xB0]; } S_Rec;

/* declared by functions of L10_00407268.c, which this file was cut from */
extern s32 D_L10_001D6C50;

/* declared by functions of L10_00407750.c, which this file was cut from */
extern void func_003C2F58(void *, s32, void *);
extern void func_003C4C18(void *, f32);

INCLUDE_ASM("asm/levels", func_L10_004077E0);
