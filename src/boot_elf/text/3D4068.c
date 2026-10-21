#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern s32 func_003D4068();
extern s32 func_003D59E8(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BE7F0;
s32 func_003D4068(V_3BE7F0 *, V_3BE7F0 *, s32, s32, s32);
extern s32 func_003D50B8(void *, s32, void *, s32, f32);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/boot_elf/handwritten", func_003D4068);

ASM_FUNC("asm/boot_elf/handwritten", func_003D50B8);

ASM_FUNC("asm/boot_elf/handwritten", func_003D59E8);

LINKER_REMNANT("asm/boot_elf/remnants", func_003D5A18);

ASM_FUNC("asm/boot_elf/handwritten", func_003D5A20);
