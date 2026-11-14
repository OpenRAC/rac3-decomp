#include "common.h"

/* localdecomp:start func_L39_0050A5E8 */
typedef struct S_0050A5E8 {
    s32 len;
    s32 f4;
    void *data;
} S_0050A5E8;

extern s32 func_0011D2EC(void *, void *, s32);

s32 func_L39_0050A5E8(S_0050A5E8 *a, S_0050A5E8 *b) {
    s32 r;

    r = a->len - b->len;
    if (r == 0) {
        r = func_0011D2EC(a->data, b->data, a->len);
        if (r == 0) {
            r = a->f4 - b->f4;
        }
    }
    return r;
}
/* localdecomp:end func_L39_0050A5E8 */

/* localdecomp:start func_L39_0050A648 */
/* log: i2d of a two-field SEQUENCE (OpenSSL ASN1 style) */
extern s32 func_L39_004F97C0(void *, u8 **);
extern s32 func_L39_00515FC0(void *, u8 **);
extern s32 func_L39_004FA1A0(s32, s32, s32);
extern void func_L39_004F9FF8(u8 **, s32, s32, s32, s32);

typedef struct {
    void *f0;
    void *f4;
    void *f8;
} S_0050A648;

s32 func_L39_0050A648(S_0050A648 *a, u8 **pp) {
    s32 len;
    s32 ret;
    u8 *p;

    if (a == 0) {
        return 0;
    }
    len = func_L39_004F97C0(a->f4, 0);
    len += func_L39_00515FC0(a->f8, 0);
    ret = func_L39_004FA1A0(1, len, 16);
    if (pp == 0) {
        return ret;
    }
    p = *pp;
    func_L39_004F9FF8(&p, 1, len, 16, 0);
    func_L39_004F97C0(a->f4, &p);
    func_L39_00515FC0(a->f8, &p);
    *pp = p;
    return ret;
}
/* localdecomp:end func_L39_0050A648 */

INCLUDE_ASM("asm/levels", func_L39_0050A70C);

INCLUDE_ASM("asm/levels", func_L39_0050A8CC);

INCLUDE_ASM("asm/levels", func_L39_0050A8D8);

/* localdecomp:start func_L39_0050AF60 */
u64 func_L39_0050AF60(u64 n) {
    u64 A, B, X, Y, D, M, T;
    s32 sign;

    Y = 0;
    A = n;
    X = 1;
    B = (0 - n) % n;
    sign = -1;
    while (B != 0) {
        sign = -sign;
        D = A / B;
        M = A % B;
        A = B;
        T = D * X + Y;
        B = M;
        Y = X;
        X = T;
    }
    if (sign < 0) {
        Y = n - Y;
    }
    if (A == 1) {
        return Y % n;
    }
    return 0;
}
/* localdecomp:end func_L39_0050AF60 */
