#include "common.h"

typedef struct {
    u8 pad0[0xA4];
    u16 flags;
} State_L07_003B9EB8;

/* localdecomp:start func_L07_003B9EB8 */
extern s32 func_L07_00440DB8(s32);
extern void func_L07_003A0BC0(s32, s32, s32, s32);

/* Plays one-shot sound id 0x41 or 0x42 for the moby depending on func_L07_00440DB8(2), setting flag
 * 0x10 or 0x20 so each plays only once. */
void func_L07_003B9EB8(void *object) {
    State_L07_003B9EB8 *state = *(State_L07_003B9EB8 **)((u8 *)object + 0x68);
    if (func_L07_00440DB8(2) != 0) {
        if (state->flags & 0x10) {
            return;
        }
        ((long (*)(s32, s32, s32, s32))func_L07_003A0BC0)(0x41, (s32)object, 0, 0x78);
        state->flags |= 0x10;
    } else {
        if (state->flags & 0x20) {
            return;
        }
        ((long (*)(s32, s32, s32, s32))func_L07_003A0BC0)(0x42, (s32)object, 0, 0x78);
        state->flags |= 0x20;
    }
}
/* localdecomp:end func_L07_003B9EB8 */
