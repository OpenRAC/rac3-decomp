#include "common.h"

/* NTSC-U counterpart of func_L07_003D8618 (src/levels/shared/L07_003D8618.c) */
/* localdecomp:start func_L07_003D6A10 */
#include "vu0.h"

extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_003D72E0(f32, f32, void *, void *, s32, s32, s32, s32, s32, s32, f32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_0032FE90_003D6A10(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 D_L07_001DE910;
__asm__(".extern D_L07_001DE910, 4");
extern s32 D_L07_001DE914;
__asm__(".extern D_L07_001DE914, 4");
extern f32 D_L07_001DE918;
__asm__(".extern D_L07_001DE918, 4");
extern f32 D_L07_001DE91C;
__asm__(".extern D_L07_001DE91C, 4");
extern f32 D_L07_001DE920;
__asm__(".extern D_L07_001DE920, 4");
extern s32 D_L07_001DE924;
__asm__(".extern D_L07_001DE924, 4");
extern f32 D_L07_001DE928_003D6A10;
__asm__(".extern D_L07_001DE928_003D6A10, 4");
extern f32 D_L07_001DE92C;
__asm__(".extern D_L07_001DE92C, 4");
extern u8 D_L07_0021EC98_003D6A10[];

void func_L07_003D6A10(f32 x, void *p, s32 n, s32 a, s32 cnt) {
    u8 loc[0x10];
    u8 *r;

    func_0037E2F0(loc, D_L07_001DE910 * 0.5f * 0.016666668f, D_L07_001DE910 * 0.016666668f);
    func_L01_003D72E0(-1e+05f, x * 3.5f, p, loc, D_L07_001DE914, 7, 5, n, a, 0, -5.0f);
    if (cnt > 0) {
        if (func_0037E1D8(cnt) == 0) {
            func_L01_0032FE90_003D6A10(p, x, 0, 2, 2, 2, 1, 2, 1, 0.0f, 0.0f, 0.0f,
                0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
    }
    if (n > 0) {
        u8 *tb = D_L07_0021EC98_003D6A10;
        s32 i = n;
        do {
            func_0037E2F0(loc, D_L07_001DE918 * 0.5f * 0.016666668f, D_L07_001DE918 * 0.016666668f);
            {
                s32 j = func_0037E208(-2, 2);
                f32 s = D_L07_001DE920 * x * 210000.0f;
                f32 t = func_0037E250(D_L07_001DE928_003D6A10 * 0.6f, D_L07_001DE928_003D6A10);
                r = func_L01_00472438(p, loc, D_L07_001DE924, j, 0x7F407FFF, 0x407FFF, s, s, t, 0);
            }
            if (r != 0) {
                r[9] = 0xF2;
                r[2] = (*(u8 **)(tb + 0x184))[3];
            }
            func_003886E8(loc, loc, D_L07_001DE91C);
            *(f32 *)(loc + 8) = fabs_asm(*(f32 *)(loc + 8));
            {
                s32 j = func_0037E208(-2, 2);
                f32 u = D_L07_001DE920 * x;
                f32 s0 = u * 0.4f * 210000.0f;
                f32 s1 = u * 0.04f * 210000.0f;
                f32 t = func_0037E250(D_L07_001DE92C * 0.6f, D_L07_001DE92C);
                r = func_L01_00472438(p, loc, D_L07_001DE924, j, 0x7F0048FF, 0x48FF, s0, s1, t, 0);
            }
            if (r != 0) {
                r[9] = 0xF2;
                r[2] = (*(u8 **)(tb + 0x184))[3];
            }
            i--;
        } while (i != 0);
    }
}
/* localdecomp:end func_L07_003D6A10 */
