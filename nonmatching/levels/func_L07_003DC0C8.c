/* PAL near miss (opus-w3): 6 words differ with the file's flags; the inner rest-length loop's exit test computes j + m after the b17 test (retail: before it, with b17 in $v1, which needs sched1 interblock motion that this form's CFG gets no region for), and the final loop's pointer/index inits before func_0040F0A0 are swapped. With -fno-sched-interblock the pl++ form (final loop) is 4 words, inner loop only. */
#include "common.h"
#include "vu0.h"
#include "structs/moby.h"

typedef struct {
    f32 f00;
    f32 f04;
    f32 f08;
    f32 f0C;
    f32 f10;
    u8 b14;
    u8 b15;
    u8 b16;
    u8 b17;
    u8 pad18[8];
} Rope_003DC0C8;

typedef struct {
    vu0_v4 link[8];
    vu0_v4 prev[8];
    vu0_v4 anchor;
    s32 w110;
    s32 w114;
    s32 w118;
    u8 pad11C[12];
    f32 f128;
} Priv_003DC0C8;

extern void func_L07_003DC598(Rope_003DC0C8 *, s32, s32, f32);
extern void func_L01_0044FD88(struct Moby *, struct Moby *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L07_003DC4C8(void *, void *, s32, s32, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_L01_0040E4C0(void *);

void func_L07_003DC0C8(void *moby)
{
    u8 *obj = moby;
    Rope_003DC0C8 prm;
    vu0_v4 gravity, step, saved, delta, scaled;
    Priv_003DC0C8 *p;
    f32 d, t;
    s32 i, j, k, m, jn;
    vu0_v4 *pl, *pp, *pa, *pb, *pq;
    vu0_v4 *anchor, *psaved;

    p = *(Priv_003DC0C8 **)(obj + 0x68);
    func_L07_003DC598(&prm, p->w110, p->w114, (f32)*(u16 *)(obj + 0x96) / 17.0f);
    if (*(u16 *)(obj + 0x96) < 17) {
        prm.f08 = 1.0f;
    }

    *(vu0_q *)&step = 0;
    step.z = prm.f04;
    anchor = &p->anchor;
    gravity = step;
    func_L01_0044FD88(*(struct Moby **)(obj + 0xB8), moby, p->w118, 0);
    *(u16 *)(obj + 0x34) &= 0xFFFD;
    *(vu0_q *)&p->link[0] = *(vu0_q *)(obj + 0x10);
    *(vu0_q *)&p->prev[0] = *(vu0_q *)(obj + 0x10);
    func_0038CF68(&step, obj + 0xC0, prm.f00);
    i = 1;
    psaved = &saved;

    for (; i < prm.b15; i++) {
        vec_add_ab(&p->link[i], &p->link[i - 1], &step);
        *(vu0_q *)&p->prev[i] = *(vu0_q *)&p->link[i];
    }
    pl = &p->link[prm.b15];
    pp = &p->prev[prm.b15];
    j = prm.b15;
    for (; j < 8; pl++, pp++, j++) {
        *(vu0_q *)&saved = *(vu0_q *)pl;
        vec_sub_ba(&delta, pl, pp);
        func_0038CE20(&delta, &delta, prm.f08);
        vec_add_ab(pl, pl, &delta);
        vec_add_ab(pl, pl, &gravity);
        *(vu0_q *)pp = *(vu0_q *)&saved;
    }
    for (k = 0; k < prm.b14; k++) {
        pa = &p->link[0];
        for (j = 0; j < 7; j = jn) {
            m = 1;
            jn = j + 1;
            pb = pa + 1;
            for (; m <= prm.b17 && j + m < 8; m++) {
                f32 rest = (f32)m * prm.f00;
                func_L07_003DC4C8(pa, pa + m, j >= prm.b15, j + m >= prm.b15, rest * rest);
            }
            pa = pb;
        }
    }

    func_0038D000(psaved, anchor, *(u8 **)(obj + 0xB8) + 0xC0);
    vec_add_ab(&saved, &saved, *(u8 **)(obj + 0xB8) + 0x10);
    for (j = 0; j < 8; j++) {
        f32 lower = prm.f0C + p->f128;
        pl = &p->link[j];
        if (pl->z < lower) {
            pl->z = lower;
        }
        if (j >= prm.b16) {
            vec_sub_ab(&delta, &saved, pl);
            d = prm.f10 * prm.f10;
            t = func_L01_0040E4C0(&delta);
            t = d / (t + d) - 0.5f;
            if (t > 0.0f) {
                func_0038CE20(&scaled, &delta, t + t);
                vec_sub_ab(pl, pl, &scaled);
            }
            if (pl->z < saved.z) {
                delta.z = 0.0f;
                t = d / (func_L01_0040E4C0(&delta) + d) - 0.5f;
                if (t > 0.0f) {
                    func_0038CE20(&scaled, &delta, t + t);
                    vec_sub_ab(pl, pl, &scaled);
                }
            }
        }
    }
}
