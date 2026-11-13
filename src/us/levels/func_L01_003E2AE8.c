#include "common.h"

/* NTSC-U counterpart of func_L01_003E48D8 (src/levels/shared/L01_003E3930.c) */
typedef struct {
    u8 pad[80];
    u8 *p50;
    u8 pad2[1036];
} Entry_3E6C58;

/* localdecomp:start func_L01_003E2AE8 */
typedef int q128_3E48D8 __attribute__((mode(TI)));

/* CameraFollow from +0x60 */
typedef struct {
    u8 pad0[0x10];
    q128_3E48D8 height;         /* +0x70: the follow point's height, set by the mode */
    q128_3E48D8 height_start;   /* +0x80: the height when a timed rise starts */
    q128_3E48D8 rise_target;    /* +0x90 */
    u8 pad40[0xE4 - 0x40];
    u8 mode;                    /* +0x144: the vertical mode, 0-11 */
    u8 old_mode;                /* +0x145: and the one it blends from */
    s16 blend_frames;           /* +0x146: the blend only changes the spring of a third point */
    f32 blend_rate;
    f32 rise_rate;              /* +0x14C: a timed rise's step, 1 / its frames */
    f32 rise_height;
    s16 rise_frames;            /* +0x154: also the frames mode 10 waits */
    u8 padF6;
    u8 rise_tick;               /* +0x157 */
} Vertical_3E48D8;

typedef struct {
    u8 pad0[0x20];
    s16 view_ease_frames;       /* the view direction eases back over these frames */
    u8 pad22[0x44 - 0x22];
    f32 view_ease_rate;
    u8 pad48[0x60 - 0x48];
    Vertical_3E48D8 v;
} Follow_3E48D8;

typedef struct {
    q128_3E48D8 position;
    u8 pad10[0x40 - 0x10];
    q128_3E48D8 view_from;
    u8 pad50[0x70 - 0x50];
    Follow_3E48D8 *follow;
    u8 pad74[0x94 - 0x74];
    s32 player;
} Cam_3E48D8;

typedef struct {
    u8 pad0[0x104];
    f32 right_y;
} Pad_3E48D8;

typedef struct {
    u8 pad0[0x100];
    s32 state;                  /* the hero's state and state type (2 fall, 4 jump, 30 jet) */
    s32 type;
    u8 pad108[0x120 - 0x108];
    s16 air_frames;
    u8 pad122[0x126 - 0x122];
    s16 strafing;
    u8 pad128[0x12A - 0x128];
    u8 past_apex;
    u8 pad12B[0x134 - 0x12B];
    Pad_3E48D8 *pad;
} Hero_3E48D8;

__asm__(".extern D_L01_001DF6BC, 4");
extern s32 D_L01_001DF6BC;
extern Entry_3E6C58 D_L01_001E2AC0[];
extern void func_L01_003E2A38(Entry_3E6C58 *entry, q128_3E48D8 *target, f32 height, s32 from_ground);
extern s32 func_003883C8(u8 *);

/* camera_vertical_modes: the follow point's vertical mode (follow +0x144) by the hero's
   state: 1 falls, 2 jump hold, 3 heli (15), 5 rocket and double jump (13, 14), 6/7 flip (11),
   8 crouch flip (12), 9/10 jump attack (20); 3, 5, 6 and 7 are timed rises. */
void func_L01_003E2AE8(Cam_3E48D8 *cam) {
    Follow_3E48D8 *follow = cam->follow;
    Vertical_3E48D8 *v = &follow->v;
    Entry_3E6C58 *entry = &D_L01_001E2AC0[cam->player];
    Hero_3E48D8 *hero = (Hero_3E48D8 *)((u8 *)entry + 0x150);

    if (D_L01_001DF6BC != 0) { /* skip one frame */
        D_L01_001DF6BC = 0;
        return;
    }
    if (v->mode == 0) {
        if (hero->type == 2 || hero->type == 30) {
            v->old_mode = v->mode;
            v->mode = 1;
            v->blend_frames = 10;
            v->blend_rate = 1.0f / v->blend_frames;
        } else if (hero->state == 15) {
            v->old_mode = v->mode;
            v->rise_tick = 0;
            v->mode = 3;
            v->rise_frames = 85;
            v->rise_rate = 1.0f / v->rise_frames;
            v->blend_frames = 30;
            v->blend_rate = 1.0f / v->blend_frames;
            v->rise_height = 3.0f;
            func_L01_003E2A38(entry, &follow->v.rise_target, 3.0f, 1);
            follow->v.height_start = follow->v.height;
        } else if (hero->state == 12) {
            v->old_mode = v->mode;
            v->mode = 8;
            v->blend_frames = 30;
            v->blend_rate = 1.0f / v->blend_frames;
        } else if (hero->state == 11) {
            /* not while strafing with the right stick's y above 0.3 */
            if (hero->strafing == 0 || hero->pad->right_y <= 0.3f) {
                v->old_mode = v->mode;
                v->rise_tick = 0;
                v->mode = 6;
                v->rise_frames = 35;
                v->rise_rate = 1.0f / v->rise_frames;
                v->blend_frames = 30;
                v->blend_rate = 1.0f / v->blend_frames;
                v->rise_height = 1.0f;
                func_L01_003E2A38(entry, &follow->v.rise_target, 1.0f, 0);
                follow->v.height_start = follow->v.height;
            }
        } else if (hero->state == 13 || hero->state == 14) {
            v->old_mode = v->mode;
            v->rise_tick = 0;
            v->mode = 5;
            v->rise_frames = 45;
            v->rise_rate = 1.0f / v->rise_frames;
            v->blend_frames = 30;
            v->blend_rate = 1.0f / v->blend_frames;
            v->rise_height = 3.5f;
            func_L01_003E2A38(entry, &follow->v.rise_target, 3.5f, 1);
            follow->v.height_start = follow->v.height;
        } else if (hero->type == 4) {
            v->old_mode = v->mode;
            v->mode = 2;
            v->blend_frames = 30;
            v->blend_rate = 1.0f / v->blend_frames;
        }
        return;
    }
    if (v->mode == 2 && (hero->state == 134 || hero->state == 95)) {
        v->old_mode = v->mode;
        v->mode = 1;
        v->blend_frames = 10;
        v->blend_rate = 1.0f / v->blend_frames;
        return;
    }
    if (v->mode != 9 && v->mode != 1 && hero->state == 20) {
        v->old_mode = v->mode;
        v->mode = 9;
        v->blend_frames = 0;
        v->rise_tick = 0;
        v->rise_frames = 30;
        v->rise_rate = 1.0f / v->rise_frames;
        v->blend_rate = 1.0f;
        v->rise_height = 1.5f;
        func_L01_003E2A38(entry, &v->rise_target, 1.5f, 1);
        v->height_start = v->height;
        return;
    }
    if ((v->mode == 1 || v->mode == 2) && hero->type != 4 && hero->type != 2 && hero->type != 30 &&
        hero->state != 134) {
        v->mode = 0;
        v->blend_frames = 0;
        v->blend_rate = 1.0f;
        return;
    }
    if (v->mode == 7) { /* a flip's way back down */
        if (hero->past_apex == 0) {
            goto flip;
        }
        if (hero->type == 2) {
            v->old_mode = v->mode;
            v->mode = 1;
            v->blend_frames = 20;
            v->blend_rate = 1.0f / v->blend_frames;
            return;
        }
    }
    if (v->mode == 4 && hero->type != 4) {
        if (hero->type == 2) {
            v->old_mode = 4;
            v->mode = 1;
            v->blend_frames = 20;
            v->blend_rate = 1.0f / v->blend_frames;
        } else {
            v->old_mode = 4;
            v->mode = 0;
            v->blend_frames = 20;
            v->blend_rate = 1.0f / v->blend_frames;
        }
        return;
    }
    if (v->mode == 3 && hero->state == 11) {
    flip:
        v->old_mode = v->mode;
        v->rise_tick = 0;
        v->mode = 6;
        v->rise_frames = 35;
        v->rise_rate = 1.0f / v->rise_frames;
        v->blend_frames = 30;
        v->blend_rate = 1.0f / v->blend_frames;
        v->rise_height = 1.0f;
        func_L01_003E2A38(entry, &v->rise_target, 1.0f, 1);
        v->height_start = v->height;
        return;
    }
    if (v->mode == 5 && hero->state == 12) {
        v->old_mode = v->mode;
        v->mode = 8;
        v->blend_frames = 30;
        v->blend_rate = 1.0f / v->blend_frames;
        return;
    }
    if (v->mode == 8 && hero->state != 12) {
        v->old_mode = v->mode;
        v->mode = 0;
        v->blend_frames = 20;
        v->blend_rate = 1.0f / v->blend_frames;
        return;
    }
    if (v->mode == 6 && hero->state != 11) {
        v->old_mode = v->mode;
        v->mode = 0;
        v->blend_frames = 20;
        v->blend_rate = 1.0f / v->blend_frames;
        return;
    }
    if ((v->mode == 3 || v->mode == 5) && hero->type != 4) {
        v->old_mode = v->mode;
        v->mode = 0;
        v->blend_frames = 20;
        v->blend_rate = 1.0f / v->blend_frames;
        return;
    }
    /* a jump attack ends falling or after 55 frames off the ground */
    if ((v->mode == 9 && (hero->type == 2 || hero->air_frames >= 55)) ||
        (v->mode == 10 && (hero->type == 2 || hero->air_frames >= 55))) {
        v->old_mode = v->mode;
        v->mode = 1;
        v->blend_frames = 20;
        v->blend_rate = 1.0f / v->blend_frames;
        {
            Follow_3E48D8 *f = cam->follow;
            f->view_ease_frames = 90;
            f->view_ease_rate = 1.0f / f->view_ease_frames;
        }
        cam->view_from = cam->position;
        return;
    }
    if (v->mode == 9 && hero->state != 20) {
        v->old_mode = v->mode;
        v->mode = 10;
        v->blend_frames = 30;
        v->blend_rate = 1.0f / v->blend_frames;
        return;
    }
    if (v->mode == 10 && func_003883C8((u8 *)&v->rise_frames)) {
        v->old_mode = v->mode;
        v->mode = 0;
        v->blend_frames = 20;
        v->blend_rate = 1.0f / v->blend_frames;
    }
}
/* localdecomp:end func_L01_003E2AE8 */
