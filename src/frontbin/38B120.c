#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

typedef int Q_3869E8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3869E8;
extern s32 D_001DA050;
extern Q_3869E8 D_001D76C0_0038B120[];
extern s32 D_001D4BD0_0038B120, D_001D4BD4_0038B120;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
INCLUDE_ASM("asm/nonmatchings/text", func_0038B120);

extern s32 D_001D4BD0_0038B4D0;
extern s32 D_001D4BD4_0038B4D0;
extern u8 D_001D76C0[];
INCLUDE_ASM("asm/nonmatchings/text", func_0038B4D0);
