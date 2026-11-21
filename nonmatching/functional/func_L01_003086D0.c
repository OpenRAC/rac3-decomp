/* functional: high. EXACT at levels 01, 05 and 20 with the file context (func_0038CF68 is declared with void* here; the file declares it later with S_0030CD20 pointers, so that must be reconciled). Retail needs 0xD0 bytes of stack for the point workspace, hence scratch[13]. */
void func_L01_003086D0(u8 *object, vu0_v4 *origin, vu0_v4 *out, f32 radius) {
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    /* Retail reserves 0xD0 bytes for this point workspace. */
    vu0_v4 scratch[13];
    vu0_v4 a, b;
    vu0_v4 *p = (vu0_v4 *)&scratch;
    s32 i;
    f32 angle = 0.0f;
    for (i = 1; i >= 0; i--, p++) {
        angle = func_0038DAB8(angle, 0.5711987018585205f);
        p->w = 0.0f;
        p->y = 0.0f;
        p->x = func_0038D098(angle) * radius;
        p->z = -func_0038D0B0(angle) * radius;
        func_0038D000(p, p, object + 0xC0);
        vec_add_ab(p, p, origin);
    }
    vec_sub_ba(&a, &((vu0_v4 *)&scratch)[0], origin);
    vec_sub_ba(&b, &((vu0_v4 *)&scratch)[1], origin);
    func_0038CE90(out, &a, &b);
    func_0038CF68(out, out, 1.0f);
}
