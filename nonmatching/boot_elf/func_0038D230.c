/* US draft of func_0038D230 (rac3-uya-decomp func_0038D178, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_00388718 func_0038D18C. */


/* localdecomp:start func_0038D230 */
/* VU0 one-block volatile form, as frontbin func_00388718. The sqc2 is the
   jr delay slot (split off as func_0038D18C by splat). */
void func_0038D230(void) {
    __asm__ __volatile__(
        "mfc1 $at, $f12\n"
        "lqc2 $vf1, 0($5)\n"
        "qmtc2.ni $at, $vf2\n"
        "vmulx.xyzw $vf1, $vf1, $vf2x\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_0038D230 */
