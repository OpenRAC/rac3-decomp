#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3CE790.c's earlier functions */
typedef struct { u16 pad; u16 flags; } Q_3C8E70;
extern void func_003CE9A0(Q_3C8E70 *);
extern void func_003CE7F8(Q_3C8E70 *);

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
