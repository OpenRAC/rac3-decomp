/* US draft of func_0038D308 (rac3-uya-decomp func_00388BD0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `@ps2as` (a single-function override). */


/* localdecomp:start func_0038D308 */
void func_0038D308(void) {
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2 $vf1, 0($5)\n"
        "vcallms 0xC80\n"
        "qmfc2.i $at, $vf20\n"
        "sqc2 $vf20, 0($4)\n"
        "sqc2 $vf21, 16($4)\n"
        "sqc2 $vf22, 32($4)\n"
        ".set reorder\n"
    );
}
/* localdecomp:end func_0038D308 */
