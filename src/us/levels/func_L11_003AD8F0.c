#include "common.h"

/* NTSC-U counterpart of func_L11_003AF6B8 (src/levels/11_obani_moons/L11_003AE1B0.c) */
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
extern f32 func_00388800(void *, void *);
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_0044E010(void *, void *, s32);
extern void func_00388830(void *, void *, f32);
extern void func_L11_003AD8F0(u8 *);
extern void func_L01_0044E010(void *, void *, s32);
extern s32 func_00388758(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L11_003AD8F0(u8 *);
extern void func_L01_0044E010(void *, void *, s32);
extern s32 func_00388758(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_L01_00440918(f32, f32);
extern s32 func_0037E1D8(s32);

/* localdecomp:start func_L11_003AD8F0 */
typedef struct Obj_3AF6B8 {
    vu0_v4 pos;
    u8 pad10[0x18 - 0x10];
    f32 f18;
    s32 f1C;
    s32 f20;
    u8 f24[0x30 - 0x24];
    f32 f30;
    f32 f34;
    f32 f38;
    u8 pad3C[0x40 - 0x3C];
    s32 f40;
} Obj_3AF6B8;

__asm__(".extern D_L11_001DE210, 4");
__asm__(".extern D_L11_001DE214, 4");
__asm__(".extern D_L11_001DE1E8_003AD8F0, 4");
__asm__(".extern D_L11_001DE1EC_003AD8F0, 4");
__asm__(".extern D_L11_001DE200, 4");
extern s32 D_L11_001DE210;
extern s32 D_L11_001DE214;
extern f32 D_L11_001DE1E8_003AD8F0;
extern f32 D_L11_001DE1EC_003AD8F0;
extern f32 D_L11_001DE200;
extern vu0_v4 D_L11_002A2820_003AD8F0[][32];
extern vu0_v4 D_L11_002A4020_003AD8F0[][32];
extern vu0_v4 D_L11_002A5820_003AD8F0[][4][4];
extern vu0_v4 D_L11_002A6420_003AD8F0[][4][4];
extern u8 D_L11_001E1700_003AD8F0[];
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00440A88(void *, f32, f32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388800(void *, void *);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E2A8();
extern void func_00388BF0(void *, void *);
extern void func_L01_0044E010(void *, void *, s32);
extern s32 func_00388758(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003BF360(void *, void *);
extern void func_003888F0(void *, void *, void *);
extern s32 func_0037E1D8(s32);

static __inline__ void vcopy_3AF6B8(vu0_v4 *d, vu0_v4 *s)
{
    *(vu0_q *)d = *(vu0_q *)s;
}

void func_L11_003AD8F0(u8 *arg)
{
    vu0_v4 A[32];
    vu0_v4 B[32];
    vu0_v4 t0;
    vu0_v4 t1;
    vu0_v4 m[4];
    vu0_v4 c;
    Obj_3AF6B8 *v;
    s32 r;
    s32 n1;
    s32 n2;
    f32 w;
    f32 f;
    s32 i;
    s32 p;
    s32 q;
    s32 j;
    s32 jj;
    s32 k;
    s32 kk;
    vu0_q row;

    n1 = D_L11_001DE210;
    n2 = D_L11_001DE214;
    *(f32 *)(arg + 0x1C) = 1.0f;
    v = *(Obj_3AF6B8 **)(arg + 0x68);
    r = func_0037E208(n1, n2);
    v->f1C = r;
    v->f20 = r;
    w = func_0037E250(v->f18 * 1.9f, v->f18 * 2.1f);
    for (i = 0; i < 32; i++) {
        f = (f32)i / 31.0f;
        f = (0.5f - f) * w;
        if (i < 3 || i > 28) {
            qzero(&A[i]);
            qzero(&B[i]);
        } else {
            func_L01_00440A88(&A[i], 0.0f, D_L11_001DE1E8_003AD8F0);
            func_L01_00440A88(&B[i], 0.0f, D_L11_001DE1EC_003AD8F0 * 0.0166666675f);
        }
        A[i].w = 1.0f;
        A[i].y += f;
    }
    for (p = 0; p < 32; p++) {
        if (p == 0 || p == 31) {
            vcopy_3AF6B8(&D_L11_002A2820_003AD8F0[v->f40][p], &A[p]);
            vcopy_3AF6B8(&D_L11_002A4020_003AD8F0[v->f40][p], &B[p]);
        } else {
            vec_add_ab(&t0, &A[p - 1], &A[p]);
            vec_add_ba(&t0, &t0, &A[p + 1]);
            func_003886E8(&D_L11_002A2820_003AD8F0[v->f40][p], &t0, 0.333f);
            vec_add_ba(&t0, &B[p - 1], &B[p]);
            vec_add_ba(&t0, &t0, &B[p + 1]);
            func_003886E8(&D_L11_002A4020_003AD8F0[v->f40][p], &t0, 0.333f);
        }
    }
    for (q = 0; q < 4; q++) {
        func_L01_00440A88(&t0, D_L11_001DE1E8_003AD8F0, D_L11_001DE1E8_003AD8F0);
        k = (s32)func_0037E250((f32)q * 6.0f, (f32)(q + 1) * 6.0f) + 4;
        v->f24[q] = k;
        vcopy_3AF6B8(&D_L11_002A5820_003AD8F0[v->f40][0][q], &D_L11_002A2820_003AD8F0[v->f40][k]);
        vcopy_3AF6B8(&D_L11_002A6420_003AD8F0[v->f40][0][q], &D_L11_002A4020_003AD8F0[v->f40][k]);
        for (j = 1; j < 4; j++) {
            func_L01_00440A88(&t1, 0.1f, 0.1f);
            func_L01_00440A88(&D_L11_002A6420_003AD8F0[v->f40][j][q], 0.0f, D_L11_001DE1EC_003AD8F0 * 0.0166666675f);
            vec_add_ba(&D_L11_002A5820_003AD8F0[v->f40][j][q], &D_L11_002A5820_003AD8F0[v->f40][j - 1][q], &t0);
            vec_add_ba(&D_L11_002A5820_003AD8F0[v->f40][j][q], &D_L11_002A5820_003AD8F0[v->f40][j][q], &t1);
        }
    }
    if (func_00388800(arg + 0x10, D_L11_001E1700_003AD8F0) >= 4.0f) {
        v->f38 = *(f32 *)(arg + 0xF8);
        v->f34 = *(f32 *)(arg + 0xF4);
        v->f34 += func_L01_00440918(0.0f, 30.0f) * 0.017453292f;
        v->f30 = func_0037E2A8();
        func_00388BF0(m, &v->f30);
        row = *(vu0_q *)&v->pos;
        *(vu0_q *)&m[0] = row;
        func_L01_0044E010(arg, &t0, 1);
        row = *(vu0_q *)&t0;
        *(vu0_q *)&m[2] = row;
        func_00388758(&m[1], &m[0], &m[2]);
        func_00388830(&m[0], &m[0], 1.0f);
        func_00388830(&m[1], &m[1], 1.0f);
        func_00388830(&m[2], &m[2], 1.0f);
        row = *(vu0_q *)(arg + 0x10);
        *(vu0_q *)&m[3] = row;
        func_003BF360(m, &v->f30);
        for (kk = 0; kk < 32; kk += 8) {
            func_003888F0(&t1, &D_L11_002A2820_003AD8F0[v->f40][kk], m);
            vcopy_3AF6B8(&c, &D_L11_002A4020_003AD8F0[v->f40][kk]);
            c.w = D_L11_001DE200;
            func_0037E1D8(2);
        }
        for (jj = 0; jj < 2; jj++) {
            func_003888F0(&c, &D_L11_002A5820_003AD8F0[v->f40][3][jj], m);
            vcopy_3AF6B8(&t1, &D_L11_002A6420_003AD8F0[v->f40][3][jj]);
            t1.w = D_L11_001DE200;
            func_0037E1D8(2);
        }
    }
}
/* localdecomp:end func_L11_003AD8F0 */
