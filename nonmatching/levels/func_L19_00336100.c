/* func_L19_00336100: near miss (w4 p2w4), VU0 block asm, 7 rows (1 insn misplaced)
   block asm in loop; twin func_L03_0038B408; all else matches
   Left: epilogue ld order needs j-form (file line lacks -mvu0-use-vf0-vf2) */
extern char D_L19_0021D500[];
extern void func_L19_00336008(void *, void *, int);

void func_L19_00336100(char *a0) {
    char *s = *(char **)(a0 + 0x68);
    char v[16] __attribute__((aligned(16)));
    int i, j;
    int *t = (int *)(s + 0x28);
    char *p;
    for (i = 0; i < 4; i++) {
        p = *(char **)(D_L19_0021D500 + *(int *)((char *)t + (i << 2)) * 4);
        if (p != 0) {
            func_L19_00336008(v, p, *(int *)(s + 0x38));
            for (j = 0; j < *(int *)(s + 0x38); j++) {
                __asm__ __volatile__(
                    "lqc2 $vf2, 0x0(%0)\n"
                    "lqc2 $vf1, 0x0(%1)\n"
                    "vsub.xyz $vf2, $vf2, $vf1\n"
                    "sqc2 $vf2, 0x0(%0)\n"
                    "lqc2 $vf1, 0x0(%0)\n"
                    "lqc2 $vf2, 0xE0(%2)\n"
                    "vadd.xyz $vf1, $vf1, $vf2\n"
                    "sqc2 $vf1, 0x0(%0)\n"
                    : : "r"(p + 0x10 + j * 0x10), "r"(v), "r"(s) : "memory");
            }
        }
    }
}
