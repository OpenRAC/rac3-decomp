#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3C4B40.c's earlier functions */
extern void func_0038CF68(s32 a, s32 b, f32 x);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C5110(void *a, f32 *out, s32 f);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BFC18;
typedef int Q_3BFC18 __attribute__((mode(TI)));
extern s32 D_001D5BEC_003C5180;
extern s32 D_001D5BF0;
typedef struct { u8 p0[0xB0]; V4_3BFC18 v; } S_3BFC18;
extern S_3BFC18 D_001A4BE0;
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C5110(void *, f32 *, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003C5180);
