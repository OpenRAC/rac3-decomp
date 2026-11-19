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

/* localdecomp:start func_L01_00470A28 */
typedef struct Motion_470A28 {
    f32 x, y, z, w;
    s32 col0, col1;
    s16 duration, spark;
} Motion_470A28;
typedef struct Particle_470A28 {
    u8 a, b, c, d;
    s32 color;
    s16 x, life;
    f32 size;
    vu0_v4 pos;
    Motion_470A28 motion;
} Particle_470A28;
extern s32 D_L01_001DFB40_00470A28;
__asm__(".extern D_L01_001DFB40_00470A28, 4");
extern s32 func_L01_00447470_00470A28(s32, s32, f32);
extern f32 func_003824E0(f32, f32), func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_L01_004CAB30(void *, void *);
extern s32 func_0038CB00(s16 *);
extern void func_003CD250(Obj *);

void func_L01_00470A28(Particle_470A28 *p)
{
    vu0_v4 old;
    vu0_v4 vec;
    Motion_470A28 *vel = &p->motion;
    vu0_v4 *pos;
    f32 length;

    if (func_0038CB00(&p->life)) {
        func_003CD250((Obj *)p);
        return;
    }
    pos = &p->pos;
    p->color = func_L01_00447470_00470A28(vel->col1, vel->col0, (f32)p->life / (f32)vel->duration);
    vec_add_ab(&p->pos, &p->pos, vel);
    vel->z -= vel->w;
    old = p->pos;
    if (p->pos.w != 0.0f) {
        if (p->pos.w == 2.0f) {
            func_L01_004CAB30(pos, pos);
        }
        p->pos.w = 2.0f;
    }
    if (vel->spark && (D_L01_001DFB40_00470A28 & 1)) {
        vu0_v4 r = {0.0f, 0.0f, 0.0f, 0.0f};
        r.x = func_003824E0(-1.0f, 1.0f);
        r.y = func_003824E0(-1.0f, 1.0f);
        r.z = func_003824E0(-1.0f, 1.0f);
        vec = r;
        length = func_0038CEA8(vel);
        func_0038CF68(&vec, &vec, length * func_003824E0(0.15f, 0.25f));
        vec_add_ba(&vec, &vec, vel);
        func_0038CE20(&vec, &vec, func_003824E0(0.75f, 0.95f));
        func_L01_00465738(pos, &vec, p->color, vel->col1, (func_00382498(15, 30) * 5 + 2) / 6, 0,
                          p->c, p->d, (s32)p->pos.w, p->size);
    } else {
        func_0038CE20(vel, vel, 0.96f);
    }
}
/* localdecomp:end func_L01_00470A28 */

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

/* localdecomp:start func_L01_00471FB0 */
typedef struct {
    vu0_v4 vel;
    s32 w10;
    s32 w14;
} Sub_471FB0;

typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    s16 h0A;
    u8 pad0C[4];
    vu0_v4 pos;
    Sub_471FB0 s20;
} Obj_471FB0;

extern f32 D_L01_001E29C8[];
extern s32 D_L01_001E02B4;
extern s32 D_L01_001E02B4_00471FB0;
__asm__(".extern D_L01_001E02B4_00471FB0, 4");
extern f32 D_L01_001E02C0;
__asm__(".extern D_L01_001E02C0, 16");
extern s32 D_L01_001DFB40;
extern vu0_v4 D_L01_001E29F0;
extern void func_L01_004CAB30(void *, void *);
extern f32 func_0038D0B0(f32);

void func_L01_00471FB0(Obj_471FB0 *o)
{
    Sub_471FB0 *s;
    vu0_v4 tmp;
    s32 n;
    s32 w;
    f32 d;

    s = &o->s20;
    d = o->pos.z - D_L01_001E29C8[0];
    if (d < -7.0f || (s->w14 != 0 && func_0038CB00((s16 *)&o->h0A) != 0)) {
        n = s->w10 - 1;
        s->w10 = n;
        if (n <= 0) {
            func_003CD250((Obj *)o);
            D_L01_001E02B4_00471FB0 = D_L01_001E02B4 - 1;
            return;
        }
        o->w4 = (o->w4 & 0xFFFFFF) + (n << 24);
    } else {
        w = o->w4;
        if ((w >> 24) < s->w10) {
            o->w4 = w + 0x1000000;
        }
    }
    if (((s32)o & 0x80) == 0) {
        o->b8 = o->b8 + 2;
    } else {
        o->b8 = o->b8 - 2;
    }
    vec_add_ba(&o->pos, &o->pos, &s->vel);
    vec_add_ab(&o->pos, &o->pos, &D_L01_001E02C0);
    func_L01_004CAB30(&o->pos, &o->pos);
    if (s->w14 == 0) {
        d = func_0038D0B0((f32)(D_L01_001DFB40 & (o->h0A - 1)) / (f32)o->h0A * 6.2831855f);
        func_0038CE20(&tmp, &D_L01_001E29F0, d * 0.020000001f);
        vec_add_ba(&o->pos, &tmp, &o->pos);
    }
}
/* localdecomp:end func_L01_00471FB0 */

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

/* localdecomp:start func_L01_004723B0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4723B0;
extern void func_L01_004CAB30(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_L01_004451A8(f32);
extern f32 func_L01_004451A0(f32);

void func_L01_004723B0(u8 *p)
{
    u8 *v = p + 0x20;
    V4_4723B0 a;
    V4_4723B0 b;
    f32 t;
    f32 k;

    b.w = 0.0f;
    b.x = *(f32 *)(p + 0x20);
    b.y = *(f32 *)(v + 4);
    b.z = *(f32 *)(v + 8);
    func_L01_004CAB30(p + 0x10, p + 0x10);
    t = (f32)*(s16 *)(p + 0xA) / (f32)v[0x11];
    k = 1.0f - t;
    if (v[0x13] == 0) {
        *(u32 *)(p + 4) = func_0038DBD8(0x103080, *(s32 *)(v + 0xC), k) | (v[0x12] << 24);
        *(f32 *)(p + 0xC) = *(f32 *)(v + 0x14) + (*(f32 *)(v + 0x18) - *(f32 *)(v + 0x14)) * k;
        func_0038CE20(&a, &b, *(f32 *)(v + 0x1C) * func_L01_004451A8(k));
    } else {
        f32 x = func_L01_004451A0(k);
        f32 al = (f32)v[0x12];
        *(u32 *)(p + 4) = *(s32 *)(v + 0xC) | ((s32)(al - al * x) << 24);
        func_0038CE20(&a, &b, *(f32 *)(v + 0x1C));
    }
    vec_add_ba(p + 0x10, &a, p + 0x10);
    p[8] = p[8] + v[0x10];
    if (func_0038CB00((s16 *)(p + 0xA)) != 0) {
        if (v[0x13] == 0) {
            v[0x13] = 1;
            v[0x11] = 0x11;
            *(s16 *)(p + 0xA) = 0x11;
        } else {
            func_003CD250((Obj *)p);
        }
    }
}
/* localdecomp:end func_L01_004723B0 */

INCLUDE_ASM("asm/levels", func_L01_00472560);

INCLUDE_ASM("asm/levels", func_L01_00472758);
