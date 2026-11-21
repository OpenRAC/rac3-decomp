#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

ASM_FUNC("asm/handwritten", func_0038DA10);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DA64);

/* localdecomp:start func_0038DA68 */
/* interpolates two 3x4 matrices: out = a * (1 - t) + b * t, row by row */
void func_0038DA68(void *out, void *a, void *b, f32 t) {
    __asm__ __volatile__(
        ".set noat\n"
        "mfc1 $at, %3\n"
        "qmtc2.ni $at, $vf7\n"
        ".set at\n"
        "vsubx.w $vf7, $vf0, $vf7x\n"
        "nop\n"
        "lqc2 $vf1, 0(%1)\n"
        "lqc2 $vf2, 16(%1)\n"
        "lqc2 $vf3, 32(%1)\n"
        "lqc2 $vf4, 0(%2)\n"
        "lqc2 $vf5, 16(%2)\n"
        "lqc2 $vf6, 32(%2)\n"
        "vmulaw.xyzw ACC, $vf1, $vf7w\n"
        "vmaddx.xyzw $vf1, $vf4, $vf7x\n"
        "vmulaw.xyzw ACC, $vf2, $vf7w\n"
        "vmaddx.xyzw $vf2, $vf5, $vf7x\n"
        "vmulaw.xyzw ACC, $vf3, $vf7w\n"
        "vmaddx.xyzw $vf3, $vf6, $vf7x\n"
        "sqc2 $vf1, 0(%0)\n"
        "sqc2 $vf2, 16(%0)\n"
        "sqc2 $vf3, 32(%0)\n"
        : : "r"(out), "r"(a), "r"(b), "f"(t) : "memory");
}
/* localdecomp:end func_0038DA68 */

