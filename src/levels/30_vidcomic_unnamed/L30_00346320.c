#include "common.h"

typedef struct S_L30_00346278_inner {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    f32 f18;
    f32 f1C;
    s32 f20;
} S_L30_00346278_inner;
typedef struct S_L30_00346278 {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[0x4C];
    S_L30_00346278_inner *f68;
} S_L30_00346278;

/* declared by functions of L30_00346230.c, which this file was cut from */
void func_L30_00346320(void *);
void func_L30_00346600(void *);

INCLUDE_ASM("asm/levels", func_L30_00346320);

INCLUDE_ASM("asm/levels", func_L30_00346600);

INCLUDE_ASM("asm/levels", func_L30_003467C0);
