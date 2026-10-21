#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003A0B60(u8 *, u32);
extern void func_003A06E8();
extern void func_003A0658(void);
void func_003A0B60(u8 *, u32);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/boot_elf/handwritten", func_003A0580);

ASM_FUNC("asm/boot_elf/handwritten", func_003A05C0);

ASM_FUNC("asm/boot_elf/handwritten", func_003A0658);

/* 0x39B2DC is 4 bytes past an 8-byte boundary: GCC pads every C function to 8,
   so this can't be a C function (it's likely leftover bytes after the previous one). */

ASM_FUNC("asm/boot_elf/handwritten", func_003A06DC);

ASM_FUNC("asm/boot_elf/handwritten", func_003A06E8);

ASM_FUNC("asm/boot_elf/handwritten", func_003A08E8);

ASM_FUNC("asm/boot_elf/handwritten", func_003A0A28);

ASM_FUNC("asm/boot_elf/handwritten", func_003A0B60);

ASM_FUNC("asm/boot_elf/handwritten", func_003A0E30);

ASM_FUNC("asm/boot_elf/handwritten", func_003A0E50);

ASM_FUNC("asm/boot_elf/handwritten", func_003A0FC8);
