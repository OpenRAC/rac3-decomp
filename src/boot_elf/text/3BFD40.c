#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3BF968.c's earlier functions */
extern f32 func_003828C0(f32, f32);
extern s32 func_00382878(s32, s32);
extern void func_003BFC98(s32 a0, u8 *src);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BFD40);
