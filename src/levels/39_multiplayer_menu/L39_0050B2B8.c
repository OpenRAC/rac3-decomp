#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0050B2B8);

INCLUDE_ASM("asm/levels", func_L39_0050B4C0);

INCLUDE_ASM("asm/levels", func_L39_0050B6F0);

/* localdecomp:start func_L39_0050B748 */
typedef struct BN_0050B748 {
    unsigned long *d;
    s32 top;
    s32 dmax;
    s32 neg;
} BN_0050B748;
extern s32 func_L39_004FC6F8(BN_0050B748 *, unsigned long);
extern BN_0050B748 *func_L39_004FC4B8(BN_0050B748 *, s32);
extern void func_L39_004FC318(void *);

/* BN_rshift (OpenSSL 0.9.x bn_shift.c) */
s32 func_L39_0050B748(BN_0050B748 *r, BN_0050B748 *a, s32 n) {
    s32 i, j, nw, lb, rb;
    unsigned long *t, *f;
    unsigned long l, tmp;

    nw = n / 64;
    rb = n % 64;
    lb = 64 - rb;
    if (nw > a->top) {
        func_L39_004FC6F8(r, 0);
        return 1;
    }
    if (r != a) {
        if (((a->top - nw + 2 <= r->dmax) ? r : func_L39_004FC4B8(r, a->top - nw + 2)) == 0) {
            return 0;
        }
        r->neg = a->neg;
    }
    f = &a->d[nw];
    t = r->d;
    j = a->top - nw;
    r->top = j;
    if (rb == 0) {
        for (i = j + 1; i > 0; i--) {
            *(t++) = *(f++);
        }
    } else {
        l = *(f++);
        for (i = 1; i < j; i++) {
            tmp = l >> rb;
            l = *(f++);
            *(t++) = tmp | (l << lb);
        }
        *(t++) = l >> rb;
        *t = 0;
    }
    func_L39_004FC318(r);
    return 1;
}
/* localdecomp:end func_L39_0050B748 */

INCLUDE_ASM("asm/levels", func_L39_0050B8C8);

INCLUDE_ASM("asm/levels", func_L39_0050BA58);

INCLUDE_ASM("asm/levels", func_L39_0050BB88);

INCLUDE_ASM("asm/levels", func_L39_0050BD10);

INCLUDE_ASM("asm/levels", func_L39_0050BEE0);

INCLUDE_ASM("asm/levels", func_L39_0050C0B4);

INCLUDE_ASM("asm/levels", func_L39_0050C110);

INCLUDE_ASM("asm/levels", func_L39_0050C20C);
