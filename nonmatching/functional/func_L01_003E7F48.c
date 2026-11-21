/* functional: high. Camera ray-march side test: only for mode == 1, returns 1 when the vector from pos to the level-wide anchor D_001EAA20 points against the spring vector (follow block +0x180) (dot < 0), else 0. Retail does the subtraction on VU0 (lqc2/vsub.xyz/sqc2), kept as COP2 asm */
#include "vu0.h"
extern f32 func_0038CE68(f32 *, f32 *);
extern vu0_v4 D_L01_001EAA20;
s32 func_L01_003E7F48(u8 *obj, s32 mode, f32 *pos) {
    vu0_v4 d;
    f32 *w;
    if (mode == 1) {
        w = (f32 *)(*(u8 **)(obj + 0x70) + 0x180);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(d) : "m"(D_L01_001EAA20), "m"(*(vu0_v4 *)pos) : "vf1", "vf2");
        if (func_0038CE68((f32 *)&d, w) < 0.0f) {
            return 1;
        }
    }
    return 0;
}
