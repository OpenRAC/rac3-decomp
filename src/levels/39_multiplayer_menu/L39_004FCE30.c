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

INCLUDE_ASM("asm/levels", func_L39_004FCF40);

INCLUDE_ASM("asm/levels", func_L39_004FCF88);

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

INCLUDE_ASM("asm/levels", func_L39_004FD710);

INCLUDE_ASM("asm/levels", func_L39_004FDA88);

INCLUDE_ASM("asm/levels", func_L39_004FDDF0);

INCLUDE_ASM("asm/levels", func_L39_004FE020);
