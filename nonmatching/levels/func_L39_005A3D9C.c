/* NTSC-U native C, moved here from src/us/levels/ (commit 59c3b0b2), in NTSC-U names and addresses.
 * Not a function: config/us/levels/boundaries.tsv joins NTSC-U's 0x5A3D9C to func_L39_005A3D20 (the
 * beqz at 0x5A3D8C branches to it; PAL's func_L39_005A5990 takes in func_L39_005A5A0C the same way).
 * Its 9 instructions are the end of that function, and equal frontbin's func_0039B940 (an inlined
 * tail). A starting point for the NTSC-U C of func_L39_005A3D20's last block; it uses a literal
 * address, which matched C may not. */
#include "common.h"

/* localdecomp:start func_L39_005A3D9C */
extern s32 D_001A4568[];

void func_L39_005A3D9C(void) {
    if (D_001A4568[0] != 2) {
        *(s32 *)0x00240578 = 4;
    }
}
/* localdecomp:end func_L39_005A3D9C */
