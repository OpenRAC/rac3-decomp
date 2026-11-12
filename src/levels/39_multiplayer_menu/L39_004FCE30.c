#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

/* declared by functions of L39_004FB668.c, which this file was cut from */
extern void *func_L39_004BEED8(s32);

/* localdecomp:start func_L39_004FCE30 */
typedef struct {
    unsigned long *d;
    s32 top;
} BN_004FCE30;
typedef struct X_004FCE30 X_004FCE30;
typedef struct {
    char _p0[0xC];
    s32 (*f0C)(X_004FCE30 *, BN_004FCE30 *, BN_004FCE30 *, BN_004FCE30 *, s32);
} XMeth_004FCE30;
struct X_004FCE30 {
    XMeth_004FCE30 *meth;
};

extern s32 func_L39_004FC6F8(BN_004FCE30 *, unsigned long);
extern BN_004FCE30 *func_L39_004FC5C0(BN_004FCE30 *, BN_004FCE30 *);
extern void func_L39_004FC288(BN_004FCE30 *, s32);

s32 func_L39_004FCE30(X_004FCE30 *x, BN_004FCE30 *r, BN_004FCE30 *a, BN_004FCE30 *p, s32 a4, s32 a5) {
    if (a->top == 0 || (a->top == 1 && a->d[0] == 0)) {
        func_L39_004FC6F8(r, 0);
        return 0;
    }
    if (p != 0) {
        if (p->top == 0 || (p->top == 1 && p->d[0] == 0)) {
            func_L39_004FC6F8(r, 1);
            return 0;
        }
        if (p->top == 1 && p->d[0] == 1) {
            func_L39_004FC5C0(r, a);
            return 0;
        }
    }
    func_L39_004FC288(a, *(s32 *)x->meth);
    return x->meth->f0C(x, r, a, p, a5);
}
/* localdecomp:end func_L39_004FCE30 */

/* localdecomp:start func_L39_004FCF40 */
extern void *func_L39_004BEED8(s32);
extern void func_L39_004FCF88(void *);
typedef struct S_004FCF40 { char _p[0x50]; s32 f50; } S_004FCF40;
S_004FCF40 *func_L39_004FCF40(void) {
    S_004FCF40 *p = func_L39_004BEED8(0x58);
    if (p == 0) {
        return 0;
    }
    func_L39_004FCF88(p);
    p->f50 = 1;
    return p;
}
/* localdecomp:end func_L39_004FCF40 */

/* localdecomp:start func_L39_004FCF88 */
typedef struct { s32 f0; s32 f4; s32 f8; char _c[0x44]; s32 f50; } S_004FCF88;
extern void func_L39_004FC370(void *);
void func_L39_004FCF88(void *arg0) {
    S_004FCF88 *p = arg0;
    p->f0 = 0;
    p->f8 = 0;
    func_L39_004FC370((char *)p + 0xC);
    func_L39_004FC370((char *)p + 0x20);
    func_L39_004FC370((char *)p + 0x34);
    p->f50 = 0;
}
/* localdecomp:end func_L39_004FCF88 */

INCLUDE_ASM("asm/levels", func_L39_004FCFD0);

/* localdecomp:start func_L39_004FD0F8 */
extern unsigned long func_L39_004FDA88(unsigned long *, unsigned long *, s32, unsigned long);
extern unsigned long func_L39_004FD710(unsigned long *, unsigned long *, s32, unsigned long);

/* OpenSSL bn_mul_normal */
void func_L39_004FD0F8(unsigned long *r, unsigned long *a, s32 na, unsigned long *b, s32 nb) {
    unsigned long *rr;

    if (na < nb) {
        s32 itmp;
        unsigned long *ltmp;

        itmp = na;
        na = nb;
        nb = itmp;
        ltmp = a;
        a = b;
        b = ltmp;
    }
    rr = &r[na];
    rr[0] = func_L39_004FDA88(r, a, na, b[0]);
    for (;;) {
        if (--nb <= 0) return;
        rr[1] = func_L39_004FD710(&r[1], a, na, b[1]);
        if (--nb <= 0) return;
        rr[2] = func_L39_004FD710(&r[2], a, na, b[2]);
        if (--nb <= 0) return;
        rr[3] = func_L39_004FD710(&r[3], a, na, b[3]);
        if (--nb <= 0) return;
        rr[4] = func_L39_004FD710(&r[4], a, na, b[4]);
        rr += 4;
        r += 4;
        b += 4;
    }
}
/* localdecomp:end func_L39_004FD0F8 */

INCLUDE_ASM("asm/levels", func_L39_004FD228);

INCLUDE_ASM("asm/levels", func_L39_004FD2D0);

INCLUDE_ASM("asm/levels", func_L39_004FD3B0);

INCLUDE_ASM("asm/levels", func_L39_004FD500);

INCLUDE_ASM("asm/levels", func_L39_004FD678);

/* localdecomp:start func_L39_004FD710 */
/* OpenSSL bn_mul_add_words (mul_add/mul64, 64-bit BN_ULONG) */
unsigned long func_L39_004FD710(unsigned long *r, unsigned long *a, s32 num, unsigned long w) {
    unsigned long carry = 0;
    unsigned long bl, bh;
    if (num <= 0) return carry;
    bl = w & 0xffffffffUL;
    bh = (w >> 32) & 0xffffffffUL;
    for (;;) {
        {
            unsigned long l, h;
            unsigned long m, m1, lt, ht;
            h = a[0]; l = h & 0xffffffffUL; h = (h >> 32) & 0xffffffffUL;
            lt = l; ht = h;
            m = bh * lt;
            lt = bl * lt;
            m1 = bl * ht;
            ht = bh * ht;
            m = m + m1; if (m < m1) ht += 0x100000000UL;
            ht += (m >> 32) & 0xffffffffUL;
            m1 = (m & 0xffffffffUL) << 32;
            lt = lt + m1; if (lt < m1) ht++;
            l = lt; h = ht;
            l = l + carry; if (l < carry) h++;
            carry = r[0]; l = l + carry; if (l < carry) h++;
            carry = h;
            r[0] = l;
        }
        if (--num == 0) break;
        {
            unsigned long l, h;
            unsigned long m, m1, lt, ht;
            h = a[1]; l = h & 0xffffffffUL; h = (h >> 32) & 0xffffffffUL;
            lt = l; ht = h;
            m = bh * lt;
            lt = bl * lt;
            m1 = bl * ht;
            ht = bh * ht;
            m = m + m1; if (m < m1) ht += 0x100000000UL;
            ht += (m >> 32) & 0xffffffffUL;
            m1 = (m & 0xffffffffUL) << 32;
            lt = lt + m1; if (lt < m1) ht++;
            l = lt; h = ht;
            l = l + carry; if (l < carry) h++;
            carry = r[1]; l = l + carry; if (l < carry) h++;
            carry = h;
            r[1] = l;
        }
        if (--num == 0) break;
        {
            unsigned long l, h;
            unsigned long m, m1, lt, ht;
            h = a[2]; l = h & 0xffffffffUL; h = (h >> 32) & 0xffffffffUL;
            lt = l; ht = h;
            m = bh * lt;
            lt = bl * lt;
            m1 = bl * ht;
            ht = bh * ht;
            m = m + m1; if (m < m1) ht += 0x100000000UL;
            ht += (m >> 32) & 0xffffffffUL;
            m1 = (m & 0xffffffffUL) << 32;
            lt = lt + m1; if (lt < m1) ht++;
            l = lt; h = ht;
            l = l + carry; if (l < carry) h++;
            carry = r[2]; l = l + carry; if (l < carry) h++;
            carry = h;
            r[2] = l;
        }
        if (--num == 0) break;
        {
            unsigned long l, h;
            unsigned long m, m1, lt, ht;
            h = a[3]; l = h & 0xffffffffUL; h = (h >> 32) & 0xffffffffUL;
            lt = l; ht = h;
            m = bh * lt;
            lt = bl * lt;
            m1 = bl * ht;
            ht = bh * ht;
            m = m + m1; if (m < m1) ht += 0x100000000UL;
            ht += (m >> 32) & 0xffffffffUL;
            m1 = (m & 0xffffffffUL) << 32;
            lt = lt + m1; if (lt < m1) ht++;
            l = lt; h = ht;
            l = l + carry; if (l < carry) h++;
            carry = r[3]; l = l + carry; if (l < carry) h++;
            carry = h;
            r[3] = l;
        }
        if (--num == 0) break;
        a += 4; r += 4;
    }
    return carry;
}
/* localdecomp:end func_L39_004FD710 */

/* localdecomp:start func_L39_004FDA88 */
/* OpenSSL bn_mul_words (mul/mul64, 64-bit BN_ULONG) */
unsigned long func_L39_004FDA88(unsigned long *r, unsigned long *a, s32 num, unsigned long w) {
    unsigned long carry = 0;
    unsigned long bl, bh;
    if (num <= 0) return carry;
    bl = w & 0xffffffffUL;
    bh = (w >> 32) & 0xffffffffUL;
    for (;;) {
        {
            unsigned long l, h;
            unsigned long m, m1, lt, ht;
            h = a[0]; l = h & 0xffffffffUL; h = (h >> 32) & 0xffffffffUL;
            lt = l; ht = h;
            m = bh * lt;
            lt = bl * lt;
            m1 = bl * ht;
            ht = bh * ht;
            m = m + m1; if (m < m1) ht += 0x100000000UL;
            ht += (m >> 32) & 0xffffffffUL;
            m1 = (m & 0xffffffffUL) << 32;
            lt = lt + m1; if (lt < m1) ht++;
            l = lt; h = ht;
            l += carry; if (l < carry) h++;
            carry = h;
            r[0] = l;
        }
        if (--num == 0) break;
        {
            unsigned long l, h;
            unsigned long m, m1, lt, ht;
            h = a[1]; l = h & 0xffffffffUL; h = (h >> 32) & 0xffffffffUL;
            lt = l; ht = h;
            m = bh * lt;
            lt = bl * lt;
            m1 = bl * ht;
            ht = bh * ht;
            m = m + m1; if (m < m1) ht += 0x100000000UL;
            ht += (m >> 32) & 0xffffffffUL;
            m1 = (m & 0xffffffffUL) << 32;
            lt = lt + m1; if (lt < m1) ht++;
            l = lt; h = ht;
            l += carry; if (l < carry) h++;
            carry = h;
            r[1] = l;
        }
        if (--num == 0) break;
        {
            unsigned long l, h;
            unsigned long m, m1, lt, ht;
            h = a[2]; l = h & 0xffffffffUL; h = (h >> 32) & 0xffffffffUL;
            lt = l; ht = h;
            m = bh * lt;
            lt = bl * lt;
            m1 = bl * ht;
            ht = bh * ht;
            m = m + m1; if (m < m1) ht += 0x100000000UL;
            ht += (m >> 32) & 0xffffffffUL;
            m1 = (m & 0xffffffffUL) << 32;
            lt = lt + m1; if (lt < m1) ht++;
            l = lt; h = ht;
            l += carry; if (l < carry) h++;
            carry = h;
            r[2] = l;
        }
        if (--num == 0) break;
        {
            unsigned long l, h;
            unsigned long m, m1, lt, ht;
            h = a[3]; l = h & 0xffffffffUL; h = (h >> 32) & 0xffffffffUL;
            lt = l; ht = h;
            m = bh * lt;
            lt = bl * lt;
            m1 = bl * ht;
            ht = bh * ht;
            m = m + m1; if (m < m1) ht += 0x100000000UL;
            ht += (m >> 32) & 0xffffffffUL;
            m1 = (m & 0xffffffffUL) << 32;
            lt = lt + m1; if (lt < m1) ht++;
            l = lt; h = ht;
            l += carry; if (l < carry) h++;
            carry = h;
            r[3] = l;
        }
        if (--num == 0) break;
        a += 4; r += 4;
    }
    return carry;
}
/* localdecomp:end func_L39_004FDA88 */

/* localdecomp:start func_L39_004FDDF0 */
/* OpenSSL bn_sqr_words (sqr64 per block, block-local temporaries) */
void func_L39_004FDDF0(unsigned long *r, unsigned long *a, s32 n) {
    if (n <= 0) return;
    for (;;) {
        {
            unsigned long l, h, m;
            h = a[0]; l = h & 0xffffffffUL; h = (h >> 32) & 0xffffffffUL; m = l * h; l *= l; h *= h;
            h += (m & 0xffffffff80000000UL) >> 31;
            m = (m & 0xffffffffUL) << 33;
            l = l + m; if (l < m) h++;
            r[0] = l; r[1] = h;
        }
        if (--n == 0) break;
        {
            unsigned long l, h, m;
            h = a[1]; l = h & 0xffffffffUL; h = (h >> 32) & 0xffffffffUL; m = l * h; l *= l; h *= h;
            h += (m & 0xffffffff80000000UL) >> 31;
            m = (m & 0xffffffffUL) << 33;
            l = l + m; if (l < m) h++;
            r[2] = l; r[3] = h;
        }
        if (--n == 0) break;
        {
            unsigned long l, h, m;
            h = a[2]; l = h & 0xffffffffUL; h = (h >> 32) & 0xffffffffUL; m = l * h; l *= l; h *= h;
            h += (m & 0xffffffff80000000UL) >> 31;
            m = (m & 0xffffffffUL) << 33;
            l = l + m; if (l < m) h++;
            r[4] = l; r[5] = h;
        }
        if (--n == 0) break;
        {
            unsigned long l, h, m;
            h = a[3]; l = h & 0xffffffffUL; h = (h >> 32) & 0xffffffffUL; m = l * h; l *= l; h *= h;
            h += (m & 0xffffffff80000000UL) >> 31;
            m = (m & 0xffffffffUL) << 33;
            l = l + m; if (l < m) h++;
            r[6] = l; r[7] = h;
        }
        if (--n == 0) break;
        a += 4; r += 8;
    }
}
/* localdecomp:end func_L39_004FDDF0 */

INCLUDE_ASM("asm/levels", func_L39_004FE020);
