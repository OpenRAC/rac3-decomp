#include "common.h"

/* NTSC-U counterpart of func_L01_00323120 (src/levels/shared/L01_0031C1D0.c): 12 -> 15 */
extern s32 func_00382468(s32);
extern u8 D_L01_001D66B0_00322C20[8];
extern void func_L01_00322C20(f32 *muzzle, u8 *zero, f32 charge);

/* localdecomp:start func_L01_00322C20 */
extern u8 D_L01_001D66B0_00322C20[8];
extern u8 *D_L01_00221288[];
extern s32 func_00382468(s32);
extern f32 func_L01_00440918(f32, f32);
extern u8 *func_L01_00466F98(f32 *pos, u8 *velocity, s32 life, s32 alpha, s32 rgb, s32 spin,
                             f32 size, f32 growth, f32 f14, f32 f15, f32 f16);

/* hydra_muzzle_glows: the Spitting Hydra's muzzle glows sized by its charge, each frame with
   even odds: a 0x2C of 6 x the charge in (0x20, 0x40, 0x90) at alpha 6 with particle type
   0x5C's texture 1, and one of 2.4 x the charge in (0x20, 0x40, 0x80) at 0x7F with its
   texture 0, jittered +-0.04, half added and half blended. */
void func_L01_00322C20(f32 *muzzle, u8 *zero, f32 charge)
{
    f32 size = charge * 210000.0f;
    f32 at[4];
    u8 *glow;

    /* spun +-1, growing 500 (/ 210000) a frame */
    if (func_00382468(2) != 0) {
        glow = func_L01_00466F98(muzzle, D_L01_001D66B0_00322C20, 15, 6, 0x904020,
                                 (s32)func_L01_00440918(1.0f, -1.0f), size * 6.0f, 500.0f,
                                 1.0f, 0.0f, 2.0f);
        if (glow != 0) {
            glow[2] = D_L01_00221288[0][1];
        }
    }
    /* the second jittered up to 0.04 either way */
    at[0] = muzzle[0] + func_L01_00440918(0.0f, 0.04f);
    at[1] = muzzle[1] + func_L01_00440918(0.0f, 0.04f);
    at[2] = muzzle[2] + func_L01_00440918(0.0f, 0.04f);
    if (func_00382468(2) != 0) {
        glow = func_L01_00466F98(at, D_L01_001D66B0_00322C20, 15, 0x7F, 0x804020,
                                 (s32)func_L01_00440918(1.0f, -1.0f), size * 2.4f, 500.0f,
                                 1.0f, 0.0f, 2.0f);
        if (glow != 0) {
            glow[3] = func_00382468(2) != 0 ? 0x48 : 0x44;
            glow[2] = D_L01_00221288[0][0];
        }
    }
}
/* localdecomp:end func_L01_00322C20 */
