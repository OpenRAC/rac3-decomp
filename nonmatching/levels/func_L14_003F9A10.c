#include "common.h"

/* localdecomp:start func_L14_003F9A10 */
void func_L14_003F9A10(void *dst, void *src, f32 scale) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0(%1)\n"
        "lqc2 $vf2, 16(%1)\n"
        "lqc2 $vf3, 32(%1)\n"
        "lqc2 $vf4, 48(%1)\n"
        "mfc1 $at, %2\n"
        "qmtc2.ni $at, $vf5\n"
        "vmulx.xyzw $vf1, $vf1, $vf5x\n"
        "vmulx.xyzw $vf2, $vf2, $vf5x\n"
        "vmulx.xyzw $vf3, $vf3, $vf5x\n"
        "vmulx.xyzw $vf4, $vf4, $vf5x\n"
        "sqc2 $vf1, 0(%0)\n"
        "sqc2 $vf2, 16(%0)\n"
        "sqc2 $vf3, 32(%0)\n"
        "sqc2 $vf4, 48(%0)\n"
        : : "r"(dst), "r"(src), "f"(scale) : "$1", "memory");
}
/* localdecomp:end func_L14_003F9A10 */
