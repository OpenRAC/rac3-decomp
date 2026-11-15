#include "common.h"

/* declared by functions of L39_004E2DD0.c, which this file was cut from */
extern s32 func_L39_004E3748(void *, s32, u8 *, u32 *, u32, s32, s32, s32);

INCLUDE_ASM("asm/levels", func_L39_004E3748);

/* localdecomp:start func_L39_004E38F0 */
typedef struct BN_004E38F0 {
    u32 *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BN_004E38F0;

typedef struct C_004E38F0 {
    u8 _p0[0x10C];
    s32 f10C;
} C_004E38F0;

typedef struct K_004E38F0 {
    s32 _p0[16];
    s32 f40;
    BN_004E38F0 *f44;
    s32 _p48;
    s32 f4C;
    void **f50;
} K_004E38F0;

extern C_004E38F0 *func_L39_004FC3C8(void);
extern void func_L39_004FC448(C_004E38F0 *);
extern void func_L39_004FC370(BN_004E38F0 *);
extern void func_L39_004FC1A0(BN_004E38F0 *);
extern BN_004E38F0 *func_L39_004FC5C0(BN_004E38F0 *, BN_004E38F0 *);
extern s32 func_L39_004FCE30(void *, BN_004E38F0 *, BN_004E38F0 *, s32, s32, C_004E38F0 *);
extern s32 func_L39_004FCFD0(BN_004E38F0 *, BN_004E38F0 *, BN_004E38F0 *, C_004E38F0 *);
extern s32 func_L39_004FBDA0(BN_004E38F0 *, BN_004E38F0 *, BN_004E38F0 *);
extern s32 func_L39_004FB9A0(BN_004E38F0 *, BN_004E38F0 *, BN_004E38F0 *);
extern s32 func_L39_004FBED8(BN_004E38F0 *, BN_004E38F0 *, BN_004E38F0 *, C_004E38F0 *);

s32 func_L39_004E38F0(BN_004E38F0 *r, BN_004E38F0 *a, K_004E38F0 *key) {
    BN_004E38F0 t;
    BN_004E38F0 m;
    BN_004E38F0 x;
    C_004E38F0 *ctx;
    s32 i;
    s32 ret;

    ret = 1;
    if ((ctx = func_L39_004FC3C8()) == 0) {
        goto err;
    }
    ctx->f10C = key->f4C;
    func_L39_004FC370(&x);
    func_L39_004FC370(&t);
    func_L39_004FC370(&m);
    if (func_L39_004FCE30(key->f50[0], r, a, 0, 0, ctx) != 0) {
        goto err;
    }
    for (i = 1; i < key->f40; i++) {
        if (i < 2) {
            func_L39_004FC5C0(&m, &key->f44[0]);
        } else {
            func_L39_004FCFD0(&m, &m, &key->f44[(i - 1) * 3], ctx);
        }
        if (func_L39_004FCE30(key->f50[i], &x, a, 0, 0, ctx) != 0) {
            goto err;
        }
        if (!func_L39_004FBDA0(&x, &x, r)) {
            goto err;
        }
        if (x.neg) {
            if (!func_L39_004FB9A0(&x, &x, &key->f44[i * 3])) {
                goto err;
            }
            if (x.neg) {
                if (!func_L39_004FBED8(&x, &x, &key->f44[i * 3], ctx)) {
                    goto err;
                }
                if (!func_L39_004FB9A0(&x, &x, &key->f44[i * 3])) {
                    goto err;
                }
            }
        }
        if (!func_L39_004FCFD0(&t, &x, &key->f44[i * 3 + 2], ctx)) {
            goto err;
        }
        if (!func_L39_004FBED8(&x, &t, &key->f44[i * 3], ctx)) {
            goto err;
        }
        if (!func_L39_004FCFD0(&t, &x, &m, ctx)) {
            goto err;
        }
        if (!func_L39_004FB9A0(r, r, &t)) {
            goto err;
        }
    }
    ret = 0;
err:
    if (ctx != 0) {
        func_L39_004FC448(ctx);
    }
    func_L39_004FC1A0(&x);
    func_L39_004FC1A0(&t);
    func_L39_004FC1A0(&m);
    return ret;
}
/* localdecomp:end func_L39_004E38F0 */
