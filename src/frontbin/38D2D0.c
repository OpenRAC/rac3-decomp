#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0038D6C8(void *, void *, void *, f32);
extern void func_0038D590(void *, void *);
extern void func_0038D640();
/* --- end of declarations from other files --- */

/* localdecomp:start func_0038D2D0 */
/* the boot_elf twin func_0038D6B0's VU0 block, with the matrix and the scale as operands: a
   scale matrix, diag(s, s, s, 1) */
void func_0038D2D0(void *m, f32 s) {
    __asm__ __volatile__(
        ".set noat\n"
        "mfc1 $at, %1\n"
        "qmtc2.ni $at, $vf5\n"
        ".set at\n"
        "vmulx.xyzw $vf1, $vf0, $vf0x\n"
        "vmulx.xyzw $vf2, $vf0, $vf0x\n"
        "vmulx.xyzw $vf3, $vf0, $vf0x\n"
        "vmove.xyzw $vf4, $vf0\n"
        "vaddx.x $vf1, $vf1, $vf5x\n"
        "vaddx.y $vf2, $vf2, $vf5x\n"
        "vaddx.z $vf3, $vf3, $vf5x\n"
        "sqc2 $vf1, 0(%0)\n"
        "sqc2 $vf2, 16(%0)\n"
        "sqc2 $vf3, 32(%0)\n"
        "sqc2 $vf4, 48(%0)\n"
        : : "r"(m), "f"(s) : "memory");
}
/* localdecomp:end func_0038D2D0 */

/* localdecomp:start func_0038D308 */
/* func_0038D308 log: the boot_elf twin func_0038D6E8 (src/boot_elf/text/38D6B0.c) with its name moved; vu0 macro-mode
   code (lqc2/vcallms/qmfc2.i/sqc2) in asm, as the twin and the file's other vu0 functions. The `qmfc2.i $at`
   line is wrapped in `.set noat` (SN's ps2as, this code's assembler before 38D278.c was cut at 0x0038D2D0,
   rejects it without), and `.set noreorder` keeps the return's delay slot empty, as in the twin. */
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

/* localdecomp:start func_0038D328 */
/* the boot_elf twin func_0038D6E8's sequence with a fourth row: the micro subroutine at 0xC80
   builds the rotation from the angles in vf1, then four rows out */
void func_0038D328(void *out, void *in) {
    __asm__ __volatile__(
        ".set noat\n"
        "lqc2 $vf1, 0(%1)\n"
        "vcallms 0xC80\n"
        "qmfc2.i $at, $vf20\n"
        ".set at\n"
        "sqc2 $vf20, 0(%0)\n"
        "sqc2 $vf21, 16(%0)\n"
        "sqc2 $vf22, 32(%0)\n"
        "sqc2 $vf23, 48(%0)\n"
        : : "r"(out), "r"(in) : "memory");
}
/* localdecomp:end func_0038D328 */

ASM_FUNC("asm/handwritten", func_0038D348);

ASM_FUNC("asm/handwritten", func_0038D570);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D58C);

ASM_FUNC("asm/handwritten", func_0038D590);

ASM_FUNC("asm/handwritten", func_0038D5B0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D5EC);

ASM_FUNC("asm/handwritten", func_0038D5F0);

ASM_FUNC("asm/handwritten", func_0038D63C);

ASM_FUNC("asm/handwritten", func_0038D640);

ASM_FUNC("asm/handwritten", func_0038D688);

ASM_FUNC("asm/handwritten", func_0038D6C4);

ASM_FUNC("asm/handwritten", func_0038D6C8);

ASM_FUNC("asm/handwritten", func_0038D750);

INCLUDE_ASM("asm/nonmatchings/text", func_0038D80C);
