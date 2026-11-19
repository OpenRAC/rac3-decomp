#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void *func_003E6FC0();
/* --- end of declarations from other files --- */

void func_0038CF58(void *, s32, s32);
typedef struct { u8 pad0[0x4]; u8 *f4; } S_001DA9B8_003E16B8;
extern S_001DA9B8_003E16B8 D_001DA938[];
extern u8 D_0031B750[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E6FC0);
