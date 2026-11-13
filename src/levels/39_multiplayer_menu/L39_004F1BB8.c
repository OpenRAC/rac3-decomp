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

INCLUDE_ASM("asm/levels", func_L39_004F1D78);

INCLUDE_ASM("asm/levels", func_L39_004F1E08);

INCLUDE_ASM("asm/levels", func_L39_004F1EC0);

INCLUDE_ASM("asm/levels", func_L39_004F1F28);

INCLUDE_ASM("asm/levels", func_L39_004F20E0);

INCLUDE_ASM("asm/levels", func_L39_004F2118);

INCLUDE_ASM("asm/levels", func_L39_004F23A0);

INCLUDE_ASM("asm/levels", func_L39_004F2868);

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
