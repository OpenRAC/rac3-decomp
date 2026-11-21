/* functional: high. Retail vsub.xyz of the camera-ish constant minus pos written as plain float subtracts (w untouched in both); every call, constant and argument order checked against the asm. */
typedef struct { u8 pad; u8 level; u8 tail[0xEE]; } Row_0035CAD0;
extern S_38C110v D_L01_001E29C0;
extern u8 D_001425C0[];
extern Row_0035CAD0 D_L01_002C5600[];
extern u8 D_L01_001D66B0[];
void func_L01_0035CAD0(S_38C110v *pos)
{
    extern f32 func_0038D160(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern void func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_00470668(void *, void *, s32, f32);
    extern void func_L01_00470C78(void *, s32, u32, s32, s32, void *, s32, s32, s32, s32, f32, f32);
    S_38C110v direction, velocity, spawn;
    s32 i, j, kind;
    f32 heading, scale, angle, azimuth, amount;
    f32 lifetime = 210000.0f;

    direction.x = D_L01_001E29C0.x - pos->x;
    direction.y = D_L01_001E29C0.y - pos->y;
    direction.z = D_L01_001E29C0.z - pos->z;
    heading = func_0038D160(direction.x, direction.y);
    for (i = 7; i >= 0; i--) {
        scale = func_003824E0(0.5f, 1.0f);
        kind = (s32)func_L01_00443A18(1.0f, 2.0f);
        func_003824E0(0.05f, 0.2f);
        angle = func_003824E0(0.0f, 1.39626336f);
        azimuth = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.39626336f));
        func_00382760(&velocity, scale * 0.0200000014f, azimuth, angle);
        spawn.x = pos->x + func_L01_00443A18(0.0f, 0.1f);
        spawn.y = pos->y + func_L01_00443A18(0.0f, 0.1f);
        spawn.z = pos->z + func_L01_00443A18(0.0f, 0.1f);
        amount = func_003824E0(0.05f, 0.2f);
        func_L01_0046A610(&spawn, &velocity, 25, 127, 0x7F7F7F, kind, amount * lifetime, 500.0f, 1.0f, 0.0f, 1.0f);
    }
    if (D_L01_002C5600[D_001425C0[0x2F]].level >= 2) {
        velocity.x = D_L01_001E29C0.x - pos->x;
        velocity.y = D_L01_001E29C0.y - pos->y;
        velocity.z = D_L01_001E29C0.z - pos->z;
        velocity.w = D_L01_001E29C0.w; /* vsub.xyz keeps the constant quad's w */
        func_0038CF68(&velocity, &velocity, func_003824E0(0.05f, 0.1f));
        for (j = 7; j >= 0; j--) {
            velocity.x += func_003824E0(-0.03f, 0.03f);
            velocity.y += func_003824E0(-0.03f, 0.03f);
            velocity.z += func_003824E0(0.0f, 0.03f);
            func_L01_00470668(pos, &velocity, (func_00382498(25, 40) * 5 + 2) / 6, 0.00584000023f);
        }
    }
    if (D_L01_002C5600[D_001425C0[0x2F]].level >= 3) {
        func_L01_00470C78(pos, 33, 0x64FFFFFF, 2, 4, D_L01_001D66B0, 0, 1, 6, 1, 0.1f, 1.04999995f);
        func_L01_00470C78(pos, 25, 0x3C3882F7, 2, 0, D_L01_001D66B0, 0, 0, 6, 1, 0.4f, 2.04999995f);
        func_L01_00470C78(pos, 33, 0x323882F7, 0, 2, D_L01_001D66B0, 0, 4, 6, 1, 0.15f, 1.64999998f);
        func_L01_00470C78(pos, 22, 0x3C0045F7, 2, 0, D_L01_001D66B0, 3, 0, 6, 1, 0.5f, 2.34999990f);
        func_L01_00470C78(pos, 22, 0x1E0045F7, 1, -2, D_L01_001D66B0, 3, 4, 6, 1, 0.3f, 1.75f);
    }
}
