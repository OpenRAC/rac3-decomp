#include "common.h"

/* localdecomp:start func_L01_004463D0 */
extern void func_003C3D30(s32, s32, s32, f32);

void func_L01_004463D0(s32 a0) {
    func_003C3D30(a0, 32, 0, 0.5f);
}
/* localdecomp:end func_L01_004463D0 */

/* localdecomp:start func_L01_004463F8 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec_004432C0;

s32 func_L01_004463F8(Vec_004432C0 *p, Vec_004432C0 *v, s32 n) {
    s32 i;
    s32 j = 0;
    s32 inside = 0;

    for (i = 0; i < n; i++) {
        j++;
        if (j == n) {
            j = 0;
        }
        if ((v[i].y < p->y && p->y <= v[j].y) || (v[j].y < p->y && p->y <= v[i].y)) {
            if (v[i].x + (p->y - v[i].y) / (v[j].y - v[i].y) * (v[j].x - v[i].x) < p->x) {
                inside = !inside;
            }
        }
    }
    return inside;
}
/* localdecomp:end func_L01_004463F8 */

INCLUDE_ASM("asm/levels", func_L01_004464C8);

INCLUDE_ASM("asm/levels", func_L01_00446630);

INCLUDE_ASM("asm/levels", func_L01_00446720);

INCLUDE_ASM("asm/levels", func_L01_00446748);

/* localdecomp:start func_L01_00446760 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_443;
typedef struct { V4_443 v; s32 a; s32 b; s32 pad; f32 f; s32 one; } S443;
void func_L01_00446760(S443 *p, s32 a, s32 b, V4_443 *v, f32 f) {
    p->a = a;
    p->b = b;
    p->f = f;
    p->one = 1;
    p->v = *v;
}
/* localdecomp:end func_L01_00446760 */

INCLUDE_ASM("asm/levels", func_L01_00446780);

INCLUDE_ASM("asm/levels", func_L01_004468C8);

LINKER_REMNANT("asm/levels", func_L01_00446970);

INCLUDE_ASM("asm/levels", func_L01_00446978);

/* localdecomp:start func_L01_00446A70 */
typedef int u128_443938 __attribute__((mode(TI)));

typedef struct {
    u128_443938 v0;
    u128_443938 v10;
    s32 w20;
    s32 flags;
    u8 b28;
    u8 pad29[3];
    f32 f2C;
    s32 w30;
    f32 f34;
    u8 *owner;
    s32 w3C;
} Entry_443938;

typedef struct {
    u8 pad0[20];
    s32 next;
} Ring_443938;

extern Ring_443938 D_L01_001EAA00;
extern Entry_443938 D_L01_001EEC80[];
extern f32 func_0038CEA8(u128_443938 *a0);

void func_L01_00446A70(u8 *a0, s32 a1, s32 a2, u128_443938 *a3, u128_443938 *t0, f32 f) {
    s32 slot = D_L01_001EAA00.next;
    s32 flags = 0;
    Entry_443938 *e;
    Entry_443938 *p;

    if (a0[168] != 255) {
        p = &D_L01_001EEC80[a0[168]];
        if (p->owner == a0) {
            if (f < p->f2C) {
                p->flags |= a2;
                return;
            }
            flags = p->flags;
        }
    }
    e = &D_L01_001EEC80[slot];
    e->flags = a2 | flags;
    e->w20 = a1;
    e->b28 = 0;
    e->owner = a0;
    e->f34 = e->f2C = f;
    e->w3C = 0;
    if (func_0038CEA8(t0) > 0.0001f) {
        e->w30 = 1;
    } else {
        e->w30 = 0;
    }
    D_L01_001EEC80[slot].v0 = *a3;
    D_L01_001EEC80[slot].v10 = *t0;
    a0[168] = slot;
    D_L01_001EAA00.next = (slot + 1) & 63;
}
/* localdecomp:end func_L01_00446A70 */

INCLUDE_ASM("asm/levels", func_L01_00446BC8);

INCLUDE_ASM("asm/levels", func_L01_00446BF0);
