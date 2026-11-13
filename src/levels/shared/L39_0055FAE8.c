#include "common.h"

/* localdecomp:start func_L39_0055FAE8 */
/* log: modelled on func_L40_00426B60 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_0055FAE8;
typedef struct {
    u8 pad0[720];
    f32 *pos;
} Q_0055FAE8;
typedef struct {
    u8 pad0[9508];
    f32 *pos;
    Q_0055FAE8 *q;
    u8 pad252C[9544 - 9516];
    s32 team;
} P_0055FAE8;
typedef struct {
    u8 pad0[556];
    s32 team;
    u8 pad230[592 - 560];
    f32 r0;
    u8 pad254[604 - 596];
    f32 r1;
} B_0055FAE8;
extern P_0055FAE8 *D_L39_0024CE20[];
extern s32 func_L39_006481F8(P_0055FAE8 *p);
extern s32 func_L39_0055D7F8(void *p);
extern f32 func_L01_0040E548(void *a, void *b);
extern s32 func_003D3CB0(void *a, void *b, s32 c, void *d, s32 e);
void *func_L39_0055FAE8(void *unused, void *bp, void *srcp) {
    B_0055FAE8 *b = bp;
    Vec4_0055FAE8 *src = srcp;
    f32 *best;
    f32 r0sq;
    f32 r1sq;
    f32 bestd;
    f32 d;
    f32 lim;
    f32 *pos;
    s32 i;
    s32 isw;
    Vec4_0055FAE8 tmp;

    if (b->team == -2) {
        return 0;
    }
    best = 0;
    r0sq = b->r0 * b->r0;
    r1sq = b->r1 * b->r1;
    bestd = r1sq < r0sq ? r0sq : r1sq;
    for (i = 0; i < 8; i++) {
        if (D_L39_0024CE20[i] == 0) {
            continue;
        }
        if (D_L39_0024CE20[i]->team == b->team) {
            continue;
        }
        if (func_L39_006481F8(D_L39_0024CE20[i]) == 0) {
            continue;
        }
        isw = 0;
        pos = D_L39_0024CE20[i]->pos;
        if (D_L39_0024CE20[i]->q != 0) {
            pos = D_L39_0024CE20[i]->q->pos;
            isw = func_L39_0055D7F8(pos);
        }
        tmp.x = pos[0] * 0.0009765625f;
        tmp.y = pos[1] * 0.0009765625f;
        tmp.z = pos[2] * 0.0009765625f;
        tmp.w = 0.0f;
        d = func_L01_0040E548(src, &tmp);
        lim = isw ? r1sq : r0sq;
        if (d < bestd && d < lim) {
            if (func_003D3CB0(src, &tmp, 18, pos, 0) == 0) {
                bestd = d;
                best = pos;
            }
        }
    }
    return best;
}
/* localdecomp:end func_L39_0055FAE8 */
