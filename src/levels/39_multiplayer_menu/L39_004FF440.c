#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

/* declared by functions of L39_004FB668.c, which this file was cut from */
extern void *func_L39_004BEED8(s32);

/* localdecomp:start func_L39_004FF440 */
typedef struct { char _p[0x10]; s32 f10; s32 f14; s32 f18; } S_004FF440;
extern void func_L39_0050B6F0(s32);
extern void func_L39_004BEF28(void *);
s32 func_L39_004FF440(S_004FF440 *p) {
    func_L39_0050B6F0(p->f10);
    if (p->f14 != 0) func_L39_004BEF28((void *)p->f14);
    if (p->f18 != 0) func_L39_004BEF28((void *)p->f18);
    func_L39_004BEF28(p);
    return 0;
}
/* localdecomp:end func_L39_004FF440 */

INCLUDE_ASM("asm/levels", func_L39_004FF4A0);

INCLUDE_ASM("asm/levels", func_L39_004FF5A0);

/* localdecomp:start func_L39_004FFAF0 */
typedef struct { s32 v[5]; } S_004FFAF0_ent;
typedef struct { s32 n; S_004FFAF0_ent e[1]; } S_004FFAF0;
extern s32 func_L39_0050B8C8(void *, s32, void *);
extern s32 func_L39_004FCFD0(void *, s32, s32, void *);
extern s32 func_L39_004FBED8(void *, void *, s32, void *);

s32 func_L39_004FFAF0(void *a, s32 b, s32 c, s32 d, S_004FFAF0 *e) {
    s32 r = 0;
    S_004FFAF0_ent *slot = &e->e[e->n++];
    s32 ok;

    if (b == c) {
        ok = func_L39_0050B8C8(slot, c, e);
    } else {
        ok = func_L39_004FCFD0(slot, b, c, e);
    }
    if (ok) {
        r = func_L39_004FBED8(a, slot, d, e) != 0;
    }
    e->n--;
    return r;
}
/* localdecomp:end func_L39_004FFAF0 */

INCLUDE_ASM("asm/levels", func_L39_004FFBB0);

/* localdecomp:start func_L39_004FFD58 */
extern void *func_L39_004BEED8(s32 n);
extern s32 func_L39_004E4FC8(void *rng, unsigned char *buf, s32 n);
extern void *func_L39_004FC780(unsigned char *s, s32 len, void *ret);
extern void func_0011D534(void *, s32, s32);
extern void func_L39_004BEF28(void *p);

/* bnrand */
s32 func_L39_004FFD58(void *rnd, void *rng, s32 bits, s32 top, s32 bottom) {
    unsigned char *buf;
    s32 ret = 0, bit, bytes, mask;

    bytes = (bits + 7) / 8;
    bit = (bits - 1) % 8;
    mask = 0xff << bit;

    buf = func_L39_004BEED8(bytes + 1);
    if (buf == 0) {
        goto err;
    }
    func_L39_004E4FC8(rng, buf, bytes + 1);
    if (top) {
        if (bit == 0) {
            buf[0] = 1;
            if (bytes > 1) {
                buf[1] |= 0x80;
            }
        } else {
            buf[0] |= (3 << (bit - 1));
            buf[0] &= ~(mask << 1);
        }
    } else {
        buf[0] |= (1 << bit);
        buf[0] &= ~(mask << 1);
    }
    if (bottom) {
        buf[bytes - 1] |= 1;
    }
    ret = func_L39_004FC780(buf, bytes, rnd) != 0;
    func_0011D534(buf, 0, bytes);
    func_L39_004BEF28(buf);
err:
    return ret;
}
/* localdecomp:end func_L39_004FFD58 */

INCLUDE_ASM("asm/levels", func_L39_004FFEE0);

INCLUDE_ASM("asm/levels", func_L39_005000BC);
