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

INCLUDE_ASM("asm/levels", func_L39_004FF4A0);

INCLUDE_ASM("asm/levels", func_L39_004FF5A0);

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

INCLUDE_ASM("asm/levels", func_L39_005000BC);
