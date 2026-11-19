#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3BE068.c's earlier functions */
extern s32 D_001D8CFC;
extern s32 D_001D8CF8;
extern void func_003BE0C0(void);

typedef struct { u8 pad[0x64]; s32 f64; } S_16C580_3B8840;
extern S_16C580_3B8840 D_16C580_003BE0F0;
extern u8 D_001DA290_003BE0F0[1];
extern s32 D_001DA268_003BE0F0[2];
extern s32 func_00382848(s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BE0F0);
