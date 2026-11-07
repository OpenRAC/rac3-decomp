/* near miss: anim_frame_reached (open-rac-engine moby.rs SequencePlayer::reached). All but the
 * end matches (14 words): retail computes the second comparison of each branch into $v1 and
 * shares one tail, `bnez $v1; li $v0, 1` / `move $v0, $zero`, and returns 0 from the first
 * test with the move in the branch's delay slot; gcc folds `if (passed) return 1; return 0;`
 * into returning the slt and lays the first branch out the other way round. Tried: early
 * returns, nested ifs, &&, a result variable (s32, u8, long), goto. */
#include "common.h"

/* localdecomp:start func_L01_0044E1B8 */
typedef struct {
    u8 pad_0[0x42];
    u8 prev_sequence;              /* 0x42: differs from +0x43 while it blends */
    u8 sequence;                   /* 0x43 */
    u8 pad_44[0x48 - 0x44];
    f32 anim_speed;                /* 0x48: negative plays it backwards */
} Moby_44E1B8;

extern f32 func_L01_004395E0(Moby_44E1B8 *moby);

/* anim_frame_reached: whether the moby's animation passed frame on the last tick (never while
 * it blends), in 1/4096ths of a frame. */
s32 func_L01_0044E1B8(Moby_44E1B8 *moby, f32 frame) {
    f32 now;
    f32 last;
    s32 frame_q;
    s32 now_q;
    s32 last_q;
    s32 passed;

    if (moby->prev_sequence != moby->sequence) return 0;
    now = func_L01_004395E0(moby);
    last = now - moby->anim_speed * 1.2f * 0.5f;
    frame_q = (s32)(frame * 4096.0f + 0.5f);
    now_q = (s32)(now * 4096.0f + 0.5f);
    last_q = (s32)(last * 4096.0f + 0.5f);
    if (moby->anim_speed < 0.0f) {
        if (frame_q < now_q) return 0;
        passed = frame_q < last_q;
    } else {
        if (now_q < frame_q) return 0;
        passed = last_q < frame_q;
    }
    if (passed) return 1;
    return 0;
}
/* localdecomp:end func_L01_0044E1B8 */
