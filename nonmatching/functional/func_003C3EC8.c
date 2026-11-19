/* functional: high. US draft checked against PAL asm (both branches, argument registers f12/f13/f14, the vmr32+sqc2 quad store to out when non-null, returns). Draft's volatile casts and builtin fabs replaced with plain reads and fabs_asm (abs.s). 41 words differ in scheduling. */
#include "vu0.h"
extern s32 D_001D99C0;
extern s32 D_001D99A8;
extern f32 D_001D99B8;
extern f32 D_001D99BC;
extern f32 D_001D99B0[];
extern s32 func_00381D50();
extern f32 func_0038CF38();
f32 func_003C3EC8(f32 *p, void *out) {
    f32 t;
    if (D_001D99C0 != 0) {
        t = p[2];
        if (((s32 (*)(f32 *, f32, f32, f32))func_00381D50)(&t, p[0], p[1], p[2]) != 0) return t;
    }
    if (D_001D99A8 != 0) {
        if (fabs_asm(p[2] - D_001D99B8) < 0.5f && func_0038CF38(p, D_001D99B0) < D_001D99BC) {
            if (out != 0) {
                __asm__ __volatile__("vmr32.xyzw $vf1, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(out) : "memory");
            }
            return D_001D99B8;
        }
    }
    if (out != 0) {
        __asm__ __volatile__("vmr32.xyzw $vf1, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(out) : "memory");
    }
    return p[2];
}
