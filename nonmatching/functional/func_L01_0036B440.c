/* functional: high. Plain-C port of the PAL asm (the draft's call order and constants re-verified); vsub.xyz as plain subtracts; one RNG call result is discarded as in retail. Uses V4_365E28 from the file's context for func_00382760's prototype. */
extern f32 func_0038D160(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern f32 D_L01_001E29C0[4];

void func_L01_0036B440(f32 *origin) {
    f32 delta[4] __attribute__((aligned(16)));
    f32 velocity[4] __attribute__((aligned(16)));
    f32 position[4] __attribute__((aligned(16)));
    f32 angle, speed, tilt, yaw, lifetime;
    s32 type, i;

    /* vsub.xyz: xyz = D - origin, w from D */
    delta[0] = D_L01_001E29C0[0] - origin[0];
    delta[1] = D_L01_001E29C0[1] - origin[1];
    delta[2] = D_L01_001E29C0[2] - origin[2];
    delta[3] = D_L01_001E29C0[3];
    angle = func_0038D160(delta[0], delta[1]);
    for (i = 14; i >= 0; i--) {
        speed = func_003824E0(0.5f, 1.0f);
        type = (s32)func_L01_00443A18(1.0f, 2.0f);
        func_003824E0(0.05f, 0.2f);
        tilt = func_003824E0(0.0f, 1.39626336f);
        yaw = func_L01_00443A18(0.0f, 1.39626336f);
        yaw = func_0038DAB8(angle, yaw);
        func_00382760((V4_365E28 *)velocity, speed * 0.020000001415610313f, yaw, tilt);
        position[0] = origin[0] + func_L01_00443A18(0.0f, 0.1f);
        position[1] = origin[1] + func_L01_00443A18(0.0f, 0.1f);
        position[2] = origin[2] + func_L01_00443A18(0.0f, 0.1f);
        lifetime = 210000.0f * func_003824E0(0.05f, 0.2f);
        func_L01_0046A610(position, velocity, 25, 127, 0x7F7F7F, type,
            lifetime, 500.0f, 1.0f, 0.0f, 2.0f);
    }
}
