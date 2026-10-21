#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_00457F00);

INCLUDE_ASM("asm/levels", func_L01_00457F20);

/* localdecomp:start func_L01_00458C98 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

typedef struct {
    Vec4 v0;
    Vec4 pos;
    Vec4 v32;
    u8 pad48[32];
    s32 w80;
    u8 pad84[20];
    u8 *pvars;
} Moby_4559A8;

extern s32 D_L01_001EAA18[];

extern s32 func_003D3CB0(Vec4 *a, Vec4 *b, s32 flags, Moby_4559A8 *moby, s32 e);

void func_L01_00458C98(Moby_4559A8 *moby, Moby_4559A8 *other) {
    Vec4 v[2];
    u8 *p = *(u8 **)(moby->pvars + 28);
    if (p == 0) {
        return;
    }
    v[0].q = moby->pos.q;
    v[1].q = other->pos.q;
    v[0].f[2] += 0.1f;
    v[0].f[2] += *(f32 *)(p + 8);
    v[1].f[2] += *(f32 *)(p + 8);
    if (func_003D3CB0(&v[0], &v[1], 16, moby, 0) != 0) {
        if (D_L01_001EAA18[0] == 0) {
            return;
        }
        if (D_L01_001EAA18[0] != other->w80) {
            return;
        }
    }
    other->v0.q = other->pos.q;
    other->v32.q = other->pos.q;
}
/* localdecomp:end func_L01_00458C98 */

INCLUDE_ASM("asm/levels", func_L01_00458D50);

INCLUDE_ASM("asm/levels", func_L01_00458F78);

/* localdecomp:start func_L01_00459188 */
typedef int u128_455E98 __attribute__((mode(TI)));

void func_L01_00459188(u8 *a0, u8 *a1, u8 *a2) {
    *(u8 **)(a2 + 80) = a1;
    *(u128_455E98 *)(a2 + 16) = *(u128_455E98 *)(a1 + 16);
    *(u128_455E98 *)(a2 + 0) = *(u128_455E98 *)(a1 + 16);
    *(u128_455E98 *)(a2 + 32) = *(u128_455E98 *)(a1 + 16);
    *(u128_455E98 *)(a2 + 112) = *(u128_455E98 *)(a0 + 16);
    *(s32 *)(a2 + 64) = 0;
}
/* localdecomp:end func_L01_00459188 */

/* localdecomp:start func_L01_004591B8 */
typedef unsigned int Q __attribute__((mode(TI)));
extern void func_L01_00457F20(u8 *a0, u8 *a1, s32 a2, s32 a3, f32 f12);
void func_L01_004591B8(u8 *a0, Q *a1, u8 *a2) {
    Q v = *a1;
    Q tmp[1];
    *(s32 *)(a2 + 80) = 0;
    *(Q *)(a2 + 32) = v;
    *(Q *)(a2 + 16) = v;
    *(Q *)(a2 + 0) = v;
    tmp[0] = v;
    *(Q *)(a2 + 112) = *(Q *)(a0 + 16);
    func_L01_00457F20(a0, a2, 0, 0, 12.0f);
    *(s32 *)(a2 + 64) = 0;
}
/* localdecomp:end func_L01_004591B8 */

INCLUDE_ASM("asm/levels", func_L01_00459218);

/* localdecomp:start func_L01_004592A8 */
extern f32 func_0038CF38(void *, void *);

u8 *func_L01_004592A8(u8 *me, u8 **list, s32 n, s32 *out) {
    s32 i;
    s32 j;
    u8 *o;
    u8 *best;
    f32 bestD;
    f32 d;

    for (i = 0; i < n; i++) {
        out[i] = 0;
    }
    bestD = 9999.0f;
    best = 0;
    for (j = 0; j < n; j++) {
        o = list[j];
        d = 0.0f;
        d += func_0038CF38(me + 16, o + 16);
        if (__builtin_fabsf(*(f32 *)(o + 24) - *(f32 *)(me + 24)) > 3.0f) {
            d += 100.0f;
        }
        if (d < bestD) {
            best = o;
            bestD = d;
        }
    }
    return best;
}
/* localdecomp:end func_L01_004592A8 */

INCLUDE_ASM("asm/levels", func_L01_004593B8);

/* localdecomp:start func_L01_00459590 */
extern u8 D_L01_001E2E20[];
extern s32 func_0038DC20(void *);
extern f32 func_L01_0040E548(void *, void *);

s32 func_L01_00459590(void *a0, f32 *out) {
    f32 d = 1048576.0f;
    s32 r;
    f32 t;

    r = func_0038DC20(a0);
    if (r != -1) {
        t = func_L01_0040E548(a0, D_L01_001E2E20);
        if (t < d) {
            d = t;
        }
    }
    if (out != 0) {
        *out = d;
    }
    return r;
}
/* localdecomp:end func_L01_00459590 */
