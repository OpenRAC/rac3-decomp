#include "common.h"

/* localdecomp:start func_L39_005CFDC8 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_005CFDC8;

typedef struct {
    f32 x, y, z;
} V3_005CFDC8;

typedef struct {
    u8 pad0[0x10];
    V4_005CFDC8 pos;
} T_005CFDC8;

typedef struct {
    f32 f0;
    f32 f4;
    s16 f8;
    u8 fA;
    u8 fB;
    V3_005CFDC8 fC;
    T_005CFDC8 *f18;
} Sub_005CFDC8;

typedef struct {
    u8 pad0[4];
    u32 f4;
    u8 f8;
    u8 pad9;
    s16 fA;
    f32 fC;
    V4_005CFDC8 pos;
    Sub_005CFDC8 sub;
} O_005CFDC8;

extern void func_L39_005FFB48(void *, void *);
extern void func_L39_005BC330(void *, void *, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern s32 func_0038CB00(void *);
extern void func_003CD250(void *);
extern f32 D_001D7E74_sda;

static __inline__ void v3to4_005CFDC8(V4_005CFDC8 *d, V3_005CFDC8 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
    d->w = 0.0f;
}

__asm__(".extern D_001D7E74_sda, 4");

void func_L39_005CFDC8(O_005CFDC8 *o) {
    Sub_005CFDC8 *sub = &o->sub;
    V4_005CFDC8 v;
    V4_005CFDC8 d;
    V4_005CFDC8 r;
    V4_005CFDC8 m;
    s32 a;
    s32 alpha;
    f32 t;

    o->f8 += sub->fA;
    a = o->fA;
    if (sub->f8 - a < 6) {
        t = (f32)(sub->f8 - a) / 5.0f;
        o->fC = sub->f4 + ((sub->f0 + sub->f4) * 0.5f - sub->f4) * t;
        {
            u32 fade = sub->fB;
            s32 start = fade;
            fade >>= 1;
            alpha = start + (s32)(fade - start) * t;
        }
    } else {
        t = (f32)a / (f32)(sub->f8 - 6);
        o->fC = sub->f0 + ((sub->f0 + sub->f4) * 0.5f - sub->f0) * t;
        alpha = 0.0f + (sub->fB >> 1) * t;
    }
    o->f4 = (alpha << 24) | (o->f4 & 0xFFFFFF);
    v3to4_005CFDC8(&v, &sub->fC);
    vec_add_ab(&o->pos, &o->pos, &v);
    func_L39_005FFB48(&o->pos, &o->pos);
    if (sub->f18 != 0) {
        vec_sub_ab(&d, &sub->f18->pos, &o->pos);
        if (fabs_asm(d.x) <= 2.0f && fabs_asm(d.y) <= 2.0f) {
            func_L39_005BC330(&m, &m, 0);
            func_0038CE90(&r, &d, &m);
            func_0038CF68(&r, &r, D_001D7E74_sda);
            vec_add_ab(&o->pos, &o->pos, &r);
            if (d.x <= 0.5f && d.y <= 0.5f) {
                func_0038CF68(&v, &d, 0.03f);
            } else {
                func_0038CF68(&v, &d, func_0038CEA8(&v));
            }
            v.z += 0.02f;
            {
                V3_005CFDC8 *vel = &sub->fC;
                vel->x = v.x;
                vel->y = v.y;
                vel->z = v.z;
            }
        }
    }
    if (func_0038CB00(&o->fA)) {
        func_003CD250(o);
    }
}
/* localdecomp:end func_L39_005CFDC8 */
