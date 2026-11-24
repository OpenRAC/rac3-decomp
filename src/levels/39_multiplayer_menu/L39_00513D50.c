#include "common.h"

/* declared by functions of L39_005128F8.c, which this file was cut from */
typedef struct S_005128F8 { s32 n; s32 cap; void *data; } S_005128F8;
extern void func_L39_005128E8(s32 *);
extern s32 func_L39_00513350(void *, void *, void *);
extern s32 func_L39_00513808(void *, void *, void *);
extern s32 func_L39_00510F60(void *, void *);
extern unsigned long func_001306F8(unsigned long, unsigned long);

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

/* localdecomp:start func_L39_00513FA0 */
typedef struct BN_00513FA0 { s32 s; s32 n; u64 *p; s32 pad; } BN_00513FA0;
extern s32 func_L39_00510EF0(void *, void *);
extern void func_L39_005128F8(void *);

s32 func_L39_00513FA0(BN_00513FA0 *a, BN_00513FA0 *b, BN_00513FA0 *c)
{
    BN_00513FA0 t0, t1;
    BN_00513FA0 *x;
    s32 rc;
    s32 k;

    func_L39_005128E8((s32 *)&t0);
    func_L39_005128E8((s32 *)&t1);
    goto start;
again:
    rc = func_L39_00513808(c, &t1, &t0);
    k = 2;
    if (rc != 0) goto out;
    if (t0.p[t0.n - 1] == 0) goto done;
    rc = func_L39_00513808(&t1, &t0, c);
    k = 1;
    if (rc != 0) goto out;
loop:
    if (c->p[c->n - 1] == 0) goto done;
    rc = func_L39_00513808(&t0, c, &t1);
    k = 0;
    if (rc != 0) goto out;
    if (t1.p[t1.n - 1] != 0) goto again;
done:
    if (rc == 0) {
        switch (k) {
        case 1:
            rc = func_L39_00510EF0(&t0, c);
            break;
        case 2:
            rc = func_L39_00510EF0(&t1, c);
            break;
        case 3:
            if (t0.p[t0.n - 1] == 0) {
                rc = 0x10A;
            } else {
                rc = func_L39_00510EF0(&t0, c);
            }
            break;
        }
    }
    goto out;
start:
    if (func_L39_00510F60(a, b) >= 0) {
        rc = func_L39_00510EF0(a, &t0);
        if (rc != 0) goto out;
        x = b;
    } else {
        rc = func_L39_00510EF0(b, &t0);
        if (rc != 0) goto out;
        x = a;
    }
    rc = func_L39_00510EF0(x, c);
    k = 3;
    if (rc == 0) goto loop;
out:
    func_L39_005128F8(&t0);
    func_L39_005128F8(&t1);
    return rc;
}
/* localdecomp:end func_L39_00513FA0 */
