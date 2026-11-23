#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003B68D8 */
typedef struct {
    vu0_v4 v0;
    vu0_v4 v10;
    f32 f20;
    f32 f24;
    s32 w28;
    u8 pad2C[4];
    s32 w30;
    u8 pad34[0x48 - 0x34];
    f32 f48;
} V_003B68D8;

extern void func_003C2F58(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_003C48A8(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_L03_003B7458(u8 *);
extern void func_L03_003B6F98(void *);
extern void func_L03_003ADB38(u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00404808(void *, void *);
extern s32 func_L01_004561B8(void *);
extern void func_003C2880(void *);
__asm__(".extern D_L03_001DEA3C, 4");
extern s32 D_L03_001DEA3C;
__asm__(".extern D_L03_001DEA40, 4");
extern s32 D_L03_001DEA40;
__asm__(".extern D_L03_001DEA44, 4");
extern s32 D_L03_001DEA44;
__asm__(".extern D_L03_001DEA48, 4");
extern f32 D_L03_001DEA48;
__asm__(".extern D_L03_001DEA4C, 4");
extern f32 D_L03_001DEA4C;
__asm__(".extern D_L03_001DEA50, 4");
extern f32 D_L03_001DEA50;
__asm__(".extern D_L03_001DEA54, 4");
extern f32 D_L03_001DEA54;
__asm__(".extern D_L03_001DEA58, 4");
extern s32 D_L03_001DEA58;
__asm__(".extern D_L03_001DEA5C, 4");
extern f32 D_L03_001DEA5C;
__asm__(".extern D_L03_001DEA60, 4");
extern f32 D_L03_001DEA60;

void func_L03_003B68D8(u8 *o) {
    V_003B68D8 *v;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 t;
    vu0_v4 m[3];
    u8 *p;

    v = *(V_003B68D8 **)(o + 0x68);
    switch (o[0x20]) {
    case 5:
        func_L03_003B7458(o);
        *(vu0_q *)&a = *(vu0_q *)(o + 0xE0);
        func_0038CF68(&a, &a, -D_L03_001DEA54);
        vec_add_ba(o + 0x10, &a, o + 0x10);
        *(vu0_q *)&b = *(vu0_q *)(o + 0xE0);
        v->f48 += D_L03_001DEA5C;
        func_0038CF68(&b, &b, v->f48);
        vec_add_ba(o + 0x10, &b, o + 0x10);
        if (*(u16 *)(o + 0x96) >= D_L03_001DEA58) {
            v->f48 = 0.0f;
            func_L01_004450F0(o, 0, -1);
        }
        func_L01_00404808(func_L03_003B6F98, o);
        break;
    case 0:
        func_003C2F58(v->w28, v->w30, &v->v10);
        func_003C2F58(v->w28, v->w30 + 0x20, v);
        v->f24 += v->f20;
        func_003C2F58(v->w28, 0x40, &t);
        vec_sub_ab(&b, &t, &v->v10);
        func_0038CF68(&b, &b, D_L03_001DEA4C);
        vec_sub_ab(&a, v, &v->v10);
        func_0038CF68(&c, &a, D_L03_001DEA48);
        func_0038CF68(&a, &a, v->f24);
        vec_add_ba(o + 0x10, &v->v10, &a);
        func_0038CE90(&d, &b, &c);
        func_0038CF68(&d, &d, D_L03_001DEA50);
        func_0038CE68(&b, &c);
        func_0038CE68(&c, &d);
        func_0038CE68(&d, &b);
        *(vu0_q *)&m[D_L03_001DEA3C] = *(vu0_q *)&c;
        *(vu0_q *)&m[D_L03_001DEA40] = *(vu0_q *)&b;
        *(vu0_q *)&m[D_L03_001DEA44] = *(vu0_q *)&d;
        func_003C48A8(m, o + 0xF0);
        *(f32 *)(o + 0xF0) = func_0038DAB8(*(f32 *)(o + 0xF0), 1.5707964f);
        func_0038D308(o + 0xC0, o + 0xF0);
        if (func_0038CF38(o + 0x10, v) <= v->f20 * 0.88f) {
            func_L01_004450F0(o, 6, -1);
        }
        o[0xA8] = 0xFF;
        func_L01_00404808(func_L03_003B6F98, o);
        break;
    case 1:
        if (func_L01_004561B8(o) != 0) {
            *(s32 *)(o + 0x98) = 0;
        }
        func_L01_00404808(func_L03_003B6F98, o);
        break;
    case 4:
        o[0x31] = 1;
        *(u16 *)(o + 0x34) &= 0xFFFE;
        func_L01_004450F0(o, 0, -1);
        break;
    case 2:
        p = *(u8 **)(o + 0xB8);
        if (p != 0 && *(s16 *)(p + 0xAA) == 0x1AE0) {
            func_L03_003ADB38(p);
        }
        func_003C2880(o);
        return;
    case 6:
        func_L03_003B7458(o);
        *(vu0_q *)&a = *(vu0_q *)(o + 0xE0);
        v->f48 -= D_L03_001DEA60;
        func_0038CF68(&a, &a, v->f48);
        vec_add_ba(o + 0x10, &a, v);
        if (*(u16 *)(o + 0x96) >= D_L03_001DEA58) {
            v->f48 = 0.0f;
            func_003C2880(o);
            return;
        }
        func_L01_00404808(func_L03_003B6F98, o);
        break;
    }
    *(u16 *)(o + 0x96) += 1;
}
/* localdecomp:end func_L03_003B68D8 */

/* localdecomp:start func_L03_003B6CB8 */
#include "vu0.h"

typedef int s128 __attribute__((mode(TI)));

typedef struct S_3B6CB8o_003B6CB8 {
    u8 pad0[0xF0];
    f32 fF0;
} S_3B6CB8o_003B6CB8;

typedef struct {
    S_3B6CB8o_003B6CB8 *owner;
} S_3B6CB8p_003B6CB8;

typedef struct {
    u8 pad0[0x10];
    s128 pos;
    f32 f20;
    s32 w24;
    S_3B6CB8o_003B6CB8 *p28;
    u8 pad2C[4];
    s32 w30;
    s32 w34;
    f32 f38;
    f32 f3C;
    u8 pad40[4];
    f32 f44;
    s32 w48;
} S_3B6CB8v_003B6CB8;

typedef struct {
    u8 pad0[0x10];
    s128 pos;
    u8 b20;
    u8 pad21[0xF];
    u8 b30;
    u8 b31;
    s16 h32;
    u8 pad34[0x68 - 0x34];
    void *vars;
    u8 pad6C[0x96 - 0x6C];
    s16 h96;
    u8 pad98[0xB8 - 0x98];
    void *pB8;
} S_3B6CB8m_003B6CB8;

extern void *func_003C24B0(s32, s32);
extern void func_003C2F58(s32, s32, void *);
extern void func_L03_0034B218_003B6CB8(u8 *, s32, s32, f32, s32, void *);
extern void func_L03_003B7190_003B6CB8(void);
extern s32 D_L03_001E1DE8_003B6CB8;
__asm__(".extern D_L03_001DEA68_003B6CB8, 4");
extern f32 D_L03_001DEA68_003B6CB8;
__asm__(".extern D_L03_001DEA64_003B6CB8, 4");
extern f32 D_L03_001DEA64_003B6CB8;
__asm__(".extern D_L03_001DEA38_003B6CB8, 4");
extern s32 D_L03_001DEA38_003B6CB8;

S_3B6CB8m_003B6CB8 *func_L03_003B6CB8(S_3B6CB8m_003B6CB8 *a0, s32 a1, f32 f)
{
    S_3B6CB8m_003B6CB8 *m = func_003C24B0(0x1C06, 0x80);
    if (m != 0) {
        S_3B6CB8v_003B6CB8 *v;
        S_3B6CB8p_003B6CB8 *p;
        m->b30 = 0xFF;
        m->b31 = 1;
        m->b20 = 5;
        v = m->vars;
        m->h32 = 0x40;
        m->pB8 = a0;
        m->h96 = 0;
        v->f20 = f * 0.020000001f;
        v->f38 = D_L03_001DEA68_003B6CB8;
        v->f3C = D_L03_001DEA64_003B6CB8;
        v->w24 = 0;
        v->w30 = a1;
        v->w34 = 0;
        v->w48 = 0;
        p = a0->vars;
        func_003C2F58((s32)p->owner, a1, &v->pos);
        func_003C2F58((s32)p->owner, a1 + 0x20, v);
        v->f44 = p->owner->fF0;
        v->p28 = p->owner;
        m->pos = v->pos;
    }
    if (D_L03_001DEA38_003B6CB8 == 0) {
        D_L03_001DEA38_003B6CB8 = 1;
        func_L03_0034B218_003B6CB8((u8 *)&D_L03_001E1DE8_003B6CB8, 0x19, 0x11, 2.1f, 0, func_L03_003B7190_003B6CB8);
    }
    return m;
}
/* localdecomp:end func_L03_003B6CB8 */

/* localdecomp:start func_L03_003B6DF8 */
typedef struct S_003B6DF8 {
    vu0_v4 v[4];
    s32 c[4];
    f32 z0;
    f32 z1;
    f32 z2;
    f32 g0;
    f32 g1;
    f32 z3;
    f32 g2;
    f32 g3;
    u8 pad70[0x20];
} S_003B6DF8;
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);
extern vu0_v4 D_L03_001D7C90[];
__asm__(".extern D_L03_001DEA70, 4");
extern f32 D_L03_001DEA70;

void func_L03_003B6DF8(u8 *a0, s32 a1, s32 c, s32 a3, f32 size, f32 off, f32 rot) {
    S_003B6DF8 s;
    vu0_v4 m[4];
    vu0_v4 t;
    vu0_v4 d;
    vu0_v4 r[3];
    s32 i;

    func_003D93B0(&s, a1, a3, 0x80);
    s.c[3] = c;
    s.c[2] = c;
    s.c[1] = c;
    s.c[0] = c;
    s.z0 = 0.0f;
    s.z1 = 0.0f;
    s.z2 = 0.0f;
    s.g0 = 1.0f;
    s.g1 = 1.0f;
    s.z3 = 0.0f;
    s.g2 = 1.0f;
    s.g3 = 1.0f;
    *(vu0_q *)&m[3] = *(vu0_q *)(a0 + 0x10);
    *(vu0_q *)&m[0] = *(vu0_q *)(a0 + 0xD0);
    *(vu0_q *)&m[1] = *(vu0_q *)(a0 + 0xC0);
    *(vu0_q *)&m[2] = *(vu0_q *)(a0 + 0xE0);
    *(vu0_q *)&t = *(vu0_q *)(a0 + 0xE0);
    func_0038CF68(&t, &t, D_L03_001DEA70);
    vec_add_ab(&m[3], &t, &m[3]);
    if (rot != 0.0f) {
        *(vu0_q *)&d = 0;
        d.x = rot;
        func_0038D308(r, &d);
        func_0038D5F0(m, m, r);
    }
    func_0038CE20(&d, m, off);
    vec_add_ab(&m[3], &m[3], &d);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&s.v[i], &D_L03_001D7C90[i], size);
        func_0038D028(&s.v[i], &s.v[i], m);
    }
    func_003D2DA0(&s, 0, 1);
}
/* localdecomp:end func_L03_003B6DF8 */

/* localdecomp:start func_L03_003B6F98 */
typedef struct { u8 p0[0x34]; f32 f34; f32 f38; f32 f3C; } S_003B6F98;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_003B6F98 *st; u8 p6C[0x96 - 0x6C]; u16 h96; } O_003B6F98;
extern f32 func_003C4138(void *, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L03_003B6DF8(u8 *, s32, s32, s32, f32, f32, f32);
__asm__(".extern D_L03_001DEA6C, 4");
extern f32 D_L03_001DEA6C;
__asm__(".extern D_L03_001DEA64, 4");
extern f32 D_L03_001DEA64;
__asm__(".extern D_L03_001DEA68, 4");
extern f32 D_L03_001DEA68;
__asm__(".extern D_L03_001DEA74, 4");
extern u32 D_L03_001DEA74;
__asm__(".extern D_L03_001DEA78, 4");
extern u32 D_L03_001DEA78;
__asm__(".extern D_L03_001DEA7C, 4");
extern s32 D_L03_001DEA7C;
__asm__(".extern D_L03_001DEA80, 4");
extern s32 D_L03_001DEA80;
__asm__(".extern D_L03_001DEA84, 4");
extern f32 D_L03_001DEA84;

void func_L03_003B6F98(void *self) {
    O_003B6F98 *o = (O_003B6F98 *)self;
    S_003B6F98 *st;
    f32 ang;
    u32 a;
    u32 b;
    s32 al;
    u32 r;
    u32 g;
    u32 bl;

    st = o->st;
    if (func_003C4138(&st->f38, st->f3C, D_L03_001DEA6C) == 0.0f) {
        if (st->f3C == D_L03_001DEA64) {
            st->f3C = D_L03_001DEA68;
        } else {
            st->f3C = D_L03_001DEA64;
        }
    }
    ang = func_0038DAB8(0.0f, st->f34 * 0.017453292f);
    if (o->b20 == 6) {
        a = D_L03_001DEA74;
        b = D_L03_001DEA78;
        r = a & 0xFF;
        g = (a >> 8) & 0xFF;
        bl = (a >> 16) & 0xFF;
        al = a >> 24;
        al -= o->h96 * 5;
        if (al < 0) {
            al = 0;
        }
        a = (al << 24) | (bl << 16) | (g << 8) | r;
        r = b & 0xFF;
        g = (b >> 8) & 0xFF;
        bl = (b >> 16) & 0xFF;
        al = b >> 24;
        al -= o->h96 * 5;
        if (al < 0) {
            al = 0;
        }
        b = (al << 24) | (bl << 16) | (g << 8) | r;
        func_L03_003B6DF8((u8 *)o, D_L03_001DEA80, b, 1, st->f38, D_L03_001DEA84, -ang);
        func_L03_003B6DF8((u8 *)o, D_L03_001DEA7C, a, 1, st->f38, D_L03_001DEA84, ang);
    } else {
        func_L03_003B6DF8((u8 *)o, D_L03_001DEA80, D_L03_001DEA78, 1, st->f38, D_L03_001DEA84, -ang);
        func_L03_003B6DF8((u8 *)o, D_L03_001DEA7C, D_L03_001DEA74, 1, st->f38, D_L03_001DEA84, ang);
    }
    st->f34 = st->f34 + 1.0f;
    if (st->f34 > 359.0f) {
        st->f34 = 0.0f;
    } else if (st->f34 < 0.0f) {
        st->f34 = 359.0f;
    }
}
/* localdecomp:end func_L03_003B6F98 */

/* localdecomp:start func_L03_003B7190 */
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);

void func_L03_003B7190(u8 *a0, u8 *a1) {
    u8 *o;
    s32 n;
    f32 zero;
    f32 ang;
    f32 rad;
    u16 e;
    f32 lo;
    f32 hi;

    if (a1 == 0) {
        return;
    }
    o = *(u8 **)a1;
    n = *(s32 *)(a1 + 4);
    if (o == 0 || n == 0) {
        return;
    }
    if ((u8)(o[0x20] + 2) < 2) {
        *(s16 *)(a0 + 0xA) = 0;
        return;
    }
    if (*(u16 *)(a1 + 0xA) & 1) {
        zero = 0.0f;
        ang = func_0038DB48(func_003824E0(zero, 6.2831855f));
        rad = func_003824E0(0.25f, 0.6f);
        *(vu0_q *)(a0 + 0x10) = *(vu0_q *)(o + 0x10);
        *(f32 *)(a0 + 0x10) += rad * func_0038D098(ang);
        *(f32 *)(a0 + 0x14) += rad * func_0038D098(ang);
        *(f32 *)(a0 + 0x18) += rad * func_0038D0B0(ang);
        *(f32 *)(a1 + 0x10) = *(f32 *)(o + 0x10);
        *(f32 *)(a1 + 0x14) = *(f32 *)(o + 0x14);
        *(f32 *)(a1 + 0x18) = *(f32 *)(o + 0x18);
        *(s32 *)(a0 + 4) = 0x88880220;
        *(s32 *)(a0 + 4) = ((s32)((f32)*(s16 *)(a0 + 0xA) * 128.0f / (f32)*(s16 *)(a1 + 8)) << 24) | 0x880220;
        e = *(u16 *)(a1 + 0xE);
        lo = (f32)(e & 0xFF);
        hi = lo + (f32)*(s16 *)(a1 + 8) * (f32)(e >> 8) * 0.00390625f;
        a0[8] = (s32)func_003C4088(lo, hi, func_L03_0034B148(*(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8), zero));
        *(f32 *)(a0 + 0xC) = 210000.0f;
    }
    *(s32 *)(a0 + 4) = (*(s32 *)(a0 + 4) & 0xFFFFFF) | ((s32)((f32)*(s16 *)(a0 + 0xA) * 128.0f / (f32)*(s16 *)(a1 + 8)) << 24);
    *(f32 *)(a0 + 0x10) += *(f32 *)(o + 0x10) - *(f32 *)(a1 + 0x10);
    *(f32 *)(a1 + 0x10) = *(f32 *)(o + 0x10);
    *(f32 *)(a0 + 0x14) += *(f32 *)(o + 0x14) - *(f32 *)(a1 + 0x14);
    *(f32 *)(a1 + 0x14) = *(f32 *)(o + 0x14);
    *(f32 *)(a0 + 0x18) += *(f32 *)(o + 0x18) - *(f32 *)(a1 + 0x18);
    *(f32 *)(a1 + 0x18) = *(f32 *)(o + 0x18);
}
/* localdecomp:end func_L03_003B7190 */

/* localdecomp:start func_L03_003B7458 */
extern void func_003C2F58(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_003C48A8(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);
__asm__(".extern D_L03_001DEA3C, 4");
extern s32 D_L03_001DEA3C;
__asm__(".extern D_L03_001DEA40, 4");
extern s32 D_L03_001DEA40;
__asm__(".extern D_L03_001DEA44, 4");
extern s32 D_L03_001DEA44;
__asm__(".extern D_L03_001DEA48, 4");
extern f32 D_L03_001DEA48;
__asm__(".extern D_L03_001DEA4C, 4");
extern f32 D_L03_001DEA4C;
__asm__(".extern D_L03_001DEA50, 4");
extern f32 D_L03_001DEA50;

void func_L03_003B7458(u8 *a0) {
    u8 *v;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 t;
    vu0_v4 m[3];

    v = *(u8 **)(a0 + 0x68);
    func_003C2F58(*(s32 *)(v + 0x28), *(s32 *)(v + 0x30), v + 0x10);
    func_003C2F58(*(s32 *)(v + 0x28), *(s32 *)(v + 0x30) + 0x20, v);
    *(f32 *)(v + 0x24) += *(f32 *)(v + 0x20);
    func_003C2F58(*(s32 *)(v + 0x28), 0x40, &t);
    vec_sub_ab(&b, &t, v + 0x10);
    func_0038CF68(&b, &b, D_L03_001DEA4C);
    vec_sub_ab(&a, v, v + 0x10);
    func_0038CF68(&c, &a, D_L03_001DEA48);
    func_0038CF68(&a, &a, *(f32 *)(v + 0x24));
    vec_add_ba(a0 + 0x10, v + 0x10, &a);
    func_0038CE90(&d, &b, &c);
    func_0038CF68(&d, &d, D_L03_001DEA50);
    func_0038CE68(&b, &c);
    func_0038CE68(&c, &d);
    func_0038CE68(&d, &b);
    *(vu0_q *)&m[D_L03_001DEA3C] = *(vu0_q *)&c;
    *(vu0_q *)&m[D_L03_001DEA40] = *(vu0_q *)&b;
    *(vu0_q *)&m[D_L03_001DEA44] = *(vu0_q *)&d;
    func_003C48A8(m, a0 + 0xF0);
    *(f32 *)(a0 + 0xF0) = func_0038DAB8(*(f32 *)(a0 + 0xF0), 1.5707964f);
    func_0038D308(a0 + 0xC0, a0 + 0xF0);
}
/* localdecomp:end func_L03_003B7458 */
