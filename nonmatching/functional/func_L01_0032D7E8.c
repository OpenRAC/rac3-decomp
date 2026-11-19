/* functional: high. Compiles; same shape as func_L01_0032CF90 (glow quads), with alloc id 0xB, size rand(0.03,0.0625), no forward offset on the matrix position, other colour constants. First arg unused in retail. */
extern void func_L01_0032CEB8(void *);
extern long func_00389598(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_00382538(void);
extern void func_0038D328(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);
extern u8 D_001E2880[];
extern u8 D_001425D5;
extern u8 D_L01_002C5600[];

void func_L01_0032D7E8(void *unused, f32 *pos) {
    u8 q[0x90] __attribute__((aligned(16)));   /* quad descriptor (retail sp+0x00) */
    f32 m[16] __attribute__((aligned(16)));    /* rotation matrix (retail sp+0x90), row 3 = position */
    f32 ang[4] __attribute__((aligned(16)));
    f32 dv[4] __attribute__((aligned(16)));
    f32 *g = (f32 *)(D_001E2880 + 0x140);
    u8 *tbl;
    f32 s, dx, dy, d, dz;
    s32 c;
    s32 i;

    func_L01_0032CEB8(q);
    *(long *)(q + 0x78) = func_00389598(0xB);
    *(long *)(q + 0x70) = 0;
    *(long *)(q + 0x80) = 0x0000FF9000000260L;
    *(long *)(q + 0x88) = 0x0000008000000048L;
    c = func_00382498(0x30, 0x40);
    tbl = D_L01_002C5600 + D_001425D5 * 0xF0;
    if (tbl[1] < 2) {
        c = (c << 24) + 0x80;
    } else {
        c = (c << 24) + 0x806060;
    }
    *(s32 *)(q + 0x40) = c;
    *(s32 *)(q + 0x4C) = c;
    *(s32 *)(q + 0x48) = c;
    *(s32 *)(q + 0x44) = c;
    dx = g[0] - pos[0];
    dy = g[1] - pos[1];
    ang[3] = 0.0f;
    ang[2] = func_0038D160(dx, dy);
    d = func_0038CF38(pos, g);
    dz = g[2] - pos[2];
    ang[1] = -func_0038D160(d, dz);
    ang[0] = func_00382538();
    func_0038D328(m, ang);
    vec_sub_ab(dv, g, pos);
    func_0038CF68(dv, dv, 0.25f);
    m[12] = pos[0];
    m[13] = pos[1];
    m[14] = pos[2];
    m[15] = 1.0f;
    s = func_003824E0(0.03f, 0.0625f);
    for (i = 0; i < 4; i++) {
        func_0038CE20(q + i * 0x10, q + i * 0x10, s);
    }
    func_003D2DA0(q, m, 0);
    for (i = 0; i < 4; i++) {
        func_0038CE20(q + i * 0x10, q + i * 0x10, 0.5f);
    }
    c = (func_00382498(0x40, 0x7F) << 24) + 0x1F1F1F;
    *(s32 *)(q + 0x40) = c;
    *(s32 *)(q + 0x4C) = c;
    *(s32 *)(q + 0x48) = c;
    *(s32 *)(q + 0x44) = c;
    func_003D2DA0(q, m, 0);
    for (i = 0; i < 4; i++) {
        func_0038CE20(q + i * 0x10, q + i * 0x10, 0.5f);
    }
    c = (func_00382498(0x40, 0x7F) << 24) + 0x7F7F7F;
    *(s32 *)(q + 0x40) = c;
    *(s32 *)(q + 0x4C) = c;
    *(s32 *)(q + 0x48) = c;
    *(s32 *)(q + 0x44) = c;
    func_003D2DA0(q, m, 0);
}
