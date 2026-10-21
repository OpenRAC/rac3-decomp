#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_0034B440);

INCLUDE_ASM("asm/levels", func_L03_0034B6C0);

/* localdecomp:start func_L03_0034BAF0 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 D_L03_001FC3D0[];
extern u8 *func_003C24B0(s32 a, s32 b);
extern void func_003C7C38(u8 *m);

u8 *func_L03_0034BAF0(u8 *a0, s32 a1) {
    u8 *m;

    if (D_L03_001FC3D0[a1] == 255) {
        return 0;
    }
    if (a1 == 0) {
        return 0;
    }
    m = func_003C24B0(a1, 128);
    if (m != 0) {
        *(u128_t *)(m + 16) = *(u128_t *)(a0 + 16);
        *(u128_t *)(m + 240) = *(u128_t *)(a0 + 240);
        *(long *)(m + 56) = *(long *)(a0 + 56);
        *(u8 *)(m + 48) = *(u8 *)(a0 + 48);
        *(s16 *)(m + 50) = *(u8 *)(a0 + 48);
        *(u8 **)(m + 184) = a0;
        *(u8 *)(m + 49) = 1;
        if (*(s32 *)(m + 36) != 0) {
            func_003C7C38(m);
        }
        return m;
    }
    return 0;
}
/* localdecomp:end func_L03_0034BAF0 */

INCLUDE_ASM("asm/levels", func_L03_0034BBA0);

INCLUDE_ASM("asm/levels", func_L03_0034BC80);
