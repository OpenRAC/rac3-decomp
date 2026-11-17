#include "common.h"

typedef struct {
    u8 pad0[0x1B8];
    s32 state_timer;        /* 1B8 */
    u8 pad1[0x270 - 0x1BC];
    f32 capsule_top;        /* 270 */
    f32 capsule_bottom;     /* 274 */
    f32 top_target;         /* 278 */
    f32 bottom_target;      /* 27C */
    f32 radius_target;      /* 280 */
    f32 radius;             /* 284 */
    f32 radius_velocity;    /* 288 */
    u8 pad2[0x2A7 - 0x28C];
    u8 wall_hit;            /* 2A7 */
    u8 pad3[0x360 - 0x2A8];
    s32 field360;           /* 360 */
    u8 pad4[0x46E - 0x364];
    u8 past_jump_apex;      /* 46E */
    u8 pad5[0x47C - 0x46F];
    s16 takeoff_frame;      /* 47C */
    u8 pad6[0x488 - 0x47E];
    f32 field488;           /* 488 */
    u8 pad7[0x1474 - 0x48C];
    u8 field1474;           /* 1474 */
    u8 pad8;
    u8 field1476;           /* 1476 */
    u8 pad9[0x25C4 - 0x1477];
    s32 move_state;         /* 25C4 */
    u8 pad10[4];
    s32 control_mode;       /* 25CC */
    u8 pad11[4];
    s32 prev_control_mode;  /* 25D4 */
    u8 pad12[0x25E0 - 0x25D8];
    s32 field25E0;          /* 25E0 */
    u8 vehicle_mode;        /* 25E4 */
} Capsule_004E24F8;

/* localdecomp:start func_L19_004DDFF0 */
extern Capsule_004E24F8 D_1A4BE0;
extern f32 func_00388800(void *, void *);
extern void func_003BEBF8(f32 *, f32, f32);
extern void func_L01_00445168(f32 *, f32 *, f32, f32, f32, f32);

/* Sets the hero's collision capsule targets (top, bottom, radius) from the vehicle mode and move
 * state, snaps to them when snap is set, and otherwise eases the capsule toward them unless a wall
 * hit holds it. */
void func_L19_004DDFF0(s32 snap)
{
    switch (D_1A4BE0.vehicle_mode) {
    case 0:
        D_1A4BE0.top_target = 0.8f;
        D_1A4BE0.bottom_target = 0.7f;
        D_1A4BE0.radius_target = 0.45f;
        break;
    case 1:
        D_1A4BE0.top_target = 0.55f;
        D_1A4BE0.bottom_target = 0.45f;
        D_1A4BE0.radius_target = 0.25f;
        break;
    case 3:
        D_1A4BE0.top_target = 0.8f;
        D_1A4BE0.bottom_target = 0.6f;
        D_1A4BE0.radius_target = 0.45f;
        break;
    }
    if (D_1A4BE0.control_mode == 4) {
        if (D_1A4BE0.takeoff_frame < D_1A4BE0.state_timer && !D_1A4BE0.past_jump_apex)
            D_1A4BE0.bottom_target = D_1A4BE0.field488;
    } else if (D_1A4BE0.move_state == 6) {
        D_1A4BE0.bottom_target = 0.5f;
    } else if (D_1A4BE0.move_state == 4) {
        D_1A4BE0.top_target = 0.3500000238418579f;
    } else if (D_1A4BE0.field1474 && D_1A4BE0.field360) {
        D_1A4BE0.top_target = 0.8f;
        D_1A4BE0.bottom_target = 0.9f;
    } else if (D_1A4BE0.move_state == 0x81) {
        D_1A4BE0.radius_target = 0.8f;
    } else if (D_1A4BE0.move_state == 0x50) {
        D_1A4BE0.radius_target = 0.5f;
    }
    if (snap) {
        D_1A4BE0.capsule_top = D_1A4BE0.top_target;
        D_1A4BE0.capsule_bottom = D_1A4BE0.bottom_target;
        D_1A4BE0.radius = D_1A4BE0.radius_target;
    }
    if (!D_1A4BE0.wall_hit || D_1A4BE0.prev_control_mode == 0x12 ||
        D_1A4BE0.field25E0 == 0x12 ||
        (D_1A4BE0.vehicle_mode == 0 && D_1A4BE0.capsule_bottom < 0.53f) ||
        D_1A4BE0.control_mode == 0x11 || D_1A4BE0.field1476 ||
        func_00388800((u8 *)&D_1A4BE0 + 0x260, (u8 *)&D_1A4BE0 + 0x80) >
            D_1A4BE0.radius * 0.5f) {
        func_003BEBF8(&D_1A4BE0.capsule_top, D_1A4BE0.top_target, 0.02f);
        func_003BEBF8(&D_1A4BE0.capsule_bottom, D_1A4BE0.bottom_target, 0.02f);
        func_L01_00445168(&D_1A4BE0.radius, &D_1A4BE0.radius_velocity,
                          D_1A4BE0.radius_target, 0.02f, 0.3f, 0.0666666701f);
    }
}
/* localdecomp:end func_L19_004DDFF0 */
