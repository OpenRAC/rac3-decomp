/* func_L24_003B66C8: level 24 near miss, 3 differences (see nonmatching/README.md). Its place is L24_003B6050.c (-mvu0-use-vf0-vf2, @ps2as); func_L24_003B6320's block there declares it extern void func_L24_003B66C8(void), which must become the K&R extern void func_L24_003B66C8(); for this definition (func_L24_003B6320 still matches with that). */
extern void func_003C2F58(void *, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040A8C0(void *, void *, u32, s32, u32, u32, u32, u32, f32, f32, f32);
extern void func_L01_00408C98(void *, s32, void *, void *, s32, s32, f32, s32, s32, s32);
__asm__(".extern D_L24_001DE808, 4");
__asm__(".extern D_L24_001DE804, 4");
extern u32 D_L24_001DE808;
extern s32 D_L24_001DE804;

void func_L24_003B66C8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 w1[4] __attribute__((aligned(16)));
    f32 w2[4] __attribute__((aligned(16)));
    f32 m[16] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    f32 t;
    u8 *q;

    t = *(f32 *)(s + 0x8E0) - 0.1f;
    *(f32 *)(s + 0x8E0) = t;
    if (t <= -8.0f) {
        *(f32 *)(s + 0x8E0) = t + 8.0f;
    }
    func_003C2F58(*(u8 **)(s + 0x8DC), 0, a);
    func_003C2F58(*(u8 **)(s + 0x8DC), 2, b);
    func_003C2F58(*(u8 **)(s + 0x8DC), 1, c);
    func_003C2F58(*(u8 **)(s + 0x8DC), 3, d);
    vec_sub_ba(w1, a, c);
    func_0038CF68(w1, w1, *(f32 *)(s + 0x8E8));
    vec_add_ba(c, w1, a);
    vec_sub_ba(w2, b, d);
    func_0038CF68(w2, w2, *(f32 *)(s + 0x8E4));
    vec_add_ab(d, w2, b);
    func_003C2EC0(*(u8 **)(s + 0x8DC), 1, m);
    *(vu0_q *)w = *(vu0_q *)m;
    func_0038CF68(w, w, -2.75f);
    *(vu0_q *)(s + 0x6D0) = *(vu0_q *)w;
    *(f32 *)(s + 0x6DC) = 1.0f;
    *(vu0_q *)w = *(vu0_q *)m;
    func_0038CF68(w, w, 0.75f);
    *(vu0_q *)(s + 0x6C0) = *(vu0_q *)w;
    *(f32 *)(s + 0x6CC) = 1.0f;
    q = s + 0x6C0;
    func_L01_0040A8C0(a, c, D_L24_001DE808, 1, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0.035f, 0.45f, *(f32 *)(s + 0x8E0));
    func_L01_0040A8C0(b, d, D_L24_001DE808, 1, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0.035f, 0.45f, *(f32 *)(s + 0x8E0));
    func_L01_0040A8C0(a, c, D_L24_001DE808, 1, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0.08f, 0.75f, *(f32 *)(s + 0x8E0));
    func_L01_0040A8C0(b, d, D_L24_001DE808, 1, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0.08f, 0.75f, *(f32 *)(s + 0x8E0));
    func_L01_00408C98(q, D_L24_001DE804, s + 0x2C0, s + 0x4C0, *(s32 *)(s + 0x8EC), *(s32 *)(s + 0x8FC), *(f32 *)(s + 0x8F8), *(s32 *)(s + 0x8F0), *(s32 *)(s + 0x8F4), 5);
}
