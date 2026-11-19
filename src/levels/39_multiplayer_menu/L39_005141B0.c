#include "common.h"

/* declared by functions of L39_005128F8.c, which this file was cut from */
typedef struct S_005128F8 { s32 n; s32 cap; void *data; } S_005128F8;
extern void func_L39_005128E8(s32 *);
extern s32 func_L39_00513350(void *, void *, void *);
extern s32 func_L39_00513808(void *, void *, void *);
extern s32 func_L39_00510F60(void *, void *);
extern unsigned long func_001306F8(unsigned long, unsigned long);

/* localdecomp:start func_L39_005141B0 */
typedef struct { s32 cap; s32 n; long *d; } V_005141B0;
extern void func_L39_005128F8(S_005128F8 *);
extern s32 func_L39_00510EF0(void *, void *);
extern s32 func_L39_00512A40(s32, V_005141B0 *);
extern s32 func_L39_00513470(void *, void *, void *, void *);
extern s32 func_L39_00514750(void *, void *, void *, s32 *, s32 *, void *, void *);
extern s32 func_L39_00511268(s32, s32, s32);
extern s32 func_L39_00510FF0(void *, void *, void *);

s32 func_L39_005141B0(V_005141B0 *a, V_005141B0 *b, V_005141B0 *c, V_005141B0 *d, V_005141B0 *e) {
    V_005141B0 v0, v1, v2, v3, v4;
    s32 y = 1;
    s32 x = 1;
    V_005141B0 *big;
    V_005141B0 *small;
    s32 flag;
    s32 r;
    s32 k;

    func_L39_005128E8((s32 *)&v0);
    flag = 0;
    func_L39_005128E8((s32 *)&v1);
    func_L39_005128E8((s32 *)&v2);
    func_L39_005128E8((s32 *)&v3);
    func_L39_005128E8((s32 *)&v4);

    do {
        if (func_L39_00510F60(a, b) >= 0) {
            big = a;
            small = b;
            r = func_L39_00510EF0(big, &v0);
            if (r != 0) break;
            r = func_L39_00510EF0(b, &v1);
            if (r != 0) break;
            flag = 1;
        } else {
            small = a;
            big = b;
            r = func_L39_00510EF0(big, &v0);
            if (r != 0) break;
            r = func_L39_00510EF0(a, &v1);
            if (r != 0) break;
            flag = 0;
        }

        r = func_L39_00512A40(1, &v2);
        if (r != 0) break;
        v2.n = 1;
        v2.d[0] = 1;
        if (c->cap <= 0) {
            r = func_L39_00512A40(1, c);
            if (r != 0) break;
        }
        c->n = 1;
        c->d[0] = 0;

        if (small->d[small->n - 1] == 0) {
            if (big->d[big->n - 1] == 0) {
                r = 0x10A;
                break;
            }
            r = func_L39_00510EF0(big, e);
            if (r != 0) break;
            if (d->cap <= 0) {
                r = func_L39_00512A40(1, d);
                if (r != 0) break;
            }
            d->n = 1;
            d->d[0] = 1;
            break;
        }

        r = func_L39_00513470(&v0, &v1, d, e);
        if (r != 0) break;
        if (e->d[e->n - 1] == 0) {
            d->n = 1;
            d->d[0] = 1;
            r = func_L39_00510EF0(small, e);
            break;
        }

        do {
            r = func_L39_00514750(&v3, &v4, d, &x, &y, &v2, c);
            if (r != 0) break;
            r = func_L39_00513470(&v1, e, d, &v0);
            k = 1;
            if (r != 0) break;
            if (v0.d[v0.n - 1] == 0) break;
            r = func_L39_00514750(&v3, &v4, d, &x, &y, &v2, c);
            if (r != 0) break;
            r = func_L39_00513470(e, &v0, d, &v1);
            k = 2;
            if (r != 0) break;
            if (v1.d[v1.n - 1] == 0) break;
            r = func_L39_00514750(&v3, &v4, d, &x, &y, &v2, c);
            if (r != 0) break;
            r = func_L39_00513470(&v0, &v1, d, e);
            k = 0;
            if (r != 0) break;
        } while (e->d[e->n - 1] != 0);

        if (r != 0) break;
        switch (k) {
        case 0:
            func_L39_00510EF0(&v1, e);
            break;
        case 2:
            func_L39_00510EF0(&v0, e);
            break;
        }
        r = func_L39_00513350(c, big, &v3);
        if (r != 0) break;
        if (y > 0) {
            r = func_L39_00511268((s32)&v3, (s32)e, (s32)&v4);
            if (r != 0) break;
        } else {
            r = func_L39_00510FF0(&v3, e, &v4);
            if (r != 0) break;
        }
        r = func_L39_00513470(&v4, small, d, &v3);
        if (r != 0) break;
        if (y > 0) {
            r = func_L39_00511268((s32)big, (s32)d, (s32)&v4);
            if (r != 0) break;
            r = func_L39_00510EF0(&v4, d);
        } else {
            r = func_L39_00511268((s32)small, (s32)c, (s32)&v4);
            if (r != 0) break;
            r = func_L39_00510EF0(&v4, c);
        }
    } while (0);

    if (flag == 0 && r == 0) {
        r = func_L39_00510EF0(c, &v3);
        if (r == 0) {
            r = func_L39_00510EF0(d, c);
            if (r == 0) {
                r = func_L39_00510EF0(&v3, d);
            }
        }
    }
    func_L39_005128F8((S_005128F8 *)&v0);
    func_L39_005128F8((S_005128F8 *)&v1);
    func_L39_005128F8((S_005128F8 *)&v2);
    func_L39_005128F8((S_005128F8 *)&v3);
    func_L39_005128F8((S_005128F8 *)&v4);
    return r;
}
/* localdecomp:end func_L39_005141B0 */
