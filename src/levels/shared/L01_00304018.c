#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

/* localdecomp:start func_L01_00304018 */
extern u8 *func_003C24B0(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern void func_003C7C38(u8 *);
u8 *func_L01_00304018(s32 a0, u128_t *p, u128_t *q, s32 a3, u8 b0, u8 b1, u8 b2, u8 b3, f32 scale) {
    u8 *m;
    u8 *pv;
    Vec4 w;
    Vec4 v;
    m = func_003C24B0(1192, 128);
    if (m != 0) {
        pv = *(u8 **)(m + 104);
        v.q = 0;
        v.f[0] = func_003824E0(-3.1415927f, 3.1415927f);
        v.f[1] = func_003824E0(-3.1415927f, 3.1415927f);
        v.f[2] = func_003824E0(-3.1415927f, 3.1415927f);
        w = v;
        m[32] = 0;
        m[35] = b3;
        m[48] = 255;
        *(s16 *)(m + 50) = 255;
        m[49] = 1;
        func_L01_0043B9E8(m, b0, b1, b2);
        *(f32 *)(pv + 24) = *(f32 *)(m + 44) * scale;
        *(s32 *)(m + 44) = 0;
        *(s32 *)(pv + 16) = a0;
        *(u128_t *)(m + 16) = *p;
        *(u128_t *)pv = *q;
        *(Vec4 *)(m + 240) = w;
        *(s16 *)(pv + 30) = b3;
        *(s32 *)(pv + 20) = a3;
        *(u16 *)(pv + 28) = *(u16 *)(pv + 20);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L01_00304018 */

INCLUDE_ASM("asm/levels", func_L01_003041A0);
