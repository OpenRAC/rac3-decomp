#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_00124920(void);
extern s32 func_00124970(void);
extern s32 func_00124920();
extern s32 func_00124970();
extern void func_001245A0(void);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/boot_elf/handwritten", func_001245A0);

LINKER_REMNANT("asm/boot_elf/remnants", func_00124794);

ASM_FUNC("asm/boot_elf/handwritten", func_001247C0);

ASM_FUNC("asm/boot_elf/handwritten", func_00124920);

ASM_FUNC("asm/boot_elf/handwritten", func_00124970);
