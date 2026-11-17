#include "common.h"

/* NTSC-U counterpart of func_L01_004F2E68 (src/levels/shared/L01_004EF3A8.c) */
typedef int s128_004ECCD8 __attribute__((mode(TI)));
typedef struct {
    u8 pad[128];
    s128_004ECCD8 out;
    u8 pad2[9972 - 144];
    s32 idx;
    s32 count;
} St_004ECCD8;
extern St_004ECCD8 D_001A4BE0;
typedef struct {
    u8 pad0[0x60];
    f32 target_x;
    f32 target_y;
    f32 target_z;
    u8 pad6C[0xA4 - 0x6C];
    f32 gain;
    f32 damping;
    f32 one;
} Spring_4F2A08;
typedef struct {
    Spring_4F2A08 root;
    Spring_4F2A08 waist;
    Spring_4F2A08 chest;
    Spring_4F2A08 neck;
    Spring_4F2A08 legs[4];
    Spring_4F2A08 other_clavicle;
    Spring_4F2A08 gun_clavicle;
    Spring_4F2A08 elbow;
    Spring_4F2A08 spring11;
    Spring_4F2A08 eyes;
    Spring_4F2A08 tail[4];
} Springs_4F2A08;
extern Springs_4F2A08 D_L01_002F4580;
extern void func_L01_004E25E0(f32 gain, f32 damping);

/* localdecomp:start func_L01_004EF060 */
#include "vu0.h"
typedef struct {
    u8 pad_0[0x98];
    f32 yaw; /* 0x98: rot.z */
    u8 pad_9C[0x118 - 0x9C];
    f32 vel_z; /* 0x118: vel.z */
    u8 pad_11C[0x174 - 0x11C];
    f32 speed_own_b; /* 0x174 */
    u8 pad_178[0x1A0 - 0x178];
    f32 move_angle; /* 0x1A0 */
    f32 yaw_rate; /* 0x1A4 */
    f32 turn_left; /* 0x1A8 */
    u8 pad_1AC[0x1B8 - 0x1AC];
    s32 state_timer; /* 0x1B8 */
    u8 pad_1BC[0x3EF - 0x1BC];
    u8 skid; /* 0x3EF: skid flag of the walk */
    u8 pad_3F0[0x1420 - 0x3F0];
    f32 strafe_vec[4]; /* 0x1420: lock-on block +0x00 */
    u8 pad_1430[0x1434 - 0x1430];
    s16 lockon_strafing; /* 0x1434 */
    u8 lockon_strafe_back; /* 0x1436 */
    u8 pad_1437;
    f32 lockon_strafe_heading; /* 0x1438 */
    u8 pad_143C[0x16B0 - 0x143C];
    s32 camera_mode; /* 0x16B0: 0 follow, 1 lock-strafe, 2 first person */
    u8 pad_16B4[0x25C4 - 0x16B4];
    s32 state; /* 0x25C4 */
    s32 substate; /* 0x25C8 */
    s32 state_type; /* 0x25CC */
    u8 pad_25D0[0x25EC - 0x25D0];
    u8 hold_type; /* 0x25EC: 0 none, 1 one hand, 2 both */
    u8 pad_25ED[0x25F4 - 0x25ED];
    u8 clavicles_near; /* 0x25F4 */
    u8 pad_25F5[0x2838 - 0x25F5];
    f32 stick_mag; /* 0x2838 */
} H_4F2E68;

extern void func_L01_004E25C8(f32 a, f32 b);
extern void func_L01_004E25F8(f32 a, f32 b);
extern void func_L01_004E2610(f32 a, f32 b);
extern f32 func_003893C8(f32 a, f32 b);
extern f32 func_00389380(f32 a, f32 b);
extern f32 func_00388978(f32 a);
extern f32 func_00388960(f32 a);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern s32 func_L01_0045D358(s32, s32, s32, s32);
extern f32 func_L01_004F1018_004EF060(void *a0, void *a1);

/* hero_body_twist: procedural joint offsets on top of the animation. Sideways strafing
   turns the root by the strafe's angle to the hero's yaw; the walk, the glide and the
   jumps lean the body by the turn and the yaw rate. */
void func_L01_004EF060(void)
{

    if ((*(H_4F2E68 *)&D_001A4BE0).lockon_strafing != 0 || ((*(H_4F2E68 *)&D_001A4BE0).camera_mode == 1 && func_L01_0045D358(0x28, 2, 0, 0) != 0)) {
        if (0.150000006f < (*(H_4F2E68 *)&D_001A4BE0).stick_mag && (*(H_4F2E68 *)&D_001A4BE0).state != 0x0B && (*(H_4F2E68 *)&D_001A4BE0).state != 0x66 && (*(H_4F2E68 *)&D_001A4BE0).state != 0x69
            && (*(H_4F2E68 *)&D_001A4BE0).lockon_strafe_back == 0) {
            /* sideways strafe: the root turns to the strafe heading, minus the hero's yaw */
            f32 lean;

            D_L01_002F4580.root.gain = 0.037f;
            D_L01_002F4580.waist.gain = 0.025f;
            D_L01_002F4580.root.damping = 0.27f;
            D_L01_002F4580.waist.damping = 0.27f;
            if ((*(H_4F2E68 *)&D_001A4BE0).clavicles_near != 0) {
                lean = func_L01_004F1018_004EF060((*(H_4F2E68 *)&D_001A4BE0).strafe_vec, 0);
            } else {
                lean = func_003893C8((*(H_4F2E68 *)&D_001A4BE0).lockon_strafe_heading, (*(H_4F2E68 *)&D_001A4BE0).yaw);
            }
            D_L01_002F4580.root.target_z = lean;
            D_L01_002F4580.waist.target_z = -lean;
            return;
        }
    }

    if ((*(H_4F2E68 *)&D_001A4BE0).state == 2) {
        f32 damping = 0.200000003f;
        f32 gain = 0.0399999991f;
        func_L01_004E25C8(gain, damping);
        func_L01_004E25E0(gain, damping);
        func_L01_004E25F8(gain, damping);
        func_L01_004E2610(0.0199999996f, damping);
        if ((*(H_4F2E68 *)&D_001A4BE0).substate == 1) {
            f32 lean;
            f32 c;

            lean = (*(H_4F2E68 *)&D_001A4BE0).yaw_rate * 17.0f;
            if (1.39999998f < lean) {
                lean = 1.39999998f;
            } else if (lean < -1.39999998f) {
                lean = -1.39999998f;
            }
            {
                f32 lim = fabs_asm((*(H_4F2E68 *)&D_001A4BE0).turn_left);
                if (lim * 3.0f < lean) {
                    lean = lim * 3.0f;
                } else {
                    lim = -lim;
                    if (lean < lim * 3.0f) {
                        lean = lim * 3.0f;
                    }
                }
            }
            if ((*(H_4F2E68 *)&D_001A4BE0).skid != 0) {
                if (1.10000002f < lean) {
                    lean = 1.10000002f;
                } else if (lean < -1.10000002f) {
                    lean = -1.10000002f;
                }
                func_L01_004E25E0(0.055f, 0.3f);
                func_L01_004E2610(0.07f, 0.3f);
                {
                    f32 lim = fabs_asm((*(H_4F2E68 *)&D_001A4BE0).turn_left);
                    if (lim < lean) {
                        lean = lim;
                    } else if (lean < -lim) {
                        lean = -lim;
                    }
                }
            }
            c = -lean;
            D_L01_002F4580.root.target_x = c * 0.109999999f;
            if ((*(H_4F2E68 *)&D_001A4BE0).skid != 0) {
                D_L01_002F4580.root.target_x = D_L01_002F4580.root.target_x * 0.25f;
            }
            {
                f32 speed = (*(H_4F2E68 *)&D_001A4BE0).speed_own_b / 0.095f;
                if (1.0f < speed) {
                    speed = 1.0f;
                }
                if (speed < 0.0f) {
                    speed = 0.0f;
                }
                D_L01_002F4580.root.target_x = D_L01_002F4580.root.target_x * speed;
            }
            D_L01_002F4580.waist.target_z = lean * 0.310000002f;
            if ((*(H_4F2E68 *)&D_001A4BE0).skid != 0) {
                D_L01_002F4580.waist.target_z = 0.0f;
            }
            {
            f32 a = fabs_asm(lean);
            D_L01_002F4580.chest.target_x = lean * -0.150000006f;
            D_L01_002F4580.neck.target_y = a * -0.150000006f;
            D_L01_002F4580.tail[0].target_z = c * 0.349999994f;
            D_L01_002F4580.neck.target_z = lean * 0.699999988f;
            D_L01_002F4580.tail[1].target_z = c * 0.300000012f;
            D_L01_002F4580.neck.target_x = a * 0.159999996f;
            D_L01_002F4580.tail[1].target_y = a * 0.200000003f;
            D_L01_002F4580.tail[2].target_z = c * 0.300000012f;
            D_L01_002F4580.tail[0].target_y = a * 0.349999994f;
            D_L01_002F4580.tail[3].target_z = c * 0.300000012f;
            }
            return;
        }
        {
        f32 turn_copy = (*(H_4F2E68 *)&D_001A4BE0).turn_left;
        f32 step;
        f32 c;

        if ((*(H_4F2E68 *)&D_001A4BE0).stick_mag < 0.800000012f && (*(H_4F2E68 *)&D_001A4BE0).state_timer < 40) {
            step = (f32)(40 - (*(H_4F2E68 *)&D_001A4BE0).state_timer) * 0.0872664601f;
            func_003BEBF8(&turn_copy, 0.0f, step);
        }
        c = turn_copy * 0.5f;
        if (0.800000012f < c) {
            c = 0.800000012f;
        } else if (c < -0.800000012f) {
            c = -0.800000012f;
        }
        c = c * fabs_asm(c) * 1.25f;
        D_L01_002F4580.waist.target_z = c;
        D_L01_002F4580.neck.target_z = c;
        D_L01_002F4580.neck.target_y = fabs_asm(c) * 0.25f;
        D_L01_002F4580.tail[0].target_z = -c * 0.349999994f;
        D_L01_002F4580.tail[1].target_z = -c * 0.300000012f;
        D_L01_002F4580.tail[2].target_z = -c * 0.300000012f;
        D_L01_002F4580.tail[3].target_z = -c * 0.300000012f;
        }
        return;
    }

    if ((*(H_4F2E68 *)&D_001A4BE0).state == 8) {
        f32 c;
        f32 a;

        func_L01_004E25C8(0.00800000038f, 0.0799999982f);
        func_L01_004E25E0(0.0149999997f, 0.0799999982f);
        func_L01_004E25F8(0.0149999997f, 0.0799999982f);
        func_L01_004E2610(0.00800000038f, 0.100000001f);
        c = (*(H_4F2E68 *)&D_001A4BE0).turn_left * 1.60000002f;
        if (1.25f < c) {
            c = 1.25f;
        } else if (c < -1.25f) {
            c = -1.25f;
        }
        D_L01_002F4580.root.target_x = -c * 0.519999981f;
        if (0.280000001f < D_L01_002F4580.root.target_x) {
            D_L01_002F4580.root.target_x = 0.280000001f;
        } else if (D_L01_002F4580.root.target_x < -0.280000001f) {
            D_L01_002F4580.root.target_x = -0.280000001f;
        }
        D_L01_002F4580.neck.target_z = c * 1.20000005f;
        D_L01_002F4580.waist.target_z = c * 0.579999983f;
        D_L01_002F4580.chest.target_x = c * -0.280000001f;
        if (0.600000024f < D_L01_002F4580.neck.target_z) {
            D_L01_002F4580.neck.target_z = 0.600000024f;
        } else if (D_L01_002F4580.neck.target_z < -0.600000024f) {
            D_L01_002F4580.neck.target_z = -0.600000024f;
        }
        D_L01_002F4580.neck.target_y = fabs_asm(c) * 0.200000003f;
        if (0.200000003f < D_L01_002F4580.neck.target_y) {
            D_L01_002F4580.neck.target_y = 0.200000003f;
        } else if (D_L01_002F4580.neck.target_y < -0.200000003f) {
            D_L01_002F4580.neck.target_y = -0.200000003f;
        }
        D_L01_002F4580.neck.target_x = fabs_asm(c) * 0.159999996f;
        D_L01_002F4580.tail[0].target_z = -c * 0.349999994f;
        D_L01_002F4580.tail[1].target_z = -c * 0.300000012f;
        D_L01_002F4580.tail[2].target_z = -c * 0.300000012f;
        D_L01_002F4580.tail[3].target_z = -c * 0.300000012f;
        return;
    }

    if ((*(H_4F2E68 *)&D_001A4BE0).state == 0x87) {
        f32 c;
        f32 a;
        f32 step;
        func_L01_004E25C8(0.0170000009f, 0.330000013f);
        func_L01_004E25E0(0.0149999997f, 0.25f);
        func_L01_004E25F8(0.0149999997f, 0.25f);
        func_L01_004E2610(0.00800000038f, 0.25f);
        c = (*(H_4F2E68 *)&D_001A4BE0).turn_left * 0.699999988f;
        if (1.20000005f < c) {
            c = 1.20000005f;
        } else if (c < -1.20000005f) {
            c = -1.20000005f;
        }
        D_L01_002F4580.root.target_x = -c * 0.519999981f;
        if (0.280000001f < D_L01_002F4580.root.target_x) {
            D_L01_002F4580.root.target_x = 0.280000001f;
        } else if (D_L01_002F4580.root.target_x < -0.280000001f) {
            D_L01_002F4580.root.target_x = -0.280000001f;
        }
        D_L01_002F4580.neck.target_z = c * 1.20000005f;
        D_L01_002F4580.waist.target_z = c * 0.579999983f;
        D_L01_002F4580.chest.target_x = c * -0.280000001f;
        if (0.600000024f < D_L01_002F4580.neck.target_z) {
            D_L01_002F4580.neck.target_z = 0.600000024f;
        } else if (D_L01_002F4580.neck.target_z < -0.600000024f) {
            D_L01_002F4580.neck.target_z = -0.600000024f;
        }
        D_L01_002F4580.neck.target_x = fabs_asm(c) * 0.159999996f;
        D_L01_002F4580.root.target_y = func_00389380(D_L01_002F4580.root.target_y, -0.122173049f);
        if (0.100000001f < (*(H_4F2E68 *)&D_001A4BE0).stick_mag) {
            a = func_003893C8((*(H_4F2E68 *)&D_001A4BE0).move_angle, (*(H_4F2E68 *)&D_001A4BE0).yaw);
            step = (*(H_4F2E68 *)&D_001A4BE0).stick_mag * 0.610865235f;
            D_L01_002F4580.root.target_x = -func_00388978(a) * step;
            D_L01_002F4580.root.target_y = func_00389380(D_L01_002F4580.root.target_y, func_00388960(a) * step);
            if (0.471238881f < D_L01_002F4580.root.target_x) {
                D_L01_002F4580.root.target_x = 0.471238881f;
            } else if (D_L01_002F4580.root.target_x < -0.471238881f) {
                D_L01_002F4580.root.target_x = -0.471238881f;
            }
            if (0.471238881f < D_L01_002F4580.root.target_y) {
                D_L01_002F4580.root.target_y = 0.471238881f;
            } else if (D_L01_002F4580.root.target_y < -0.471238881f) {
                D_L01_002F4580.root.target_y = -0.471238881f;
            }
        }
        D_L01_002F4580.other_clavicle.gain = 0.0250000004f;
        D_L01_002F4580.other_clavicle.damping = 0.370000005f;
        D_L01_002F4580.gun_clavicle.gain = 0.0250000004f;
        D_L01_002F4580.gun_clavicle.damping = 0.370000005f;
        {
            f32 lean;
            s32 arm_one = 1;
            s32 arm_two = 1;
            if ((*(H_4F2E68 *)&D_001A4BE0).hold_type == 1) {
                arm_two = 0;
            } else if ((*(H_4F2E68 *)&D_001A4BE0).hold_type == 2) {
                arm_one = 0;
                arm_two = 0;
            }
            lean = func_00389380((*(H_4F2E68 *)&D_001A4BE0).vel_z * 5.0f, 0.296705961f);
            if (arm_one != 0) {
                D_L01_002F4580.other_clavicle.target_z = -0.34906584f;
                D_L01_002F4580.other_clavicle.target_x = -lean;
                if (0.610865235f < -lean) {
                    D_L01_002F4580.other_clavicle.target_x = 0.610865235f;
                } else if (-lean < -0.610865235f) {
                    D_L01_002F4580.other_clavicle.target_x = -0.610865235f;
                }
            }
            if (arm_two != 0) {
                D_L01_002F4580.gun_clavicle.target_x = lean;
                D_L01_002F4580.gun_clavicle.target_z = 0.34906584f;
                if (0.610865235f < lean) {
                    D_L01_002F4580.gun_clavicle.target_x = 0.610865235f;
                } else if (lean < -0.610865235f) {
                    D_L01_002F4580.gun_clavicle.target_x = -0.610865235f;
                }
            }
        }
        D_L01_002F4580.neck.target_y = -(*(H_4F2E68 *)&D_001A4BE0).vel_z * 7.69999981f;
        if (0.645771801f < D_L01_002F4580.neck.target_y) {
            D_L01_002F4580.neck.target_y = 0.645771801f;
        } else if (D_L01_002F4580.neck.target_y < -0.645771801f) {
            D_L01_002F4580.neck.target_y = -0.645771801f;
        }
        D_L01_002F4580.tail[0].target_z = -c * 0.349999994f;
        D_L01_002F4580.tail[1].target_z = -c * 0.300000012f;
        D_L01_002F4580.tail[2].target_z = -c * 0.300000012f;
        D_L01_002F4580.tail[3].target_z = -c * 0.300000012f;
        return;
    }

    if ((*(H_4F2E68 *)&D_001A4BE0).state_type == 2 || (*(H_4F2E68 *)&D_001A4BE0).state_type == 4) {
        f32 c;
        func_L01_004E25C8(0.0399999991f, 0.200000003f);
        func_L01_004E25E0(0.0399999991f, 0.200000003f);
        func_L01_004E25F8(0.0399999991f, 0.200000003f);
        func_L01_004E2610(0.0199999996f, 0.200000003f);
        c = (*(H_4F2E68 *)&D_001A4BE0).turn_left;
        if (1.39999998f < c) {
            c = 1.39999998f;
        } else if (c < -1.39999998f) {
            c = -1.39999998f;
        }
        D_L01_002F4580.waist.target_z = c * 0.289999992f;
        D_L01_002F4580.chest.target_x = c * -0.270000011f;
        D_L01_002F4580.neck.target_z = c * 0.870000005f;
        D_L01_002F4580.tail[0].target_z = -c * 0.349999994f;
        D_L01_002F4580.tail[1].target_z = -c * 0.300000012f;
        D_L01_002F4580.tail[2].target_z = -c * 0.300000012f;
        D_L01_002F4580.tail[3].target_z = -c * 0.300000012f;
    }
}
/* localdecomp:end func_L01_004EF060 */
