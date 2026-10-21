#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void func_003DDB20(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern u32 func_003DEC38(u32, u32, s32, void *);
extern s32 func_003DEDB0(s32, s32, s32);
extern void func_003DCFA8(s32);
void func_003DB148();
void func_003DC518();
void func_003DD258();
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003DA1E0);

ASM_FUNC("asm/boot_elf/handwritten", func_003DB11C);

ASM_FUNC("asm/boot_elf/handwritten", func_003DB148);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003DBA38);

ASM_FUNC("asm/boot_elf/handwritten", func_003DC4C8);

ASM_FUNC("asm/boot_elf/handwritten", func_003DC4F0);

ASM_FUNC("asm/boot_elf/handwritten", func_003DC518);

ASM_FUNC("asm/boot_elf/handwritten", func_003DCF54);

ASM_FUNC("asm/boot_elf/handwritten", func_003DCF7C);

ASM_FUNC("asm/boot_elf/handwritten", func_003DCFA8);

ASM_FUNC("asm/boot_elf/handwritten", func_003DD258);

ASM_FUNC("asm/boot_elf/handwritten", func_003DD9A0);

ASM_FUNC("asm/boot_elf/handwritten", func_003DD9C8);

ASM_FUNC("asm/boot_elf/handwritten", func_003DDAE8);

ASM_FUNC("asm/boot_elf/handwritten", func_003DDB20);

ASM_FUNC("asm/boot_elf/handwritten", func_003DEC10);

ASM_FUNC("asm/boot_elf/handwritten", func_003DEC38);

ASM_FUNC("asm/boot_elf/handwritten", func_003DEDB0);

ASM_FUNC("asm/boot_elf/handwritten", func_003DEEB8);

ASM_FUNC("asm/boot_elf/handwritten", func_003DEFCC);
