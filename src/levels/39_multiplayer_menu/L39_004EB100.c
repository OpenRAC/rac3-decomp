#include "common.h"

/* localdecomp:start func_L39_004EB100 */
/* log: v1 ssl3_output_cert_chain shape */
typedef struct {
    s32 num;
    void **data;
} SK_004EB100;

typedef struct {
    s32 length;
    u8 *data;
} BUF_004EB100;

typedef struct {
    u8 _p0[0x18];
    void *cert_store;
    u8 _p1C[0x110 - 0x1C];
    SK_004EB100 *extra_certs;
} CTX_004EB100;

typedef struct {
    u8 _p0[0x3C];
    BUF_004EB100 *init_buf;
    u8 _p40[0x88 - 0x40];
    SK_004EB100 *chain;
    u8 _p8C[0xDC - 0x8C];
    CTX_004EB100 *ctx;
} SSL_004EB100;

typedef struct {
    s32 type;
    void *x509;
} OBJ_004EB100;

extern s32 func_L39_004DB1C0(void *, s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void *func_L39_004BC198(void);
extern s32 func_L39_004BC1E0(void *, void *, void *, void *);
extern void *func_L39_004BBD50(void *);
extern s32 func_L39_004BC150(void *, s32, void *, OBJ_004EB100 *);
extern void func_L39_004BBBA0(void *);
extern s32 func_L39_004BBC30(void *, u8 **);
extern void *func_L39_004BBD98(void *);
extern s32 func_L39_004BBE70(void *, void *);
extern void func_L39_004BC270(void *);
extern void func_L39_004BC228(void *);

unsigned long func_L39_004EB100(SSL_004EB100 *s, void *x) {
    u8 *p;
    s32 n, i;
    unsigned long l = 7;
    BUF_004EB100 *buf;
    void *xs_ctx = 0;
    OBJ_004EB100 obj;

    buf = s->init_buf;
    if (!func_L39_004DB1C0(buf, 0x800)) {
        func_L39_004BC6C8(20, 148, 0x807, 0, 0);
        return 0;
    }
    if (x != 0) {
        if (s->ctx->cert_store != 0) {
            xs_ctx = func_L39_004BC198();
            if (xs_ctx == 0) {
                return 0;
            }
            func_L39_004BC1E0(xs_ctx, s->ctx->cert_store, 0, 0);
        }
        for (;;) {
            n = func_L39_004BBC30(x, 0);
            if (!func_L39_004DB1C0(buf, (s32)(n + l + 3))) {
                func_L39_004BC6C8(20, 148, 0x807, 0, 0);
                return 0;
            }
            p = &buf->data[l];
            p[0] = (u8)((n >> 16) & 0xff), p[1] = (u8)((n >> 8) & 0xff), p[2] = (u8)(n & 0xff), p += 3;
            func_L39_004BBC30(x, &p);
            l += n + 3;
            if (func_L39_004BBE70(func_L39_004BBD98(x), func_L39_004BBD50(x)) == 0) {
                break;
            }
            if (s->ctx->cert_store == 0 || s->chain != 0) {
                break;
            }
            i = func_L39_004BC150(xs_ctx, 1, func_L39_004BBD50(x), &obj);
            if (i <= 0) {
                break;
            }
            x = obj.x509;
            func_L39_004BBBA0(x);
        }
        if (s->ctx->cert_store != 0) {
            func_L39_004BC270(xs_ctx);
            func_L39_004BC228(xs_ctx);
        }
    }

    if (s->chain != 0) {
        for (i = 0; i < s->chain->num; i++) {
            x = s->chain->data[i];
            n = func_L39_004BBC30(x, 0);
            if (!func_L39_004DB1C0(buf, (s32)(n + l + 3))) {
                func_L39_004BC6C8(20, 148, 0x807, 0, 0);
                return 0;
            }
            p = &buf->data[l];
            p[0] = (u8)((n >> 16) & 0xff), p[1] = (u8)((n >> 8) & 0xff), p[2] = (u8)(n & 0xff), p += 3;
            func_L39_004BBC30(x, &p);
            l += n + 3;
        }
    }

    if (s->ctx->extra_certs != 0) {
        for (i = 0; i < s->ctx->extra_certs->num; i++) {
            x = s->ctx->extra_certs->data[i];
            n = func_L39_004BBC30(x, 0);
            if (!func_L39_004DB1C0(buf, (s32)(n + l + 3))) {
                func_L39_004BC6C8(20, 148, 0x807, 0, 0);
                return 0;
            }
            p = &buf->data[l];
            p[0] = (u8)((n >> 16) & 0xff), p[1] = (u8)((n >> 8) & 0xff), p[2] = (u8)(n & 0xff), p += 3;
            func_L39_004BBC30(x, &p);
            l += n + 3;
        }
    }

    l -= 7;
    p = &buf->data[4];
    p[0] = (u8)((l >> 16) & 0xff), p[1] = (u8)((l >> 8) & 0xff), p[2] = (u8)(l & 0xff), p += 3;
    l += 3;
    p = &buf->data[0];
    *(p++) = 0xB;
    p[0] = (u8)((l >> 16) & 0xff), p[1] = (u8)((l >> 8) & 0xff), p[2] = (u8)(l & 0xff), p += 3;
    l += 4;
    return l;
}
/* localdecomp:end func_L39_004EB100 */

INCLUDE_ASM("asm/levels", func_L39_004EB540);
