#include "common.h"

INCLUDE_ASM("asm/levels", func_L22_003B6D30);

INCLUDE_ASM("asm/levels", func_L22_003B6EE8);

INCLUDE_ASM("asm/levels", func_L22_003B7150);

INCLUDE_ASM("asm/levels", func_L22_003B71D0);

/* localdecomp:start func_L22_003B72F0 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern void func_L22_003B6EE8(u8 *a0, s32 a1);
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);

void func_L22_003B72F0(u8 *moby, Vec4 *pos, s32 force, f32 value) {
    Vec4 v;
    u8 *vars;

    v = *pos;
    vars = *(u8 **)(moby + 104);
    if (force != 0 || moby[149] == 1) {
        func_L22_003B6EE8(moby, 0);
        *(Vec4 *)(vars + 1296) = v;
        *(f32 *)(vars + 1320) = value;
        func_L01_004450F0(moby, 30, 6);
    }
}
/* localdecomp:end func_L22_003B72F0 */
