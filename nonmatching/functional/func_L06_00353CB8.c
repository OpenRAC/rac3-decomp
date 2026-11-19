/* functional: medium. check.py at level_06: 289 diffs (stack layout, extra saved registers, scheduling); control flow, call order, arguments (0.1/-0.1 deltas, -1/+1 directions, 3-iteration clamp loop) re-derived from the assembly. Callee func_L01_00476498 (retail func at 459340 in level 06) prototype guessed (path, pos, idx*, f*, loopflag, f32 delta). */
#include "vu0.h"
#include "common.h"
typedef struct { vu0_v4 p; s32 idx; f32 f; } H_00353CB8;
typedef struct { vu0_v4 *pos; s32 *idx; f32 *out; } B_00353CB8;
typedef struct { u8 pad0[4]; u8 *y; vu0_v4 *to; u8 padC[8]; f32 lo; f32 hi; f32 lim; } S_00353CB8;
typedef struct { S_00353CB8 *s; B_00353CB8 *b; u8 pad8[4]; f32 c; f32 d; s32 k; H_00353CB8 *a; H_00353CB8 *e; } C_00353CB8;
extern s32 func_L06_00352E20(u8 *, s32, s32, void *);
extern void func_L06_0045B1F8(void *, void *, s32 *, f32 *);
extern void func_L01_00476498(void *, void *, s32 *, f32 *, s32, f32);
extern f32 func_L06_0045B290(void *, f32, f32, s32, s32);
extern f32 func_003824E0(f32, f32);

s32 func_L06_00353CB8(C_00353CB8 *c) {
    vu0_v4 q;
    vu0_v4 out;
    s32 si;
    f32 sf;
    s32 n;
    s32 i;
    f32 x;
    f32 r;
    f32 lim;
    u8 *y = c->s->y;
    u8 *p = *(u8 **)(y + 0x358);

    i = c->a->idx;
    if (0.0f < c->a->f) {
        i++;
    }
    if (func_L06_00352E20(y, -1, i, &q)) {
        func_L06_0045B1F8(p, &q, &c->a->idx, &c->a->f);
        func_L01_00476498(p, c->a, &c->a->idx, &c->a->f, *(s32 *)(c->s->y + 0x340), 0.1f);
    } else if (0.0f < c->a->f) {
        i = c->a->idx;
        if (func_L06_00352E20(c->s->y, -1, i, &q)) {
            func_L06_0045B1F8(p, &q, &si, &sf);
            if (si != i || !(sf < c->a->f)) {
                c->a->idx = si;
                c->a->f = sf;
                func_L01_00476498(p, c->a, &c->a->idx, &c->a->f, *(s32 *)(c->s->y + 0x340), 0.1f);
            }
        }
    }
    if (func_L06_00352E20(c->s->y, 1, c->e->idx, &q)) {
        func_L06_0045B1F8(p, &q, &c->e->idx, &c->e->f);
        func_L01_00476498(p, c->e, &c->e->idx, &c->e->f, *(s32 *)(c->s->y + 0x340), -0.1f);
    } else if (0.0f < c->e->f) {
        i = c->e->idx + 1;
        if (func_L06_00352E20(c->s->y, 1, i, &q)) {
            func_L06_0045B1F8(p, &q, &si, &sf);
            if (si != i || !(c->e->f < sf)) {
                c->e->idx = si;
                c->e->f = sf;
                func_L01_00476498(p, c->e, &c->e->idx, &c->e->f, *(s32 *)(c->s->y + 0x340), -0.1f);
            }
        }
    }
    if (func_L06_0045B290(p, c->a->f, c->e->f, c->a->idx, c->e->idx) < 0.0f) {
        return 0;
    }
    x = func_003824E0(0.0f, func_L06_0045B290(p, c->a->f, c->e->f, c->a->idx, c->e->idx));
    si = c->a->idx;
    sf = c->a->f;
    func_L01_00476498(p, &out, &si, &sf, *(s32 *)(c->s->y + 0x340), x);
    r = func_003824E0(c->c, c->d);
    lim = c->s->lim;
    if (lim < r) {
        r = lim;
    } else if (r < -lim) {
        r = -lim;
    }
    func_L06_00353480(c->s->y, p, si, sf, r, c->k, c->b->pos);
    *c->b->idx = si;
    *c->b->out = sf;
    if (*(s32 *)(c->s->y + 0x390) == 0) {
        for (n = 3; n > 0; n--) {
            if (func_L06_00353AC8(c->b->pos, c->s->to, c->s->lo, c->s->hi) == 0) {
                break;
            }
            func_L06_0045B1F8(p, c->b->pos, c->b->idx, c->b->out);
            if (func_L06_00353B90((u8 **)c, c->b->pos, c->b->idx, c->b->out) == 0) {
                break;
            }
        }
    }
    return func_L06_00352E20(c->s->y, -1, *c->b->idx, &q) == 0;
}
