/* functional: high. Draft verified against PAL assembly (random per-spark scale/sign/rotation, velocity from the direction rotated and scaled 0.05 plus 0.06 up, jittered position, two particles per spark; the RNG call whose result retail discards is kept). func_L01_0046B458 is declared in the argument order func_L01_00309708 uses. 161 words differ in codegen only. */
void func_L01_0030BF20(f32 *position, f32 *direction, s32 count, u32 color) {
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382468(s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038D308(void *, void *);
    extern void func_0038D000(void *, void *, void *);
    extern f32 func_L01_00443A18(f32, f32);
    extern s32 func_13D3E0(void);
    extern u8 *func_L01_0046B458(void *, s32, f32, s32, f32, s32, s32, void *, f32, s32);
    vu0_v4 velocity;
    vu0_v4 original;
    vu0_v4 angles;
    vu0_v4 matrix[3];
    f32 scale;
    s32 sign, random, remaining;

    u8 *particle;
    if (count <= 0) return;
    {
    f32 outer = 0.1f;
    f32 inner = 0.07f;
    f32 shrink = 0.7f;
    remaining = count;
    do {
        scale = func_003824E0(1.75f, 2.0f);
        sign = func_00382468(2);
        if (!sign) sign--;
        angles.w = 0;
        angles.y = func_003824E0(-1.5707964f, 1.5707964f);
        angles.x = func_003824E0(-1.5707964f, 1.5707964f);
        angles.z = func_003824E0(-1.5707964f, 1.5707964f);
        func_0038D308(matrix, &angles);
        func_0038D000(&velocity, direction, matrix);
        func_0038CF68((void *)&velocity, (void *)&velocity, 0.05f);
        velocity.z += 0.060000002f;
        *(vu0_q *)&original = *(vu0_q *)position;
        position[0] += func_L01_00443A18(0.0f, 0.15f);
        position[1] += func_L01_00443A18(0.0f, 0.15f);
        position[2] += func_L01_00443A18(0.0f, 0.15f);
        random = (u32)func_13D3E0() % 2;
        particle = func_L01_0046B458(position, 50, scale * outer, color | 0x4F000000, scale, 0, sign, &velocity, 0.0028800003f, 1);
        if (particle) particle[9] = 0x74;
        particle = func_L01_0046B458(position, 50, scale * inner, 0x7FFFFFFF, scale * shrink, 1, -sign, &velocity, 0.0028800003f, 1);
        if (particle) particle[9] = 0x74;
    } while (--remaining);
    }
}
