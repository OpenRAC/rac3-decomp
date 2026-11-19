/* functional: high. Compiles at level_01 (112 diff; stack frame 0xA0 matches; every float constant verified bit-exact against the asm). S_49A348 is the 0x54-byte config block passed to func_003B9C68. */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    f32 f34;
    s32 z[7];
} S_49A348;
extern E_496DC0 *D_L01_001D92E8;
extern s32 D_L01_001D92EC;
extern char D_L01_001D9338[];
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern s32 *func_003B9BD0(s32);
extern void func_003B9C68(s32 *, S_49A348 *);
extern void func_003BABB0(s32 *, s32, f32, f32, f32, f32, f32);
extern void func_003BABD0(s32 *, f32, f32, f32, f32);
extern void func_003BA4E0(s32 *, s32, f32, f32, f32);
extern s32 func_003B9E30(s32 *, s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_0011B2E8(s32, char *, ...);

void func_L01_0049A348(void) {
    S_49A348 s;
    s32 i = 0;
    s32 h;
    s32 cnt;

    s.f0 = func_L01_0047DAE0();
    s.f4 = func_003BB118(0);
    cnt = D_L01_001D92EC;
    s.f8 = 0x14;
    s.fC = cnt;
    s.f10 = (cnt < 7) ? cnt : 6;
    s.f14 = 1;
    s.f18 = 1.0f;
    s.f1C = 0.563596f;
    s.f20 = 0.054f;
    s.f24 = 0.5f;
    s.f28 = 1.0f;
    s.f2C = 1.0f;
    s.f30 = 1.0f;
    s.f34 = 0.795206f;
    s.z[0] = 0;
    s.z[1] = 0;
    s.z[2] = 0;
    s.z[3] = 0;
    s.z[4] = 0;
    s.z[5] = 0;
    s.z[6] = 0;
    func_003B9C68(func_003B9BD0(0), &s);
    func_003BABB0(func_003B9BD0(0), 0, 0.5f, 0.816536f, 0.045f, 0.0425f, 0.35f);
    func_003BABD0(func_003B9BD0(0), 0.500369f, 0.700703f, 0.816536f, 0.312706f);
    func_003BA4E0(func_003B9BD0(0), 1, 0.0265f, 0.00666f, 0.03f);
    if (D_L01_001D92EC > 0) {
        do {
            h = func_003B9E30(func_003B9BD0(0), 0, i);
            i++;
            func_0011B2E8(h, D_L01_001D9338, func_00381FF0(D_L01_001D92E8[i - 1].x0));
        } while (i < D_L01_001D92EC);
    }
}
