#include "common.h"

/* localdecomp:start func_L39_004F5100 */
typedef struct S_004F5100 { void *pad0; u32 *iv; u32 *buf; u32 bs; } S_004F5100;
typedef struct S2_004F5100 { void *pad0; void *pad4; void (*enc)(void *, u32 *, u32 *); void (*dec)(void *, u32 *, u32 *); } S2_004F5100;

s32 func_L39_004F5100(S_004F5100 *ctx, S2_004F5100 *ci, void *key, u8 *out, u32 *outlen, u8 *in, u32 inlen) {
    u32 bs = ctx->bs;
    u32 *buf = ctx->buf;
    u32 nw = bs / 4;
    u32 total = 0;
    u32 i;
    u32 j;
    u32 k;

    while (inlen >= bs) {
        for (i = 0, j = 0; i < bs; i += 8, j += 2) {
            buf[j] = in[i] + (in[i + 1] << 8) + (in[i + 2] << 16) + (in[i + 3] << 24);
            buf[j + 1] = in[i + 4] + (in[i + 5] << 8) + (in[i + 6] << 16) + (in[i + 7] << 24);
        }
        for (k = 0; k < nw; k++) {
            buf[k] ^= ctx->iv[k];
        }
        ci->enc(key, buf, buf);
        for (k = 0; k < nw; k++) {
            ctx->iv[k] = buf[k];
        }
        for (i = 0, j = 0; i < bs; i += 8, j += 2) {
            out[i] = buf[j];
            out[i + 1] = buf[j] >> 8;
            out[i + 2] = buf[j] >> 16;
            out[i + 3] = buf[j] >> 24;
            out[i + 4] = buf[j + 1];
            out[i + 5] = buf[j + 1] >> 8;
            out[i + 6] = buf[j + 1] >> 16;
            out[i + 7] = buf[j + 1] >> 24;
        }
        inlen -= bs;
        in += bs;
        out += bs;
        total += bs;
    }
    *outlen = total;
    return 0;
}
/* localdecomp:end func_L39_004F5100 */

/* localdecomp:start func_L39_004F5320 */
typedef struct S_004F5320 { void *pad0; u32 *iv; u32 *buf; u32 bs; } S_004F5320;
typedef struct S2_004F5320 { void *pad0; void *pad4; void (*enc)(void *, u32 *, u32 *); void (*dec)(void *, u32 *, u32 *); } S2_004F5320;

s32 func_L39_004F5320(S_004F5320 *ctx, S2_004F5320 *ci, void *key, u8 *out, u32 *outlen, u8 *in, u32 inlen) {
    u32 bs = ctx->bs;
    u32 *buf = ctx->buf;
    u32 nw = bs / 4;
    u32 total = 0;
    u32 i;
    u32 j;
    u32 k;

    while (inlen >= bs) {
        for (i = 0, j = 0; i < bs; i += 8, j += 2) {
            buf[j] = in[i] + (in[i + 1] << 8) + (in[i + 2] << 16) + (in[i + 3] << 24);
            buf[j + 1] = in[i + 4] + (in[i + 5] << 8) + (in[i + 6] << 16) + (in[i + 7] << 24);
        }
        ci->dec(key, buf, buf);
        for (k = 0; k < nw; k++) {
            buf[k] ^= ctx->iv[k];
        }
        for (k = 0; k < nw; k++) {
            ctx->iv[k] = ((u32 *)in)[k];
        }
        for (i = 0, j = 0; i < bs; i += 8, j += 2) {
            out[i] = buf[j];
            out[i + 1] = buf[j] >> 8;
            out[i + 2] = buf[j] >> 16;
            out[i + 3] = buf[j] >> 24;
            out[i + 4] = buf[j + 1];
            out[i + 5] = buf[j + 1] >> 8;
            out[i + 6] = buf[j + 1] >> 16;
            out[i + 7] = buf[j + 1] >> 24;
        }
        inlen -= bs;
        in += bs;
        out += bs;
        total += bs;
    }
    *outlen = total;
    return 0;
}
/* localdecomp:end func_L39_004F5320 */
