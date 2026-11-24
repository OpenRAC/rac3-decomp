#include "common.h"

/* localdecomp:start func_L01_0040E408 */
void func_L01_0040E408(f32 *dst, f32 *src, f32 f) {
    __asm__ __volatile__(
        ".set noat\n\t"
        "mfc1 $at, %2\n\t"
        "lqc2 $vf1, 0(%1)\n\t"
        "qmtc2.ni $at, $vf2\n\t"
        "vdiv Q, $vf0w, $vf2x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf1, $vf1, Q\n\t"
        "sqc2 $vf1, 0(%0)\n\t"
        ".set at"
        : : "r"(dst), "r"(src), "f"(f) : "$1", "memory");
}
/* localdecomp:end func_L01_0040E408 */
