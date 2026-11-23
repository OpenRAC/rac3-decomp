#include "common.h"

/* NTSC-U counterpart of func_L20_003E6378 (src/levels/20_final_boss/L20_003E6150.c) */
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);
extern void func_003888F0(void *, void *, void *);

/* localdecomp:start func_L20_003E45C8 */
/* func_L20_003E45C8: builds the final boss's two lightning bolts (32 smoothed points each, plus
 * four branches of eight points) and spawns the
 * bolt effects (func_L01_0045FEC8) along them when the moby is at least 4 units from
 * D_L20_001E2E00_003E45C8.
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

extern s32 D_L20_001DF198_003E45C8;
__asm__(".extern D_L20_001DF198_003E45C8, 4");
extern s32 D_L20_001DF19C_003E45C8;
__asm__(".extern D_L20_001DF19C_003E45C8, 4");
extern f32 D_L20_001DF170_003E45C8;
__asm__(".extern D_L20_001DF170_003E45C8, 4");
extern f32 D_L20_001DF174_003E45C8;
__asm__(".extern D_L20_001DF174_003E45C8, 4");
extern f32 D_L20_001DF188_003E45C8;
__asm__(".extern D_L20_001DF188_003E45C8, 4");
extern s32 D_L20_001DF190_003E45C8;
__asm__(".extern D_L20_001DF190_003E45C8, 4");
extern s32 D_L20_001DF194;
__asm__(".extern D_L20_001DF194, 4");
extern s32 D_L20_001DF17C_003E45C8;
__asm__(".extern D_L20_001DF17C_003E45C8, 4");
extern s32 D_L20_001DF180_003E45C8;
__asm__(".extern D_L20_001DF180_003E45C8, 4");
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern void func_L01_00440A88(void *, f32, f32);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_00388BF0(void *, void *);
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388800(f32 *, f32 *);
extern u8 D_L20_001E2E00_003E45C8[];
__asm__(".extern D_L20_001E2E00_003E45C8, 16");

/* the vector class's assignment (an inline operator= in the original C++): *d = *p */
static __inline__ void cp_003E6378(V4_003E6378 *d, V4_003E6378 *p) {
    *d = *p;
}

void func_L20_003E45C8(void *pv) {
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

    s = *(S_003E6378 **)(p + 0x68);
    {
        s32 lo = D_L20_001DF198_003E45C8;
        s32 hi = D_L20_001DF19C_003E45C8;

        *(f32 *)(p + 0x1C) = 1.0f;
        s->i8 = s->count = func_0037E208(lo, hi);
    }
    h = func_0037E250(4.0f, 5.0f);
    {
        s32 i;

        for (i = 0; i < 32; i++) {
            f32 d = i / 31.0f;

            d = (0.5f - d) * h;

            if (i < 3 || i > 28) {
                qzero(&pos[i]);
                qzero(&vel[i]);
            } else {
                func_L01_00440A88(&pos[i], 0.0f, D_L20_001DF170_003E45C8);
                func_L01_00440A88(&vel[i], 0.0f, D_L20_001DF174_003E45C8 * 0.016666668f);
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
                func_003886E8(&s->set[0].v[j], &t, 0.333f);
                vec_add_ba(&t, &vel[j - 1], &vel[j]);
                vec_add_ba(&t, &t, &vel[j + 1]);
                func_003886E8(&s->set[0].v[j + 32], &t, 0.333f);
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
                func_003886E8(&s->set[1].v[j], &t, 0.333f);
                vec_add_ba(&t, &vel[j - 1], &vel[j]);
                vec_add_ba(&t, &t, &vel[j + 1]);
                func_003886E8(&s->set[1].v[j + 32], &t, 0.333f);
            }
        }
    }
    {
        s32 k;

        for (k = 0; k < 4; k++) {
            s32 n;

            func_L01_00440A88(&t, D_L20_001DF170_003E45C8, D_L20_001DF170_003E45C8);
            n = (s32)func_0037E250(k * 6.0f, (k + 1) * 6.0f) + 4;
            s->idx[k] = n;
            cp_003E6378(&s->set[0].w[0][k], &s->set[0].v[n]);
            cp_003E6378(&s->set[0].w[4][k], &s->set[0].v[n + 32]);
            {
                s32 m;

                for (m = 1; m < 4; m++) {
                    func_L01_00440A88(&r, 0.1f, 0.1f);
                    func_L01_00440A88(&s->set[0].w[m + 4][k], 0.0f, D_L20_001DF174_003E45C8 * 0.016666668f);
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

            func_L01_00440A88(&t, D_L20_001DF170_003E45C8, D_L20_001DF170_003E45C8);
            n = (s32)func_0037E250(l * 6.0f, (l + 1) * 6.0f) + 4;
            s->idx[l] = n;
            cp_003E6378(&s->set[1].w[0][l], &s->set[1].v[n]);
            cp_003E6378(&s->set[1].w[4][l], &s->set[1].v[n + 32]);
            {
                s32 m;

                for (m = 1; m < 4; m++) {
                    func_L01_00440A88(&r, 0.1f, 0.1f);
                    func_L01_00440A88(&s->set[1].w[m + 4][l], 0.0f, D_L20_001DF174_003E45C8 * 0.016666668f);
                    vec_add_ab(&s->set[1].w[m][l], &s->set[1].w[m - 1][l], &t);
                    vec_add_ba(&s->set[1].w[m][l], &s->set[1].w[m][l], &r);
                }
            }
        }
    }
    if (func_00388800((f32 *)(p + 0x10), (f32 *)D_L20_001E2E00_003E45C8) >= 4.0f) {
        s->set[0].ang.z = *(f32 *)(p + 0xF8);
        s->set[0].ang.y = *(f32 *)(p + 0xF4);
        s->set[0].ang.y += func_L01_00440918(0.0f, 30.0f) * 0.017453292f;
        s->set[0].ang.x = func_0037E2A8();
        func_00388BF0(&x, &s->set[0].ang);
        cp_003E6378(&w, (V4_003E6378 *)(p + 0x10));
        {
            s32 i;

            for (i = 0; i < 32; i += 8) {
                s32 col;

                func_003888F0(&t, &s->set[0].v[i], &x);
                cp_003E6378(&r, &s->set[0].v[i + 32]);
                r.w = D_L20_001DF188_003E45C8;
                col = func_0037E1D8(2) ? D_L20_001DF190_003E45C8 : D_L20_001DF194;
                func_L01_0045FEC8(&t, &r, &r, D_L20_001DF17C_003E45C8, D_L20_001DF180_003E45C8, i >> 1, 15,
                                  func_0037E1D8(10) + 20, col);
            }
        }
        {
            s32 m;

            for (m = 0; m < 2; m++) {
                s32 col;

                func_003888F0(&t, &s->set[0].w[3][m], &x);
                cp_003E6378(&r, &s->set[0].w[7][m]);
                r.w = D_L20_001DF188_003E45C8;
                col = func_0037E1D8(2) ? D_L20_001DF190_003E45C8 : D_L20_001DF194;
                func_L01_0045FEC8(&t, &r, &r, D_L20_001DF17C_003E45C8, D_L20_001DF180_003E45C8, s->idx[m] >> 1, 15,
                                  func_0037E1D8(10) + 20, D_L20_001DF194);
            }
        }
    }
    if (func_00388800((f32 *)(p + 0x10), (f32 *)D_L20_001E2E00_003E45C8) >= 4.0f) {
        s->set[1].ang.z = *(f32 *)(p + 0xF8);
        s->set[1].ang.y = *(f32 *)(p + 0xF4);
        s->set[1].ang.y += func_L01_00440918(0.0f, 30.0f) * 0.017453292f;
        s->set[1].ang.x = func_0037E2A8();
        func_00388BF0(&t, &s->set[1].ang);
        cp_003E6378(&y, (V4_003E6378 *)(p + 0x10));
        {
            s32 i;

            for (i = 0; i < 32; i += 8) {
                s32 col;

                func_003888F0(&z, &s->set[1].v[i], &t);
                cp_003E6378(&w, &s->set[1].v[i + 32]);
                w.w = D_L20_001DF188_003E45C8;
                col = func_0037E1D8(2) ? D_L20_001DF190_003E45C8 : D_L20_001DF194;
                func_L01_0045FEC8(&z, &w, &w, D_L20_001DF17C_003E45C8, D_L20_001DF180_003E45C8, i >> 1, 15,
                                  func_0037E1D8(10) + 20, col);
            }
        }
        {
            s32 m;

            for (m = 0; m < 2; m++) {
                s32 col;

                func_003888F0(&z, &s->set[1].w[3][m], &t);
                cp_003E6378(&w, &s->set[1].w[7][m]);
                w.w = D_L20_001DF188_003E45C8;
                col = func_0037E1D8(2) ? D_L20_001DF190_003E45C8 : D_L20_001DF194;
                func_L01_0045FEC8(&z, &w, &w, D_L20_001DF17C_003E45C8, D_L20_001DF180_003E45C8, s->idx[m] >> 1, 15,
                                  func_0037E1D8(10) + 20, D_L20_001DF194);
            }
        }
    }
}
/* localdecomp:end func_L20_003E45C8 */
