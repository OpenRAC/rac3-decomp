/* functional: high. Hand-written from PAL assembly. Lightning/beam strip drawer: pts (n 16-byte points) become a strip of quads submitted through func_003D2DA0 in two passes (width f13 pass 1 with a ribbon along the camera-facing normal, pass 2 with equalised side vectors scaled by f14). The two draw objects carry the same {tag} words func_003D93B0 builds (inlined here, call sequence read from the asm). f12 is unused by retail. Needs -mvu0-use-vf0-vf2 only if vec helpers were used (plain C here). */
#include "common.h"

/* localdecomp:start func_L17_003B8BF8 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) V_003B8BF8;

typedef struct {
    V_003B8BF8 q[4];
    s32 k[4];
    f32 e0[4];
    f32 f0[4];
    u64 tag[4];
} S_003B8BF8;

extern V_003B8BF8 D_L17_001E1900;
extern s32 D_L17_001DE5A4;
extern s32 D_L17_001DE5A8;
extern f32 D_L17_001DE5AC;
extern f32 D_L17_001DE59C;
extern s32 D_L17_001DE5D0;
extern s32 D_L17_001DE5D4;
__asm__(".extern D_L17_001DE5A4, 4");
__asm__(".extern D_L17_001DE5A8, 4");
__asm__(".extern D_L17_001DE5AC, 4");
__asm__(".extern D_L17_001DE59C, 4");
__asm__(".extern D_L17_001DE5D0, 4");
__asm__(".extern D_L17_001DE5D4, 4");
extern unsigned long fe_func_00389598(s32);
extern void fe_func_0038CE90(void *, void *, void *);
extern f32 fe_func_0038CEA8(void *);
extern void fe_func_0038CE20(void *, void *, f32);
extern void fe_func_003D2DA0(void *, void *, s32);
extern void fe_func_003A9440(s32, unsigned long);

static void vsub3(V_003B8BF8 *d, V_003B8BF8 *a, V_003B8BF8 *b) {
    d->v[0] = a->v[0] - b->v[0];
    d->v[1] = a->v[1] - b->v[1];
    d->v[2] = a->v[2] - b->v[2];
    d->v[3] = a->v[3];
}

static void vadd3(V_003B8BF8 *d, V_003B8BF8 *a, V_003B8BF8 *b) {
    d->v[0] = a->v[0] + b->v[0];
    d->v[1] = a->v[1] + b->v[1];
    d->v[2] = a->v[2] + b->v[2];
    d->v[3] = a->v[3];
}

void func_L17_003B8BF8(void *pts_, s32 a1, s32 a2, s32 n, f32 f12, f32 w1, f32 w2) {
    S_003B8BF8 o1;
    S_003B8BF8 o2;
    V_003B8BF8 nrm;
    V_003B8BF8 t;
    V_003B8BF8 p0;
    V_003B8BF8 d1;
    V_003B8BF8 aa;
    V_003B8BF8 bb;
    V_003B8BF8 xx;
    V_003B8BF8 yy;
    V_003B8BF8 zz;
    V_003B8BF8 ww;
    V_003B8BF8 uu;
    V_003B8BF8 mm;
    s32 c1;
    s32 c2;
    s32 n2;
    s32 i;
    f32 zero;
    f32 e;
    f32 len;
    f32 lb;
    f32 inv;
    V_003B8BF8 *p;
    V_003B8BF8 *pts = (V_003B8BF8 *)pts_;

    o1.tag[1] = fe_func_00389598(D_L17_001DE5D0);
    c1 = D_L17_001DE5A4 | (a1 << 24);
    o1.tag[3] = 0x8000000048ULL;
    o1.tag[2] = 0xFF9000000260ULL;
    o1.tag[0] = 0;
    o1.k[3] = c1;
    o1.k[2] = c1;
    o1.k[1] = c1;
    o1.k[0] = c1;
    o2.tag[1] = fe_func_00389598(D_L17_001DE5D4);
    zero = 0.0f;
    c2 = D_L17_001DE5A8 | (a2 << 24);
    e = D_L17_001DE59C;
    vsub3(&p0, &pts[0], &D_L17_001E1900);
    vsub3(&d1, &pts[1], &pts[0]);
    o2.tag[3] = o1.tag[3];
    o2.tag[2] = o1.tag[2];
    o2.tag[0] = o1.tag[0];
    o1.e0[2] = e + zero;
    o1.f0[2] = e + 1.0f;
    o2.k[3] = c2;
    o2.k[2] = c2;
    o2.k[1] = c2;
    o2.k[0] = c2;
    o2.e0[0] = 0.0f;
    o2.e0[1] = 0.0f;
    o2.e0[2] = 0.0f;
    o2.e0[3] = 1.0f;
    o2.f0[0] = 1.0f;
    o2.f0[1] = 0.0f;
    o2.f0[2] = 1.0f;
    o2.f0[3] = 1.0f;
    o1.e0[0] = o1.e0[2];
    o1.e0[1] = zero;
    o1.e0[3] = 1.0f;
    o1.f0[0] = o1.f0[2];
    o1.f0[1] = zero;
    o1.f0[3] = 1.0f;
    fe_func_0038CE90(&nrm, &d1, &p0);
    len = fe_func_0038CEA8(&nrm);
    if (len != zero) {
        len = 1.0f / len;
    }
    fe_func_0038CE20(&nrm, &nrm, D_L17_001DE5AC * len);
    n2 = n - 2;
    vadd3(&o1.q[0], &pts[0], &nrm);
    vsub3(&o1.q[1], &pts[0], &nrm);
    p = &pts[1];
    for (i = 1; i < n - 1; i++, p++) {
        vsub3(&t, p, &D_L17_001E1900);
        p0 = t;
        vsub3(&d1, p + 1, p);
        fe_func_0038CE90(&nrm, &d1, &p0);
        len = fe_func_0038CEA8(&nrm);
        if (len != zero) {
            len = 1.0f / len;
        }
        fe_func_0038CE20(&nrm, &nrm, D_L17_001DE5AC * len);
        vadd3(&o1.q[2], p, &nrm);
        vsub3(&o1.q[3], p, &nrm);
        if (i == 1) {
            o1.k[0] = D_L17_001DE5A4;
            o1.k[1] = D_L17_001DE5A4;
        } else if (i == n2) {
            o1.k[2] = D_L17_001DE5A4;
            o1.k[3] = D_L17_001DE5A4;
        } else if (i == 2) {
            o1.k[1] = c1;
            o1.k[0] = c1;
        }
        fe_func_003D2DA0(&o1, 0, 0);
        o1.q[0] = o1.q[2];
        o1.q[1] = o1.q[3];
    }
    if (n2 > 0) {
        p = pts;
        for (i = 0; i < n2; i++, p++) {
            vsub3(&t, p, &D_L17_001E1900);
            aa = t;
            vsub3(&bb, p + 1, &D_L17_001E1900);
            len = fe_func_0038CEA8(&aa);
            lb = fe_func_0038CEA8(&bb);
            if (lb < len) {
                if (lb == zero) {
                    bb = aa;
                } else {
                    fe_func_0038CE20(&bb, &bb, len / lb);
                }
            } else {
                if (len == zero) {
                    aa = bb;
                } else {
                    fe_func_0038CE20(&aa, &aa, lb / len);
                }
            }
            vadd3(&xx, &D_L17_001E1900, &aa);
            vadd3(&yy, &D_L17_001E1900, &bb);
            vsub3(&zz, &yy, &xx);
            fe_func_0038CE20(&ww, &zz, w2);
            vsub3(&xx, &xx, &ww);
            uu = D_L17_001E1900;
            vadd3(&yy, &yy, &ww);
            vsub3(&uu, &uu, &xx);
            fe_func_0038CE90(&nrm, &uu, &zz);
            len = fe_func_0038CEA8(&nrm);
            if (len == zero) {
                inv = w1 * len;
            } else {
                inv = w1 * (1.0f / len);
            }
            fe_func_0038CE20(&mm, &nrm, inv);
            vadd3(&o2.q[0], &xx, &mm);
            vsub3(&o2.q[1], &xx, &mm);
            vadd3(&o2.q[2], &yy, &mm);
            vsub3(&o2.q[3], &yy, &mm);
            if (i == 0) {
                o2.k[0] = D_L17_001DE5A8;
                o2.k[1] = D_L17_001DE5A8;
            } else if (i == n - 3) {
                o2.k[2] = D_L17_001DE5A8;
                o2.k[3] = D_L17_001DE5A8;
            } else if (i == 1) {
                o2.k[1] = c2;
                o2.k[0] = c2;
            }
            fe_func_003D2DA0(&o2, 0, 0);
        }
    }
    fe_func_003A9440(0x47, 0x5360BUL);
}
/* localdecomp:end func_L17_003B8BF8 */
