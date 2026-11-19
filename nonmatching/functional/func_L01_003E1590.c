/* functional: high. 51 diff vs retail; ported from the NTSC-U draft but PAL differs (life=(r*5+2)/6, PAL constants, texture slots 0x17/0x69/0x22 of D_L01_00221098, streak decay -0.006) all re-read from the PAL asm */
extern u8 *D_L01_00221098[];
/* Per-frame sparkle burst for a moby: four independent 1-in-3 chances each spawn a particle
   (three glow sparks with different sizes/textures, one streak along the player direction). */
void func_L01_003E1590(u8 *p) {
    extern void func_00382580(void *, f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_L01_004C7D98(void *, void *);
    extern void func_L01_00466F50(void *, void *, s32, f32, f32);
    vu0_v4 pos, dir, scaled, other;
    u8 *particle;
    s32 life, k;

    if (func_00382468(3) == 0) {
        func_00382580(&dir, 0.035f, 0.05f);
        func_0038CE20(&scaled, &dir, 10.0f);
        vec_add_ab(&pos, &scaled, p + 0x10);
        life = (func_00382498(10, 30) * 5 + 2) / 6;
        k = func_00382498(-1, -3);
        particle = func_L01_004713C8(&pos, &dir, life, 0x5A182, k, 0x40, 0, 0, 126000.0078125f, 231000.0f, 0.0096f);
        if (particle != 0) {
            particle[3] = func_00382468(2) != 0 ? 0x48 : 0x44;
            particle[2] = D_L01_00221098[0x17][0];
        }
    }
    if (func_00382468(3) == 0) {
        func_00382580(&dir, 0.01f, 0.04f);
        func_0038CE20(&scaled, &dir, 10.0f);
        vec_add_ab(&pos, &scaled, p + 0x10);
        life = (func_00382498(10, 30) * 5 + 2) / 6;
        k = func_00382498(-1, -3);
        particle = func_L01_004713C8(&pos, &dir, life, 0x5A182, k, 0x40, 0, 0, 105000.0f, 84000.0f, 0.0096f);
        if (particle != 0) {
            particle[3] = func_00382468(2) != 0 ? 0x48 : 0x44;
            particle[2] = D_L01_00221098[0x69][0];
        }
    }
    if (func_00382468(3) == 0) {
        func_00382580(&dir, 0.01f, 0.03f);
        func_0038CE20(&scaled, &dir, 10.0f);
        vec_add_ab(&pos, &scaled, p + 0x10);
        life = (func_00382498(10, 30) * 5 + 2) / 6;
        k = func_00382498(-1, -3);
        particle = func_L01_004713C8(&pos, &dir, life, 0x5A182, k, 0x40, 0, 0, 84000.0f, 42000.0f, 0.0096f);
        if (particle != 0) {
            particle[3] = func_00382468(2) != 0 ? 0x48 : 0x44;
            particle[2] = D_L01_00221098[0x22][0];
        }
    }
    if (func_00382468(3) == 0) {
        func_00382580(&dir, 0.01f, 0.03f);
        func_0038CE20(&scaled, &dir, 20.0f);
        vec_add_ab(&pos, &scaled, p + 0x10);
        func_L01_004C7D98(p + 0x10, &other);
        func_0038CF68(&other, &other, -func_003824E0(0.01f, 0.05f));
        func_L01_00466F50(&pos, &other, 0x4005A182, -1.0f, -0.006f);
    }
}
