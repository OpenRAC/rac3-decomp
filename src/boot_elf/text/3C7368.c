#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C7FF0();
extern void func_003C8190();
extern s32 func_003C76C8();
extern void func_003C7838();
extern void func_003C7D10();
extern void func_003C7398();
extern void func_003CA858();
extern void func_003CB408();
extern void func_003CB6B8();
extern void *func_003CB798(s32, void *, s32, s32);
extern void func_003C8ED0();
extern void func_003C7368(s32, s32 *, s32 *, s32 *);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/boot_elf/handwritten", func_003C7368);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C7398);

ASM_FUNC("asm/boot_elf/handwritten", func_003C76C8);

ASM_FUNC("asm/boot_elf/handwritten", func_003C7838);

ASM_FUNC("asm/boot_elf/handwritten", func_003C7908);

ASM_FUNC("asm/boot_elf/handwritten", func_003C7AC8);

ASM_FUNC("asm/boot_elf/handwritten", func_003C7C38);

ASM_FUNC("asm/boot_elf/handwritten", func_003C7C98);

ASM_FUNC("asm/boot_elf/handwritten", func_003C7D10);

ASM_FUNC("asm/boot_elf/handwritten", func_003C7FF0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C818C);

ASM_FUNC("asm/boot_elf/handwritten", func_003C8190);

ASM_FUNC("asm/boot_elf/handwritten", func_003C81D8);

ASM_FUNC("asm/boot_elf/handwritten", func_003C8ED0);

ASM_FUNC("asm/boot_elf/handwritten", func_003C9BA8);

ASM_FUNC("asm/boot_elf/handwritten", func_003CA858);

ASM_FUNC("asm/boot_elf/handwritten", func_003CA9C0);

ASM_FUNC("asm/boot_elf/handwritten", func_003CB408);

ASM_FUNC("asm/boot_elf/handwritten", func_003CB6B8);

ASM_FUNC("asm/boot_elf/handwritten", func_003CB798);

ASM_FUNC("asm/boot_elf/handwritten", func_003CD1D8);
