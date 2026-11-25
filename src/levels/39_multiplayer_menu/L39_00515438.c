#include "common.h"

/* localdecomp:start func_L39_00515438 */
typedef struct { s32 cap; s32 n; unsigned long *d; } S_00515438;
extern unsigned long func_001306F8(unsigned long, unsigned long);
void func_L39_00515438(S_00515438 *a, S_00515438 *b) {
    unsigned long c;
    s32 i;
    s32 k;
    unsigned long *r;
    unsigned long *ad;
    unsigned long *ap;
    unsigned long *rp;
    unsigned long x, lo, hi, l, h, m, m2;
    c = 0;
    i = 0;
    r = b->d;
    ad = a->d;
    k = 0;
    if (a->n > 0) {
        ap = ad;
        rp = r;
        do {
            x = *ap++;
            lo = x & 0xFFFFFFFFUL;
            hi = x >> 32;
            k += 2;
            l = func_001306F8(lo, lo);
            h = func_001306F8(hi, hi);
            m = func_001306F8(lo, hi);
            m2 = m << 1;
            if (m2 < m) h += (unsigned long)1 << 32;
            h += m2 >> 32;
            m2 <<= 32;
            l += m2;
            h += l < m2;
            l += rp[0];
            h += l < rp[0];
            l += c;
            h += l < c;
            rp[0] = l;
            i++;
            h += rp[1];
            c = h < rp[1];
            rp[1] = h;
            rp += 2;
        } while (i < a->n);
    }
    if (c) {
        while (r[k] == (unsigned long)-1) {
            r[k] = 0;
            k++;
        }
        r[k]++;
    }
}
/* localdecomp:end func_L39_00515438 */

/* localdecomp:start func_L39_005155E8 */
typedef struct { u8 *s; s32 len; } S_005155E8;
extern s32 func_L39_004F60D8(void *, void *, u8 *, s32);

s32 func_L39_005155E8(u8 *dst, u8 *src, u8 *base, u8 **fields, u32 n, void *ctx) {
    u32 i;
    s32 r;
    for (i = 0; i < n; i++) {
        s32 off = fields[i] - base;
        S_005155E8 t = *(S_005155E8 *)(src + off);
        S_005155E8 *d = (S_005155E8 *)(dst + off);
        while (t.len != 0 && *t.s == 0) {
            t.len--;
            t.s++;
        }
        d->len = t.len;
        r = func_L39_004F60D8(ctx, d, t.s, t.len);
        if (r != 0) return r;
    }
    return 0;
}
/* localdecomp:end func_L39_005155E8 */

LINKER_REMNANT("asm/levels", func_L39_005156F8);

/* localdecomp:start func_L39_00515708 */
typedef struct {
    s32 f0, f4, f8, fC, f10, f14;
    s32 a[4], b[4], c[4];
} P_00515708;
typedef struct {
    s32 f0, f4, f8, fC, f10, f14;
    s32 f18;
    s32 *f1C, *f20, *f24;
} S_00515708;
extern s32 func_L39_00515778(void *, S_00515708 *);
void func_L39_00515708(void *a, P_00515708 *p) {
    S_00515708 t;
    s32 *pa = p->a;
    s32 *pb = p->b;
    s32 *pc = p->c;
    t.f0 = p->f0;
    t.f4 = p->f4;
    t.f8 = p->f8;
    t.fC = p->fC;
    t.f10 = p->f10;
    t.f14 = p->f14;
    t.f18 = 2;
    t.f1C = pa;
    t.f20 = pb;
    t.f24 = pc;
    func_L39_00515778(a, &t);
}
/* localdecomp:end func_L39_00515708 */

/* localdecomp:start func_L39_00515778 */
typedef struct { u8 *s; s32 len; } E_00515778;
typedef struct {
    E_00515778 f0, f8, f10;
    s32 f18;
    E_00515778 *f1C, *f20, *f24;
} K_00515778;
extern void *func_L39_004F7590(s32);
extern void func_L39_004F7620(void *);
extern s32 func_L39_004F6060(void *, void *, s32);
extern s32 func_L39_004F5EA0(void *, void *, void *);
extern u8 D_L39_0046F468[];

s32 func_L39_00515778(void *ctx, S_00515708 *arg) {
    K_00515778 *s = (K_00515778 *)arg;
    K_00515778 *p = 0;
    E_00515778 **a;
    E_00515778 **b = 0;
    s32 r;
    s32 n = s->f18 * 3 + 2;
    s32 i, j, off;

    while ((r = 0x206, (a = func_L39_004F7590(n * 4)) != 0) && (b = func_L39_004F7590(n * 4)) != 0
           && (r = func_L39_004F6060(ctx, &p, 0x28)) == 0) {
        if ((r = func_L39_004F6060(ctx, &p->f1C, s->f18 * 8)) != 0) break;
        if ((r = func_L39_004F6060(ctx, &p->f20, s->f18 * 8)) != 0) break;
        if ((r = func_L39_004F6060(ctx, &p->f24, (s->f18 - 1) << 3)) != 0) break;
        a[0] = &s->f0;
        a[1] = &s->f8;
        a[2] = &s->f10;
        b[0] = &p->f0;
        b[1] = &p->f8;
        b[2] = &p->f10;
        i = 3;
        j = 0;
        for (;;) {
            off = j * 8;
            a[i] = (E_00515778 *)((u8 *)s->f1C + off);
            b[i] = (E_00515778 *)((u8 *)p->f1C + off);
            a[i + s->f18] = (E_00515778 *)((u8 *)s->f20 + off);
            b[i + s->f18] = (E_00515778 *)((u8 *)p->f20 + off);
            if (j == s->f18 - 1) break;
            a[s->f18 * 2 + i] = (E_00515778 *)((u8 *)s->f24 + off);
            b[s->f18 * 2 + i] = (E_00515778 *)((u8 *)p->f24 + off);
            i++;
            j++;
        }
        p->f18 = s->f18;
        for (i = 0; i < n; i++) {
            if ((r = func_L39_005155E8((u8 *)b[i], (u8 *)a[i], (u8 *)a[0], (u8 **)a, 1, ctx)) != 0) break;
        }
        break;
    }
    func_L39_004F7620(a);
    func_L39_004F7620(b);
    if (r != 0) return r;
    return func_L39_004F5EA0(ctx, D_L39_0046F468, p);
}
/* localdecomp:end func_L39_00515778 */
