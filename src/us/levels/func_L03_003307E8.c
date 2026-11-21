#include "common.h"

/* NTSC-U counterpart of func_L03_00330EC8 (src/levels/03_starship_phoenix/L03_0032FBA8.c): 0.4 -> 0.333333; 17 -> 20 */
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"

/* localdecomp:start func_L03_003307E8 */
#include "vu0.h"
typedef struct S_00330EC8b { u8 pad00[0xF7]; u8 fF7; f32 fF8; } S_00330EC8b;
typedef struct S_00330EC8a { u8 pad00[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_00330EC8b *f68; } S_00330EC8a;
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_L01_004708F8(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);

/* 0 or 1 at random */
static __inline__ s32 coin_00330EC8(void) {
    return func_0037E1D8(2);
}

/* 1 or -1: the sign sg, or a random one when sg is -1 */
static __inline__ s32 rsign_00330EC8(s32 sg) {
    s32 s;

    if (sg == -1 ? coin_00330EC8() : sg) {
        s = 1;
    } else {
        s = -1;
    }
    return s;
}

/* the axis ax, or a random one (x or y) when ax is -1 */
static __inline__ s32 pick_00330EC8(s32 ax) {
    s32 k;

    if (ax == -1) {
        k = coin_00330EC8();
    } else {
        k = ax;
    }
    return k;
}

/* a random length between lo and hi, with sign s */
static __inline__ f32 rand_len_00330EC8(f32 lo, f32 hi, s32 s) {
    f32 d = func_0037E250(lo, hi);

    return d * (f32)s;
}

void func_L03_003307E8(void *arg0) {
    S_00330EC8a *a = arg0;
    S_00330EC8b *p = a->f68;
    vu0_v4 v;
    f32 t;
    f32 y;
    f32 lo;
    f32 hi;
    s32 i;
    s32 j;
    s32 n;
    s32 ax;
    s32 sg;

    t = 2.0f - p->fF8;
    if (1.0f < t) {
        y = 1.0f;
    } else {
        y = t;
    }
    for (i = 0; i < 5; i++) {
        n = 4;
        if (!((p->fF7 >> i) & 1)) continue;
        if (i == 4) {
            n = 8;
            lo = 0.0f;
            hi = 10.5f;
            ax = -1;
            sg = -1;
        } else {
            lo = 10.5f;
            hi = 22.83f;
            ax = i % 2;
            sg = 1 - i / 2;
        }
        for (j = 0; j < n; j++) {
            f32 *q;

            {
                s32 k = pick_00330EC8(ax);
                s32 s = rsign_00330EC8(sg);

                qzero(&v);
                q = &(&v.x)[k];
                *q = rand_len_00330EC8(lo, hi, s);
            }
            {
                vu0_v4 w;

                vec_add_ab(&w, &a->pos, &v);
                {
                    vu0_v4 u;

                    {
                        f32 r = func_0037E2A8();

                        func_0037E4B8(&u, 0.333333343f, r, func_0037E250(1.0f, y) * 1.5707964f);
                    }
                    func_L01_004708F8(&w, &u, 0x14, 0.08f, 2.0f, 1.5f, 1.0f, 0x80FF2020, 0x80404040, 10, 0);
                }
            }
        }
    }
}
/* localdecomp:end func_L03_003307E8 */
