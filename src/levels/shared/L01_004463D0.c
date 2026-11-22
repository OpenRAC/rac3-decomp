#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_004463D0 */
extern void func_003C3D30(s32, s32, s32, f32);

void func_L01_004463D0(s32 a0) {
    func_003C3D30(a0, 32, 0, 0.5f);
}
/* localdecomp:end func_L01_004463D0 */

/* localdecomp:start func_L01_004463F8 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec_004432C0;

s32 func_L01_004463F8(Vec_004432C0 *p, Vec_004432C0 *v, s32 n) {
    s32 i;
    s32 j = 0;
    s32 inside = 0;

    for (i = 0; i < n; i++) {
        j++;
        if (j == n) {
            j = 0;
        }
        if ((v[i].y < p->y && p->y <= v[j].y) || (v[j].y < p->y && p->y <= v[i].y)) {
            if (v[i].x + (p->y - v[i].y) / (v[j].y - v[i].y) * (v[j].x - v[i].x) < p->x) {
                inside = !inside;
            }
        }
    }
    return inside;
}
/* localdecomp:end func_L01_004463F8 */

/* localdecomp:start func_L01_004464C8 */
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);

typedef struct { vu0_q q; } vu0_s_004464C8;
static __inline__ void vec_seq_004464C8(vu0_v4 *A, vu0_v4 *B, vu0_v4 *C, vu0_v4 *D, vu0_v4 *E, vu0_v4 *N, vu0_v4 *pr, vu0_v4 *p, vu0_v4 *q, vu0_v4 *r) {
    vu0_q a, b;

    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*q));
    ((vu0_s_004464C8 *)A)->q = a;
    __asm__("lqc2 %0, %1" : "+j"(a) : "m"(*p));
    b = ((vu0_s_004464C8 *)A)->q;
    __asm__("vsub.xyz %0, %0, %1" : "+j"(b) : "j"(a));
    __asm__("sqc2 %1, %0" : "=m"(*A) : "j"(b));
    __asm__("lqc2 %0, %1" : "+j"(a) : "m"(*p));
    __asm__("lqc2 %0, %1" : "+j"(b) : "m"(*r), "j"(a), "j"(a), "j"(a));
    __asm__("sqc2 %1, %0" : "=m"(*B) : "j"(b), "j"(a), "j"(a), "j"(a));
    __asm__("lqc2 %0, %1" : "+j"(b) : "m"(*A));
    __asm__("sqc2 %1, %0" : "=m"(*C) : "j"(b));
    __asm__("lqc2 %0, %1" : "+j"(b) : "m"(*B));
    __asm__("vsub.xyz %0, %0, %1" : "+j"(a) : "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(*pr) : "j"(a));
    __asm__("lqc2 %0, %1" : "+j"(b) : "m"(*r));
    __asm__("lqc2 %0, %1" : "+j"(a) : "m"(*r));
    ((vu0_s_004464C8 *)D)->q = a;
    E->x = C->y;
    E->y = -C->x;
    __asm__("lqc2 %0, %1" : "+j"(a) : "m"(*E));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(b) : "j"(a));
    __asm__("sqc2 %1, %0" : "=m"(*E) : "j"(b));
    __asm__("lqc2 %0, %1" : "+j"(a) : "m"(*E));
    __asm__("lqc2 %0, %1" : "+j"(b) : "m"(*D));
    __asm__("vsub.xyz %0, %1, %0" : "+j"(a) : "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(*N) : "j"(a));
}
f32 func_L01_004464C8(vu0_v4 *out, vu0_v4 *p, vu0_v4 *q, vu0_v4 *r) {
    vu0_v4 C, N, pr, E, B, D, A;
    f32 denom, t, tc;
    vec_seq_004464C8(&A, &B, &C, &D, &E, &N, &pr, p, q, r);
    denom = C.y * N.x - C.x * N.y;
    if (fabs_asm(denom) < 0.0001f) {
        *out = *p;
        return 0.0f;
    }
    denom = 1.0f / denom;
    t = N.y * pr.x - N.x * pr.y;
    t *= denom;
    tc = t;
    if (tc < 0.0f) {
        tc = 0.0f;
    }
    if (1.0f < tc) {
        tc = 1.0f;
    }
    func_0038CE20(out, &C, tc);
    vec_add_ba(out, out, p);
    return t;
}
/* localdecomp:end func_L01_004464C8 */

/* localdecomp:start func_L01_00446630 */
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);

f32 func_L01_00446630(vu0_v4 *out, vu0_v4 *p, vu0_v4 *a, vu0_v4 *b) {
    vu0_v4 d1;
    vu0_v4 d2;
    vu0_q qa, qb, qp, qp2, r1, r2;
    f32 t;

    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*b));
    __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*p));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(qa), "j"(qp));
    __asm__("lqc2 %0, %1" : "=j"(qp2) : "m"(*p));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r2) : "j"(qb), "j"(qp2));
    __asm__("sqc2 %1, %0" : "=m"(d1) : "j"(r1));
    __asm__("sqc2 %1, %0" : "=m"(d2) : "j"(r2));
    t = func_0038CE68(&d1, &d2) / func_0038CE68(&d1, &d1);
    t = t < 0.0f ? 0.0f : t;
    t = 1.0f < t ? 1.0f : t;
    func_0038CE20(&d1, &d1, t);
    vec_add_ab(out, p, &d1);
    return t;
}
/* localdecomp:end func_L01_00446630 */

/* localdecomp:start func_L01_00446720 */
/* from rac2-decomp's func_L00_0031BE88, renamed */
s32 func_L01_00446720(char *a0) {
    if (*(s32 **)(a0 + 0x98) != 0 && *(s32 *)(*(char **)(a0 + 0x98) + 8) != 0)
        return 1;
    return 0;
}
/* localdecomp:end func_L01_00446720 */

/* localdecomp:start func_L01_00446748 */
void func_L01_00446748(u8 *a, s32 b, s32 c, f32 d) {
    *(s32 *)(a + 0x10) = b;
    qzero(a);
    *(s32 *)(a + 0x14) = c;
    *(f32 *)(a + 0x1c) = d;
    *(s32 *)(a + 0x20) = 0;
}
/* localdecomp:end func_L01_00446748 */

/* localdecomp:start func_L01_00446760 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_443;
typedef struct { V4_443 v; s32 a; s32 b; s32 pad; f32 f; s32 one; } S443;
void func_L01_00446760(S443 *p, s32 a, s32 b, V4_443 *v, f32 f) {
    p->a = a;
    p->b = b;
    p->f = f;
    p->one = 1;
    p->v = *v;
}
/* localdecomp:end func_L01_00446760 */

/* localdecomp:start func_L01_00446780 */




typedef int TI128_00446780 __attribute__((mode(TI)));
typedef union { TI128_00446780 q; float f[4]; } Vector_00446780;

typedef struct { int a,b,c,d; } __attribute__((aligned(16))) Quad16_00446780;
/* Known 36-byte query fields; alignment supplies the measured 48-byte slot. */
typedef struct {
    Vector_00446780 direction;
    int owner, queryMode;
    u8 first, second;
    u16 objectId;
    float distance;
    int enabled;
} CollisionQuery_00446780;
int func_L01_00446780(void *owner, f32 radius, f32 *start, s32 queryMode, f32 distance, f32 scale,
                      s32 first, s32 second, s32 mode) {
    extern void func_0038CF68(void *, void *, float);
    extern void func_L01_00446760(S443 *, s32, s32, V4_443 *, f32);
    extern float func_0038D098(float);
    extern float func_0038D0B0(float);
    extern void func_0038CE20(void *, void *, float);
    extern int func_003D4D00(void *, float, int, char *, void *);
    char *object = owner;
    Vector_00446780 direction;
    CollisionQuery_00446780 query;
    if (*(u16 *)(object + 0x34) & 0x100) {
        func_0038CF68(&direction, object + 0xE0, 0.25f);
        __asm__(
            "lqc2 $vf1, %1\n"
            "lqc2 $vf2, %2\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "=m" (direction)
            : "m" (direction), "m" (*(Vector_00446780 *)(object + 0xC0))
            : "vf1", "vf2");
    } else {
        direction.f[0] = func_0038D098(*(float *)(object + 0xF8));
        direction.f[1] = func_0038D0B0(*(float *)(object + 0xF8));
        direction.f[2] = 1.0f;
    }
    func_0038CE20(&direction, &direction, scale);
    direction.f[3] = 5627.9248046875f;
    func_L01_00446760((S443 *)&query, (s32)object, queryMode, (V4_443 *)&direction, distance);
    query.first = first;
    query.second = second;
    query.objectId = *(u16 *)(object + 0xAA);
    return func_003D4D00(start, radius, mode, object, &query);
}
/* localdecomp:end func_L01_00446780 */

/* localdecomp:start func_L01_004468C8 */
extern void func_003C2F58(void *, int, float *);
extern int func_L01_00446780(void *, float, float *, int, float, float, int, int, int);

/* from rac2-decomp's func_002A8D70, renamed */
int func_L01_004468C8(void *object, int bone, float x, int mode, float y, float z, int first, int second, int third)
{
    float vector[4];
    func_003C2F58(object, bone, vector);
    return func_L01_00446780(object, x, vector, mode, y, z, first, second, third);
}
/* localdecomp:end func_L01_004468C8 */

LINKER_REMNANT("asm/levels", func_L01_00446970);

/* localdecomp:start func_L01_00446978 */
#include "vu0.h"

typedef struct {
    vu0_q v0;
    s32 w10;
    s32 flags;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 f1C;
    s32 w20;
    f32 f24;
    s32 w28;
} Src_446978_00446978;

typedef struct {
    vu0_q v0;
    vu0_q v10;
    s32 w20;
    s32 flags;
    u8 b28;
    u8 b29;
    u16 h2A;
    f32 f2C;
    s32 w30;
    f32 f34;
    u8 *owner;
    s32 w3C;
} Entry_446978_00446978;

typedef struct {
    u8 pad0[20];
    s32 next;
} Ring_446978_00446978;

extern Ring_446978_00446978 D_L01_001EAA00_00446978;
extern Entry_446978_00446978 D_L01_001EEC80_00446978[];

void func_L01_00446978(u8 *a0, Src_446978_00446978 *a1) {
    s32 slot = D_L01_001EAA00_00446978.next;
    s32 flags = 0;
    Entry_446978_00446978 *e;
    Entry_446978_00446978 *p;

    if (a0[168] != 255) {
        p = &D_L01_001EEC80_00446978[a0[168]];
        if (p->owner == a0) {
            if (p->f2C > a1->f1C) {
                p->flags |= a1->flags;
                return;
            }
            flags = p->flags;
        }
    }
    e = &D_L01_001EEC80_00446978[slot];
    qzero(&e->v0);
    D_L01_001EEC80_00446978[slot].v10 = a1->v0;
    e->flags = a1->flags | flags;
    e->w20 = a1->w10;
    e->b28 = a1->b18;
    e->b29 = a1->b19;
    e->h2A = a1->h1A;
    e->f2C = a1->f1C;
    e->f34 = a1->f24;
    e->w30 = a1->w20;
    e->owner = a0;
    e->w3C = a1->w28;
    a0[168] = slot;
    D_L01_001EAA00_00446978.next = (slot + 1) & 63;
}
/* localdecomp:end func_L01_00446978 */

/* localdecomp:start func_L01_00446A70 */
typedef int u128_443938 __attribute__((mode(TI)));

typedef struct {
    u128_443938 v0;
    u128_443938 v10;
    s32 w20;
    s32 flags;
    u8 b28;
    u8 pad29[3];
    f32 f2C;
    s32 w30;
    f32 f34;
    u8 *owner;
    s32 w3C;
} Entry_443938;

typedef struct {
    u8 pad0[20];
    s32 next;
} Ring_443938;

extern Ring_443938 D_L01_001EAA00;
extern Entry_443938 D_L01_001EEC80[];
extern f32 func_0038CEA8(u128_443938 *a0);

void func_L01_00446A70(u8 *a0, s32 a1, s32 a2, u128_443938 *a3, u128_443938 *t0, f32 f) {
    s32 slot = D_L01_001EAA00.next;
    s32 flags = 0;
    Entry_443938 *e;
    Entry_443938 *p;

    if (a0[168] != 255) {
        p = &D_L01_001EEC80[a0[168]];
        if (p->owner == a0) {
            if (f < p->f2C) {
                p->flags |= a2;
                return;
            }
            flags = p->flags;
        }
    }
    e = &D_L01_001EEC80[slot];
    e->flags = a2 | flags;
    e->w20 = a1;
    e->b28 = 0;
    e->owner = a0;
    e->f34 = e->f2C = f;
    e->w3C = 0;
    if (func_0038CEA8(t0) > 0.0001f) {
        e->w30 = 1;
    } else {
        e->w30 = 0;
    }
    D_L01_001EEC80[slot].v0 = *a3;
    D_L01_001EEC80[slot].v10 = *t0;
    a0[168] = slot;
    D_L01_001EAA00.next = (slot + 1) & 63;
}
/* localdecomp:end func_L01_00446A70 */

/* localdecomp:start func_L01_00446BC8 */
extern void func_L01_00446A70(u8 *a0, s32 a1, s32 a2, u128_443938 *a3, u128_443938 *t0, f32 f);
extern s8 D_L01_001D66B0;

/* from rac2-decomp's func_002A90C8 */
void func_L01_00446BC8(u8 *a, s32 b, s32 c, u128_443938 *d, f32 duration) {
    func_L01_00446A70(a, b, c, d, (u128_443938 *)&D_L01_001D66B0, duration);
}
/* localdecomp:end func_L01_00446BC8 */

/* localdecomp:start func_L01_00446BF0 */
#include "vu0.h"
static __inline__ void vec_add_copy_00446BF0(void *d, void *a, void *b, void *cd, void *cs) {
    vu0_q x, y;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_v4 *)b));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_v4 *)a));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x));
    __asm__("lqc2 %0, %1" : "+j"(x) : "m"(*(vu0_v4 *)cs));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)cd) : "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(y));
}
static __inline__ void vec_add_l_00446BF0(void *d, void *a, void *b) {
    vu0_q qa, qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b), "j"(qa), "j"(qa));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qr));
}
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
s32 func_L01_00446BF0(f32 *a, f32 *b, f32 *p, f32 *q, void *arg4, s32 arg5, s32 steps) {
    vu0_v4 da, db, pa, pb, qv;
    f32 step = 1.0f / (f32)steps;
    f32 t = step;
    s32 i;

    vec_sub_ba(&da, a, p);
    vec_sub_ab(&db, b, q);
    for (i = 0; i < steps; i++) {
        func_0038CE20(&pa, &da, t);
        func_0038CE20(&pb, &db, t);
        vec_add_copy_00446BF0(&pa, &pa, p, &qv, q);
        vec_add_l_00446BF0(&pb, &pb, &qv);
        if (func_003D3CB0(&pa, &pb, 0, arg4, arg5) != 0) {
            return 1;
        }
        t += step;
    }
    return 0;
}
/* localdecomp:end func_L01_00446BF0 */
