#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L22_003B6D30);

INCLUDE_ASM("asm/levels", func_L22_003B6EE8);

/* localdecomp:start func_L22_003B7150 */
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L22_003B7150(u8 *a0) {
    vu0_v4 v;
    u8 *s;
    f32 t = *(f32 *)(a0 + 0xC) / 500.0f;

    *(vu0_q *)&v = *(vu0_q *)(a0 + 0x10);
    v.z += t;
    s = *(u8 **)(a0 + 0x68);
    if (*(s32 *)(s + 0x46C) >= 0) {
        func_003D9508(&v, *(s32 *)(s + 0x46C) + 100, 0x7F7F7F7F, 0, 0.3f, 0.08f, 0.0f);
    }
}
/* localdecomp:end func_L22_003B7150 */

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
