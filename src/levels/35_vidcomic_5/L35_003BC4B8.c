#include "common.h"

typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad1[0x47];
    void *f68;
} S_Obj_003BC958;
typedef struct {
    u8 pad0[0x84];
    s32 f84;
} S_Sub_003BC958;
typedef struct {
    u8 pad0[0x24];
    s32 f24;
    u8 pad1[0x44];
    s32 f6C;
    u8 pad2[0x24];
    s32 f94;
} S_1CCFD0_003BC958;

INCLUDE_ASM("asm/levels", func_L35_003BC4B8);

INCLUDE_ASM("asm/levels", func_L35_003BC828);

INCLUDE_ASM("asm/levels", func_L35_003BC958);

INCLUDE_ASM("asm/levels", func_L35_003BC9F0);

INCLUDE_ASM("asm/levels", func_L35_003BCA28);

INCLUDE_ASM("asm/levels", func_L35_003BCAB8);
