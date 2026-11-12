#include "common.h"

typedef struct S_00504410 {
    u8 pad[0x20];
    u8 *f20;
    void (*f24)(void);
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
} S_00504410;

/* localdecomp:start func_L39_005045C0 */
typedef struct S_005045C0 {
    s32 num;
    s32 length;
    u8 enc_data[80];
    s32 line_num;
    s32 expect_nl;
} S_005045C0;

extern u8 D_L39_0046EB18[];
extern s32 func_L39_005047E8(u8 *t, u8 *f, s32 n);

/* OpenSSL's EVP_DecodeUpdate */
s32 func_L39_005045C0(S_005045C0 *ctx, u8 *out, s32 *outl, u8 *in, s32 inl) {
    s32 seof = -1, eof = 0, rv = -1, ret = 0, i, v, tmp, n, ln, exp_nl;
    u8 *d;

    n = ctx->num;
    d = ctx->enc_data;
    ln = ctx->line_num;
    exp_nl = ctx->expect_nl;

    if ((inl == 0) || ((n == 0) && (D_L39_0046EB18[in[0] & 0x7F] == 0xF2))) {
        rv = 0;
        goto end;
    }

    for (i = 0; i < inl; i++) {
        if (ln >= 80) {
            rv = -1;
            goto end;
        }
        tmp = *(in++);
        v = D_L39_0046EB18[tmp & 0x7F];
        if (!((v | 0x13) == 0xF3)) {
            d[n++] = tmp;
            ln++;
        } else if (v == 0xFF) {
            rv = -1;
            goto end;
        }
        if (tmp == '=') {
            if (seof == -1) seof = n;
            eof++;
        }
        if (v == 0xF0) {
            ln = 0;
            if (exp_nl) {
                exp_nl = 0;
                continue;
            }
        }
        exp_nl = 0;
        if (((i + 1) == inl) && (((n & 3) == 0) || eof)) {
            v = 0xF2;
        }
        if ((v == 0xF2) || (n >= 64)) {
            if ((v != 0xF2) && (n >= 64)) exp_nl = 1;
            if (n > 0) {
                v = func_L39_005047E8(out, d, n);
                if (v < 0) {
                    rv = 0;
                    goto end;
                }
                n = 0;
                ret += (v - eof);
            } else {
                eof = 1;
                v = 0;
            }
            if ((v < ctx->length) && eof) {
                rv = 0;
                goto end;
            } else {
                ctx->length = v;
            }
            if (seof >= 0) {
                rv = 0;
                goto end;
            }
            out += v;
        }
    }
    rv = 1;
end:
    *outl = ret;
    ctx->num = n;
    ctx->line_num = ln;
    ctx->expect_nl = exp_nl;
    return rv;
}
/* localdecomp:end func_L39_005045C0 */
