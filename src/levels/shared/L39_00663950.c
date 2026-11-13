#include "common.h"

typedef struct N_65FDA0 { u32 w0; s32 w4; s32 w8; u8 p0[0x49]; u8 b55; u8 p1x; struct N_65FDA0 *next; } N_65FDA0;
typedef struct N_65FE10 { u8 pad[0x58]; struct N_65FE10 *next; } N_65FE10;
typedef void (*Fn_6600D8)(void *, void *);
typedef struct {
    u32 pad0 : 4;
    u32 cap : 6;
    u32 pad1 : 22;
} S_6601C8;

INCLUDE_ASM("asm/levels", func_L39_00663950);

INCLUDE_ASM("asm/levels", func_L39_00663C80);

INCLUDE_ASM("asm/levels", func_L39_00663DA8);

INCLUDE_ASM("asm/levels", func_L39_00664760);

INCLUDE_ASM("asm/levels", func_L39_00665568);
