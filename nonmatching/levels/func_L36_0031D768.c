/* func_L36_0031D768: near miss, level 36 (Vidcomic 1 Special Edition). 11 differences (needs -mvu0-use-vf0-vf2 and @ps2as on L36_0031D768.c, which has no C; the vmr32 line is a local asm for a VU0 op the helpers lack): every instruction is right, only the order differs: retail stores d to w (sqc2) and copies the old quadword (sq) later, and stores the vadd result after the w copy; ours stores the vadd result first. Statement orders and an early u128 temporary tried (worse) */
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
extern s32 func_0038CAD0(u8 *);
extern void func_L36_0031D878(u8 *);
extern u8 D_L36_001E9540[];
typedef int u128_t __attribute__((mode(TI)));
void func_L36_0031D768(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 old;
    vu0_v4 w;
    vu0_v4 t;
    vu0_v4 d;
    u8 *g;
    if (s != 0) {
        vec_copy(&t, a0 + 0x10);
        old = *(vu0_v4 *)(a0 + 0x10);
        {
            vu0_q q;
            __asm__("vmr32.xyzw %0, $vf0" : "=j"(q));
            __asm__("sqc2 %1, %0" : "=m"(d) : "j"(q));
        }
        vec_add_ab(a0 + 0x10, &t, s);
        vec_copy(&w, &d);
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
