#include "common.h"

typedef struct { u8 pad0[0x68]; struct { u8 pad[4]; s32 idx; } *p68; } O_B;

/* declared by functions of L07_003C0710.c, which this file was cut from */
extern u8 D_001426E0[];
typedef struct { u8 pad0[4]; s16 h4; u8 pad6[0x1E]; } E_003C0ED8;
extern E_003C0ED8 D_L07_002BC920[];
extern s32 func_L07_003C1360(s32);

INCLUDE_ASM("asm/levels", func_L07_003C1360);
