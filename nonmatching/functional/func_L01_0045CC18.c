/* functional: medium. Returns f0 (retail returns the float difference; callers' decl in 0045C510 file is void/s32, ignored there). Scratch sizes for func_0038D308's output (m) assumed >= retail's 0x30. Not byte exact (no abs.s/lq-sq asm helpers). */
extern f32 func_L01_00451700(void *, void *, void *);
extern void func_L01_00448890(void *, f32, f32, f32, f32, void *, s32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
f32 func_L01_0045CC18(u8 *self, u8 *s, u8 *vec, void *a3) {
    f32 v[4] __attribute__((aligned(16)));
    f32 m[16] __attribute__((aligned(16)));
    s32 junk[4] __attribute__((aligned(16)));
    f32 a;
    v[0] = ((f32 *)vec)[0];
    v[1] = ((f32 *)vec)[1];
    v[2] = ((f32 *)vec)[2];
    v[3] = ((f32 *)vec)[3];
    a = func_L01_00451700(self, v, a3);
    junk[0] = 0;
    func_L01_00448890(junk, a, *(f32 *)(s + 20), *(f32 *)(s + 24), 3.1415927f, s + 180, 0);
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = *(f32 *)(s + 180);
    v[3] = 0.0f;
    func_0038D308(m, v);
    func_0038D5F0(self + 192, self + 192, m);
    return __builtin_fabsf(a) - __builtin_fabsf(*(f32 *)(s + 180));
}
