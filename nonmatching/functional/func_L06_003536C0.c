/* functional: medium. check.py at level_06: 200 diffs, from register allocation (path pointer $s3 vs $s2), branch-likely scheduling and the stack offsets; the block structure, loop counts, constants (1e-4, 0.999) and all stores follow the assembly. The helper macros PN/PF/PQ are local shorthand for the path struct (count at +0, point j at +0x10+16j, segment length at +0x1C+16j). */
#include "vu0.h"
#include "common.h"
typedef struct { u8 *y; s32 i; vu0_v4 *pos; vu0_v4 *tgt; s32 k; f32 r; f32 d; } C_003536C0;
typedef struct { vu0_v4 p; s32 i; f32 f; u8 pad[8]; } H_003536C0;
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_L06_003532B8(void *, void *, s32, s32, f32, void *);
extern s32 func_L05_0043F7E0(void *, void *, f32 *, f32 *, void *, void *, void *, f32);

s32 func_L06_003536C0(C_003536C0 *c, H_003536C0 *o1, H_003536C0 *o2) {
    vu0_v4 seg[2];
    vu0_v4 q20;
    vu0_v4 q30;
    vu0_v4 q40;
    f32 t1;
    f32 t2;
    s32 flags = 0;
    s32 idx;
    s32 cnt;
    u8 *p;
    f32 len;

    p = *(u8 **)(c->y + 0x358);
    #define PN (*(s32 *)p)
    #define PF(j) (*(f32 *)(p + (j) * 16 + 0x1C))
    #define PQ(j) ((vu0_v4 *)(p + (j) * 16 + 0x10))
    if (c->d + c->r < func_0038CF38(c->tgt, c->pos)) {
        vu0_v4 tmp;
        *(vu0_q *)o1 = *(vu0_q *)c->pos;
        o1->i = c->i;
        vec_sub_ab(&tmp, c->pos, PQ(c->i));
        o1->f = func_0038CEA8(&tmp);
        *(vu0_q *)o2 = *(vu0_q *)c->pos;
        o2->i = c->i;
        o2->f = o1->f;
        return 0;
    }
    if (*(s32 *)(c->y + 0x340) == 0) {
        cnt = PN - c->i - 1;
    } else {
        cnt = PN;
    }
    idx = c->i;
    if (cnt != 0) {
        do {
            if (0.0f < c->d) {
                func_L06_003532B8(c->y, p, idx, c->k, c->d, &seg[0]);
                func_L06_003532B8(c->y, p, idx + 1, c->k, c->d, &seg[1]);
            } else {
                seg[0] = *PQ(idx);
                seg[1] = *PQ(idx + 1);
            }
            q40 = *c->tgt;
            if (func_L05_0043F7E0(&q20, &q30, &t1, &t2, &seg[0], &seg[1], &q40, c->r)) {
                if (0.0001f < t1 && t1 < 0.999f) {
                    *(vu0_q *)o1 = *(vu0_q *)&q20;
                    o1->i = idx;
                    flags |= 1;
                    o1->f = PF(idx) * t1;
                }
                if (0.0001f < t2 && t2 < 0.999f) {
                    *(vu0_q *)o2 = *(vu0_q *)&q30;
                    o2->i = idx;
                    flags |= 2;
                    o2->f = PF(idx) * t2;
                    break;
                }
            }
            idx = (idx + 1) % PN;
        } while (--cnt != 0);
    }
    if (!(flags & 1)) {
        if (*(s32 *)(c->y + 0x340) == 0) {
            cnt = c->i;
        } else {
            cnt = PN;
        }
        idx = c->i - 1;
        if (cnt != 0) {
            do {
                if (0.0f < c->d) {
                    func_L06_003532B8(c->y, p, idx, c->k, c->d, &seg[0]);
                    func_L06_003532B8(c->y, p, idx + 1, c->k, c->d, &seg[1]);
                } else {
                    seg[0] = *PQ(idx);
                    seg[1] = *PQ(idx + 1);
                }
                q40 = *c->tgt;
                if (func_L05_0043F7E0(&q20, &q30, &t1, &t2, &seg[0], &seg[1], &q40, c->r)) {
                    if (0.0001f < t1 && t1 < 0.999f) {
                        *(vu0_q *)o1 = *(vu0_q *)&q20;
                        o1->i = idx;
                        flags |= 1;
                        o1->f = PF(idx) * t1;
                        break;
                    }
                }
                idx = (idx + PN - 1) % PN;
            } while (--cnt != 0);
        }
    }
    return flags;
}
