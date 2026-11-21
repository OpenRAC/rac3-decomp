/* functional: high. Plain-C vector helpers stand in for retail VU0 lqc2/vsub.xyz/vadd.xyz/sqc2 (same xyz math, w kept from the first operand); the file prelude declares this function as void(void) but retail takes the object in a0, so that extern needs the O_0053E300 * parameter. Same stores/calls/order as retail; byte match not attempted (file flags lack -mvu0-use-vf0-vf2). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0053E300;
typedef struct { V_0053E300 v[4]; u32 c[4]; f32 uv[8]; long t70, t78, t80, t88; } Q_0053E300;
typedef struct { u8 p0[0x10]; V_0053E300 pos; u8 p20[0x48]; u8 *f68; } O_0053E300;
typedef struct { u8 p0[0x18]; f32 f18; s32 f1C; u8 p20[8]; s32 f28; } S_0053E300;
static void vsub_0053E300(V_0053E300 *d, V_0053E300 *a, V_0053E300 *b) {
    f32 w = a->w;
    d->x = a->x - b->x; d->y = a->y - b->y; d->z = a->z - b->z; d->w = w;
}
static void vadd_0053E300(V_0053E300 *d, V_0053E300 *a, V_0053E300 *b) {
    f32 w = a->w;
    d->x = a->x + b->x; d->y = a->y + b->y; d->z = a->z + b->z; d->w = w;
}
extern u8 D_L39_002462A8[];
extern V_0053E300 D_L39_0024DE80[];
extern s32 D_L39_00241118;
extern void func_003D93B0(void *, s32, s32, long);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);

void func_L39_0053E300(O_0053E300 *a0) {
    S_0053E300 *s = (S_0053E300 *)a0->f68;
    Q_0053E300 q;
    V_0053E300 d, e, f, pos, c0;
    s32 lo2;
    s32 idx = s->f1C;
    s32 c6 = ((s32 *)((u8 *)D_L39_00352B4C[0] + 0x88))[idx];
    s32 lvl;
    s32 hi, mid, lo;
    s32 i;
    f32 *p;

    if (c6 == -1) {
        lo = 0xFF; mid = 0xFF; hi = 0xFF;
    } else {
        f32 fl, fa, fb, fc, k;
        u8 *t;
        lvl = *(s32 *)((u8 *)D_L39_00352B4C[0] + idx * 4 + 0xE8);
        if (lvl > 0x50) {
            s->f28 = 1;
        }
        t = &D_L39_002462A8[c6 * 3];
        fl = (f32)lvl;
        k = 100.0f;
        fb = (f32)t[2];
        fa = (f32)t[0];
        fc = (f32)t[1];
        fl = k - fl;
        fb = fb * (f32)lvl;
        fl = fl * 255.0f;
        fa = fa * (f32)lvl;
        fc = fc * (f32)lvl;
        fl = fl / k;
        fb = fb / k;
        fa = fa / k;
        fc = fc / k;
        fb = fb + fl;
        fa = fa + fl;
        fc = fc + fl;
        hi = ((s32)fb) & 0xFF;
        lo = ((s32)fa) & 0xFF;
        mid = ((s32)fc) & 0xFF;
    }
    func_003D93B0(&q, 0x17, 0, 0x80);
    q.c[0] = q.c[1] = 0x40000000 | (mid << 8) | (hi << 16) | lo;
    q.c[2] = q.c[3] = (hi << 16) | (mid << 8) | lo;
    q.uv[0] = 0.0f; q.uv[1] = 0.0f; q.uv[2] = 0.0f; q.uv[3] = 1.0f;
    q.uv[4] = 5.0f; q.uv[5] = 0.0f; q.uv[6] = 5.0f; q.uv[7] = 1.0f;
    p = &q.uv[0];
    for (i = 3; i >= 0; i--) {
        f32 u = *p - s->f18;
        *p = u;
        if (u <= 7.0f) {
            *p = u + 7.0f;
        }
        p += 2;
    }
    s->f18 = s->f18 + 0.1f;
    if (4.0f <= s->f18) {
        s->f18 = s->f18 - 4.0f;
    }
    pos = a0->pos;
    d = pos;
    d.z = 500.0f;
    vsub_0053E300(&e, &a0->pos, &D_L39_0024DE80[D_L39_00241118]);
    vsub_0053E300(&f, &d, &pos);
    func_0038CE90(&c0, &e, &f);
    func_0038CF68(&c0, &c0, 2.0f);
    vadd_0053E300(&q.v[0], &a0->pos, &c0);
    vsub_0053E300(&q.v[1], &a0->pos, &c0);
    vadd_0053E300(&q.v[2], &d, &c0);
    vsub_0053E300(&q.v[3], &d, &c0);
    func_003D2DA0(&q, 0, 0);
    func_003D93B0(&q, 0xE, 1, 0x80);
    lo2 = lo + 0x20;
    if (lo2 >= 0x100) {
        lo2 = 0xFF;
    }
    q.c[0] = q.c[1] = 0x40000000 | (hi << 16) | (mid << 8) | lo2;
    q.c[2] = q.c[3] = (hi << 16) | (mid << 8) | lo2;
    q.uv[0] = 0.0f; q.uv[1] = 0.0f; q.uv[2] = 0.0f; q.uv[3] = 1.0f;
    q.uv[4] = 1.0f; q.uv[5] = 0.0f; q.uv[6] = 1.0f; q.uv[7] = 1.0f;
    func_0038CF68(&c0, &c0, 6.0f);
    vadd_0053E300(&q.v[0], &a0->pos, &c0);
    vsub_0053E300(&q.v[1], &a0->pos, &c0);
    vadd_0053E300(&q.v[2], &d, &c0);
    vsub_0053E300(&q.v[3], &d, &c0);
    func_003D2DA0(&q, 0, 0);
}
