/* Historical draft retained for reference. Implementation now in
 * src/levels/07_annihilation_nation/L07_003E3770.c.
 */
/* PAL near miss (Codex wave 6): near miss: 77 words differ with the file's flags.
 * Worker's note: 77 positional diff; scalar tail is shifted by one missing nop, VU0 block prevents retail interleaving of prologue/scalar setup. Shared vu0.h j-operand helper fails fixed flags (forbidden vf17 spill), log .02. Real draft out/func_L07_003E3B30.near.c; actual ...
 */
#include "common.h"
/* localdecomp:start func_L07_003E3B30 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003E3B30;
extern V_003E3B30 D_L07_001E1EC0[];
void func_L07_003E3B30(u8 *obj) {
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_003C2F58(void *, s32, void *);
    extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
    V_003E3B30 delta, position;
    f32 intensity;
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(delta) : "m"(D_L07_001E1EC0[0]), "m"(*(V_003E3B30 *)(obj + 0x10)) : "vf1", "vf2");
    func_0038CF68(&delta, &delta, 1.0f);
    intensity = func_0038CE68(&delta, (u8 *)D_L07_001E1EC0 + 0x380);
    if (intensity > 0.0f) {
        func_003C2F58(obj, 0, &position);
        func_003D9508(&position, 0x31, 0x40605050, 1, intensity * 0.6f, 0.08f, 0.0f);
        func_003C2F58(obj, 1, &position);
        func_003D9508(&position, 0x31, 0x40605050, 1, intensity * 0.15f, 0.08f, 0.0f);
        func_003C2F58(obj, 2, &position);
        func_003D9508(&position, 0x31, 0x40605050, 1, intensity * 0.2f, 0.08f, 0.0f);
    }
}
/* localdecomp:end func_L07_003E3B30 */
