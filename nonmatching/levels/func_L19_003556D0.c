/* func_L19_003556D0: NEAR 4 (wave 4, VU0 blocks). Epilogue: retail hoists ld $s1 between vadd and sqc2 (interleave; needs j-form, file lacks vf2 flag).
   Twin func_L02_00333438 not used; written from retail asm.
   file src/levels/shared/L19_003553A0.c, flags -mno-split-addresses */
extern void func_0038CF68(f32 *, f32 *, f32);

void func_L19_003556D0(char *self, f32 *vec) {
    func_0038CF68(vec, (f32 *)(self + 0xC0), 1.0f);
    __asm__ __volatile__(
        "lqc2    $vf2, 0x10(%0)\n"
        "lqc2    $vf1, 0x0(%1)\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        : : "r"(self), "r"(vec) : "memory");
    __asm__(
        "sqc2    $vf1, 0x0(%0)\n"
        : : "r"(vec) : "memory");
}
