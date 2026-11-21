/* functional: high. COP2 add of the target position offset, a distance/collision test, and a hero-identity check; only scheduling of the two hero-slot compares differs. */
extern s32 func_L01_003FB640(f32 *, s32, u8 *, f32);
__asm__(".extern D_L30_001DD730, 4");
extern f32 D_L30_001DD730;
extern s32 D_L30_001E9018;
extern u8 D_1A4BE0[];
void func_L30_003509A8(O_3501B0 *self) {
    __asm__ __volatile__(
        "lqc2    $vf1, 0x10(%0)\n"
        "lqc2    $vf2, 0x30(%1)\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2    $vf1, 0x10(%0)\n"
        : : "r"(self), "r"(self->x68) : "memory");
    if (func_L01_003FB640((f32 *)self->x10, 0x10, (u8 *)self, D_L30_001DD730) != 0) {
        s32 v = D_L30_001E9018;
        if (v == 0 || (v != *(s32 *)(D_1A4BE0 + 0x25C0) && v != *(s32 *)(D_1A4BE0 + 0x1B24))) {
            func_L01_004450F0(self, 1, -1);
        }
    }
}
