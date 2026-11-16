#include "common.h"

/* localdecomp:start func_L39_005090B8 */
typedef struct N_005090B8 {
    s32 w[3];
} N_005090B8;
typedef struct S_005090B8 {
    s32 len;
    void *buf;
    s32 f8;
    N_005090B8 n;
    N_005090B8 e;
} S_005090B8;
typedef struct In_005090B8 {
    u8 *n;
    s32 nlen;
    u8 *e;
    s32 elen;
} In_005090B8;

extern void func_L39_005128E8(void *);
extern void func_L39_005128F8(void *);
extern s32 func_L39_005115B8(u8 *, s32, void *);
extern s32 func_L39_005119F0(s32, void *);
extern s32 func_L39_00510F60(void *, void *);
extern s32 func_L39_00511540(void *);
extern void *func_L39_004F7590(s32);
extern s32 func_L39_0050CA80(s32);

s32 func_L39_005090B8(S_005090B8 *s, In_005090B8 *in) {
    N_005090B8 t;
    s32 r;

    func_L39_005128E8(&s->n);
    func_L39_005128E8(&s->e);
    func_L39_005128E8(&t);
    s->buf = 0;
    do {
        if ((r = func_L39_005115B8(in->n, in->nlen, &s->n)) != 0)
            break;
        if ((r = func_L39_005115B8(in->e, in->elen, &s->e)) != 0)
            break;
        if ((r = func_L39_005119F0(1, &t)) != 0)
            break;
        if (!func_L39_00510F60(&s->e, &t)) {
            r = 0x11;
            break;
        }
        s->len = (func_L39_00511540(&s->n) + 7) / 8;
        if ((s->buf = func_L39_004F7590(s->len)) == 0) {
            r = 0x10;
            break;
        }
        s->f8 = 0;
    } while (0);
    func_L39_005128F8(&t);
    if (r == 0) {
        return 0;
    }
    return func_L39_0050CA80(r);
}
/* localdecomp:end func_L39_005090B8 */

INCLUDE_ASM("asm/levels", func_L39_005091E8);

INCLUDE_ASM("asm/levels", func_L39_00509388);

INCLUDE_ASM("asm/levels", func_L39_005093A8);

INCLUDE_ASM("asm/levels", func_L39_005094F8);

INCLUDE_ASM("asm/levels", func_L39_00509558);

INCLUDE_ASM("asm/levels", func_L39_00509DF8);

/* localdecomp:start func_L39_00509E38 */
/* Ported from rac4-decomp/src/pal/game/00405D38.c. */

u32 func_L39_00509E38(s32 value) {
    u32 out;
    s32 top;
    s32 nib;
    s32 high;
    s32 i;

    out = 0;
    top = value >> 28;
    nib = 0xF;
    nib = top & nib;
    if ((top & 7) != 0) {
        high = nib - (nib & 8);
    } else {
        high = 5;
    }
    for (i = 0; i < 7; i++) {
        out |= ((value >> (i * 4)) & 7) << (i * 4);
    }
    return (out & 0xFFFFFFF) | (high << 28);
}

/* localdecomp:end func_L39_00509E38 */
