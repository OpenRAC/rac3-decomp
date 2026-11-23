#include "common.h"
#include "structs/moby.h"
#include "vu0.h"

/* localdecomp:start func_L07_003A70B0 */
s32 func_L07_003BAC00(s32, s32);
void func_L01_004450F0(void *, s32, s32);

void func_L07_003A70B0(void *arg0) {
    u8 *p = arg0;
    u8 *s = *(u8 **)(p + 0x68);
    s32 f;

    if (p[0x20] != 0) {
        if (*(s32 *)(s + 0x74) != 0) {
            if (func_L07_003BAC00(*(s32 *)(s + 0x74), *(s32 *)(s + 0x70)) == 0) {
                return;
            }
        }
    }
    f = p[0x20];
    if (f != 1) {
        if (f >= 2) {
            return;
        }
        if (f != 0) {
            return;
        }
        p[0x30] = 0xFF;
        *(s16 *)(p + 0x32) = 0x40;
        p[0x31] = 0;
        *(s32 *)(s + 0x74) = 0;
        *(s32 *)(s + 0x70) = -1;
        func_L01_004450F0(p, 1, -1);
    } else {
        if (*(s32 *)(s + 0x70) != -1) {
            func_L01_004450F0(p, 2, -1);
        }
    }
}
/* localdecomp:end func_L07_003A70B0 */

/* localdecomp:start func_L07_003A7178 */
typedef int u128_t __attribute__((mode(TI)));

s32 func_L07_003A7178(u8 *self, u128_t *vec, s32 a2, s32 a3) {
    u8 *s = *(u8 **)(self + 0x68);

    if (*(s32 *)(s + 0x70) != -1) {
        return 0;
    }
    self[0x30] = 0x40;
    *(s16 *)(self + 0x32) = 0x40;
    self[0x31] = 1;
    *(f32 *)(self + 0x2C) = *(f32 *)(*(u8 **)(self + 0x24) + 0x24);
    *(u128_t *)(s + 0x80) = *(u128_t *)(self + 0x10);
    *(u128_t *)(self + 0x10) = *vec;
    *(s32 *)(s + 0x70) = a3;
    *(s32 *)(s + 0x74) = a2;
    *(s32 *)(s + 0x6C) |= 1;
    return 1;
}
/* localdecomp:end func_L07_003A7178 */

/* localdecomp:start func_L07_003A71E8 */
typedef int Q_003A71E8 __attribute__((mode(TI)));
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
extern void func_L01_004450F0(void *, s32, s32);
void func_L07_003A71E8(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    if (*(s32 *)(p + 0x70) != -1) {
        *(Q_003A71E8 *)(arg0 + 0x10) = *(Q_003A71E8 *)(p + 0x80);
        *(Q_003A71E8 *)(p + 0x80) = *(Q_003A71E8 *)D_L07_001D66B0;
        *(s32 *)(p + 0x70) = -1;
        func_L01_004450F0(arg0, 0, -1);
    }
}
/* localdecomp:end func_L07_003A71E8 */

/* localdecomp:start func_L07_003A7238 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A7238;
typedef int Q_003A7238 __attribute__((mode(TI)));
extern s32 func_0038CB00(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L07_003A75E0(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L07_003A7E88(void *);
extern void func_L07_003A7C10(void *);

void func_L07_003A7238(u8 *p) {
    u8 *s = *(u8 **)(p + 0x68);
    V4_003A7238 d;

    switch (p[0x20]) {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
        if (func_0038CB00(s + 0x2B8) != 0) {
            *(Q_003A7238 *)(s + 0x130) = **(Q_003A7238 **)(s + 0x2B4);
        } else {
            vec_sub_ba(&d, *(void **)(s + 0x2B4), s + 0x2A0);
            func_0038CE20(&d, &d, 1.0f / (f32)*(s16 *)(s + 0x2B8));
            vec_add_ab(s + 0x2A0, s + 0x2A0, &d);
            *(Q_003A7238 *)(s + 0x130) = *(Q_003A7238 *)(s + 0x2A0);
        }
        break;
    }
    if (*(s32 *)(s + 0x290) != *(s32 *)(s + 0x294)) {
        (*(u16 *)(p + 0x96))++;
        if (1.0f <= (f32)*(u16 *)(p + 0x96) * *(f32 *)(s + 0x29C)) {
            *(s32 *)(s + 0x290) = *(s32 *)(s + 0x294);
        }
    }
    func_L07_003A75E0(p);
    func_L01_00404808(func_L07_003A7E88, p);
    if (s[0x2BC] != 0) {
        func_L07_003A7C10(p);
        s[0x2BC] = 0;
    }
}
/* localdecomp:end func_L07_003A7238 */

/* localdecomp:start func_L07_003A7378 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Q_003A7378;
typedef struct P_003A7378 {
    u8 pad[0x280];
    Q_003A7378 vector;
    u8 pad290[8];
    f32 f298;
    u8 pad29c[0x2BA-0x29C];
    u8 f2BA, f2BB, f2BC;
} P_003A7378;
extern struct Moby *func_003C24B0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0044FD88(struct Moby *, struct Moby *, s32, s32);
extern void func_003C7C38(void *);
extern void func_L07_003A7558(struct Moby *);
struct Moby *func_L07_003A7378(struct Moby *owner, u8 kind, Q_003A7378 *vector, u8 flags, f32 scale) {
    Q_003A7378 copy = *vector;
    struct Moby *m = func_003C24B0(0x1980, 0x2C0);
    P_003A7378 *p;
    if (m) {
        struct MobyClass *cls = m->pclass;
        m->pad_30[0] = 0xFF;
        m->draw_dist = owner->draw_dist;
        m->scale = cls->scale * 0.3f;
        m->mode_flags |= 0x100;
        p = m->pvar;
        func_L01_004450F0(m, 0, 0);
        m->parent = owner;
        func_L01_0044FD88(owner, m, kind, 0);
        m->mode_flags &= ~2;
        p->f2BB = flags;
        p->f2BA = kind;
        p->f2BC = 0;
        p->vector = copy;
        p->f298 = scale;
        func_003C7C38(m);
        func_L07_003A7558(m);
    }
    return m;
}
/* localdecomp:end func_L07_003A7378 */

/* localdecomp:start func_L07_003A7488 */
typedef struct { u8 pad[0x294]; void *f294; u8 pad2[4]; f32 f29C; } S_003A7488;
extern s32 D_L07_001DE350_sda;
extern s32 D_L07_001DE370_sda;
extern s32 D_L07_001DE390_sda;
extern s32 D_L07_001DE3B0_sda;
__asm__(".extern D_L07_001DE350_sda, 4");
__asm__(".extern D_L07_001DE370_sda, 4");
__asm__(".extern D_L07_001DE390_sda, 4");
__asm__(".extern D_L07_001DE3B0_sda, 4");
extern void func_L01_004450F0(void *, s32, s32);

void func_L07_003A7488(u8 *a0, s32 a1, s32 a2) {
    S_003A7488 *s;

    if (a1 == a0[0x20]) {
        return;
    }
    s = *(S_003A7488 **)(a0 + 0x68);
    s->f29C = 1.0f / (f32)a2;
    switch (a1) {
    case 0:
        s->f294 = &D_L07_001DE350_sda;
        break;
    case 1:
        s->f294 = &D_L07_001DE370_sda;
        break;
    case 2:
        s->f294 = &D_L07_001DE390_sda;
        break;
    case 4:
        s->f294 = &D_L07_001DE3B0_sda;
        break;
    }
    func_L01_004450F0(a0, a1, -1);
}
/* localdecomp:end func_L07_003A7488 */

/* localdecomp:start func_L07_003A7540 */
void func_L07_003A7540(void *arg0) {
    if (arg0 != 0) {
        *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x2BC) = 1;
    }
}
/* localdecomp:end func_L07_003A7540 */

/* localdecomp:start func_L07_003A7558 */
typedef int Q_003A7558 __attribute__((mode(TI)));
typedef struct {
    Q_003A7558 points[20];
    Q_003A7558 previous[20];
    u8 pad280[0x10];
    f32 *current;
    f32 *target;
    u8 pad298[0x22];
    u8 joint;
} State_003A7558;
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
__asm__(".extern D_L07_001DE350_sda, 4");
void func_L07_003A7558(struct Moby *self) {
    Q_003A7558 matrix[4];
    Q_003A7558 step;
    Q_003A7558 translation;
    State_003A7558 *s = self->pvar;
    Q_003A7558 *point;
    s32 count;
    func_003C2EC0(self->parent, s->joint, matrix);
    translation = matrix[3];
    s->points[0] = translation;
    s->previous[0] = translation;
    func_0038CF68(&step, matrix, *(f32 *)&D_L07_001DE350_sda);
    point = &s->points[1];
    count = 18;
    do {
        vec_add_ab(point, point - 1, &step);
        count--;
        point[20] = *point;
        point++;
    } while (count >= 0);
    s->target = (f32 *)&D_L07_001DE350_sda;
    s->current = (f32 *)&D_L07_001DE350_sda;
}
/* localdecomp:end func_L07_003A7558 */

/* localdecomp:start func_L07_003A75E0 */
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    u8 b14;
    u8 b15;
    u8 b16;
    u8 b17;
} R_003A75E0;
extern s32 D_L07_001DE3D0_sda;
__asm__(".extern D_L07_001DE3D0_sda, 4");
extern f32 D_L07_001DE3D8_sda;
__asm__(".extern D_L07_001DE3D8_sda, 4");
extern void func_L07_003A7AC0(R_003A75E0 *, f32, void *, void *);
extern void func_L07_003A79F0_003A75E0(void *, void *, s32, s32, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_L01_0040E4C0(void *);

void func_L07_003A75E0(void *object) {
    u8 *o = object;
    u8 *s = *(u8 **)(o + 0x68);
    R_003A75E0 r;
    vu0_v4 g;
    vu0_v4 t;
    vu0_v4 p;
    vu0_v4 d;
    vu0_v4 e;
    u8 *pp;
    u8 *w;
    s32 a;
    s32 i;
    s32 j;
    s32 jj;
    s32 k;
    s32 m;
    f32 len;
    f32 f20;
    f32 x;
    vu0_v4 *q;
    vu0_v4 *q2;
    vu0_v4 *p3;

    func_L07_003A7AC0(&r, (f32)*(u16 *)(o + 0x96) * *(f32 *)(s + 0x29C), *(void **)(s + 0x290), *(void **)(s + 0x294));
    if (*(u16 *)(o + 0x96) < (D_L07_001DE3D0_sda * 5 + 2) / 6) {
        r.f8 = D_L07_001DE3D8_sda;
    }
    *(vu0_q *)&t = 0;
    t.z = r.f4;
    w = s + 0x280;
    g = t;
    func_L01_0044FD88(*(struct Moby **)(o + 0xB8), object, s[0x2BA], 0);
    *(u16 *)(o + 0x34) = *(u16 *)(o + 0x34) & 0xFFFD;
    *(vu0_q *)s = *(vu0_q *)(o + 0x10);
    *(vu0_q *)(s + 0x140) = *(vu0_q *)(o + 0x10);
    func_0038CF68(&t, o + 0xC0, r.f0);
    pp = (u8 *)&p;
    for (a = 1; a < r.b15; a++) {
        vec_add_ab(s + a * 16, s + a * 16 - 16, &t);
        *(vu0_q *)(s + a * 16 + 0x140) = *(vu0_q *)(s + a * 16);
    }
    q = (vu0_v4 *)s + r.b15;
    q2 = (vu0_v4 *)s + (r.b15 + 20);
    for (j = r.b15; j < 20; j++, q++, q2++) {
        p = *q;
        vec_sub_ba(&d, q, q2);
        func_0038CE20(&d, &d, r.f8);
        vec_add_ab(q, q, &d);
        vec_add_ab(q, q, &g);
        *(vu0_q *)q2 = *(vu0_q *)&p;
    }
    for (k = 0; k < r.b14; k++) {
        for (p3 = (vu0_v4 *)s, jj = 0; jj < 19; p3++, jj++) {
            m = 1;
            if (r.b17 != 0 && jj + 1 < 20) {
                for (;;) {
                    s32 ok;
                    f32 dist = (f32)m * r.f0;
                    func_L07_003A79F0_003A75E0(p3, p3 + m, jj >= r.b15, jj + m >= r.b15, dist * dist);
                    m++;
                    ok = (jj + m < 20);
                    if (m > r.b17 || !ok) {
                        break;
                    }
                }
            }
        }
    }
    func_0038D000(pp, w, *(u8 **)(o + 0xB8) + 0xC0);
    vec_add_ab(&p, &p, *(u8 **)(o + 0xB8) + 0x10);
    for (q = (vu0_v4 *)s, i = 0; i < 20; i++, q++) {
        f32 minz = r.fC + *(f32 *)(s + 0x298);
        if (q->z < minz) {
            q->z = minz;
        }
        if (i < r.b16) {
            continue;
        }
        vec_sub_ab(&d, &p, q);
        f20 = r.f10 * r.f10;
        len = func_L01_0040E4C0(&d);
        x = f20 / (len + f20) - 0.5f;
        if (0.0f < x) {
            func_0038CE20(&e, &d, x + x);
            vec_sub_ab(q, q, &e);
        }
        if (!(q->z < p.z)) {
            continue;
        }
        d.z = 0.0f;
        len = func_L01_0040E4C0(&d);
        x = f20 / (len + f20) - 0.5f;
        if (0.0f < x) {
            func_0038CE20(&e, &d, x + x);
            vec_sub_ab(q, q, &e);
        }
    }
}
/* localdecomp:end func_L07_003A75E0 */

/* localdecomp:start func_L07_003A79F0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A79F0;
extern f32 func_L01_0040E4C0(void *);
extern void func_0038CE20(void *, void *, f32);

void func_L07_003A79F0(V4_003A79F0 *a, V4_003A79F0 *b, s32 movea, s32 moveb, f32 r) {
    V4_003A79F0 d;

    vec_sub_ab(&d, b, a);
    r = r / (func_L01_0040E4C0(&d) + r);
    func_0038CE20(&d, &d, r - 0.5f);
    if (movea != 0) {
        vec_sub_ab(a, a, &d);
    }
    if (moveb != 0) {
        vec_add_ab(b, b, &d);
    }
}
/* localdecomp:end func_L07_003A79F0 */
