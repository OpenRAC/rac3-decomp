#include "common.h"

/* localdecomp:start func_L04_00313D88 */
extern s32 D_L04_001DC558;
extern s32 D_L04_001DC578;

void *func_L04_00313D88(s32 arg0, s32 arg1, s32 *arg2) {
    switch (arg1) {                                 /* irregular */
    case 1:
        *arg2 = 0x1C;
        return &D_L04_001DC558;
    case 6:
        *arg2 = 4;
        return &D_L04_001DC578;
    default:
        return 0;
    }
}
/* localdecomp:end func_L04_00313D88 */

INCLUDE_ASM("asm/levels", func_L04_00313DD0);

/* localdecomp:start func_L04_00314F58 */
f32 func_L04_00314F58(void *arg0) {
    return (*(f32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x40));
}
/* localdecomp:end func_L04_00314F58 */

/* localdecomp:start func_L04_00314F68 */
void func_L04_00314F68(u8 *a0, u8 *a1) {
    u8 *v = *(u8 **)(a1 + 104);
    float x = *(float *)(v + 96);
    u8 *o = *(u8 **)(a0 + 104);
    if (0.0f <= x) *(float *)(o + 64) = x;
    else *(float *)(o + 64) = 0.0f;
    *(s32 *)(o + 96) = *(s32 *)(v + 32);
}
/* localdecomp:end func_L04_00314F68 */

/* localdecomp:start func_L04_00314FA0 */
extern void (**func_L01_0043B548())(int);

void func_L04_00314FA0(int a0) {
    (*func_L01_0043B548(6625, 108))(a0);
}
/* localdecomp:end func_L04_00314FA0 */
