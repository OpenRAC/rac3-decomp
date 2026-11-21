/* functional: medium. Not byte-matched. Visibility test func_0038DC20 is hand-written asm (returns <0 when culled). The 128-bit lq copy of pos is written as three floats plus w=2*scale (retail overwrites w). vadd.xyz keeps vec10.w for vec20.w. */
extern s32 D_L01_001DE7E4;
extern s32 func_0038DC20(void *, f32);
extern void func_00382580(void *, f32, f32);
extern void func_L01_003B84F0(void *, s32, s32, s32, s32, f32);

void func_L01_003B8878(u8 *m, f32 fx, f32 fy, f32 fz, f32 scale, s32 count, s32 a2, s32 a3) {
    f32 vec0[4] __attribute__((aligned(16)));
    f32 vec10[4] __attribute__((aligned(16)));
    f32 vec20[4] __attribute__((aligned(16)));
    f32 *pos = (f32 *)(m + 0x10);
    f32 f21, f22, f23;
    s32 i;

    if ((a2 ^ 0x1FF) == 0) {
        a2 = 0xFF;
    }
    f23 = fx * scale;
    f22 = fy * scale;
    f21 = fz * scale;
    vec0[0] = pos[0];
    vec0[1] = pos[1];
    vec0[2] = pos[2];
    vec0[3] = scale + scale;
    if (func_0038DC20(vec0, a2 <= 0x80 ? 128.0f : (f32)a2) < 0) {
        return;
    }
    func_00382580(vec10, f22 * 0.8f, f22 * 1.2f);
    vec10[2] = vec10[2] + f23;
    vec10[0] = vec10[0] + pos[0];
    vec10[1] = vec10[1] + pos[1];
    vec10[2] = vec10[2] + pos[2];
    for (i = 1; i >= 0; i--) {
        func_00382580(vec20, f21 * 0.15f, f21);
        vec20[0] = vec10[0] + vec20[0];
        vec20[1] = vec10[1] + vec20[1];
        vec20[2] = vec10[2] + vec20[2];
        vec20[3] = vec10[3];
        func_L01_003B84F0(vec20, count, a2, a3, D_L01_001DE7E4, scale * 0.04f);
    }
}
