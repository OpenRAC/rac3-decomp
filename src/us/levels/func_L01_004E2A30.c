#include "common.h"

/* NTSC-U counterpart of func_L01_004E67F8 (src/levels/shared/L01_004DF428.c) */
typedef struct { u8 pad[0xB0]; } S_4DC790;
typedef struct {
    u8 pad0[4688];
    s32 f1250;
    u8 pad1254[36];
    s32 f1278;
    u8 pad127C[4932];
    s32 f25C0;
} G_4DD4B0;
extern G_4DD4B0 D_001A4BE0;
extern s32 func_L01_004E5470(s32 slot);
extern S_4DC790 D_L01_002F4580[];
extern S_4DC790 D_L01_002F4580[];
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern f32 func_003BEBF8(f32 *, f32, f32);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern G_4DD4B0 D_001A4BE0;
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern S_4DC790 D_L01_002F4580[];
extern S_4DC790 D_L01_002F4580[];
extern S_4DC790 D_L01_002F4580[];
extern S_4DC790 D_L01_002F4580[];

/* localdecomp:start func_L01_004E2A30 */
typedef struct {
    u8 pad0[0x60];
    f32 target_x;
    f32 target_y;
    f32 target_z;
    u8 pad6C[0xA4 - 0x6C];
    f32 gain;
    f32 damping;
    f32 one; /* the joint's scale */
} Spring_4E67F8;
/* the hero's joint springs (43, from D_L01_002F4580) */
typedef struct {
    Spring_4E67F8 root;
    Spring_4E67F8 waist;
    Spring_4E67F8 chest;
    Spring_4E67F8 neck;
    Spring_4E67F8 others[13];
    Spring_4E67F8 head;
    Spring_4E67F8 clank;
} Springs_4E67F8;
typedef struct {
    u8 pad0[0x43];
    u8 sequence;
} Moby_4E67F8;
typedef struct {
    u8 pad0[0x1E8];
    s32 idle_time;
    u8 pad1EC[0x208 - 0x1EC];
    s16 fidget_gap;
    u8 pad20A[0x298 - 0x20A];
    f32 wall_height;
    u8 pad29C[0x2A8 - 0x29C];
    f32 wall_distance;
    f32 wall_clearance;
    s32 wall_valid;
    u8 pad2B4[0xBD8 - 0x2B4];
    s32 gun_target;
    u8 padBDC[0x1174 - 0xBDC];
    f32 glance_pitch;
    f32 glance_yaw;
    u8 pad117C[0x1180 - 0x117C];
    s32 glance_timer;
    f32 glance_gain;
    f32 glance_damping;
    u8 pad118C[0x12F4 - 0x118C];
    s32 back_clank;
    u8 pad12F8[0x25C0 - 0x12F8];
    Moby_4E67F8 *hero_moby;
    s32 state;
    u8 pad25C8[0x25E9 - 0x25C8];
    u8 firing;
    u8 pad25EA[0x27FC - 0x25EA];
    s32 look_at;
} H_4E67F8;
extern u8 D_001D5470; /* a cheat: a big Clank */
extern u8 D_001D5472; /* a cheat: a big head */
__asm__(".extern D_L01_001DBD78, 4");
extern f32 D_L01_001DBD78 __attribute__((section(".sdata"))); /* the head's scale */
extern f32 D_L01_001DBD7C __attribute__((section(".sdata"))); /* Clank's scale */
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_L01_004E29F8(void);
extern void func_L01_004E25E0(f32 a, f32 b);
extern void func_L01_004E2610(f32 a, f32 b);
extern s32 func_0037E208(s32, s32);
extern s32 func_L01_004E5470(s32 slot);
extern s32 func_00388398(s32 *timer);
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32 a, f32 b);
extern f32 func_003BEB48(f32 a, f32 b, f32 t);

/* hero_idle_glance: idle glances on the neck and waist springs at random targets and times;
   firing or with a gun target, zeroes them (gains 0.03, 0.2); facing a wall close ahead,
   looks up at it. */
void func_L01_004E2A30(void) {
    s32 turn_waist;
    f32 pitch;
    f32 cap;
    f32 t;
    s32 timer;

    if (D_001D5470 != 0 && (*(H_4E67F8 *)&D_001A4BE0).back_clank != 0) {
        (*(Springs_4E67F8 *)D_L01_002F4580).clank.one = D_L01_001DBD7C;
    }
    (*(Springs_4E67F8 *)D_L01_002F4580).head.one = D_L01_001DBD78;
    if (D_001D5472 != 0) {
        func_003BEBF8(&D_L01_001DBD78, 1.57000005f, 0.0500000007f);
    } else {
        func_003BEBF8(&D_L01_001DBD78, 0.875f, 0.0500000007f);
    }
    if ((*(H_4E67F8 *)&D_001A4BE0).idle_time <= 19) {
        return;
    }
    if ((*(H_4E67F8 *)&D_001A4BE0).firing != 0 || (*(H_4E67F8 *)&D_001A4BE0).gun_target != 0) {
        func_L01_004E29F8();
        func_L01_004E2610(0.03f, 0.2f);
        func_L01_004E25E0(0.03f, 0.2f);
        (*(H_4E67F8 *)&D_001A4BE0).glance_timer = func_0037E208(90, 120);
        (*(H_4E67F8 *)&D_001A4BE0).fidget_gap = func_0037E208(90, 120);
        return;
    }
    /* a wall close ahead: looks up at it */
    if ((*(H_4E67F8 *)&D_001A4BE0).wall_valid != 0 && (*(H_4E67F8 *)&D_001A4BE0).wall_distance > 1.39999998f &&
        (*(H_4E67F8 *)&D_001A4BE0).wall_height > 1.0f) {
        func_L01_004E2610(0.015f, 0.3f);
        /* 11 deg and 1.5 deg a unit away, at most 27 deg */
        pitch = (*(H_4E67F8 *)&D_001A4BE0).wall_distance * 1.5f * 0.0174532924f + 0.191986218f;
        if (pitch > 0.471238881f) {
            pitch = 0.471238881f;
        }
        cap = (1.0f - (*(H_4E67F8 *)&D_001A4BE0).wall_clearance) * 35.0f * 0.0174532924f;
        if (cap < pitch) {
            pitch = cap;
        }
        (*(Springs_4E67F8 *)D_L01_002F4580).neck.target_y = pitch;
        func_L01_004E25E0(0.008f, 0.3f);
        (*(Springs_4E67F8 *)D_L01_002F4580).waist.target_y = (*(Springs_4E67F8 *)D_L01_002F4580).neck.target_y * 0.699999988f;
        return;
    }
    turn_waist = func_L01_004E5470(0) != 0x2F;
    if ((*(H_4E67F8 *)&D_001A4BE0).state != 0) {
        return;
    }
    if (!((*(H_4E67F8 *)&D_001A4BE0).hero_moby->sequence < 3 || (*(H_4E67F8 *)&D_001A4BE0).hero_moby->sequence == 0x35) ||
        (*(H_4E67F8 *)&D_001A4BE0).look_at != 0) {
        return;
    }
    if ((*(H_4E67F8 *)&D_001A4BE0).hero_moby->sequence == 1 || (*(H_4E67F8 *)&D_001A4BE0).hero_moby->sequence == 2) {
        (*(H_4E67F8 *)&D_001A4BE0).glance_timer = func_0037E208(40, 70);
    }
    /* a new glance when the timer runs out */
    if (func_00388398(&(*(H_4E67F8 *)&D_001A4BE0).glance_timer) != 0) {
        (*(H_4E67F8 *)&D_001A4BE0).glance_pitch = -func_0037E250(-0.157079637f, 0.436332315f);
        if ((*(H_4E67F8 *)&D_001A4BE0).wall_height < 1.5f) {
            (*(H_4E67F8 *)&D_001A4BE0).glance_yaw = func_L01_00440918(0.872664630f, 1.22173047f);
        } else {
            (*(H_4E67F8 *)&D_001A4BE0).glance_yaw = func_L01_00440918(0.349065840f, 0.994837642f);
        }
        t = func_0037E250(0.0f, 1.0f);
        (*(H_4E67F8 *)&D_001A4BE0).glance_gain = func_003BEB48(0.0149999997f, 0.00700000022f, t);
        (*(H_4E67F8 *)&D_001A4BE0).glance_damping = func_003BEB48(0.289999992f, 0.300000012f, t);
        /* 90-200 frames to the next, and up to 80 more the longer it lasts */
        timer = func_0037E208(90, 200);
        t *= 80.0f;
        (*(H_4E67F8 *)&D_001A4BE0).glance_timer = timer + (s32)t;
    }
    if ((*(H_4E67F8 *)&D_001A4BE0).hero_moby->sequence == 1 || (*(H_4E67F8 *)&D_001A4BE0).hero_moby->sequence == 2) {
        if ((*(H_4E67F8 *)&D_001A4BE0).glance_yaw > 0.349065840f) {
            (*(H_4E67F8 *)&D_001A4BE0).glance_yaw = 0.349065840f;
        } else if ((*(H_4E67F8 *)&D_001A4BE0).glance_yaw < -0.349065840f) {
            (*(H_4E67F8 *)&D_001A4BE0).glance_yaw = -0.349065840f;
        }
        if ((*(H_4E67F8 *)&D_001A4BE0).glance_pitch > 0.261799395f) {
            (*(H_4E67F8 *)&D_001A4BE0).glance_pitch = 0.261799395f;
        }
        if ((*(H_4E67F8 *)&D_001A4BE0).glance_pitch < 0.0f) {
            (*(H_4E67F8 *)&D_001A4BE0).glance_pitch = 0.0f;
        }
    }
    func_L01_004E2610((*(H_4E67F8 *)&D_001A4BE0).glance_gain, (*(H_4E67F8 *)&D_001A4BE0).glance_damping);
    (*(Springs_4E67F8 *)D_L01_002F4580).neck.target_z = (*(H_4E67F8 *)&D_001A4BE0).glance_yaw;
    (*(Springs_4E67F8 *)D_L01_002F4580).neck.target_y = (*(H_4E67F8 *)&D_001A4BE0).glance_pitch;
    if (turn_waist) {
        func_L01_004E25E0(0.008f, 0.3f);
        (*(Springs_4E67F8 *)D_L01_002F4580).waist.target_z = (*(Springs_4E67F8 *)D_L01_002F4580).neck.target_z * 0.519999981f;
        (*(Springs_4E67F8 *)D_L01_002F4580).waist.target_y = (*(Springs_4E67F8 *)D_L01_002F4580).neck.target_y * 0.550000012f;
    }
}
/* localdecomp:end func_L01_004E2A30 */
