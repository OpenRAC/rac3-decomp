#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

extern s32 D_001D99C0;
extern s32 D_001D99A8;
extern f32 D_001D99B8;
extern f32 D_001D99BC;
extern f32 D_001D99B0[];
extern s32 func_00381C60();
extern f32 func_0038D318();
/* localdecomp:start func_003C4280 */
extern f32 D_001D99B8_003C4280 __attribute__((section(".data")));
f32 func_003C4280(f32 *p, void *out) {
    f32 t;
    if (D_001D99C0 != 0) {
        t = p[2];
        if (((s32 (*)(f32 *, f32, f32, f32))func_00381C60)(&t, p[0], p[1], p[2]) != 0) return t;
    }
    if (D_001D99A8 != 0) {
        if (__builtin_fabsf(p[2] - D_001D99B8_003C4280) < 0.5f && func_0038D318(p, D_001D99B0) < D_001D99BC) {
            if (out != 0) {
                __asm__ __volatile__("vmr32.xyzw $vf1, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(out) : "memory");
            }
            return D_001D99B8_003C4280;
        }
    }
    if (out != 0) {
        __asm__ __volatile__("vmr32.xyzw $vf1, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(out) : "memory");
    }
    return p[2];
}
/* localdecomp:end func_003C4280 */
