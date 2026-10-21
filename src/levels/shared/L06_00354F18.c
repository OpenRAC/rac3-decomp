#include "common.h"

INCLUDE_ASM("asm/levels", func_L06_00354F18);

/* localdecomp:start func_L06_003550B0 */
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
extern void func_L06_00351930(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 t0);
s32 func_L06_003550B0(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    f32 f;
    if (a0[96] & 2) {
        func_L01_004450F0(a0, 1, 0);
        func_L06_00351930(a0, s1, 0, 0, 0);
        f = (*(f32 *)(s1 + 788) + *(f32 *)(s1 + 796)) * 0.5f;
        if (*(f32 *)(s1 + 616) < f) {
            *(f32 *)(s1 + 616) = f;
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_003550B0 */

/* localdecomp:start func_L06_00355148 */
extern void func_L06_00351930(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 t0);
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
extern int func_L01_004561E0(void *a0);
extern void func_L06_00353208(float f, void *a0, void *a1);

int func_L06_00355148(void *moby)
{
    char *pv = *(char **)((char *)moby + 104);

    if (func_L01_004561E0(moby)) {
        func_L06_00353208(*(float *)(pv + 824), moby, pv);
        *(int *)(pv + 824) = 0;
        ((void (*)(void *a0, int a1, int a2))func_L01_004450F0)(moby, 3, -1);
        return 1;
    }
    if (*(unsigned char *)((char *)moby + 32) == 15) {
        ((void (*)(void *a0, int a1, int a2))func_L01_004450F0)(moby, 1, 5);
        ((void (*)(void *a0, void *a1, int a2, int a3, int t0))func_L06_00351930)(moby, pv, 2, 0, 10);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00355148 */

INCLUDE_ASM("asm/levels", func_L06_003551E8);

INCLUDE_ASM("asm/levels", func_L06_003552F8);

INCLUDE_ASM("asm/levels", func_L06_00355610);

INCLUDE_ASM("asm/levels", func_L06_003558D0);

INCLUDE_ASM("asm/levels", func_L06_00355C20);

INCLUDE_ASM("asm/levels", func_L06_00355F90);

INCLUDE_ASM("asm/levels", func_L06_00356088);

INCLUDE_ASM("asm/levels", func_L06_003564A0);

INCLUDE_ASM("asm/levels", func_L06_003565B8);

INCLUDE_ASM("asm/levels", func_L06_003566B0);
