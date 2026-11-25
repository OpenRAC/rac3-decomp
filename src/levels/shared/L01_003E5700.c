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

/* declared by functions of L01_003E3930.c, which this file was cut from */
extern Entry_3E6C58 D_L01_001E2A40[];
extern s32 func_0038CB00(u8 *);
extern f32 func_00382BC8(f32 *, f32, f32, f32, f32, f32);

/* localdecomp:start func_L01_003E5700 */
extern void func_L01_003E5578(O_3E3730 *a0, f32 *a1, f32 *a2, f32 b, f32 c, f32 d);
extern s32 func_0038CB00(u8 *);
extern void func_L01_003E5638(u8 *, s32, void *, s32);

void func_L01_003E5700(u8 *a0, s32 a1) {
    u8 buf[16];
    u8 *q;
    u8 *s;
    f32 scale;
    f32 x;
    f32 y;
    u8 t;

    q = *(u8 **)(a0 + 0x70);
    s = q + 0x60;
    if (func_0038CB00(q + 0x146) != 0) {
        s[0xE5] = s[0xE4];
    }
    scale = (f32)*(s16 *)(s + 0xE6) * *(f32 *)(s + 0xE8);
    func_L01_003E5638(a0, a1, buf, s[0xE4]);
    t = s[0xE4];
    if (t == 3 || t == 5 || t == 6 || t == 7 || t == 1) {
        x = scale * -0.049999997f + 0.0599999987f;
        y = scale * -0.200000003f + 0.400000006f;
    } else {
        x = 0.00999999978f;
        y = 0.200000003f;
    }
    ((void (*)(u8 *, u8 *, void *, f32, f32, f32))func_L01_003E5578)(a0, s + 0xB0, buf, x, y, 0.0f);
}
/* localdecomp:end func_L01_003E5700 */

/* localdecomp:start func_L01_003E5828 */
#include "vu0.h"

typedef int q128_003E5828 __attribute__((mode(TI)));
typedef struct { u8 pad0[0x50]; u8 *p50; u8 pad54[0x460 - 0x54]; } Entry_003E5828;

typedef struct {
    u8 pad0[0x70];
    u8 *follow;
    u8 pad74[0x94 - 0x74];
    s32 player;
} Cam_003E5828;

extern Entry_003E5828 D_L01_001E2A40_003E5828[];
extern s32 D_L01_001DF810_003E5828[2] __attribute__((section(".sdata")));
extern vu0_v4 D_L01_001EAA20_003E5828;

extern void func_L01_003E4028(u8 *, q128_003E5828 *);
extern void func_L01_003E48D8(Cam_003E5828 *);
extern void func_L01_003E4F20(Cam_003E5828 *, vu0_v4 *);
extern f32 func_0038CE68_003E5828(void *, void *);
extern void func_0038CE20_003E5828(void *, void *, f32);
extern f32 func_0038CF00_003E5828(void *, void *);
extern f32 func_00382BC8(f32 *, f32, f32, f32, f32, f32);
extern s32 func_L01_0040E020(void *);
extern void func_0038CDF8_003E5828(f32 *, f32 *, f32 *, f32);
extern void func_L01_003E5700(u8 *, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038CEA8_003E5828(void *);
extern void func_L01_003E8C28(s32, f32, f32);

void func_L01_003E5828(Cam_003E5828 *cam) {
    vu0_v4 dir;
    vu0_v4 pos[2];      /* func_L01_003E4028 fills pos[0]; retail keeps the 16 bytes of pos[1] (sp+0x20) unused */
    vu0_v4 old;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 off;
    vu0_v4 from;
    vu0_v4 to;
    vu0_v4 hit;
    vu0_v4 d;
    vu0_v4 mid;
    u8 *entry;
    u8 *follow;
    u8 *hero;
    u8 *target;
    u8 *vel;
    u8 *look;
    u8 *springs;
    u8 *body;
    u8 *p;
    f32 zero;
    f32 radius;
    f32 height;
    f32 len;

    entry = (u8 *)&D_L01_001E2A40_003E5828[cam->player];
    follow = cam->follow;
    zero = 0.0f;
    springs = follow + 0x180;
    target = follow + 0xC0;
    vel = follow + 0x70;
    look = follow + 0x60;
    body = entry + 0x60;
    hero = entry + 0x150;

    func_L01_003E4028((u8 *)cam, (q128_003E5828 *)pos);
    func_L01_003E48D8(cam);
    func_L01_003E4F20(cam, &dir);
    *(q128_003E5828 *)(vel) = *(q128_003E5828 *)&dir;
    *(q128_003E5828 *)&old = *(q128_003E5828 *)look;
    {
        f32 t = func_0038CE68_003E5828(entry + 0x90, target);
        func_0038CE20_003E5828(&a, entry + 0x90, t);
    }
    vec_sub_ba(&b, target, &a);
    *(f32 *)(look + 0x110) = func_0038CF00_003E5828(&a, vel);
    a.x = func_00382BC8((f32 *)(follow + 0x100), a.x, *(f32 *)(look + 0x10), *(f32 *)(look + 0x104), *(f32 *)(look + 0x108), zero);
    a.y = func_00382BC8((f32 *)(follow + 0x104), a.y, *(f32 *)(look + 0x14), *(f32 *)(look + 0x104), *(f32 *)(look + 0x108), zero);
    a.z = func_00382BC8((f32 *)(follow + 0x108), a.z, *(f32 *)(look + 0x18), *(f32 *)(look + 0x104), *(f32 *)(look + 0x108), zero);
    b.x = func_00382BC8((f32 *)(follow + 0xF0), b.x, *(f32 *)(look + 0x0), *(f32 *)(look + 0xFC), *(f32 *)(look + 0x100), zero);
    b.y = func_00382BC8((f32 *)(follow + 0xF4), b.y, *(f32 *)(look + 0x4), *(f32 *)(look + 0xFC), *(f32 *)(look + 0x100), zero);
    b.z = func_00382BC8((f32 *)(follow + 0xF8), b.z, *(f32 *)(look + 0x8), *(f32 *)(look + 0xFC), *(f32 *)(look + 0x100), zero);
    vec_add_ba(look, look, vel);
    vec_add_ab(target, &b, &a);
    func_0038CE20_003E5828(&off, entry + 0x80, *(f32 *)(look + 0xD0));
    if (look[0xF9] != 0) {
        look[0xF8]++;
        if (*(s16 *)(look + 0x10C) < look[0xF8]) {
            look[0xF8] = *(s16 *)(look + 0x10C);
        }
        func_0038CDF8_003E5828((f32 *)&from, (f32 *)look, (f32 *)target, (f32)look[0xF8] / (f32)*(s16 *)(look + 0x10C));
        vec_add_ab(follow + 0xA0, &off, &from);
    } else {
        func_L01_0040E020(follow + 0x158);
        func_0038CDF8_003E5828((f32 *)&from, (f32 *)look, (f32 *)target, (f32)look[0xF8] / (f32)*(s16 *)(look + 0x10C));
        vec_add_ab(follow + 0xA0, &off, &from);
    }
    func_L01_003E5700((u8 *)cam, (s32)&off);
    if (hero[0x12B] == 2) {
        func_0038CE20_003E5828(&off, body + 0x20, 2.25f);
    } else if (hero[0x12B] == 1) {
        func_0038CE20_003E5828(&off, body + 0x20, 0.4f);
    } else if (*(s32 *)(hero + 0x104) == 0x11) {
        qzero(&off);
    } else {
        func_0038CE20_003E5828(&off, body + 0x20, 0.5f);
    }
    p = body + 0x20;
    vec_add_ba(&from, pos, &off);
    func_0038CE20_003E5828(&off, p, *(f32 *)(springs + 0x30));
    vec_add_ba(look + 0x50, &off, look);
    {
        Entry_003E5828 *e = &D_L01_001E2A40_003E5828[cam->player];
        u8 *m = *(u8 **)(e->p50 + 0x70);
        radius = *(f32 *)(m + 0x254) * *(f32 *)(m + 0x24C) * (*(f32 *)(m + 0x250) - 1.0f) + 0.35f;
    }
    func_0038CE20_003E5828(&to, p, 20.0f);
    vec_add_ab(&to, &from, &to);
    if (func_003D3CB0(&from, &to, D_L01_001DF810_003E5828[cam->player], *(void **)(hero + 0xF0), 0) != 0) {
        hit = D_L01_001EAA20_003E5828;
    } else {
        hit = to;
    }
    func_0038CE20_003E5828(&to, p, 20.0f);
    vec_sub_ab(&to, &from, &to);
    if (func_003D3CB0(&from, &to, D_L01_001DF810_003E5828[cam->player], *(void **)(hero + 0xF0), 0) != 0) {
        to = D_L01_001EAA20_003E5828;
    }
    vec_sub_ab(&d, &to, &hit);
    if (func_0038CEA8_003E5828(&d) < radius + radius) {
        vec_add_ba(&mid, &hit, &to);
        func_0038CE20_003E5828(&mid, &mid, 0.5f);
        *(vu0_v4 *)(look + 0x50) = mid;
        vec_sub_ba(&d, &mid, look);
        func_L01_003E8C28(cam->player, func_0038CE68_003E5828(&d, p), 0.006f);
    } else {
        vec_sub_ab(&d, &hit, look);
        len = func_0038CEA8_003E5828(&d);
        height = *(f32 *)(springs + 0x30);
        if (len <= height + radius) {
            func_0038CE20_003E5828(&mid, p, radius);
            vec_sub_ba(&mid, &hit, &mid);
            *(vu0_v4 *)(look + 0x50) = mid;
            vec_sub_ba(&d, &mid, look);
            func_L01_003E8C28(cam->player, func_0038CE68_003E5828(&d, p), 0.006f);
        } else {
            f32 dl = func_0038CE68_003E5828(look, body + 0x30);
            if (func_0038CE68_003E5828(&to, body + 0x30) < dl) {
                to = *(vu0_v4 *)look;
            }
            func_0038CE20_003E5828(&off, p, height);
            vec_add_ab(look + 0x50, &off, &to);
        }
    }
}
/* localdecomp:end func_L01_003E5828 */

/* localdecomp:start func_L01_003E5E50 */
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
extern s32 D_L01_001DF820[2];      /* one per player: 8 bytes, so its address is one `la` */
extern f32 func_00382BC8(f32 *, f32, f32, f32, f32, f32);
extern void func_003C41A0(f32 *, f32 *, f32, f32, f32, f32);
extern void func_L01_003E8DB8(s32, f32, f32);

typedef struct {
    s16 x0;
    s16 x2;
    u8 pad_4[0x1C - 0x4];
    f32 gain;                  /* 0x1C */
    f32 damping;               /* 0x20 */
    u8 pad_24[4];
    f32 value;                 /* 0x28 */
    f32 target;                /* 0x2C */
    f32 velocity;              /* 0x30 */
    f32 x34;
    f32 x38;
} View_3E5E50;
typedef struct {
    u8 pad_0[0xD0];
    f32 height;                /* 0xD0 */
    f32 height_target;         /* 0xD4 */
    f32 height_gain;           /* 0xD8 */
    f32 height_velocity;       /* 0xDC */
    u8 pad_E0[0xF9 - 0xE0];
    u8 xF9;
    s16 height_set;            /* 0xFA */
    u8 pad_FC[0x104 - 0xFC];
    f32 spring_gain;           /* 0x104 */
    f32 spring_damping;        /* 0x108 */
    s16 spring_frames;         /* 0x10C */
} Look_3E5E50;
typedef struct {
    u8 pad_0[0x2C];
    f32 distance;              /* 0x2C */
    f32 height;                /* 0x30 */
    u8 pad_34[0x3C - 0x34];
    s16 distance_set;          /* 0x3C */
    s16 height_set;            /* 0x3E */
    f32 distance_target;       /* 0x40 */
    f32 distance_velocity;     /* 0x44 */
    f32 distance_gain;         /* 0x48 */
    f32 height_target;         /* 0x4C */
    f32 height_velocity;       /* 0x50 */
    f32 height_gain;           /* 0x54 */
    f32 rest_distance;         /* 0x58 */
} Springs_3E5E50;
typedef struct {
    u8 pad_0[0x10];
    s32 x10;
    f32 x14;
    u8 pad_18[4];
    f32 x1C;
    f32 x20;
    f32 x24;
} Stick_3E5E50;
typedef struct {
    u8 pad_0[0x3C];
    f32 x3C;
    f32 x40;
    f32 x44;
    s32 x48;
    u8 pad_4C[2];
    s16 x4E;
} Steer_3E5E50;
typedef struct {
    u8 pad_0[6];
    s16 x6;
    u8 pad_8[4];
    f32 far_distance;          /* 0xC */
} Approach_3E5E50;
typedef struct {
    u8 pad_0[0x10];
    s16 x10;
    u8 pad_12[0x20 - 0x12];
    View_3E5E50 view;          /* 0x20 */
    u8 pad_5C[0x60 - 0x5C];
    Look_3E5E50 look;          /* 0x60 */
    u8 pad_170[0x180 - 0x170];
    Springs_3E5E50 springs;    /* 0x180 */
    u8 pad_1DC[0x1E0 - 0x1DC];
    Stick_3E5E50 stick;        /* 0x1E0 */
    u8 pad_208[0x210 - 0x208];
    Steer_3E5E50 steer;        /* 0x210 */
    Approach_3E5E50 approach;  /* 0x260 */
} Follow_3E5E50;
typedef struct {
    u8 pad_0[0x70];
    Follow_3E5E50 *follow;     /* 0x70 */
    u8 pad_74[0x94 - 0x74];
    s32 player;                /* 0x94 */
} Update_3E5E50;
typedef struct {
    u8 pad_0[0x70];
    Follow_3E5E50 *follow;     /* 0x70 */
    u8 pad_74[0xB0 - 0x74];
} Slot_3E5E50;
extern u8 D_L01_001E50D0[];

/* camera_end_of_frame: springs the distance (gain 0.003, damping 0.2), height and look
   height to their targets and resets the per-frame overrides. The fields are struct members
   on purpose: a member store cannot alias a scalar global, which is what lets retail load
   the look-spring defaults ahead of the stores around them. */
void func_L01_003E5E50(Update_3E5E50 *update) {
    Stick_3E5E50 *stick = &update->follow->stick;
    Follow_3E5E50 *follow;
    Springs_3E5E50 *springs;
    Look_3E5E50 *look;
    Follow_3E5E50 *rest;
    Look_3E5E50 *rest_look;
    Springs_3E5E50 *rest_springs;
    View_3E5E50 *view;
    Steer_3E5E50 *steer;
    Approach_3E5E50 *approach;

    /* the virtual stick */
    stick->x14 = D_L01_001D5FF0[update->player];
    stick->x1C = 0.0f;
    stick->x20 = 0.0f;
    stick->x10 = 0;
    stick->x24 = 0.0f;

    follow = update->follow;
    springs = &follow->springs;
    look = &follow->look;
    /* the follow camera at rest gives the targets nothing set this frame */
    rest = ((Slot_3E5E50 *)(D_L01_001E50D0 + update->player * 0xB0))->follow;
    rest_springs = &rest->springs;
    rest_look = &rest->look;
    /* the distance: towards this frame's target if one was set, else the resting one */
    if (springs->distance_set != 0) {
        springs->distance = func_00382BC8(&follow->springs.distance_velocity, springs->distance,
            springs->distance_target, springs->distance_gain, 0.2f, stick->x1C);
    } else {
        springs->distance = func_00382BC8(&follow->springs.distance_velocity, springs->distance,
            rest_springs->distance, springs->distance_gain, 0.2f, stick->x1C);
    }
    /* the height */
    if (springs->height_set != 0) {
        springs->height = func_00382BC8(&springs->height_velocity, springs->height,
            springs->height_target, springs->height_gain, 0.2f, 0.0f);
    } else {
        springs->height = func_00382BC8(&springs->height_velocity, springs->height,
            rest_springs->height, springs->height_gain, 0.2f, 0.0f);
    }
    /* the look height */
    if (look->height_set != 0) {
        look->height = func_00382BC8(&look->height_velocity, look->height,
            look->height_target, look->height_gain, 0.2f, 0.0f);
    } else {
        look->height = func_00382BC8(&look->height_velocity, look->height,
            rest_look->height, look->height_gain, 0.2f, 0.0f);
    }
    springs->distance_set = 0;
    springs->height_set = 0;
    springs->distance_target = 0.0f;
    springs->height_target = 0.0f;
    springs->rest_distance = rest_springs->distance;
    look->height_set = 0;
    look->height_target = 0.0f;

    update->follow->x10 = 1;
    view = &update->follow->view;
    /* the look-up's spring */
    view->gain = 0.005f;
    view->damping = 0.2f;
    view->x2 = 0;
    if (view->target != 0.0f) {
        func_003C41A0(&view->value, &view->velocity, view->target, view->x34, view->x38, 1.0f);
    } else if (view->value != 0.0f) {
        func_003C41A0(&view->value, &view->velocity, 0.0f, view->x34, view->x38, 1.0f);
    }
    view->target = 0.0f;

    /* the look point's springs back to their defaults */
    func_L01_003E8DB8(update->player, D_L01_001DF664, D_L01_001DF66C);
    look->spring_gain = D_L01_001DF668;
    look->spring_damping = D_L01_001DF66C;
    look->xF9 = 0;
    look->spring_frames = (D_L01_001DF670 * 5 + 2) / 6;

    steer = &update->follow->steer;
    steer->x44 = 0.1f;
    steer->x3C = 1.0f;
    steer->x40 = 8.0f;
    steer->x48 = D_L01_001DF820[update->player];
    steer->x4E = 0;
    /* the approach's far distance, and its per-frame switch */
    approach = &update->follow->approach;
    approach->far_distance = 6.0f;
    approach->x6 = 0;
}
/* localdecomp:end func_L01_003E5E50 */

/* localdecomp:start func_L01_003E6120 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E6120;

typedef struct {
    u8 pad0[0x100];
    f32 f100;
    f32 f104;
    u8 pad108[0x1A0 - 0x108];
    s32 w1A0;
} Pad_003E6120;

typedef struct {
    u8 pad0[0x40];
    u8 pos[0x10];
    u8 pad50[0xF0 - 0x50];
    u8 *wF0;
    s32 wF4;
    s32 wF8;
    s32 wFC;
    s32 w100;
    s32 w104;
    u8 pad108[0x11C - 0x108];
    s32 w11C;
    u8 pad120[0x126 - 0x120];
    s16 h126;
    u8 pad128[0x12B - 0x128];
    u8 b12B;
    u8 pad12C[0x134 - 0x12C];
    Pad_003E6120 *p134;
    u8 pad138[0x144 - 0x138];
    s32 w144;
    f32 f148;
    u8 pad14C[0x2B0 - 0x14C];
} St_003E6120;

typedef struct {
    u8 pad0[0x108];
    f32 f108[6];
    u8 pad120[0x144 - 0x120];
    struct {
        u8 *w144;
        s32 w148;
    } s144;
    u8 pad14C[4];
    St_003E6120 st;
    void (*fn400)(s32);
    u8 pad404[0x460 - 0x404];
} Ent_003E6120;

typedef struct {
    u8 pad0[0xD0];
    f32 fD0;
    u8 padD4[0x104 - 0xD4];
    f32 f104;
    u8 pad108[0x110 - 0x108];
    f32 f110;
    s32 w114;
} P60_003E6120;

typedef struct {
    u8 pad0[0x4E];
    s16 h4E;
} P210_003E6120;

typedef struct {
    u8 pad0[0x3C];
    f32 f3C;
    u8 pad40[4];
    f32 f44;
} Q210_003E6120;

typedef struct {
    s32 w0;
    u8 pad4[0xC];
    s32 w10;
} P260_003E6120;

typedef struct {
    u8 pad0[0x12];
    s16 h12;
    s16 h14;
    s16 h16;
    u8 pad18[0x130 - 0x18];
    f32 f130;
} Cam_003E6120;

typedef struct {
    s16 h0;
    s16 h2;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
} C20_003E6120;

typedef struct {
    u8 pad0[0x70];
    Cam_003E6120 *cam;
    u8 pad74[0x94 - 0x74];
    s32 player;
} Obj_003E6120;

extern Ent_003E6120 D_L01_001E2A40_003E6120[];
extern s32 D_L01_001DF810_003E6120[] __attribute__((section(".sdata")));
extern s32 D_L01_001D673C_003E6120;
__asm__(".extern D_L01_001D673C_003E6120, 16");
extern f32 D_L01_001D5FE8_003E6120[] __attribute__((section(".sdata")));
extern s32 D_L01_001EEA80_003E6120[];
extern f32 D_L01_001DF668_003E6120;
extern s32 D_L01_001DF684_003E6120;
extern f32 D_L01_001DF688_003E6120;
extern f32 D_L01_001DF68C_003E6120;
extern f32 D_L01_001DF690_003E6120;
extern f32 D_L01_001DF694_003E6120;
extern f32 D_L01_001DF698_003E6120;
extern f32 D_L01_001DF69C_003E6120;
extern f32 D_L01_001DF6AC_003E6120;
extern f32 D_L01_001DF6B0_003E6120;
__asm__(".extern D_L01_001DF668_003E6120, 4");
__asm__(".extern D_L01_001DF684_003E6120, 4");
__asm__(".extern D_L01_001DF688_003E6120, 4");
__asm__(".extern D_L01_001DF68C_003E6120, 4");
__asm__(".extern D_L01_001DF690_003E6120, 4");
__asm__(".extern D_L01_001DF694_003E6120, 4");
__asm__(".extern D_L01_001DF698_003E6120, 4");
__asm__(".extern D_L01_001DF69C_003E6120, 4");
__asm__(".extern D_L01_001DF6AC_003E6120, 4");
__asm__(".extern D_L01_001DF6B0_003E6120, 4");
typedef struct {
    u8 pad0[0x1430];
    u8 *target;
} Hero_003E6120;
extern Hero_003E6120 D_001A4BE0_003E6120;

extern s32 func_L01_003F2B58(s32 player);
extern void func_L01_003E8BD0(s32 player, s32 both, f32 distance, f32 gain);
extern void func_L01_003E8C28(s32 player, f32 height, f32 gain);
extern void func_L01_003E8C70(s32 idx, s32 flag, f32 a, f32 b);
extern void func_L01_003E6DA0_003E6120(s32 player, s32 a);
extern void func_L01_003E8D80(s32 player, s32 a);
extern void func_L01_003E8DB8(s32 player, f32 spring, f32 damping);
extern void func_L01_003E8E10(s32 player, f32 spring, f32 damping);
extern void func_L01_003E8E70(s32 player);
extern void func_L01_003E8EA8(s32 player);
extern void func_L01_003E8EE8(s32 player, s32 a);
extern void func_L01_003E8F20(s32 player, f32 x, f32 y, f32 z);
extern void func_L01_003E9250_003E6120(s32 player, void *direction, f32 speed, f32 a);
extern void func_L01_003E92B0_003E6120(s32 player, void *direction, f32 speed, f32 a);
extern s32 func_003D4D00_003E6120(void *centre, f32 radius, s32 kinds, void *skip, s32 extra);
extern s32 func_0038CAD0_003E6120(void *);
extern s32 func_0038CB00_003E6120(s16 *count);
extern void func_0038CE20_003E6120(void *, void *, f32);
extern f32 func_0038DAB8_003E6120(f32, f32);
extern f32 func_0038DBA0_003E6120(f32, f32);
extern f32 func_0038D098_003E6120(f32);
extern f32 func_0038D0B0_003E6120(f32);
extern u8 *func_00382348_003E6120(s32);

static __inline__ u8 state_003E6120(u8 *m)
{
    return m[0x20];
}

void func_L01_003E6120(Obj_003E6120 *a)
{
    s32 player = a->player;
    Ent_003E6120 *ent = &D_L01_001E2A40_003E6120[player];
    St_003E6120 *st = &ent->st;
    u8 *cam = (u8 *)a->cam;
    P60_003E6120 *p60 = (P60_003E6120 *)(cam + 0x60);
    P210_003E6120 *p210 = (P210_003E6120 *)(cam + 0x210);
    P260_003E6120 *p260 = (P260_003E6120 *)(cam + 0x260);
    s32 flag = 0;
    s32 camvol;
    s32 i;
    f32 t;
    f32 v[4] __attribute__((aligned(16)));
    f32 sum;
    void *pos;
    s32 n;
    s32 k;
    Ent_003E6120 *e;
    Ent_003E6120 *e2;

    if (st->b12B == 2) {
        if (p260->w10 < 2) {
            func_L01_003E8C70(player, 0, D_L01_001DF694_003E6120 * 0.75f, 0.005f);
            func_L01_003E8BD0(player, 1, D_L01_001DF698_003E6120 * 0.75f, 0.003f);
            func_L01_003E8C28(player, D_L01_001DF69C_003E6120 * 0.75f, 0.003f);
            if (*(s32 *)((u8 *)ent + 0x454) < 2) {
                f32 t1, t2, t3;
                u8 *e1D0 = (u8 *)ent + 0x1D0;
                u8 *c1 = (u8 *)a->cam;
                u8 *dd = c1 + 0x180;
                u8 *c2;
                u8 *s210;
                C20_003E6120 *c20;
                t1 = D_L01_001DF698_003E6120 * 0.75f;
                t2 = D_L01_001DF69C_003E6120 * 0.75f;
                t3 = D_L01_001DF694_003E6120 * 0.75f;
                *(f32 *)(dd + 0x2C) = t1;
                *(f32 *)(dd + 0x30) = t2;
                p60->fD0 = t3;
                func_L01_003E6DA0_003E6120(player, 1);
                c2 = (u8 *)a->cam;
                func_0038CE20_003E6120(v, e1D0, -*(f32 *)(dd + 0x30));
                c20 = (C20_003E6120 *)(c2 + 0x20);
                s210 = c2 + 0x210;
                vec_add_ab(cam + 0xB0, (u8 *)ent + 0x190, v);
                vec_sub_ab(c1 + 0x180, (u8 *)a + 0x30, cam + 0xB0);
                *(V4_003E6120 *)(c1 + 0x190) = *(V4_003E6120 *)(c1 + 0x180);
                func_0038CE20_003E6120(v, e1D0, -p60->fD0);
                vec_add_ab(cam + 0xA0, (u8 *)ent + 0x190, v);
                *(V4_003E6120 *)(cam + 0x110) = *(V4_003E6120 *)(cam + 0xA0);
                *(V4_003E6120 *)(cam + 0xC0) = *(V4_003E6120 *)(cam + 0x60) = *(V4_003E6120 *)((u8 *)ent + 0x190);
                *(V4_003E6120 *)c2 = *(V4_003E6120 *)((u8 *)a + 0x30);
                *(V4_003E6120 *)(c2 + 0x230) = *(V4_003E6120 *)((u8 *)a + 0x30);
                *(s32 *)(s210 + 0x30) = 0;
                c20->f14 = 0.0f;
                c20->f4 = p60->fD0;
                c20->f8 = *(f32 *)(dd + 0x30);
                c20->h2 = 0;
                c20->f18 = c20->f14;
                c20->f10 = c20->f14;
                c20->fC = c20->f14;
            }
        }
        func_L01_003E8E70(player);
        {
            Q210_003E6120 *q = (Q210_003E6120 *)((u8 *)a->cam + 0x210);
            q->f3C = D_L01_001DF6B0_003E6120 * 0.75f;
            q->f44 = D_L01_001DF6AC_003E6120 * 0.75f;
        }
    }
    camvol = func_L01_003F2B58(player);
    if (st->w100 == 0x81 || st->w100 == 0x7D || st->w100 == 0x7E || st->w100 == 0x7F || st->w100 == 0x50) {
        p210->h4E = 1;
    }
    if (st->w11C == 0 || p60->w114 != 0) {
        t = p60->f110;
        if (t > 2.0f) {
            t = 2.0f;
        }
        p60->f104 = (D_L01_001DF668_003E6120 - 0.002f) * (t * 0.5f) + 0.002f;
        if (st->w11C != 0) {
            func_0038CAD0_003E6120(&p60->w114);
        } else {
            p60->w114 = 12;
        }
    }
    if (st->w104 == 0x1E) {
        a->cam->f130 = 0.75f;
        func_L01_003E8E10(player, 0.04f, 0.2f);
    }
    if (st->wFC == 0xD && st->w144 != 0) {
        f32 ang = func_0038DAB8_003E6120(st->f148, 3.1415927f);
        v[0] = func_0038D098_003E6120(ang);
        v[1] = func_0038D0B0_003E6120(ang);
        v[2] = 0.0f;
        func_L01_003E9250_003E6120(player, v, 0.20943952f, v[2]);
        func_L01_003E8EA8(player);
    }
    if (st->w104 == 0x11) {
        p60->fD0 = 0.25f;
        func_L01_003E8C28(player, 0.5f, 0.003f);
        D_L01_001DF810_003E6120[player] = 0xB4;
    } else {
        func_L01_003E8EE8(player, 0x14);
        D_L01_001DF810_003E6120[player] = 0x94;
    }
    if (st->w104 == 5 && D_L01_001D673C_003E6120 == 0) {
        P60_003E6120 *q60;
        flag = 1;
        q60 = (P60_003E6120 *)((u8 *)a->cam + 0x60);
        if (st->b12B == 1 && camvol == -1) {
            q60->fD0 = 0.25f;
            func_L01_003E8C28(player, 1.5f, 0.003f);
        } else {
            q60->fD0 = 0.25f;
            func_L01_003E8C28(player, 2.5f, 0.003f);
        }
    }
    if (st->w104 == 0x10) {
        p60->fD0 = 0.25f;
    }
    if (st->b12B == 1) {
        if (p260->w0 == 0 && camvol == -1) {
            func_L01_003E8BD0(player, 1, D_L01_001DF68C_003E6120, 0.003f);
            if (flag == 0) {
                p60->fD0 = D_L01_001DF688_003E6120;
                func_L01_003E8C28(player, D_L01_001DF690_003E6120, 0.003f);
            }
        }
        *(f32 *)((u8 *)a->cam + 0x24C) = 0.6f;
    }
    if (ent->fn400 != 0) {
        ent->fn400(player);
    }
    e = &D_L01_001E2A40_003E6120[player];
    if (e->s144.w144 != 0) {
        if (p260->w10 < 2) {
            if (state_003E6120(e->s144.w144) == 0xFE || state_003E6120(e->s144.w144) == 0xFD) {
                e->s144.w144 = 0;
            } else {
                if (__builtin_fabsf(st->p134->f100) >= 0.3f || __builtin_fabsf(st->p134->f104) >= 0.3f) {
                    e->s144.w148 = 0x215;
                }
                e2 = &D_L01_001E2A40_003E6120[player];
                if (e2->s144.w148 >= 0x14E) {
                    func_0038CAD0_003E6120(&D_L01_001E2A40_003E6120[player].s144.w148);
                    if (e2->s144.w148 < 0x14E) {
                        e2->s144.w148 = 0;
                    }
                } else {
                    e2->s144.w148 = e2->s144.w148 + 1;
                    if (e2->s144.w148 >= 0x14E) {
                        e2->s144.w148 = 0x14D;
                    }
                    func_L01_003E92B0_003E6120(player, e2->s144.w144 + 0x10, (f32)e2->s144.w148 / 333.0f * 1.5707964f, 0.0f);
                    func_L01_003E8EA8(player);
                    func_L01_003E8DB8(player, 0.03f, 0.2f);
                }
            }
        }
    }
    if (D_001A4BE0_003E6120.target != 0) {
        if ((s8)(D_001A4BE0_003E6120.target)[0x20] >= 0) {
            e = &D_L01_001E2A40_003E6120[player];
            e->s144.w148 = e->s144.w148 + 1;
            if (e->s144.w148 >= 0x14E) {
                e->s144.w148 = 0x14D;
            }
            func_L01_003E92B0_003E6120(player, D_001A4BE0_003E6120.target + 0x10, (f32)e->s144.w148 / 333.0f * 1.5707964f, 0.0f);
            func_L01_003E8EA8(player);
            func_L01_003E8DB8(player, 0.03f, 0.2f);
        }
    }
    e = &D_L01_001E2A40_003E6120[player];
    if (e->s144.w144 == 0 && D_001A4BE0_003E6120.target == 0) {
        e->s144.w148 = 0;
    }
    if (st->w100 == 0x86) {
        func_L01_003E8EA8(player);
        func_L01_003E8DB8(player, 1.0f, 1.0f);
        func_L01_003E8E10(player, 0.06f, 0.2f);
        func_L01_003E8E70(player);
    }
    if (st->w100 == 0x80) {
        func_L01_003E8DB8(player, 0.04f, 0.2f);
        func_L01_003E9250_003E6120(player, st->wF0 + 0xC0, 0.7853982f, 0.017453292f);
        func_L01_003E8BD0(player, 0, 3.0f, 0.003f);
        func_L01_003E8F20(player, -1.0f, -1.0f, 0.18f);
        func_L01_003E8E70(player);
    }
    if (p260->w10 < 2 && st->w100 != 0x86 && st->w100 != 0x80 &&
        (st->w100 == 0x83 || st->w100 == 0x87 || st->h126 != 0) && (st->p134->w1A0 & 3) != 0) {
        func_L01_003E8D80(player, 0);
        pos = st->pos;
        func_L01_003E8EA8(player);
        func_L01_003E8DB8(player, 0.04f, 0.2f);
        {
            Cam_003E6120 *c = a->cam;
            c->h16 = 0;
            c->h12 = 0;
            c->h14 = 0;
        }
    } else if (st->w104 == 0x25) {
        func_L01_003E8D80(player, 0);
        pos = st->pos;
        func_L01_003E8EA8(player);
        func_L01_003E8DB8(player, 0.005f, 0.025f);
        {
            Cam_003E6120 *c = a->cam;
            c->h16 = 0;
            c->h12 = 0;
            c->h14 = 0;
        }
    } else {
        pos = st->pos;
        if (D_L01_001DF684_003E6120 != 0) {
            Cam_003E6120 *c = a->cam;
            f32 t;
            sum = 0.0f;
            for (i = 0; i < 4; i++) {
                v[i] = func_0038DBA0_003E6120(ent->f108[i + 1], ent->f108[i + 2]);
                sum += v[i];
            }
            sum *= 0.25f;
            t = sum * 5.0f;
            if (t > 1.0f) {
                t = 1.0f;
            }
            t = 1.0f - t;
            if (t < 0.3f) {
                c->h12 = 0x1B;
            }
            if (c->h12 != 0) {
                if (func_0038CB00_003E6120(&c->h12)) {
                    c->h14 = 0x25;
                }
                func_L01_003E8EA8(player);
                c->h16 = c->h16 + 1;
                if (c->h16 >= 0x1A) {
                    c->h16 = 0x19;
                }
                func_L01_003E8DB8(player, (f32)c->h16 / 25.0f * (0.04f - 0.015f) + 0.015f, 0.2f);
                D_L01_001D5FE8_003E6120[player] = 0.0f;
            } else if (c->h14 != 0) {
                func_0038CB00_003E6120(&c->h14);
                D_L01_001D5FE8_003E6120[player] = (f32)c->h14 / 37.0f * -0.85f + 0.85f;
                c->h16 = 0;
            } else {
                c->h16 = 0;
                D_L01_001D5FE8_003E6120[player] = 0.85f;
            }
        }
    }
    p260->w10 = 0;
    n = func_003D4D00_003E6120(pos, 15.0f, 1, st->wF0, 0);
    if (n > 0) {
        for (k = 0; k < n; k++) {
            u8 *o = func_00382348_003E6120(D_L01_001EEA80_003E6120[k]);
            if (o != 0 && (f32)o[0xD] != 0.0f) {
                p260->w10 = 1;
                break;
            }
        }
    }
}
/* localdecomp:end func_L01_003E6120 */

/* localdecomp:start func_L01_003E6DA0 */
#include "vu0.h"
extern s32 D_L01_001DF810[2];
extern vu0_v4 D_L01_001EAA20_003E6DA0;
extern void func_0038D590_003E6DA0(f32 *, u8 *);
extern void func_0038D000_003E6DA0(f32 *, f32 *, u8 *);
extern void func_0038CE20_003E6DA0(f32 *, f32 *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038CEA8_003E6DA0(f32 *);
extern void func_0038CF68_003E6DA0(f32 *, f32 *, f32);
extern void func_0038CE90_003E6DA0(f32 *, f32 *, f32 *);

void func_L01_003E6DA0(s32 player, s32 collision) {
    vu0_v4 up, scaled, direction, target, offset, angles;
    f32 matrix[12] __attribute__((aligned(16)));
    vu0_v4 delta;
    Entry_3E6C58 *entry = &D_L01_001E2A40[player];
    u8 *cam = entry->p50;
    u8 *follow = *(u8 **)(cam + 0x70);
    u8 *hero = (u8 *)entry + 0x150;
    u8 *springs = follow + 0x180;
    u8 *look = follow + 0x60;
    f32 distance;
    s32 mask;
    f32 *from, *copy;
    if (collision) {
        angles.x = -*(f32 *)(springs + 0x2C);
        angles.y = 0.0f;
        angles.z = *(f32 *)(springs + 0x30);
        angles.w = 0.0f;
        func_0038D590_003E6DA0(matrix, hero);
        func_0038D000_003E6DA0(&offset.x, &angles.x, *(u8 **)(look + 0xE0) + 0xC0);
        vec_add_ba(cam + 0x30, follow + 0x60, &offset);
        func_0038CE20_003E6DA0(&scaled.x, (f32 *)(*(u8 **)(look + 0xE0) + 0xE0), *(f32 *)(look + 0xD0));
        vec_add_ab(&target, follow + 0x60, &scaled);
        if (func_003D3CB0(&target, cam + 0x30, D_L01_001DF810[player], *(void **)(hero + 0xF0), 0)) {
            vec_sub_ba(&delta, &D_L01_001EAA20_003E6DA0, &target);
            distance = func_0038CEA8_003E6DA0(&delta.x);
            if (distance == 0.0f) {
                *(vu0_q *)(cam + 0x30) = *(vu0_q *)&target;
            } else {
                func_0038CE20_003E6DA0(&delta.x, &delta.x, (distance - 0.5f) / distance);
                vec_add_ab(cam + 0x30, &target, &delta);
            }
        }
    }
    from = (f32 *)(cam + 0x30);
    copy = (f32 *)(cam + 0x64);
    copy[0] = from[0];
    copy[1] = from[1];
    copy[2] = from[2];
    *(vu0_q *)&up = *(vu0_q *)((u8 *)entry + 0x90);
    func_0038CF68_003E6DA0(&scaled.x, &up.x, *(f32 *)(look + 0xD0));
    vec_add_ab(&target, &scaled, look);
    vec_sub_ba(&direction, &target, cam + 0x30);
    func_0038CF68_003E6DA0((f32 *)cam, &direction.x, 1.0f);
    *(vu0_q *)(cam + 0x20) = *(vu0_q *)&up;
    func_0038CE90_003E6DA0((f32 *)(cam + 0x10), (f32 *)cam, (f32 *)(cam + 0x20));
    func_0038CF68_003E6DA0((f32 *)(cam + 0x10), (f32 *)(cam + 0x10), 1.0f);
    func_0038CE90_003E6DA0((f32 *)(cam + 0x20), (f32 *)(cam + 0x10), (f32 *)cam);
    *(vu0_q *)(cam + 0x40) = *(vu0_q *)cam;
}
/* localdecomp:end func_L01_003E6DA0 */

/* localdecomp:start func_L01_003E7000 */
#include "vu0.h"
extern u8 D_L01_001E2B90[];
typedef int Q_3E7000 __attribute__((mode(TI)));
void func_L01_003E7000(u8 *object) {
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_0038CE68(f32 *, f32 *);
    f32 direction[4] __attribute__((aligned(16)));
    f32 temp[4] __attribute__((aligned(16)));
    f32 dot;
    u8 *entry;
    u8 *follow;
    Look_3E5E50 *look;
    Springs_3E5E50 *springs;
    if (*(s16 *)(object+0x86)!=0) return;
    entry=D_L01_001E2B90+*(s32 *)(object+0x94)*0x460;
    follow=*(u8 **)(object+0x70);
    springs=(Springs_3E5E50 *)(follow+0x180);
    look=(Look_3E5E50 *)(follow+0x60);
    func_0038CE20(direction,(f32 *)(entry+0x80),-1.0f);
    *(u128_t *)(follow+0xC0)=*(u128_t *)look=*(u128_t *)(entry+0x40);
    dot=func_0038CE68((f32 *)look,direction);
    func_0038CE20((f32 *)(follow+0x70),direction,dot);
    qzero(follow+0xF0);
    qzero(follow+0x100);
    qzero(follow+0x120);
    func_0038CE20(temp,direction,springs->height);
    {
        Q_3E7000 a, b, r;
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(vu0_v4 *)(look)));
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(vu0_v4 *)(temp)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(follow+0xB0)) : "j"(r));
    }
    func_0038CE20(temp,direction,look->height);
    {
        Q_3E7000 a, b, r;
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(vu0_v4 *)(look)));
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(vu0_v4 *)(temp)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(follow+0x110)) : "j"(r));
    }
    *(u128_t *)(follow+0xA0)=*(u128_t *)(follow+0x110);
    {
        Q_3E7000 a, b, r;
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(vu0_v4 *)(follow+0xB0)));
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(vu0_v4 *)(object+0x30)));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(springs)) : "j"(r));
    }
    *(u128_t *)(follow+0x190)=*(u128_t *)springs;
    *(u128_t *)follow=*(u128_t *)(object+0x30);
    {
        Q_3E7000 a, b, r;
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(vu0_v4 *)(follow+0xB0)));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(vu0_v4 *)(springs)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(follow+0x230)) : "j"(r));
    }
    *(s32 *)(follow+0x260)=0;
}
/* localdecomp:end func_L01_003E7000 */

INCLUDE_ASM("asm/levels", func_L01_003E7138);

/* localdecomp:start func_L01_003E75A8 */
#include "vu0.h"

extern u8 D_L01_001E2B90_003E75A8[];
extern f32 func_0038CEA8_003E75A8(void *);
extern void func_0038CF68_003E75A8(void *, void *, f32);
extern void func_0038CE20_003E75A8(void *, void *, f32);

s32 func_L01_003E75A8(u8 *a0, void *a1, s32 a2, s32 a3) {
    u8 *p = *(u8 **)(a0 + 0x70);
    u8 *e = D_L01_001E2B90_003E75A8 + *(s32 *)(a0 + 0x94) * 0x460;
    u8 *v = p + 0x180;
    u8 *w = p + 0x210;
    u8 *x = p + 0x60;
    f32 len;
    f32 d;

    len = func_0038CEA8_003E75A8(v);
    vec_sub_ab(p + 0x180, a1, p + 0xB0);
    if (*(s16 *)(w + 0x38) != 0) {
        func_0038CF68_003E75A8(v, v, *(f32 *)(v + 0x2C) - *(f32 *)(w + 0x30));
        return a3;
    }
    d = func_0038CEA8_003E75A8(v);
    if (e[0x12B] != 2 && __builtin_fabsf(*(f32 *)(*(u8 **)(e + 0x134) + 0x100)) > 0.05f && a3 != 0) {
        *(s16 *)(w + 0x34) = 0x719;
        d -= 0.09f;
    }
    if (a2 == 0 && *(s32 *)(e + 0x104) != 2 && len < d) {
        func_0038CE20_003E75A8(v, v, len / d);
        *(f32 *)(w + 0x30) = *(f32 *)(v + 0x2C) - len;
        return a3;
    }
    if (d < 0.2f) {
        if (d <= 0.0001f) {
            func_0038CF68_003E75A8(v, *(u8 **)(x + 0xE0) + 0xC0, -0.2f);
        } else {
            func_0038CE20_003E75A8(v, v, 0.2f / d);
        }
        d = 0.2f;
    }
    *(f32 *)(w + 0x30) = *(f32 *)(v + 0x2C) - d;
    return 1;
}
/* localdecomp:end func_L01_003E75A8 */

/* localdecomp:start func_L01_003E77B0 */
#include "vu0.h"
extern u8 D_L01_001E2AA0[];
extern vu0_q D_L01_001EAA20_003E77B0[];
extern vu0_q D_L01_001EAA30_003E77B0[];
extern f32 func_0038CE68(f32 *, f32 *);
extern void func_0038CF68(f32 *, f32 *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003E4050(void *, f32);
extern s32 func_L01_003FB640_003E77B0(void *, f32, s32, u8 *);
extern s32 func_L01_003FE1D8_003E77B0(void *, f32, s32);
extern s32 func_L01_003E75A8_003E77B0(u8 *, void *, s32, s32);

s32 func_L01_003E77B0(u8 *obj) {
    vu0_v4 pos, delta, normal;
    u8 *follow = *(u8 **)(obj + 0x70);
    u8 *motion = follow + 0x60;
    u8 *spring = follow + 0x180;
    u8 *steer = follow + 0x210;
    s32 idx = *(s32 *)(obj + 0x94);
    u8 *entry = D_L01_001E2AA0 + idx * 1120;
    u8 *hero;
    u8 *hero_follow;
    s32 mask;
    f32 radius;
    s32 collided = 0, changed = 0, i, again, result;

    vec_add_ab(&pos, follow + 0xB0, follow + 0x180);
    *(s16 *)(steer + 0x38) = 2;
    hero = *(u8 **)(D_L01_001E2AA0 + idx * 1120 - 0x10);
    mask = *(s32 *)(steer + 0x48);
    hero_follow = *(u8 **)(hero + 0x70);
    radius = *(f32 *)(hero_follow + 0x254) * *(f32 *)(hero_follow + 0x24C) * (*(f32 *)(hero_follow + 0x250) - 1.0f) + 0.35f;
    vec_sub_ab(&delta, obj + 0x30, &pos);
    if (func_0038CE68(&delta.x, &delta.x) > radius * radius && func_003D3CB0(obj + 0x30, &pos, mask, 0, 0)) {
        *(vu0_q *)&pos = D_L01_001EAA20_003E77B0[0];
        func_0038CF68(&delta.x, (f32 *)(D_L01_001EAA20_003E77B0 + 2), 0.005f);
        vec_add_ab(&pos, &pos, &delta);
    }
    for (i = 0; i < 3; i++) {
        if (func_L01_003E4050(&pos, radius)) collided = 1;
        again = 0;
        if (func_L01_003FB640_003E77B0(&pos, radius, mask, *(u8 **)(entry + 0xC4))) {
            *(vu0_q *)&pos = D_L01_001EAA30_003E77B0[0];
            again = 1; changed = 1;
        }
        if (func_L01_003FE1D8_003E77B0(&pos, radius, 0)) {
            *(vu0_q *)&pos = D_L01_001EAA30_003E77B0[0];
            again = 1; changed = 1;
        }
        if (!again) break;
        if (*(s16 *)(steer + 0x38) != 0) {
            f32 dot;
            vec_sub_ba(&normal, D_L01_001EAA20_003E77B0, &pos);
            func_0038CF68(&normal.x, &normal.x, 1.0f);
            dot = func_0038CE68((f32 *)(entry + 0x30), &normal.x);
            if (dot > 0.75f) *(s16 *)(steer + 0x38) = 1;
            else if (dot < -0.5f) *(s16 *)(steer + 0x38) = -1;
            else *(s16 *)(steer + 0x38) = 0;
        }
    }
    result = func_L01_003E75A8_003E77B0(obj, &pos, collided, changed);
    vec_add_ab(steer + 0x20, motion + 0x50, spring);
    if (*(s16 *)(steer + 0x38) == 2) *(s16 *)(steer + 0x38) = 0;
    return result;
}
/* localdecomp:end func_L01_003E77B0 */

/* localdecomp:start func_L01_003E7AA0 */
s32 func_L01_003E7AA0(void) {
    u8 buf[80];
    return 0;
}
/* localdecomp:end func_L01_003E7AA0 */

/* localdecomp:start func_L01_003E7AB0 */
#include "vu0.h"
/* vu0_s_003E7AB0: 128-bit struct with TImode, so "m" operands are TImode MEMs (per-offset stack deps) */
typedef struct { vu0_q q; } vu0_s_003E7AB0;

/* vec_load_003E7AB0(): lqc2 into a "j" register */
static __inline__ vu0_q vec_load_003E7AB0(void *s) {
    vu0_q q;
    __asm__("lqc2 %0, %1" : "=j"(q) : "m"(*(vu0_s_003E7AB0 *)s));
    return q;
}

/* vec_add_r2_003E7AB0(): vadd.xyz of two loaded values; a is listed twice so its register wins the result */
static __inline__ vu0_q vec_add_r2_003E7AB0(vu0_q a, vu0_q b) {
    vu0_q r;
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b), "j"(a));
    return r;
}

/* vec_store2_003E7AB0(): two sqc2 in one statement */
static __inline__ void vec_store2_003E7AB0(void *d1, vu0_q q1, void *d2, vu0_q q2) {
    __asm__("sqc2 %2, %0\n\tsqc2 %3, %1" : "=m"(*(vu0_s_003E7AB0 *)d1), "=m"(*(vu0_s_003E7AB0 *)d2) : "j"(q1), "j"(q2));
}

/* vec_sub_l1_003E7AB0(): d = a - b; a loaded alone, b loaded and subtracted in one statement, then sqc2 */
static __inline__ void vec_sub_l1_003E7AB0(void *d, void *a, void *b) {
    vu0_q x, t;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_s_003E7AB0 *)a));
    __asm__("lqc2 %1, %2\n\tvsub.xyz %0, %0, %1" : "+j"(x), "=&j"(t) : "m"(*(vu0_s_003E7AB0 *)b));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(x));
}

extern void func_0038CF68(f32 *, f32 *, f32);

void func_L01_003E7AB0(u8 *obj, vu0_v4 *out, vu0_v4 *position, vu0_v4 *target, vu0_v4 *origin, f32 gain, f32 damping) {
    vu0_v4 delta, scaled, follow_delta, sum, origin_copy;
    u8 *state = *(u8 **)(obj + 0x70);
    vec_sub_ba(&delta, position, target);
    func_0038CF68((f32 *)&scaled, (f32 *)&delta, gain);
    vec_add_ba(position, position, &scaled);
    vec_sub_ba(&follow_delta, position, state + 0xB0);
    func_0038CF68((f32 *)&follow_delta, (f32 *)&follow_delta, damping);
    {
        vu0_q qs = vec_load_003E7AB0(state + 0xB0);
        vu0_q qf = vec_load_003E7AB0(&follow_delta);
        vu0_q qo;
        qs = vec_add_r2_003E7AB0(qs, qf);
        qo = vec_load_003E7AB0(origin);
        vec_store2_003E7AB0(&origin_copy, qo, &sum, qs);
    }
    vec_sub_l1_003E7AB0(out, &sum, &origin_copy);
}
/* localdecomp:end func_L01_003E7AB0 */

/* localdecomp:start func_L01_003E7B80 */
#include "vu0.h"
extern u8 D_L01_001E2B90[];
extern vu0_v4 D_L01_001EAA20_003E7B80[];
extern s32 D_L01_001DF818[] __attribute__((section(".sdata")));
extern f32 func_L01_00476920(void *, void *, void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_003E7AB0_003E7B80(u8 *, vu0_v4 *, vu0_v4 *, vu0_v4 *, vu0_v4 *, f32, f32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);

s32 func_L01_003E7B80(u8 *cam, vu0_v4 *position, s32 index, f32 damping, f32 radius) {
    vu0_v4 total, delta, old, origin, result, target, closest, extra;
    u8 *entry = (u8 *)((Ent1120 *)D_L01_001E2B90 + *(s32 *)(cam + 0x94));
    u8 *hero = *(u8 **)(*(u8 **)(D_L01_001E2B90 + *(s32 *)(cam + 0x94) * 1120 - 0x100) + 0x70);
    u8 *follow = *(u8 **)(cam + 0x70);
    u8 *look = follow + 0xB0;
    u8 *springs = follow + 0x180;
    u8 *steer = follow + 0x210;
    f32 base, limit, t, distance, threshold;
    s32 changed;

    base = *(f32 *)(hero + 0x254) * *(f32 *)(hero + 0x24C) * (*(f32 *)(hero + 0x250) - 1.0f) + 0.35f;
    old = *position;
    origin = D_L01_001EAA20_003E7B80[0];
    result = D_L01_001EAA20_003E7B80[1];
    qzero(&total);
    vec_add_ab(&target, look, springs);
    t = func_L01_00476920(&closest, &origin, look, &target, 0.0f);
    limit = base - 0.35f;
    distance = func_0038CF00(look, &closest);
    changed = 0;
    threshold = (limit * (distance / (*(f32 *)(springs + 0x2C) - *(f32 *)(steer + 0x30))) + 0.35f) * 0.75f;
    if (t < threshold) {
        func_L01_003E7AB0_003E7B80(cam, &total, &closest, &origin, &old, threshold - t, damping);
        changed = 1;
        *position = result;
        if (func_L01_003FB640(position, D_L01_001DF818[*(s32 *)(cam + 0x94)], *(u8 **)(entry + 0xF0), radius) != 0) {
            vec_sub_ab(&delta, &old, position);
            vec_add_ba(&origin, D_L01_001EAA20_003E7B80, &delta);
            t = func_L01_00476920(&closest, &origin, look, &target, 0.0f);
            distance = func_0038CF00(look, &closest);
            threshold = (limit * (distance / (*(f32 *)(springs + 0x2C) - *(f32 *)(steer + 0x30))) + 0.35f) * 0.75f;
            if (t < threshold) {
                func_L01_003E7AB0_003E7B80(cam, &extra, &closest, &origin, &old, threshold - t, damping);
                vec_add_ab(&total, &total, &extra);
                *position = D_L01_001EAA20_003E7B80[1];
                if (func_L01_003FB640(position, D_L01_001DF818[*(s32 *)(cam + 0x94)], *(u8 **)(entry + 0xF0), radius) != 0) {
                    vec_sub_ab(&delta, &old, position);
                    vec_add_ba(&origin, D_L01_001EAA20_003E7B80, &delta);
                    t = func_L01_00476920(&closest, &origin, look, &target, 0.0f);
                    distance = func_0038CF00(look, &closest);
                    threshold = (limit * (distance / (*(f32 *)(springs + 0x2C) - *(f32 *)(steer + 0x30))) + 0.35f) * 0.75f;
                    if (t < threshold) {
                        func_L01_003E7AB0_003E7B80(cam, &extra, &closest, &origin, &old, threshold - t, damping);
                        vec_add_ab(&total, &total, &extra);
                    }
                }
            }
        }
    }
    vec_add_ab(position, &old, &total);
    return changed;
}
/* localdecomp:end func_L01_003E7B80 */

/* localdecomp:start func_L01_003E7F48 */
#include "vu0.h"
extern f32 func_0038CE68(f32 *, f32 *);
extern short D_L01_001EAA20[];

s32 func_L01_003E7F48(u8 *obj, s32 mode, f32 *pos) {
    vu0_v4 d;

    f32 *w;

    if (mode == 1) {
        w = (f32 *)(*(u8 **)(obj + 0x70) + 0x180);
        vec_sub_ab(&d, D_L01_001EAA20, pos);
        if (func_0038CE68((f32 *)&d, w) < 0.0f) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003E7F48 */

/* localdecomp:start func_L01_003E7FA8 */
#include "vu0.h"

typedef int u128_003E7FA8 __attribute__((mode(TI)));

extern u8 D_L01_001E2A40_003E7FA8[];
extern s32 D_L01_001DF818_003E7FA8[2];
extern vu0_v4 D_L01_001EAA20_003E7FA8;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void func_0038CF68_003E7FA8(void *, void *, f32);
extern f32 func_0038CE68_003E7FA8(void *, void *);
extern void func_0038CE20_003E7FA8(void *, void *, f32);
extern s32 func_L01_003E4168(void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern s32 func_L01_003E7F48_003E7FA8(void *, s32, void *, f32);
extern s32 func_L01_003E7B80_003E7FA8(void *, void *, s32, f32, f32);

s32 func_L01_003E7FA8(u8 *a0) {
    vu0_v4 dir0;
    vu0_v4 pos;
    vu0_v4 dir;
    vu0_v4 step;
    vu0_v4 old;
    vu0_v4 d;
    u8 *m;
    u8 *cam;
    u8 *st;
    u8 *pl;
    u8 *pls;
    u8 *sub;
    s32 ret;
    s32 flag;
    s32 i;
    f32 sp;
    f32 dist;
    s32 *q;

    ret = 0;
    m = *(u8 **)(a0 + 0x70);
    sub = m + 0x60;
    cam = m + 0x180;
    *(u128_003E7FA8 *)&dir0 = *(u128_003E7FA8 *)(m + 0x180);
    st = m + 0x210;
    pl = D_L01_001E2A40_003E7FA8 + *(s32 *)(a0 + 0x94) * 0x460;
    dist = 0.0f;
    *(u128_003E7FA8 *)&pos = *(u128_003E7FA8 *)(m + 0xB0);
    pls = pl + 0x150;
    func_0038CF68_003E7FA8(&dir, &dir0, 1.0f);
    sp = 0.35f;
    flag = 0;
    if (D_001D545C == 0x30 || D_001D545C == 0x1C) {
        if (!(D_L01_001DF818_003E7FA8[*(s32 *)(a0 + 0x94)] & 0x20)) {
            flag = 1;
            D_L01_001DF818_003E7FA8[*(s32 *)(a0 + 0x94)] |= 0x20;
        }
    }
    for (i = 0; i < (s32)(*(f32 *)(st + 0x40) - 1.0f); i++) {
        if (i > 0 && func_L01_003E4168(&pos) == 0
            && func_L01_003FB640(&pos, D_L01_001DF818_003E7FA8[*(s32 *)(a0 + 0x94)], *(u8 **)(pls + 0xF0), sp) != 0
            && func_L01_003E7F48_003E7FA8(a0, i, &pos, sp) == 0) {
            *(u128_003E7FA8 *)&step = *(u128_003E7FA8 *)&D_L01_001EAA20_003E7FA8;
            *(u128_003E7FA8 *)&old = *(u128_003E7FA8 *)&pos;
            if (func_L01_003E7B80_003E7FA8(a0, &pos, i, dist, sp) != 0) {
                ret = 1;
                if (pls[0x12B] != 2 && fabs_asm(*(f32 *)(*(u8 **)(pls + 0x134) + 0x100)) > 0.05f) {
                    {
                        vu0_q qa, qb;
                        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(step));
                        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(old));
                        __asm__("vsub.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
                        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qa));
                    }
                    func_0038CF68_003E7FA8(&d, &d, 1.0f);
                    if (fabs_asm(func_0038CE68_003E7FA8(pl + 0x90, &d)) < 0.75f) {
                        *(s16 *)(st + 0x34) = 0x719;
                        *(f32 *)(st + 0x30) += 0.09f;
                        if (*(f32 *)(cam + 0x2C) - *(f32 *)(st + 0x30) < 0.2f) {
                            *(f32 *)(st + 0x30) = *(f32 *)(cam + 0x2C) - 0.2f;
                        }
                    }
                }
                {
                    vu0_q qa, qb;
                    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(pos));
                    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(sub + 0x50)));
                    __asm__("vsub.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
                    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qa));
                }
                func_0038CF68_003E7FA8(cam, &d, *(f32 *)(cam + 0x2C) - *(f32 *)(st + 0x30));
                func_0038CF68_003E7FA8(&dir, cam, 1.0f);
            }
        }
        sp += *(f32 *)(st + 0x44) * *(f32 *)(st + 0x3C);
        dist += sp;
        func_0038CE20_003E7FA8(&step, &dir, sp * ((*(f32 *)(cam + 0x2C) - *(f32 *)(st + 0x30)) / *(f32 *)(cam + 0x2C)));
        {
            vu0_q qa, qb;
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(pos));
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(step));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(qa));
        }
    }
    if (D_001D545C == 0x30 || D_001D545C == 0x1C) {
        if (flag) {
            q = &D_L01_001DF818_003E7FA8[*(s32 *)(a0 + 0x94)];
            *q &= ~0x20;
        }
    }
    return ret;
}
/* localdecomp:end func_L01_003E7FA8 */

/* localdecomp:start func_L01_003E8360 */
#include "vu0.h"

typedef int q128_003E8360 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003E8360;

typedef struct {
    u8 pad0[0x10];
    V_003E8360 pos; /* 0x10 */
    u8 *p20;
    struct { u8 pad[0x10]; s32 w10; } *p24; /* 0x24 */
    u8 pad28[0x98 - 0x28];
    s32 w98; /* 0x98 */
    u8 pad9C[0xAA - 0x9C];
    s16 hAA; /* 0xAA */
} M_003E8360;

typedef struct {
    u8 pad0[0x50];
    V_003E8360 pos; /* 0x50 */
} C_003E8360;

typedef struct {
    V_003E8360 v; /* 0x00 */
    u8 pad10[0x2C - 0x10];
    f32 f2C; /* 0x2C */
} D_003E8360_003E8360;

typedef struct {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    s16 pad36;
    s16 pad38;
    s16 h3A;
    u8 pad3C[0x4C - 0x3C];
    s16 h4C;
    s16 h4E;
} E_003E8360;

typedef struct {
    u8 pad0[0x60];
    C_003E8360 c;  /* 0x60 */
    u8 padC0[0x180 - 0xC0];
    D_003E8360_003E8360 d;  /* 0x180 */
    u8 pad1B0[0x210 - 0x1B0];
    E_003E8360 e;  /* 0x210 */
} B_003E8360;

typedef struct {
    u8 pad0[0x30];
    V_003E8360 pos; /* 0x30 */
    u8 pad40[0x70 - 0x40];
    B_003E8360 *base; /* 0x70 */
    u8 pad74[0x94 - 0x74];
    s32 idx; /* 0x94 */
} S_003E8360;

typedef struct {
    u8 pad0[0x80];
    V_003E8360 v80; /* 0x80 */
    u8 pad90[0xF0 - 0x90];
    void *pF0; /* 0xF0 */
    u8 padF4[0x100 - 0xF4];
    s32 w100; /* 0x100 */
    u8 pad104[0x11C - 0x104];
    s32 w11C; /* 0x11C */
    u8 pad120[0x12B - 0x120];
    u8 b12B; /* 0x12B */
    u8 pad12C[0x134 - 0x12C];
    struct { u8 pad[0x100]; f32 f100; f32 f104; } *p134; /* 0x134 */
} R_003E8360;

typedef struct {
    u8 pad0[0x20];
    V_003E8360 v20; /* 0x80 */
    V_003E8360 v30; /* 0x90 */
} T_003E8360;

typedef struct {
    u8 pad0[0x54];
    struct { u8 pad[0x86]; s16 h86; } *p54; /* 0x54 */
    u8 pad58[0x60 - 0x58];
    T_003E8360 t;   /* 0x60 */
    u8 padA0[0x150 - 0xA0];
    R_003E8360 r;   /* 0x150 */
    u8 pad290[0x454 - 0x290];
    s32 w454;       /* 0x454 */
    u8 pad458[0x460 - 0x458];
} P_003E8360;

extern u8 D_L01_001E2A40_003E8360[];
extern s32 D_L01_001DF810_003E8360[] __attribute__((section(".sdata")));
extern M_003E8360 *D_L01_001EEA80_003E8360[];
extern M_003E8360 *D_L01_002A41C0_003E8360[];
extern vu0_v4 D_L01_001EAA20_003E8360;
extern f32 D_L01_001DF680_003E8360 __attribute__((section(".sdata")));
extern s32 D_L01_001D7BE0_003E8360;
extern s32 D_001A5EF8_003E8360[];
__asm__(".extern D_L01_001DF680_003E8360, 4");
__asm__(".extern D_L01_001D7BE0_003E8360, 4");

extern void func_0038CDF8_003E8360(void *, void *, void *, f32);
extern s32 func_003D4D00_003E8360(void *, s32, void *, void *, f32);
extern void func_L01_003E8F20(s32, f32, f32, f32);
extern s32 func_L01_00446720(char *);
extern f32 func_0038CE68_003E8360(void *, void *);
extern void func_0038CE20_003E8360(void *, void *, f32);
extern void func_0038CF68_003E8360(void *, void *, f32);
extern f32 func_0038D0C8_003E8360(f32);
extern void func_0038CE90_003E8360(void *, void *, void *);
extern void func_0038D890_003E8360(void *, void *, void *, f32);
extern s32 func_L01_003E7FA8(u8 *);
extern s32 func_L01_003E7AA0_003E8360(void *);
extern s32 func_L01_003E77B0_003E8360(void *);
extern s32 func_0038CB00_003E8360(void *);
extern f32 func_003C3BE8_003E8360(f32, f32, f32);
extern s32 func_003D3CB0_003E8360(void *, void *, s32, void *, s32);
extern s32 func_L01_003E4168(void *);
extern void func_L01_003F5AC0(s32, s32);
extern f32 func_0038CEA8_003E8360(void *);

void func_L01_003E8360(u8 *a0) {
    S_003E8360 *self = (S_003E8360 *)a0;
    V_003E8360 v0;
    V_003E8360 v10;
    V_003E8360 v20;
    V_003E8360 v30;
    V_003E8360 v40;
    P_003E8360 *p = &((P_003E8360 *)D_L01_001E2A40_003E8360)[self->idx];
    B_003E8360 *base = self->base;
    R_003E8360 *r = &p->r;
    C_003E8360 *c = &base->c;
    E_003E8360 *e;
    D_003E8360_003E8360 *d = &base->d;
    T_003E8360 *t;
    f32 len;
    s32 flag = 0;
    s32 nsaved = 0;
    s32 n;
    s32 i;
    s32 j;
    f32 x;
    s32 set;
    f32 dist;

    e = &base->e;
    t = &p->t;
    len = d->f2C - e->f30 + 1.5f;

    func_0038CDF8_003E8360(&v0, &c->pos, p, 0.5f);
    n = func_003D4D00_003E8360(&v0, 1, r->pF0, 0, len * 0.5f);
    if (n > 0) {
        for (i = 0; i < n; i++) {
            M_003E8360 *m = D_L01_001EEA80_003E8360[i];
            if (m->hAA == 0x191F || m->hAA == 0x1920) {
                func_L01_003E8F20(self->idx, -1.0f, -1.0f, D_L01_001DF680_003E8360);
            }
            if (m->w98 != 0 && (!func_L01_00446720((char *)m) || m->hAA == 0xB6B)) {
                if (m->hAA != 0x477 && m->hAA != 0xB && m->hAA != 0x1AD6 && m->hAA != 0x1ADA &&
                    m->hAA != 0x1944 && m->hAA != 0x18DE && m->hAA != 0x1F89 && m->hAA != 0x1CAA &&
                    m->hAA != 0x109E && m->hAA != 0x109F) {
                    D_L01_002A41C0_003E8360[nsaved++] = m;
                    m->w98 = 0;
                } else {
                    vec_sub_ab(&v10, &m->pos, &c->pos);
                    func_0038CE20_003E8360(&v20, &t->v30, func_0038CE68_003E8360(&t->v30, &v10));
                    vec_sub_ab(&v30, &v10, &v20);
                    func_0038CF68_003E8360(&v30, &v30, 1.0f);
                    if (fabs_asm(1.5707964f - func_0038D0C8_003E8360(func_0038CE68_003E8360(&v30, d) / (d->f2C - e->f30))) < 0.43633232f) {
                        func_0038CE90_003E8360(&v40, d, &t->v30);
                        func_0038CF68_003E8360(&v40, &v40, 1.0f);
                        if (func_0038CE68_003E8360(&v40, &v10) > 0.0f) {
                            func_0038D890_003E8360(d, d, &t->v20, -0.017453292f);
                        } else {
                            func_0038D890_003E8360(d, d, &t->v20, 0.017453292f);
                        }
                    }
                }
            }
        }
    }

    if (e->h4E == 0) {
        if (func_L01_003E7FA8((u8 *)self)) {
            flag = 1;
        }
        if (func_L01_003E7AA0_003E8360(self)) {
            flag = 1;
        }
    }
    if (func_L01_003E77B0_003E8360(self)) {
        flag = 1;
    }
    x = d->f2C;
    if (x - e->f30 < 1.5f) {
        e->h34 = 0x683;
        e->f30 = x - 1.5f;
    }
    if (p->p54 != 0 && (p->p54->h86 == 4 || p->p54->h86 == 0x51)) {
        if (p->w454 < 8) {
            e->h34 = 0x589;
        }
    }
    if (e->h3A != 0 || (!flag && ((e->h34 > 0 && e->h34 < 0x683) ||
                                 (r->p134->f100 < 0.3f && r->p134->f104 < 0.3f)))) {
        if (func_0038CB00_003E8360(&e->h34)) {
            e->h3A = 0;
        }
        if (e->h3A != 0) {
            if (func_0038CB00_003E8360(&e->h34)) {
                e->h3A = 0;
            }
        }
        e->f30 = func_003C3BE8_003E8360(0.0f, e->f30, (f32)e->h34 / 1667.0f);
    } else {
        if (e->h34 >= 0x684) {
            func_0038CB00_003E8360(&e->h34);
        } else {
            e->h34 = 0x683;
        }
    }
    func_0038CF68_003E8360(d, d, d->f2C - e->f30);

    set = 0;
    vec_add_ab(&v10, d, &c->pos);
    if (!(D_L01_001DF810_003E8360[self->idx] & 0x20)) {
        D_L01_001DF810_003E8360[self->idx] |= 0x20;
        set = 1;
    }
    if (r->w100 != 0x31 && D_L01_001D7BE0_003E8360 == -1 && e->h4E == 0 &&
        func_003D3CB0_003E8360(&c->pos, &v10, D_L01_001DF810_003E8360[self->idx], r->pF0, 0) &&
        !func_L01_003E4168(&D_L01_001EAA20_003E8360)) {
        if (++e->h4C >= 25) {
            func_L01_003F5AC0(self->idx, 1);
        }
    } else {
        e->h4C = 0;
    }

    vec_sub_ba(&v30, &self->pos, &v10);
    dist = func_0038CEA8_003E8360(&v30);
    vec_sub_ab(&v20, &self->pos, &c->pos);
    func_0038CF68_003E8360(&v20, &v20, 1.0f);
    if ((30.0f < dist && p->w454 >= 9) ||
        (!r->b12B && (D_L01_001D7BE0_003E8360 == -1 || D_001A5EF8_003E8360[0] != 3) && r->w11C > 0 && func_0038CE68_003E8360(&v20, &r->v80) > 0.0f && dist < 20.0f &&
         func_003D3CB0_003E8360(&self->pos, &v10, D_L01_001DF810_003E8360[self->idx], r->pF0, 0))) {
        func_L01_003F5AC0(self->idx, 0);
    }
    if (set) {
        D_L01_001DF810_003E8360[self->idx] &= ~0x20;
    }
    for (j = 0; j < nsaved; j++) {
        D_L01_002A41C0_003E8360[j]->w98 = D_L01_002A41C0_003E8360[j]->p24->w10;
    }
}
/* localdecomp:end func_L01_003E8360 */

/* localdecomp:start func_L01_003E8AD8 */
extern Entry_3E6C58 D_L01_001E2A40[];
s32 func_L01_003E8AD8(u8 *a0) {
    Entry_3E6C58 *e = D_L01_001E2A40;
    u8 *p = e[*(s32 *)(a0 + 148)].p50;
    if (*(s16 *)(p + 134)) {
        return -1;
    }
    p = *(u8 **)(p + 112);
    if (*(u8 **)(p + 608) == a0) {
        *(s32 *)(p + 608) = 0;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_003E8AD8 */

/* localdecomp:start func_L01_003E8B28 */
extern Entry_3E6C58 D_L01_001E2A40[];
extern M_3E6CA8 *D_L01_001DF804;
s32 func_L01_003E8B28(u8 *a0) {
    Entry_3E6CA8 *e = ((Entry_3E6CA8 *)&D_L01_001E2A40);
    u8 *q = e[*(s32 *)(a0 + 148)].p50;
    u8 *p;
    u8 *cur;
    if (*(s16 *)(q + 134)) {
        return -1;
    }
    p = *(u8 **)(q + 112);
    cur = *(u8 **)(p + 608);
    if (cur == 0) {
        *(u8 **)(p + 608) = a0;
        return 1;
    }
    if (cur == a0) {
        return 1;
    }
    if (D_L01_001DF804[*(s16 *)(cur + 132)].p1C[28] < D_L01_001DF804[*(s16 *)(a0 + 132)].p1C[28]) {
        *(u8 **)(p + 608) = a0;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_003E8B28 */

/* localdecomp:start func_L01_003E8BD0 */
extern Entry_3E6C58 D_L01_001E2A40[];
void func_L01_003E8BD0(s32 player, s32 both, f32 distance, f32 gain) {
    u8 *e = ((u8 *)&D_L01_001E2A40) + player * 1120;
    u8 *o = *(u8 **)(e + 80);
    if (*(s16 *)(o + 134) == 0) {
        u8 *p = *(u8 **)(o + 112) + 0x180;
        *(s16 *)(p + 0x3C) = 1;
        *(f32 *)(p + 0x48) = gain;
        *(f32 *)(p + 0x40) = distance;
        if (both) {
            *(f32 *)(p + 0x58) = distance;
        }
    }
}
/* localdecomp:end func_L01_003E8BD0 */

/* localdecomp:start func_L01_003E8C28 */
extern Entry_3E6C58 D_L01_001E2A40[];
void func_L01_003E8C28(s32 player, f32 height, f32 gain) {
    u8 *e = ((u8 *)&D_L01_001E2A40) + player * 1120;
    u8 *o = *(u8 **)(e + 80);
    if (*(s16 *)(o + 134) == 0) {
        u8 *p = *(u8 **)(o + 112) + 0x180;
        *(s16 *)(p + 0x3E) = 1;
        *(f32 *)(p + 0x4C) = height;
        *(f32 *)(p + 0x54) = gain;
    }
}
/* localdecomp:end func_L01_003E8C28 */

/* localdecomp:start func_L01_003E8C70 */
extern u8 D_L01_001E50D0[];

void func_L01_003E8C70(s32 idx, s32 flag, f32 a, f32 b)
{
    u8 *e = (u8 *)D_L01_001E2A40 + idx * 0x460;
    u8 *p = *(u8 **)(e + 0x50);

    if (*(s16 *)(p + 134) == 0) {
        u8 *q = *(u8 **)(p + 112);
        u8 *r = q + 0x60;

        *(s16 *)(r + 0xFA) = 1;
        *(f32 *)(r + 0xD8) = b;
        if (flag) {
            u8 *f = (u8 *)D_L01_001E50D0 + idx * 0xB0;
            u8 *s = *(u8 **)(f + 0x70);
            *(f32 *)(r + 0xD4) = *(f32 *)(s + 0x130) + a;
        } else {
            *(f32 *)(r + 0xD4) = a;
        }
    }
}
/* localdecomp:end func_L01_003E8C70 */

/* localdecomp:start func_L01_003E8CE0 */
extern Entry_3E6C58 D_L01_001E2A40[];
void func_L01_003E8CE0(s32 a0, f32 a, f32 b, f32 c) {
    u8 *e = ((u8 *)&D_L01_001E2A40) + a0 * 1120;
    u8 *p = *(u8 **)(e + 80);
    if (*(s16 *)(p + 134) == 0) {
        u8 *q = *(u8 **)(p + 112);
        u8 *r = q + 32;

        *(f32 *)(r + 44) = a;
        *(f32 *)(r + 52) = b * 0.0174532925f * 0.0004000000189f;
        *(f32 *)(r + 56) = c * 0.0174532925f * 0.0004000000189f;
    }
}
/* localdecomp:end func_L01_003E8CE0 */

/* localdecomp:start func_L01_003E8D48 */
extern Entry_3E6C58 D_L01_001E2A40[];
void func_L01_003E8D48(s32 a0, f32 a) {
    u8 *e = ((u8 *)&D_L01_001E2A40) + a0 * 1120;
    u8 *p = *(u8 **)(e + 80);
    if (*(s16 *)(p + 134) == 0) {
        u8 *q = *(u8 **)(p + 112);
        *(f32 *)(q + 0x204) = a;
    }
}
/* localdecomp:end func_L01_003E8D48 */

/* localdecomp:start func_L02_003C1360 */
extern u8 D_L02_001E1300[];
void func_L02_003C1360(s32 a0, f32 a) {
    u8 *e = D_L02_001E1300 + a0 * 1120;
    u8 *o = *(u8 **)(e + 80);

    if (*(s16 *)(o + 134) == 0) {
        *(f32 *)(*(u8 **)(o + 112) + 620) = a;
    }
}
/* localdecomp:end func_L02_003C1360 */

/* localdecomp:start func_L01_003E8D80 */
extern Entry_3E6C58 D_L01_001E2A40[];
void func_L01_003E8D80(s32 a0, s32 a) {
    u8 *e = ((u8 *)&D_L01_001E2A40) + a0 * 1120;
    u8 *o = *(u8 **)(e + 80);
    if (*(s16 *)(o + 134) == 0) {
        *(s16 *)(*(u8 **)(o + 112) + 0x10) = a;
    }
}
/* localdecomp:end func_L01_003E8D80 */

/* localdecomp:start func_L01_003E8DB8 */
extern Entry_3E6C58 D_L01_001E2A40[];
void func_L01_003E8DB8(s32 a0, f32 a, f32 b) {
    u8 *e = ((u8 *)&D_L01_001E2A40) + a0 * 1120;
    u8 *o = *(u8 **)(e + 80);
    u8 *p;
    if (*(s16 *)(o + 134) != 0) {
        return;
    }
    p = *(u8 **)(o + 112) + 0x60;
    if (a != 0.0f) {
        *(f32 *)(p + 0xFC) = a;
    }
    if (b != 0.0f) {
        *(f32 *)(p + 0x100) = b;
    }
}
/* localdecomp:end func_L01_003E8DB8 */

/* localdecomp:start func_L01_003E8E10 */
void func_L01_003E8E10(s32 player, f32 spring, f32 damping) {
    Entry_3E6C58 *e = &D_L01_001E2A40[player];
    u8 *p = e->p50;
    u8 *q;

    if (*(s16 *)(p + 0x86) == 0) {
        q = *(u8 **)(p + 0x70) + 0x60;
        if (spring != 0.0f) {
            *(f32 *)(q + 0x104) = spring;
        }
        if (damping != 0.0f) {
            *(f32 *)(q + 0x108) = damping;
        }
    }
}
/* localdecomp:end func_L01_003E8E10 */


/* localdecomp:start func_L01_003E8E70 */
extern Entry_3E6C58 D_L01_001E2A40[];
void func_L01_003E8E70(s32 player) {
    u8 *e = ((u8 *)&D_L01_001E2A40) + player * 1120;
    u8 *o = *(u8 **)(e + 80);
    if (*(s16 *)(o + 134) == 0) {
        *(s16 *)(*(u8 **)(o + 112) + 0x266) = 1;
    }
}
/* localdecomp:end func_L01_003E8E70 */

/* localdecomp:start func_L01_003E8EA8 */
extern Entry_3E6C58 D_L01_001E2A40[];
void func_L01_003E8EA8(s32 player) {
    u8 *e = ((u8 *)&D_L01_001E2A40) + player * 1120;
    u8 *o = *(u8 **)(e + 80);
    if (*(s16 *)(o + 134) == 0) {
        *(u8 *)(*(u8 **)(o + 112) + 0x159) = 1;
    }
}
/* localdecomp:end func_L01_003E8EA8 */

/* localdecomp:start func_L01_003E8EE8 */
extern Entry_3E6C58 D_L01_001E2A40[];
void func_L01_003E8EE8(s32 a0, s32 a) {
    u8 *e = ((u8 *)&D_L01_001E2A40) + a0 * 1120;
    u8 *o = *(u8 **)(e + 80);
    if (*(s16 *)(o + 134) == 0) {
        *(s32 *)(*(u8 **)(o + 112) + 0x258) = a;
    }
}
/* localdecomp:end func_L01_003E8EE8 */

/* localdecomp:start func_L01_003E8F20 */
void func_L01_003E8F20(s32 idx, f32 x, f32 y, f32 z) {
    Entry_3E6C58 *e = (Entry_3E6C58 *)((u8 *)D_L01_001E2A40 + idx * 1120);
    Q_003E8F20 *q = (Q_003E8F20 *)e->p50;
    u8 *p;

    if (q->h86 != 0) {
        return;
    }
    p = q->x70 + 0x210;
    if (x != -1.0f) {
        *(f32 *)(p + 0x3C) = x;
    }
    if (y != -1.0f) {
        *(f32 *)(p + 0x40) = y;
    }
    if (z != -1.0f) {
        *(f32 *)(p + 0x44) = z;
    }
}
/* localdecomp:end func_L01_003E8F20 */

/* localdecomp:start func_L01_003E8F90 */
extern Entry_3E6C58 D_L01_001E2A40[];
void func_L01_003E8F90(s32 player, s32 axes) {
    u8 *e = ((u8 *)&D_L01_001E2A40) + player * 1120;
    u8 *o = *(u8 **)(e + 80);
    if (*(s16 *)(o + 134) == 0) {
        u8 *p = *(u8 **)(o + 112) + 0x1E0;
        if (axes == -1) {
            *(u32 *)(p + 0x10) |= 3;
        } else {
            *(u32 *)(p + 0x10) |= axes;
        }
    }
}
/* localdecomp:end func_L01_003E8F90 */

/* localdecomp:start func_L01_003E8FE8 */
#include "vu0.h"
typedef struct { u8 pad[0x20]; f32 up[4]; u8 pad2[1120 - 0x30]; } Ent_3E8FE8;
extern Ent_3E8FE8 D_L01_001E2AA0_3E8FE8[];
extern f32 func_0038CE68(f32 *, f32 *);
extern void func_0038CE20(f32 *, f32 *, f32);
extern f32 func_0038CEA8(f32 *);
extern void func_0038CE90(f32 *, f32 *, f32 *);
extern f32 func_0038D0C8(f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_L01_004451D0(f32, f32, f32, f32, f32);
f32 func_L01_003E8FE8(u8 *obj, f32 *vec, f32 limit) {
    f32 proj[4] __attribute__((aligned(16)));
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    u8 *follow = *(u8 **)(obj + 0x70);
    u8 *springs = follow + 0x180;
    u8 *stick = follow + 0x1E0;
    Ent_3E8FE8 *ent = &D_L01_001E2AA0_3E8FE8[*(s32 *)(obj + 0x94)];
    f32 *up;
    f32 dot, len_a, len_b, angle, sign, s;
    f32 turn = 0.0f;
    up = ent->up;
    func_0038CE20(proj, up, func_0038CE68(vec, up));
    vec_sub_ba((vu0_v4 *)a, (vu0_v4 *)vec, (vu0_v4 *)proj);
    func_0038CE20(proj, up, func_0038CE68((f32 *)springs, up));
    vec_sub_ba((vu0_v4 *)b, (vu0_v4 *)springs, (vu0_v4 *)proj);
    dot = func_0038CE68(a, b);
    len_a = func_0038CEA8(a);
    if (len_a == 0.0f) return turn;
    len_b = func_0038CEA8(b);
    len_a = len_a * len_b;
    if (len_a == 0.0f) return turn;
    angle = 1.5707964f - func_0038D0C8(dot / len_a);
    sign = -1.0f;
    func_0038CE90(c, a, up);
    if (0.0f <= func_0038CE68(c, b)) sign = 1.0f;
    turn = func_0038DB00(3.1415927f, angle);
    if (limit != 0.0f && limit < __builtin_fabsf(turn)) return turn;
    s = func_L01_004451D0(-1.0f, 0.0f, 1.0f, 0.0f, turn / 1.5707964f);
    if (1.0f < s) s = 1.0f;
    *(f32 *)(stick + 0x1C) = s * sign;
    return turn;
}
/* localdecomp:end func_L01_003E8FE8 */

/* localdecomp:start func_L01_003E9218 */
#include "vu0.h"
extern void func_L01_003E8FE8_003E9218(u8 *, vu0_v4 *);
void func_L01_003E9218(u8 *camera, vu0_v4 *position) {
    vu0_v4 d;
    vec_sub_ab(&d, position, *(u8 **)(camera + 0x70) + 0x60);
    func_L01_003E8FE8_003E9218(camera, &d);
}
/* localdecomp:end func_L01_003E9218 */

/* localdecomp:start func_L01_003E9250 */
extern Entry_3E6C58 D_L01_001E2A40[];
extern void func_L01_003E8FE8_003E9250(u8 *a0, f32 f12);
void func_L01_003E9250(s32 a0, f32 a, f32 b) {
    u8 *e = ((u8 *)&D_L01_001E2A40) + a0 * 1120; u8 *o = *(u8 **)(e + 80);
    if (*(s16 *)(o + 134) == 0 && a != 0.0f) {
        *(f32 *)(*(u8 **)(o + 112) + 500) = a;
        func_L01_003E8FE8_003E9250(o, b);
    }
}
/* localdecomp:end func_L01_003E9250 */

/* localdecomp:start func_L01_003E92B0 */
extern Entry_3E6C58 D_L01_001E2A40[];
extern void func_L01_003E9218_003E92B0(u8 *, f32);
void func_L01_003E92B0(s32 i, f32 a, f32 b) {
    u8 *p = (((S_003E7430 *)&D_L01_001E2A40) + i)->p;
    if (*(s16 *)(p + 134) == 0) {
        *(f32 *)(*(u8 **)(p + 112) + 500) = a;
        func_L01_003E9218_003E92B0(p, b);
    }
}
/* localdecomp:end func_L01_003E92B0 */

/* localdecomp:start func_L01_003E92F8 */
extern u8 D_L01_001E2B90[];
extern f32 D_L01_001D5FF0[2];
extern Pad_003E92F8 D_143A70[];
extern s32 D_143A10[][8];
extern u8 D_1439F4[];
extern s32 D_001D4C38;
extern s32 D_001D545C;
extern Counter_003E92F8 D_1A7C10;
__asm__(".extern D_L01_001DF674, 4");
__asm__(".extern D_L01_001DF678, 4");
extern s32 D_L01_001DF674;
extern s32 D_L01_001DF678;

void func_L01_003E92F8(u8 *obj, f32 *x, f32 *y)
{
    Input_003E92F8 *t = (Input_003E92F8 *)(*(u8 **)(obj + 0x70) + 0x1E0);
    Ent_003E92F8 *e = (Ent_003E92F8 *)(D_L01_001E2B90 + *(s32 *)(obj + 0x94) * 0x460);
    Counter_003E92F8 *c;
    u32 n;
    s32 cnt;
    s32 k = 0;

    if (t->flags & 1) {
        *x = 0.0f;
    } else {
        *x = e->p134[0x100 / 4];
        if (D_143A70[D_1439F4[0]].v == 0)
            *x = -*x;
    }
    if (*x == 0.0f) {
        D_L01_001DF674 = 0;
        D_L01_001DF678 = 0;
        if (t->f1C != 0.0f)
            *x = t->f1C;
    } else {
        cnt = D_L01_001DF674 + 1;
        t->f14 = D_L01_001D5FF0[*(s32 *)(obj + 0x94)];
        D_L01_001DF674 = cnt;
        if (D_L01_001DF678 == 0 && cnt > 0xC) {
            c = &D_1A7C10;
            if (c->count < 0xFFFF)
                c->count++;
            n = (D_001D4C38 * 5 + 2) / 6;
            if (c->best < n)
                c->best = n;
            c->flags = (c->flags | (1 << D_001D545C)) | 0x80000000;
            D_L01_001DF678 = 1;
        }
    }
    if (t->flags & 2) {
        *y = 0.0f;
        *y = t->f24 / 0.6981317f;
    } else {
        f32 v = e->p134[0x104 / 4];
        *y = -v;
        if (D_143A10[D_1439F4[0]][k] == 0)
            *y = v;
        if (*y == 0.0f)
            *y = t->f24 / 0.6981317f;
    }
}
/* localdecomp:end func_L01_003E92F8 */

/* localdecomp:start func_L01_003E9500 */
/* fabs is the game's fabs_asm (include/vu0.h) at every site of this file. */
#include "vu0.h"
extern u8 D_L01_001E2AA0[];
extern f32 D_L01_001DF6C8[2];
extern s32 D_001D52F4;
extern f32 func_00382BC8(f32 *, f32, f32, f32, f32, f32);
extern void func_0038D890(f32 *, f32 *, f32 *, f32);
extern f32 func_0038CE68(f32 *, f32 *);
extern f32 func_0038CEA8(f32 *);
extern void func_0038CE90(f32 *, f32 *, f32 *);
extern void func_0038CF68(f32 *, f32 *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);

void func_L01_003E9500(u8 *moby, f32 a, f32 b)
{
    f32 v[4];
    u8 *m;
    u8 *p;
    u8 *q;
    u8 *t;
    f32 *w;
    f32 zero;
    f32 lim;
    f32 ang;
    f32 x;
    f32 f2;

    zero = 0.0f;
    m = *(u8 **)(moby + 112);
    q = m + 480;
    p = m + 384;
    t = D_L01_001E2AA0 + *(s32 *)(moby + 148) * 1120;
    x = *(f32 *)(q + 20);
    *(f32 *)(m + 480) = func_00382BC8((f32 *)(m + 484), *(f32 *)(m + 480), a, 2.0f, 4.0f, zero);
    x = x * *(f32 *)(m + 480);
    *(f32 *)(p + 52) = x;
    if (b < -0.3f) {
        b = (b + 0.3f) * 1.4285715f;
    } else if (0.3f < b) {
        b = (b - 0.3f) * 1.4285715f;
    } else {
        b = zero;
    }
    if (b == 0.0f || (f2 = *(f32 *)(q + 8), fabs_asm(b) < fabs_asm(f2) && ((0.0f < b && 0.0f < f2) || (b < 0.0f && f2 < 0.0f)))) {
        lim = 0.01f;
    } else {
        lim = 0.02f;
    }
    *(f32 *)(q + 8) = func_00382BC8((f32 *)(q + 12), *(f32 *)(q + 8), b, 2.0f, 4.0f, lim);
    ang = *(f32 *)(q + 8) * 0.6981317f;
    if (a == 0.0f) {
        func_0038D890((f32 *)p, (f32 *)p, (f32 *)(t + 32), *(f32 *)(q + 32));
        w = (f32 *)(t + 32);
    } else {
        w = (f32 *)(t + 32);
        func_0038D890((f32 *)p, (f32 *)p, w, *(f32 *)(p + 52));
    }
    b = func_0038CE68((f32 *)p, w);
    x = func_0038CEA8((f32 *)p);
    func_0038CE90(v, w, (f32 *)p);
    func_0038CF68(v, v, 1.0f);
    x = func_0038D160(x, b);
    if (fabs_asm(x) < fabs_asm(ang) && lim == 0.01f) {
        *(f32 *)(q + 8) = x / 0.6981317f;
    }
    if (x < ang) {
        if (ang < func_0038DAB8(x, D_L01_001DF6C8[D_001D52F4])) {
            *(f32 *)(p + 56) = func_0038DB00(ang, x);
        } else {
            *(f32 *)(p + 56) = D_L01_001DF6C8[D_001D52F4];
        }
    } else if (ang < x) {
        if (*(s16 *)(*(u8 **)(moby + 112) + 584) < 0) {
            *(f32 *)(p + 56) = 0.0f;
        } else if (func_0038DAB8(x, -D_L01_001DF6C8[D_001D52F4]) < ang) {
            *(f32 *)(p + 56) = func_0038DB00(ang, x);
        } else {
            *(f32 *)(p + 56) = -D_L01_001DF6C8[D_001D52F4];
        }
    } else {
        *(f32 *)(p + 56) = 0.0f;
    }
    if (ang < 0.0f) {
        *(s16 *)(*(u8 **)(moby + 112) + 34) = 1;
    }
    func_0038D890((f32 *)p, (f32 *)p, v, *(f32 *)(p + 56));
}
/* localdecomp:end func_L01_003E9500 */

INCLUDE_ASM("asm/levels", func_L01_003E9908);

INCLUDE_ASM("asm/levels", func_L01_003E99E8);

/* localdecomp:start func_L01_003E9F40 */
typedef struct {
    u8 pad0[0x60];
    u8 motion[0xF0];  /* 0x060: +0x80 the hero's move, +0xA4 his speed */
    u8 hero[0x310];   /* 0x150: the camera's copy of the hero */
} Camera_003E9F40;
extern Entry_3E6C58 D_L01_001E2A40[];
extern f32 func_0038CE68(f32 *, f32 *); /* the dot product */
extern void func_L01_003E8BD0(s32, s32, f32, f32);

/* camera_approach_distance: the hero moving against the camera's facing (dot < -0.3):
   distance target up to 6.0 by speed (full at 0.07 u/frame), and a stiffer arm spring. */
void func_L01_003E9F40(u8 *update, f32 *gain, f32 *damping) {
    u8 *follow = *(u8 **)(update + 0x70);
    u8 *approach = follow + 0x260;
    u8 *springs = follow + 0x180;
    s32 player = *(s32 *)(update + 0x94);
    u8 *motion = ((Camera_003E9F40 *)D_L01_001E2A40)[player].motion;
    u8 *hero = ((Camera_003E9F40 *)D_L01_001E2A40)[player].hero;
    f32 share;
    f32 far;
    f32 distance;

    if (*(s16 *)(approach + 6) == 0) {
        if ((*(s16 *)(approach + 4) != 0 && *(f32 *)(motion + 0xA4) == 0.0f &&
             func_0038CE68((f32 *)(*(u8 **)(hero + 0xF0) + 0xC0), (f32 *)update) <= -0.3f) ||
            (fabs_asm(*(f32 *)(motion + 0xA4)) > 0.0001f &&
             func_0038CE68((f32 *)(motion + 0x80), (f32 *)update) <= -0.3f)) {
            *(s16 *)(approach + 4) = 100;
            /* full at 0.07 u a frame */
            share = *(f32 *)(motion + 0xA4) * 14.2857f;
            if (share > 1.0f) {
                share = 1.0f;
            }
            far = 4.0f;
            if (hero[0x12B] != 1) {
                far = *(f32 *)(approach + 0xC);
            }
            distance = *(f32 *)(springs + 0x58) + (far - *(f32 *)(springs + 0x58)) * share;
            if (distance > *(f32 *)(approach + 8)) {
                *(f32 *)(approach + 8) = distance;
            }
            func_L01_003E8BD0(*(s32 *)(update + 0x94), 0, *(f32 *)(approach + 8), 0.003f);
            *gain = share * 0.02f + 0.02f;
            *damping = share * 0.100000009f + 0.2f;
            return;
        }
    }
    if (*(s16 *)(approach + 4) != 0) {
        *(s16 *)(approach + 4) = 0;
        *(f32 *)(approach + 8) = *(f32 *)(springs + 0x58);
    }
    if (*(s32 *)(hero + 0x100) == 0x89) {
        *gain = 0.04f;
        *damping = 0.2f;
    } else {
        *gain = 0.02f;
        *damping = 0.2f;
    }
}
/* localdecomp:end func_L01_003E9F40 */

/* localdecomp:start func_L01_003EA190 */
#include "vu0.h"
typedef int Q_003EA190 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003EA190;
typedef struct {
    u8 pad0[0x460];
} Ent_003EA190;

extern Ent_003EA190 D_L01_001E2AA0_003EA190[];
extern V4_003EA190 D_L01_001EAA30_003EA190;
extern f32 func_0038CEA8_003EA190(void *);
extern f32 func_0038CE68_003EA190(void *, void *);
extern void func_0038CE20_003EA190(void *, void *, f32);
extern void func_0038CE90_003EA190(void *, void *, void *);
extern void func_0038D890_003EA190(void *, void *, void *, f32);
extern void func_0038CF68_003EA190(void *, void *, f32);
extern f32 func_0038D0C8_003EA190(f32);
extern void func_L01_003E9F40(u8 *, f32 *, f32 *);
extern f32 func_00382BC8_003EA190(f32, f32 *, f32, f32, f32, f32);
extern f32 func_00382C58(f32 *, f32, f32, f32, f32, f32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);

void func_L01_003EA190(u8 *a)
{
    V4_003EA190 v0;
    V4_003EA190 v10;
    V4_003EA190 v20;
    V4_003EA190 v30;
    V4_003EA190 v40;
    V4_003EA190 v50;
    V4_003EA190 v60;
    V4_003EA190 v70;
    V4_003EA190 old;
    V4_003EA190 d;
    f32 fa;
    f32 fb;
    u8 *ent = (u8 *)&D_L01_001E2AA0_003EA190[*(s32 *)(a + 0x94)];
    u8 *st = (u8 *)D_L01_001E2AA0_003EA190 + 0xF0 + *(s32 *)(a + 0x94) * 0x460;
    u8 *cam = *(u8 **)(a + 0x70);
    u8 *c180;
    u8 *c60;
    f32 len1, len2, dot1, dot2;
    f32 ang1;
    f32 ang2;
    f32 r2;
    f32 t;
    f32 zero;
    f32 sgn;
    f32 dd, ll, ang3;
    f32 side;
    s32 i;
    s32 hit;

    c180 = cam + 0x180;
    {
        Q_003EA190 qt, qd;
        __asm__("lqc2 %0, %1" : "=j"(qt) : "m"(*(V4_003EA190 *)(cam + 0xB0)));
        __asm__("lqc2 %0, %1" : "=j"(qd) : "m"(*(V4_003EA190 *)(cam + 0x180)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qt) : "0"(qt), "j"(qd));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_003EA190 *)(cam + 0x0)) : "j"(qt));
    }
    c60 = cam + 0x60;
    len1 = func_0038CEA8_003EA190(c180);
    len2 = func_0038CEA8_003EA190(cam + 0x190);
    func_L01_003E9F40(a, &fa, &fb);
    len2 = func_00382BC8_003EA190(len2, (f32 *)(cam + 0x1A8), len1, fa, fb, 0.0f);
    dot1 = func_0038CE68_003EA190(c180, (ent + 0x20));
    if (fabs_asm(len1) < 0.0001f) {
        ang1 = 0.0f;
    } else {
        t = dot1 / len1;
        if (t > 1.0f) {
            t = 1.0f;
        } else if (t < -1.0f) {
            t = -1.0f;
        }
        ang1 = func_0038D0C8_003EA190(t);
    }
    dot2 = func_0038CE68_003EA190(c180 + 0x10, (ent + 0x20));
    if (fabs_asm(len2) < 0.0001f) {
        ang2 = 0.0f;
    } else {
        t = dot2 / len2;
        if (t > 1.0f) {
            t = 1.0f;
        } else if (t < -1.0f) {
            t = -1.0f;
        }
        ang2 = func_0038D0C8_003EA190(t);
    }
    zero = 0.0f;
    ang2 = func_00382C58((f32 *)(c180 + 0x24), ang2, ang1, 0.015f, 0.2f, zero);
    func_0038CE20_003EA190(&v0, (ent + 0x20), dot1);
    vec_sub_ba(&v10, c180, &v0);
    func_0038CE20_003EA190(&v20, (ent + 0x20), dot2);
    vec_sub_ba(&v30, c180 + 0x10, &v20);
    dd = func_0038CE68_003EA190(&v10, &v30);
    ll = func_0038CEA8_003EA190(&v10) * func_0038CEA8_003EA190(&v30);
    if (ll < 0.0001f) {
        ang3 = zero;
    } else {
        ang3 = 1.5707964f - func_0038D0C8_003EA190(dd / ll);
    }
    r2 = func_00382C58((f32 *)(c180 + 0x20), 0.0f, ang3, 0.015f, 0.2f, 0.0f);
    func_0038CE90_003EA190(&v40, &v30, (ent + 0x20));
    side = func_0038CE68_003EA190(&v40, &v10);
    sgn = -1.0f;
    if (side >= 0.0f) {
        sgn = 1.0f;
    }
    func_0038D890_003EA190(&v50, &v30, (ent + 0x20), r2 * sgn);
    hit = 0;
    func_0038CE90_003EA190(&v40, (ent + 0x20), &v50);
    func_0038D890_003EA190(&v50, &v50, &v40, ang2);
    func_0038CF68_003EA190(c180 + 0x10, &v50, len2);
    func_0038CE20_003EA190(&v60, (ent + 0x20), *(f32 *)(c180 + 0x30));
    vec_add_ba(&v70, &v60, c60 + 0x60);
    vec_add_ba(a + 0x30, &v70, c180 + 0x10);
    old = *(V4_003EA190 *)(a + 0x30);
    for (i = 0; i < 3; i++) {
        if (func_L01_003FB640(a + 0x30, 0x36, 0, 0.25f)) {
            *(V4_003EA190 *)(a + 0x30) = D_L01_001EAA30_003EA190;
            hit = 1;
        } else {
            break;
        }
    }
    if (hit) {
        vec_sub_ba(&d, a + 0x30, &old);
        {
            Q_003EA190 qt, qd;
            __asm__("lqc2 %0, %1" : "=j"(qt) : "m"(*(V4_003EA190 *)(c60 + 0x0)));
            __asm__("lqc2 %0, %1" : "=j"(qd) : "m"(d));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qt) : "0"(qt), "j"(qd));
            __asm__("sqc2 %1, %0" : "=m"(*(V4_003EA190 *)(c60 + 0x0)) : "j"(qt));
        }
        vec_add_ba(c60 + 0x60, c60 + 0x60, &d);
        {
            Q_003EA190 qt, qd;
            __asm__("lqc2 %0, %1" : "=j"(qt) : "m"(*(V4_003EA190 *)(c60 + 0xB0)));
            __asm__("lqc2 %0, %1" : "=j"(qd) : "m"(d));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qt) : "0"(qt), "j"(qd));
            __asm__("sqc2 %1, %0" : "=m"(*(V4_003EA190 *)(c60 + 0xB0)) : "j"(qt));
        }
        vec_add_ab(c60 + 0x30, c60 + 0x30, &d);
    }
}
/* localdecomp:end func_L01_003EA190 */

/* localdecomp:start func_L01_003EA648 */
extern void func_L01_003E9908(u8 *);
extern void func_L01_003E92F8(u8 *, f32 *, f32 *);
extern void func_L01_003E9500(u8 *, f32, f32);
extern void func_L01_003E8360(u8 *);
extern void func_L01_003EA190(u8 *);
extern void func_L01_003E99E8(u8 *);

void func_L01_003EA648(u8 *a0) {
    f32 v[2];

    func_L01_003E9908(a0);
    func_L01_003E92F8(a0, &v[0], &v[1]);
    func_L01_003E9500(a0, v[0], v[1]);
    func_L01_003E8360(a0);
    func_L01_003EA190(a0);
    func_L01_003E99E8(a0);
}
/* localdecomp:end func_L01_003EA648 */

/* localdecomp:start func_L01_003EA6A8 */
extern Entry_3E6C58 D_L01_001E2A40[];


s32 func_L01_003EA6A8(u8 *a0) {
    Unk003E8810 *p = &((Unk003E8810 *)&D_L01_001E2A40)[*(s32 *)(a0 + 148)];
    switch (p->v) {
    case 4:
    case 81:
        return -1;
    }
    return 0;
}
/* localdecomp:end func_L01_003EA6A8 */

/* localdecomp:start func_L01_003EA6E8 */
#include "vu0.h"

typedef struct {
    vu0_q pos;
    u8 pad10[0x30];
    vu0_q pos2;
    u8 pad50[0x20];
    u8 *unk70;
    u8 pad74[0x20];
    s32 idx;
    f32 unk98;
} Moby_003EA6E8;

typedef struct {
    u8 pad0[0x1C0];
    vu0_v4 unk1C0;
    u8 pad1D0[0x410 - 0x1D0];
    vu0_v4 unk410;
    u8 pad420[0x460 - 0x420];
} Cam_003EA6E8;

typedef struct {
    u8 pad0[0xA4];
    u8 unkA4[1];
} G_003EA6E8;

extern G_003EA6E8 D_00143950;
extern s32 D_00143AD0[][8];
extern f32 D_001D5FF0_003EA6E8[] __attribute__((section(".sdata")));
extern Cam_003EA6E8 D_L01_001E2A40_003EA6E8[];
extern s32 D_L01_001D673C_003EA6E8;
__asm__(".extern D_L01_001D673C_003EA6E8, 16");
extern s32 D_L01_001DF658_003EA6E8;
__asm__(".extern D_L01_001DF658_003EA6E8, 4");
extern f32 D_L01_001DF65C_003EA6E8;
__asm__(".extern D_L01_001DF65C_003EA6E8, 4");
extern f32 D_L01_001DF6C4_003EA6E8;
__asm__(".extern D_L01_001DF6C4_003EA6E8, 4");

extern void func_003C47E8(void *, Moby_003EA6E8 *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_003E4580(Moby_003EA6E8 *, void *);
extern void func_L01_003E6120_003EA6E8(Moby_003EA6E8 *);
extern void func_L01_003E5828_003EA6E8(Moby_003EA6E8 *);
extern void func_L01_003EA648_003EA6E8(Moby_003EA6E8 *);
extern void func_L01_003E5E50_003EA6E8(Moby_003EA6E8 *);
extern void func_0038D6C8(void *, void *, void *, f32);
extern void func_0038D830(void *, void *);
extern void func_0038D590(Moby_003EA6E8 *, void *);

void func_L01_003EA6E8(Moby_003EA6E8 *m)
{
    vu0_v4 q0;
    vu0_v4 q1;
    vu0_v4 q2;
    vu0_v4 v;
    vu0_v4 pos;
    vu0_v4 *src;
    f32 mat[16];
    u8 *p;
    f32 d;
    f32 f;

    p = m->unk70 + 0x60;
    func_003C47E8(&q0, m);
    D_001D5FF0_003EA6E8[m->idx] =
        ((f32)D_00143AD0[D_00143950.unkA4[0]][0] / 100.0f) * 0.0567232035f + 0.021816615f;
    src = &D_L01_001E2A40_003EA6E8[m->idx].unk1C0;
    pos = *src;
    d = pos.z - m->unk98;
    if (d > 0.0f) {
        if (d > D_L01_001DF6C4_003EA6E8 * 0.0200000014f) {
            d = D_L01_001DF6C4_003EA6E8 * 0.0200000014f;
        }
    } else if (d < 0.0f) {
        if (d < -(D_L01_001DF6C4_003EA6E8 * 0.0200000014f)) {
            d = -(D_L01_001DF6C4_003EA6E8 * 0.0200000014f);
        }
    }
    m->unk98 = m->unk98 + d;
    if (pos.z == 0.0f) {
        if (__builtin_fabsf(m->unk98) <= D_L01_001DF6C4_003EA6E8 * 0.0200000014f) {
            m->unk98 = 0.0f;
        }
    }
    pos.z = m->unk98;
    vec_add_ab(&v, &pos, &D_L01_001E2A40_003EA6E8[m->idx].unk410);
    f = D_L01_001E2A40_003EA6E8[m->idx].unk1C0.w;
    if (D_L01_001D673C_003EA6E8 != 0) {
        f = 0.0f;
    }
    v.w = func_0038DAB8(f, D_L01_001E2A40_003EA6E8[m->idx].unk410.w);
    func_L01_003E4580(m, &v);
    func_L01_003E6120_003EA6E8(m);
    func_L01_003E5828_003EA6E8(m);
    func_L01_003EA648_003EA6E8(m);
    func_L01_003E5E50_003EA6E8(m);
    if ((s8)p[0x10F] > 0) {
        p[0x10F]--;
        func_003C47E8(&q2, m);
        func_0038D6C8(&q1, &q0, &q2,
            D_L01_001DF65C_003EA6E8 + (1.0f - D_L01_001DF65C_003EA6E8) * (1.0f - (f32)(s8)p[0x10F] / (f32)D_L01_001DF658_003EA6E8));
        func_0038D830(&q1, mat);
        func_0038D590(m, mat);
        m->pos2 = m->pos;
    } else {
        p[0x10E] = 0;
    }
}
/* localdecomp:end func_L01_003EA6E8 */

/* localdecomp:start func_L01_003EA9B8 */
void func_L01_003EA9B8(void) {

}
/* localdecomp:end func_L01_003EA9B8 */

LINKER_REMNANT("asm/levels", func_L01_003EA9C0);

/* localdecomp:start func_L01_003EA9C8 */
#include "vu0.h"
typedef int Q_003EA9C8 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003EA9C8;
typedef struct { u8 pad[0x54]; f32 *up; u8 rest[0x460-0x58]; } Entry_003EA9C8;
extern u8 D_L01_001E2B90[];
extern Entry_3E6C58 D_L01_001E2A40[];
void func_L01_003EA9C8(Obj_003E8C50 *obj) {
    extern void func_0038CF68(f32 *,f32 *,f32);
    extern void func_0038CE90(f32 *,f32 *,f32 *);
    extern void func_0038CE20(f32 *,f32 *,f32);
    Q_003EA9C8 forward, offset;
    f32 *up;
    u8 *hero = D_L01_001E2B90 + obj->f94 * 0x460;
    func_0038CF68((f32 *)&forward,(f32 *)(*(u8 **)(hero+0xF0)+0xE0),1.0f);
    if(hero[0x12B]==2) {
        func_0038CE20((f32 *)&offset,(f32 *)&forward,3.75f);
    } else if(hero[0x12B]==1) {
        func_0038CE20((f32 *)&offset,(f32 *)&forward,0.75f);
    } else {
        func_0038CE20((f32 *)&offset,(f32 *)&forward,1.6f);
    }
    vec_add_ab((V_003EA9C8 *)&obj->q30,(V_003EA9C8 *)(hero+0x40),(V_003EA9C8 *)&offset);
    up = ((Entry_003EA9C8 *)D_L01_001E2A40)[obj->f94].up;
    *(Q_003EA9C8 *)((u8 *)obj+0x20)=forward;
    func_0038CE90((f32 *)((u8 *)obj+0x10),up,(f32 *)&forward);
    func_0038CF68((f32 *)((u8 *)obj+0x10),(f32 *)((u8 *)obj+0x10),1.0f);
    func_0038CE90((f32 *)obj,(f32 *)&forward,(f32 *)((u8 *)obj+0x10));
    *(Q_003EA9C8 *)((u8 *)obj+0x40)=*(Q_003EA9C8 *)obj;
}
/* localdecomp:end func_L01_003EA9C8 */

/* localdecomp:start func_L01_003EAAE8 */
extern M_3E6CA8 *D_L01_001DF804;
extern Entry_3E6C58 D_L01_001E2A40[];





extern void func_0038CC88(Obj_003E8C50 *, void *, s32);
extern void func_L01_003EA9C8(Obj_003E8C50 *);

void func_L01_003EAAE8(Obj_003E8C50 *obj) {
    Slot_003E8C50 *s = (Slot_003E8C50 *)(obj->f94 * 1120 + (u8 *)((Slot_003E8C50 *)&D_L01_001E2A40));
    Base_003E8C50 *base = (*(Ent_003E8C50 * *)&D_L01_001DF804)[obj->h84].p;
    if (base->a3C[obj->f94]) {
        base->a3C[obj->f94] = 0;
        obj->q30 = s->q;
        func_0038CC88(obj, s->data, 48);
    } else {
        s32 *z = obj->f70;
        z[0] = 0;
        z[2] = 0;
        z[1] = 0;
        z[3] = 0;
        z[4] = 0;
        z[5] = 0;
        z[6] = 0;
        func_L01_003EA9C8(obj);
    }
    base->a38[obj->f94] = 0;
    obj->h7E = 0;
}
/* localdecomp:end func_L01_003EAAE8 */

/* localdecomp:start func_L01_003EABB0 */
extern void func_0038CC88(Obj_003E8C50 *, void *, s32);
extern Entry_3E6C58 D_L01_001E2A40[];
extern G_3E8D18 D_001A4BE0;
extern u8 D_001A71C5[];
void func_L01_003EABB0(O_3E8D18 *a0) {
    E_3E8D18 *e = &((E_3E8D18 *)&D_L01_001E2A40)[a0->x94];
    a0->x30 = e->x230;
    ((void (*)(O_3E8D18 *, void *, s32))func_0038CC88)(a0, e->x200, 48);
    if (e->x2A0 == 3 && e->x2C0 >= 0.5f) {
        if (D_001A4BE0.x25E5 == 0) {
            D_001A4BE0.x25E5 = 1;
        } else {
            e->x2C0 = 1.0f;
        }
    } else if (e->x2A0 == 0) {
        D_001A71C5[0] = 1;
    }
}
/* localdecomp:end func_L01_003EABB0 */

/* localdecomp:start func_L01_003EAC70 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003EAC70;
typedef struct {
    V_003EAC70 pos;
    u8 p10[0x7C - 0x10];
    u8 b7C;
    u8 p7D[0x84 - 0x7D];
    s16 h84;
    s16 h86;
    u8 p88[0x94 - 0x88];
    s32 w94;
} M_003EAC70;
typedef struct {
    u8 p0[0xC0];
    V_003EAC70 vC0;
} T_003EAC70;
typedef struct {
    u8 p0[0x40];
    u128_t q40;
    u8 p50[0x58 - 0x50];
    f32 f58;
    u8 p5C[0xF0 - 0x5C];
    T_003EAC70 *pF0;
    u8 pF4[0xFC - 0xF4];
    s32 wFC;
} F_003EAC70;
typedef struct {
    u8 p0[0x50];
    M_003EAC70 *p50;
    M_003EAC70 *p54;
    u8 p58[0x90 - 0x58];
    V_003EAC70 v90;
    u8 pA0[0x150 - 0xA0];
    F_003EAC70 f150;
    u8 p250[0x460 - 0x250];
} E_003EAC70;
typedef struct {
    u8 p0[0x20];
    s16 h20[4];
    s16 h28[4];
    s16 h30[4];
    u8 p38[4];
    u8 b3C[4];
} R_003EAC70;
typedef struct {
    u8 p0[0x1C];
    R_003EAC70 *r;
} Row_003EAC70;
typedef struct {
    u8 p0[0x198];
    u16 h198;
    u16 p19A;
    u32 w19C;
    u32 w1A0;
} St_003EAC70;
typedef struct {
    u8 p0[0x18];
    s32 w18;
} H_003EAC70;


extern Row_003EAC70 *D_L01_001DF804_003EAC70;
extern E_003EAC70 D_L01_001E2A40_003EAC70[];
extern s32 D_L01_001DF700_003EAC70[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DF700_003EAC70, 4");
extern St_003EAC70 D_001A7C10_003EAC70;
extern s32 D_001D4C38_003EAC70;
extern s32 D_001D545C_003EAC70;
extern H_003EAC70 *func_L01_003F7350(void *, f32);
extern f32 func_0038CE68_003EAC70(void *, void *);
extern void func_0038CE20_003EAC70(void *, void *, f32);
extern f32 func_0038CEA8_003EAC70(void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D0C8(f32);
extern s32 func_0038CB00_003EAC70(void *);
extern void func_L01_003E9250_003EAC70(s32, f32 *, f32, f32);
extern void func_L01_003F5AC0(s32, s32);

s32 func_L01_003EAC70(M_003EAC70 *o, M_003EAC70 *a) {
    V_003EAC70 v;
    V_003EAC70 d1;
    V_003EAC70 d2;
    E_003EAC70 *e;
    F_003EAC70 *f;
    R_003EAC70 *r;
    M_003EAC70 *p;
    s32 *slot;
    f32 len;
    s32 n;

    e = &D_L01_001E2A40_003EAC70[o->w94];
    slot = &D_L01_001DF700_003EAC70[o->w94];
    r = D_L01_001DF804_003EAC70[o->h84].r;
    f = &e->f150;
    if (*slot != 0) {
        *slot = 0;
        return 0;
    }
    *slot = 0;
    if (f->wFC == o->h86 || f->wFC == 0x51) {
        p = e->p50;
        if ((a->h86 == 0x20 || a->h86 == 0 || a->h86 == 10 || a->h86 == 14 || a->h86 == 2) &&
            (a->h86 == 0x20 || p->h86 == 0 || p->h86 == 10 || p->h86 == 14 || p->h86 == 2)) {
            H_003EAC70 *h;
            *(u128_t *)&v = f->q40;
            h = func_L01_003F7350(&v, 0.25f);
            if (h != 0 && (h->w18 & 1)) {
                return 0;
            }
            r->h28[o->w94] = 1;
            r->h30[o->w94] = 0;
            r->h20[o->w94]++;
            if (r->h20[o->w94] >= 6) {
                if ((e->p54 != 0 && e->p54->h86 == 0x20) || p->h86 == 0x20) {
                    r->b3C[o->w94] = 1;
                    return 1;
                }
                if (p->h86 == 0) {
                    o->b7C = 5;
                }
                return 1;
            }
            if ((e->p54 != 0 && e->p54->h86 == 0x20) || p->h86 == 0x20) {
                r->b3C[o->w94] = 1;
                return 1;
            }
            v.x = func_0038D098(f->f58);
            v.y = func_0038D0B0(f->f58);
            v.z = 0.0f;
            func_L01_003E9250_003EAC70(o->w94, &v.x, 0.06981317f, v.z);
        } else {
            r->h20[o->w94] = 0;
            r->h28[o->w94] = 0;
        }
    } else {
        r->h20[o->w94] = 0;
        if (r->h28[o->w94] != 0) {
            r->h28[o->w94] = 0;
            if (e->p50->h86 == 0) {
                if (D_001A7C10_003EAC70.h198 < 0xFFFF) {
                    D_001A7C10_003EAC70.h198++;
                }
                n = (D_001D4C38_003EAC70 * 5 + 2) / 6;
                if (D_001A7C10_003EAC70.w19C < n) {
                    D_001A7C10_003EAC70.w19C = n;
                }
                D_001A7C10_003EAC70.w1A0 = D_001A7C10_003EAC70.w1A0 | (1 << D_001D545C_003EAC70) | 0x80000000;
                func_0038CE20_003EAC70(&v, &e->v90, func_0038CE68_003EAC70(&e->v90, e->p50));
                vec_sub_ba(&d1, &e->p50->pos, &v);
                func_0038CE20_003EAC70(&v, &e->v90, func_0038CE68_003EAC70(&e->v90, &f->pF0->vC0));
                vec_sub_ba(&d2, &f->pF0->vC0, &v);
                len = func_0038CEA8_003EAC70(&d2);
                if (len != 0.0f) {
                    len *= func_0038CEA8_003EAC70(&d1);
                }
                if (len != 0.0f) {
                    if (1.5707964f - func_0038D0C8(func_0038CE68_003EAC70(&d2, &d1) / len) >= 1.3962634f) {
                        func_L01_003F5AC0(o->w94, 1);
                        return 0;
                    }
                }
                r->h30[o->w94] = 0x19;
            }
        }
    }
    if (r->h30[o->w94] != 0 && e->p50->h86 != 0x20 && (e->p54 == 0 || e->p54->h86 == 0x20)) {
        func_0038CB00_003EAC70(&r->h30[o->w94]);
        v.x = func_0038D098(f->f58);
        v.y = func_0038D0B0(f->f58);
        v.z = 0.0f;
        func_L01_003E9250_003EAC70(o->w94, &v.x, 0.13962634f, v.z);
    }
    return 0;
}
/* localdecomp:end func_L01_003EAC70 */

/* localdecomp:start func_L01_003EB158 */
extern void func_L01_003EAAE8(Obj_003E8C50 *obj);
extern Entry_3E6C58 D_L01_001E2A40[];
extern void func_003A52A0(s32, s32, s32);
void func_L01_003EB158(u8 *a0) {
    Entry_3E92A8 *e = &((Entry_3E92A8 *)&D_L01_001E2A40)[*(s32 *)(a0 + 148)];
    if (e->h2A0 != 0) {
        e->h2A0 = 2;
    } else {
        e->h2A0 = 1;
    }
    e->b2A3 = 0;
    (((Entry_3E92A8 *)&D_L01_001E2A40) + *(s32 *)(a0 + 148))->f2C8 = 0.075f;
    ((Entry_3E92A8 *)&D_L01_001E2A40)[*(s32 *)(a0 + 148)].f2B8 = 0.075f;
    ((void (*)(u8 *))func_L01_003EAAE8)(a0);
    if (e->w124) {
        func_003A52A0(0, 0, e->w124);
    }
}
/* localdecomp:end func_L01_003EB158 */

/* localdecomp:start func_L01_003EB200 */
extern Entry_3E6C58 D_L01_001E2A40[];

void func_L01_003EB200(Obj_003E8C50 *obj) {
    Ent_003EB200 *e = &((Ent_003EB200 *)&D_L01_001E2A40)[obj->f94];
    s32 st = e->x24C;
    if (st == 0x51 || st == 4) {
        return;
    }
    if (e->h2A0 == 0) {
        e->b2A3 = 0;
        obj->h7E = 2;
        ((Ent_003EB200 *)&D_L01_001E2A40)[obj->f94].f2C8 = 0.018f;
        ((Ent_003EB200 *)&D_L01_001E2A40)[obj->f94].f2B8 = 0.018f;
        ((Ent_003EB200 *)&D_L01_001E2A40)[obj->f94].f2CC = 0.25f;
        ((Ent_003EB200 *)&D_L01_001E2A40)[obj->f94].f2BC = 0.25f;
        e->f2C0 = 0.5f;
        return;
    }
    e->h2A0 = 0;
    obj->h7E = 4;
}
/* localdecomp:end func_L01_003EB200 */

/* localdecomp:start func_L01_003EB2C0 */
/* Ps2EeAs only uses $gp for this if it knows it is small before the use. */
__asm__(".extern D_L01_001DF700, 8");
extern s32 D_L01_001DF700[2];
void func_L01_003EB2C0(s32 player) {
    D_L01_001DF700[player] = 1;
}
/* localdecomp:end func_L01_003EB2C0 */

/* localdecomp:start func_L01_003EB2D8 */
/* Ps2EeAs only uses $gp for it if it knows it is small before the use. */
__asm__(".extern D_L01_001DF700, 8");
extern s32 D_L01_001DF700[2];
extern Entry_3E6C58 D_L01_001E2A40[];

/* camera_look_blocked: 0 when the hero may enter the look: the current camera is the follow
   camera (class 0) or class 0x20 and has been on for more than 4 frames. The second clause
   reads the class from the update again instead of the local: that is what keeps retail's
   redundant class tests (the compiler only sees they are the same value after its last
   pass that could fold them). */
s32 func_L01_003EB2D8(s32 player) {
    u8 *camera;
    u8 *update;
    s16 class;
    s32 blocked = 0;

    if (D_L01_001DF700[player] == 0) {
        camera = (u8 *)&D_L01_001E2A40 + player * 1120;
        update = *(u8 **)(camera + 0x50);
        class = *(s16 *)(update + 0x86);
        if ((class != 0 && class != 0x20)
            || ((*(s16 *)(update + 0x86) == 0 || *(s16 *)(update + 0x86) == 0x20) && *(s32 *)(camera + 0x454) < 5)) {
            blocked = 1;
        }
    } else {
        blocked = 1;
    }
    return blocked;
}
/* localdecomp:end func_L01_003EB2D8 */

/* localdecomp:start func_L01_003EB350 */
extern Entry_3E6C58 D_L01_001E2A40[];
extern u8 *func_L01_003F34E0(s32, s32);
void func_L01_003EB350(s32 a0, u128_003E94A0 *a1) {
    u8 *o = (&((Slot_003E94A0 *)&D_L01_001E2A40)[a0])->o;
    u8 *r;
    if (*(s16 *)(o + 134) != 5) {
        r = func_L01_003F34E0(a0, 5);
    } else {
        r = o;
    }
    *(u128_003E94A0 *)(*(u8 **)(r + 112) + 128) = *a1;
}
/* localdecomp:end func_L01_003EB350 */

/* localdecomp:start func_L01_003EB3C0 */
extern Entry_3E6C58 D_L01_001E2A40[];
extern u8 *func_L01_003F34E0(s32, s32);
void func_L01_003EB3C0(s32 a0, u128_003E9510 *a1) {
    u8 *o = (&((Slot_003E9510 *)&D_L01_001E2A40)[a0])->o;
    u8 *r;
    if (*(s16 *)(o + 134) != 5) {
        r = func_L01_003F34E0(a0, 5);
    } else {
        r = o;
    }
    *(u128_003E9510 *)(*(u8 **)(r + 112) + 144) = *a1;
}
/* localdecomp:end func_L01_003EB3C0 */

LINKER_REMNANT("asm/levels", func_L01_003EB430);

/* localdecomp:start func_L01_003EB438 */
extern Entry_3E6C58 D_L01_001E2A40[];
extern M_3E6CA8 *D_L01_001DF804;
extern s32 D_001A4E18[];
#include "structs/camera.h"
static __inline__ void copy_003EB438(void *d, void *s) { *(u128_t *)d = *(u128_t *)s; }
static __inline__ u128_t *hero_pos_003EB438(struct GameCamera *c) { return (u128_t *)&c->hero_pos; }
/* camera_scripted_set: switches player's camera to the scripted camera (mode 5) at a position
   and facing; kind 3 starts from the old pose aimed at the hero; no_look_timer = 2 */
void func_L01_003EB438(s32 player, u128_t *position, u128_t *facing, s32 mode, s32 value, s32 owner) {
    extern u8 *func_L01_003F34E0(s32, s32);
    extern void func_00382E10(u8 *, s32);
    extern s32 func_L01_003F5FC0(u8 *, u128_t *, u128_t *);
    f32 pos[4] __attribute__((aligned(16)));
    f32 rot[4] __attribute__((aligned(16)));
    f32 oldpos[4] __attribute__((aligned(16)));
    f32 oldrot[4] __attribute__((aligned(16)));
    u8 *obj = func_L01_003F34E0(player, 5);
    u8 *base = D_L01_001DF804[*(s16 *)(obj+0x84)].p1C;
    u8 *data;
    u8 *sub;
    copy_003EB438(pos, position);
    copy_003EB438(rot, facing);
    copy_003EB438(oldpos, &((struct GameCamera *)D_L01_001E2A40)[player].position);
    copy_003EB438(oldrot, &((struct GameCamera *)D_L01_001E2A40)[player].angles);
    func_00382E10(obj, mode == 4);
    obj[0x7D] = 1;
    data = *(u8 **)(obj+0x70);
    sub = data+0xE0;
    *(u128_t *)(obj+0x30) = *(u128_t *)pos;
    copy_003EB438(&((struct GameCamera *)D_L01_001E2A40)[player].position, pos);
    *(u128_t *)(obj+0x40) = *(u128_t *)rot;
    *(u128_t *)(data+0x80) = *(u128_t *)pos;
    *(u128_t *)(data+0x90) = *(u128_t *)rot;
    *(s32 *)(sub+0x40) = owner;
    obj[0x88] = mode;
    base[0x20] = 0;
    if (mode == 2) goto set_value;
    if (mode == 3) {
        *(f32 *)(sub+0x44) = 1.0f;
        *(s32 *)(sub+0x48) = 0;
        *(u128_t *)(obj+0x30) = *(u128_t *)oldpos;
        *(u128_t *)(obj+0x40) = *(u128_t *)oldrot;
        copy_003EB438(data + 0x110, &((struct GameCamera *)D_L01_001E2A40)[player].hero_pos);
        func_L01_003F5FC0(data+0xFC, (u128_t *)oldpos, hero_pos_003EB438(&((struct GameCamera *)D_L01_001E2A40)[player]));
set_value:
        *(s32 *)(sub+4) = value;
        *(s32 *)(data+0xE0) = value;
    }
    D_001A4E18[0] = 2;
}
/* localdecomp:end func_L01_003EB438 */
