/* US draft of func_0038D5B0 (rac3-uya-decomp func_00388E78, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `@ps2as` (a single-function override). */


/* localdecomp:start func_0038D5B0 */
void func_0038D5B0(p, b) u8 *p; void *b; {  /* K&R: later callers pass (M_3BFAF8 *, void *) */
    register u128_t v __asm__("$10");
    __asm__ __volatile__(
        "lq $8, 0($5)\n"
        "lq $9, 16($5)\n"
        "lq $10, 32($5)\n"
        "pextlw $12, $9, $8\n"
        "sqc2 $vf0, 48($4)\n"
        "pextuw $13, $9, $8\n"
        "pextlw $14, $0, $10\n"
        "pextuw $15, $0, $10\n"
        "pcpyld $8, $14, $12\n"
        "pcpyud $9, $12, $14\n"
        "sq $8, 0($4)\n"
        "pcpyld $10, $15, $13\n"
        "sq $9, 16($4)\n"
        "nop\n"
        : "=r"(v) : : "memory"
    );
    *(u128_t *)(p + 0x20) = v;
}
/* localdecomp:end func_0038D5B0 */
