#include "common.h"

/* declared by functions of L39_00694418.c, which this file was cut from */
typedef struct {
    u8 pad[0xC8];
    u8 fc8;
    s32 fcc;
    s32 fd0;
} R_006948A0;
typedef struct {
    s32 f0;
    s32 f4;
    R_006948A0 **f8;
} E_006948A0;
typedef struct {
    u8 pad0[0x3EC];
    u8 f3ec;
    s32 f3f0;
    u8 f3f4;
    u8 pad1[0x3FC - 0x3F5];
    s32 f3fc;
    u8 pad2[0x404 - 0x400];
    E_006948A0 entries[1];
} Q_006948A0;
typedef struct { u8 pad[0x38]; Q_006948A0 *f38; } G_006948A0;
extern void *func_00381FF0(s32);

INCLUDE_ASM("asm/levels", func_L39_006949F0);
