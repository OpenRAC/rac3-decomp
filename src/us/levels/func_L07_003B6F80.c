#include "common.h"

/* localdecomp:start func_L07_003B6F80 */
extern void func_L07_0044BF10(void *, void *, s32, f32, f32);

/* Clamps the angle at offset 0x218 of the moby's data to +-1.396 radians (80 degrees), then calls
 * func_L07_0044BF10 on the block at offset 0x1B0. */
void func_L07_003B6F80(u8 *object) {
    u8 *vars = *(u8 **)(object + 0x68);
    if (*(f32 *)(vars + 0x218) > 1.3962634f) {
        *(f32 *)(vars + 0x218) = 1.3962634f;
    } else if (*(f32 *)(vars + 0x218) < -1.3962634f) {
        *(f32 *)(vars + 0x218) = -1.3962634f;
    }
    func_L07_0044BF10(object, vars + 0x1B0, 1, 0.03f, 0.3f);
}
/* localdecomp:end func_L07_003B6F80 */
