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

/* localdecomp:start func_L40_004271E0 */
typedef struct {
    u8 pad0[0x1C];
    u8 (*f1C)(void *, s32);
} VT_004271E0;

typedef struct {
    u8 pad0[0x14];
    VT_004271E0 *vt;
} O_004271E0;

extern s32 D_L40_002499F4 __attribute__((section(".data")));
extern u8 *D_001D5F30_sda;
extern u8 *func_L39_0061D7B0(void *);
extern void *func_L01_00447490(void *, u32, s32);
extern f32 func_L01_004474E8(void *, void *);
extern O_004271E0 *func_L39_0061CEA0(void *);
extern void func_003C4A40(void *, void *);

void func_L40_004271E0(u8 *a0) {
    u8 *v;
    u8 *r;
    u8 *h;
    O_004271E0 *o;
    u8 ok;

    r = func_L39_0061D7B0(a0);
    v = *(u8 **)(a0 + 0x68);
    if (r == 0) {
        return;
    }
    if (*(s32 *)(r + 4) == D_L40_002499F4) {
        return;
    }
    h = func_L01_00447490(a0, 0x10000, 0);
    func_L01_004474E8(a0, h);
    if (h != 0 && *(void **)(h + 0x20) != 0 && *(s8 *)(D_001D5F30_sda + 0x18E) == 0) {
        o = func_L39_0061CEA0(*(void **)(h + 0x20));
        ok = *(s32 *)(v + 0x230) != 0 && *(s32 *)(v + 0x2A0) == 0;
        if (ok) {
            if (o != 0) {
                ok = o->vt->f1C(o, *(s32 *)(v + 0x27C)) ^ 1;
            }
            if (ok) {
                func_003C4A40(a0, v + 0x70);
            }
        }
    }
    *(u8 *)(a0 + 0xA8) = 0xFF;
}
/* localdecomp:end func_L40_004271E0 */

INCLUDE_ASM("asm/levels", func_L40_004272D0);

INCLUDE_ASM("asm/levels", func_L40_004276F0);

INCLUDE_ASM("asm/levels", func_L40_00427920);
