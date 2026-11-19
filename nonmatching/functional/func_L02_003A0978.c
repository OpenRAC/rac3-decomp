/* functional: high. Rewritten from PAL asm (the NTSC-U draft differs: PAL callees, 0.0016 size scale, -0.7999999523 slope). Every constant and callee checked; 139-diff gap is register allocation (this build keeps the texture address in a saved register). */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A0978;

extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern u8 D_001D66B0[];
extern u8 *D_L02_0021E23C;

void func_L02_003A0978(u8 *a0) {
    V4_3A0978 pos;
    V4_3A0978 v10;
    u8 *st;
    u8 *p;
    f32 r0;
    f32 base;
    f32 lin;
    f32 ang;
    f32 zup;
    f32 sz;
    s32 life;
    s32 color;
    s32 b5;

    st = *(u8 **)(a0 + 0x68);
    r0 = func_003824E0(0.0f, *(f32 *)(st + 8));
    lin = *(f32 *)(st + 0xC) * -0.7999999523162842f + 0.9f;
    base = lin + (0.1f - lin) * r0;
    ang = func_00382538();
    zup = *(f32 *)(st + 8) - 0.5f;
    if (zup < 0.0f) {
        zup = 0.0f;
    }
    *(u128_t *)&v10 = 0;
    zup = zup * 3.0f + r0 * 3.0f;
    v10.x = base * func_0038D0B0(ang);
    v10.y = base * func_0038D098(ang);
    v10.z = zup;
    *(u128_t *)&pos = *(u128_t *)&v10;
    vec_add_ab(&pos, a0 + 0x10, &pos);
    life = func_00382498(-10, 10) + 30;
    sz = func_003824E0(-0.1f, 0.1f) + 0.3f;
    color = st[0x16] << 16 | st[0x15] << 8 | st[0x14];
    b5 = 0;
    p = func_L01_0046FB40(&pos, D_001D66B0, life, color, func_00382468(2) ? -1 : 1, 0x40, 0x20, 0,
                          sz * 210000.0f, sz * 210000.0f, 0.0016f);
    if (p != 0) {
        b5 = p[8] + 0x20;
        p[2] = *D_L02_0021E23C;
    }
    p = func_L01_0046FB40(&pos, D_001D66B0, life, 0xF7F7F7, func_00382468(2) ? -1 : 1, 0x30, 0x30, 0,
                          sz * 0.4f * 210000.0f, sz * 0.4f * 210000.0f, 0.0016f);
    if (p != 0) {
        p[8] = b5;
        p[2] = *D_L02_0021E23C;
    }
}
