/* functional: high. Plain-C port of the PAL asm; the single-pass loop (counter 0 to -1) is unrolled; vadd.xyz as plain adds; the retail position's w is stack garbage, set to 0 (callee only uses xyz). */
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_0046B288(void *, s32, s32, s32, f32, f32);

void func_L01_00369C48(f32 *pos) {
    f32 v[4] __attribute__((aligned(16)));
    f32 angle, radius, a, b;
    s32 n;
    u8 *p;

    /* retail's loop counter goes 0 -> -1 and exits after one pass */
    angle = func_00382538();
    radius = func_003824E0(0.0f, 0.6f);
    a = func_003824E0(0.0f, 1.2f);
    b = func_003824E0(1.0f, 4.0f);
    n = func_00382498(70, 130);
    v[0] = func_0038D098(angle) * radius;
    v[1] = func_0038D0B0(angle) * radius;
    v[2] = 0.0f;
    v[3] = 0.0f;
    v[0] = v[0] + pos[0];
    v[1] = v[1] + pos[1];
    v[2] = v[2] + pos[2];
    p = func_L01_0046B288(v, 0x5005B182, 0x5B182, n, a, b);
    if (p != 0) {
        p[3] = 68;
    }
}
