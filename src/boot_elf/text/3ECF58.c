#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003ECF58(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
/* --- end of declarations from other files --- */

typedef struct { u8 b[16]; } V16_003E7638;
extern s32 D_001D9730_003ECF58;
extern V16_003E7638 D_001D96C0_003ECF58;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003ECF58);
