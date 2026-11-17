#include "common.h"

/* declared by functions of L39_004E1CB8.c, which this file was cut from */
extern void func_L39_004BEF28(void *);

/* localdecomp:start func_L39_004E2440 */
extern u8 D_L39_0046D290[];

void *func_L39_004E2440(void) {
    return D_L39_0046D290;
}
/* localdecomp:end func_L39_004E2440 */

/* localdecomp:start func_L39_004E2450 */
extern void func_L39_004FC228(void *);
extern void func_L39_004FCD30(void *);
extern void func_L39_004BEF28(void *);

struct C_004E24B8;

typedef struct S_004E2450 {
    u8 pad0[0xC];
    u8 p[0x14];
    u8 g[0x14];
    u8 pub[0x14];
    u8 priv[0x14];
    u8 pad5C[8];
    void *mont;
} S_004E2450;

typedef struct C_004E2450 {
    u8 pad0[8];
    S_004E2450 *dh;
} C_004E2450;

s32 func_L39_004E2450(struct C_004E24B8 *c) {
    C_004E2450 *ctx = (C_004E2450 *)c;
    S_004E2450 *dh;

    dh = ctx->dh;
    if (dh == 0) {
        return 0;
    }
    func_L39_004FC228(dh->p);
    func_L39_004FC228(dh->g);
    func_L39_004FC228(dh->pub);
    func_L39_004FC228(dh->priv);
    if (dh->mont != 0) {
        func_L39_004FCD30(dh->mont);
    }
    func_L39_004BEF28(dh);
    return 0;
}
/* localdecomp:end func_L39_004E2450 */

/* localdecomp:start func_L39_004E24B8 */
extern void *func_L39_004FC3C8(void);
extern void func_L39_004FC448(void *);
extern void func_L39_004FC370(void *);
extern s32 func_L39_004FC158(void *);
extern void *func_L39_004FC780(u8 *, s32, void *);
extern void func_11D534(void *, s32, s32);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004FCCC8(s32, void *);
extern s32 func_L39_004FCD58(void *, void *, s32, s32, void *);

typedef struct BN_004E24B8 {
    u32 *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BN_004E24B8;

typedef struct S_004E24B8 {
    u8 pad0[4];
    u32 flags;
    s32 bits;
    BN_004E24B8 p;
    BN_004E24B8 g;
    BN_004E24B8 pub;
    BN_004E24B8 priv;
    u8 *f5C;
    u8 *f60;
    void *mont;
} S_004E24B8;

typedef struct C_004E24B8 {
    u8 pad0[8];
    S_004E24B8 *dh;
} C_004E24B8;

typedef struct R_004E24B8 {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 *data;
    s32 len;
} R_004E24B8;

extern s32 func_L39_004E2450(C_004E24B8 *);
extern s32 func_L39_004E4AE8(void *container, u32 category, u32 key, s32 *cursor, R_004E24B8 **output, u32 flags);

s32 func_L39_004E24B8(C_004E24B8 *ctx, void *container) {
    s32 cursor;
    R_004E24B8 *r;
    void *bnctx;
    S_004E24B8 *dh;
    s32 ret = 1;

    bnctx = func_L39_004FC3C8();
    if (bnctx == 0) {
        return 1;
    }
    dh = ctx->dh;
    if (dh != 0) {
        func_L39_004E2450(ctx);
    }
    dh = func_L39_004BEED8(0x68);
    if (dh == 0) goto end;
    func_11D534(dh, 0, 0x68);
    ctx->dh = dh;
    func_L39_004FC370(&dh->p);
    func_L39_004FC370(&dh->g);
    func_L39_004FC370(&dh->pub);
    func_L39_004FC370(&dh->priv);
    dh->flags = 0;

    cursor = 0;
    func_L39_004E4AE8(container, 1, 2, &cursor, &r, 4);
    dh->f5C = r != 0 ? r->data : 0;
    func_L39_004E4AE8(container, 1, 3, &cursor, &r, 4);
    dh->f60 = r != 0 ? r->data : 0;

    cursor = 0;
    func_L39_004E4AE8(container, 0x12, 1, &cursor, &r, 4);
    if (r == 0) goto end;
    func_L39_004FC780(r->data, r->len, &dh->p);
    if (dh->p.top <= 0 || ((dh->p.d[0] ^ 1) & 1)) goto end;
    func_L39_004E4AE8(container, 0x12, 2, &cursor, &r, 4);
    if (r == 0) goto end;
    func_L39_004FC780(r->data, r->len, &dh->g);
    dh->flags |= 1;
    func_L39_004FCCC8(0, &dh->mont);
    if (func_L39_004FCD58(dh->mont, &dh->p, 1, 0, bnctx) != 0) goto end;

    func_L39_004E4AE8(container, 0x12, 5, &cursor, &r, 4);
    cursor = func_L39_004FC158(&dh->p);
    if (r == 0) {
        dh->bits = cursor;
    } else {
        dh->bits = cursor < r->len ? cursor : r->len;
    }
    if (func_L39_004E4AE8(container, 0x12, 4, &cursor, &r, 4) == 0) {
        func_L39_004FC780(r->data, r->len, &dh->priv);
        dh->flags |= 4;
    }
    if (func_L39_004E4AE8(container, 0x12, 3, &cursor, &r, 4) == 0) {
        func_L39_004FC780(r->data, r->len, &dh->pub);
        dh->flags |= 2;
    }
    ret = 0;
end:
    if (bnctx != 0) {
        func_L39_004FC448(bnctx);
    }
    return ret;
}
/* localdecomp:end func_L39_004E24B8 */

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
