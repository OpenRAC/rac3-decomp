#include "common.h"

/* NTSC-U counterpart of func_L01_004CB1F0 (src/levels/shared/L01_004C6618.c): 0.02 -> 0.0166667 */
typedef struct {
    u8 pad0[872];
    s16 x368;
    u8 pad36A[8790];
    u8 *x25C0;
} S_4C4A18;
extern S_4C4A18 D_001A4BE0;
extern S_4C4A18 D_001A4BE0;
extern f32 func_0038D0B0(f32);
extern S_4C4A18 D_001A4BE0;
extern S_4C4A18 D_001A4BE0;
extern S_4C4A18 D_001A4BE0;

/* localdecomp:start func_L01_004C7588 */
typedef struct {
    u8 pad0[0x15F0];
    f32 look_cam_weight;
    u8 pad15F4[0x16D4 - 0x15F4];
    f32 crosshair_pulse;
    s32 crosshair_fade;
} H_4CB1F0;
extern f32 func_0038DAB8(f32 angle, f32 step);
extern f32 func_0038D0B0(f32 angle);
extern u32 func_0038DBD8(u32 from, u32 to, f32 t);

/* crosshair_colour: fades in over 20 counts (5 alpha a count) and pulses between green and
   white, the phase moving deg_per_s; solid red while the free-look target's weight is above
   the threshold. */
u32 func_L01_004C7588(f32 threshold, f32 deg_per_s) {
    u32 alpha;
    u32 colour;
    (*(H_4CB1F0 *)&D_001A4BE0).crosshair_fade++;
    if ((*(H_4CB1F0 *)&D_001A4BE0).crosshair_fade > 20) {
        (*(H_4CB1F0 *)&D_001A4BE0).crosshair_fade = 20;
    }
    /* degrees a second to radians a frame */
    (*(H_4CB1F0 *)&D_001A4BE0).crosshair_pulse =
        func_0038DAB8((*(H_4CB1F0 *)&D_001A4BE0).crosshair_pulse, deg_per_s * 0.0174532924f * 0.0166666675f);
    alpha = ((*(H_4CB1F0 *)&D_001A4BE0).crosshair_fade * 5) << 24;
    /* green (0x0F, 0xFF, 0x00) to white, by 0.5 + 0.5 sin */
    colour = func_0038DBD8(alpha | 0xFF0F, alpha | 0xFFFFFF,
                           func_0038D0B0((*(H_4CB1F0 *)&D_001A4BE0).crosshair_pulse) * 0.5f + 0.5f);
    if (threshold < (*(H_4CB1F0 *)&D_001A4BE0).look_cam_weight) {
        colour = 0x600000FF; /* red */
    }
    return colour;
}
/* localdecomp:end func_L01_004C7588 */
