#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L39_0056DEC8 */
typedef struct {
    u8 motion[0xF0];  /* +0x80: movement; +0xA4: speed. */
    u8 hero[0x370];   /* 0xF0: the camera's copy of the hero. */
} Camera_56DEC8;
extern Camera_56DEC8 D_L39_0024DFE0[];
extern f32 func_00388730(f32 *, f32 *); /* the dot product */
extern void func_L01_003E6D50(s32, s32, f32, f32);

/* camera_approach_distance: the hero moving against the camera's facing (dot < -0.3):
   distance target up to 6.0 by speed (full at 0.07 u/frame), and a stiffer arm spring. */
void func_L39_0056DEC8(u8 *update, f32 *gain, f32 *damping) {
    u8 *follow = *(u8 **)(update + 0x70);
    u8 *approach = follow + 0x260;
    u8 *springs = follow + 0x180;
    s32 player = *(s32 *)(update + 0x94);
    u8 *motion = D_L39_0024DFE0[player].motion;
    u8 *hero = D_L39_0024DFE0[player].hero;
    f32 share;
    f32 far;
    f32 distance;

    if (*(s16 *)(approach + 6) == 0) {
        if ((*(s16 *)(approach + 4) != 0 && *(f32 *)(motion + 0xA4) == 0.0f &&
             func_00388730((f32 *)(*(u8 **)(hero + 0xF0) + 0xC0), (f32 *)update) <= -0.3f) ||
            (fabs_asm(*(f32 *)(motion + 0xA4)) > 0.0001f &&
             func_00388730((f32 *)(motion + 0x80), (f32 *)update) <= -0.3f)) {
            *(s16 *)(approach + 4) = 120;
            /* full at 0.07 u a frame */
            share = *(f32 *)(motion + 0xA4) * 14.2857f;
            if (share > 1.0f) {
                share = 1.0f;
            }
            far = *(f32 *)(approach + 0xC);
            distance = *(f32 *)(springs + 0x58) + (far - *(f32 *)(springs + 0x58)) * share;
            if (distance > *(f32 *)(approach + 8)) {
                *(f32 *)(approach + 8) = distance;
            }
            func_L01_003E6D50(*(s32 *)(update + 0x94), 0, *(f32 *)(approach + 8), 0.003f);
            *gain = share * 0.02f + 0.02f;
            *damping = share * 0.100000009f + 0.2f;
            return;
        }
    }
    if (*(s16 *)(approach + 4) != 0) {
        *(s16 *)(approach + 4) = 0;
        *(f32 *)(approach + 8) = *(f32 *)(springs + 0x58);
    }
    if (*(s32 *)(hero + 0x100) == 0x86) {
        *gain = 0.04f;
        *damping = 0.2f;
    } else {
        *gain = 0.02f;
        *damping = 0.2f;
    }
}
/* localdecomp:end func_L39_0056DEC8 */
