#include "common.h"

typedef struct {
    u8 pad0[0x50];
    u8 *p50;
    u8 pad54[0x460 - 0x54];
} Ent_003C5150;
typedef struct {
    u8 pad0[0x1C];
    u8 *st;
} Sp_003C5150;

/* declared by functions of L02_003C5150.c, which this file was cut from */
extern Ent_003C5150 D_L02_001E1300[];
extern Sp_003C5150 *D_L02_001DE184;
extern u8 D_001A4C60[];

INCLUDE_ASM("asm/levels", func_L02_003C5310);
