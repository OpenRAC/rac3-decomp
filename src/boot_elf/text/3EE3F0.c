#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3EE290.c's earlier functions */
extern s32 *func_003E6FC0();
extern s32 func_003E74D0();
typedef struct { s32 a[0x12]; s32 x48; } S_E8;
typedef struct { u8 p[0x2C]; S_E8 *x2C; } T_E8;
extern u8 D_001D9708[8];
void **func_003E7078(s32 *, s32);
extern void func_003EE290(T_E8 *a0);

typedef struct { s32 *arr[16]; s32 x40; s32 x44; } O_3E8AD0;
typedef struct { u8 p0[8]; void *f8; u8 p1[0x2C - 0xC]; O_3E8AD0 *x2C; } T_3E8AD0;
typedef struct { u8 p0[4]; s32 f4; } S_3E8AD0;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); s32 (*fC)(); } VT_3E8AD0;
extern u8 D_001D9708[8];
extern u8 D_001D9670_003EE3F0[8];
extern S_3E8AD0 D_001DA938_003EE3F0[];
extern s32 *func_003E6FC0();
extern s32 **func_003E7078_003EE3F0();
extern s32 func_003E74D0();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EE3F0);
