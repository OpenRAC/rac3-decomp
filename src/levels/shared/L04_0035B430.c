#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_0035B430 */
extern s32 func_L01_00367080(void *, void *, void *, void *);
extern void func_L01_00367260(void *, s32, s32, void *, void *, s32);
extern void func_L04_00379CC0(u8 *a0, void *out);
extern void func_0038CF68(void *, void *, f32);
__asm__(".extern D_L04_001DD518, 8");
extern s32 D_L04_001DD518[2];
extern s32 D_L04_001DD538[2];

void func_L04_0035B430(void *a0, u8 *s) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    s32 r;

    *(vu0_q *)&a = *(vu0_q *)(s + 0x50);
    if (*(s32 *)(s + 0xA0) == 1) {
        *(vu0_q *)&b = *(vu0_q *)(s + 0x90);
    } else {
        *(vu0_q *)&b = *(vu0_q *)(s + 0x60);
    }
    r = func_L01_00367080(&a, &b, &c, &d);
    if (r == 0 && *(s32 *)(s + 0x110) == 5) {
        *(vu0_q *)&c = *(vu0_q *)(s + 0x60);
        r = 1;
    }
    if (r != 0 && r != 2) {
        func_L01_00367260(a0, 0, D_L04_001DD518[r], &a, &c, -1);
        *(s32 *)s = 1;
    }
    if (*(s32 *)(s + 4) != 0) {
        *(vu0_q *)&a = *(vu0_q *)(s + 0xB0);
        if (*(s32 *)(s + 0x100) == 1) {
            *(vu0_q *)&b = *(vu0_q *)(s + 0xF0);
        } else {
            *(vu0_q *)&b = *(vu0_q *)(s + 0xC0);
        }
        r = func_L01_00367080(&a, &b, &c, &d);
        if (r != 0 && r != 2) {
            func_L01_00367260(a0, 2, D_L04_001DD538[r], &a, &c, -1);
            *(s32 *)s = 1;
        }
        if (*(s32 *)(s + 8) != 0) {
            func_L04_00379CC0(*(u8 **)(s + 8), &b);
            vec_sub_ab(s + 0x150, &b, &a);
            func_0038CF68(s + 0x150, s + 0x150, 1.0f);
        }
    }
}
/* localdecomp:end func_L04_0035B430 */

/* localdecomp:start func_L04_0035B5D8 */
extern s32 func_L04_00377118(void *, void *);
extern s32 func_L04_00377760(void *);
extern void func_L01_0040EE50(void *, void *);
extern s32 func_L01_00367080(void *, void *, void *, void *);
extern f32 func_L01_00446630(void *, void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L04_00455C40(void *, void *, void *, void *, f32 *);
typedef union { u8 b[0x2600]; void *ptr[0x980]; } Hero_35B5D8;
extern u8 D_001A4BE0[];
extern s32 D_001D545C;

void func_L04_0035B5D8(void *a0, u8 *s, vu0_v4 *out) {
    vu0_v4 p0;
    vu0_v4 p1;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 i0;
    vu0_v4 i1;
    vu0_v4 dir;
    vu0_v4 e0;
    vu0_v4 e1;
    vu0_v4 m[3];
    vu0_v4 save;
    f32 t;
    s32 r;

    *(vu0_q *)&p0 = *(vu0_q *)(s + 0x50);
    if (*(s32 *)(s + 0xA0) == 1) {
        *(vu0_q *)&p1 = *(vu0_q *)(s + 0x90);
    } else {
        *(vu0_q *)&p1 = *(vu0_q *)(s + 0x60);
    }
    func_L04_00377118(&c, &d);
    func_L04_00377760(&d);
    func_L01_0040EE50(m, (u8 *)((Hero_35B5D8 *)D_001A4BE0)->ptr[0x25C0 / 4] + 0xC0);
    r = func_L01_00367080(&p0, &p1, &i0, &i1);
    *(vu0_q *)&save = *(vu0_q *)&i0;
    if (r == 0) {
        func_L01_00446630(out, &p0, &p1, &c);
        return;
    }
    if ((r ^ 1) & 1) {
        *(vu0_q *)&i0 = *(vu0_q *)&p0;
    }
    if (!(r & 2)) {
        *(vu0_q *)&i1 = *(vu0_q *)&p1;
    }
    func_0038D000(&i0, &i0, m);
    func_0038D000(&i1, &i1, m);
    func_0038D000(&c, &c, m);
    func_0038D000(&d, &d, m);
    func_0038CE20(&e0, &d, -5.0f);
    vec_add_ab(&e0, &e0, &c);
    func_0038CE20(&e1, &d, 5.0f);
    vec_add_ab(&e1, &e1, &c);
    if (func_L04_00455C40(&i0, &i1, &e0, &e1, &t) != 0) {
        vec_sub_ab(&dir, &i1, &i0);
        func_0038CE20(out, &dir, t);
        vec_add_ab(out, out, &i0);
    } else if (t <= 0.0f) {
        *(vu0_q *)out = *(vu0_q *)&i0;
    } else {
        *(vu0_q *)out = *(vu0_q *)&i1;
    }
    func_0038D000(out, out, (u8 *)((Hero_35B5D8 *)D_001A4BE0)->ptr[0x25C0 / 4] + 0xC0);
    if (D_001D545C == 0xB) {
        *(vu0_q *)out = *(vu0_q *)&save;
    }
}
/* localdecomp:end func_L04_0035B5D8 */

/* localdecomp:start func_L04_0035B838 */
extern s32 func_L04_00377698(void *);
extern f32 func_0038CF00(void *, void *);
extern u8 D_001425C0[];

s32 func_L04_0035B838(void *a0, u8 *s, s32 a2) {
    vu0_v4 buf;
    f32 lim;

    if (!((*(s32 *)(D_001A4BE0 + 0x25C4) == 1 || D_001425C0[0x1434] != 0) && func_L04_00377698(a0) != 0)) {
        if (a2 == 0) {
            return 0;
        }
    }
    if (*(u8 **)(s + 4) != 0) {
        func_L04_0035B5D8(a0, s, &buf);
        lim = func_0038CF00(*(u8 **)(s + 4) + 0x10, &buf);
    } else {
        lim = 2.4f;
    }
    return 1.2f < lim;
}
/* localdecomp:end func_L04_0035B838 */

/* localdecomp:start func_L04_0035B908 */
typedef int u128_35A960 __attribute__((mode(TI)));

typedef struct {
    u128_35A960 a;
    u128_35A960 b;
    s32 active;
} S_35A960;

extern s32 func_L04_004BB4F8(u128_35A960 *, u128_35A960 *, f32);
extern u32 func_L04_004BB268(void);
extern s32 func_L04_004BB348(u32, s32, s32, s32);
extern void func_L04_004BB288(u32, f32);
extern void func_L04_004BB2E0(u32, u128_35A960 *, u128_35A960 *);
extern void func_L04_004BB3A8(u32);

void func_L04_0035B908(s32 arg0, S_35A960 *p, S_35A960 *q, u32 *h) {
    u128_35A960 v[2];
    u32 n;

    if (p->active == 1 || q->active == 1) {
        if (p->active == 1) {
            v[0] = p->a;
            if (q->active == 1) {
                v[1] = q->b;
            } else {
                v[1] = p->b;
            }
        } else {
            v[0] = q->a;
            v[1] = q->b;
        }
        if (*h == 0xFFFFFFFF) {
            if (func_L04_004BB4F8(&v[0], &v[1], 24.0f) == 0) {
                n = func_L04_004BB268();
                *h = n;
                func_L04_004BB348(n, 0, arg0, 6455);
                func_L04_004BB288(*h, 24.0f);
                func_L04_004BB2E0(*h, &v[0], &v[1]);
            }
        } else if (func_L04_004BB4F8(&v[0], &v[1], 24.0f) == 0) {
            func_L04_004BB2E0(*h, &v[0], &v[1]);
        } else {
            func_L04_004BB3A8(*h);
            *h = 0xFFFFFFFF;
        }
    } else if (*h != 0xFFFFFFFF) {
        func_L04_004BB3A8(*h);
        *h = 0xFFFFFFFF;
    }
}
/* localdecomp:end func_L04_0035B908 */

/* localdecomp:start func_L04_0035BA58 */
extern s32 func_L01_00456250(void *);
extern s32 func_0038CAD0(void *);
extern s32 func_L04_003796E0(u8 *);
extern void func_L01_0038B988_0035BA58(void *);
extern void func_L04_003796C8(u8 *);
extern void func_L04_0035A4F8(void *, void *);
extern u8 *D_L04_001DFD9C;
extern s32 D_L04_001DF940;

typedef struct { s32 w0; s32 w4; s32 w8; s32 wC; } P_35BA58;
typedef struct { u8 b[0x30]; } Q_35BA58;
typedef struct {
    s32 w0;
    u8 *w4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
    s32 w1C;
    s32 pad20[3];
    s32 w2C;
    u8 pad30[0x20];
    Q_35BA58 q[4];
    P_35BA58 p[4];
} S_35BA58;

s32 func_L04_0035BA58(void *a0, S_35BA58 *s) {
    s32 ok;
    s32 i;
    s32 c;
    s32 none;
    P_35BA58 *p;
    Q_35BA58 *q;
    none = -1;
    c = s->wC;
    if (c == none && s->w10 == none) {
        return s->w18;
    }
    ok = 1;
    if (c != none && func_L01_00456250(D_L04_001DFD9C + (c << 8)) == 0) {
        ok = 0;
    }
    if (s->w10 != none && func_L01_00456250(D_L04_001DFD9C + (s->w10 << 8)) == 0) {
        ok = 0;
    }
    if (ok == s->w14) {
        if (s->w18 != 0) {
            if (s->w2C == 0) {
                s->w2C = 30;
            }
            if (func_0038CAD0(&s->w2C) != 0) {
                if (s->w4 != 0) {
                    if (func_L04_003796E0(s->w4) != 0) {
                        func_L01_0038B988_0035BA58(s->w4);
                        s->w4 = 0;
                    } else {
                        func_L04_003796C8(s->w4);
                    }
                }
                q = s->q;
                p = s->p;
                for (i = 0; i < 4; i++, q++, p++) {
                    if (p->w4 < D_L04_001DF940) {
                        func_L04_0035A4F8(q, p);
                    }
                }
                s->w18 = 0;
            }
        } else {
            s->w2C = 0;
            if (s->w4 != 0 && func_L04_003796E0(s->w4) != 0) {
                func_L01_0038B988_0035BA58(s->w4);
                s->w4 = 0;
            }
        }
    } else if (s->w18 == 0) {
        if (s->w2C == 0) {
            s->w2C = 30;
        }
        if (func_0038CAD0(&s->w2C) != 0) {
            s->w18 = 1;
        }
    } else {
        s->w2C = 0;
    }
    if (s->w1C != 0 && s->w18 != s->w14) {
        s->wC = -1;
        s->w10 = -1;
    }
    return s->w18;
}
/* localdecomp:end func_L04_0035BA58 */

/* localdecomp:start func_L04_0035BC10 */
extern void func_L01_00367260(void *, s32, s32, void *, void *, s32);
extern void func_L01_00367430(void *, f32);
extern void func_L04_0037A5B8(void *, void *, s32);
extern s32 func_L04_003796E0(u8 *);
extern void func_L01_0038B988_0035BC10(void *);
extern void func_0038D308(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0040BE10(void *, void *);
extern void func_L04_0035A6E0(void *, void *, s32, s32);
extern u8 *func_L04_003776D8(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L04_00377720(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L04_00379CC0(u8 *a0, void *out);
extern s32 func_L04_0035A5B8(void *, void *, void *);
extern void func_L04_003796C8(u8 *);
extern u8 *func_L04_00379410(void *);
extern void func_L04_003776F8(void *, void *);
extern void func_L04_0035A4F8(void *, void *);
extern void func_L04_0035B430(void *, u8 *);
extern void func_L04_0035C1B8(u8 *, u8 *);
extern s32 D_001D545C;
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern u8 D_001BBC40[];
extern u8 D_001BBB18[];
extern u8 *D_L04_001DFE80;
extern s32 D_L04_001DF940;
extern f32 D_L04_001DD50C;

void func_L04_0035BC10(u8 *m, u8 *s) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    u8 *p;
    u8 *t;
    u8 *r;
    u8 *r0;
    u8 *o;
    s32 hit;
    s32 chk;
    s32 i;
    f32 f;
    u8 *p2;

    if (*(s32 *)s != 0) {
        func_L01_00367260(m, -1, 0, m + 0x10, m + 0x10, -1);
        func_L01_00367430(m, 0.0f);
        *(s32 *)s = 0;
    }
    if (*(u8 **)(s + 8) != 0) {
        func_L04_0037A5B8(*(u8 **)(s + 8), m, 0);
        *(s32 *)(s + 8) = 0;
    }
    if (func_L04_0035BA58(m, (S_35BA58 *)s) == 0) {
        func_L04_0035B908((s32)m, (S_35A960 *)(s + 0x50), (S_35A960 *)(s + 0x80), (u32 *)(s + 0x40));
        func_L04_0035B908((s32)m, (S_35A960 *)(s + 0xB0), (S_35A960 *)(s + 0xE0), (u32 *)(s + 0x44));
        return;
    }
    if (*(u8 **)(s + 4) != 0 && func_L04_003796E0(*(u8 **)(s + 4)) != 0) {
        func_L01_0038B988_0035BC10(*(u8 **)(s + 4));
        *(s32 *)(s + 4) = 0;
    }
    i = -1;
    if (*(s32 *)(s + 0x4C) == i) {
        func_0038D308(m + 0xC0, m + 0xF0);
    }
    p = s + 0x50;
    r0 = s + 0x110;
    if (*(s32 *)(s + 0x20) == i) {
        func_0038CE20(p, m + 0xC0, 0.33f);
    } else if (*(s32 *)(s + 0x20) != 0) {
        func_0038CE20(p, m + 0xC0, 0.23f);
    } else {
        func_0038CE20(p, m + 0xC0, 0.33f);
    }
    vec_add_ab(p, p, m + 0x10);
    p2 = p + 0x10;
    f = D_001D545C == 0xB ? 80.0f : 40.0f;
    func_0038CE20(p2, m + 0xC0, f);
    vec_add_ba(p2, p2, m + 0x10);
    func_L01_0040BE10(m + 0x10, p2);
    func_L04_0035A6E0(m, s, 0, 0);
    if (func_L04_0035B838(m, s, 0) != 0) {
        hit = 0;
        t = func_L04_003776D8(m);
        if (t != 0 && *(s16 *)(t + 0xAA) == 0x1860 && t != *(u8 **)(s + 8)) {
            if (*(s32 *)(*(u8 **)(t + 0x68) + 4) != -1) {
                hit = 1;
            } else {
                o = *(u8 **)(*(u8 **)(t + 0xB8) + 0x68);
                if (func_L01_0040E548(o + 0x2C0, D_L04_001DFE80 + (*(s32 *)(o + 0x13C) << 7) + 0x30) < 0.25f) {
                    hit = 1;
                }
            }
        }
        chk = hit != 0;
        if (hit != 0) {
            func_L04_0035B5D8(m, s, &a);
            func_L04_00377720(&b);
            vec_sub_ab(&c, &b, &a);
            func_0038CF68(&c, &c, 1.0f);
            if (t != 0) {
                func_L04_00379CC0(t, &b);
                vec_sub_ab(&c, &b, &a);
                func_0038CF68(&c, &c, 1.0f);
            }
            if (chk) {
                if (func_L04_0035A5B8(&a, &b, &b) == 0) {
                    hit = 0;
                }
            }
            if (hit != 0) {
                if (*(u8 **)(s + 4) != 0) {
                    func_L04_003796C8(*(u8 **)(s + 4));
                }
                *(u8 **)(s + 4) = func_L04_00379410(&a);
                *(vu0_q *)(s + 0x150) = *(vu0_q *)&c;
                if (t != 0 && *(s32 *)(*(u8 **)(t + 0x68) + 4) == -1) {
                    *(u8 **)(s + 0x30) = t;
                }
                *(s32 *)(s + 0x110) = 4;
                func_L04_003776F8(m, &a);
                if (*(u8 **)(s + 8) != 0) {
                    func_L04_0037A5B8(*(u8 **)(s + 8), m, 0);
                    *(s32 *)(s + 8) = 0;
                }
            }
        }
    }
    if (*(u8 **)(s + 4) != 0) {
        p = s + 0xB0;
        if (*(s32 *)(s + 0x110) != 4 && *(s32 *)(s + 0x120) != 4) {
            if (*(s32 *)(s + 0x1C) == 0
               || ((m[0xB0] == 0xFF || (D_001BBC40[m[0xB0] + (D_001D545C_sda << 4)] & 0x80) == 0)
                   && (*(s32 *)(s + 0x34) == -1 || D_001BBB18[*(s32 *)(s + 0x34) + (D_001D545C_sda << 3)] == 0))) {
                func_L04_003796C8(*(u8 **)(s + 4));
            }
        } else {
            *(vu0_q *)p = *(vu0_q *)(*(u8 **)(s + 4) + 0x10);
            func_0038CE20(p + 0x10, s + 0x150, D_001D545C == 0xB ? 80.0f : 40.0f);
            vec_add_ab(p + 0x10, p + 0x10, p);
            func_L01_0040BE10(p, p + 0x10);
            func_L04_0035A6E0(m, s, 2, 0);
        }
    }
    p = s + 0x50;
    r = r0;
    for (i = 0; i < 4; i++, p += 0x30, r += 0x10) {
        if (*(s32 *)(r + 4) < D_L04_001DF940) {
            func_L04_0035A4F8(p, r);
        }
    }
    func_L04_0035B908((s32)m, (S_35A960 *)(s + 0x50), (S_35A960 *)(s + 0x80), (u32 *)(s + 0x40));
    func_L04_0035B908((s32)m, (S_35A960 *)(s + 0xB0), (S_35A960 *)(s + 0xE0), (u32 *)(s + 0x44));
    if (*(u8 **)(s + 4) != 0) {
        o = *(u8 **)(s + 4);
        if (*(s32 *)(s + 0xA0) == 1) {
            *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * 1.5f * D_L04_001DD50C;
        } else {
            *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * 1.5f;
        }
    }
    func_L04_0035B430(m, s);
    func_L04_0035C1B8(m, s);
}
/* localdecomp:end func_L04_0035BC10 */

/* localdecomp:start func_L04_0035C1B8 */
#include "vu0.h"
extern f32 func_L01_0040E548(void *, void *);
__asm__(".extern D_L04_001DD4E8, 4");
__asm__(".extern D_L04_001DD4EC, 4");
__asm__(".extern D_L04_001DD4F0, 4");
__asm__(".extern D_L04_001DD4F4, 4");
extern f32 D_L04_001DD4E8;
extern s32 D_L04_001DD4EC;
extern f32 D_L04_001DD4F0;
extern s32 D_L04_001DD4F4;

void func_L04_0035C1B8(u8 *a0, u8 *a1) {
    f32 max;
    f32 d;
    s32 i;
    u8 *p;

    max = 0.0f;
    p = a1 + 0x50;
    for (i = 3; i >= 0; i--) {
        if (*(s32 *)(p + 0x20) != 0) {
            d = func_L01_0040E548(a0 + 0x10, p + 0x10);
            if (max < d) {
                max = d;
            }
        }
        p += 0x30;
    }
    if (max > 0.0f) {
        s32 v1;
        s32 v2;

        max = sqrt_asm(max) + 0.99f;
        v1 = (s32)(max + D_L04_001DD4E8);
        if (v1 > D_L04_001DD4EC) {
            v1 = D_L04_001DD4EC;
        }
        a0[0x30] = v1;
        v2 = (s32)(max + D_L04_001DD4F0);
        if (v2 > D_L04_001DD4F4) {
            v2 = D_L04_001DD4F4;
        }
        *(s16 *)(a0 + 0x32) = v2;
    } else {
        a0[0x30] = D_L04_001DD4EC;
        *(s16 *)(a0 + 0x32) = 0;
    }
}
/* localdecomp:end func_L04_0035C1B8 */

/* localdecomp:start func_L04_0035C2B0 */
#include "vu0.h"
extern s32 func_0038DC20(void *, f32);
extern f32 func_L01_0040E548_0035C2B0(void *, void *);
extern u8 D_L04_001E2840_0035C2B0[];
__asm__(".extern D_L04_001DD4F0_0035C2B0, 4");
extern f32 D_L04_001DD4F0_0035C2B0;

void func_L04_0035C2B0(void *a0, void *a1, void *a2, f32 w) {
    vu0_v4 q;
    f32 d;
    f32 t;

    q = *(vu0_v4 *)a0;
    q.w = w;
    if (func_0038DC20(&q, D_L04_001DD4F0_0035C2B0) == -1) {
        *(s32 *)a1 = 0;
        *(f32 *)a2 = 1.0f;
        return;
    }
    d = func_L01_0040E548_0035C2B0(D_L04_001E2840_0035C2B0, a0);
    if (D_L04_001DD4F0_0035C2B0 * D_L04_001DD4F0_0035C2B0 < d) {
        *(s32 *)a1 = 0;
        *(f32 *)a2 = 1.0f;
        return;
    }
    *(s32 *)a1 = 1;
    t = D_L04_001DD4F0_0035C2B0 - 4.0f;
    if (t * t < d) {
        d = sqrt_asm(d) - t;
        *(f32 *)a2 = d * 0.25f;
    } else {
        *(f32 *)a2 = 0.0f;
    }
}
/* localdecomp:end func_L04_0035C2B0 */

/* localdecomp:start func_L04_0035C398 */
typedef struct { s32 a; f32 b; s32 c; f32 d; } R_35C398;
typedef struct { u8 pad0[4]; s32 f4; u8 pad8[0x98]; s32 fA0; } O_35C398;
__asm__(".extern D_L04_001DD508, 8");
extern f32 D_L04_001DD508[2];
extern void func_L04_0035C2B0(void *, void *, void *, f32);
extern void func_003A9440(s32, unsigned long);
extern s32 func_0038DBD8(f32, s32, s32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L04_0035C398(O_35C398 *obj, s32 n) {
    R_35C398 r;
    u8 *p = (u8 *)obj + (n * 0x30 + 0x50);
    f32 k = D_L04_001DD508[n] * 0.225f;
    s32 c;

    func_L04_0035C2B0(p, &r.a, &r.b, k);
    func_L04_0035C2B0(p + 0x10, &r.c, &r.d, k);
    func_003A9440(0x47, 0x53001);
    if (n == 0) {
        if (obj->fA0 == 1 || obj->f4 == 0) {
            if (r.c != 0) {
                c = func_0038DBD8(r.d, 0xFF3020FF, 0xFF000000);
                func_003D9508(p + 0x10, 0x39, c, 1, k + k, k, func_00382538());
                c = func_0038DBD8(r.d, 0x4F3020FF, 0xFF000000);
                func_003D9508(p + 0x10, 0x39, c, 1, k * 2.5f, k, func_00382538());
                c = func_0038DBD8(r.d, 0x606040FF, 0xFF000000);
                func_003D9508(p + 0x10, 0x31, c, 1, k * 3.0f, k, func_00382538());
            }
        }
    }
    if (n == 1) {
        if (r.a != 0) {
            c = func_0038DBD8(r.b, 0xFF3020FF, 0xFF000000);
            func_003D9508(p, 0x39, c, 1, k + k, k, func_00382538());
            c = func_0038DBD8(r.b, 0x4F3020FF, 0xFF000000);
            func_003D9508(p, 0x39, c, 1, k * 2.5f, k, func_00382538());
            c = func_0038DBD8(r.b, 0x606040FF, 0xFF000000);
            func_003D9508(p, 0x31, c, 1, k * 3.0f, k, func_00382538());
        }
        if (obj->f4 == 0) {
            if (r.c != 0) {
                c = func_0038DBD8(r.d, 0xFF3020FF, 0xFF000000);
                func_003D9508(p + 0x10, 0x39, c, 1, k + k, k, func_00382538());
                c = func_0038DBD8(r.d, 0x4F3020FF, 0xFF000000);
                func_003D9508(p + 0x10, 0x39, c, 1, k * 2.5f, k, func_00382538());
                c = func_0038DBD8(r.d, 0x606040FF, 0xFF000000);
                func_003D9508(p + 0x10, 0x31, c, 1, k * 3.0f, k, func_00382538());
            }
        }
    }
    if (n == 2) {
        if (r.c != 0) {
            c = func_0038DBD8(r.d, 0xFFFF2040, 0xFF000000);
            func_003D9508(p + 0x10, 0x39, c, 1, k + k, k, func_00382538());
            c = func_0038DBD8(r.d, 0x4FFF2040, 0xFF000000);
            func_003D9508(p + 0x10, 0x39, c, 1, k * 2.5f, k, func_00382538());
            c = func_0038DBD8(r.d, 0x60FF4060, 0xFF000000);
            func_003D9508(p + 0x10, 0x31, c, 1, k * 3.0f, k, func_00382538());
        }
    }
    if (n == 3) {
        if (r.a != 0) {
            c = func_0038DBD8(r.b, 0xFFFF2040, 0xFF000000);
            func_003D9508(p, 0x39, c, 1, k + k, k, func_00382538());
            c = func_0038DBD8(r.b, 0x4FFF2040, 0xFF000000);
            func_003D9508(p, 0x39, c, 1, k * 2.5f, k, func_00382538());
            c = func_0038DBD8(r.b, 0x60FF4060, 0xFF000000);
            func_003D9508(p, 0x31, c, 1, k * 3.0f, k, func_00382538());
        }
        if (r.c != 0) {
            c = func_0038DBD8(r.d, 0xFFFF2040, 0xFF000000);
            func_003D9508(p + 0x10, 0x39, c, 1, k + k, k, func_00382538());
            c = func_0038DBD8(r.d, 0x4FFF2040, 0xFF000000);
            func_003D9508(p + 0x10, 0x39, c, 1, k * 2.5f, k, func_00382538());
            c = func_0038DBD8(r.d, 0x60FF4060, 0xFF000000);
            func_003D9508(p + 0x10, 0x31, c, 1, k * 3.0f, k, func_00382538());
        }
    }
}
/* localdecomp:end func_L04_0035C398 */

/* localdecomp:start func_L04_0035C9C8 */
#include "vu0.h"
typedef struct {
    vu0_v4 a;
    vu0_v4 b;
    s32 state;
    s32 time;
    u8 pad28[8];
} I_0035C9C8;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
    u8 pad1C[4];
    s32 f20;
    u8 pad24[0x2C];
    I_0035C9C8 items[4];
} O_0035C9C8;
typedef struct {
    s32 f30;
    s32 f34;
    f32 f38;
    s32 col0;
    s32 col1;
    f32 size;
    f32 f48;
    f32 f4C;
    f32 f50;
    f32 f54;
    f32 f58;
    f32 f5C;
    f32 f60;
    s32 f64;
    f32 f68;
    f32 f6C;
    s32 f70;
    s32 f74;
    s32 f78;
    s32 f7C;
} P_0035C9C8;
extern f32 func_0038CF00(void *, void *);
extern f32 func_L01_00446630(void *, void *, void *, void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern s32 func_0038DC20(void *, f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern s32 func_0038DBD8_0035C9C8(s32, s32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0040B858(void *, void *);
extern void func_003A9440(s32, unsigned long);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern u8 D_L04_001E2840[];
extern s32 D_L04_001DF940;
__asm__(".extern D_L04_001DD4F0, 4");
extern f32 D_L04_001DD4F0;
__asm__(".extern D_L04_001DD4F8, 8");
extern s32 D_L04_001DD4F8[2];
__asm__(".extern D_L04_001DD508, 8");
extern f32 D_L04_001DD508[2];

void func_L04_0035C9C8(u8 *a0) {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    P_0035C9C8 st;
    vu0_v4 v80;
    O_0035C9C8 *s;
    I_0035C9C8 *it;
    f32 dist;
    f32 d;
    f32 t;
    f32 f1;
    f32 f2;
    s32 i;
    s32 r;

    s = *(O_0035C9C8 **)(a0 + 0x68);
    if (s->f18 == 0) {
        it = s->items;
        if (it->state != 1) {
            if (it->state != 2) {
                return;
            }
            if (D_L04_001DF940 - it->time >= 8) {
                return;
            }
        }
    }
    dist = func_0038CF00(D_L04_001E2840, a0 + 0x10);
    if ((f32)*(s16 *)(a0 + 0x32) < dist) {
        return;
    }
    st.f30 = 10;
    st.f34 = 8;
    st.f38 = 1.25f;
    st.f50 = 0.06f;
    st.f54 = 0.05f;
    st.f58 = 0.2f;
    st.f5C = 0.6f;
    st.f60 = 1.2f;
    st.f64 = 15;
    st.f68 = 15.0f;
    st.f6C = 20.0f;
    st.f70 = 0;
    st.f74 = 0;
    st.f78 = 0;
    st.f7C = 0x45;
    it = s->items;
    for (i = 0; i < 4; i++, it++) {
        func_L01_00446630(&v0, &it->a, &it->b, D_L04_001E2840);
        d = func_L01_0040E548(&v0, D_L04_001E2840);
        if (D_L04_001DD4F0 * D_L04_001DD4F0 < d) {
            continue;
        }
        func_0038CDF8(&v20, &it->a, &it->b, 0.5f);
        v20.w = func_0038CF00(&it->a, &it->b) * 0.5f;
        if (func_0038DC20(&v20, D_L04_001DD4F0) == -1) {
            continue;
        }
        st.col0 = D_L04_001DD4F8[i];
        st.col1 = func_0038DBD8_0035C9C8(0xFF000000, st.col0, 0.5f);
        t = D_L04_001DD4F0 - 4.0f;
        if (t * t < d) {
            f32 k;

            d = sqrt_asm(d) - t;
            k = d * 0.25f;
            st.col0 = func_0038DBD8_0035C9C8(st.col0, 0xFF000000, k);
            st.col1 = func_0038DBD8_0035C9C8(st.col1, 0xFF000000, k);
        }
        st.size = D_L04_001DD508[i] * 0.225f * func_003824E0(1.0f, 1.0375f);
        if (s->items[1].state == 1) {
            if (i == 2) {
                st.size *= 0.6f;
            } else if (i == 3) {
                st.size *= 0.6f;
            }
        }
        if (i == 0) {
            st.f48 = 0.5f;
            st.f4C = 0.55f;
        } else {
            st.f48 = 1.0f;
            st.f4C = 0.0f;
        }
        func_L01_0040B858((u8 *)s + (i * 0x30 + 0x50), &st);
    }
    func_003A9440(0x47, 0x513F1);
    it = s->items;
    for (i = 0; i < 4; i++, it++) {
        if (it->state == 1) {
            func_L04_0035C398((O_35C398 *)s, i);
        }
    }
    if (dist < D_L04_001DD4F0) {
        *(vu0_q *)&v20 = *(vu0_q *)(a0 + 0x10);
        v20.w = 2.0f;
        if (func_0038DC20(&v20, D_L04_001DD4F0) == -1) {
            return;
        }
        r = s->f20;
        if (r == -1) {
            func_0038CE20(&v10, a0 + 0xC0, 0.25f);
        } else if (r != 0) {
            func_0038CE20(&v10, a0 + 0xC0, 0.35f);
        } else {
            func_0038CE20(&v10, a0 + 0xC0, 0.45f);
        }
        vec_add_ba(&v10, &v10, a0 + 0x10);
        f1 = func_003824E0(1.0f, 1.0375f) * 0.45f;
        func_003D9508(&v10, 0x39, 0x302020FF, 1, f1, 0.3f, func_00382538());
        if (s->f20 < 0) {
            return;
        }
        func_0038CE20(&v80, a0 + 0xC0, 0.35f);
        vec_add_ab(&v10, &v80, &v10);
        f2 = func_003824E0(1.0f, 1.0375f) * 0.33749998f;
        func_003D9508(&v10, 0x39, 0x302020FF, 1, f2, 0.3f, func_00382538());
    }
}
/* localdecomp:end func_L04_0035C9C8 */
