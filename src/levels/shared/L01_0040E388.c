#include "common.h"

/* localdecomp:start func_L01_0040E388 */
/* func_L01_0040E388: sets the quadword at a0 to (1, 1, 1, 1): vmaxw of vf0 with vf0.w (1.0). */
void func_L01_0040E388(void *a0) {
    __asm__ __volatile__(
        "vmaxw.xyzw $vf1, $vf0, $vf0w\n"
        "nop\n"
        "sqc2 $vf1, 0(%0)\n"
        : : "r"(a0) : "memory");
}
/* localdecomp:end func_L01_0040E388 */
