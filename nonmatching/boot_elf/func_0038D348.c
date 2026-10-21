/* US draft of func_0038D348 (rac3-uya-decomp func_0038D290, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_0038D2DC. */

/* localdecomp:start func_0038D348 */
/* func_0038D2DC (4 bytes, the sqc2 in this function's jr delay slot) was a split artifact. */
void func_0038D348(s32 a, s32 b, f32 x) {
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2 $vf1, 0($5)\n"
        "vaddw.xyz $vf3, $vf0, $vf0w\n"
        "vmul.xyz $vf2, $vf1, $vf1\n"
        "vadday.x ACC, $vf2, $vf2y\n"
        "vmaddz.x $vf2, $vf3, $vf2z\n"
        "mfc1 $at, $f12\n"
        "qmtc2.ni $at, $vf3\n"
        "vrsqrt Q, $vf3x, $vf2x\n"
        "qmfc2.ni $at, $vf2\n"
        "dsll32 $at, $at, 0\n"
        "beqz $at, .L00388870_0038D290\n"
        "nop\n"
        "vwaitq\n"
        "vmulq.xyz $vf1, $vf1, Q\n"
        "jr $31\n"
        "sqc2 $vf1, 0($4)\n"
        ".L00388870_0038D290:\n"
        ".set reorder\n"
        "vadd.xyz $vf1, $vf0, $vf0\n"
        "nop\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_0038D348 */
