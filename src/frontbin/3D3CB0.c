#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern s32 func_003D3CB0();
extern s32 func_003D5630(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BE7F0;
s32 func_003D3CB0(V_3BE7F0 *, V_3BE7F0 *, s32, s32, s32);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/handwritten", func_003D3CB0);

ASM_FUNC("asm/handwritten", func_003D4D00);

ASM_FUNC("asm/handwritten", func_003D5630);

LINKER_REMNANT("asm/remnants", func_003D5660);

ASM_FUNC("asm/handwritten", func_003D5668);
