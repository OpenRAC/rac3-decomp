#include "common.h"

/* declared by functions of L39_0055D7F8.c, which this file was cut from */
extern u16 *D_L39_002927E0[];
struct E_0055DB18;
extern struct E_0055DB18 *D_L39_0024BF5C;
extern s32 D_L39_0024BF98;
extern void func_L01_004450F0(void *, s32, s32);
typedef struct T_0055DB18 {
    u8 pad[0x88];
    s32 w88[8];
    s32 wA8[8];
} T_0055DB18;
typedef struct Q_0055DB18 {
    u8 pad0[0x1C];
    s32 f1C;
    u8 pad20[0xC];
    s32 f2C;
} Q_0055DB18;
typedef struct E_0055DB18 {
    u8 pad[0x68];
    Q_0055DB18 *f68;
    u8 pad2[0x100 - 0x6C];
} E_0055DB18;
extern E_0055DB18 *D_L39_0024BF5C;
extern T_0055DB18 *D_L39_00352B4C[];

INCLUDE_ASM("asm/levels", func_L39_0055DCE0);

INCLUDE_ASM("asm/levels", func_L39_0055E2E0);
