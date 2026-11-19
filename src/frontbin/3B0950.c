#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3B0048.c's earlier functions */
extern void func_003B0950(s32 *);
extern void func_003B0728(u8 *o, s32 a, s32 b, s32 c);

typedef struct { s32 x0; u8 p4[0x14]; s32 x18; s32 x1C; u8 p20[0x14]; s32 x34; s32 x38; s32 x3C; s32 x40; u8 p44[0xC]; s32 x50; u8 p54[0xC]; s32 x60; } S_3AB3A8;
extern s32 func_13D1B0();
typedef struct { u8 pad[0x7F00]; u8 buf[0x100]; } S_2224A0;
extern S_2224A0 D_00222420;
extern u8 D_0022E320[];
INCLUDE_ASM("asm/nonmatchings/text", func_003B0950);
