#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L05_003CA628);

/* localdecomp:start func_L05_003CA8F0 */
__asm__(".extern D_L05_001DEDF8, 4");
__asm__(".extern D_L05_001DEDFC, 4");
__asm__(".extern D_L05_001DEE00, 4");
__asm__(".extern D_L05_001DEE04, 4");
__asm__(".extern D_L05_001DEE08, 4");
__asm__(".extern D_L05_001DEE0C, 4");
__asm__(".extern D_L05_001DEE10, 4");
__asm__(".extern D_L05_001DEE14, 4");
__asm__(".extern D_L05_001DEE18, 4");
typedef struct {
    vu0_v4 p[4];
    u32 col[4];
    f32 uv[8];
    u8 pad70[0x20];
} Quad_3CA8F0;
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern vu0_v4 D_L05_001E2680;
extern s32 D_L05_001DEDF8;
extern s32 D_L05_001DEDFC;
extern s32 D_L05_001DEE00;
extern s32 D_L05_001DEE04;
extern f32 D_L05_001DEE08;
extern s32 D_L05_001DEE0C;
extern s32 D_L05_001DEE10;
extern s32 D_L05_001DEE14;
extern s32 D_L05_001DEE18;

void func_L05_003CA8F0(u8 *obj) {
    Quad_3CA8F0 q;
    vu0_v4 P;
    vu0_v4 Q;
    vu0_v4 D;
    vu0_v4 v[8];
    vu0_v4 W;
    vu0_v4 A;
    vu0_v4 S0;
    vu0_v4 S1;
    vu0_v4 S2;
    u8 *sub;
    f32 *fp;
    f32 t;
    f32 k;
    s32 i;
    s32 c;
    u8 st;

    sub = *(u8 **)(obj + 0x68);
    if (obj == 0) {
        return;
    }
    st = obj[0x20];
    if (st == 0xFE) {
        return;
    }
    if (st == 0xFD) {
        return;
    }
    if (sub == 0) {
        return;
    }
    P = *(vu0_v4 *)(obj + 0x10);
    if (*(s32 *)(sub + 0x30) != 0) {
        Q = *(vu0_v4 *)(sub + 0x10);
        vec_sub_ab(&D, &Q, &P);
    } else {
        func_0038CF68(&D, sub, *(f32 *)(sub + 0x20));
        vec_add_ab(&Q, &P, &D);
    }
    k = (f32)*(s32 *)(sub + 0x24) * *(f32 *)(sub + 0x28);

    func_003D93B0(&q, 0x17, 0, 0x80);
    q.uv[0] = 0.0f;
    q.uv[1] = 0.0f;
    q.uv[2] = 0.0f;
    q.uv[3] = 1.0f;
    q.uv[4] = 1.0f;
    q.col[1] = ((s32)(k * 64.0f) << 24) | 0x108080;
    q.col[0] = ((s32)(k * 64.0f) << 24) | 0x108080;
    q.col[3] = ((s32)(k * 64.0f) << 24) | 0x101080;
    q.col[2] = ((s32)(k * 64.0f) << 24) | 0x101080;
    q.uv[5] = 0.0f;
    q.uv[6] = 1.0f;
    q.uv[7] = 1.0f;
    fp = q.uv;
    for (i = 3; i >= 0; i--) {
        t = *fp - *(f32 *)(sub + 0x2C);
        *fp = t;
        if (t <= 7.0f) {
            *fp = t + 7.0f;
        }
        fp += 2;
    }
    t = *(f32 *)(sub + 0x2C) + 0.1f;
    *(f32 *)(sub + 0x2C) = t;
    if (4.0f <= t) {
        *(f32 *)(sub + 0x2C) = t - 4.0f;
    }

    vec_sub_ab(&W, obj + 0x10, &D_L05_001E2680);
    func_0038CE90(&A, &W, &D);
    func_0038CF68(&A, &A, 1.0f);
    func_0038CE20(&S0, &D, D_L05_001DEE08);
    func_0038CE20(&S1, &D, 1.0f - D_L05_001DEE08);
    func_0038CE20(&S2, &D, 0.5f);
    vec_add_ba(&S0, &S0, &P);
    vec_add_ab(&S1, &S1, &P);
    vec_add_ab(&S2, &S2, &P);
    vec_add_ab(&v[0], &P, &A);
    vec_sub_ba(&v[1], &P, &A);
    vec_add_ab(&v[2], &S0, &A);
    vec_sub_ba(&v[3], &S0, &A);
    vec_add_ab(&v[4], &S1, &A);
    vec_sub_ba(&v[5], &S1, &A);
    vec_add_ab(&v[6], &Q, &A);
    vec_sub_ba(&v[7], &Q, &A);

    q.p[0] = v[0];
    q.p[1] = v[1];
    q.p[2] = v[2];
    q.p[3] = v[3];
    q.col[0] = (D_L05_001DEE00 << 16) | (D_L05_001DEDFC << 8) | D_L05_001DEDF8;
    q.col[1] = (D_L05_001DEE00 << 16) | (D_L05_001DEDFC << 8) | D_L05_001DEDF8;
    q.col[2] = (D_L05_001DEE04 << 24) | (D_L05_001DEE00 << 16) | (D_L05_001DEDFC << 8) | D_L05_001DEDF8;
    q.col[3] = (D_L05_001DEE04 << 24) | (D_L05_001DEE00 << 16) | (D_L05_001DEDFC << 8) | D_L05_001DEDF8;
    func_003D2DA0(&q, 0, 0);

    q.p[0] = v[4];
    q.p[1] = v[5];
    q.col[0] = (D_L05_001DEE04 << 24) | (D_L05_001DEE00 << 16) | (D_L05_001DEDFC << 8) | D_L05_001DEDF8;
    q.col[1] = (D_L05_001DEE04 << 24) | (D_L05_001DEE00 << 16) | (D_L05_001DEDFC << 8) | D_L05_001DEDF8;
    func_003D2DA0(&q, 0, 0);

    q.p[2] = v[6];
    q.p[3] = v[7];
    q.col[2] = (D_L05_001DEE00 << 16) | (D_L05_001DEDFC << 8) | D_L05_001DEDF8;
    q.col[3] = (D_L05_001DEE00 << 16) | (D_L05_001DEDFC << 8) | D_L05_001DEDF8;
    func_003D2DA0(&q, 0, 0);

    func_003D93B0(&q, 0xE, 1, 0x80);
    c = ((s32)(k * 64.0f) << 24) | 0x40FF;
    q.uv[0] = 0.0f;
    q.uv[1] = 0.0f;
    q.uv[2] = 0.0f;
    q.uv[3] = 1.0f;
    q.uv[4] = 1.0f;
    q.uv[5] = 0.0f;
    q.uv[6] = 1.0f;
    q.uv[7] = 1.0f;
    q.col[3] = c;
    q.col[2] = c;
    q.col[1] = c;
    q.col[0] = c;
    func_0038CF68(&A, &A, 2.0f);
    vec_add_ba(&v[0], &P, &A);
    vec_sub_ba(&v[1], &P, &A);
    vec_add_ba(&v[2], &S2, &A);
    vec_sub_ba(&v[3], &S2, &A);
    vec_add_ba(&v[4], &Q, &A);
    vec_sub_ab(&v[5], &Q, &A);
    q.p[0] = v[0];
    q.p[1] = v[1];
    q.p[2] = v[2];
    q.p[3] = v[3];
    q.col[0] = (D_L05_001DEE14 << 16) | (D_L05_001DEE10 << 8) | D_L05_001DEE0C;
    q.col[1] = (D_L05_001DEE14 << 16) | (D_L05_001DEE10 << 8) | D_L05_001DEE0C;
    q.col[2] = (D_L05_001DEE18 << 24) | (D_L05_001DEE14 << 16) | (D_L05_001DEE10 << 8) | D_L05_001DEE0C;
    q.col[3] = (D_L05_001DEE18 << 24) | (D_L05_001DEE14 << 16) | (D_L05_001DEE10 << 8) | D_L05_001DEE0C;
    func_003D2DA0(&q, 0, 0);
    q.p[0] = v[4];
    q.p[1] = v[5];
    func_003D2DA0(&q, 0, 0);
}
/* localdecomp:end func_L05_003CA8F0 */
