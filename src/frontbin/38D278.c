#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0038D890(void *, void *, void *, f32);
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

INCLUDE_ASM("asm/nonmatchings/text", func_0038D5F0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D63C);

ASM_FUNC("asm/handwritten", func_0038D640);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D688);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D6C4);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D6C8);

ASM_FUNC("asm/handwritten", func_0038D750);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D80C);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D810);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D830);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D84C);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D850);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D884);

LINKER_REMNANT("asm/remnants", func_0038D888);

ASM_FUNC("asm/handwritten", func_0038D890);

/* localdecomp:start func_0038D978 */
void func_0038D978(void) {
    __asm__ __volatile__(
        "lqc2 $vf8, 0($4)\n"
        "lqc2 $vf1, 0($5)\n"
        "vmulx.xyzw $vf14, $vf0, $vf0x\n"
        "vmulx.xyzw $vf15, $vf0, $vf0x\n"
        "vmr32.xyzw $vf16, $vf0\n"
        "lqc2 $vf17, 0($6)\n"
        "vaddw.x $vf14, $vf14, $vf0w\n"
        "vaddw.y $vf15, $vf15, $vf0w\n"
        "vadd.xyzw $vf9, $vf8, $vf8\n"
        "vmulw.xyz $vf10, $vf9, $vf8w\n"
        "vmulx.xyz $vf11, $vf9, $vf8x\n"
        "vmuly.yz $vf12, $vf9, $vf8y\n"
        "vmulz.z $vf13, $vf9, $vf8z\n"
        "vaddz.x $vf15, $vf0, $vf10z\n"
        "vsuby.x $vf16, $vf0, $vf10y\n"
        "vaddx.y $vf16, $vf0, $vf10x\n"
        "vsuby.x $vf14, $vf14, $vf12y\n"
        "vsubx.y $vf15, $vf15, $vf11x\n"
        "vsubx.z $vf16, $vf16, $vf11x\n"
        "vsubz.y $vf14, $vf11, $vf10z\n"
        "vaddy.z $vf14, $vf11, $vf10y\n"
        "vsubx.z $vf15, $vf12, $vf10x\n"
        "vaddy.x $vf15, $vf15, $vf11y\n"
        "vaddz.x $vf16, $vf16, $vf11z\n"
        "vaddz.y $vf16, $vf16, $vf12z\n"
        "vsubz.x $vf14, $vf14, $vf13z\n"
        "vsubz.y $vf15, $vf15, $vf13z\n"
        "vsuby.z $vf16, $vf16, $vf12y\n"
        "vmulx.xyz $vf14, $vf14, $vf1x\n"
        "vmuly.xyz $vf15, $vf15, $vf1y\n"
        "vmulz.xyz $vf16, $vf16, $vf1z\n"
        "vaddx.w $vf17, $vf0, $vf0x\n"
        "sqc2 $vf14, 0($7)\n"
        "sqc2 $vf15, 16($7)\n"
        "sqc2 $vf16, 32($7)\n"
        "sqc2 $vf17, 48($7)\n"
    );
}
/* localdecomp:end func_0038D978 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038DA10);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DA64);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DA68);

INCLUDE_ASM("asm/nonmatchings/text", func_0038DAB4);
