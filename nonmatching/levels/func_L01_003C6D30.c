/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_003C54B0, the NTSC-U twin of func_L01_003C6D30, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L01_003C64E0.c's current line.
 * Worker's note: 77 diff; permitted GNU assembler uses two lit4 loads instead of inline 0x3C8EFA35 and 0x3C888889; core arithmetic sequence preserved; store scheduling also differs; no flags_alt; forbidden flags not tried; best log func_L01_003C54B0.check01.log
 */
#include "common.h"

/* localdecomp:start func_L01_003C54B0 */
extern f32 D_001DEC98_sda, D_001DEC94_sda, D_001DECA4_sda, D_001DECA8_sda, D_001DECAC_sda, D_001DEC9C_sda, D_001DECA0_sda;
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);

void func_L01_003C54B0(s32 a0, u8 *obj, f32 *p1, f32 *p2, f32 *p3)
{
    *(f32 *)(obj + 0xB4) = func_00389380(*(f32 *)(obj + 0xB4), D_001DEC98_sda * 0.01745329238474369f * 0.01666666753590107f);
    *p1 = func_00388978(*(f32 *)(obj + 0xB4)) * D_001DEC94_sda;
    *p2 = D_001DECA4_sda * func_00388978(*(f32 *)(obj + 0xB8)) * func_00388978(*(f32 *)(obj + 0xBC)) * 1.5f;
    *p3 = D_001DECA4_sda * func_00388978(*(f32 *)(obj + 0xB8)) * func_00388960(*(f32 *)(obj + 0xBC));
    *(f32 *)(obj + 0xB8) = func_00389380(*(f32 *)(obj + 0xB8), D_001DECA8_sda * 0.01745329238474369f * 0.01666666753590107f);
    *(f32 *)(obj + 0xBC) = func_00389380(*(f32 *)(obj + 0xBC), D_001DECAC_sda * 0.01745329238474369f * 0.01666666753590107f);
    *p3 += func_00388978(*(f32 *)(obj + 0xB4) + D_001DEC9C_sda) * D_001DECA0_sda;
}
/* localdecomp:end func_L01_003C54B0 */
