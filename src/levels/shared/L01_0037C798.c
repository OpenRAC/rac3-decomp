#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0037C798 */
void func_L01_0037C798(vu0_v4 *p, s32 i) {
    vu0_v4 d;

    vec_sub_ab(&d, &p[i - 2], &p[i - 3]);
    vec_add_ab(&p[i - 1], &p[i - 2], &d);
}
/* localdecomp:end func_L01_0037C798 */

/* localdecomp:start func_L01_0037C7D8 */
void func_L01_0037C7D8(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0037C7D8 */

/* localdecomp:start func_L01_0037C860 */
#include "vu0.h"
void func_L01_0037C860(f32 *out, f32 *a, f32 *b, f32 *c, f32 *d, f32 t) {
    f32 t2, t3, p, q, r, ca, db;
    if (t == 0.0f) { *(vu0_q *)out = *(vu0_q *)a; return; }
    if (t == 1.0f) { *(vu0_q *)out = *(vu0_q *)b; return; }
    t2 = t * t;
    t3 = t2 * t;
    p = (d[0] - b[0]) - (c[0] - a[0]);
    q = (c[0] - a[0]) - p;
    r = b[0] - c[0];
    out[0] = p * t3 + q * t2 + r * t + a[0];
    p = (d[1] - b[1]) - (c[1] - a[1]);
    q = (c[1] - a[1]) - p;
    r = b[1] - c[1];
    out[1] = p * t3 + q * t2 + r * t + a[1];
    p = (d[2] - b[2]) - (c[2] - a[2]);
    q = (c[2] - a[2]) - p;
    r = b[2] - c[2];
    out[2] = p * t3 + q * t2 + r * t + a[2];
    out[3] = 0.0f;
}
/* localdecomp:end func_L01_0037C860 */

INCLUDE_ASM("asm/levels", func_L01_0037C978);

LINKER_REMNANT("asm/levels", func_L01_0037CC28);

INCLUDE_ASM("asm/levels", func_L01_0037CC30);

LINKER_REMNANT("asm/levels", func_L01_0037CEC0);

/* localdecomp:start func_L01_0037CEC8 */
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
extern s32 D_L01_001D6694;
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
    u8 beam[0x20];                 /* 0x00: func_L01_0037D210 draws the beam from the link */
    Vec4f position;                /* 0x20 */
    u8 pad_30[0xA0 - 0x30];
    struct Moby *shield;           /* 0xA0: the shield that made the link */
    struct Moby *moby;             /* 0xA4: the linked moby */
    u8 pad_A8[0xB0 - 0xA8];
} HoloLink_37CEC8;
/* The Holo Shield's pvars (class 0x186D; weapons.md, "Holo Shield Glove"). */
typedef struct {
    u8 pad_0[0x20];
    s32 heal_timer;                /* 0x20: 37 frames (45 on NTSC-U) between points of health */
    u8 pad_24[0x26 - 0x24];
    s16 hits;                      /* 0x26: hits left */
    u8 pad_28[0x54 - 0x28];
    s32 heal;                      /* 0x54: health a heal gives, 1 */
    u8 pad_58[0x64 - 0x58];
    s32 drain_timer;               /* 0x64: 150 frames (180 on NTSC-U) between drain hits */
    u8 pad_68[0x90 - 0x68];
    HoloLink_37CEC8 links[12];     /* 0x90 */
} HoloShield_37CEC8;
/* holo_drain_update: the Holo Shield's drain: while a living enemy is linked, hits each linked
   enemy for 1 when the shared drain timer runs out, and while the hero is linked and within 5 u
   (25 squared), gives him a point of health up to his maximum, which costs the shield a hit. */
void func_L01_0037CEC8(struct Moby *shield) {
    extern f32 *func_00382348(struct Moby *);
    extern s32 func_0038CAD0(s32 *);
    extern void func_L01_00446748(void *, struct Moby *, s32, f32);
    extern void func_L01_00446978(struct Moby *, void *);
    extern void func_L01_0037D210(struct Moby *, void *);
    extern f32 func_L01_0040E548(void *, void *);
    extern s32 func_00382468(s32);
    extern void func_00382580(void *, f32, f32);
    extern void func_L01_0046C470(void *, void *, u32, s32, s32, s32, s32, s32, f32);
    extern void func_003E4D10(s32);
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
        health = func_00382348(target);
        if (health == 0 || target == D_001A4BE0.hero_moby ||
            target == 0 || target->pclass == 0 ||
            ((u8 *)target->pclass)[0x46] != 5 ||  /* the class's category, 5 an enemy */
            (u8)target->state == 0xFE || (u8)target->state == 0xFD || !(*health > 0.0f) ||
            (target->mode_flags & 2) ||
            target->oclass == 0x1AE6 || target->oclass == 0x1A17 ||
            target->oclass == 0x1B27) goto next_link;
        enemy_linked = 1;
        if (D_L01_001D6694 == 0 && func_0038CAD0(&vars->drain_timer)) {
            func_L01_00446748(&hit, shield, 0x10000, 1.0f);
            hit.type = 0;
            hit.attacker_class = shield->oclass;
            hit.mode = enemy_linked;
            func_L01_00446978(target, &hit);
            vars->drain_timer = 150;
        }
        func_L01_0037D210(shield, link);
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
        if (!(func_L01_0040E548(&D_001A4BE0.pos, position) < 25.0f)) continue;
        if (func_00382468(2) == 0) {
            func_00382580(&hit.momentum, 0.020000001415610313f, 0.040000002831220627f);
            func_L01_0046C470(&D_001A4BE0.pickup_point, &hit.momentum, 0x50804040, 60,
                func_00382468(255) & 255, 1, 64, 0, 0.4f);
            func_L01_0046C470(&D_001A4BE0.pickup_point, &hit.momentum, 0x407F7F7F, 60,
                func_00382468(255) & 255, 1, 64, 0, 0.2f);
        }
        cap = D_00142660.max_health;
        if (!D_L01_001D6694 && func_0038CAD0(&vars->heal_timer)) {
            old = D_001A4BE0.health;
            if (old != 0) {
                value = old + vars->heal;
                if (value > cap) value = cap;
                D_001A4BE0.health = value;
                if (old != value) {
                    vars->heal_timer = 37;
                    vars->hits -= (u16)vars->heal;
                    if (vars->hits < 0) vars->hits = 0;
                    func_003E4D10(300);
                }
            }
        }
        func_L01_0037D210(shield, heal_link);
        break;
    }
}
/* localdecomp:end func_L01_0037CEC8 */

INCLUDE_ASM("asm/levels", func_L01_0037D210);

INCLUDE_ASM("asm/levels", func_L01_0037D358);

INCLUDE_ASM("asm/levels", func_L01_0037D920);

INCLUDE_ASM("asm/levels", func_L01_0037DC70);

