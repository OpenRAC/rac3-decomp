#include "common.h"

/* localdecomp:start func_U_L36_0031D218 */
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, u8 *, s32);
extern s32 func_00388398(u8 *);
extern void func_L36_0031D328(u8 *);
extern u8 D_L36_001E9540[];
void func_U_L36_0031D218(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 old;
    vu0_v4 w;
    u8 *pos;
    u8 *g;
    if (s != 0) {
        pos = a0 + 0x10;
        {
            vu0_q qp, qd, qs;
            __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)pos));
            old = *(vu0_v4 *)pos;
            __asm__("vmr32.xyzw %0, $vf0" : "=j"(qd));
            __asm__("lqc2 %0, %1" : "=j"(qs) : "m"(*(vu0_v4 *)s));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qs) : "j"(qs), "j"(qp));
            __asm__("sqc2 %1, %0" : "=m"(w) : "j"(qd));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)pos) : "j"(qs));
        }
        func_003886E8(&w, &w, 0.003055555745959282f);
        vec_sub_ab(s, s, &w);
        if (func_003CE740(&old, pos, 0x10, a0, 0) != 0) {
            g = D_L36_001E9540;
            if (*(s32 *)(g + 0x18) != 0 || *(s32 *)(g + 0x1C) > 0) {
                *(vu0_q *)pos = *(vu0_q *)(g + 0x20);
                *(f32 *)(a0 + 0x18) = *(f32 *)(a0 + 0x18) + 1.0f;
                func_L36_0031D328(a0);
            }
        } else if (func_00388398(s + 0x18) != 0) {
            func_L36_0031D328(a0);
        }
    }
}
/* localdecomp:end func_U_L36_0031D218 */
