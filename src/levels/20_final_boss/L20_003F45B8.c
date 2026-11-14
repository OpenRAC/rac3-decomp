#include "common.h"

typedef struct Vars_3F4A78 {
    u8 pad0[0x10];
    u8 slot[2][0x10];
    u8 pad30[0xA0 - 0x30];
    s32 wA0;
} Vars_3F4A78;

INCLUDE_ASM("asm/levels", func_L20_003F45B8);

INCLUDE_ASM("asm/levels", func_L20_003F47E8);

INCLUDE_ASM("asm/levels", func_L20_003F4918);
