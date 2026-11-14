#include "common.h"

typedef struct Hero_004C3638 {
    u8 pad0[0x1B8];
    s32 state_timer;           /* 1B8 */
    u8 pad1[0x270 - 0x1BC];
    f32 capsule_top;           /* 270 */
    f32 capsule_bottom;        /* 274 */
    f32 top_target;            /* 278 */
    f32 bottom_target;         /* 27C */
    f32 radius_target;         /* 280 */
    f32 radius;                /* 284 */
    f32 radius_velocity;       /* 288 */
    u8 pad2[0x2A7 - 0x28C];
    u8 wall_hit;               /* 2A7 */
    u8 pad3[0x360 - 0x2A8];
    s32 field360;              /* 360 */
    u8 pad4[0x46E - 0x364];
    u8 past_jump_apex;         /* 46E */
    u8 pad5[0x47C - 0x46F];
    s16 takeoff_frame;         /* 47C */
    u8 pad6[0x488 - 0x47E];
    f32 field488;              /* 488 */
    u8 pad7[0x1474 - 0x48C];
    u8 field1474;              /* 1474 */
    u8 pad8;
    u8 base_condition;         /* 1476 */
    u8 pad9[0x25C4 - 0x1477];
    s32 move_state;            /* 25C4 */
    u8 pad10[0x25CC - 0x25C8];
    s32 control_mode;          /* 25CC */
    u8 pad11[0x25D4 - 0x25D0];
    s32 prev_control_mode;     /* 25D4 */
    u8 pad12[0x25E0 - 0x25D8];
    s32 field25E0;             /* 25E0 */
    u8 vehicle_mode;           /* 25E4 */
} Hero_004C3638;

/* localdecomp:start func_L02_004BF3E8 */
extern Hero_004C3638 D_001A4BE0;
extern f32 func_00388800(void *, void *);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_L01_00445168(f32 *, f32 *, f32, f32, f32, f32);

/* Updates the hero's collision capsule: picks top, bottom and radius targets from vehicle mode,
 * control mode and move state, then eases the capsule toward them (or snaps when arg0 is set). */
void func_L02_004BF3E8(s32 arg0) {
    switch (D_001A4BE0.vehicle_mode) {
    case 0:
        D_001A4BE0.top_target = 0.8f;
        D_001A4BE0.bottom_target = 0.7f;
        D_001A4BE0.radius_target = 0.45f;
        break;
    case 3:
        D_001A4BE0.top_target = 0.8f;
        D_001A4BE0.bottom_target = 0.6f;
        D_001A4BE0.radius_target = 0.45f;
        break;
    }
    if (D_001A4BE0.control_mode == 4) {
        if (D_001A4BE0.takeoff_frame < D_001A4BE0.state_timer && !D_001A4BE0.past_jump_apex)
            D_001A4BE0.bottom_target = D_001A4BE0.field488;
    } else if (D_001A4BE0.move_state == 6) {
        D_001A4BE0.bottom_target = 0.5f;
    } else if (D_001A4BE0.move_state == 4) {
        D_001A4BE0.top_target = 0.3500000238418579f;
    } else if ((u32)(D_001A4BE0.control_mode - 17) < 2) {
        D_001A4BE0.top_target = 0.0f;
        D_001A4BE0.bottom_target = 0.0f;
    } else if (D_001A4BE0.field1474 && D_001A4BE0.field360) {
        D_001A4BE0.top_target = 0.8f;
        D_001A4BE0.bottom_target = 0.9f;
    } else if (D_001A4BE0.move_state == 129) {
        D_001A4BE0.radius_target = 0.8f;
    } else if (D_001A4BE0.move_state == 80) {
        D_001A4BE0.radius_target = 0.5f;
    }
    if (arg0) {
        D_001A4BE0.capsule_top = D_001A4BE0.top_target;
        D_001A4BE0.capsule_bottom = D_001A4BE0.bottom_target;
        D_001A4BE0.radius = D_001A4BE0.radius_target;
    }
    if (!D_001A4BE0.wall_hit || D_001A4BE0.prev_control_mode == 18 ||
        D_001A4BE0.field25E0 == 18 ||
        (D_001A4BE0.vehicle_mode == 0 && D_001A4BE0.capsule_bottom < 0.53f) ||
        D_001A4BE0.control_mode == 17 || D_001A4BE0.base_condition ||
        func_00388800((u8 *)&D_001A4BE0 + 0x260, (u8 *)&D_001A4BE0 + 0x80) >
            D_001A4BE0.radius * 0.5f) {
        func_003BEBF8(&D_001A4BE0.capsule_top, D_001A4BE0.top_target, 0.02f);
        func_003BEBF8(&D_001A4BE0.capsule_bottom, D_001A4BE0.bottom_target, 0.02f);
        func_L01_00445168(&D_001A4BE0.radius, &D_001A4BE0.radius_velocity,
                          D_001A4BE0.radius_target, 0.02f, 0.3f, 0.0666666701f);
    }
}
/* localdecomp:end func_L02_004BF3E8 */
