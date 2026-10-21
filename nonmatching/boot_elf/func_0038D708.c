/* US draft of func_0038D708 (rac3-uya-decomp func_0038D650, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_00388BF0 func_0038D66C. */


/* localdecomp:start func_0038D708 */
/* VU0 one-block volatile form, as frontbin func_00388BF0. The last sqc2 is the
   jr delay slot (split off as func_0038D66C by splat). */
void func_0038D708(void) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0($5)\n"
        "vcallms 0xC80\n"
        "qmfc2.i $at, $vf20\n"
        "sqc2 $vf20, 0($4)\n"
        "sqc2 $vf21, 16($4)\n"
        "sqc2 $vf22, 32($4)\n"
        "sqc2 $vf23, 48($4)\n"
    );
}
/* localdecomp:end func_0038D708 */
