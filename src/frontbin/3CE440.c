#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3CE2C0.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u16 pad; u16 flags; } Q_3C8E70;
extern void func_003CE5E8(Q_3C8E70 *);
extern void func_003CE440(Q_3C8E70 *);

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
