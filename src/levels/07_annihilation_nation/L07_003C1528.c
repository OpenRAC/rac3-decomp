#include "common.h"

typedef struct { u8 pad0[0x68]; struct { u8 pad[4]; s32 idx; } *p68; } O_B;

/* declared by functions of L07_003C0710.c, which this file was cut from */
extern u8 *D_001DE550_sda;
extern void func_L07_003C17C0(void *);
extern void func_L07_003C0F40(u8 *);
typedef struct {
    u8 b0;
    u8 pad1;
    s16 h2;
    u8 pad4[0x20];
} E_003C0F40;
extern E_003C0F40 D_L07_002BC920_003C0F40[];
extern u8 D_L07_001DE554;
extern u8 D_L07_001DE555;

INCLUDE_ASM("asm/levels", func_L07_003C1528);

INCLUDE_ASM("asm/levels", func_L07_003C17C0);
