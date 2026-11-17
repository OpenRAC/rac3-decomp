#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L14_003F7C70 */
typedef struct {
    s32 n0;
    s32 n;
    f32 depth;
    s32 fC;
    vu0_v4 pts[60];
    vu0_v4 nrm[60];
    vu0_v4 ctr[60];
    u8 pad0[0x20];
    f32 uv[60][2];
    u8 pad1[0x10];
    s32 col[60];
    u8 pad2[0x18];
    f32 r[2];
} S_3F7C70;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
void func_L14_003F7C70(S_3F7C70 *s, s32 col, s32 n, s32 fC, f32 r0, f32 r1, f32 depth) {
    vu0_v4 a;
    vu0_v4 b;
    s32 i;
    s32 odd;
    f32 ang;
    f32 r;
    s->n0 = n + 2;
    s->depth = depth;
    s->r[0] = r0;
    s->r[1] = r1;
    s->fC = fC;
    s->n = n + 6;
    for (i = 0; i < s->n; i++) {
        ang = (f32)i * 6.2831855f / (f32)(s->n - 2) + -3.1415927f;
        odd = i & 1;
        r = s->r[odd];
        s->pts[i].x = r * func_0038D098(ang);
        s->pts[i].y = r * func_0038D0B0(ang);
        s->pts[i].z = (f32)(-odd) * s->depth;
        if (i >= 2) {
            vec_sub_ab(&a, &s->pts[i - 2], &s->pts[i - 1]);
            func_0038CF68(&a, &a, 1.0f);
            vec_sub_ab(&b, &s->pts[i - 1], &s->pts[i]);
            func_0038CF68(&b, &b, 1.0f);
            func_0038CE90(&s->nrm[i], &a, &b);
            if (odd) {
                func_0038CE20(&s->nrm[i], &s->nrm[i], -1.0f);
            }
            func_0038CF68(&s->nrm[i], &s->nrm[i], 1.0f);
            vec_add_ab(&s->ctr[i], &s->pts[i - 2], &s->pts[i - 1]);
            vec_add_ab(&s->ctr[i], &s->ctr[i], &s->pts[i]);
            func_0038CE20(&s->ctr[i], &s->ctr[i], 0.33333334f);
        }
        s->col[i] = col;
        s->uv[i][0] = 0.5f;
        s->uv[i][1] = 0.5f;
    }
}
/* localdecomp:end func_L14_003F7C70 */

/* localdecomp:start func_L14_003F7EB8 */
extern vu0_v4 D_L14_001E20C0_v;
extern f32 func_0038CE68(void *, void *);
s32 func_L14_003F7EB8(S_3F7C70 *s, vu0_v4 *pos, s32 *first, s32 *idx, s32 *last, f32 scale) {
    vu0_v4 p;
    vu0_v4 v;
    vu0_v4 *pp;
    s32 i;
    s32 found;
    f32 prev;
    f32 cur;
    pp = &p;
    *pp = *pos;
    found = 0;
    prev = -2.0f;
    *first = 0;
    *last = s->n0 + 2;
    for (i = 0; i < s->n0 + 2; i++) {
        v.x = scale * *(f32 *)((u8 *)s + i * 16 + 0x7B0);
        v.y = scale * *(f32 *)((u8 *)s + i * 16 + 0x7B4);
        v.z = *(f32 *)((u8 *)s + i * 16 + 0x7B8);
        vec_sub_ba(&v, &v, &D_L14_001E20C0_v);
        vec_add_ab(&v, &v, pp);
        cur = func_0038CE68(&v, &s->nrm[i + 2]) < 0.0f ? 0.0f : 1.0f;
        if (prev == -2.0f) {
            prev = cur;
        }
        if (cur != prev) {
            if (found) {
                *last = i;
                return 0;
            }
            *first = i;
            *idx = (s32)cur;
            prev = cur;
            found = 1;
        }
    }
    return 1;
}
/* localdecomp:end func_L14_003F7EB8 */

/* localdecomp:start func_L14_003F8060 */
typedef struct { f32 x, y, z, w; } V_3F8060;
extern V_3F8060 D_L14_001E20C0;
extern f32 D_L14_001E20C0_z[];
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_0038CF00(void *, void *);
s32 func_L14_003F8060(u8 *a0, vu0_v4 *a1, f32 scale) {
    vu0_v4 aq;
    V_3F8060 b;
    f32 r;
    f32 d;
    s32 n;
    aq = *a1;
    b.x = aq.x;
    b.y = aq.y;
    b.z = D_L14_001E20C0_z[2];
    r = func_003C4088(*(f32 *)(a0 + 0xE68), *(f32 *)(a0 + 0xE6C), (aq.z - D_L14_001E20C0_z[2]) / *(f32 *)(a0 + 8));
    if (r > *(f32 *)(a0 + 8)) {
        r = *(f32 *)(a0 + 8);
    } else if (r < 0.0f) {
        r = 0.0f;
    }
    d = func_0038CF00(&b, &D_L14_001E20C0);
    n = (s32)func_003C4088(0.0f, 127.0f, scale * (d - (r + 0.5f)));
    if (n > 0x80) {
        n = 0x80;
    } else if (n < 0) {
        n = 0;
    }
    return n;
}
/* localdecomp:end func_L14_003F8060 */

/* localdecomp:start func_L14_003F8170 */
extern void func_003D3A24(s32, s32, s32, s32, s32);
void func_L14_003F8170(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 i = a0;
    s32 k = i - 3;
    func_003D3A24(a1 - k, i * 12 + a2, a3 + i * 4, a4 + i * 8, 1);
}
/* localdecomp:end func_L14_003F8170 */

INCLUDE_ASM("asm/levels", func_L14_003F81B8);

INCLUDE_ASM("asm/levels", func_L14_003F8550);
