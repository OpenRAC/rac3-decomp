#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0038D6C8(void *, void *, void *, f32);
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

/* localdecomp:start func_0038D308 */
/* func_0038D308 log: the boot_elf twin func_0038D6E8 (src/boot_elf/text/38D6B0.c) with its name moved; vu0 macro-mode
   code (lqc2/vcallms/qmfc2.i/sqc2) in asm, as the twin and the file's other vu0 functions. ps2as (this file's
   assembler) rejects `qmfc2.i $at` without `.set noat`, so that one line is wrapped in it. */
void func_0038D308(void) {
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2 $vf1, 0($5)\n"
        "vcallms 0xC80\n"
        ".set noat\n"
        "qmfc2.i $at, $vf20\n"
        ".set at\n"
        "sqc2 $vf20, 0($4)\n"
        "sqc2 $vf21, 16($4)\n"
        "sqc2 $vf22, 32($4)\n"
        ".set reorder\n"
    );
}
/* localdecomp:end func_0038D308 */

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
