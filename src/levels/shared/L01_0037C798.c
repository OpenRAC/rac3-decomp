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

/* localdecomp:start func_L01_0037C978 */
void func_L01_0037C978(u8 *moby, s32 id, s32 value)
{
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    u8 *vars = *(u8 **)(moby + 0x68);
    u8 *e;
    u8 *p;
    u8 *rotation;
    s32 i;
    f32 a, b;
    for (i = 0; i < 12; i++) {
        if (*(s32 *)(vars + 0x134 + i * 0xB0) == id) return;
    }
    for (i = 0; i < 12; i++) {
        e = vars + i * 0xB0;
        if (*(s32 *)(e + 0x130) != 0) continue;
        p = vars + 0x90 + i * 0xB0;
        rotation = p + 0x40;
        *(u8 **)(p + 0xA0) = moby;
        *(s32 *)(p + 0xA4) = id;
        ++*(s32 *)(vars + 0x50);
        *(f32 *)(p + 0x50) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(p + 0x54) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(p + 0x58) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(p + 0x74) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(p + 0x78) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(p + 0x7C) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(p + 0x5C) = func_L01_00443A18(0.2f, 0.5f) * 0.5f;
        *(f32 *)(p + 0x60) = func_L01_00443A18(0.2f, 0.5f) * 0.5f;
        *(f32 *)(p + 0x64) = func_L01_00443A18(0.2f, 0.5f) * 0.5f;
        *(f32 *)(p + 0x80) = func_L01_00443A18(0.2f, 0.5f) * 0.5f;
        *(f32 *)(p + 0x84) = func_L01_00443A18(0.2f, 0.5f) * 0.5f;
        *(f32 *)(p + 0x88) = func_L01_00443A18(0.2f, 0.5f) * 0.5f;
        *(f32 *)(p + 0x68) = func_003824E0(3.25f, 4.75f) * 0.25f;
        *(f32 *)(p + 0x6C) = func_003824E0(3.25f, 4.75f) * 0.25f;
        *(f32 *)(p + 0x70) = func_003824E0(3.25f, 4.75f) * 0.25f;
        *(f32 *)(p + 0x8C) = func_003824E0(3.25f, 4.75f) * 0.25f;
        *(f32 *)(p + 0x90) = func_003824E0(3.25f, 4.75f) * 0.25f;
        *(f32 *)(p + 0x94) = func_003824E0(3.25f, 4.75f) * 0.25f;
        *(s32 *)(p + 0x9C) = value;
        *(s32 *)(p + 0x98) = value;
        qzero(p + 0x10);
        qzero(p);
        a = func_00382538();
        b = func_00382538();
        func_00382760(rotation, *(f32 *)(vars + 0x2C), a, b);
        return;
    }
}
/* localdecomp:end func_L01_0037C978 */

LINKER_REMNANT("asm/levels", func_L01_0037CC28);

/* localdecomp:start func_L01_0037CC30 */
#include "vu0.h"
typedef int s128 __attribute__((mode(TI)));
typedef union { u8 b[0x2A00]; s32 i[0xA80]; } Hero;
typedef struct {
    f32 d0, d4, d8, dC;
    f32 e0, e4, e8, eC;
    s128 q20;
    s128 q30;
    u8 p40[0x10];
    f32 f50, f54, f58, f5C, f60, f64, f68, f6C, f70, f74, f78, f7C, f80, f84, f88, f8C, f90, f94;
    u8 timer[8];
    u8 *owner;
    u8 *target;
    u8 pA8[8];
} S_Slot;
typedef struct {
    u8 p0[0x50];
    s32 cnt;
    u8 p54[0x3C];
    S_Slot slots[12];
} S_Obj;

extern u8 D_001A4BE0_0037CC30[];
extern s32 D_L01_001EEA80[];
extern void func_003C2F58(void *, s32, void *);
extern s32 func_003D4D00_0037CC30(void *, s32, f32, void *, void *);
extern void func_L01_0037C978_0037CC30(void *, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_00382348_0037CC30(u8 *);
extern s32 func_0038CAD0_0037CC30(void *);

void func_L01_0037CC30(u8 *a) {
    S_Obj *s5 = *(S_Obj **)(a + 0x68);
    s128 q0;
    s128 tmp;
    S_Slot *p;
    u8 *v;
    s32 n;
    s32 i;
    s32 k;
    u8 *h;
    func_003C2F58(a, 0, &q0);
    n = func_003D4D00_0037CC30(a + 0x10, 1, 6.0f, a, 0);
    for (i = 0; i < n; i++) {
        func_L01_0037C978_0037CC30(a, D_L01_001EEA80[i], 2500);
    }
    for (k = 0; k < 12; k++) {
        if (s5->slots[k].owner != a) continue;
        if (s5->slots[k].target == 0) continue;
        p = &s5->slots[k];
        p->f50 = func_0038DAB8(p->f50, p->f5C);
        p->f54 = func_0038DAB8(p->f54, p->f60);
        p->f58 = func_0038DAB8(p->f58, p->f64);
        p->f74 = func_0038DAB8(p->f74, p->f80);
        p->f78 = func_0038DAB8(p->f78, p->f84);
        p->f7C = func_0038DAB8(p->f7C, p->f88);
        p->d0 = func_0038D098(p->f50) * p->f68;
        p->d4 = func_0038D0B0(p->f54) * p->f6C;
        p->d8 = -func_0038D0B0(p->f58) * p->f70;
        p->e0 = func_0038D098(p->f74) * p->f8C;
        p->e4 = func_0038D0B0(p->f78) * p->f90;
        p->e8 = -func_0038D0B0(p->f7C) * p->f94;
        p->q20 = q0;
        h = D_001A4BE0_0037CC30;
        if (s5->slots[k].target == *(u8 **)(h + 0x25C0)) {
            func_L01_004C7D98(a + 0x10, &tmp);
            func_0038CE20(&tmp, &tmp, 0.8f);
            vec_add_ba(&p->q30, h + 0x80, &tmp);
        } else {
            v = func_00382348_0037CC30(s5->slots[k].target);
            if (v != 0) {
                func_L01_004C7D98(a + 0x10, &tmp);
                func_0038CE20(&tmp, &tmp, *(f32 *)(v + 0x10));
                vec_add_ba(&p->q30, s5->slots[k].target + 0x10, &tmp);
            }
        }
        if (func_0038CAD0_0037CC30(p->timer) != 0) {
            p->owner = 0;
            p->target = 0;
            s5->cnt--;
        }
    }
}
/* localdecomp:end func_L01_0037CC30 */

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

/* localdecomp:start func_L01_0037D210 */
#include "vu0.h"
static __inline__ void gp_add_lo2_0037D210(void *d, void *a, void *b) {
    vu0_q qr, qb;
    __asm__("lqc2 %1, %2\n\tlqc2 %0, %3\n\tvadd.xyz %1, %1, %0" : "=&j"(qb), "=&j"(qr) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qr));
}
extern s32 func_00382498(s32, s32);
extern void func_L01_0037D358(void *, s32, vu0_v4 *, s32);
void func_L01_0037C860(f32 *out, f32 *a, f32 *b, f32 *c, f32 *d, f32 t);
typedef struct {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    u8 pad40[0x58];
    s32 f98;
    s32 f9C;
} S_37D210;
void func_L01_0037D210(void *a0, S_37D210 *a1) {
    vu0_v4 out[9];
    vu0_v4 a, b, c;
    s32 i;
    for (i = 0; i < 8; i++) {
        a = a1->v0;
        {
            vu0_q qc, q2, qa, qr, tb;
            tb = *(vu0_q *)&a1->v10;
            __asm__("lqc2 %0, %1" : "=j"(qc) : "m"(a1->v30));
            __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(a1->v20));
            __asm__("sqc2 %1, %0" : "=m"(c) : "j"(qc), "j"(q2));
            *(vu0_q *)&b = tb;
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(a));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(q2));
            __asm__("sqc2 %1, %0" : "=m"(a) : "j"(qr));
        }
        gp_add_lo2_0037D210(&b, &b, &c);
        func_L01_0037C860((f32 *)&out[i], (f32 *)&a1->v20, (f32 *)&a1->v30, (f32 *)&a, (f32 *)&b, (f32)i / 7.0f);
    }
    if (a1->f98 >= (a1->f9C >> 1)) {
        func_L01_0037D358(a0, func_00382498(0x10, 0x20), out, 9);
    } else {
        func_L01_0037D358(a0, func_00382498(0, 0x10), out, 9);
    }
}
/* localdecomp:end func_L01_0037D210 */

INCLUDE_ASM("asm/levels", func_L01_0037D358);

/* localdecomp:start func_L01_0037D920 */
#include "vu0.h"
typedef struct { u8 pad[0x30]; f32 f30; s32 f34; u8 *f38; f32 f3c; s32 f40, f44, f48, f4c; } S_0037D920;
typedef struct { u8 pad0[0x34]; u16 flags; } Obj_0037D920;
typedef struct { s32 mode, count, f8, color0, color1; f32 scale; } Settings_0037D920;
extern Settings_0037D920 D_L01_002B3AC0_0037D920;
extern s32 D_L01_001DFB40;
extern s32 D_L01_001E1D94;
extern s32 D_L01_001E1D90_0037D920;
extern u8 D_0014262F[];
extern u8 D_L01_002C5600_0037D920[];
extern f32 D_L01_001DDB60 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DDB60, 4");
extern f32 D_L01_001DDB64 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DDB64, 4");
extern vu0_v4 D_L01_001E2DE0[];
extern u8 D_L01_001E1D70[8];
extern u8 D_L01_001E1D80[8];
extern s32 D_L01_001E1DA0;
extern f32 D_L01_001E1DBC;
extern f32 D_L01_001E1DB8;
u8 *func_L01_0037D920(u8 *owner, vu0_q *pos, vu0_q *dir, vu0_q *other, s32 a4, s32 a5, s32 alt, f32 scale)
{
    extern u8 *func_003C24B0(s32, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_00382538(void);
    extern void func_L01_004AA7E8(void *, s32);
    vu0_v4 v0, v1, from, to, delta;
    u8 *obj = func_003C24B0(0x186F, 0x80);
    u8 *s;
    u8 *second;
    Settings_0037D920 *settings;
    s32 color;
    s32 count;
    f32 sc;
    vu0_v4 *camera;
    if (obj != 0) {
        *(s16 *)(obj + 0x32) = 255; obj[0x20] = 0; obj[0x30] = 255;
        settings = &D_L01_002B3AC0_0037D920;
        s = *(u8 **)(obj + 0x68);
        *(vu0_q *)(obj + 0x10) = *pos;
        *(vu0_q *)(s + 0x20) = *pos;
        second = s + 0x10;
        func_0038CE20(dir, dir, 0.1f);
        func_0038CE20(other, other, 0.1f);
        *(vu0_q *)s = *dir;
        *(vu0_q *)(s + 0x10) = *other;
        ((S_0037D920 *)s)->f40 = a4;
        ((S_0037D920 *)s)->f38 = owner;
        *(u8 **)(obj + 0xB8) = owner;
        ((S_0037D920 *)s)->f30 = func_00382538();
        ((S_0037D920 *)s)->f3c = scale;
        ((S_0037D920 *)s)->f34 = 0;
        ((S_0037D920 *)s)->f44 = a5;
        ((S_0037D920 *)s)->f48 = alt;
        ((S_0037D920 *)s)->f4c = 0;
        D_L01_001E1D90_0037D920 = 1;
        D_L01_001E1D94 = D_L01_001DFB40;
        settings->color0 = 0xBFB0B0B0;
        {
            u8 *weapons = D_L01_002C5600_0037D920;
            u8 type = *(D_0014262F[0] * 240 + weapons + 1);
            color = 0xBFA0FFA0;
            if (type == 1) color = 0xBFFFA0A0;
            if (type == 2) color = 0xBFFF8040;
            if (type == 3) color = 0xBFA0A0FF;
            if (type >= 4) color = 0xBFA0A0FF;
        }
        settings->color1 = color;
        func_0038CF68(s, s, 30.0f);
        func_0038CF68(second, second, 30.0f);
        if (alt) {
            camera = D_L01_001E2DE0;
            func_0038CE20(&v0, camera, D_L01_001DDB60);
            func_0038CE20(&v1, camera - 2, D_L01_001DDB64);
            vec_add_ba(&from, camera - 58, &v1);
            vec_add_ba(&from, &from, &v0);
            func_0038CF68(&delta, second, 100.0f);
            count = 5;
            sc = 0.25f;
            vec_add_ab(&to, &from, &delta);
            D_L01_002B3AC0_0037D920.mode = 2;
            *(vu0_q *)D_L01_001E1D70 = *(vu0_q *)&from;
            settings->count = count;
            settings->scale = sc;
        } else {
            func_0038CF68(&delta, s, 100.0f);
            vec_add_ab(&to, pos, &delta);
            *(vu0_q *)D_L01_001E1D70 = *pos;
            count = 10;
            sc = 0.75f;
            D_L01_002B3AC0_0037D920.mode = 4;
            settings->count = count;
            settings->scale = sc;
        }
        *(vu0_q *)D_L01_001E1D80 = *(vu0_q *)&to;
        D_L01_001E1DA0 = 17;
        D_L01_001E1DB8 = 0.2f;
        D_L01_001E1DBC = 0.2f;
        ((Obj_0037D920 *)obj)->flags = (((Obj_0037D920 *)obj)->flags | 0x41) & 0xEFFF;
        *(s32 *)(obj + 0x98) = 0;
        func_L01_004AA7E8(obj, 1);
    }
    return obj;
}
/* localdecomp:end func_L01_0037D920 */

/* localdecomp:start func_L01_0037DC70 */
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 b20; u8 p21[0x47]; u8 *p68; u8 p6C[0x3E]; u16 hAA;
} M_37DC70;
typedef struct {
    vu0_v4 v0; vu0_v4 v10; u8 p20[0x14]; s32 w34; u8 p38[4]; f32 f3C; s32 w40; u8 p44[4]; s32 w48; s32 w4C;
} St_37DC70;
typedef struct { u8 p0[0xAA]; s16 hAA; } H_37DC70;
typedef struct { u8 p0[0x18]; H_37DC70 *w18; u8 p1C[4]; vu0_v4 v20; } T_37DC70;
typedef struct { vu0_v4 v; u8 p10[8]; u8 b18; u8 b19; u16 h1A; u8 p1C[0x14]; } S_37DC70;
typedef struct { u8 p0; u8 b1; u8 p2[0xEE]; } Row_37DC70;
extern T_37DC70 D_L01_001EAA00;
extern vu0_v4 D_L01_001EAA20;
extern vu0_v4 D_001A52D0;
extern u8 D_001425C0[];
extern Row_37DC70 D_L01_002C5600[];
extern s32 D_L01_001E1DA0;
extern f32 D_L01_001E1DB8;
extern f32 D_L01_001E1DBC;
typedef struct { s32 a; s32 b; } G_37DC70;
extern G_37DC70 D_L01_001E1D90;
extern s32 D_L01_001DFB40;
extern s32 D_L01_002B3AC0[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D4D00_0037DC70(void *, s32, void *, void *, f32);
extern s32 func_0038CAD0(s32 *);
extern void func_003C2880(void *);
extern void func_L01_00404A10_0037DC70(void *, void *);
extern void func_L01_0037E2E8();
extern void func_L01_0037E620();
extern void func_L01_0037E670();

void func_L01_0037DC70(M_37DC70 *m) {
    s32 *p;
    vu0_v4 old;
    vu0_v4 v10;
    vu0_v4 vA0;
    S_37DC70 sB0;
    vu0_v4 v60;
    M_37DC70 *hit;
    s32 i;
    s32 off;

    p = (s32 *)m->p68;
    if (m->b20 != 0) {
        return;
    }
    old = m->pos;
    if (p[18] != 0) {
        vec_add_ab(&m->pos, &m->pos, (p + 4));
    } else {
        vec_add_ab(&m->pos, &m->pos, p);
    }
    p[13]++;
    if (((Row_37DC70 *)((u8 *)D_L01_002C5600 + D_001425C0[0x6F] * 0xF0))->b1 == 0) {
        if (p[19] == 0) {
            if (!(m->pos.x < 2.0f || 1021.0f < m->pos.x || m->pos.y < 2.0f || 1021.0f < m->pos.y ||
                  m->pos.z < 2.0f || 1021.0f < m->pos.z)) {
                if (func_003D3CB0(&old, &m->pos, 0, m, 0)) {
                    p[19] = 1;
                    v10 = D_L01_001EAA20;
                    vA0 = D_001A52D0;
                    func_0038CE20(&vA0, &vA0, 1.0f);
                    vA0.w = 5627.925f;
                    func_L01_00446760(&sB0, m, p[16], &vA0, ((f32 *)p)[15]);
                    sB0.b19 = 1;
                    sB0.h1A = m->hAA;
                    sB0.b18 = 0;
                    func_003D4D00_0037DC70(&v10, 0, m, &sB0, 0.6f);
                    if (p[18] != 0) {
                        func_0038CF68((p + 4), (p + 4), -0.2f);
                        vec_add_ab(&v60, &v10, (p + 4));
                    } else {
                        func_0038CF68(p, p, -0.2f);
                        vec_add_ab(&v60, &v10, p);
                    }
                }
            }
        }
    } else {
        hit = 0;
        for (i = 0; i < 6; i++) {
            if (m->pos.x < 2.0f || 1021.0f < m->pos.x || m->pos.y < 2.0f || 1021.0f < m->pos.y ||
                m->pos.z < 2.0f || 1021.0f < m->pos.z) {
                continue;
            }
            if (func_003D3CB0(&old, &m->pos, 0, hit, 0)) {
                T_37DC70 *t = &D_L01_001EAA00;
                if (t->w18 != 0 && t->w18->hAA == 0x1CF7) {
                    break;
                }
                v10 = t->v20;
                hit = (M_37DC70 *)t->w18;
                vA0 = D_001A52D0;
                func_0038CE20(&vA0, &vA0, 1.75f);
                vA0.w = 5627.925f;
                func_L01_00446760(&sB0, m, p[16], &vA0, ((f32 *)p)[15]);
                sB0.b18 = 0;
                sB0.h1A = m->hAA;
                sB0.b19 = 1;
                off = D_001425C0[0x6F] * 0xF0;
                if (((Row_37DC70 *)((u8 *)D_L01_002C5600 + off))->b1 >= 3) {
                    func_003D4D00_0037DC70(&v10, 0, m, &sB0, 2.5f);
                } else {
                    func_003D4D00_0037DC70(&v10, 0, m, &sB0, 0.8f);
                }
                if (p[18] != 0) {
                    func_0038CF68((p + 4), (p + 4), -0.2f);
                    vec_add_ab(&v60, &v10, (p + 4));
                } else {
                    func_0038CF68(p, p, -0.2f);
                    vec_add_ab(&v60, &v10, p);
                }
            }
        }
    }
    if (func_0038CAD0(&D_L01_001E1DA0) == 0 && ((Row_37DC70 *)((u8 *)D_L01_002C5600 + D_001425C0[0x6F] * 0xF0))->b1 >= 3) {
        if (D_L01_001E1DA0 >= 5) {
            D_L01_001E1DB8 += 0.05f;
            D_L01_001E1DBC += 0.05f;
        } else {
            D_L01_001E1DB8 -= 0.05f;
            D_L01_001E1DBC -= 0.05f;
        }
        func_L01_00404A10_0037DC70(func_L01_0037E2E8, m);
    }
    if (p[13] >= 0x16) {
        func_003C2880(m);
        return;
    }
    if (p[18] != 0) {
        if (p[13] < 0x11) {
            func_L01_00404A10_0037DC70(func_L01_0037E620, m);
            func_L01_00404A10_0037DC70(func_L01_0037E670, m);
        }
        if (p[13] == 8) {
            D_L01_001E1D90.a = 2;
            D_L01_001E1D90.b = D_L01_001DFB40;
        }
    } else {
        if (p[13] < 8) {
            func_L01_00404A10_0037DC70(func_L01_0037E620, m);
            func_L01_00404A10_0037DC70(func_L01_0037E670, m);
        }
        if (p[13] == 3) {
            D_L01_001E1D90.a = 2;
            D_L01_001E1D90.b = D_L01_001DFB40;
        }
        D_L01_002B3AC0[3] = ((0xBF - p[13] * 15) << 24) | 0x808080;
        D_L01_002B3AC0[4] = ((0xBF - p[13] * 15) << 24) | 0x8080B4;
    }
}
/* localdecomp:end func_L01_0037DC70 */

