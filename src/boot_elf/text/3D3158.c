#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003D3158();
extern void func_003D3DDC();
/* --- end of declarations from other files --- */

ASM_FUNC("asm/boot_elf/handwritten", func_003D3158);

ASM_FUNC("asm/boot_elf/handwritten", func_003D3718);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D3794);

ASM_FUNC("asm/boot_elf/handwritten", func_003D3798);

ASM_FUNC("asm/boot_elf/handwritten", func_003D37D8);

ASM_FUNC("asm/boot_elf/handwritten", func_003D3DDC);

ASM_FUNC("asm/boot_elf/handwritten", func_003D3FC8);
