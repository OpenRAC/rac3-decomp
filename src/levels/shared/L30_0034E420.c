#include "common.h"

/* localdecomp:start func_L30_0034E420 */
extern void func_003C2F58(void *, s32, void *);
void func_L30_0034E420(void *a0, void *a1) {
    u8 *s = *(u8 **)((u8 *)a0 + 104);
    if (*(s32 *)(s + 20) == 1) {
        func_003C2F58(a0, 0, a1);
    }
    if (*(s32 *)(s + 20) == 4) {
        func_003C2F58(a0, 0, a1);
    }
    if (*(s32 *)(s + 20) == 3) {
        func_003C2F58(a0, 1, a1);
    }
    if (*(s32 *)(s + 20) == 2) {
        func_003C2F58(a0, 1, a1);
    }
}
/* localdecomp:end func_L30_0034E420 */

/* localdecomp:start func_L30_0034E4D0 */
extern s32 D_L30_001DD4F0[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD4F0, 4");
extern s32 D_L30_001DD500[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD500, 4");
extern s32 D_L30_001DD510[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD510, 4");
extern s32 D_L30_001DD520[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD520, 4");
s32 func_L30_0034E4D0(void *a0, u32 a1) {
    u8 *s = *(u8 **)((u8 *)a0 + 104);
    if (a1 >= 3) {
        return 0;
    }
    if (*(s32 *)(s + 20) == 1) {
        return D_L30_001DD4F0[a1];
    }
    if (*(s32 *)(s + 20) == 4) {
        return D_L30_001DD500[a1];
    }
    if (*(s32 *)(s + 20) == 3) {
        return D_L30_001DD510[a1];
    }
    if (*(s32 *)(s + 20) == 2) {
        return D_L30_001DD520[a1];
    }
    return 0;
}
/* localdecomp:end func_L30_0034E4D0 */
