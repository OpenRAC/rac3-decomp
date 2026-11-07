/* near miss (open-rac-engine names it camera_look_blocked): 12 words differ. Retail keeps the redundant
 * tests of the second clause ((class == 0 || class == 0x20) after `class != 0x20` fell through: beql/bne
 * before the frame check); our gcc folds them away, so the code is 4 instructions shorter. Same with
 * s32 class, re-reading the class, if/else-if, `!(first clause)`, gotos and boolean returns. */
#include "common.h"

/* Entry_3E6C58 is in src/levels/shared/L01_003E3930.c's prelude. */
__asm__(".extern D_L01_001DF700, 8");
extern s32 D_L01_001DF700[2];
extern Entry_3E6C58 D_L01_001E2A40[];

/* camera_look_blocked: 0 when the hero may enter the look: the current camera is the follow
   camera (class 0) or class 0x20 and has been on for more than 4 frames. */
s32 func_L01_003EB2D8(s32 player) {
    u8 *camera;
    s16 class;
    s32 blocked = 0;

    if (D_L01_001DF700[player] == 0) {
        camera = (u8 *)&D_L01_001E2A40 + player * 1120;
        class = *(s16 *)(*(u8 **)(camera + 0x50) + 0x86);
        if ((class != 0 && class != 0x20) || ((class == 0 || class == 0x20) && *(s32 *)(camera + 0x454) < 5)) {
            blocked = 1;
        }
    } else {
        blocked = 1;
    }
    return blocked;
}
