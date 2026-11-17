#include "common.h"

/* NTSC-U counterpart of func_L01_004E64C0 (src/levels/shared/L01_004DF428.c) */
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
extern G_4DD4B0 D_001A4BE0;
extern f32 func_003893C8(f32, f32);
extern S_4DC790 D_L01_002F4580[];
extern S_4DC790 D_L01_002F4580[];
extern S_4DC790 D_L01_002F4580[];
extern S_4DC790 D_L01_002F4580[];
extern float func_003887C8(char *source, short *table);
extern short D_L01_001EAAA0[];

/* localdecomp:start func_L01_004E26F8 */
typedef struct {
    u8 pad0[0x60];
    f32 target_x;
    f32 target_y;
    f32 target_z;
    u8 pad6C[0xA4 - 0x6C];
    f32 gain;
    f32 damping;
    f32 one;
} Spring_4E64C0;
/* the hero's joint springs (43, from D_L01_002F4580) */
typedef struct {
    Spring_4E64C0 root;
    Spring_4E64C0 waist;
    Spring_4E64C0 others[6];
    Spring_4E64C0 other_clavicle;
    Spring_4E64C0 gun_clavicle;
} Springs_4E64C0;
typedef struct {
    u8 pad0[0x204];
    f32 radius;
} HeroPos_4E64C0;
typedef struct {
    u8 pad0[0x222];
    s16 no_gun_raise;
    u8 pad224[0x15A0 - 0x224];
    f32 look_cam_pitch;
    u8 pad15A4[0x16B0 - 0x15A4];
    s32 camera_mode;
    u8 pad16B4[0x25E9 - 0x16B4];
    u8 firing;
    u8 pad25EA[0x25EC - 0x25EA];
    u8 hold_type; /* 0 none, 1 one hand, 2 both */
    u8 pad25ED[0x25F0 - 0x25ED];
    u8 no_hold; /* on ledges */
    u8 pad25F1[0x2874 - 0x25F1];
    s16 gun_arm_raised;
} H_4E64C0;
extern HeroPos_4E64C0 D_001A4C60;
extern s32 D_L01_001EAA98[];
extern s32 func_003BF5E0(s32 moby);
extern int func_L01_004E2628(float *out, float scale, float amount);

/* hero_gun_arm_raise: with a gun in hand, a ray 0.57 u up (0.7 firing) to 1.3 u ahead; a hit
   raises the gun arm by -70 deg x 1.25 x (1.3 - d) / 1.3, clamped to -30..-70 deg, and sets
   gun_arm_raised. In lock-strafe the arm follows the camera pitch (-80..45 deg) instead. Past
   35 deg the waist bends back for the rest; items 0x3F and 0x97 roll the arm too. */
void func_L01_004E26F8(void) {
    f32 pitch;
    f32 roll;
    f32 height;
    s32 item;

    (*(H_4E64C0 *)&D_001A4BE0).gun_arm_raised = 0;
    if ((*(H_4E64C0 *)&D_001A4BE0).hold_type == 0 || (*(H_4E64C0 *)&D_001A4BE0).no_gun_raise != 0 ||
        (*(H_4E64C0 *)&D_001A4BE0).no_hold != 0) {
        return;
    }
    /* the ray: 0.57 u up, 0.7 firing, to 1.3 u ahead */
    height = (*(H_4E64C0 *)&D_001A4BE0).firing ? 0.699999988f : 0.569999993f;
    pitch = 0.0f;
    if (func_L01_004E2628(0, height, 1.29999995f)) {
        /* firing with a target that passes func_003BF5E0, the arm stays level but raised */
        if (!(*(H_4E64C0 *)&D_001A4BE0).firing || D_L01_001EAA98[0] == 0 || !func_003BF5E0(D_L01_001EAA98[0])) {
            f32 d = func_003887C8((char *)&D_001A4C60, D_L01_001EAAA0) - D_001A4C60.radius;
            pitch = (1.29999995f - d) / 1.29999995f * 1.25f * -1.22173047f;
            if (pitch > -0.52359879f) {
                pitch = -0.52359879f;
            }
            if (pitch < -1.22173047f) {
                pitch = -1.22173047f;
            }
        }
        (*(H_4E64C0 *)&D_001A4BE0).gun_arm_raised = 1;
    }
    /* lock-strafe: the camera's pitch, where it raises the arm more */
    if ((*(H_4E64C0 *)&D_001A4BE0).camera_mode == 1) {
        f32 down = -1.39626336f;
        f32 up = 0.785398185f;
        f32 camera = (*(H_4E64C0 *)&D_001A4BE0).look_cam_pitch;
        if ((*(H_4E64C0 *)&D_001A4BE0).gun_arm_raised == 0 || camera < pitch) {
            pitch = camera;
            if (pitch > up) {
                pitch = up;
            } else if (pitch < down) {
                pitch = down;
            }
            (*(H_4E64C0 *)&D_001A4BE0).gun_arm_raised = 0;
        }
    }
    if (pitch == 0.0f) {
        return;
    }
    /* past 35 deg up the waist bends back for the rest */
    if (pitch < -0.610865235f) {
        (*(Springs_4E64C0 *)D_L01_002F4580).waist.gain = 0.05f;
        (*(Springs_4E64C0 *)D_L01_002F4580).waist.damping = 0.3f;
        (*(Springs_4E64C0 *)D_L01_002F4580).waist.target_y = func_003893C8(pitch, -0.610865235f);
        pitch = -0.610865235f;
    }
    (*(Springs_4E64C0 *)D_L01_002F4580).gun_clavicle.gain = 0.05f;
    (*(Springs_4E64C0 *)D_L01_002F4580).gun_clavicle.damping = 0.3f;
    roll = 0.0f;
    item = func_L01_004E5470(0);
    /* items 0x3F and 0x97 roll the arm too */
    if (item == 0x3F || item == 0x97) {
        roll = pitch * 0.00997330993f;
        if (roll > 0.69813168f) {
            roll = 0.69813168f;
        }
    }
    (*(Springs_4E64C0 *)D_L01_002F4580).gun_clavicle.target_y = pitch;
    (*(Springs_4E64C0 *)D_L01_002F4580).gun_clavicle.target_x = roll;
    /* a gun in both hands: the other clavicle too */
    if ((*(H_4E64C0 *)&D_001A4BE0).hold_type == 2) {
        (*(Springs_4E64C0 *)D_L01_002F4580).other_clavicle.gain = (*(Springs_4E64C0 *)D_L01_002F4580).gun_clavicle.gain;
        (*(Springs_4E64C0 *)D_L01_002F4580).other_clavicle.damping = (*(Springs_4E64C0 *)D_L01_002F4580).gun_clavicle.damping;
        (*(Springs_4E64C0 *)D_L01_002F4580).other_clavicle.target_y = pitch;
        (*(Springs_4E64C0 *)D_L01_002F4580).other_clavicle.target_x = roll;
    }
}
/* localdecomp:end func_L01_004E26F8 */
