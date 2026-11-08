/* func_L01_00450F00: NEAR 2 diff (ld ra / ld s0 epilogue order). Two non-volatile asm statements with m operands. */
typedef int Q_450F00 __attribute__((mode(TI)));
extern void func_0038D000(void *a, void *b, void *c);

void func_L01_00450F00(u8 *self, Q_450F00 *vec) {
    func_0038D000(vec, *(u8 **)(self + 0x68) + 0x20, self + 0xC0);
    __asm__("lqc2 $vf2, %1\n lqc2 $vf1, %0\n vadd.xyz $vf1, $vf1, $vf2\n"
        : "+m"(*vec) : "m"(*(Q_450F00 *)(self + 0x10)) : "vf1", "vf2");
    __asm__("sqc2 $vf1, %0\n" : "=m"(*vec) : "m"(*vec) : "vf1");
}
