/* near miss (round 19 worker J5B): 4 real rows of 225 words (check.py shows 6 raw diffs: 2 more are the jump table's `lui`/`addiu`, a .rodata relocation it cannot
 * resolve) with the file's flags. A particle that follows a target object (q->tgt): kill tests (func_0038CB00, the target's flag byte), the offset from a matrix
 * (func_003C2EC0 + func_0038D000) or from the target's position, a seven-way `switch` on q->bC (a jump table, cases 1..7: the direction to the target normalised,
 * or +/- one row of the target's matrix), a dot product with the direction to func_L01_001E29C0 that sets the alpha, and a pull towards that point.
 * Written from the retail listing (225 words, 73 -> 4 rows). What fixed most: the target arm FIRST and the NULL-target copy last (retail lays the null arm out at the
 * end), no `dir` pointer variable (`&v[2]` written out: gcse's PRE then puts `addiu $s2,$sp,0x20` into the range-check branch's slot and into every case, as retail),
 * `f = -func_0038CE68(...); f = f * 1.25f + 0.05f;` as two statements (f in $f3), and in the alpha arm `t = p->rgba & 0xFF000000; a = t >> 24; g = (f32)a * f;
 * p->rgba = (p->rgba & 0xFFFFFF) | ((s32)g << 24);` (the second read of p->rgba gives retail's `move $a0,$v0` copy through gcse).
 * Left (4 words): the else arm of `if (q->bF != 0)`: retail has the 0xFFFFFF mask in $v0 (its `lui $v0,0xff` sits in the delay slot of the bF test) and the
 * `mfc1` result in $v1; this C has the two swapped (mask as a variable, statement order, a float temp, the arms swapped: no change).
 * Escalation NM7 (about 45 compiles and toys, nothing moved): the 4 rows stay. What was proved: (1) the scheduled insns of that arm are the same for every
 * spelling (sched1 dump, verbose-5: lui/ori of the mask at clock 1-2, lw, mult at 3, `and` at 4, the `fix` insn (cvt.w.s + mfc1 with an SI scratch) at 6),
 * so the local allocator sees one block whatever the source says; (2) it allocates the {fix result, sll} chain (4 refs over 2 insns, priority 2.0) before the
 * mask (4 refs over 4 insns, 1.0): chain $v0, mask $v1; retail has the opposite order; (3) in toys (36 wordings of the update: operand order, `+`/`|`, mask
 * spelled 0xFFFFFF / ~0xFF000000 / 0xFFFFFFu / `<< 8 >> 8`, user variables, a pointer, an inline helper for the update, u32/s32 field) the pair is always
 * mask $3 / chain $2 when `and` is immediately followed by the `fix` insn, and shares one register ($2) only when another insn separates them. Retail's else
 * block must therefore hold an insn mine has not (or different ref counts); the then-arm's tail (R through the gcse copy in $a0) already gets retail's
 * mask $v0 / chain $v1 because its `and` result is tied to the mask. Not found: a source form that changes that block. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_004702E0 */
typedef struct {
    u8 pad0[0x10];
    u128_t pos;
    u8 pad20[0xA0];
    u128_t rowA;
    u128_t rowB;
    u128_t rowC;
} Tgt_004702E0;
typedef struct {
    Tgt_004702E0 *tgt;
    s32 i4;
    f32 f8;
    u8 bC;
    u8 bD;
    u8 bE;
    u8 bF;
    f32 v10[3];
    f32 f1C;
} Sub_004702E0;
typedef struct {
    u8 pad0[4];
    s32 rgba;
    u8 b8;
    u8 pad9;
    s16 hA;
    f32 fC;
    u128_t pos;
    Sub_004702E0 sub;
} T_004702E0;

extern u128_t D_L01_001E29C0_004702E0[];
extern void func_003CD250(Obj *);
extern s32 func_0038CB00(s16 *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);

void func_L01_004702E0(T_004702E0 *p) {
    Sub_004702E0 *q = &p->sub;
    Tgt_004702E0 *tgt;
    Vec4 v[4];
    Vec4 *d;
    f32 f;
    f32 r;

    if (p->hA >= 0 && func_0038CB00(&p->hA) != 0) {
        func_003CD250((Obj *)p);
        return;
    }
    tgt = q->tgt;
    if (tgt != 0) {
        if (*(s8 *)((u8 *)tgt + 0x20) < 0) {
            func_003CD250((Obj *)p);
            return;
        }
        if (q->i4 >= 0) {
            func_003C2EC0(tgt, q->i4, v);
            func_0038D000(&p->pos, q->v10, v);
            vec_add_ab(&p->pos, &p->pos, &v[3]);
            *(s32 *)((u8 *)&p->pos + 12) = 0;
        } else {
            p->pos = tgt->pos;
            func_0038D000(v, q->v10, &tgt->rowA);
            vec_add_ab(&p->pos, &p->pos, v);
            if (q->bE != 0) {
                vec_sub_ba(&v[1], &p->pos, D_L01_001E29C0_004702E0);
                r = func_0038CE68(&v[1], &D_L01_001E29C0_004702E0[2]);
                p->b8 = (s32)(r * 6.0f);
            }
            if (q->bC != 0) {
                switch (q->bC) {
                case 1:
                    d = &v[2];
                    vec_sub_ba(d, &p->pos, &tgt->pos);
                    func_0038CF68(d, d, 1.0f);
                    break;
                case 2:
                    *(u128_t *)&v[2] = tgt->rowA;
                    break;
                case 3:
                    *(u128_t *)&v[2] = tgt->rowA;
                    vec_neg(&v[2], &v[2]);
                    break;
                case 4:
                    *(u128_t *)&v[2] = tgt->rowB;
                    break;
                case 5:
                    *(u128_t *)&v[2] = tgt->rowB;
                    vec_neg(&v[2], &v[2]);
                    break;
                case 6:
                    *(u128_t *)&v[2] = tgt->rowC;
                    break;
                case 7:
                    *(u128_t *)&v[2] = tgt->rowC;
                    vec_neg(&v[2], &v[2]);
                    break;
                }
                vec_sub_ba(&v[1], &p->pos, D_L01_001E29C0_004702E0);
                func_0038CF68(&v[1], &v[1], 1.0f);
                f = -func_0038CE68(&v[1], &v[2]);
                f = f * 1.25f + 0.05f;
                if (f < 0.0f) {
                    p->rgba &= 0x05FFFFFF;
                    goto tail;
                }
                if (1.0f < f) {
                    f = 1.0f;
                }
                if (q->bF != 0) {
                    u32 t = p->rgba & 0xFF000000;
                    u32 a = t >> 24;
                    f32 g = (f32)a * f;
                    p->rgba = (p->rgba & 0xFFFFFF) | ((s32)g << 24);
                } else {
                    p->rgba = (p->rgba & 0xFFFFFF) | ((s32)(f * 255.0f) << 24);
                }
            }
        }
    } else {
        p->pos = *(u128_t *)q->v10;
    }
tail:
    p->fC = p->fC * q->f1C;
    p->b8 = p->b8 + q->bD;
    vec_sub_ba(&v[0], D_L01_001E29C0_004702E0, &p->pos);
    func_0038CF68(&v[0], &v[0], q->f8);
    vec_add_ab(&p->pos, &p->pos, &v[0]);
}
/* localdecomp:end func_L01_004702E0 */
