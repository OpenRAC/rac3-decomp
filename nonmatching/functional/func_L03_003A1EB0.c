/* functional: high. PAL port of the NTSC draft: spark burst (1-3 sparks, two particle spawns each). PAL constants (0.02 speed scale, life=(rand(20,40)*5+2)/6 rescale) taken from the asm; 128-bit origin copy done as 4 floats; not byte-exact (regalloc/scheduling). */
extern u8 *D_L03_0021F298[];
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern void func_003C4C18(void *, f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L03_003A1EB0(void *o) {
    f32 *origin = o;
    f32 pos[4];
    f32 vel[4];
    s32 n;
    s32 spin;
    s32 life;
    u8 tint;
    f32 speed;
    f32 heading;
    f32 elevation;
    f32 size;
    u8 *p;

    n = func_00382498(1, 3);
    while (n > 0) {
        pos[0] = origin[0];
        pos[1] = origin[1];
        pos[2] = origin[2];
        pos[3] = origin[3];
        func_003C4C18(pos, 0.3f);
        tint = 0;
        speed = func_003824E0(3.0f, 5.5f) * 0.020000001415610313f;
        heading = func_00382538();
        elevation = func_003824E0(1.0471976f, 3.1415927f);
        func_00382760(vel, speed, heading, elevation);
        spin = func_00382468(2) == 0 ? 3 : 0xFD;
        life = (func_00382498(20, 40) * 5 + 2) / 6;
        size = func_003824E0(0.25f, 0.75f) * 210000.0f;
        p = func_L01_0046FB40(pos, vel, life, 0x808020, spin, 0x7F, 0, size, size, 0.00392000005f, 0);
        size *= 0.3f;
        if (p != 0) {
            p[2] = D_L03_0021F298[89][0];
            tint = p[8] + 0x20;
        }
        p = func_L01_0046FB40(pos, vel, life, 0xFFFFFF, spin, 0x7F, 0x40, size, size, 0.00392000005f, 0);
        n--;
        if (p != 0) {
            p[8] = tint;
            p[2] = D_L03_0021F298[89][0];
        }
    }
}
