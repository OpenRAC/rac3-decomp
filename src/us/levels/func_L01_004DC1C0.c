#include "common.h"

/* NTSC-U counterpart of func_L01_004DFEA0 (src/levels/shared/L01_004DF428.c): 300 -> 360 */
typedef struct {
    u8 pad0[4688];
    s32 f1250;
    u8 pad1254[36];
    s32 f1278;
    u8 pad127C[4932];
    s32 f25C0;
} G_4DD4B0;
extern G_4DD4B0 D_001A4BE0;

/* localdecomp:start func_L01_004DC1C0 */
typedef struct {
    u8 pad0[0x25E4];
    u8 critter_mode;
    u8 pad25E5[0x25F7 - 0x25E5];
    u8 area;
    u8 pad25F8[0x2850 - 0x25F8];
    s32 health;
} H_4DFEA0;
extern s16 D_001426A0[]; /* the armor worn, 0-4 */
extern s32 D_001D545C; /* the level */
extern u8 D_001BBC40[][16]; /* each level's areas' flags: 0x80 no help */
extern s32 D_001C5290[][16]; /* each level's areas' deaths */
extern f32 func_L01_004DC1A8(s32 armor); /* the armor's damage factor */
extern s32 func_L01_003FE420(s32 level, s32 area);
extern void func_003E4D10(s32 frames);

/* hero_damage: health -= damage x the armor's factor x the help measure's, rounded, at least
   1; never below 0. */
void func_L01_004DC1C0(s32 damage) {
    s32 armor;
    f32 factor;
    s32 deaths;

    if (damage == 0) {
        return;
    }
    armor = D_001426A0[0];
    if (armor >= 5) {
        armor = 4;
    }
    if (armor < 0) {
        armor = 0;
    }
    factor = func_L01_004DC1A8(armor);
    /* where he keeps dying: less over a measure of 250 and 6 deaths */
    if ((*(H_4DFEA0 *)&D_001A4BE0).critter_mode == 0 &&
        !(D_001BBC40[D_001D545C][(*(H_4DFEA0 *)&D_001A4BE0).area & 0xF] & 0x80)) {
        deaths = D_001C5290[D_001D545C][(*(H_4DFEA0 *)&D_001A4BE0).area & 0xF];
        if (func_L01_003FE420(D_001D545C, (*(H_4DFEA0 *)&D_001A4BE0).area) > 250 && deaths > 6) {
            /* 0.07 less a death over 6, at most 0.5 less */
            f32 ease = (deaths - 6) * 0.0700000003f;
            if (ease > 0.5f) {
                ease = 0.5f;
            }
            ease = 1.0f - ease;
            factor *= ease;
        }
    }
    /* where he seldom dies: more under a measure of 50 with no deaths or one */
    if ((*(H_4DFEA0 *)&D_001A4BE0).critter_mode == 0 &&
        !(D_001BBC40[D_001D545C][(*(H_4DFEA0 *)&D_001A4BE0).area & 0xF] & 0x80)) {
        deaths = D_001C5290[D_001D545C][(*(H_4DFEA0 *)&D_001A4BE0).area & 0xF];
        if (func_L01_003FE420(D_001D545C, (*(H_4DFEA0 *)&D_001A4BE0).area) < 50 && deaths < 2) {
            if (deaths == 0) {
                factor *= 1.20000005f; /* x 1.2 with no deaths */
            } else if (deaths == 1) {
                factor *= 1.10000002f; /* x 1.1 with one */
            }
        }
    }
    if ((*(H_4DFEA0 *)&D_001A4BE0).critter_mode == 0 && damage > 0) {
        damage = (s32)(damage * factor + 0.5f);
        if (damage < 1) {
            damage = 1;
        }
    }
    (*(H_4DFEA0 *)&D_001A4BE0).health -= damage;
    if ((*(H_4DFEA0 *)&D_001A4BE0).health < 0) {
        (*(H_4DFEA0 *)&D_001A4BE0).health = 0;
    }
    func_003E4D10(360);
}
/* localdecomp:end func_L01_004DC1C0 */
