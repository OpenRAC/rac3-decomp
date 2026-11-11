/* near miss (open-rac-engine names it camera_look_springs_v): matches in check.py and in every level but
 * the ones that differ: level 11 adds 0x20 to the follow pointer, the other 48 add 0x60: the catalogue counts them as one function (it masks addiu immediates), so one C cannot match all 49. */
#include "common.h"

typedef struct { u8 pad[0x460]; } Entry_3E6C58;

extern Entry_3E6C58 D_L01_001E2A40[];

/* camera_look_springs_v: this frame's vertical look-point spring (gain, damping); 0 keeps a value. */
void func_L01_003E8E10(s32 player, f32 gain, f32 damping) {
    u8 *camera = ((u8 *)&D_L01_001E2A40) + player * 1120;
    u8 *update = *(u8 **)(camera + 0x50);
    u8 *follow;
    /* follow camera (class 0) only */
    if (*(s16 *)(update + 0x86) != 0) {
        return;
    }
    follow = *(u8 **)(update + 0x70) + 0x60;
    if (gain != 0.0f) {
        *(f32 *)(follow + 0x104) = gain;
    }
    if (damping != 0.0f) {
        *(f32 *)(follow + 0x108) = damping;
    }
}
