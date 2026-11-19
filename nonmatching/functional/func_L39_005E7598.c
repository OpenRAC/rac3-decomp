/* functional: high. Same instruction stream as retail except the prologue (retail saves s-regs with sq in a 0xC0 frame, mine sd in 0x80) and two div.s hazard nops before the f20 divide; behaviour identical. */
/* localdecomp:start func_L39_005E7598 */
typedef struct { f32 a, b, c, d; } V4_005E7598;
__asm__(".extern D_L39_00241120, 16");
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241130, 16");
extern f32 D_L39_00241130[4] __attribute__((section(".sdata")));
__asm__(".extern D_001D8538_sda, 4");
extern f32 D_001D8538_sda __attribute__((section(".sdata")));
__asm__(".extern D_001D853C_sda, 4");
extern f32 D_001D853C_sda __attribute__((section(".sdata")));
__asm__(".extern D_001D8540_sda, 4");
extern f32 D_001D8540_sda __attribute__((section(".sdata")));
__asm__(".extern D_001D8544_sda, 4");
extern f32 D_001D8544_sda __attribute__((section(".sdata")));
__asm__(".extern D_001D8548_sda, 4");
extern f32 D_001D8548_sda __attribute__((section(".sdata")));
__asm__(".extern D_001D854C_sda, 4");
extern f32 D_001D854C_sda __attribute__((section(".sdata")));
__asm__(".extern D_001D84F8_sda, 16");
extern V4_005E7598 D_001D84F8_sda[4];

extern void func_0038E150(s32);
extern void func_003BAF90(s32, void *, void *);
extern s32 func_003B5060(s32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8B98(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00517190(s32, s32);

s32 func_L39_005E7598(s32 p0, f32 v1, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5, s32 p6, s32 p7,
                      s32 p8, s32 p9, s32 p10, s32 p11, s32 p12, s32 p13) {
    f32 v[2];
    f32 d;
    s32 ok;
    s32 i;

    v[1] = v1;
    func_0038E150(0);
    v[0] = 1.0f;
    func_003BAF90(p9, &v[0], &v[1]);
    ok = func_003B5060(p1) != 0;
    d = D_L39_00241130[0] / D_L39_00241130[*D_L39_00241120 - 1];
    { s32 r = func_003E8EF0(p4, 0x35, 0x331465B7, D_001D8538_sda, D_001D853C_sda, 1.0f, d, v[1]) != 0; ok &= r; }
    { s32 r = func_003E8EF0(p5, 0x36, 0x802299DE, D_001D8538_sda, D_001D853C_sda, 1.0f, d, v[1]) != 0; ok &= r; }
    { s32 r = func_003E8EF0(p2, 0x33, 0x332299DE, D_001D8538_sda, D_001D853C_sda, 1.0f, d, v[1]) != 0; ok &= r; }
    { s32 r = func_003E8EF0(p3, 0x34, 0x332299DE, D_001D8538_sda, D_001D853C_sda, 1.0f, d, v[1]) != 0; ok &= r; }
    { s32 r = func_003E9138(p6, 0x331465B7, 0, D_001D8538_sda, D_001D853C_sda, D_001D8540_sda, D_001D8544_sda) != 0; ok &= r; }
    { s32 r = func_003E9270(p8, 0x332299DE, D_001D8538_sda, D_001D853C_sda, D_001D8540_sda, D_001D8544_sda, D_001D8548_sda, D_001D854C_sda) != 0; ok &= r; }
    { s32 r = func_003E8B98(p1, p2, p3, p4, p5, p6, p8) != 0; ok &= r; }
    { s32 r = func_003E8FE8(p7, p9, 0x8066CCFF, 0.5f, 0.0745f, v[0], v[0]) != 0; ok &= r; }
    { s32 r = func_003E8630(p1, p7) != 0; ok &= r; }
    { s32 r = func_L01_00516AA0(p7, 0x2040, 1) != 0; ok &= r; }
    if (p10 != 0) {
        s32 s = p11 != 0 ? func_00381FF0(p11) : 0;
        { s32 r = func_003E8FE8(p10, s, 0x8066CCFF, 0.1675f, 0.932f, 0.9f, 0.9f) != 0; ok &= r; }
        { s32 r = func_L01_00516AA0(p10, 0x2040, 1) != 0; ok &= r; }
        { s32 r = func_003E8630(p1, p10) != 0; ok &= r; }
    }
    if (p12 != 0) {
        s32 s = p13 != 0 ? func_00381FF0(p13) : 0;
        { s32 r = func_003E8FE8(p12, s, 0x8066CCFF, 0.8325f, 0.932f, 0.9f, 0.9f) != 0; ok &= r; }
        { s32 r = func_L01_00516AA0(p12, 0x2040, 1) != 0; ok &= r; }
        { s32 r = func_003E8630(p1, p12) != 0; ok &= r; }
    }
    for (i = 0; i < 4; i++) {
        s32 id = 0x590000 + i;
        { s32 r = func_003E9138(id, 0x332299DE, 0, D_001D84F8_sda[i].a, D_001D84F8_sda[i].b, D_001D84F8_sda[i].c, D_001D84F8_sda[i].d) != 0; ok &= r; }
        { s32 r = func_L01_00517190(id, 0xED5A) != 0; ok &= r; }
        { s32 r = func_003E8630(p1, id) != 0; ok &= r; }
    }
    {
        s32 r = func_003E8348(p0, p1) != 0;
        return ok & r;
    }
}
/* localdecomp:end func_L39_005E7598 */
