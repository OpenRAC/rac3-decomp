#include "common.h"


/* localdecomp:start func_L30_0034DAC0 */
extern void func_L01_00424D88(s32);

void func_L30_0034DAC0(s32 *p) {
    if (*p != -1) {
        func_L01_00424D88(*p);
        *p = -1;
    }
}
/* localdecomp:end func_L30_0034DAC0 */

LINKER_REMNANT("asm/levels", func_L30_0034DB08);

/* localdecomp:start func_L30_0034DB30 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
extern f32 D_001A4C60[];
extern f32 D_L30_001DD4B8;
extern s32 func_003D3CB0(Vec4 *, Vec4 *, s32, u8 *, s32);
s32 func_L30_0034DB30(u8 *a0) {
    Vec4 v;
    f32 y = D_001A4C60[0];
    v.q = ((Vec4 *)(a0 + 16))->q;
    if (y < ((Vec4 *)(a0 + 16))->f[0]) {
        v.f[0] = y - D_L30_001DD4B8;
    } else {
        v.f[0] = y + D_L30_001DD4B8;
    }
    return func_003D3CB0(&v, (Vec4 *)(a0 + 16), 2, a0, 0) != 0;
}
/* localdecomp:end func_L30_0034DB30 */

/* localdecomp:start func_L30_0034DBA0 */
extern s32 func_00382498(s32, s32);

s32 func_L30_0034DBA0(s32 a, s32 b) {
    s32 a0 = (a >> 24) & 0xFF;
    s32 a1 = (a >> 16) & 0xFF;
    s32 a2 = (a >> 8) & 0xFF;
    s32 a3 = a & 0xFF;
    s32 b0 = (b >> 24) & 0xFF;
    s32 b1 = (b >> 16) & 0xFF;
    s32 b2 = (b >> 8) & 0xFF;
    s32 b3 = b & 0xFF;
    s32 c0 = func_00382498(a0, b0);
    s32 c1 = func_00382498(a1, b1);
    s32 c2 = func_00382498(a2, b2);
    s32 c3 = func_00382498(a3, b3);
    return (c0 << 24) | (c1 << 16) | (c2 << 8) | c3;
}
/* localdecomp:end func_L30_0034DBA0 */
