/* near miss (level 3, Starship Phoenix): 12 differences, one cause: retail addresses the path segment from t + i*16 (lq 0x10($v0)) and keeps a copy of that pointer for the lqc2 0x20($a3), this C computes t + (i+1)*16 and uses one register; every other instruction matches (the vec_sub/vec_add forms do not matter, all 256 ab/ba choices give 12). Found: the limit must be read in the loop condition (s->i154, 119 -> 29) and the segment taken through a pointer to t[i + 1] (29 -> 12); &t[i]-based pointers, separate pointer variables and byte offsets give 101 */
#include "common.h"

/* localdecomp:start func_L03_00397390 */
#include "vu0.h"
typedef struct {
    char pad0[0x14C];
    int i14C;
    int i150;
    int i154;
    int i158;
} S_00397390;
typedef struct { char pad0[0x10]; vu0_v4 pos; char pad20[0x48]; S_00397390 *p68; } O_00397390;
extern u128_t *D_L03_0021D8C0[];
__asm__(".extern D_L03_0021D8C0, 16");
extern u8 *D_L03_001DF99C;
extern u8 D_001D9BE0[8];
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);

f32 func_L03_00397390(void *arg) {
    O_00397390 *a = arg;
    S_00397390 *s = a->p68;
    u128_t *t;
    u8 *e;
    int i;
    int n;
    if (s->i158 != -1 && s->i14C != -1) {
        t = D_L03_0021D8C0[s->i14C];
        e = D_L03_001DF99C + (s->i158 << 8);
        for (i = s->i150; i < s->i154; i++) {
            if (i >= 0 && i + 1 < *(s32 *)t) {
                vu0_v4 p;
                vu0_v4 d;
                vu0_v4 nrm;
                vu0_v4 w;
                vu0_v4 q;
                f32 r;
                u128_t *seg = &t[i + 1];
                *(u128_t *)&p = *seg;
                vec_sub_ab(&d, seg + 1, &p);
                func_0038CE90(&nrm, D_001D9BE0, &d);
                func_0038CF68(&nrm, &nrm, 2.0f);
                vec_add_ab(&q, &p, &nrm);
                vec_sub_ab(&w, e + 0x10, &q);
                r = func_0038CE68(&nrm, &w);
                vec_sub_ab(&q, &p, &nrm);
                vec_sub_ab(&w, e + 0x10, &q);
                if (r * func_0038CE68(&nrm, &w) >= 0.0f) return 0.0f;
                r = func_0038CE68(&d, &w);
                vec_add_ab(&q, &q, &d);
                vec_sub_ab(&w, e + 0x10, &q);
                if (r * func_0038CE68(&d, &w) >= 0.0f) return 0.0f;
                vec_sub_ab(&w, e + 0x10, &a->pos);
                return func_0038CE68(&d, &w);
            }
        }
    }
    return 0.0f;
}
/* localdecomp:end func_L03_00397390 */
