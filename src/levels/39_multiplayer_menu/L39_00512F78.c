#include "common.h"

/* declared by functions of L39_005128F8.c, which this file was cut from */
extern void func_L39_004F74E8(void *, s32, s32);
extern s32 func_L39_00510F60(void *, void *);

/* localdecomp:start func_L39_00512F78 */
typedef struct {
    s32 cap;
    s32 size;
    unsigned long *data;
} S_00512F78;

extern void func_L39_004F74E8(void *, s32, s32);
extern s32 func_L39_00512A40(s32, void *);
extern void func_L39_00515258(unsigned long, void *, s32, s32, void *, s32);
extern unsigned long func_1306F8(unsigned long, unsigned long);
extern s32 func_L39_00515030();
extern s32 func_L39_00515180(s32, void *);
extern s32 func_L39_00514EB8(s32, void *);
extern void func_L39_00515438(void *, void *);
extern s32 func_L39_00510F60(void *, void *);
extern s32 func_L39_00514AA0(void *, void *);

s32 func_L39_00512F78(S_00512F78 *a, S_00512F78 *m, unsigned long minv, S_00512F78 *r) {
    s32 n;
    s32 n2;
    s32 an;
    s32 last;
    s32 i;
    s32 err;
    s32 c;
    unsigned long *d;

    n = m->size;
    n2 = n * 2;
    an = a->size;
    if (r->cap < n2 + 3) {
        err = func_L39_00512A40(n2 + 3, r);
        if (err != 0) {
            return err;
        }
    }
    d = r->data;
    last = an - 1;
    func_L39_004F74E8(d, 0, n * 16 + 24);
    r->size = 1;
    for (i = 0; i < last; i++) {
        func_L39_00515258(a->data[i], a, i + 1, a->size - i - 1, r, i * 2 + 1);
    }
    err = func_L39_00515180(n2, r);
    if (err != 0) {
        return err;
    }
    err = func_L39_00514EB8(1, r);
    if (err != 0) {
        return err;
    }
    func_L39_00515438(a, r);
    for (i = 0; i < n; i++) {
        func_L39_00515258(func_1306F8(d[i], minv), m, 0, n, r, i);
    }
    r->size = n2 + 1;
    func_L39_00515030(n, r);
    func_L39_00515180(n, r);
    c = func_L39_00510F60(m, r);
    if (c < 0) {
        err = func_L39_00514AA0(m, r);
        if (err != 0) {
            return err;
        }
    } else if (c == 0) {
        r->data[0] = 0;
        r->size = 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00512F78 */

/* localdecomp:start func_L39_00513178 */
typedef struct {
    s32 cap;
    s32 size;
    unsigned long *data;
} S_00513178;

extern void func_L39_004F74E8(void *, s32, s32);
extern s32 func_L39_00512A40(s32, void *);
extern void func_L39_00515258(unsigned long, void *, s32, s32, void *, s32);
extern unsigned long func_1306F8(unsigned long, unsigned long);
extern s32 func_L39_00515030();
extern s32 func_L39_00515180(s32, void *);
extern s32 func_L39_00510F60(void *, void *);
extern s32 func_L39_00514AA0(void *, void *);

s32 func_L39_00513178(S_00513178 *a, S_00513178 *b, S_00513178 *m, unsigned long minv, S_00513178 *r) {
    s32 n;
    s32 n2;
    s32 i;
    s32 an;
    s32 err;
    unsigned long *ad;
    unsigned long *d;

    n = m->size;
    n2 = n * 2;
    if (r->cap < n2 + 3) {
        err = func_L39_00512A40(n2 + 3, r);
        if (err != 0) {
            return err;
        }
    }
    d = r->data;
    i = 0;
    func_L39_004F74E8(d, 0, n * 16 + 24);
    r->size = 1;
    an = a->size;
    ad = a->data;
    for (; i < an; i++) {
        func_L39_00515258(ad[i], b, 0, b->size, r, i);
        func_L39_00515258(func_1306F8(d[i], minv), m, 0, n, r, i);
    }
    for (; i < n; i++) {
        func_L39_00515258(func_1306F8(d[i], minv), m, 0, n, r, i);
    }
    r->size = n2 + 1;
    func_L39_00515030(n, r);
    func_L39_00515180(n, r);
    if (func_L39_00510F60(r, m) >= 0) {
        err = func_L39_00514AA0(m, r);
        if (err != 0) {
            return err;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00513178 */
