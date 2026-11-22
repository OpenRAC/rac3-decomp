#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003BD448 */
typedef int u128_3BD448 __attribute__((mode(TI)));
typedef struct { s16 h[4]; } Row_3BD448;
typedef struct { u8 pad[0x32]; s16 h32; } M_3BD448;
typedef struct { u8 pad[0x20]; u8 b20; } M20_3BD448;

extern Row_3BD448 D_L05_002A64C0[];
extern Row_3BD448 D_L05_002A6560[];
extern s32 D_L05_001DEAE0;
__asm__(".extern D_L05_001DEAE0, 4");
extern u8 *func_003C24B0(s32, s32);
extern f32 func_00382538(void);

u8 *func_L05_003BD448(u8 *a0, u8 *a1, s32 a2, u8 *a3, s32 t0, s32 t1) {
    u8 *m;
    u8 *s;
    s32 i;
    s32 v;

    m = func_003C24B0(0x1B6F, 0x80);
    if (m != 0) {
        s = *(u8 **)(m + 0x68);
        *(s32 *)(s + 0x60) = t1;
        m[0x30] = 0xFF;
        ((M20_3BD448 *)m)->b20 = 0;
        ((M_3BD448 *)m)->h32 = 0xFF;
        m[0x31] = 1;
        *(u8 **)(m + 0xB8) = a1;
        *(u128_3BD448 *)(s + 0x30) = *(u128_3BD448 *)a3;
        *(u128_3BD448 *)(m + 0x10) = *(u128_3BD448 *)a0;
        v = (D_L05_001DEAE0 * 5 + 2) / 6;
        *(s32 *)(s + 0x10) = v;
        if (*(s16 *)(a1 + 0xAA) == 0x1BF6) {
            *(s32 *)(s + 0x10) = v * 10;
        }
        *(s32 *)(s + 0x1C) = t0;
        *(f32 *)(s + 0x14) = 1.0f / (f32)*(s32 *)(s + 0x10);
        *(f32 *)(m + 0xF0) = func_00382538();
        *(f32 *)(m + 0xF4) = func_00382538();
        *(f32 *)(m + 0xF8) = func_00382538();
        *(f32 *)(s + 0x0) = func_00382538();
        *(f32 *)(s + 0x4) = func_00382538();
        *(f32 *)(s + 0x8) = func_00382538();
        for (i = 0; i < 3; i++) {
            D_L05_002A64C0[*(s32 *)(s + 0x60)].h[i] = -1;
            D_L05_002A6560[*(s32 *)(s + 0x60)].h[i] = 5;
        }
        m[0x20] = 0;
    }
    return m;
}
/* localdecomp:end func_L05_003BD448 */

INCLUDE_ASM("asm/levels", func_L05_003BD5E0);

/* localdecomp:start func_L05_003BDB68 */
extern u8 D_L05_002A4BC0[];
typedef struct {
    u8 pad0[0x10];
    s32 x10;
    u8 pad14[0x60 - 0x14];
    s32 x60;
} M_003BBBC8;

typedef struct {
    u8 pad0[0x68];
    M_003BBBC8 *x68;
    u8 pad6C[0xB8 - 0x6C];
    u8 *xB8;
} O_003BBBC8;

extern void func_L05_003BE190(void *, s32, s32, f32, f32, f32, s32, s32, s32);

void func_L05_003BDB68(O_003BBBC8 *o) {
    s32 c1 = 0xFF1010;
    s32 c2 = 0xFF2020;
    f32 half = 0.5f;
    M_003BBBC8 *m;
    s32 kind;
    s32 n;

    kind = *(s16 *)(o->xB8 + 0xAA);
    m = o->x68;
    if (kind == 0x1BF6 || kind == 0x1BDC || kind == 0x1B6C) {
        c1 = 0x1010FF;
        c2 = 0x2020FF;
    }
    if (m->x10 < 8) {
        n = m->x10 * 3;
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 0), n, n, half * 0.12f, half * 0.22f, 0.2f, 10, 0x7F7F7F, c2);
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 160), m->x10 * 2, m->x10 * 2, half * 0.1f, half * 0.19f, 0.2f, 10, 0x7F7F7F, c1);
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 320), m->x10 * 2, m->x10 * 2, half * 0.1f, half * 0.19f, 0.2f, 10, 0x7F7F7F, c1);
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 480), m->x10 * 2, m->x10 * 2, 0.03f, 0.09f, 0.2f, 10, 0x7F7F7F, c1);
        return;
    }
    if (*(s16 *)(o->xB8 + 0xAA) == 0x1BF6) {
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 0), 0x80, 0x80, 0.2f, 0.4f, 0.5f, 10, 0x7F7F7F, c1);
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 160), 0x40, 0x40, 0.15f, 0.2f, 0.5f, 10, 0x7F7F7F, c1);
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 320), 0x40, 0x40, 0.15f, 0.2f, 0.5f, 10, 0x7F7F7F, c1);
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 480), 0x40, 0x40, 0.15f, 0.2f, 0.5f, 10, 0x7F7F7F, c1);
    } else {
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 0), 0x32, 0x32, 0.04f, 0.15f, 0.2f, 10, 0x7F7F7F, c1);
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 160), 0xF, 0xF, 0.03f, 0.09f, 0.2f, 10, 0x7F7F7F, c1);
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 320), 0xF, 0xF, 0.03f, 0.09f, 0.2f, 10, 0x7F7F7F, c1);
        func_L05_003BE190((D_L05_002A4BC0 + m->x60 * 0x280 + 480), 0xF, 0xF, 0.03f, 0.09f, 0.2f, 10, 0x7F7F7F, c1);
    }
}
/* localdecomp:end func_L05_003BDB68 */

/* localdecomp:start func_L05_003BDFA8 */
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern vu0_v4 D_001A4EC0;
extern vu0_v4 D_L05_001E2680;

void func_L05_003BDFA8(vu0_v4 *pos) {
    vu0_v4 d;
    vu0_v4 a;
    vu0_v4 c;
    u8 *r;
    u8 *t;
    s32 i;
    s32 k;
    f32 sz;

    vec_sub_ab(&d, &D_L05_001E2680, pos);
    for (i = 0; i < 20; i++) {
        func_0038CE20(&a, &D_001A4EC0, -(func_003824E0(0.2f, 3.0f) * 0.020000001f));
        k = (s32)func_L01_00443A18(1.0f, 2.0f);
        sz = func_003824E0(0.3f, 0.75f) * 210000.0f;
        c.x = pos->x + func_L01_00443A18(0.0f, 0.2f);
        c.y = pos->y + func_L01_00443A18(0.0f, 0.2f);
        c.z = pos->z + func_L01_00443A18(0.0f, 0.2f);
        r = func_L01_004669B0(&c, 0.0f, 1.0f, 1.01f, sz, k, &a, 0x7F202020, 0);
        if (r != 0) {
            *(s16 *)(r + 0xA) = 0x4B;
            t = r + 0x20;
            r[0x3] = 0x44;
            r[0x9] = 0x44;
            *(f32 *)(t + 0x1C) = 4.0f;
            *(s32 *)(t + 0x4) = 3;
            t[0xA] = 0x30;
            t[0xB] = r[0xA];
        }
    }
}
/* localdecomp:end func_L05_003BDFA8 */

/* localdecomp:start func_L05_003BE190 */
typedef struct {
    vu0_v4 m[4];
    s32 col[4];
    f32 uv[8];
    long x70, x78, x80, x88;
} __attribute__((aligned(16))) Q_003BE190;

extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);
extern long func_00389598(s32);
extern void func_003A9440(s32, unsigned long);

void func_L05_003BE190(void *pv, s32 a1, s32 a2, f32 w0, f32 w1, f32 k, s32 n, s32 c0, s32 c1) {
    Q_003BE190 q1;
    Q_003BE190 q2;
    vu0_v4 perp;
    vu0_v4 r;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 v;
    vu0_v4 w;
    vu0_v4 t;
    vu0_v4 u;
    vu0_v4 c;
    vu0_v4 s;
    vu0_v4 *p = pv;
    s32 col0;
    s32 col1;
    f32 len;
    f32 m0;
    f32 m1;
    f32 l0;
    f32 l1;
    s32 i;

    q1.x78 = func_00389598(0xE);
    col0 = c0 | (a1 << 24);
    q1.x88 = 0x8000000048L;
    q1.x80 = 0xFF9000000260L;
    q1.x70 = 0;
    q1.col[0] = q1.col[1] = q1.col[2] = q1.col[3] = col0;
    q2.x78 = func_00389598(0x10);
    q2.x88 = q1.x88;
    q2.x80 = q1.x80;
    q2.x70 = q1.x70;
    col1 = c1 | (a2 << 24);
    q2.col[0] = q2.col[1] = q2.col[2] = q2.col[3] = col1;
    q2.uv[0] = 0.0f;
    q2.uv[1] = 0.0f;
    q2.uv[2] = 0.0f;
    q2.uv[3] = 1.0f;
    q2.uv[4] = 1.0f;
    q2.uv[5] = 0.0f;
    q2.uv[6] = 1.0f;
    q2.uv[7] = 1.0f;
    q1.uv[0] = 0.0f;
    q1.uv[1] = 0.0f;
    q1.uv[2] = 0.0f;
    q1.uv[3] = 1.0f;
    q1.uv[4] = 1.0f;
    q1.uv[5] = 0.0f;
    q1.uv[6] = 1.0f;
    q1.uv[7] = 1.0f;

    vec_sub_ab(&a, &p[0], &D_L05_001E2680);
    vec_sub_ab(&b, &p[1], &p[0]);
    func_0038CE90(&perp, &b, &a);
    m0 = func_0038CEA8(&perp);
    if (m0 != 0.0f) {
        m0 = 1.0f / m0;
    }
    func_0038CE20(&perp, &perp, w0 * m0);
    vec_add_ba(&q1.m[0], &p[0], &perp);
    vec_sub_ab(&q1.m[1], &p[0], &perp);

    for (i = 1; i < n - 1; i++) {
        vec_sub_ab(&a, &p[i], &D_L05_001E2680);
        vec_sub_ab(&b, &p[i + 1], &p[i]);
        func_0038CE90(&perp, &b, &a);
        m1 = func_0038CEA8(&perp);
        if (m1 != 0.0f) {
            m1 = 1.0f / m1;
        }
        func_0038CE20(&perp, &perp, w0 * m1);
        vec_add_ba(&q1.m[2], &p[i], &perp);
        vec_sub_ab(&q1.m[3], &p[i], &perp);
        if (i == 1) {
            q1.col[0] = q1.col[1] = c0;
        } else if (i == n - 2) {
            q1.col[2] = q1.col[3] = c0;
        } else if (i == 2) {
            q1.col[0] = q1.col[1] = col0;
        }
        func_003D2DA0(&q1, 0, 0);
        q1.m[0] = q1.m[2];
        q1.m[1] = q1.m[3];
    }

    for (i = 0; i < n - 1; i++) {
        vec_sub_ab(&t, &p[i], &D_L05_001E2680);
        vec_sub_ab(&u, &p[i + 1], &D_L05_001E2680);
        l0 = func_0038CEA8(&t);
        l1 = func_0038CEA8(&u);
        if (l1 < l0) {
            if (l1 == 0.0f) {
                u = t;
            } else {
                func_0038CE20(&u, &u, l0 / l1);
            }
        } else {
            if (l0 == 0.0f) {
                t = u;
            } else {
                func_0038CE20(&t, &t, l1 / l0);
            }
        }
        vec_add_ba(&v, &D_L05_001E2680, &t);
        vec_add_ab(&w, &D_L05_001E2680, &u);
        vec_sub_ba(&b, &w, &v);
        func_0038CE20(&s, &b, k);
        vec_sub_ab(&v, &v, &s);
        vec_add_ab(&w, &w, &s);
        vec_sub_ab(&c, &D_L05_001E2680, &v);
        func_0038CE90(&perp, &c, &b);
        len = func_0038CEA8(&perp);
        if (len != 0.0f) {
            len = 1.0f / len;
        }
        func_0038CE20(&r, &perp, w1 * len);
        vec_add_ba(&q2.m[0], &v, &r);
        vec_sub_ab(&q2.m[1], &v, &r);
        vec_add_ba(&q2.m[2], &w, &r);
        vec_sub_ab(&q2.m[3], &w, &r);
        if (i == 0) {
            q2.col[0] = q2.col[1] = c1;
        } else if (i == n - 2) {
            q2.col[2] = q2.col[3] = c1;
        } else if (i == 1) {
            q2.col[0] = q2.col[1] = col1;
        }
        func_003D2DA0(&q2, 0, 0);
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L05_003BE190 */
