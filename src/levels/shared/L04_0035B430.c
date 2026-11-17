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

INCLUDE_ASM("asm/levels", func_L04_0035B838);

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

INCLUDE_ASM("asm/levels", func_L04_0035BC10);

INCLUDE_ASM("asm/levels", func_L04_0035C1B8);

INCLUDE_ASM("asm/levels", func_L04_0035C2B0);

INCLUDE_ASM("asm/levels", func_L04_0035C398);

INCLUDE_ASM("asm/levels", func_L04_0035C9C8);
