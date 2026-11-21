#include "common.h"

/* NTSC-U counterpart of func_L01_0032BDD8 (src/levels/shared/L01_0032B408.c): 4 -> 5 */
#include "vu0.h"

/* localdecomp:start func_L01_0032B970 */
/* from the NTSC-U draft of func_L01_0032B970 (nonmatching/levels/func_L01_0032B970.c) */
/* log: draft with PAL catalogue names (func_0037E1D8, func_003BE988, func_003886E8, func_0037E250, func_L01_00465020) -> MATCH under the file's @ps2as line */
extern s32 func_0037E1D8(s32);
extern f32 func_003BE988(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_L01_00465020(void *, void *, f32, f32, s32);

void func_L01_0032B970(u8 *moby) {
    f32 velocity[4];
    f32 got;
    u8 *vars = *(u8 **)(moby + 0x68);

    if (func_0037E1D8(5) != 0) {
        return;
    }
    got = func_003BE988(moby + 0x10, velocity);
    func_003886E8(velocity, vars, 0.25f);
    func_L01_00465020(moby + 0x10, velocity, func_0037E250(0.05f, 0.1f) * 210000.0f, got, 0x88A0A0A0);
}
/* localdecomp:end func_L01_0032B970 */
