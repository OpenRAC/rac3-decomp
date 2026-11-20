#include "common.h"

typedef struct Ent_00359D78 {
    u8 pad[0x20];
    u8 type;
    u8 pad2[0xDF];
} Ent_00359D78;
typedef struct Obj_00359D78 {
    u8 pad[4];
    s32 i4;
    s32 i8;
    u8 pad2[0x94];
    s32 fA0[3];
} Obj_00359D78;

INCLUDE_ASM("asm/levels", func_L30_00359A08);
