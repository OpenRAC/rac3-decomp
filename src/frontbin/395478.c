#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 394F48.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u8 pad[0x58]; s32 w; s32 h; union { s32 flags; u8 c; } u; } S_38EDE8;
extern void func_00393808(void *);
extern s32 func_00393620(S_38EDE8 *p, s32 *x, s32 *y);
extern void func_00393808(void *arg);

INCLUDE_ASM("asm/nonmatchings/text", func_00395478);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C0C0);

LINKER_REMNANT("asm/remnants", func_00396240);
