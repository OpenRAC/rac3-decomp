/* Near miss: func_L01_004EE850 (open-rac-engine names it hero_stick_move), in
 * src/levels/shared/L01_004E7338.c (@ps2as). Checked with tools/check.py at level 01: 26
 * differing lines, all in the mode == 1 clamp at the top (the first ~35 instructions after the
 * stick copy); the rest of the function, the zero-stick path and the strafe sorting match.
 * What still differs: register allocation. Retail loads the stick's x into $f2 at once and
 * keeps it there, the 0.7 and 0.12 constants go in $f1 and the abs results in $f0; gcc puts x
 * in $f1, the constant in $f0 and the abs in $f2. Sixteen spellings of the four compares,
 * the order of the stick copy, and separate locals for x and y give the same 26 lines.
 */
extern u8 D_001A4BE0[];
extern S_4E56A8q D_L01_001E2A40;
extern f32 func_0038CED8(void *a0);
extern f32 func_0038D160(f32 a, f32 b);
extern f32 func_0038DBA0(f32 a, f32 b);
extern f32 func_0038DAB8(f32 a, f32 b);
extern f32 func_L01_00510CE8(void);
extern void func_L01_0040E408(void *a0, void *a1, f32 len);
extern void func_0038D000(void *a0, void *a1, void *a2);
extern void func_L01_00511508(s32, s32, f32);
extern void func_0038CF68(void *, s32, float);
extern s32 func_L01_004606E8(s32, s32, s32, s32);

typedef struct H_4EE850 {
    u8 pad0[0x98];
    f32 f152;
    u8 pad9C[0x190 - 0x9C];
    S_4E56A8vec move;
    f32 move_angle;
    u8 pad1A4[0x1B0 - 0x1A4];
    f32 target_speed;
    u8 pad1B4[0x1434 - 0x1B4];
    s16 h5172;
    u8 strafe_back;
    u8 strafe_side;
    u8 pad1438[0x16B0 - 0x1438];
    s32 f16B0;
    u8 pad16B4[0x2260 - 0x16B4];
    f32 stick_x;
    f32 stick_y;
    u8 pad2268[0x25C0 - 0x2268];
    u8 *res25C0;
    u8 pad25C4[0x25F4 - 0x25C4];
    u8 strafing;
    u8 pad25F5[0x2838 - 0x25F5];
    f32 stick_mag;
} H_4EE850;

/* hero_stick_move: turns the stick into the move angle (0x1A0), the target speed (0x1B0) and
 * the move vector (0x190), and while strafing sorts it into a side. mode 1 zeroes an axis
 * under 0.12 while the other is over 0.7. */
void func_L01_004EE850(f32 max_speed, s32 mode) {
    S_4E56A8vec stick;
    S_4E56A8vec one;
    f32 len;
    f32 angle;
    s32 side;
    f32 a;
    f32 nx;
    f32 zero;
    f32 oy;
    f32 ox;

    stick.x = (*(H_4EE850 *)&D_001A4BE0).stick_x;
    stick.y = -(*(H_4EE850 *)&D_001A4BE0).stick_y;
    if (mode == 1) {
        f32 ax = __builtin_fabsf(stick.x);
        f32 ay = __builtin_fabsf(stick.y);
        if (ay > 0.7f && ax < 0.12f) {
            stick.x = 0.0f;
        }
        if (ax > 0.7f && ay < 0.12f) {
            stick.y = 0.0f;
        }
    }
    len = func_0038CED8(&stick);
    if (1.0f < len) {
        func_L01_0040E408(&stick, &stick, len);
    }
    if (stick.x == 0.0f && stick.y == 0.0f) {
        (*(H_4EE850 *)&D_001A4BE0).target_speed = 0.0f;
        if ((*(H_4EE850 *)&D_001A4BE0).strafing) {
            (*(H_4EE850 *)&D_001A4BE0).move_angle = func_L01_00510CE8();
        } else {
            (*(H_4EE850 *)&D_001A4BE0).move_angle = (*(H_4EE850 *)&D_001A4BE0).f152;
        }
        *(s128 *)&one = 0;
        one.x = 1.0f;
        func_0038D000(&(*(H_4EE850 *)&D_001A4BE0).move, &one,
                      (*(H_4EE850 *)&D_001A4BE0).res25C0 + 0xC0);
        return;
    }
    angle = func_0038D160(-stick.y, -stick.x);
    (*(H_4EE850 *)&D_001A4BE0).move_angle = angle;
    if ((*(H_4EE850 *)&D_001A4BE0).h5172 != 0 ||
        ((*(H_4EE850 *)&D_001A4BE0).f16B0 == 1 && func_L01_004606E8(40, 2, 0, 0) != 0)) {
        side = 2;
        a = func_0038D160(stick.x, stick.y);
        if (func_0038DBA0(a, 1.5707964f) < 0.78539819f) {
            side = 3;
        } else if (func_0038DBA0(a, 0.0f) < 0.78539819f) {
            side = 1;
        } else if (func_0038DBA0(a, 3.1415927f) < 0.78539819f) {
            side = 0;
        }
        (*(H_4EE850 *)&D_001A4BE0).strafe_side = side;
        if (side == 3 && 0.15f < (*(H_4EE850 *)&D_001A4BE0).stick_mag) {
            (*(H_4EE850 *)&D_001A4BE0).strafe_back = 1;
        } else {
            (*(H_4EE850 *)&D_001A4BE0).strafe_back = 0;
        }
    }
    zero = 0.0f;
    (*(H_4EE850 *)&D_001A4BE0).move_angle =
        func_0038DAB8((*(H_4EE850 *)&D_001A4BE0).move_angle, D_L01_001E2A40.x18);
    ox = stick.x;
    oy = stick.y;
    stick.y = -ox;
    stick.x = -oy;
    stick.w = zero;
    stick.z = zero;
    func_0038D000(&(*(H_4EE850 *)&D_001A4BE0).move, &stick, (u8 *)&D_L01_001E2A40 + 0x380);
    func_L01_00511508((s32)&(*(H_4EE850 *)&D_001A4BE0).move,
                      (s32)&(*(H_4EE850 *)&D_001A4BE0).move, zero);
    func_0038CF68(&(*(H_4EE850 *)&D_001A4BE0).move, (s32)&(*(H_4EE850 *)&D_001A4BE0).move, 1.0f);
    (*(H_4EE850 *)&D_001A4BE0).target_speed = max_speed * func_0038CED8(&stick);
}
