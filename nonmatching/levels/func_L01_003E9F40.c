/* near miss (open-rac-engine names it camera_approach_distance): the body matches up to the off path.
 * There retail holds the gain (0.02/0.04) in $f0 and 0.2 in $f1; ours gets them the other way round, so
 * the approach path's two stores become identical to the off path's and gcc cross-jumps them, and
 * $s4..$s6 are permuted (gain, damping, follow+0x180). About 45 words. Constants: 1/0.07 is 14.2857f,
 * 0.1 is 0.100000009f (0x3DCCCCCE). */
#include "common.h"

typedef struct {
    u8 pad0[0x60];
    u8 motion[0xF0];  /* 0x060: +0x80 the hero's move, +0xA4 his speed */
    u8 hero[0x310];   /* 0x150: the camera's copy of the hero */
} Camera_003E9F40;
extern Entry_3E6C58 D_L01_001E2A40[];
extern f32 func_0040E428(void *, void *);
extern void func_L01_003E8BD0(s32, s32, f32, f32);

/* camera_approach_distance: the hero moving against the camera's facing (dot < -0.3):
   distance target up to 6.0 by speed (full at 0.07 u/frame), and a stiffer arm spring. */
void func_L01_003E9F40(u8 *update, f32 *gain, f32 *damping) {
    u8 *follow = *(u8 **)(update + 0x70);
    u8 *approach = follow + 0x260;
    u8 *springs = follow + 0x180;
    s32 player = *(s32 *)(update + 0x94);
    u8 *motion = ((Camera_003E9F40 *)D_L01_001E2A40)[player].motion;
    u8 *hero = ((Camera_003E9F40 *)D_L01_001E2A40)[player].hero;
    f32 share;
    f32 far;
    f32 distance;
    f32 spring_gain;

    if (*(s16 *)(approach + 6) == 0) {
        if ((*(s16 *)(approach + 4) != 0 && *(f32 *)(motion + 0xA4) == 0.0f &&
             func_0040E428(*(u8 **)(hero + 0xF0) + 0xC0, update) <= -0.3f) ||
            (__builtin_fabsf(*(f32 *)(motion + 0xA4)) > 0.0001f &&
             func_0040E428(motion + 0x80, update) <= -0.3f)) {
            *(s16 *)(approach + 4) = 100;
            /* full at 0.07 u a frame */
            share = *(f32 *)(motion + 0xA4) * 14.2857f;
            if (share > 1.0f) {
                share = 1.0f;
            }
            far = 4.0f;
            if (hero[0x12B] != 1) {
                far = *(f32 *)(approach + 0xC);
            }
            distance = *(f32 *)(springs + 0x58) + (far - *(f32 *)(springs + 0x58)) * share;
            if (distance > *(f32 *)(approach + 8)) {
                *(f32 *)(approach + 8) = distance;
            }
            func_L01_003E8BD0(*(s32 *)(update + 0x94), 0, *(f32 *)(approach + 8), 0.003f);
            *gain = share * 0.02f + 0.02f;
            *damping = share * 0.100000009f + 0.2f;
            return;
        }
    }
    if (*(s16 *)(approach + 4) != 0) {
        *(s16 *)(approach + 4) = 0;
        *(f32 *)(approach + 8) = *(f32 *)(springs + 0x58);
    }
    spring_gain = 0.02f;
    if (*(s32 *)(hero + 0x100) == 0x89) {
        spring_gain = 0.04f;
    }
    *gain = spring_gain;
    *damping = 0.2f;
}
