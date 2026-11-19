#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_0038D810 */
/* from boot_elf's twin func_0038DBF0, with the pointers as operands */
void func_0038D810(void *in, void *out) {
    __asm__ __volatile__(
        "lqc2 $vf8, 0(%0)\n"
        "vcallms 0xE98\n"
        "vnop\n"
        "sqc2 $vf14, 0(%1)\n"
        "sqc2 $vf15, 16(%1)\n"
        "sqc2 $vf16, 32(%1)\n"
        : : "r"(in), "r"(out) : "memory");
}
/* localdecomp:end func_0038D810 */
