#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3AFC48.c's earlier functions */
extern s32 D_001DA088_003AFC48;
extern s32 D_001DA0B4_003AFC48;
extern s32 D_001DA0B8_003AFC48;
extern s32 D_001D4D40;
extern s32 func_003AFE10();

typedef struct { u8 p0[0x1A0]; s32 f1A0; s32 f1A4; } P_3AA4B0;
extern P_3AA4B0 *D_001D52FC_003AFE10;
extern s32 D_001D4D40;
extern volatile s32 D_1DA0CC;
extern s32 D_001DA088_003AFC48;
extern s32 D_001DA0B4_003AFC48;
extern s32 D_001DA0B8_003AFC48;
extern void func_003A3F70(void);
extern void func_003B04E8();
extern void func_003B29D8(void *);
extern s32 func_003B16E0(u8 *, void **);
extern s32 func_003B17F8();
extern void func_003B1710(u8 *, s32);
extern s32 func_003B1750(u8 *, u8 **);
extern s32 func_00139A70(void *, u8 *, s32, u8 *, s32);
extern s32 func_003B1790();
extern void func_003B0400(void);
extern s32 func_003B3020(void *);
extern s32 func_003B0160_003AFE10(void);
extern void func_003B1348(s32);
extern s32 func_003B29E8(void *);
extern s32 func_003B2A68();
extern s32 func_003B2B38(void *);
extern void func_003B1398(void);
extern void func_003B0588(s32 *);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AFE10);
