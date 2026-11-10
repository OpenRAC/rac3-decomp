#include "common.h"

typedef struct S_006A5FE0 {
    u8 pad0[0x2B1];
    u8 f2B1;
    u8 pad1[6];
    s32 f2B8;
    s32 f2BC[576];
    s32 fBBC[1];
} S_006A5FE0;

typedef struct S_006A6108 {
    u8 pad0[0xCBC];
    u8 f_CBC;
    u8 pad1[7];
    s32 f_CC4;
    s32 f_CC8[1];
    u8 pad2[0x8FC];
    s32 f_15C8[1];
} S_006A6108;

typedef struct S_L39_006A6078 {
    u8 pad0[0x16CC];
    s32 f16CC;
    s32 f16D0[11];
    s32 f16FC[1];
} S_L39_006A6078;

/* declared by functions of L39_006A5F30.c, which this file was cut from */
extern s32 func_00381FF0(s32);
extern void func_L39_00688340(s32, s32, s32);
extern void func_L39_006A6290(void *, s32, s32);

INCLUDE_ASM("asm/levels", func_L39_006A61A0);

INCLUDE_ASM("asm/levels", func_L39_006A6290);

INCLUDE_ASM("asm/levels", func_L39_006A6470);

INCLUDE_ASM("asm/levels", func_L39_006A65B8);

INCLUDE_ASM("asm/levels", func_L39_006A6778);

INCLUDE_ASM("asm/levels", func_L39_006A6938);

LINKER_REMNANT("asm/levels", func_L39_006A69A0);

INCLUDE_ASM("asm/levels", func_L39_006A69C0);

LINKER_REMNANT("asm/levels", func_L39_006A6F98);

INCLUDE_ASM("asm/levels", func_L39_006A6FA0);

INCLUDE_ASM("asm/levels", func_L39_006A6FC8);

INCLUDE_ASM("asm/levels", func_L39_006A7178);

INCLUDE_ASM("asm/levels", func_L39_006A72B0);
