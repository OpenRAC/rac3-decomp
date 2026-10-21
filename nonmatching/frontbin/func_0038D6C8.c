/* US draft of func_0038D6C8 (rac3-uya-decomp func_00388F90, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `@ps2as` (a single-function override). */


/* localdecomp:start func_0038D6C8 */
void func_0038D6C8(void) {
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
/* localdecomp:end func_0038D6C8 */
