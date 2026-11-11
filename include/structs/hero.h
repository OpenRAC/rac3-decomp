#ifndef STRUCTS_HERO_H
#define STRUCTS_HERO_H

/*
 * The hero (Ratchet), D_001A4BE0: the base the code uses, 0x20 into the hero's 0x2940-byte
 * region at 0x1A4BC0, at the same address on PAL and NTSC-U. The offsets below are from
 * D_001A4BE0; the [0x1A....] in a note is the field's address. Blocks inside it keep a prefix
 * (ledge_, lockon_, look_, zip_, aim_, swim_, grind_). Its state numbers are in
 * enums/hero_state.h. struct HeroAttackRow is a row of the melee attack table (0x2C bytes; on
 * NTSC-U Veldin at 0x2F6310).
 *
 * From open-rac-engine (GPL-3.0-or-later; THIRD_PARTY_NOTICES.md) at c9306a5:
 * re/SCES-52456/hero.toml, docs/research/hero-controller.md, camera.md, weapons.md and
 * effects.md. Read in UYA NTSC-U's code and data, some of it checked in the running game; R&C3
 * and UYA are one game, so the layouts hold for PAL, but level data sits at other addresses in
 * each release and level. Only the fields it names: gaps are pad_*, and a field whose size it
 * doesn't state, or that lies inside another, is a comment at its offset. A field named like a
 * names.h macro ends in _.
 *
 * Fields tagged [PAL] are from this repository's matched C, read in the function named, and
 * some from tests in the running PAL game (PCSX2, 2026-10), where the note says "live". The hero
 * code drives whichever moby is its body (+0x25C0): Ratchet's own (+0xBF8), Clank, Giant Clank or
 * the Tyhrra-Guise disguise (+0xBFC). bodySet (func_L01_004ED3F8, hero_set_character) sets it and
 * +0x25E4; bodyRestore (func_L01_004ED658) puts Ratchet's moby back.
 */

#include "common.h"
#include "structs/vector.h"
#include "enums/hero_state.h"

struct Moby;

struct Hero {
    u8 pad_0[0x80 - 0x0];
    Vec4f pos;                     /* 0x080: [0x1A4C60] Hero position in world units. Verified: it follows Ratchet in ever... */
    Vec4f rot;                     /* 0x090: [0x1A4C70] Roll, pitch, yaw in radians. Yaw changes as Ratchet turns; roll an... */
    u8 pad_A0[0xE0 - 0xA0];
    Vec4f pickup_point;            /* 0x0E0: [0x1A4CC0] 0.7 u above his feet: where pickups fly to; the whip wave spawns f... */
    Vec4f intended_vel;            /* 0x0F0: [0x1A4CD0] Velocity the state code asks for (code base +0xF0); collision turn... */
    Vec4f carry_accum;             /* 0x100: [0x1A4CE0] The carry hero_platform_carry adds the platform's move to this frame */
    Vec4f vel;                     /* 0x110: [0x1A4CF0] Actual displacement per frame: equals pos[n] - pos[n-1] exactly on... */
    u8 pad_120[0x150 - 0x120];
    Vec4f carried;                 /* 0x150: [0x1A4D30] What the platform carry moved him this frame after collision; to t... */
    u8 pad_160[0x170 - 0x160];
    /* 0x170: speed_own_a (size not stated): [0x1A4D50] One of his own speeds, which leave the carry out */
    u8 pad_170[0x174 - 0x170];
    /* 0x174: speed_own_b (size not stated): [0x1A4D54] Ground speed the flip starts with (carried if over 0.025). Doubt... */
    u8 pad_174[0x1A0 - 0x174];
    f32 move_angle;                /* 0x1A0: [0x1A4D80] Yaw the hero wants to face and move towards (radians): the stick d... */
    f32 yaw_rate;                  /* 0x1A4: [0x1A4D84] Yaw change per frame from the turn spring. Reproduced on all 724 n... */
    f32 turn_left;                 /* 0x1A8: [0x1A4D88] Angle left to turn after hero_turn_to_move_angle [type inferred] */
    u8 pad_1AC[0x1B0 - 0x1AC];
    f32 speed_target;              /* 0x1B0: [0x1A4D90] Ground speed the stick asks for: 6.17 * 0.02 * stick_mag while wal... */
    f32 speed;                     /* 0x1B4: [0x1A4D94] Current ground speed; steps towards speed_target by 0.0148 per fra... */
    s32 state_timer;               /* 0x1B8: [0x1A4D98] Frames since the current state began; hero_change_state resets it.... */
    u8 pad_1BC[0x1D0 - 0x1BC];
    s16 no_grab_timer;             /* 0x1D0: [0x1A4DB0] No-grab timer; first of the i16 timers 0x1A4DB0-0x1A4DFC counted d... */
    u8 pad_1D2[0x1D4 - 0x1D2];
    s16 wall_window;               /* 0x1D4: [0x1A4DB4] Wall-contact countdown: 6 (7 in a wall jump) while a wall is in reach */
    u8 pad_1D6[0x1D8 - 0x1D6];
    s16 firing_count;              /* 0x1D8: [0x1A4DB8] Counts the frames firing has run (the Nitro Launcher waits past 20) [type inferred] */
    u8 pad_1DA[0x1DC - 0x1DA];
    s16 timer_1fc;                 /* 0x1DC: [0x1A4DBC] A hero timer (+0x1FC, not read); past 27 the waist keeps within 17... [type inferred] */
    u8 pad_1DE[0x1E0 - 0x1DE];
    s16 land_lockout;              /* 0x1E0: [0x1A4DC0] Lockout on landing: 7, 10 after state 44, 18 after a fall over 50... [type inferred] */
    u8 pad_1E2[0x1F0 - 0x1E2];
    s16 no_cap_timer;              /* 0x1F0: [0x1A4DD0] While this timer runs the 0.43 u/frame move cap is off; setter not... [type inferred] */
    u8 pad_1F2[0x1FE - 0x1F2];
    s16 no_dive_timer;             /* 0x1FE: [0x1A4DDE] Dive from the surface needs 0; held at 10 on Florana and Marcadia */
    u8 pad_200[0x204 - 0x200];
    s16 no_zip_timer_;             /* 0x204: [0x1A4DE4] Frames before a zip line can be caught; 30 when he lets go */
    u8 pad_206[0x208 - 0x206];
    s16 fidget_gap_;               /* 0x208: [0x1A4DE8] Frames before another fidget may play; 120 when one starts [type inferred] */
    u8 pad_20A[0x21E - 0x20A];
    /* 0x21E: death_timer (size not stated): [0x1A4DFE] Run out by the death state after the animation's end flag; no writ... */
    u8 pad_21E[0x230 - 0x21E];
    s32 bolt_mult_timer;           /* 0x230: [0x1A4E10] Frames; crate 0x1F7 adds 1800; beeps near the end; clears bolt_mul... */
    /* 0x234: giant_clank (size not stated): [0x1A4E14] Giant-Clank mode flag: damage x 50, stronger lunge, wider aim (lis... */
    u8 pad_234[0x238 - 0x234];
    /* 0x238: no_look_timer (size not stated): [0x1A4E18] While above 0 the hero camera is refused and mode 0x20 can't start... */
    u8 pad_238[0x23C - 0x238];
    /* 0x23C: drown_counter (size not stated): [0x1A4E1C] A drowned hero's (108) own counter in place of the death timer */
    u8 pad_23C[0x284 - 0x23C];
    f32 radius;                    /* 0x284: [0x1A4E64] Collision radius (0.45); the move caps motion at it less 0.02 */
    u8 pad_288[0x28C - 0x288];
    struct Moby *moby_touched;     /* 0x28C: [0x1A4E6C] A moby he runs into (crate fuse code). Which list entry is which i... */
    struct Moby *moby_stood_on;    /* 0x290: [0x1A4E70] The moby he stands on (crate fuse code) */
    u8 pad_294[0x2E0 - 0x294];
    Vec4f down;                    /* 0x2E0: [0x1A4EC0] The game's down, (0, 0, -1) */
    u8 pad_2F0[0x300 - 0x2F0];
    Vec4f last_ground;             /* 0x300: [0x1A4EE0] Ground point last stood on; the flip looks for ground near its z */
    u8 pad_310[0x33C - 0x310];
    f32 height_above_ground;       /* 0x33C: [0x1A4F1C] From the ground probe: distance down to the ground, 32 if none */
    f32 ground_slope;              /* 0x340: [0x1A4F20] Ground's angle from the horizontal, radians */
    u8 pad_344[0x350 - 0x344];
    f32 water_height;              /* 0x350: [0x1A4F30] Water surface height under him (ground probe) */
    f32 quicksand_height;          /* 0x354: [0x1A4F34] Quicksand's surface height, kept apart from water's [type inferred] */
    u8 pad_358[0x35C - 0x358];
    struct Moby *ground_moby;      /* 0x35C: [0x1A4F3C] Moby under him from the ground probe, 0 for level ground. CONFLICT... */
    /* 0x360: ground_frames (size not stated): [0x1A4F40] Frames on the ground (0 in the air); crouch and early flip need it */
    u8 pad_360[0x368 - 0x360];
    /* 0x368: unk_4f48 (size not stated): [0x1A4F48] Gates 0x4C4A18 and 0x4C4AD8, run by every projectile (not read) */
    u8 pad_368[0x36C - 0x368];
    /* 0x36C: frames_off_any (size not stated): [0x1A4F4C] Frames off any ground, copied to camera 0x1E2D30 */
    u8 pad_36C[0x36E - 0x36C];
    s16 air_frames;                /* 0x36E: [0x1A4F4E] Frames off the ground, 0 standing. Doubt: next to 0x1A4F4C, also f... */
    Vec4f platform_pin_pos;        /* 0x370: [0x1A4F50] His position pinned in the platform's frame */
    /* 0x380: platform_pin_facing (size not stated): [0x1A4F60] His facing pinned in the platform's frame (while not turning) */
    u8 pad_380[0x3B0 - 0x380];
    Vec4f platform_last_carry;     /* 0x3B0: [0x1A4F90] The platform's last carry a frame, carried on after he leaves it */
    void *platform;                /* 0x3C0: [0x1A4FA0] The moby carrying him (ground moby, ledge moby, or the last) */
    /* 0x3C4: platform_flags (size not stated): [0x1A4FA4] Bit 0 position pinned in its frame, bit 1 facing */
    u8 pad_3C4[0x3EF - 0x3C4];
    u8 skid;                       /* 0x3EF: [0x1A4FCF] Skid flag of the walk state: set by a sharp turn or by releasing t... */
    /* 0x3F0: release_flag (size not stated): [0x1A4FD0] Walk's release flag: never set with a gun, at once with the wrench... */
    u8 pad_3F0[0x404 - 0x3F0];
    /* 0x404: hero_mobys (size not stated): [0x1A4FE4] A block of the hero's mobys in an outside layout (hero + 0x424); e... */
    u8 pad_404[0x428 - 0x404];
    f32 jump_apex_gravity;         /* 0x428: [0x1A5008] Gravity after the apex: jump_gravity * 1.17 for a standing jump (0... */
    u8 pad_42C[0x450 - 0x42C];
    Vec4f flip_facing_vec;         /* 0x450: [0x1A5030] flip_facing as a vector */
    u8 pad_460[0x464 - 0x460];
    f32 jump_air_turn_cap;         /* 0x464: [0x1A5044] Turn-rate cap in the air (15 rad/s: 0.3002 per frame on PAL, 0.250... */
    u8 pad_468[0x46C - 0x468];
    u8 jump_landed_;               /* 0x46C: [0x1A504C] Counts up from 1 once a jump-type state lands; then 2 */
    u8 pad_46D[0x46E - 0x46D];
    u8 jump_past_apex_;            /* 0x46E: [0x1A504E] Set once the vertical speed drops below 0.001 after push-off. Chec... */
    u8 pad_46F[0x470 - 0x46F];
    f32 jump_max_fall;             /* 0x470: [0x1A5050] Fall speed cap per frame (1.0000001, i.e. 50 units/s). Value read... */
    f32 jump_air_max;              /* 0x474: [0x1A5054] Horizontal speed cap for air control (0.1234 per frame for a stand... */
    f32 jump_height;               /* 0x478: [0x1A5058] Target jump height: starts at jump_min_height and grows by (max -... */
    s16 jump_push_frames;          /* 0x47C: [0x1A505C] Push-off frames before the jump impulse applies (1 for a standing... */
    s16 jump_frames_to_land_;      /* 0x47E: [0x1A505E] hero_ticks_to_land's answer past the apex; camera copies it */
    f32 jump_pending;              /* 0x480: [0x1A5060] Upward speed still to add: sqrt(2 * jump_height * jump_gravity) mi... */
    f32 jump_given;                /* 0x484: [0x1A5064] Upward speed added so far. Checked frame by frame in the traces */
    u8 pad_488[0x490 - 0x488];
    f32 flip_move_angle_;          /* 0x490: [0x1A5070] The flip's way: the move angle when it started [type inferred] */
    f32 flip_facing_;              /* 0x494: [0x1A5074] Yaw the flip turns back to (10 frames back), spring 0.04/0.2, cap... [type inferred] */
    f32 jump_peak_frame;           /* 0x498: [0x1A5078] Animation frame to reach at the apex, set per jump state */
    f32 jump_land_frame;           /* 0x49C: [0x1A507C] Landing frame */
    f32 jump_land_key;             /* 0x4A0: [0x1A5080] Landing keyframe; the landing replays from it + 2 */
    s32 flip_side_;                /* 0x4A4: [0x1A5084] hero_strafe_side at the start: left 0, right 1, forward 2, back 3 */
    f32 flip_carry_;               /* 0x4A8: [0x1A5088] Start ground speed (0x1A4D54) if over 0.025 u a frame, else 0 [type inferred] */
    f32 flip_speed_;               /* 0x4AC: [0x1A508C] The flip's own speed along flip_move_angle [type inferred] */
    Vec4f wall_normal;             /* 0x4B0: [0x1A5090] Wall normal from hero_detect_wall; its yaw at +0xC */
    /* 0x4BC: wall_normal_yaw (inside the field above): [0x1A509C] The wall normal's yaw (wall_normal +0xC) */
    Vec4f wall_jump_normal;        /* 0x4C0: [0x1A50A0] A wall jump's copy of the normal, compared with the next wall */
    /* 0x4CC: wall_jump_yaw (inside the field above): [0x1A50AC] A wall jump's copy of the yaw */
    f32 jump_air_accel;            /* 0x4D0: [0x1A50B0] Acceleration of the ground speed towards the air cap during push-o... */
    f32 jump_air_decel;            /* 0x4D4: [0x1A50B4] Braking of the ground speed during push-off (0.0044 per frame on P... */
    f32 jump_min_height;           /* 0x4D8: [0x1A50B8] Height of a tapped jump (1.42 for a standing jump). Read in the tr... */
    f32 jump_max_height;           /* 0x4DC: [0x1A50BC] Height of a fully held jump (2.7 for a standing jump). Read in the... */
    u8 pad_4E0[0x4E4 - 0x4E0];
    f32 jump_anim_factor_;         /* 0x4E4: [0x1A50C4] hero_anim_rate_to_frame's factor: 0.5 (keyframe = 2 frames), 1 in... */
    s16 jump_up_frames;            /* 0x4E8: [0x1A50C8] Frames X can extend the jump (14 for a standing jump on PAL). Read... */
    u8 pad_4EA[0x4F0 - 0x4EA];
    f32 jump_gravity_;             /* 0x4F0: [0x1A50D0] Gravity per frame (0.01188 = 29.7 units/s^2 for a standing jump).... */
    u8 pad_4F4[0x4FD - 0x4F4];
    u8 flip_strafing_;             /* 0x4FD: [0x1A50DD] Moves as the strafe flip (strafing, stick past 0.3 at the start)... */
    u8 jump_can_flip_;             /* 0x4FE: [0x1A50DE] Set entering standing, run, long, heli jumps; R1 + stick press the... */
    u8 pad_4FF[0x500 - 0x4FF];
    Vec4f ledge_hang;              /* 0x500: [0x1A50E0] Ledge block +0x00: the hang point (hero_detect_ledge's result) */
    Vec4f ledge_lip;               /* 0x510: [0x1A50F0] Ledge block +0x10: the lip point */
    u8 pad_520[0x524 - 0x520];
    f32 ledge_wall_yaw;            /* 0x524: [0x1A5104] Ledge block +0x24: the wall's yaw */
    /* 0x528: ledge_found (size not stated): [0x1A5108] Ledge block +0x28: found flag */
    u8 pad_528[0x534 - 0x528];
    /* 0x534: ledge_flags (size not stated): [0x1A5114] Ledge block +0x34: flags, bit 0 room above the lip */
    u8 pad_534[0x538 - 0x534];
    struct Moby *ledge_moby;       /* 0x538: [0x1A5118] Ledge block +0x38: the object grabbed; the platform while hanging */
    u8 pad_53C[0x5E0 - 0x53C];
    /* 0x5E0: grind_end_frames (size not stated): [0x1A51C0] Frames since the rail's spline ran out; falls at 6 */
    u8 pad_5E0[0x5E4 - 0x5E0];
    f32 grind_speed_;              /* 0x5E4: [0x1A51C4] Grind speed a frame: base (0x1A5200) + slope term (0x1A51F4) [type inferred] */
    u8 pad_5E8[0x5F8 - 0x5E8];
    f32 grind_stance_;             /* 0x5F8: [0x1A51D8] Stance offset added to the rail's yaw: -pi/2 on getting on, +pi/2... */
    /* 0x5FC: grind_stance_side (size not stated): [0x1A51DC] 0 or 1; the grind plays sequence 44 + this */
    u8 pad_5FC[0x614 - 0x5FC];
    f32 grind_slope_term;          /* 0x614: [0x1A51F4] The grind speed's slope term [type inferred] */
    u8 pad_618[0x620 - 0x618];
    f32 grind_base_speed;          /* 0x620: [0x1A5200] The grind speed's base, toward 0.2 [type inferred] */
    u8 pad_624[0x62C - 0x624];
    /* 0x62C: grind_auto_a (size not stated): [0x1A520C] Flag for rails that jump him over a gap (not modelled) */
    u8 pad_62C[0x630 - 0x62C];
    /* 0x630: grind_auto_b (size not stated): [0x1A5210] Second flag for rails that jump him over a gap */
    u8 pad_630[0x634 - 0x630];
    /* 0x634: grind_search_flag (size not stated): [0x1A5214] Set: grind jumps search other rails before the rail's end */
    u8 pad_634[0x648 - 0x634];
    void *grind_stance_object;     /* 0x648: [0x1A5228] Moby the grind entry checks; over 90 deg the other way turns the s... */
    u8 pad_64C[0x668 - 0x64C];
    /* 0x668: grind_off_frames (size not stated): [0x1A5248] Frames more than 1.07 u above the ground under the rail; falls at 6 */
    u8 pad_668[0x670 - 0x668];
    Vec4f zip_found_point;         /* 0x670: [0x1A5250] Zip line: the found point */
    Vec4f zip_last_step;           /* 0x680: [0x1A5260] Zip line: the last step */
    /* 0x690: zip_spline (size not stated): [0x1A5270] Zip line: spline (0x1A5270-0x1A5278 hold spline, segment, position) */
    u8 pad_690[0x694 - 0x690];
    /* 0x694: zip_segment (size not stated): [0x1A5274] Zip line: segment (per the range's order) */
    u8 pad_694[0x698 - 0x694];
    f32 zip_position;              /* 0x698: [0x1A5278] Zip line: position along the spline (per the range's order) [type inferred] */
    /* 0x69C: zip_found (size not stated): [0x1A527C] hero_find_zipline's found flag; state 118 unless a rail was found */
    u8 pad_69C[0x6A0 - 0x69C];
    /* 0x6A0: zip_end (size not stated): [0x1A5280] 0 while riding; counts frames from the cable's end, falls at 6 */
    u8 pad_6A0[0x6A4 - 0x6A0];
    f32 zip_speed_;                /* 0x6A4: [0x1A5284] Speed along the cable, u a frame: +0.0025 a frame to 0.23333 */
    u8 pad_6A8[0x6AC - 0x6A8];
    /* 0x6AC: zip_rail_flags (size not stated): [0x1A528C] The rail's flag word */
    u8 pad_6AC[0x6B0 - 0x6AC];
    f32 zip_heading;               /* 0x6B0: [0x1A5290] Heading [type inferred] */
    f32 zip_slope;                 /* 0x6B4: [0x1A5294] Slope [type inferred] */
    f32 zip_hand_dist;             /* 0x6B8: [0x1A5298] Hands' distance from the cable, settles about 0.04 u [type inferred] */
    u8 pad_6BC[0x6C0 - 0x6BC];
    Vec4f aim_matrix[4];           /* 0x6C0: [0x1A52A0] Fire direction: matrix; guns shoot along it without a target */
    /* 0x6F0: aim_dir (inside the field above): [0x1A52D0] Fire direction: direction (his facing) */
    Vec4f aim_angles;              /* 0x700: [0x1A52E0] Fire direction: angles, yaw plus the upper-body twist */
    u8 pad_710[0x720 - 0x710];
    /* 0x720: surface_bob (size not stated): [0x1A5300] Surface float values; the bobbing offset */
    u8 pad_720[0x724 - 0x720];
    /* 0x724: surface_bob_rate (size not stated): [0x1A5304] Rate of the surface bob */
    u8 pad_724[0x990 - 0x724];
    /* 0x990: swim (size not stated): [0x1A5570] Swim block start (fields below) */
    u8 pad_990[0x9A0 - 0x990];
    /* 0x9A0: swim_dive_time (size not stated): [0x1A5580] Swim block +0x10: dive time (the dive lasts 40) */
    u8 pad_9A0[0x9A4 - 0x9A0];
    /* 0x9A4: swim_bank_rate (size not stated): [0x1A5584] Swim block +0x14: bank rate */
    u8 pad_9A4[0x9A8 - 0x9A4];
    /* 0x9A8: swim_pitch_rate (size not stated): [0x1A5588] Swim block +0x18: pitch rate */
    u8 pad_9A8[0x9AC - 0x9A8];
    /* 0x9AC: swim_saved_yaw_rate (size not stated): [0x1A558C] Swim block +0x1C: saved yaw rate */
    u8 pad_9AC[0x9B4 - 0x9AC];
    /* 0x9B4: swim_min_timer (size not stated): [0x1A5594] Swim block +0x24: minimum swim timer */
    u8 pad_9B4[0x9BC - 0x9B4];
    /* 0x9BC: swim_bob_rate (size not stated): [0x1A559C] Swim block +0x2C: the surface swim's bob spring rate */
    u8 pad_9BC[0x9C0 - 0x9BC];
    /* 0x9C0: swim_hold_cross (size not stated): [0x1A55A0] Swim block +0x30: Cross hold count */
    u8 pad_9C0[0x9C2 - 0x9C0];
    /* 0x9C2: swim_hold_square (size not stated): [0x1A55A2] Swim block +0x32: Square hold count */
    u8 pad_9C2[0xB40 - 0x9C2];
    Vec4f wrench_line_hand;        /* 0xB40: [0x1A5720] Wrench line this frame: hero point 0, the wrench hand */
    Vec4f wrench_line_tip;         /* 0xB50: [0x1A5730] Wrench line this frame: the wrench's joint 1, its tip */
    Vec4f wrench_line_hand_old;    /* 0xB60: [0x1A5740] Last frame's hand point */
    Vec4f wrench_line_tip_old;     /* 0xB70: [0x1A5750] Last frame's tip point */
    u8 pad_B80[0xBC4 - 0xB80];
    /* 0xBC4: attack_fields (size not stated): [0x1A57A4] Attack fields to 0x1A57BE: attack row, step, serial, chain buffer */
    u8 pad_BC4[0xBD8 - 0xBC4];
    void *gun_target_now_;         /* 0xBD8: [0x1A57B8] Target the gun in hand aims at this frame; cleared by hero_head_look */
    /* 0xBDC: attack_row (size not stated): [0x1A57BC] Attack table row: 0-2 combo, 3 throw, 4 jump attack (grind: 0, 1) */
    u8 pad_BDC[0xBDE - 0xBDC];
    /* 0xBDE: attack_clank_latch (size not stated): [0x1A57BE] Set by a clank or first hit; a new attack clears it; no more clank... */
    u8 pad_BDE[0xBF4 - 0xBDE];
    struct Moby *body_set;         /* 0xBF4: [0x1A57D4] [PAL] The body bodySet gave him; bodyRestore clears its mode bits 6, then this */
    struct Moby *hero_moby_c18;    /* 0xBF8: [0x1A57D8] The hero's moby (hero struct + 0xC18) */
    /* [PAL] 0xBF8: Ratchet's own moby: func_L01_004ED658 makes it the body (+0x25C0) again */
    struct Moby *guise_moby;       /* 0xBFC: [0x1A57DC] [PAL] The disguise's moby: guiseSpawn (func_L01_004F5DC8) spawns class
                                    * 0x173B (0x1A4E when loaded) here and passes it to bodySet as kind 3; bodyRestore removes it */
    f32 anim_rate;                 /* 0xC00: [0x1A57E0] Animation speed; advances rate x 0x1A57E4 frames a tick; swims and... */
    f32 anim_key_rate;             /* 0xC04: [0x1A57E4] 1 / current keyframe's ticks (0.5); 1 / blend ticks during a blend */
    /* 0xC08: anim_flags (size not stated): [0x1A57E8] Animation flags: & 2 probably the sequence's end; bit 2 stops the... */
    u8 pad_C08[0xC18 - 0xC08];
    f32 anim_frame;                /* 0xC18: [0x1A57F8] Animation frame (time stamps / 16, interpolated); melee windows us... */
    f32 anim_step;                 /* 0xC1C: [0x1A57FC] Last tick's step [type inferred] */
    u8 pad_C20[0xC30 - 0xC20];
    Vec4f attach_mats[9][4];       /* 0xC30: [0x1A5810] 9 x 0x40 attach matrices from his joints (0 right hand 56, 2 joint... */
    /* 0xE70: hold_layers (size not stated): [0x1A5A50] Two arm hold layers (layer +0x08 weight, +0x18 hold class, +0x34 l... */
    u8 pad_E70[0xE78 - 0xE70];
    /* 0xE78: fire_layers (size not stated): [0x1A5A58] Two arm layers of the arms-only firing animation */
    u8 pad_E78[0xE84 - 0xE78];
    /* 0xE84: fire_layers_fade (size not stated): [0x1A5A64] 0 while the firing layers are in, 1 or 2 as they fade out */
    u8 pad_E84[0x11E0 - 0xE84];
    u8 item_slots[7][0x50];        /* 0x11E0: [0x1A5DC0] Seven item slots of 0x50, the moby at +0x20 */
    /* 0x1200: hand_moby (inside the field above): [0x1A5DE0] The gun or item moby in his hand (slot 0 +0x20) */
    /* 0x1210: fire_button (size not stated): [0x1A5DF0] Button the item fires on: 0x80 (Square) wrench, 0x20 (Circle) guns */
    /* 0x121A: wrench_thrown (size not stated): [0x1A5DFA] Set while the thrown wrench (or whip) is out; no attack until caught */
    /* 0x1220: hand_ticks (inside the field above): [0x1A5E00] Frames the item has been in hand; restarts at 3 as the hand change... */
    /* 0x1224: hand_state (inside the field above): [0x1A5E04] 2 item in hand, 3 changing, 0 empty */
    /* 0x1228: held_item (size not stated): [0x1A5E08] Item in his hand: 9 wrench, 0 while changing */
    /* 0x12F0: back_pack (inside the field above): [0x1A5ED0] The back slot's pack moby (heli-pack 0x25F or thruster-pack) */
    /* 0x12F4: back_clank (inside the field above): [0x1A5ED4] Clank's moby on his back (class 0x259) */
    /* 0x1314: back_state (size not stated): [0x1A5EF4] Back slot state: 2 once its mobys exist */
    /* 0x1318: back_item (size not stated): [0x1A5EF8] Back slot's item when its pack was made (saved one, else 2, or 3) */
    u8 pad_1410[0x1420 - 0x1410];
    Vec4f lockon_strafe_heading_vec; /* 0x1420: [0x1A6000] Lock-on block +0x00: strafe heading as a vector */
    void *lockon_target;           /* 0x1430: [0x1A6010] Lock-on block +0x10: the moby locked on to, or 0 */
    s16 lockon_strafing;           /* 0x1434: [0x1A6014] +0x14: 1 while L2/R2 held, 2 from the first-person and lock-strafe... */
    u8 lockon_strafe_back;         /* 0x1436: [0x1A6016] +0x16: strafing backwards with the stick past 0.15 [type inferred] */
    u8 lockon_strafe_dir;          /* 0x1437: [0x1A6017] +0x17: stick sector vs the camera: left 0, right 1, forward 2, back 3 [type inferred] */
    f32 lockon_strafe_heading;     /* 0x1438: [0x1A6018] +0x18: yaw the strafe moves along (the move angle) */
    f32 lockon_strafe_turn_rate;   /* 0x143C: [0x1A601C] +0x1C: hero_strafe_turn's own yaw rate */
    u8 pad_1440[0x144C - 0x1440];
    s16 lockon_strafe_rev_timers[2]; /* 0x144C: [0x1A602C] +0x2C: 3-frame timers, +0 strafing right, +2 strafing left */
    u8 pad_1450[0x1460 - 0x1450];
    void *lock_reticle_target_;    /* 0x1460: [0x1A6040] Target the lock reticle shows (fades out before a change) */
    f32 lock_reticle_fade_;        /* 0x1464: [0x1A6044] Reticle fade 0..1, 0.1 a frame */
    f32 lock_reticle_spin_;        /* 0x1468: [0x1A6048] Reticle spin, 45 deg/s */
    u8 pad_146C[0x1474 - 0x146C];
    /* 0x1474: strafe_flag_wade (size not stated): [0x1A6054] A strafe flag the wading entry tests. Doubt: strafing is at 0x1A6014 */
    u8 pad_1474[0x1476 - 0x1474];
    u8 in_puddle;                  /* 0x1476: [0x1A6056] Set on material 14 (a puddle); splashes without wading */
    u8 pad_1477[0x1479 - 0x1477];
    u8 walk_slow_flag;             /* 0x1479: [0x1A6059] Set: the walk's target speed x 0.85 in level 21 [type inferred] */
    u8 pad_147A[0x1520 - 0x147A];
    Vec4f look_eye;                /* 0x1520: [0x1A6100] Free-look block +0x00: the eye point */
    Vec4f look_cam_fwd_copy;       /* 0x1530: [0x1A6110] Camera's forward copied here by hero_camera_set(1) and (2) */
    Vec4f look_cam_matrix[4];      /* 0x1540: [0x1A6120] Free-look camera +0x00: matrix rows forward, left, up */
    /* 0x1570: look_cam_pos (inside the field above): [0x1A6150] Free-look camera +0x30: position, copied by camera modes 4 and 0x20 */
    f32 look_cam_yaw;              /* 0x1580: [0x1A6160] Free-look camera +0x40: yaw */
    u8 pad_1584[0x1588 - 0x1584];
    /* 0x1588: look_cam_yaw_speeds (size not stated): [0x1A6168] +0x48-+0x5C: yaw speed, max speeds and rates */
    u8 pad_1588[0x1598 - 0x1588];
    /* 0x1598: look_cam_k58 (size not stated): [0x1A6178] +0x58: a constant that is 0, so the quick turn's speed is uncut */
    u8 pad_1598[0x15A0 - 0x1598];
    f32 look_cam_pitch;            /* 0x15A0: [0x1A6180] +0x60: pitch, positive looks down; lock-strafe gun arm follows it */
    u8 pad_15A4[0x15A8 - 0x15A4];
    /* 0x15A8: look_cam_pitch_speeds (size not stated): [0x1A6188] +0x68-+0x7C: pitch speed, max speed, rate and target factors */
    u8 pad_15A8[0x15C0 - 0x15A8];
    /* 0x15C0: look_cam_quick_turn (size not stated): [0x1A61A0] +0x80: quick-turn state */
    u8 pad_15C0[0x15CC - 0x15C0];
    void *look_cam_target;         /* 0x15CC: [0x1A61AC] +0x8C: the free-look camera's target */
    u8 pad_15D0[0x15F0 - 0x15D0];
    f32 look_cam_weight;           /* 0x15F0: [0x1A61D0] +0xB0: target weight, 1 for a ray hit, else (cos a - cos15)/(1 - c... */
    f32 look_cam_limit_down;       /* 0x15F4: [0x1A61D4] +0xB4: pitch limit down [type inferred] */
    f32 look_cam_limit_up;         /* 0x15F8: [0x1A61D8] +0xB8: pitch limit up [type inferred] */
    struct Moby *hero_moby_161c;   /* 0x15FC: [0x1A61DC] The hero's moby (hero struct + 0x161C), inside the free-look block */
    Vec4f look_cam_offset;         /* 0x1600: [0x1A61E0] +0xC0: offset in the camera's axes, (-6, 0, 0) lock-strafe, 0 firs... */
    u8 pad_1610[0x1620 - 0x1610];
    /* 0x1620: look_cam_flags (size not stated): [0x1A6200] +0xE0: flags; bit 0 the look in third person (both sticks, d-pad) */
    u8 pad_1620[0x1630 - 0x1620];
    /* 0x1630: look_cam_facing (size not stated): [0x1A6210] +0xF0: facing */
    u8 pad_1630[0x1650 - 0x1630];
    Vec4f look_cam_aim_pos;        /* 0x1650: [0x1A6230] +0x110: the point the free look aims at (30 u ray hit or end) */
    f32 look_cam_range;            /* 0x1660: [0x1A6240] +0x120: range, 30 [type inferred] */
    f32 look_cam_offset_len;       /* 0x1664: [0x1A6244] +0x124: lock-strafe camera's current distance behind the eye */
    f32 look_cam_offset_len_spd;   /* 0x1668: [0x1A6248] +0x128: its speed [type inferred] */
    u8 pad_166C[0x16B0 - 0x166C];
    /* 0x16B0: hero_camera_mode (size not stated): [0x1A6290] Free-look block +0x190: 0 follow, 1 lock-strafe, 2 first person */
    u8 pad_16B0[0x16CC - 0x16B0];
    f32 look_eye_height;           /* 0x16CC: [0x1A62AC] +0x1AC: eye height above the hero; 2.0 lock-strafe, 1.75 first person */
    f32 look_eye_height_speed;     /* 0x16D0: [0x1A62B0] The eye height's speed (+4) [type inferred] */
    /* 0x16D4: crosshair_pulse (size not stated): [0x1A62B4] The crosshair's pulse phase */
    u8 pad_16D4[0x16D8 - 0x16D4];
    /* 0x16D8: crosshair_alpha (size not stated): [0x1A62B8] The crosshair's fade-in count (to 20) */
    u8 pad_16D8[0x16E0 - 0x16D8];
    Vec4f hand_history[16][4];     /* 0x16E0: [0x1A62C0] 16 frames of the hand's matrix (averaged for a held gun with 0x1DB... */
    u8 pad_1AE0[0x2260 - 0x1AE0];
    f32 stick_x;                   /* 0x2260: [0x1A6E40] Left stick x after the pad's dead zone, as the hero sees it. Match... */
    f32 stick_y;                   /* 0x2264: [0x1A6E44] Left stick y (forward positive), as stick_x */
    u8 pad_2268[0x25C0 - 0x2268];
    struct Moby *hero_moby;        /* 0x25C0: [0x1A71A0] The hero's moby (hero struct + 0x25E0); the holo shield copies its... */
    s32 state;                     /* 0x25C4: [0x1A71A4] Hero state. Verified: 24 (ledge idle) in the ledge savestate, and... */
    s32 substate;                  /* 0x25C8: [0x1A71A8] meaning not checked */
    s32 state_type;                /* 0x25CC: [0x1A71AC] State category. Verified pairs: walk=1, crouch=12, all jump states... */
    s32 prev_state;                /* 0x25D0: [0x1A71B0] Previous state: equal to the old state at all 54 transitions in th... */
    /* 0x25D4: prev_state? (size not stated): [0x1A71B4] Probably the previous state. CONFLICT: hero.toml prev_state is +0x... */
    u8 pad_25D4[0x25E4 - 0x25D4];
    u8 body_kind;                  /* 0x25E4: [0x1A71C4] Critter mode; 1 while he plays Clank; camera copies it to 0x1E2D3B [type inferred] */
    /* [PAL] 0x25E4: the body's kind: 0 Ratchet, 1 Clank, 2 Giant Clank, 3 the disguise (critter_mode in open-rac-engine).
     * func_L01_004ED658 tests it for 1 (Clank's mobys, health) and sets 0; func_L01_004F5DC8 passes 3 to bodySet. Kinds 1
     * and 2 are bodySet's from the savegame restore with classes 0x0057 and 0x01A3, live */
    u8 look_ready_;                /* 0x25E5: [0x1A71C5] Set by the look camera once half blended; lets look states snap fa... */
    u8 pad_25E6[0x25E8 - 0x25E6];
    /* 0x25E8: unk_71c8 (size not stated): [0x1A71C8] Set with no_firing by the hand's update in swim states; tested on... */
    u8 pad_25E8[0x25E9 - 0x25E8];
    u8 firing;                     /* 0x25E9: [0x1A71C9] Set by hero_fire_anim, cleared when the firing animation ends [type inferred] */
    u8 wading;                     /* 0x25EA: [0x1A71CA] Set in water 0.25-0.85 u deep (not a puddle); walk runs as 117 */
    u8 firing_held;                /* 0x25EB: [0x1A71CB] Row +0x30 copied by hero_fire_anim: 1 for hold-to-fire guns */
    /* 0x25EC: hold_type (size not stated): [0x1A71CC] Hand item's hold (row +0x18): 0 none, 1 one hand, 2 both */
    u8 pad_25EC[0x25ED - 0x25EC];
    u8 no_firing;                  /* 0x25ED: [0x1A71CD] Guns refuse to fire while set; set for ledge states and others */
    u8 pad_25EE[0x25F0 - 0x25EE];
    /* 0x25F0: no_hold (size not stated): [0x1A71D0] Set for states 23-27 (ledges): hold layers leave, none starts */
    u8 pad_25F0[0x25F2 - 0x25F0];
    /* 0x25F2: death_reported (size not stated): [0x1A71D2] Set to 1 when the death is reported; the level respawns him */
    u8 pad_25F2[0x25F3 - 0x25F2];
    /* 0x25F3: pickup_instant (size not stated): [0x1A71D3] Set: ammo pickups are taken at once */
    u8 pad_25F3[0x25F7 - 0x25F3];
    u8 area;                       /* 0x25F7: [0x1A71D7] The area he is in, 0xFF none; checkpoints set it */
    /* 0x25F8: hand_item_request (size not stated): [0x1A71D8] Hand item asked for (quick select/switch); 0xCC none */
    u8 pad_25F8[0x2630 - 0x25F8];
    /* 0x2630: remembered_gun (size not stated): [0x1A7210] Gun remembered when Square brings out the wrench */
    u8 pad_2630[0x266C - 0x2630];
    f32 yaw_history[32];           /* 0x266C: [0x1A724C] His yaw at the start of each of the last 32 frames */
    /* 0x26EC: yaw_history_next (size not stated): [0x1A72CC] Next slot of yaw_history */
    u8 pad_26EC[0x26F0 - 0x26EC];
    /* 0x26F0: yaw_history_count (size not stated): [0x1A72D0] Count of yaw_history */
    u8 pad_26F0[0x27FC - 0x26F0];
    /* 0x27FC: look_at_list (size not stated): [0x1A73DC] The look-at list (the head looks at the nearest every 7th frame) */
    u8 pad_27FC[0x280C - 0x27FC];
    /* 0x280C: camera_request (size not stated): [0x1A73EC] Camera mode he asks for: 4 look, 0x51 targeting, 7 swing, 0 or 3... */
    u8 pad_280C[0x2824 - 0x280C];
    f32 pickup_radius_;            /* 0x2824: [0x1A7404] How far across pickups are taken: 8.7, 17.0 Bolt Grabber V2, 2.125... */
    f32 pickup_height_;            /* 0x2828: [0x1A7408] How far up pickups are taken: 3.0, 4.5, 1.25 critter. Sym: hero +0... */
    u8 pad_282C[0x2838 - 0x282C];
    f32 stick_mag;                 /* 0x2838: [0x1A7418] (max(|x|,|y|) + length) / 2 of the stick, clamped to 1. Checked in... */
    u8 pad_283C[0x2848 - 0x283C];
    f32 water_depth;               /* 0x2848: [0x1A7428] Water surface less the floor; 0.25-0.85 sets wading [type inferred] */
    u8 pad_284C[0x2850 - 0x284C];
    s32 health;                    /* 0x2850: [0x1A7430] Health: below 1, idle, walk and hit recovery go to death (57) */
    s32 health_clank;              /* 0x2854: [0x1A7434] [PAL] Clank's health, kept here by func_L01_004ED658 when he stops */
    s16 health_ratchet;            /* 0x2858: [0x1A7438] [PAL] Ratchet's health, kept while he plays Clank; func_L01_004ED658
                                    * puts it back in +0x2850 */
    u8 pad_285A[0x2870 - 0x285A];
    /* 0x2870: clank_fidget_timer (size not stated): [0x1A7450] Ticks to Clank's next fidget, counted only while he could fidget */
    u8 pad_2870[0x2874 - 0x2870];
    /* 0x2874: gun_arm_raised (size not stated): [0x1A7454] A wall close in front: the gun points up */
    u8 pad_2874[0x287E - 0x2874];
    s16 quick_select_delay;        /* 0x287E: [0x1A745E] 27 or 15 frames after the ring opens; then pad +0x1CC = 2 */
    s16 quick_switch_tap;          /* 0x2880: [0x1A7460] 20 on a Triangle press; letting go meanwhile asks for a switch */
    s16 quick_switch_recent_;      /* 0x2882: [0x1A7462] 20 on a tap; the ring's input delay becomes 27 */
    u8 pad_2884[0x288C - 0x2884];
    s16 guise_timer;               /* 0x288C: [0x1A746C] [PAL] Counts down; at 0 the hero puts the disguise on or takes it off
                                    * (hero_timers_update); live, writing 1 put it on, on Veldin [type inferred] */
    u8 pad_288E[0x28B4 - 0x288E];
    /* 0x28B4: xp_bar_hi (size not stated): [0x1A7494] EXP bar bound (bar runs between 0x1A7498 and this) */
    u8 pad_28B4[0x28B8 - 0x28B4];
    /* 0x28B8: xp_bar_lo (size not stated): [0x1A7498] EXP bar bound */
    u8 pad_28B8[0x28BC - 0x28B8];
    /* 0x28BC: aiming_fire_wait (size not stated): [0x1A749C] 40 outside state 29; counted down there; Shock Blaster waits for it */
    u8 pad_28BC[0x28C0 - 0x28BC];
    u8 quick_switch_request_;      /* 0x28C0: [0x1A74A0] Set on a Triangle tap, taken by hero_quick_switch */
    u8 pad_28C1[0x28C8 - 0x28C1];
    u8 bolt_mult_exp;              /* 0x28C8: [0x1A74A8] Bolts and XP shift left by it; crate 0x1F7 adds 1 */
    u8 pad_28C9[0x2920 - 0x28C9];
};
/* size 0x2920 */

struct HeroAttackRow {
    s32 kind;                      /* 0x000: Kind: 0 a swing, 1 the jump attack, 2 the throw */
    s32 step;                      /* 0x004: The swing's number */
    s32 chain_before;              /* 0x008: Frame: entering under it chains to the next swing (33, 25, 0, 99, 99) */
    s32 buffer_from;               /* 0x00C: Frame: presses before it never count (presses from) */
    s32 chain_from;                /* 0x010: Frame: a press chains a swing from here */
    s32 jump_from;                 /* 0x014: Frame: jumping out allowed past it */
    s32 end;                       /* 0x018: Frame: past it he walks (stick over 0.8) or idles */
    s32 hit_from;                  /* 0x01C: First frame of the hit window */
    s32 hit_to;                    /* 0x020: Last frame of the hit window */
    s32 unread_0;                  /* 0x024: Not read */
    s32 unread_1;                  /* 0x028: Not read */
};
/* size 0x2C */

/* One of the hero's 7 item slots at 0x1A5DC0 (Hero +0x11E0); slot 0 is the hand, slot 3 the back. Fields marked derived come from documented addresses in slots 0 and 3 */
struct HeroItemSlot {
    u8 pad_0[0x20 - 0x0];
    struct Moby *moby;             /* 0x020: The slot's moby (hand: 0x1A5DE0, the gun in his hand; back: 0x1A5ED0, the pack) */
    struct Moby *moby2;            /* 0x024: Second moby: back slot's Clank (0x1A5ED4). Not stated as a slot field [derived from a slot address] */
    u8 pad_28[0x30 - 0x28];
    /* 0x030: fire_button (size not stated): Hand slot (0x1A5DF0): button it fires on, 0x80 wrench, 0x20 guns. Not stated... [derived from a slot address] */
    u8 pad_30[0x3A - 0x30];
    /* 0x03A: thrown (size not stated): Hand slot (0x1A5DFA): set while the wrench or whip is thrown. Not stated as a... [derived from a slot address] */
    u8 pad_3A[0x40 - 0x3A];
    s32 ticks;                     /* 0x040: Hand slot (0x1A5E00): frames in hand, restarting at 3 on a change. Not stated... [derived from a slot address] */
    s32 state;                     /* 0x044: Hand (0x1A5E04): 2 in hand, 3 changing, 0 empty; back (0x1A5EF4): 2 once its... [derived from a slot address] */
    /* 0x048: item (size not stated): Hand (0x1A5E08): the held item, 9 wrench; back (0x1A5EF8): its item when the... [derived from a slot address] */
    u8 pad_48[0x50 - 0x48];
};
/* size 0x50 */

/* A joint spring: 43 at 0x2F4580 on NTSC-U Veldin; each eases a moby joint's angles */
struct HeroJointSpring {
    u8 pad_0[0x40 - 0x0];
    Vec4f angles;                  /* 0x040: Angles about the joint's own x, y, z (x forward, y left, z up) */
    Vec4f rates;                   /* 0x050: The angles' rates (spring_angle) */
    Vec4f targets;                 /* 0x060: Target angles x, y, z; set afresh each frame, zeroed after the step */
    u8 pad_70[0xA0 - 0x70];
    /* 0x0A0: point (size not stated): The moby's point (class point list) whose joint it turns */
    u8 pad_A0[0xA2 - 0xA0];
    /* 0x0A2: which_moby (size not stated): Which moby: 0, 2, 3, 4, 6 the hero; 1 Clank on his back; 7 another */
    u8 pad_A2[0xA4 - 0xA2];
    f32 gain;                      /* 0x0A4: Spring gain; stays as last set */
    f32 damping;                   /* 0x0A8: Spring damping */
    f32 one;                       /* 0x0AC: 1.0 */
};
/* size 0xB0 */

/* An idle fidget: 4 rows at 0x2F4370 on NTSC-U Veldin; nothing below +0x44 is described */
struct HeroFidget {
    u8 pad_0[0x44 - 0x0];
    /* 0x044: kind (size not stated): 0 to play a sequence, else enter state 60 */
    u8 pad_44[0x48 - 0x44];
    /* 0x048: sequence (size not stated): The sequence (1, 2, 73, 78) */
    u8 pad_48[0x50 - 0x48];
    /* 0x050: hand_item (size not stated): The hand item it needs, -1 any */
    u8 pad_50[0x58 - 0x50];
    /* 0x058: mean_s (size not stated): Mean seconds between plays (chance 1 in mean x 60 a frame) */
    u8 pad_58[0x5C - 0x58];
    /* 0x05C: cooldown_s (size not stated): Cooldown in seconds */
    u8 pad_5C[0x60 - 0x5C];
    /* 0x060: cooldown_left (size not stated): Cooldown counter in frames, counted down every frame */
    u8 pad_60[0x70 - 0x60];
};
/* size 0x70 */

#endif /* STRUCTS_HERO_H */
