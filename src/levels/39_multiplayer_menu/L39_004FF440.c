#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

/* declared by functions of L39_004FB668.c, which this file was cut from */
extern void *func_L39_004BEED8(s32);

/* localdecomp:start func_L39_004FF440 */
typedef struct { char _p[0x10]; s32 f10; s32 f14; s32 f18; } S_004FF440;
extern void func_L39_0050B6F0(s32);
extern void func_L39_004BEF28(void *);
s32 func_L39_004FF440(S_004FF440 *p) {
    func_L39_0050B6F0(p->f10);
    if (p->f14 != 0) func_L39_004BEF28((void *)p->f14);
    if (p->f18 != 0) func_L39_004BEF28((void *)p->f18);
    func_L39_004BEF28(p);
    return 0;
}
/* localdecomp:end func_L39_004FF440 */

/* localdecomp:start func_L39_004FF4A0 */
typedef struct {
    s32 *f0;
    s32 pad4[3];
    u8 *f10;
    void *f14;
} S_004FF4A0;
/* aliases: L39_004FF440.c defines func_L39_004FFBB0 and declares func_L39_004FC288 later, with types not yet declared here */
extern s32 func_L39_004FFBB0_004FF4A0(u8 *, s32 *, void *);
extern s32 func_L39_004FC288_004FF4A0(u8 *, s32);
extern s32 func_L39_0050BB88(s32 *, s32 *, s32, void *);
extern void func_L39_004BEF28(void *);
extern void func_0011D380(void *, s32, s32);

s32 func_L39_004FF4A0(S_004FF4A0 *arg0, s32 *arg1, s32 cmd, s32 arg3, void *ctx) {
    s32 loc;
    s32 n;
    u8 *p;
    s32 r;
    void *buf;

    if (cmd == 1) {
        p = arg0->f10;
        r = func_L39_004FFBB0_004FF4A0(p, arg1, ctx);
        n = *arg0->f0;
        if (arg1[1] < n) {
            func_L39_004FC288_004FF4A0(p + 0xC, n);
            func_L39_004FC288_004FF4A0(p + 0x20, n);
        }
        return r == 0;
    }
    if (cmd == 3) {
        n = func_L39_0050BB88(arg1, &loc, arg3, ctx);
        if (n >= 2) {
            if (arg0->f14 != 0) {
                func_L39_004BEF28(arg0->f14);
            }
            buf = func_L39_004BEED8(n);
            arg0->f14 = buf;
            if (buf == 0) {
                return 1;
            }
            func_0011D380(buf, loc, n);
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_004FF4A0 */

/* localdecomp:start func_L39_004FF5A0 */
typedef unsigned long UL_004FF5A0;
typedef struct { UL_004FF5A0 *d; s32 top; s32 dmax; s32 neg; s32 flags; } BN_004FF5A0;
typedef struct {
    s32 use_word;
    s32 f4;
    s32 ri;
    BN_004FF5A0 RR;
    BN_004FF5A0 N;
    char _p[0x48 - 0x34];
    UL_004FF5A0 n0;
} Mont_004FF5A0;
typedef struct Cb_004FF5A0 { s32 (*fn)(struct Cb_004FF5A0 *, s32, s32); } Cb_004FF5A0;
typedef struct { s32 tos; BN_004FF5A0 bn[13]; s32 f108; Cb_004FF5A0 *cb; } Ctx_004FF5A0;
typedef struct { char _p[0x10]; Mont_004FF5A0 *mont; unsigned char *rec; } P_004FF5A0;

/* aliases: this file declares func_L39_004FC5C0 and func_L39_004FC288 later, with BN_004FFBB0 */
extern void *func_L39_004FC5C0_004FF5A0(BN_004FF5A0 *, BN_004FF5A0 *);
extern s32 func_L39_004FC288_004FF5A0(BN_004FF5A0 *, s32);
extern s32 func_L39_004FBED8(void *, void *, s32, void *);
extern void *func_L39_004FC4B8(BN_004FF5A0 *, s32);
extern void func_L39_004FD0F8(UL_004FF5A0 *, UL_004FF5A0 *, s32, UL_004FF5A0 *, s32);
extern void func_L39_0050BEE0(UL_004FF5A0 *, UL_004FF5A0 *, UL_004FF5A0 *, s32, UL_004FF5A0);
extern void func_L39_0050BA58(UL_004FF5A0 *, UL_004FF5A0 *, s32, UL_004FF5A0 *);
extern void func_L39_004FC318(BN_004FF5A0 *);

s32 func_L39_004FF5A0(P_004FF5A0 *p, BN_004FF5A0 *r, BN_004FF5A0 *a, BN_004FF5A0 *e, Ctx_004FF5A0 *ctx) {
    UL_004FF5A0 *tbl[16];
    unsigned char *rec;
    s32 tos;
    s32 wbits;
    BN_004FF5A0 *aa;
    Mont_004FF5A0 *mont;
    Cb_004FF5A0 *cb;
    s32 ticks;
    BN_004FF5A0 *N;
    s32 n;
    s32 ret;
    BN_004FF5A0 *t;
    s32 i, c, z;
    UL_004FF5A0 *d, *tmp, *acc, *np;
    UL_004FF5A0 n0;

    ret = 0;
    mont = p->mont;
    N = &mont->N;
    cb = ctx->cb;
    n = mont->N.top;
    tos = ctx->tos;
    ticks = 0;

    if (a->top == n && a->d[n - 1] < N->d[n - 1]) {
        aa = a;
    } else if (a->top >= n) {
        aa = &ctx->bn[ctx->tos++];
        if (!func_L39_004FBED8(aa, a, (s32)N, ctx)) {
            goto err;
        }
    } else {
        aa = &ctx->bn[ctx->tos++];
        func_L39_004FC5C0_004FF5A0(aa, a);
    }
    func_L39_004FC288_004FF5A0(aa, n);

    if (e != 0) {
        if (func_L39_0050BB88((s32 *)e, (s32 *)&rec, 0, ctx) < 2) {
            goto err;
        }
        ctx->tos++;
    } else {
        if (p->rec == 0) {
            return 1;
        }
        rec = p->rec;
    }

    wbits = rec[3];
    rec += 4;
    t = &ctx->bn[ctx->tos++];
    if (r->dmax < n) {
        func_L39_004FC4B8(r, n);
    }
    if (t->dmax < n * (wbits + 6)) {
        func_L39_004FC4B8(t, n * (wbits + 6));
    }
    d = t->d;
    tmp = d + n * 2;
    acc = d + n * 4;
    tbl[0] = d + n * 6;
    np = mont->N.d;
    n0 = mont->n0;

    func_L39_004FD0F8(d, aa->d, n, mont->RR.d, n);
    func_L39_0050BEE0(tbl[0], d, np, n, n0);
    if (wbits > 1) {
        func_L39_0050BA58(d, tbl[0], n, tmp);
        func_L39_0050BEE0(tmp, d, np, n, n0);
        for (i = 1; i < wbits; i++) {
            tbl[i] = tbl[i - 1] + n;
            func_L39_004FD0F8(d, tbl[i - 1], n, tmp, n);
            func_L39_0050BEE0(tbl[i], d, np, n, n0);
        }
    }

    c = *rec++;
    z = *rec++;
    func_0011D380(acc, (s32)tbl[c >> 1], n * 8);
    if (z != 0) do {
        for (i = 0; i < z; i++) {
            func_L39_0050BA58(d, acc, n, tmp);
            func_L39_0050BEE0(acc, d, np, n, n0);
        }
        c = *rec++;
        z = *rec++;
        if (c == 0 && z == 0) {
            break;
        }
        if (z != 0 || c != 1) {
            func_L39_004FD0F8(d, acc, n, tbl[c >> 1], n);
            func_L39_0050BEE0(acc, d, np, n, n0);
            if (cb != 0) {
                ret = cb->fn(cb, 0xff, ticks++);
                if (ret != 0) {
                    goto err;
                }
            }
        } else {
            func_L39_004FD0F8(d, acc, n, aa->d, n);
            func_L39_0050BEE0(r->d, d, np, n, n0);
            goto done;
        }
    } while (z != 0);
    for (i = n; i < n * 2; i++) {
        acc[i] = 0;
    }
    func_L39_0050BEE0(r->d, acc, np, n, n0);
done:
    ret = 0;
    r->top = n;
    func_L39_004FC318(r);
err:
    if (cb != 0) {
        ret = cb->fn(cb, 0xff, -1);
        if (ret != 0) {
            goto err;
        }
    }
    ctx->tos = tos;
    return ret;
}
/* localdecomp:end func_L39_004FF5A0 */

/* localdecomp:start func_L39_004FFAF0 */
typedef struct { s32 v[5]; } S_004FFAF0_ent;
typedef struct { s32 n; S_004FFAF0_ent e[1]; } S_004FFAF0;
extern s32 func_L39_0050B8C8(void *, s32, void *);
extern s32 func_L39_004FCFD0(void *, s32, s32, void *);
extern s32 func_L39_004FBED8(void *, void *, s32, void *);

s32 func_L39_004FFAF0(void *a, s32 b, s32 c, s32 d, S_004FFAF0 *e) {
    s32 r = 0;
    S_004FFAF0_ent *slot = &e->e[e->n++];
    s32 ok;

    if (b == c) {
        ok = func_L39_0050B8C8(slot, c, e);
    } else {
        ok = func_L39_004FCFD0(slot, b, c, e);
    }
    if (ok) {
        r = func_L39_004FBED8(a, slot, d, e) != 0;
    }
    e->n--;
    return r;
}
/* localdecomp:end func_L39_004FFAF0 */

/* localdecomp:start func_L39_004FFBB0 */
typedef struct { unsigned long *d; s32 top; s32 dmax; s32 neg; s32 flags; } BN_004FFBB0;
typedef struct {
    s32 use_word;
    s32 f4;
    s32 ri;
    BN_004FFBB0 RR;
    BN_004FFBB0 N;
    char _p[0x48 - 0x34];
    unsigned long n0;
} Mont_004FFBB0;
extern void func_L39_004FC370(BN_004FFBB0 *);
extern void *func_L39_004FC5C0(BN_004FFBB0 *, BN_004FFBB0 *);
extern s32 func_L39_004FC158(BN_004FFBB0 *);
extern s32 func_L39_004FC6F8(BN_004FFBB0 *, unsigned long);
extern s32 func_L39_0050B140(BN_004FFBB0 *, s32);
extern unsigned long func_L39_0050AF60(unsigned long);
extern void *func_L39_004FCB28(BN_004FFBB0 *, BN_004FFBB0 *, s32);
extern s32 func_L39_004FD500(BN_004FFBB0 *, unsigned long);
extern unsigned long func_L39_004FFEE0(unsigned long, unsigned long, unsigned long);
extern void func_L39_004FC228(BN_004FFBB0 *);
extern s32 func_L39_004FC288(BN_004FFBB0 *, s32);

/* BN_MONT_CTX_set */
s32 func_L39_004FFBB0(Mont_004FFBB0 *mont, BN_004FFBB0 *mod, void *ctx) {
    BN_004FFBB0 Ri;
    BN_004FFBB0 *R;
    unsigned long d0;

    if (mod->top == 0) {
        return 0;
    }
    func_L39_004FC370(&Ri);
    func_L39_004FC5C0(&mont->N, mod);
    R = &mont->RR;
    mont->use_word = 1;
    mont->ri = (func_L39_004FC158(mod) + 63) / 64;
    func_L39_004FC6F8(R, 0);
    func_L39_0050B140(R, 64);
    d0 = mod->d[0];
    func_L39_004FC6F8(&Ri, func_L39_0050AF60(d0));
    func_L39_004FCB28(&Ri, &Ri, 64);
    if (!(Ri.top == 0 || (Ri.top == 1 && Ri.d[0] == 0))) {
        func_L39_004FD500(&Ri, 1);
    } else {
        func_L39_004FC6F8(&Ri, -1);
    }
    mont->n0 = func_L39_004FFEE0(Ri.top > 1 ? Ri.d[1] : 0, Ri.top > 0 ? Ri.d[0] : 0, d0);
    func_L39_004FC228(&Ri);
    func_L39_004FC6F8(R, 0);
    func_L39_0050B140(R, mont->ri * 2 * 64);
    func_L39_004FBED8(R, R, (s32)&mont->N, ctx);
    func_L39_004FC288(R, mont->ri);
    return 1;
}
/* localdecomp:end func_L39_004FFBB0 */

/* localdecomp:start func_L39_004FFD58 */
extern void *func_L39_004BEED8(s32 n);
extern s32 func_L39_004E4FC8(void *rng, unsigned char *buf, s32 n);
extern void *func_L39_004FC780(unsigned char *s, s32 len, void *ret);
extern void func_0011D534(void *, s32, s32);
extern void func_L39_004BEF28(void *p);

/* bnrand */
s32 func_L39_004FFD58(void *rnd, void *rng, s32 bits, s32 top, s32 bottom) {
    unsigned char *buf;
    s32 ret = 0, bit, bytes, mask;

    bytes = (bits + 7) / 8;
    bit = (bits - 1) % 8;
    mask = 0xff << bit;

    buf = func_L39_004BEED8(bytes + 1);
    if (buf == 0) {
        goto err;
    }
    func_L39_004E4FC8(rng, buf, bytes + 1);
    if (top) {
        if (bit == 0) {
            buf[0] = 1;
            if (bytes > 1) {
                buf[1] |= 0x80;
            }
        } else {
            buf[0] |= (3 << (bit - 1));
            buf[0] &= ~(mask << 1);
        }
    } else {
        buf[0] |= (1 << bit);
        buf[0] &= ~(mask << 1);
    }
    if (bottom) {
        buf[bytes - 1] |= 1;
    }
    ret = func_L39_004FC780(buf, bytes, rnd) != 0;
    func_0011D534(buf, 0, bytes);
    func_L39_004BEF28(buf);
err:
    return ret;
}
/* localdecomp:end func_L39_004FFD58 */

/* localdecomp:start func_L39_004FFEE0 */
extern s32 func_L39_0050B060(unsigned long);

/* BN_div_words (OpenSSL bn_asm.c, BN_ULONG 64 bits) */
unsigned long func_L39_004FFEE0(unsigned long h, unsigned long l, unsigned long d) {
    unsigned long dh, dl, q, ret = 0, th, tl, mask, t;
    s32 i, count = 2;

    if (d == 0)
        return -1;
    i = func_L39_0050B060(d);
    if (i != 64 && (1UL << i) < h)
        return 0;
    i = 64 - i;
    if (h >= d)
        h -= d;
    if (i) {
        d <<= i;
        h = (h << i) | (l >> (64 - i));
        l <<= i;
    }
    dh = d >> 32;
    dl = d & 0xFFFFFFFFUL;
    for (;;) {
        if ((h >> 32) == dh)
            q = 0xFFFFFFFFUL;
        else
            q = h / dh;
        for (;;) {
            th = q * dh;
            t = h - th;
            if ((t & 0xFFFFFFFF00000000UL) || dl * q <= ((t << 32) + ((l >> 32) & 0xFFFFFFFFUL)))
                break;
            q--;
        }
        tl = q * dl;
        t = tl >> 32;
        tl = tl << 32;
        th += t;
        if (l < tl)
            th++;
        mask = 0xFFFFFFFFUL;
        l -= tl;
        if (h < th) {
            h += d;
            q--;
        }
        h -= th;
        if (--count == 0)
            break;
        ret = (q & mask) << 32;
        h = (h << 32) | (l >> 32);
        l = (l & mask) << 32;
    }
    ret |= q;
    return ret;
}
/* localdecomp:end func_L39_004FFEE0 */

LINKER_REMNANT("asm/levels", func_L39_005000C0);

