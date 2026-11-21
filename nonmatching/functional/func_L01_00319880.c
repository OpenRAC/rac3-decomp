/* functional: high. 79 words differ (VU load order/scheduling); all offsets, constants, random-call order and the final branch verified vs retail. */
/* PAL near miss (Codex wave 10): near miss: 79 words differ with the file's flags.
 * Worker's note: Best 2 diff: w542/func_L01_00319880.run04.log with --divs 2; VU loads at 0x6c and 0x88 reversed; retained after eight compiles, no flags changed
 */
#include "common.h"
/* localdecomp:start func_L01_00319880 */
#include "vu0.h"
void func_L01_00319880(u8 *owner, u8 *state) {
    extern void func_L01_00445208(void *, void *, void *, void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_00319A88(u8 *, s32, vu0_v4 *, s32);
    vu0_v4 points[13], a, b, noise, center;
    vu0_v4 *p = points;
    s32 i;
    for (i = 0; i < 12; i++) {
        a = *(vu0_v4 *)state;
        vec_copy(&center, state + 0x30);
        b = *(vu0_v4 *)(state + 0x10);
        vec_add_ba(&a, &a, state + 0x20);
        vec_add_ba(&b, &b, &center);
        func_L01_00445208(p, state + 0x20, state + 0x30, &a, &b, (f32)i / 11.0f);
        noise.w = 0.0f;
        noise.x = func_003824E0(-1.0f, 1.0f);
        noise.y = func_003824E0(-1.0f, 1.0f);
        noise.z = func_003824E0(-1.0f, 1.0f);
        func_0038CF68((f32 *)&noise, (f32 *)&noise, 0.075f);
        vec_add_ab(p, p, &noise);
        p++;
    }
    if (*(s32 *)(state + 0x98) >= 8) {
        func_L01_00319A88(owner, func_00382498(64, 128), points, 13);
    } else {
        func_L01_00319A88(owner, func_00382498(0, 64), points, 13);
    }
}
/* localdecomp:end func_L01_00319880 */
