#include "common.h"

/* NTSC-U counterpart of func_L01_0044E1B8 (src/levels/shared/L01_0044E130.c) */
/* localdecomp:start func_L01_0044AF40 */
typedef struct {
    u8 pad_0[0x42];
    u8 prev_sequence;              /* 0x42: differs from +0x43 while it blends */
    u8 sequence;                   /* 0x43 */
    u8 pad_44[0x48 - 0x44];
    f32 anim_speed;                /* 0x48: negative plays it backwards */
} Moby_44E1B8;

extern f32 func_L01_00436500(Moby_44E1B8 *moby);

/* anim_frame_reached: whether the moby's animation passed frame on the last tick (never while
 * it blends), in 1/4096ths of a frame. */
s32 func_L01_0044AF40(Moby_44E1B8 *moby, f32 frame) {
    f32 now;
    f32 last;
    s32 frame_q;
    s32 now_q;
    s32 last_q;

    if (moby->prev_sequence != moby->sequence) return 0;
    now = func_L01_00436500(moby);
    last = now - moby->anim_speed * 0.5f;
    frame_q = (s32)(frame * 4096.0f + 0.5f);
    now_q = (s32)(now * 4096.0f + 0.5f);
    last_q = (s32)(last * 4096.0f + 0.5f);
    if (moby->anim_speed < 0.0f) {
        if (frame_q >= now_q && frame_q < last_q) return 1;
        return 0;
    } else {
        if (now_q >= frame_q && last_q < frame_q) return 1;
        return 0;
    }
}
/* localdecomp:end func_L01_0044AF40 */
