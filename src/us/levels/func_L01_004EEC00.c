#include "common.h"

/* NTSC-U counterpart of func_L01_004F2A08 (src/levels/shared/L01_004EF3A8.c): 0.01872 -> 0.013; 0.432 -> 0.3; 0.072 -> 0.05 */
typedef int s128_004ECCD8 __attribute__((mode(TI)));
typedef struct {
    u8 pad[128];
    s128_004ECCD8 out;
    u8 pad2[9972 - 144];
    s32 idx;
    s32 count;
} St_004ECCD8;
extern St_004ECCD8 D_001A4BE0;

/* localdecomp:start func_L01_004EEC00 */
typedef int s128_4F2A08 __attribute__((mode(TI)));
typedef union {
    s128_4F2A08 q;
    struct {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    } v;
} V_4F2A08;
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
/* the hero's joint springs (43, from D_L01_002F4580) */
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
typedef struct {
    u8 pad0[0x40];
    u8 matrix[0x40]; /* 0x40: his rotation */
    V_4F2A08 pos; /* 0x80 */
    u8 pad90[0x35C - 0x90];
    s32 ground_moby;
    u8 pad360[0x368 - 0x360];
    s16 on_slope;
    u8 pad36A[0x25C4 - 0x36A];
    s32 state;
    u8 pad25C8[0x25EB - 0x25C8];
    u8 firing_held;
    u8 hold_type; /* 0 none, 1 one hand, 2 both */
    u8 pad25ED[0x25F4 - 0x25ED];
    u8 b25F4; /* 1: the clavicles drop near (330, 245, 138) */
    u8 pad25F5[0x2874 - 0x25F5];
    s16 gun_arm_raised;
} H_4F2A08;
extern s32 D_001D545C; /* the level */
extern Springs_4F2A08 D_L01_002F4580;
extern void func_0038D028(f32 *out, void *a, void *b);
extern f32 func_0038CF00(void *a, void *b);
extern void func_L01_004E25E0(f32 gain, f32 damping);

/* hero_slope_lean: on a slope, not firing a held gun, the waist leans with the ground's tilt
   (up to 21 deg; 7 deg with a gun), the neck half of it back, the clavicles against it with a
   gun not raised; the tail too. */
void func_L01_004EEC00(void) {
    V_4F2A08 v; /* the ground's down in his frame, then a spot */
    f32 limit;
    f32 lean;
    f32 tilt;
    f32 tail;
    s32 near;

    if (D_001D545C == 21) {
        return;
    }
    if ((*(H_4F2A08 *)&D_001A4BE0).on_slope != 0 && (*(H_4F2A08 *)&D_001A4BE0).firing_held == 0) {
        v.q = 0;
        v.v.z = -1.0f;
        func_0038D028(&v.v.x, &v, (*(H_4F2A08 *)&D_001A4BE0).matrix);
        func_L01_004E25E0(0.0130000003f, 0.300000012f);
        limit = 0.366519153f; /* 21 deg */
        if ((*(H_4F2A08 *)&D_001A4BE0).state == 0x72) {
            limit = 0.0872664601f; /* 5 deg */
        } else if ((*(H_4F2A08 *)&D_001A4BE0).state == 0x73 || (*(H_4F2A08 *)&D_001A4BE0).state == 4) {
            limit = 0.191986218f; /* 11 deg */
        }
        if ((*(H_4F2A08 *)&D_001A4BE0).hold_type != 0 && limit > 0.122173049f) {
            limit = 0.122173049f; /* 7 deg with a gun */
        }
        if ((*(H_4F2A08 *)&D_001A4BE0).ground_moby != 0 && limit > 0.157079637f) {
            limit = 0.157079637f; /* 9 deg on a moby */
        }
        if ((*(H_4F2A08 *)&D_001A4BE0).gun_arm_raised == 0) {
            lean = v.v.x * 0.698131680f; /* 40 deg */
            if (lean > limit) {
                lean = limit;
            } else if (lean < -limit) {
                lean = -limit;
            }
            D_L01_002F4580.waist.target_y = lean;
            D_L01_002F4580.neck.target_y = -lean * 0.5f;
            if ((*(H_4F2A08 *)&D_001A4BE0).hold_type != 0) {
                D_L01_002F4580.other_clavicle.target_y = -lean;
                D_L01_002F4580.gun_clavicle.target_y = -lean;
            }
        }
        tilt = -v.v.y * 0.698131680f;
        if (tilt > limit) {
            tilt = limit;
        } else if (tilt < -limit) {
            tilt = -limit;
        }
        D_L01_002F4580.waist.target_x = tilt;
        D_L01_002F4580.neck.target_x = -tilt * 0.25f;
        tail = -v.v.x * 1.22173047f; /* 70 deg */
        if (tail > 0.994837642f) {
            tail = 0.994837642f; /* 57 deg */
        }
        if (tail < -0.122173049f) {
            tail = -0.122173049f;
        }
        if (v.v.z > 0.850000024f) {
            if (tail < 1.39626336f) {
                tail = 1.39626336f; /* 80 deg */
            }
        } else if (v.v.z > 0.5f) {
            if (tail < 1.22173047f) {
                tail = 1.22173047f;
            }
        }
        tilt = v.v.y * 1.22173047f;
        D_L01_002F4580.tail[0].target_y = tail * 0.569999993f;
        D_L01_002F4580.tail[1].target_y = tail * 0.5f;
        D_L01_002F4580.tail[2].target_y = tail * 0.5f;
        D_L01_002F4580.tail[3].target_y = tail * 0.349999994f;
        if (tilt > 1.22173047f) {
            tilt = 1.22173047f;
        } else if (tilt < -1.22173047f) {
            tilt = -1.22173047f;
        }
        D_L01_002F4580.tail[3].target_x = tilt;
        D_L01_002F4580.tail[0].target_x = tilt * 0.699999988f;
        D_L01_002F4580.tail[1].target_x = tilt * 0.699999988f;
        D_L01_002F4580.tail[2].target_x = tilt * 0.699999988f;
    }
    if ((*(H_4F2A08 *)&D_001A4BE0).b25F4 == 1) {
        v.q = 0;
        v.v.x = 330.0f;
        v.v.y = 245.0f;
        v.v.z = 138.0f;
        near = 0;
        if (func_0038CF00(&(*(H_4F2A08 *)&D_001A4BE0).pos, &v) < 35.0f) {
            near = 1;
        }
        if ((*(H_4F2A08 *)&D_001A4BE0).hold_type != 0 && near) {
            D_L01_002F4580.gun_clavicle.gain = 0.0500000007f;
            D_L01_002F4580.gun_clavicle.damping = 0.300000012f;
            D_L01_002F4580.gun_clavicle.target_y = -0.226892799f;
            D_L01_002F4580.other_clavicle.gain = 0.0500000007f;
            D_L01_002F4580.other_clavicle.damping = 0.300000012f;
            D_L01_002F4580.other_clavicle.target_y = -0.226892799f;
        }
    }
}
/* localdecomp:end func_L01_004EEC00 */
