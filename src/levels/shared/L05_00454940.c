#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_00454940);

/* localdecomp:start func_L05_00454970 */
extern s32 D_L05_001D673C;
extern f32 func_0038D160(f32, f32);
extern s32 func_L01_0045BD10(u8 *, f32);
extern u8 *func_L01_0045B958(u8 *);
extern f32 func_L01_0045CC18(u8 *, u8 *, f32 *, s32);
s32 func_L05_00454970(u8 *a0, f32 *a1) {
    u8 *p;
    if (D_L05_001D673C == 0) {
        return func_L01_0045BD10(a0, func_0038D160(a1[0], a1[1]));
    }
    p = func_L01_0045B958(a0);
    if (p == 0) {
        return 0;
    }
    if (*(f32 *)(p + 48) < func_L01_0045CC18(a0, p, a1, 0)) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L05_00454970 */
