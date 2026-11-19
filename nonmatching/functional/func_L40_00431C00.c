/* functional: medium. No draft; written from PAL asm, compiles (169 diff, scheduling). Wide-arg callees func_L01_00451FE0 and func_L01_003303B8 passed with ints in a0..t3/stack and floats in f12..f19 as retail; first normalised direction (func_0038CF68 on a local) is dead but kept for its call */
/* localdecomp:start func_L40_00431C00 */
extern u8 D_L40_00242930[];
extern u8 D_L40_00249F40[];
extern u8 D_001FE020[];
extern s32 D_001DC310_sda;
extern f32 D_001DC304_sda;
__asm__(".extern D_001DC310_sda, 4");
__asm__(".extern D_001DC304_sda, 4");
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L40_004311A8(u8 *, s32, s32, s32, f32, f32, f32, f32);
extern void func_L39_005F3088(s32);
extern s32 func_L39_005F33E0(s32, s32, u8 *);

void func_L40_00431C00(u8 *m) {
    f32 d[4] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    f32 *src = (f32 *)D_L40_00249F40;
    u8 *v = *(u8 **)(m + 0x68);
    f32 s;
    f32 s15;
    s32 i;
    s32 idx;
    u8 *o;

    d[0] = src[0] - *(f32 *)(m + 0x10);
    d[1] = src[1] - *(f32 *)(m + 0x14);
    d[2] = src[2] - *(f32 *)(m + 0x18);
    d[3] = src[3];
    func_0038CF68(d, d, 1.0f);
    func_L01_00451FE0(m, 0xFF, D_L40_00242930, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                      3.0f, 6.0f, 5.0f, 8.0f, -1.0f, -1.0f, 1.0f, 1.0f);
    s = *(f32 *)(m + 0x2C) / *(f32 *)(*(u8 **)(m + 0x24) + 0x24);
    s15 = s * 1.5f;
    for (i = 0; i < D_001DC310_sda; i++) {
        func_L40_004311A8(m, 5, 0x32, 2, D_001DC304_sda + s15, s15, s, s);
    }
    pos[0] = *(f32 *)(m + 0x0) * 0.0009765625f;
    pos[1] = *(f32 *)(m + 0x4) * 0.0009765625f;
    pos[2] = *(f32 *)(m + 0x8) * 0.0009765625f;
    pos[3] = 0.0f;
    func_L01_003303B8(pos, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 2.5f, 0.0f, 0.0f, 2.0f,
                      1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                      0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    idx = *(s32 *)(v + 0x94);
    if (idx != -1) {
        o = D_001FE020 + (idx << 7);
        if (*(u8 **)(o + 0xDC) == m && o[0xD0] != 0) {
            func_L39_005F3088(idx);
        }
    }
    *(s32 *)(v + 0x94) = -1;
    func_L39_005F33E0(0, 0, m);
}
/* localdecomp:end func_L40_00431C00 */
