#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L20_003E6150 */
typedef struct {
    vu0_v4 v[4];
    u32 col[4];
    f32 uv[4][2];
    unsigned long u70;
    unsigned long u78;
    unsigned long u80;
    unsigned long gif;
} Q_003E6150;
extern f32 D_L20_001E2E80[];
__asm__(".extern D_L20_001E2E80, 16");
extern vu0_v4 D_001A4EC0;
extern vu0_v4 D_L20_001D7C50[4];
extern s32 D_L20_001DF0E8;
__asm__(".extern D_L20_001DF0E8, 4");
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003A9440(s32, unsigned long);
extern void func_003D2DA0(void *, s32, s32);
extern void func_00389478(void *, f32 *, f32 *);

/* from rac3's func_L36_0037CF50 */
void func_L20_003E6150(u8 *a0, f32 size) {
    Q_003E6150 q;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 p;
    vu0_v4 z;
    vu0_v4 c[3];
    s32 i;
    s32 j;

    func_003D93B0(&q, D_L20_001DF0E8, 1, 0x80);
    q.gif = (0x8000L << 24) | 0x4A;
    p = *(vu0_v4 *)(a0 + 0x10);
    q.col[3] = 0x80808080;
    q.col[2] = 0x80808080;
    q.col[1] = 0x80808080;
    q.col[0] = 0x80808080;
    q.uv[0][0] = 0.0f;
    q.uv[0][1] = 0.0f;
    q.uv[1][0] = 0.0f;
    q.uv[1][1] = 1.0f;
    q.uv[2][0] = 1.0f;
    q.uv[2][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.uv[3][1] = 1.0f;
    vec_sub_ab(&d, D_L20_001E2E80, &p);
    func_0038CF68(&d, &d, 1.0f);
    func_0038CE90(&e, &d, &D_001A4EC0);
    func_0038CF68(&e, &e, 1.0f);
    func_0038CE90(&f, &e, &d);
    func_0038CE20(&z, &d, 0.05f);
    vec_add_ab(&p, &p, &z);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&q.v[i], &D_L20_001D7C50[i], size);
        func_0038D028(&q.v[i], &q.v[i], &d);
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&q, 0, 0);
    for (j = 0; j < 4; j++) {
        func_00389478(&q.v[j], &q.uv[j][0], &q.uv[j][1]);
    }
    func_003D93B0(&q, -1, 1, 0x80);
    q.gif = (0x8000L << 22) | 0x54;
    func_003D2DA0(&q, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L20_003E6150 */

/* localdecomp:start func_L20_003E6378 */
/* func_L20_003E6378: builds the final boss's two lightning bolts (32 smoothed points each, plus
 * four branches of eight points) and spawns the
 * bolt effects (func_L01_00463378) along them when the moby is at least 4 units from
 * D_L20_001E2E00.
 * Matching notes: one counter variable per loop and a body-local n (C++ for-scope locals); every
 * vector copy goes through the inline assignment cp_003E6378; the branch loops count m from 1;
 * the second spawn loop of each set picks a colour it never uses (retail calls rand(2) there and
 * drops the result), and the moby position copies into w/y are never read (retail stores them).
 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E6378;
typedef struct {
    V4_003E6378 v[64];      /* +0x000: 0..31 positions, 32..63 velocities */
    V4_003E6378 w[8][4];    /* +0x400: four branches of eight points; 0..3 positions, 4..7 velocities */
    V4_003E6378 ang;        /* +0x600 */
} Set_003E6378;
typedef struct {
    u8 pad0[0x8];
    s32 i8;                 /* 0x08 */
    u8 padC[0x22 - 0xC];
    s16 count;              /* 0x22 */
    s32 color;              /* 0x24 */
    u8 idx[4];              /* 0x28 */
    u8 pad2C[4];
    Set_003E6378 set[2];    /* 0x30, 0x640 */
} S_003E6378;

extern s32 D_L20_001DF158;
__asm__(".extern D_L20_001DF158, 4");
extern s32 D_L20_001DF15C;
__asm__(".extern D_L20_001DF15C, 4");
extern f32 D_L20_001DF130;
__asm__(".extern D_L20_001DF130, 4");
extern f32 D_L20_001DF134;
__asm__(".extern D_L20_001DF134, 4");
extern f32 D_L20_001DF148;
__asm__(".extern D_L20_001DF148, 4");
extern s32 D_L20_001DF150;
__asm__(".extern D_L20_001DF150, 4");
extern s32 D_L20_001DF154;
__asm__(".extern D_L20_001DF154, 4");
extern s32 D_L20_001DF13C;
__asm__(".extern D_L20_001DF13C, 4");
extern s32 D_L20_001DF140;
__asm__(".extern D_L20_001DF140, 4");
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern void func_L01_00443B88(void *, f32, f32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_0038D328(void *, void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038CF38(f32 *, f32 *);
extern u8 D_L20_001E2E00[];
__asm__(".extern D_L20_001E2E00, 16");

/* the vector class's assignment (an inline operator= in the original C++): *d = *p */
static __inline__ void cp_003E6378(V4_003E6378 *d, V4_003E6378 *p) {
    *d = *p;
}

void func_L20_003E6378(void *pv) {
    u8 *p = pv;
    S_003E6378 *s;
    V4_003E6378 pos[32];    /* the bolt's 32 points */
    V4_003E6378 vel[32];    /* and their drift */
    V4_003E6378 t;
    V4_003E6378 r;
    V4_003E6378 x;
    V4_003E6378 y;
    V4_003E6378 z;
    V4_003E6378 w;
    f32 h;

    {
        s32 lo = (D_L20_001DF158 * 5 + 2) / 6;
        s32 hi = (D_L20_001DF15C * 5 + 2) / 6;

        *(f32 *)(p + 0x1C) = 1.0f;
        s = *(S_003E6378 **)(p + 0x68);
        s->i8 = s->count = func_00382498(lo, hi);
    }
    h = func_003824E0(4.0f, 5.0f);
    {
        s32 i;

        for (i = 0; i < 32; i++) {
            f32 d = i / 31.0f;

            d = (0.5f - d) * h;

            if (i < 3 || i > 28) {
                qzero(&pos[i]);
                qzero(&vel[i]);
            } else {
                func_L01_00443B88(&pos[i], 0.0f, D_L20_001DF130);
                func_L01_00443B88(&vel[i], 0.0f, D_L20_001DF134 * 0.020000001f);
            }
            pos[i].w = 1.0f;
            pos[i].y += d;
        }
    }
    {
        s32 j;

        for (j = 0; j < 32; j++) {
            if (j == 0 || j == 31) {
                cp_003E6378(&s->set[0].v[j], &pos[j]);
                cp_003E6378(&s->set[0].v[j + 32], &vel[j]);
            } else {
                vec_add_ab(&t, &pos[j - 1], &pos[j]);
                vec_add_ab(&t, &t, &pos[j + 1]);
                func_0038CE20(&s->set[0].v[j], &t, 0.333f);
                vec_add_ba(&t, &vel[j - 1], &vel[j]);
                vec_add_ba(&t, &t, &vel[j + 1]);
                func_0038CE20(&s->set[0].v[j + 32], &t, 0.333f);
            }
        }
    }
    {
        s32 j;

        for (j = 0; j < 32; j++) {
            if (j == 0 || j == 31) {
                cp_003E6378(&s->set[1].v[j], &pos[j]);
                cp_003E6378(&s->set[1].v[j + 32], &vel[j]);
            } else {
                vec_add_ab(&t, &pos[j - 1], &pos[j]);
                vec_add_ab(&t, &t, &pos[j + 1]);
                func_0038CE20(&s->set[1].v[j], &t, 0.333f);
                vec_add_ba(&t, &vel[j - 1], &vel[j]);
                vec_add_ba(&t, &t, &vel[j + 1]);
                func_0038CE20(&s->set[1].v[j + 32], &t, 0.333f);
            }
        }
    }
    {
        s32 k;

        for (k = 0; k < 4; k++) {
            s32 n;

            func_L01_00443B88(&t, D_L20_001DF130, D_L20_001DF130);
            n = (s32)func_003824E0(k * 6.0f, (k + 1) * 6.0f) + 4;
            s->idx[k] = n;
            cp_003E6378(&s->set[0].w[0][k], &s->set[0].v[n]);
            cp_003E6378(&s->set[0].w[4][k], &s->set[0].v[n + 32]);
            {
                s32 m;

                for (m = 1; m < 4; m++) {
                    func_L01_00443B88(&r, 0.1f, 0.1f);
                    func_L01_00443B88(&s->set[0].w[m + 4][k], 0.0f, D_L20_001DF134 * 0.020000001f);
                    vec_add_ab(&s->set[0].w[m][k], &s->set[0].w[m - 1][k], &t);
                    vec_add_ba(&s->set[0].w[m][k], &s->set[0].w[m][k], &r);
                }
            }
        }
    }
    {
        s32 l;

        for (l = 0; l < 4; l++) {
            s32 n;

            func_L01_00443B88(&t, D_L20_001DF130, D_L20_001DF130);
            n = (s32)func_003824E0(l * 6.0f, (l + 1) * 6.0f) + 4;
            s->idx[l] = n;
            cp_003E6378(&s->set[1].w[0][l], &s->set[1].v[n]);
            cp_003E6378(&s->set[1].w[4][l], &s->set[1].v[n + 32]);
            {
                s32 m;

                for (m = 1; m < 4; m++) {
                    func_L01_00443B88(&r, 0.1f, 0.1f);
                    func_L01_00443B88(&s->set[1].w[m + 4][l], 0.0f, D_L20_001DF134 * 0.020000001f);
                    vec_add_ab(&s->set[1].w[m][l], &s->set[1].w[m - 1][l], &t);
                    vec_add_ba(&s->set[1].w[m][l], &s->set[1].w[m][l], &r);
                }
            }
        }
    }
    if (func_0038CF38((f32 *)(p + 0x10), (f32 *)D_L20_001E2E00) >= 4.0f) {
        s->set[0].ang.z = *(f32 *)(p + 0xF8);
        s->set[0].ang.y = *(f32 *)(p + 0xF4);
        s->set[0].ang.y += func_L01_00443A18(0.0f, 30.0f) * 0.017453292f;
        s->set[0].ang.x = func_00382538();
        func_0038D328(&x, &s->set[0].ang);
        cp_003E6378(&w, (V4_003E6378 *)(p + 0x10));
        {
            s32 i;

            for (i = 0; i < 32; i += 8) {
                s32 col;

                func_0038D028(&t, &s->set[0].v[i], &x);
                cp_003E6378(&r, &s->set[0].v[i + 32]);
                r.w = D_L20_001DF148;
                col = func_00382468(2) ? D_L20_001DF150 : D_L20_001DF154;
                func_L01_00463378(&t, &r, &r, D_L20_001DF13C, D_L20_001DF140, i >> 1, 15,
                                  ((func_00382468(10) + 20) * 5 + 2) / 6, col);
            }
        }
        {
            s32 m;

            for (m = 0; m < 2; m++) {
                s32 col;

                func_0038D028(&t, &s->set[0].w[3][m], &x);
                cp_003E6378(&r, &s->set[0].w[7][m]);
                r.w = D_L20_001DF148;
                col = func_00382468(2) ? D_L20_001DF150 : D_L20_001DF154;
                func_L01_00463378(&t, &r, &r, D_L20_001DF13C, D_L20_001DF140, s->idx[m] >> 1, 15,
                                  ((func_00382468(10) + 20) * 5 + 2) / 6, D_L20_001DF154);
            }
        }
    }
    if (func_0038CF38((f32 *)(p + 0x10), (f32 *)D_L20_001E2E00) >= 4.0f) {
        s->set[1].ang.z = *(f32 *)(p + 0xF8);
        s->set[1].ang.y = *(f32 *)(p + 0xF4);
        s->set[1].ang.y += func_L01_00443A18(0.0f, 30.0f) * 0.017453292f;
        s->set[1].ang.x = func_00382538();
        func_0038D328(&t, &s->set[1].ang);
        cp_003E6378(&y, (V4_003E6378 *)(p + 0x10));
        {
            s32 i;

            for (i = 0; i < 32; i += 8) {
                s32 col;

                func_0038D028(&z, &s->set[1].v[i], &t);
                cp_003E6378(&w, &s->set[1].v[i + 32]);
                w.w = D_L20_001DF148;
                col = func_00382468(2) ? D_L20_001DF150 : D_L20_001DF154;
                func_L01_00463378(&z, &w, &w, D_L20_001DF13C, D_L20_001DF140, i >> 1, 15,
                                  ((func_00382468(10) + 20) * 5 + 2) / 6, col);
            }
        }
        {
            s32 m;

            for (m = 0; m < 2; m++) {
                s32 col;

                func_0038D028(&z, &s->set[1].w[3][m], &t);
                cp_003E6378(&w, &s->set[1].w[7][m]);
                w.w = D_L20_001DF148;
                col = func_00382468(2) ? D_L20_001DF150 : D_L20_001DF154;
                func_L01_00463378(&z, &w, &w, D_L20_001DF13C, D_L20_001DF140, s->idx[m] >> 1, 15,
                                  ((func_00382468(10) + 20) * 5 + 2) / 6, D_L20_001DF154);
            }
        }
    }
}
/* localdecomp:end func_L20_003E6378 */

/* localdecomp:start func_L20_003E6D30 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E6D30;
typedef struct {
    u8 pad0[0x8];
    s32 i8;                 /* 0x08 */
    u8 padC[0x22 - 0xC];
    s16 count;              /* 0x22 */
    s32 color;              /* 0x24 */
    u8 idx[4];              /* 0x28 */
    u8 pad2C[4];
    struct {
        V4_003E6D30 v[64];      /* +0x000: 4..26 positions, 36..58 velocities */
        V4_003E6D30 sel[4];     /* +0x400 */
        V4_003E6D30 g[7][4];    /* +0x440 */
        u8 pad600[0x10];
    } set[2];               /* 0x30, 0x640 */
} S_003E6D30;

extern s32 func_0038DBD8(s32, s32, f32);
extern s32 D_L20_001DF160;
__asm__(".extern D_L20_001DF160, 4");
extern s32 D_L20_001DF164;
__asm__(".extern D_L20_001DF164, 4");
extern s32 D_L20_001DF104;
__asm__(".extern D_L20_001DF104, 4");
extern s32 D_L20_001DF108;
__asm__(".extern D_L20_001DF108, 4");
extern s32 D_L20_001DF10C;
__asm__(".extern D_L20_001DF10C, 4");

static __inline__ void step_003E6D30(S_003E6D30 *s, s32 n) {
    if (s->count != 0) {
        s32 k;
        s32 i;
        s32 j;

        s->count--;
        for (k = 0; k < 23; k++) {
            vec_add_ab(&s->set[n].v[k + 4], &s->set[n].v[k + 4], &s->set[n].v[k + 36]);
        }
        for (i = 0; i < 4.0f; i++) {
            /* column i of the grid, addressed from the block base as an integer */
            V4_003E6D30 *c = (V4_003E6D30 *)(i * 16 + (u32)s) + n * 0x61;
            for (k = 0; k < 3; k++) {
                vec_add_ab(&c[0x47 + k * 4], &c[0x47 + k * 4], &c[0x57 + k * 4]);
            }
        }
        for (j = 0; j < 4; j++) {
            s->set[n].sel[j] = ((V4_003E6D30 *)(s->idx[j] * 16 + (u32)s) + n * 0x61)[3];
        }
    }
}

void func_L20_003E6D30(u8 *m) {
    S_003E6D30 *s = *(S_003E6D30 **)(m + 0x68);

    step_003E6D30(s, 0);
    if (D_L20_001DF160 < s->count) {
        s->color = func_0038DBD8(D_L20_001DF108, D_L20_001DF104,
                                 (f32)(s->count - D_L20_001DF160) / (f32)(s->i8 - D_L20_001DF160));
    } else if (D_L20_001DF164 < s->count) {
        s->color = func_0038DBD8(D_L20_001DF10C, D_L20_001DF108,
                                 (f32)(s->count - D_L20_001DF164) / (f32)(D_L20_001DF160 - D_L20_001DF164));
    } else {
        s->color = 0;
    }
    step_003E6D30(s, 1);
}
/* localdecomp:end func_L20_003E6D30 */
