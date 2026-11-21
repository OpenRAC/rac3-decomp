#include "common.h"
#include "vu0.h"

/* near miss: 21 diff of 139 words, all of them one rotation of three callee-saved registers (check.py --no-context --flags=-mvu0-use-vf0-vf2; its file L01_00451A68.c
 * has `@ps2as` but not -mvu0-use-vf0-vf2, which the vec_* helpers need: a match also needs that flag on the file's line and its other C blocks rechecked).
 * A billboard quad drawer: per point a 3x3 basis from the direction to D_L01_001E29C0 (func_0038CF68 / CE90 / CE20), the four corners of a unit quad scaled by `sa`
 * and transformed by func_0038D028, then func_003D2DA0(&quad, 0, 0); the quad descriptor is the one of func_L01_00307058 (c40..c4C colours, x50..x6C uv floats,
 * x70..x88 GIF words). Words: everything else matches, including the stack frame, the 64-bit constants (in the order x88, x80, x70, found by a 6-permutation sweep:
 * 30 -> 21) and the `color` update (the stores read the loaded temp `c`, `color = c` between the first and second store).
 * Left: retail allocates $s3 = &m[0], $s4 = &m[1], $s5 = i + 1, $s6 = color; mine $s3 = &m[0], $s4 = color, $s5 = &m[1], $s6 = i + 1. From -da (t.c.lreg): color has
 * 15 weighted refs over 89 insns = priority 0.506, &m[1] 0.415, i + 1 0.400; retail needs color below 0.400 (11 refs, or a longer live range). Tried without change:
 * declaration order of color and c (12 positions), a temp for the four initial colour stores (propagated away), chain assignment, while / `i = n1` loop forms (89 diff),
 * indexed inner loop. */

/* localdecomp:start func_L01_00451A68 */
typedef struct {
    f32 v[4][4];
    s32 c40, c44, c48, c4C;
    s32 x50, x54, x58;
    f32 x5C, x60;
    s32 x64;
    f32 x68, x6C;
    long x70, x78, x80, x88;
    f32 axis[4];
    f32 m[4][4];
    f32 e[4];
} Q_451A68;

extern vu0_v4 D_L01_001E29C0;
extern u8 D_L01_001D7C50[8];
__asm__(".extern D_L01_001D7C50, 8");
extern long func_00389598(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);

void func_L01_00451A68(s32 n, vu0_q *pts, s32 *cols, f32 sa, f32 sb) {
    Q_451A68 q;
    s32 i;
    s32 k;
    s32 color;
    s32 c;
    f32 *t;
    f32 *p;

    *(vu0_q *)q.axis = 0;
    q.axis[2] = 1.0f;
    q.axis[3] = 1.0f;
    q.x78 = func_00389598(11);
    color = cols[0];
    q.x88 = 0x8000000048L;
    q.x80 = 0xFF9000000260L;
    q.x70 = 5;
    q.x50 = 0;
    q.x54 = 0;
    q.x58 = 0;
    q.x5C = 1.0f;
    q.x60 = 1.0f;
    q.x64 = 0;
    q.x68 = 1.0f;
    q.x6C = 1.0f;
    q.c4C = color;
    q.c48 = color;
    q.c44 = color;
    q.c40 = color;
    for (i = 0; i < n; i++) {
        *(vu0_q *)q.m[3] = pts[i];
        vec_sub_ab(q.m[0], &D_L01_001E29C0, q.m[3]);
        func_0038CF68(q.m[0], q.m[0], 1.0f);
        func_0038CE90(q.m[1], q.m[0], q.axis);
        func_0038CF68(q.m[1], q.m[1], 1.0f);
        func_0038CE90(q.m[2], q.m[1], q.m[0]);
        func_0038CE20(q.e, q.m[0], sb);
        vec_add_ab(q.m[3], q.m[3], q.e);
        c = cols[i];
        if (c != color) {
            q.c4C = c;
            color = c;
            q.c48 = c;
            q.c44 = c;
            q.c40 = c;
        }
        t = (f32 *)D_L01_001D7C50;
        p = q.v[0];
        for (k = 3; k >= 0; k--) {
            func_0038CE20(p, t, sa);
            t += 4;
            func_0038D028(p, p, q.m[0]);
            p += 4;
        }
        func_003D2DA0(&q, 0, 0);
    }
}
/* localdecomp:end func_L01_00451A68 */
