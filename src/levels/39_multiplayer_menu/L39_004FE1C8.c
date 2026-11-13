#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

/* localdecomp:start func_L39_004FE1C8 */
typedef struct { u8 b[16]; } V16_4FE1C8;
extern s32 D_L39_0046EA54 __attribute__((section(".data")));
extern V16_4FE1C8 D_L39_00453B48[];
s32 func_L39_004FE1C8(s32 idx) {
    s32 n = D_L39_0046EA54;
    s32 i;
    if (idx < n) {
        for (i = idx; i + 1 < n; i++) {
            D_L39_00453B48[i] = (D_L39_00453B48 + 1)[i];
        }
        D_L39_0046EA54--;
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L39_004FE1C8 */

/* localdecomp:start func_L39_004FE250 */
s32 func_L39_004FE250(s32 a, s32 b, s32 c, s32 d, s32 pos) {
    s32 i;

    if (D_L39_0046EA54 >= 32) {
        return 1;
    }
    i = D_L39_0046EA54;
    while (pos < i) {
        D_L39_00453B48[i] = (D_L39_00453B48 - 1)[i];
        i--;
    }
    ((s32 *)&D_L39_00453B48[i])[0] = a;
    ((s32 *)&D_L39_00453B48[i])[1] = b;
    ((s32 *)&D_L39_00453B48[i])[2] = c;
    ((s32 *)&D_L39_00453B48[i])[3] = d;
    D_L39_0046EA54++;
    return 0;
}
/* localdecomp:end func_L39_004FE250 */

LINKER_REMNANT("asm/levels", func_L39_004FE320);

INCLUDE_ASM("asm/levels", func_L39_004FE328);

INCLUDE_ASM("asm/levels", func_L39_004FE608);

/* localdecomp:start func_L39_004FE6B0 */
typedef struct S_004FE6B0 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} S_004FE6B0;
extern s32 func_L39_004FE328(s32, s32, s32, s32);

s32 func_L39_004FE6B0(S_004FE6B0 *a0)
{
    s32 i = 0;

    while (a0[i].f0 != 0) {
        func_L39_004FE328(a0[i].f0, a0[i].f4, a0[i].f8, a0[i].fC);
        i++;
    }
    return 0;
}
/* localdecomp:end func_L39_004FE6B0 */

/* localdecomp:start func_L39_004FE728 */
typedef struct BN_004FE728 {
    unsigned long *d;
    s32 top;
    s32 max;
    s32 neg;
    s32 flags;
} BN_004FE728;

typedef struct CTX_004FE728 {
    s32 tos;
    BN_004FE728 bn[1];
} CTX_004FE728;

typedef struct MONT_004FE728 {
    s32 f0;
    s32 f4;
    s32 f8;
    BN_004FE728 rr;
} MONT_004FE728;

extern s32 func_L39_004FC158(BN_004FE728 *);
extern s32 func_L39_004FC6F8(BN_004FE728 *, unsigned long);
extern MONT_004FE728 *func_L39_004FCF40(void);
extern s32 func_L39_004FFBB0(MONT_004FE728 *, BN_004FE728 *, CTX_004FE728 *);
extern void func_L39_004FC370(BN_004FE728 *);
extern s32 func_L39_004FC960(BN_004FE728 *, BN_004FE728 *);
extern s32 func_L39_004FBED8(BN_004FE728 *, BN_004FE728 *, BN_004FE728 *, CTX_004FE728 *);
extern s32 func_L39_0050B2B8(BN_004FE728 *, BN_004FE728 *, BN_004FE728 *, MONT_004FE728 *, CTX_004FE728 *);
extern BN_004FE728 *func_L39_0050B050(void);
extern s32 func_L39_0050B258(BN_004FE728 *, s32);
extern s32 func_L39_0050B4C0(BN_004FE728 *, BN_004FE728 *, MONT_004FE728 *, CTX_004FE728 *);
extern void func_L39_0050B6F0(MONT_004FE728 *);
extern void func_L39_004FC1A0(BN_004FE728 *);

/* from OpenSSL 0.9.x crypto/bn/bn_exp2.c, BN_mod_exp2_mont */
s32 func_L39_004FE728(BN_004FE728 *rr, BN_004FE728 *a1, BN_004FE728 *p1, BN_004FE728 *a2, BN_004FE728 *p2,
                      BN_004FE728 *m, CTX_004FE728 *ctx, MONT_004FE728 *in_mont) {
    s32 i, j, k, bits, bits1, bits2, ret = 0, wstart, wend, window, xvalue, yvalue;
    s32 start = 1, ts = 0, x, y, size;
    BN_004FE728 *d, *aa1, *aa2, *r;
    BN_004FE728 val[4][4];
    MONT_004FE728 *mont = 0;

    if (!(m->d[0] & 1)) {
        return 0;
    }
    d = &ctx->bn[ctx->tos++];
    r = &ctx->bn[ctx->tos++];
    bits1 = func_L39_004FC158(p1);
    bits2 = func_L39_004FC158(p2);
    if (bits1 == 0 && bits2 == 0) {
        func_L39_004FC6F8(r, 1);
        return 1;
    }
    bits = (bits1 > bits2) ? bits1 : bits2;

    if (in_mont != 0) {
        mont = in_mont;
    } else {
        if ((mont = func_L39_004FCF40()) == 0) goto err;
        if (!func_L39_004FFBB0(mont, m, ctx)) goto err;
    }

    func_L39_004FC370(&val[0][0]);
    func_L39_004FC370(&val[1][1]);
    func_L39_004FC370(&val[0][1]);
    func_L39_004FC370(&val[1][0]);
    ts = 1;
    if (func_L39_004FC960(a1, m) >= 0) {
        func_L39_004FBED8(&val[1][0], a1, m, ctx);
        aa1 = &val[1][0];
    } else {
        aa1 = a1;
    }
    if (func_L39_004FC960(a2, m) >= 0) {
        func_L39_004FBED8(&val[0][1], a2, m, ctx);
        aa2 = &val[0][1];
    } else {
        aa2 = a2;
    }
    if (!func_L39_0050B2B8(&val[1][0], aa1, &mont->rr, mont, ctx)) goto err;
    if (!func_L39_0050B2B8(&val[0][1], aa2, &mont->rr, mont, ctx)) goto err;
    if (!func_L39_0050B2B8(&val[1][1], &val[1][0], &val[0][1], mont, ctx)) goto err;

    size = 4;
    for (x = 0; x < size; x++) {
        if (x >= 2) {
            func_L39_004FC370(&val[x][0]);
            func_L39_004FC370(&val[x][1]);
            if (!func_L39_0050B2B8(&val[x][0], &val[1][0], &val[x - 1][0], mont, ctx)) goto err;
            if (!func_L39_0050B2B8(&val[x][1], &val[1][0], &val[x - 1][1], mont, ctx)) goto err;
        }
        for (y = 2; y < size; y++) {
            func_L39_004FC370(&val[x][y]);
            if (!func_L39_0050B2B8(&val[x][y], &val[x][y - 1], &val[0][1], mont, ctx)) goto err;
        }
    }
    ts = size;

    start = 1;
    wstart = bits - 1;
    wend = 0;
    if (!func_L39_0050B2B8(r, func_L39_0050B050(), &mont->rr, mont, ctx)) goto err;

    for (;;) {
        xvalue = func_L39_0050B258(p1, wstart);
        yvalue = func_L39_0050B258(p2, wstart);
        if (!(xvalue || yvalue)) {
            if (!start) {
                if (!func_L39_0050B2B8(r, r, r, mont, ctx)) goto err;
            }
            wstart--;
            if (wstart < 0) break;
            continue;
        }

        j = wstart;
        wend = 0;
        for (i = 1; i < 2; i++) {
            if (wstart - i < 0) break;
            xvalue += xvalue;
            xvalue |= func_L39_0050B258(p1, wstart - i);
            yvalue += yvalue;
            yvalue |= func_L39_0050B258(p2, wstart - i);
        }

        if (!start) {
            for (j = 0; j < i; j++) {
                if (!func_L39_0050B2B8(r, r, r, mont, ctx)) goto err;
            }
        }

        if (xvalue || yvalue) {
            if (!func_L39_0050B2B8(r, r, &val[xvalue][yvalue], mont, ctx)) goto err;
        }

        wstart -= i;
        start = 0;
        if (wstart < 0) break;
    }
    func_L39_0050B4C0(rr, r, mont, ctx);
    ret = 1;
err:
    if (in_mont == 0 && mont != 0) func_L39_0050B6F0(mont);
    ctx->tos -= 2;
    for (i = 0; i < ts; i++) {
        for (j = 0; j < ts; j++) {
            func_L39_004FC1A0(&val[i][j]);
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004FE728 */

INCLUDE_ASM("asm/levels", func_L39_004FECA0);

INCLUDE_ASM("asm/levels", func_L39_004FF3AC);

/* localdecomp:start func_L39_004FF3C0 */
typedef struct { void *f0; u8 pad[0xC]; void *f10; s32 f14; s32 f18; s32 f1c; } S_004FF3C0;
extern void *func_L39_004BEED8(s32);
extern void func_11D534(void *, s32, s32);
extern void func_L39_004FCF88(void *);
s32 func_L39_004FF3C0(void *a0, s32 *a1) {
    S_004FF3C0 *p = func_L39_004BEED8(0x78);
    if (p == 0) {
        return 1;
    }
    func_11D534(p, 0, 0x20);
    p->f0 = a0;
    p->f10 = p + 1;
    func_L39_004FCF88(p + 1);
    p->f14 = 0;
    p->f18 = 0;
    *a1 = (s32)p;
    return 0;
}
/* localdecomp:end func_L39_004FF3C0 */
