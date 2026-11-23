/* PAL near miss (haiku-w3): 2 words differ with the file's flags; the loop-preheader float move (mov.s $f21,$f23 vs addiu $s0 order) and the order of the two stack swc1 pairs at the loop tail is unresolved */
/* PAL near miss (Codex wave 8): near miss: 15 words differ with the file's flags.
 * Worker's note: 15 differing words / 289; loop setup and final quadword-copy/UV scheduling; three equivalent wordings unchanged; best build/codex/w422/func_L01_002FDC18.01.log; contract compiled build/codex/w422/func_L01_002FDC18.contract.log
 */
#include "common.h"

/* localdecomp:start func_L01_002FDC18 */
#include "vu0.h"
extern f32 D_L01_001E29C0[];
void func_L01_002FDC18(s32 unused, s32 colour, f32 (*pts)[4], s32 count) {
    extern unsigned long func_00389598(s32);
    extern void func_L01_002FDBD8(f32 (*)[4], s32);
    extern void func_L01_002FD988(f32 *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern void func_0038CE90(f32 *, f32 *, f32 *);
    extern void func_0038D028(f32 *, f32 *, f32 *);
    extern void func_003D2DA0(f32 *, s32, s32);
    f32 a[36] __attribute__((aligned(16)));
    f32 b[36] __attribute__((aligned(16)));
    f32 axis[4] __attribute__((aligned(16)));
    f32 eye[4] __attribute__((aligned(16)));
    f32 side[4] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    f32 inner[4] __attribute__((aligned(16)));
    f32 outer[4] __attribute__((aligned(16)));
    s32 i;
    s32 edgeColour = 0x8000FF00;
    unsigned long texture;
    f32 u, v;
    texture = func_00389598(43);
    *(unsigned long *)(a + 28) = 0;
    *(unsigned long *)(a + 32) = 0x0000FF9000000260UL;
    *(unsigned long *)(a + 34) = ((unsigned long)(u32)colour << 32) | 104;
    *(s32 *)(a + 17) = 0x7FFFFFFF;
    *(s32 *)(a + 16) = 0x7FFFFFFF;
    *(unsigned long *)(a + 30) = texture;
    texture = func_00389598(43);
    *(unsigned long *)(b + 28) = 0;
    *(unsigned long *)(b + 32) = 0x0000FF9000000260UL;
    *(unsigned long *)(b + 34) = ((unsigned long)(u32)(colour / 3) << 32) | 104;
    *(unsigned long *)(b + 30) = texture;
    *(vu0_q *)inner = 0;
    *(vu0_q *)outer = 0;
    inner[2] = 0.05f;
    outer[2] = 0.2f;
    *(s32 *)(a + 17) = edgeColour;
    *(s32 *)(b + 16) = edgeColour;
    inner[3] = 1.0f; outer[3] = 1.0f;
    func_L01_002FDBD8(pts, count);
    func_L01_002FD988(a);
    func_L01_002FD988(b);
    a[20]=0.0f; a[21]=0.0f; a[22]=0.0f; a[23]=1.0f;
    a[24]=1.0f; a[25]=0.0f; a[26]=1.0f; a[27]=1.0f;
    b[20]=0.0f; b[21]=0.0f; b[22]=0.0f; b[23]=1.0f;
    b[24]=0.33f; b[25]=0.0f; b[26]=0.33f; b[27]=1.0f;
    vec_sub_ba(axis, pts[1], pts[0]);
    func_0038CF68(axis, axis, 1.0f);
    vec_sub_ab(eye, D_L01_001E29C0, pts[0]);
    func_0038CE90(side, eye, axis);
    func_0038CF68(side, side, 1.0f);
    func_0038CE90(eye, axis, side);
    *(vu0_q *)pos = *(vu0_q *)pts[0];
    *(vu0_q *)a = *(vu0_q *)inner;
    func_0038CE20(a + 4, a, -1.0f);
    func_0038D028(a, a, axis);
    func_0038D028(a + 4, a + 4, axis);
    *(vu0_q *)b = *(vu0_q *)outer;
    func_0038CE20(b + 4, b, -1.0f);
    func_0038D028(b, b, axis);
    func_0038D028(b + 4, b + 4, axis);
    for (i = 1; i < count - 1; i++) {
        *(vu0_q *)(a + 8) = *(vu0_q *)inner;
        func_0038CE20(a + 12, a + 8, -1.0f);
        *(vu0_q *)(b + 8) = *(vu0_q *)outer;
        func_0038CE20(b + 12, b + 8, -1.0f);
        vec_sub_ab(axis, pts[i + 1], pts[i]);
        func_0038CF68(axis, axis, 1.0f);
        vec_sub_ab(eye, D_L01_001E29C0, pts[i]);
        func_0038CE90(side, eye, axis);
        func_0038CF68(side, side, 1.0f);
        func_0038CE90(eye, axis, side);
        *(vu0_q *)pos = *(vu0_q *)pts[i];
        func_0038D028(a + 8, a + 8, axis);
        func_0038D028(a + 12, a + 12, axis);
        func_0038D028(b + 8, b + 8, axis);
        func_0038D028(b + 12, b + 12, axis);
        *(s32 *)(a + 19) = 0x7F7F7F7F;
        *(s32 *)(a + 18) = 0x7F7F7F7F;
        *(s32 *)(b + 19) = edgeColour;
        *(s32 *)(b + 18) = edgeColour;
        func_003D2DA0(a, 0, 0);
        func_003D2DA0(b, 0, 0);
        u = i * 0.33f;
        v = u + 0.33f;
        if (u >= 1.0f) { u -= 1.0f; v -= 1.0f; }
        b[20] = u; b[24] = v; b[22] = u; b[26] = v;
        *(vu0_q *)a = *(vu0_q *)(a + 8);
        *(vu0_q *)(a + 4) = *(vu0_q *)(a + 12);
        *(vu0_q *)b = *(vu0_q *)(b + 8);
        *(vu0_q *)(b + 4) = *(vu0_q *)(b + 12);
    }
}
/* localdecomp:end func_L01_002FDC18 */
