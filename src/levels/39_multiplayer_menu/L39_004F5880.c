#include "common.h"

/* localdecomp:start func_L39_004F5880 */
typedef struct S_004F5880 { void *buf; u32 n; } S_004F5880;
extern void *func_L39_004F7590(u32 n);

s32 func_L39_004F5880(S_004F5880 *out, s32 unused, u8 *len) {
    u32 n = *len;
    void *p = func_L39_004F7590(n);
    out->buf = p;
    if (p == 0) {
        return 0x10;
    }
    out->n = n;
    return 0;
}
/* localdecomp:end func_L39_004F5880 */

/* localdecomp:start func_L39_004F58D0 */
typedef struct S_004F58D0 { u32 *buf; u32 bs; } S_004F58D0;
typedef struct S2_004F58D0 { void *pad0; void *pad4; void (*fn)(void *, u32 *, u32 *); void (*dec)(void *, u32 *, u32 *); } S2_004F58D0;

s32 func_L39_004F58D0(S_004F58D0 *ctx, S2_004F58D0 *ci, void *key, u8 *out, u32 *outlen, u8 *in, u32 inlen) {
    u32 bs = ctx->bs;
    u32 *buf = ctx->buf;
    u32 total = 0;
    u32 i;
    u32 j;

    while (inlen >= bs) {
        for (i = 0, j = 0; i < bs; i += 8, j += 2) {
            buf[j] = in[i] + (in[i + 1] << 8) + (in[i + 2] << 16) + (in[i + 3] << 24);
            buf[j + 1] = in[i + 4] + (in[i + 5] << 8) + (in[i + 6] << 16) + (in[i + 7] << 24);
        }
        ci->fn(key, buf, buf);
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
/* localdecomp:end func_L39_004F58D0 */

/* localdecomp:start func_L39_004F5A78 */
typedef struct S_004F5A78 { u32 *buf; u32 bs; } S_004F5A78;
typedef struct S2_004F5A78 { void *pad0; void *pad4; void (*enc)(void *, u32 *, u32 *); void (*fn)(void *, u32 *, u32 *); } S2_004F5A78;

s32 func_L39_004F5A78(S_004F5A78 *ctx, S2_004F5A78 *ci, void *key, u8 *out, u32 *outlen, u8 *in, u32 inlen) {
    u32 bs = ctx->bs;
    u32 *buf = ctx->buf;
    u32 total = 0;
    u32 i;
    u32 j;

    while (inlen >= bs) {
        for (i = 0, j = 0; i < bs; i += 8, j += 2) {
            buf[j] = in[i] + (in[i + 1] << 8) + (in[i + 2] << 16) + (in[i + 3] << 24);
            buf[j + 1] = in[i + 4] + (in[i + 5] << 8) + (in[i + 6] << 16) + (in[i + 7] << 24);
        }
        ci->fn(key, buf, buf);
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
/* localdecomp:end func_L39_004F5A78 */
