#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0038D590(void *, void *);
extern void func_0038D2A0();
extern void func_0038D640();
/* --- end of declarations from other files --- */

/* localdecomp:start func_0038D278 */
void func_0038D278(void) {
    __asm__ __volatile__(
        "vmulx.xyzw $vf1, $vf0, $vf0x\n"
        "vmulx.xyzw $vf2, $vf0, $vf0x\n"
        "vmr32.xyzw $vf3, $vf0\n"
        "vaddw.x $vf1, $vf1, $vf0w\n"
        "vaddw.y $vf2, $vf2, $vf0w\n"
        "sqc2 $vf1, 0($4)\n"
        "sqc2 $vf2, 16($4)\n"
        "sqc2 $vf3, 32($4)\n"
    );
}
/* localdecomp:end func_0038D278 */

/* localdecomp:start func_0038D2A0 */
void func_0038D2A0(void) {
    __asm__ __volatile__(
        "vmulx.xyzw $vf1, $vf0, $vf0x\n"
        "vmulx.xyzw $vf2, $vf0, $vf0x\n"
        "vmr32.xyzw $vf3, $vf0\n"
        "vmove.xyzw $vf4, $vf0\n"
        "vaddw.x $vf1, $vf1, $vf0w\n"
        "vaddw.y $vf2, $vf2, $vf0w\n"
        "sqc2 $vf1, 0($4)\n"
        "sqc2 $vf2, 16($4)\n"
        "sqc2 $vf3, 32($4)\n"
        "sqc2 $vf4, 48($4)\n"
    );
}
/* localdecomp:end func_0038D2A0 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038D2D0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D304);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D308);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D328);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D344);

ASM_FUNC("asm/handwritten", func_0038D348);

ASM_FUNC("asm/handwritten", func_0038D570);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D58C);

ASM_FUNC("asm/handwritten", func_0038D590);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D5B0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D5EC);

ASM_FUNC("asm/handwritten", func_0038D5F0);

ASM_FUNC("asm/handwritten", func_0038D63C);

ASM_FUNC("asm/handwritten", func_0038D640);

ASM_FUNC("asm/handwritten", func_0038D688);

ASM_FUNC("asm/handwritten", func_0038D6C4);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D6C8);

ASM_FUNC("asm/handwritten", func_0038D750);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D80C);
