/* NTSC-U draft (Claude wave C2): C of func_L01_0044C9C8, the NTSC-U twin of func_L01_0044FC48, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as -mvu0-use-vf0-vf2") (NTSC-U twin "func_L01_0044C9C8", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (0 diff) only WITHOUT -mno-split-addresses (retail has lui $v0,%hi / addiu $a2,$v0,%lo around the stack adjust); with its PAL file's flags (L01_0044E130.c: -mno-split-addresses @ps2as) the 'la' macro gives 3 diff. Source: local s32 tbl[38] ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_0044FC48 (src/levels/shared/L01_0044E130.c) */
/* localdecomp:start func_L01_0044C9C8 */
extern void func_L01_0044ECE0(s32, s32, s32);
extern void func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);

void func_L01_0044C9C8(s32 idx, u8 flag)
{
    s32 tbl[38] = {
        0, 0xB1A, 0xB1B, 0xB1C, 0xB1D, 0xB1E, 0xB1F, 0xB20, 0xB21, 0xB22,
        0xB23, 0xB24, 0xB25, 0xB26, 0xB27, 0xB28, 0xB29, 0xB2A, 0xB2B, 0xB2C,
        0, 0xD33, 0xD34, 0xD35, 0, 0, 0, 0, 0, 0,
        0, 0xC55, 0xC77, 0xC75, 0xC76, 0xC78, 0xC78, 0xC79
    };

    if (flag != 0) {
        func_L01_0044ECE0(tbl[idx], -1, 0);
    } else if (tbl[idx] != 0) {
        func_L01_0044F2E8(0, 0xF, tbl[idx], 0xB4, 0, 0, 0);
    }
}
/* localdecomp:end func_L01_0044C9C8 */
