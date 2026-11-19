/* functional: medium. same calls/order/args and packet fields; frame layout differs (retail packet B's r[] rows live past packet B) */
typedef struct {
    f32 m[4][4];
    s32 c[4];
    f32 x50, x54, x58;
    f32 x5C, x60;
    f32 x64;
    f32 x68, x6C;
    long x70, x78, x80, x88;
    f32 r[4][4];
} Quad_35A218;

static void vsub_xyz(f32 *d, f32 *a, f32 *b) {
    f32 x = a[0] - b[0], y = a[1] - b[1], z = a[2] - b[2], w = a[3];
    d[0] = x; d[1] = y; d[2] = z; d[3] = w;
}
extern s32 D_001DD690_sda;
extern s32 D_001DD694_sda;
extern u8 D_L01_001E29C0[];
extern long func_00389598(s32);
extern void func_L01_0035A190(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);

void func_L01_0035A218(u8 *pts, s32 count, s32 a2, s32 colorA, s32 colorB, s32 a5, f32 w, f32 hi) {
    Quad_35A218 A, B;
    f32 mat[16] __attribute__((aligned(16)));
    f32 *d = &mat[0];
    f32 *e = &mat[4];
    f32 *f = &mat[8];
    f32 *g = &mat[12];
    f32 u0, u1;
    s32 k;

    A.x78 = func_00389598(D_001DD690_sda);
    A.x80 = 0xFF9000000260L;
    A.x88 = ((long)a2 << 32) | 0x68;
    A.c[0] = colorA; A.c[1] = colorA; A.c[2] = colorA; A.c[3] = colorA;
    A.x70 = 0;
    func_L01_0035A190(&A);
    A.x50 = 0.0f; A.x54 = 0.0f; A.x58 = 0.0f;
    A.x5C = 1.0f; A.x60 = 1.0f; A.x64 = 0.0f; A.x68 = 1.0f; A.x6C = 1.0f;
    B.x78 = func_00389598(D_001DD690_sda);
    B.c[0] = colorB; B.c[1] = colorB; B.c[2] = colorB; B.c[3] = colorB;
    B.x70 = 0;
    B.x80 = 0xFF9000000260L;
    B.x88 = ((long)(a2 / 3) << 32) | 0x68;
    func_L01_0035A190(&B);
    *(u128_t *)&B.r[0] = 0;
    *(u128_t *)&B.r[1] = 0;
    B.x50 = 0.0f; B.x54 = 0.0f; B.x58 = 0.0f;
    B.x5C = 1.0f; B.x60 = 0.33f; B.x64 = 0.0f; B.x68 = 0.33f; B.x6C = 1.0f;
    B.r[0][2] = w; B.r[0][3] = 1.0f;
    B.r[1][2] = w * hi; B.r[1][3] = 1.0f;

    vsub_xyz(d, (f32 *)(pts + 0x10), (f32 *)pts);
    func_0038CF68(d, d, 1.0f);
    vsub_xyz(e, (f32 *)D_L01_001E29C0, (f32 *)pts);
    func_0038CE90(f, e, d);
    func_0038CF68(f, f, 1.0f);
    func_0038CE90(e, d, f);
    *(u128_t *)&A.m[0] = *(u128_t *)&B.r[0];
    *(u128_t *)g = *(u128_t *)pts;
    func_0038CE20(A.m[1], A.m[0], -1.0f);
    func_0038D028(A.m[0], A.m[0], mat);
    func_0038D028(A.m[1], A.m[1], mat);
    *(u128_t *)&B.m[0] = *(u128_t *)&B.r[1];
    func_0038CE20(B.m[1], B.m[0], -1.0f);
    func_0038D028(B.m[0], B.m[0], mat);
    func_0038D028(B.m[1], B.m[1], mat);
    if (1 < count) {
        u0 = 1.0f; u1 = 0.33f;
        k = 1;
        do {
            *(u128_t *)&A.m[2] = *(u128_t *)&B.r[0];
            func_0038CE20(A.m[3], A.m[2], -1.0f);
            *(u128_t *)&B.m[2] = *(u128_t *)&B.r[1];
            func_0038CE20(B.m[3], B.m[2], -1.0f);
            vsub_xyz(d, (f32 *)(pts + k * 0x10 + 0x10), (f32 *)(pts + k * 0x10));
            func_0038CF68(d, d, 1.0f);
            vsub_xyz(e, (f32 *)D_L01_001E29C0, (f32 *)(pts + k * 0x10));
            func_0038CE90(f, e, d);
            func_0038CF68(f, f, 1.0f);
            func_0038CE90(e, d, f);
            *(u128_t *)g = *(u128_t *)(pts + k * 0x10);
            func_0038D028(A.m[2], A.m[2], mat);
            func_0038D028(A.m[3], A.m[3], mat);
            func_0038D028(B.m[2], B.m[2], mat);
            func_0038D028(B.m[3], B.m[3], mat);
            if (k == count - 1) { A.c[2] = 0; A.c[3] = 0; B.c[2] = 0; B.c[3] = 0; }
            A.x78 = func_00389598(D_001DD694_sda);
            A.x88 = ((long)a2 << 32) | 0x68;
            A.x78 = func_00389598(0x2B);
            func_003D2DA0(&A, 0, 0);
            func_003D2DA0(&B, 0, 0);
            u0 = (f32)k * 0.33f;
            u1 = u0 + 0.33f;
            if (1.0f <= u0) { u0 -= 1.0f; u1 -= 1.0f; }
            k++;
            *(u128_t *)&A.m[0] = *(u128_t *)&A.m[2];
            *(u128_t *)&A.m[1] = *(u128_t *)&A.m[3];
            *(u128_t *)&B.m[0] = *(u128_t *)&B.m[2];
            *(u128_t *)&B.m[1] = *(u128_t *)&B.m[3];
            B.x58 = u0; B.x68 = u1; B.x50 = u0; B.x60 = u1;
        } while (k < count);
    }
}
