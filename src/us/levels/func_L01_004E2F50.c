#include "common.h"

/* NTSC-U counterpart of func_L01_004E6D18 (src/levels/shared/L01_004DF428.c): 23 -> 28; 0.05328 -> 0.037; 0.432 -> 0.3; 0.03024 -> 0.021; 0.3888 -> 0.27; 0.02016 -> 0.014 */
typedef struct { u8 pad[0xB0]; } S_4DC790;
typedef struct {
    u8 pad0[4688];
    s32 f1250;
    u8 pad1254[36];
    s32 f1278;
    u8 pad127C[4932];
    s32 f25C0;
} G_4DD4B0;
typedef int u128_t __attribute__((mode(TI)));
typedef int s128 __attribute__((mode(TI)));
extern G_4DD4B0 D_001A4BE0;
extern S_4DC790 D_L01_002F4580[];
extern S_4DC790 D_L01_002F4580[];
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern void func_L01_0050D180(s128 *, s128 *, f32);
extern G_4DD4B0 D_001A4BE0;
extern void func_L01_0050D180(u128_t *, u128_t *, f32);
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern f32 func_0038DB00(f32, f32);
extern S_4DC790 D_L01_002F4580[];
extern S_4DC790 D_L01_002F4580[];
extern S_4DC790 D_L01_002F4580[];
extern S_4DC790 D_L01_002F4580[];
extern int func_003D3CB0(char *first, char *second, int mode, int flag, int extra);
extern void func_L01_004E25E0(f32 a, f32 b);
extern void func_L01_004E2610(f32 a, f32 b);

/* localdecomp:start func_L01_004E2F50 */
/* The pitch's fabs is the game's fabs_asm (include/vu0.h): retail loads the 50 deg limit before
   the abs.s and keeps it out of the delay slot. */
#include "vu0.h"
typedef union {
    s128 q;
    struct {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    } v;
} V_4E6D18;
typedef struct {
    u8 pad0[0x60];
    f32 target_x;
    f32 target_y;
    f32 target_z;
    u8 pad6C[0xB0 - 0x6C];
} Spring_4E6D18;
/* the hero's joint springs (43, from D_L01_002F4580) */
typedef struct {
    Spring_4E6D18 root;
    Spring_4E6D18 waist;
    Spring_4E6D18 chest;
    Spring_4E6D18 neck;
} Springs_4E6D18;
/* a moby's damage record (func_00382348) */
typedef struct {
    u8 pad0[0x10];
    f32 height;
    u8 pad14[0x28 - 0x14];
    u8 range;
    u8 priority;
    u8 height8; /* in eighths of a unit */
} Damage_4E6D18;
typedef struct {
    u8 pad0[0x10];
    V_4E6D18 pos;
    u8 pad20[0x43 - 0x20];
    u8 sequence;
} Moby_4E6D18;
typedef struct {
    u8 pad0[0x80];
    V_4E6D18 pos;
    V_4E6D18 rot;
    u8 padA0[0x1DC - 0xA0];
    s16 timer_1fc;
    u8 pad1DE[0xBD8 - 0x1DE];
    Moby_4E6D18 *gun_target;
    u8 padBDC[0x1430 - 0xBDC];
    Moby_4E6D18 *lockon_target;
    u8 pad1434[0x25C0 - 0x1434];
    Moby_4E6D18 *hero_moby;
    s32 state;
    u8 pad25C8[0x25CC - 0x25C8];
    s32 state_type;
    u8 pad25D0[0x25E9 - 0x25D0];
    u8 firing;
    u8 pad25EA[0x27FC - 0x25EA];
    Moby_4E6D18 *look_at;
} H_4E6D18;
extern s32 D_L01_001DFBC0_004E2F50; /* the frame counter */
extern Moby_4E6D18 *D_L01_0021E8E0[]; /* what he may look at, to a 0 */
extern Damage_4E6D18 *func_00382348(Moby_4E6D18 *moby);
extern f32 func_0038CF38(void *a, void *b);
extern f32 func_0038D160(f32 x, f32 y);
extern f32 func_0038DBA0(f32 a, f32 b);
extern f32 func_0038DB00(f32, f32);
extern void func_L01_0050D110(f32 forward, f32 left, f32 up, V_4E6D18 *out, s32 add_position);
extern void func_L01_0050D180(s128 *, s128 *, f32);
extern int func_003D3CB0(char *first, char *second, int mode, int flag, int extra);
extern void func_L01_004E25E0(f32 a, f32 b);
extern void func_L01_004E25F8(f32 a, f32 b);
extern void func_L01_004E2610(f32 a, f32 b);

/* hero_head_look: in state types 0, 1, 2, 4 and 7, turns the upper chest and waist to the
   gun's target (yaw within 59 deg, pitch from 25 deg up to 35 deg down), or the neck to the
   nearest thing on the look-at list, picked every 7th frame. */
void func_L01_004E2F50(void) {
    s32 gun;
    s32 i;
    Moby_4E6D18 *moby;
    Moby_4E6D18 *best;
    Damage_4E6D18 *record;
    Moby_4E6D18 *aim;
    Damage_4E6D18 *aim_record;
    f32 best_score;
    f32 best_priority;
    f32 distance;
    f32 yaw;
    f32 pitch;
    f32 score;
    f32 turn;
    f32 tilt;
    f32 priority;
    V_4E6D18 target;
    V_4E6D18 eye;

    /* a gun target, unless locked on to something */
    gun = (*(H_4E6D18 *)&D_001A4BE0).gun_target != 0 && (*(H_4E6D18 *)&D_001A4BE0).lockon_target == 0;
    if ((*(H_4E6D18 *)&D_001A4BE0).state_type != 1 && (*(H_4E6D18 *)&D_001A4BE0).state_type != 4 &&
        (*(H_4E6D18 *)&D_001A4BE0).state_type != 2 && (*(H_4E6D18 *)&D_001A4BE0).state_type != 7 &&
        (*(H_4E6D18 *)&D_001A4BE0).state_type != 0) {
        (*(H_4E6D18 *)&D_001A4BE0).gun_target = 0;
        (*(H_4E6D18 *)&D_001A4BE0).look_at = 0;
        return;
    }
    if ((*(H_4E6D18 *)&D_001A4BE0).state == 0x2E) {
        return;
    }
    if ((*(H_4E6D18 *)&D_001A4BE0).firing != 0) {
        (*(H_4E6D18 *)&D_001A4BE0).look_at = 0;
    }
    if (!gun) {
        if ((*(H_4E6D18 *)&D_001A4BE0).hero_moby->sequence == 0x4A) {
            return;
        }
        /* every 7th frame, the best thing to look at */
        if (D_L01_001DFBC0_004E2F50 % 7 == 0) {
            best_score = 100000000.0f;
            best_priority = 0.0f;
            best = 0;
            for (i = 0; (moby = D_L01_0021E8E0[i]) != 0; i++) {
                record = func_00382348(moby);
                if (record == 0) {
                    continue;
                }
                distance = func_0038CF38(&(*(H_4E6D18 *)&D_001A4BE0).pos, &moby->pos);
                if (distance > record->range) {
                    continue;
                }
                /* within 90 deg of where he faces */
                yaw = func_0038DBA0(func_0038D160(moby->pos.v.x - (*(H_4E6D18 *)&D_001A4BE0).pos.v.x,
                                                  moby->pos.v.y - (*(H_4E6D18 *)&D_001A4BE0).pos.v.y),
                                    (*(H_4E6D18 *)&D_001A4BE0).rot.v.z);
                if (yaw > 1.57079637f) {
                    continue;
                }
                /* and 50 deg up or down */
                pitch = func_0038D160(func_0038CF38(&moby->pos, &(*(H_4E6D18 *)&D_001A4BE0).pos),
                                      (*(H_4E6D18 *)&D_001A4BE0).pos.v.z - moby->pos.v.z);
                if (fabs_asm(pitch) > 0.872664630f) {
                    continue;
                }
                score = yaw * distance + distance;
                /* the one he looks at already is 1.5 u nearer */
                if (moby == (*(H_4E6D18 *)&D_001A4BE0).look_at) {
                    score -= 1.5f;
                    if (score < 0.0f) {
                        score = 0.0f;
                    }
                }
                priority = record->priority;
                if (priority > best_priority || score < best_score) {
                    if (best_priority < priority) {
                        best_priority = priority;
                    }
                    best_score = score;
                    best = moby;
                }
            }
            (*(H_4E6D18 *)&D_001A4BE0).look_at = best;
        }
        /* within 50 u, and nothing between */
        if ((*(H_4E6D18 *)&D_001A4BE0).look_at != 0 &&
            func_0038CF38(&(*(H_4E6D18 *)&D_001A4BE0).pos, &(*(H_4E6D18 *)&D_001A4BE0).look_at->pos) < 50.0f) {
            func_L01_0050D110(0.0f, 0.0f, 1.20000005f, &target, 1);
            eye = (*(H_4E6D18 *)&D_001A4BE0).look_at->pos;
            func_L01_0050D180(&eye.q, &eye.q, 0.5f);
            if (func_003D3CB0((char *)&target, (char *)&eye, 2, 0, 0) != 0) {
                (*(H_4E6D18 *)&D_001A4BE0).look_at = 0;
            }
        }
    }
    if ((*(H_4E6D18 *)&D_001A4BE0).look_at != 0 || gun) {
        aim = (*(H_4E6D18 *)&D_001A4BE0).look_at;
        if (gun) {
            aim = (*(H_4E6D18 *)&D_001A4BE0).gun_target;
        }
        target = aim->pos;
        /* raised by its damage record's height */
        aim_record = func_00382348(aim);
        if (aim_record != 0) {
            if (gun) {
                target.v.z += aim_record->height;
            } else {
                target.v.z += aim_record->height8 * 0.125f;
            }
        }
        if (gun) {
            func_L01_0050D110(0.5f, 0.0f, 0.550000012f, &eye, 1);
        } else {
            func_L01_0050D110(0.300000012f, 0.0f, 0.850000024f, &eye, 1);
        }
        turn = func_0038DB00(func_0038D160(target.v.x - eye.v.x, target.v.y - eye.v.y), (*(H_4E6D18 *)&D_001A4BE0).rot.v.z);
        tilt = func_0038D160(func_0038CF38(&target, &eye), eye.v.z - target.v.z);
        if (turn > 1.02974427f) {
            turn = 1.02974427f; /* 59 deg */
        } else if (turn < -1.02974427f) {
            turn = -1.02974427f;
        }
        if (tilt > 0.610865235f) {
            tilt = 0.610865235f; /* 35 deg down */
        }
        if (tilt < -0.436332315f) {
            tilt = -0.436332315f; /* 25 deg up */
        }
        if ((*(H_4E6D18 *)&D_001A4BE0).timer_1fc >= 28) {
            if (turn > 0.296705961f) {
                turn = 0.296705961f; /* 17 deg */
            } else if (turn < -0.296705961f) {
                turn = -0.296705961f;
            }
            tilt = 0.0f;
        }
        if (gun) {
            func_L01_004E25F8(0.0370000005f, 0.300000012f);
            (*(Springs_4E6D18 *)D_L01_002F4580).chest.target_z = turn;
            func_L01_004E25E0(0.0370000005f, 0.300000012f);
            (*(Springs_4E6D18 *)D_L01_002F4580).waist.target_y = tilt;
        } else {
            func_L01_004E2610(0.0209999997f, 0.270000011f);
            (*(Springs_4E6D18 *)D_L01_002F4580).neck.target_y = tilt;
            (*(Springs_4E6D18 *)D_L01_002F4580).neck.target_z = turn * 0.75f;
            func_L01_004E25F8(0.0140000004f, 0.300000012f);
            (*(Springs_4E6D18 *)D_L01_002F4580).chest.target_z = (*(Springs_4E6D18 *)D_L01_002F4580).neck.target_z * 0.25f;
        }
    }
    (*(H_4E6D18 *)&D_001A4BE0).gun_target = 0;
}
/* localdecomp:end func_L01_004E2F50 */
