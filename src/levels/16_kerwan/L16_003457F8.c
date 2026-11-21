#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L16_003457F8 */
typedef struct C_003457F8 {
    u8 pad0[0x10];
    s32 i10;
    u8 pad14[0x30];
    u16 h44;
} C_003457F8;

typedef struct M_003457F8 {
    u8 pad0[0x10];
    vu0_v4 v10;
    u8 b20;
    u8 pad21[3];
    C_003457F8 *p24;
    u8 pad28[8];
    union {
        long d;
        struct {
            u8 b30;
            u8 b31;
            u16 h32;
            u16 h34;
        } s;
    } u30;
    long d38;
    u8 pad40[0x28];
    void *p68;
    u8 pad6C[0x2C];
    s32 i98;
    u8 pad9C[0x54];
    vu0_v4 vF0;
} M_003457F8;

typedef struct T_003457F8 {
    u8 pad0[0x30];
    u8 v30[0x40];
    M_003457F8 *p70;
    u8 pad74[4];
    s32 i78;
} T_003457F8;

struct S_003459A0;
extern u8 *D_L16_0021ED00[];
__asm__(".extern D_L16_0021ED00, 16");
void func_L16_003459A0(struct S_003459A0 *);
void func_L16_00345BB0(void *, s32);
void func_003C7C38(void *);
void func_003C4DA8(void *, void *, void *, void *);
extern void func_003C2880(void *);
extern void func_L01_004AA7E8(void *, s32);

void func_L16_003457F8(M_003457F8 *m) {
    T_003457F8 *p = m->p68;
    vu0_v4 pos;
    vu0_v4 rot;
    vu0_v4 d;
    vu0_v4 *r;

    if (p->p70 != 0) {
        if ((m->u30.d & 0x104100000000LL) == 0x4100000000LL && m->i98 == 0) {
            p->p70->u30.s.h34 |= 0x41;
            p->p70->u30.s.h34 &= 0xEFFF;
            p->p70->i98 = 0;
            func_L01_004AA7E8(p->p70, 1);
        } else {
            p->p70->u30.s.h34 &= 0xFFBE;
            p->p70->u30.s.h34 |= p->p70->p24->h44 & 0x1000;
            p->p70->i98 = p->p70->p24->i10;
        }
    }
    switch (m->b20) {
    case 0:
        if (p->i78 == -1) {
            func_003C2880(m);
        } else {
            func_L16_003459A0((struct S_003459A0 *)m);
        }
        break;
    case 1:
        pos = m->v10;
        rot = m->vF0;
        r = &m->vF0;
        func_L16_00345BB0(m, (s32)D_L16_0021ED00[p->i78]);
        vec_sub_ba(&d, &m->v10, &pos);
        func_003C4DA8(p->v30, &d, &rot, r);
        if (p->p70 != 0) {
            p->p70->v10 = m->v10;
            p->p70->vF0 = m->vF0;
            func_003C7C38(p->p70);
        }
        break;
    }
}
/* localdecomp:end func_L16_003457F8 */

/* localdecomp:start func_L16_003459A0 */
typedef struct S_003459A0 {
    u8 pad0[0x10];
    vu0_q q10;
    u8 pad20[0xC];
    f32 f2C;
    u8 b30;
    u8 b31;
    u16 h32;
    u8 pad34[4];
    long d38;
    u8 pad40[0x28];
    struct T_003459A0 *p68;
    u8 pad6C[0x3E];
    s16 hAA;
    u8 padAC[0x44];
    vu0_q qF0;
} S_003459A0;

typedef struct T_003459A0 {
    u8 pad0[0x30];
    u8 v30[0x3C];
    s32 i6C;
    S_003459A0 *p70;
    u8 pad74[4];
    s32 i78;
    u8 pad7C[4];
    f32 f80;
    s32 i84;
    s32 i88;
    u8 pad8C[4];
    vu0_q q90;
    vu0_q qA0;
} T_003459A0;

extern f32 D_L16_001DD184;
__asm__(".extern D_L16_001DD184, 4");
extern f32 D_L16_001DD1A0;
__asm__(".extern D_L16_001DD1A0, 4");
extern u8 D_L16_001D66B0;
extern S_003459A0 *func_003C24B0(s32, s32);
extern void func_003C7C38(void *);
extern void func_003C4DA8(void *, void *, void *, void *);
void func_L16_00345AD0(s32);
void func_L01_004450F0(void *, s32, s32);

void func_L16_003459A0(S_003459A0 *a) {
    T_003459A0 *p;
    a->b30 = 0xFF;
    p = a->p68;
    p->i6C |= 3;
    a->b30 = 0xFF;
    a->h32 = 0x80;
    p->i88 = 0;
    p->f80 = D_L16_001DD184;
    p->i84 = 0;
    p->q90 = a->q10;
    p->qA0 = a->qF0;
    if (a->hAA == 0x1BB1) {
        a->f2C *= D_L16_001DD1A0;
        p->p70 = func_003C24B0(0x1BB3, 0);
        if (p->p70 != 0) {
            p->p70->h32 = a->h32;
            p->p70->b31 = a->b31;
            p->p70->b30 = 0;
            p->p70->d38 = a->d38;
            p->p70->f2C *= D_L16_001DD1A0;
            p->p70->q10 = a->q10;
            p->p70->qF0 = a->qF0;
            func_003C7C38(p->p70);
        }
    }
    func_003C4DA8(p->v30, &D_L16_001D66B0, &a->qF0, &a->qF0);
    func_L16_00345AD0(p->i78);
    func_L01_004450F0(a, 2, -1);
}
/* localdecomp:end func_L16_003459A0 */

/* localdecomp:start func_L16_00345AD0 */
typedef int u128_t __attribute__((mode(TI)));

extern f32 func_0038CF00(void *, void *);
extern u8 *D_L16_0021ED00[];
__asm__(".extern D_L16_0021ED00, 16");
extern f32 D_L16_00278200[];
__asm__(".extern D_L16_00278200, 16");
extern s32 D_L16_001DD1A4;
__asm__(".extern D_L16_001DD1A4, 4");

void func_L16_00345AD0(s32 a0) {
    u8 *p;
    s32 i;
    s32 j;
    u128_t t1;
    u128_t t2;

    if (a0 != D_L16_001DD1A4) {
        p = D_L16_0021ED00[a0];
        if (*(s32 *)p < 0x101) {
            for (i = 0; i < *(s32 *)p; i++) {
                t1 = *(u128_t *)(p + i * 16 + 0x10);
                j = (i + 1) % *(s32 *)p;
                t2 = *(u128_t *)(p + j * 16 + 0x10);
                D_L16_00278200[i] = func_0038CF00(&t1, &t2);
            }
            D_L16_001DD1A4 = a0;
        }
    }
}
/* localdecomp:end func_L16_00345AD0 */

/* localdecomp:start func_L16_00345BB0 */
extern f32 D_L16_001DD184;
__asm__(".extern D_L16_001DD184, 4");
extern u8 *D_L16_001E015C;
__asm__(".extern D_L16_001E015C, 16");
extern f32 D_L16_001DD188;
__asm__(".extern D_L16_001DD188, 4");
extern f32 D_L16_001DD18C;
__asm__(".extern D_L16_001DD18C, 4");
extern f32 D_L16_001DD190;
__asm__(".extern D_L16_001DD190, 4");
extern f32 D_L16_001DD194;
__asm__(".extern D_L16_001DD194, 4");
extern f32 D_L16_001DD198;
__asm__(".extern D_L16_001DD198, 4");
extern f32 D_L16_001DD19C;
__asm__(".extern D_L16_001DD19C, 4");
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038CE20(void *, void *, f32);
f32 func_L16_00345DE8(s32, f32, f32, f32);
f32 func_L16_00345E98(s32, f32, f32, f32);
void func_L16_00345F50(s32, void *, f32, f32);

void func_L16_00345BB0(void *arg0, s32 arg1) {
    u8 *o = arg0;
    u8 *p;
    u8 *q;
    u8 *r;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    f32 f;
    f32 t;
    f32 v;
    f32 x;
    f32 w;
    f32 g;
    f32 da;
    f32 db;

    p = *(u8 **)(o + 0x68);
    if (*(s32 *)(p + 0x74) >= 0) {
        q = D_L16_001E015C + (*(s32 *)(p + 0x74) << 8);
        g = *(f32 *)(p + 0x7C);
        r = *(u8 **)(q + 0x68);
        t = func_0038D0B0(func_0038DBA0(*(f32 *)(o + 0xF8), *(f32 *)(q + 0xF8)));
        *(f32 *)(p + 0x88) = func_L16_00345E98(arg1, *(f32 *)(r + 0x88),
            g + (t * (D_L16_001DD194 * *(f32 *)(p + 0x8C) + D_L16_001DD198) + D_L16_001DD19C), *(f32 *)(p + 0x8C));
    } else {
        func_003C4138((f32 *)(p + 0x84), *(f32 *)(p + 0x80), D_L16_001DD18C);
        v = *(f32 *)(p + 0x84);
        if (D_L16_001DD188 < v) {
            *(f32 *)(p + 0x84) = D_L16_001DD188;
        } else if (v < D_L16_001DD184) {
            *(f32 *)(p + 0x84) = D_L16_001DD184;
        }
        *(f32 *)(p + 0x88) = func_L16_00345DE8(arg1, *(f32 *)(p + 0x88), *(f32 *)(p + 0x84), *(f32 *)(p + 0x8C));
    }
    da = func_L16_00345DE8(arg1, *(f32 *)(p + 0x88), D_L16_001DD190, *(f32 *)(p + 0x8C));
    func_L16_00345F50(arg1, &a, da, *(f32 *)(p + 0x8C));
    db = func_L16_00345E98(arg1, *(f32 *)(p + 0x88), D_L16_001DD190, *(f32 *)(p + 0x8C));
    func_L16_00345F50(arg1, &b, db, *(f32 *)(p + 0x8C));
    vec_add_ab(&c, &a, &b);
    func_0038CE20(&c, &c, 0.5f);
    *(f32 *)(p + 0x84) = func_0038CF00(o + 0x10, &c);
    *(u128_t *)(o + 0x10) = *(u128_t *)&c;
    f = *(f32 *)(o + 0xF8);
    *(f32 *)(o + 0xF8) = func_0038D160(a.x - b.x, a.y - b.y);
    w = 1.0f - fabs_asm(f - *(f32 *)(o + 0xF8)) / 1.5707964f;
    x = (((w < 0.0f) ? 0.0f : w) > 1.0f) ? 1.0f : ((w < 0.0f) ? 0.0f : w);
    *(f32 *)(p + 0x80) = D_L16_001DD184 + (D_L16_001DD188 - D_L16_001DD184) * x;
}
/* localdecomp:end func_L16_00345BB0 */

/* localdecomp:start func_L16_00345DE8 */
extern f32 D_L16_00278200[];

f32 func_L16_00345DE8(s32 a0, f32 t, f32 d, f32 unused) {
    s32 n;
    s32 i;
    f32 rem;
    f32 seg;
    s32 next;
    f32 step;

    if (0.0f < d) {
        n = *(s32 *)a0;
        do {
            i = (s32)t;
            rem = 1.0f - (t - cvtsw_asm(cvtws_asm(t)));
            seg = D_L16_00278200[i];
            next = (i + 1) % n;
            step = d / seg;

            if (rem < step) {
                d = d - rem * seg;
                t = (f32)next;
            } else {
                t = t + step;
                d = 0.0f;
            }
        } while (0.0f < d);
    }
    return t;
}
/* localdecomp:end func_L16_00345DE8 */

/* localdecomp:start func_L16_00345E98 */
f32 func_L16_00345E98(s32 path, f32 position, f32 distance, f32 unused) {
    f32 fraction = position - cvtsw_asm(cvtws_asm(position));
    s32 index = (s32)position;

    while (distance > 0.0f) {
        f32 length = D_L16_00278200[index];
        f32 step = distance / length;
        if (fraction < step) {
            distance -= fraction * length;
            index--;
            if (index < 0) {
                index = *(s32 *)path - 1;
            }
            fraction = 1.0f;
            position = (f32)index;
        } else {
            position = (f32)index + (fraction - step);
            distance = 0.0f;
        }
    }
    return position;
}
/* localdecomp:end func_L16_00345E98 */

/* localdecomp:start func_L16_00345F50 */
void func_L16_00345F50(s32 arg0, void *arg1, f32 t, f32 k) {
    extern void func_L16_00346010(void *, s32, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    s32 *path = (s32 *)arg0;
    struct {
        vu0_v4 a;
        vu0_v4 b;
        vu0_v4 c;
    } l;
    s32 i = (s32)t;

    func_L16_00346010(path, (i + 1) % path[0], &l.a, k);
    func_L16_00346010(path, i, &l.b, k);
    vec_sub_ba(&l.c, &l.a, &l.b);
    func_0038CE20(&l.c, &l.c, t - cvtsw_asm(cvtws_asm(t)));
    vec_add_ab(arg1, &l.b, &l.c);
}
/* localdecomp:end func_L16_00345F50 */

/* localdecomp:start func_L16_00346010 */

extern void func_0038CE90(float *, float *, float *);
extern void func_0038CF68(float, float *, float *);

void func_L16_00346010(void *arg0, s32 arg1, void *arg2, f32 arg3) {
    s32 n;
    vu0_v4 cur, prev, next, vC, vB, vA;

    n = *(s32 *)arg0;
    cur = *(vu0_v4 *)((u8 *)arg0 + 0x10 + 16 * (arg1 % n));
    prev = *(vu0_v4 *)((u8 *)arg0 + 0x10 + 16 * ((arg1 + n - 1) % n));
    next = *(vu0_v4 *)((u8 *)arg0 + 0x10 + 16 * ((arg1 + 1) % n));
    vec_sub_ba(&vC, &next, &prev);
    *(u128_t *)&vB = 0;
    vB.z = 1.0f;
    func_0038CE90((float *)&vA, (float *)&vB, (float *)&vC);
    func_0038CF68(arg3, (float *)&vA, (float *)&vA);
    vec_add_ab(arg2, &cur, &vA);
}
/* localdecomp:end func_L16_00346010 */

/* localdecomp:start func_L16_00346100 */
extern u8 *D_L16_001E015C;
__asm__(".extern D_L16_001E015C, 16");
__asm__(".extern D_L16_0021ED00, 16");
extern u8 D_L16_001D66B0;
__asm__(".extern D_L16_001D66B0, 16");
void func_L16_00346100(u8 *, s32);
void func_L16_00345BB0(void *, s32);
void func_003C7C38(void *);
void func_L01_004450F0(void *, s32, s32);
void func_003C4DA8(void *, void *, void *, void *);

void func_L16_00346100(u8 *arg0, s32 arg1) {
    u8 *temp_v1;
    s32 temp_a0;
    u8 *dst;

    temp_v1 = *(u8 **)(arg0 + 0x68);
    temp_a0 = *(s32 *)(temp_v1 + 0x74);
    if (temp_a0 >= 0) {
        func_L16_00346100(D_L16_001E015C + (temp_a0 << 8), arg1);
    }
    if (arg1 != 0) {
        func_L16_00345BB0(arg0, D_L16_0021ED00[*(s32 *)(temp_v1 + 0x78)]);
        func_L01_004450F0(arg0, 1, -1);
    } else {
        *(u128_t *)(arg0 + 0x10) = *(u128_t *)(temp_v1 + 0x90);
        *(u128_t *)(arg0 + 0xF0) = *(u128_t *)(temp_v1 + 0xA0);
        func_003C7C38(arg0);
        if (*(u8 **)(temp_v1 + 0x70) != 0) {
            *(u128_t *)(*(u8 **)(temp_v1 + 0x70) + 0x10) = *(u128_t *)(arg0 + 0x10);
            *(u128_t *)(*(u8 **)(temp_v1 + 0x70) + 0xF0) = *(u128_t *)(arg0 + 0xF0);
            func_003C7C38(*(u8 **)(temp_v1 + 0x70));
        }
        func_L01_004450F0(arg0, 2, -1);
    }
    dst = arg0 + 0xF0;
    func_003C4DA8(temp_v1 + 0x30, &D_L16_001D66B0, dst, dst);
}
/* localdecomp:end func_L16_00346100 */
