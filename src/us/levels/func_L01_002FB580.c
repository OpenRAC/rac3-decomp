#include "common.h"

/* NTSC-U counterpart of func_L01_002FB5A8 (src/levels/shared/L01_002F7800.c): 4 -> 5 */
extern f32 func_003824E0(f32, f32);

/* localdecomp:start func_L01_002FB580 */
extern s32 func_00382468(s32);
extern f32 func_003C3EC8(u8 *position, f32 *out);
extern void func_0038CE20(f32 *, f32 *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00465020(u8 *position, f32 *velocity, s32 colour, f32 size, f32 f13);

/* One frame in four on average, a bubble (particle_spawn_bubble, type 0x22) at the moby, moving
 * at a quarter of the vector its vars start with; func_003C3EC8's result (it also writes the
 * buffer, which the scale then overwrites) goes to the bubble as its f13. */
void func_L01_002FB580(u8 *moby)
{
    f32 velocity[4];
    f32 got;
    u8 *vars = *(u8 **)(moby + 0x68);

    if (func_00382468(5) != 0) {
        return;
    }
    got = func_003C3EC8(moby + 0x10, velocity);
    func_0038CE20(velocity, (f32 *)vars, 0.25f);
    func_L01_00465020(moby + 0x10, velocity, 0x88A0A0A0, func_003824E0(0.05f, 0.1f) * 210000.0f, got);
}
/* localdecomp:end func_L01_002FB580 */
