#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern f32 func_0038D248(void *, void *);
extern void func_0038D200(f32 *, void *, f32);
extern void func_0038D270();
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D198);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D1AC);

/* localdecomp:start func_0038D1B0 */
/* VU0 macro code is inline asm, as in the original. The assembler moves the
   sqc2 into the jr delay slot, like retail. */
void func_0038D1B0(void *o, void *a, void *b) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0(%1)\n"
        "lqc2 $vf2, 0(%2)\n"
        "vmini.xyzw $vf1, $vf1, $vf2\n"
        "nop\n"
        "sqc2 $vf1, 0(%0)\n"
        : : "r"(o), "r"(a), "r"(b) : "memory");
}
/* localdecomp:end func_0038D1B0 */

/* localdecomp:start func_0038D1C8 */
void func_0038D1C8(void) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0($5)\n"
        "vabs.xyzw $vf1, $vf1\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_0038D1C8 */

/* localdecomp:start func_0038D1D8 */
void func_0038D1D8(void) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0($5)\n"
        "mfc1 $5, $f12\n"
        "lqc2 $vf2, 0($6)\n"
        "qmtc2.ni $5, $vf3\n"
        "vaddax.xyz ACC, $vf1, $vf0x\n"
        "vmsubax.xyz ACC, $vf1, $vf3x\n"
        "vmaddx.xyz $vf1, $vf2, $vf3x\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_0038D1D8 */

/* localdecomp:start func_0038D200 */
void func_0038D200(f32 * p0, void * p1, f32 p2) {
    __asm__ __volatile__(
        "mfc1 $at, $f12\n"
        "lqc2 $vf1, 0($5)\n"
        "qmtc2.ni $at, $vf2\n"
        "vmulx.xyz $vf1, $vf1, $vf2x\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_0038D200 */

/* localdecomp:start func_0038D218 */
void func_0038D218(void) {
    __asm__ __volatile__(
        "mfc1 $at, $f12\n"
        "lqc2 $vf1, 0($5)\n"
        "qmtc2.ni $at, $vf2\n"
        "vmulx.xyz $vf1, $vf1, $vf2x\n"
        "sqc2 $vf1, 0($5)\n"
    );
}
/* localdecomp:end func_0038D218 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D230);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D244);

ASM_FUNC("asm/boot_elf/handwritten", func_0038D248);

/* localdecomp:start func_0038D270 */
void func_0038D270(void) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0($5)\n"
        "lqc2 $vf2, 0($6)\n"
        "vopmula.xyz ACC, $vf2, $vf1\n"
        "vopmsub.xyz $vf3, $vf1, $vf2\n"
        "sqc2 $vf3, 0($4)\n"
    );
}
/* localdecomp:end func_0038D270 */
