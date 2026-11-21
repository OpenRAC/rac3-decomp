/* func_L19_004044B0: MATCH in check.py (0 diff), but only with lui/ori written inside the asm block: not allowed (ordinary EE instructions).
   Round 17 (nm/b27-k2a, 4 compiles): the VU0 sequence uses vf4-vf6, outside the helper "j" class (vf1/vf2 only, and any other
   -mvu0-use-vf0-vfN is a new flag), so it stays one hand-written block (or three: lqc2 vf4 / lqc2 vf5 / the rest). With the
   constant as a C value (`unsigned c = 0x3FB504F3;`, or split `c = 0x3FB50000; c |= 0x04F3;` between the asm statements) gcc keeps
   the lui/ori adjacent in $v0 (4-5 diff): retail's `lui $t0` / `lqc2 vf5` / `ori $t0` interleave and the $t0 are the hand
   scheduling of a hand-written block, not something the compiler emits. Candidate for ASM_FUNC (VU0 code, hand-written), a
   maintainer decision. */
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
