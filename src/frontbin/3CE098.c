#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003CE250(void);
extern void func_003CE1B0(void);
extern void func_003CE2C0(void);
/* --- end of declarations from other files --- */

typedef struct { u8 pad[0x20]; s16 *arr[1]; } S_3C8B28;
extern S_3C8B28 *D_001DA5F0_003CE098;
extern s32 D_001DA610[2];
extern void func_0038D348(void *, void *);
INCLUDE_ASM("asm/nonmatchings/text", func_003CE098);

extern s32 func_003CE098(s32, s32);
s32 func_003CE3E0_003CE1B0(s32);
extern s32 D_001D9D00;
extern void *D_001DA5F0_003CE1B0;
extern s32 D_001DA650;
INCLUDE_ASM("asm/nonmatchings/text", func_003CE1B0);

LINKER_REMNANT("asm/remnants", func_003CE248);

typedef struct Config_003C8CE0 {
    unsigned char padding[0xC];
    short count;
    unsigned char padding2[2];
    unsigned char *buffer;
} Config_003C8CE0;
extern int D_001DA050;
extern Config_003C8CE0 *D_001DA5F0_003CE250;
extern int D_001DA600;
extern int D_001D4BB4;
extern int D_001D4BB0;
extern int D_001D9BFC;
INCLUDE_ASM("asm/nonmatchings/text", func_003CE250);

extern u32 *D_001DA050_003CE2C0;
extern u32 *D_001DA600_003CE2C0;
extern u32 *D_001DA604_003CE2C0;
extern s32 D_001D4BB0_003CE2C0;
extern s32 D_001D4BB4_003CE2C0;
extern void func_003A02E8();
extern s32 func_003A9618();
INCLUDE_ASM("asm/nonmatchings/text", func_003CE2C0);

LINKER_REMNANT("asm/remnants", func_003CE3D8);

/* localdecomp:start func_003CE3E0 */
typedef struct { u16 pad; u16 flags; } Q_3C8E70;
typedef struct { u8 pad[6]; s16 n; u8 pad2[0x18]; Q_3C8E70 *arr[1]; } P_3C8E70;
extern P_3C8E70 *D_001DA5F0[];
extern void func_003CE5E8(Q_3C8E70 *);
extern void func_003CE440(Q_3C8E70 *);
void func_003CE3E0(s32 i) {
    P_3C8E70 *p = D_001DA5F0[0];
    if (i < p->n) {
        Q_3C8E70 *q = p->arr[i];
        if (q->flags & 1) func_003CE5E8(q);
        else func_003CE440(q);
    }
}
/* localdecomp:end func_003CE3E0 */

typedef struct { u8 pad[0x10]; u8 *base; s16 h14; s16 h16; s16 h18; s16 h1A; s16 h1C; s16 h1E; } E_3C8ED0;
typedef struct { s16 n; u16 flags; u8 pad[0xC]; E_3C8ED0 items[1]; } S_3C8ED0;
extern u32 *D_001DA050_003CE440;
extern s32 D_001D9348;
extern u8 D_001423C0[];
extern u8 D_00142350[];
extern void func_003CED08(E_3C8ED0 *, s32, u8 *);
extern void func_003CE780(void);
extern s32 func_003CE828(u8 *, u8 *, s32);
extern s32 func_003CEA20(s32, u8 *, u8 *, u8 *, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003CE440);

typedef E_3C8ED0 E_3C9078;
typedef struct { s16 n; u16 flags; u8 pad[0xC]; E_3C9078 items[1]; } S_3C9078;
extern u32 *D_001DA050_003CE5E8;
extern u8 D_1422E0[];
extern s32 D_1A1ED0[];
extern void func_003CED08(E_3C9078 *, s32, u8 *);
extern void func_003CE780(void);
extern s32 func_003CE828(u8 *, u8 *, s32);
extern void func_003CE920(s32, u8 *, u8 *, u8 *);
extern void func_003A9440(s32, unsigned long);
INCLUDE_ASM("asm/nonmatchings/text", func_003CE5E8);

LINKER_REMNANT("asm/remnants", func_003CE778);
