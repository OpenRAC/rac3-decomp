/* PAL near miss (Codex wave 8): near miss: 27 words differ with the file's flags.
 * Worker's note: 27 word diff; w434/func_L01_004E5130.06.log. CSE merges two retail cvt.w.s into integer round trip; register/schedule residual unchanged in three wordings; stopped.
 */
#include "common.h"
/* localdecomp:start func_L01_004E5130 */
typedef struct { u8 pad[0xC08]; s32 flags; u8 padC0C[12]; f32 frame; f32 weight; } Anim_004E5130;
extern G_4DD4B0 D_001A4BE0;
f32 func_L01_004E5130(f32 *table, s32 count) {
    u8 *h = (u8 *)&D_001A4BE0;
    f32 frame = ((Anim_004E5130 *)h)->frame;
    f32 fraction = frame - (s32)((Anim_004E5130 *)h)->frame;
    s32 index = (s32)*(f32 *)(h + 0xC18);
    s32 last = count - 1;
    s32 previous = (index + last) % count;
    if (*(s32 *)(h + 0xC08) & 2) previous = last;
    return fraction * table[index] + (*(f32 *)(h + 0xC1C) - fraction) * table[previous];
}
/* localdecomp:end func_L01_004E5130 */
