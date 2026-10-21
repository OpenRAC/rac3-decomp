#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0038DBD8(s32, s32, f32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/handwritten", func_0038DBD8);

ASM_FUNC("asm/handwritten", func_0038DC20);

LINKER_REMNANT("asm/remnants", func_0038DD18);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DD20);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DE18);
