#include "common.h"
#include "vu0.h"

typedef struct {
    u8 p0[0x30];
    u8 v30[0x0E];
    u8 b3E;
    u8 p3F[0x5E - 0x3F];
    u8 b5E;
    u8 b5F;
    u8 p60[0x160 - 0x60];
    u8 v160[0x304 - 0x160];
    s32 i304;
    f32 f308;
} S_Vars3A1638;
typedef struct {
    u8 p0[0x20]; u8 state;
    u8 p21[0x68 - 0x21]; S_Vars3A1638 *vars;
} S_Moby3A1638;
typedef struct {
    u8 pad0[16];
    u8 pos[33];
    u8 b49;
    u8 pad32[61];
    u8 b111;
    u8 pad70[38];
    u16 h150;
} Moby_3A1DD8;

/* declared by functions of L08_003A16C8.c, which this file was cut from */
extern s32 func_L08_003A34C8(S_Moby3A1638 *);
extern void func_L08_003A37A0(S_Moby3A1638 *);

INCLUDE_ASM("asm/levels", func_L08_003A34C8);

INCLUDE_ASM("asm/levels", func_L08_003A37A0);
