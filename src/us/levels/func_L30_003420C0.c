#include "common.h"

/* NTSC-U counterpart of func_L30_00342D98 (src/levels/shared/L30_00342D98.c): 0.02 -> 0.0166667; 333 -> 400 */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L30_003420C0 */
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00452E70(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CED8(f32 *);
extern void func_0038CE20(void *, f32 *, f32);
extern void func_003C7C38(void *);
extern f32 D_L30_001DCE88;
__asm__(".extern D_L30_001DCE88, 4");
__asm__(".extern D_L30_001DCE8C, 4");
extern f32 D_L30_001DCE8C;
u8 *func_L30_003420C0(u8 *a, u128_t *b, f32 *v) {
    u8 *o = func_003C24B0(0x15AD, 0x80);
    u8 *st;
    f32 f, g;
    if (o != 0) {
        st = *(u8 **)(o + 0x68);
        func_L01_00452E70(o, a);
        *(s32 *)(st + 0x18) = -1;
        *(f32 *)(o + 0xF8) = func_0038DAB8(func_0038D160(v[0], v[1]), 1.5707964f);
        f = func_0038D160(func_0038CED8(v), v[2]);
        g = D_L30_001DCE88 * 0.0166666675f;
        *(f32 *)(o + 0xF0) = -f;
        func_0038CE20(st, v, g);
        *(u128_t *)(o + 0x10) = *b;
        *(u8 **)(st + 0x10) = a;
        *(u128_t *)(o + 0xF0) = *(u128_t *)(a + 0xF0);
        *(f32 *)(o + 0x2C) = *(f32 *)(o + 0x2C) * D_L30_001DCE8C;
        *(s32 *)(st + 0x14) = 0x190;
        o[0xBC] = 0;
        *(u16 *)(o + 0x34) |= 0x41;
        func_003C7C38(o);
    }
    return o;
}
/* localdecomp:end func_L30_003420C0 */
