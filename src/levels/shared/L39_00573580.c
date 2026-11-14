#include "common.h"

typedef struct Ent_00573C58 {
    u8 pad0[0x18];
    u8 f18;
    u8 pad19[7];
} Ent_00573C58;

/* declared by functions of L39_00573208.c, which this file was cut from */
typedef struct {
    u8 pad0[0xFC];
    s32 wFC;
    s32 w100;
    s32 w104;
} Sub_00573208;
typedef struct {
    u8 pad0[0x150];
    Sub_00573208 sub;
    u8 pad25C[0x2A3 - 0x150 - 0x108];
    u8 b2A3;
    u8 pad2A4[0x2B8 - 0x2A4];
    f32 f2B8;
    u8 pad2BC[0x2C8 - 0x2BC];
    f32 f2C8;
    u8 pad2CC[0x458 - 0x2CC];
    s32 w458;
    u8 pad45C[4];
} Cam_00573208;
extern Cam_00573208 D_L39_0024DE80[];
extern s32 D_L39_00241128;
typedef struct {
    u8 pad0[0x1C];
    u8 *p1C;
    u8 pad20[0x20 - 0x20];
} Slot_005732E0;
extern Slot_005732E0 *D_L39_0024B850;
extern void func_0038CC88(void *, void *, s32);

INCLUDE_ASM("asm/levels", func_L39_00573580);

INCLUDE_ASM("asm/levels", func_L39_00573948);
