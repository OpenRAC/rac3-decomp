#include "common.h"

/* localdecomp:start func_L39_004E1CB8 */
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_004E1CB8(u8 **arg0, u8 *arg1, s32 arg2) {
    u8 *p;
    s32 i;
    s32 v;
    u8 *q;
    s32 len;
    u8 t;

    p = *arg0;
    for (i = 0; i < arg2; i++) {
        arg1[i] = 0;
    }
    len = arg2 * 2;
    for (i = 0; i < len; i++) {
        if ((u8)(*p - '0') < 10) {
            v = *p - '0';
        } else if ((u8)(*p - 'A') < 6) {
            v = *p - 'A' + 10;
        } else if ((u8)(*p - 'a') < 6) {
            v = *p - 'a' + 10;
        } else {
            func_L39_004BC6C8(9, 0x65, 0x67, 0, 0);
            return 0;
        }
        p++;
        q = &arg1[i / 2];
        t = *q;
        if (i % 2 == 0) {
            *q = t | (v << 4);
        } else {
            *q = t | v;
        }
    }
    *arg0 = p;
    return 1;
}
/* localdecomp:end func_L39_004E1CB8 */

/* localdecomp:start func_L39_004E1DC8 */
extern void *func_L39_004DB110(void);
extern void *func_L39_00504528(void);
extern s32 func_L39_004FB898(void *, char *, s32);
extern s32 func_L39_004DB1C0(void *, s32);
extern s32 func_L39_005045C0(void *, u8 *, s32 *, u8 *, s32);
extern void func_L39_005045A8(void *);
extern s32 func_L39_00504970(void *, u8 *, s32 *);
extern void func_L39_004BEF28(void *);
extern void func_L39_004DB168(void *);
extern void func_L39_00504588(void *);
extern s32 func_00120B70(char *, char *, s32);
extern s32 func_00120884(char *);
extern void *func_00120D28(void *, void *, s32);
extern char D_L39_00477358[];
extern char D_L39_00477368[];
extern char D_L39_00477370[];

typedef struct S_004E1DC8 {
    s32 f0;
    char *f4;
    s32 f8;
} S_004E1DC8;

/* from OpenSSL's PEM_read_bio (crypto/pem/pem_lib.c) */
s32 func_L39_004E1DC8(void *bp, char **out1, char **out2, char **out3, long *out4) {
    long len;
    s32 end = 0, i, k, bl = 0, hl = 0, nohead = 0, m;
    char buf[0x100];
    S_004E1DC8 *nameB;
    S_004E1DC8 *headerB;
    S_004E1DC8 *dataB;
    S_004E1DC8 *tmpB;
    void *ctx;

    nameB = func_L39_004DB110();
    nohead = 0;
    headerB = func_L39_004DB110();
    dataB = func_L39_004DB110();
    ctx = func_L39_00504528();
    if (nameB == 0 || headerB == 0 || dataB == 0 || ctx == 0) {
        func_L39_004BC6C8(9, 0x6D, 0x21, 0, 0);
        goto err;
    }
    buf[0xFE] = 0;
    for (;;) {
        i = func_L39_004FB898(bp, buf, 0xFE);
        if (i <= 0) {
            func_L39_004BC6C8(9, 0x6D, 0x6C, 0, 0);
            goto err;
        }
        while (i >= 0 && buf[i] <= ' ') i--;
        buf[++i] = '\n';
        buf[++i] = 0;
        if (func_00120B70(buf, D_L39_00477358, 11) == 0) {
            i = func_00120884(&buf[11]);
            if (func_00120B70(&buf[11 + i - 6], D_L39_00477368, 6) != 0) continue;
            if (!func_L39_004DB1C0(nameB, i + 9)) {
                func_L39_004BC6C8(9, 0x6D, 0x21, 0, 0);
                goto err;
            }
            func_00120D28(nameB->f4, &buf[11], i - 6);
            nameB->f4[i - 6] = 0;
            break;
        }
    }
    hl = 0;
    if (!func_L39_004DB1C0(headerB, 256)) {
        func_L39_004BC6C8(9, 0x6D, 0x21, 0, 0);
        goto err;
    }
    headerB->f4[0] = 0;
    for (;;) {
        i = func_L39_004FB898(bp, buf, 0xFE);
        if (i <= 0) break;
        while (i >= 0 && buf[i] <= ' ') i--;
        buf[++i] = '\n';
        buf[++i] = 0;
        if (buf[0] == '\n') break;
        m = hl + i;
        if (!func_L39_004DB1C0(headerB, m + 9)) {
            func_L39_004BC6C8(9, 0x6D, 0x21, 0, 0);
            goto err;
        }
        if (func_00120B70(buf, D_L39_00477370, 9) == 0) {
            nohead = 1;
            break;
        }
        func_00120D28(headerB->f4 + hl, buf, i);
        headerB->f4[m] = 0;
        hl = m;
    }
    bl = 0;
    if (!func_L39_004DB1C0(dataB, 1024)) {
        func_L39_004BC6C8(9, 0x6D, 0x21, 0, 0);
        goto err;
    }
    dataB->f4[0] = 0;
    if (!nohead) {
        for (;;) {
            i = func_L39_004FB898(bp, buf, 0xFE);
            if (i <= 0) break;
            while (i >= 0 && buf[i] <= ' ') i--;
            buf[++i] = '\n';
            buf[++i] = 0;
            if (i != 65) end = 1;
            if (func_00120B70(buf, D_L39_00477370, 9) == 0) break;
            if (i > 65) break;
            if (!func_L39_004DB1C0(dataB, i + bl + 9)) {
                func_L39_004BC6C8(9, 0x6D, 0x21, 0, 0);
                goto err;
            }
            func_00120D28(dataB->f4 + bl, buf, i);
            dataB->f4[bl + i] = 0;
            bl += i;
            if (end) {
                buf[0] = 0;
                i = func_L39_004FB898(bp, buf, 0xFE);
                if (i <= 0) break;
                while (i >= 0 && buf[i] <= ' ') i--;
                buf[++i] = '\n';
                buf[++i] = 0;
                break;
            }
        }
    } else {
        tmpB = headerB;
        headerB = dataB;
        dataB = tmpB;
        bl = hl;
    }
    i = func_00120884(nameB->f4);
    if (func_00120B70(buf, D_L39_00477370, 9) != 0 ||
        func_00120B70(nameB->f4, &buf[9], i) != 0 ||
        func_00120B70(&buf[9 + i], D_L39_00477368, 6) != 0) {
        func_L39_004BC6C8(9, 0x6D, 0x66, 0, 0);
        goto err;
    }
    func_L39_005045A8(ctx);
    i = func_L39_005045C0(ctx, (u8 *)dataB->f4, &bl, (u8 *)dataB->f4, bl);
    if (i < 0) {
        func_L39_004BC6C8(9, 0x6D, 0x64, 0, 0);
        goto err;
    }
    i = func_L39_00504970(ctx, (u8 *)&dataB->f4[bl], &k);
    if (i < 0) {
        func_L39_004BC6C8(9, 0x6D, 0x64, 0, 0);
        goto err;
    }
    bl += k;
    if (bl == 0) goto err;
    len = bl;
    *out1 = nameB->f4;
    *out2 = headerB->f4;
    *out3 = dataB->f4;
    *out4 = len;
    func_L39_004BEF28(nameB);
    func_L39_004BEF28(headerB);
    func_L39_004BEF28(dataB);
    func_L39_00504588(ctx);
    return 1;
err:
    if (ctx != 0) func_L39_00504588(ctx);
    if (nameB != 0) {
        func_L39_004DB168(nameB);
        func_L39_004DB168(headerB);
    }
    if (dataB != 0) func_L39_004DB168(dataB);
    return 0;
}
/* localdecomp:end func_L39_004E1DC8 */

INCLUDE_ASM("asm/levels", func_L39_004E2398);

INCLUDE_ASM("asm/levels", func_L39_004E23D8);

/* localdecomp:start func_L39_004E2440 */
extern u8 D_L39_0046D290[];

void *func_L39_004E2440(void) {
    return D_L39_0046D290;
}
/* localdecomp:end func_L39_004E2440 */

INCLUDE_ASM("asm/levels", func_L39_004E2450);

INCLUDE_ASM("asm/levels", func_L39_004E24B8);

/* localdecomp:start func_L39_004E27B8 */
extern void *func_L39_004FC3C8(void);
extern void func_L39_004FC448(void *);
extern s32 func_L39_004FFD58(void *, void *, s32, s32, s32);
extern s32 func_L39_004FCE30(void *, void *, void *, void *, void *, void *);

typedef struct S_004E27B8 {
    u8 pad0[4];
    u32 flags;
    s32 bits;
    u8 p[0x14];
    u8 g[0x14];
    u8 pub[0x14];
    u8 priv[0x14];
    void *f5C;
    u8 pad60[4];
    void *mont;
} S_004E27B8;

typedef struct C_004E27B8 {
    u8 pad0[8];
    S_004E27B8 *dh;
} C_004E27B8;

s32 func_L39_004E27B8(C_004E27B8 *ctx, s32 cmd, void *arg2, s32 mode) {
    void *bnctx;
    S_004E27B8 *dh;
    s32 ret;

    if (cmd != 5) {
        return 2;
    }
    bnctx = func_L39_004FC3C8();
    if (bnctx == 0) {
        return 1;
    }
    dh = ctx->dh;
    if (!(dh->flags & 1)) {
        ret = 3;
    } else if (dh->f5C == 0) {
        ret = 4;
    } else {
        if (!(mode & 1) || !(dh->flags & 4)) {
            func_L39_004FFD58(dh->priv, dh->f5C, dh->bits, 1, 0);
        }
        ret = func_L39_004FCE30(dh->mont, dh->pub, dh->g, dh->priv, 0, bnctx);
        if (ret == 0) {
            dh->flags |= 6;
        }
    }
    if (bnctx != 0) {
        func_L39_004FC448(bnctx);
    }
    return ret;
}
/* localdecomp:end func_L39_004E27B8 */

/* localdecomp:start func_L39_004E28B8 */
extern void *func_L39_004FC3C8(void);
extern void func_L39_004FC448(void *);
extern void func_L39_004FC370(void *);
extern void func_L39_004FC228(void *);
extern s32 func_L39_004FC158(void *);
extern void *func_L39_004FC780(u8 *, s32, void *);
extern s32 func_L39_004FCE30(void *, void *, void *, void *, void *, void *);
extern void func_11D534(void *, s32, s32);
extern s32 func_L39_004FC8C0(void *, u8 *);

typedef struct BN_004E28B8 {
    u64 *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BN_004E28B8;

typedef struct S_004E28B8 {
    u8 pad0[4];
    u32 flags;
    s32 bits;
    BN_004E28B8 p;
    BN_004E28B8 g;
    BN_004E28B8 pub;
    BN_004E28B8 priv;
    void *f5C;
    u8 pad60[4];
    void *mont;
} S_004E28B8;

typedef struct C_004E28B8 {
    u8 pad0[8];
    S_004E28B8 *dh;
} C_004E28B8;

s32 func_L39_004E28B8(C_004E28B8 *ctx, s32 cmd, u8 *buf, s32 *outlen, u32 bufsize, u8 *peer, s32 peerlen) {
    BN_004E28B8 a;
    BN_004E28B8 b;
    void *bnctx;
    S_004E28B8 *dh;
    s32 ret = 1;
    u32 size;
    s32 pad;

    if (cmd != 6) {
        return 2;
    }
    bnctx = func_L39_004FC3C8();
    if (bnctx == 0) {
        return 1;
    }
    func_L39_004FC370(&a);
    func_L39_004FC370(&b);
    dh = ctx->dh;
    if ((dh->flags & 5) != 5) {
        ret = 3;
    } else {
        size = (func_L39_004FC158(&dh->p) + 7) / 8;
        if (bufsize < size) {
            ret = 4;
        } else {
            func_L39_004FC780(peer, peerlen, &a);
            /* BN_is_zero(&a) || BN_is_one(&a) */
            if ((a.top == 0 || (a.top == 1 && a.d[0] == 0)) || (a.top == 1 && a.d[0] == 1)) {
                ret = 5;
            } else {
                ret = func_L39_004FCE30(dh->mont, &b, &a, &dh->priv, 0, bnctx);
                if (ret == 0) {
                    pad = size - (func_L39_004FC158(&b) + 7) / 8;
                    if (pad != 0) {
                        func_11D534(buf, 0, pad);
                    }
                    *outlen = func_L39_004FC8C0(&b, buf + pad) + pad;
                }
            }
        }
    }
    if (bnctx != 0) {
        func_L39_004FC448(bnctx);
    }
    func_L39_004FC228(&a);
    func_L39_004FC228(&b);
    return ret;
}
/* localdecomp:end func_L39_004E28B8 */

/* localdecomp:start func_L39_004E2A98 */
extern s32 func_L39_004FC158(void *);
extern void func_11D534(void *, s32, s32);
extern s32 func_L39_004FC8C0(void *, u8 *);

typedef struct S_004E2A98 {
    u8 pad0[4];
    u32 flags;
    u8 pad8[4];
    u8 p[0x28];
    u8 pub[0x14];
} S_004E2A98;

typedef struct C_004E2A98 {
    u8 pad0[8];
    S_004E2A98 *dh;
} C_004E2A98;

s32 func_L39_004E2A98(C_004E2A98 *ctx, s32 cmd, u8 *buf, s32 *outlen) {
    S_004E2A98 *dh;
    s32 len;
    s32 pad;
    s32 size;

    if (cmd != 8) {
        return 2;
    }
    dh = ctx->dh;
    if (!(dh->flags & 2)) {
        return 3;
    }
    size = (func_L39_004FC158(dh->p) + 7) / 8;
    len = (func_L39_004FC158(dh->pub) + 7) / 8;
    pad = size - len;
    if (buf != 0) {
        if (pad != 0) {
            func_11D534(buf, 0, pad);
        }
        *outlen = func_L39_004FC8C0(dh->pub, buf + pad) + pad;
    } else {
        *outlen = len + pad;
    }
    return 0;
}
/* localdecomp:end func_L39_004E2A98 */

/* localdecomp:start func_L39_004E2B80 */
extern s32 func_L39_004FC158(void *);
extern void *func_L39_004BEED8(s32);
extern s32 func_L39_004FC8C0(void *, u8 *);
extern void func_L39_004E4578(void *, s32, s32, u8 *, s32, s32);
extern char D_L39_00477380[];

typedef struct N_004E2B80 {
    u8 pad0[4];
    char *name;
} N_004E2B80;

typedef struct M_004E2B80 {
    N_004E2B80 *meth;
} M_004E2B80;

typedef struct S_004E2B80 {
    u8 pad0[4];
    u32 flags;
    s32 bits;
    u8 p[0x14];
    u8 g[0x14];
    u8 pub[0x14];
    u8 priv[0x14];
    void *f5C;
    u8 pad60[4];
    struct M_004E2B80 *f64;
} S_004E2B80;

typedef struct C_004E2B80 {
    u8 pad0[8];
    S_004E2B80 *dh;
} C_004E2B80;

typedef struct O_004E2B80 {
    s32 f0;
    u8 pad4[4];
    s32 f8;
    u8 padC[8];
    u32 f14;
} O_004E2B80;

s32 func_L39_004E2B80(C_004E2B80 *ctx, s32 cmd, s32 which, O_004E2B80 *out) {
    S_004E2B80 *dh;
    void *bn;
    u8 *buf;
    s32 len;

    if (ctx == 0 || (dh = ctx->dh) == 0) {
        return 2;
    }
    if (cmd == 0x101) {
        if (out == 0) {
            return 2;
        }
        if (which == 4) {
            bn = dh->priv;
        } else if (which == 3 && (dh->flags & 2)) {
            bn = dh->pub;
        } else if (which == 1) {
            bn = dh->p;
        } else if (which == 2) {
            bn = dh->g;
        } else {
            return 2;
        }
        if (bn == 0) {
            return 3;
        }
        len = (func_L39_004FC158(bn) + 7) / 8;
        buf = func_L39_004BEED8(len);
        if (buf == 0) {
            return 1;
        }
        func_L39_004FC8C0(bn, buf);
        func_L39_004E4578(out, 0x12, which, buf, len, 0);
        out->f8 = 2;
        out->f14 |= 2;
        return 0;
    } else if (cmd == 0x102) {
        M_004E2B80 *m;

        m = dh->f64;
        if (m == 0 || m->meth == 0) {
            out->f0 = (s32)D_L39_00477380;
        } else {
            out->f0 = (s32)m->meth->name;
        }
    } else if (cmd == 0x103) {
        out->f0 = (func_L39_004FC158(dh->p) + 7) / 8;
    }
    return 0;
}
/* localdecomp:end func_L39_004E2B80 */

/* localdecomp:start func_L39_004E2D18 */
s32 func_L39_004E2D18(void) {
    return 2;
}
/* localdecomp:end func_L39_004E2D18 */
