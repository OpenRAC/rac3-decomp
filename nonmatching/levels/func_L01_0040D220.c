/* NEAR MISS (36 diff): formula is right (hermite-like: k*t^3 + (d1-k)*t^2 + (b-c)*t + a, k=(e-b)-(c-a)); only FP register numbering/order differs from retail (retail: c->f3, a->f6, b->f4, e->f0, t3 in f2, t2 in f5). Needs Vec4_40CA60 from func_L01_0040CA60's block (src/levels/shared/L01_0040C3C0.c). */
#include "common.h"
void func_L01_0040D220(Vec4_40CA60 *d, Vec4_40CA60 *a, Vec4_40CA60 *b, Vec4_40CA60 *c, Vec4_40CA60 *e, f32 t) {
    f32 t2, t3, k;
    if (t == 0.0f) { d->q = a->q; return; }
    if (t == 1.0f) { d->q = b->q; return; }
    t2 = t * t;
    t3 = t2 * t;
    k = (e->f[0] - b->f[0]) - (c->f[0] - a->f[0]);
    d->f[0] = k * t3 + ((c->f[0] - a->f[0]) - k) * t2 + (b->f[0] - c->f[0]) * t + a->f[0];
    k = (e->f[1] - b->f[1]) - (c->f[1] - a->f[1]);
    d->f[1] = k * t3 + ((c->f[1] - a->f[1]) - k) * t2 + (b->f[1] - c->f[1]) * t + a->f[1];
    k = (e->f[2] - b->f[2]) - (c->f[2] - a->f[2]);
    d->f[2] = k * t3 + ((c->f[2] - a->f[2]) - k) * t2 + (b->f[2] - c->f[2]) * t + a->f[2];
    d->f[3] = 0.0f;
}
