#include "common.h"
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} V40A3D0;
typedef struct {
    u8 pad0[48];
    V40A3D0 out;
    V40A3D0 pad40;
    V40A3D0 ang;
    V40A3D0 pad60;
    V40A3D0 tgt;
    V40A3D0 pad80;
    V40A3D0 scale;
} S40A3D0;
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    s32 n;
    f32 f4;
    u8 pad8[16];
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    u8 data[1];
} P_0040A478;

/* localdecomp:start func_L01_0040C3C0 */
#include "vu0.h"

typedef struct { vu0_v4 v[4]; } M_0040C3C0;
typedef struct { f32 a[3]; f32 b[3]; } V_0040C3C0;
typedef struct { s32 a, b; } C_0040C3C0;
typedef struct { f32 a[2]; f32 b[2]; } T_0040C3C0;
extern V_0040C3C0 D_L01_001E93D0_0040C3C0[];
extern C_0040C3C0 D_L01_001E9C10_0040C3C0[];
extern C_0040C3C0 D_L01_001E9A00_0040C3C0[];
extern T_0040C3C0 D_L01_001EA240_0040C3C0[];
extern T_0040C3C0 D_L01_001E9E20_0040C3C0[];
extern f32 D_L01_002C5308_0040C3C0[];
extern f32 D_L01_002C5200_0040C3C0[];
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_00389478(void *, f32 *, f32 *);
extern void func_0038CC88(void *, void *, s32);
extern void func_0038D028(void *, void *, void *);
extern f32 func_003C4088(f32, f32, f32);
extern void func_0038C750(void);
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_003D3A24(s32, void *, void *, void *, s32);

void func_L01_0040C3C0(M_0040C3C0 *src, s32 n, f32 t, f32 ang, s32 col1, s32 col0, s32 col2, s32 tex0, s32 tex1)
{
    M_0040C3C0 m;
    vu0_v4 pos;
    vu0_v4 rot;
    vu0_v4 mat[3];
    vu0_v4 off[3];
    vu0_v4 tmp;
    f32 scr[2];
    f32 mid[2];
    vu0_v4 dir;
    vu0_v4 p;
    s32 step;
    V_0040C3C0 *v;
    C_0040C3C0 *c0;
    C_0040C3C0 *c2;
    T_0040C3C0 *uv;
    T_0040C3C0 *st;
    s32 i;

    m = *src;
    if (n & 1) {
        n &= ~1;
    }
    if (n > 64) {
        n = 64;
    }
    step = 64 / n;
    if (64 % step != 0) {
        n -= 64 % step;
        step = 64 / n;
    }
    if (n < 4) {
        return;
    }
    qzero(&rot);
    rot.x = ang;
    func_0038D308(mat, &rot);
    func_0038D5F0(off, &m, mat);
    tmp = m.v[3];
    vec_add_ab(&pos, &tmp, off);
    func_00389478(&pos, &scr[0], &scr[1]);
    dir.w = 1.0f;
    v = D_L01_001E93D0_0040C3C0;
    c0 = D_L01_001E9C10_0040C3C0;
    c2 = D_L01_001E9A00_0040C3C0;
    uv = D_L01_001EA240_0040C3C0;
    st = D_L01_001E9E20_0040C3C0;
    dir.x = 0.0f;
    for (i = 0; i <= n; i++) {
        func_0038CC88(v->a, &pos, 12);
        dir.y = D_L01_002C5308_0040C3C0[i * step];
        dir.z = D_L01_002C5200_0040C3C0[i * step];
        func_0038D028(&p, &dir, off);
        func_0038CC88(v->b, &p, 12);
        c0->a = col0;
        c0->b = col1;
        func_00389478(&p, &uv->b[0], &uv->b[1]);
        if (i == 0) {
            uv->a[0] = scr[0];
            uv->a[1] = scr[1];
        } else {
            mid[0] = (uv[-1].b[0] + uv->b[0]) * 0.5f;
            mid[1] = (uv[-1].b[1] + uv->b[1]) * 0.5f;
            uv->a[0] = func_003C4088(scr[0], mid[0], t);
            uv->a[1] = func_003C4088(scr[1], mid[1], t);
        }
        c2->a = col2;
        c2->b = col2;
        st->a[1] = 1.0f;
        st->b[0] = (f32)(i & 1);
        st->a[0] = 0.5f;
        st->b[1] = 0.0f;
        v++;
        c0++;
        c2++;
        uv++;
        st++;
    }
    func_0038C750();
    func_003A9440(0x47, 0x513F1);
    func_003A9440(6, func_00389598(tex0));
    func_003A9440(8, 4);
    func_003A9440(0x42, 0x800000004AUL);
    func_003D3A24(n * 2 + 1, D_L01_001E93D0_0040C3C0[0].b, &D_L01_001E9A00_0040C3C0[0].b, D_L01_001E9E20_0040C3C0[0].b, 1);
    func_003A9440(6, func_00389598(tex1));
    func_003A9440(8, 5);
    func_003A9440(0x42, 0x8000000054UL);
    func_003D3A24(n * 2 + 1, D_L01_001E93D0_0040C3C0[0].b, &D_L01_001E9C10_0040C3C0[0].b, D_L01_001EA240_0040C3C0[0].b, 1);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L01_0040C3C0 */

/* localdecomp:start func_L01_0040C7A0 */
/* m2c3 */
s32 func_L01_00443B88(s32, f32, f32);               /* extern */

void func_L01_0040C7A0(s32 arg0, void *arg1) {
    func_L01_00443B88(arg0 + 0x50, -3.1415927f, 3.1415927f);
    func_L01_00443B88(arg0 + 0x60, -3.1415927f, 3.1415927f);
    func_L01_00443B88(arg0 + 0x70, (*(f32 *)((u8 *)(arg1) + 8)) * 0.017453292f * 0.020000001f, (*(f32 *)((u8 *)(arg1) + 0xC)) * 0.017453292f * 0.020000001f);
    func_L01_00443B88(arg0 + 0x80, (*(f32 *)((u8 *)(arg1) + 8)) * 0.017453292f * 0.020000001f, (*(f32 *)((u8 *)(arg1) + 0xC)) * 0.017453292f * 0.020000001f);
    func_L01_00443B88(arg0 + 0x90, (*(f32 *)((u8 *)(arg1) + 0x10)), (*(f32 *)((u8 *)(arg1) + 0x14)));
    func_L01_00443B88(arg0 + 0xA0, (*(f32 *)((u8 *)(arg1) + 0x10)), (*(f32 *)((u8 *)(arg1) + 0x14)));
}
/* localdecomp:end func_L01_0040C7A0 */

/* localdecomp:start func_L01_0040C8A0 */


extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L01_0040C8A0(S40A3D0 *s) {
    s32 i;

    for (i = 1; i >= 0; i--) {
        s->ang.x = func_0038DAB8(s->ang.x, s->tgt.x);
        s->ang.y = func_0038DAB8(s->ang.y, s->tgt.y);
        s->ang.z = func_0038DAB8(s->ang.z, s->tgt.z);
        s->out.x = func_0038D098(s->ang.x) * s->scale.x;
        s->out.y = func_0038D0B0(s->ang.y) * s->scale.y;
        s->out.z = -func_0038D0B0(s->ang.z) * s->scale.z;
        s = (S40A3D0 *)((u8 *)s + 16);
    }
}
/* localdecomp:end func_L01_0040C8A0 */

/* localdecomp:start func_L01_0040C948 */


extern void func_L01_0040CA60(void *, s32, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0040CC30(void *, s32, s32 *, s32 *, void *, f32, f32, f32);

void func_L01_0040C948(s32 *a0, P_0040A478 *a1)
{
    s128 buf[a1->n];
    s32 a[4];
    s32 b[4];
    f32 f20;
    f32 f22;
    f32 f21;

    func_L01_0040CA60(buf, a1->n, a0, a1->f18);
    f20 = func_003824E0(a1->f2C, a1->f30);
    f22 = func_003824E0(a1->f1C, a1->f20);
    f21 = func_003824E0(a1->f24, a1->f28);
    a[0] = func_0038DBD8(0, a0[8], f20);
    a[1] = func_0038DBD8(0, a0[9], f20);
    b[0] = func_0038DBD8(0, a0[10], f20);
    b[1] = func_0038DBD8(0, a0[11], f20);
    func_L01_0040CC30(buf, a1->n, a, b, a1->data, f22, f21, a1->f4);
}
/* localdecomp:end func_L01_0040C948 */

/* localdecomp:start func_L01_0040CA60 */
typedef int u128_40CA60 __attribute__((mode(TI)));
typedef union {
    u128_40CA60 q;
    f32 f[4];
} Vec4_40CA60;
extern void func_L01_0040D220(Vec4_40CA60 *, Vec4_40CA60 *, Vec4_40CA60 *, Vec4_40CA60 *, Vec4_40CA60 *, f32);
extern void func_0038CF68(Vec4_40CA60 *, Vec4_40CA60 *, f32);

void func_L01_0040CA60(void *a0, s32 n, void *a2, f32 s) {
    Vec4_40CA60 *buf = a0;
    Vec4_40CA60 *p = a2;
    Vec4_40CA60 t0, t1, tmp;
    f32 inv;
    s32 i;
    t0 = p[3];
    vec_add_ba(&t0, &t0, &p[0]);
    t1 = p[4];
    vec_add_ba(&t1, &t1, &p[1]);
    inv = 1.0f / (f32)(n - 2);
    for (i = 0; i < n - 1; i++) {
        func_L01_0040D220(&buf[i], &p[0], &p[1], &t0, &t1, (f32)i * inv);
        if (i > 0 && i < n - 2) {
            tmp.f[3] = 0.0f;
            tmp.f[0] = func_003824E0(-1.0f, 1.0f);
            tmp.f[1] = func_003824E0(-1.0f, 1.0f);
            tmp.f[2] = func_003824E0(-1.0f, 1.0f);
            func_0038CF68(&tmp, &tmp, s);
            vec_add_ba(&buf[i], &buf[i], &tmp);
        }
    }
    vec_sub_ab(&tmp, &buf[n - 2], &buf[n - 3]);
    vec_add_ab(&buf[n - 1], &buf[n - 2], &tmp);
}
/* localdecomp:end func_L01_0040CA60 */

/* localdecomp:start func_L01_0040CC30 */
typedef struct {
    Vec4_40CA60 m[4];
    u32 col[4];
    f32 uv[8];
    long l70;
    long l78;
    long l80;
    long l88;
} Pkt_40CC30;

typedef struct {
    s32 c0;
    s32 c1;
} Col_40CC30;

typedef struct {
    s32 f0;
    s32 f4;
} Flg_40CC30;

extern vu0_v4 D_L01_001E29C0;
extern void func_L01_0040D198_0040CC30(u8 *p);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, s32, s32);

void func_L01_0040CC30(void *pts_, s32 n, s32 *ca_, s32 *cb_, void *flag_, f32 w0, f32 w1, f32 uvs) {
    Vec4_40CA60 *pts = pts_;
    Col_40CC30 *ca = (Col_40CC30 *)ca_;
    Col_40CC30 *cb = (Col_40CC30 *)cb_;
    Flg_40CC30 *flag = flag_;
    Vec4_40CA60 M[4];
    Pkt_40CC30 A;
    Pkt_40CC30 B;
    Vec4_40CA60 E;
    Vec4_40CA60 F;
    f32 inv;
    f32 u;
    f32 v;
    f32 fr;
    f32 fn;
    s32 i;

    A.l78 = func_00389598(0x2B);
    A.l80 = 0x0000FF9000000260L;
    A.l70 = 0;
    A.l88 = 0x000000FF00000068L;
    inv = 1.0f / (f32)(n - 1);
    A.col[0] = A.col[1] = ca->c0;
    A.col[2] = A.col[3] = func_0038DBD8(ca->c0, ca->c1, inv);
    func_L01_0040D198_0040CC30((u8 *)&A);
    A.uv[0] = 0.0f;
    A.uv[1] = 0.0f;
    A.uv[2] = 0.0f;
    A.uv[3] = 1.0f;
    A.uv[4] = 1.0f;
    A.uv[5] = 0.0f;
    A.uv[6] = 1.0f;
    A.uv[7] = 1.0f;
    B.l78 = func_00389598(0x2B);
    B.col[0] = B.col[1] = cb->c0;
    B.l80 = 0x0000FF9000000260L;
    B.l88 = 0x000000FF00000068L;
    B.l70 = 0;
    B.col[2] = B.col[3] = func_0038DBD8(cb->c0, cb->c1, inv);
    func_L01_0040D198_0040CC30((u8 *)&B);
    B.uv[0] = 0.0f;
    B.uv[1] = 0.0f;
    B.uv[2] = 0.0f;
    B.uv[3] = 1.0f;
    B.uv[4] = uvs;
    B.uv[5] = 0.0f;
    B.uv[6] = uvs;
    B.uv[7] = 1.0f;
    if (flag->f0 != 0) {
        B.col[0] = B.col[1] = 0;
        A.col[0] = A.col[1] = 0;
    }
    E.q = 0;
    F.q = 0;
    E.f[3] = 1.0f;
    F.f[3] = 1.0f;
    E.f[2] = w0;
    F.f[2] = w0 * w1;
    vec_sub_ab(&M[0], &pts[1], &pts[0]);
    func_0038CF68(&M[0], &M[0], 1.0f);
    vec_sub_ba(&M[1], &D_L01_001E29C0, &pts[0]);
    func_0038CE90(&M[2], &M[1], &M[0]);
    func_0038CF68(&M[2], &M[2], 1.0f);
    func_0038CE90(&M[1], &M[0], &M[2]);
    M[3].q = pts[0].q;
    A.m[0].q = E.q;
    func_0038CE20(&A.m[1], &A.m[0], -1.0f);
    func_0038D028(&A.m[0], &A.m[0], M);
    func_0038D028(&A.m[1], &A.m[1], M);
    B.m[0].q = F.q;
    func_0038CE20(&B.m[1], &B.m[0], -1.0f);
    func_0038D028(&B.m[0], &B.m[0], M);
    func_0038D028(&B.m[1], &B.m[1], M);
    for (i = 1; i < n - 1; i++) {
        A.m[2].q = E.q;
        func_0038CE20(&A.m[3], &A.m[2], -1.0f);
        B.m[2].q = F.q;
        func_0038CE20(&B.m[3], &B.m[2], -1.0f);
        fr = (f32)i / (f32)(n - 1);
        vec_sub_ab(&M[0], &pts[i + 1], &pts[i]);
        func_0038CF68(&M[0], &M[0], 1.0f);
        vec_sub_ab(&M[1], &D_L01_001E29C0, &pts[i]);
        func_0038CE90(&M[2], &M[1], &M[0]);
        func_0038CF68(&M[2], &M[2], 1.0f);
        func_0038CE90(&M[1], &M[0], &M[2]);
        M[3].q = pts[i].q;
        func_0038D028(&A.m[2], &A.m[2], M);
        func_0038D028(&A.m[3], &A.m[3], M);
        func_0038D028(&B.m[2], &B.m[2], M);
        func_0038D028(&B.m[3], &B.m[3], M);
        A.col[0] = A.col[1] = func_0038DBD8(ca->c0, ca->c1, fr);
        fn = (f32)(i + 1) / (f32)(n - 1);
        A.col[2] = A.col[3] = func_0038DBD8(ca->c0, ca->c1, fn);
        B.col[0] = B.col[1] = func_0038DBD8(cb->c0, cb->c1, fr);
        B.col[2] = B.col[3] = func_0038DBD8(cb->c0, cb->c1, fn);
        if (flag->f4 != 0) {
            if (i == n - 2) {
                B.col[2] = B.col[3] = 0;
                A.col[2] = A.col[3] = 0;
            }
        }
        func_003D2DA0(&A, 0, 0);
        func_003D2DA0(&B, 0, 0);
        u = uvs * (f32)i;
        v = u + uvs;
        if (u >= 1.0f) {
            u -= 1.0f;
            v -= 1.0f;
        }
        B.uv[0] = u;
        B.uv[2] = u;
        B.uv[4] = v;
        B.uv[6] = v;
        A.m[0].q = A.m[2].q;
        A.m[1].q = A.m[3].q;
        B.m[0].q = B.m[2].q;
        B.m[1].q = B.m[3].q;
    }
}
/* localdecomp:end func_L01_0040CC30 */

/* localdecomp:start func_L01_0040D198 */
void func_L01_0040D198(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0040D198 */

/* localdecomp:start func_L01_0040D220 */
#include "vu0.h"

void func_L01_0040D220(Vec4_40CA60 *vo, Vec4_40CA60 *va, Vec4_40CA60 *vb, Vec4_40CA60 *vc, Vec4_40CA60 *vd, f32 t) {
    f32 *out = (f32 *)vo, *a = (f32 *)va, *b = (f32 *)vb, *c = (f32 *)vc, *d = (f32 *)vd;
    f32 t2, t3, p, q, r, e;

    if (t == 0.0f) {
        *(vu0_q *)out = *(vu0_q *)a;
        return;
    }
    if (t == 1.0f) {
        *(vu0_q *)out = *(vu0_q *)b;
        return;
    }
    t2 = t * t;
    t3 = t2 * t;
    p = (d[0] - b[0]) - (c[0] - a[0]);
    q = (c[0] - a[0]) - p;
    r = b[0] - c[0];
    e = a[0];
    out[0] = p * t3 + q * t2 + r * t + e;
    p = (d[1] - b[1]) - (c[1] - a[1]);
    q = (c[1] - a[1]) - p;
    r = b[1] - c[1];
    e = a[1];
    out[1] = p * t3 + q * t2 + r * t + e;
    p = (d[2] - b[2]) - (c[2] - a[2]);
    q = (c[2] - a[2]) - p;
    r = b[2] - c[2];
    e = a[2];
    out[3] = 0.0f;
    out[2] = p * t3 + q * t2 + r * t + e;
}
/* localdecomp:end func_L01_0040D220 */
