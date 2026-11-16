/* PAL near miss (Codex wave 8): near miss: 5 words differ with the file's flags.
 * Worker's note: 5 diff / 103 words: build/codex/w413/func_L01_00335418.01.log; pointer induction retry gives 12 diffs (02.log). Retail increment between vadd/sqc2 and scalar store between lqc2 loads cannot interleave intact VU sequences. Fixed flags; contract compile clean; ...
 */
#include "common.h"
/* localdecomp:start func_L01_00335418 */
#include "vu0.h"
typedef struct { s32 *path; u8 pad[0x2C]; } Record_00335418;
typedef struct { u8 pad[0x3C]; Record_00335418 entries[1]; } Table_00335418;
extern Table_00335418 *D_L01_001DFC4C;
s32 func_L01_00335418(u8 *context, u8 *state, u8 *unused, u8 *vars, s32 unused2, u8 *cfg) {
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_L01_00456500(void *, s32);
    vu0_v4 center;
    s32 *path;
    s32 i;
    f32 angle, radius;
    if (*(s32 *)(cfg + 0x70) == -1) return 1;
    path = D_L01_0021F6C0[*D_L01_001DFC4C->entries[*(s32 *)(cfg + 0x70)].path];
    qzero(&center);
    for (i = 0; i < path[0]; i++) {
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(center) : "m"(*(vu0_v4 *)(path + 4 + i * 4)), "m"(center) : "vf1", "vf2");
    }
    func_0038CE20(&center, &center, 1.0f / (f32)path[0]);
    angle = func_00382538();
    radius = func_003824E0(2.0f, 10.0f);
    qzero(vars + 0x4A0);
    *(f32 *)(vars + 0x4A0) = func_0038D098(angle) * radius;
    *(f32 *)(vars + 0x4A4) = func_0038D0B0(angle) * radius;
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)(vars + 0x4A0)) : "m"(*(vu0_v4 *)(vars + 0x4A0)), "m"(center) : "vf1", "vf2");
    if (!func_L01_00456500(vars + 0x4A0, *(s32 *)(cfg + 0x70))) {
        *(s128 *)(vars + 0x4A0) = *(s128 *)&center;
    }
    if (*(s32 *)(state + 0x68) == 0) {
        *(s32 *)(state + 0x68) = func_00382498(300, 530);
    }
    context[0xBC] = 0;
    state[0x5E] = 0;
    return 0;
}
/* localdecomp:end func_L01_00335418 */
