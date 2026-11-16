/* NTSC-U draft (Claude wave C2): C of func_L07_003CA6C0, the NTSC-U twin of func_L07_003CC0C0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 3 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L07_003CA6C0", whose code is not the PAL one).
 * Worker's note: 3 diff with @ps2as (inline 1/60 = 0.016666668f; the PAL flags have none): loop condition 'lw/slt/bnez' uses $v0 in mine, $v1 in retail (the hoisted 'por $v0,$zero,$zero' zero quad lives in $v0). Source: u[4] = 0 via *(u128_t*)u = 0, three ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L07_003CC0C0 (src/levels/shared/L07_003CB9B8.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L07_003CA6C0 */
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00460318(void *, void *, s32, s32, s32, s32, s32, s32);
extern s32 D_001DE714_sda;
extern f32 D_001DE71C_sda;
extern f32 D_001DE720_sda;
extern f32 D_001DE724_sda;
extern f32 D_001DE728_sda;
extern f32 D_001DE710_sda;
extern s32 D_001DE700_sda;
extern s32 D_001DE6FC_sda;
extern s32 D_001DE6F8_sda;
extern s32 D_001DE6F4_sda;
extern s32 D_001DE704_sda;
extern s32 D_001DE708_sda;
extern s32 D_001DE70C_sda;
extern s32 D_001DE718_sda;
__asm__(".extern D_001DE714_sda, 4");
__asm__(".extern D_001DE71C_sda, 4");
__asm__(".extern D_001DE720_sda, 4");
__asm__(".extern D_001DE724_sda, 4");
__asm__(".extern D_001DE728_sda, 4");
__asm__(".extern D_001DE710_sda, 4");
__asm__(".extern D_001DE700_sda, 4");
__asm__(".extern D_001DE6FC_sda, 4");
__asm__(".extern D_001DE6F8_sda, 4");
__asm__(".extern D_001DE6F4_sda, 4");
__asm__(".extern D_001DE704_sda, 4");
__asm__(".extern D_001DE708_sda, 4");
__asm__(".extern D_001DE70C_sda, 4");
__asm__(".extern D_001DE718_sda, 4");

void func_L07_003CA6C0(u8 *obj)
{
    f32 v[4];
    f32 u[4];
    s32 i;

    for (i = 0; i < D_001DE714_sda; ) {
        *(u128_t *)u = 0;
        i++;
        u[0] = func_0037E250(D_001DE71C_sda, D_001DE720_sda);
        u[1] = func_0037E250(D_001DE71C_sda, D_001DE720_sda);
        u[2] = func_0037E250(D_001DE724_sda, D_001DE728_sda);
        *(u128_t *)v = *(u128_t *)u;
        func_00388830(v, v, D_001DE710_sda * 0.016666668f);
        func_L01_00460318(obj, v,
                          (D_001DE700_sda << 24) | (D_001DE6FC_sda << 16) | (D_001DE6F8_sda << 8) | D_001DE6F4_sda,
                          (D_001DE6FC_sda << 16) | (D_001DE6F8_sda << 8) | D_001DE6F4_sda,
                          D_001DE704_sda, D_001DE708_sda, D_001DE70C_sda, D_001DE718_sda);
    }
}
/* localdecomp:end func_L07_003CA6C0 */
