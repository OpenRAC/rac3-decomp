/* PAL near miss: 77 words differ with the file's flags.
 * Remaining differences (all in one group each):
 *  1. the delay slot of the first `beqz` holds retail's `nop`; this C schedules
 *     the `lui` of D_001D5470 there (the function is one word shorter).
 *  2. float registers: retail keeps the lean value in $f1 and the clamp bounds
 *     (1.30899692f, 0.1f) in $f2; this C gets the pair the other way round
 *     (lean $f2, bounds $f1). Because of that the last clamp is a `bc1tl` with
 *     the lean store moved up instead of retail's `bc1f` with the store in its
 *     delay slot. Separate variables for the two phases give retail's branch
 *     shape but a wider float-register mismatch (81).
 */
#include "common.h"
/* localdecomp:start func_L01_004F3F40 */
typedef struct {
    u8 pad0[0x1A8]; f32 turn;
    u8 pad1AC[0x12F4 - 0x1AC]; u8 *clank;
    u8 pad12F8[0x25C4 - 0x12F8]; s32 state;
} H_004F3F40;
typedef struct {
    u8 pad0[0xCC8]; f32 lean;
    u8 padCCC[0xCF8 - 0xCCC]; f32 speed;
    u8 padCFC[8]; f32 gain; f32 damping; f32 reset;
} S_004F3F40;
extern u8 D_001D5470 __attribute__((section(".data")));
extern f32 D_001DBD3C_sda;
__asm__(".extern D_001DBD3C_sda, 4");

void func_L01_004F3F40(void) {
    H_004F3F40 *h = (H_004F3F40 *)&D_001A4BE0;
    f32 scale;
    f32 turn;
    f32 gain;

    if (h->clank == 0) return;
    if (D_001D5470) {
        ((S_004F3F40 *)&D_L01_002F4540)->reset = D_001DBD3C_sda;
    }
    scale = 1024.0f / *(f32 *)(h->clank + 0x2C);
    if (h->state == 2) {
        turn = h->turn;
        ((S_004F3F40 *)&D_L01_002F4540)->gain = 0.02f;
        ((S_004F3F40 *)&D_L01_002F4540)->damping = 0.35f;
        if (turn > 1.4f) turn = 1.4f;
        else if (turn < -1.4f) turn = -1.4f;
        gain = -turn;
        gain *= 1.2f;
        if (gain > 1.30899692f) gain = 1.30899692f;
        else if (gain < -1.30899692f) gain = -1.30899692f;
        ((S_004F3F40 *)&D_L01_002F4540)->lean = gain;
        gain = __builtin_fabsf(turn) * 0.1f + 0.1f;
        if (gain > 0.07f) gain = 0.07f;
        ((S_004F3F40 *)&D_L01_002F4540)->speed = gain * scale;
    }
}
/* localdecomp:end func_L01_004F3F40 */
