#include "common.h"

/* declared by functions of L39_005128F8.c, which this file was cut from */
extern void func_L39_004F74E8(void *, s32, s32);
typedef struct {
    s32 cap;
    s32 count;
    unsigned long *words;
} S_00512A40_Big;
extern s32 func_L39_00513350(void *, void *, void *);

/* localdecomp:start func_L39_00513350 */
typedef struct { s32 cap; s32 n; unsigned long *d; } S_00513350;

extern void func_L39_00515258(unsigned long, void *, s32, s32, void *, s32);

s32 func_L39_00513350(void *pa, void *pb, void *pr) {
    S_00513350 *a = pa;
    S_00513350 *b = pb;
    S_00513350 *r = pr;
    s32 bn = b->n;
    s32 an = a->n;
    s32 len = bn + an;
    s32 i;
    s32 err;
    unsigned long *d;

    if (r->cap < len) {
        err = func_L39_00512A40(len, (S_00512A40_Big *)r);
        if (err != 0) {
            return err;
        }
    }
    d = r->d;
    func_L39_004F74E8(d, 0, len * 8);
    for (i = 0; i < an; i++) {
        func_L39_00515258(a->d[i], b, 0, bn, r, i);
    }
    while (len > 0 && d[--len] == 0) {
    }
    len++;
    r->n = len;
    return 0;
}
/* localdecomp:end func_L39_00513350 */
