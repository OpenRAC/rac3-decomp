#include "common.h"

/* localdecomp:start func_L07_003D2680 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_003BCFB0(s32 a, s32 b);
extern f32 func_00388770(f32 *v);
extern void func_L01_004475D0(u8 *m);
extern void func_L01_00441FB8(u8 *m, s32 a, s32 b);
extern f32 func_0037E2A8(void);
extern f32 func_00388A28(f32 a, f32 b);
extern f32 func_003887A0(f32 *v);
extern void func_00388BD0(u8 *a, u8 *b);
extern void func_00388550(void *d, void *s, s32 n);
extern void func_003C26C8(u8 *m);
extern s32 D_L07_001DE7F8;
__asm__(".extern D_L07_001DE7F8, 4");

u8 *func_L07_003D2680(u8 *a0, u8 *a1, f32 *a2, u8 a3, f32 f) {
    u8 *m;
    u8 *v;

    m = func_003BCFB0(0x1C81, 128);
    if (m != 0) {
        m[48] = 255;
        *(s16 *)(m + 50) = 255;
        m[49] = 1;
        *(u8 **)(m + 184) = a0;
        m[32] = 0;
        v = *(u8 **)(m + 104);
        func_L01_004475D0(m);
        *(u128_t *)(m + 16) = *(u128_t *)a1;
        *(u128_t *)(v + 16) = *(u128_t *)a2;
        *(f32 *)(v + 8) = func_00388770(a2);
        *(f32 *)(v + 4) = f;
        v[12] = a3;
        func_L01_00441FB8(m, 1, -1);
        *(s32 *)v = 100;
        *(u16 *)(m + 52) |= 0x100;
        *(f32 *)(m + 240) = func_0037E2A8();
        *(f32 *)(m + 248) = func_00388A28(a2[0], a2[1]);
        *(f32 *)(m + 244) = -func_00388A28(func_003887A0(a2), a2[2]);
        func_00388BD0(m + 192, m + 240);
        *(f32 *)(m + 44) = *(f32 *)(*(u8 **)(m + 36) + 36) * 1.25f;
        func_00388550(v + 48, &D_L07_001DE7F8, 16);
        func_003C26C8(m);
    }
    return m;
}
/* localdecomp:end func_L07_003D2680 */
