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

/* localdecomp:start func_L01_0046A938 */



extern u8 *D_L01_0022114C[];
extern S_467288 *func_L01_004618E0(s32 size);
extern s32 func_00382468(s32);
extern s32 func_0013D3E0(void);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

S_467288 *func_L01_0046A938(Vec4 *a0, s32 a1, s32 a2, f32 f12, f32 f13) {
    S_467288 *p = func_L01_004618E0(45);
    if (p != 0) {
        S_467288_Sub *q;
        f32 ang;
        f32 r;
        s32 c;

        p->unk10 = *a0;
        if (a2 == -1) {
            c = ((func_00382468(6) + 20) << 24) | 0x808080;
        } else {
            c = a2;
        }
        p->unk04 = c;
        p->unk09 = 33;
        p->unk03 = 72;
        p->unk01 = 1;
        q = &p->sub;
        p->unk02 = *D_L01_0022114C[0];
        p->unk08 = func_0013D3E0();
        p->unk0A = 4;
        p->unk0C = f12 * 210000.0f;
        ang = func_00382538();
        r = func_003824E0(0.0015f, 0.0025f);
        p->sub.unk00 = func_0038D098(ang) * r;
        q->unk04 = func_0038D0B0(ang) * r;
        q->unk14 = a1;
        q->unk10 = f13;
        q->unk08 = 0;
    }
    return p;
}
/* localdecomp:end func_L01_0046A938 */

/* localdecomp:start func_L01_0046AA88 */
typedef struct {
    Vec4 vel;
    f32 f10;
    f32 *p14;
} Q_0046AA88;

typedef struct {
    u8 pad0[4];
    s32 c4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    Vec4 pos;
    Q_0046AA88 q;
} T_0046AA88;

__asm__(".extern D_L01_001D7F30, 4");
extern f32 D_L01_001D7F30;
extern void func_003CD250(Obj *);

void func_L01_0046AA88(T_0046AA88 *p) {
    Q_0046AA88 *q = &p->q;
    vec_add_ab(&p->pos, &p->pos, &q->vel);
    if (p->pos.x < 2.0f || p->pos.x > 1021.0f || p->pos.y < 2.0f || p->pos.y > 1021.0f || p->pos.z < 2.0f || p->pos.z > 1021.0f) {
        func_003CD250((Obj *)p);
        return;
    }
    p->fC += q->f10;
    p->b8++;
    if (q->p14 != 0) {
        p->pos.z = *q->p14 + D_L01_001D7F30;
    }
    p->hA--;
    if (p->hA == 0) {
        p->c4 += 0xFF000000;
        p->hA = 4;
    }
    if ((p->c4 & 0xFF000000) == 0) {
        func_003CD250((Obj *)p);
    }
}
/* localdecomp:end func_L01_0046AA88 */

/* localdecomp:start func_L01_0046ABC0 */
extern S_467288 *func_L01_004618E0(s32 size);


extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern u8 *D_L01_00221150[];

u8 *func_L01_0046ABC0(s128_467510 *pos, s128_467510 *dir, int life, f32 scale, f32 g) {
    u8 *m = ((u8 * (*)(s32))func_L01_004618E0)(46);
    P_467510 *p;

    if (m != 0) {
        *(s128_467510 *)(m + 0x10) = *pos;
        p = (P_467510 *)(m + 0x20);
        *(u32 *)(m + 4) = ((func_00382468(10) + 38) << 24) | 0x808080;
        m[9] = 33;
        m[3] = 72;
        m[1] = 1;
        m[2] = *D_L01_00221150[0];
        *(s16 *)(m + 10) = 5;
        *(f32 *)(m + 12) = scale * 210000.0f;
        p->q0 = *dir;
        p->f10 = func_003824E0(0.0f, 256.0f);
        m[8] = (int)p->f10;
        p->f14 = g;
        p->f18 = life;
    }
    return m;
}
/* localdecomp:end func_L01_0046ABC0 */

/* localdecomp:start func_L01_0046ACD0 */
typedef struct {
    Vec4 vel;
    f32 f10;
    f32 f14;
    f32 *p18;
} Q_0046ACD0;

typedef struct {
    u8 pad0[4];
    s32 c4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    Vec4 pos;
    Q_0046ACD0 q;
} T_0046ACD0;

extern void func_003CD250(Obj *);

void func_L01_0046ACD0(T_0046ACD0 *p) {
    Q_0046ACD0 *q = &p->q;
    f32 t;
    vec_add_ab(&p->pos, &p->pos, &q->vel);
    p->fC += 5880.0f;
    q->f14 = q->f14 * 0.98f;
    q->f10 = q->f10 + q->f14;
    p->b8 = (s32)q->f10;
    if (q->p18 != 0) {
        t = *q->p18;
        if (fabs_asm(p->pos.z - t) < 0.2f) {
            p->pos.z = t + 0.02f;
        }
    }
    p->hA--;
    if (p->hA == 0) {
        p->c4 += 0xFF000000;
        p->hA = 1;
    }
    if ((p->c4 & 0xFF000000) == 0) {
        func_003CD250((Obj *)p);
    }
}
/* localdecomp:end func_L01_0046ACD0 */

/* localdecomp:start func_L01_0046ADE0 */
extern S_467288 *func_L01_004618E0(s32 size);

extern u8 *D_L01_00221154[];
extern s32 func_00382468(s32);

u8 *func_L01_0046ADE0(u128_t *a, u128_t *b, f32 size) {
    u8 *r;

    r = ((u8 * (*)(s32))func_L01_004618E0)(47);
    if (r != 0) {
        *(u128_t *)(r + 16) = *a;
        *(u32 *)(r + 4) = ((func_00382468(8) + 40) << 24) | 0x808080;
        r[9] = 34;
        r[3] = 72;
        r[1] = 0;
        r[2] = *D_L01_00221154[0];
        *(f32 *)(r + 12) = size;
        *(u128_t *)(r + 32) = *b;
        r[8] = func_00382468(256);
    }
    return r;
}
/* localdecomp:end func_L01_0046ADE0 */

/* localdecomp:start func_L01_0046AE98 */
typedef struct {
    Vec4 vel;
    u8 b10;
} Q_0046AE98;

typedef struct {
    u8 pad0[4];
    s32 c4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    Vec4 pos;
    Q_0046AE98 q;
} T_0046AE98;

extern void func_0038CE20(void *, void *, f32);
extern void func_003CD250(Obj *);

void func_L01_0046AE98(T_0046AE98 *p) {
    Q_0046AE98 *q = &p->q;
    func_0038CE20(q, q, 0.975f);
    vec_add_ab(&p->pos, &p->pos, &q->vel);
    p->fC += 14700.0f;
    p->b8 += q->b10;
    p->c4 += 0xFE000000;
    if (p->c4 < 0) {
        func_003CD250((Obj *)p);
    }
}
/* localdecomp:end func_L01_0046AE98 */

LINKER_REMNANT("asm/levels", func_L01_0046AF30);

/* localdecomp:start func_L01_0046AF38 */
typedef struct {
    Vec4 vel;
    f32 f10;
    s32 i14;
    s32 i18;
    u8 b1C;
} Q_0046AF38;

typedef struct {
    u8 pad0[4];
    s32 c4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    Vec4 pos;
    Q_0046AF38 q;
} T_0046AF38;

extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_0038CB00(s16 *);
extern void func_003CD250(Obj *);

void func_L01_0046AF38(T_0046AF38 *p) {
    Q_0046AF38 *q = &p->q;
    p->b8 += q->b1C;
    vec_add_ab(&p->pos, &p->pos, &q->vel);
    p->c4 = func_0038DBD8(q->i18, q->i14, fabs_asm((f32)p->hA * q->f10 - 1.0f));
    if (func_0038CB00(&p->hA) != 0) {
        func_003CD250((Obj *)p);
    }
}
/* localdecomp:end func_L01_0046AF38 */

LINKER_REMNANT("asm/levels", func_L01_0046AFD0);

/* localdecomp:start func_L01_0046AFD8 */
typedef struct {
    f32 x, y, z;
    s32 i0C;
} Q_0046AFD8;

typedef struct {
    u8 pad0[0xA];
    s16 hA;
    f32 fC;
    Vec4 pos;
    Vec4 v20;
    Q_0046AFD8 q;
} T_0046AFD8;

extern s32 func_0038CB00(s16 *);
extern void func_003CD250(Obj *);
extern int func_003D3CB0(void *, void *, int, int, int);
extern Vec4 D_L01_001EAA20_0046AFD8;
void func_L01_0046AFD8(T_0046AFD8 *p) {
    Q_0046AFD8 *q = &p->q;
    Vec4 *v = &p->v20;
    Vec4 *pp = &p->pos;
    Vec4 d;

    d.x = q->x;
    d.y = q->y;
    d.z = q->z;
    d.w = 0.0f;
    vec_add_ab(pp, pp, &d);
    vec_add_ab(v, v, &d);
    if (func_0038CB00(&p->hA) != 0) {
        func_003CD250((Obj *)p);
    } else if (func_003D3CB0(v, pp, 0x10, q->i0C, 0) != 0) {
        *pp = D_L01_001EAA20_0046AFD8;
        p->hA = 0;
    }
}
/* localdecomp:end func_L01_0046AFD8 */

/* localdecomp:start func_L01_0046B0B8 */
typedef struct {
    f32 x, y, z, w;
    f32 floor;
    u8 increment;
    u8 pad[3];
    f32 gravity;
} Motion_46B0B8;
typedef struct {
    u8 a, b, c, d;
    s32 color;
    u8 angle, unused;
    s16 life;
    f32 size;
    vu0_v4 pos;
    Motion_46B0B8 motion;
} Particle_46B0B8;
extern u8 *D_L01_00221160[];
extern f32 D_L01_001D7F34;
__asm__(".extern D_L01_001D7F34, 4");
extern s32 func_0038CB00(s16 *);

void func_L01_0046B0B8(Particle_46B0B8 *p)
{
    Motion_46B0B8 *motion = &p->motion;
    if (func_0038CB00(&p->life)) {
        motion->z -= motion->gravity;
    }
    vec_add_ab(&p->pos, &p->pos, motion);
    p->angle += motion->increment;
    if (p->c == D_L01_00221160[0][0]) {
        p->size += D_L01_001D7F34 * 0.020000001f * 210000.0f;
    }
    if (p->pos.z < motion->floor) {
        func_003CD250((Obj *)p);
    }
}
/* localdecomp:end func_L01_0046B0B8 */

LINKER_REMNANT("asm/levels", func_L01_0046B190);

/* localdecomp:start func_L01_0046B198 */
extern void func_0038CE38(void *, void *, f32);

void func_L01_0046B198(u8 *p)
{
    vu0_v4 v;
    vu0_q qa;
    vu0_q qb;
    vu0_q qr;
    u32 x;
    f32 *q = (f32 *)(p + 0x20);

    func_0038CE38(&v, q, 0.95f);
    q[2] += 0.002f;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(p + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(p + 0x20)));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(p + 0x10)) : "j"(qr));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(qr));
    x = *(u32 *)(p + 4) + 0xFE000000;
    *(u32 *)(p + 4) = x;
    if ((x & 0xFF000000) - 1 > 0x5EFFFFFF || func_0038CB00((s16 *)(p + 0xA)) != 0) {
        func_003CD250((Obj *)p);
    } else {
        f32 f = *(f32 *)(p + 0xC);
        p[8]++;
        *(f32 *)(p + 0xC) = f + (210000.0f - f) * 0.07f;
    }
}
/* localdecomp:end func_L01_0046B198 */

/* localdecomp:start func_L01_0046B288 */
typedef struct {
    f32 f0;
    f32 f4;
    s32 i8;
    s32 iC;
    f32 f10;
} Q_0046B288;

typedef struct {
    u8 b0, b1, b2, b3;
    s32 c4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    u128_t v10;
    Q_0046B288 q;
} T_0046B288;

extern S_467288 *func_L01_004618E0(s32 size);
extern u8 *D_L01_00221168[];
extern s32 func_00382468(s32);

T_0046B288 *func_L01_0046B288(u128_t *pos, s32 color, s32 a2, s32 life, f32 size, f32 f13) {
    T_0046B288 *m = ((T_0046B288 * (*)(s32))func_L01_004618E0)(0x34);
    Q_0046B288 *q;
    if (m != 0) {
        m->v10 = *pos;
        m->b3 = 0x44;
        m->b9 = 0x22;
        m->b1 = 1;
        m->c4 = color;
        ((f32 *)&m->v10)[2] += 0.05f;
        m->b2 = *D_L01_00221168[0];
        m->hA = life;
        m->fC = size * 210000.0f;
        q = &m->q;
        m->b8 = func_00382468(255);
        q->i8 = color;
        q->iC = a2;
        q->f0 = size;
        q->f4 = f13;
        q->f10 = 1.0f / (f32)life;
    }
    return m;
}
/* localdecomp:end func_L01_0046B288 */

/* localdecomp:start func_L01_0046B3A8 */


extern s32 func_0038CB00(s16 *);
extern void func_003CD250(Obj *);
extern void func_L01_004CAB30(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);

void func_L01_0046B3A8(Obj *o) {
    Sub *s;
    f32 t;

    if (func_0038CB00(&o->timer) != 0) {
        func_003CD250(o);
        return;
    }
    s = &o->sub;
    func_L01_004CAB30(o->vec, o->vec);
    t = o->timer * s->scale;
    o->result = func_0038DBD8(s->a, s->b, t);
    o->out = ((o->sub.target - s->base) * t + s->base) * 210000.0f;
}
/* localdecomp:end func_L01_0046B3A8 */

/* localdecomp:start func_L01_0046B458 */
extern S_467288 *func_L01_004618E0(s32 size);

extern u8 *D_L01_0022116C[];
extern s32 func_00382468(s32);

#define U8(p, o) (*(u8 *)((p) + (o)))
#define S16(p, o) (*(s16 *)((p) + (o)))
#define S32(p, o) (*(s32 *)((p) + (o)))
#define F32(p, o) (*(f32 *)((p) + (o)))

u8 *func_L01_0046B458(s128 *pos, s32 id, s32 color, s32 mode, s32 b, f32 *v, s32 n, f32 sx, f32 sy, f32 z) {
    u8 *o;
    u8 *p;
    f32 *q;
    u8 t;

    o = ((u8 * (*)(s32))func_L01_004618E0)(53);
    if (o != 0) {
        p = o + 32;
        *(s128 *)(o + 16) = *pos;
        F32(o, 28) = (f32)n;
        F32(o, 24) += 0.05f;
        U8(o, 3) = 72;
        S32(o, 4) = color;
        U8(o, 9) = 32;
        U8(o, 1) = 0;
        t = *D_L01_0022116C[0];
        S16(o, 10) = id;
        U8(o, 2) = t;
        F32(o, 12) = sx * 210000.0f;
        if (mode == 0) {
            U8(o, 8) = 0;
        } else if (mode == 1) {
            U8(o, 8) = 32;
        } else {
            U8(o, 8) = func_00382468(255);
        }
        F32(p, 0) = F32(o, 12);
        S16(p, 8) = id;
        F32(p, 4) = sy * 210000.0f;
        U8(p, 10) = b;
        U8(p, 11) = color >> 24;
        F32(p, 24) = z;
        q = (f32 *)(p + 12);
        q[0] = v[0];
        q[1] = v[1];
        q[2] = v[2];
    }
    return o;
}
/* localdecomp:end func_L01_0046B458 */

INCLUDE_ASM("asm/levels", func_L01_0046B5F0);

LINKER_REMNANT("asm/levels", func_L01_0046B890);

INCLUDE_ASM("asm/levels", func_L01_0046B898);

/* localdecomp:start func_L01_0046B9E8 */
typedef struct {
    u8 *p0;
    s32 i4;
    s32 i8;
    f32 fC;
} Q_0046B9E8;

typedef struct {
    u8 b0, b1, b2, b3;
    s32 c4;
    u8 b8, b9;
    s16 hA;
    s32 iC;
    u128_t v10;
    u128_t v20;
    Q_0046B9E8 q;
} T_0046B9E8;

extern u8 *D_L01_00221174[];
extern void func_003C2F58(void *, s32, void *);

T_0046B9E8 *func_L01_0046B9E8(u8 *a0, s32 a1, s32 a2, f32 f12, s32 a3, f32 f13) {
    T_0046B9E8 *m = ((T_0046B9E8 * (*)(s32))func_L01_004618E0)(0x37);
    Q_0046B9E8 *q;
    if (m != 0) {
        m->c4 = a2;
        m->iC = a3;
        m->b9 = 0x20;
        m->b3 = 0x48;
        m->b1 = 3;
        m->b2 = *D_L01_00221174[0];
        if (a1 > 0) {
            func_003C2F58(a0, a1, &m->v10);
        } else {
            m->v10 = *(u128_t *)(a0 + 0x10);
        }
        m->v20 = m->v10;
        ((f32 *)m)[7] = f12;
        ((f32 *)m)[11] = f13;
        q = &m->q;
        q->p0 = a0;
        q->i8 = *(s16 *)(a0 + 0xAA);
        q->i4 = a1;
        q->fC = f12;
    }
    return m;
}
/* localdecomp:end func_L01_0046B9E8 */

/* localdecomp:start func_L01_0046BAE0 */
#include "vu0.h"

typedef struct {
    u8 *moby;
    s32 c4;
    s32 id;
    f32 fC;
} Q_0046BAE0;
typedef struct {
    u8 pad[0x10];
    vu0_v4 pos;
    vu0_v4 v20;
    Q_0046BAE0 q;
} T_0046BAE0;

extern void func_003CD250(Obj *);
extern f32 func_003824E0(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);

void func_L01_0046BAE0(T_0046BAE0 *o) {
    Q_0046BAE0 *q = &o->q;
    u8 *m = q->moby;
    vu0_v4 t;
    f32 s;
    f32 w;
    vu0_v4 *pos;

    if (m == 0 || *(s16 *)(m + 0xAA) != q->id || m[0x20] == 0xFE || m[0x20] == 0xFD) {
        func_003CD250((Obj *)o);
        return;
    }
    pos = &o->pos;
    s = q->fC * func_003824E0(0.5f, 1.0f);
    w = o->v20.w;
    t = o->pos;
    if (q->c4 > 0) {
        func_003C2F58(q->moby, q->c4, pos);
    } else {
        o->pos = ((T_0046BAE0 *)q->moby)->pos;
    }
    if (func_0038CF00(pos, &o->v20) > 1.5f) {
        vec_sub_ba(&t, &t, &o->pos);
        func_0038CF68(&t, &t, 1.5f);
        vec_add_ab(&o->v20, &o->pos, &t);
    }
    o->pos.w = s;
    o->v20.w = w;
}
/* localdecomp:end func_L01_0046BAE0 */

LINKER_REMNANT("asm/levels", func_L01_0046BC10);

/* localdecomp:start func_L01_0046BC18 */
typedef struct {
    u8 b0, b1, b2, b3;
    u8 b4, b5, b6, b7;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    Vec4 pos;
    Vec4 vel;
} T_0046BC18;

extern void func_0038CE20(void *, void *, f32);
extern void func_003CD250(Obj *);

void func_L01_0046BC18(T_0046BC18 *p) {
    s32 t;
    func_0038CE20(&p->vel, &p->vel, 0.975f);
    vec_add_ab(&p->pos, &p->pos, &p->vel);
    p->fC += 6300.0f;
    t = p->b4 - 4;
    if (t <= 0) {
        func_003CD250((Obj *)p);
    } else {
        *(s32 *)&p->b4 = 0x60000000 | (t << 16) | (t << 8) | t;
    }
}
/* localdecomp:end func_L01_0046BC18 */

/* localdecomp:start func_L01_0046BCB0 */
typedef struct {
    Vec4 vel;
    f32 f10;
    f32 f14;
} Q_0046BCB0;

typedef struct {
    u8 pad0[4];
    s32 c4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    Vec4 pos;
    Q_0046BCB0 q;
} T_0046BCB0;

extern void func_003CD250(Obj *);

void func_L01_0046BCB0(T_0046BCB0 *p) {
    Q_0046BCB0 *q = &p->q;
    s32 t;
    vec_add_ab(&p->pos, &p->pos, &q->vel);
    p->fC += 5880.0f;
    q->f14 = q->f14 * 0.98f;
    q->f10 = q->f10 + q->f14;
    p->b8 = (s32)q->f10;
    p->hA--;
    if (p->hA <= 0) {
        func_003CD250((Obj *)p);
    }
    t = p->hA;
    if (t > 0x40) {
        p->c4 = ((0x80 - t) << 24) | 0x808080;
    } else {
        p->c4 = (t << 24) | 0x808080;
    }
}
/* localdecomp:end func_L01_0046BCB0 */

/* localdecomp:start func_L01_0046BD88 */
typedef struct {
    u8 v[16];
    u8 c10, c11, c12, c13, c14, c15, c16, c17;
    s32 w18;
    f32 f1C;
} T_0046BD88_Sub_0046BD88;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    s16 h0A;
    f32 f0C;
    s128 q10;
    T_0046BD88_Sub_0046BD88 sub;
} T_0046BD88;

extern S_467288 *func_L01_004618E0_0046BD88(s32 size);
extern s32 func_0013D3E0(void);
extern u8 *D_L01_00221180_0046BD88[];
extern f32 func_L01_004439C0_0046BD88(f32, f32);
extern f32 func_L01_00443A78_0046BD88(void);
extern void func_L01_00443E10_0046BD88(void *, f32, f32, f32);

u8 *func_L01_0046BD88(void *pos, u8 type, u8 a2, u8 a3, u8 a4, u8 a5, s32 a6, f32 f12, f32 f13) {
    T_0046BD88 *o = (T_0046BD88 *)func_L01_004618E0_0046BD88(0x3A);
    if (o != 0) {
        f32 x, y;
        s32 t;
        s32 k;
        T_0046BD88_Sub_0046BD88 *p;

        o->q10 = *(s128 *)pos;
        p = &o->sub;
        o->b9 = 0x70;
        o->b3 = 0x44;
        o->b1 = 0;
        o->b2 = D_L01_00221180_0046BD88[0][func_0013D3E0() & 7];
        o->f0C = 21000.0f;
        o->b8 = func_0013D3E0();
        p->c10 = type;
        p->c12 = a3;
        p->c13 = a4;
        p->w18 = a6;
        p->f1C = f12;
        p->c11 = a2;
        p->c15 = a5;
        k = p->c10;
        switch (k) {
        case 0:
        case 1:
            o->h0A = a2;
            o->w4 = 0xFF808080;
            p->c14 = 0;
            break;
        case 2:
            x = func_L01_004439C0_0046BD88(3.0f, 9.0f) * f13 * 0.020000001f;
            y = func_L01_00443A78_0046BD88();
            func_L01_00443E10_0046BD88(p->v, x, y, func_L01_004439C0_0046BD88(1.3439035f, 1.7976891f));
            o->f0C = 42000.0f;
            t = (func_0013D3E0() & 0x1F) + 0x10;
            p->c16 = t;
            o->w4 = (p->c16 << 24) | 0x808080;
            o->h0A = a5;
            p->c14 = k;
            break;
        }
    }
    return (u8 *)o;
}
/* localdecomp:end func_L01_0046BD88 */

/* localdecomp:start func_L01_0046BF78 */
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003C4C18(void *, f32);
extern u8 *func_L01_0046BD88(void *, u8, u8, u8, u8, u8, s32, f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446A70(s32, s32, s32, void *, void *, f32);
extern s32 func_0013D3E0(void);
extern Vec4 D_001A4C60;
extern u8 *D_L01_00221180[];
extern u8 *D_L01_001E0278;

void func_L01_0046BF78(u8 *o)
{
    u8 *c = o + 0x20;
    u8 *h;
    u8 *hp;
    vu0_v4 t;
    f32 f;
    f32 sc;
    s32 i;
    s32 r;

    switch (c[0x14]) {
    case 0:
        *(s32 *)(o + 4) = func_0038DBD8(0xFF4080FF, 0, ((f32)c[0x11] - (f32)*(s16 *)(o + 0xA)) / (f32)c[0x11]);
        if (func_0038CB00((s16 *)(o + 0xA)) == 0) {
            return;
        }
        if (c[0x10] == 1) {
            func_003CD250((Obj *)o);
            return;
        }
        c[0x14] = 1;
        *(s16 *)(o + 0xA) = c[0x12];
        return;
    case 1:
        i = 0;
        if (c[0x13] != 0) {
            do {
                t = *(vu0_v4 *)(o + 0x10);
                func_003C4C18(&t, 0.05f);
                sc = 1.0f;
                if (*(s16 *)(o + 0xA) < 8) {
                    sc = (f32)*(s16 *)(o + 0xA) * 0.125f;
                }
                i++;
                func_L01_0046BD88(&t, 2, c[0x11], c[0x12], c[0x13], c[0x15], *(s32 *)(c + 0x18), *(f32 *)(c + 0x1C), sc);
            } while (i < c[0x13]);
        }
        if (func_0038CB00((s16 *)(o + 0xA)) != 0) {
            func_003CD250((Obj *)o);
        }
        if (func_0038CF38(o + 0x10, (u8 *)&D_001A4C60) < 0.3f) {
            hp = (u8 *)&D_001A4C60;
            h = hp - 0x80;
            if (*(f32 *)(h + 0x88) < *(f32 *)(o + 0x18) + 1.2f) {
                vec_sub_ab(&t, hp, o + 0x10);
                func_0038CF68(&t, &t, 1.0f);
                t.z = 1.0f;
                func_L01_00446A70(*(s32 *)(h + 0x25C0), *(s32 *)(c + 0x18), 1, o + 0x10, &t, *(f32 *)(c + 0x1C));
            }
        }
        return;
    case 2:
        vec_add_ab(o + 0x10, o + 0x10, o + 0x20);
        f = ((f32)c[0x15] - (f32)*(s16 *)(o + 0xA)) / (f32)c[0x15];
        *(s32 *)(o + 4) = func_0038DBD8((c[0x16] << 24) | 0x4060, 0x8FAFFF, f);
        if (f < 0.6f) {
            *(f32 *)(o + 0xC) = *(f32 *)(o + 0xC) + 10836.001f;
        } else {
            *(f32 *)(o + 0xC) = *(f32 *)(o + 0xC) - 20160.0f;
        }
        r = func_0013D3E0();
        o[2] = D_L01_00221180[0][r & 7];
        if (((o - D_L01_001E0278) >> 6) & 1) {
            o[8] = o[8] + 1;
        } else {
            o[8] = o[8] - 1;
        }
        if (func_0038CB00((s16 *)(o + 0xA)) != 0) {
            func_003CD250((Obj *)o);
        }
        return;
    }
}
/* localdecomp:end func_L01_0046BF78 */

/* localdecomp:start func_L01_0046C2E8 */
typedef struct {
    Vec4 v;
    s32 i10;
    u8 *i14;
} Q_0046C2E8;

typedef struct {
    u8 b0, b1, b2, b3;
    s32 c4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    u128_t v10;
    Q_0046C2E8 q;
} T_0046C2E8;

extern S_467288 *func_L01_004618E0(s32 size);
extern u8 *D_001A71A0[];
extern u8 *D_L01_00221098[];

T_0046C2E8 *func_L01_0046C2E8(u128_t *pos, s32 color, u8 a2, s32 a3, s32 flag, s32 life, s32 t2, u8 *t3, f32 size) {
    T_0046C2E8 *m = ((T_0046C2E8 * (*)(s32))func_L01_004618E0)(0x3B);
    Q_0046C2E8 *q;
    u8 *g;
    if (m != 0) {
        q = &m->q;
        q->i14 = t3;
        q->i10 = t2;
        g = D_001A71A0[0];
        q->i14 = g;
        if (t2 == 1) {
            if (g != 0) {
                vec_sub_ba(&q->v, pos, g + 0x10);
            }
        }
        m->v10 = *pos;
        m->c4 = color;
        m->b9 = 0x21;
        if (flag != 0) {
            m->b3 = 0x44;
        } else {
            m->b3 = 0x48;
        }
        m->b8 = a2;
        m->fC = size * 210000.0f;
        m->b1 = 0;
        m->b2 = *D_L01_00221098[a3];
        m->hA = life;
    }
    return m;
}
/* localdecomp:end func_L01_0046C2E8 */

INCLUDE_ASM("asm/levels", func_L01_0046C418);

/* localdecomp:start func_L01_0046C470 */
extern S_467288 *func_L01_004618E0(s32 size);



extern Vec4 D_001A4C60;
extern u8 *D_L01_0022116C[];

S_468DC0 *func_L01_0046C470(Vec4 *a0, f32 *a1, s32 a2, s32 a3, u8 t0, s32 t1, s32 t2, s32 t3, f32 f12) {
    S_468DC0 *p = ((S_468DC0 * (*)(s32 size))func_L01_004618E0)(60);
    if (p != 0) {
        S_468DC0_Sub *q = &p->sub;
        p->unk10 = *a0;
        q->pos[0] = a1[0];
        q->pos[1] = a1[1];
        q->pos[2] = a1[2];
        q->unk0C = t3;
        q->unk1C = t1;
        if (t1 == 1) {
            Vec4 v = D_001A4C60;
            q->off[0] = p->unk10.x - v.x;
            q->off[1] = p->unk10.y - v.y;
            q->off[2] = p->unk10.z - v.z;
        }
        p->unk04 = a2;
        p->unk09 = ((t2 >> 5) << 4) + 1;
        p->unk03 = 72;
        p->unk0C = f12 * 210000.0f;
        p->unk08 = t0;
        p->unk01 = 0;
        p->unk02 = *D_L01_0022116C[0];
        p->unk0A = a3;
    }
    return p;
}
/* localdecomp:end func_L01_0046C470 */

/* localdecomp:start func_L01_0046C5C8 */
extern Vec4 D_001A4C60;
extern s32 func_0038DBD8(s32, s32, f32);

void func_L01_0046C5C8(u8 *p)
{
    f32 v[4] __attribute__((aligned(16)));
    f32 g[4] __attribute__((aligned(16)));
    u8 *q = p + 0x20;
    s32 life;

    v[3] = 0.0f;
    v[0] = *(f32 *)(p + 0x20);
    v[1] = *(f32 *)(q + 4);
    v[2] = *(f32 *)(q + 8);
    if (*(s32 *)(q + 0x1C) == 1) {
        *(u128_t *)g = *(u128_t *)&D_001A4C60;
        *(f32 *)(p + 0x10) = g[0] + *(f32 *)(q + 0x10);
        *(f32 *)(p + 0x14) = g[1] + *(f32 *)(q + 0x14);
        *(f32 *)(p + 0x18) = g[2] + *(f32 *)(q + 0x18);
        vec_add_ab(p + 0x10, p + 0x10, v);
        *(f32 *)(q + 0x10) = *(f32 *)(p + 0x10) - g[0];
        *(f32 *)(q + 0x14) = *(f32 *)(p + 0x14) - g[1];
        *(f32 *)(q + 0x18) = *(f32 *)(p + 0x18) - g[2];
    } else {
        vec_add_ab(p + 0x10, p + 0x10, v);
    }
    if (*(f32 *)(p + 0x10) < 2.0f || 1021.0f < *(f32 *)(p + 0x10) ||
        *(f32 *)(p + 0x14) < 2.0f || 1021.0f < *(f32 *)(p + 0x14) ||
        *(f32 *)(p + 0x18) < 2.0f || 1021.0f < *(f32 *)(p + 0x18) ||
        func_0038CB00((s16 *)(p + 0xA)) != 0) {
        func_003CD250((Obj *)p);
        return;
    }
    life = *(s16 *)(p + 0xA);
    if (life < 250) {
        *(s32 *)(p + 4) = func_0038DBD8(*(s32 *)(p + 4) & 0xFFFFFF, *(s32 *)(p + 4), (f32)(life - 1) / (f32)life);
    }
}
/* localdecomp:end func_L01_0046C5C8 */

LINKER_REMNANT("asm/levels", func_L01_0046C788);

INCLUDE_ASM("asm/levels", func_L01_0046C790);

/* localdecomp:start func_L01_0046CA28 */
typedef struct {
    s16 h0;
    u8 b2;
    u8 b3;
} Q_0046CA28;

typedef struct {
    u8 b0, b1, b2, b3;
    s32 c4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    u128_t v10;
    Q_0046CA28 q;
} T_0046CA28;

__asm__(".extern D_L01_001D7F38, 4");
extern f32 D_L01_001D7F38;
extern S_467288 *func_L01_004618E0(s32 size);
extern u8 *D_L01_00221190[];
extern s32 func_00382468(s32);

T_0046CA28 *func_L01_0046CA28(u128_t *pos, s32 life, s32 a2, s32 a3) {
    T_0046CA28 *m = ((T_0046CA28 * (*)(s32))func_L01_004618E0)(0x3E);
    Q_0046CA28 *q;
    if (m != 0) {
        q = &m->q;
        m->v10 = *pos;
        m->fC = 30000.0f;
        m->c4 = 0x7F7F4040;
        m->b9 = 0x44;
        m->b3 = 0x48;
        m->b1 = 0;
        D_L01_001D7F38 = 30000.0f;
        m->b8 = func_00382468(255);
        q->b2 = a2;
        q->b3 = a3;
        if (a2 >= 2) {
            a2 = 0;
        }
        m->b2 = D_L01_00221190[0][a2];
        m->hA = life;
        q->h0 = (s32)(127.0f / (f32)life);
    }
    return m;
}
/* localdecomp:end func_L01_0046CA28 */

/* localdecomp:start func_L01_0046CB28 */
typedef struct T_0046CB28 T_0046CB28;
typedef struct {
    s16 h0;
    u8 b2;
    u8 b3;
    T_0046CB28 *p4;
    char pad8[0x10 - 0x8];
    f32 off[3];
} Q_0046CB28;
struct T_0046CB28 {
    u8 b0, b1, b2, b3;
    s32 c4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    f32 pos[4];
    Q_0046CB28 q;
};

__asm__(".extern D_L01_001D7F38_0046CB28, 4");
extern f32 D_L01_001D7F38_0046CB28;
extern s32 D_L01_001D6694_0046CB28;
extern void func_003CD250(Obj *);
extern void func_L01_004CAB30_0046CB28(void *, void *);

void func_L01_0046CB28(T_0046CB28 *m) {
    Q_0046CB28 *q = &m->q;
    s32 t;

    if (q == 0) {
        return;
    }
    if (D_L01_001D6694_0046CB28 == 7) {
        D_L01_001D7F38_0046CB28 = m->fC;
        m->fC = 0.0f;
    } else {
        m->fC = D_L01_001D7F38_0046CB28;
    }
    if (q->b2 != 1) {
        if (q->b2 == 2) {
            Q_0046CB28 *q2 = &m->q;
            m->pos[0] = q2->p4->pos[0] + q2->off[0];
            m->pos[1] = q2->p4->pos[1] + q2->off[1];
            m->pos[2] = q2->p4->pos[2] + q2->off[2];
        }
        t = m->c4 >> 24;
        t -= q->h0;
        if (t <= 0) {
            func_003CD250((Obj *)m);
            return;
        }
        m->c4 = (m->c4 & 0xFFFFFF) | (t << 24);
    }
    if (q->b3 != 0) {
        func_L01_004CAB30_0046CB28(m->pos, m->pos);
    }
}
/* localdecomp:end func_L01_0046CB28 */

LINKER_REMNANT("asm/levels", func_L01_0046CC18);

/* localdecomp:start func_L01_0046CC20 */
extern void func_003CD250(Obj *);
extern s32 func_0038CB00(s16 *);
void func_L01_0046CC20(u8 *a0) {
    if (((s32 (*)(u8 *))func_0038CB00)(a0 + 10)) {
        ((void (*)(u8 *))func_003CD250)(a0);
    }
}
/* localdecomp:end func_L01_0046CC20 */

INCLUDE_ASM("asm/levels", func_L01_0046CC58);

/* localdecomp:start func_L01_0046CDA8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_46CDA8;
extern s32 D_L01_001D7F50;
__asm__(".extern D_L01_001D7F50, 4");
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void *func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
typedef struct { u8 pad[16]; V_46CDA8 pos, vel; } Particle_46CDA8;

void func_L01_0046CDA8(u8 *obj)
{
    u8 *rec = obj + 0x20;
    u8 *position;

    if (func_0038CB00((s16 *)(obj + 0xA))) {
        *(f32 *)(rec + 8) -= *(f32 *)(rec + 0x14);
    }
    vec_add_ab(&((Particle_46CDA8 *)obj)->pos, &((Particle_46CDA8 *)obj)->pos, &((Particle_46CDA8 *)obj)->vel);
    position = obj + 0x10;
    {
        f32 height = *(f32 *)(obj + 0x18);
        obj[8] += 2;
        if (height < *(f32 *)(rec + 0x10)) {
            if (!func_00382468(D_L01_001D7F50 - 1)) {
                *(f32 *)(obj + 0x18) = *(f32 *)(rec + 0x10);
                *(f32 *)(obj + 0x20) *= func_003824E0(1.0f, 3.5f);
                *(f32 *)(rec + 4) *= func_003824E0(1.0f, 3.5f);
                *(f32 *)(rec + 8) *= func_003824E0(-1.0f, -1.5f);
                func_L01_00465738(position, rec, *(s32 *)(obj + 4), *(s32 *)(rec + 0x18), func_00382498(50, 100), 0, obj[2], obj[3], 0, *(f32 *)(obj + 0xC) * 0.5f);
            } else {
                *(f32 *)(obj + 0x18) = *(f32 *)(rec + 0x10);
                *(f32 *)(obj + 0x20) += func_003824E0(-5.0f, 5.0f) * 0.020000001f;
                *(f32 *)(rec + 4) += func_003824E0(-5.0f, 5.0f) * 0.020000001f;
                *(f32 *)(rec + 8) *= func_003824E0(-0.5f, -1.0f);
                func_L01_00465738(position, rec, *(s32 *)(obj + 4), *(s32 *)(rec + 0x18), func_00382498(25, 50), 0, obj[2], obj[3], 0, *(f32 *)(obj + 0xC) * 0.25f);
            }
            func_003CD250((Obj *)obj);
        }
    }
}
/* localdecomp:end func_L01_0046CDA8 */

/* localdecomp:start func_L01_0046CFD8 */
typedef struct {
    f32 x, y, z;
    f32 wC;
    f32 r, g, b, a;
} Q_0046CFD8;

typedef struct {
    u8 pad0[4];
    u32 rgba;
    u8 b8;
    u8 pad9;
    s16 hA;
    f32 fC;
    Vec4 pos;
    Q_0046CFD8 q;
} T_0046CFD8;

extern s32 func_0038CB00(s16 *);
extern void func_003CD250(Obj *);
extern int func_003D3CB0(void *, void *, int, int, int);
extern s32 func_L01_00448CC0_0046CFD8(f32, f32, f32, f32);
extern Vec4 D_L01_001EAA20_0046CFD8;

void func_L01_0046CFD8(T_0046CFD8 *p) {
    Q_0046CFD8 *q;
    Vec4 d;

    if (p == 0) {
        return;
    }
    q = &p->q;
    q->a += 0.0f;
    p->fC += -120.00001f;
    vec_add_ab(&d, &p->pos, q);
    if (q->x != 0.0f || q->y != 0.0f || q->z != 0.0f) {
        if (func_003D3CB0(&p->pos, &d, 2, (int)p, 0) != 0) {
            p->pos = D_L01_001EAA20_0046CFD8;
            qzero(q);
            p->fC += p->fC;
        } else {
            p->pos = d;
            if (q->wC != 0.0f) {
                q->z += q->wC;
            } else {
                q->z += -0.009072f;
            }
        }
    }
    if (q->a <= 0.0f || func_0038CB00(&p->hA) != 0 || p->fC < 0.0f ||
        d.x < 0.01f || d.y < 0.01f || d.z < 0.01f) {
        func_003CD250((Obj *)p);
        return;
    }
    q->r += -0.012f;
    if (q->r < 0.0f) {
        q->r = 0.0f;
    }
    q->g += -0.036012f;
    if (q->g < 0.0f) {
        q->g = 0.0f;
    }
    q->b += -0.060000002f;
    if (q->b < 0.0f) {
        q->b = 0.0f;
    }
    q->a += 0.0f;
    if (q->a < 0.0f) {
        q->a = 0.0f;
    }
    p->rgba = func_L01_00448CC0_0046CFD8(q->r, q->g, q->b, q->a);
    p->b8--;
}
/* localdecomp:end func_L01_0046CFD8 */

/* localdecomp:start func_L01_0046D250 */
extern S_467288 *func_L01_004618E0(s32 size);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern s32 func_0013D3E0(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *D_L01_002211A0[];

P_469BA0 *func_L01_0046D250(u128_469BA0 *a, s32 color, f32 scale, f32 z) {
    P_469BA0 *p = ((void * (*)(s32))func_L01_004618E0)(66);
    Q_469BA0 *q;
    f32 ang;
    f32 r;
    s32 c;

    if (p != 0) {
        p->v10 = *a;
        if (color == -1) {
            c = ((func_00382468(6) + 20) << 24) | 0x808080;
        } else {
            c = color;
        }
        p->x4 = c;
        p->b9 = 33;
        p->b3 = 72;
        p->b1 = 1;
        if (func_00382468(256) & 1) {
            p->b2 = D_L01_002211A0[0][0];
        } else {
            p->b2 = D_L01_002211A0[0][1];
        }
        p->b8 = func_0013D3E0();
        q = &p->q;
        p->hA = 4;
        p->fC = scale * 210000.0f;
        ang = func_00382538();
        r = func_003824E0(0.0015f, 0.0025f);
        q->f0 = func_0038D098(ang) * r;
        q->f4 = func_0038D0B0(ang) * r;
        q->x8 = 0;
        q->f10 = z;
    }
    return p;
}
/* localdecomp:end func_L01_0046D250 */

/* localdecomp:start func_L01_0046D3B0 */
typedef struct {
    u8 pad0[4];
    s32 c4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    Vec4 pos;
    Vec4 vel;
    f32 f30;
} T_0046D3B0;

extern void func_003CD250(Obj *);

void func_L01_0046D3B0(T_0046D3B0 *p) {
    vec_add_ab(&p->pos, &p->pos, &p->vel);
    p->fC += p->f30;
    p->b8++;
    p->hA--;
    if (p->hA == 0) {
        p->c4 += 0xFF000000;
        p->hA = 2;
    }
    if ((p->c4 & 0xFF000000) == 0) {
        func_003CD250((Obj *)p);
    }
}
/* localdecomp:end func_L01_0046D3B0 */

/* localdecomp:start func_L01_0046D440 */
extern S_467288 *func_L01_004618E0(s32 size);
extern u8 *D_L01_002211A4[];
extern s32 func_00382468(s32);
S_469D90 *func_L01_0046D440(s32 a0, void *pos, s32 life, s32 mode, s32 color, f32 *vel, f32 f12, f32 f13) {
    S_469D90 *p;
    S_469D90_Q *q;
    p = ((S_469D90 * (*)(s32))func_L01_004618E0)(67);
    if (p) {
        p->x10 = *(s128 *)pos;
        q = &p->q;
        q->x0C = a0;
        q->x10 = f12;
        q->x14 = f13;
        p->x1 = 0;
        p->x4 = color | 0x409B9B00;
        p->x9 = 68;
        p->x3 = 72;
        p->xC = 52500.0f;
        p->x8 = func_00382468(255);
        q->x1C = mode;
        q->x18 = 0;
        if (mode == 0) {
            p->x2 = D_L01_002211A4[0][0];
        } else {
            p->x2 = D_L01_002211A4[0][1];
        }
        if (mode == 0) {
            q->x1A = 127.0f / (f32)life;
        }
        if (vel) {
            q->v[0] = vel[0];
            q->v[1] = vel[1];
            q->v[2] = vel[2];
        }
        p->xA = life;
    }
    return p;
}
/* localdecomp:end func_L01_0046D440 */

INCLUDE_ASM("asm/levels", func_L01_0046D5A8);

LINKER_REMNANT("asm/levels", func_L01_0046D848);

/* localdecomp:start func_L01_0046D850 */
typedef struct {
    u8 *target;
    u8 slot;
    u8 range;
    s16 id;
    f32 scale;
    f32 amp;
} T_0046D850_Sub_0046D850;
typedef struct {
    char pad0[0x10];
    Vec4 base;
    Vec4 pos;
    T_0046D850_Sub_0046D850 sub;
} T_0046D850;

extern void func_003CD250(Obj *);
extern f32 func_003824E0(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);

void func_L01_0046D850(T_0046D850 *p)
{
    T_0046D850_Sub_0046D850 *s = &p->sub;
    vu0_v4 m[4];
    vu0_v4 v;
    f32 sc;
    f32 w;
    f32 t;

    if (s->target == 0 || *(s16 *)(s->target + 0xAA) != s->id || s->target[0x20] == 0xFE || s->target[0x20] == 0xFD) {
        func_003CD250((Obj *)p);
        return;
    }
    sc = s->scale * func_003824E0(0.05f, 1.0f);
    w = p->pos.w;
    func_003C2F58(s->target, s->slot, &p->base);
    func_003C2EC0(s->target, s->slot, m);
    t = (f32)s->range;
    t = func_003824E0(-t, t) / 100.0f;
    t -= 1.0f;
    func_0038CF68(&v, m, t * s->amp);
    vec_add_ab(&p->pos, &p->base, &v);
    p->base.w = sc;
    p->pos.w = w;
}
/* localdecomp:end func_L01_0046D850 */

LINKER_REMNANT("asm/levels", func_L01_0046D978);

INCLUDE_ASM("asm/levels", func_L01_0046D980);

/* localdecomp:start func_L01_0046DBE8 */
extern void func_003CD250(Obj *);
void func_L01_0046DBE8(u8 *a0) {
    if (--*(s16 *)(a0 + 10) == 0) { *(s16 *)(a0 + 10) = 2; *(s32 *)(a0 + 4) += 0xFF000000; }
    if ((*(u32 *)(a0 + 4) & 0xFF000000) == 0) {
        ((void (*)(u8 *a0))func_003CD250)(a0);
    }
}
/* localdecomp:end func_L01_0046DBE8 */

LINKER_REMNANT("asm/levels", func_L01_0046DC48);

/* localdecomp:start func_L01_0046DC50 */
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s16 x10;
    s16 x12;
    s16 x14;
    u8 pad16[2];
    vu0_v4 *x18;
} S_46DC50_0046DC50;
typedef struct {
    u8 pad0[4];
    s32 x4;
    u8 x8;
    u8 pad9;
    s16 hA;
    u8 padC[4];
    vu0_v4 x10;
    S_46DC50_0046DC50 s;
} O_46DC50_0046DC50;
extern s32 D_L01_001DFB40_0046DC50;
extern u8 D_001A4CC0[];
extern f32 func_L01_0040E4E0_0046DC50(void *, void *);
extern f32 func_L01_0040E468_0046DC50(void *);
extern void func_L01_0040E620_0046DC50(void *, void *, f32);
extern void func_L01_0044E028_0046DC50(void *, void *);
extern s32 func_L01_0040F550_0046DC50(s32, s32, f32);
extern void func_L01_0044E130_0046DC50(void *, void *);
extern s32 func_L01_0040DFF0_0046DC50(u8 *);
extern void func_L01_0040E398_0046DC50(void *, void *, void *, f32);
extern void func_L01_00461A28_0046DC50(O_46DC50_0046DC50 *);

void func_L01_0046DC50(O_46DC50_0046DC50 *o) {
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;
    S_46DC50_0046DC50 *s = &o->s;
    f32 d;

    if (D_L01_001DFB40_0046DC50 & 1) {
        o->x8++;
    }
    d = func_L01_0040E4E0_0046DC50(&o->x10, D_001A4CC0);
    if (d < 5.0f && 0.0f < s->x18->z) {
        vec_sub_ab(&v1, s->x18, &o->x10);
        if (0.5f < func_L01_0040E468_0046DC50(&v1)) {
            func_L01_0040E620_0046DC50(&v1, &v1, 0.1f / d);
            vec_add_ab(&o->x10, &o->x10, &v1);
        } else {
            func_L01_0040E620_0046DC50(&v1, &v1, 0.005f);
            func_L01_0044E028_0046DC50(&v1, &s->x4);
        }
    }
    d = (2.5f - (d - 0.5f)) / 2.5f;
    if (d > 1.0f) {
        d = 1.0f;
    } else if (d < 0.0f) {
        d = 0.0f;
    }
    o->x4 = func_L01_0040F550_0046DC50(s->x8, s->xC, d);
    if (s->x10 != 0) {
        func_L01_0044E130_0046DC50(&v0, s);
        vec_add_ab(&o->x10, &o->x10, &v0);
        o->x4 = func_L01_0040F550_0046DC50(o->x4 & 0xFFFFFF, o->x4, 1.0f - (f32)o->hA / (f32)s->x10);
        if (func_L01_0040DFF0_0046DC50((u8 *)&o->hA)) {
            s->x10 = 0;
            o->hA = s->x12;
        }
    } else if (s->x12 != 0) {
        func_L01_0044E130_0046DC50(&v1, s);
        func_L01_0044E130_0046DC50(&v2, &s->x4);
        func_L01_0040E398_0046DC50(&v0, &v2, &v1, (f32)o->hA / (f32)s->x12);
        vec_add_ab(&o->x10, &o->x10, &v0);
        if (func_L01_0040DFF0_0046DC50((u8 *)&o->hA)) {
            s->x12 = 0;
            o->hA = s->x14;
        }
    } else {
        func_L01_0044E130_0046DC50(&v0, &s->x4);
        vec_add_ab(&o->x10, &o->x10, &v0);
        o->x4 = func_L01_0040F550_0046DC50(o->x4 & 0xFFFFFF, o->x4, (f32)o->hA / (f32)s->x14);
        if (func_L01_0040DFF0_0046DC50((u8 *)&o->hA)) {
            func_L01_00461A28_0046DC50(o);
        }
    }
}
/* localdecomp:end func_L01_0046DC50 */

LINKER_REMNANT("asm/levels", func_L01_0046DF88);

/* localdecomp:start func_L01_0046DF90 */
/* from rac2-decomp's func_002C4B10, renamed */
void func_L01_0046DF90(u8 *a0)
{
    f32 value = *(f32 *)(a0 + 0x0C);
    *(u8 *)(a0 + 0x08) = *(u8 *)(a0 + 0x08) + *(u8 *)(a0 + 0x38);
    if (value <= 0.0f) {
        *(f32 *)(a0 + 0x0C) = 0.0f;
        func_003CD250((Obj *)a0);
    }
}
/* localdecomp:end func_L01_0046DF90 */

/* localdecomp:start func_L01_0046DFD0 */
typedef struct {
    u8 pad_00[0x10];
    vu0_v4 pos;
    vu0_v4 vel;
} Obj_46DFD0;

extern f32 D_L01_001E02A0;
__asm__(".extern D_L01_001E02A0, 16");
extern f32 D_L01_001E02A8;

void func_L01_0046DFD0(Obj_46DFD0 *o)
{
    vu0_v4 g;
    vu0_v4 *p = &o->vel;
    f32 w = p->w;

    if (*(f32 *)((u8 *)o + 0x18) < w) {
        func_003CD250((Obj *)o);
        return;
    }
    g = o->vel;
    g.w = 0.0f;
    vec_add_ba(&o->pos, &o->pos, &g);
    g.z = -0.00020000001f;
    g.x = 0.0f;
    g.y = 0.0f;
    vec_add_ba(&o->pos, &o->pos, &D_L01_001E02A0);
    g.w = 0.0f;
    vec_add_ba(&o->vel, &g, &o->vel);
    p->w = w + D_L01_001E02A8;
}
/* localdecomp:end func_L01_0046DFD0 */

/* localdecomp:start func_L01_0046E078 */
typedef struct {
    f32 x, y, z;
    u8 *o;
    f32 tx, ty, tz;
    s32 *src;
} Q_0046E078;

typedef struct {
    u8 b0, b1, b2, b3;
    s32 c4;
    u8 b8, b9;
    s16 hA;
    s32 iC;
    u128_t v10;
    Q_0046E078 q;
} T_0046E078;

extern S_467288 *func_L01_004618E0_0046E078(s32 size);
extern s32 func_0013D3E0(void);
extern u8 *D_L01_002211C0_0046E078[];
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);

T_0046E078 *func_L01_0046E078(u8 *o, u128_t *pos, f32 *v, s32 *src, s32 flag) {
    T_0046E078 *m = ((T_0046E078 * (*)(s32))func_L01_004618E0_0046E078)(0x4A);
    Q_0046E078 *q;
    if (m != 0) {
        m->b9 = 0xA0;
        if (flag != 0) {
            m->b3 = 0x48;
        } else {
            m->b3 = 0x44;
        }
        m->b1 = 0;
        q = &m->q;
        m->b2 = *D_L01_002211C0_0046E078[0];
        m->b8 = func_0013D3E0();
        m->iC = 0;
        m->v10 = *pos;
        q->x = v[0];
        q->y = v[1];
        q->z = v[2];
        if (o != 0) {
            Vec4 t;
            Vec4 mat[4];
            vec_sub_ba(&t, pos, o + 0x10);
            qzero(&mat[0]);
            qzero(&mat[1]);
            qzero(&mat[2]);
            qzero(&mat[3]);
            func_0038D5B0(mat, o + 0xC0);
            func_0038D028(&t, &t, mat);
            q->tx = t.x;
            q->ty = t.y;
            q->tz = t.z;
        }
        q->o = o;
        q->src = src;
        m->hA = *(u16 *)((u8 *)src + 0xC);
        m->c4 = src[0];
    }
    return m;
}
/* localdecomp:end func_L01_0046E078 */

INCLUDE_ASM("asm/levels", func_L01_0046E1B8);

LINKER_REMNANT("asm/levels", func_L01_0046E378);

/* localdecomp:start func_L01_0046E380 */
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    u8 padC[4];
    u8 pad10[4];
    f32 f14;
    u8 pad18[4];
    s32 i1C;
} Q_0046E380;

typedef struct {
    u8 pad0[8];
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    Vec4 pos;
    Q_0046E380 q;
} T_0046E380;

extern f32 func_0038CED8(void *);
extern s32 func_0038CB00(s16 *);
extern s32 func_L01_00445EA8(u8 *, s32);
extern void func_003CD250(Obj *);

void func_L01_0046E380(T_0046E380 *p) {
    Q_0046E380 *q = &p->q;
    f32 len;
    f32 scale;
    f32 t;
    p->b8 += ((u8 *)q)[0x12];
    vec_add_ab(&p->pos, &p->pos, q);
    q->f8 = q->f8 - 0.0043200003f;
    len = func_0038CED8(q);
    scale = ((len * 0.97f - 1.0f) * 1.2f + 1.0f) / len;
    q->f0 = q->f0 * scale;
    q->f4 = q->f4 * scale;
    if (func_0038CB00(&p->hA) == 0) {
        t = p->fC + (q->f14 + q->f14);
        p->fC = t;
        if (t < 15000.0f) {
            p->fC = 15000.0f;
        }
    } else if (func_L01_00445EA8((u8 *)p + 4, q->i1C) != 0) {
        p->fC = 0;
        func_003CD250((Obj *)p);
    }
}
/* localdecomp:end func_L01_0046E380 */

/* localdecomp:start func_L01_0046E4A0 */
__asm__(".extern D_L01_001D7F68, 4");
extern s32 D_L01_001D7F68;
extern s32 func_L01_00445EA8(u8 *, s32);
extern s32 func_L01_0040DFF0(u8 *);
extern void func_003CD250(Obj *);

void func_L01_0046E4A0(u8 *p) {
    func_L01_00445EA8(p + 4, D_L01_001D7F68);
    if (func_L01_0040DFF0(p + 0xA) != 0) {
        func_003CD250((Obj *)p);
    }
}
/* localdecomp:end func_L01_0046E4A0 */

LINKER_REMNANT("asm/levels", func_L01_0046E4E8);

/* localdecomp:start func_L01_0046E4F0 */
typedef struct {
    u8 pad0[4];
    s32 c4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    Vec4 pos;
    Vec4 vec;
} T_0046E4F0;

extern s32 func_0038CB00(s16 *);
extern void func_003CD250(Obj *);

void func_L01_0046E4F0(T_0046E4F0 *p) {
    Vec4 v;
    f32 f;
    v = p->vec;
    f = (f32)p->hA / v.w;
    v.w = 0.0f;
    p->c4 = ((s32)(f * 38.0f) << 24) | 0x808080;
    p->b8 = (s32)(f * 33.0f);
    vec_add_ba(&p->pos, &p->pos, &v);
    if (func_0038CB00(&p->hA) != 0) {
        func_003CD250((Obj *)p);
    }
}
/* localdecomp:end func_L01_0046E4F0 */

/* localdecomp:start func_L01_0046E5A8 */
extern S_467288 *func_L01_004618E0(s32 size);

extern u8 *D_L01_002211D0[];
extern s32 func_00382468(s32);
extern u8 *func_00382348(s32);

#define U8(p, o) (*(u8 *)((p) + (o)))
#define S16(p, o) (*(s16 *)((p) + (o)))
#define S32(p, o) (*(s32 *)((p) + (o)))
#define F32(p, o) (*(f32 *)((p) + (o)))

u8 *func_L01_0046E5A8(s128 *a0, s32 a1, s32 a2, s32 a3, s32 t0, f32 *t1, s32 t2, f32 f12, f32 f13) {
    u8 *p = ((u8 * (*)(s32))func_L01_004618E0)(78);
    u8 *q;
    u8 *r;
    f32 *v;
    if (p != 0) {
        *(s128 *)(p + 16) = *a0;
        U8(p, 3) = 72;
        U8(p, 9) = 36;
        q = p + 32;
        S32(p, 4) = a2;
        U8(p, 1) = 0;
        U8(p, 2) = *D_L01_002211D0[0];
        S16(p, 10) = a1;
        F32(p, 12) = f12 * 210000.0f;
        if (a3 == 0) {
            U8(p, 8) = 0;
        } else if (a3 == 1) {
            U8(p, 8) = 32;
        } else {
            U8(p, 8) = func_00382468(255);
        }
        F32(q, 0) = F32(p, 12);
        F32(q, 4) = f13 * 210000.0f;
        S16(q, 8) = a1;
        U8(q, 10) = t0;
        U8(q, 11) = a2 >> 24;
        S32(q, 24) = t2;
        S32(q, 28) = 0;
        if (t2 != 0) {
            r = func_00382348(t2);
            if (r != 0) {
                F32(q, 28) = F32(r, 16);
            }
        }
        v = (f32 *)(q + 12);
        v[0] = t1[0];
        v[1] = t1[1];
        v[2] = t1[2];
    }
    return p;
}
/* localdecomp:end func_L01_0046E5A8 */

INCLUDE_ASM("asm/levels", func_L01_0046E720);

/* localdecomp:start func_L01_0046EA10 */
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    u8 padC[4];
    f32 f10;
    f32 f14;
    f32 f18;
    u8 *p1C;
} Q_0046EA10;

typedef struct {
    u8 pad0[4];
    s32 c4;
    u8 pad8[2];
    s16 hA;
    f32 fC;
    Vec4 pos;
    Q_0046EA10 q;
} T_0046EA10;

extern s32 func_0038CB00(s16 *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003CD250(Obj *);

void func_L01_0046EA10(T_0046EA10 *p) {
    Q_0046EA10 *q = &p->q;
    if (q->p1C != 0) {
        q->f0 = q->f0 + q->f10;
        q->f4 = q->f4 + q->f14;
        q->f8 = q->f8 + q->f18;
        vec_add_ab(&p->pos, q->p1C + 0x10, q);
    } else {
        p->pos.x = p->pos.x + q->f10;
        p->pos.y = p->pos.y + q->f14;
        p->pos.z = p->pos.z + q->f18;
    }
    if (func_0038CB00(&p->hA) != 0) {
        func_003CD250((Obj *)p);
        return;
    }
    if (q->p1C != 0) {
        p->c4 = func_0038DBD8(p->c4 & 0xFFFFFF, p->c4, (f32)(p->hA - 1) / (f32)p->hA);
    } else {
        p->c4 = func_0038DBD8(0, p->c4, (f32)(p->hA - 1) / (f32)p->hA);
    }
}
/* localdecomp:end func_L01_0046EA10 */

/* localdecomp:start func_L01_0046EB58 */
typedef struct {
    u8 pad0[4];
    s32 c4;
    u8 pad8[2];
    s16 hA;
    f32 fC;
    Vec4 pos;
    s32 i20;
} T_0046EB58;

extern s32 func_0038CB00(s16 *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003CD250(Obj *);

void func_L01_0046EB58(T_0046EB58 *p) {
    if (p->pos.x < 2.0f || p->pos.x > 1021.0f || p->pos.y < 2.0f || p->pos.y > 1021.0f || p->pos.z < 2.0f || p->pos.z > 1021.0f || func_0038CB00(&p->hA) != 0) {
        func_003CD250((Obj *)p);
        return;
    }
    if (p->i20 != 0) {
        p->fC = p->fC * 0.99f;
        p->c4 = func_0038DBD8(0x30FFFFFF, p->c4, (f32)(p->hA - 1) / (f32)p->hA);
    } else {
        p->fC = p->fC * 0.95f;
        p->c4 = func_0038DBD8(0x603F1008, p->c4, (f32)(p->hA - 1) / (f32)p->hA);
    }
}
/* localdecomp:end func_L01_0046EB58 */

/* localdecomp:start func_L01_0046ECB8 */
typedef struct {
    u8 pad00[0x10];
    s16 h10;
    u8 b12;
    u8 b13;
    u8 b14;
    u8 b15;
    u8 b16;
    u8 b17;
    s32 i18;
    f32 f1C;
} S_46ECB8_Sub;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 c4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    s128 v10;
    S_46ECB8_Sub sub;
} S_46ECB8;

extern S_467288 *func_L01_004618E0(s32 size);
extern u8 *D_L01_00221180[];
extern s32 func_0013D3E0(void);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern void func_00382760(void *, f32, f32, f32);

S_46ECB8 *func_L01_0046ECB8(s128 *pos, u8 a1, u8 a2, s16 a3, u8 a4, u8 a5, s32 a6, f32 sx, f32 sy) {
    S_46ECB8 *o;
    S_46ECB8_Sub *p;
    f32 speed;
    f32 yaw;
    s32 r;
    u8 mode;

    o = ((S_46ECB8 * (*)(s32))func_L01_004618E0)(0x51);
    if (o != 0) {
        p = &o->sub;
        o->v10 = *pos;
        o->b9 = 0x70;
        o->b3 = 0x44;
        o->b1 = 0;
        r = func_0013D3E0();
        o->b2 = D_L01_00221180[0][r & 7];
        o->fC = 21000.0f;
        o->b8 = func_0013D3E0();
        p->b12 = a2;
        p->b13 = a4;
        mode = p->b12;
        p->i18 = a6;
        p->f1C = sx;
        p->b17 = a1;
        p->h10 = a3;
        p->b15 = a5;
        switch (mode) {
        case 0:
            o->hA = a3;
            o->c4 = 0xFF808080;
            p->b14 = 0;
            break;
        case 1:
            speed = func_003824E0(3.0f, 9.0f) * sy * 0.0200000014f;
            yaw = func_00382538();
            func_00382760(p, speed, yaw, func_003824E0(1.34390354f, 1.79768908f));
            o->fC = 42000.0f;
            r = func_0013D3E0();
            p->b16 = (r & 0x1F) + 0x10;
            o->c4 = (p->b16 << 24) | 0x808080;
            o->hA = a5;
            p->b14 = mode;
            break;
        }
    }
    return o;
}
/* localdecomp:end func_L01_0046ECB8 */

/* localdecomp:start func_L01_0046EEA0 */
typedef struct {
    s128 q;
    s32 hero;
    s32 b;
    u8 c, d;
    s16 e;
    f32 f;
    s32 g;
} S_0046EEA0;

extern s32 func_0038CB00(s16 *);
extern void func_003CD250(Obj *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003C4C18(void *, f32);
extern s32 func_0013D3E0(void);
extern u8 *D_L01_00221180_0046EEA0[];
extern u8 *D_L01_001E0278_0046EEA0;
extern S_46ECB8 *func_L01_0046ECB8_0046EEA0(s128 *pos, u8 a1, u8 a2, s16 a3, u8 a4, u8 a5, s32 a6, f32 sx, f32 sy);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern u8 D_001A4BE0[];
extern s32 D_L01_001DFB40_0046EEA0;
__asm__(".extern D_L01_001DFB40_0046EEA0, 16");

static __inline__ s32 hero_moby(u8 *h) { return *(s32 *)(h + 0x25C0); }

void func_L01_0046EEA0(u8 *o)
{
    u8 *c = o + 0x20;
    vu0_v4 t;
    S_0046EEA0 s;
    f32 f;
    f32 sc;
    s32 i;
    s32 r;

    switch (c[0x14]) {
    case 0:
        i = 0;
        if (c[0x13] != 0) {
            do {
                t = *(vu0_v4 *)(o + 0x10);
                func_003C4C18(&t, 0.05f);
                sc = 1.0f;
                if (*(s16 *)(o + 0xA) < 8) {
                    sc = (f32)*(s16 *)(o + 0xA) * 0.125f;
                }
                i++;
                func_L01_0046ECB8_0046EEA0((s128 *)&t, 0, 1, *(s16 *)(c + 0x10), c[0x13], c[0x15], *(s32 *)(c + 0x18), *(f32 *)(c + 0x1C), sc);
            } while (i < c[0x13]);
        }
        if (func_0038CB00((s16 *)(o + 0xA)) != 0) {
            func_003CD250((Obj *)o);
        }
        qzero(&s.q);
        s.hero = hero_moby(D_001A4BE0);
        s.b = 0x10000;
        s.c = 2;
        s.e = 0x820;
        s.d = 1;
        s.f = 1.0f;
        s.g = 0;
        if ((D_L01_001DFB40_0046EEA0 + c[0x17]) % 10 == 0) {
            func_003D4D00(o + 0x10, 0x10, (void *)s.hero, &s, 0.2f);
        }
        return;
    case 1:
        vec_add_ab(o + 0x10, o + 0x10, o + 0x20);
        f = ((f32)c[0x15] - (f32)*(s16 *)(o + 0xA)) / (f32)c[0x15];
        *(s32 *)(o + 4) = func_0038DBD8((c[0x16] << 24) | 0x4060, 0x8FAFFF, f);
        if (f < 0.6f) {
            *(f32 *)(o + 0xC) = *(f32 *)(o + 0xC) + 10836.001f;
        } else {
            *(f32 *)(o + 0xC) = *(f32 *)(o + 0xC) - 20160.0f;
        }
        r = func_0013D3E0();
        o[2] = D_L01_00221180_0046EEA0[0][r & 7];
        if (((o - D_L01_001E0278_0046EEA0) >> 6) & 1) {
            o[8] = o[8] + 1;
        } else {
            o[8] = o[8] - 1;
        }
        if (func_0038CB00((s16 *)(o + 0xA)) != 0) {
            func_003CD250((Obj *)o);
        }
        return;
    }
}
/* localdecomp:end func_L01_0046EEA0 */

/* localdecomp:start func_L01_0046F148 */
typedef struct {
    u128_t v0;
    f32 f10;
    s16 h14;
    s16 h16;
    u8 b18;
    s32 i1C;
} Q_0046F148;

typedef struct {
    u8 b0, b1, b2, b3;
    s32 c4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    u128_t v10;
    Q_0046F148 q;
} T_0046F148;

extern S_467288 *func_L01_004618E0(s32 size);
extern s32 func_L01_00448CC0(f32, f32, f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0013D3E0(void);
extern u8 *D_L01_002211E0[];

T_0046F148 *func_L01_0046F148(u128_t *pos, u128_t *vec, u8 a2, s32 a3) {
    T_0046F148 *m = ((T_0046F148 * (*)(s32))func_L01_004618E0)(0x52);
    Q_0046F148 *q;
    if (m != 0) {
        m->v10 = *pos;
        q = &m->q;
        q->v0 = *vec;
        m->c4 = func_L01_00448CC0(0.7f, 0.7f, 0.7f, 0.08f);
        m->b1 = 0;
        m->b9 = 0x44;
        m->b3 = 0x44;
        q->f10 = func_003824E0(0.0f, 1.0f);
        m->b8 = (s32)(q->f10 * 256.0f);
        m->b2 = D_L01_002211E0[0][func_0013D3E0() & 7];
        q->b18 = a2;
        q->h14 = 0;
        q->h16 = 0;
        if (a2 < 5) {
            m->fC = func_003824E0(7000.0f, 10000.0f);
            m->hA = 15 - func_0013D3E0() % 12;
        } else {
            m->hA = 15;
            m->fC = 10000.0f;
        }
        q->i1C = a3;
    }
    return m;
}
/* localdecomp:end func_L01_0046F148 */

INCLUDE_ASM("asm/levels", func_L01_0046F2B8);

LINKER_REMNANT("asm/levels", func_L01_0046F930);

/* localdecomp:start func_L01_0046F938 */
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    u16 h18;
    u8 b1A;
    f32 f1C;
} Q_0046F938;

typedef struct {
    u8 pad0[8];
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    Vec4 pos;
    Q_0046F938 q;
} T_0046F938;

extern s32 func_00382468(s32);
extern S_467288 *func_L01_0046A938(Vec4 *, s32, s32, f32, f32);
extern void func_L01_00468A68(void *, void *, s32, s32);
extern s32 func_0038CB00(s16 *);
extern void func_003CD250(Obj *);

void func_L01_0046F938(T_0046F938 *p) {
    Q_0046F938 *q = &p->q;
    Vec4 *r = &p->pos;
    q->f10 = q->f10 + 0.0090000005f;
    q->f8 = q->f8 - q->fC;
    p->fC = q->f14 * q->f10 * 210000.0f;
    p->b8 += q->b1A;
    vec_add_ab(&p->pos, &p->pos, q);
    if (p->pos.z <= q->f1C) {
        if (func_00382468(6) == 1) {
            func_L01_0046A938(r, 0, -1, 0.4f, 31500.002f);
        }
    }
    if (func_00382468(6) == 1 && (s16)q->h18 >= 0x32) {
        func_L01_00468A68(&p->pos, q, 1, 0x11);
    }
    q->h18++;
    if (func_0038CB00(&p->hA) != 0) {
        func_003CD250((Obj *)p);
    }
}
/* localdecomp:end func_L01_0046F938 */

LINKER_REMNANT("asm/levels", func_L01_0046FA80);

/* localdecomp:start func_L01_0046FA88 */
extern s32 func_0038CB00(s16 *);
extern void func_003CD250(Obj *);
extern f32 func_0038D0B0(f32);

void func_L01_0046FA88(Obj *o) {
    if (o != 0) {
        Sub *s = &o->sub;
        if (func_0038CB00((s16 *)&s->base) != 0) {
            func_003CD250(o);
        } else {
            f32 ang = (f32)*(s16 *)((u8 *)s + 4) / (f32)*(s16 *)((u8 *)s + 6) * 6.2831855f;
            f32 x;
            s32 c;

            x = (f32)s->a * func_0038D0B0(ang);
            c = o->result;
            o->result = (c & 0xFFFFFF) + ((s32)fabs_asm(x) << 24);
        }
    }
}
/* localdecomp:end func_L01_0046FA88 */

INCLUDE_ASM("asm/levels", func_L01_0046FB40);

INCLUDE_ASM("asm/levels", func_L01_0046FD18);

LINKER_REMNANT("asm/levels", func_L01_0046FE58);

INCLUDE_ASM("asm/levels", func_L01_0046FE60);

LINKER_REMNANT("asm/levels", func_L01_0046FFF8);

/* localdecomp:start func_L01_00470000 */
typedef struct {
    u8 pad0[0x10];
    s128 pos;
    u8 state;
    u8 pad21[0x31 - 0x21];
    u8 unk31;
    u8 pad32[2];
    u16 unk34;
} M_470000_00470000;
typedef struct {
    M_470000_00470000 *moby;
    u8 pad4[2];
    s16 joint;
    u8 pad8[3];
    s8 alpha;
} A_470000_00470000;
typedef struct {
    u8 pad0[4];
    s32 color;
    u8 count;
    u8 pad9[0x10 - 0x9];
    s128 pos;
    A_470000_00470000 att;
} S_470000_00470000;

extern s32 func_L01_00445EA8_00470000(u8 *, s32);
extern void func_003CD250(Obj *);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern vu0_v4 D_L01_001E29C0_00470000;

void func_L01_00470000(S_470000_00470000 *s) {
    vu0_v4 pos;
    vu0_v4 d;
    A_470000_00470000 *att;
    M_470000_00470000 *m;
    s32 a;
    s32 lim;

    if (s == 0) {
        return;
    }
    att = &s->att;
    s->count++;
    m = att->moby;
    if (m == 0 || m->state == 0xFE || m->state == 0xFD) {
        if (func_L01_00445EA8_00470000((u8 *)&s->color, 4)) {
            func_003CD250((Obj *)s);
        }
        return;
    }
    a = s->color >> 24;
    lim = att->alpha;
    if (m->unk31 != 0 && !(m->unk34 & 2)) {
        if (a < lim) {
            a += 4;
            if (lim < a) {
                a = lim;
            }
        }
    } else {
        a -= 4;
        if (a < 0) {
            a = 0;
        }
    }
    s->color = (s->color & 0xFFFFFF) | (a << 24);
    if (att->joint == -1) {
        s->pos = att->moby->pos;
        return;
    }
    func_003C2F58(att->moby, att->joint, &pos);
    vec_sub_ba(&d, &D_L01_001E29C0_00470000, &pos);
    func_0038CF68(&d, &d, 0.4f);
    vec_add_ab(&s->pos, &pos, &d);
}
/* localdecomp:end func_L01_00470000 */

LINKER_REMNANT("asm/levels", func_L01_00470148);

INCLUDE_ASM("asm/levels", func_L01_00470150);

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

INCLUDE_ASM("asm/levels", func_L01_00470770);
