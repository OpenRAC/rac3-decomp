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

INCLUDE_ASM("asm/levels", func_L39_004EA230);
