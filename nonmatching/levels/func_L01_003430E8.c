/* func_L01_003430E8 (Claude wave 14 r66, 2026-11-28). Replaces the earlier draft of this function (Codex wave 8 near miss). */
/* PAL near miss (wave 14 r66, 2026-11-28): 263 instruction diffs at level 01 under the file's own line
 * (-O2 -G8 -fopt-stack -mno-check-zero-division -fno-sched-interblock @ps2as -mvu0-use-vf0-vf2), 264 with the divs
 * metadata below. This cannot match under that line: retail saves $s0-$s7, $fp and $ra with sq in 16-byte slots of a
 * 0x350 frame (no -fopt-stack); -fopt-stack gives sd saves and another frame, so every stack offset differs. It needs
 * the existing line of src/levels/shared/L01_00344A88.c, "-O2 -G8 -mno-check-zero-division -fno-sched-interblock
 * @ps2as -mvu0-use-vf0-vf2", as a file of its own: 0x003430E8-0x00343650 at level 01 (start and end 8-aligned at all
 * 34 places; func_L01_00342D18 ends and func_L01_00343650 starts there), plus an sq_ra_funcs row 'func_L01_003430E8'
 * and a divs_nops row 'func_L01_003430E8 2 2 2' (two nops before each of the three div.s).
 * Against the Codex wave 8 draft: it compiles in the file's context now (D_L01_001E29C0 is the file's vu0_v4 scalar,
 * not an array; func_003D2DA0/func_0038CF68 use the file's prototypes; the parameters take the types of the
 * caller's block-scope extern in func_L01_00342D18: void *, s32 x3, u32 x4, s32 x3, f32 x3). The body is the draft's;
 * retail also copies points[first] / points[i] through VU0 stack temporaries (0x1F0, 0x200, 0x210, 0x260) that the
 * draft does not have. */
#include "common.h"
/* localdecomp:start func_L01_003430E8 */
#include "vu0.h"
typedef struct {
    vu0_v4 point[4];
    s32 color[4];
    s32 x50, x54, x58;
    f32 x5C, x60;
    s32 x64;
    f32 x68, x6C;
    u8 state[0x20];
} Quad_003430E8;

void func_L01_003430E8(void *pts, s32 count, s32 tex0, s32 tex1,
    u32 end0, u32 start0, u32 end1, u32 start1, s32 first, s32 last, s32 steps,
    f32 outer_width, f32 inner_width, f32 extend) {
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_003A9440(s32, unsigned long);
    Quad_003430E8 outer;
    Quad_003430E8 inner;
    vu0_v4 normal;
    vu0_v4 width;
    vu0_v4 radial;
    vu0_v4 edge;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 current;
    vu0_v4 previous;
    vu0_v4 to_origin;
    vu0_v4 scaled_previous;
    vu0_v4 scaled_current;
    vu0_v4 extension;
    vu0_v4 *points = pts;
    s32 i, next, old;
    f32 unit, t, previous_length, length;
    func_003D93B0(&outer, tex0, 1, 128);
    outer.color[3] = start0;
    outer.color[2] = start0;
    outer.color[1] = start0;
    outer.color[0] = start0;
    outer.x50 = 0; outer.x54 = 0; outer.x58 = 0;
    outer.x5C = 1.0f; outer.x60 = 1.0f; outer.x64 = 0;
    outer.x68 = 1.0f; outer.x6C = 1.0f;
    func_003D93B0(&inner, tex1, 1, 128);
    inner.color[3] = start1;
    inner.color[2] = start1;
    inner.color[1] = start1;
    inner.color[0] = start1;
    inner.x50 = 0; inner.x54 = 0; inner.x58 = 0;
    inner.x5C = 1.0f; inner.x60 = 1.0f; inner.x64 = 0;
    inner.x68 = 1.0f; inner.x6C = 1.0f;
    next = (first + 1) % count;
    vec_sub_ba(&radial, &points[first], &D_L01_001E29C0);
    vec_sub_ba(&edge, &points[next], &points[first]);
    func_0038CE90(&normal, &edge, &radial);
    steps--;
    func_0038CF68(&normal, &normal, outer_width);
    unit = 1.0f / steps;
    t = unit;
    vec_add_ba(&outer.point[0], &normal, &points[first]);
    vec_sub_ba(&outer.point[1], &points[first], &normal);
    old = first;
    for (i = next; i != last; i = (i + 1) % count) {
        vec_sub_ba(&radial, &points[i], &D_L01_001E29C0);
        vec_sub_ba(&edge, &points[i], &points[old]);
        func_0038CE90(&normal, &edge, &radial);
        func_0038CF68(&normal, &normal, outer_width);
        vec_add_ab(&outer.point[2], &points[i], &normal);
        vec_sub_ab(&outer.point[3], &points[i], &normal);
        outer.color[2] = outer.color[3] = func_0038DBD8(start0, end0, t);
        t += unit;
        func_003D2DA0(&outer, 0, 0);
        old = i;
        *(vu0_q *)&outer.point[0] = *(vu0_q *)&outer.point[2];
        *(vu0_q *)&outer.point[1] = *(vu0_q *)&outer.point[3];
        outer.color[0] = outer.color[1] = outer.color[2];
    }
    vec_sub_ab(&previous, &points[first], &D_L01_001E29C0);
    previous_length = func_0038CEA8(&previous);
    t = unit;
    for (i = next; i != last; i = (i + 1) % count) {
        vec_sub_ab(&current, &points[i], &D_L01_001E29C0);
        length = func_0038CEA8(&current);
        if (previous_length < length) {
            if (previous_length == 0.0f) *(vu0_q *)&scaled_previous = *(vu0_q *)&current;
            else func_0038CE20(&scaled_previous, &previous, length / previous_length);
            vec_add_ab(&a, &D_L01_001E29C0, &current);
            vec_add_ab(&b, &D_L01_001E29C0, &scaled_previous);
        } else {
            if (length == 0.0f) *(vu0_q *)&scaled_current = *(vu0_q *)&previous;
            else func_0038CE20(&scaled_current, &current, previous_length / length);
            vec_add_ab(&a, &D_L01_001E29C0, &scaled_current);
            vec_add_ab(&b, &D_L01_001E29C0, &previous);
        }
        vec_sub_ba(&edge, &b, &a);
        func_0038CE20(&extension, &edge, extend);
        previous_length = length;
        vec_sub_ab(&a, &a, &extension);
        vec_add_ab(&b, &b, &extension);
        vec_sub_ba(&to_origin, &D_L01_001E29C0, &a);
        func_0038CE90(&normal, &to_origin, &edge);
        func_0038CF68(&width, &normal, inner_width);
        vec_add_ab(&inner.point[0], &a, &width);
        vec_sub_ab(&inner.point[1], &a, &width);
        vec_add_ab(&inner.point[2], &b, &width);
        vec_sub_ba(&inner.point[3], &b, &width);
        inner.color[2] = inner.color[3] = func_0038DBD8(start1, end1, t);
        t += unit;
        func_003D2DA0(&inner, 0, 0);
        *(vu0_q *)&previous = *(vu0_q *)&current;
        inner.color[0] = inner.color[1] = inner.color[2];
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L01_003430E8 */
