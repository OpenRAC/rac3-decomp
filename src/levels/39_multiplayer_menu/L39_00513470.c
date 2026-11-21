#include "common.h"

/* declared by functions of L39_005128F8.c, which this file was cut from */
typedef struct S_005128F8 { s32 n; s32 cap; void *data; } S_005128F8;
typedef struct {
    s32 cap;
    s32 count;
    unsigned long *words;
} S_00512A40_Big;
extern void func_L39_005128E8(s32 *);
extern s32 func_L39_00513808(void *, void *, void *);
extern s32 func_L39_00510F60(void *, void *);

/* localdecomp:start func_L39_00513470 */
typedef struct { s32 cap; s32 n; long *d; } BN_00513470;
/* defined later in this file, on S_00515030 (the same layout) */
extern s32 func_L39_00515030();

extern void func_L39_005128F8(void *);
extern s32 func_L39_00514EB8(s32, void *);
extern s32 func_L39_00510F60(void *, void *);
extern s32 func_L39_00510EF0(void *, void *);
extern s32 func_L39_00512A40(s32, void *);
extern s32 func_L39_00514AA0(void *, void *);
extern s32 func_L39_00511188(long, void *);
extern s32 func_L39_00513AD8(long, void *);
extern s32 func_L39_00513B90(void *, void *, void *, void *);
extern s32 func_L39_00514CF8(s32, void *);
extern void func_L39_00515088(s32, void *);
extern s32 func_L39_00511480(s32, void *);
extern s32 func_L39_005151E8(void *, s32 *);

s32 func_L39_00513470(BN_00513470 *a, BN_00513470 *b, BN_00513470 *q, BN_00513470 *r) {
    BN_00513470 t;
    BN_00513470 u;
    s32 shift;
    s32 err;
    s32 na;
    s32 nb;
    s32 i;

    func_L39_005128E8((s32 *)&t);
    func_L39_005128E8((s32 *)&u);
    do {
        if (q->cap <= 0) {
            if ((err = func_L39_00512A40(2, q)) != 0) break;
        }
        *q->d = 0;
        q->n = 1;
        if (func_L39_00510F60(a, b) < 0) {
            err = func_L39_00510EF0(a, r);
            break;
        }
        if ((err = func_L39_005151E8(b, &shift)) != 0) break;
        err = 0x106;
        if (shift == 0x40) break;
        if (shift > 0) {
            if ((err = func_L39_00514EB8(shift, b)) != 0) break;
            if ((err = func_L39_00514EB8(shift, a)) != 0) break;
        }
        na = a->n;
        nb = b->n;
        if ((err = func_L39_00510EF0(a, r)) != 0) break;
        if (nb < na) {
            if ((err = func_L39_00515030(na - nb, r)) != 0) break;
        } else {
            *q->d = 1;
            q->n = 1;
            if ((err = func_L39_00514AA0(b, r)) != 0) break;
        }
        if ((err = func_L39_00512A40(na, &u)) != 0) break;
        if ((err = func_L39_00512A40(2, &t)) != 0) break;
        for (i = na - nb - 1; i >= 0; i--) {
            if (func_L39_00510F60(r, b) >= 0) {
                if ((err = func_L39_00514AA0(b, r)) != 0) break;
                if ((err = func_L39_00511188(1, q)) != 0) break;
            }
            if ((err = func_L39_00513AD8(a->d[i], r)) != 0) break;
            if ((err = func_L39_00514CF8(1, q)) != 0) break;
            if (nb < r->n) {
                if ((err = func_L39_00513B90(r, b, &t, &u)) != 0) break;
                while (func_L39_00510F60(&u, r) > 0) {
                    if ((err = func_L39_00511480(1, &t)) != 0) break;
                    if ((err = func_L39_00514AA0(b, &u)) != 0) break;
                }
                if (err != 0) break;
                if ((err = func_L39_00511188(*t.d, q)) != 0) break;
                if ((err = func_L39_00514AA0(&u, r)) != 0) break;
            }
        }
        if (err != 0) break;
        if (shift > 0) {
            func_L39_00515088(shift, r);
            func_L39_00515088(shift, a);
            func_L39_00515088(shift, b);
        }
        if (func_L39_00510F60(r, b) < 0) break;
        if ((err = func_L39_00514AA0(b, r)) != 0) break;
        err = func_L39_00511188(1, q);
    } while (0);
    func_L39_005128F8(&t);
    func_L39_005128F8(&u);
    return err;
}
/* localdecomp:end func_L39_00513470 */

INCLUDE_ASM("asm/levels", func_L39_00513808);

/* localdecomp:start func_L39_00513AD8 */
typedef struct { s32 cap; s32 count; unsigned long *data; } S_00513AD8;
extern s32 func_L39_004F7538(void *, void *, s32);
extern s32 func_L39_00512948(s32, S_00513AD8 *);
s32 func_L39_00513AD8(long val, void *arg) {
    S_00513AD8 *s = arg;
    s32 n = s->count;
    unsigned long *p = s->data;
    s32 bytes = n * 8;
    s32 need = n + 1;
    unsigned long *d = s->data;
    s32 err;
    if (p[n - 1] != 0) {
        if (s->cap < need) {
            err = func_L39_00512948(n + 2, s);
            if (err != 0) {
                return err;
            }
            d = s->data;
        }
        func_L39_004F7538(d + 1, d, bytes);
        s->data[0] = val;
        s->count++;
        return 0;
    }
    p[0] = val;
    s->count = 1;
    return 0;
}
/* localdecomp:end func_L39_00513AD8 */

/* localdecomp:start func_L39_00513B90 */
typedef struct {
    s32 f0;
    s32 f4;
    unsigned long *f8;
    s32 fC;
} S_00513B90;
extern void func_L39_00513D50(unsigned long, unsigned long, unsigned long, unsigned long *, unsigned long *);
extern s32 func_L39_00513350(void *, void *, void *, s32);

s32 func_L39_00513B90(void *a0, void *a1, void *a2, void *a3) {
    S_00513B90 *a = a0;
    S_00513B90 *b = a1;
    S_00513B90 *q = a2;
    S_00513B90 *r = a3;
    S_00513B90 x;
    S_00513B90 y;
    unsigned long qd;
    unsigned long rd;
    s32 m, n;
    s32 k, c, k2, c2;
    s32 ret;

    func_L39_005128E8((s32 *) &x);
    func_L39_005128E8((s32 *) &y);
    goto test;
body:
    if ((ret = func_L39_00510EF0(a, &x)) != 0) goto end;
    if ((ret = func_L39_00510EF0(b, &y)) != 0) goto end;
    k = m - 3;
    if (k >= 0) c = k; else c = 0;
    func_L39_00515030(c, &x);
    k2 = n - 2;
    if (k2 >= 0) c2 = k2; else c2 = 0;
    func_L39_00515030(c2, &y);
    func_L39_00513D50(y.f8[y.f4 - 1], x.f8[x.f4 - 1], x.f8[x.f4 - 2], &qd, &rd);
    q->f8[0] = qd;
    q->f4 = 1;
    func_L39_00513350(q, b, r, 1);
    goto end;
test:
    n = b->f4;
    m = a->f4;
    if (n < m) goto body;
    if (r->f0 <= 0) {
        if ((ret = func_L39_00512A40(2, r)) != 0) goto end;
    }
    r->f8[0] = 0;
    r->f4 = 1;
    if (q->f0 <= 0) {
        if ((ret = func_L39_00512A40(2, q)) != 0) goto end;
    }
    q->f8[0] = 0;
    q->f4 = 1;
    ret = 0;
end:
    func_L39_005128F8(&x);
    func_L39_005128F8(&y);
    return ret;
}
/* localdecomp:end func_L39_00513B90 */
