#include "common.h"

/* localdecomp:start func_L01_004CA1E8 */
extern s32 func_0011BB58(void *, s32, s32);
extern void func_L01_004C9F98(void *, s32, s32, f32, f32);

/* Copies up to 255 characters of a string into the object, then initialises its text box at (255,
 * 80) in mode 1 with the given limit (360 if count is -1). */
void func_L01_004CA1E8(u8 *object, s32 value, s32 count) {
    s32 limit = count == -1 ? 360 : count;
    u8 *state = object + 0x4ED0;
    func_0011BB58(object + 0x4F58, value, 255);
    func_L01_004C9F98(state, 1, limit, 255.0f, 80.0f);
}
/* localdecomp:end func_L01_004CA1E8 */
