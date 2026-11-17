#include "common.h"

/* NTSC-U counterpart of func_L01_00309B80 (src/levels/shared/L01_003068B8.c): 100 -> 120 */
extern f32 func_00382538(void);

/* localdecomp:start func_L01_003098F8 */
typedef int s128_00309B80 __attribute__((mode(TI)));
typedef struct {
    s128_00309B80 velocity; /* u a frame */
    u8 pad10[0x10];
    s128_00309B80 start_velocity;
    u8 pad30[4];
    s32 fly_ticks;          /* 0x34 */
    u8 pad38[8];
    s32 level;              /* 0x40 */
    s32 gun_class;          /* 0x44 */
    u8 pad48[4];
    f32 x4C;
    s32 x50;
    s32 x54;
    s32 x58;
    s32 light;              /* 0x5C */
} StormVars_00309B80;

__asm__(".extern D_L01_001DC670, 4");
extern s32 D_L01_001DC670;
extern u8 D_001A4BE0[];
extern u8 *func_003C24B0(s32, s32);
extern f32 func_0038CEA8(void *);
extern void func_L01_004C7010(f32 speed, f32 range, f32 max_angle, void *out, void *from);
extern s32 func_L01_004C4A18(u8 *ball, s32 a1, f32 x, f32 y, f32 z);
extern s32 func_L01_00421F08(void *pos, f32 radius, f32 x, f32 r, f32 g, f32 b);
extern f32 func_00382538(void);
extern void func_0038D308(void *matrix, void *rotation);

/* storm_ball_spawn: throws the Plasma Storm's ball (class 0x9A9) from pos at velocity (1/3
   u a frame along the aim), for 120 frames (120 at 60 Hz); in the aiming camera modes the
   velocity is bent toward the aim point. A light and a random spin go with it. */
u8 *func_L01_003098F8(u8 *gun, s32 level, s128_00309B80 *pos, s128_00309B80 *velocity)
{
    u8 *ball = func_003C24B0(0x9A9, 0x80);
    StormVars_00309B80 *vars;
    f32 one;
    f32 zero;

    if (ball != 0) {
        ball[0x30] = 0xFF;
        *(u16 *)(ball + 0x32) = 0x1FF;
        *(u16 *)(ball + 0x34) |= 0x100;
        vars = *(StormVars_00309B80 **)(ball + 0x68);
        vars->gun_class = *(s16 *)(gun + 0xAA);
        vars->level = level;
        vars->fly_ticks = 120;
        vars->x4C = 0.01f;
        *(s128_00309B80 *)(ball + 0x10) = *pos;
        /* the hero's camera mode (hero + 0x16B0): not the follow camera */
        if (*(s32 *)(D_001A4BE0 + 0x16B0) != 0) {
            /* within 35 u, turned at most 80 degrees */
            func_L01_004C7010(func_0038CEA8(velocity), 35.0f, 1.3962634f, velocity, ball + 0x10);
        }
        vars->velocity = *velocity;
        one = 1.0f;
        zero = 0.0f;
        vars->start_velocity = *velocity;
        vars->x50 = func_L01_004C4A18(ball, 0, one, one, one);
        vars->x54 = 0;
        vars->x58 = 0;
        ball[0x20] = 0;
        D_L01_001DC670++;
        /* a light in (0.25, 0.14, 1.0) */
        vars->light = func_L01_00421F08(ball + 0x10, zero, zero, 0.25f, 0.14f, one);
        *(f32 *)(ball + 0xF0) = func_00382538();
        *(f32 *)(ball + 0xF4) = func_00382538();
        *(f32 *)(ball + 0xF8) = func_00382538();
        *(f32 *)(ball + 0xFC) = zero;
        func_0038D308(ball + 0xC0, ball + 0xF0);
    }
    return ball;
}
/* localdecomp:end func_L01_003098F8 */
