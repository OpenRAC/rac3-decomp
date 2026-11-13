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

INCLUDE_ASM("asm/levels", func_L04_003E25F8);

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

INCLUDE_ASM("asm/levels", func_L04_003E2818);
