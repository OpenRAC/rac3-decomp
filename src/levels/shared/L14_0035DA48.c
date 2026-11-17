#include "common.h"

/* localdecomp:start func_L14_0035DA48 */
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *func_L01_003F79D8(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern f32 D_L14_001E20D8[];
extern void func_L01_002FFF00(void);

void func_L14_0035DA48(u8 *obj, s32 idx) {
    f32 vec[3];
    f32 f20;
    f32 f21;
    u8 *r;
    s32 m = 1 << idx;

    *(u16 *)(obj + 0x7C) &= ~m;
    (*(u16 **)(obj + 0x68))[0x36 / 2]--;
    f20 = func_0038DAB8(func_L01_00443A18(90.0f, 120.0f) * 0.017453292f, D_L14_001E20D8[0]);
    f21 = func_003824E0(2.0f, 4.0f) * 0.020000001f;
    vec[0] = func_0038D098(f20) * f21;
    vec[1] = func_0038D0B0(f20) * f21;
    vec[2] = 0.0f;
    vec[2] = func_003824E0(5.0f, 8.0f) * 0.020000001f;
    r = func_L01_003F79D8(obj, 1, *(s16 *)(obj + 0xAA), idx, obj + 0x10, obj + 0xF0, vec, 0xFF, 10.0f, 15.0f, 0x50, 0, 0x80);
    if (r != 0)
        *(void (**)(void))(r + 0x64) = func_L01_002FFF00;
}
/* localdecomp:end func_L14_0035DA48 */
