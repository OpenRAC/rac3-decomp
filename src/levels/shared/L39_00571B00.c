#include "common.h"

typedef struct {
    u8 pad0[0x460];
} Ent_005718B8;
typedef struct {
    u8 pad0[0x30];
    u8 pos[0x50];
} Pt_005718B8;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 pad14[0x26 - 0x14];
    s16 x26;
    u8 pad28[0x34 - 0x28];
    s32 x34;
    u8 pad38[0x4A - 0x38];
    s16 x4A;
} Info_005718B8;
typedef struct {
    u8 pad0[0x1C];
    Info_005718B8 *info;
} Row_005718B8;

/* declared by functions of L39_005718B8.c, which this file was cut from */
extern Ent_005718B8 D_L39_0024DE80[];
extern Row_005718B8 *D_L39_0024B850;

INCLUDE_ASM("asm/levels", func_L39_00571B00);
