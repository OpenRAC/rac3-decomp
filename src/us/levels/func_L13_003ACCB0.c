#include "common.h"

/* localdecomp:start func_L13_003ACCB0 */
extern void func_L13_00422428(u8 *, s32, s32);
extern void func_L13_004220E8(u8 *, s32, s32, s32);
extern f32 func_L13_003ED340(u8 *, u8 *);
extern f32 D_L13_001DE6E4;

/* Switches a moby's animation by distance to its target: within the squared trigger radius it plays
 * sequence 13 and sound 33, otherwise sequence 9 and sound 28. */
void func_L13_003ACCB0(u8 *object) {
    f32 distance = func_L13_003ED340(object + 0x10, *(u8 **)(object + 0x68) + 0x130);
    if (distance < D_L13_001DE6E4 * D_L13_001DE6E4) {
        if (object[0x43] != 13) {
            func_L13_004220E8(object, 13, 0, 4);
        }
        func_L13_00422428(object, 33, -1);
    } else {
        if (object[0x43] != 9) {
            func_L13_004220E8(object, 9, 3, 16);
        }
        func_L13_00422428(object, 28, -1);
    }
}
/* localdecomp:end func_L13_003ACCB0 */
