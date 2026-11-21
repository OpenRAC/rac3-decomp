#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0038DC70(void *, void *, void *, f32);
extern void func_0038D970(void *, void *);
extern void func_0038DA20();
/* --- end of declarations from other files --- */

/* localdecomp:start func_0038D6B0 */
void func_0038D6B0(void) {
    __asm__ __volatile__(
        "mfc1 $at, $f12\n"
        "qmtc2.ni $at, $vf5\n"
        "vmulx.xyzw $vf1, $vf0, $vf0x\n"
        "vmulx.xyzw $vf2, $vf0, $vf0x\n"
        "vmulx.xyzw $vf3, $vf0, $vf0x\n"
        "vmove.xyzw $vf4, $vf0\n"
        "vaddx.x $vf1, $vf1, $vf5x\n"
        "vaddx.y $vf2, $vf2, $vf5x\n"
        "vaddx.z $vf3, $vf3, $vf5x\n"
        "sqc2 $vf1, 0($4)\n"
        "sqc2 $vf2, 16($4)\n"
        "sqc2 $vf3, 32($4)\n"
        "sqc2 $vf4, 48($4)\n"
    );
}
/* localdecomp:end func_0038D6B0 */

/* localdecomp:start func_0038D6E8 */
void func_0038D6E8(void) {
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2 $vf1, 0($5)\n"
        "vcallms 0xC80\n"
        "qmfc2.i $at, $vf20\n"
        "sqc2 $vf20, 0($4)\n"
        "sqc2 $vf21, 16($4)\n"
        "sqc2 $vf22, 32($4)\n"
        ".set reorder\n"
    );
}
/* localdecomp:end func_0038D6E8 */

/* localdecomp:start func_0038D708 */
/* func_0038D6E8's sequence with a fourth row: the micro subroutine at 0xC80
   builds the rotation from the angles in vf1, then four rows out */
void func_0038D708(void *out, void *in) {
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
        : : "r"(out), "r"(in) : "vf1", "vf20", "vf21", "vf22", "vf23", "memory");
}
/* localdecomp:end func_0038D708 */

ASM_FUNC("asm/boot_elf/handwritten", func_0038D728);

ASM_FUNC("asm/boot_elf/handwritten", func_0038D950);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D96C);

ASM_FUNC("asm/boot_elf/handwritten", func_0038D970);

typedef int u128_t __attribute__((mode(TI)));
ASM_FUNC("asm/boot_elf/handwritten", func_0038D990);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D9CC);

/* localdecomp:start func_0038D9D0 */
void func_0038D9D0(void) {
    __asm__ __volatile__(
        "lqc2 $vf4, 0($5)\n"
        "lqc2 $vf5, 16($5)\n"
        "lqc2 $vf6, 32($5)\n"
        "lqc2 $vf1, 0($6)\n"
        "lqc2 $vf2, 16($6)\n"
        "lqc2 $vf3, 32($6)\n"
        "vmulax.xyzw ACC, $vf4, $vf1x\n"
        "vmadday.xyzw ACC, $vf5, $vf1y\n"
        "vmaddz.xyzw $vf1, $vf6, $vf1z\n"
        "vmulax.xyzw ACC, $vf4, $vf2x\n"
        "vmadday.xyzw ACC, $vf5, $vf2y\n"
        "vmaddz.xyzw $vf2, $vf6, $vf2z\n"
        "vmulax.xyzw ACC, $vf4, $vf3x\n"
        "vmadday.xyzw ACC, $vf5, $vf3y\n"
        "vmaddz.xyzw $vf3, $vf6, $vf3z\n"
        "nop\n"
        "sqc2 $vf1, 0($4)\n"
        "sqc2 $vf2, 16($4)\n"
        "sqc2 $vf3, 32($4)\n"
    );
}
/* localdecomp:end func_0038D9D0 */

ASM_FUNC("asm/boot_elf/handwritten", func_0038DA20);

/* localdecomp:start func_0038DA68 */
void func_0038DA68(void) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0($5)\n"
        "lqc2 $vf2, 0($6)\n"
        "vaddw.xyz $vf9, $vf0, $vf0w\n"
        "vmul.w $vf3, $vf2, $vf1\n"
        "vmul.xyz $vf4, $vf2, $vf1\n"
        "vmulw.xyz $vf5, $vf2, $vf1w\n"
        "vmulw.xyz $vf6, $vf1, $vf2w\n"
        "vopmula.xyz ACC, $vf1, $vf2\n"
        "vopmsub.xyz $vf7, $vf2, $vf1\n"
        "vadday.x ACC, $vf4, $vf4y\n"
        "vmaddz.x $vf4, $vf9, $vf4z\n"
        "vadd.xyz $vf8, $vf5, $vf6\n"
        "vadd.xyz $vf8, $vf8, $vf7\n"
        "vsubx.w $vf8, $vf3, $vf4x\n"
        "sqc2 $vf8, 0($4)\n"
    );
}
/* localdecomp:end func_0038DA68 */

ASM_FUNC("asm/boot_elf/handwritten", func_0038DAA8);

ASM_FUNC("asm/boot_elf/handwritten", func_0038DB30);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038DBEC);

/* localdecomp:start func_0038DBF0 */
void func_0038DBF0(void) {
    __asm__ __volatile__(
        "lqc2 $vf8, 0($4)\n"
        "vcallms 0xE98\n"
        "vnop\n"
        "sqc2 $vf14, 0($5)\n"
        "sqc2 $vf15, 16($5)\n"
        "sqc2 $vf16, 32($5)\n"
    );
}
/* localdecomp:end func_0038DBF0 */

/* localdecomp:start func_0038DC10 */
void func_0038DC10(void) {
    __asm__ __volatile__(
        "lqc2 $vf8, 0($4)\n"
        "vcallms 0xE98\n"
        "vnop\n"
        "sqc2 $vf14, 0($5)\n"
        "sqc2 $vf15, 16($5)\n"
        "sqc2 $vf16, 32($5)\n"
        "sqc2 $vf0, 48($5)\n"
    );
}
/* localdecomp:end func_0038DC10 */

ASM_FUNC("asm/boot_elf/handwritten", func_0038DC30);

LINKER_REMNANT("asm/boot_elf/remnants", func_0038DC68);

ASM_FUNC("asm/boot_elf/handwritten", func_0038DC70);

/* localdecomp:start func_0038DD58 */
void func_0038DD58(void *rotation, void *scale, void *translation, void *matrix) {
    __asm__ volatile(
        ".set noreorder\n"
        "lqc2       $vf8, 0x0(%0)\n"
        "lqc2       $vf1, 0x0(%1)\n"
        "vmulx.xyzw $vf14, $vf0, $vf0x\n"
        "vmulx.xyzw $vf15, $vf0, $vf0x\n"
        "vmr32.xyzw $vf16, $vf0\n"
        "lqc2       $vf17, 0x0(%2)\n"
        "vaddw.x    $vf14, $vf14, $vf0w\n"
        "vaddw.y    $vf15, $vf15, $vf0w\n"
        "vadd.xyzw  $vf9, $vf8, $vf8\n"
        "vmulw.xyz  $vf10, $vf9, $vf8w\n"
        "vmulx.xyz  $vf11, $vf9, $vf8x\n"
        "vmuly.yz   $vf12, $vf9, $vf8y\n"
        "vmulz.z    $vf13, $vf9, $vf8z\n"
        "vaddz.x    $vf15, $vf0, $vf10z\n"
        "vsuby.x    $vf16, $vf0, $vf10y\n"
        "vaddx.y    $vf16, $vf0, $vf10x\n"
        "vsuby.x    $vf14, $vf14, $vf12y\n"
        "vsubx.y    $vf15, $vf15, $vf11x\n"
        "vsubx.z    $vf16, $vf16, $vf11x\n"
        "vsubz.y    $vf14, $vf11, $vf10z\n"
        "vaddy.z    $vf14, $vf11, $vf10y\n"
        "vsubx.z    $vf15, $vf12, $vf10x\n"
        "vaddy.x    $vf15, $vf15, $vf11y\n"
        "vaddz.x    $vf16, $vf16, $vf11z\n"
        "vaddz.y    $vf16, $vf16, $vf12z\n"
        "vsubz.x    $vf14, $vf14, $vf13z\n"
        "vsubz.y    $vf15, $vf15, $vf13z\n"
        "vsuby.z    $vf16, $vf16, $vf12y\n"
        "vmulx.xyz  $vf14, $vf14, $vf1x\n"
        "vmuly.xyz  $vf15, $vf15, $vf1y\n"
        "vmulz.xyz  $vf16, $vf16, $vf1z\n"
        "vaddx.w    $vf17, $vf0, $vf0x\n"
        "sqc2       $vf14, 0x0(%3)\n"
        "sqc2       $vf15, 0x10(%3)\n"
        "sqc2       $vf16, 0x20(%3)\n"
        "sqc2       $vf17, 0x30(%3)\n"
        ".set reorder\n"
        : : "r"(rotation), "r"(scale), "r"(translation), "r"(matrix)
        : "vf1", "vf8", "vf9", "vf10", "vf11", "vf12", "vf13", "vf14", "vf15", "vf16", "vf17", "memory");
}
/* localdecomp:end func_0038DD58 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0038DDF0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038DDF8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038DE44);

/* localdecomp:start func_0038DE48 */
/* interpolates two 3x4 matrices: out = a * (1 - t) + b * t, row by row */
void func_0038DE48(void *out, void *a, void *b, f32 t) {
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
        : : "r"(out), "r"(a), "r"(b), "f"(t) : "vf1", "vf2", "vf3", "vf4", "vf5", "vf6", "vf7", "memory");
}
/* localdecomp:end func_0038DE48 */

