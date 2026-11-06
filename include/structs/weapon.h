#ifndef STRUCTS_WEAPON_H
#define STRUCTS_WEAPON_H

/*
 * A row of the weapon table: 0xF0 bytes per item and level (V1 to Omega), static data in each
 * story level's program (on NTSC-U Veldin at 0x2C5640). item_weapon_rows (D_001425C0) holds each
 * item's current row; levelling up follows next_row.
 *
 * From open-rac-engine (GPL-3.0-or-later; THIRD_PARTY_NOTICES.md), docs/research/weapons.md at
 * c9306a5, "The weapon row": read in UYA NTSC-U's code and data. R&C3 and UYA are one game, so the
 * layout holds for PAL. Only the fields it names; gaps are pad_*.
 */

#include "common.h"

struct WeaponRow {
    u8 is_weapon;                  /* 0x00: 1 for a weapon */
    u8 level;                      /* 0x01: 0-7, V1 ... Omega */
    u8 pad_02[2];                  /* 0x02: not read */
    u32 name_text;                 /* 0x04: text number of the name */
    u32 slot;                      /* 0x08: 0 hand, 1 feet, 3 back, 4 body, 6 a camera option */
    s32 matrix_slot;               /* 0x0C: hero matrix its moby goes on: 6 Miniturret Glove, else 0 */
    s32 moby_class[2];             /* 0x10: classes spawned for it in hand, -1 none */
    u8 hold_type;                  /* 0x18: 0 none, 1 one hand, 2 both hands */
    u8 pad_19[0x24 - 0x19];
    s32 fire_anim;                 /* 0x24: firing animation, whole body */
    s32 fire_anim_arms;            /* 0x28: arms only */
    s32 fire_anim_arms_crouch;     /* 0x2C: arms only, in state type HERO_TYPE_CROUCH */
    u8 firing_held;                /* 0x30: copied to the hero's firing_held when firing */
    u8 pad_31[3];
    u16 ammo_text_many;            /* 0x34: "Got %d ... ammo" for several rounds */
    u16 ammo_text_one;             /* 0x36: the same for one round */
    u16 icon;                      /* 0x38: icon on the HUD and the quick-select ring, 0 none */
    u16 ammo_model;                /* 0x3A: a placed ammo pickup of this class fills the gun */
    u8 pad_3C[2];
    u16 vendor_text;               /* 0x3E: vendor description */
    u8 pad_40[4];
    u16 tier_text;                 /* 0x44: name of the tier (V1-V4 share one, V5 and up another) */
    s16 next_row;                  /* 0x46: next level's row, 0 at the end */
    s16 prev_row;                  /* 0x48: previous level's row, 0 at the start */
    u8 pad_4A[2];
    f32 shot_speed;                /* 0x4C: projectile speed in units per second */
    f32 shots_per_second;          /* 0x50: for the guns whose code reads it */
    u8 pad_54[0x68 - 0x54];
    s32 xp_next;                   /* 0x68: total XP at which it leaves this level, 0 none */
    f32 damage;                    /* 0x6C: read by every weapon's code */
    f32 damage_more[3];            /* 0x70: further damages, per weapon (the wrench's jump attack) */
    s32 price;                     /* 0x7C: in bolts, on the V1 row (the Mega upgrade's on its row) */
    u8 pad_80[4];
    u16 round_price;               /* 0x84: one round at the vendor */
    u16 round_price_kind4;         /* 0x86: the same at vendor kind 4 */
    u16 pickup_rounds;             /* 0x88: rounds in each pickup an ammo crate throws out */
    u16 max_ammo;                  /* 0x8A: 0 means no ammo used */
    u8 pad_8C[2];
    u16 start_ammo;                /* 0x8E: ammo when first given */
    u8 pad_90[0xD0 - 0x90];
    s32 level_up_text;             /* 0xD0: message on reaching this level */
    u8 pad_D4[0xF0 - 0xD4];
};

#endif /* STRUCTS_WEAPON_H */
