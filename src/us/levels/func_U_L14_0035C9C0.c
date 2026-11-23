#include "common.h"

/* NTSC-U counterpart of PAL func_L14_0035DA48. */
/* localdecomp:start func_U_L14_0035C9C0 */
extern f32 func_L01_00440918(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern u8 *func_L01_003F5830(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern f32 D_L14_001E20D8[];
extern void func_L01_002FFEA8(void);

void func_U_L14_0035C9C0(u8 *obj, s32 idx) {
    f32 vec[3];
    f32 f20;
    f32 f21;
    u8 *r;
    s32 m = 1 << idx;

    *(u16 *)(obj + 0x7C) &= ~m;
    (*(u16 **)(obj + 0x68))[0x36 / 2]--;
    f20 = func_00389380(func_L01_00440918(90.0f, 120.0f) * 0.017453292f, D_L14_001E20D8[0]);
    f21 = func_0037E250(2.0f, 4.0f) * 0.016666668f;
    vec[0] = func_00388960(f20) * f21;
    vec[1] = func_00388978(f20) * f21;
    vec[2] = 0.0f;
    vec[2] = func_0037E250(5.0f, 8.0f) * 0.016666668f;
    r = func_L01_003F5830(obj, 1, *(s16 *)(obj + 0xAA), idx, obj + 0x10, obj + 0xF0, vec, 0xFF, 10.0f, 15.0f, 0x50, 0, 0x80);
    if (r != 0)
        *(void (**)(void))(r + 0x64) = func_L01_002FFEA8;
}
/* localdecomp:end func_U_L14_0035C9C0 */
