/* US draft of func_0038D830 (rac3-uya-decomp func_003890F8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `@ps2as` (a single-function override). */


/* localdecomp:start func_0038D830 */
void func_0038D830(void) {
    __asm__ __volatile__(
        "lqc2 $vf8, 0($4)\n"
        "vcallms 0xE98\n"
        "vnop\n"
        "sqc2 $vf14, 0($5)\n"
        "sqc2 $vf15, 16($5)\n"
        "sqc2 $vf16, 32($5)\n"
        "sqc2 $vf0, 48($5)\n"
    );
}
/* localdecomp:end func_0038D830 */
