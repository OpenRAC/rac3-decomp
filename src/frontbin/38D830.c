#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038D830(void *, void *);
extern void func_0038D850(void *, void *, void *);
/* --- end of declarations from other files --- */

/* localdecomp:start func_0038D830 */
/* the boot_elf twin func_0038DC10's VU0 block, with the pointers as operands (func_0038D810 with
   the fourth row stored from vf0) */
void func_0038D830(void *in, void *out) {
    __asm__ __volatile__(
        "lqc2 $vf8, 0(%0)\n"
        "vcallms 0xE98\n"
        "vnop\n"
        "sqc2 $vf14, 0(%1)\n"
        "sqc2 $vf15, 16(%1)\n"
        "sqc2 $vf16, 32(%1)\n"
        "sqc2 $vf0, 48(%1)\n"
        : : "r"(in), "r"(out) : "vf8", "vf9", "vf10", "vf11", "vf12", "vf13", "vf14", "vf15", "vf16", "memory");
}
/* localdecomp:end func_0038D830 */

ASM_FUNC("asm/handwritten", func_0038D850);

LINKER_REMNANT("asm/remnants", func_0038D888);

ASM_FUNC("asm/handwritten", func_0038D890);
