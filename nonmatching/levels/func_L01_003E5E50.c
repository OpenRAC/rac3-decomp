/* near miss (open-rac-engine names it camera_end_of_frame): 28 words differ, all after the
 * camera_look_springs_h call: retail loads D_L01_001DF664 before the player and both look-spring
 * defaults before the stores, and puts 0.1, 1.0, 8.0, 6.0 in $f2, $f1, $f0, $f3 (ours $f3, $f2, $f1,
 * $f0), so the scheduling differs. Everything before matches (springs as if/else calls, cross-jumped). */
#include "common.h"

/* Ps2EeAs only uses $gp for these if it knows they are small before the use. */
__asm__(".extern D_L01_001DF664, 4");
__asm__(".extern D_L01_001DF668, 4");
__asm__(".extern D_L01_001DF66C, 4");
__asm__(".extern D_L01_001DF670, 4");
extern f32 D_L01_001DF664;
extern f32 D_L01_001DF668;
extern f32 D_L01_001DF66C;
extern s32 D_L01_001DF670;
extern f32 D_L01_001D5FF0[2];
extern u8 D_L01_001E50D0[];
extern s32 D_L01_001DF820[];
extern f32 func_00382BC8(f32 *, f32, f32, f32, f32, f32);
extern void func_003C41A0(f32 *, f32 *, f32, f32, f32, f32);
extern void func_L01_003E8DB8(s32, f32, f32);

/* camera_end_of_frame: springs the distance (gain 0.003, damping 0.2), height and look
   height to their targets and resets the per-frame overrides. */
void func_L01_003E5E50(u8 *update) {
    u8 *stick = *(u8 **)(update + 0x70) + 0x1E0;
    u8 *follow;
    u8 *springs;
    u8 *look;
    u8 *slot;
    u8 *rest;
    u8 *rest_look;
    u8 *rest_springs;
    u8 *view;
    u8 *steer;
    u8 *approach;

    /* the virtual stick */
    *(f32 *)(stick + 0x14) = D_L01_001D5FF0[*(s32 *)(update + 0x94)];
    *(f32 *)(stick + 0x1C) = 0.0f;
    *(f32 *)(stick + 0x20) = 0.0f;
    *(s32 *)(stick + 0x10) = 0;
    *(f32 *)(stick + 0x24) = 0.0f;

    follow = *(u8 **)(update + 0x70);
    springs = follow + 0x180;
    look = follow + 0x60;
    /* the follow camera at rest gives the targets nothing set this frame */
    slot = D_L01_001E50D0 + *(s32 *)(update + 0x94) * 0xB0;
    rest = *(u8 **)(slot + 0x70);
    rest_springs = rest + 0x180;
    rest_look = rest + 0x60;
    /* the distance: towards this frame's target if one was set, else the resting one */
    if (*(s16 *)(springs + 0x3C) != 0) {
        *(f32 *)(springs + 0x2C) = func_00382BC8((f32 *)(follow + 0x1C4), *(f32 *)(springs + 0x2C),
            *(f32 *)(springs + 0x40), *(f32 *)(springs + 0x48), 0.2f, *(f32 *)(stick + 0x1C));
    } else {
        *(f32 *)(springs + 0x2C) = func_00382BC8((f32 *)(follow + 0x1C4), *(f32 *)(springs + 0x2C),
            *(f32 *)(rest_springs + 0x2C), *(f32 *)(springs + 0x48), 0.2f, *(f32 *)(stick + 0x1C));
    }
    /* the height */
    if (*(s16 *)(springs + 0x3E) != 0) {
        *(f32 *)(springs + 0x30) = func_00382BC8((f32 *)(springs + 0x50), *(f32 *)(springs + 0x30),
            *(f32 *)(springs + 0x4C), *(f32 *)(springs + 0x54), 0.2f, 0.0f);
    } else {
        *(f32 *)(springs + 0x30) = func_00382BC8((f32 *)(springs + 0x50), *(f32 *)(springs + 0x30),
            *(f32 *)(rest_springs + 0x30), *(f32 *)(springs + 0x54), 0.2f, 0.0f);
    }
    /* the look height */
    if (*(s16 *)(look + 0xFA) != 0) {
        *(f32 *)(look + 0xD0) = func_00382BC8((f32 *)(look + 0xDC), *(f32 *)(look + 0xD0),
            *(f32 *)(look + 0xD4), *(f32 *)(look + 0xD8), 0.2f, 0.0f);
    } else {
        *(f32 *)(look + 0xD0) = func_00382BC8((f32 *)(look + 0xDC), *(f32 *)(look + 0xD0),
            *(f32 *)(rest_look + 0xD0), *(f32 *)(look + 0xD8), 0.2f, 0.0f);
    }
    *(s16 *)(springs + 0x3C) = 0;
    *(s16 *)(springs + 0x3E) = 0;
    *(f32 *)(springs + 0x40) = 0.0f;
    *(f32 *)(springs + 0x4C) = 0.0f;
    *(f32 *)(springs + 0x58) = *(f32 *)(rest_springs + 0x2C);
    *(s16 *)(look + 0xFA) = 0;
    *(f32 *)(look + 0xD4) = 0.0f;

    *(s16 *)(*(u8 **)(update + 0x70) + 0x10) = 1;
    view = *(u8 **)(update + 0x70) + 0x20;
    /* the look-up's spring */
    *(f32 *)(view + 0x1C) = 0.005f;
    *(f32 *)(view + 0x20) = 0.2f;
    *(s16 *)(view + 2) = 0;
    if (*(f32 *)(view + 0x2C) != 0.0f) {
        func_003C41A0((f32 *)(view + 0x28), (f32 *)(view + 0x30), *(f32 *)(view + 0x2C),
                      *(f32 *)(view + 0x34), *(f32 *)(view + 0x38), 1.0f);
    } else if (*(f32 *)(view + 0x28) != 0.0f) {
        func_003C41A0((f32 *)(view + 0x28), (f32 *)(view + 0x30), 0.0f,
                      *(f32 *)(view + 0x34), *(f32 *)(view + 0x38), 1.0f);
    }
    *(f32 *)(view + 0x2C) = 0.0f;

    /* the look point's springs back to their defaults */
    func_L01_003E8DB8(*(s32 *)(update + 0x94), D_L01_001DF664, D_L01_001DF66C);
    *(f32 *)(look + 0x104) = D_L01_001DF668;
    *(f32 *)(look + 0x108) = D_L01_001DF66C;
    look[0xF9] = 0;
    *(s16 *)(look + 0x10C) = (D_L01_001DF670 * 5 + 2) / 6;

    steer = *(u8 **)(update + 0x70) + 0x210;
    *(f32 *)(steer + 0x44) = 0.1f;
    *(f32 *)(steer + 0x3C) = 1.0f;
    *(f32 *)(steer + 0x40) = 8.0f;
    *(s32 *)(steer + 0x48) = D_L01_001DF820[*(s32 *)(update + 0x94)];
    *(s16 *)(steer + 0x4E) = 0;
    /* the approach's far distance, and its per-frame switch */
    approach = *(u8 **)(update + 0x70) + 0x260;
    *(f32 *)(approach + 0xC) = 6.0f;
    *(s16 *)(approach + 6) = 0;
}
