#include "common.h"

typedef struct {
    s32 w0;
    s32 w4;
} S_34A460b;
typedef struct {
    u8 pad0[0x68];
    S_34A460b *p68;
} S_34A460;

INCLUDE_ASM("asm/levels", func_L04_00355740);

/* localdecomp:start func_L04_00355BF8 */


extern s32 func_0038CB00(s32 *a0);
extern void func_L01_00404A10_00355BF8(void (*a0)(void), S_34A460 *a1);
extern void func_L04_00355C60(void);
extern void func_003C2880(S_34A460 *a0);

void func_L04_00355BF8(S_34A460 *a0) {
    S_34A460b *t = a0->p68;
    if (func_0038CB00(&t->w0) == 0) {
        func_0038CB00(&t->w4);
        func_L01_00404A10_00355BF8(func_L04_00355C60, a0);
    } else {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L04_00355BF8 */

INCLUDE_ASM("asm/levels", func_L04_00355C60);

INCLUDE_ASM("asm/levels", func_L04_00355DE0);
