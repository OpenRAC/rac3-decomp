#ifndef STRUCTS_CAMERA_H
#define STRUCTS_CAMERA_H

/*
 * The cameras. struct GameCamera (0x460 bytes, one per player; on NTSC-U Veldin at 0x1E2AC0)
 * is the camera itself; struct CameraUpdate (0xB0 bytes, 48 per player; 0x1E3050) is a camera
 * mode's slot; struct CameraFollow (0x1E5590) the follow camera's point and springs; struct
 * CameraVolumeSlot (0x40 bytes, 32 per player; 0x1E5D10) a camera volume's settings. Level
 * cameras are mobys whose pvars start with struct CameraPvars (0x20 bytes); classes 0x11, 0x13
 * and 0x17 add the fields in CameraPvars11, 13 and 17, and the camera volume moby (class 2329)
 * has CameraVolumePvars. On R&C3 PAL the camera's position copy was measured at 0x1E2A40
 * +0x190, where NTSC-U has it at GameCamera +0x190: check the base on PAL before using it.
 *
 * From open-rac-engine (GPL-3.0-or-later; THIRD_PARTY_NOTICES.md) at c9306a5:
 * docs/research/camera.md and re/SCUS-97353/symbols.toml. Read in UYA NTSC-U's code and data,
 * some of it checked in the running game; R&C3 and UYA are one game, so the layouts hold for
 * PAL, but level data sits at other addresses in each release and level. Only the fields it
 * names: gaps are pad_*, and a field whose size it doesn't state, or that lies inside another,
 * is a comment at its offset. A field named like a names.h macro ends in _.
 */

#include "common.h"
#include "structs/vector.h"

struct GameCamera {
    Vec4f position;                /* 0x000: Camera position */
    Vec4f angles;                  /* 0x010: Rotation as angles: roll, pitch, yaw */
    /* 0x018: yaw (inside the field above): [0x1E2AD8] Yaw; the hero's strafe turn follows it */
    s32 shake[3][4];               /* 0x020: [0x1E2AE0] Shake: 3 channels 0x10 apart, each amplitude, current, frames left... */
    void *update_cur;              /* 0x050: Current update-camera object (0x1E2B10 points at 0x1E31B0 on Veldin) */
    void *update_prev;             /* 0x054: Previous update-camera object */
    u8 pad_58[0x150 - 0x58];
    /* 0x150: hero_data (size not stated): [0x1E2C10] Start of the camera's copy of the hero, filled each frame by camer... */
    u8 pad_150[0x190 - 0x150];
    Vec4f hero_pos;                /* 0x190: [0x1E2C50] Copy of the hero's position; tested against camera cuboids */
    /* 0x198: hero_height (inside the field above): Hero's height read by the follow code (lies inside the +0x190 vector) */
    u8 pad_1A0[0x1A8 - 0x1A0];
    f32 hero_yaw;                  /* 0x1A8: Hero's yaw read by the follow code */
    u8 pad_1AC[0x1C0 - 0x1AC];
    Vec4f hero_carry;              /* 0x1C0: [0x1E2C80] Hero data +0x70: the move that carried him this frame (hero 0x1A4D... */
    u8 pad_1D0[0x24C - 0x1D0];
    /* 0x24C: req_class (size not stated): [0x1E2D0C] Requested camera class, copied each frame from hero 0x1A73EC (old... */
    u8 pad_24C[0x250 - 0x24C];
    /* 0x250: hero_state (size not stated): [0x1E2D10] Hero state copy (old layouts' +0x2D0) */
    u8 pad_250[0x254 - 0x250];
    /* 0x254: hero_state_type (size not stated): [0x1E2D14] Hero state type copy */
    u8 pad_254[0x260 - 0x254];
    /* 0x260: hero_motion (size not stated): [0x1E2D20] Read as the hero being almost still when at most 1/60 */
    u8 pad_260[0x264 - 0x260];
    f32 hero_above_ground;         /* 0x264: [0x1E2D24] Height above the ground (from hero 0x1A4F1C) */
    u8 pad_268[0x26C - 0x268];
    /* 0x26C: hero_good_ground (size not stated): [0x1E2D2C] On good ground; enables the look-up */
    u8 pad_26C[0x270 - 0x26C];
    /* 0x270: hero_air_frames (size not stated): [0x1E2D30] Frames off any ground (from hero 0x1A4F4C) */
    u8 pad_270[0x278 - 0x270];
    /* 0x278: hero_frames_to_land (size not stated): [0x1E2D38] Frames to land (from hero 0x1A505E) */
    u8 pad_278[0x27A - 0x278];
    u8 hero_past_apex;             /* 0x27A: [0x1E2D3A] Past the apex (old layouts' +0x2FA; from hero 0x1A504E) */
    u8 hero_critter;               /* 0x27B: [0x1E2D3B] Critter mode (old layouts' +0x2FB; from hero 0x1A71C4); 0x17 pvars... */
    u8 pad_27C[0x288 - 0x27C];
    /* 0x288: swing_target (size not stated): Swing target; with the hero state 43 and a target set the swing distances apply */
    u8 pad_288[0x290 - 0x288];
    f32 swing_radius;              /* 0x290: Ideal swing radius */
    u8 pad_294[0x2A0 - 0x294];
    s16 blend_state;               /* 0x2A0: [0x1E2D60] Blend state: 0 none, 1 started by a switch, 2 restarted, 3 running */
    u8 blend_kind_cur;             /* 0x2A2: Running blend kind */
    u8 blend_kind;                 /* 0x2A3: Blend kind: 0 the lerp, 2 the orbit (record type 5) */
    u8 pad_2A4[0x2B0 - 0x2A4];
    f32 blend_rot_t;               /* 0x2B0: [0x1E2D70] Rotation blend progress */
    f32 blend_rot_rate;            /* 0x2B4: Rotation blend rate */
    f32 next_rot_rate;             /* 0x2B8: Next blend's rotation rate, staged (0.075 look, 0.018 back) */
    f32 next_rot_t;                /* 0x2BC: Next blend's rotation start t, staged (0.25 leaving the look) */
    f32 blend_pos_t;               /* 0x2C0: Position blend progress */
    f32 blend_pos_rate;            /* 0x2C4: Position blend rate */
    f32 next_pos_rate;             /* 0x2C8: Next blend's position rate, staged */
    f32 next_pos_t;                /* 0x2CC: Next blend's position start t. Not the old layouts' camera +0x2CC (= +0x24C h... */
    /* 0x2D0: blend_old_rot (size not stated): Old rotation the blend starts from */
    u8 pad_2D0[0x2E0 - 0x2D0];
    Vec4f blend_old_pos;           /* 0x2E0: Old position the blend starts from; moves with the hero's platform */
    u8 pad_2F0[0x380 - 0x2F0];
    Vec4f forward;                 /* 0x380: [0x1E2E40] Forward row; gun code calls it the camera's aim and scope line */
    Vec4f left;                    /* 0x390: [0x1E2E50] Left row */
    Vec4f up;                      /* 0x3A0: [0x1E2E60] Up row */
    u8 pad_3B0[0x420 - 0x3B0];
    /* 0x420: fov_block (size not stated): Field-of-view block; on PAL two of its fields hold 1.11 and the next 0.005 (o... */
    u8 pad_420[0x424 - 0x420];
    f32 fov;                       /* 0x424: [0x1E2EE4] Current field of view (1.11 default); scales the free look's turn... */
    u8 pad_428[0x458 - 0x428];
    /* 0x458: reset_timer (size not stated): Reset timer whose forced cut clears the blend state */
    u8 pad_458[0x460 - 0x458];
};
/* size 0x460 */

struct CameraUpdate {
    u8 pad_0[0x30 - 0x0];
    Vec4f position;                /* 0x030: Camera position (camera 0's follow camera: 0x1E31B0 +0x30) */
    u8 pad_40[0x70 - 0x40];
    void *follow_block;            /* 0x070: The follow block */
    /* 0x074: activation (size not stated): Activation type (from pvar +0x1F) */
    u8 pad_74[0x78 - 0x74];
    /* 0x078: blend_rate (size not stated): Blend rate (type 1) or frames (type 5); -1 from the loader, scripts probably... */
    u8 pad_78[0x7C - 0x78];
    u8 priority;                   /* 0x07C: Priority */
    u8 asked_for;                  /* 0x07D: Set while something asked for this camera (activation 1, 2) */
    u8 ending;                     /* 0x07E: Nonzero while the camera ends; the path camera sets 4 (a cut back) */
    u8 pad_7F[0x84 - 0x7F];
    /* 0x084: record_index (size not stated): Record index in the level's camera list */
    u8 pad_84[0x86 - 0x84];
    /* 0x086: class (size not stated): Camera class */
    u8 pad_86[0x8C - 0x86];
    /* 0x08C: mode_row (size not stated): Row in the camera mode table */
    u8 pad_8C[0x8E - 0x8C];
    /* 0x08E: active (size not stated): Active */
    u8 pad_8E[0x94 - 0x8E];
    /* 0x094: player (size not stated): Player. CONFLICT: camera0_update_object calls +0x94 the camera index */
    u8 pad_94[0x98 - 0x94];
    f32 platform_z;                /* 0x098: Slow copy of the platform carry's z, moving at most 0.01/60 u a frame */
    u8 pad_9C[0xB0 - 0x9C];
};
/* size 0xB0 */

struct CameraFollow {
    u8 pad_0[0x10 - 0x0];
    /* 0x010: flag10 (size not stated): Flag cleared by a volume's +0x18 and each frame by a 0x17 camera whose pvar +... */
    u8 pad_10[0x24 - 0x10];
    f32 view_look_h;               /* 0x024: l: chases the look height (+0x130) for the view's pitch, spring 0.004/0.2; ra... */
    f32 view_h;                    /* 0x028: h: chases the height (+0x1B0) for the view's pitch, spring 0.004/0.2; rate +0x30 */
    f32 view_look_h_rate;          /* 0x02C: Rate of l (+0x24) */
    f32 view_h_rate;               /* 0x030: Rate of h (+0x28) */
    f32 lookup;                    /* 0x034: Look-up angle on good ground with the arm below level; angle spring, rate +0x38 */
    f32 lookup_rate;               /* 0x038: Rate of the look-up */
    f32 lookup_k1;                 /* 0x03C: Look-up spring constant (gain 0.005 or damping 0.2), set at init and each fra... */
    f32 lookup_k2;                 /* 0x040: The other look-up spring constant */
    u8 pad_44[0x48 - 0x44];
    f32 extra_yaw;                 /* 0x048: Extra yaw added to the view; zero in every trace */
    u8 pad_4C[0x60 - 0x4C];
    Vec4f follow_point;            /* 0x060: Follow point, horizontal part: the hero's horizontal position */
    Vec4f follow_height;           /* 0x070: Follow point's height, a vector along up, set by the vertical mode */
    u8 pad_80[0x90 - 0x80];
    Vec4f rise_target;             /* 0x090: The rise target of the timed vertical modes; the platform carry is added to it */
    Vec4f aim;                     /* 0x0A0: Aim: lerp(follow point, look point, n/90) + the look height */
    Vec4f pivot;                   /* 0x0B0: Pivot (clearance point) from two 20 u rays up and down */
    Vec4f look_point;              /* 0x0C0: Look point: springs to the follow point (0.015/0.2 across, 0.0125/0.2 up) */
    u8 pad_D0[0x110 - 0xD0];
    Vec4f third_point;             /* 0x110: A third point only the mode blend's timer touches; nothing in the follow came... */
    u8 pad_120[0x130 - 0x120];
    f32 look_height;               /* 0x130: Look height, springs to 1.5 (gain 0.005, damping 0.2) */
    f32 look_height_target;        /* 0x134: This frame's look-height target (camera_set_look_height) */
    f32 look_height_gain;          /* 0x138: Look-height spring gain */
    u8 pad_13C[0x144 - 0x13C];
    u8 vmode;                      /* 0x144: Vertical mode 0-11 of the follow point's height [type inferred] */
    u8 vmode_old;                  /* 0x145: Old mode, set by a blend [type inferred] */
    /* 0x146: vmode_timer (size not stated): Blend timer (changes only +0x110's spring) */
    u8 pad_146[0x148 - 0x146];
    /* 0x148: vmode_rate (size not stated): Blend rate (changes only +0x110's spring) */
    u8 pad_148[0x158 - 0x148];
    u8 aim_blend_n;                /* 0x158: n: +1 a frame up to +0x16C while +0x159 is set, else -1 to 0; init clears it [type inferred] */
    u8 aim_blend_on;               /* 0x159: Aim blend flag; strafing, lock-on, bosses, volumes set it; cleared at frame end */
    u8 look_height_set;            /* 0x15A: Flag: a look-height target is set this frame [type inferred] */
    u8 pad_15B[0x15C - 0x15B];
    f32 look_h_gain;               /* 0x15C: Horizontal look-point spring gain (class 0x11 eases it from pvar +0x38) */
    f32 look_h_damping;            /* 0x160: Horizontal look-point spring damping, as the symbols have it (camera.md reads... */
    f32 look_v_gain;               /* 0x164: Vertical look-point spring gain (default 0.0125) */
    f32 look_v_damping;            /* 0x168: Vertical look-point spring damping (default 0.2) */
    /* 0x16C: aim_blend_max (size not stated): The 90: aim blend frames, set each frame end from 0x1DF6B0 */
    u8 pad_16C[0x170 - 0x16C];
    f32 look_gap;                  /* 0x170: Last frame's distance between the look point's height and the follow point's */
    /* 0x174: land_count (size not stated): Counts down the 15 frames after landing; the air vertical gain rule applies m... */
    u8 pad_174[0x180 - 0x174];
    Vec4f arm_desired;             /* 0x180: Desired (dragged) arm from the pivot: lerp(arm, last camera - pivot, 0.85) */
    Vec4f arm_actual;              /* 0x190: Actual arm; its yaw and elevation spring 0.015/0.2 to the desired arm */
    u8 pad_1A0[0x1AC - 0x1A0];
    f32 distance;                  /* 0x1AC: Follow distance, springs to 4.64 (gain 0.003, damping 0.2) */
    f32 height;                    /* 0x1B0: Height, springs to 2.0 */
    u8 pad_1B4[0x1BC - 0x1B4];
    /* 0x1BC: distance_set (size not stated): Flag: a distance target is set this frame */
    u8 pad_1BC[0x1BE - 0x1BC];
    /* 0x1BE: height_set (size not stated): Flag: a height target is set this frame */
    u8 pad_1BE[0x1C0 - 0x1BE];
    f32 distance_target;           /* 0x1C0: This frame's follow-distance target (camera_set_distance) */
    u8 pad_1C4[0x1C8 - 0x1C4];
    f32 distance_gain;             /* 0x1C8: Distance spring gain; not reset at the end of the frame */
    f32 height_target;             /* 0x1CC: This frame's height target (camera_set_height) */
    u8 pad_1D0[0x1D4 - 0x1D0];
    f32 height_gain;               /* 0x1D4: Height spring gain; not reset at the end of the frame */
    u8 pad_1D8[0x1E0 - 0x1D8];
    /* 0x1E0: stick_spring (size not stated): Spring between the virtual and the real stick (gain 2, damping 4). Doc says t... */
    u8 pad_1E0[0x1F0 - 0x1E0];
    /* 0x1F0: stick_lock_bits (size not stated): Stick-lock bits (bit 0 x, bit 1 y); class 0x11 subtypes 10 and 11 set bits he... */
    u8 pad_1F0[0x1F4 - 0x1F0];
    f32 lock_turn_speed;           /* 0x1F4: Lock-on turn speed (t/400) x pi/2 rad a frame. Doc says the camera's */
    u8 pad_1F8[0x1FC - 0x1F8];
    /* 0x1FC: virtual_stick (size not stated): Virtual right stick set from the lock-on target; cleared at frame end. Doc sa... */
    u8 pad_1FC[0x204 - 0x1FC];
    f32 tilt_target;               /* 0x204: Arm's tilt target while the right stick's y rests (volume slot +0x0C) */
    u8 pad_208[0x240 - 0x208];
    f32 pull_in;                   /* 0x240: Pull-in: arm length = distance - pull-in */
    /* 0x244: pull_in_timer (size not stated): Pull-in timer: 2000 at rest, 2180 on a wall turn; eases (1 - cos(pi t/2000))/2 */
    u8 pad_244[0x248 - 0x244];
    /* 0x248: end_contact (size not stated): First contact of the camera-end sphere: ceiling, floor or wall */
    u8 pad_248[0x24A - 0x248];
    /* 0x24A: pull_in_fast (size not stated): Set when the camera starts beyond the distance; the timer counts twice as fast */
    u8 pad_24A[0x24C - 0x24A];
    /* 0x24C: clearance_a (size not stated): One of the clearance radius terms (r = 0.35 + growth x scale x (count-1)); ma... */
    u8 pad_24C[0x250 - 0x24C];
    /* 0x250: clearance_b (size not stated): One of the clearance radius terms; reset each frame by 0x3E4008 */
    u8 pad_250[0x254 - 0x250];
    /* 0x254: clearance_c (size not stated): One of the clearance radius terms (listed first in the doc) */
    u8 pad_254[0x258 - 0x254];
    /* 0x258: end_mask (size not stated): Collision mask of the camera-end sphere */
    u8 pad_258[0x25C - 0x258];
    /* 0x25C: blocked_frames (size not stated): Frames the pivot-to-camera line is blocked; at 30 the camera is re-made */
    u8 pad_25C[0x25E - 0x25C];
    /* 0x25E: no_sweep (size not stated): Set in states 80, 125-127, 129: no arm sweep and no blocked count */
    u8 pad_25E[0x260 - 0x25E];
    /* 0x260: claim (size not stated): Claim by 0x17 and 0x11 cameras; the higher priority (pvar +0x1C) wins */
    u8 pad_260[0x266 - 0x260];
    /* 0x266: no_push_back (size not stated): Turns off the run-at-camera push-back for this frame */
    u8 pad_266[0x270 - 0x266];
    /* 0x270: zone_value (size not stated): A value class 0x11 subtypes 10 and 11 set */
};

struct CameraVolumeSlot {
    f32 distance;                  /* 0x000: Distance target, gain 0.001; outside 4.64-6.0 it also turns off the push-back... */
    f32 height;                    /* 0x004: Height target, gain 0.001 */
    f32 look_height;               /* 0x008: Look-height target, gain 0.005 */
    f32 tilt;                      /* 0x00C: Arm's tilt target in radians while the stick's y rests (follow +0x204) */
    f32 fov;                       /* 0x010: FOV target (default 1.11), gain 0.005, damping 0.2 */
    f32 drag;                      /* 0x014: Replaces the arm drag's 0.85 (0x1D5FE8); -1 unset */
    u8 look_blend;                 /* 0x018: Look-point blend on, springs 0.03 / 0.01, push-back off, follow +0x10 cleared */
    u8 look_blend2;                /* 0x019: Look-point blend on, springs 0.03 / 0.0075 (never set from data) */
    /* 0x01A: stick_lock (size not stated): 1 ignores both right-stick axes, 2 the yaw, 3 the pitch */
    u8 pad_1A[0x1C - 0x1A];
    u8 priority;                   /* 0x01C: Priority (default 5); the highest in-use slot wins, ties to the lowest slot */
    u8 in_use;                     /* 0x01D: In use */
    u8 steer;                      /* 0x01E: Steer the arm toward +0x20 at up to +0x34 deg a frame */
    u8 steer_idle;                 /* 0x01F: Steer once the right stick rested +0x32 frames */
    f32 direction[4];              /* 0x020: Steer direction (horizontal) */
    s16 rest_timer;                /* 0x030: Rest timer [type inferred] */
    s16 rest_frames;               /* 0x032: Frames of rest before steering (default 120) [type inferred] */
    /* 0x034: steer_deg (size not stated): Steer speed in degrees a frame (default 6) */
    u8 pad_34[0x38 - 0x34];
    /* 0x038: lifetime (size not stated): Lifetime: positive counts down and frees the slot at 0; -1 forever */
    u8 pad_38[0x3C - 0x38];
    /* 0x03C: no_look (size not stated): Keeps the mode 4 camera from taking over (never set from data) */
    u8 pad_3C[0x40 - 0x3C];
};
/* size 0x40 */

struct CameraPvars {
    f32 lead;                      /* 0x000: 8.0 on the 0x17 and 0x11 cameras, 0 elsewhere (0x11: steer cap, degrees a frame) */
    void *update_object;           /* 0x004: Filled in at load: the camera's update object */
    s32 sphere;                    /* 0x008: Sphere index, -1 for none */
    s32 cuboid;                    /* 0x00C: Cuboid index, -1 for none */
    s32 cylinder;                  /* 0x010: Cylinder index, -1 for none */
    s32 path;                      /* 0x014: Path index, -1 for none (0x11: a camera collider) */
    f32 focus_height;              /* 0x018: 1.5 on every camera seen; not read */
    u8 priority;                   /* 0x01C: Priority: 5 the follow camera, 4 the 0x17, 6 the rest */
    u8 blend_in;                   /* 0x01D: How the switch to this camera blends (0 to 6) */
    u8 blend_out;                  /* 0x01E: Not read */
    u8 activation;                 /* 0x01F: When the camera may take over (activation type 0 to 7) */
};
/* size 0x20 */

struct CameraPvars11 {
    f32 steer_deg;                 /* 0x000: Steer cap toward the record's yaw, degrees a frame, ramped in over 200 frames */
    u8 pad_4[0x8 - 0x4];
    s32 sphere;                    /* 0x008: Sphere tested */
    s32 cuboid;                    /* 0x00C: First cuboid tested */
    s32 cylinder;                  /* 0x010: Cylinder tested */
    s32 collider;                  /* 0x014: Camera collider tested */
    u8 pad_18[0x1C - 0x18];
    u8 priority;                   /* 0x01C: Priority; the higher claims the follow camera */
    u8 pad_1D[0x24 - 0x1D];
    f32 distance;                  /* 0x024: Distance target (gain 0.003; 0.002 in subtypes 6, 8); 0 leaves it */
    f32 height;                    /* 0x028: Height target (gain 0.003) */
    /* 0x02C: subtype (size not stated): Subtype (1, 7, 9, 10: stick push restarts; 2, 4: hold; 10, 11: follow bits) */
    u8 pad_2C[0x2E - 0x2C];
    /* 0x02E: frame_count (size not stated): Its frame count for the steer ramp */
    u8 pad_2E[0x30 - 0x2E];
    f32 look_height;               /* 0x030: Look height target (gain 0.005) */
    u8 pad_34[0x38 - 0x34];
    f32 look_gain_h;               /* 0x038: Look point's horizontal spring gain (to follow +0x15C over 120 frames) */
    f32 look_gain_v;               /* 0x03C: Look point's vertical spring gain (to follow +0x160) */
    u8 pad_40[0x4C - 0x40];
    s32 cuboid2;                   /* 0x04C: Second cuboid tested */
    f32 tilt_deg;                  /* 0x050: Tilt, degrees */
};

struct CameraPvars13 {
    struct CameraPvars common;     /* 0x000 */
    s32 path;                      /* 0x020: The path it moves along */
    s32 look_path;                 /* 0x024: Path it looks at, at the same fraction of its length; -1 none */
    s32 look_moby;                 /* 0x028: Moby link to look at instead (UID in the file, index once loaded) */
    f32 look_offset[3];            /* 0x02C: Added to that moby's position */
    u8 started;                    /* 0x038: Set while running (script start, camera_flythrough_start) */
    u8 finished;                   /* 0x039: Finished; never starts again once set */
    s16 frames;                    /* 0x03A: Flight length in frames when positive; speed = path length / it */
    f32 speed;                     /* 0x03C: Speed along the path in u/s */
    u8 end_test;                   /* 0x040: Tested at the end of the flight; not read */
    u8 free_hero;                  /* 0x041: 0 holds the hero in state 116 for the flight */
    s8 need_state;                 /* 0x042: -1, or the hero state needed to start */
    s8 need_state_type;            /* 0x043: -1, or the hero state type needed to start */
    u8 inited;                     /* 0x044: Set once initialised */
    u8 pad_45[0x46 - 0x45];
    s16 hold_a;                    /* 0x046: Hold time at the end; not read in full */
    s32 hold_b;                    /* 0x048: Hold time at the end (word); not read in full */
    s32 next_camera;               /* 0x04C: Probably a camera to start at the end; -1 none */
    u8 pad_50[0x54 - 0x50];
    u8 no_fade_in;                 /* 0x054: Set: no fade at the start */
    u8 no_fade_out;                /* 0x055: Set: no fade at the end */
    u8 pad_56[0x5C - 0x56];
    s32 end_moby;                  /* 0x05C: Moby (index) whose class function is called at the end; -1 none */
    f32 fovs[8];                   /* 0x060: Written at start: fields of view in degrees, from the path */
    s32 fov_points[8];             /* 0x080: Written at start: the path points those apply at */
    s32 progress_flag;             /* 0x0A0: Progress flag (byte 0x1BBC40 + flag + level x 16, bit 0x80) that stops it; -1... */
    u8 pad_A4[0xB0 - 0xA4];
};
/* size 0xB0 */

struct CameraPvars17 {
    struct CameraPvars common;     /* 0x000 */
    s32 frames;                    /* 0x020: Runtime: frames it has applied, up to 200 */
    s16 keep_flag;                 /* 0x024: 0 makes it clear follow block +0x10 each frame; 1 on Veldin and Florana */
    s16 let_go;                    /* 0x026: Runtime: set when it lets go; never applies again in that visit */
    f32 tilt_deg;                  /* 0x028: Tilt in degrees to hold, 0 none */
    f32 pitch;                     /* 0x02C: View pitch (radians); with +0x30 both 0, the camera's rotation y and z */
    f32 yaw;                       /* 0x030: View yaw (radians) */
    s32 stick_release;             /* 0x034: Nonzero: let go as soon as the right stick turns the camera */
    f32 distance;                  /* 0x038: Runtime: horizontal distance hero to camera position (6.339 respawn) */
    f32 height;                    /* 0x03C: Runtime: camera position's height above the hero */
    f32 look_height;               /* 0x040: Runtime: the look height that gives the pitch at +0x2C */
    f32 hold_yaw;                  /* 0x044: Runtime: a yaw to hold, 0 none */
    s16 state_gate_in;             /* 0x048: Nonzero lets it apply only in a follow-camera state (critter byte 1 or 2); no... */
    s16 state_gate_out;            /* 0x04A: Nonzero lets it apply only out of that state; not read further */
    u8 pad_4C[0x60 - 0x4C];
};
/* size 0x60 */

struct CameraVolumePvars {
    s32 cuboid;                    /* 0x000: Cuboid the hero must be in */
    f32 distance;                  /* 0x004: Follow distance, -1 none (to slot +0x00) */
    f32 height;                    /* 0x008: Height, -1 none (slot +0x04) */
    f32 look_height;               /* 0x00C: Look height, -1 none (slot +0x08) */
    f32 tilt;                      /* 0x010: Tilt in radians, -1 none (slot +0x0C) */
    f32 fov;                       /* 0x014: Field of view in radians, -1 none (slot +0x10) */
    f32 drag;                      /* 0x018: Arm drag, -1 none (slot +0x14) */
    u8 stiff_look;                 /* 0x01C: Stiff look, copied unless the halfword is -1 (slot +0x18) */
    u8 pad_1D[0x1E - 0x1D];
    s16 stick_lock;                /* 0x01E: Stick lock, -1 none (slot +0x1A) */
    u8 priority;                   /* 0x020: Priority, 0 keeps the slot's 5 (slot +0x1C) */
    u8 in_use;                     /* 0x021: Copied if nonzero (slot +0x1D, the in-use flag) */
    u8 steer;                      /* 0x022: Steer always (slot +0x1E) */
    u8 steer_idle;                 /* 0x023: Steer once the stick rests (slot +0x1F) */
    s16 rest_timer;                /* 0x024: Rest timer, -1 none (slot +0x30) */
    s16 rest_frames;               /* 0x026: Frames of rest before steering, -1 none (slot +0x32) */
    s32 inside;                    /* 0x028: Runtime: the hero is inside */
    s32 slot;                      /* 0x02C: Runtime: the slot it holds */
    f32 direction[4];              /* 0x030: Steer direction unless the first is -1 (slot +0x20) */
    s32 group;                     /* 0x040: Moby group that must have a living member */
};

#endif /* STRUCTS_CAMERA_H */
