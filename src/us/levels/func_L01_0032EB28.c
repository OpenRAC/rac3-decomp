#include "common.h"

/* NTSC-U counterpart of func_L01_0032F020 (src/levels/shared/L01_0032C6B8.c): func_0037E1D8 takes 5 for PAL's 4 */
/* localdecomp:start func_L01_0032EB28 */
extern s32 func_0037E1D8(s32);
extern f32 func_003BE988(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_L01_00465020(s32, s32, f32, f32, s32);

void func_L01_0032EB28(u8 *a0) {
    f32 v[4];
    f32 h;
    u8 *s = *(u8 **)(a0 + 0x68);

    if (func_0037E1D8(5) != 0) {
        return;
    }
    h = func_003BE988(a0 + 0x10, v);
    func_003886E8(v, s, 0.25f);
    func_L01_00465020((s32)(a0 + 0x10), (s32)v, func_0037E250(0.05f, 0.1f) * 210000.0f, h, 0x88A0A0A0);
}
/* localdecomp:end func_L01_0032EB28 */
