/* PAL near miss (Codex wave 10): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: Compile blocked by existing later typedef Vec4_0039E0C8 needed by exact func_0038CF68 signature; move that existing typedef before this block for context correction. Substantive fresh PAL draft retained; build/codex/w516/func_L01_0039BD08.check.1.log
 */
#include "common.h"
/* localdecomp:start func_L01_0039BD08 */
#include "vu0.h"
extern s32 D_001DE0F4_sda;
void func_L01_0039BD08(u8 *owner, u8 *state) {
    extern void func_L01_00445208(void *, void *, void *, void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(Vec4_0039E0C8 *, Vec4_0039E0C8 *, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_0039C560(u8 *, s32, void *, s32);
    vu0_q start, end;
    Vec4_0039E0C8 jitter;
    vu0_q delta;
    vu0_v4 *points = __builtin_alloca(D_001DE0F4_sda * 16);
    s32 i;
    for (i = 0; i < D_001DE0F4_sda; i++) {
        start = *(vu0_q *)state;
        end = *(vu0_q *)(state + 0x10);
        vec_copy(&delta, state + 0x30);
        vec_add_ab(&start, &start, state + 0x20);
        vec_add_ab(&end, &end, &delta);
        func_L01_00445208(points + i, state + 0x20, state + 0x30, &start, &end, (f32)i / (D_001DE0F4_sda - 1));
        jitter.v[3] = 0.0f;
        jitter.v[0] = func_003824E0(-1.0f, 1.0f);
        jitter.v[1] = func_003824E0(-1.0f, 1.0f);
        jitter.v[2] = func_003824E0(-1.0f, 1.0f);
        func_0038CF68(&jitter, &jitter, 0.075f);
        vec_add_ab(points + i, points + i, &jitter);
    }
    if (*(s32 *)(state + 0x98) >= 8) {
        func_L01_0039C560(owner, func_00382498(64, 128), points, D_001DE0F4_sda + 1);
    } else {
        func_L01_0039C560(owner, func_00382498(0, 64), points, D_001DE0F4_sda + 1);
    }
}
/* localdecomp:end func_L01_0039BD08 */
