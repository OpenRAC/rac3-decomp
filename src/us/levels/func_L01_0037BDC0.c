#include "common.h"

/* NTSC-U counterpart of func_L01_0037CEC8 (src/levels/shared/L01_0037C798.c): 150 -> 180; 0.04 -> 0.0333333; 0.02 -> 0.0166667; 37 -> 45; 300 -> 360 */
#include "vu0.h"
#include "vu0.h"

/* localdecomp:start func_L01_0037BDC0 */
#include "vu0.h"
#include "structs/moby.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
/* player_bolts and the words after it, read as one object (a plain hero_max_health,
   D_00142668, loads late and changes the schedule). */
typedef struct {
    s32 bolts;                     /* 0x142660: player_bolts */
    s32 unk_4;                     /* 0x142664 */
    s32 max_health;                /* 0x142668: hero_max_health */
    s32 unk_C;                     /* 0x14266C */
} Player_37CEC8;
extern Player_37CEC8 D_00142660;
extern s32 D_L01_001D6694_0037BDC0;
/* A damage record, as blast_damage_apply (func_L01_00447718) fills it. */
typedef struct {
    vu0_v4 momentum;               /* 0x00 */
    struct Moby *attacker;         /* 0x10 */
    s32 flags;                     /* 0x14 */
    u8 type;                       /* 0x18 */
    u8 mode;                       /* 0x19 */
    u16 attacker_class;            /* 0x1A */
    f32 damage;                    /* 0x1C */
    s32 pushed;                    /* 0x20 */
    s32 unk_24;                    /* 0x24 */
    s32 extra;                     /* 0x28 */
} DamageIn_37CEC8;
/* A drain link: the Holo Shield links itself to up to 12 mobys within 6 u, drawn as wavering
   beams (open-rac-engine docs/research/weapons.md, "Holo Shield Glove"). */
typedef struct {
    u8 beam[0x20];                 /* 0x00: func_L01_0037C108 draws the beam from the link */
    Vec4f position;                /* 0x20 */
    u8 pad_30[0xA0 - 0x30];
    struct Moby *shield;           /* 0xA0: the shield that made the link */
    struct Moby *moby;             /* 0xA4: the linked moby */
    u8 pad_A8[0xB0 - 0xA8];
} HoloLink_37CEC8;
/* The Holo Shield's pvars (class 0x186D; weapons.md, "Holo Shield Glove"). */
typedef struct {
    u8 pad_0[0x20];
    s32 heal_timer;                /* 0x20: 45 frames (45 on NTSC-U) between points of health */
    u8 pad_24[0x26 - 0x24];
    s16 hits;                      /* 0x26: hits left */
    u8 pad_28[0x54 - 0x28];
    s32 heal;                      /* 0x54: health a heal gives, 1 */
    u8 pad_58[0x64 - 0x58];
    s32 drain_timer;               /* 0x64: 180 frames (180 on NTSC-U) between drain hits */
    u8 pad_68[0x90 - 0x68];
    HoloLink_37CEC8 links[12];     /* 0x90 */
} HoloShield_37CEC8;
/* holo_drain_update: the Holo Shield's drain: while a living enemy is linked, hits each linked
   enemy for 1 when the shared drain timer runs out, and while the hero is linked and within 5 u
   (25 squared), gives him a point of health up to his maximum, which costs the shield a hit. */
void func_L01_0037BDC0(struct Moby *shield) {
    extern f32 *func_0037E0B8(struct Moby *);
    extern s32 func_00388398(s32 *);
    extern void func_L01_00443610(void *, struct Moby *, s32, f32);
    extern void func_L01_00443840(struct Moby *, void *);
    extern void func_L01_0037C108(struct Moby *, void *);
    extern f32 func_L01_0040C018(void *, void *);
    extern s32 func_0037E1D8(s32);
    extern void func_0037E2F0(void *, f32, f32);
    extern void func_L01_00468DC0(void *, void *, u32, s32, s32, s32, s32, s32, f32);
    extern void func_003DF7C0(s32);
    DamageIn_37CEC8 hit;
    HoloShield_37CEC8 *vars = shield->pvar;
    HoloLink_37CEC8 *link;
    HoloLink_37CEC8 *heal_link;
    u8 *at;
    Vec4f *position;
    struct Moby **linked;
    struct Moby *target;
    f32 *health;
    s32 enemy_linked = 0;
    s32 i;
    link = vars->links;
    /* `at` steps through the pvars a link at a time, and the link's shield and moby are read at
       +0x130 and +0x134 from it (links[0]'s): retail addresses them from that cursor, not from
       the link. */
    at = (u8 *)vars;
    do {
        target = *(struct Moby **)(at + 0x134);
        if (*(struct Moby **)(at + 0x130) != shield || target == 0) goto next_link;
        health = func_0037E0B8(target);
        if (health == 0 || target == D_001A4BE0.hero_moby ||
            target == 0 || target->pclass == 0 ||
            ((u8 *)target->pclass)[0x46] != 5 ||  /* the class's category, 5 an enemy */
            (u8)target->state == 0xFE || (u8)target->state == 0xFD || !(*health > 0.0f) ||
            (target->mode_flags & 2) ||
            target->oclass == 0x1AE6 || target->oclass == 0x1A17 ||
            target->oclass == 0x1B27) goto next_link;
        enemy_linked = 1;
        if (D_L01_001D6694_0037BDC0 == 0 && func_00388398(&vars->drain_timer)) {
            func_L01_00443610(&hit, shield, 0x10000, 1.0f);
            hit.type = 0;
            hit.attacker_class = shield->oclass;
            hit.mode = enemy_linked;
            func_L01_00443840(target, &hit);
            vars->drain_timer = 180;
        }
        func_L01_0037C108(shield, link);
next_link:
        at += sizeof(HoloLink_37CEC8);
        link++;
    } while ((s32)at < (s32)((u8 *)vars + 12 * sizeof(HoloLink_37CEC8)));
    i = 0;
    heal_link = vars->links;
    position = &vars->links[0].position;
    linked = &vars->links[0].moby;
    for (; i < 12; i++, heal_link++, position = (Vec4f *)((u8 *)position + sizeof(HoloLink_37CEC8)),
                   linked = (struct Moby **)((u8 *)linked + sizeof(HoloLink_37CEC8))) {
        s32 old, cap, value;
        if (*linked != D_001A4BE0.hero_moby) continue;
        if (!enemy_linked) continue;
        if (!(func_L01_0040C018(&D_001A4BE0.pos, position) < 25.0f)) continue;
        if (func_0037E1D8(2) == 0) {
            func_0037E2F0(&hit.momentum, 0.0166666675f, 0.0333333351f);
            func_L01_00468DC0(&D_001A4BE0.pickup_point, &hit.momentum, 0x50804040, 60,
                func_0037E1D8(255) & 255, 1, 64, 0, 0.4f);
            func_L01_00468DC0(&D_001A4BE0.pickup_point, &hit.momentum, 0x407F7F7F, 60,
                func_0037E1D8(255) & 255, 1, 64, 0, 0.2f);
        }
        cap = D_00142660.max_health;
        if (!D_L01_001D6694_0037BDC0 && func_00388398(&vars->heal_timer)) {
            old = D_001A4BE0.health;
            if (old != 0) {
                value = old + vars->heal;
                if (value > cap) value = cap;
                D_001A4BE0.health = value;
                if (old != value) {
                    vars->heal_timer = 45;
                    vars->hits -= (u16)vars->heal;
                    if (vars->hits < 0) vars->hits = 0;
                    func_003DF7C0(360);
                }
            }
        }
        func_L01_0037C108(shield, heal_link);
        break;
    }
}
/* localdecomp:end func_L01_0037BDC0 */
