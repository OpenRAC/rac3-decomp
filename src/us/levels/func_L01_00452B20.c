#include "common.h"

/* NTSC-U counterpart of func_L01_00455E18 (src/levels/shared/L01_00454728.c) */
/* localdecomp:start func_L01_00452B20 */
typedef struct { u8 thresholds[16]; f32 previous; } Breaks_00455E18;
typedef struct { f32 value; s16 maximum; } Health_00455E18;
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_00455E18;
typedef struct { u8 pad[0x158]; f32 yaw; } Camera_00455E18;
extern Camera_00455E18 D_L01_001E2900;
extern u8 D_L01_002FFEA8[];
extern f32 D_L01_001D7CB0_00452B20;
__asm__(".extern D_L01_001D7CB0_00452B20, 4");
s32 func_L01_00452B20(u8 *obj, Breaks_00455E18 *state, Health_00455E18 *health) {
    extern void func_L01_004367A0(u8 *, s32 *, s32 *);
    extern f32 func_L01_00440918(f32, f32);
    extern f32 func_00389380(f32, f32);
    extern f32 func_0037E250(f32, f32);
    extern f32 func_00388960(f32);
    extern f32 func_00388978(f32);
    extern u8 *func_L01_003F5830(u8 *, s32, s32, s32, void *, void *, Vec_00455E18 *, s32, f32, f32, s32, s32, s32);
    extern void func_0039FF28(s32, s32, s32);
    Vec_00455E18 velocity;
    s32 mask, unused;
    s32 result = 0;
    if (state->previous == 0.0f && health->value != 0.0f) {
        s32 i;
        f32 v;
        u8 threshold;
        func_L01_004367A0(obj, &mask, &unused);
        v = health->value;
        if (v < 0.0f) v = 0.0f;
        threshold = (s32)(v / health->maximum * 255.0f);
        for (i = 0; i < 15; i++) {
            s32 bit = 1 << i;
            if ((bit & mask) && state->thresholds[i] && state->thresholds[i] < threshold) {
                *(u16 *)(obj + 0x7C) |= bit;
            }
        }
    }
    if (health->value < state->previous) {
        s32 i, bit;
        f32 v;
        u8 threshold;
        v = health->value;
        if (v < 0.0f) v = 0.0f;
        threshold = (s32)(v / health->maximum * 255.0f);
        for (bit = 1, i = 0; i < 15; i++, bit <<= 1) {
            if ((*(u16 *)(obj + 0x7C) & bit) && threshold < state->thresholds[i]) {
                f32 angle, speed;
                u8 *piece;
                angle = func_00389380(func_L01_00440918(90.0f, 120.0f) * 0.0174532924f, D_L01_001E2900.yaw);
                speed = func_0037E250(2.0f, 4.0f) * 0.01666666753590107f;
                velocity.x = func_00388960(angle) * speed;
                velocity.y = func_00388978(angle) * speed;
                velocity.z = 0.0f;
                velocity.z = func_0037E250(5.0f, 8.0f) * 0.01666666753590107f;
                piece = func_L01_003F5830(obj, 1, *(s16 *)(obj + 0xAA), i, obj + 0x10, obj + 0xF0, &velocity, 255, D_L01_001D7CB0_00452B20, 15.0f, 180, 0, 128);
                if (piece) *(u8 **)(piece + 0x64) = D_L01_002FFEA8;
                *(u16 *)(obj + 0x7C) &= ~bit;
                if (!result) func_0039FF28(7, 0, 0);
                result = 1;
            }
        }
    }
    state->previous = health->value;
    return result;
}
/* localdecomp:end func_L01_00452B20 */
