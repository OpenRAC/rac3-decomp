/* functional: high. EXACT match at level 01 (byte-identical under the file's flags). Spawns a trail particle (func_L01_00468678) behind a moby unless func_00382468(4) is set. */
extern s32 func_00382468(s32);
extern f32 func_003C3EC8(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_00468678(void *, void *, s32, f32, f32);

void func_L01_0032BDD8(u8 *moby) {
    f32 velocity[4];
    f32 got;
    u8 *vars = *(u8 **)(moby + 0x68);

    if (func_00382468(4) != 0) {
        return;
    }
    got = func_003C3EC8(moby + 0x10, velocity);
    func_0038CE20(velocity, vars, 0.25f);
    func_L01_00468678(moby + 0x10, velocity, 0x88A0A0A0, func_003824E0(0.05f, 0.1f) * 210000.0f, got);
}
