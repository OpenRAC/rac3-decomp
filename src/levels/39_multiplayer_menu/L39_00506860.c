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
s32 func_L39_00507208();
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

/* localdecomp:start func_L39_00506C80 */
typedef struct S_00506C80 {
    u8 pad0[0x10];
    u8 f10[0x38];
    void *f48;
    u8 pad4C[0xC];
    void *f58;
    u8 pad5C[8];
    u32 f64;
    u8 pad68[4];
    u32 f6C;
    u8 *f70;
    u32 f74;
} S_00506C80;

s32 func_L39_00507510(void *, void *, void *);

s32 func_L39_00506C80(S_00506C80 *p, u8 *arg1, u32 *arg2, u32 arg3, s32 arg4, s32 arg5) {
    u32 i;
    u32 n;
    u32 pad;
    s32 r;

    switch (p->f64) {
    case 0:
        if (p->f6C != 0) {
            return 0x20D;
        }
        *arg2 = 0;
        break;
    case 1:
        if (arg3 < p->f74) {
            return 0x20D;
        }
        n = p->f6C;
        pad = p->f74 - n;
        for (i = n; i < p->f74; i++) {
            p->f70[i] = pad;
        }
        r = func_L39_005074C0(p->f10, p->f48, p->f58, arg1, arg2, p->f70, p->f74, arg5);
        if (r != 0) {
            return r;
        }
        p->f6C = 0;
        break;
    case 2:
        *arg2 = 0;
        break;
    default:
        return 0x217;
    }
    if ((r = func_L39_00507510(p->f10, p->f48, p->f58)) != 0) {
        return r;
    }
    return 0;
}
/* localdecomp:end func_L39_00506C80 */

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

/* localdecomp:start func_L39_00506F90 */
s32 func_L39_00507510(void *, void *, void *);
s32 func_L39_00506F90(u8 *arg0, u8 *buf, u32 *outlen, u32 max, s32 arg4, s32 arg5, s32 arg6) {
    u32 len;
    u32 pad;
    u32 n;
    u32 i;
    s32 r;

    switch (*(u32 *)(arg0 + 0x64)) {
    case 0:
        if (*(s32 *)(arg0 + 0x6C) != 0) {
            return 0x20D;
        }
        *outlen = 0;
        break;
    case 1:
        if (*(u32 *)(arg0 + 0x6C) != *(u32 *)(arg0 + 0x74)) {
            return 0x20D;
        }
        if (max < *(u32 *)(arg0 + 0x6C)) {
            return 0x218;
        }
        r = func_L39_005074C0(arg0 + 0x10, *(void **)(arg0 + 0x48), *(void **)(arg0 + 0x58), buf, outlen,
                              *(u8 **)(arg0 + 0x70), *(u32 *)(arg0 + 0x6C), arg5);
        if (r != 0) {
            return r;
        }
        len = *outlen;
        pad = buf[len - 1];
        if (pad == 0 || (n = *(u32 *)(arg0 + 0x74)) < pad) {
            return 0x20C;
        }
        for (i = n - pad; i < n; ) {
            if (buf[i++] != pad) {
                return 0x20C;
            }
        }
        *outlen = len - pad;
        *(s32 *)(arg0 + 0x6C) = 0;
        break;
    case 2:
        *outlen = 0;
        break;
    default:
        return 0x217;
    }
    if ((r = func_L39_00507510(arg0 + 0x10, *(void **)(arg0 + 0x48), *(void **)(arg0 + 0x58))) != 0) {
        return r;
    }
    return 0;
}
/* localdecomp:end func_L39_00506F90 */

/* localdecomp:start func_L39_005070D0 */
typedef struct {
    void *f0;
    s32 f4;
} S_005070D0;

extern void func_L39_004F7510(void *, void *, u32);
void func_L39_00507500(void *);

s32 func_L39_005070D0(u8 *arg0, S_005070D0 *arg1, S_005070D0 *arg2) {
    if (arg1->f4 != arg2->f4) {
        return 0x20D;
    }
    func_L39_004F7510(arg1->f0, arg2->f0, arg1->f4);
    func_L39_00507500(arg0 + 0x10);
    return 0;
}
/* localdecomp:end func_L39_005070D0 */

/* localdecomp:start func_L39_00507128 */
extern void *func_L39_004F7590(s32);
extern void func_L39_004F73F0(void *);
extern s32 func_L39_00507268();

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

/* localdecomp:start func_L39_005071C8 */
typedef struct S_005071C8 {
    u8 pad0[0x10];
    s32 (*get)(void *, s32 *);
} S_005071C8;

s32 func_L39_00508278(s32);

s32 func_L39_005071C8(void *arg0, s32 *arg1) {
    s32 r = (*(S_005071C8 **)((u8 *)arg0 + 0xC))->get(*(void **)((u8 *)arg0 + 0x1C), arg1);
    if (r != 0) {
        return func_L39_00508278(r);
    }
    return r;
}
/* localdecomp:end func_L39_005071C8 */

/* localdecomp:start func_L39_00507208 */
s32 func_L39_00508128(void *, void *, s32, void *, s32, s32, s32);

s32 func_L39_00507208(u8 *arg0, void *arg1, s32 arg2, s32 arg3) {
    return func_L39_00508128(arg0, arg0 + 0xC, 1, arg1, 0, arg2, arg3);
}
/* localdecomp:end func_L39_00507208 */

/* localdecomp:start func_L39_00507238 */
s32 func_L39_00508128(void *, void *, s32, void *, s32, s32, s32);

s32 func_L39_00507238(u8 *arg0, void *arg1, s32 arg2, s32 arg3) {
    return func_L39_00508128(arg0, arg0 + 0xC, 0, arg1, 0, arg2, arg3);
}
/* localdecomp:end func_L39_00507238 */

/* localdecomp:start func_L39_00507268 */
typedef struct S_00507268_vt {
    s32 (*f0)(s32 *, s32, s32);
    s32 (*f4)(s32, s32, s32, s32, void *, s32, s32);
    u8 pad8[0xC];
    s32 (*f14)(void *);
} S_00507268_vt;

typedef struct S_00507268_obj {
    u8 pad0[0xC];
    S_00507268_vt *vt;
} S_00507268_obj;

typedef struct S_00507268 {
    u8 pad0[8];
    s32 f8;
    u8 padC[4];
    s32 f10;
} S_00507268;

s32 func_L39_004F7460(void *, s32);
s32 func_L39_00508278(s32);

s32 func_L39_00507268(S_00507268 *p, s32 arg1, s32 arg2, S_00507268_obj *obj, s32 arg4, s32 arg5) {
    s32 len;
    s32 err;
    s32 r;

    err = obj->vt->f0(&len, arg1, p->f8);
    if (err != 0) {
        return func_L39_00508278(err);
    }
    r = func_L39_004F7460(&p->f10, len);
    if (r != 0) {
        return r;
    }
    if (obj->vt->f14 != 0) {
        err = obj->vt->f14(&p->f10);
        if (err != 0) {
            return func_L39_00508278(err);
        }
    }
    err = obj->vt->f4(p->f10, arg1, p->f8, arg2, obj, arg4, arg5);
    if (err != 0) {
        return func_L39_00508278(err);
    }
    return err;
}
/* localdecomp:end func_L39_00507268 */

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

/* localdecomp:start func_L39_00507420 */
typedef struct S_00507420 {
    u8 pad0[0x14];
    s32 (*get)(void *, s32 *);
} S_00507420;

s32 func_L39_00508278(s32);

s32 func_L39_00507420(void *arg0, s32 *arg1) {
    s32 r = (*(S_00507420 **)((u8 *)arg0 + 0xC))->get(*(void **)((u8 *)arg0 + 0x1C), arg1);
    if (r != 0) {
        return func_L39_00508278(r);
    }
    return r;
}
/* localdecomp:end func_L39_00507420 */

/* localdecomp:start func_L39_00507460 */
s32 func_L39_00508128(void *, void *, s32, void *, s32, s32, s32);

s32 func_L39_00507460(void *arg0, s32 arg1, s32 arg2) {
    return func_L39_00508128(arg0, (u8 *)arg0 + 0xC, 1, 0, 0, arg1, arg2);
}
/* localdecomp:end func_L39_00507460 */

INCLUDE_ASM("asm/levels", func_L39_00507490);

/* localdecomp:start func_L39_005074C0 */
typedef struct S_005074C0 {
    u8 pad0[0xC];
    s32 (*update)(void *, void *, void *, u8 *, u32 *, u8 *, u32, s32);
} S_005074C0;

s32 func_L39_00508278(s32);

s32 func_L39_005074C0(void *arg0, void *arg1, void *arg2, u8 *out, u32 *outl, u8 *in, u32 inl, s32 arg7) {
    s32 r = (*(S_005074C0 **)((u8 *)arg0 + 0xC))->update(*(void **)((u8 *)arg0 + 0x1C), arg1, arg2, out, outl, in, inl, arg7);
    if (r != 0) {
        return func_L39_00508278(r);
    }
    return r;
}
/* localdecomp:end func_L39_005074C0 */
