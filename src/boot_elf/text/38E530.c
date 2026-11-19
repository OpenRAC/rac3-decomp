#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0038E530(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 38E518.c's earlier functions */
extern u8 *D_001D5B38;
extern u8 *D_001D5B3C;
extern s32 D_001D55E8;

extern s32 D_001D55D0[];
extern s32 D_001D55D8[];
extern s32 D_001D55E0[];
extern s32 D_001D55C0;
extern s32 D_001D55C4_0038E530;
extern s32 D_001D55C8;
extern u8 D_0031CF50[];
extern u8 D_0031CFD0[];
extern u8 *D_001D5B38;
extern u8 *D_001D5B3C;
extern s32 D_001D55E8;
/* localdecomp:start func_0038E530 */
__asm__(".extern D_001D5B38, 4");
__asm__(".extern D_001D5B3C, 4");
__asm__(".extern D_001D55E8, 4");
extern s32 D_001D55D0_0038E530[2];
extern s32 D_001D55D8_0038E530[2];
extern s32 D_001D55E0_0038E530[2];
void func_0038E530(s32 index) {
    D_001D55E8 = index;
    D_001D55C0 = D_001D55D0_0038E530[index];
    D_001D55C4_0038E530 = D_001D55D8_0038E530[index];
    D_001D55C8 = D_001D55E0_0038E530[index];
    D_001D5B38 = D_0031CF50 + index * 64;
    D_001D5B3C = D_0031CFD0 + index * 64;
}
/* localdecomp:end func_0038E530 */
