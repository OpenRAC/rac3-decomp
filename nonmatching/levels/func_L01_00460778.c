/* near miss: pad_pressed_together (open-rac-engine). Every word matches except the absolute
 * value: retail has `blezl $v0; neg $v0, $v0` (neg is the trapping `sub $v0, $zero, $v0`),
 * gcc's abs gives `bltzl $v0; negu $v0, $v0`. No C form gives `sub`; 19 Veldin functions have
 * the same blezl/neg pair, so it looks like an asm ABS macro or another compiler's abssi2. */
#include "common.h"

/* localdecomp:start func_L01_00460778 */
typedef struct {
    u8 pad_0[0x18E];
    s16 ring_pos;
    s32 ring_filled;
    u8 pad_194[0x1E0 - 0x194];
    u32 press_ring[30];
} Pad_4606E8;
extern u32 func_L01_004606E8(u32 mask, s32 frames, s32 *frames_ago, Pad_4606E8 *pad);

/* pad_pressed_together: whether both masks were pressed in the last frames frames, their
 * latest presses fewer than gap frames apart (the crouch flip: X and a stick press). */
s32 func_L01_00460778(u32 mask_a, u32 mask_b, s32 frames, s32 gap, Pad_4606E8 *pad) {
    s32 ago[2];
    s32 together = 0;

    if (func_L01_004606E8(mask_a, frames, &ago[0], pad) && func_L01_004606E8(mask_b, frames, &ago[1], pad)) {
        s32 apart = ago[0] - ago[1];
        apart = __builtin_abs(apart);
        together = apart < gap;
    }
    return together;
}
/* localdecomp:end func_L01_00460778 */
