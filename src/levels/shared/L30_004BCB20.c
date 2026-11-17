#include "common.h"

/* localdecomp:start func_L30_004BCB20 */
/* from this repository's func_L01_004EE850 (L01_004E7338.c), plus the body_kind 5 path */
#include "vu0.h"

typedef struct S_004BCB20v {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} S_004BCB20v __attribute__((aligned(16)));

typedef struct H_004BCB20 {
    u8 pad0[0x98];
    f32 f98;
    u8 pad9C[0x190 - 0x9C];
    S_004BCB20v move;
    f32 move_angle;
    u8 pad1A4[0x1B0 - 0x1A4];
    f32 target_speed;
    u8 pad1B4[0x1434 - 0x1B4];
    s16 h1434;
    u8 strafe_back;
    u8 strafe_side;
    u8 pad1438[0x16B0 - 0x1438];
    s32 f16B0;
    u8 pad16B4[0x2260 - 0x16B4];
    f32 stick_x;
    f32 stick_y;
    u8 pad2268[0x25C0 - 0x2268];
    u8 *res25C0;
    u8 pad25C4[0x25E4 - 0x25C4];
    u8 body_kind;
    u8 pad25E5[0x25F4 - 0x25E5];
    u8 strafing;
    u8 pad25F5[0x2838 - 0x25F5];
    f32 stick_mag;
} H_004BCB20;

typedef struct S_004BCB20c {
    u8 pad0[0x18];
    f32 x18;
} S_004BCB20c;

extern u8 D_001A4BE0[];
extern u8 D_L30_001E22C0[];
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_00510CE8(void);
extern void func_L01_0040E408(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_00511508(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_004606E8(s32, s32, s32, s32);

void func_L30_004BCB20(f32 max_speed, s32 mode) {
    S_004BCB20v stick;
    S_004BCB20v one;
    f32 len;
    f32 angle;
    s32 side;
    f32 a;
    f32 zero;
    f32 oy;
    f32 ox;

    stick.x = (*(H_004BCB20 *)&D_001A4BE0).stick_x;
    stick.y = -(*(H_004BCB20 *)&D_001A4BE0).stick_y;
    if ((*(H_004BCB20 *)&D_001A4BE0).body_kind == 5) {
        f32 z = 0.0f;
        stick.w = z;
        stick.z = z;
        stick.y = z;
        (*(H_004BCB20 *)&D_001A4BE0).move_angle = func_0038D160(stick.x, z);
        (*(H_004BCB20 *)&D_001A4BE0).move = stick;
        (*(H_004BCB20 *)&D_001A4BE0).target_speed = max_speed * func_0038CED8(&stick);
        return;
    }
    if (mode == 1) {
        if (fabs_asm(stick.y) > 0.7f && fabs_asm(stick.x) < 0.12f) {
            stick.x = 0.0f;
        }
        if (fabs_asm(stick.x) > 0.7f && fabs_asm(stick.y) < 0.12f) {
            stick.y = 0.0f;
        }
    }
    len = func_0038CED8(&stick);
    if (1.0f < len) {
        func_L01_0040E408(&stick, &stick, len);
    }
    if (stick.x == 0.0f && stick.y == 0.0f) {
        (*(H_004BCB20 *)&D_001A4BE0).target_speed = 0.0f;
        if ((*(H_004BCB20 *)&D_001A4BE0).strafing) {
            (*(H_004BCB20 *)&D_001A4BE0).move_angle = func_L01_00510CE8();
        } else {
            (*(H_004BCB20 *)&D_001A4BE0).move_angle = (*(H_004BCB20 *)&D_001A4BE0).f98;
        }
        *(vu0_q *)&one = 0;
        one.x = 1.0f;
        func_0038D000(&(*(H_004BCB20 *)&D_001A4BE0).move, &one,
                      (*(H_004BCB20 *)&D_001A4BE0).res25C0 + 0xC0);
        return;
    }
    angle = func_0038D160(-stick.y, -stick.x);
    (*(H_004BCB20 *)&D_001A4BE0).move_angle = angle;
    if ((*(H_004BCB20 *)&D_001A4BE0).h1434 != 0 ||
        ((*(H_004BCB20 *)&D_001A4BE0).f16B0 == 1 && func_L01_004606E8(40, 2, 0, 0) != 0)) {
        side = 2;
        a = func_0038D160(stick.x, stick.y);
        if (func_0038DBA0(a, 1.5707964f) < 0.78539819f) {
            side = 3;
        } else if (func_0038DBA0(a, 0.0f) < 0.78539819f) {
            side = 1;
        } else if (func_0038DBA0(a, 3.1415927f) < 0.78539819f) {
            side = 0;
        }
        (*(H_004BCB20 *)&D_001A4BE0).strafe_side = side;
        if (side == 3 && 0.15f < (*(H_004BCB20 *)&D_001A4BE0).stick_mag) {
            (*(H_004BCB20 *)&D_001A4BE0).strafe_back = 1;
        } else {
            (*(H_004BCB20 *)&D_001A4BE0).strafe_back = 0;
        }
    }
    zero = 0.0f;
    (*(H_004BCB20 *)&D_001A4BE0).move_angle =
        func_0038DAB8((*(H_004BCB20 *)&D_001A4BE0).move_angle, ((S_004BCB20c *)D_L30_001E22C0)->x18);
    ox = stick.x;
    oy = stick.y;
    stick.y = -ox;
    stick.x = -oy;
    stick.w = zero;
    stick.z = zero;
    func_0038D000(&(*(H_004BCB20 *)&D_001A4BE0).move, &stick, D_L30_001E22C0 + 0x380);
    func_L01_00511508(&(*(H_004BCB20 *)&D_001A4BE0).move, &(*(H_004BCB20 *)&D_001A4BE0).move, zero);
    func_0038CF68(&(*(H_004BCB20 *)&D_001A4BE0).move, &(*(H_004BCB20 *)&D_001A4BE0).move, 1.0f);
    (*(H_004BCB20 *)&D_001A4BE0).target_speed = max_speed * func_0038CED8(&stick);
}
/* localdecomp:end func_L30_004BCB20 */
