/* functional: high. 6 diff: only the VU0 temp registers ($vf1/$vf2) are swapped in the first block, same operations and stores in the same order; uses COP2 asm helpers (needs vu0.h, -mvu0-use-vf0-vf2, @ps2as). */
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
extern s32 func_0038CAD0(u8 *);
extern void func_L36_0031D878(u8 *);
extern u8 D_L36_001E9540[];
typedef int u128_t __attribute__((mode(TI)));
static __inline__ vu0_q vadd_ab_q(void *a, void *b) {
    vu0_q qa, qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    return qr;
}
void func_L36_0031D768(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 old;
    vu0_v4 w;
    vu0_v4 t;
    vu0_v4 d;
    u8 *g;
    if (s != 0) {
        vec_copy(&t, a0 + 0x10);
        {
            vu0_q q;
            __asm__("vmr32.xyzw %0, $vf0" : "=j"(q));
            __asm__("sqc2 %1, %0" : "=m"(d) : "j"(q));
        }
        old = *(vu0_v4 *)(a0 + 0x10);
        {
            vu0_q r = vadd_ab_q(&t, s);
            vec_copy(&w, &d);
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(a0 + 0x10)) : "j"(r));
        }
        func_0038CE20(&w, &w, 0.0044f);
        vec_sub_ab(s, s, &w);
        if (func_003D3CB0(&old, a0 + 0x10, 0x10, a0, 0) != 0) {
            g = D_L36_001E9540;
            if (*(s32 *)(g + 0x18) != 0 || *(s32 *)(g + 0x1C) > 0) {
                *(u128_t *)(a0 + 0x10) = *(u128_t *)(g + 0x20);
                *(f32 *)(a0 + 0x18) = *(f32 *)(a0 + 0x18) + 1.0f;
                func_L36_0031D878(a0);
            }
        } else if (func_0038CAD0(s + 0x18) != 0) {
            func_L36_0031D878(a0);
        }
    }
}
