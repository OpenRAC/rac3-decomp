#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_003E2550 */
extern void func_L01_00456C98(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L04_003E2550(s32 a0, u8 *a1, s32 a2) {
    if (a2) {
        func_L01_00456C98(a0, *(s32 *)(a1 + 88), 0, 0, 1, 1, 3, 0, 0, 0,
                      *(f32 *)(a1 + 92), *(f32 *)(a1 + 92) + *(f32 *)(a1 + 92), 1.0f);
    } else {
        func_L01_00456C98(a0, *(s32 *)(a1 + 80), 0, 0, 1, 1, 3, 0, 0, 0,
                      *(f32 *)(a1 + 84), *(f32 *)(a1 + 84) + *(f32 *)(a1 + 84), 1.0f);
    }
    return *(s16 *)(a1 + 76) != 0;
}
/* localdecomp:end func_L04_003E2550 */

/* localdecomp:start func_L04_003E25F8 */
extern f32 func_0038DB00(f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
__asm__(".extern D_L04_001DF04C, 4");
extern f32 D_L04_001DF04C;
__asm__(".extern D_L04_001DF050, 4");
extern f32 D_L04_001DF050;
__asm__(".extern D_L04_001DF054, 4");
extern f32 D_L04_001DF054;
__asm__(".extern D_L04_001DF058, 4");
extern f32 D_L04_001DF058;

void func_L04_003E25F8(void *a0, u8 *a1) {
    f32 k = 1.44f;
    f32 d;
    f32 x;
    f32 y;
    d = func_0038DB00(*(f32 *)(a1 + 0x64), *(f32 *)((u8 *)a0 + 0xF8));
    x = D_L04_001DF04C * k;
    y = D_L04_001DF050 * k;
    *(f32 *)(a1 + 0xD8) = d;
    func_L01_0044E850(a0, a1 + 0x70, 0, x, y);
    x = D_L04_001DF054 * k;
    y = D_L04_001DF058 * k;
    *(f32 *)(a1 + 0x150) = *(f32 *)(a1 + 0x68);
    func_L01_0044E850(a0, a1 + 0xF0, 2, x, y);
    x = D_L04_001DF054 * k;
    y = D_L04_001DF058 * k;
    *(f32 *)(a1 + 0x1D0) = *(f32 *)(a1 + 0x68) * 0.35f;
    func_L01_0044E850(a0, a1 + 0x170, 3, x, y);
}
/* localdecomp:end func_L04_003E25F8 */

/* localdecomp:start func_L04_003E26C8 */
extern void func_003C2F58(void *, s32, void *);
extern u8 *func_L01_0045B958(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_003824E0(f32, f32);
__asm__(".extern D_L04_001DF068, 4");
extern f32 D_L04_001DF068;
__asm__(".extern D_L04_001DF040, 4");
extern f32 D_L04_001DF040;

void func_L04_003E26C8(void *a0, u8 *a1) {
    vu0_v4 p;
    vu0_v4 t;
    vu0_v4 v;
    u8 *o;
    u8 *pos;
    f32 d;

    pos = a1 + 0x30;
    func_003C2F58(a0, 1, &p);
    t = *(vu0_v4 *)pos;
    if (*(void **)(a1 + 0x40) != 0) {
        o = func_L01_0045B958(*(void **)(a1 + 0x40));
        if (o != 0) {
            d = func_0038CF00(pos, &p);
            func_0038CE20(&v, o + 0xA0, d / D_L04_001DF068);
            vec_add_ab(&t, &t, &v);
        }
    }
    vec_sub_ab(&v, &t, &p);
    *(f32 *)(a1 + 0x64) = func_0038DAB8(func_0038D160(v.x, v.y), D_L04_001DF040 * 0.017453292f);
    *(f32 *)(a1 + 0x68) = -func_0038D160(func_0038CED8(&v), v.z);
    *(f32 *)(a1 + 0x64) = func_0038DAB8(*(f32 *)(a1 + 0x64), func_003824E0(-0.017453292f, 0.017453292f));
    *(f32 *)(a1 + 0x68) = func_0038DAB8(*(f32 *)(a1 + 0x68), func_003824E0(-0.017453292f, 0.017453292f));
}
/* localdecomp:end func_L04_003E26C8 */

/* localdecomp:start func_L04_003E2818 */
extern void func_003C2EC0(void *, s32, void *);
extern void func_L01_003B1750(void *, void *, void *, s32, s32, s32, s32, f32, f32);

void func_L04_003E2818(void *a0, u8 *a1) {
    vu0_v4 m[4];
    vu0_v4 a;
    vu0_v4 b;

    func_003C2EC0(a0, 1, m);
    vec_neg(&m[1], &m[1]);
    a = m[3];
    b = m[1];
    func_L01_003B1750(a0, &a, &b, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, *(f32 *)(a1 + 0x6C), 0.65f);
}
/* localdecomp:end func_L04_003E2818 */
