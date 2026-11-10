#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

/* localdecomp:start func_L39_004FB668 */
typedef struct {
    s32 f0;
    void *f4;
} S_004FB668;

extern void func_L39_004F9A88(void *);
extern void func_L39_004FA4E8(void *);

void func_L39_004FB668(S_004FB668 *p) {
    void *h;
    if (p != 0) {
        h = p->f4;
        if (h != 0) {
            switch (p->f0) {
            case 6:
                func_L39_004F9A88(h);
                break;
            case 2: case 3: case 4:
            case 0x10: case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17:
            case 0x18: case 0x19: case 0x1A: case 0x1B: case 0x1C:
            case 0x1E:
            case 0x102:
                func_L39_004FA4E8(p->f4);
                break;
            }
            p->f0 = 0;
            p->f4 = 0;
        }
    }
}
/* localdecomp:end func_L39_004FB668 */

/* localdecomp:start func_L39_004FB710 */
typedef struct {
    s32 length;
    s32 type;
    unsigned char *data;
} AStr_004FB710;

typedef struct {
    void *algorithm;
} Alg_004FB710;

extern void *func_L01_0047F3B0(void *obj);
extern void *func_L39_004DE940(void);
extern void *func_L39_004BEED8(s32 n);
extern void func_L39_004BC6C8(s32 lib, s32 func, s32 reason, char *file, s32 line);
extern s32 func_L39_004DD690(void *ctx, void *type);
extern void func_L39_004DD778(void *ctx, void *buf, s32 n);
extern void func_0011D534(void *, s32, s32);
extern s32 func_L39_004E1478(void *ctx, unsigned char *sig, s32 siglen, void *pkey);
extern void func_L39_004BEF28(void *p);
extern void func_L39_004DE9B8(void *ctx);

/* ASN1_verify */
s32 func_L39_004FB710(s32 (*i2d)(void *, unsigned char **), Alg_004FB710 *a, AStr_004FB710 *signature,
                      void *data, void *pkey) {
    void *ctx = 0;
    void *type;
    unsigned char *p, *buf_in = 0;
    s32 ret = -1, inl;

    type = func_L01_0047F3B0(a->algorithm);
    if (type == 0) {
        func_L39_004BC6C8(13, 121, 141, 0, 0);
        goto err;
    }
    ctx = func_L39_004DE940();
    if (ctx == 0) {
        goto err;
    }
    inl = i2d(data, 0);
    buf_in = func_L39_004BEED8(inl);
    if (buf_in == 0) {
        func_L39_004BC6C8(13, 121, 33, 0, 0);
        goto err;
    }
    p = buf_in;
    i2d(data, &p);
    if (!func_L39_004DD690(ctx, type)) {
        goto err;
    }
    func_L39_004DD778(ctx, buf_in, inl);
    func_0011D534(buf_in, 0, inl);
    if (func_L39_004E1478(ctx, signature->data, signature->length, pkey) <= 0) {
        func_L39_004BC6C8(13, 121, 0x806, 0, 0);
        ret = 0;
        goto err;
    }
    ret = 1;
err:
    if (buf_in != 0) {
        func_L39_004BEF28(buf_in);
    }
    if (ctx != 0) {
        func_L39_004DE9B8(ctx);
    }
    return ret;
}
/* localdecomp:end func_L39_004FB710 */

INCLUDE_ASM("asm/levels", func_L39_004FB898);

/* localdecomp:start func_L39_004FB9A0 */
typedef struct { u8 pad0[0xC]; s32 fC; } S_004FB9A0;
extern s32 func_L39_004FC960(S_004FB9A0 *, S_004FB9A0 *);
extern s32 func_L39_004FBBE8(S_004FB9A0 *, S_004FB9A0 *, S_004FB9A0 *);
extern s32 func_L39_004FBA78(S_004FB9A0 *, S_004FB9A0 *, S_004FB9A0 *);

s32 func_L39_004FB9A0(S_004FB9A0 *arg0, S_004FB9A0 *a, S_004FB9A0 *b) {
    S_004FB9A0 *t;

    if (a->fC != b->fC) {
        if (a->fC != 0) {
            t = a;
            a = b;
            b = t;
        }
        if (func_L39_004FC960(a, b) < 0) {
            if (!func_L39_004FBBE8(arg0, b, a)) {
                return 0;
            }
            arg0->fC = 1;
        } else {
            if (!func_L39_004FBBE8(arg0, a, b)) {
                return 0;
            }
            arg0->fC = 0;
        }
        return 1;
    }
    if (a->fC != 0) {
        arg0->fC = 1;
    } else {
        arg0->fC = 0;
    }
    return func_L39_004FBA78(arg0, a, b) != 0;
}
/* localdecomp:end func_L39_004FB9A0 */

INCLUDE_ASM("asm/levels", func_L39_004FBA78);

INCLUDE_ASM("asm/levels", func_L39_004FBBE8);

INCLUDE_ASM("asm/levels", func_L39_004FBDA0);

/* localdecomp:start func_L39_004FBED8 */
typedef struct BN_004FBED8 BN_004FBED8;
extern s32 func_L39_0050A8D8(BN_004FBED8 *, BN_004FBED8 *, const BN_004FBED8 *, const BN_004FBED8 *, void *);

s32 func_L39_004FBED8(BN_004FBED8 *rem, const BN_004FBED8 *m, const BN_004FBED8 *d, void *ctx) {
    return func_L39_0050A8D8(0, rem, m, d, ctx);
}
/* localdecomp:end func_L39_004FBED8 */

INCLUDE_ASM("asm/levels", func_L39_004FBF10);

/* localdecomp:start func_L39_004FC158 */
extern s32 func_L39_0050B060(unsigned long);

s32 func_L39_004FC158(BitSet_004FCA98 *a0) {
    s32 n = a0->f4;
    s32 r = 0;
    if (n != 0) {
        s32 off = (n - 1) << 6;
        r = off + func_L39_0050B060(a0->f0[n - 1]);
    }
    return r;
}
/* localdecomp:end func_L39_004FC158 */

INCLUDE_ASM("asm/levels", func_L39_004FC1A0);

/* localdecomp:start func_L39_004FC228 */
extern void func_L39_004BEF28(void *p);

typedef struct S_004FC228 {
    void *f0;
    char _p4[0xC];
    s32 f10;
} S_004FC228;

void func_L39_004FC228(void *arg0) {
    S_004FC228 *s = (S_004FC228 *)arg0;

    if (s == 0) {
        return;
    }
    if (s->f0 != 0 && !(s->f10 & 2)) {
        func_L39_004BEF28(s->f0);
    }
    s->f10 |= 0x8000;
    if (s->f10 & 1) {
        func_L39_004BEF28(s);
    }
}
/* localdecomp:end func_L39_004FC228 */

INCLUDE_ASM("asm/levels", func_L39_004FC288);
