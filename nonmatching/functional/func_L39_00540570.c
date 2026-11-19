/* functional: medium. Rendering effect built from the shared quad init/submit calls (func_003D93B0/003D2DA0), VU0 xyz ops as plain C with w from the dest register. Factored into helpers, so call order/arguments match retail but the stack layout does not. Not byte matched (1169 diff lines). Unsure: func_L39_005BC330 and func_0038D890 semantics, whether func_003D93B0 clears uvs (retail relies on it not doing so for layers 5-6). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00540570;
typedef struct { V_00540570 v[4]; u32 c[4]; f32 uv[8]; long t70, t78, t80, t88; } Q_00540570;
typedef struct { u8 p0[0x10]; V_00540570 pos; u8 p20[0xA0]; V_00540570 vC0; V_00540570 vD0; V_00540570 vE0; } O_00540570;
extern V_00540570 D_L39_002432B0[];
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern f32 func_L01_004451D0(f32, f32, f32, f32, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_L39_005BC330(void *, void *, s32);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_0038CB00(void *);
extern void func_003860A8(void *, void *);
extern void func_003D93B0(void *, s32, s32, long);
extern void func_003D2DA0(void *, s32, s32);

static void vadd_00540570(V_00540570 *d, V_00540570 *a, V_00540570 *b) {
    f32 w = a->w;
    d->x = a->x + b->x; d->y = a->y + b->y; d->z = a->z + b->z; d->w = w;
}
static void vsub_00540570(V_00540570 *d, V_00540570 *a, V_00540570 *b) {
    f32 w = a->w;
    d->x = a->x - b->x; d->y = a->y - b->y; d->z = a->z - b->z; d->w = w;
}

/* m = a 4x4 matrix of rows v90, vA0, vB0, vC0 (contiguous on retail's stack) */
typedef struct { V_00540570 r[4]; } M_00540570;

/* the shared tail of every glow layer: scale the three axis vectors, fix the w lanes, transform the four corners, submit */
static void layer_00540570(Q_00540570 *q, M_00540570 *m, V_00540570 *axis, f32 k) {
    s32 i;
    func_0038CE20(&m->r[0], axis, k);
    func_0038CE20(&m->r[1], &m->r[1], k);
    func_0038CE20(&m->r[2], &m->r[2], k);
    m->r[0].w = 0.0f;
    m->r[1].w = 0.0f;
    m->r[2].w = 0.0f;
    m->r[3].w = 1.0f;
    for (i = 0; i < 4; i++) {
        func_0038D028(&q->v[i], &D_L39_002432B0[i], m);
    }
    func_003D2DA0(q, 0, 0);
}

/* rotate (srcA, srcB) about axis by ang into m's rows 1 and 2, or copy them when the angle is ~0 */
static void spin_00540570(M_00540570 *m, V_00540570 *rm, V_00540570 *axis, V_00540570 *srcA, V_00540570 *srcB, f32 ang) {
    f32 a = (ang < 0.0f) ? -ang : ang;
    if (a > 9.999999747378752e-06f) {
        func_003C4840(rm, axis, ang);
        func_0038D850(&m->r[1], srcA, rm);
        func_0038D850(&m->r[2], srcB, rm);
    } else {
        m->r[1] = *srcA;
        m->r[2] = *srcB;
    }
}

static f32 ramp_00540570(f32 v) {
    f32 t = v * 0.00011641443416010588f;
    if (t < 0.5f) {
        return (t + t) + 0.0f;
    }
    return ((t - 0.5f) + (t - 0.5f)) * 5.0f + 1.0f;
}

void func_L39_00540570(O_00540570 *o) {
    u8 *s = *(u8 **)((u8 *)o + 0x68);
    Q_00540570 q;
    M_00540570 m;
    V_00540570 rm, vD0, vE0, vF0, v100, v110, v120, v130, v140, v150, v160, v170, v180, v190, v1A0, v1B0;
    V_00540570 *pos = &o->pos;
    V_00540570 *axisC0 = &o->vC0;
    f32 len, f23, dot, f22, f21, f20, f4;
    s32 n1, n2, a1, a3, a4, col, i, k;
    s32 alpha1;
    f32 *sf = (f32 *)s;

    vsub_00540570(&vD0, pos, (V_00540570 *)&D_L39_0024DE80[0].pos);
    len = func_0038CEA8(&vD0);
    if (len != 0.0f) {
        func_0038CE20(&vD0, &vD0, 1.0f / len);
    }
    f23 = 1.0f;
    if (len < 11.0f) {
        f23 = 0.0f;
        if (!(len <= 7.0f)) {
            f23 = (len - 7.0f) * 0.25f;
        }
    }
    dot = func_0038CE68(&vD0, axisC0);
    n1 = *(s16 *)(s + 0x1C);
    f4 = (f32)n1;
    n2 = *(s16 *)(s + 0x28);
    f22 = (f4 * *(f32 *)(s + 0x20)) * -18.0f + 20.0f;
    if (n1 < n2) {
        f21 = f4 * *(f32 *)(s + 0x2C);
        a1 = (s32)(((f21 * 60.0f) * dot) * dot);
    } else {
        a1 = (s32)((dot * 60.0f) * dot);
    }
    alpha1 = a1 << 24;

    /* layer 1 and 2 */
    spin_00540570(&m, &rm, axisC0, &o->vC0 + 1, &o->vC0 + 2, sf[0]);
    m.r[3] = *pos;
    func_0038CE20(&m.r[0], axisC0, f22);
    func_0038CE20(&m.r[1], &m.r[1], f22);
    func_0038CE20(&m.r[2], &m.r[2], f22);
    m.r[0].w = 0.0f; m.r[1].w = 0.0f; m.r[2].w = 0.0f; m.r[3].w = 1.0f;
    func_003D93B0(&q, 0x38, 1, 0x80);
    q.c[0] = q.c[1] = q.c[2] = q.c[3] = alpha1 | 0x7F7F7F;
    q.uv[0] = 0.0f; q.uv[1] = 0.0f; q.uv[2] = 0.0f; q.uv[3] = 1.0f;
    q.uv[4] = 1.0f; q.uv[5] = 0.0f; q.uv[6] = 1.0f; q.uv[7] = 1.0f;
    for (i = 0; i < 4; i++) {
        func_0038D028(&q.v[i], &D_L39_002432B0[i], &m);
    }
    func_003D2DA0(&q, 0, 0);

    spin_00540570(&m, &rm, axisC0, &o->vC0 + 1, &o->vC0 + 2, -sf[0]);
    m.r[3] = *pos;
    layer_00540570(&q, &m, axisC0, f22);

    /* layer 3 */
    n1 = *(s16 *)(s + 0x1E);
    f4 = (f32)n1;
    n2 = *(s16 *)(s + 0x2A);
    f22 = (f4 * *(f32 *)(s + 0x24)) * -3.0f + 4.0f;
    if (n1 < n2) {
        f21 = func_L01_004451D0(1.0f, 0.0f, 1.0f, 2.0f, f4 * *(f32 *)(s + 0x30));
    } else {
        f21 = 1.0f;
    }
    a3 = (s32)((f21 * 255.0f) * f23);
    alpha1 = a3 << 24;
    col = (((s32)((f32)a3 * 0.2f)) << 24) | 0xFFFFFF;
    q.c[0] = q.c[1] = q.c[2] = q.c[3] = col;
    spin_00540570(&m, &rm, axisC0, &o->vC0 + 1, &o->vC0 + 2, sf[1]);
    f20 = f22 * 1.5f;
    layer_00540570(&q, &m, axisC0, f20);

    a4 = (s32)(((f21 * 255.0f) * f23) * 1.5f);
    if (a4 >= 0x100) {
        a4 = 0xFF;
    }
    func_003D93B0(&q, 0x39, 1, 0x80);
    col = (a4 << 24) | 0xFFFFFF;
    v120 = *pos;
    q.uv[7] = 1.0f; q.uv[3] = 1.0f; q.uv[4] = 1.0f; q.uv[6] = 1.0f;
    q.c[0] = q.c[3] = q.c[2] = q.c[1] = col;
    q.uv[0] = 0.0f; q.uv[1] = 0.0f; q.uv[2] = 0.0f; q.uv[5] = 0.0f;
    spin_00540570(&m, &rm, axisC0, &o->vC0 + 1, &o->vC0 + 2, sf[2]);
    f20 = f22 * 1.25f;
    layer_00540570(&q, &m, axisC0, f20);

    spin_00540570(&m, &rm, axisC0, &o->vC0 + 1, &o->vC0 + 2, sf[3]);
    m.r[3] = *pos;
    layer_00540570(&q, &m, axisC0, f22);

    /* billboard layers */
    col = alpha1 | 0xFFFFFF;
    q.c[0] = q.c[3] = q.c[2] = q.c[1] = col;
    vsub_00540570(&vE0, (V_00540570 *)&D_L39_0024DE80[0].pos, pos);
    func_0038CF68(&vE0, &vE0, 0.25f);
    vadd_00540570(&m.r[3], pos, &vE0);
    func_L39_005BC330(&v120, &v130, 1);
    vsub_00540570(&vF0, (V_00540570 *)&D_L39_0024DE80[0].pos, &m.r[3]);
    func_0038CF68(&vF0, &vF0, 1.0f);
    func_0038CE90(&v100, &vF0, &v130);
    func_0038CF68(&v100, &v100, 1.0f);
    func_0038CE90(&v110, &v100, &vF0);

    spin_00540570(&m, &rm, &vF0, &v100, &v110, sf[4]);
    layer_00540570(&q, &m, &vF0, f22);

    spin_00540570(&m, &rm, &vF0, &v100, &v110, sf[5]);
    f20 = f22 * 0.75f;
    layer_00540570(&q, &m, &vF0, f20);

    func_003D93B0(&q, 0x38, 1, 0x80);
    col = (((s32)((f32)(a3 & 0xFF) * 0.2f)) << 24) | 0xFFFFFF;
    q.c[0] = q.c[3] = q.c[2] = q.c[1] = col;
    spin_00540570(&m, &rm, &vF0, &v100, &v110, sf[1]);
    f20 = f22 * 1.5f;
    layer_00540570(&q, &m, &vF0, f20);

    /* lens flare */
    if (func_0038CB00(s + 0x36) == 0) {
        func_003860A8(&v140, pos);
        if (28492.0f <= v140.x && v140.x <= 37082.0f && 28492.0f <= v140.y && v140.y <= 37082.0f) {
            f32 e[4];
            f32 x, y;
            v140.y = v140.y - 28492.0f;
            v140.x = v140.x - 28492.0f;
            x = v140.x;
            y = v140.y;
            f21 = (f32)(s32)*(s16 *)(s + 0x36) * *(f32 *)(s + 0x38);
            a1 = (s32)(f21 * 64.0f);
            func_0038D890(&v150, &v130, &vD0, 0.7853981852531433f);
            func_003D93B0(&q, 0xB, 1, 0x80);
            q.t70 = 5;
            q.c[0] = q.c[1] = 0x104050;
            q.c[2] = q.c[3] = (a1 << 24) | 0x104050;
            q.uv[0] = 0.0f; q.uv[1] = 1.0f; q.uv[2] = 1.0f; q.uv[3] = 1.0f;
            q.uv[4] = 0.0f; q.uv[5] = 0.0f; q.uv[6] = 1.0f; q.uv[7] = 0.0f;
            e[3] = ramp_00540570((x < y) ? x : y);
            e[2] = ramp_00540570((x < 8590.0f - y) ? x : 8590.0f - y);
            e[1] = ramp_00540570((8590.0f - x < 8590.0f - y) ? 8590.0f - x : 8590.0f - y);
            e[0] = ramp_00540570((8590.0f - x < y) ? 8590.0f - x : y);
            func_0038CF68(&v170, &vD0, 2.0f);
            for (k = 0; k < 4; k++) {
                func_0038CF68(&v150, &v150, e[k]);
                func_0038CE90(&v180, &vD0, &v150);
                func_0038CF68(&v180, &v180, 0.009999999776482582f);
                vadd_00540570(&v190, (V_00540570 *)&D_L39_0024DE80[0].pos, &v170);
                v1B0 = *pos;
                vsub_00540570(&v1A0, &v190, pos);
                vadd_00540570(&q.v[0], &v190, &v180);
                vsub_00540570(&q.v[1], &v190, &v180);
                vadd_00540570(&v190, &v1B0, &v150);
                v190.w = v150.w;
                vadd_00540570(&v190, &v1A0, &v190);
                v190.w = v1A0.w;
                func_0038CE20(&v180, &v180, 5.0f);
                vadd_00540570(&q.v[2], &v190, &v180);
                vsub_00540570(&q.v[3], &v190, &v180);
                func_003D2DA0(&q, 0, 0);
                if (k < 3) {
                    func_0038D890(&v150, &v150, &vD0, 1.5707963705062866f);
                }
            }
        }
    }

    /* glow */
    if (*(s16 *)(s + 0x34) != 0) {
        f21 = (f32)(s32)*(s16 *)(s + 0x34) * *(f32 *)(s + 0x3C);
        func_003D93B0(&q, 0xB, 4, 0x80);
        q.uv[7] = 1.0f;
        a1 = (s32)(f21 * 255.0f);
        q.uv[0] = 0.0f; q.uv[1] = 0.0f; q.uv[2] = 0.0f;
        vsub_00540570(&v140, pos, (V_00540570 *)&D_L39_0024DE80[0].pos);
        q.uv[3] = 1.0f;
        q.uv[4] = 1.0f;
        col = (a1 << 24) | 0x808080;
        q.c[0] = q.c[3] = q.c[2] = q.c[1] = col;
        q.uv[5] = 0.0f;
        q.uv[6] = 1.0f;
        func_0038CF68(&v150, &v140, 0.1f);
        vadd_00540570(&v160, (V_00540570 *)&D_L39_0024DE80[0].pos, &v150);
        func_0038CE90(&v170, &v140, &v130);
        func_0038CF68(&v170, &v170, 0.07500000298023224f);
        func_0038CE90(&v180, &v170, &v140);
        func_0038CF68(&v180, &v180, 0.07500000298023224f);
        vadd_00540570(&v190, &v160, &v180);
        vadd_00540570(&q.v[0], &v190, &v170);
        vsub_00540570(&q.v[1], &v190, &v170);
        vsub_00540570(&v190, &v160, &v180);
        vadd_00540570(&q.v[2], &v190, &v170);
        vsub_00540570(&q.v[3], &v190, &v170);
        func_003D2DA0(&q, 0, 0);
    }
}
