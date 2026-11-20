#include "common.h"

/* declared by functions of L20_003368E0.c, which this file was cut from */
extern void func_L20_00336AA0(void *);

/* localdecomp:start func_L20_00336AA0 */
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
extern s32 D_L20_001DCAAC;
__asm__(".extern D_L20_001DCAAC, 4");
extern s32 D_L20_001DCAB0;
__asm__(".extern D_L20_001DCAB0, 4");
extern f32 D_L20_001DCB10;
__asm__(".extern D_L20_001DCB10, 4");
extern f32 D_L20_001DCB14;
__asm__(".extern D_L20_001DCB14, 4");
extern s32 D_L20_001DCB1C;
__asm__(".extern D_L20_001DCB1C, 4");
extern s32 D_L20_001DCB20;
__asm__(".extern D_L20_001DCB20, 4");
extern f32 D_L20_001DCB28;
__asm__(".extern D_L20_001DCB28, 4");
extern s32 D_L20_001DCB30;
__asm__(".extern D_L20_001DCB30, 4");
extern s32 D_L20_001DCB34;
__asm__(".extern D_L20_001DCB34, 4");
extern f32 D_L20_001E2E00[];
__asm__(".extern D_L20_001E2E00, 16");
typedef struct {
    u8 pad00[0x74];
    f32 f74;
    f32 f78;
    u8 pad7C[4];
} E_00336AA0;

extern E_00336AA0 *D_L20_001E0380;
__asm__(".extern D_L20_001E0380, 16");
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_00382538(void);
extern void func_0038D328(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern s32 func_00382468(s32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);

static __inline__ void copy_00336AA0(V_00336AA0 *d, V_00336AA0 *v)
{
    *(vu0_q *)d = *(vu0_q *)v;
}

void func_L20_00336AA0(void *arg)
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
    s->n = func_00382498((D_L20_001DCAAC * 5 + 2) / 6, (D_L20_001DCAB0 * 5 + 2) / 6);
    s->n2 = s->n;
    if (D_001D545C == 0xD5 || D_001D545C == 0x10 || D_001D545C == 0x14)
        scale = func_003824E0(15.0f, 20.0f);
    else
        scale = func_003824E0(4.0f, 8.0f);

    for (i = 0; i < 32; i++) {
        t = (f32)i / 31.0f;
        t = (0.5f - t) * scale;
        if (i < 3 || i > 28) {
            qzero(&A[i]);
            qzero(&B[i]);
        } else {
            func_L01_00443B88(&A[i], 0.0f, D_L20_001DCB10);
            if (D_001D545C == 0x10 || D_001D545C == 0xD5)
                func_L01_00443B88(&B[i], 0.0f, 0.24000001f);
            else
                func_L01_00443B88(&B[i], 0.0f, D_L20_001DCB14 * 0.020000001f);
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
            func_0038CE20(&s->a[j], &tmp, 0.333f);
            vec_add_ba(&tmp, &B[j - 1], &B[j]);
            vec_add_ba(&tmp, &tmp, &B[j + 1]);
            func_0038CE20(&s->b[j], &tmp, 0.333f);
        }
    }

    for (n = 0; n < 4; n++) {
        if (D_001D545C == 0xD5 || D_001D545C == 0x10)
            func_L01_00443B88(&tmp, 1.0f, 1.0f);
        else
            func_L01_00443B88(&tmp, D_L20_001DCB10, D_L20_001DCB10);
        m = (s32)func_003824E0((f32)n * 6.0f, (f32)(n + 1) * 6.0f) + 4;
        s->pick[n] = m;
        copy_00336AA0(&s->c[0][n], &s->a[m]);
        copy_00336AA0(&s->d[0][n], &s->b[m]);
        for (k = 1; k < 4; k++) {
            func_L01_00443B88(&tmp2, 0.1f, 0.1f);
            if (D_001D545C == 0xD5 || D_001D545C == 0x10)
                func_L01_00443B88(&s->d[k][n], 0.0f, 0.24000001f);
            else
                func_L01_00443B88(&s->d[k][n], 0.0f, D_L20_001DCB14 * 0.020000001f);
            vec_add_ab(&s->c[k][n], &s->c[k - 1][n], &tmp);
            vec_add_ab(&s->c[k][n], &s->c[k][n], &tmp2);
        }
    }

    if (func_0038CF38(&self->pos, D_L20_001E2E00) >= 4.0f) {
        s->rot[2] = D_L20_001E0380[s->type].f78;
        s->rot[1] = D_L20_001E0380[s->type].f74;
        s->rot[0] = func_00382538();
        func_0038D328(mat, s->rot);
        mat[3] = self->pos;
        for (l = 0; l < 32; l += 8) {
            s32 color;
            func_0038D028(&tmp, &s->a[l], mat);
            tmp2 = s->b[l];
            tmp2.w = D_L20_001DCB28;
            color = func_00382468(2) ? D_L20_001DCB30 : D_L20_001DCB34;
            func_L01_00463378(&tmp, &tmp2, &tmp2, D_L20_001DCB1C, D_L20_001DCB20, l >> 1, 15, ((func_00382468(10) + 20) * 5 + 2) / 6, color);
        }
        for (p = 0; p < 2; p++) {
            s32 color;
            func_0038D028(&tmp, &s->c[3][p], mat);
            tmp2 = s->d[3][p];
            tmp2.w = D_L20_001DCB28;
            color = func_00382468(2) ? D_L20_001DCB30 : D_L20_001DCB34;
            func_L01_00463378(&tmp, &tmp2, &tmp2, D_L20_001DCB1C, D_L20_001DCB20, s->pick[p] >> 1, 15, ((func_00382468(10) + 20) * 5 + 2) / 6, D_L20_001DCB34);
        }
    }
}
/* localdecomp:end func_L20_00336AA0 */
