#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003E4D10(s32);
/* --- end of declarations from other files --- */

typedef struct { s32 x0, x4, x8, xC; } S_3DF038;
extern S_3DF038 D_001DA938[];

/* localdecomp:start func_003E4D10 */
extern u8 D_001D9554;
extern u8 D_001D9566;
extern s32 D_001D9550;
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E4F30(s32);
extern void func_003E4EA8();
void func_003E4D10(s32 a) {
    if (D_001D9554 != 0 && D_001D9566 == 0) {
        D_001D9550 = a;
        func_003E7838(0x90000, 1, a != 0);
        func_003E4EA8(func_003E4F30(0));
    }
}
/* localdecomp:end func_003E4D10 */

LINKER_REMNANT("asm/remnants", func_003E4D60);
