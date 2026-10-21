/* US draft of func_0038DA10 (rac3-uya-decomp func_003892D8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `@ps2as` (a single-function override). */


/* localdecomp:start func_0038DA10 */
void func_0038DA10(void) {
    __asm__ __volatile__(
        "ld $at, 0x0($4)\n"
        "nop\n"
        "ld $2, 0x8($4)\n"
        "pextlh $at, $at, $0\n"
        "ld $3, 0x10($4)\n"
        "psraw $at, $at, 16\n"
        "pextlh $2, $2, $0\n"
        "qmtc2.ni $at, $vf1\n"
        "psrlw $2, $2, 13\n"
        "qmtc2.ni $0, $vf0\n"
        "pextlh $3, $3, $0\n"
        "qmtc2.ni $2, $vf2\n"
        "psraw $3, $3, 16\n"
        "qmtc2.ni $3, $vf3\n"
        "vitof15.xyzw $vf1, $vf1\n"
        "vitof15.xyz $vf2, $vf2\n"
        "vitof0.xyz $vf3, $vf3\n"
        "sqc2 $vf1, 0($5)\n"
        "sqc2 $vf2, 16($5)\n"
        "nop\n"
        "sqc2 $vf3, 32($5)\n"
    );
}
/* localdecomp:end func_0038DA10 */
