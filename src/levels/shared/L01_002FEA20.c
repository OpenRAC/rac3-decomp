#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L01_002FEA20);

/* localdecomp:start func_L01_002FFBC8 */
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern void func_003C2F58(u8 *, s32, u8 *);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_003C7C38(u8 *);
u8 *func_L01_002FFBC8(u8 *src, f32 f12) {
    u8 *m;
    u8 *pv;
    m = func_003C24B0(209, 128);
    if (m != 0) {
        pv = *(u8 **)(m + 104);
        *(u8 **)pv = src;
        *(f32 *)(pv + 4) = f12;
        m[49] = 0;
        m[48] = 255;
        *(s16 *)(m + 50) = 255;
        func_L01_0043B9E8(m, 128, 128, 128);
        func_003C2F58(src, 0, m + 16);
        *(u128_t *)(m + 192) = *(u128_t *)(src + 192);
        *(u128_t *)(m + 208) = *(u128_t *)(src + 208);
        *(u128_t *)(m + 224) = *(u128_t *)(src + 224);
        if (m[67] != 0)
            func_003C3A10(m, 0, 0, 8);
        func_003C7C38(m);
        m[32] = 0;
        *(u16 *)(m + 52) |= 5;
        m[49] = 0;
    }
    return m;
}
/* localdecomp:end func_L01_002FFBC8 */
