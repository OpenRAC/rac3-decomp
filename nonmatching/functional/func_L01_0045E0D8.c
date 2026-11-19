/* functional: high. 23 diff at default flags: retail has two nops before sqrt.s (FPU hazard) that the inline sqrt_asm does not get; otherwise identical; callee arg 2 passes b through the unset $a1 (register passthrough kept explicitly) */
extern void func_0038CF68(f32, void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038CC88(void *, void *, s32);

void func_L01_0045E0D8(u8 *a, u8 *b, void *c) {
    f32 m[12] __attribute__((aligned(16)));
    f32 q[4];
    f32 n[4];
    f32 l;

    func_0038CF68(1.0f, n, b);
    func_0038CE90(q, n, a + 0x20);
    func_0038CE20(q, q, 0.05f);
    l = func_0038CEA8(q);
    q[3] = -sqrt_asm(1.0f - l * l);
    func_0038D810(q, m);
    func_0038D5F0(a, m, a);
    if (c != 0) {
        func_0038CC88(c, m, 0x30);
    }
}
