/* US draft of func_0038DA68 (rac3-uya-decomp func_00389330, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `@ps2as` (a single-function override). */


/* localdecomp:start func_0038DA68 */
void func_0038DA68(void) {
    __asm__ __volatile__(
        "mfc1 $at, $f12\n"
        "qmtc2.ni $at, $vf7\n"
        "vsubx.w $vf7, $vf0, $vf7x\n"
        "nop\n"
        "lqc2 $vf1, 0($5)\n"
        "lqc2 $vf2, 16($5)\n"
        "lqc2 $vf3, 32($5)\n"
        "lqc2 $vf4, 0($6)\n"
        "lqc2 $vf5, 16($6)\n"
        "lqc2 $vf6, 32($6)\n"
        "vmulaw.xyzw ACC, $vf1, $vf7w\n"
        "vmaddx.xyzw $vf1, $vf4, $vf7x\n"
        "vmulaw.xyzw ACC, $vf2, $vf7w\n"
        "vmaddx.xyzw $vf2, $vf5, $vf7x\n"
        "vmulaw.xyzw ACC, $vf3, $vf7w\n"
        "vmaddx.xyzw $vf3, $vf6, $vf7x\n"
        "sqc2 $vf1, 0($4)\n"
        "sqc2 $vf2, 16($4)\n"
        "sqc2 $vf3, 32($4)\n"
    );
}
/* localdecomp:end func_0038DA68 */
