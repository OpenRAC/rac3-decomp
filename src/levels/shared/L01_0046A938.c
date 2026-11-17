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

INCLUDE_ASM("asm/levels", func_L01_0046AFD8);

INCLUDE_ASM("asm/levels", func_L01_0046B0B8);

LINKER_REMNANT("asm/levels", func_L01_0046B190);

INCLUDE_ASM("asm/levels", func_L01_0046B198);

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

INCLUDE_ASM("asm/levels", func_L01_0046B9E8);

INCLUDE_ASM("asm/levels", func_L01_0046BAE0);

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

INCLUDE_ASM("asm/levels", func_L01_0046BD88);

INCLUDE_ASM("asm/levels", func_L01_0046BF78);

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

INCLUDE_ASM("asm/levels", func_L01_0046C5C8);

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

INCLUDE_ASM("asm/levels", func_L01_0046CB28);

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

INCLUDE_ASM("asm/levels", func_L01_0046CDA8);

INCLUDE_ASM("asm/levels", func_L01_0046CFD8);

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

INCLUDE_ASM("asm/levels", func_L01_0046D850);

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

INCLUDE_ASM("asm/levels", func_L01_0046DC50);

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

INCLUDE_ASM("asm/levels", func_L01_0046DFD0);

INCLUDE_ASM("asm/levels", func_L01_0046E078);

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

INCLUDE_ASM("asm/levels", func_L01_0046ECB8);

INCLUDE_ASM("asm/levels", func_L01_0046EEA0);

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
            o->result = (c & 0xFFFFFF) + ((s32)__builtin_fabsf(x) << 24);
        }
    }
}
/* localdecomp:end func_L01_0046FA88 */

INCLUDE_ASM("asm/levels", func_L01_0046FB40);

INCLUDE_ASM("asm/levels", func_L01_0046FD18);

LINKER_REMNANT("asm/levels", func_L01_0046FE58);

INCLUDE_ASM("asm/levels", func_L01_0046FE60);

LINKER_REMNANT("asm/levels", func_L01_0046FFF8);

INCLUDE_ASM("asm/levels", func_L01_00470000);

LINKER_REMNANT("asm/levels", func_L01_00470148);

INCLUDE_ASM("asm/levels", func_L01_00470150);

INCLUDE_ASM("asm/levels", func_L01_004702E0);

INCLUDE_ASM("asm/levels", func_L01_00470668);

INCLUDE_ASM("asm/levels", func_L01_00470770);

INCLUDE_ASM("asm/levels", func_L01_004708C8);

INCLUDE_ASM("asm/levels", func_L01_00470A28);

INCLUDE_ASM("asm/levels", func_L01_00470C78);

INCLUDE_ASM("asm/levels", func_L01_00470E48);

LINKER_REMNANT("asm/levels", func_L01_004710E8);

/* localdecomp:start func_L01_004710F8 */
typedef struct {
    Vec4 vel;
    f32 f10;
    f32 f14;
    u8 b18;
} Q_004710F8;

typedef struct {
    u8 pad0[4];
    s32 c4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    Vec4 pos;
    Q_004710F8 q;
} T_004710F8;

extern s32 func_0038CB00(s16 *);
extern void func_003CD250(Obj *);

void func_L01_004710F8(T_004710F8 *p) {
    Q_004710F8 *q = &p->q;
    Vec4 v;
    q->f10 = q->f10 + 0.001f;
    q->vel.z = q->vel.z - 0.0043200003f;
    p->fC = q->f14 * q->f10 * 210000.0f;
    v = p->q.vel;
    vec_add_ba(&p->pos, &p->pos, &v);
    p->c4 = (p->hA << 24) | 0xFFD2D2;
    p->b8 += q->b18;
    if (func_0038CB00(&p->hA) != 0) {
        func_003CD250((Obj *)p);
    }
}
/* localdecomp:end func_L01_004710F8 */

INCLUDE_ASM("asm/levels", func_L01_004711C0);

LINKER_REMNANT("asm/levels", func_L01_004712D8);

/* localdecomp:start func_L01_004712E0 */
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    u8 padC[4];
    s32 i10;
    u8 pad14[8];
    f32 f1C;
} Q_004712E0;

typedef struct {
    u8 pad0[4];
    s32 c4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    Vec4 pos;
    Q_004712E0 q;
} T_004712E0;

__asm__(".extern D_L01_001D7F84, 4");
extern f32 D_L01_001D7F84;
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038CB00(s16 *);
extern void func_003CD250(Obj *);

void func_L01_004712E0(T_004712E0 *p) {
    Q_004712E0 *q = &p->q;
    func_0038CE20(q, q, D_L01_001D7F84);
    q->f8 = q->f8 - q->f1C;
    vec_add_ab(&p->pos, &p->pos, q);
    if (p->hA < q->i10) {
        p->c4 = ((s32)((f32)p->hA / (f32)q->i10 * 64.0f) << 24) | 0x808080;
    } else {
        p->c4 = 0x40808080;
    }
    p->b8 += *((u8 *)q + 0x14);
    if (func_0038CB00(&p->hA) != 0) {
        func_003CD250((Obj *)p);
    }
}
/* localdecomp:end func_L01_004712E0 */

INCLUDE_ASM("asm/levels", func_L01_004713C8);

INCLUDE_ASM("asm/levels", func_L01_00471530);

LINKER_REMNANT("asm/levels", func_L01_00471668);

/* localdecomp:start func_L01_00471670 */
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    u8 b14;
    u8 b15;
} Q_00471670;

typedef struct {
    u8 pad0[4];
    s32 c4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    Vec4 pos;
    Q_00471670 q;
} T_00471670;

extern s32 func_0038CB00(s16 *);
extern void func_003CD250(Obj *);

void func_L01_00471670(T_00471670 *p) {
    Q_00471670 *q = &p->q;
    Vec4 v;
    if (func_0038CB00(&p->hA) != 0) {
        func_003CD250((Obj *)p);
        return;
    }
    p->c4 = (p->c4 & 0xFFFFFF) | (((p->c4 >> 24) + q->b14) << 24);
    v.x = q->f0;
    v.y = q->f4;
    v.z = q->f8;
    v.w = 0.0f;
    vec_add_ba(&p->pos, &p->pos, &v);
    p->b8 += q->b15;
    p->fC += q->f10;
    q->f8 = q->f8 - q->fC;
}
/* localdecomp:end func_L01_00471670 */

LINKER_REMNANT("asm/levels", func_L01_00471740);

INCLUDE_ASM("asm/levels", func_L01_00471748);

/* localdecomp:start func_L01_00471A30 */
extern int func_0038CB00(short *);
extern u8 *D_L35_0021F3E8[];
extern f32 D_L35_001D7DB4;
__asm__(".extern D_L35_001D7DB4, 4");

void func_L01_00471A30(char *self) {
    char *state = self + 0x20;
    char *p;
    if (func_0038CB00((short *)(self + 0xA))) {
        *(f32 *)(state + 8) -= *(f32 *)(state + 0x18);
    }
    __asm__ __volatile__(
        "lqc2    $vf1, 0x10(%0)\n"
        "lqc2    $vf2, 0x20(%0)\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2    $vf1, 0x10(%0)\n"
        : : "r"(self) : "memory");
    p = *(char **)(state + 0x1C);
    if (p != 0) {
        __asm__ __volatile__(
            "lqc2    $vf2, 0x0(%1)\n"
            "lqc2    $vf1, 0x10(%0)\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2    $vf1, 0x10(%0)\n"
            : : "r"(self), "r"(p) : "memory");
    }
    self[8] += *(u8 *)(state + 0x14);
    if ((u8)self[2] == D_L35_0021F3E8[0][0]) {
        *(f32 *)(self + 0xC) += D_L35_001D7DB4 * 0.020000001f * 210000.0f;
    }
    if (*(f32 *)(self + 0x18) < *(f32 *)(state + 0x10)) {
        func_003CD250((Obj *)self);
    }
}
/* localdecomp:end func_L01_00471A30 */

/* localdecomp:start func_L01_00471B20 */
extern void func_003CD250(Obj *);


extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DBA0(f32, f32);

void func_L01_00471B20(Obj_0046E408 *m) {
    Orbit_0046E408 *o = &m->o;

    m->b8 += o->step;
    o->angle = func_0038DAB8(o->angle, o->speed);
    m->f12 += o->rise;
    m->f16 = m->o.p[0] + o->radius * func_0038D098(o->angle);
    m->f24 = m->o.p[2] + o->radius * func_0038D0B0(o->angle);
    if (func_0038DBA0(o->angle, m->o.p[4]) < __builtin_fabsf(o->speed + o->speed)) {
        ((void (*)(Obj_0046E408 *))func_003CD250)(m);
    }
}
/* localdecomp:end func_L01_00471B20 */

INCLUDE_ASM("asm/levels", func_L01_00471BF0);

INCLUDE_ASM("asm/levels", func_L01_00471D88);

LINKER_REMNANT("asm/levels", func_L01_00471F70);

/* localdecomp:start func_L01_00471F78 */
extern void func_003CD250(Obj *);
extern s32 func_0038CB00(s16 *);
void func_L01_00471F78(u8 *a0) {
    if (((s32 (*)(u8 *))func_0038CB00)(a0 + 10)) {
        ((void (*)(u8 *))func_003CD250)(a0);
    }
}
/* localdecomp:end func_L01_00471F78 */

INCLUDE_ASM("asm/levels", func_L01_00471FB0);

LINKER_REMNANT("asm/levels", func_L01_00472150);

/* localdecomp:start func_L01_00472158 */
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    u8 b14;
    u8 b15;
} Q_00472158;

typedef struct {
    u8 pad0[4];
    s32 c4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    Vec4 pos;
    Q_00472158 q;
} T_00472158;

extern s32 func_0038CB00(s16 *);
extern void func_003CD250(Obj *);
extern void func_L01_004CAB30(void *, void *);

void func_L01_00472158(T_00472158 *p) {
    Q_00472158 *q;
    Vec4 v;
    if (func_0038CB00(&p->hA) != 0) {
        func_003CD250((Obj *)p);
        return;
    }
    q = &p->q;
    p->c4 = (p->c4 & 0xFFFFFF) | (((p->c4 >> 24) + q->b14) << 24);
    v.x = q->f0;
    v.y = q->f4;
    v.z = q->f8;
    v.w = 0.0f;
    vec_add_ba(&p->pos, &p->pos, &v);
    func_L01_004CAB30(&p->pos, &p->pos);
    q->f8 = q->f8 - q->fC;
    p->b8 += q->b15;
    p->fC += q->f10;
}
/* localdecomp:end func_L01_00472158 */

INCLUDE_ASM("asm/levels", func_L01_00472238);

INCLUDE_ASM("asm/levels", func_L01_004723B0);

INCLUDE_ASM("asm/levels", func_L01_00472560);

INCLUDE_ASM("asm/levels", func_L01_00472758);
