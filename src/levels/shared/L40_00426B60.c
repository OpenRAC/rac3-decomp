#include "common.h"

/* localdecomp:start func_L40_00426B60 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_426250;
typedef struct {
    u8 pad0[720];
    f32 *pos;
} Q426250;
typedef struct {
    u8 pad0[9508];
    f32 *pos;
    Q426250 *q;
    u8 pad252C[9544 - 9516];
    s32 team;
} P426250;
typedef struct {
    u8 pad0[16];
    s32 f10;
} V426250;
typedef struct {
    u8 pad0[36];
    V426250 *v;
    u8 pad28[152 - 40];
    s32 f98;
} A426250;
typedef struct {
    u8 pad0[596];
    f32 range;
    u8 pad258[636 - 600];
    s32 team;
} B426250;
extern P426250 *D_L40_00249330[];
extern s32 func_L39_006481F8(P426250 *p);
extern f32 func_L01_0040E548(void *a, void *b);
extern s32 func_L40_00424BA0(void *a, void *b, f32 *c);
f32 *func_L40_00426B60(A426250 *a, B426250 *b, Vec4_426250 *src) {
    Vec4_426250 tmp;
    Vec4_426250 cp;
    f32 *best;
    f32 *pos;
    f32 bestd;
    f32 d;
    s32 i;
    s32 r;

    best = 0;
    bestd = b->range * b->range;
    for (i = 0; i < 8; i++) {
        if (D_L40_00249330[i] == 0) {
            continue;
        }
        if (D_L40_00249330[i]->team == b->team) {
            continue;
        }
        if (func_L39_006481F8(D_L40_00249330[i]) == 0) {
            continue;
        }
        pos = D_L40_00249330[i]->pos;
        if (D_L40_00249330[i]->q != 0) {
            pos = D_L40_00249330[i]->q->pos;
        }
        tmp.x = pos[0] * 0.0009765625f;
        tmp.y = pos[1] * 0.0009765625f;
        tmp.z = pos[2] * 0.0009765625f;
        tmp.w = 0.0f;
        d = func_L01_0040E548(src, &tmp);
        if (d < bestd) {
            a->f98 = 0;
            cp = *src;
            r = func_L40_00424BA0(&cp, &tmp, pos);
            a->f98 = a->v->f10;
            if (r == 0) {
                bestd = d;
                best = pos;
            }
        }
    }
    return best;
}
/* localdecomp:end func_L40_00426B60 */

INCLUDE_ASM("asm/levels", func_L40_00426CC0);

INCLUDE_ASM("asm/levels", func_L40_00426F68);

INCLUDE_ASM("asm/levels", func_L40_004271E0);

INCLUDE_ASM("asm/levels", func_L40_004272D0);

INCLUDE_ASM("asm/levels", func_L40_004276F0);

INCLUDE_ASM("asm/levels", func_L40_00427920);
