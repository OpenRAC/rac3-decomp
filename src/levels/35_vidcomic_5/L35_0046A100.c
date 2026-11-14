#include "common.h"

typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_0046A100;

INCLUDE_ASM("asm/levels", func_L35_0046A100);
