#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C5810(void *, s32, f32, f32);
/* --- end of declarations from other files --- */

/* declarations of 3C5608.c's earlier functions */
extern void func_0038D348(s32 a, s32 b, f32 x);
extern void func_0038D200(f32 *, void *, f32);
extern void func_0038D348(s32, s32, f32);
extern void func_0038D270(f32 *, f32 *, s32);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C5810);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C59D8);
