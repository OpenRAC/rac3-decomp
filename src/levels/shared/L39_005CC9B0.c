#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L39_005CC9B0 */
#include "vu0.h"

typedef struct {
    f32 x, y, z;
    f32 fC;
    u8 b10;
    u8 b11;
    u8 b12;
    u8 b13;
    f32 f14;
    f32 f18;
    s16 h1C;
    s16 h1E;
} D_005CC9B0;

typedef struct {
    u8 pad0[4];
    s32 color;
    u8 b8;
    u8 pad9;
    s16 h0A;
    f32 fC;
    vu0_v4 pos;
    D_005CC9B0 d;
} P_005CC9B0;

extern int func_0038CB00(void *);
extern void func_003CD250(void *);
extern void func_L39_005FFB48(void *, void *);
extern void func_L39_005BC330(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);

void func_L39_005CC9B0(P_005CC9B0 *p) {
    D_005CC9B0 *d;
    vu0_v4 v;
    vu0_v4 t;
    f32 a;

    if (func_0038CB00(&p->h0A)) {
        func_003CD250(p);
        return;
    }
    d = &p->d;
    a = (f32)p->h0A / (f32)d->h1C;
    v.x = d->x;
    v.w = 0.0f;
    p->color = ((s32)(d->h1E * a) << 24) | (d->b13 << 16) | (d->b12 << 8) | d->b11;
    v.y = d->y;
    v.z = d->z;
    vec_add_ab(&p->pos, &p->pos, &v);
    if (p->pos.w != 0.0f) {
        if (p->pos.w == 2.0f) {
            func_L39_005FFB48(&p->pos, &p->pos);
        }
        p->pos.w = 2.0f;
    }
    func_L39_005BC330(&p->pos, &t, 0);
    func_0038CE20(&t, &t, d->fC);
    vec_add_ab(&v, &v, &t);
    func_0038CE20(&v, &v, d->f18);
    d->x = v.x;
    d->y = v.y;
    d->z = v.z;
    p->b8 += d->b10;
    p->fC += d->f14;
}
/* localdecomp:end func_L39_005CC9B0 */
