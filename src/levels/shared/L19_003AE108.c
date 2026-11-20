#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

typedef int Q __attribute__((mode(TI)));
typedef struct {u8 pad[0x30]; Q pos; u8 tail[0x40];} Rec;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad14[0xC];
    s32 ids[8];
    u8 quads[0x80];
} P_003AD358;

/* declared by functions of L19_003ADE70.c, which this file was cut from */
extern Rec *D_L19_001DF800_003AC268;
extern u8 D_1A30B0[];
extern void func_L19_003AE108(void *);
extern void func_L19_003AE5A8(void *);
extern int func_L01_004561B8(void *);
extern void func_003A4F28(int);

INCLUDE_ASM("asm/levels", func_L19_003AE108);

INCLUDE_ASM("asm/levels", func_L19_003AE5A8);
