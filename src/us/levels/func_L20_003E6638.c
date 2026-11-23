#include "common.h"

/* NTSC-U counterpart of func_L20_003E84B0 (src/levels/20_final_boss/L20_003E7988.c) */
#include "vu0.h"
extern f32 func_00388800(f32 *, f32 *);
#include "vu0.h"
extern u8 D_L20_001E2E00_003E6638[];
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern void func_003886E8(void *, void *, f32);
extern void func_003888F0(void *, void *, void *);

/* localdecomp:start func_L20_003E6638 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E84B0;
typedef struct {
    u8 pad0[0x8];
    s32 i8;                 /* 0x08 */
    u8 padC[0x22 - 0xC];
    s16 count;              /* 0x22 */
    s32 color;              /* 0x24 */
    u8 idx[4];              /* 0x28 */
    u8 pad2C[4];
    struct {
        V4_003E84B0 pos[32];    /* +0x000 */
        V4_003E84B0 vel[32];    /* +0x200 */
        V4_003E84B0 g[8][4];    /* +0x400 */
        V4_003E84B0 rot;        /* +0x600 */
    } set[2];               /* 0x30, 0x640 */
} S_003E84B0;

extern s32 D_L20_001DF240_003E6638;
__asm__(".extern D_L20_001DF240_003E6638, 4");
extern s32 D_L20_001DF244;
__asm__(".extern D_L20_001DF244, 4");
extern f32 D_L20_001DF218_003E6638;
__asm__(".extern D_L20_001DF218_003E6638, 4");
extern f32 D_L20_001DF21C_003E6638;
__asm__(".extern D_L20_001DF21C_003E6638, 4");
extern f32 D_L20_001DF230_003E6638;
__asm__(".extern D_L20_001DF230_003E6638, 4");
extern s32 D_L20_001DF238;
__asm__(".extern D_L20_001DF238, 4");
extern s32 D_L20_001DF23C_003E6638;
__asm__(".extern D_L20_001DF23C_003E6638, 4");
extern s32 D_L20_001DF224_003E6638;
__asm__(".extern D_L20_001DF224_003E6638, 4");
extern s32 D_L20_001DF228_003E6638;
__asm__(".extern D_L20_001DF228_003E6638, 4");
extern u8 D_L20_001E2E00_003E6638[];
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00440A88(void *, f32, f32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388800(f32 *, f32 *);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E2A8(void);
extern void func_00388BF0(void *, void *);
extern void func_003888F0(void *, void *, void *);
extern s32 func_0037E1D8(s32);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);

static __inline__ void vcopy_003E84B0(V4_003E84B0 *d, V4_003E84B0 *s)
{
    *(vu0_q *)d = *(vu0_q *)s;
}

/* the two-set version of func_L11_003AF6B8 */
void func_L20_003E6638(u8 *p) {
    V4_003E84B0 a[32];
    V4_003E84B0 b[32];
    S_003E84B0 *s;
    s32 r;
    s32 n1;
    s32 n2;
    f32 h;
    f32 f;
    s32 i;
    s32 j0;
    s32 j1;
    s32 col0;
    s32 row0;
    s32 col1;
    s32 row1;
    s32 pt0;
    s32 br0;
    s32 pt1;
    s32 br1;

    s = *(S_003E84B0 **)(p + 0x68);
    n1 = D_L20_001DF240_003E6638;
    n2 = D_L20_001DF244;
    *(f32 *)(p + 0x1C) = 1.0f;
    r = func_0037E208(n1, n2);
    s->i8 = (s16)r;
    s->count = r;
    h = func_0037E250(4.0f, 5.0f);
    for (i = 0; i < 32; i++) {
        f = (f32)i / 31.0f;
        f = (0.5f - f) * h;
        if (i < 3 || i > 28) {
            qzero(&a[i]);
            qzero(&b[i]);
        } else {
            func_L01_00440A88(&a[i], 0.0f, D_L20_001DF218_003E6638);
            func_L01_00440A88(&b[i], 0.0f, D_L20_001DF21C_003E6638 * 0.016666668f);
        }
        a[i].w = 1.0f;
        a[i].y += f;
    }
    for (j0 = 0; j0 < 32; j0++) {
        V4_003E84B0 t;

        if (j0 == 0 || j0 == 31) {
            vcopy_003E84B0(&s->set[0].pos[j0], &a[j0]);
            vcopy_003E84B0(&s->set[0].vel[j0], &b[j0]);
        } else {
            vec_add_ab(&t, &a[j0 - 1], &a[j0]);
            vec_add_ab(&t, &t, &a[j0 + 1]);
            func_003886E8(&s->set[0].pos[j0], &t, 0.333f);
            vec_add_ba(&t, &b[j0 - 1], &b[j0]);
            vec_add_ba(&t, &t, &b[j0 + 1]);
            func_003886E8(&s->set[0].vel[j0], &t, 0.333f);
        }
    }
    for (j1 = 0; j1 < 32; j1++) {
        V4_003E84B0 t;

        if (j1 == 0 || j1 == 31) {
            vcopy_003E84B0(&s->set[1].pos[j1], &a[j1]);
            vcopy_003E84B0(&s->set[1].vel[j1], &b[j1]);
        } else {
            vec_add_ab(&t, &a[j1 - 1], &a[j1]);
            vec_add_ab(&t, &t, &a[j1 + 1]);
            func_003886E8(&s->set[1].pos[j1], &t, 0.333f);
            vec_add_ba(&t, &b[j1 - 1], &b[j1]);
            vec_add_ba(&t, &t, &b[j1 + 1]);
            func_003886E8(&s->set[1].vel[j1], &t, 0.333f);
        }
    }
    {
        /* scratch vectors of the grids and of set 0's bolt (C++ block scope: freed for set 1's) */
        V4_003E84B0 t;
        V4_003E84B0 u;

        {
            for (col0 = 0; col0 < 4; col0++) {
                s32 k;

                func_L01_00440A88(&t, D_L20_001DF218_003E6638, D_L20_001DF218_003E6638);
                k = (s32)func_0037E250((f32)col0 * 6.0f, (f32)(col0 + 1) * 6.0f) + 4;
                s->idx[col0] = k;
                vcopy_003E84B0(&s->set[0].g[0][col0], &s->set[0].pos[k]);
                vcopy_003E84B0(&s->set[0].g[4][col0], &s->set[0].vel[k]);
                for (row0 = 1; row0 < 4; row0++) {
                    func_L01_00440A88(&u, 0.1f, 0.1f);
                    func_L01_00440A88(&s->set[0].g[row0 + 4][col0], 0.0f, D_L20_001DF21C_003E6638 * 0.016666668f);
                    vec_add_ab(&s->set[0].g[row0][col0], &s->set[0].g[row0 - 1][col0], &t);
                    vec_add_ab(&s->set[0].g[row0][col0], &s->set[0].g[row0][col0], &u);
                }
            }
            for (col1 = 0; col1 < 4; col1++) {
                s32 k;

                func_L01_00440A88(&t, D_L20_001DF218_003E6638, D_L20_001DF218_003E6638);
                k = (s32)func_0037E250((f32)col1 * 6.0f, (f32)(col1 + 1) * 6.0f) + 4;
                s->idx[col1] = k;
                vcopy_003E84B0(&s->set[1].g[0][col1], &s->set[1].pos[k]);
                vcopy_003E84B0(&s->set[1].g[4][col1], &s->set[1].vel[k]);
                for (row1 = 1; row1 < 4; row1++) {
                    func_L01_00440A88(&u, 0.1f, 0.1f);
                    func_L01_00440A88(&s->set[1].g[row1 + 4][col1], 0.0f, D_L20_001DF21C_003E6638 * 0.016666668f);
                    vec_add_ab(&s->set[1].g[row1][col1], &s->set[1].g[row1 - 1][col1], &t);
                    vec_add_ab(&s->set[1].g[row1][col1], &s->set[1].g[row1][col1], &u);
                }
            }
        }
        if (func_00388800((f32 *)(p + 0x10), (f32 *)D_L20_001E2E00_003E6638) >= 4.0f) {
            V4_003E84B0 m[4];

            s->set[0].rot.z = *(f32 *)(p + 0xF8);
            s->set[0].rot.y = *(f32 *)(p + 0xF4);
            s->set[0].rot.y += func_L01_00440918(0.0f, 30.0f) * 0.017453292f;
            s->set[0].rot.x = func_0037E2A8();
            func_00388BF0(m, &s->set[0].rot);
            m[3] = *(V4_003E84B0 *)(p + 0x10);
            for (pt0 = 0; pt0 < 32; pt0 += 8) {
                s32 color;

                func_003888F0(&t, &s->set[0].pos[pt0], m);
                vcopy_003E84B0(&u, &s->set[0].vel[pt0]);
                u.w = D_L20_001DF230_003E6638;
                color = func_0037E1D8(2) ? D_L20_001DF238 : D_L20_001DF23C_003E6638;
                func_L01_0045FEC8(&t, &u, &u, D_L20_001DF224_003E6638, D_L20_001DF228_003E6638, pt0 >> 1, 15,
                                  (func_0037E1D8(10) + 20), color);
            }
            for (br0 = 0; br0 < 2; br0++) {
                s32 color;

                func_003888F0(&t, &s->set[0].g[3][br0], m);
                vcopy_003E84B0(&u, &s->set[0].g[7][br0]);
                u.w = D_L20_001DF230_003E6638;
                color = func_0037E1D8(2) ? D_L20_001DF238 : D_L20_001DF23C_003E6638;   /* unused: branches pass D_L20_001DF23C_003E6638 */
                func_L01_0045FEC8(&t, &u, &u, D_L20_001DF224_003E6638, D_L20_001DF228_003E6638, s->idx[br0] >> 1, 15,
                                  (func_0037E1D8(10) + 20), D_L20_001DF23C_003E6638);
            }
        }
    }
    if (func_00388800((f32 *)(p + 0x10), (f32 *)D_L20_001E2E00_003E6638) >= 4.0f) {
        V4_003E84B0 m[4];
        V4_003E84B0 t;
        V4_003E84B0 u;

        s->set[1].rot.z = *(f32 *)(p + 0xF8);
        s->set[1].rot.y = *(f32 *)(p + 0xF4);
        s->set[1].rot.y += func_L01_00440918(0.0f, 30.0f) * 0.017453292f;
        s->set[1].rot.x = func_0037E2A8();
        func_00388BF0(m, &s->set[1].rot);
        m[3] = *(V4_003E84B0 *)(p + 0x10);
        for (pt1 = 0; pt1 < 32; pt1 += 8) {
            s32 color;

            func_003888F0(&t, &s->set[1].pos[pt1], m);
            vcopy_003E84B0(&u, &s->set[1].vel[pt1]);
            u.w = D_L20_001DF230_003E6638;
            color = func_0037E1D8(2) ? D_L20_001DF238 : D_L20_001DF23C_003E6638;
            func_L01_0045FEC8(&t, &u, &u, D_L20_001DF224_003E6638, D_L20_001DF228_003E6638, pt1 >> 1, 15,
                              (func_0037E1D8(10) + 20), color);
        }
        for (br1 = 0; br1 < 2; br1++) {
            s32 color;

            func_003888F0(&t, &s->set[1].g[3][br1], m);
            vcopy_003E84B0(&u, &s->set[1].g[7][br1]);
            u.w = D_L20_001DF230_003E6638;
            color = func_0037E1D8(2) ? D_L20_001DF238 : D_L20_001DF23C_003E6638;   /* unused: branches pass D_L20_001DF23C_003E6638 */
            func_L01_0045FEC8(&t, &u, &u, D_L20_001DF224_003E6638, D_L20_001DF228_003E6638, s->idx[br1] >> 1, 15,
                              (func_0037E1D8(10) + 20), D_L20_001DF23C_003E6638);
        }
    }
}
/* localdecomp:end func_L20_003E6638 */
