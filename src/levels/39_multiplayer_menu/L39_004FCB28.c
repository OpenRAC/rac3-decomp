#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

/* declared by functions of L39_004FCA98.c, which this file was cut from */
extern void func_L39_004FC318(void *p);

/* localdecomp:start func_L39_004FCB28 */
/* BN_lshift */
typedef struct {
    unsigned long *d;
    s32 top;
    s32 dmax;
    s32 neg;
} BN_004FCB28;
extern BN_004FCB28 *func_L39_004FC4B8(BN_004FCB28 *, s32);
extern void *func_0011D534(void *, s32, s32);

s32 func_L39_004FCB28(BN_004FCB28 *r, BN_004FCB28 *a, s32 n) {
    s32 i, nw, lb, rb;
    unsigned long *t, *f;
    unsigned long l;

    if (((a->top + n / 64 + 1 <= r->dmax) ? r : func_L39_004FC4B8(r, a->top + n / 64 + 1)) == 0) {
        return 0;
    }
    r->neg = a->neg;
    nw = n / 64;
    lb = n % 64;
    rb = 64 - lb;
    f = a->d;
    t = r->d;
    t[a->top + nw] = 0;
    if (lb == 0) {
        for (i = a->top - 1; i >= 0; i--) {
            t[nw + i] = f[i];
        }
    } else {
        for (i = a->top - 1; i >= 0; i--) {
            l = f[i];
            t[nw + i + 1] |= l >> rb;
            t[nw + i] = l << lb;
        }
    }
    func_0011D534(t, 0, nw * 8);
    r->top = a->top + nw + 1;
    func_L39_004FC318(r);
    return 1;
}
/* localdecomp:end func_L39_004FCB28 */

/* localdecomp:start func_L39_004FCCC8 */
extern void *func_L39_004DBA08(void);

s32 func_L39_004FCCC8(void *a0, s32 *a1) {
    s32 local;
    s32 *p = a1;
    void *obj = a0;
    s32 r;
    s32 (*f)(void) = *(s32 (**)(void))((char *)func_L39_004DBA08() + 0xC);
    if (p == 0) {
        p = &local;
    }
    if (obj == 0) {
        obj = (void *)f();
    }
    r = (*(s32 (**)(void *, s32 *))((char *)obj + 0x10))(obj, p);
    if (r != 0) {
        return 0;
    }
    return *p;
}
/* localdecomp:end func_L39_004FCCC8 */
