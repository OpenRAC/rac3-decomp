#include "common.h"

typedef struct { u8 pad0[0x394]; s32 x394; u8 pad1[0x5C]; s16 x3F4; } T_003FB630;
typedef struct { u8 pad0[0x68]; T_003FB630 *x68; } O_003FB630;

/* declared by functions of L20_003FB630.c, which this file was cut from */
extern s32 func_L20_003FB3B0(void *);

INCLUDE_ASM("asm/levels", func_L20_003FEBA8);
