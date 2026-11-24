#include "common.h"

/* NTSC-U counterpart of func_L08_0039C930 (src/levels/08_aquatos/L08_0039C930.c) */

/* localdecomp:start func_U_L08_0039AF00 */
#include "vu0.h"
extern s32 func_0037E1D8(s32);
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L01_00467BD8(f32, f32, void *, s32, s32, s32);

void func_U_L08_0039AF00(u8 *a0)
{
    vu0_v4 v;
    f32 mid = 1.0f;

    if (*(u8 *)(a0 + 0x31) != 0) {
        if (func_0037E1D8(0xE) == 0) {
            f32 ang, r, a, b;
            s32 n;

            ang = func_0037E2A8();
            r = func_0037E250(0.0f, 0.1f);
            a = func_0037E250(0.0f, mid);
            b = func_0037E250(mid, 2.0f);
            n = func_0037E250(180.0f, 240.0f);
            v.x = func_00388960(ang) * r;
            v.y = func_00388978(ang) * r;
            v.z = 0.0f;
            vec_add_ba(&v, &v, a0 + 0x10);
            func_L01_00467BD8(a, b, &v, 0x40005840, 0x5840, n);
        }
        if (func_0037E1D8(4) == 0) {
            f32 ang, r, a, b;
            s32 n;

            ang = func_0037E2A8();
            r = func_0037E250(0.0f, 0.1f);
            a = func_0037E250(0.0f, 3.5f);
            b = func_0037E250(3.5f, 4.5f);
            n = func_0037E250(180.0f, 240.0f);
            v.x = func_00388960(ang) * r;
            v.y = func_00388978(ang) * r;
            v.z = 0.0f;
            vec_add_ba(&v, &v, a0 + 0x10);
            func_L01_00467BD8(a, b, &v, 0x30005840, 0x7040, n);
        }
    }
}
/* localdecomp:end func_U_L08_0039AF00 */
