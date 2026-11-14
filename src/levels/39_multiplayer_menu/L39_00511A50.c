#include "common.h"

/* declared by functions of L39_00510BA8.c, which this file was cut from */
extern void func_L39_004F74E8(void *, s32, s32);
typedef struct { s32 cap; s32 n; long *d; } S_00510EF0;

/* localdecomp:start func_L39_00511A50 */
extern s32 func_L39_00515F90(void *);
extern s32 func_L39_00510F60(void *, void *);
/* 00512488 is defined later in the file with an anonymous struct type no earlier line can name: declared without a prototype */
extern s32 func_L39_00512488();
extern s32 func_L39_00512EC0(void *, unsigned long *);
extern s32 func_L39_00512620(void *, s32 *, s32 **, s32 *, s32 *);
extern s32 func_L39_00511BA8(void *, s32 *, s32, s32, s32, void *, void *, void *, void *);
extern void func_L39_004F74E8(void *, s32, s32);
extern void func_L39_004F7620(void *);

s32 func_L39_00511A50(void *x, void *m, void *e, void *r, void *ctx) {
    unsigned long inv;
    s32 w;
    s32 n;
    s32 *tab;
    s32 bits;
    s32 k;
    s32 err;

    n = 0;
    w = 0;
    tab = 0;
    do {
        if ((err = func_L39_00515F90(ctx)) != 0) break;
        if (func_L39_00510F60(x, e) >= 0) {
            err = 0x108;
            break;
        }
        k = func_L39_00511540(m);
        if (k < 2) {
            return func_L39_00512488((s32)x, m, (s32)e, (s32)r, k, (s32)ctx);
        }
        if ((err = func_L39_00512EC0(e, &inv)) != 0) break;
        if ((err = func_L39_00512620(m, &bits, &tab, &n, &w)) != 0) break;
        err = ((s32 (*)(void *, s32 *, s32, s32, s32, void *, unsigned long, void *, void *))func_L39_00511BA8)(x, tab, n, bits, w, e, inv, r, ctx);
    } while (0);
    if (tab != 0) {
        func_L39_004F74E8(tab, 0, n * 4);
        func_L39_004F7620(tab);
    }
    return err;
}
/* localdecomp:end func_L39_00511A50 */

/* localdecomp:start func_L39_00511BA8 */
typedef struct { s32 cap; s32 n; long *d; } S_00511BA8;

extern void func_L39_005128F8(void *);
extern void *func_L39_004F7590(s32);
extern void func_L39_004F7620(void *);
extern s32 func_L39_00512CB0(void *, void *, void *);
extern s32 func_L39_00512F78(void *, void *, void *, void *);
extern s32 func_L39_00515F90(void *);
extern s32 func_L39_00513178(void *, void *, void *, void *, void *);
extern s32 func_L39_00511DB0(void *, s32, s32 *, s32, void *, void *, void *, void *, void *);

s32 func_L39_00511BA8(void *arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5, void *arg6, void *arg7, void *arg8) {
    S_00511BA8 tmp;
    S_00511BA8 *buf;
    s32 count;
    s32 ret;
    s32 i;

    func_L39_005128E8((s32 *) &tmp);
    do {
        count = 1 << (arg3 - 1);
        buf = func_L39_004F7590(count * sizeof(S_00511BA8));
        if (buf == 0) {
            count = 0;
            ret = 0x100;
            break;
        }
        for (i = 0; i < count; i++) {
            func_L39_005128E8((s32 *) &buf[i]);
        }
        ret = func_L39_00512CB0(arg0, arg5, buf);
        if (ret != 0) break;
        if (arg4 != 1) {
            ret = func_L39_00512F78(buf, arg5, arg6, &tmp);
            if (ret != 0) break;
            ret = func_L39_00515F90(arg8);
            if (ret != 0) break;
            for (i = 1; i < count && 2 * i + 1 <= arg4; i++) {
                ret = func_L39_00513178(&buf[i - 1], &tmp, arg5, arg6, &buf[i]);
                if (ret != 0) break;
            }
            if (ret != 0) break;
        }
        ret = func_L39_00511DB0(buf, count, arg1, arg2, arg6, &tmp, arg5, arg7, arg8);
    } while (0);
    if (buf != 0) {
        for (i = 0; i < count; i++) {
            func_L39_005128F8(&buf[i]);
        }
        func_L39_004F7620(buf);
    }
    func_L39_005128F8(&tmp);
    return ret;
}
/* localdecomp:end func_L39_00511BA8 */

/* localdecomp:start func_L39_00511DB0 */
extern s32 func_L39_00515F90(void *);
extern s32 func_L39_00512F78(void *, void *, void *, void *);
extern s32 func_L39_00513178(void *, void *, void *, void *, void *);
extern s32 func_L39_00512E18(void *, void *, void *, void *);

typedef struct { s32 cap; s32 n; long *d; } S_00511DB0;

s32 func_L39_00511DB0(void *arg0, s32 count, s32 *tbl, s32 n, void *arg4, void *tmp, void *arg6, void *out, void *arg8) {
    S_00511DB0 *buf = arg0;
    s32 ret;
    s32 i;
    s32 a;
    s32 b;
    s32 flag;

    do {
        ret = func_L39_00515F90(arg8);
        if (ret != 0) break;
        ret = func_L39_00510EF0((S_00510EF0 *)buf, tmp);
        if (ret != 0) break;
        a = tbl[0];
        b = tbl[1];
        flag = 0;
        for (i = 2;;) {
            ret = func_L39_00515F90(arg8);
            if (ret != 0) goto out;
            if (flag == 1) {
                ret = func_L39_00512F78(out, arg6, arg4, tmp);
                if (ret != 0) goto out;
                a--;
                flag = 0;
            }
            while (a > 0) {
                ret = func_L39_00512F78(tmp, arg6, arg4, out);
                if (ret != 0) break;
                a--;
                flag = 1;
                if (a <= 0) break;
                ret = func_L39_00512F78(out, arg6, arg4, tmp);
                if (ret != 0) break;
                a--;
                flag = 0;
            }
            if (ret != 0) goto out;
            if (b != 0) {
                b = (b - 1) >> 1;
                if (flag == 0) {
                    ret = func_L39_00513178(&buf[b], tmp, arg6, arg4, out);
                    if (ret != 0) goto out;
                    flag = 1;
                } else {
                    ret = func_L39_00513178(&buf[b], out, arg6, arg4, tmp);
                    if (ret != 0) goto out;
                    flag = 0;
                }
            }
            if (i >= n) break;
            a = tbl[i];
            b = tbl[i + 1];
            i += 2;
            if (a == 0) break;
        }
        if (ret != 0) break;
        if (flag == 0) {
            ret = func_L39_00512E18(tmp, arg6, arg4, out);
        } else {
            ret = func_L39_00512E18(out, arg6, arg4, tmp);
            if (ret != 0) break;
            ret = func_L39_00510EF0(tmp, out);
        }
    } while (0);
out:
    return ret;
}
/* localdecomp:end func_L39_00511DB0 */

/* localdecomp:start func_L39_00512018 */
typedef struct { s32 a, b, c; } S_00512018;
typedef struct { S_00512018 p, q; } P_00512018;
extern void func_L39_005120B0(s32, s32, P_00512018 *, P_00512018 *, s32, s32, s32);
void func_L39_00512018(s32 a0, S_00512018 *p, S_00512018 *q, S_00512018 *r, S_00512018 *s, s32 x, s32 y, s32 z) {
    P_00512018 u;
    P_00512018 v;
    u.p = *p;
    u.q = *q;
    v.p = *r;
    v.q = *s;
    func_L39_005120B0(a0, 2, &u, &v, x, y, z);
}
/* localdecomp:end func_L39_00512018 */

INCLUDE_ASM("asm/levels", func_L39_005120B0);

/* localdecomp:start func_L39_00512488 */
extern s32 func_L39_005119F0(s32, s32);
extern s32 func_L39_00512510(s32, s32, s32, s32);
extern s32 func_L39_00512B20(s32, s32, s32, s32);

typedef struct {
    s32 unk0;
    s32 unk4;
    s64 *unk8;
} S_00512488;

s32 func_L39_00512488(s32 arg0, S_00512488 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    if (arg4 < 2) {
        if (*arg1->unk8 == 0) {
            return func_L39_005119F0(1, arg3);
        }
        return func_L39_00510EF0((S_00510EF0 *)arg0, (S_00510EF0 *)arg3);
    }
    if (*arg1->unk8 == 3) {
        return func_L39_00512510(arg0, arg2, arg3, arg5);
    }
    return func_L39_00512B20(arg0, arg0, arg2, arg3);
}
/* localdecomp:end func_L39_00512488 */

/* localdecomp:start func_L39_00512510 */
typedef struct { s32 cap; s32 n; long *d; } S_00512510;
extern s32 func_L39_00513350(void *, void *, void *);
extern s32 func_L39_00513470(void *, void *, void *, void *);

s32 func_L39_00512510(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    S_00512510 a;
    S_00512510 b;
    s32 ret;

    func_L39_005128E8((s32 *) &a);
    func_L39_005128E8((s32 *) &b);
    do {
        if ((ret = func_L39_00513350((void *)arg0, (void *)arg0, &a)) != 0) break;
        if ((ret = func_L39_00513470(&a, (void *)arg1, &b, (void *)arg2)) != 0) break;
        if ((ret = func_L39_00515F90((void *)arg3)) != 0) break;
        if ((ret = func_L39_00513350((void *)arg0, (void *)arg2, &a)) != 0) break;
        ret = func_L39_00513470(&a, (void *)arg1, &b, (void *)arg2);
    } while (0);
    func_L39_005128F8(&a);
    func_L39_005128F8(&b);
    return ret;
}
/* localdecomp:end func_L39_00512510 */

INCLUDE_ASM("asm/levels", func_L39_00512620);

/* localdecomp:start func_L39_00512778 */
s32 func_L39_00512778(s32 arg0)
{
    if (arg0 >= 0x3FC) {
        return 6;
    }
    if (arg0 >= 0x17E) {
        return 5;
    }
    if (arg0 >= 0x50) {
        return 4;
    }
    if (arg0 >= 0x13) {
        return 3;
    }
    return 2;
}
/* localdecomp:end func_L39_00512778 */

INCLUDE_ASM("asm/levels", func_L39_005127B8);
