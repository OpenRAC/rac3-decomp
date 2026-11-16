#include "common.h"

/* localdecomp:start func_L07_003E10D8 */
extern s32 func_L07_00444CC8(u8 *, s32, s32);
extern void func_L07_00442528(u8 *, s32, s32);
extern void func_L07_0040CA00(void *, void *, f32);

/* If the moby is not already in state 4 and func_L07_00444CC8 finds a target, copies the target's
 * position into its vars, sets a 0x32 timer and full 0x30 byte, and switches to state 4. */
void func_L07_003E10D8(u8 *object) {
    u8 *vars = *(u8 **)(object + 0x68);
    s32 result;
    if (object[0x20] != 4) {
        result = func_L07_00444CC8(object, -1, 0);
        if (result != 0) {
            func_L07_0040CA00(vars + 0x220, (void *)(result + 0x10), 0.416666687f);
            *(s16 *)(vars + 0x25C) = 0x32;
            object[0x30] = 0xFF;
            func_L07_00442528(object, 4, -1);
        }
    }
}
/* localdecomp:end func_L07_003E10D8 */
