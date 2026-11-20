#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_005BEAE0);

/* localdecomp:start func_L39_005BEAF8 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

extern int func_L39_005BEB98(void *, void *, Vec4 *);
extern int func_L39_005BEFB0(void *, void *, Vec4 *);

int func_L39_005BEAF8(void *a, void *b, Vec4 *out) {
    Vec4 tmp;
    int r;
    if (out != 0) {
        r = func_L39_005BEB98(a, b, &tmp);
        r &= func_L39_005BEFB0(a, &tmp, &tmp);
        *out = tmp;
        return r;
    }
    if (func_L39_005BEB98(a, b, 0) != 0) {
        int t = func_L39_005BEFB0(a, b, 0);
        if (t != 0) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_005BEAF8 */

/* localdecomp:start func_L39_005BEB98 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, r;
    Vec4 *pts;
    s32 n;
    s32 pad[2];
} Coll_005BEB98;

extern s32 D_L39_0024C120_005BEB98;
extern Coll_005BEB98 D_L39_002947C0_005BEB98[];
extern f32 D_L39_002433D4_005BEB98; __asm__(".extern D_L39_002433D4_005BEB98, 4");
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_L01_00446630_005BEB98(Vec4 *, void *, void *, void *);

int func_L39_005BEB98(void *a, void *b, Vec4 *out) {
    Vec4 m[3];
    Vec4 near;
    Vec4 d0;
    Vec4 d1;
    f32 inv;
    f32 eps;
    f32 y0;
    f32 y1;
    f32 t;
    f32 lo;
    f32 hi;
    f32 h;
    f32 zlo;
    f32 zhi;
    f32 best;
    s32 ok;
    s32 i;
    s32 j;
    s32 close;
    s32 edge;
    Coll_005BEB98 *c;
    vu0_q q;

    vec_sub_ba(&m[0], b, a);
    m[0].v[2] = 0.0f;
    inv = 1.0f / func_0038CEA8(&m[0]);
    func_0038CF68(&m[0], &m[0], inv);
    __asm__("vmr32.xyzw %0, vf0" : "=j"(q));
    m[1].v[0] = m[0].v[1];
    m[1].v[1] = -m[0].v[0];
    m[1].v[2] = 0.0f;
    eps = D_L39_002433D4_005BEB98 * inv;
    __asm__("sqc2 %1, %0" : "=m"(m[2]) : "j"(q));
    if (out != 0) {
        *out = *(Vec4 *)b;
    }
    ok = 1;
    best = 1.0f;
    if (((Vec4 *)a)->v[2] > ((Vec4 *)b)->v[2]) {
        zhi = ((Vec4 *)a)->v[2];
        zlo = ((Vec4 *)b)->v[2];
    } else {
        zhi = ((Vec4 *)b)->v[2];
        zlo = ((Vec4 *)a)->v[2];
    }
    for (i = 0; i < D_L39_0024C120_005BEB98; i++) {
        c = &D_L39_002947C0_005BEB98[i];
        func_L01_00446630_005BEB98(&near, a, b, c);
        if (c->r < func_0038CF00(&near, c)) {
            continue;
        }
        vec_sub_ba(&d0, c->pts, a);
        func_0038D000(&d0, &d0, m);
        for (j = 1; j < c->n; j++) {
            vec_sub_ba(&d1, &c->pts[j], a);
            func_0038D000(&d1, &d1, m);
            close = 0;
            edge = 0;
            if (fabs_asm(d1.v[1]) < eps || fabs_asm(d0.v[1]) < eps) {
                close = 1;
            }
            y0 = d0.v[1];
            y1 = d1.v[1];
            if (y1 * y0 <= 0.0f || close) {
                t = (d0.v[0] - d1.v[0]) / (y0 - y1);
                t *= -y1;
                t += d1.v[0];
                if (fabs_asm(t) < eps) {
                    edge = 1;
                }
                if (best == 1.0f && 0.0f < t && t < eps + 1.0f) {
                    edge = 1;
                }
                if ((0.0f < t && t <= best) || edge) {
                    lo = c->pts[j - 1].v[2] - c->pts[j - 1].v[3];
                    hi = lo + c->pts[j - 1].v[3];
                    if (c->pts[j].v[2] < lo) {
                        lo = c->pts[j].v[2];
                    }
                    h = c->pts[j].v[2] + c->pts[j].v[3];
                    if (hi < h) {
                        hi = h;
                    }
                    lo -= 0.5f;
                    if ((lo < zlo && zhi < hi) || (zlo < lo && lo < zhi) || (zlo < hi && hi < zhi)) {
                        best = t;
                        if (out == 0) {
                            return 0;
                        }
                        ok = 0;
                    }
                }
            }
            d0 = d1;
        }
    }
    if (out != 0 && !ok) {
        func_0038CDF8(out, a, b, best);
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L39_005BEB98 */

/* localdecomp:start func_L39_005BEFB0 */
#include "vu0.h"

typedef struct {
    Vec4 p0;
    Vec4 p1;
    Vec4 c;
    f32 f30;
    f32 base;
    f32 height;
    f32 f3C;
} S_005BEFB0;

extern s32 D_L39_0024C124_005BEFB0 __attribute__((section(".sdata")));
extern S_005BEFB0 D_L39_00294FC0_005BEFB0[];
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_L01_00446630_005BEFB0(Vec4 *, void *, void *, void *);

int func_L39_005BEFB0(void *a, void *b, Vec4 *out) {
    Vec4 m[4];
    Vec4 v0;
    Vec4 v1;
    vu0_q q;
    f32 best;
    f32 zmin;
    f32 zmax;
    f32 az;
    f32 bz;
    s32 miss;
    s32 i;
    S_005BEFB0 *p;

    vec_sub_ba(&m[0], b, a);
    m[0].v[2] = 0.0f;
    func_0038CF68(&m[0], &m[0], 1.0f / func_0038CEA8(&m[0]));
    m[1].v[0] = m[0].v[1];
    m[1].v[1] = -m[0].v[0];
    m[1].v[2] = 0.0f;
    __asm__("vmr32.xyzw %0, vf0" : "=j"(q));
    __asm__("sqc2 %1, %0" : "=m"(m[2]) : "j"(q));
    if (out != 0) {
        *out = *(Vec4 *)b;
    }
    best = 1.0f;
    miss = 1;
    az = ((Vec4 *)a)->v[2];
    bz = ((Vec4 *)b)->v[2];
    if (bz < az) {
        zmax = az;
        zmin = bz;
    } else {
        zmax = bz;
        zmin = az;
    }
    for (i = 0; i < D_L39_0024C124_005BEFB0; i++) {
        p = &D_L39_00294FC0_005BEFB0[i];
        func_L01_00446630_005BEFB0(&m[3], a, b, &p->c);
        if (p->c.v[3] < func_0038CF00(&m[3], &p->c)) {
            continue;
        }
        vec_sub_ab(&v0, &p->p0, a);
        func_0038D000(&v0, &v0, m);
        vec_sub_ab(&v1, &p->p1, a);
        func_0038D000(&v1, &v1, m);
        if (v1.v[1] * v0.v[1] < 0.0f) {
            f32 t = (v0.v[0] - v1.v[0]) / (v0.v[1] - v1.v[1]);
            t *= -v1.v[1];
            t += v1.v[0];
            if (t > 0.0f && t < best) {
                f32 lo = p->base;
                f32 hi = lo + p->height;
                if ((lo < zmin && zmax < hi) || (zmin < lo && lo < zmax) || (zmin < hi && hi < zmax)) {
                    best = t;
                    if (out == 0) {
                        return 0;
                    }
                    miss = 0;
                }
            }
        }
    }
    if (out == 0) {
        return 1;
    }
    if (miss != 0) {
        return 1;
    }
    func_0038CDF8(out, a, b, best);
    return 0;
}
/* localdecomp:end func_L39_005BEFB0 */

LINKER_REMNANT("asm/levels", func_L39_005BF280);
