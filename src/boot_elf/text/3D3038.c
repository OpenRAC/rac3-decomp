#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

ASM_FUNC("asm/boot_elf/handwritten", func_003D3038);

/* localdecomp:start func_003D30F8 */
/* Store the closest point on the segment and return the unclamped projection. */
f32 func_003D30F8(void *out, void *start, void *end, void *point) {
    f32 t;
    __asm__ __volatile__(
        "vaddw.xyz $vf24, $vf0, $vf0w\n\t"
        "lqc2 $vf1, 0(%2)\n\t"
        "lqc2 $vf2, 0(%3)\n\t"
        "lqc2 $vf3, 0(%4)\n\t"
        "vsub.xyz $vf4, $vf2, $vf1\n\t"
        "vsub.xyz $vf5, $vf3, $vf1\n\t"
        "vmul.xyz $vf6, $vf4, $vf4\n\t"
        "vmul.xyz $vf7, $vf4, $vf5\n\t"
        "vadday.x ACC, $vf6, $vf6y\n\t"
        "vmaddz.x $vf6, $vf24, $vf6z\n\t"
        "vadday.x ACC, $vf7, $vf7y\n\t"
        "vmaddz.x $vf7, $vf24, $vf7z\n\t"
        "vdiv Q, $vf7x, $vf6x\n\t"
        "vwaitq\n\t"
        "vaddq.x $vf8, $vf0, Q\n\t"
        "vminiw.x $vf7, $vf8, $vf0w\n\t"
        "qmfc2.ni $8, $vf8\n\t"
        "nop\n\t"
        "vmaxx.x $vf7, $vf7, $vf0x\n\t"
        "mtc1 $8, %0\n\t"
        "vmulax.xyz ACC, $vf4, $vf7x\n\t"
        "vmaddw.xyz $vf1, $vf1, $vf0w\n\t"
        "sqc2 $vf1, 0(%1)"
        : "=f"(t) : "r"(out), "r"(start), "r"(end), "r"(point) : "$8", "memory");
    return t;
}
/* localdecomp:end func_003D30F8 */
