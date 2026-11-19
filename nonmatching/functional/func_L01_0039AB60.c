/* functional: high. Codex PAL draft re-checked in context: 162 words (same instruction mix and jal list) differs only in scheduling/register allocation/addressing, same calls in the same order.  */
extern vu0_v4 D_L01_001E29C0;
extern f32 D_001A4EC0[1] __attribute__((section(".data")));
typedef struct { u8 pad[0x184]; u8 *p184; } T_0039AB60;
extern T_0039AB60 D_L01_00221098[1];
void func_L01_0039AB60(f32 *origin) {
    extern f32 func_0038D160(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern u8 *func_L01_004669B0(void *, s32, void *, u32, f32, f32, f32, f32, s32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, u32, s32, f32, f32, f32, f32, f32);
    vu0_v4 delta, velocity, position;
    f32 angle, lifetime, radius, pitch, yaw;
    s32 i, size;
    s32 color = 0x7FFF8040;
    s32 flags = 0x44;
    u8 *p, *d;
    vec_sub_ab(&delta, &D_L01_001E29C0, origin);
    angle = func_0038D160(delta.x, delta.y);
    for (i = 19; i >= 0; i--) {
        func_0038CE20((f32 *)&velocity, D_001A4EC0, -(func_003824E0(0.2f, 3.0f) * 0.020000001415610313f));
        size = func_L01_00443A18(1.0f, 2.0f);
        lifetime = func_003824E0(0.3f, 0.75f) * 210000.0f;
        position.x = origin[0] + func_L01_00443A18(0.0f, 0.2f);
        position.y = origin[1] + func_L01_00443A18(0.0f, 0.2f);
        position.z = origin[2] + func_L01_00443A18(0.0f, 0.2f);
        p = func_L01_004669B0(&position, size, &velocity, 0x7F202020, 0.0f, 1.0f, 1.01f, lifetime, 0);
        if (p != 0) {
            *(u16 *)(p + 0xA) = 75;
            d = p + 0x20;
            p[3] = flags;
            p[9] = flags;
            *(f32 *)(d + 0x1C) = 4.0f;
            *(s32 *)(d + 4) = 3;
            d[0xA] = 0x30;
            d[0xB] = p[0xA];
        }
        radius = func_003824E0(1.0f, 2.0f);
        pitch = func_003824E0(0.0f, 1.39626336f);
        yaw = func_L01_00443A18(0.0f, 1.39626336f);
        yaw = func_0038DAB8(angle, yaw);
        func_00382760(&velocity, radius * 0.020000001415610313f, yaw, pitch);
        position.x = origin[0] + func_L01_00443A18(0.0f, 0.1f);
        position.y = origin[1] + func_L01_00443A18(0.0f, 0.1f);
        position.z = origin[2] + func_L01_00443A18(0.0f, 0.1f);
        lifetime = func_003824E0(0.1f, 0.3f) * 210000.0f;
        p = func_L01_0046A610(&position, &velocity, 25, 0x7F, color, size, lifetime, 500.0f, 1.0f, 0.0f, 0.0f);
        if (p != 0) p[2] = D_L01_00221098[0].p184[6];
    }
}
