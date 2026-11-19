/* functional: high. Ported from the NTSC-U draft and re-read against the PAL assembly: PAL uses 50-frame lifetimes, 0.02 (not 1/60) velocity scales, 0.00288 drag and the PAL callee/global names. Spawns `count` pairs of billboard sparks around a point, with random size, spin, velocity and a small positional jitter; the spawned effects get byte 9 = 0x74. */
/* localdecomp:start func_L03_0034A4B8 */
extern vu0_v4 D_L03_001E2440;
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_0046B458(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);

void func_L03_0034A4B8(f32 *position, s32 count) {
    vu0_v4 velocity, at, delta, axis, base;
    f32 size, angle, z;
    s32 spin, i;
    u8 *p;
    vec_sub_ab(&delta, &D_L03_001E2440, position);
    func_0038CF68(&base, &delta, 0.3f);
    delta.z = 0.0f;
    axis.x = 0.0f;
    axis.y = 0.0f;
    axis.z = 1.0f;
    axis.w = 1.0f;
    if (count > 0) {
    z = delta.z;
    i = count;
    do {
        size = func_003824E0(0.5f, 2.0f);
        spin = func_00382468(2);
        if (spin == 0) spin--;
        angle = func_003824E0(-1.0471976f, 1.0471976f);
        func_0038D890(&velocity, &delta, &axis, angle);
        func_0038CF68(&velocity, &velocity, func_003824E0(0.05f, 3.0f) * 0.02f);
        velocity.z = func_003824E0(1.0f, 5.0f) * 0.02f;
        vec_add_ab(&at, position, &base);
        position[0] += func_L01_00443A18(z, 0.15f);
        position[1] += func_L01_00443A18(z, 0.15f);
        position[2] += func_L01_00443A18(z, 0.15f);
        p = func_L01_0046B458(&at, 50, size * 0.1f, size, 0xDD10FF10, 0, spin, &velocity, 0.00288f, 0);
        if (p) p[9] = 0x74;
        p = func_L01_0046B458(&at, 50, size * 0.07f, size * 0.7f, 0xDD10FF10, 1, -spin, &velocity, 0.00288f, 0);
        if (p) p[9] = 0x74;
    } while (--i != 0);
    }
}
/* localdecomp:end func_L03_0034A4B8 */
