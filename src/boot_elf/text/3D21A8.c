#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003D21E0(f32 *, f32 *);
extern void func_003D2738(s32, s32);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/boot_elf/handwritten", func_003D21A8);

ASM_FUNC("asm/boot_elf/handwritten", func_003D21AC);

ASM_FUNC("asm/boot_elf/handwritten", func_003D21E0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D2278);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D2468);

ASM_FUNC("asm/boot_elf/handwritten", func_003D2620);

ASM_FUNC("asm/boot_elf/handwritten", func_003D2630);

ASM_FUNC("asm/boot_elf/handwritten", func_003D26EC);

ASM_FUNC("asm/boot_elf/handwritten", func_003D2738);

ASM_FUNC("asm/boot_elf/handwritten", func_003D2860);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D28D8);

ASM_FUNC("asm/boot_elf/handwritten", func_003D2ABC);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D2B78);

ASM_FUNC("asm/boot_elf/handwritten", func_003D2D98);

ASM_FUNC("asm/boot_elf/handwritten", func_003D2DD0);

ASM_FUNC("asm/boot_elf/handwritten", func_003D2E38);

ASM_FUNC("asm/boot_elf/handwritten", func_003D2E70);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D2EBC);

ASM_FUNC("asm/boot_elf/handwritten", func_003D2EC0);
