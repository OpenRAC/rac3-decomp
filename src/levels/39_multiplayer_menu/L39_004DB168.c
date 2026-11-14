#include "common.h"

/* localdecomp:start func_L39_004DB168 */
typedef struct {
    s32 f0;
    void *data;
    s32 size;
} S_004DB168;

extern void func_0011D534(void *, s32, s32);
extern void func_L39_004BEF28(void *);

/* clear and free a buffer holder (memset then Free) */
void func_L39_004DB168(S_004DB168 *p) {
    if (p != 0) {
        if (p->data != 0) {
            func_0011D534(p->data, 0, p->size);
            func_L39_004BEF28(p->data);
        }
        func_L39_004BEF28(p);
    }
}
/* localdecomp:end func_L39_004DB168 */

INCLUDE_ASM("asm/levels", func_L39_004DB1C0);

LINKER_REMNANT("asm/levels", func_L39_004DB288);

/* localdecomp:start func_L39_004DB298 */
typedef struct {
    u32 f0;
    s32 f4;
    s32 f8;
} S_004DB298_src;

typedef struct {
    s32 f0;
    s32 f4;
    u64 f8;
    s32 f10;
} S_004DB298_out;

extern S_004DB298_src *func_L39_004F16B0(void *);

s32 func_L39_004DB298(void *a, S_004DB298_out *out) {
    S_004DB298_src *p;
    s32 r = 0;

    p = func_L39_004F16B0(a);
    if (p != 0 && out != 0) {
        out->f8 = p->f0;
        out->f10 = p->f8;
        out->f0 = p->f4;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L39_004DB298 */

/* localdecomp:start func_L39_004DB300 */
typedef s32 (*F_004DB300)(void *, s32, s32);

s32 func_L39_004DB300(void *a, s32 *args, F_004DB300 fn) {
    s32 r = 0;
    if (fn != 0) {
        r = fn(a, args[1], args[0]);
    }
    return r;
}
/* localdecomp:end func_L39_004DB300 */

/* localdecomp:start func_L39_004DB330 */
typedef struct {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x18];
} S_004DB330_ctx;

typedef struct {
    s32 f0;
    s32 *f4;
} S_004DB330_a;

typedef s32 (*F_004DB330)(S_004DB330_ctx *, s32);

extern void func_L39_004F1E08(S_004DB330_ctx *, s32, s32, S_004DB330_a *);
extern s32 func_L39_004EC7C8(void *);
extern void func_L39_004F1F28(S_004DB330_ctx *, s32);
extern s32 func_L39_004EC768(void);
extern void func_L39_004F1D78(S_004DB330_ctx *, s32, void *);
extern s32 func_L39_004F23A0(S_004DB330_ctx *, s32);
extern void func_L39_004F1EC0(S_004DB330_ctx *);

s32 func_L39_004DB330(void *a, S_004DB330_a *b, s32 c, F_004DB330 fn, s32 arg, s64 *out) {
    S_004DB330_ctx ctx;
    s32 r;

    func_L39_004F1E08(&ctx, c, *b->f4, b);
    if (func_L39_004EC7C8(a) >= 0) {
        func_L39_004F1F28(&ctx, func_L39_004EC7C8(a));
    }
    func_L39_004F1D78(&ctx, func_L39_004EC768(), a);
    if (fn != 0) {
        r = fn(&ctx, arg);
    } else {
        r = func_L39_004F23A0(&ctx, arg);
    }
    if (out != 0) {
        *out = ctx.f24;
    }
    func_L39_004F1EC0(&ctx);
    return r;
}
/* localdecomp:end func_L39_004DB330 */

/* localdecomp:start func_L39_004DB408 */
typedef struct {
    u32 f0;
    s32 f4;
    s32 f8;
} S_004DB408_src;

typedef struct {
    s32 f0;
    s32 f4;
    u64 f8;
    s32 f10;
} S_004DB408_out;

extern S_004DB408_src *func_L39_004F1928(void *);

s32 func_L39_004DB408(void *a, S_004DB408_out *out) {
    S_004DB408_src *p;
    s32 r = 0;

    p = func_L39_004F1928(a);
    if (p != 0 && out != 0) {
        out->f8 = p->f0;
        out->f10 = p->f8;
        out->f0 = p->f4;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L39_004DB408 */

/* localdecomp:start func_L39_004DB470 */
typedef struct {
    u32 f0;
    s32 f4;
    s32 f8;
} S_004DB470_src;

typedef struct {
    s32 f0;
    s32 f4;
    u64 f8;
    s32 f10;
} S_004DB470_out;

extern S_004DB470_src *func_L39_004F1918(void *);

s32 func_L39_004DB470(void *a, S_004DB470_out *out) {
    S_004DB470_src *p;
    s32 r = 0;

    p = func_L39_004F1918(a);
    if (p != 0 && out != 0) {
        out->f8 = p->f0;
        out->f10 = p->f8;
        out->f0 = p->f4;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L39_004DB470 */

/* localdecomp:start func_L39_004DB4D8 */
typedef struct {
    s32 f0;
    s32 f4;
} S_004DB4D8_src;

typedef struct {
    u8 pad0[0xC];
    S_004DB4D8_src *fC;
} S_004DB4D8;

typedef struct {
    s32 f0;
    s32 f4;
    s64 f8;
    s32 f10;
} S_004DB4D8_out;

extern s32 func_L39_004FA5B0(void *, void *);

s32 func_L39_004DB4D8(S_004DB4D8 *a, S_004DB4D8_out *out) {
    s32 r = 0;

    if (func_L39_004FA5B0(a, 0) > 0 && out != 0 && a->fC != 0) {
        r = 1;
        out->f8 = a->fC->f0;
        out->f10 = a->fC->f4;
        out->f0 = 0x2D;
    }
    return r;
}
/* localdecomp:end func_L39_004DB4D8 */

/* localdecomp:start func_L39_004DB558 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} S_004DB558_a;

typedef struct {
    u32 f0;
    s32 f4;
    s32 f8;
} S_004DB558_b;

typedef struct {
    s32 f0;
    S_004DB558_a *f4;
    S_004DB558_b *f8;
} S_004DB558;

typedef struct {
    s32 f0;
    s32 f4;
    s64 f8;
    s32 f10;
} S_004DB558_out;

s32 func_L39_004DB558(S_004DB558 *p, S_004DB558_out *a, S_004DB558_out *b) {
    s32 r = 0;
    if (a != 0) {
        a->f0 = 6;
        r = 1;
        a->f10 = p->f4->f10;
        a->f8 = p->f4->fC;
    }
    if (b != 0) {
        r = 1;
        b->f0 = p->f8->f4;
        b->f10 = p->f8->f8;
        b->f8 = p->f8->f0;
    }
    return r;
}
/* localdecomp:end func_L39_004DB558 */

/* localdecomp:start func_L39_004DB5C0 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} S_004DB5C0;

s32 func_L39_004DB5C0(S_004DB5C0 *p, s32 v) {
    p->f10 = v;
    return 1;
}
/* localdecomp:end func_L39_004DB5C0 */

/* localdecomp:start func_L39_004DB5D0 */
extern void *func_L39_004F39F0(void *, u8 **, s32);
extern void *func_L39_004F3CA8(void *);
extern void func_L39_004BC420(void *);
extern void func_L39_004BC4B0(void *);
extern void func_L39_004F3C40(void *);

void *func_L39_004DB5D0(void *unused, void **out, u8 **pp, s32 len) {
    void *x;
    void *r;

    x = func_L39_004F39F0(0, pp, len);
    if (x == 0) {
        return 0;
    }
    r = func_L39_004F3CA8(x);
    if (out != 0 && r != 0) {
        if (*out != 0) {
            func_L39_004BC420(*out);
        }
        *out = r;
        func_L39_004BC4B0(r);
    }
    func_L39_004F3C40(x);
    return r;
}
/* localdecomp:end func_L39_004DB5D0 */
