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

/* localdecomp:start func_L39_00514868 */
extern s32 func_L39_00510F60(void *, void *);
extern s32 func_L39_00511268(s32, s32, s32);

s32 func_L39_00514868(void *arg0, void *arg1, s32 *arg2, void *arg3)
{
    if (func_L39_00510F60(arg0, arg1) >= 0) {
        *arg2 = 1;
        return func_L39_00511268((s32)arg0, (s32)arg1, (s32)arg3);
    }
    *arg2 = -1;
    return func_L39_00511268((s32)arg1, (s32)arg0, (s32)arg3);
}
/* localdecomp:end func_L39_00514868 */
