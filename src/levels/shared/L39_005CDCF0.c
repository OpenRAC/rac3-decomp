#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005CDCF0);

/* localdecomp:start func_L39_005CDE10 */
extern s32 func_0038CB00(void *);
extern void func_003CD250(u8 *);

void func_L39_005CDE10(u8 *a0) {
    u8 *q = a0 + 0x20;

    if (*(s32 *)(q + 0x10) == 1 && *(u8 **)(q + 0x14) != 0) {
        __asm__ __volatile__(
            "lqc2 $vf1, 0x10(%0)\n"
            "lqc2 $vf2, 0x20(%1)\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, 0x10(%1)\n"
            : : "r"(*(u8 **)(q + 0x14)), "r"(a0) : "memory");
    }
    if (func_0038CB00(a0 + 0xA) != 0) {
        func_003CD250(a0);
    }
}
/* localdecomp:end func_L39_005CDE10 */

INCLUDE_ASM("asm/levels", func_L39_005CDE78);
