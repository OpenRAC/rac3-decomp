#include "common.h"

typedef struct { s32 w0; f32 f4; } S_003A20E0;
typedef struct { u8 pad0[0x20]; u8 state; u8 pad1[0x47]; S_003A20E0 *s; u8 pad2[0x3C]; u8 fA8; u8 padA9; s16 hAA; u8 padAC[0x48]; f32 fF4; } O_003A20E0;
typedef struct { u8 pad[0x20]; O_003A20E0 *q; } T_003A20E0;

INCLUDE_ASM("asm/levels", func_L03_003A20E0);
