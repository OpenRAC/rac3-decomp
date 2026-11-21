#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef int s64_003AFF80 __attribute__((mode(DI)));

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L01_003B1350 */
void func_L01_003B1350(void) {

}
/* localdecomp:end func_L01_003B1350 */

INCLUDE_ASM("asm/levels", func_L01_003B1358);

/* localdecomp:start func_L01_003B1750 */

extern u8 *func_003C24B0(s32, s32);

u8 *func_L01_003B1750(u8 *parent, s128 *a, s128 *b, s32 a3, s32 t0, s32 t1, s32 t2, f32 fa, f32 fb) {
    s128 v[2];
    u8 *p;
    u8 *q;

    v[0] = *a;
    v[1] = *b;
    p = func_003C24B0(6597, 128);

    if (p != 0) {
        p[48] = 255;
        *(s16 *)(p + 50) = 255;
        p[49] = 1;
        q = *(u8 **)(p + 104);
        p[32] = 0;
        if (parent != 0) {
            *(u8 **)(p + 184) = parent;
            *(s64_003AFF80 *)(p + 56) = *(s64_003AFF80 *)(parent + 56);
        }
        *(s128 *)(p + 16) = *(s128 *)q;
        *(s128 *)q = v[0];
        *(s128 *)(q + 32) = v[1];
        *(f32 *)(q + 84) = fb;
        *(f32 *)(q + 60) = fa;
        *(s32 *)(q + 68) = a3;
        *(s32 *)(q + 72) = t0;
        *(s32 *)(q + 76) = t1;
        *(s32 *)(q + 80) = t2;
        *(s32 *)(q + 56) = 0;
        *(s32 *)(q + 52) = 0;
    }
    return p;
}
/* localdecomp:end func_L01_003B1750 */

/* localdecomp:start func_L01_003B1848 */
extern void func_L01_003B1870(char *, void *);

void func_L01_003B1848(char *arg0)
{
    u128_t v;
    v = **(u128_t **)(arg0 + 0x68);
    func_L01_003B1870(arg0, &v);
}
/* localdecomp:end func_L01_003B1848 */

/* localdecomp:start func_L01_003B1870 */
#include "vu0.h"

typedef struct {
    vu0_v4 p0;
    vu0_v4 p1;
    u8 pad20[0x18];
    f32 f38;
    u8 pad3C[8];
    s32 w44;
    s32 w48;
    u8 pad4C[8];
    f32 f54;
} S_003B1870;

typedef struct {
    vu0_v4 m[4];
    u32 col[4];
    f32 uv[8];
    long l70;
    long l78;
    long l80;
    long l88;
} Pkt_003B1870;

extern vu0_v4 D_L01_001E29C0;
extern f32 D_L01_001DE610[2];
extern f32 D_L01_001DE614[2];
extern long func_00389598(s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_003D2DA0(void *, s32, s32);

void func_L01_003B1870(char *arg0, void *arg1) {
    vu0_v4 v;
    Pkt_003B1870 P;
    vu0_v4 A;
    vu0_v4 B;
    vu0_v4 C;
    vu0_v4 X;
    vu0_v4 T;
    S_003B1870 *s;
    f32 f23;
    s32 i;
    s32 j;
    f32 *pu;
    f32 *pv;

    v = *(vu0_v4 *)arg1;
    s = *(S_003B1870 **)(arg0 + 0x68);
    f23 = s->f54;
    if (s->f38 > 84.0f) {
        f23 = f23 * (1.0f - (s->f38 - 84.0f) / 6.0f);
        if (f23 < 0.001f) {
            f23 = 0.001f;
        }
    }
    vec_sub_ba(&C, &s->p0, &s->p1);
    vec_sub_ba(&A, &s->p0, &D_L01_001E29C0);
    vec_sub_ba(&B, &s->p1, &D_L01_001E29C0);
    func_0038CE90(&A, &A, &C);
    func_0038CF68(&A, &A, (s->f54 + func_L01_00443A18(0.1f, 0.3f)) * f23);
    func_0038CE90(&B, &B, &C);
    func_0038CF68(&B, &B, (s->f54 + func_L01_00443A18(0.1f, 0.3f)) * f23);

    P.l78 = func_00389598(0x3E);
    P.l80 = 0x0000FF9000000260L;
    P.l88 = 0x0000003000000048L;
    P.l70 = 0;
    P.col[0] = P.col[1] = P.col[2] = P.col[3] = s->w44;
    pu = &P.uv[0];
    pv = &P.uv[1];
    for (i = 0; i < 4; i++) {
        pu[i * 2] = D_L01_001DE610[i * 2];
        pv[i * 2] = D_L01_001DE614[i * 2];
    }
    vec_sub_ba(&T, &s->p0, &A);
    P.m[0] = X = T;
    vec_add_ba(&T, &s->p0, &A);
    P.m[1] = X = T;
    vec_sub_ba(&T, &s->p1, &B);
    P.m[2] = X = T;
    vec_add_ba(&T, &s->p1, &B);
    P.m[3] = X = T;
    func_003D2DA0(&P, 0, 0);

    vec_sub_ba(&C, &s->p0, &s->p1);
    vec_sub_ba(&A, &s->p0, &D_L01_001E29C0);
    vec_sub_ba(&B, &s->p1, &D_L01_001E29C0);
    func_0038CE90(&A, &A, &C);
    func_0038CF68(&A, &A, (s->f54 * 0.5f + func_L01_00443A18(0.05f, 0.15f)) * f23);
    func_0038CE90(&B, &B, &C);
    func_0038CF68(&B, &B, (s->f54 * 0.5f + func_L01_00443A18(0.05f, 0.15f)) * f23);

    P.l78 = func_00389598(0x3F);
    P.l80 = 0x0000FF9000000260L;
    P.l88 = 0x0000003000000048L;
    P.l70 = 0;
    P.col[0] = P.col[1] = P.col[2] = P.col[3] = s->w48;
    for (j = 0; j < 4; j++) {
        pu[j * 2] = D_L01_001DE610[j * 2];
        pv[j * 2] = D_L01_001DE614[j * 2];
    }
    vec_sub_ba(&T, &s->p0, &A);
    P.m[0] = X = T;
    vec_add_ba(&T, &s->p0, &A);
    P.m[1] = X = T;
    vec_sub_ba(&T, &s->p1, &B);
    P.m[2] = X = T;
    vec_add_ba(&T, &s->p1, &B);
    P.m[3] = X = T;
    func_003D2DA0(&P, 0, 0);
}
/* localdecomp:end func_L01_003B1870 */

/* localdecomp:start func_L01_003B1D10 */
extern void func_L01_003303B8(s32, s32, s32, s32, s32, s32, s32, s32,
                          float, float, float, float,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_L01_003B1D10(s32 a, s32 b, s32 c) {
    func_L01_003303B8(a, 0, 5, 0, 5, 5, 0, 0,
                  0.4f, 0.0f, 0.0f, 0.0f,
                  0, 0, 0, 0, 0, 0, 0x10000, 0, c,
                  c, c, c, c, c, c, c, 0x3064FF, 0);
}
/* localdecomp:end func_L01_003B1D10 */

/* localdecomp:start func_L01_003B1DB8 */
void func_L01_003B1DB8(void) {

}
/* localdecomp:end func_L01_003B1DB8 */
