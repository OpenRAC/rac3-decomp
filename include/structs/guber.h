#ifndef STRUCTS_GUBER_H
#define STRUCTS_GUBER_H

/*
 * Multiplayer network objects ("gubers") and the units built on them: the Siege Ranger (the
 * Galactic Ranger), Shock Droids, Ball Bots, the turrets. Multiplayer levels only (39 and 40-53
 * and the shared code of both): campaign and multiplayer are different programs, and nothing
 * here is assumed to hold in single player. In particular struct MpPlayer is the multiplayer
 * player, not struct Hero (structs/hero.h, the campaign's Ratchet).
 *
 * A guber is the network side of a moby: moby +0x90 points at it. Its UID is
 * creator << 28 | type << 24 | generation << 12 | index (guber_make_uid): type 0 a player, 2 a
 * unit (the 50-entry unit table, struct GuberUnit), 3 a vehicle, 7 a level moby's (turrets,
 * node columns; struct GuberMoby), others the pool's (struct Guber). Level-code names are in
 * config/names.tsv (guber_*, net_*, ranger_*, node_turret_*).
 *
 * From this project's own research on PAL multiplayer (Bakisi Isles, map 40, 2026-11), checked
 * against the matched C named in each note. Where the note says "live" the field was also read or
 * written in the running game. A field only the research notes name, not this repository's C, is
 * tagged [notes]. Level data sits at other addresses on each map and release; class ids and
 * offsets in a pVar do not. Gaps are pad_*; a field whose size is not known is a comment at its
 * offset.
 */

#include "common.h"
#include "structs/vector.h"

struct Guber;
struct Moby;

/* A guber's vtable. Only the slots read in this repository's C. */
struct GuberVtable {
    u8 pad_0[0x8 - 0x0];
    void (*init)(struct Guber *g);          /* 0x08: run by guber_alloc and guber_alloc_uid on a new entry */
    void (*fn_C)(struct Guber *g);          /* 0x0C: another per-entry hook (guber_alloc, guber_owned_add) */
    void *(*get_moby)(struct Guber *g);     /* 0x10: the guber's moby (node_turret_event) */
    u8 pad_14[0x1C - 0x14];
    s32 (*same_team)(struct Guber *g, s32 team); /* 0x1C: 1 when the guber is of the team code (ranger_take_damage) */
};

/* A guber of a pooled type (guber_alloc; entry size per type): the 0x18-byte header every
 * type shares. The unit table's entries (GuberUnit) and the type-7 ones (GuberMoby) go on from
 * it with their own fields. */
struct Guber {
    u32 uid;                      /* 0x00: guber_make_uid; -1 on a free owned entry */
    s32 owner;                    /* 0x04: the console that owns it (guber_alloc's third argument) */
    s32 state;                    /* 0x08: 1 in use, 2 freed (guber_free), 0 never used */
    struct Guber *next;           /* 0x0C: used / free list link */
    struct Guber *prev;           /* 0x10: previous link */
    struct GuberVtable *vtable;   /* 0x14 */
};
/* size 0x18 */

/* A type-7 guber: a level moby's (guber_type7_create), made for turrets and node columns. */
struct GuberMoby {
    struct Guber head;            /* 0x00 */
    struct Moby *moby;            /* 0x18 */
    u16 mode_flags;               /* 0x1C: the moby's +0x34 when it was made */
    u8 pad_1E[0x20 - 0x1E];
    void (*hook)(struct Moby *m); /* 0x20: the class interface's +8; guber_type7_update calls it with the moby */
    s32 timer;                    /* 0x24: frame at which guber_type7_update calls class interface +0x14; -1 none */
    u8 pad_28[0x2C - 0x28];
    u8 elect;                     /* 0x2C: set = this guber takes part in the ownership election (the last argument of guber_type7_create) */
};

/* One entry of the unit table (moby_guber_attach; 50 entries, 0x44 bytes): Rangers, Shock
 * Droids, Ball Bots and their spawners. */
struct GuberUnit {
    u32 uid;                      /* 0x00 */
    u8 pad_4[0x14 - 0x4];
    struct GuberVtable *vtable;   /* 0x14 */
    u8 pad_18[0x1C - 0x18];
    struct Moby *moby;            /* 0x1C */
    s32 time;                     /* 0x20: frame it was attached */
    u8 pad_24[0x28 - 0x24];
    void *update;                 /* 0x28: the class table row's update callback (net_class_register) */
    void *think;                  /* 0x2C: the row's think callback */
    u8 kind;                      /* 0x30: the creator's kind byte (net_class_moby) */
    u8 active;                    /* 0x31: 1 while in use (moby_guber_release clears it) */
    u8 pad_32[0x38 - 0x32];
    s32 zero;                     /* 0x38: set to 0 */
    s32 sender;                   /* 0x3C: value2 given to moby_guber_attach (the create message's sender) */
    s32 time2;                    /* 0x40: the frame again */
};
/* size 0x44 */

/* A row of the class table (net_class_register; 10 rows at D_L40_00340030). */
struct NetClassRow {
    s32 class_id;                 /* 0x00: 0 = free row */
    void *update;                 /* 0x04 */
    void *think;                  /* 0x08 */
    void *create;                 /* 0x0C */
};
/* size 0x10 */

/* A network message's header (net_msg_header); the class's own data follows it. */
struct NetMsgHeader {
    s32 size;                     /* 0x00: the whole message, written by the sender after its data */
    s32 sender;                   /* 0x04: the console's client index */
    s32 type;                     /* 0x08: 0 create, 1 update (a think's message), 2 destroy */
    u32 uid;                      /* 0x0C */
    s32 time;                     /* 0x10: the frame it is for (the sender's frame counter + a delay) */
    s32 class_id;                 /* 0x14 */
};
/* size 0x18 */

/* One entry of the target registry (target_registry_add; 40 entries, 0x0C bytes); the shared
 * AI target finder (target_find) scans it. */
struct TargetEntry {
    u32 uid;                      /* 0x00: 0 = free */
    s32 team_code;                /* 0x04: 0 Blue, 1 Red, 6 node defenders (the notes' ids) */
    struct GuberUnit *guber;      /* 0x08: the moby's object (guber_find of the UID) */
};
/* size 0xC */

/* The Siege Ranger legs' (class 0x109F) pVar, struct Moby +0x68; the torso (0x109E) has none of
 * its own. The pVar is 0x3E0 bytes; this struct stops at 0x360, the last field this repository's
 * C reads as a whole word (the fields past it are noted below). The first 0x30 bytes are a
 * pointer table that the create callback fills (ranger_net_create). */
struct RangerPvar {
    void *target_vars;            /* 0x000: -> +0x30 */
    u8 pad_4[0xC - 0x4];
    void *ptr_0C;                 /* 0x00C: -> +0x220 */
    void *ptr_10;                 /* 0x010: -> +0x160 */
    u8 pad_14[0x1C - 0x14];
    void *ptr_1C;                 /* 0x01C: -> +0x70 */
    u8 pad_20[0x30 - 0x20];
    f32 health;                   /* 0x030: TargetVars health; set to the base HP (+0x3D0) on respawn; 20 when 0 in state-0 init */
    s16 health_max;               /* 0x034: TargetVars, the same value as an integer */
    s16 hit_cooldown;             /* 0x036: frames; 8 after a hit, 0x32 after one of class 0x108F (ranger_take_damage) */
    u8 pad_38[0x3E - 0x38];
    u8 target_state;              /* 0x03E: TargetVars state; the create callback sets 1; the notes: 2 = dead [notes] */
    u8 pad_3F[0x160 - 0x3F];
    /* 0x160: hit and damage block: 0x167 colour flash set to 0xC8 on a hit (ranger_take_damage) */
    u8 pad_160[0x220 - 0x160];
    /* 0x220: target position [notes] */
    u8 pad_220[0x240 - 0x220];
    Vec4f home;                   /* 0x240: home position, written by ranger_state0_init */
    u8 pad_250[0x270 - 0x250];
    struct Moby *torso;           /* 0x270: the torso moby (class 0x109E); 0 or state 0xFE/0xFD = spawn again */
    u8 pad_274[0x290 - 0x274];
    s32 node;                     /* 0x290: path point it is walking to; the create callback sets 0 */
    u8 pad_294[0x2A0 - 0x294];
    struct Moby *attacker;        /* 0x2A0: the shooter of the hit it took (cleared each ranger_take_damage) */
    u8 pad_2A4[0x2B4 - 0x2A4];
    s32 target_uid;               /* 0x2B4: written by ranger_net_think after target_find */
    s32 team;                     /* 0x2B8: -1 dormant twin, 0 Blue, 1 Red, 2 neutral; from the create message */
    u8 pad_2BC[0x2C0 - 0x2BC];
    f32 aggro_range;              /* 0x2C0: target_find's range */
    u8 pad_2C4[0x2CC - 0x2C4];
    s32 dead_frames;              /* 0x2CC: frames spent at 0 health; past 200 the guber is destroyed */
    u8 pad_2D0[0x2F0 - 0x2D0];
    s32 team_code;                /* 0x2F0: 0 Blue, 1 Red, 6 for a team of 2 or more, -1 none; the registry's code */
    u8 pad_2F4[0x348 - 0x2F4];
    s32 boot;                     /* 0x348: 0 new, 1 create message due, 2 running (ranger_legs_update) */
    s32 respawn_frames;           /* 0x34C: counts up in state 0x25 until the respawn */
    Vec4f home_copy;              /* 0x350: position at the first frame (ranger_update_prelude) */
    /* 0x360: think state (ranger_net_think: 1 find a target, 2 keep it); the struct goes on to
     * 0x3E0 with +0x37C player_in_way, +0x3D0 base HP and +0x3D8 the respawn delay */
};

/* The multiplayer player (D_L39_0024CE20 holds 8 pointers to them), not the campaign's hero.
 * Only the fields this repository's C reads. */
struct MpPlayer {
    u32 uid;                      /* 0x0000: its guber UID (guber_find type 0 compares it) */
    u8 pad_4[0x24C9 - 0x4];
    u8 local_index;               /* 0x24C9: index among the local heroes (hero_local_index) */
    u8 pad_24CA[0x2524 - 0x24CA];
    void *hero_moby;              /* 0x2524: the hero moby; turrets aim at its +0x00 sphere centre [notes] */
    void *vehicle;                /* 0x2528: the player's vehicle, whose +0x2D0 is its moby [notes] */
    u8 pad_252C[0x2548 - 0x252C];
    s32 team;                     /* 0x2548: 0 Blue, 1 Red; turrets and gatlings skip the same team */
};

#endif /* STRUCTS_GUBER_H */
