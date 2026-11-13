#include "common.h"

/* NTSC-U counterpart of func_L19_003B2968 (src/levels/19_thran_asteroid_belt/L19_003B1A80.c): 0.02 -> 0.0166667 */
extern void func_L19_003B0CD8(u8 *a0, s32 a1);

/* localdecomp:start func_L19_003B0CD8 */
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *func_L01_003F5830(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern f32 D_L19_001E2098_003B0CD8[];
extern void func_L01_002FFEA8(void);

void func_L19_003B0CD8(u8 *obj, s32 idx) {
    f32 vec[3];
    f32 f20;
    f32 f21;
    u8 *r;
    s32 m = 1 << idx;

    if (*(u16 *)(obj + 0x7C) & m) {
        *(u16 *)(obj + 0x7C) &= ~m;
        f20 = func_0038DAB8(func_L01_00440918(90.0f, 120.0f) * 0.017453292f, D_L19_001E2098_003B0CD8[0]);
        f21 = func_003824E0(2.0f, 4.0f) * 0.0166666675f;
        vec[0] = func_0038D098(f20) * f21;
        vec[1] = func_0038D0B0(f20) * f21;
        vec[2] = 0.0f;
        vec[2] = func_003824E0(5.0f, 8.0f) * 0.0166666675f;
        r = func_L01_003F5830(obj, 1, *(s16 *)(obj + 0xAA), idx, obj + 0x10, obj + 0xF0, vec, 0xFF, 90.0f, 15.0f, 0xB4, 0, 0x80);
        if (r != 0)
            *(void (**)(void))(r + 0x64) = func_L01_002FFEA8;
    }
}
/* localdecomp:end func_L19_003B0CD8 */
