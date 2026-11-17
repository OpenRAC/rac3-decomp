/* PAL near miss (Codex wave 6): near miss: 14 words differ with the file's flags.
 * Worker's note: Canonical MATCH with --divs 2; 12/49 places MATCH, remaining 1 jal diff (02.log,03-level03.log); catalogue twin mapping 00447470 vs 00451FB8 inconsistent. Type contract compiles (contract.log). No all-place exact; divs count 2 candidate only.
 */
#include "common.h"
/* localdecomp:start func_L01_00468D98 */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
void func_L01_00468D98(u8 *self) {
    extern f32 func_0038CEA8(f32 *);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern s32 func_L01_00447470(s32, s32, f32);
    vu0_v4 delta;
    u8 *vars = self + 0x20;
    f32 facing;
    vec_sub_ab(&delta, &D_L01_001E29C0, self + 0x30);
    if (func_0038CEA8(&delta.x) > 1.0f) {
        func_0038CF68(&delta.x, &delta.x, 0.25f);
    } else {
        func_0038CE20(&delta.x, &delta.x, 0.25f);
    }
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)(self + 0x10))
        : "m"(delta), "m"(*(vu0_v4 *)(vars + 0x10)) : "vf1", "vf2");
    *(f32 *)(vars + 4) = func_0038DAB8(*(f32 *)(vars + 4), *(f32 *)(vars + 0x1C));
    facing = func_0038D0B0(*(f32 *)(vars + 4));
    if (func_0038CB00(self + 0xA)) {
        if (facing < *(f32 *)(vars + 8) || facing < -0.9f) goto kill;
    }
    if (**(s32 **)vars == 0) {
kill:
        **(s32 **)vars = 0;
        func_003CD250(self);
        return;
    }
    if (*(f32 *)(vars + 8) < facing) {
        *(s32 *)(self + 4) = func_L01_00447470(0, *(s32 *)(vars + 0xC),
            (facing - *(f32 *)(vars + 8)) / (1.0f - *(f32 *)(vars + 8)));
    } else {
        *(s32 *)(self + 4) = 0;
    }
}
/* localdecomp:end func_L01_00468D98 */
