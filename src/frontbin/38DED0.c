#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

typedef struct { s16 x; s16 y; } P_3896E8;
typedef struct {
    u8 n0; u8 n1; u8 p2[0x2E];
    u8 k30[0x10];
    u8 k40[0x10];
    P_3896E8 pt[0x10];
    s32 o90[0x10];
    s32 oD0[0x10];
} T_3896E8;
extern T_3896E8 *D_001D55D0_0038DED0[2];
extern s32 D_001D9BC8_0038DED0;
extern s32 D_001D5B34;
extern u8 *D_001D5B38;
extern u8 *D_001D5B3C;
extern s32 D_001D5B30;
extern s32 D_001D55E8;
extern s32 D_0031CFD0_0038DED0[][16];
extern s32 D_0031CF50_0038DED0[][16];
extern s32 func_00389C48(s32 a, s32 b);
extern s32 func_00389B10(s32, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_0038DED0);
