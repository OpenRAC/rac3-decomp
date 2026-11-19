/* func_L32_003A25B0: 73 diff with the file's flags. Calls, stack layout, registers, floats all match; remaining: (1) gcc hoists i++ above the first call (retail keeps addiu i at the loop end, copied into the beql delay slots), so the whole loop tail is shifted; (2) the vec_add_ba on p+0x10 gets vf2 for the first-loaded operand where retail has vf1 (vadd.xyz vf2,vf2,vf1), and lui/mtc1 f12 (-1.0f) is scheduled before the lqc2 pair instead of between vadd and sqc2. Tried for/do-while, q++ vs q[i], vec_add_ab. */
extern s32 D_L32_001DF9C0;
__asm__(".extern D_L32_001DF9C0, 16");
extern s32 D_L32_001DE6D8;
extern s32 D_L32_001DE6B4;
extern s32 D_L32_001DE6B8;
extern f32 D_L32_001DE6BC;
__asm__(".extern D_L32_001DE6D8, 4");
__asm__(".extern D_L32_001DE6B4, 4");
__asm__(".extern D_L32_001DE6B8, 4");
__asm__(".extern D_L32_001DE6BC, 4");
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L03_0034B440(f32, f32, f32, s32, s32, s32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_L02_003BA9F8(void *, void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
typedef int u128_t __attribute__((mode(TI)));

void func_L32_003A25B0(u8 *a0, f32 a, f32 b) {
    u8 *v = *(u8 **)(a0 + 0x68);
    f32 ang, r, s, m, k, hi, lo;
    u8 **q;
    s32 i, mod;
    u8 *o;
    u8 *p;
    vu0_v4 d, h, e, f, g;

    *(f32 *)(v + 0x224) = func_0038DAB8(*(f32 *)(v + 0x224), a);
    r = func_L03_0034B440((f32)D_L32_001DF9C0, (f32)D_L32_001DE6D8, 1.0f, 0, 1, 0);
    mod = D_L32_001DF9C0 % D_L32_001DE6B4;
    if (mod < D_L32_001DE6B8) {
        s = func_0038D0B0(func_L03_0034B440((f32)mod, (f32)D_L32_001DE6B8, 1.0f, 0, 1, 0));
    } else {
        s = 0.0f;
    }
    m = D_L32_001DE6BC * s;
    hi = b * (m + 1.0f);
    lo = b * (1.0f - m);
    d.x = func_0038D098(r);
    d.z = func_0038D0B0(r);
    d.y = 0.0f;
    q = (u8 **)(v + 0x200);
    i = 0;
    do {
        ang = func_0038DAB8(*(f32 *)(v + 0x224), (f32)i * 6.2831855f / 6.0f);
        e.x = func_0038D098(ang);
        e.z = func_0038D0B0(ang);
        e.y = 0.0f;
        func_L02_003BA9F8(&e, &d, &f, &g);
        func_0038CE20(&f, &f, hi);
        func_0038CE20(&g, &g, lo);
        vec_add_ab(&e, &f, &g);
        o = q[i];
        if (o != 0) {
            p = *(u8 **)(o + 0x68);
            if (p != 0) {
                vec_add_ba(p + 0x10, a0 + 0x10, &e);
                *(u128_t *)p = *(u128_t *)(v + 0x60);
                func_0038CE20(&h, &e, -1.0f);
                vec_add_ba(&h, &h, p + 0x10);
            }
        }
        i++;
    } while (i < 6);
}
