#include "common.h"

/* localdecomp:start func_L39_004EA080 */
/* log: v1 digest-mix shape */
typedef struct {
    u8 state[0x18];
    u8 *buf;
    u32 count;
    void *md;
    void *ctx;
} ST_004EA080;

typedef struct {
    u8 _p0[0xC];
    ST_004EA080 *st;
} X_004EA080;

extern void *func_L39_004DE940(void);
extern s32 func_L01_00494120(void *);
extern s32 func_L39_004DD690(void *, void *);
extern void func_L39_004DD778(void *, void *, s32);
extern void func_L39_004DD7A8(void *, u8 *, s32 *);
extern void func_L39_004DE9B8(void *);

s32 func_L39_004EA080(X_004EA080 *x, void *data, s32 num) {
    ST_004EA080 *st = x->st;
    void *ctx = st->ctx;
    u8 md[0x20];
    s32 len;
    s32 n, i, a, b;

    if (ctx == 0) {
        ctx = func_L39_004DE940();
        if (ctx == 0) {
            return 0;
        }
    }
    n = func_L01_00494120(st->md);
    func_L39_004DD690(ctx, st->md);
    func_L39_004DD778(ctx, data, num);
    func_L39_004DD778(ctx, st->state, 0x18);
    func_L39_004DD778(ctx, st->buf, 0x18);
    func_L39_004DD778(ctx, &st->count, 4);
    st->count++;
    func_L39_004DD7A8(ctx, md, &len);
    a = (st->count * (n / 2)) % 0x18;
    b = (a + n / 2) % 0x18;
    for (i = 0; i < n / 2; i++) {
        st->state[(a + i) % 0x18] ^= md[i];
        st->buf[(b + i) % 0x18] ^= md[i + n / 2];
    }
    if (st->ctx == 0) {
        func_L39_004DE9B8(ctx);
    }
    return num;
}
/* localdecomp:end func_L39_004EA080 */

/* localdecomp:start func_L39_004EA230 */
typedef struct {
    u64 w[3];
} K_004EA230;

typedef struct {
    K_004EA230 state;
    u8 *buf;
    u32 count;
    void *md;
    void *ctx;
    u64 counter;
    s32 flags;
} ST_004EA230;

typedef struct {
    u8 _p0[0xC];
    ST_004EA230 *st;
} X_004EA230;

extern X_004EA230 D_L39_0046D398;
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern s32 func_L39_004ECA10(void);

s32 func_L39_004EA230(X_004EA230 *x, s32 cmd, void *arg) {
    ST_004EA230 *st;
    ST_004EA230 *src;
    u64 seed;

    switch (cmd) {
    case 1:
        if (x == 0) {
            x = &D_L39_0046D398;
        }
        st = func_L39_004BEED8(0x38);
        if (st == 0) {
            return 1;
        }
        src = x->st;
        st->buf = src->buf;
        st->state = src->state;
        st->counter = src->counter;
        st->count = 0;
        st->md = src->md;
        st->ctx = func_L39_004DE940();
        st->flags = cmd;
        ((X_004EA230 *)arg)->st = st;
        return 0;
    case 2:
        if (x == 0) {
            x = &D_L39_0046D398;
        }
        st = x->st;
        if (st == 0) {
            return 0;
        }
        if (st->ctx != 0) {
            func_L39_004DE9B8(st->ctx);
            st->ctx = 0;
        }
        if (st->flags & 1) {
            func_L39_004BEF28(x->st);
        }
        return 0;
    case 3:
        st = x->st;
        if (arg == 0) {
            return 0;
        }
        *(u64 *)arg = st->counter;
        return 0;
    case 0x10:
        st = x->st;
        seed = func_L39_004ECA10();
        func_L39_004EA080((X_004EA080 *)x, &seed, 8);
        st->counter++;
        return 0;
    }
    return 0;
}
/* localdecomp:end func_L39_004EA230 */
