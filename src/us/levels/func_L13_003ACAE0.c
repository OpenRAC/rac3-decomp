#include "common.h"

extern void func_L13_004220E8(u8 *, s32, s32, s32);
extern void func_L13_00422428(u8 *, s32, s32);

/* localdecomp:start func_L13_003ACAE0 */
/* Picks an animation for the moby from its state block flags (0x3AE, 0x390): blends to animation 0,
 * 0x18 or 0x1A if not already playing, then sets the matching state (0x10, 0xA or 0xD). */
void func_L13_003ACAE0(u8 *object) {
    u8 *child = *(u8 **)(object + 0x68);
    if (child[0x3AE] != 0) {
        if (object[0x43] != 0) {
            func_L13_004220E8(object, 0, 0, 4);
        }
        func_L13_00422428(object, 0x10, -1);
    } else {
        s32 state = *(s32 *)(child + 0x390);
        if (state != -1) {
            if (object[0x43] != 0x18) {
                func_L13_004220E8(object, 0x18, 0, 4);
            }
            func_L13_00422428(object, 0xA, -1);
        } else {
            if (object[0x43] != 0x1A) {
                func_L13_004220E8(object, 0x1A, 0, 9);
            }
            func_L13_00422428(object, 0xD, -1);
        }
    }
}
/* localdecomp:end func_L13_003ACAE0 */
