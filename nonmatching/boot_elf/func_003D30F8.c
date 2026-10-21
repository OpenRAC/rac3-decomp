/* US draft of func_003D30F8 (rac3-uya-decomp func_003D2F90, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_003D2FEC. */


/* localdecomp:start func_003D30F8 */
/* func_003D2FEC (4 bytes, the sqc2 in this function's jr delay slot) was a split artifact. */
void func_003D30F8(void) {
    __asm__ __volatile__(
        "vaddw.xyz $vf24, $vf0, $vf0w\n"
        "lqc2 $vf1, 0($5)\n"
        "lqc2 $vf2, 0($6)\n"
        "lqc2 $vf3, 0($7)\n"
        "vsub.xyz $vf4, $vf2, $vf1\n"
        "vsub.xyz $vf5, $vf3, $vf1\n"
        "vmul.xyz $vf6, $vf4, $vf4\n"
        "vmul.xyz $vf7, $vf4, $vf5\n"
        "vadday.x ACC, $vf6, $vf6y\n"
        "vmaddz.x $vf6, $vf24, $vf6z\n"
        "vadday.x ACC, $vf7, $vf7y\n"
        "vmaddz.x $vf7, $vf24, $vf7z\n"
        "vdiv Q, $vf7x, $vf6x\n"
        "vwaitq\n"
        "vaddq.x $vf8, $vf0, Q\n"
        "vminiw.x $vf7, $vf8, $vf0w\n"
        "qmfc2.ni $8, $vf8\n"
        "nop\n"
        "vmaxx.x $vf7, $vf7, $vf0x\n"
        "mtc1 $8, $f0\n"
        "vmulax.xyz ACC, $vf4, $vf7x\n"
        "vmaddw.xyz $vf1, $vf1, $vf0w\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_003D30F8 */
