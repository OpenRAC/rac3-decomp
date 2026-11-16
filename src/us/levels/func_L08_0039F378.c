#include "common.h"

/* NTSC-U counterpart of func_L08_003A0F48 (src/levels/08_aquatos/L08_003A0F48.c) */
#include "vu0.h"

/* localdecomp:start func_L08_0039F378 */
#include "vu0.h"
extern s32 func_0037E1D8(s32);
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L01_00467BD8(f32, f32, void *, s32, s32, s32);

void func_L08_0039F378(u8 *a0) {
    vu0_v4 v;
    f32 ang;
    f32 r;
    f32 c;
    f32 d;
    s32 n;
    f32 half;

    if (a0[0x31] == 0) {
        return;
    }
    half = 0.5f;
    if (func_0037E1D8(14) == 0) {
        ang = func_0037E2A8();
        r = func_0037E250(0.0f, 0.1f);
        c = func_0037E250(0.0f, 1.0f) * half;
        d = func_0037E250(1.0f, 2.0f) * half;
        n = func_0037E250(180.0f, 240.0f);
        v.x = func_00388960(ang) * r;
        v.y = func_00388978(ang) * r;
        v.z = 0.0f;
        vec_add_ba(&v, &v, a0 + 0x10);
        func_L01_00467BD8(c, d, &v, 0x40005840, 0x5840, n);
    }
    if (func_0037E1D8(4) == 0) {
        ang = func_0037E2A8();
        r = func_0037E250(0.0f, 0.1f);
        c = func_0037E250(0.0f, 3.5f) * half;
        d = func_0037E250(3.5f, 4.5f) * half;
        n = func_0037E250(180.0f, 240.0f);
        v.x = func_00388960(ang) * r;
        v.y = func_00388978(ang) * r;
        v.z = 0.0f;
        vec_add_ba(&v, &v, a0 + 0x10);
        func_L01_00467BD8(c, d, &v, 0x30005840, 0x7040, n);
    }
}
/* localdecomp:end func_L08_0039F378 */
