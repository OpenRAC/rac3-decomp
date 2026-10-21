#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3CE2E8.c's earlier functions (tools/port_from_us.py) */
typedef struct { u8 pad[0x20]; s16 *arr[1]; } S_3C8B28;
extern S_3C8B28 *D_001DA5F0_003CE450;
extern s32 D_001DA610[2];
extern void func_0038D728(void *, void *);
extern s32 func_003CE450(s32, s32);
s32 func_003CE798_003CE568(s32);
extern s32 D_001D9D00;
extern void *D_001DA5F0_003CE568;
extern s32 D_001DA650;
typedef struct Config_003C8CE0 {
    unsigned char padding[0xC];
    short count;
    unsigned char padding2[2];
    unsigned char *buffer;
} Config_003C8CE0;
extern int D_001DA050;
extern Config_003C8CE0 *D_001DA5F0_003CE608;
extern int D_001DA600;
extern int D_001D4BB4;
extern int D_001D4BB0;
extern int D_001D9BFC;
extern u32 *D_001DA050_003CE678;
extern u32 *D_001DA600_003CE678;
extern u32 *D_001DA604_003CE678;
extern s32 D_001D4BB0_003CE678;
extern s32 D_001D4BB4_003CE678;
extern void func_003A06E8();
extern s32 func_003A99D0();

LINKER_REMNANT("asm/boot_elf/remnants", func_003CE790);

/* localdecomp:start func_003CE798 */
typedef struct { u16 pad; u16 flags; } Q_3C8E70;
typedef struct { u8 pad[6]; s16 n; u8 pad2[0x18]; Q_3C8E70 *arr[1]; } P_3C8E70;
extern P_3C8E70 *D_001DA5F0[];
extern void func_003CE9A0(Q_3C8E70 *);
extern void func_003CE7F8(Q_3C8E70 *);
void func_003CE798(s32 i) {
    P_3C8E70 *p = D_001DA5F0[0];
    if (i < p->n) {
        Q_3C8E70 *q = p->arr[i];
        if (q->flags & 1) func_003CE9A0(q);
        else func_003CE7F8(q);
    }
}
/* localdecomp:end func_003CE798 */

typedef struct { u8 pad[0x10]; u8 *base; s16 h14; s16 h16; s16 h18; s16 h1A; s16 h1C; s16 h1E; } E_3C8ED0;
typedef struct { s16 n; u16 flags; u8 pad[0xC]; E_3C8ED0 items[1]; } S_3C8ED0;
extern u32 *D_001DA050_003CE7F8;
extern s32 D_001D9348;
extern u8 D_001423C0[];
extern u8 D_00142350[];
extern void func_003CF0C0(E_3C8ED0 *, s32, u8 *);
extern void func_003CEB38(void);
extern s32 func_003CEBE0(u8 *, u8 *, s32);
extern s32 func_003CEDD8(s32, u8 *, u8 *, u8 *, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003CE7F8);

typedef E_3C8ED0 E_3C9078;
typedef struct { s16 n; u16 flags; u8 pad[0xC]; E_3C9078 items[1]; } S_3C9078;
extern u32 *D_001DA050_003CE9A0;
extern u8 D_1422E0[];
extern s32 D_1A1ED0[];
extern void func_003CF0C0(E_3C9078 *, s32, u8 *);
extern void func_003CEB38(void);
extern s32 func_003CEBE0(u8 *, u8 *, s32);
extern void func_003CECD8(s32, u8 *, u8 *, u8 *);
extern void func_003A97F8(s32, unsigned long);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003CE9A0);

LINKER_REMNANT("asm/boot_elf/remnants", func_003CEB30);
