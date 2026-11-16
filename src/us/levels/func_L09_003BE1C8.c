#include "common.h"

/* NTSC-U counterpart of func_L09_003BFA48 (src/levels/09_tyhrranosis/L09_003BFA48.c) */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L09_003BE1C8 */
/* follows func_L09_003BFC90 (the same effect with the parameters fixed) */
typedef struct { u8 pad0[2]; u8 b2; u8 b3; } S_003BFA48;
typedef struct { u8 pad[0x5C]; u8 *p5C; } G_003BFA48;
typedef struct {
    u8 pad[0x20]; f32 f20; u8 pad24[4]; s32 i28; s32 i2C; u8 pad30[0x10]; f32 f40; u8 pad44[4]; s32 i48;
} T_003BFA48;
extern s32 func_L01_0044AF40(void *, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern G_003BFA48 D_L09_00220098;
extern T_003BFA48 D_L09_001E2C00;

void func_L09_003BE1C8(u8 *a0) {
    f32 vel[4];
    f32 pos[4];
    s32 i, n;
    f32 size;
    S_003BFA48 *s;

    if (func_L01_0044AF40(a0, 16.0f)) {
        D_L09_001E2C00.f20 = 0.2f;
        D_L09_001E2C00.i2C = 0;
        D_L09_001E2C00.i28 = 0x64;
        D_L09_001E2C00.i48 = 0x64;
        D_L09_001E2C00.f40 = 0.1f;
        for (i = 0; i < 30; i++) {
            size = func_0037E250(5.0f, 10.0f) * 210000.0f;
            vel[0] = func_L01_00440918(0.0833333358168602f, 0.1666666716337204f);
            vel[1] = func_L01_00440918(0.0833333358168602f, 0.1666666716337204f);
            vel[2] = func_0037E250(0.25f, 0.8f) * 0.01666666753590107f;
            *(u128_t *)pos = *(u128_t *)(a0 + 0x10);
            pos[0] += func_L01_00440918(0.0f, 0.6f);
            pos[1] += func_L01_00440918(0.0f, 0.6f);
            pos[2] += func_L01_00440918(0.0f, 0.2f);
            n = func_0037E208(0x23, 0x78);
            s = (S_003BFA48 *)func_L01_0046C468(pos, vel, n, 0x10909090, func_0037E1D8(2) ? 1 : -1, 50, 0, size, size, 0.0f, 0);
            if (s) {
                s->b2 = *D_L09_00220098.p5C;
                s->b3 = 0x44;
            }
        }
    }
}
/* localdecomp:end func_L09_003BE1C8 */
