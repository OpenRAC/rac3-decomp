/* PAL near miss (haiku-w6): 50 words differ with the file's flags; VU0 lq/sqc2 interleave and the frame is 0x170 against retail 0x160 (one 16-byte slot extra), so every sp offset differs. The local S_0030CD20 typedef is in this file, not the source file. */
#include "common.h"
typedef struct {
    f32 v[4];
    s32 w16;
    f32 f20;
    s32 w24;
    s32 w28;
    f32 f32_;
    s32 w36;
    f32 f40;
    f32 f44;
} S_0030CD20;
/* localdecomp:start func_L01_00308508 */
#include "vu0.h"
void func_L01_00308508(s32 owner, vu0_v4 *start, vu0_v4 *end, u8 *controls) {
    extern void func_L01_00308238(void *, void *, void *, f32);
    extern void func_L01_003082D0(f32 *,f32 *,f32 *,f32 *,f32 *,f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(S_0030CD20 *, S_0030CD20 *, f32);
    extern void func_L01_003088D8(s32,s32,void *,s32);
    vu0_v4 points[11];
    vu0_v4 control0;
    vu0_v4 control1;
    vu0_v4 noise;
    vu0_v4 copy;
    s32 i;
    f32 t;
    for (i = 0; i < 10; i++) {
        t = (f32)i / 9.0f;
        func_L01_00308238(&points[i], start, end, t);
        vec_copy(&copy, end);
        *(vu0_q *)&control0 = *(vu0_q *)(controls + 0x50);
        *(vu0_q *)&control1 = *(vu0_q *)(controls + 0x60);
        vec_add_ab(&control1, &control1, &copy);
        vec_add_ba(&control0, &control0, start);
        func_L01_003082D0((f32 *)&points[i], (f32 *)start, (f32 *)end, (f32 *)&control0, (f32 *)&control1, t);
        noise.w = 0.0f;
        noise.x = func_003824E0(-1.0f, 1.0f);
        noise.y = func_003824E0(-1.0f, 1.0f);
        noise.z = func_003824E0(-1.0f, 1.0f);
        func_0038CF68((S_0030CD20 *)&noise, (S_0030CD20 *)&noise, 0.04f);
        vec_add_ab(&points[i], &points[i], &noise);
    }
    func_L01_003088D8(owner, 0x80, points, 11);
}
/* localdecomp:end func_L01_00308508 */
