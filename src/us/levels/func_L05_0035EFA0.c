#include "common.h"

/* localdecomp:start func_L05_0035EFA0 */
extern void func_L05_0043E4A0(u8 *, u8 *, f32, f32, f32, f32, s32);
extern f32 func_L05_00405B68(f32, f32);

/* Per-frame step of a moby: sets its scale from its class to half and eases its heading angle
 * toward the direction of a target point stored in its vars. */
void func_L05_0035EFA0(u8 *object) {
    u8 *vars = *(u8 **)(object + 0x68);
    f32 direction;
    *(f32 *)(object + 0x2C) = *(f32 *)(*(u8 **)(object + 0x24) + 0x24) * 0.5f;
    direction = func_L05_00405B68(*(f32 *)(vars + 0x30) - *(f32 *)(object + 0x10),
                                   *(f32 *)(vars + 0x34) - *(f32 *)(object + 0x14));
    {
        f32 scale = 0.00014544411f;
        func_L05_0043E4A0(object + 0xF8, vars + 0xAC, direction,
                           scale, scale, 0.023271058f, 0);
    }
}
/* localdecomp:end func_L05_0035EFA0 */
