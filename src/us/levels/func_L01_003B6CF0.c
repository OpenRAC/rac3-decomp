#include "common.h"

#include "vu0.h"

/* localdecomp:start func_L01_003B6CF0 */
extern f32 D_001DE80C_sda;
__asm__(".extern D_001DE80C_sda, 4");
extern s32 D_001DE814_sda;
__asm__(".extern D_001DE814_sda, 4");
extern f32 D_001DE818_sda;
__asm__(".extern D_001DE818_sda, 4");
extern f32 D_001DE81C_sda;
__asm__(".extern D_001DE81C_sda, 4");
extern f32 D_001DE820_sda_003B6CF0;
__asm__(".extern D_001DE820_sda_003B6CF0, 4");
extern f32 D_001DE828_sda;
__asm__(".extern D_001DE828_sda, 4");
extern f32 D_001DE82C_sda;
__asm__(".extern D_001DE82C_sda, 4");
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_003D72E0(void *, void *, f32, f32, s32, f32, s32, s32, s32, void *, s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_0032FE90(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 D_L01_00221118[];
__asm__(".extern D_L01_00221118, 16");

void func_L01_003B6CF0(f32 x, u8 *p, s32 n, u8 *a, s32 cnt, s32 w) {
    u8 loc[0x10];
    u8 *r;
    s32 k;
    f32 fa, f21, f20, t;
    s32 v;

    func_0037E2F0(loc, D_001DE80C_sda * 0.5f * 0.016666668f, D_001DE80C_sda * 0.016666668f);
    func_L01_003D72E0(p, loc, -1e+05f, x * 3.5f, D_001DE814_sda, -5.0f, 7, 5, n, a, 0);
    if (cnt > 0) {
        if (func_0037E1D8(cnt) == 0) {
            func_L01_0032FE90(p, x, 0, 2, 2, 2, 1, 2, 1, 0.0f, 0.0f, 0.0f,
                0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
    }
    if (n > 0) {
        u8 *tb = D_L01_00221118;
        cnt = n;
        v = 0xF2;
        do {
            func_0037E2F0(loc, D_001DE818_sda * 0.5f * 0.016666668f, D_001DE818_sda * 0.016666668f);
            k = func_0037E208(-2, 2);
            fa = D_001DE820_sda_003B6CF0;
            fa = fa * x;
            fa = fa * 2.1e+05f;
            t = func_0037E250(D_001DE828_sda * 0.6f, D_001DE828_sda);
            r = func_L01_00472438(p, loc, w, k, 0x7F407FFF, 0x407FFF, fa, fa, t, 0);
            if (r != 0) {
                r[9] = (u8)v;
                r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
            }
            if (func_0037E1D8(5) == 0) {
                func_003886E8(loc, loc, D_001DE81C_sda);
                *(f32 *)(loc + 8) = fabs_asm(*(f32 *)(loc + 8));
                k = func_0037E208(-2, 2);
                f20 = D_001DE820_sda_003B6CF0;
                f20 = f20 * x;
                f21 = f20 * 0.04f;
                f20 = f20 * 0.4f;
                f21 = f21 * 2.1e+05f;
                f20 = f20 * 2.1e+05f;
                t = func_0037E250(D_001DE82C_sda * 0.6f, D_001DE82C_sda);
                r = func_L01_00472438(p, loc, w, k, 0x7F0048FF, 0x48FF, f20, f21, t, 0);
                if (r != 0) {
                    r[9] = (u8)v;
                    r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
                }
            }
            cnt--;
        } while (cnt != 0);
    }
}
/* localdecomp:end func_L01_003B6CF0 */
