#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L24_0034C618 */
extern void func_003C2EC0(char *, s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C6FE0(char *);
extern void func_003C7C38(char *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_0038D308(void *, void *);
extern void func_003C7DD8(char *);

void func_L24_0034C618(char *a0, char *a1, s32 a2, u128_t *a3, s32 flags)
{
    u128_t w[5];
    f32 *v = (f32 *)w;
    f32 dist;
    char *pp;

    w[0] = *a3;
    func_003C2EC0(a0, a2, &v[4]);
    pp = a1 + 0x10;
    *(u128_t *)(a1 + 0x10) = w[0];
    if (flags & 1) {
        func_0038CE20(&v[4], &v[4], -1.0f);
    }
    if (flags & 2) {
        func_0038CE20(&v[8], &v[8], -1.0f);
    }
    if (flags & 4) {
        func_0038CE20(&v[12], &v[12], -1.0f);
    }
    func_003C6FE0(a1);
    if ((*(u16 *)(a1 + 0x34) & 4) == 0) {
        func_003C7C38(a1);
    }
    *(f32 *)(a1 + 0xF8) = func_0038D160(v[16] - *(f32 *)(a1 + 0x10), v[17] - *(f32 *)(a1 + 0x14));
    *(f32 *)(a1 + 0xF8) = func_0038DAB8(*(f32 *)(a1 + 0xF8), 3.1415927f);
    dist = func_0038CF38(pp, &v[16]);
    *(f32 *)(a1 + 0xF4) = func_0038D160(dist, v[18] - *(f32 *)(a1 + 0x18));
    *(f32 *)(a1 + 0xF0) = 1.5707964f;
    func_0038D308(a1 + 0xC0, a1 + 0xF0);
    func_003C7DD8(a1);
    if (*(u16 *)(a0 + 0x34) & 1) {
        *(u16 *)(a1 + 0x34) |= 0x41;
    } else {
        *(u16 *)(a1 + 0x34) &= 0xFFBE;
    }
    *(u16 *)(a1 + 0x34) |= 6;
}
/* localdecomp:end func_L24_0034C618 */

/* localdecomp:start func_L24_0034C7A8 */
extern void func_003C2F58(void *, s32, void *);
extern void func_L24_0034C8D0(void *, void *, void *);

void func_L24_0034C7A8(u8 *obj) {
    u8 a[16];
    u8 b[16];
    u8 *s = *(u8 **)(obj + 0x68);
    s32 i;
    s32 j;
    void **pa;
    void **pb;
    f32 f;

    f = *(f32 *)(s + 0x580) + 0.1f;
    *(f32 *)(s + 0x580) = f;
    if (f >= 4.0f) {
        *(f32 *)(s + 0x580) = f - 4.0f;
    }
    pa = (void **)(s + 0x540);
    pb = (void **)(s + 0x560);
    for (i = 1; i < 5; i++) {
        func_003C2F58(pa[i - 1], 0, a);
        func_003C2F58(pa[i], 1, b);
        func_L24_0034C8D0(obj, a, b);
    }
    for (j = 1; j < 5; j++) {
        func_003C2F58(pb[j - 1], 0, a);
        func_003C2F58(pb[j], 1, b);
        func_L24_0034C8D0(obj, a, b);
    }
}
/* localdecomp:end func_L24_0034C7A8 */

/* localdecomp:start func_L24_0034C8D0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_34C8D0;
typedef struct { f32 u, v; } UV_34C8D0;
typedef struct { V_34C8D0 p[4]; s32 c[4]; UV_34C8D0 uv[4]; } Q_34C8D0;
__asm__(".extern D_L24_001DD3A8, 4");
__asm__(".extern D_L24_001DD3AC, 4");
__asm__(".extern D_L24_001DD3B0, 4");
__asm__(".extern D_L24_001DD3B4, 4");
extern s32 D_L24_001DD3A8;
extern s32 D_L24_001DD3AC;
extern f32 D_L24_001DD3B0;
extern f32 D_L24_001DD3B4;
extern V_34C8D0 D_L24_001E2180;
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);

static __inline__ V_34C8D0 vsub_34C8D0(V_34C8D0 *a, V_34C8D0 *b) {
    V_34C8D0 r;
    vec_sub_ba(&r, a, b);
    return r;
}

static __inline__ V_34C8D0 vadd_34C8D0(V_34C8D0 *a, V_34C8D0 *b) {
    V_34C8D0 r;
    vec_add_ba(&r, a, b);
    return r;
}

void func_L24_0034C8D0(void *obj, void *pa, void *pb) {
    V_34C8D0 a = *(V_34C8D0 *)pa;
    V_34C8D0 b = *(V_34C8D0 *)pb;
    Q_34C8D0 q;
    char buf[32];
    V_34C8D0 e;
    V_34C8D0 f;
    V_34C8D0 d;
    V_34C8D0 *ap = &a;
    V_34C8D0 *bp = &b;
    u8 *s = *(u8 **)((u8 *)obj + 0x68);
    s32 c;
    s32 i;

    func_003D93B0(&q, 0xE, 1, 0x80);
    c = D_L24_001DD3A8;
    q.c[3] = c;
    q.c[2] = c;
    q.c[1] = c;
    q.c[0] = c;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    for (i = 0; i < 4; i++) {
        q.uv[i].u -= *(f32 *)(s + 0x580);
        if (q.uv[i].u <= 7.0f) {
            q.uv[i].u += 7.0f;
        }
    }
    vec_sub_ba(&d, ap, bp);
    func_0038CF68(&d, &d, 1.0f);
    vec_sub_ba(&e, ap, &D_L24_001E2180);
    vec_sub_ba(&f, bp, &D_L24_001E2180);
    func_0038CE90(&e, &e, &d);
    func_0038CF68(&e, &e, D_L24_001DD3B0);
    func_0038CE90(&f, &f, &d);
    func_0038CF68(&f, &f, D_L24_001DD3B4);
    {
        q.p[0] = vsub_34C8D0(ap, &e);
    }
    {
        q.p[1] = vadd_34C8D0(ap, &e);
    }
    {
        q.p[2] = vsub_34C8D0(bp, &f);
    }
    {
        q.p[3] = vadd_34C8D0(bp, &f);
    }
    func_003D2DA0(&q, 0, 0);

    func_003D93B0(&q, 0xE, 1, 0x80);
    c = D_L24_001DD3AC;
    q.c[3] = c;
    q.c[2] = c;
    q.c[1] = c;
    q.c[0] = c;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    for (i = 0; i < 4; i++) {
        q.uv[i].u -= *(f32 *)(s + 0x580);
        if (q.uv[i].u <= 7.0f) {
            q.uv[i].u += 7.0f;
        }
    }
    vec_sub_ba(&d, ap, bp);
    func_0038CF68(&d, &d, 1.0f);
    vec_sub_ba(&e, ap, &D_L24_001E2180);
    vec_sub_ba(&f, bp, &D_L24_001E2180);
    func_0038CE90(&e, &e, &d);
    func_0038CF68(&e, &e, D_L24_001DD3B0 * 0.5f);
    func_0038CE90(&f, &f, &d);
    func_0038CF68(&f, &f, D_L24_001DD3B4 * 0.5f);
    {
        q.p[0] = vsub_34C8D0(ap, &e);
    }
    {
        q.p[1] = vadd_34C8D0(ap, &e);
    }
    {
        q.p[2] = vsub_34C8D0(bp, &f);
    }
    {
        q.p[3] = vadd_34C8D0(bp, &f);
    }
    func_003D2DA0(&q, 0, 0);
}
/* localdecomp:end func_L24_0034C8D0 */

/* localdecomp:start func_L24_0034CCA0 */
void func_0038CAD0(s32);
void func_0038CB00(s32);

void func_L24_0034CCA0(void *arg0) {
    s32 temp_s0;
    u16 temp_v1;

    temp_s0 = *(s32 *)((u8 *)arg0 + 0x68);
    func_0038CAD0(temp_s0 + 0x4B0);
    func_0038CB00(temp_s0 + 0x4B4);
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
}
/* localdecomp:end func_L24_0034CCA0 */
