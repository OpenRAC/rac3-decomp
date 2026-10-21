#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0038DFB8(s32, s32, f32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/boot_elf/handwritten", func_0038DFB8);

ASM_FUNC("asm/boot_elf/handwritten", func_0038E000);

LINKER_REMNANT("asm/boot_elf/remnants", func_0038E0F8);

ASM_FUNC("asm/boot_elf/handwritten", func_0038E100);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038E1F8);
