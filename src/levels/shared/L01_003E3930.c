#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad[1120];
} Ent1120;
typedef int q128 __attribute__((mode(TI)));
typedef struct { u8 pad[0x120]; f32 x120[3]; } V_3E3730;
typedef struct { u8 pad[0x70]; V_3E3730 *x70; } O_3E3730;
typedef struct {
    u8 pad[80];
    u8 *p50;
    u8 pad2[1036];
} Entry_3E6C58;
typedef struct {
    u8 pad[80];
    u8 *p50;
    u8 pad2[1036];
} Entry_3E6CA8;
typedef struct {
    u8 pad[28];
    u8 *p1C;
} M_3E6CA8;
typedef struct {
    u8 pad[80];
    u8 *p;
    u8 pad2[1120 - 84];
} S_003E7430;
typedef struct {
    u8 pad[588];
    s32 v;
    u8 pad2[1120 - 592];
} Unk003E8810;
typedef int s128_003E8C50 __attribute__((mode(TI)));
typedef struct {
    u8 pad[512];
    u8 data[48];
    s128_003E8C50 q;
    u8 pad2[1120 - 576];
} Slot_003E8C50;
typedef struct {
    u8 pad[56];
    u8 a38[4];
    u8 a3C[4];
} Base_003E8C50;
typedef struct {
    u8 pad[28];
    Base_003E8C50 *p;
} Ent_003E8C50;
typedef struct {
    u8 pad[48];
    s128_003E8C50 q30;
    u8 pad2[112 - 64];
    s32 *f70;
    u8 pad3[10];
    s16 h7E;
    u8 pad4[4];
    s16 h84;
    u8 pad5[14];
    s32 f94;
} Obj_003E8C50;
typedef int u128_3E8D18 __attribute__((mode(TI)));
typedef struct { u8 pad[0x200]; u8 x200[0x30]; u128_3E8D18 x230; u8 pad240[0x2A0 - 0x240]; s16 x2A0; u8 pad2A2[0x2C0 - 0x2A2]; f32 x2C0; u8 pad2C4[1120 - 0x2C4]; } E_3E8D18;
typedef struct { u8 pad[0x25E5]; u8 x25E5; } G_3E8D18;
typedef struct { u8 pad[0x30]; u128_3E8D18 x30; u8 pad40[0x94 - 0x40]; s32 x94; } O_3E8D18;
typedef struct {
    u8 pad0[292];
    s32 w124;
    u8 pad128[672 - 296];
    s16 h2A0;
    u8 b2A2;
    u8 b2A3;
    u8 pad2A4[696 - 676];
    f32 f2B8;
    u8 pad2BC[712 - 700];
    f32 f2C8;
    u8 pad2CC[1120 - 716];
} Entry_3E92A8;
typedef int u128_003E94A0 __attribute__((mode(TI)));
typedef struct { u8 pad[80]; u8 *o; u8 pad2[1036]; } Slot_003E94A0;
typedef int u128_003E9510 __attribute__((mode(TI)));
typedef struct { u8 pad[80]; u8 *o; u8 pad2[1036]; } Slot_003E9510;

typedef struct {
    u8 pad[0x70];
    u8 *x70;
    u8 pad2[0x86 - 0x74];
    s16 h86;
} Q_003E8F20;

typedef struct {
    u8 pad00[0x10];
    u32 flags;
    f32 f14;
    u8 pad18[4];
    f32 f1C;
    u8 pad20[4];
    f32 f24;
} Input_003E92F8;
typedef struct {
    u8 pad00[0x134];
    f32 *p134;
} Ent_003E92F8;
typedef struct {
    u8 pad00[0x60];
    u16 count;
    u8 pad62[2];
    u32 best;
    u32 flags;
} Counter_003E92F8;
typedef struct {
    s32 v;
    u8 pad[0x1C];
} Pad_003E92F8;

typedef struct {
    u8 pad0[0x24C];
    s32 x24C;
    u8 pad1[0x2A0 - 0x250];
    s16 h2A0;
    u8 pad2[0x2A3 - 0x2A2];
    u8 b2A3;
    u8 pad3[0x2B8 - 0x2A4];
    f32 f2B8;
    f32 f2BC;
    f32 f2C0;
    f32 f2C4;
    f32 f2C8;
    f32 f2CC;
    u8 pad4[1120 - 0x2D0];
} Ent_003EB200;

LINKER_REMNANT("asm/levels", func_L01_003E3930);

INCLUDE_ASM("asm/levels", func_L01_003E3938);

INCLUDE_ASM("asm/levels", func_L01_003E3F08);

/* localdecomp:start func_L01_003E4008 */
extern void func_003C2880_003E4008();
 
void func_L01_003E4008(void) {
    func_003C2880_003E4008();
}
/* localdecomp:end func_L01_003E4008 */

/* localdecomp:start func_L01_003E4028 */
extern Ent1120 D_L01_001E2BD0[];

void func_L01_003E4028(u8 *obj, u128_t *out) {
    *out = *(u128_t *)&D_L01_001E2BD0[*(s32 *)(obj + 148)];
}
/* localdecomp:end func_L01_003E4028 */

INCLUDE_ASM("asm/levels", func_L01_003E4050);

/* localdecomp:start func_L01_003E4168 */
extern s32 func_L01_003F7350(q128 *, f32);

s32 func_L01_003E4168(q128 *a0) {
    q128 v = *a0;
    return func_L01_003F7350(&v, 0.0f) != 0;
}
/* localdecomp:end func_L01_003E4168 */

INCLUDE_ASM("asm/levels", func_L01_003E4198);

INCLUDE_ASM("asm/levels", func_L01_003E42E8);

INCLUDE_ASM("asm/levels", func_L01_003E4428);

INCLUDE_ASM("asm/levels", func_L01_003E4580);

INCLUDE_ASM("asm/levels", func_L01_003E4828);

/* localdecomp:start func_L01_003E48D8 */
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

__asm__(".extern D_L01_001DF67C, 4");
extern s32 D_L01_001DF67C;
extern Entry_3E6C58 D_L01_001E2A40[];
extern void func_L01_003E4828(Entry_3E6C58 *entry, q128_3E48D8 *target, f32 height, s32 from_ground);
extern s32 func_0038CB00(u8 *);

/* camera_vertical_modes: the follow point's vertical mode (follow +0x144) by the hero's
   state: 1 falls, 2 jump hold, 3 heli (15), 5 rocket and double jump (13, 14), 6/7 flip (11),
   8 crouch flip (12), 9/10 jump attack (20); 3, 5, 6 and 7 are timed rises. */
void func_L01_003E48D8(Cam_3E48D8 *cam) {
    Follow_3E48D8 *follow = cam->follow;
    Vertical_3E48D8 *v = &follow->v;
    Entry_3E6C58 *entry = &D_L01_001E2A40[cam->player];
    Hero_3E48D8 *hero = (Hero_3E48D8 *)((u8 *)entry + 0x150);

    if (D_L01_001DF67C != 0) { /* skip one frame */
        D_L01_001DF67C = 0;
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
            v->rise_frames = 71;
            v->rise_rate = 1.0f / v->rise_frames;
            v->blend_frames = 30;
            v->blend_rate = 1.0f / v->blend_frames;
            v->rise_height = 3.0f;
            func_L01_003E4828(entry, &follow->v.rise_target, 3.0f, 1);
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
                v->rise_frames = 29;
                v->rise_rate = 1.0f / v->rise_frames;
                v->blend_frames = 30;
                v->blend_rate = 1.0f / v->blend_frames;
                v->rise_height = 1.0f;
                func_L01_003E4828(entry, &follow->v.rise_target, 1.0f, 0);
                follow->v.height_start = follow->v.height;
            }
        } else if (hero->state == 13 || hero->state == 14) {
            v->old_mode = v->mode;
            v->rise_tick = 0;
            v->mode = 5;
            v->rise_frames = 37;
            v->rise_rate = 1.0f / v->rise_frames;
            v->blend_frames = 30;
            v->blend_rate = 1.0f / v->blend_frames;
            v->rise_height = 3.5f;
            func_L01_003E4828(entry, &follow->v.rise_target, 3.5f, 1);
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
        v->rise_frames = 25;
        v->rise_rate = 1.0f / v->rise_frames;
        v->blend_rate = 1.0f;
        v->rise_height = 1.5f;
        func_L01_003E4828(entry, &v->rise_target, 1.5f, 1);
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
            v->blend_frames = 17;
            v->blend_rate = 1.0f / v->blend_frames;
            return;
        }
    }
    if (v->mode == 4 && hero->type != 4) {
        if (hero->type == 2) {
            v->old_mode = 4;
            v->mode = 1;
            v->blend_frames = 17;
            v->blend_rate = 1.0f / v->blend_frames;
        } else {
            v->old_mode = 4;
            v->mode = 0;
            v->blend_frames = 17;
            v->blend_rate = 1.0f / v->blend_frames;
        }
        return;
    }
    if (v->mode == 3 && hero->state == 11) {
    flip:
        v->old_mode = v->mode;
        v->rise_tick = 0;
        v->mode = 6;
        v->rise_frames = 29;
        v->rise_rate = 1.0f / v->rise_frames;
        v->blend_frames = 30;
        v->blend_rate = 1.0f / v->blend_frames;
        v->rise_height = 1.0f;
        func_L01_003E4828(entry, &v->rise_target, 1.0f, 1);
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
        v->blend_frames = 17;
        v->blend_rate = 1.0f / v->blend_frames;
        return;
    }
    if (v->mode == 6 && hero->state != 11) {
        v->old_mode = v->mode;
        v->mode = 0;
        v->blend_frames = 17;
        v->blend_rate = 1.0f / v->blend_frames;
        return;
    }
    if ((v->mode == 3 || v->mode == 5) && hero->type != 4) {
        v->old_mode = v->mode;
        v->mode = 0;
        v->blend_frames = 17;
        v->blend_rate = 1.0f / v->blend_frames;
        return;
    }
    /* a jump attack ends falling or after 46 frames off the ground */
    if ((v->mode == 9 && (hero->type == 2 || hero->air_frames >= 46)) ||
        (v->mode == 10 && (hero->type == 2 || hero->air_frames >= 46))) {
        v->old_mode = v->mode;
        v->mode = 1;
        v->blend_frames = 17;
        v->blend_rate = 1.0f / v->blend_frames;
        {
            Follow_3E48D8 *f = cam->follow;
            f->view_ease_frames = 75;
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
    if (v->mode == 10 && func_0038CB00((u8 *)&v->rise_frames)) {
        v->old_mode = v->mode;
        v->mode = 0;
        v->blend_frames = 17;
        v->blend_rate = 1.0f / v->blend_frames;
    }
}
/* localdecomp:end func_L01_003E48D8 */

INCLUDE_ASM("asm/levels", func_L01_003E4F20);

/* localdecomp:start func_L01_003E5578 */
extern f32 func_00382BC8(f32 *, f32, f32, f32, f32, f32);
void func_L01_003E5578(O_3E3730 *a0, f32 *a1, f32 *a2, f32 b, f32 c, f32 d) {
    V_3E3730 *v = a0->x70;
    a1[0] = func_00382BC8(&v->x120[0], a1[0], a2[0], b, c, d);
    a1[1] = func_00382BC8(&v->x120[1], a1[1], a2[1], b, c, d);
    a1[2] = func_00382BC8(&v->x120[2], a1[2], a2[2], b, c, d);
}
/* localdecomp:end func_L01_003E5578 */
