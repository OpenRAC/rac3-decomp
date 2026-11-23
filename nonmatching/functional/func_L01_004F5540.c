/* functional: high. 2 words differ: loop counter decrement lands in a different call delay slot (no effect) */
extern vu0_q D_001A4C60[];
extern St_004ECCD8 D_001A4BE0;
extern s32 D_001D545C;
void func_L01_004F5540(void) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);
    struct { vu0_q position, velocity; } v;
    s32 i, size, life;
    f32 speed, angle, elevation, radius;
    vu0_q *base = D_001A4C60;
    u8 *hero = (u8 *)base - 0x80;
    for (i = 0; i < 10; i++) {
        size = (s32)(func_003824E0(4200.0f, 7350.0f) / 1000.0f);
        life = (s32)(func_003824E0(21000.0f, 31500.001953125f) / 1000.0f);
        speed = func_003824E0(0.00300000026f, 0.014f);
        v.position = *base;
        if (D_001D545C != 6) ((f32 *)&v.position)[2] = *(f32 *)(hero + 0x354);
        angle = func_00382538();
        elevation = func_003824E0(0.34906584f, 1.39626336f);
        radius = func_003824E0(0.05f, *(f32 *)(hero + 0x284) + 0.2f);
        func_00382760(&v.velocity, speed, angle, elevation);
        ((f32 *)&v.position)[0] += func_0038D098(angle) * radius;
        ((f32 *)&v.position)[1] += func_0038D0B0(angle) * radius;
        func_L01_004637C8(&v.position, &v.velocity, 0x7000C0F0, 0x70F0, 0x21, size, life, 1);
    }
}
