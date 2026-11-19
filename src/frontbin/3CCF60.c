#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003CCF60();
extern void func_003CCF60(int, int);
/* --- end of declarations from other files --- */

typedef struct { u8 p[0x24]; } T36_3C79F0;
typedef struct { s32 k; s32 f4; T36_3C79F0 *f8; } E12_3C79F0;
extern E12_3C79F0 D_00380F00[];
extern T36_3C79F0 D_00380F0C[];
extern s32 D_001DA480;
extern s32 D_001DA484;
extern s32 D_002DD190[];
extern u8 D_002DD390[];
extern s32 D_002DAB00[];
extern u8 D_002DAEC0[];
INCLUDE_ASM("asm/nonmatchings/text", func_003CCF60);
