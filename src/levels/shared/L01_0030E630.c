#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x28];
    s32 w28;
} S_311A18m;
typedef struct {
    u8 pad0[0x10];
    s128 q10;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    S_311A18m *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} S_311A18;

INCLUDE_ASM("asm/levels", func_L01_0030E630);

INCLUDE_ASM("asm/levels", func_L01_0030EAE8);

INCLUDE_ASM("asm/levels", func_L01_0030F0B0);

INCLUDE_ASM("asm/levels", func_L01_0030F288);

LINKER_REMNANT("asm/levels", func_L01_0030F4E0);

INCLUDE_ASM("asm/levels", func_L01_0030F4E8);

INCLUDE_ASM("asm/levels", func_L01_0030F6C0);

LINKER_REMNANT("asm/levels", func_L01_003104A0);

INCLUDE_ASM("asm/levels", func_L01_003104B8);

INCLUDE_ASM("asm/levels", func_L01_00310538);

LINKER_REMNANT("asm/levels", func_L01_003107A8);

INCLUDE_ASM("asm/levels", func_L01_003107C8);
