/* US draft of func_0038D198 (rac3-uya-decomp func_0038D0E0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_00388680 func_0038D0F4. */

/* localdecomp:start func_0038D198 */
/* VU0 one-block volatile form, as frontbin func_00388680. The sqc2 is the
   jr delay slot (split off as func_0038D0F4 by splat). */
void func_0038D198(void) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0($5)\n"
        "lqc2 $vf2, 0($6)\n"
        "vmax.xyzw $vf1, $vf1, $vf2\n"
        "nop\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_0038D198 */
