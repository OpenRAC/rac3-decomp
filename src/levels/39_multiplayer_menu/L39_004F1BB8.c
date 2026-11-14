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

INCLUDE_ASM("asm/levels", func_L39_004F1CA0);

INCLUDE_ASM("asm/levels", func_L39_004F1CE0);

INCLUDE_ASM("asm/levels", func_L39_004F1D30);

INCLUDE_ASM("asm/levels", func_L39_004F1D78);

INCLUDE_ASM("asm/levels", func_L39_004F1D98);

INCLUDE_ASM("asm/levels", func_L39_004F1DB8);

INCLUDE_ASM("asm/levels", func_L39_004F1E08);

INCLUDE_ASM("asm/levels", func_L39_004F1E88);

INCLUDE_ASM("asm/levels", func_L39_004F1EC0);

INCLUDE_ASM("asm/levels", func_L39_004F1F28);

INCLUDE_ASM("asm/levels", func_L39_004F1F30);

INCLUDE_ASM("asm/levels", func_L39_004F1F38);

INCLUDE_ASM("asm/levels", func_L39_004F1F40);

INCLUDE_ASM("asm/levels", func_L39_004F1F50);

INCLUDE_ASM("asm/levels", func_L39_004F20E0);

INCLUDE_ASM("asm/levels", func_L39_004F2118);

INCLUDE_ASM("asm/levels", func_L39_004F2148);

INCLUDE_ASM("asm/levels", func_L39_004F2178);

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

INCLUDE_ASM("asm/levels", func_L39_004F2868);

INCLUDE_ASM("asm/levels", func_L39_004F2AC8);

INCLUDE_ASM("asm/levels", func_L39_004F2AE8);

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
