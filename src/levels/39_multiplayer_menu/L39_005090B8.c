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

/* localdecomp:start func_L39_00509388 */
s32 func_L39_00509388(S_005090B8 *s) {
    if (s->f8 != 0) {
        return 6;
    }
    s->f8 = 0;
    return 0;
}
/* localdecomp:end func_L39_00509388 */

/* localdecomp:start func_L39_005093A8 */
/* log (func_L39_005093A8): best 63 diff with the file's flags (this do-while(0) form gives retail's block layout).
 * - nested ifs / if-else chain / gotos: 74 diff, wrong layout (no "b test" at the top)
 * - do { ... break; } while (0) (also for(;;)/while(1)): 63 diff, layout right, registers differ
 * - inits inside the do: 72; pointer temp pa = &a: 71 (CSEs &a like retail, but hoists the -1 into $fp)
 * - (n + 7) / 8 in every form (temp, explicit if (x < 0), ?:, >> 31, s64, @ee29, -O1/-Os): the compiler
 *   always emits "addiu -1; slt; movz/movn"; retail has "slti x, 0; movn x, x+7" (known gap, see
 *   docs/research/us/permuter_todo.md func_0038F3F8). In the loop form the extra -1 gets a saved register.
 * - @ee29: 77-79 diff; vperm (240 s): base 66, best 54 by moving key->len reads (not a real improvement)
 */
typedef struct {
    u8 data[12];
} N_005093A8;

typedef struct S_005093A8 {
    u32 len;
    u8 pad4[8];
    N_005093A8 mod;
    N_005093A8 exp;
    s32 (*op)(N_005093A8 *, N_005093A8 *, N_005093A8 *, N_005093A8 *, void *);
} S_005093A8;

extern s32 func_L39_00511750(void *, u32, u32, u32 *, u8 *);

s32 func_L39_005093A8(S_005093A8 *key, u8 *out, u32 *outlen, u32 outmax, u8 *in, void *ctx) {
    N_005093A8 b;
    N_005093A8 a;
    s32 err;

    func_L39_005128E8(&a);
    func_L39_005128E8(&b);
    do {
        *outlen = key->len;
        if (*outlen > outmax) {
            err = 10;
            break;
        }
        if ((err = func_L39_005115B8(in, key->len, &b)) != 0) {
            break;
        }
        if ((err = key->op(&b, &key->exp, &key->mod, &a, ctx)) != 0) {
            break;
        }
        err = func_L39_00511750(&a, (func_L39_00511540(&key->mod) + 7) / 8, outmax, outlen, out);
    } while (0);
    func_L39_005128F8(&b);
    func_L39_005128F8(&a);
    if (err == 0) {
        return 0;
    }
    return func_L39_0050CA80(err);
}
/* localdecomp:end func_L39_005093A8 */

INCLUDE_ASM("asm/levels", func_L39_005094F8);

INCLUDE_ASM("asm/levels", func_L39_00509558);

/* localdecomp:start func_L39_00509DF8 */
s32 func_L39_00509DF8(s32 key, s32 count, s32 *list) {
    s32 i = 0;
    if (count > 0) {
        do {
            if (key == *list++) return 0;
        } while (++i < count);
    }
    return 1;
}
/* localdecomp:end func_L39_00509DF8 */

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
