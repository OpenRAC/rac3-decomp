#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003D3158();
extern void func_003D3158(void *, s32, s32);
extern void func_003D3DDC();
/* --- end of declarations from other files --- */

ASM_FUNC("asm/boot_elf/handwritten", func_003D3158);

ASM_FUNC("asm/boot_elf/handwritten", func_003D3718);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D3794);

ASM_FUNC("asm/boot_elf/handwritten", func_003D3798);

ASM_FUNC("asm/boot_elf/handwritten", func_003D37D8);

ASM_FUNC("asm/boot_elf/handwritten", func_003D3DDC);

ASM_FUNC("asm/boot_elf/handwritten", func_003D3FC8);
