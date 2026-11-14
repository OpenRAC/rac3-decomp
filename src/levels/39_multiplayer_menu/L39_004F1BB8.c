#include "common.h"

/* localdecomp:start func_L39_004F1BB8 */
/* OpenSSL 0.9.6 X509_STORE_get_by_subject (x509_lu.c), sk_num/sk_value inlined */
typedef struct { s32 num; void **data; } STACK_004F1BB8;
typedef struct { s32 cache; STACK_004F1BB8 *objs; STACK_004F1BB8 *get_cert_methods; } STORE_004F1BB8;
typedef struct { STORE_004F1BB8 *ctx; s32 current_method; } CTX_004F1BB8;
typedef struct { s32 type; void *ptr; } OBJ_004F1BB8;

extern OBJ_004F1BB8 *func_L39_004F1CA0(STACK_004F1BB8 *, s32, void *);
extern s32 func_L39_00505EA8(void *, s32, void *, OBJ_004F1BB8 *);
extern void func_L39_00505F88(OBJ_004F1BB8 *);

s32 func_L39_004F1BB8(CTX_004F1BB8 *vs, s32 type, void *name, OBJ_004F1BB8 *ret) {
    STORE_004F1BB8 *ctx = vs->ctx;
    void *lu;
    OBJ_004F1BB8 stmp, *tmp;
    s32 i, j;

    tmp = func_L39_004F1CA0(ctx->objs, type, name);

    if (tmp == 0) {
        for (i = vs->current_method; i < ctx->get_cert_methods->num; i++) {
            lu = ctx->get_cert_methods->data[i];
            j = func_L39_00505EA8(lu, type, name, &stmp);
            if (j < 0) {
                vs->current_method = j;
                return j;
            } else if (j) {
                tmp = &stmp;
                break;
            }
        }
        vs->current_method = 0;
        if (tmp == 0)
            return 0;
    }

    ret->type = tmp->type;
    ret->ptr = tmp->ptr;

    func_L39_00505F88(ret);

    return 1;
}
/* localdecomp:end func_L39_004F1BB8 */

/* localdecomp:start func_L39_004F1CA0 */
/* OpenSSL 0.9.6 X509_OBJECT_retrieve_by_subject (x509_lu.c) */
typedef struct { s32 version; void *cert_info; s32 pad[6]; } X509_004F1CA0;
typedef struct { s32 pad[5]; void *subject; s32 pad2[6]; } CINF_004F1CA0;

extern OBJ_004F1BB8 *func_L39_004BCDE0(STACK_004F1BB8 *, OBJ_004F1BB8 *);

OBJ_004F1BB8 *func_L39_004F1CA0(STACK_004F1BB8 *h, s32 type, void *name) {
    OBJ_004F1BB8 stmp;
    X509_004F1CA0 x509_s;
    CINF_004F1CA0 cinf_s;

    stmp.type = type;
    switch (type) {
    case 1:
        stmp.ptr = &x509_s;
        x509_s.cert_info = &cinf_s;
        cinf_s.subject = name;
        break;
    }
    return func_L39_004BCDE0(h, &stmp);
}
/* localdecomp:end func_L39_004F1CA0 */

/* localdecomp:start func_L39_004F1CE0 */
/* OpenSSL 0.9.6 X509_STORE_CTX_get_ex_new_index (x509_vfy.c) */
extern void *D_L39_0046D500 __attribute__((section(".data")));
extern s32 D_L39_0046D504 __attribute__((section(".data")));
extern s32 func_L39_004DEC08(s32, void **, s32, void *, void *, void *, void *);

s32 func_L39_004F1CE0(s32 argl, void *argp, void *new_func, void *dup_func, void *free_func) {
    D_L39_0046D504++;
    return func_L39_004DEC08(D_L39_0046D504 - 1, &D_L39_0046D500, argl, argp, new_func, dup_func, free_func);
}
/* localdecomp:end func_L39_004F1CE0 */

/* localdecomp:start func_L39_004F1D30 */
/* OpenSSL 0.9.6: free the X509_STORE_CTX ex_data method stack */
extern void *D_L39_0046D500 __attribute__((section(".data")));
extern s32 D_L39_0046D504 __attribute__((section(".data")));
extern void func_L39_004DEBF0(void *);
extern void func_L39_004CC510(void *, void *);

s32 func_L39_004F1D30(void) {
    if (D_L39_0046D500 != 0) {
        func_L39_004CC510(D_L39_0046D500, func_L39_004DEBF0);
        D_L39_0046D500 = 0;
        D_L39_0046D504 = 0;
    }
    return 1;
}
/* localdecomp:end func_L39_004F1D30 */

/* localdecomp:start func_L39_004F1D78 */
/* OpenSSL 0.9.6 X509_STORE_CTX_set_ex_data (x509_vfy.c) */
typedef struct {
    s32 pad0[11];
    struct { void *sk; s32 dummy; } ex_data;
} CTX_004F1D78;

extern s32 func_L39_004DED48(void *, s32, void *);

s32 func_L39_004F1D78(CTX_004F1D78 *ctx, s32 idx, void *data) {
    return func_L39_004DED48(&ctx->ex_data, idx, data);
}
/* localdecomp:end func_L39_004F1D78 */

/* localdecomp:start func_L39_004F1D98 */
typedef struct { s32 n; s32 *items; } L_004F1D98;
typedef struct { u8 pad[0x2C]; L_004F1D98 *f2C; } S_004F1D98;

extern int func_L39_004DEE38(L_004F1D98 **, int);

int func_L39_004F1D98(S_004F1D98 *a, int idx) {
    return func_L39_004DEE38(&a->f2C, idx);
}
/* localdecomp:end func_L39_004F1D98 */

/* localdecomp:start func_L39_004F1DB8 */
/* OpenSSL 0.9.6 X509_STORE_CTX_new (x509_vfy.c) */
extern void *func_L39_004BEED8(s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

void *func_L39_004F1DB8(void) {
    void *ctx;

    ctx = func_L39_004BEED8(0x34);
    if (ctx == 0) {
        func_L39_004BC6C8(0xB, 0xEA, 0x21, 0, 0);
    }
    return ctx;
}
/* localdecomp:end func_L39_004F1DB8 */

/* localdecomp:start func_L39_004F1E08 */
/* OpenSSL 0.9.6 X509_STORE_CTX_init (x509_vfy.c) */
typedef struct {
    void *ctx;
    s32 current_method;
    void *cert;
    void *untrusted;
    s32 depth;
    s32 valid;
    s32 last_untrusted;
    void *chain;
    s32 error;
    s32 error_depth;
    void *current_cert;
    struct { void *sk; s32 dummy; } ex_data;
} CTX_004F1E08;

extern void func_L39_004DEF48(void *, void *, void *);
extern void *D_L39_0046D500 __attribute__((section(".data")));
extern void *func_0011D534(void *, s32, u32);

void func_L39_004F1E08(CTX_004F1E08 *ctx, void *store, void *x509, void *chain) {
    ctx->ctx = store;
    ctx->current_method = 0;
    ctx->cert = x509;
    ctx->untrusted = chain;
    ctx->valid = 0;
    ctx->last_untrusted = 0;
    ctx->chain = 0;
    ctx->depth = 10;
    ctx->error = 0;
    ctx->error_depth = 0;
    ctx->current_cert = 0;
    func_0011D534(&ctx->ex_data, 0, 8);
    func_L39_004DEF48(D_L39_0046D500, ctx, &ctx->ex_data);
}
/* localdecomp:end func_L39_004F1E08 */

INCLUDE_ASM("asm/levels", func_L39_004F1E88);

/* localdecomp:start func_L39_004F1EC0 */
/* OpenSSL 0.9.6 X509_STORE_CTX_cleanup (x509_vfy.c) */
typedef struct {
    void *ctx;
    s32 current_method;
    void *cert;
    void *untrusted;
    s32 purpose;
    s32 trust;
    s32 check_time;
    void *chain;
    s32 pad20[3];
    struct { void *sk; s32 dummy; } ex_data;
} CTX_004F1EC0;

extern void func_L39_004CC510(void *, void *);
extern void func_L39_004F4818(void *);
extern void func_L39_004DEE70(void *, void *, void *);
extern void *D_L39_0046D500 __attribute__((section(".data")));
extern void *func_0011D534(void *, s32, u32);

void func_L39_004F1EC0(CTX_004F1EC0 *ctx) {
    if (ctx->chain != 0) {
        func_L39_004CC510(ctx->chain, func_L39_004F4818);
        ctx->chain = 0;
    }
    func_L39_004DEE70(D_L39_0046D500, ctx, &ctx->ex_data);
    func_0011D534(&ctx->ex_data, 0, 8);
}
/* localdecomp:end func_L39_004F1EC0 */

/* localdecomp:start func_L39_004F1F28 */
/* OpenSSL 0.9.6 X509_STORE_CTX setter of the field at 0x10 (depth) */
typedef struct { u8 pad[0x10]; s32 f10; } S_004F1F28;

void func_L39_004F1F28(S_004F1F28 *ctx, s32 v) {
    ctx->f10 = v;
}
/* localdecomp:end func_L39_004F1F28 */

/* localdecomp:start func_L39_004F1F30 */
typedef struct { u8 pad[0x24]; s32 f24; } S_004F1F30;

s32 func_L39_004F1F30(S_004F1F30 *a) {
    return a->f24;
}
/* localdecomp:end func_L39_004F1F30 */

/* localdecomp:start func_L39_004F1F38 */
typedef struct { u8 pad[0x24]; s32 f24; } S_004F1F38;

void func_L39_004F1F38(S_004F1F38 *a, s32 v) {
    a->f24 = v;
}
/* localdecomp:end func_L39_004F1F38 */

/* localdecomp:start func_L39_004F1F40 */
typedef struct { u8 pad[0x20]; s32 f20; } S_004F1F40;

s32 func_L39_004F1F40(S_004F1F40 *a) {
    return a->f20;
}
/* localdecomp:end func_L39_004F1F40 */

/* localdecomp:start func_L39_004F1F50 */
/* OpenSSL 0.9.6 X509_check_private_key (x509_cmp.c), a variant comparing key parameters as byte strings */
typedef struct { s32 pad[6]; void *pub_key; } DSA_004F1F50;
typedef struct { s32 type; s32 save_type; s32 references; void *pkey; } PKEY_004F1F50;

extern PKEY_004F1F50 *func_L39_004F18C0(void *);
extern s32 func_L39_004E1138(PKEY_004F1F50 *);
extern s32 func_L39_004EA4E0(void *, s32, void **, s32 *);
extern s32 func_0011D2EC(void *, void *, s32);
extern s32 func_L39_004FC9D0(void *, void *);

s32 func_L39_004F1F50(void *x, PKEY_004F1F50 *k) {
    PKEY_004F1F50 *xk;
    void *xp;
    s32 xn;
    void *kp;
    s32 kn;
    s32 ok = 0;
    s32 type;

    xk = func_L39_004F18C0(x);
    type = func_L39_004E1138(xk);
    if (type != func_L39_004E1138(k)) goto err;
    switch (type) {
    case 6:
        if (func_L39_004EA4E0(xk->pkey, 0x10, &xp, &xn) != 0) goto err;
        if (func_L39_004EA4E0(k->pkey, 0x10, &kp, &kn) != 0) goto err;
        if (xn != kn) goto err;
        if (func_0011D2EC(xp, kp, xn) != 0) goto err;
        if (func_L39_004EA4E0(xk->pkey, 0x11, &xp, &xn) != 0) goto err;
        if (func_L39_004EA4E0(k->pkey, 0x11, &kp, &kn) != 0) goto err;
        if (xn != kn) goto err;
        if (func_0011D2EC(xp, kp, xn) != 0) goto err;
        break;
    case 0x74:
        if (func_L39_004FC9D0(((DSA_004F1F50 *)xk->pkey)->pub_key, ((DSA_004F1F50 *)k->pkey)->pub_key) != 0) goto err;
        break;
    case 0x1C:
    default:
        goto err;
    }
    ok = 1;
err:
    return ok;
}
/* localdecomp:end func_L39_004F1F50 */

/* localdecomp:start func_L39_004F20E0 */
/* OpenSSL 0.9.6 X509_*_verify (x_all.c): ASN1_verify(i2d, a->sig_alg, a->signature, a->info, r) */
typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
} S_004F20E0;

extern s32 func_L39_004F2B50();
extern s32 func_L39_004FB710(s32 (*)(void *, unsigned char **), void *, void *, void *, void *);

s32 func_L39_004F20E0(S_004F20E0 *a, void *r) {
    return func_L39_004FB710(func_L39_004F2B50, a->f8, a->fC, a->f4, r);
}
/* localdecomp:end func_L39_004F20E0 */

/* localdecomp:start func_L39_004F2118 */
/* OpenSSL 0.9.6 d2i_X509_bio (x_all.c): ASN1_d2i_bio(X509_new, d2i_X509, bp, x509) */
extern void *func_L39_004F8EB8(void *(*)(void), void *, void *, void *);
extern void *func_L39_004F4760(void);
extern void *func_L39_004F4540();

void *func_L39_004F2118(void *bp, void *x509) {
    return func_L39_004F8EB8(func_L39_004F4760, func_L39_004F4540, bp, x509);
}
/* localdecomp:end func_L39_004F2118 */

/* localdecomp:start func_L39_004F2148 */
/* OpenSSL X509_dup: ASN1_dup(i2d_X509, d2i_X509, x) */
extern char *func_L39_004F9278(s32 (*i2d)(), char *(*d2i)(), char *x);
extern s32 func_L39_004FA5B0(void *, void *);
extern void *func_L39_004FA7F8(void *, u8 **, s64);

void *func_L39_004F2148(void *x) {
    return func_L39_004F9278(func_L39_004FA5B0, (char *(*)())func_L39_004FA7F8, x);
}
/* localdecomp:end func_L39_004F2148 */

/* localdecomp:start func_L39_004F2178 */
/* OpenSSL 0.9.6 X509_digest (x_all.c): ASN1_digest(i2d_X509, type, data, md, len) */
extern s32 func_L39_004F4460(s32, void **);
extern s32 func_L39_004F9158(s32 (*)(s32, void **), s32, s32, s32, s32);

s32 func_L39_004F2178(s32 data, s32 type, s32 md, s32 len) {
    return func_L39_004F9158(func_L39_004F4460, type, data, md, len);
}
/* localdecomp:end func_L39_004F2178 */

INCLUDE_ASM("asm/levels", func_L39_004F21B0);

INCLUDE_ASM("asm/levels", func_L39_004F2240);

/* localdecomp:start func_L39_004F23A0 */
typedef struct { s32 n; u8 **items; } L_004F23A0;
typedef struct {
    void *f0;
    void *f4;
    void *f8;
    s32 (*fC)(void *);
    s32 (*f10)(s32, void *);
} VT_004F23A0;
typedef struct {
    VT_004F23A0 *vt;
    void *f4;
    u8 *f8;
    s32 fC;
    s32 f10;
    s32 pad14;
    s32 f18;
    L_004F23A0 *list;
    s32 f20;
    s32 f24;
    void *f28;
} S_004F23A0;
typedef struct {
    s32 f0;
    u8 *item;
    s32 pad[2];
} Loc_004F23A0;

extern s32 func_L39_004F16C0(void *, void *);

extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern L_004F23A0 *func_L39_004CC228(s32);
extern s32 func_L39_004CC3E0(L_004F23A0 *, void *);
extern s32 func_L39_004BECF0(void *, s32, s32, void *, s32);
extern void *func_L39_004CC190(s32);
extern void func_L39_004CC538(void *);
extern void *func_L39_004CC800(void *);
extern void *func_L39_004CC408(L_004F23A0 *);
extern u8 *func_L39_00505CC0(void *, u8 *);
extern void *func_L39_00505C60(void *, u8 *);
extern void func_L39_00505FA8(void *);
extern s32 func_L39_005061D8(s32, L_004F23A0 *);
extern u8 *func_L39_004F16A0(void *);
extern s32 func_L39_004F2868(void *);
extern void func_L39_004F4818(void *);
extern s32 D_L39_004F2398(s32, void *);
extern u8 D_L39_00478D08[];

s32 func_L39_004F23A0(S_004F23A0 *ctx) {
    u8 *x;
    u8 *xtmp;
    void *sktmp;
    void *chain_ss;
    u8 *xn;
    Loc_004F23A0 obj;
    s32 depth;
    s32 i;
    s32 ok;
    s32 num;
    s32 (*cb)(s32, void *);

    chain_ss = 0;
    ok = 0;
    sktmp = 0;
    if (ctx->f8 == 0) {
        func_L39_004BC6C8(0xB, 0xEC, 0x9F, 0, 0);
        return -1;
    }
    cb = ctx->vt->f10;
    if (cb == 0) {
        cb = D_L39_004F2398;
    }
    if (ctx->list == 0) {
        ctx->list = func_L39_004CC228(0);
        if (ctx->list == 0 || func_L39_004CC3E0(ctx->list, ctx->f8) == 0) {
            func_L39_004BC6C8(0xB, 0xEC, 0x21, 0, 0);
            goto end;
        }
        func_L39_004BECF0(ctx->f8 + 0x14, 1, 3, D_L39_00478D08, 0x5C);
        ctx->f18 = 1;
    }
    if (ctx->fC != 0 && (sktmp = func_L39_004CC190(ctx->fC)) == 0) {
        func_L39_004BC6C8(0xB, 0xEC, 0x21, 0, 0);
        goto end;
    }
    depth = ctx->f10;
    num = ctx->list->n;
    x = ctx->list->items[num - 1];
    for (;;) {
        if (depth <= num) {
            break;
        }
        xn = func_L39_004F16A0(x);
        if (func_L39_004F16C0(func_L39_004CC800(x), xn) == 0) {
            break;
        }
        if (ctx->fC != 0) {
            xtmp = func_L39_00505CC0(sktmp, xn);
            if (xtmp != 0) {
                if (func_L39_004CC3E0(ctx->list, xtmp) == 0) {
                    func_L39_004BC6C8(0xB, 0xEC, 0x21, 0, 0);
                    goto end;
                }
                func_L39_004BECF0(xtmp + 0x14, 1, 3, D_L39_00478D08, 0x81);
                func_L39_00505C60(sktmp, xtmp);
                x = xtmp;
                num++;
                ctx->f18++;
                continue;
            }
        }
        break;
    }
    i = ctx->list->n;
    x = ctx->list->items[i - 1];
    if (func_L39_004F16C0(func_L39_004CC800(x), func_L39_004F16A0(x)) == 0) {
        if (ctx->list->n == 1) {
            ctx->f28 = x;
            ctx->f24 = 0x12;
            ctx->f20 = i - 1;
            ok = cb(0, ctx);
            if (ok == 0) {
                goto end;
            }
        } else {
            chain_ss = func_L39_004CC408(ctx->list);
            num--;
            ctx->f18--;
            x = ctx->list->items[num - 1];
        }
    }
    for (;;) {
        if (depth <= num) {
            break;
        }
        xn = func_L39_004F16A0(x);
        if (func_L39_004F16C0(func_L39_004CC800(x), xn) == 0) {
            break;
        }
        ok = func_L39_004F1BB8((CTX_004F1BB8 *)ctx, 1, xn, (OBJ_004F1BB8 *)&obj);
        if (ok != 1) {
            if (ok == -1) {
                func_L39_00505FA8(&obj);
                func_L39_004BC6C8(0xB, 0xEC, 0xA0, 0, 0);
                return ok;
            } else if (ok != 0) {
                func_L39_00505FA8(&obj);
                return ok;
            }
            break;
        }
        x = obj.item;
        if (func_L39_004CC3E0(ctx->list, obj.item) == 0) {
            func_L39_00505FA8(&obj);
            func_L39_004BC6C8(0xB, 0xEC, 0x21, 0, 0);
            return 0;
        }
        num++;
    }
    xn = func_L39_004F16A0(x);
    if (func_L39_004F16C0(func_L39_004CC800(x), xn) != 0) {
        if (chain_ss == 0 || func_L39_004F16C0(func_L39_004CC800(chain_ss), xn) != 0) {
            if (ctx->f18 < num) {
                ctx->f24 = 2;
            } else {
                ctx->f24 = 0x14;
            }
            ctx->f28 = x;
        } else {
            func_L39_004CC3E0(ctx->list, chain_ss);
            num++;
            ctx->f18 = num;
            ctx->f28 = chain_ss;
            ctx->f24 = 0x13;
            chain_ss = 0;
        }
        ctx->f20 = num - 1;
        ok = cb(0, ctx);
        if (ok == 0) {
            goto end;
        }
    }
    func_L39_005061D8(0, ctx->list);
    if (ctx->vt->fC != 0) {
        ok = ctx->vt->fC(ctx);
    } else {
        ok = func_L39_004F2868(ctx);
    }
    goto cleanup;
end:
    func_L39_005061D8(0, ctx->list);
cleanup:
    if (sktmp != 0) {
        func_L39_004CC538(sktmp);
    }
    if (chain_ss != 0) {
        func_L39_004F4818(chain_ss);
    }
    return ok;
}
/* localdecomp:end func_L39_004F23A0 */

/* localdecomp:start func_L39_004F2868 */
/* OpenSSL 0.9.6 internal_verify (x509_vfy.c), without the EVP_PKEY_free calls */
typedef struct { s32 n; void **data; } STACK_004F2868;
typedef struct { s32 pad[4]; s32 (*verify_cb)(s32, void *); } STORE_004F2868;
typedef struct { s32 pad[4]; s32 valid; } X509_004F2868;
typedef struct {
    STORE_004F2868 *ctx;
    s32 pad4[6];
    STACK_004F2868 *chain;
    s32 error_depth;
    s32 error;
    X509_004F2868 *current_cert;
} CTX_004F2868;

/* func_L39_004CC800, func_L39_004F16A0, func_L39_004F16C0, func_L39_004F18C0, func_L39_004F20E0
   and D_L39_004F2398 (the null callback) are declared earlier in the file */
extern void *func_L39_004F1918(void *);
extern void *func_L39_004F1928(void *);
extern s32 func_L39_005060F8(void *);

s32 func_L39_004F2868(void *arg) {
    CTX_004F2868 *ctx = arg;
    s32 i, ok, n;
    X509_004F2868 *xs, *xi;
    void *pkey;
    s32 (*cb)(s32, void *);

    cb = ctx->ctx->verify_cb;
    if (cb == 0) cb = D_L39_004F2398;

    n = ctx->chain->n;
    ctx->error_depth = n - 1;
    n--;
    xi = ctx->chain->data[n];
    if (func_L39_004F16C0(func_L39_004CC800(xi), func_L39_004F16A0(xi)) == 0) {
        xs = xi;
    } else {
        if (n <= 0) {
            ctx->error = 0x15;
            ctx->current_cert = xi;
            ok = cb(0, ctx);
            goto end;
        } else {
            n--;
            ctx->error_depth = n;
            xs = ctx->chain->data[n];
        }
    }

    while (n >= 0) {
        ctx->error_depth = n;
        if (!xs->valid) {
            if ((pkey = func_L39_004F18C0(xi)) == 0) {
                ctx->error = 6;
                ctx->current_cert = xi;
                ok = cb(0, ctx);
                if (!ok) goto end;
            }
            if (func_L39_004F20E0((S_004F20E0 *)xs, pkey) <= 0) {
                ctx->error = 7;
                ctx->current_cert = xs;
                ok = cb(0, ctx);
                if (!ok) goto end;
            }

            i = func_L39_005060F8(func_L39_004F1918(xs));
            if (i == 0) {
                ctx->error = 0xD;
                ctx->current_cert = xs;
                ok = cb(0, ctx);
                if (!ok) goto end;
            }
            if (i > 0) {
                ctx->error = 9;
                ctx->current_cert = xs;
                ok = cb(0, ctx);
                if (!ok) goto end;
            }
            xs->valid = 1;
        }

        i = func_L39_005060F8(func_L39_004F1928(xs));
        if (i == 0) {
            ctx->error = 0xE;
            ctx->current_cert = xs;
            ok = cb(0, ctx);
            if (!ok) goto end;
        }
        if (i < 0) {
            ctx->error = 0xA;
            ctx->current_cert = xs;
            ok = cb(0, ctx);
            if (!ok) goto end;
        }

        ctx->current_cert = xs;
        ok = cb(1, ctx);
        if (!ok) goto end;

        n--;
        if (n >= 0) {
            xi = xs;
            xs = ctx->chain->data[n];
        }
    }
    ok = 1;
end:
    return ok;
}
/* localdecomp:end func_L39_004F2868 */

INCLUDE_ASM("asm/levels", func_L39_004F2AC8);

/* localdecomp:start func_L39_004F2AE8 */
/* OpenSSL 0.9.6 style sk_value bounds check (X509v3_get_ext shape) */
typedef struct {
    s32 f0;
    STACK_004F1BB8 *sk;
} S_004F2AE8;

void *func_L39_004F2AE8(S_004F2AE8 *x, s32 loc) {
    if (x == 0 || loc >= x->sk->num || loc < 0) {
        return 0;
    }
    return x->sk->data[loc];
}
/* localdecomp:end func_L39_004F2AE8 */

LINKER_REMNANT("asm/levels", func_L39_004F2B28);

/* localdecomp:start func_L39_004F2B50 */
extern s32 func_L39_004F9340(void *, void *);
extern s32 func_L39_004FA1A0(s32, s32, s32);
extern s32 func_L39_00506300(void *, void *);
extern s32 func_L39_004FA5B0(void *, void *);
extern s32 func_L39_004F4110(void *, void *);
extern s32 func_L39_004F3928(void *, void *);
extern s32 func_L39_004F8A78(void *, void *);
extern s32 func_L39_004FACB0(void *, void *, void *, s32, s32);
extern void func_L39_004F9FF8(void *, s32, s32, s32, s32);
extern u8 D_L39_004F34E8[];

typedef struct {
    s32 *f0;
    void *f4;
    void *f8;
    void *fC;
    void *f10;
    void *f14;
    void *f18;
    u8 **f1C;
    u8 **f20;
    s32 **f24;
} S_004F2B50;

s32 func_L39_004F2B50(S_004F2B50 *arg0, u8 **arg1) {
    s32 t1 = 0;
    s32 t0 = 0;
    s32 ret;
    u8 *p;
    u8 *cur;
    s32 sum = 0;

    if (arg0 == 0) {
        return 0;
    }
    if (arg0->f0 != 0) {
        t0 = func_L39_004F9340(arg0->f0, 0);
        sum += func_L39_004FA1A0(1, t0, 0);
    }
    sum += func_L39_004F9340(arg0->f4, 0);
    sum += func_L39_00506300(arg0->f8, 0);
    sum += func_L39_004FA5B0(arg0->fC, 0);
    sum += func_L39_004F4110(arg0->f10, 0);
    sum += func_L39_004FA5B0(arg0->f14, 0);
    sum += func_L39_004F3928(arg0->f18, 0);
    if (arg0->f1C != 0) {
        sum += func_L39_004F8A78(arg0->f1C, 0);
    }
    if (arg0->f20 != 0) {
        sum += func_L39_004F8A78(arg0->f20, 0);
    }
    if (arg0->f24 != 0) {
        if (*arg0->f24 != 0) {
            t1 = func_L39_004FACB0(arg0->f24, 0, D_L39_004F34E8, 16, 0);
            sum += func_L39_004FA1A0(1, t1, 3);
        }
    }
    ret = func_L39_004FA1A0(1, sum, 16);
    if (arg1 == 0) {
        return ret;
    }
    cur = *arg1;
    func_L39_004F9FF8(&cur, 1, sum, 16, 0);
    if (arg0->f0 != 0) {
        func_L39_004F9FF8(&cur, 1, t0, 0, 0x80);
        func_L39_004F9340(arg0->f0, &cur);
    }
    func_L39_004F9340(arg0->f4, &cur);
    func_L39_00506300(arg0->f8, &cur);
    func_L39_004FA5B0(arg0->fC, &cur);
    func_L39_004F4110(arg0->f10, &cur);
    func_L39_004FA5B0(arg0->f14, &cur);
    func_L39_004F3928(arg0->f18, &cur);
    if (arg0->f1C != 0) {
        p = cur;
        func_L39_004F8A78(arg0->f1C, &cur);
        *p = (*p & 0x20) | 0x81;
    }
    if (arg0->f20 != 0) {
        p = cur;
        func_L39_004F8A78(arg0->f20, &cur);
        *p = (*p & 0x20) | 0x82;
    }
    if (arg0->f24 != 0) {
        if (*arg0->f24 != 0) {
            func_L39_004F9FF8(&cur, 1, t1, 3, 0x80);
            func_L39_004FACB0(arg0->f24, &cur, D_L39_004F34E8, 16, 0);
        }
    }
    *arg1 = cur;
    return ret;
}
/* localdecomp:end func_L39_004F2B50 */
