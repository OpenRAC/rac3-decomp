/* functional: medium. Plain-C vector math instead of VU0 lqc2/vadd; the w lanes follow retail's vadd.xyz (kept from the first operand). func_L01_0044A850's effect on its two vectors is unknown (it is only called with them), and the result of the 3-float-arg func_L01_004461B8 gets its third argument (f14) as retail passes it. */
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0044A850(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern s32 func_L01_004461B8(f32 *, f32 *, f32, f32, f32);
extern f32 func_L39_00632678(u8 *, void *);
extern f32 D_L39_0025F760[];

/* probe a swept path from the hero's position: returns the (clamped) distance A or a shortened one if the path is blocked */
f32 func_L39_0063C000(u8 *o, f32 a, f32 b, f32 c) {
    f32 v0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    f32 v30[4] __attribute__((aligned(16)));
    f32 out[2];
    f32 *pos = (f32 *)(o + 0xA0);
    f32 x;
    f32 y;
    f32 z;
    f32 r1;
    f32 r2;
    f32 r3;
    s32 k;

    switch (o[0x1A06]) {
    case 0:
        if (c < 0.0f) {
            func_0038CE20(v0, o + 0x120, a);
            v0[2] = v0[2] - (a * a + a) * 0.5f * b;
            v0[0] += pos[0];
            v0[1] += pos[1];
            v0[2] += pos[2];
            for (k = 0; k < 4; k++) v10[k] = pos[k];
            func_L01_0044A850(v10, v0);
            for (k = 0; k < 4; k++) v10[k] = pos[k];
            v10[2] = v10[2] + *(f32 *)(o + 0x1F4) * 2.9f;
            if (func_003D3CB0(v10, v0, 0x22, 0, 0) != 0) {
                c = D_L39_0025F760[2];
            }
        }
        if (!(0.0f < c)) {
            return a;
        }
        z = *(f32 *)(o + 0xA8) - c;
        if (z < 0.01f) {
            return 0.0f;
        }
        x = b * -0.5f;
        if (func_L01_004461B8(&out[0], &out[1], x, *(f32 *)(o + 0x128) - x, z) <= 0) {
            return a;
        }
        if (0.0f < out[0]) {
            return out[0];
        }
        return a;
    case 1:
        for (k = 0; k < 4; k++) v10[k] = ((f32 *)(o + 0x230))[k];
        func_0038CF68(v10, v10, b);
        func_0038CE20(v10, v10, -1.0f);
        break;
    case 2:
        v20[0] = 100.0f;
        v20[2] = 100.0f;
        v20[1] = 100.0f;
        v10[0] = pos[0] - v20[0];
        v10[1] = pos[1] - v20[1];
        v10[2] = pos[2] - v20[2];
        v10[3] = pos[3];
        func_0038CF68(v10, v10, b);
        func_0038CE20(v10, v10, -1.0f);
        break;
    default:
        return a;
    }
    /* modes 1 and 2 share the rest */
    func_0038CE20(v0, o + 0x120, a);
    func_0038CE20(v20, v10, (a * a + a) * 0.5f * b);
    v0[0] = v20[0] + v0[0];
    v0[1] = v20[1] + v0[1];
    v0[2] = v20[2] + v0[2];
    v0[3] = v20[3];
    for (k = 0; k < 4; k++) v30[k] = pos[k];
    v0[0] = pos[0] + v0[0];
    v0[1] = pos[1] + v0[1];
    v0[2] = pos[2] + v0[2];
    v0[3] = pos[3];
    func_L01_0044A850(v30, v0);
    if (func_003D3CB0(pos, v0, 0x22, 0, 0) == 0) {
        return a;
    }
    x = b * -0.5f;
    r1 = func_L39_00632678(o, o + 0x120);
    y = r1 - x;
    r2 = func_L39_00632678(o, pos);
    r3 = func_L39_00632678(o, D_L39_0025F760);
    if (func_L01_004461B8(&out[0], &out[1], x, y, r2 - r3) <= 0) {
        return a;
    }
    if (0.0f < out[0]) {
        return out[0];
    }
    return a;
}
