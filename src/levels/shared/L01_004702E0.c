#include "common.h"
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;
typedef struct {
    f32 unk00;
    f32 unk04;
    s32 unk08;
    f32 unk0C;
    f32 unk10;
    s32 unk14;
} S_467288_Sub;
typedef struct {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
    s32 unk04;
    u8 unk08;
    u8 unk09;
    s16 unk0A;
    f32 unk0C;
    Vec4 unk10;
    S_467288_Sub sub;
} S_467288;
typedef int s128_467510 __attribute__((mode(TI)));
typedef struct {
    s128_467510 q0;
    f32 f10;
    f32 f14;
    int f18;
} P_467510;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 target;
    f32 base;
    s32 b;
    s32 a;
    f32 scale;
} Sub;
typedef struct {
    char pad0[0x4];
    s32 result;
    char pad8[0xA - 0x8];
    s16 timer;
    f32 out;
    char vec[0x20 - 0x10];
    Sub sub;
} Obj;
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 pos[3];
    s32 unk0C;
    f32 off[3];
    s32 unk1C;
} S_468DC0_Sub;
typedef struct {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
    s32 unk04;
    u8 unk08;
    u8 unk09;
    s16 unk0A;
    f32 unk0C;
    Vec4 unk10;
    S_468DC0_Sub sub;
} S_468DC0;
typedef int u128_469BA0 __attribute__((mode(TI)));
typedef struct {
    f32 f0;
    f32 f4;
    s32 x8;
    f32 fC;
    f32 f10;
} Q_469BA0;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 x4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    u128_469BA0 v10;
    Q_469BA0 q;
} P_469BA0;
typedef struct {
    f32 v[3];
    s32 x0C;
    f32 x10;
    f32 x14;
    s16 x18;
    s16 x1A;
    s16 x1C;
} S_469D90_Q;
typedef struct {
    u8 x0;
    u8 x1;
    u8 x2;
    u8 x3;
    s32 x4;
    u8 x8;
    u8 x9;
    s16 xA;
    f32 xC;
    s128 x10;
    S_469D90_Q q;
} S_469D90;
typedef struct {
    f32 *p;
    f32 radius;
    f32 angle;
    f32 speed;
    f32 rise;
    u8 step;
} Orbit_0046E408;
typedef struct {
    u8 pad0[8];
    u8 b8;
    u8 pad9[3];
    f32 f12;
    f32 f16;
    f32 pad20;
    f32 f24;
    f32 pad28;
    Orbit_0046E408 o;
} Obj_0046E408;

extern S_467288 *func_L01_004618E0(s32 size);

/* localdecomp:start func_L01_004702E0 */
typedef struct {
    u8 pad0[0x10];
    s128 pos;
    s8 state;
    u8 pad21[0xC0 - 0x21];
    s128 x;
    s128 y;
    s128 z;
} M_004702E0;
typedef struct {
    M_004702E0 *owner;
    s32 joint;
    f32 speed;
    u8 face;
    u8 spin;
    u8 glow;
    u8 keep;
    s128 off;
} A_004702E0;
typedef struct {
    u8 pad0[4];
    u32 color;
    u8 b8;
    u8 pad9;
    s16 timer;
    f32 size;
    s128 pos;
    A_004702E0 a;
} P_004702E0;

extern s32 func_0038CB00(s16 *);
extern void func_003CD250(Obj *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern vu0_v4 D_L01_001E29C0_004702E0;

void func_L01_004702E0(P_004702E0 *p)
{
    A_004702E0 *a = &p->a;
    M_004702E0 *m;
    vu0_v4 w[4];
    f32 d;
    f32 max = 255.0f;

    if (p->timer >= 0 && func_0038CB00(&p->timer) != 0) {
        func_003CD250((Obj *)p);
        return;
    }
    m = a->owner;
    if (m != 0) {
        if (m->state < 0) {
            func_003CD250((Obj *)p);
            return;
        }
        if (a->joint >= 0) {
            func_003C2EC0(m, a->joint, w);
            func_0038D000(&p->pos, &a->off, w);
            vec_add_ab(&p->pos, &p->pos, &w[3]);
            ((f32 *)&p->pos)[3] = 0.0f;
        } else {
            p->pos = m->pos;
            func_0038D000(w, &a->off, &m->x);
            vec_add_ab(&p->pos, &p->pos, w);
            if (a->glow) {
                vec_sub_ba(&w[1], &p->pos, &D_L01_001E29C0_004702E0);
                p->b8 = func_0038CE68(&w[1], (u8 *)&D_L01_001E29C0_004702E0 + 0x20) * 6.0f;
            }
            if (a->face) {
                switch (a->face) {
                case 1:
                    vec_sub_ba(&w[2], &p->pos, &m->pos);
                    func_0038CF68(&w[2], &w[2], 1.0f);
                    break;
                case 2:
                    *(s128 *)&w[2] = m->x;
                    break;
                case 3:
                    *(s128 *)&w[2] = m->x;
                    vec_neg(&w[2], &w[2]);
                    break;
                case 4:
                    *(s128 *)&w[2] = m->y;
                    break;
                case 5:
                    *(s128 *)&w[2] = m->y;
                    vec_neg(&w[2], &w[2]);
                    break;
                case 6:
                    *(s128 *)&w[2] = m->z;
                    break;
                case 7:
                    *(s128 *)&w[2] = m->z;
                    vec_neg(&w[2], &w[2]);
                    break;
                }
                vec_sub_ba(&w[1], &p->pos, &D_L01_001E29C0_004702E0);
                func_0038CF68(&w[1], &w[1], 1.0f);
                d = -func_0038CE68(&w[1], &w[2]);
                d = d * 1.25f + 0.05f;
                if (d < 0.0f) {
                    p->color &= 0x5FFFFFF;
                } else {
                    if (d > 1.0f) {
                        d = 1.0f;
                    }
                    if (a->keep) {
                        s32 t = (f32)((p->color & 0xFF000000) >> 24) * d;
                        p->color = (p->color & 0xFFFFFF) | (t << 24);
                    } else {
                        s32 t = d * max;
                        p->color = (p->color & 0xFFFFFF) | (t << 24);
                    }
                }
            }
        }
    } else {
        p->pos = a->off;
    }
    p->size *= ((f32 *)&a->off)[3];
    p->b8 += a->spin;
    vec_sub_ba(w, &D_L01_001E29C0_004702E0, &p->pos);
    func_0038CF68(w, w, a->speed);
    vec_add_ab(&p->pos, &p->pos, w);
}
/* localdecomp:end func_L01_004702E0 */

/* localdecomp:start func_L01_00470668 */
typedef int Quad_470668 __attribute__((mode(TI)));
typedef struct {
    u8 type;
    s8 flags;
    u8 texture;
    u8 render;
    s32 rgba;
    u8 spin;
    u8 render2;
    s16 life;
    s32 end_rgba;
    Quad_470668 head;
    vu0_v4 vel;
    Quad_470668 tail;
} Spark_470668;

extern u8 *D_L01_00221200[];
extern void func_0038CF68(void *, void *, f32);

Spark_470668 *func_L01_00470668(Quad_470668 *head, Quad_470668 *tail, s32 life, f32 w)
{
    Spark_470668 *s = ((Spark_470668 * (*)(s32))func_L01_004618E0)(0x5A);
    vu0_v4 tmp;
    Quad_470668 *q;

    if (s != 0) {
        s->rgba = 0x7FFFFFFF;
        s->end_rgba = 0x7FFFFFFF;
        s->render2 = 0x22;
        s->render = 0x48;
        s->flags = 3;
        q = &s->tail;
        s->texture = *D_L01_00221200[0];
        *q = *tail;
        ((f32 *)q)[3] = w;
        s->head = *head;
        func_0038CF68(&tmp, q, 0.9f);
        vec_sub_ab(&s->vel, head, &tmp);
        s->life = life;
        ((f32 *)&s->head)[3] = 0.05f;
        ((f32 *)&s->vel)[3] = 2.0f;
        s->spin = (u8)s->life - 12;
    }
    return s;
}
/* localdecomp:end func_L01_00470668 */

/* localdecomp:start func_L01_00470770 */
#include "vu0.h"
/* vu0_s: a 128-bit struct with TImode, so its "m" operands are TImode MEMs (dependences tracked per offset). */
typedef struct { vu0_q q; } vu0_s;

/* vec_add_ba4yv(): d = a + b as one statement: lqc2 b, lqc2 a, vadd into a's register, sqc2 (vu0_v4 operands) */
static __inline__ void vec_add_ba4yv(void *d, void *a, void *b) {
    vu0_q qa, qb;
    __asm__("lqc2 %1, %4\n\tlqc2 %2, %3\n\tvadd.xyz %2, %2, %1\n\tsqc2 %2, %0" : "=m"(*(vu0_v4 *)d), "=&j"(qb), "=&j"(qa) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b));
}

/* vec_sub_ba4y(): d = a - b as one statement: lqc2 b, lqc2 a, vsub into a's register, sqc2 (vu0_s operands) */
static __inline__ void vec_sub_ba4y(void *d, void *a, void *b) {
    vu0_q qa, qb;
    __asm__("lqc2 %1, %4\n\tlqc2 %2, %3\n\tvsub.xyz %2, %2, %1\n\tsqc2 %2, %0" : "=m"(*(vu0_s *)d), "=&j"(qb), "=&j"(qa) : "m"(*(vu0_s *)a), "m"(*(vu0_s *)b));
}
extern s32 func_0038CB00(s16 *);
extern s32 func_00382468(s32);
extern void func_0038CF68(void *, void *, f32);
extern u8 *D_L01_00221200[];
typedef struct {
    u8 b0, b1, b2, b3;
    u32 w4;
    u8 b8, b9;
    s16 hA;
    u32 wC;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
} P_470770;
void func_L01_00470770(P_470770 *p) {
    vu0_v4 old, d, prev;
    f32 *q = (f32 *)&p->v30;
    s32 a;
    if (func_0038CB00(&p->hA)) {
        func_003CD250((Obj *)p);
        return;
    }
    p->b2 = D_L01_00221200[0][func_00382468(2)];
    old = p->v10;
    vec_copy(&prev, &old);
    vec_add_ba4yv(&p->v10, &p->v10, &p->v30);
    vec_sub_ba4y(&d, &p->v10, &prev);
    func_0038CF68(&d, &d, 0.9f);
    vec_sub_ab(&p->v20, &p->v10, &d);
    p->v20.w = 2.0f;
    q[2] -= q[3];
    if (p->hA < p->b8) {
        a = (s32)((f32)p->hA / (f32)p->b8 * 127.0f);
        p->w4 = (a << 24) | (p->w4 & 0xFFFFFF);
        p->wC = (a << 24) | (p->wC & 0xFFFFFF);
    }
}
/* localdecomp:end func_L01_00470770 */
