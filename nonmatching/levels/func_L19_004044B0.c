/* func_L19_004044B0: MATCH in check.py, but only with lui/ori written inside the asm block: not allowed (ordinary EE instructions) */
void func_L19_004044B0(void *o, void *a, void *b) {
    __asm__ __volatile__(
        "lqc2 $vf4, 0(%2)\n"
        "lui $8, 0x3FB5\n"
        "lqc2 $vf5, 0(%1)\n"
        "ori $8, $8, 0x04F3\n"
        "qmtc2.ni $8, $vf6\n"
        "vmulx.xyzw $vf4, $vf4, $vf6x\n"
        "vopmula.xyz ACC, $vf4, $vf5\n"
        "vmsubaw.xyz ACC, $vf5, $vf4w\n"
        "vopmsub.xyz $vf6, $vf5, $vf4\n"
        "vopmula.xyz ACC, $vf4, $vf6\n"
        "vmaddaw.xyz ACC, $vf5, $vf0w\n"
        "vopmsub.xyz $vf5, $vf6, $vf4\n"
        "sqc2 $vf5, 0(%0)\n"
        : : "r"(o), "r"(a), "r"(b) : "$8", "memory");
}
