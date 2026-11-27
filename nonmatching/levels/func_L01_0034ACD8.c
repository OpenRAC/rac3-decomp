/* func_L01_0034ACD8 (k8 agent 5, 2026-11-27): near miss, 12 rows at level 01 with the file's flags (src/levels/shared/L01_00348620.c,
 * -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as). Ported from the matched func_L39_00540570 (same skeleton, 8 billboard
 * passes) plus a tail L39 lacks: `if (v->n40 != 0 && v->n40 < 13)` draws one more textured quad around the hero-to-target midpoint,
 * averages its corners, projects them with func_00389478 into the uv fields (clamped to [0, 0.9]) and sends a second packet
 * (func_00389598(-7) as the GIF tag word, 0x8000000054, 0xFF9000000260).
 * What closed rows: the h34 block's locals one block deeper (`if (v->h34 != 0) { { vu0_v4 dd, ...` ): gcc 2.95 frees a reused stack
 * slot only at the depth it was first allocated (the ang block inside `if (func_0038CB00(..) == 0) { if (...) {`), so only then does the
 * tail block reuse sp+0x150.. and the frame is 0x260 as retail; the tail's own t/col locals (tt, cc) keep the function's s4/s5 and
 * f20/f21 as retail; q.v[1] and q.v[2] with vec_*_ab (sched2 swaps their two lqc2s, retail's vf1/vf2 naming); func_003A9440's
 * second argument is unsigned long; the packet words gif, u80 order.
 * Left (12 rows): (1) the two spill slots at sp+0x1d0/0x1d4 swapped (&v->h36, hoisted at the start, and `col >> 24` of pass 7;
 * retail &h36 at 0x1d0); (2) in pass 5's tail, retail schedules `or $v0,$s5,$v0` (col | 0xFFFFFF) before the two lqc2 of
 * vec_sub_ab(&r, D_L01_001E2A40, a0 + 0x10), here after. Permuter (box2, 5 min, -j4): stuck at its score 10.
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_0034ACD8 */
typedef struct {
    vu0_v4 v[4];
    u32 col[4];
    f32 uv[4][2];
    unsigned long u70;
    unsigned long u78;
    unsigned long u80;
    unsigned long gif;
} Q_0034ACD8;
typedef struct {
    f32 ang[6];
    u8 pad18[4];
    s16 h1C;
    s16 h1E;
    f32 f20;
    f32 f24;
    s16 h28;
    s16 h2A;
    f32 f2C;
    f32 f30;
    s16 h34;
    s16 h36;
    f32 f38;
    f32 f3C;
    s32 n40;
    f32 f44;
} V_0034ACD8;
extern vu0_v4 D_L01_001D7C50_0034ACD8[4] __asm__("D_L01_001D7C50");
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);
extern f32 func_L01_004451D0(f32, f32, f32, f32, f32);
extern void func_0038CE90(void *, void *, void *);
extern s32 func_0038CB00(void *);
extern void func_003860A8(f32 *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_003A9440(s32, unsigned long);
extern void func_00389478(void *, f32 *, f32 *);
extern unsigned long func_00389598(s32);

static __inline__ f32 lerp_0034ACD8(f32 a, f32 b, f32 t) {
    return a + (b - a) * t;
}

void func_L01_0034ACD8(u8 *a0) {
    Q_0034ACD8 q;
    vu0_v4 m[4];
    vu0_v4 d;
    vu0_v4 r;
    vu0_v4 basis[4];
    vu0_v4 cam;
    vu0_v4 t2;
    V_0034ACD8 *v;
    f32 len;
    f32 fade;
    f32 dot;
    f32 size;
    f32 t;
    f32 k;
    f32 c;
    s32 col;
    s32 a;
    s32 i;

    vec_sub_ab(&d, a0 + 0x10, D_L01_001E2A40);
    v = *(V_0034ACD8 **)(a0 + 0x68);
    len = func_0038CEA8(&d);
    if (len != 0.0f) {
        func_0038CE20(&d, &d, 1.0f / len);
    }
    fade = 1.0f;
    if (len < 11.0f) {
        if (len <= 7.0f) {
            fade = 0.0f;
        } else {
            fade = (len - 7.0f) * 0.25f;
        }
    }
    dot = func_0038CE68(&d, a0 + 0xC0);
    t = v->h1C * v->f20;
    size = lerp_0034ACD8(20.0f, 2.0f, t);
    if (v->h1C < v->h28) {
        c = v->h1C * v->f2C;
        col = (s32)(c * 60.0f * dot * dot) << 24;
    } else {
        col = (s32)(dot * 60.0f * dot) << 24;
    }
    /* 1 */
    if (fabs_asm(v->ang[0]) > 1e-5f) {
        func_003C4840(&r, a0 + 0xC0, v->ang[0]);
        func_0038D850(&m[1], a0 + 0xD0, &r);
        func_0038D850(&m[2], a0 + 0xE0, &r);
    } else {
        m[1] = *(vu0_v4 *)(a0 + 0xD0);
        m[2] = *(vu0_v4 *)(a0 + 0xE0);
    }
    m[3] = *(vu0_v4 *)(a0 + 0x10);
    func_0038CE20(&m[0], a0 + 0xC0, size);
    func_0038CE20(&m[1], &m[1], size);
    func_0038CE20(&m[2], &m[2], size);
    m[0].w = m[1].w = m[2].w = 0.0f;
    m[3].w = 1.0f;
    func_003D93B0(&q, 0x38, 1, 0x80);
    q.col[3] = col | 0x7F7F7F;
    q.col[2] = col | 0x7F7F7F;
    q.col[1] = col | 0x7F7F7F;
    q.col[0] = col | 0x7F7F7F;
    q.uv[0][0] = 0.0f;
    q.uv[0][1] = 0.0f;
    q.uv[1][0] = 0.0f;
    q.uv[1][1] = 1.0f;
    q.uv[2][0] = 1.0f;
    q.uv[2][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.uv[3][1] = 1.0f;
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            func_0038D028(&q.v[j], &D_L01_001D7C50_0034ACD8[j], m);
        }
    }
    func_003D2DA0(&q, 0, 0);
    /* 2 */
    if (fabs_asm(v->ang[0]) > 1e-5f) {
        func_003C4840(&r, a0 + 0xC0, -v->ang[0]);
        func_0038D850(&m[1], a0 + 0xD0, &r);
        func_0038D850(&m[2], a0 + 0xE0, &r);
    } else {
        m[1] = *(vu0_v4 *)(a0 + 0xD0);
        m[2] = *(vu0_v4 *)(a0 + 0xE0);
    }
    m[3] = *(vu0_v4 *)(a0 + 0x10);
    func_0038CE20(&m[0], a0 + 0xC0, size);
    func_0038CE20(&m[1], &m[1], size);
    func_0038CE20(&m[2], &m[2], size);
    m[0].w = m[1].w = m[2].w = 0.0f;
    m[3].w = 1.0f;
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            func_0038D028(&q.v[j], &D_L01_001D7C50_0034ACD8[j], m);
        }
    }
    func_003D2DA0(&q, 0, 0);
    t = v->h1E * v->f24;
    size = lerp_0034ACD8(4.0f, 1.0f, t);
    if (v->h1E < v->h2A) {
        c = func_L01_004451D0(1.0f, 0.0f, 1.0f, 2.0f, v->h1E * v->f30);
    } else {
        c = 1.0f;
    }
    col = (s32)(c * 255.0f * fade);
    a = (s32)(col * 0.2f) << 24;
    col <<= 24;
    q.col[3] = a | 0xFFFFFF;
    q.col[2] = a | 0xFFFFFF;
    q.col[1] = a | 0xFFFFFF;
    q.col[0] = a | 0xFFFFFF;
    /* 3 */
    if (fabs_asm(v->ang[1]) > 1e-5f) {
        func_003C4840(&r, a0 + 0xC0, v->ang[1]);
        func_0038D850(&m[1], a0 + 0xD0, &r);
        func_0038D850(&m[2], a0 + 0xE0, &r);
    } else {
        m[1] = *(vu0_v4 *)(a0 + 0xD0);
        m[2] = *(vu0_v4 *)(a0 + 0xE0);
    }
    k = size * 1.5f;
    func_0038CE20(&m[0], a0 + 0xC0, k);
    func_0038CE20(&m[1], &m[1], k);
    func_0038CE20(&m[2], &m[2], k);
    m[0].w = m[1].w = m[2].w = 0.0f;
    m[3].w = 1.0f;
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            func_0038D028(&q.v[j], &D_L01_001D7C50_0034ACD8[j], m);
        }
    }
    func_003D2DA0(&q, 0, 0);
    a = (s32)(c * 255.0f * fade * 1.5f);
    if (a > 255) {
        a = 255;
    }
    func_003D93B0(&q, 0x39, 1, 0x80);
    basis[3] = *(vu0_v4 *)(a0 + 0x10);
    q.col[3] = (a << 24) | 0xFFFFFF;
    q.col[2] = (a << 24) | 0xFFFFFF;
    q.col[1] = (a << 24) | 0xFFFFFF;
    q.col[0] = (a << 24) | 0xFFFFFF;
    q.uv[0][0] = 0.0f;
    q.uv[0][1] = 0.0f;
    q.uv[1][0] = 0.0f;
    q.uv[1][1] = 1.0f;
    q.uv[2][0] = 1.0f;
    q.uv[2][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.uv[3][1] = 1.0f;
    /* 4 */
    if (fabs_asm(v->ang[2]) > 1e-5f) {
        func_003C4840(&r, a0 + 0xC0, v->ang[2]);
        func_0038D850(&m[1], a0 + 0xD0, &r);
        func_0038D850(&m[2], a0 + 0xE0, &r);
    } else {
        m[1] = *(vu0_v4 *)(a0 + 0xD0);
        m[2] = *(vu0_v4 *)(a0 + 0xE0);
    }
    k = size * 1.25f;
    func_0038CE20(&m[0], a0 + 0xC0, k);
    func_0038CE20(&m[1], &m[1], k);
    func_0038CE20(&m[2], &m[2], k);
    m[0].w = m[1].w = m[2].w = 0.0f;
    m[3].w = 1.0f;
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            func_0038D028(&q.v[j], &D_L01_001D7C50_0034ACD8[j], m);
        }
    }
    func_003D2DA0(&q, 0, 0);
    /* 5 */
    if (fabs_asm(v->ang[3]) > 1e-5f) {
        func_003C4840(&r, a0 + 0xC0, v->ang[3]);
        func_0038D850(&m[1], a0 + 0xD0, &r);
        func_0038D850(&m[2], a0 + 0xE0, &r);
    } else {
        m[1] = *(vu0_v4 *)(a0 + 0xD0);
        m[2] = *(vu0_v4 *)(a0 + 0xE0);
    }
    m[3] = *(vu0_v4 *)(a0 + 0x10);
    func_0038CE20(&m[0], a0 + 0xC0, size);
    func_0038CE20(&m[1], &m[1], size);
    func_0038CE20(&m[2], &m[2], size);
    m[0].w = m[1].w = m[2].w = 0.0f;
    m[3].w = 1.0f;
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            func_0038D028(&q.v[j], &D_L01_001D7C50_0034ACD8[j], m);
        }
    }
    func_003D2DA0(&q, 0, 0);
    q.col[3] = col | 0xFFFFFF;
    q.col[2] = col | 0xFFFFFF;
    q.col[1] = col | 0xFFFFFF;
    q.col[0] = col | 0xFFFFFF;
    vec_sub_ab(&r, D_L01_001E2A40, a0 + 0x10);
    func_0038CF68(&r, &r, 0.25f);
    vec_add_ba(&m[3], a0 + 0x10, &r);
    {
        vu0_v4 *b = basis;
        func_003C5180(&b[3], &cam, 1);
        vec_sub_ba(&b[0], D_L01_001E2A40, &m[3]);
        func_0038CF68(&b[0], &b[0], 1.0f);
        func_0038CE90(&b[1], &b[0], &cam);
        func_0038CF68(&b[1], &b[1], 1.0f);
        func_0038CE90(&b[2], &b[1], &b[0]);
    }    /* 6 */
    if (fabs_asm(v->ang[4]) > 1e-5f) {
        func_003C4840(&t2, &basis[0], v->ang[4]);
        func_0038D850(&m[1], &basis[1], &t2);
        func_0038D850(&m[2], &basis[2], &t2);
    } else {
        m[1] = basis[1];
        m[2] = basis[2];
    }
    func_0038CE20(&m[0], &basis[0], size);
    func_0038CE20(&m[1], &m[1], size);
    func_0038CE20(&m[2], &m[2], size);
    m[0].w = m[1].w = m[2].w = 0.0f;
    m[3].w = 1.0f;
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            func_0038D028(&q.v[j], &D_L01_001D7C50_0034ACD8[j], m);
        }
    }
    func_003D2DA0(&q, 0, 0);

    /* 7 */
    if (fabs_asm(v->ang[5]) > 1e-5f) {
        func_003C4840(&t2, &basis[0], v->ang[5]);
        func_0038D850(&m[1], &basis[1], &t2);
        func_0038D850(&m[2], &basis[2], &t2);
    } else {
        m[1] = basis[1];
        m[2] = basis[2];
    }
    k = size * 0.75f;
    func_0038CE20(&m[0], &basis[0], k);
    func_0038CE20(&m[1], &m[1], k);
    func_0038CE20(&m[2], &m[2], k);
    m[0].w = m[1].w = m[2].w = 0.0f;
    m[3].w = 1.0f;
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            func_0038D028(&q.v[j], &D_L01_001D7C50_0034ACD8[j], m);
        }
    }
    func_003D2DA0(&q, 0, 0);

    a = (s32)((f32)((col >> 24) & 0xFF) * 0.2f) << 24;
    func_003D93B0(&q, 0x38, 1, 0x80);
    q.col[3] = a | 0xFFFFFF;
    q.col[2] = a | 0xFFFFFF;
    q.col[1] = a | 0xFFFFFF;
    q.col[0] = a | 0xFFFFFF;
    /* 8 */
    if (fabs_asm(v->ang[1]) > 1e-5f) {
        func_003C4840(&t2, &basis[0], v->ang[1]);
        func_0038D850(&m[1], &basis[1], &t2);
        func_0038D850(&m[2], &basis[2], &t2);
    } else {
        m[1] = basis[1];
        m[2] = basis[2];
    }
    k = size * 1.5f;
    func_0038CE20(&m[0], &basis[0], k);
    func_0038CE20(&m[1], &m[1], k);
    func_0038CE20(&m[2], &m[2], k);
    m[0].w = m[1].w = m[2].w = 0.0f;
    m[3].w = 1.0f;
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            func_0038D028(&q.v[j], &D_L01_001D7C50_0034ACD8[j], m);
        }
    }
    func_003D2DA0(&q, 0, 0);
    if (func_0038CB00(&v->h36) == 0) {
        func_003860A8(&t2.x, a0 + 0x10);
        if (28492.0f <= t2.x && t2.x <= 37082.0f && 28492.0f <= t2.y && t2.y <= 37082.0f) {
            vu0_v4 ax;
            f32 w[4];
            vu0_v4 off;
            vu0_v4 sd;
            vu0_v4 o;
            vu0_v4 o2;
            vu0_q pp;
            f32 one;
            f32 W;
            f32 iW;
            f32 rx;
            f32 ry;
            f32 u;
            f32 mn;
            t2.x -= 28492.0f;
            t2.y -= 28492.0f;
            one = 1.0f;
            W = 8590.0f;
            iW = 1.0f / 8590.0f;
            c = v->h36 * v->f38;
            col = (s32)(c * 64.0f) << 24;
            func_0038D890(&ax, &cam, &d, 0.7853982f);
            func_003D93B0(&q, 0xB, 1, 0x80);
            q.u70 = 5;
            q.uv[0][0] = 0.0f;
            q.uv[0][1] = 1.0f;
            q.uv[1][0] = 1.0f;
            q.uv[1][1] = 1.0f;
            q.uv[2][0] = 0.0f;
            q.uv[2][1] = 0.0f;
            q.uv[3][0] = 1.0f;
            q.uv[3][1] = 0.0f;
            q.col[1] = 0x104050;
            q.col[0] = 0x104050;
            q.col[3] = col | 0x104050;
            q.col[2] = col | 0x104050;
            mn = t2.x < t2.y ? t2.x : t2.y;
            u = mn * iW;
            if (u < 0.5f) {
                w[3] = lerp_0034ACD8(0.0f, one, u * 2.0f);
            } else {
                w[3] = lerp_0034ACD8(one, 6.0f, (u - 0.5f) * 2.0f);
            }
            ry = W - t2.y;
            mn = t2.x < ry ? t2.x : ry;
            u = mn * iW;
            if (u < 0.5f) {
                w[2] = lerp_0034ACD8(0.0f, 1.0f, u * 2.0f);
            } else {
                w[2] = lerp_0034ACD8(1.0f, 6.0f, (u - 0.5f) * 2.0f);
            }
            rx = W - t2.x;
            mn = rx < ry ? rx : ry;
            u = mn * iW;
            if (u < 0.5f) {
                w[1] = lerp_0034ACD8(0.0f, 1.0f, u * 2.0f);
            } else {
                w[1] = lerp_0034ACD8(1.0f, 6.0f, (u - 0.5f) * 2.0f);
            }
            mn = rx < t2.y ? rx : t2.y;
            u = mn * iW;
            if (u < 0.5f) {
                w[0] = lerp_0034ACD8(0.0f, 1.0f, u * 2.0f);
            } else {
                w[0] = lerp_0034ACD8(1.0f, 6.0f, (u - 0.5f) * 2.0f);
            }
            func_0038CF68(&off, &d, 2.0f);
            for (i = 0; i < 4; i++) {
                func_0038CF68(&ax, &ax, w[i]);
                func_0038CE90(&sd, &d, &ax);
                func_0038CF68(&sd, &sd, 0.01f);
                vec_add_ba(&o, D_L01_001E2A40, &off);
                vec_sub_ba(&o2, &o, a0 + 0x10);
                __asm__("lqc2 %0, %1" : "=j"(pp) : "m"(*(vu0_v4 *)(a0 + 0x10)));
                vec_add_ba(&q.v[0], &o, &sd);
                vec_sub_ab(&q.v[1], &o, &sd);
                {
                    vu0_q qa, qr;
                    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(ax));
                    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(pp), "j"(qa));
                    __asm__("sqc2 %1, %0" : "=m"(o) : "j"(qr));
                }
                vec_add_ba(&o, &o2, &o);
                func_0038CE20(&sd, &sd, 5.0f);
                vec_add_ab(&q.v[2], &o, &sd);
                vec_sub_ab(&q.v[3], &o, &sd);
                func_003D2DA0(&q, 0, 0);
                if (i < 3) {
                    func_0038D890(&ax, &ax, &d, 1.5707964f);
                }
            }
        }
    }
    if (v->h34 != 0) {
      {
        vu0_v4 dd;
        vu0_v4 o;
        vu0_v4 sx;
        vu0_v4 sy;
        vu0_v4 o2;
        c = v->h34 * v->f3C;
        func_003D93B0(&q, 0xB, 4, 0x80);
        q.col[3] = ((s32)(c * 255.0f) << 24) | 0x808080;
        q.col[2] = ((s32)(c * 255.0f) << 24) | 0x808080;
        q.col[1] = ((s32)(c * 255.0f) << 24) | 0x808080;
        q.col[0] = ((s32)(c * 255.0f) << 24) | 0x808080;
        q.uv[0][0] = 0.0f;
        q.uv[0][1] = 0.0f;
        q.uv[1][0] = 0.0f;
        q.uv[1][1] = 1.0f;
        q.uv[2][0] = 1.0f;
        q.uv[2][1] = 0.0f;
        q.uv[3][0] = 1.0f;
        q.uv[3][1] = 1.0f;
        vec_sub_ba(&t2, a0 + 0x10, D_L01_001E2A40);
        func_0038CF68(&dd, &t2, 0.1f);
        vec_add_ba(&o, D_L01_001E2A40, &dd);
        func_0038CE90(&sx, &t2, &cam);
        func_0038CF68(&sx, &sx, 0.075f);
        func_0038CE90(&sy, &sx, &t2);
        func_0038CF68(&sy, &sy, 0.075f);
        vec_add_ba(&o2, &o, &sy);
        vec_add_ab(&q.v[0], &o2, &sx);
        vec_sub_ab(&q.v[1], &o2, &sx);
        vec_sub_ab(&o2, &o, &sy);
        vec_add_ab(&q.v[2], &o2, &sx);
        vec_sub_ab(&q.v[3], &o2, &sx);
        func_003D2DA0(&q, 0, 0);
      }
    }
    if (v->n40 != 0 && v->n40 < 13) {
        vu0_v4 B;
        vu0_v4 C;
        vu0_v4 X;
        vu0_v4 Y;
        vu0_v4 Z;
        vu0_v4 P;
        vu0_v4 D;
        s32 j;
        s32 k;
        s32 cc;
        f32 s;
        f32 tt;
        tt = v->n40 * v->f44;
        s = lerp_0034ACD8(0.5f, 0.0f, tt);
        vec_sub_ba(&t2, a0 + 0x10, D_L01_001E2A40);
        func_0038CF68(&t2, &t2, 0.3f);
        vec_add_ba(&B, D_L01_001E2A40, &t2);
        func_003D93B0(&q, 0x36, 1, 0x80);
        q.gif = 0x800000004AUL;
        C = cam;
        cc = ((s32)(tt * 255.0f) << 24) | 0x808080;
        q.col[3] = cc;
        q.col[2] = cc;
        q.col[1] = cc;
        q.col[0] = cc;
        q.uv[0][0] = 0.0f;
        q.uv[0][1] = 0.0f;
        q.uv[1][0] = 0.0f;
        q.uv[1][1] = 1.0f;
        q.uv[2][0] = 1.0f;
        q.uv[2][1] = 0.0f;
        q.uv[3][0] = 1.0f;
        q.uv[3][1] = 1.0f;
        func_0038CE90(&X, &t2, &C);
        func_0038CF68(&X, &X, s);
        func_0038CE90(&Y, &X, &t2);
        func_0038CF68(&Y, &Y, s);
        vec_add_ba(&Z, &B, &Y);
        vec_add_ba(&q.v[0], &Z, &X);
        vec_sub_ab(&q.v[1], &Z, &X);
        vec_sub_ba(&Z, &B, &Y);
        vec_add_ab(&q.v[2], &Z, &X);
        vec_sub_ab(&q.v[3], &Z, &X);
        func_003A9440(0x47, 0x31001);
        func_003D2DA0(&q, 0, 0);
        func_003A9440(0x47, 0x33001);
        qzero(&P);
        for (k = 0; k < 4; k++) {
            vec_add_ba(&P, &P, &q.v[k]);
        }
        func_0038CE20(&P, &P, 0.25f);
        for (j = 0; j < 4; j++) {
            vec_sub_ba(&D, &q.v[j], &P);
            func_0038CE20(&D, &D, 0.8f);
            vec_add_ab(&D, &P, &D);
            func_00389478(&q.v[j], &q.uv[j][0], &q.uv[j][1]);
            if (q.uv[j][0] > 0.9f) {
                q.uv[j][0] = 0.9f;
            } else if (q.uv[j][0] < 0.0f) {
                q.uv[j][0] = 0.0f;
            }
            if (q.uv[j][1] > 0.9f) {
                q.uv[j][1] = 0.9f;
            } else if (q.uv[j][1] < 0.0f) {
                q.uv[j][1] = 0.0f;
            }
        }
        q.u78 = func_00389598(-7);
        q.u80 = 0xFF9000000260UL;
        q.gif = 0x8000000054UL;
        q.u70 = 0;
        func_003D2DA0(&q, 0, 0);
    }
}
/* localdecomp:end func_L01_0034ACD8 */
