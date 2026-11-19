/* functional: high. Same calls, order, stores and loop as retail; vsub.xyz and the lq/sq vector copies are plain C (w of vsub taken from the minuend as retail's vf1/vf2 does); rand() low bit picks the texture V flip. */
typedef int s128_310DB8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_310DB8;
typedef struct {
    V_310DB8 v[4];
    s32 col[4];
    f32 w[4][2];
    long d70;
    long d78;
    long d80;
    long d88;
} __attribute__((aligned(16))) P_310DB8;
extern V_310DB8 D_L01_001E29C0;
extern void func_003D93B0(void *, s32, s32, long);
extern s32 func_0013D3E0(void);
extern void func_0038CF68(float *off, char *src, float scale);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(f32 *, f32 *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(char *pkt, float *matrix, int mode);

static void sub_310DB8(V_310DB8 *d, V_310DB8 *a, V_310DB8 *b) {
    f32 w = a->w;
    d->x = a->x - b->x;
    d->y = a->y - b->y;
    d->z = a->z - b->z;
    d->w = w;
}

void func_L01_00310DB8(V_310DB8 *origin, V_310DB8 *pts, s32 color, s32 count, f32 u0, f32 size, f32 du) {
    V_310DB8 cam;
    P_310DB8 a;
    P_310DB8 b;
    V_310DB8 basis[4];
    V_310DB8 narrow, wide;
    s32 i;
    s32 colA, colB;
    f32 u, v;

    cam = *origin;
    func_003D93B0(&a, 0x2B, 1, 0x80);
    func_003D93B0(&b, 0x2B, 1, 0x80);
    size = size * 0.25f;
    *(s128_310DB8 *)&narrow = 0;
    *(s128_310DB8 *)&wide = 0;
    a.col[1] = color;
    a.col[0] = color;
    b.col[1] = color;
    b.col[0] = color;
    a.col[3] = color;
    a.col[2] = color;
    b.col[3] = color;
    b.col[2] = color;
    narrow.z = size;
    wide.z = size + size;
    narrow.w = 1.0f;
    wide.w = 1.0f;
    v = du + u0;
    u = u0 + 0.0f;
    if ((func_0013D3E0() & 1) == 0) {
        b.w[3][1] = 1.0f; b.w[2][1] = 0.0f; a.w[0][1] = 0.0f;
        b.w[3][0] = v; b.w[1][0] = u; a.w[0][0] = u; a.w[1][0] = u;
        a.w[1][1] = 1.0f; a.w[2][0] = v; a.w[2][1] = 0.0f;
        a.w[3][0] = v; a.w[3][1] = 1.0f;
        b.w[0][0] = u; b.w[0][1] = 0.0f; b.w[1][1] = 1.0f;
    } else {
        b.w[2][1] = 1.0f; b.w[3][1] = 0.0f; a.w[0][1] = 1.0f;
        b.w[3][0] = v; b.w[1][0] = u; a.w[0][0] = u; a.w[1][0] = u;
        a.w[1][1] = 0.0f; a.w[2][0] = v; a.w[2][1] = 1.0f;
        a.w[3][0] = v; a.w[3][1] = 0.0f;
        b.w[0][0] = u; b.w[0][1] = 1.0f; b.w[1][1] = 0.0f;
    }
    b.w[2][0] = v;

    sub_310DB8(&basis[0], pts, &cam);
    func_0038CF68((f32 *)&basis[0], (char *)&basis[0], 1.0f);
    sub_310DB8(&basis[1], &D_L01_001E29C0, &cam);
    func_0038CE90(&basis[2], &basis[1], &basis[0]);
    i = 0;
    func_0038CF68((f32 *)&basis[2], (char *)&basis[2], 1.0f);
    func_0038CE90(&basis[1], &basis[0], &basis[2]);
    basis[3] = cam;
    a.v[0] = narrow;
    b.v[0] = wide;
    func_0038CE20((f32 *)&a.v[1], (f32 *)&a.v[0], -1.0f);
    func_0038CE20((f32 *)&b.v[1], (f32 *)&b.v[0], -1.0f);
    func_0038D028(&a.v[0], &a.v[0], basis);
    func_0038D028(&a.v[1], &a.v[1], basis);
    func_0038D028(&b.v[0], &b.v[0], basis);
    func_0038D028(&b.v[1], &b.v[1], basis);

    colA = color | 0x7F000000;
    colB = color | 0x3F000000;
    while (i < count - 1) {
        sub_310DB8(&basis[0], &pts[i + 1], &pts[i]);
        func_0038CF68((f32 *)&basis[0], (char *)&basis[0], 1.0f);
        sub_310DB8(&basis[1], &D_L01_001E29C0, &pts[i]);
        func_0038CE90(&basis[2], &basis[1], &basis[0]);
        func_0038CF68((f32 *)&basis[2], (char *)&basis[2], 1.0f);
        func_0038CE90(&basis[1], &basis[0], &basis[2]);
        narrow.z = narrow.z * 0.7f;
        wide.z = narrow.z + narrow.z;
        basis[3] = pts[i];
        a.v[2] = narrow;
        b.v[2] = wide;
        func_0038CE20((f32 *)&a.v[3], (f32 *)&a.v[2], -1.0f);
        func_0038CE20((f32 *)&b.v[3], (f32 *)&b.v[2], -1.0f);
        func_0038D028(&a.v[2], &a.v[2], basis);
        func_0038D028(&a.v[3], &a.v[3], basis);
        func_0038D028(&b.v[2], &b.v[2], basis);
        func_0038D028(&b.v[3], &b.v[3], basis);
        u = du * (f32)(i + 1);
        v = u + du;
        if (1.0f <= u) {
            u -= 1.0f;
            v -= 1.0f;
        }
        u += u0;
        v += u0;
        b.w[1][0] = u;
        b.w[3][0] = v;
        a.w[0][0] = u;
        a.w[1][0] = u;
        a.w[2][0] = v;
        a.w[3][0] = v;
        b.w[0][0] = u;
        b.w[2][0] = v;
        func_003D2DA0((char *)&a, 0, 0);
        func_003D2DA0((char *)&b, 0, 0);
        if (i != 0) {
            a.col[1] = colA;
            a.col[0] = colA;
            b.col[1] = colB;
            b.col[0] = colB;
        }
        i++;
        a.v[0] = a.v[2];
        a.v[1] = a.v[3];
        b.v[0] = b.v[2];
        b.v[1] = b.v[3];
        a.col[3] = colA;
        a.col[2] = colA;
        b.col[3] = colB;
        b.col[2] = colB;
    }
    narrow.z = narrow.z * 0.7f;
    wide.z = narrow.z + narrow.z;
    basis[3] = pts[count - 1];
    a.v[2] = narrow;
    b.v[2] = wide;
    func_0038CE20((f32 *)&a.v[3], (f32 *)&a.v[2], -1.0f);
    func_0038CE20((f32 *)&b.v[3], (f32 *)&b.v[2], -1.0f);
    func_0038D028(&a.v[2], &a.v[2], basis);
    func_0038D028(&a.v[3], &a.v[3], basis);
    func_0038D028(&b.v[2], &b.v[2], basis);
    func_0038D028(&b.v[3], &b.v[3], basis);
    u = du * (f32)(i + 1);
    v = u + du;
    if (1.0f <= u) {
        u -= 1.0f;
        v -= 1.0f;
    }
    u += u0;
    v += u0;
    b.col[2] = color; a.col[3] = color; a.col[2] = color; b.col[3] = color;
    b.w[3][0] = v;
    b.w[1][0] = u;
    a.w[0][0] = u;
    a.w[1][0] = u;
    a.w[2][0] = v;
    a.w[3][0] = v;
    b.w[0][0] = u;
    b.w[2][0] = v;
    func_003D2DA0((char *)&a, 0, 0);
    func_003D2DA0((char *)&b, 0, 0);
}
