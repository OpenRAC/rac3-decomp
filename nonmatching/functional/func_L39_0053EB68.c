/* functional: high. Plain-C vec helpers replace retail VU0 xyz ops (w taken from the dest register as retail; one case sets w from vB0). Signature follows the caller's prototype (u8*,int,f32,int,int,f32,f32,int,u8*): retail uses only the last arg (t1 = object) and reads its parameters from sdata globals instead; unused params kept so the prelude extern still matches. Byte match not attempted. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0053EB68;
typedef struct { V_0053EB68 v[4]; u32 c[4]; f32 uv[8]; long t70, t78, t80, t88; } Q_0053EB68;
typedef struct { u8 p0[0x10]; V_0053EB68 pos; u8 p20[0x48]; u8 *f68; } O_0053EB68;
extern int D_L39_0024AE38 __attribute__((section(".sdata")));
extern int D_L39_0024AE3C __attribute__((section(".sdata")));
extern f32 D_L39_0024AE24 __attribute__((section(".sdata")));
extern f32 D_L39_0024AE28 __attribute__((section(".sdata")));
extern f32 D_L39_0024AE2C __attribute__((section(".sdata")));
extern f32 D_L39_0024AE30 __attribute__((section(".sdata")));
extern int D_L39_0024AE34 __attribute__((section(".sdata")));
extern int D_L39_0024AE48 __attribute__((section(".sdata")));
extern int D_L39_0024AE4C __attribute__((section(".sdata")));
extern int D_L39_0024AE50 __attribute__((section(".sdata")));
extern int D_L39_0024AE54 __attribute__((section(".sdata")));
extern int D_L39_0024AE58 __attribute__((section(".sdata")));
extern int D_L39_0024AE5C __attribute__((section(".sdata")));
extern int D_L39_0024AE60 __attribute__((section(".sdata")));
extern int D_L39_0024AE64 __attribute__((section(".sdata")));
extern int D_L39_0024AE68 __attribute__((section(".sdata")));
extern int D_L39_0024AE6C __attribute__((section(".sdata")));
extern int D_L39_0024AE70 __attribute__((section(".sdata")));
extern int D_L39_0024AE74 __attribute__((section(".sdata")));
extern int D_L39_0024AE78 __attribute__((section(".sdata")));
extern int D_L39_0024AE7C __attribute__((section(".sdata")));
extern int D_L39_0024AE80 __attribute__((section(".sdata")));
extern int D_L39_0024AE84 __attribute__((section(".sdata")));
extern int D_L39_0024AE88 __attribute__((section(".sdata")));
extern V_0053EB68 D_L39_0024DE00;
extern void func_L01_0030AB70(void *);
extern void func_003D93B0(void *, s32, s32, long);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern f32 func_L39_005B44C8(void);

static void vadd_0053EB68(V_0053EB68 *d, V_0053EB68 *a, V_0053EB68 *b) {
    f32 w = a->w;
    d->x = a->x + b->x; d->y = a->y + b->y; d->z = a->z + b->z; d->w = w;
}
static void vsub_0053EB68(V_0053EB68 *d, V_0053EB68 *a, V_0053EB68 *b) {
    f32 w = a->w;
    d->x = a->x - b->x; d->y = a->y - b->y; d->z = a->z - b->z; d->w = w;
}

void func_L39_0053EB68(u8 *unused, int a1, f32 f1, int a3, int a4, f32 f2, f32 f3, int a5, O_0053EB68 *obj) {
    Q_0053EB68 q;
    V_0053EB68 v90, vA0, vB0, vC0, vD0, vE0, vF0;
    V_0053EB68 *pos = &obj->pos;
    u8 *s = obj->f68;
    f32 *p;
    s32 i;
    u32 colA, colB;

    func_L01_0030AB70(&q);
    func_003D93B0(&q, D_L39_0024AE38, 0, 0x80);
    q.c[0] = q.c[1] = (D_L39_0024AE58 << 24) | (D_L39_0024AE54 << 16) | (D_L39_0024AE50 << 8) | D_L39_0024AE4C;
    q.c[2] = q.c[3] = (D_L39_0024AE68 << 24) | (D_L39_0024AE64 << 16) | (D_L39_0024AE60 << 8) | D_L39_0024AE5C;
    q.uv[0] = 0.0f; q.uv[1] = 0.0f; q.uv[2] = 0.0f; q.uv[3] = 1.0f;
    q.uv[4] = 1.0f; q.uv[5] = 0.0f; q.uv[6] = 1.0f; q.uv[7] = 1.0f;
    p = &q.uv[0];
    for (i = 3; i >= 0; i--) {
        f32 u = *p - *(f32 *)(s + 0x28);
        *p = u;
        if (u <= 7.0f) {
            *p = u + 7.0f;
        }
        p += 2;
    }
    *(f32 *)(s + 0x28) = *(f32 *)(s + 0x28) + 0.1f;
    if (4.0f <= *(f32 *)(s + 0x28)) {
        *(f32 *)(s + 0x28) = *(f32 *)(s + 0x28) - 4.0f;
    }
    func_0038CF68(&v90, s, -0.17f);
    vadd_0053EB68(&v90, pos, &v90);
    vE0 = D_L39_0024DE00;
    vsub_0053EB68(&vA0, pos, &vE0);
    func_0038CF68(&vB0, s, -4.0f);
    vadd_0053EB68(&vC0, &v90, &vB0);
    func_0038CE90(&vD0, &vA0, &vB0);
    func_0038CF68(&vD0, &vD0, D_L39_0024AE2C);
    vadd_0053EB68(&q.v[0], pos, &vD0);
    vsub_0053EB68(&q.v[1], pos, &vD0);
    vadd_0053EB68(&q.v[2], &vC0, &vD0);
    vsub_0053EB68(&q.v[3], &vC0, &vD0);
    func_003D2DA0(&q, 0, 0);
    {
        u32 c2 = q.c[2], c3 = q.c[3];
        V_0053EB68 t2 = q.v[2], t3 = q.v[3];
        q.c[0] = c2; q.c[1] = c3;
        q.c[2] = 0x801010; q.c[3] = 0x801010;
        q.v[0] = t2; q.v[1] = t3;
    }
    vadd_0053EB68(&q.v[2], &q.v[2], &vB0);
    vadd_0053EB68(&q.v[3], &q.v[3], &vB0);
    func_003D2DA0(&q, 0, 0);

    func_003D93B0(&q, D_L39_0024AE3C, 1, 0x80);
    colA = (D_L39_0024AE78 << 24) | (D_L39_0024AE74 << 16) | (D_L39_0024AE70 << 8) | D_L39_0024AE6C;
    colB = (D_L39_0024AE74 << 16) | (D_L39_0024AE70 << 8) | D_L39_0024AE6C;
    q.c[0] = q.c[1] = colA;
    q.c[2] = q.c[3] = colB;
    q.uv[0] = 0.0f; q.uv[1] = 0.0f; q.uv[2] = 0.0f; q.uv[3] = 1.0f;
    q.uv[4] = 1.0f; q.uv[5] = 0.0f; q.uv[6] = 1.0f; q.uv[7] = 1.0f;
    func_0038CF68(&vD0, &vD0, D_L39_0024AE24);
    vadd_0053EB68(&q.v[0], pos, &vD0);
    vF0 = *pos;
    vsub_0053EB68(&q.v[1], pos, &vD0);
    vadd_0053EB68(&vC0, &vF0, &vB0);
    vC0.w = vB0.w;
    vadd_0053EB68(&vC0, &vC0, &vB0);
    vadd_0053EB68(&q.v[2], &vC0, &vD0);
    vsub_0053EB68(&q.v[3], &vC0, &vD0);
    func_003D2DA0(&q, 0, 0);

    colA = (D_L39_0024AE78 << 24) | (D_L39_0024AE74 << 16) | (D_L39_0024AE70 << 8) | D_L39_0024AE6C;
    colB = (D_L39_0024AE74 << 16) | (D_L39_0024AE70 << 8) | D_L39_0024AE6C;
    q.c[0] = q.c[1] = colA;
    q.c[2] = q.c[3] = colB;
    func_0038CF68(&vD0, &vD0, D_L39_0024AE28);
    func_0038CF68(&v90, s, -0.1f);
    vadd_0053EB68(&v90, pos, &v90);
    vadd_0053EB68(&q.v[0], &v90, &vD0);
    vsub_0053EB68(&q.v[1], &v90, &vD0);
    vadd_0053EB68(&vC0, &v90, &vB0);
    vadd_0053EB68(&vC0, &vC0, &vB0);
    vadd_0053EB68(&q.v[2], &vC0, &vD0);
    vsub_0053EB68(&q.v[3], &vC0, &vD0);
    func_003D2DA0(&q, 0, 0);

    q.c[0] = q.c[1] = (D_L39_0024AE88 << 24) | (D_L39_0024AE84 << 16) | (D_L39_0024AE80 << 8) | D_L39_0024AE6C;
    q.c[2] = q.c[3] = (D_L39_0024AE84 << 16) | (D_L39_0024AE80 << 8) | D_L39_0024AE7C;
    func_0038CF68(&vD0, &vD0, D_L39_0024AE28);
    func_0038CF68(&v90, s, -0.1f);
    vadd_0053EB68(&v90, pos, &v90);
    vadd_0053EB68(&q.v[0], &v90, &vD0);
    vsub_0053EB68(&q.v[1], &v90, &vD0);
    vadd_0053EB68(&vC0, &v90, &vB0);
    vadd_0053EB68(&vC0, &vC0, &vB0);
    vadd_0053EB68(&q.v[2], &vC0, &vD0);
    vsub_0053EB68(&q.v[3], &vC0, &vD0);
    func_003D2DA0(&q, 0, 0);

    q.c[0] = q.c[1] = 0x40FFFFFF;
    q.c[2] = q.c[3] = (D_L39_0024AE74 << 16) | (D_L39_0024AE70 << 8) | D_L39_0024AE6C;
    func_0038CF68(&vD0, &vD0, D_L39_0024AE24);
    vadd_0053EB68(&q.v[0], pos, &vD0);
    vsub_0053EB68(&q.v[1], pos, &vD0);
    func_0038CF68(&vB0, s, -0.6f);
    vadd_0053EB68(&vC0, pos, &vB0);
    vadd_0053EB68(&vC0, &vC0, &vB0);
    vadd_0053EB68(&q.v[2], &vC0, &vD0);
    vsub_0053EB68(&q.v[3], &vC0, &vD0);
    func_003D2DA0(&q, 0, 0);

    func_003D9508(pos, D_L39_0024AE34, D_L39_0024AE48, 1, D_L39_0024AE30, 0.08f, func_L39_005B44C8());
}
