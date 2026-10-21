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

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D708);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D724);

ASM_FUNC("asm/boot_elf/handwritten", func_0038D728);

ASM_FUNC("asm/boot_elf/handwritten", func_0038D950);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D96C);

ASM_FUNC("asm/boot_elf/handwritten", func_0038D970);

typedef int u128_t __attribute__((mode(TI)));
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D990);

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

/* localdecomp:start func_0038DAA8 */
void func_0038DAA8(void) {
    __asm__ __volatile__(
        ".set noreorder\n"
        "mfc1 $at, $f12\n"
        "qmtc2.ni $at, $vf3\n"
        "lqc2 $vf1, 0($5)\n"
        "lqc2 $vf2, 0($6)\n"
        "vsubx.w $vf3, $vf0, $vf3x\n"
        "vaddw.xyz $vf7, $vf0, $vf0w\n"
        "vmulw.xyzw $vf1, $vf1, $vf3w\n"
        "vmulx.xyzw $vf2, $vf2, $vf3x\n"
        "vadd.xyzw $vf4, $vf1, $vf2\n"
        "vmul.xyzw $vf6, $vf1, $vf2\n"
        "vmul.xyzw $vf5, $vf4, $vf4\n"
        "vaddax.y ACC, $vf6, $vf6x\n"
        "vmaddaz.y ACC, $vf7, $vf6z\n"
        "vmaddw.y $vf6, $vf7, $vf6w\n"
        "vadday.x ACC, $vf5, $vf5y\n"
        "vmaddaz.x ACC, $vf7, $vf5z\n"
        "vmaddw.x $vf5, $vf7, $vf5w\n"
        "qmfc2.ni $9, $vf6\n"
        "bgez $9, .L00388FF8_00388F90\n"
        "nop\n"
        "vsub.xyzw $vf4, $vf1, $vf2\n"
        "vmul.xyzw $vf5, $vf4, $vf4\n"
        "vadday.x ACC, $vf5, $vf5y\n"
        "vmaddaz.x ACC, $vf7, $vf5z\n"
        "vmaddw.x $vf5, $vf7, $vf5w\n"
        "nop\n"
        ".L00388FF8_00388F90:\n"
        "nop\n"
        "nop\n"
        "vrsqrt Q, $vf0w, $vf5x\n"
        "vwaitq\n"
        "vmulq.xyzw $vf1, $vf4, Q\n"
        "sqc2 $vf1, 0($4)\n"
        ".set reorder\n"
    );
}
/* localdecomp:end func_0038DAA8 */

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

/* localdecomp:start func_0038DC30 */
void func_0038DC30(void) {
    __asm__ __volatile__(
        "lqc2 $vf4, 0($6)\n"
        "lui $8, 0x3fb5\n"
        "lqc2 $vf5, 0($5)\n"
        "ori $8, $8, 0x4f3\n"
        "qmtc2.ni $8, $vf6\n"
        "vmulx.xyzw $vf4, $vf4, $vf6x\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vmaddaw.xyz ACC, $vf5, $vf4w\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vopmula.xyz ACC, $vf4, $vf6\n"
        "vmaddaw.xyz ACC, $vf5, $vf0w\n"
        "vopmsub.xyz $vf5, $vf6, $vf4\n"
        "sqc2 $vf5, 0($4)\n"
    );
}
/* localdecomp:end func_0038DC30 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0038DC68);

ASM_FUNC("asm/boot_elf/handwritten", func_0038DC70);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038DD58);

LINKER_REMNANT("asm/boot_elf/remnants", func_0038DDF0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038DDF8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038DE44);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038DE48);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038DE94);
