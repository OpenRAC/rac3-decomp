#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

extern s32 D_001A1ED4[];
extern s32 D_001DA0C0_003B0F70[2];
extern void func_003A1428_003B0F70(s32, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B0F70);
