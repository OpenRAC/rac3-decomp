#include "common.h"

typedef struct { u8 pad[0x2D8]; s32 x2D8; s32 x2DC; u8 pad2E0[0x2F8 - 0x2E0]; s32 x2F8; } X_006683F8;
typedef struct { u8 pad[0x2528]; X_006683F8 *x2528; u8 pad2[0x254C - 0x252C]; s32 x254C; } P_006683F8;

/* declared by functions of L39_00666F88.c, which this file was cut from */
extern s32 func_L39_0061BF68(void *);
extern void func_L01_003F2278(s32, void *);

INCLUDE_ASM("asm/levels", func_L39_00667700);
