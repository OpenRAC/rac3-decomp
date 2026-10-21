/* US draft of func_0038D850 (rac3-uya-decomp func_00389118, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `@ps2as` (a single-function override). */


/* localdecomp:start func_0038D850 */
void func_0038D850(void) {
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
/* localdecomp:end func_0038D850 */
