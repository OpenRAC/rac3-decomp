#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_00460270);

INCLUDE_ASM("asm/levels", func_L01_004602C0);

INCLUDE_ASM("asm/levels", func_L01_004606A8);

LINKER_REMNANT("asm/levels", func_L01_004606C8);

/* localdecomp:start func_L01_004606E8 */
/* A pad's 30-frame histories (the per-frame pad update fills them). */
typedef struct {
    u8 pad_0[0x18E];
    s16 ring_pos;                  /* 0x18E: this frame's slot in the rings */
    s32 ring_filled;               /* 0x190: frames recorded so far */
    u8 pad_194[0x1E0 - 0x194];
    u32 press_ring[30];            /* 0x1E0: button presses per frame */
} Pad_4606E8;

extern u8 D_L01_001CD0C0[];

/* pad_pressed_within: whether any button of mask was pressed in the last frames frames (pad 0
 * is the first pad); frames_ago, when given, gets how many frames ago (0 is this frame). */
u32 func_L01_004606E8(u32 mask, s32 frames, s32 *frames_ago, Pad_4606E8 *pad) {
    s32 back;

    if (pad == 0) pad = (Pad_4606E8 *)D_L01_001CD0C0;
    if (pad->ring_filled < frames) frames = pad->ring_filled;
    frames++;
    for (back = 1; back < frames; back++) {
        s32 slot = (pad->ring_pos - back + 30) % 30;
        if (pad->press_ring[slot] & mask) {
            if (frames_ago != 0) *frames_ago = back - 1;
            return pad->press_ring[slot] & mask;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_004606E8 */

INCLUDE_ASM("asm/levels", func_L01_00460778);

LINKER_REMNANT("asm/levels", func_L01_00460810);

/* localdecomp:start func_L01_00460818 */
typedef struct {
    u8 pad_0[0x18E];
    s16 ring_pos;                  /* 0x18E: this frame's slot in the rings */
    s32 ring_filled;               /* 0x190: frames recorded so far */
    u8 pad_194[0x258 - 0x194];
    f32 angle_ring[30];            /* 0x258: left stick angle per frame */
} Pad_460818;

extern u8 D_L01_001CD0C0[];

/* pad_stick_angle_back: the left stick's angle frames back in the pad's ring (1 is this
 * frame; pad 0 is the first pad). */
f32 func_L01_00460818(s32 back, Pad_460818 *pad) {
    Pad_460818 *p;

    if (pad != 0) p = pad;
    else p = (Pad_460818 *)D_L01_001CD0C0;
    if (p->ring_filled < back) back = p->ring_filled;
    return p->angle_ring[(p->ring_pos - back + 30) % 30];
}
/* localdecomp:end func_L01_00460818 */
