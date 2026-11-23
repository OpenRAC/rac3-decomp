#include "common.h"

/* NTSC-U counterpart of func_L20_00336AA0 (src/levels/20_final_boss/L20_00336AA0.c) */
extern void func_L20_003364B8(void *);

/* localdecomp:start func_L20_003364B8 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00336AA0;

typedef struct {
    s32 type;                   /* 0x000 */
    u8 pad004[0xE];
    s16 n;                      /* 0x012 */
    u8 pad014[4];
    u8 pick[8];                 /* 0x018 */
    V_00336AA0 a[32];           /* 0x020 */
    V_00336AA0 b[32];           /* 0x220 */
    V_00336AA0 c[4][4];         /* 0x420 */
    V_00336AA0 d[4][4];         /* 0x520 */
    s32 n2;                     /* 0x620 */
    u8 pad624[0x2C];
    f32 rot[3];                 /* 0x650 */
} S_00336AA0;

typedef struct {
    u8 pad00[0x10];
    V_00336AA0 pos;             /* 0x10 */
    u8 pad20[0x48];
    S_00336AA0 *state;          /* 0x68 */
} M_00336AA0;

extern s32 D_001D545C;
extern s32 D_L20_001DCAEC_003364B8;
__asm__(".extern D_L20_001DCAEC_003364B8, 4");
extern s32 D_L20_001DCAF0;
__asm__(".extern D_L20_001DCAF0, 4");
extern f32 D_L20_001DCB50;
__asm__(".extern D_L20_001DCB50, 4");
extern f32 D_L20_001DCB54;
__asm__(".extern D_L20_001DCB54, 4");
extern s32 D_L20_001DCB5C;
__asm__(".extern D_L20_001DCB5C, 4");
extern s32 D_L20_001DCB60;
__asm__(".extern D_L20_001DCB60, 4");
extern f32 D_L20_001DCB68;
__asm__(".extern D_L20_001DCB68, 4");
extern s32 D_L20_001DCB70;
__asm__(".extern D_L20_001DCB70, 4");
extern s32 D_L20_001DCB74;
__asm__(".extern D_L20_001DCB74, 4");
extern f32 D_L20_001E2E00_003364B8[];
__asm__(".extern D_L20_001E2E00_003364B8, 16");
typedef struct {
    u8 pad00[0x74];
    f32 f74;
    f32 f78;
    u8 pad7C[4];
} E_00336AA0;

extern E_00336AA0 *D_L20_001E0380_003364B8;
__asm__(".extern D_L20_001E0380_003364B8, 16");
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00440A88(void *, f32, f32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388800(void *, void *);
extern f32 func_0037E2A8(void);
extern void func_00388BF0(void *, void *);
extern void func_003888F0(void *, void *, void *);
extern s32 func_0037E1D8(s32);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);

static __inline__ void copy_00336AA0(V_00336AA0 *d, V_00336AA0 *v)
{
    *(vu0_q *)d = *(vu0_q *)v;
}

void func_L20_003364B8(void *arg)
{
    S_00336AA0 *s;
    V_00336AA0 A[32];
    V_00336AA0 B[32];
    V_00336AA0 tmp;
    V_00336AA0 tmp2;
    V_00336AA0 mat[4];
    s32 i, j, k, l, m;
    M_00336AA0 *self = arg;
    s32 n, p;
    f32 scale, t;

    s = self->state;
    self->pos.w = 1.0f;
    s->n = func_0037E208(D_L20_001DCAEC_003364B8, D_L20_001DCAF0);
    s->n2 = s->n;
    if (D_001D545C == 0xD5 || D_001D545C == 0x10 || D_001D545C == 0x14)
        scale = func_0037E250(15.0f, 20.0f);
    else
        scale = func_0037E250(4.0f, 8.0f);

    for (i = 0; i < 32; i++) {
        t = (f32)i / 31.0f;
        t = (0.5f - t) * scale;
        if (i < 3 || i > 28) {
            qzero(&A[i]);
            qzero(&B[i]);
        } else {
            func_L01_00440A88(&A[i], 0.0f, D_L20_001DCB50);
            if (D_001D545C == 0x10 || D_001D545C == 0xD5)
                func_L01_00440A88(&B[i], 0.0f, 0.20000002f);
            else
                func_L01_00440A88(&B[i], 0.0f, D_L20_001DCB54 * 0.016666668f);
        }
        A[i].w = 1.0f;
        A[i].y += t;
    }

    for (j = 0; j < 32; j++) {
        if (j == 0 || j == 31) {
            copy_00336AA0(&s->a[j], &A[j]);
            copy_00336AA0(&s->b[j], &B[j]);
        } else {
            vec_add_ab(&tmp, &A[j - 1], &A[j]);
            vec_add_ab(&tmp, &tmp, &A[j + 1]);
            func_003886E8(&s->a[j], &tmp, 0.333f);
            vec_add_ba(&tmp, &B[j - 1], &B[j]);
            vec_add_ba(&tmp, &tmp, &B[j + 1]);
            func_003886E8(&s->b[j], &tmp, 0.333f);
        }
    }

    for (n = 0; n < 4; n++) {
        if (D_001D545C == 0xD5 || D_001D545C == 0x10)
            func_L01_00440A88(&tmp, 1.0f, 1.0f);
        else
            func_L01_00440A88(&tmp, D_L20_001DCB50, D_L20_001DCB50);
        m = (s32)func_0037E250((f32)n * 6.0f, (f32)(n + 1) * 6.0f) + 4;
        s->pick[n] = m;
        copy_00336AA0(&s->c[0][n], &s->a[m]);
        copy_00336AA0(&s->d[0][n], &s->b[m]);
        for (k = 1; k < 4; k++) {
            func_L01_00440A88(&tmp2, 0.1f, 0.1f);
            if (D_001D545C == 0xD5 || D_001D545C == 0x10)
                func_L01_00440A88(&s->d[k][n], 0.0f, 0.20000002f);
            else
                func_L01_00440A88(&s->d[k][n], 0.0f, D_L20_001DCB54 * 0.016666668f);
            vec_add_ab(&s->c[k][n], &s->c[k - 1][n], &tmp);
            vec_add_ab(&s->c[k][n], &s->c[k][n], &tmp2);
        }
    }

    if (func_00388800(&self->pos, D_L20_001E2E00_003364B8) >= 4.0f) {
        s->rot[2] = D_L20_001E0380_003364B8[s->type].f78;
        s->rot[1] = D_L20_001E0380_003364B8[s->type].f74;
        s->rot[0] = func_0037E2A8();
        func_00388BF0(mat, s->rot);
        mat[3] = self->pos;
        for (l = 0; l < 32; l += 8) {
            s32 color;
            func_003888F0(&tmp, &s->a[l], mat);
            tmp2 = s->b[l];
            tmp2.w = D_L20_001DCB68;
            color = func_0037E1D8(2) ? D_L20_001DCB70 : D_L20_001DCB74;
            func_L01_0045FEC8(&tmp, &tmp2, &tmp2, D_L20_001DCB5C, D_L20_001DCB60, l >> 1, 15, (func_0037E1D8(10) + 20), color);
        }
        for (p = 0; p < 2; p++) {
            s32 color;
            func_003888F0(&tmp, &s->c[3][p], mat);
            tmp2 = s->d[3][p];
            tmp2.w = D_L20_001DCB68;
            color = func_0037E1D8(2) ? D_L20_001DCB70 : D_L20_001DCB74;
            func_L01_0045FEC8(&tmp, &tmp2, &tmp2, D_L20_001DCB5C, D_L20_001DCB60, s->pick[p] >> 1, 15, (func_0037E1D8(10) + 20), D_L20_001DCB74);
        }
    }
}
/* localdecomp:end func_L20_003364B8 */
