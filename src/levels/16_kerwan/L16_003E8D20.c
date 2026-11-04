#include "common.h"

INCLUDE_ASM("asm/levels", func_L16_003E8D20);

INCLUDE_ASM("asm/levels", func_L16_003E8DC0);

INCLUDE_ASM("asm/levels", func_L16_003E9068);

INCLUDE_ASM("asm/levels", func_L16_003E91B0);

INCLUDE_ASM("asm/levels", func_L16_003E92B8);

INCLUDE_ASM("asm/levels", func_L16_003E93F8);

/* localdecomp:start func_L16_003E95A8 */
extern void func_L01_004048D0(void *, u8 *);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_004450F0(s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L16_003E93F8();
extern u8 D_1A4C60[];

void func_L16_003E95A8(u8 *o) {
    s32 k = o[0x20];
    f32 d;

    switch (k) {
    case 0:
        func_L01_004450F0((s32)o, 1, -1);
        break;
    case 1:
        func_L01_004048D0(func_L16_003E93F8, o);
        d = func_0038CF38(D_1A4C60, o + 0x10);
        if (40.0f < d) {
            func_L01_004450F0((s32)o, 2, -1);
        }
        break;
    case 2:
        func_003C2880(o);
        break;
    }
}
/* localdecomp:end func_L16_003E95A8 */

INCLUDE_ASM("asm/levels", func_L16_003E9660);

INCLUDE_ASM("asm/levels", func_L16_003E9ED8);
