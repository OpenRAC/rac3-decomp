#include "common.h"

/* declared by functions of L39_0056B080.c, which this file was cut from */
typedef struct {
    u8 pad0[0x100];
    f32 f100;
    f32 f104;
    u8 pad108[0x1A0 - 0x108];
    s32 w1A0;
} Pad_0056B080;
typedef struct {
    u8 pad0[0x40];
    u8 pos[0x10];
    u8 pad50[0xF0 - 0x50];
    u8 *wF0;
    s32 wF4;
    s32 wF8;
    s32 wFC;
    s32 w100;
    s32 w104;
    u8 pad108[0x11C - 0x108];
    s32 w11C;
    u8 pad120[0x126 - 0x120];
    s16 h126;
    u8 pad128[0x12C - 0x128];
    u8 b12C;
    u8 pad12D[0x133 - 0x12D];
    u8 b133;
    Pad_0056B080 *p134;
    u8 pad138[0x144 - 0x138];
    s32 w144;
    f32 f148;
    u8 pad14C[0x2B0 - 0x14C];
} St_0056B080;
typedef struct {
    u8 pad0[0x108];
    f32 f108[6];
    u8 pad120[0x144 - 0x120];
    struct {
        u8 *w144;
        s32 w148;
    } s144;
    u8 pad14C[4];
    St_0056B080 st;
    void (*fn400)(s32);
    u8 pad404[0x460 - 0x404];
} Ent_0056B080;
extern Ent_0056B080 D_L39_0024DE80[];
extern s32 D_L39_0024B858[] __attribute__((section(".sdata")));

INCLUDE_ASM("asm/levels", func_L39_0056B940);
