/* NTSC-U draft (Claude wave C2): C of func_L18_00353648, the NTSC-U twin of func_L18_00354250, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L18_00353648", whose code is not the PAL one).
 * Worker's note: flags: MATCH only with '-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (the float 1/12 = 0x3DAAAAAB is built with lui/ori/mtc1; with the PAL file's flags it is a gp literal load, 38 diff by shift). C is final: PAL-C template func_L14_00354030 reworked ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L18_00353648 */
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_0044F090(void *, s32, void *, s32, s32, f32, f32, f32, f32, f32, s32, f32, f32, s32, s32);
extern s32 func_0039FE80(s32, s32, u8 *);
extern void func_L18_00353590(u8 *, s32);

void func_L18_00353648(u8 *a0) {
    vu0_v4 v;
    u8 *s = *(u8 **)(a0 + 0x68);
    func_L01_0032FE90(a0 + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.5f, 10.0f, 0.0f, 2.0f,
                      0, 0, 0, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                      0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_00388830(&v, s + 0x290, 0.083333336f);
    func_L01_0044F090(a0, 0x3FF, &v, 1, 0x23, -1.0f, 3.0f, 6.0f, 5.0f, 15.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0);
    func_0039FE80(0, 0, a0);
    func_L18_00353590(a0, 1);
}
/* localdecomp:end func_L18_00353648 */
