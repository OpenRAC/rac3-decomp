#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L34_0034EBE0);

INCLUDE_ASM("asm/levels", func_L34_0034F2E0);

/* localdecomp:start func_L34_0034F4B8 */
typedef int u128_t __attribute__((mode(TI)));

void func_L34_0034F4B8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 n = *(s32 *)(p + 0x80);
    *(u128_t *)(p + 0x50) = *(u128_t *)(a0 + 0x10);
    *(s32 *)(p + 0x88) = 0;
    *(s32 *)(p + 0x84) = 0;
    *(s32 *)(p + 0x80) = (n * 5 + 2) / 6;
    *(f32 *)(a0 + 0xF8) = -1.57079637050628662109375f;
}
/* localdecomp:end func_L34_0034F4B8 */

/* localdecomp:start func_L34_0034F500 */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L34_0034F500(u8 *a0) {
    vu0_v4 tmp;
    u8 *o;
    f32 ang;
    f32 s;
    f32 c;
    qzero(&tmp);
    o = *(u8 **)(a0 + 0x68);
    ang = *(f32 *)(o + 0x7C) * 0.5f * 3.14159274f;
    s = func_0038D098(ang);
    c = (1.0f - s) * *(f32 *)(o + 0x68);
    tmp.x = c;
    tmp.z = func_0038D0B0(ang) * *(f32 *)(o + 0x78);
    vec_add_ab(a0 + 0x10, o + 0x50, &tmp);
}
/* localdecomp:end func_L34_0034F500 */

/* localdecomp:start func_L34_0034F5A0 */
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L34_0034F5A0(u8 *a0) {
    vu0_v4 tmp;
    u8 *p = *(u8 **)(a0 + 0x68);

    qzero(&tmp);
    *(f32 *)&tmp = *(f32 *)(p + 0x68);
    func_0038CF68(&tmp, &tmp, *(f32 *)(p + 0x70));
    vec_add_ba(&tmp, a0 + 0x10, &tmp);
    if (func_003D3CB0(a0 + 0x10, &tmp, 2, a0, 0) != 0) {
        func_L01_004450F0(a0, 0x42, -1);
    } else {
        *(u128_t *)(a0 + 0x10) = *(u128_t *)&tmp;
    }
}
/* localdecomp:end func_L34_0034F5A0 */

/* localdecomp:start func_L34_0034F630 */
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L34_0034F630(u8 *a0) {
    f32 v[4];
    u8 *q = a0 + 0x10;
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 x, t;
    *(u128_t *)v = *(u128_t *)q;
    v[2] = *(f32 *)(s + 0x58) + *(f32 *)(s + 0x78) * *(f32 *)(s + 0x7C);
    x = *(f32 *)(s + 0x7C);
    t = func_0038D098(func_0038DB48((x + x) * 3.1415927410125732f + 1.5707963705062866f));
    v[0] = *(f32 *)(s + 0x50) + *(f32 *)(s + 0x68) * t;
    if (func_003D3CB0(q, v, 2, a0, 0) != 0) {
        func_L01_004450F0(a0, 0x42, -1);
    } else {
        *(u128_t *)q = *(u128_t *)v;
    }
}
/* localdecomp:end func_L34_0034F630 */
