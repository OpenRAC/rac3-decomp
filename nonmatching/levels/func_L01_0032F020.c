/* NTSC-U draft (Claude wave S/us): C of func_L01_0032EB28, the NTSC-U twin of func_L01_0032F020, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L01_0032EB28", whose code is not the PAL one).
 * Worker's note: MATCH only with @ps2as added (re-checked: PAL file src/levels/shared/L01_0032C6B8.c flags 22 diff: the float literals are inline lui/ori/mtc1 in retail (Ps2EeAs li.s, docs/wiki/Matching-Patterns.md line 139 says use @ps2as), lwc1 from the gp pool with plain ...
 */
#include "common.h"

/* localdecomp:start func_L01_0032EB28 */
extern s32 func_0037E1D8(s32);
extern f32 func_003BE988(u8 *position, f32 *out);
extern void func_003886E8(f32 *, f32 *, f32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00465020(u8 *position, f32 *velocity, s32 colour, f32 size, f32 f13);

void func_L01_0032EB28(u8 *moby)
{
    f32 velocity[4];
    f32 got;
    u8 *vars = *(u8 **)(moby + 0x68);

    if (func_0037E1D8(5) != 0) {
        return;
    }
    got = func_003BE988(moby + 0x10, velocity);
    func_003886E8(velocity, (f32 *)vars, 0.25f);
    func_L01_00465020(moby + 0x10, velocity, 0x88A0A0A0, func_0037E250(0.05f, 0.1f) * 210000.0f, got);
}
/* localdecomp:end func_L01_0032EB28 */
