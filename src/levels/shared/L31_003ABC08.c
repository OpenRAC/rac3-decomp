#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L31_003ABC08);

INCLUDE_ASM("asm/levels", func_L31_003ABD70);

INCLUDE_ASM("asm/levels", func_L31_003ABF70);

/* localdecomp:start func_L31_003AC0B0 */

extern u8 *func_003C24B0(s32 a, s32 b);
extern void func_L01_00456160(u8 *m, s32 a);
extern void func_L01_00445F40(u8 *m, s32 a);
extern void func_003C7DD8(u8 *m);
extern f32 func_003824E0(f32 a, f32 b);
extern f32 func_0038DB48(f32 a);
extern void func_L01_004450F0(u8 *m, s32 a, s32 b);

u8 *func_L31_003AC0B0(u128_t *a0, u128_t *a1, s32 a2, s32 a3, s32 a4, s32 a5, f32 scale, f32 f1, f32 f2, f32 f3) {
    u8 *m;
    u8 *v;

    m = func_003C24B0(6948, 80);
    if (m != 0) {
        func_L01_00456160(m, 0);
        if (a2 >= 0) {
            func_L01_00445F40(m, a2);
        }
        *(u128_t *)(m + 16) = *a0;
        func_003C7DD8(m);
        *(u16 *)(m + 52) &= ~5;
        *(f32 *)(m + 244) = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        v = *(u8 **)(m + 104);
        *(f32 *)(m + 44) = scale * *(f32 *)(*(u8 **)(m + 36) + 36);
        *(u128_t *)v = *a1;
        *(s32 *)(v + 16) = a3;
        *(f32 *)(v + 24) = f1;
        *(s32 *)(v + 28) = a4;
        *(s32 *)(v + 32) = a5;
        *(f32 *)(v + 36) = f2;
        *(f32 *)(v + 40) = f3;
        *(s32 *)(v + 60) = -1;
        *(s32 *)(m + 152) = 0;
        func_L01_004450F0(m, 0, -1);
        return m;
    }
    return 0;
}
/* localdecomp:end func_L31_003AC0B0 */

/* localdecomp:start func_L31_003AC210 */
void func_L31_003AC210(u8 *obj, s32 a, s32 b, s32 c, s32 d, f32 e, f32 f, f32 g, f32 h) {
    u8 *p = *(u8 **)(obj + 104);
    *(f32 *)(p + 44) = e;
    *(s32 *)(p + 48) = a;
    *(s32 *)(p + 52) = c;
    *(s32 *)(p + 56) = b;
    *(s32 *)(p + 60) = d;
    *(f32 *)(p + 64) = f;
    *(f32 *)(p + 68) = g;
    *(f32 *)(p + 72) = h;
}
/* localdecomp:end func_L31_003AC210 */

INCLUDE_ASM("asm/levels", func_L31_003AC238);

INCLUDE_ASM("asm/levels", func_L31_003AC410);

INCLUDE_ASM("asm/levels", func_L31_003AC578);
