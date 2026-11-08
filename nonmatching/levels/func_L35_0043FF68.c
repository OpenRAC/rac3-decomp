/* func_L35_0043FF68: NEAR 1 (catalogue size: retail asm ends at jr $ra, delay-slot addiu not counted in the 236 bytes); needs --as ps2as (inline float consts)
   VU0 via two __asm__ blocks (rule wave 4), rac2 twin func_002C1FC0 only loosely; everything else equal.
   file src/levels/35_vidcomic_5/L35_0043FF68.c (no vu0 flag needed for block form) */
extern int func_0038CB00(short *);
extern void func_003CD250(void *);
extern u8 *D_L35_0021F3E8[];
extern f32 D_L35_001D7DB4;
__asm__(".extern D_L35_001D7DB4, 4");

void func_L35_0043FF68(char *self) {
    char *state = self + 0x20;
    char *p;
    if (func_0038CB00((short *)(self + 0xA))) {
        *(f32 *)(state + 8) -= *(f32 *)(state + 0x18);
    }
    __asm__ __volatile__(
        "lqc2    $vf1, 0x10(%0)\n"
        "lqc2    $vf2, 0x20(%0)\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2    $vf1, 0x10(%0)\n"
        : : "r"(self) : "memory");
    p = *(char **)(state + 0x1C);
    if (p != 0) {
        __asm__ __volatile__(
            "lqc2    $vf2, 0x0(%1)\n"
            "lqc2    $vf1, 0x10(%0)\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2    $vf1, 0x10(%0)\n"
            : : "r"(self), "r"(p) : "memory");
    }
    self[8] += *(u8 *)(state + 0x14);
    if ((u8)self[2] == D_L35_0021F3E8[0][0]) {
        *(f32 *)(self + 0xC) += D_L35_001D7DB4 * 0.020000001f * 210000.0f;
    }
    if (*(f32 *)(self + 0x18) < *(f32 *)(state + 0x10)) {
        func_003CD250(self);
    }
}
