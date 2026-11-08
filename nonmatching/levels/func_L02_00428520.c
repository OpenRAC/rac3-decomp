/* func_L02_00428520: near miss (w4 p2w4), VU0 block asm, 4 diff
   store order f13,f14,f12; callee func_00282CC0 replaced by lqc2/vadd.xyz/sqc2 block.
   Left: epilogue ld order needs j-form (file line lacks -mvu0-use-vf0-vf2) */
extern void func_0038D000(char *, char *, char *);
extern void func_0038CE20(void *, void *, float);

void func_L02_00428520(char *a0, char *a1, float f12, float f13, float f14) {
    *(float *)(a1 + 4) = f13;
    *(float *)(a1 + 8) = f14;
    *(float *)(a1 + 0) = f12;
    func_0038D000(a1, a1, a0 + 0xC0);
    func_0038CE20(a1, a1, *(float *)(a0 + 0x2C));
    __asm__ __volatile__(
        "lqc2 $vf2, 0x10(%0)\n"
        "lqc2 $vf1, 0x0(%1)\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, 0x0(%1)\n"
        : : "r"(a0), "r"(a1) : "memory");
}
