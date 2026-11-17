#include "common.h"

typedef struct Player_004D0308 {
    /* 0x000 */ u8 pad0[0x80];
    /* 0x080 */ u8 pos80[0x138];
    /* 0x1B8 */ s32 f1B8;
    /* 0x1BC */ u8 pad1BC[0x260 - 0x1BC];
    /* 0x260 */ u8 v260[0x10];
    /* 0x270 */ f32 top;
    /* 0x274 */ f32 bottom;
    /* 0x278 */ f32 top_target;
    /* 0x27C */ f32 bottom_target;
    /* 0x280 */ f32 radius_target;
    /* 0x284 */ f32 radius;
    /* 0x288 */ f32 radius_velocity;
    /* 0x28C */ u8 pad28C[0x2A7 - 0x28C];
    /* 0x2A7 */ u8 b2A7;
    /* 0x2A8 */ u8 pad2A8[0x360 - 0x2A8];
    /* 0x360 */ s32 f360;
    /* 0x364 */ u8 pad364[0x46E - 0x364];
    /* 0x46E */ u8 b46E;
    /* 0x46F */ u8 pad46F[0x47C - 0x46F];
    /* 0x47C */ s16 h47C;
    /* 0x47E */ u8 pad47E[0x488 - 0x47E];
    /* 0x488 */ f32 f488;
    /* 0x48C */ u8 pad48C[0x1474 - 0x48C];
    /* 0x1474 */ u8 b1474;
    /* 0x1475 */ u8 pad1475;
    /* 0x1476 */ u8 b1476;
    /* 0x1477 */ u8 pad1477[0x25C4 - 0x1477];
    /* 0x25C4 */ s32 move_state;
    /* 0x25C8 */ s32 f25C8;
    /* 0x25CC */ s32 control_mode;
    /* 0x25D0 */ s32 f25D0;
    /* 0x25D4 */ s32 prev_mode;
    /* 0x25D8 */ s32 f25D8;
    /* 0x25DC */ s32 f25DC;
    /* 0x25E0 */ s32 f25E0;
    /* 0x25E4 */ u8 vehicle_mode;
} Player_004D0308;

/* localdecomp:start func_L23_004CC570 */
extern Player_004D0308 D_1A4BE0;
extern f32 func_00388800(void *, void *);
extern void func_003BEBF8(f32 *, f32, f32);
extern void func_L01_00445168(f32 *, f32 *, f32, f32, f32, f32);

/* Sets the hero camera clearance targets (top, bottom, radius) from vehicle mode and move state,
 * snaps them when arg0 is set, and otherwise eases them toward the targets. */
void func_L23_004CC570(s32 arg0)
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
    case 2:
        D_1A4BE0.top_target = 3.75f;
        D_1A4BE0.bottom_target = 2.775f;
        D_1A4BE0.radius_target = 2.25f;
        break;
    case 3:
        D_1A4BE0.top_target = 0.8f;
        D_1A4BE0.bottom_target = 0.6f;
        D_1A4BE0.radius_target = 0.45f;
        break;
    }
    if (D_1A4BE0.control_mode == 4) {
        if (D_1A4BE0.h47C < D_1A4BE0.f1B8 && !D_1A4BE0.b46E)
            D_1A4BE0.bottom_target = D_1A4BE0.f488;
    } else if (D_1A4BE0.move_state == 6) {
        D_1A4BE0.bottom_target = 0.5f;
    } else if (D_1A4BE0.move_state == 4) {
        D_1A4BE0.top_target = 0.3500000238418579f;
    } else if ((u32)(D_1A4BE0.control_mode - 17) < 2) {
        D_1A4BE0.top_target = 0.0f;
        D_1A4BE0.bottom_target = 0.0f;
    } else if (D_1A4BE0.b1474 && D_1A4BE0.f360) {
        D_1A4BE0.top_target = 0.8f;
        D_1A4BE0.bottom_target = 0.9f;
    } else if (D_1A4BE0.move_state == 129) {
        D_1A4BE0.radius_target = 0.8f;
    } else if (D_1A4BE0.move_state == 80) {
        D_1A4BE0.radius_target = 0.5f;
    }
    if (arg0) {
        D_1A4BE0.top = D_1A4BE0.top_target;
        D_1A4BE0.bottom = D_1A4BE0.bottom_target;
        D_1A4BE0.radius = D_1A4BE0.radius_target;
    }
    if (!D_1A4BE0.b2A7 || D_1A4BE0.prev_mode == 18 ||
        D_1A4BE0.f25E0 == 18 ||
        (D_1A4BE0.vehicle_mode == 0 && D_1A4BE0.bottom < 0.53f) ||
        D_1A4BE0.control_mode == 17 || D_1A4BE0.b1476 ||
        func_00388800(&D_1A4BE0.v260, &D_1A4BE0.pos80) >
            D_1A4BE0.radius * 0.5f) {
        func_003BEBF8(&D_1A4BE0.top, D_1A4BE0.top_target, 0.02f);
        func_003BEBF8(&D_1A4BE0.bottom, D_1A4BE0.bottom_target, 0.02f);
        func_L01_00445168(&D_1A4BE0.radius, &D_1A4BE0.radius_velocity,
                          D_1A4BE0.radius_target, 0.02f, 0.3f,
                          0.0666666701f);
    }
}
/* localdecomp:end func_L23_004CC570 */
