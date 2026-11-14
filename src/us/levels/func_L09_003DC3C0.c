#include "common.h"

/* NTSC-U counterpart of func_L09_003DDEE0. */
#include "vu0.h"

/* localdecomp:start func_L09_003DC3C0 */
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_003D72E0(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_0032FE90(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 D_L09_00220098[];
__asm__(".extern D_L09_00220098, 16");

void func_L09_003DC3C0(f32 x, u8 *p, s32 n) {
    u8 loc[0x10];
    u8 *r;
    s32 k;
    f32 f22, f21, f20, f23, t;
    s32 v;
    s32 cnt;

    func_0037E2F0(loc, 0.016666668f, 0.033333335f);
    func_L01_003D72E0(p, loc, 60, 7, 5, n, 0x1FF, 0, -1e+05f, x * 3.5f, -5.0f);
    if (func_0037E1D8(2) != 0) {
            func_L01_0032FE90(p, x, 0, 0, 0, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f,
                0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    }
    if (n > 0) {
        u8 *tb = D_L09_00220098;
        cnt = n;
        v = 0xF2;
        do {
            func_0037E2F0(loc, 0.05833333731f, 0.1166666746f);
            k = func_0037E208(-2, 2);
            f22 = x * 3.0f;
            t = func_0037E250(-6.0f, -10.0f);
            f23 = f22 * 2.1e+05f;
            r = func_L01_00472438(p, loc, 60, k, 0x7F407FFF, 0x407FFF, f23, f23, t, 0);
            if (r != 0) {
                r[9] = (u8)v;
                r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
            }
            func_003886E8(loc, loc, 2.0f);
            *(f32 *)(loc + 8) = fabs_asm(*(f32 *)(loc + 8));
            k = func_0037E208(-2, 2);
            f21 = (f22 * 0.4f) * 2.1e+05f;
            f20 = (f22 * 0.04f) * 2.1e+05f;
            t = func_0037E250(24.0f, 4e+01f);
            r = func_L01_00472438(p, loc, 60, k, 0x7F0048FF, 0x48FF, f21, f20, t, 0);
            if (r != 0) {
                r[9] = (u8)v;
                r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
            }
            cnt--;
        } while (cnt != 0);
    }
}
/* localdecomp:end func_L09_003DC3C0 */
