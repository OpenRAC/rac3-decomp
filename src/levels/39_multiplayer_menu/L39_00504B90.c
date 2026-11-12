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

/* localdecomp:start func_L39_00504B90 */
typedef struct {
    s32 f0;
    s32 f4;
} S_00504B90_A;

typedef struct {
    S_00504B90_A *f0;
    s32 f4;
    s32 f8;
    u8 pad[0x4C - 0xC];
    u8 f4C[1];
} S_00504B90;

extern void *func_0011D380(void *, void *, s32);
extern void func_L39_004DE6D0(S_00504B90 *, s32, s32 *, u8 *, s32);

void func_L39_00504B90(S_00504B90 *arg0, s32 arg1, s32 *arg2, u8 *arg3, s32 arg4) {
    s32 n;
    s32 flag = 0;

    *arg2 = 0;
    if (arg4 == 0) {
        return;
    }
    n = arg0->f0->f4;
    if (n >= 2) {
        if ((arg4 + arg0->f8) % n == 0) {
            if (arg4 < n) {
                func_0011D380((u8 *)(arg0->f8 + (s32)arg0) + 0x4C, arg3, arg4);
                arg0->f8 = n;
                *arg2 = 0;
                return;
            }
            flag = 1;
            arg4 -= n;
        }
    }
    func_L39_004DE6D0(arg0, arg1, arg2, arg3, arg4);
    if (flag) {
        func_0011D380(arg0->f4C, arg3 + arg4, n);
        arg0->f8 = n;
    }
}
/* localdecomp:end func_L39_00504B90 */

/* localdecomp:start func_L39_00504C80 */
/* Clash fix: uses the file's S_00504B90 types and its func_L39_004DE6D0 declaration (second argument cast to s32). */
/* from OpenSSL's EVP_DecryptFinal (0.9.6 shape) */
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_00504C80(S_00504B90 *ctx, u8 *out, s32 *outl) {
    s32 i, n;
    s32 b;

    *outl = 0;
    b = ((s32 *)(*(s32 *)ctx))[1];
    if (b > 1) {
        if (ctx->f8 != b) {
            func_L39_004BC6C8(6, 0x6F, 0x79, 0, 0);
            return 0;
        }
        func_L39_004DE6D0(ctx, (s32)ctx->f4C, &n, ctx->f4C, 0);
        if (n != b) {
            return 0;
        }
        n = ctx->f4C[b - 1];
        if (n > b) {
            func_L39_004BC6C8(6, 0x6F, 0x74, 0, 0);
            return 0;
        }
        for (i = 0; i < n; i++) {
            if (ctx->f4C[--b] != n) {
                func_L39_004BC6C8(6, 0x6F, 0x74, 0, 0);
                return 0;
            }
        }
        n = ctx->f0->f4 - n;
        for (i = 0; i < n; i++) {
            out[i] = ctx->f4C[i];
        }
        *outl = n;
    } else {
        *outl = 0;
    }
    return 1;
}
/* localdecomp:end func_L39_00504C80 */
