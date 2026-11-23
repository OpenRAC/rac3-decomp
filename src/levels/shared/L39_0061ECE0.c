#include "common.h"

/* localdecomp:start func_L39_0061ECE0 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct S_0061ECE0 {
    u128_t q00;
    u128_t q10;
    s32 i20;
    s32 i24;
    s32 i28;
    u8 pad2C[4];
    u128_t q30;
    u128_t q40;
    u128_t q50;
    u128_t q60;
    u128_t q70;
    u128_t q80;
    u128_t q90;
    u128_t qA0;
    u128_t qB0;
    u8 padC0[0x30];
    f32 *pF0;
    s32 iF4;
    s32 iF8;
    s32 iFC;
    u8 pad100[0x30];
    s32 i130;
    s32 i134;
    s32 i138;
    u8 pad13C[8];
    s32 i144;
    s32 i148;
    u8 pad14C[0xC];
    s32 i158;
    s32 i15C;
    u128_t q160;
} S_0061ECE0;

void func_L39_0061ECE0(S_0061ECE0 *s, u128_t *a1, s32 a2) {
    s32 t = a2 - 0x1E;
    s->i138 = 0;
    s->i144 = 0x1E;
    s->i130 = 0;
    s->i134 = 0;
    s->q00 = *a1;
    s->q10 = *a1;
    s->i20 = a2 - 0x20;
    qzero(&s->q30);
    qzero(&s->q40);
    s->i24 = a2 - 0x1F;
    qzero(&s->q50);
    s->i28 = 0;
    qzero(&s->q60);
    qzero(&s->qA0);
    qzero(&s->qB0);
    s->q70 = *a1;
    s->q80 = *a1;
    s->q90 = *a1;
    s->iF4 = t;
    s->iF8 = t;
    s->iFC = t;
    s->i15C = -1;
    s->i158 = -1;
    s->i148 = 1;
}
/* localdecomp:end func_L39_0061ECE0 */

LINKER_REMNANT("asm/levels", func_L39_0061ED70);

INCLUDE_ASM("asm/levels", func_L39_0061ED80);

/* localdecomp:start func_L39_0061F3F0 */
#include "vu0.h"
typedef int Q_0061F3F0 __attribute__((mode(TI)));

typedef struct S_0061F3F0 {
    Q_0061F3F0 q00;
    Q_0061F3F0 q10;
    s32 i20;
    s32 i24;
    s32 i28;
    u8 pad2C[4];
    Q_0061F3F0 q30;
    Q_0061F3F0 q40;
    Q_0061F3F0 q50;
    Q_0061F3F0 q60;
    Q_0061F3F0 q70;
    Q_0061F3F0 q80;
    Q_0061F3F0 q90;
    Q_0061F3F0 qA0;
    Q_0061F3F0 qB0;
    u8 padC0[0x34];
    s32 iF4;
    s32 iF8;
    s32 iFC;
    u8 pad100[0x5C];
    s32 i15C;
    Q_0061F3F0 q160;
    Q_0061F3F0 q170;
    Q_0061F3F0 q180;
} S_0061F3F0;

extern s32 D_001A5DF8[];
extern f32 D_L39_0024118C;
extern void func_0038CE20(void *, void *, f32);

void func_L39_0061F3F0(void *arg) {
    S_0061F3F0 *s = arg;
    s32 now = D_001A5DF8[0];
    vu0_v4 pos;
    vu0_v4 vel;
    vu0_v4 dv;
    vu0_v4 da;
    vu0_v4 sum;
    Q_0061F3F0 *v;
    f32 dt;
    f32 inv;

    if (now == s->iFC) {
        return;
    }
    if (s->i15C >= 0 && now >= s->i15C) {
        s->q180 = s->q170;
        s->q170 = s->q160;
        s->i15C = -1;
    }
    dt = (f32)(now - s->iF4) / (D_L39_0024118C * 1000.0f);
    pos = *(vu0_v4 *)&s->q90;
    vel = *(vu0_v4 *)&s->qA0;
    v = &s->qA0;
    func_0038CE20(&dv, &s->q30, dt);
    func_0038CE20(&da, &s->q40, 0.5f * dt * dt);
    vec_add_ba(&sum, &dv, &da);
    {
        vu0_q b, p, a, r, q, d;
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(vu0_v4 *)&s->q70));
        __asm__("lqc2 %0, %1" : "=j"(p) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(sum));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(b), "j"(a));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&s->q90) : "j"(r));
        dt = (f32)(now - s->iFC) / (D_L39_0024118C * 1000.0f);
        __asm__("lqc2 %0, %1" : "=j"(q) : "m"(*(vu0_v4 *)&s->q90));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(d) : "j"(p), "j"(q));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)v) : "j"(d));
    }
    inv = 1.0f / dt;
    func_0038CE20(v, v, inv);
    vec_sub_ba(&s->qB0, &vel, v);
    func_0038CE20(&s->qB0, &s->qB0, inv);
    s->iFC = now;
}
/* localdecomp:end func_L39_0061F3F0 */

/* localdecomp:start func_L39_0061F5A0 */
#include "vu0.h"

typedef struct S_0061F5A0 {
    vu0_q q00[2];
    s32 i20[2];
    s32 i28;
    u8 pad2C[4];
    vu0_q q30;
    vu0_q q40;
    vu0_q q50;
    vu0_q q60;
    vu0_q q70;
    vu0_q q80;
    vu0_q q90;
    u8 padA0[0x50];
    f32 *pF0;
    s32 iF4;
    s32 iF8;
    s32 iFC;
    u8 pad100[0x10];
    vu0_q q110[2];
    s32 i130[2];
    s32 i138;
    u8 pad13C[4];
    s32 i140;
    u8 pad144[4];
    s32 i148;
} S_0061F5A0;

extern f32 D_L39_0024118C;
extern f32 func_L39_0061FDF0(vu0_q *, vu0_q *, vu0_q *);
extern void func_L39_00620240(f32 *out, s32 *outi, s32 base, f32 *a, f32 *b, s32 *p1, s32 *p2, f32 unused, f32 minv);
extern void func_0038CE20(void *, void *, f32);
extern void func_L39_0061FEA8(vu0_v4 *, vu0_v4 *, vu0_v4 *, vu0_v4 *, vu0_v4 *, s32 *, s32 *, s32 *);
extern void func_L39_00620168(vu0_v4 *, s32 *, s32, vu0_v4 *, vu0_v4, vu0_v4 *, s32, s32, f32);
extern void func_L39_006205B0(void *, void *, void *, s32 *, s32 *);
extern void func_L39_006202E0(f32 *, f32 *, f32 *, f32 *, f32 *, s32 *, s32 *, s32 *);

/* the index of the other of the two save slots */
static __inline__ s32 other_slot_0061F5A0(s32 i) {
    return (i + 1) % 2;
}

void func_L39_0061F5A0(S_0061F5A0 *s, vu0_q *pos, s32 time, s32 force) {
    vu0_v4 tmp;
    u8 buf[0x30];
    s32 t;
    s32 *curT;
    s32 *nextT;
    vu0_q *cur;
    vu0_q *nxt;
    f32 d;
    u8 hit;

    t = time;
    curT = &s->i20[s->i28];
    cur = &s->q00[s->i28];
    nxt = &s->q00[(s->i28 + 1) % 2];
    nextT = &s->i20[(s->i28 + 1) % 2];
    if (time < *curT) {
        return;
    }
    if (time < *nextT) {
        t = *nextT;
        *nextT = time;
        tmp = *(vu0_v4 *)nxt;
        *nxt = *pos;
        *(vu0_v4 *)pos = tmp;
    }
    d = func_L39_0061FDF0(cur, nxt, pos);
    hit = (s->i148 & 4) || d < s->pF0[0];
    if (force == 0) {
        s32 busy = s->i148 & 0x40;
        if (busy || (hit && s->iFC < *nextT)) {
            s32 i = s->i138;
            s32 *ts = s->i130;
            s32 n = other_slot_0061F5A0(i);
            if (!busy) {
                s32 *p;
                *(s->q110 + i) = *pos;
                p = &ts[s->i138];
                *p = time;
                s->i148 |= 0x40;
                s->i140 = *nextT;
            } else {
                s32 *p;
                *(s->q110 + n) = *pos;
                p = &ts[(s->i138 + 1) % 2];
                *p = time;
            }
            return;
        }
    }
    if (force != 0) {
        s32 *ts = s->i130;
        s32 *ta = &ts[s->i138];
        s32 *tb = &ts[(s->i138 + 1) % 2];
        if (*ta < *tb) {
            f32 d2 = func_L39_0061FDF0(nxt, pos, &s->q110[(s->i138 + 1) % 2]);
            if (!(s->i148 & 4) && s->pF0[0] <= d2) {
                s32 *p;
                *cur = *nxt;
                d = d2;
                hit = 0;
                *nxt = *pos;
                *pos = *(s->q110 + (s->i138 + 1) % 2);
                *curT = *nextT;
                *nextT = t;
                p = &ts[(s->i138 + 1) % 2];
                t = *p;
                *p = 0;
                s->i148 &= ~0x40U;
            } else {
                s->i140 = t;
                s->i138 = (s->i138 + 1) % 2;
            }
        } else {
            s->i148 &= ~0x40U;
        }
    }
    s->q70 = s->q90;
    s->iF4 = s->iFC;
    if (hit) {
        f32 f;
        func_L39_00620240((f32 *)&s->q80, &s->iF8, s->iFC, (f32 *)nxt, (f32 *)pos, nextT, &t, s->pF0[2], s->pF0[3]);
        f = 1.0f / ((f32)(t - *nextT) / (D_L39_0024118C * 1000.0f));
        vec_sub_ab(&s->q30, pos, nxt);
        func_0038CE20(&s->q30, &s->q30, f);
        qzero(&s->q40);
    } else {
        func_L39_0061FEA8((vu0_v4 *)&s->q30, (vu0_v4 *)&s->q40, (vu0_v4 *)cur, (vu0_v4 *)nxt, (vu0_v4 *)pos, curT, nextT, &t);
        tmp = *(vu0_v4 *)&s->q40;
        func_L39_00620168((vu0_v4 *)&s->q80, &s->iF8, s->iFC, (vu0_v4 *)&s->q30, tmp, (vu0_v4 *)pos, *nextT, t, s->pF0[4]);
    }
    if ((s->i148 & 2) || s->pF0[1] < d) {
        s->i148 = (s->i148 & ~1U) | 0x10;
        func_L39_006205B0(&s->q50, &s->q90, &s->q80, &s->iFC, &s->iF8);
        qzero(&s->q60);
    } else {
        vu0_q *a;
        vu0_q *b;
        s32 *ta;
        s32 *tb;
        if ((s->i148 & 1) && s->iFC < t) {
            s->i148 |= 0x20;
        }
        if (s->iFC > t) {
            a = nxt;
            b = &s->q90;
            ta = nextT;
            tb = &s->iFC;
        } else if (*curT < s->iFC) {
            a = cur;
            b = &s->q90;
            ta = curT;
            tb = &s->iFC;
        } else {
            a = &s->q90;
            b = cur;
            ta = &s->iFC;
            tb = curT;
        }
        s->i148 &= ~1U;
        s->i148 &= ~0x10U;
        func_L39_006202E0((f32 *)&s->q50, (f32 *)&s->q60, (f32 *)a, (f32 *)b, (f32 *)&s->q80, ta, tb, &s->iF8);
        if (s->iFC <= *curT) {
            func_0038CE20(&tmp, &s->q60, (f32)(*curT - s->iFC) / (D_L39_0024118C * 1000.0f));
            vec_sub_ab(&s->q50, &s->q50, &tmp);
        }
    }
    *cur = *pos;
    *curT = time;
    s->i28 = (s->i28 + 1) % 2;
}
/* localdecomp:end func_L39_0061F5A0 */

/* localdecomp:start func_L39_0061FBC8 */
#include "vu0.h"

extern f32 D_L39_0024118C_0061FBC8;
extern f32 func_L39_0061FDF0_0061FBC8(u128_t *, u128_t *, u128_t *);
extern void func_L39_0061FEA8_0061FBC8(u128_t *, u128_t *, u128_t *, u128_t *, u128_t *, s32 *, s32 *, s32 *);
extern void func_0038CE20(void *, void *, f32);

void func_L39_0061FBC8(S_0061ECE0 *s, u128_t *pos, s32 time) {
    vu0_v4 q;
    s32 idx, next, tmp;
    s32 *tp;
    s32 *cur_t, *next_t;
    u128_t *cur_q, *next_q;
    f32 f;

    if (time >> 9 != s->i158 >> 9 && s->i158 != -1 && (time & 0x1FF) < 0x100) {
        s->q160 = *pos;
        s->i15C = time + 0xF5;
    }
    idx = s->i28;
    tp = &time;
    next = idx + 1;
    next %= 2;
    cur_t = &s->i20 + idx;
    cur_q = &s->q00 + idx;
    next_q = &s->q00 + next;
    next_t = &s->i20 + next;
    s->i158 = time;
    if (time < *cur_t) {
        return;
    }
    if (time < *next_t) {
        tmp = *next_t;
        *next_t = time;
        time = tmp;
        q = *(vu0_v4 *)next_q;
        *next_q = *pos;
        *(vu0_v4 *)pos = q;
    }
    f = func_L39_0061FDF0_0061FBC8(cur_q, next_q, pos);
    if ((s->i148 & 4) || f < *s->pF0) {
        f = 1.0f / ((f32)(time - *next_t) / (D_L39_0024118C_0061FBC8 * 1000.0f));
        vec_sub_ab(&s->q30, pos, next_q);
        func_0038CE20(&s->q30, &s->q30, f);
        qzero(&s->q40);
    } else {
        func_L39_0061FEA8_0061FBC8(&s->q30, &s->q40, cur_q, next_q, pos, cur_t, next_t, tp);
    }
    *cur_q = *pos;
    *cur_t = time;
    s->i28 = (s->i28 + 1) % 2;
    s->q70 = s->q90 = *pos;
    s->iFC = *tp;
    s->iF4 = *tp;
}
/* localdecomp:end func_L39_0061FBC8 */
