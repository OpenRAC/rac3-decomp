#include "common.h"

/* localdecomp:start func_L39_006AB300 */
/* best: 79 diff with --mode N --as ps2as (file flags differ in float-literal mode only, like
 * func_L39_006AC1A0 in the same file). Control flow and instruction sequence match; what is left
 * is register allocation only: retail has best=$s1, i=$s2 (mine swapped) and ddx=$f2, ddy=$f3
 * (mine swapped). Tried: declaration order, ddx/ddy statement order, block-scoped ddx/ddy (worse),
 * an items pointer local (worse). The dy<0 / dy>0 / else-continue shape of pass 2 was what fixed
 * the branch layout. */
typedef struct VT_006AB300 {
    char _p0[0x30];
    void (*f30)(void *, f32 *, f32 *);
} VT_006AB300;
typedef struct O_006AB300 {
    char _p0[0x60];
    VT_006AB300 *vt;
} O_006AB300;
typedef struct S_006AB300 {
    char _p0[0x110];
    O_006AB300 *items[52];
    char _p1e0[0x290 - 0x1E0];
    s32 cur;
} S_006AB300;
extern void func_L39_0068B2F8(void *, s32, s32);

void func_L39_006AB300(S_006AB300 *self, s32 dx, s32 dy)
{
    f32 x0, y0, x, y, x2, y2;
    f32 ddy, ddx;
    f32 ddy2, ddx2;
    f32 bestX, bestY;
    s32 best, i;
    s32 j;

    if ((u32)(self->cur - 2) >= 50) {
        func_L39_0068B2F8(self, 8, 0);
        return;
    }
    if (self->cur == 0x12 && dx < 0) {
        func_L39_0068B2F8(self, 0x1C, 0);
        return;
    }
    best = self->cur;

    self->items[best]->vt->f30(self->items[best], &x0, &y0);
    bestY = 1.0f;
    bestX = 1.0f;
    for (i = 2; i < 52; i++) {
        if (i == self->cur) {
            continue;
        }
        self->items[i]->vt->f30(self->items[i], &x, &y);
        ddx = x - x0;
        ddy = y - y0;
        if (dx < 0) {
            if (-ddy <= bestY && ddy < 0.0f) {
                if (__builtin_fabsf(ddx) < bestX || -ddy < bestY) {
                    bestX = __builtin_fabsf(ddx);
                    bestY = -ddy;
                    best = i;
                }
            }
        } else if (dx > 0) {
            if (ddy <= bestY && 0.0f < ddy) {
                if (__builtin_fabsf(ddx) < bestX || ddy < bestY) {
                    bestX = __builtin_fabsf(ddx);
                    bestY = ddy;
                    best = i;
                }
            }
        } else if (dy < 0) {
            if (-ddx < bestX && ddx < 0.0f && __builtin_fabsf(ddy) < 0.001f) {
                bestX = -ddx;
                bestY = ddy;
                best = i;
            }
        } else if (dy > 0) {
            if (ddx < bestX && 0.0f < ddx && __builtin_fabsf(ddy) < 0.001f) {
                bestX = ddx;
                bestY = ddy;
                best = i;
            }
        }
    }
    if (best == self->cur) {
        bestY = 0.0f;
        bestX = 0.0f;
        for (j = 2; j < 52; j++) {
            if (j == self->cur) {
                continue;
            }
            self->items[j]->vt->f30(self->items[j], &x2, &y2);
            ddx2 = x2 - x0;
            ddy2 = y2;
            ddy2 -= y0;
            if (dx < 0) {
                if (bestY <= ddy2) {
                    if (__builtin_fabsf(ddx2) < bestX || bestY < ddy2) {
                        bestX = __builtin_fabsf(ddx2);
                        bestY = ddy2;
                        best = j;
                    }
                }
            } else if (dx > 0) {
                if (bestY <= -ddy2) {
                    if (__builtin_fabsf(ddx2) < bestX || bestY < -ddy2) {
                        bestX = __builtin_fabsf(ddx2);
                        bestY = ddy2;
                        best = j;
                    }
                }
            } else {
                if (dy < 0) {
                } else if (dy > 0) {
                    ddx2 = -ddx2;
                } else {
                    continue;
                }
                if (bestX < ddx2 && __builtin_fabsf(ddy2) < 0.001f) {
                    bestX = ddx2;
                    bestY = ddy2;
                    best = j;
                }
            }
        }
    }
    func_L39_0068B2F8(self, best, 0);
}
/* localdecomp:end func_L39_006AB300 */
