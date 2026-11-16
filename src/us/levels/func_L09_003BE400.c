#include "common.h"

/* NTSC-U counterpart of func_L09_003BFC90 (src/levels/09_tyhrranosis/L09_003BFC90.c) */
#include "vu0.h"

/* localdecomp:start func_L09_003BE400 */
typedef struct { u8 pad0[2]; u8 b2; u8 b3; } S_003BFC90;
typedef struct { u8 pad[0x5C]; u8 *p5C; } G_003BFC90;
typedef struct { u8 pad[0x20]; f32 f20; u8 pad24[4]; s32 i28; s32 i2C; } T_003BFC90;
extern s32 func_L01_0044AF40(void *, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern f32 D_L09_001DE730;
__asm__(".extern D_L09_001DE730, 4");
extern s32 D_L09_001DE734;
__asm__(".extern D_L09_001DE734, 4");
extern s32 D_L09_001DE738;
__asm__(".extern D_L09_001DE738, 4");
extern s32 D_L09_001DE73C;
__asm__(".extern D_L09_001DE73C, 4");
extern f32 D_L09_001DE740;
__asm__(".extern D_L09_001DE740, 4");
extern f32 D_L09_001DE744;
__asm__(".extern D_L09_001DE744, 4");
extern f32 D_L09_001DE748_003BE400;
__asm__(".extern D_L09_001DE748_003BE400, 4");
extern f32 D_L09_001DE74C;
__asm__(".extern D_L09_001DE74C, 4");
extern f32 D_L09_001DE750_003BE400;
__asm__(".extern D_L09_001DE750_003BE400, 4");
extern f32 D_L09_001DE758;
__asm__(".extern D_L09_001DE758, 4");
extern s32 D_L09_001DE760;
__asm__(".extern D_L09_001DE760, 4");
extern G_003BFC90 D_L09_00220098;
extern T_003BFC90 D_L09_001E2C00;

void func_L09_003BE400(u8 *a0, s32 flag, f32 x, f32 y) {
    f32 vel[4];
    f32 pos[4];
    s32 which = 0;
    s32 ok;
    s32 count, i, n;
    f32 lo, hi, sx, sy, a, b, size;
    S_003BFC90 *s;

    if (func_L01_0044AF40(a0, x)) {
        ok = 1;
        which = 1;
    } else {
        ok = func_L01_0044AF40(a0, y) != 0;
    }
    if (ok) {
        count = flag ? D_L09_001DE73C : D_L09_001DE738;
        lo = flag ? D_L09_001DE744 : D_L09_001DE740;
        hi = flag ? D_L09_001DE74C : D_L09_001DE748_003BE400;
        sx = flag ? D_L09_001DE744 : D_L09_001DE750_003BE400;
        sy = flag ? D_L09_001DE74C : D_L09_001DE758;
        for (i = 0; i < count; i++) {
            size = func_0037E250(lo, hi) * 210000.0f;
            a = sx * 0.01666666753590107f;
            b = sy * 0.01666666753590107f;
            vel[0] = func_L01_00440918(a, b);
            vel[1] = func_L01_00440918(a, b);
            vel[2] = func_0037E250(0.25f, 0.8f) * 0.01666666753590107f;
            func_003BDA38(a0, which ? 0x34 : 0x35, pos);
            pos[0] += func_L01_00440918(0.0f, 0.6f);
            pos[1] += func_L01_00440918(0.0f, 0.6f);
            pos[2] += func_L01_00440918(0.0f, 0.2f);
            n = func_0037E208(0x23, 0x78);
            s = (S_003BFC90 *)func_L01_0046C468(pos, vel, n, D_L09_001DE760, func_0037E1D8(2) ? 1 : -1, 50, 0, size, size, 0.0f, 0);
            if (s) {
                s->b2 = *D_L09_00220098.p5C;
                s->b3 = 0x44;
            }
        }
        if (flag) {
            D_L09_001E2C00.f20 = D_L09_001DE730;
            D_L09_001E2C00.i2C = 0;
            D_L09_001E2C00.i28 = D_L09_001DE734;
        }
    }
}
/* localdecomp:end func_L09_003BE400 */
