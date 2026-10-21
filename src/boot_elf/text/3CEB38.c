#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u8 pad[0x10]; u8 *base; s16 h14; s16 h16; s16 h18; s16 h1A; s16 h1C; s16 h1E; } E_3C8ED0;
extern void func_003CF0C0(E_3C8ED0 *, s32, u8 *);
extern void func_003CEB38(void);
extern s32 func_003CEBE0(u8 *, u8 *, s32);
extern s32 func_003CEDD8(s32, u8 *, u8 *, u8 *, s32);
typedef E_3C8ED0 E_3C9078;
extern void func_003CF0C0(E_3C9078 *, s32, u8 *);
extern void func_003CECD8(s32, u8 *, u8 *, u8 *);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/boot_elf/handwritten", func_003CEB38);

ASM_FUNC("asm/boot_elf/handwritten", func_003CEBE0);

ASM_FUNC("asm/boot_elf/handwritten", func_003CECD8);

ASM_FUNC("asm/boot_elf/handwritten", func_003CEDD8);

ASM_FUNC("asm/boot_elf/handwritten", func_003CF0C0);
