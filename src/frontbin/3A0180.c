#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003A0760(u8 *, u32);
extern void func_003A02E8();
void func_003A0760(u8 *, u32);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/handwritten", func_003A0180);

INCLUDE_ASM("asm/nonmatchings/text", func_003A01C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A0258);
TEXT_PADDING(1);

/* 0x39B2DC is 4 bytes past an 8-byte boundary: GCC pads every C function to 8,
   so this can't be a C function (it's likely leftover bytes after the previous one). */
ASM_FUNC("asm/handwritten", func_003A02DC);  /* 4-byte aligned: cannot be a compiled C function (gcc aligns to 8) */

ASM_FUNC("asm/handwritten", func_003A02E8);

ASM_FUNC("asm/handwritten", func_003A04E8);

ASM_FUNC("asm/handwritten", func_003A0628);

ASM_FUNC("asm/handwritten", func_003A0760);

ASM_FUNC("asm/handwritten", func_003A0A30);

ASM_FUNC("asm/handwritten", func_003A0A50);

ASM_FUNC("asm/handwritten", func_003A0BC8);
