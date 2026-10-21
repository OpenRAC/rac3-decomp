/* US draft of func_0038D990 (rac3-uya-decomp func_0038D8D8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_0038D914. */


/* localdecomp:start func_0038D990 */
/* MMI/VU0 body as frontbin func_00388ED0. The final sq is the jr delay slot
   (split off as func_0038D914 by splat). */
typedef int u128_t __attribute__((mode(TI)));
void func_0038D990(u8 *p, void *b) {
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
/* localdecomp:end func_0038D990 */
