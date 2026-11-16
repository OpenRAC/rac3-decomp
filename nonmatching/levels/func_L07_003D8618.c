/* NTSC-U draft (Claude wave C4): C of func_L07_003D6A10, the NTSC-U twin of func_L07_003D8618, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L07_003D6A10", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (MATCH) only with the extra @ps2as; its PAL counterpart file src/levels/shared/L07_003D8618.c has no @ps2as (200 diff with its flags: retail builds 7 float constants with lui/ori/mtc1 (0.016666668f, -1e5f, 2.1e5f, 0.6f, 0.04f, 0.4f ...), ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003D6A10 */
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_003D72E0(f32, f32, void *, void *, s32, s32, s32, s32, void *, s32, f32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_0032FE90(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 D_001DE910_sda;
__asm__(".extern D_001DE910_sda, 4");
extern s32 D_001DE914_sda;
__asm__(".extern D_001DE914_sda, 4");
extern f32 D_001DE918_sda;
__asm__(".extern D_001DE918_sda, 4");
extern f32 D_001DE91C_sda;
__asm__(".extern D_001DE91C_sda, 4");
extern f32 D_001DE920_sda;
__asm__(".extern D_001DE920_sda, 4");
extern s32 D_001DE924_sda;
__asm__(".extern D_001DE924_sda, 4");
extern f32 D_001DE928_sda;
__asm__(".extern D_001DE928_sda, 4");
extern f32 D_001DE92C_sda;
__asm__(".extern D_001DE92C_sda, 4");
extern u8 D_L07_0021EC98[];
__asm__(".extern D_L07_0021EC98, 16");

void func_L07_003D6A10(f32 x, u8 *p, s32 n, u8 *a, s32 cnt) {
    u8 loc[0x10];
    u8 *r;
    s32 k;
    f32 f19, f20, f21, u, t;
    s32 v;

    func_0037E2F0(loc, D_001DE910_sda * 0.5f * 0.016666668f, D_001DE910_sda * 0.016666668f);
    func_L01_003D72E0(-1e+05f, x * 3.5f, p, loc, D_001DE914_sda, 7, 5, n, a, 0, -5.0f);
    if (cnt > 0) {
        if (func_0037E1D8(cnt) == 0) {
            func_L01_0032FE90(p, x, 0, 2, 2, 2, 1, 2, 1, 0.0f, 0.0f, 0.0f,
                0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
    }
    if (n > 0) {
        u8 *tb = D_L07_0021EC98;
        cnt = n;
        v = 0xF2;
        do {
            func_0037E2F0(loc, D_001DE918_sda * 0.5f * 0.016666668f, D_001DE918_sda * 0.016666668f);
            k = func_0037E208(-2, 2);
            f19 = D_001DE920_sda * x * 2.1e+05f;
            t = func_0037E250(D_001DE928_sda * 0.6f, D_001DE928_sda);
            r = func_L01_00472438(p, loc, D_001DE924_sda, k, 0x7F407FFF, 0x407FFF, f19, f19, t, 0);
            if (r != 0) {
                r[9] = (u8)v;
                r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
            }
            func_003886E8(loc, loc, D_001DE91C_sda);
            *(f32 *)(loc + 8) = fabs_asm(*(f32 *)(loc + 8));
            k = func_0037E208(-2, 2);
            u = D_001DE920_sda * x;
            f20 = u * 0.4f * 2.1e+05f;
            f21 = u * 0.04f * 2.1e+05f;
            t = func_0037E250(D_001DE92C_sda * 0.6f, D_001DE92C_sda);
            r = func_L01_00472438(p, loc, D_001DE924_sda, k, 0x7F0048FF, 0x48FF, f20, f21, t, 0);
            if (r != 0) {
                r[9] = (u8)v;
                r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
            }
            cnt--;
        } while (cnt != 0);
    }
}
/* localdecomp:end func_L07_003D6A10 */
