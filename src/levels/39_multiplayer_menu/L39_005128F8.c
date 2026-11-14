#include "common.h"

/* localdecomp:start func_L39_005128F8 */
extern void func_L39_004F74E8(void *, s32, s32);
extern void func_L39_004F7620(void *);
typedef struct S_005128F8 { s32 n; s32 cap; void *data; } S_005128F8;

void func_L39_005128F8(S_005128F8 *arg0) {
    if (arg0->data != 0) {
        func_L39_004F74E8(arg0->data, 0, arg0->n << 3);
        func_L39_004F7620(arg0->data);
        arg0->data = 0;
    }
    arg0->n = 0;
    arg0->cap = 0;
}
/* localdecomp:end func_L39_005128F8 */

/* localdecomp:start func_L39_00512948 */
typedef struct { s32 cap; s32 count; unsigned long *data; } S_00512948;
extern void *func_L39_004F7590(s32);
extern void func_L39_004F7510(void *, void *, s32);
extern void func_L39_004F74E8(void *, s32, s32);
extern void func_L39_004F7620(void *);
s32 func_L39_00512948(s32 n, S_00512948 *s) {
    unsigned long *p;
    s32 size = n * 8;

    if (s->cap >= n) {
        return 0;
    }
    if (s->data == 0) {
        s->cap = n;
        s->data = func_L39_004F7590(size);
        if (s->data == 0) {
            s->cap = 0;
            return 0x100;
        }
        return 0;
    }
    p = func_L39_004F7590(size);
    if (p != 0) {
        func_L39_004F7510(p, s->data, s->count * 8);
        func_L39_004F74E8(s->data, 0, s->cap * 8);
        func_L39_004F7620(s->data);
        s->cap = n;
        s->data = p;
        return 0;
    }
    func_L39_004F74E8(s->data, 0, s->cap * 8);
    func_L39_004F7620(s->data);
    s->cap = 0;
    s->count = 0;
    s->data = 0;
    return 0x100;
}
/* localdecomp:end func_L39_00512948 */

/* localdecomp:start func_L39_00512A40 */
typedef struct {
    s32 cap;
    s32 count;
    unsigned long *words;
} S_00512A40_Big;

extern void *func_L39_004F7590(s32);
extern void func_L39_004F74E8(void *, s32, s32);
extern void func_L39_004F7620(void *);

s32 func_L39_00512A40(s32 n, S_00512A40_Big *b) {
    unsigned long *p;
    s32 ret;
    s32 size = n * 8;

    if (b->cap >= n) {
        return 0;
    }
    if (b->words == 0) {
        b->cap = n;
        b->words = func_L39_004F7590(size);
        if (b->words == 0) {
            b->cap = 0;
            return 0x100;
        }
        return 0;
    }
    p = func_L39_004F7590(size);
    if (p != 0) {
        func_L39_004F74E8(b->words, 0, b->cap * 8);
        func_L39_004F7620(b->words);
        b->cap = n;
        b->words = p;
        ret = 0;
    } else {
        func_L39_004F74E8(b->words, 0, b->cap * 8);
        func_L39_004F7620(b->words);
        b->cap = 0;
        b->words = 0;
        ret = 0x100;
    }
    b->count = 0;
    return ret;
}
/* localdecomp:end func_L39_00512A40 */

/* localdecomp:start func_L39_00512B20 */
extern void func_L39_005128E8(s32 *);
extern s32 func_L39_00513350(void *, void *, void *);
extern s32 func_L39_00513808(void *, void *, void *);
s32 func_L39_00512B20(void *a, void *b, void *c, void *d) {
    s32 buf[4];
    s32 r;
    func_L39_005128E8(buf);
    r = func_L39_00513350(a, b, buf);
    if (r == 0) r = func_L39_00513808(buf, c, d);
    func_L39_005128F8((S_005128F8 *)buf);
    return r;
}
/* localdecomp:end func_L39_00512B20 */

/* localdecomp:start func_L39_00512BA8 */
typedef struct { s32 cap; s32 n; long *d; } S_00512BA8;
extern void func_L39_005128E8(s32 *);
extern s32 func_L39_00510F60(void *, void *);
extern s32 func_L39_005141B0(void *, void *, void *, void *, void *);

s32 func_L39_00512BA8(void *arg0, S_00512BA8 *arg1, void *arg2) {
    S_00512BA8 a;
    S_00512BA8 b;

    s32 ret;

    func_L39_005128E8((s32 *)&a);
    func_L39_005128E8((s32 *)&b);
    for (;;) {
        if (func_L39_00510F60(arg0, arg1) >= 0) {
            ret = arg1->d[arg1->n - 1] == 0 ? 0x107 : 0x108;
            break;
        }
        ret = func_L39_005141B0(arg0, arg1, arg2, &a, &b);
        if (ret != 0) break;
        if (b.n != 1 || b.d[0] != 1) ret = 0x10B;
        break;
    }
    func_L39_005128F8((S_005128F8 *)&a);
    func_L39_005128F8((S_005128F8 *)&b);
    return ret;
}
/* localdecomp:end func_L39_00512BA8 */

INCLUDE_ASM("asm/levels", func_L39_00512CB0);

INCLUDE_ASM("asm/levels", func_L39_00512E18);

/* localdecomp:start func_L39_00512EC0 */
typedef struct { s32 unk0; s32 unk4; unsigned long *unk8; } S_00512EC0;
extern unsigned long func_001306F8(unsigned long, unsigned long);
s32 func_L39_00512EC0(S_00512EC0 *arg0, unsigned long *arg1) {
    unsigned long x = *arg0->unk8;
    unsigned long bit, r, mask;
    s32 i;
    if ((x & 1) == 0) {
        return 0x107;
    }
    mask = 3;
    bit = 2;
    r = 1;
    if ((x & mask) > bit) {
        r += bit;
    }
    for (i = 0x3D; i >= 0; i--) {
        bit <<= 1;
        mask |= bit;
        if ((func_001306F8(x, r) & mask) > bit) {
            r += bit;
        }
    }
    *arg1 = ~r + 1;
    return 0;
}
/* localdecomp:end func_L39_00512EC0 */

INCLUDE_ASM("asm/levels", func_L39_00512F78);

INCLUDE_ASM("asm/levels", func_L39_00513178);

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

INCLUDE_ASM("asm/levels", func_L39_00513470);

INCLUDE_ASM("asm/levels", func_L39_00513808);

INCLUDE_ASM("asm/levels", func_L39_00513AD8);

INCLUDE_ASM("asm/levels", func_L39_00513B90);

/* localdecomp:start func_L39_00513D50 */
extern void func_L39_00513DF0(unsigned long, unsigned long, unsigned long, unsigned long *, unsigned long *);

void func_L39_00513D50(unsigned long hi, unsigned long lo, unsigned long d, unsigned long *quot, unsigned long *rem)
{
    unsigned long q1, r1, q2, r2;

    if (lo < hi) {
        func_L39_00513DF0(hi, lo, d, &q1, &r1);
        func_L39_00513DF0(hi, r1, d << 32, &q2, &r2);
        *quot = (q1 << 32) + q2;
        *rem = r2;
    } else {
        *quot = -1;
        *rem = 0;
    }
}
/* localdecomp:end func_L39_00513D50 */

/* localdecomp:start func_L39_00513DF0 */
extern long func_00130760(long, long);
extern unsigned long func_001306F8(unsigned long, unsigned long);

void func_L39_00513DF0(unsigned long d, unsigned long h, unsigned long l,
                       unsigned long *qp, unsigned long *rp) {
    unsigned long dh;
    unsigned long dl;
    unsigned long q;
    unsigned long ql;
    unsigned long qh;
    unsigned long lo;
    unsigned long hi;
    unsigned long m;
    unsigned long t;
    unsigned long nh;
    unsigned long nl;
    unsigned long s;

    dh = d >> 32;
    nl = (h << 32) | (l >> 32);
    dl = d & 0xFFFFFFFF;
    nh = h >> 32;
    q = func_00130760(h, dh);
    ql = q & 0xFFFFFFFF;
    qh = q >> 32;
    lo = func_001306F8(ql, dl);
    hi = func_001306F8(qh, dh);
    t = func_001306F8(ql, dh);
    m = func_001306F8(dl, qh);
    s = t + m;
    if (s < t) {
        hi += (unsigned long) 1 << 32;
    }
    hi += s >> 32;
    s <<= 32;
    lo += s;
    hi += lo < s;
    while (hi > nh || (hi == nh && lo > nl)) {
        q--;
        if (lo >= d) {
            lo -= d;
        } else {
            hi--;
            lo = ~(d - lo) + 1;
        }
    }
    *rp = (lo <= nl) ? nl - lo : ~(lo - nl) + 1;
    *qp = q;
}
/* localdecomp:end func_L39_00513DF0 */

INCLUDE_ASM("asm/levels", func_L39_00513FA0);

INCLUDE_ASM("asm/levels", func_L39_005141B0);

/* localdecomp:start func_L39_00514750 */
extern s32 func_L39_00513350(void *, void *, void *);
extern s32 func_L39_00514868(void *, void *, s32 *, void *);
extern s32 func_L39_00510FF0(void *, void *, void *);
extern s32 func_L39_00510EF0(void *, void *);

s32 func_L39_00514750(void *arg0, void *arg1, void *arg2, s32 *arg3, s32 *arg4, void *arg5, void *arg6) {
    s32 old;
    s32 ret;
    s32 m;

    old = *arg3;
    *arg3 = *arg4;
    do {
        ret = func_L39_00513350(arg2, arg6, arg1);
        if (ret != 0) {
            break;
        }
        if (*arg4 != old) {
            ret = func_L39_00510FF0(arg5, arg1, arg0);
            if (ret != 0) {
                break;
            }
            *arg4 = -*arg4;
        } else {
            if (func_L39_00514868(arg5, arg1, &m, arg0) != ret) {
                break;
            }
            *arg4 = *arg4 * m;
        }
        ret = func_L39_00510EF0(arg6, arg5);
        if (ret == 0) {
            ret = func_L39_00510EF0(arg0, arg6);
        }
    } while (0);
    return ret;
}
/* localdecomp:end func_L39_00514750 */

INCLUDE_ASM("asm/levels", func_L39_00514868);

INCLUDE_ASM("asm/levels", func_L39_005148F8);

INCLUDE_ASM("asm/levels", func_L39_00514AA0);

/* localdecomp:start func_L39_00514BE0 */
extern s32 func_L39_00510F60(void *, void *);
extern s32 func_L39_00511268(s32, s32, s32);
extern s32 func_L39_00510FF0(void *, void *, void *);

s32 func_L39_00514BE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5)
{
    if (func_L39_00510F60((void *)arg0, (void *)arg2) >= 0) {
        *arg5 = arg1;
        if (arg1 == arg3) {
            return func_L39_00511268(arg0, arg2, arg4);
        }
        return func_L39_00510FF0((void *)arg0, (void *)arg2, (void *)arg4);
    }
    *arg5 = -arg3;
    if (arg1 == arg3) {
        return func_L39_00511268(arg2, arg0, arg4);
    }
    return func_L39_00510FF0((void *)arg0, (void *)arg2, (void *)arg4);
}
/* localdecomp:end func_L39_00514BE0 */

INCLUDE_ASM("asm/levels", func_L39_00514CF8);

INCLUDE_ASM("asm/levels", func_L39_00514EB8);
