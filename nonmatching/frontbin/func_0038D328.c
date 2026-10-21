/* US draft of func_0038D328 (rac3-uya-decomp func_00388BF0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `@ps2as` (a single-function override). */


/* localdecomp:start func_0038D328 */
void func_0038D328(void) {
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
/* localdecomp:end func_0038D328 */
