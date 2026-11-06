#ifndef STRUCTS_MOBY_H
#define STRUCTS_MOBY_H

/*
 * A moby: one 0x100-byte record per live object in a global array; its class's per-level
 * update function gets it in $a0. Its class's data (pClass) starts with struct MobyClass; a
 * class's sound table (class +0x28) holds struct MobyClassSound entries. The offsets of
 * pClass, oClass and the pvars pointer are not stated.
 *
 * From open-rac-engine (GPL-3.0-or-later; THIRD_PARTY_NOTICES.md) at c9306a5:
 * docs/research/moby-format.md, effects.md, weapons.md, camera.md and
 * re/SCUS-97353/symbols.toml. Read in UYA NTSC-U's code and data, some of it checked in the
 * running game; R&C3 and UYA are one game, so the layouts hold for PAL, but level data sits at
 * other addresses in each release and level. Only the fields it names: gaps are pad_*, and a
 * field whose size it doesn't state, or that lies inside another, is a comment at its offset.
 * A field named like a names.h macro ends in _.
 */

#include "common.h"
#include "structs/vector.h"

struct Moby {
    u8 pad_0[0x10 - 0x0];
    Vec4f position;                /* 0x010: World position; the root joint's world position */
    s8 state;                      /* 0x020: State byte (moby_set_state); negative = not living for group counts; -2/-3 =... */
    u8 pad_21[0x23 - 0x21];
    u8 opacity;                    /* 0x023: Opacity/alpha, 0x80 from moby_init; rings fade it, the holo shield spawns at... */
    u8 pad_24[0x2C - 0x24];
    f32 scale;                     /* 0x02C: Scale; starts as the class's (class +0x24, moby_init); class units are scale/... */
    u8 pad_30[0x34 - 0x30];
    /* 0x034: mode_flags (size not stated): Mode flags: 0x20 has a damage record; 0x100 draw +0xC0 matrix as set; 0x41 se... */
    u8 pad_34[0x3C - 0x34];
    u8 colour[3];                  /* 0x03C: Tint r,g,b at +0x3C..+0x3E, 0x80 = 1 (moby_set_colour); from class +0x40. CON... */
    u8 pad_3F[0x44 - 0x3F];
    f32 anim_time;                 /* 0x044: Keyframe time between previous and current keyframe; hero_anim_set sets it to 0 */
    f32 anim_speed;                /* 0x048: Animation speed: advances speed x sequence rate a tick; 1 from moby_init, a b... */
    u8 pad_4C[0x50 - 0x4C];
    void *anim_layer;              /* 0x050: Animation layer link (moby_anim_layer_new; 16 layers of 0x40 bytes at 0x1F47C0) */
    void *joint_layers;            /* 0x054: Joint layers listed from here (joint_layer_drive hooks 0x80-byte layers on po... */
    void *prev_keyframe;           /* 0x058: Previous keyframe, pointing into the sequence's frames (moby_anim_keys) */
    void *cur_keyframe;            /* 0x05C: Current keyframe (moby_anim_keys) */
    /* 0x060: anim_flags (size not stated): Bit 0 set on a keyframe step, bit 1 (0x02) on the frame the sequence wraps */
    u8 pad_60[0x64 - 0x60];
    void *update;                  /* 0x064: Update function (the heli-pack moby's is heli_pack_update) */
    void *damage_link;             /* 0x068: Points at a block whose first word is the damage record, read when +0x34 has... */
    u8 pad_6C[0x7C - 0x6C];
    /* 0x07C: bangles (size not stated): Bangle mask: bit n shows bangle n; gun updates set it by level (e.g. 2 at V2... [inferred] */
    u8 pad_7C[0x7E - 0x7C];
    u8 armor_tint;                 /* 0x07E: Byte: armor_change tints the hero moby by the armor kept when it is 1-3. Doub... */
    u8 pad_7F[0x80 - 0x7F];
    Vec4f bsphere_class;           /* 0x080: Bounding sphere in class units; held the class's in the agents' savestate */
    u8 pad_90[0x94 - 0x90];
    s8 prev_state;                 /* 0x094: Previous state, kept by moby_set_state when it sets +0x20 [type inferred] */
    u8 pad_95[0x98 - 0x95];
    void *coll_record;             /* 0x098: A record whose +8 set means the object can take damage (0x4435E8); owner of +... */
    u8 pad_9C[0xA8 - 0x9C];
    void *damage_pending;          /* 0x0A8: Pending damage record; a hit at least as strong replaces it, a weaker one onl... */
    u8 pad_AC[0xB0 - 0xAC];
    /* 0x0B0: area (size not stated): Checkpoint mobys: the area (to 0x1A71D7). Bolt drops index 0x1DFF00 by a kill... */
    u8 pad_B0[0xB1 - 0xB0];
    /* 0x0B1: flag_b1 (size not stated): With +0xB0, picks a bank-reward trigger's 0x1BBC40 progress bit; owner of the... */
    u8 pad_B1[0xB4 - 0xB1];
    /* 0x0B4: crate_bolts (size not stated): Bolt crates: the bolts it holds (11, 44 or 61 on Veldin) */
    u8 pad_B4[0xC0 - 0xB4];
    Vec4f matrix[3];               /* 0x0C0: Rotation matrix, rows map class axes to world (rows +0xC0, +0xD0, +0xE0; to +... */
    /* 0x0D0: matrix_y (inside the field above): Matrix y row; a gun's barrel runs along -y; the whip's wave stretches it to l... */
    Vec4f rotation;                /* 0x0F0: Rotation as angles x, y, z; the matrix is made from it unless +0x34 has 0x100 */
    /* 0x0F8: rot_z (inside the field above): Yaw (the whip links' yaw), the z of +0xF0 */
};
/* size 0x100 */

struct MobyClass {
    void *packets;                 /* 0x000: Packet table: high LOD first, then low LOD, then metal; 0 for the hero's clas... */
    u8 packets_hi;                 /* 0x004: High-LOD packet count (hero 60) */
    u8 packets_lo;                 /* 0x005: Low-LOD packet count (hero 22) */
    u8 packets_metal;              /* 0x006: Metal packet count */
    u8 metal_start;                /* 0x007: First metal packet's entry in the packet table */
    /* 0x008: joint_count (size not stated): Joint count (classes of sequences only: 20) */
    u8 pad_8[0xC - 0x8];
    u8 seq_count;                  /* 0x00C: Sequence count */
    u8 sound_count;                /* 0x00D: Count of the sound table's entries (+0x28) */
    u8 pad_E[0xF - 0xE];
    u8 armor_block_qw;             /* 0x00F: Size in quadwords of the per-armor block armor_install copies just before the... */
    u8 pad_10[0x14 - 0x10];
    void *skeleton;                /* 0x014: Skeleton: one 0x40-byte inverse bind matrix (four VU0 columns) per joint; 0 i... */
    void *joint_offsets;           /* 0x018: Joint offsets: 0x10 bytes per joint (x, y, z from the parent, then the parent... */
    void *points;                  /* 0x01C: Point lists (animated-joint lists): count, then per point a u16 count and joi... */
    u8 pad_20[0x24 - 0x20];
    f32 scale;                     /* 0x024: Class scale; one class unit is scale/1024 world units; moby_init copies it to... */
    void *sounds;                  /* 0x028: Sound table: 0x20-byte entries, count at +0x0D */
    u8 bangle_qw;                  /* 0x02C: Bangle table's place in quadwords from the class start, 0 for none. Verified... */
    u8 pad_2D[0x40 - 0x2D];
    /* 0x040: colour (size not stated): Colour that moby_init copies to a new moby */
    u8 pad_40[0x48 - 0x40];
    /* 0x048: sequences (size not stated): Sequence pointers, one per sequence (null if unused) */
    u8 pad_48[0x120 - 0x48];
    void *dive_anim;               /* 0x120: Hero's class: a pointer here must be set for a dive, probably the dive animation */
};

struct MobyClassSound {
    f32 near;                      /* 0x000: Near distance; within it the near volume */
    f32 far;                       /* 0x004: Far distance; past it the far volume */
    /* 0x008: vol_far (size not stated): Volume at far and beyond, out of 0x400 */
    u8 pad_8[0xC - 0x8];
    /* 0x00C: vol_near (size not stated): Volume within near, out of 0x400 (louder ones capped at 0x400 less the fade) */
    u8 pad_C[0x10 - 0xC];
    /* 0x010: pitch_lo (size not stated): Pitch modulation bound, 128ths of a semitone (unit inferred from values) */
    u8 pad_10[0x14 - 0x10];
    /* 0x014: pitch_hi (size not stated): Other pitch modulation bound; picked at random between the two */
    u8 pad_14[0x18 - 0x14];
    u8 loops;                      /* 0x018: Loops; a loop only starts when the call has flag 4 (and the reverse) [type inferred] */
    u8 flags;                      /* 0x019: Flags; bit 0: the volume falls with the square of the distance left [type inferred] */
    /* 0x01A: sound (size not stated): The sound's number in its bank */
    u8 pad_1A[0x1C - 0x1A];
    /* 0x01C: bank (size not stated): The bank: 0 the level's; gadget_install sets a gun's to 4 */
    u8 pad_1C[0x20 - 0x1C];
};
/* size 0x20 */

/* An animation layer: 16 of them at 0x1F47C0 on NTSC-U Veldin, linked from moby +0x50 */
struct MobyAnimLayer {
    u8 pad_0[0x8 - 0x0];
    f32 weight;                    /* 0x008: Weight (hold layers: up 0.25 a frame, down 0.15 under the firing layer, 0.1 l... [type inferred] */
    u8 pad_C[0x18 - 0xC];
    /* 0x018: class (size not stated): The layer's own class, whose keyframes it plays (hold layers: class 1 or 2).... */
    u8 pad_18[0x34 - 0x18];
    /* 0x034: leaving (size not stated): Leaving: set by hero_item_switch when the hold type changes; the layer falls... */
    u8 pad_34[0x40 - 0x34];
};
/* size 0x40 */

/* A joint layer: drives a point's joints (joint_layer_drive); its owner keeps it */
struct MobyJointLayer {
    u8 pad_0[0x4 - 0x0];
    void *joint_matrix;            /* 0x004: The hooked joint's scratchpad matrix (0x70000000 + joint x 0x40) */
    u8 pad_8[0x10 - 0x8];
    /* 0x010: quat (size not stated): Quaternion made from the angles each frame */
    u8 pad_10[0x20 - 0x10];
    Vec4f scale;                   /* 0x020: Scale, taken from the target scale (+0x70) each frame [type inferred] */
    u8 pad_30[0x40 - 0x30];
    Vec4f angles;                  /* 0x040: Angles, sprung to the targets by spring_angle with the caller's gain and damping */
    Vec4f rates;                   /* 0x050: The angles' rates */
    Vec4f targets;                 /* 0x060: Target angles; set back to 0 after each step */
    Vec4f target_scale;            /* 0x070: Target scale; set back to 1.0 after each step (agents at V5: 0.45) [type inferred] */
};
/* size 0x80 */

/* A class's animation sequence header; frame pointers follow at +0x1C, one per keyframe */
struct MobySequence {
    Vec4f bsphere;                 /* 0x000: Bounding sphere */
    u8 frame_count;                /* 0x010: Keyframe count */
    u8 sound;                      /* 0x011: A sound: names a looped sound entry for the sequence (no shot uses one) */
    u8 trigger_count;              /* 0x012: Trigger count: {entry, frame x 16} pairs after the frame table play sounds as... */
    u8 format;                     /* 0x013: 0xFF for an uncompressed sequence, else the number of extra words after the f... */
    u8 pad_14[0x18 - 0x14];
    f32 rate;                      /* 0x018: The sequence's rate; animation advances by moby speed x this (or each keyfram... [type inferred] */
    /* 0x01C: frames (size not stated): Frame pointers, one per keyframe; compressed ones have 0xF in the top 4 bits... */
};
/* size 0x1C */

/* An uncompressed keyframe (or one unpacked); its size in quadwords minus one is at +0x6 */
struct MobyKeyframe {
    f32 inv_ticks;                 /* 0x000: Uncompressed: 1/ticks the keyframe lasts. What an unpacked frame keeps here i... */
    u16 time_stamp;                /* 0x004: Time stamp in sixteenths of an animation frame (here once unpacked) */
    /* 0x006: size_qw (size not stated): Size in quadwords, minus one */
    u8 pad_6[0x8 - 0x6];
    /* 0x008: joints_x8 (size not stated): Joint count x 8 */
    u8 pad_8[0xA - 0x8];
    /* 0x00A: scale_count (size not stated): Scale entry count */
    u8 pad_A[0xE - 0xA];
    /* 0x00E: trans_count (size not stated): Translation entry count */
    u8 pad_E[0x10 - 0xE];
    /* 0x010: rotations (size not stated): Per joint quaternion x,y,z,w (1.0 = 0x8000, stored inverse); then scale and t... */
};

/* A compressed keyframe, as stored */
struct MobyKeyframePacked {
    u16 ticks;                     /* 0x000: Ticks the keyframe lasts */
    u16 time_stamp;                /* 0x002: Time stamp in sixteenths of an animation frame */
    /* 0x004: data (size not stated): Bit stream, byte deltas, 16-bit values, w sign bits, per-entry mode bytes; ba... */
};

/* A compressed sequence's base block */
struct MobyKeyframeBase {
    u32 header;                    /* 0x000: Bits 0-9 offset of the 16-bit values, 10-20 byte deltas, 21-31 sign bits, fro... */
    /* 0x004: rot_bases (size not stated): Per joint base x, y, z; low 2 bits: 0 keep, 1 byte x4, 2 10-bit x4, 3 replace... */
};

#endif /* STRUCTS_MOBY_H */
