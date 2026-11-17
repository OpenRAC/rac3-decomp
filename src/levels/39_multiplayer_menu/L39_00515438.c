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

INCLUDE_ASM("asm/levels", func_L39_005155E8);

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

INCLUDE_ASM("asm/levels", func_L39_00515778);
