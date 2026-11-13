#include "common.h"

/* NTSC-U counterpart of func_L01_0030D408 (src/levels/shared/L01_003068B8.c) */
extern u8 D_001A4C60[];
typedef int s128_00309B80 __attribute__((mode(TI)));
extern u8 *func_003BCFB0(s32, s32);
extern f32 func_00388770(void *);
extern void func_L01_004C7010(f32 speed, f32 range, f32 max_angle, void *out, void *from);
extern s32 func_L01_004C4A18(u8 *ball, s32 a1, f32 x, f32 y, f32 z);
extern u8 *D_L01_001E17A4;
typedef struct {
    f32 v[4];
    s32 w16;
    f32 f20;
    s32 w24;
    s32 w28;
    f32 f32_;
    s32 w36;
    f32 f40;
    f32 f44;
} S_0030CD20;
extern S_0030CD20 *D_L01_001E17A0;
extern void func_00388830(S_0030CD20 *, S_0030CD20 *, f32);

/* localdecomp:start func_L01_0030D168 */
typedef struct {
    f32 velocity[4];
    s32 life;       /* 0x10: frames */
    s32 slot;       /* 0x14: its place among the 5 */
    f32 radius;     /* 0x18 */
    s32 x1C;
    u8 pad20[0x10];
    s32 sound;      /* 0x30 */
    s32 x34;
    s32 x38;
    s32 level;      /* 0x3C */
    s32 gun_class;  /* 0x40 */
    s32 shadow;     /* 0x44 */
} CoilBall_0030D408;
typedef struct {
    u8 pad0[0x8C];
    s32 used;       /* 0x8C */
    u8 pad90[0x10];
} CoilArc_0030D408;
__asm__(".extern D_L01_001DC690, 4");
__asm__(".extern D_L01_001DC694, 4");
extern s32 D_L01_001DC690;
extern s32 D_L01_001DC694;
extern s32 D_L01_00271B70[];
extern s32 func_L01_0030D3D0(void);
extern u8 *func_L01_00454120(u8 *);
/* coil_ball_spawn: the Plasma Coil's ball (class 0xA9B) from pos at velocity x 1.2 (PAL's
   frame), in the first free of 5 slots; none while 4 are out. In the aiming camera modes it
   bends toward the aim point. The first one also clears the sparks' and arcs' slots; each
   ball gets 20 sparks. One pointer holds the gun's vars, read before the once-only test, and
   then the buffer they point to: it conflicts with $a0 that way and gets $v0. */
u8 *func_L01_0030D168(u8 *gun, s32 level, s128_00309B80 *pos, f32 *velocity)
{
    u8 *ball;
    CoilBall_0030D408 *vars;
    f32 at[4];
    s128_00309B80 *place;
    s32 i;
    u8 *buf;
    if (func_L01_0030D3D0() != 0) {
        return 0;
    }
    for (i = 0; i < 5; i++) {
        if (D_L01_00271B70[i * 4] == 0) {
            break;
        }
    }
    ball = func_003BCFB0(0xA9B, 0x80);
    if (ball != 0) {
        ball[0x20] = 0;
        *(u16 *)(ball + 0x32) = 0xFF;
        ball[0x30] = 0xFF;
        vars = *(CoilBall_0030D408 **)(ball + 0x68);
        place = (s128_00309B80 *)(ball + 0x10);
        *place = *pos;
        *(s128_00309B80 *)at = *place;
        /* its shadow made at the hero, then put where it starts */
        *place = *(s128_00309B80 *)D_001A4C60;
        vars->shadow = func_L01_004C4A18(ball, 0, 1.0f, 1.0f, 1.0f);
        *place = *(s128_00309B80 *)at;
        func_00388830((S_0030CD20 *)vars, (S_0030CD20 *)velocity, 1.0f);
        /* the hero's camera mode: not the follow camera */
        if (*(s32 *)(D_001A4C60 + 0x1630) != 0) {
            /* within 35 u, turned at most 80 degrees */
            ((void (*)(void *, void *, f32, f32, f32))func_L01_004C7010)(vars, place, func_00388770(vars), 35.0f, 1.3962634f);
        }
        vars->life = 160;
        vars->sound = 20;
        vars->slot = i;
        D_L01_00271B70[i * 4] = (s32)ball;
        D_L01_001DC690++;
        vars->radius = 2.5f;
        vars->level = level;
        vars->x1C = 0;
        vars->x34 = 0;
        vars->x38 = 0;
        vars->gun_class = *(s16 *)(gun + 0xAA);
        buf = *(u8 **)(gun + 0x68);
        if (D_L01_001DC694 == 0) {
            buf = *(u8 **)(buf + 8);
            D_L01_001E17A0 = (S_0030CD20 *)buf;
            D_L01_001E17A4 = func_L01_00454120(buf + 0xC00);
            func_L01_00454120(D_L01_001E17A4 + 0x780);
            D_L01_001DC694 = 1;
            for (i = 63; i >= 0; i--) {
                D_L01_001E17A0[i].w16 = 0;
            }
            for (i = 0; i < 12; i++) {
                ((CoilArc_0030D408 *)D_L01_001E17A4)[i].used = 0;
            }
        }
        for (i = 0; i < 20; i++) {
            func_L01_0030CD20((s32)ball);
        }
    }
    return ball;
}
/* localdecomp:end func_L01_0030D168 */
