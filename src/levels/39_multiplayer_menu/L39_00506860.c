#include "common.h"

/* localdecomp:start func_L39_00506860 */
typedef struct S_00506860 {
    u8 pad0[0x10];
    u8 f10[0x2C];
    u8 f3C[0x30];
    s32 f6C;
    void *f70;
    s32 f74;
} S_00506860;

extern void *func_L39_004F7590(s32);
extern void func_L39_004F74E8(void *, s32, s32);
void func_L39_004F7620(void *);
s32 func_L39_00507208(void *, s32);
s32 func_L39_005071C8(void *, s32 *);
s32 func_L39_00507460(void *, s32, s32);
s32 func_L39_00507420(void *, s32 *);

s32 func_L39_00506860(S_00506860 *p, s32 arg1, s32 arg2, s32 arg3) {
    s32 a;
    s32 b;
    s32 r;

    r = func_L39_00507208(p->f3C, arg1);
    if (r != 0) {
        return r;
    }
    r = func_L39_005071C8(p->f3C, &a);
    if (r != 0) {
        return r;
    }
    r = func_L39_00507460(p->f10, arg2, arg3);
    if (r != 0) {
        return r;
    }
    r = func_L39_00507420(p->f10, &b);
    if (r != 0) {
        return r;
    }
    if (b != a) {
        return 0x20C;
    }
    if (p->f70 != 0) {
        func_L39_004F74E8(p->f70, 0, p->f74 * 2);
        func_L39_004F7620(p->f70);
    }
    p->f74 = b;
    p->f70 = func_L39_004F7590(b * 2);
    p->f6C = 0;
    if (p->f70 == 0) {
        r = 0x206;
    }
    return r;
}
/* localdecomp:end func_L39_00506860 */

INCLUDE_ASM("asm/levels", func_L39_00506958);

/* localdecomp:start func_L39_00506A80 */
typedef struct {
    u8 _p0[0x10];
    u8 cipher[0x38];
    void *f48;
    u8 _p4C[0xC];
    void *f58;
    u8 _p5C[0x8];
    s32 mode;
    u8 _p68[0x4];
    u32 bufLen;
    u8 *buf;
    u32 blockSize;
} S_00506A80;

extern s32 func_L39_005074C0(void *, void *, void *, u8 *, u32 *, u8 *, u32, s32);
extern void func_L39_004F7510(void *, void *, u32);

s32 func_L39_00506A80(S_00506A80 *ctx, u8 *out, u32 *outl, u32 outSize, u8 *in, u32 inl, s32 arg6, s32 arg7) {
    u32 bufLen;
    u32 bs;
    u32 total;
    u32 n;
    u8 *src;
    u8 *op;
    s32 r;
    u32 done;
    u32 used;
    s32 mode;

    *outl = 0;
    mode = ctx->mode;
    done = 0;
    bufLen = ctx->bufLen;
    bs = ctx->blockSize;
    if (mode == 2) {
        if (outSize < inl) {
            return 0x218;
        }
        return func_L39_005074C0(ctx->cipher, ctx->f48, ctx->f58, out, outl, in, inl, arg7);
    }
    total = bufLen + inl;
    if (total < bs) {
        func_L39_004F7510(ctx->buf + bufLen, in, inl);
        ctx->bufLen += inl;
        return 0;
    }
    n = total / bs * bs;
    if (outSize < n) {
        return 0x218;
    }
    op = out;
    done = 0;
    src = in;
    if (bufLen != 0) {
        src = ctx->buf;
        func_L39_004F7510(src + bufLen, in, bs - bufLen);
        r = func_L39_005074C0(ctx->cipher, ctx->f48, ctx->f58, op, &done, src, bs, arg7);
        if (r != 0) {
            return r;
        }
        src = in + bs - bufLen;
        used = done;
        op += used;
        *outl = used;
    } else {
        used = 0;
    }
    if (used < n) {
        r = func_L39_005074C0(ctx->cipher, ctx->f48, ctx->f58, op, &done, src, n - used, arg7);
        if (r != 0) {
            return r;
        }
        *outl += done;
    }
    if (n < total) {
        bufLen = total - n;
        func_L39_004F7510(ctx->buf, in + inl - bufLen, bufLen);
        ctx->bufLen = bufLen;
    } else {
        ctx->bufLen = 0;
    }
    return 0;
}
/* localdecomp:end func_L39_00506A80 */

INCLUDE_ASM("asm/levels", func_L39_00506C80);

/* localdecomp:start func_L39_00506D78 */
typedef struct {
    u8 _p0[0x10];
    u8 cipher[0x38];
    void *f48;
    u8 _p4C[0xC];
    void *f58;
    u8 _p5C[0x8];
    s32 mode;
    u8 _p68[0x4];
    u32 bufLen;
    u8 *buf;
    u32 blockSize;
} S_00506D78;

extern s32 func_L39_005074C0(void *, void *, void *, u8 *, u32 *, u8 *, u32, s32);
extern void func_L39_004F7510(void *, void *, u32);

s32 func_L39_00506D78(S_00506D78 *ctx, u8 *out, u32 *outl, u32 outSize, u8 *in, u32 inl, s32 arg6, s32 arg7) {
    u32 bufLen;
    u32 bs;
    u32 total;
    u32 n;
    u8 *src;
    u8 *op;
    s32 r;
    u32 done;
    u32 used;
    u32 pad;
    s32 mode;

    *outl = 0;
    done = 0;
    bufLen = ctx->bufLen;
    total = bufLen + inl;
    mode = ctx->mode;
    bs = ctx->blockSize;
    if (mode == 2) {
        if (outSize < inl) {
            return 0x218;
        }
        return func_L39_005074C0(ctx->cipher, ctx->f48, ctx->f58, out, outl, in, inl, arg7);
    }
    pad = (mode == 0);
    if (total <= bs - pad) {
        func_L39_004F7510(ctx->buf + bufLen, in, inl);
        ctx->bufLen += inl;
        return 0;
    }
    n = total - (mode != 0);
    n = n / bs * bs;
    if (outSize < n) {
        return 0x218;
    }
    op = out;
    done = 0;
    src = in;
    if (bufLen != 0) {
        src = ctx->buf;
        func_L39_004F7510(src + bufLen, in, bs - bufLen);
        r = func_L39_005074C0(ctx->cipher, ctx->f48, ctx->f58, op, &done, src, bs, arg7);
        if (r != 0) {
            return r;
        }
        src = in + bs - bufLen;
        used = done;
        op += used;
        *outl = used;
    } else {
        used = 0;
    }
    if (used < n) {
        r = func_L39_005074C0(ctx->cipher, ctx->f48, ctx->f58, op, &done, src, n - used, arg7);
        if (r != 0) {
            return r;
        }
        *outl += done;
    }
    if (n < total) {
        bufLen = total - n;
        func_L39_004F7510(ctx->buf, in + inl - bufLen, bufLen);
        ctx->bufLen = bufLen;
    } else {
        ctx->bufLen = 0;
    }
    return 0;
}
/* localdecomp:end func_L39_00506D78 */

INCLUDE_ASM("asm/levels", func_L39_00506F90);

INCLUDE_ASM("asm/levels", func_L39_005070D0);

/* localdecomp:start func_L39_00507128 */
extern void *func_L39_004F7590(s32);
extern void func_L39_004F73F0(void *);
extern void func_L39_00507268(void);

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    void (*f18)(void);
    u8 f1C[0xC];
} S_00507128;

S_00507128 *func_L39_00507128(S_00507128 *o, s32 a1, s32 a2, s32 a3) {
    if (o == 0) {
        o = func_L39_004F7590(sizeof(S_00507128));
        if (o == 0) return o;
    }
    o->f4 = a1; o->f0 = 0; func_L39_004F73F0(o->f1C);
    o->f18 = func_L39_00507268; o->f10 = a2; o->f14 = a3;
    return o;
}
/* localdecomp:end func_L39_00507128 */

/* localdecomp:start func_L39_005071B0 */
void func_L39_004F7410(void *);

void func_L39_005071B0(void *arg0) {
    func_L39_004F7410((u8 *)arg0 + 0x1C);
}
/* localdecomp:end func_L39_005071B0 */

INCLUDE_ASM("asm/levels", func_L39_005071C8);

INCLUDE_ASM("asm/levels", func_L39_00507208);

/* localdecomp:start func_L39_00507238 */
s32 func_L39_00508128(void *, void *, s32, void *, s32, s32, s32);

s32 func_L39_00507238(u8 *arg0, void *arg1, s32 arg2, s32 arg3) {
    return func_L39_00508128(arg0, arg0 + 0xC, 0, arg1, 0, arg2, arg3);
}
/* localdecomp:end func_L39_00507238 */

INCLUDE_ASM("asm/levels", func_L39_00507268);

/* localdecomp:start func_L39_00507378 */
extern void *func_L39_004F7590(s32);
extern void func_L39_004F73F0(void *);
extern void func_L39_005075D0(void);

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    void (*f18)(void);
    u8 f1C[0xC];
    s32 f28;
} S_00507378;

S_00507378 *func_L39_00507378(S_00507378 *o, s32 a1, s32 a2, s32 a3) {
    if (o == 0) {
        o = func_L39_004F7590(sizeof(S_00507378));
        if (o == 0) return o;
    }
    o->f4 = a1;
    o->f0 = 0;
    func_L39_004F73F0(o->f1C);
    o->f18 = func_L39_005075D0;
    o->f10 = a2;
    o->f14 = a3;
    o->f28 = 0;
    return o;
}
/* localdecomp:end func_L39_00507378 */

/* localdecomp:start func_L39_00507408 */
void func_L39_004F7410(void *);

void func_L39_00507408(void *arg0) {
    func_L39_004F7410((u8 *)arg0 + 0x1C);
}
/* localdecomp:end func_L39_00507408 */

INCLUDE_ASM("asm/levels", func_L39_00507420);

INCLUDE_ASM("asm/levels", func_L39_00507460);

INCLUDE_ASM("asm/levels", func_L39_00507490);

INCLUDE_ASM("asm/levels", func_L39_005074C0);
