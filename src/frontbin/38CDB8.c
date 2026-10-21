#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038CE90();
/* --- end of declarations from other files --- */

/* localdecomp:start func_0038CDB8 */
void func_0038CDB8(void) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0($5)\n"
        "lqc2 $vf2, 0($6)\n"
        "vmax.xyzw $vf1, $vf1, $vf2\n"
        "nop\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_0038CDB8 */

/* localdecomp:start func_0038CDD0 */
/* VU0 macro code is inline asm, as in the original. The assembler moves the
   sqc2 into the jr delay slot, like retail. */
void func_0038CDD0(void *o, void *a, void *b) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0(%1)\n"
        "lqc2 $vf2, 0(%2)\n"
        "vmini.xyzw $vf1, $vf1, $vf2\n"
        "nop\n"
        "sqc2 $vf1, 0(%0)\n"
        : : "r"(o), "r"(a), "r"(b) : "memory");
}
/* localdecomp:end func_0038CDD0 */

/* localdecomp:start func_0038CDE8 */
void func_0038CDE8(void) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0($5)\n"
        "vabs.xyzw $vf1, $vf1\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_0038CDE8 */

/* localdecomp:start func_0038CDF8 */
void func_0038CDF8(void) {
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
/* localdecomp:end func_0038CDF8 */

/* localdecomp:start func_0038CE20 */
void func_0038CE20(f32 * p0, void * p1, f32 p2) {
    __asm__ __volatile__(
        "mfc1 $at, $f12\n"
        "lqc2 $vf1, 0($5)\n"
        "qmtc2.ni $at, $vf2\n"
        "vmulx.xyz $vf1, $vf1, $vf2x\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_0038CE20 */

/* localdecomp:start func_0038CE38 */
void func_0038CE38(void) {
    __asm__ __volatile__(
        "mfc1 $at, $f12\n"
        "lqc2 $vf1, 0($5)\n"
        "qmtc2.ni $at, $vf2\n"
        "vmulx.xyz $vf1, $vf1, $vf2x\n"
        "sqc2 $vf1, 0($5)\n"
    );
}
/* localdecomp:end func_0038CE38 */

/* localdecomp:start func_0038CE50 */
void func_0038CE50(void) {
    __asm__ __volatile__(
        "mfc1 $at, $f12\n"
        "lqc2 $vf1, 0($5)\n"
        "qmtc2.ni $at, $vf2\n"
        "vmulx.xyzw $vf1, $vf1, $vf2x\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_0038CE50 */

ASM_FUNC("asm/handwritten", func_0038CE68);

/* localdecomp:start func_0038CE90 */
void func_0038CE90(void) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0($5)\n"
        "lqc2 $vf2, 0($6)\n"
        "vopmula.xyz ACC, $vf2, $vf1\n"
        "vopmsub.xyz $vf3, $vf1, $vf2\n"
        "sqc2 $vf3, 0($4)\n"
    );
}
/* localdecomp:end func_0038CE90 */
