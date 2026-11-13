#include "common.h"

/* localdecomp:start func_L39_005BC330 */
extern s32 D_L39_002429BC;
__asm__(".extern D_L39_002429BC, 16");
extern void func_0038CE20(f32 *, void *, f32);

void func_L39_005BC330(void *a0, void *a1, s32 a2) {
    if (D_L39_002429BC == 0) {
        __asm__ __volatile__(
            "vmr32.xyzw $vf1, $vf0\n"
            "sqc2 $vf1, 0(%0)\n"
            : : "r"(a1) : "memory");
    }
    if (a2 == 0) {
        func_0038CE20(a1, a1, -1.0f);
    }
}
/* localdecomp:end func_L39_005BC330 */
