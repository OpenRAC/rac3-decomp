#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 39E5E0.c's earlier functions */
extern u8 D_00332388[];
extern u8 D_00332618[];
extern s32 func_0039E7C8();
extern s32 func_0039E7C8(u8 *dst, s32 n, s32 *e);

extern s32 func_0039EC28(s32, s32);
typedef struct { u8 b[8]; } V8_399C90;
typedef struct { s32 f0, f4, f8, fC; V8_399C90 f10; s32 f18; } E_399C90;
typedef struct { u8 p0[0x18]; s16 h18; u8 p1a[0x16]; E_399C90 e[4]; u8 pA0[0xA8]; s32 f148; s32 f14C; s32 f150; u8 p154[8]; s32 f15C; u8 p160[4]; s32 f164; s32 f168; u8 p16C[0x10]; s32 f17C; } S_399C90;
typedef struct { s32 f0; u8 p4[0x2E]; u8 b32; } T_399C90;
extern S_399C90 D_142430_0039EC28;
extern T_399C90 D_142660_0039EC28;
extern s32 D_001D4CF0;
extern u32 D_001D545C;
extern s32 D_001D5528;
extern s32 D_001D4CEC_0039EC28;
extern V8_399C90 D_1D4BE0;
extern u8 D_1A9318[];
extern u8 D_001D5570[8];
extern u8 D_001C5BD0[];
extern u8 D_001CBBD0[];
extern u8 D_00332388[];
extern u8 D_00332618[];
extern void func_003A0090();
INCLUDE_ASM("asm/nonmatchings/text", func_0039EC28);
