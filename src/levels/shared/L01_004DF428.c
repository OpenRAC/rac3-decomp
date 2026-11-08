#include "common.h"

typedef struct {
    u8 pad0[6];
    s16 h6;
} S_4DBFE8_Ent;
typedef struct {
    u8 pad0[0x10];
    u8 b10;
    u8 pad11[2];
    u8 b13;
    u8 pad14[8];
    S_4DBFE8_Ent *entries[1];
} S_4DBFE8_Hdr;
typedef struct {
    u8 pad0[8];
    u8 b8;
    u8 pad9[0x3F];
    S_4DBFE8_Hdr *hdrs[1];
} S_4DBFE8_Tbl;
typedef struct {
    u8 pad0[0x24];
    S_4DBFE8_Tbl *tbl;
} S_4DBFE8_Obj;
typedef struct { u8 pad[0xB0]; } S_4DC790;
typedef struct {
    u8 pad0[4688];
    s32 f1250;
    u8 pad1254[36];
    s32 f1278;
    u8 pad127C[4932];
    s32 f25C0;
} G_4DD4B0;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad[8944];
    u128_t q[8];
    s32 i[8];
    f32 a[8];
    f32 b[8];
    s16 count;
} S_4DF808;
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[128];
    s128 v128;
    s128 v144;
    u8 pad160[336];
    s16 h496;
    u8 pad498[126];
    f32 f624;
    f32 f628;
    u8 pad632[12];
    f32 f644;
    u8 pad648[9016];
    u8 *obj;
    u8 pad9668[8];
    s32 w9676;
} S_001A4BE0;
typedef struct {
    u8 p0[0x10];
    u128_t q10;
    u8 p20[0x98 - 0x20];
    s32 f98;
    u8 p9C[0xA8 - 0x9C];
    u8 bA8;
    u8 pA9[0xC0 - 0xA9];
    u8 fC0[0x30];
    u128_t qF0;
} Obj_4E09A8;
typedef struct {
    u8 p0[0x80];
    u128_t q80;
    u128_t q90;
    u8 pA0[0x1F0 - 0xA0];
    s16 h1F0;
    u8 p1F2[0x270 - 0x1F2];
    f32 f270;
    f32 f274;
    u8 p278[0x284 - 0x278];
    f32 f284;
    u8 p288[0x25C0 - 0x288];
    Obj_4E09A8 *f25C0;
    s32 f25C4;
    u8 p25C8[0x25E5 - 0x25C8];
    u8 b25E5;
} S_4E09A8;
typedef struct {
    u8 pad0[8800];
    f32 x2260;
    f32 x2264;
} S_004E1168;
typedef unsigned long u64l;
typedef struct {
    u64l a;
    u64l b;
    u64l c;
    u64l d;
} E_4E1758;
typedef struct {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
    s16 hC;
    s16 hE;
    u64l x10;
    u64l data[1];
} H_4E1758;
typedef struct { u8 pad[164]; f32 a; f32 b; } S_004E25C8;
typedef struct { u8 pad[340]; f32 a; f32 b; } S_004E25E0;
typedef struct { u8 pad[516]; f32 a; f32 b; } S_004E25F8;
typedef struct { u8 pad[692]; f32 a; f32 b; } S_004E2610;

typedef struct {
    u8 p0[0x1B8];
    s32 f1B8;
    u8 p1BC[0xC0C - 0x1BC];
    s32 fC0C;
    u8 pC10[0x147F - 0xC10];
    u8 b147F;
    u8 p1480[0x25C0 - 0x1480];
    u8 *f25C0;
    s32 f25C4;
} S_004E1218;

typedef struct {
    u8 p0[0x600];
    s32 f600;
    u8 p604[0x650 - 0x604];
    f32 f650;
    u8 p654[0x65C - 0x654];
    s16 h65C;
    u8 p65E[0x25C0 - 0x65E];
    u8 *f25C0;
    s32 f25C4;
} S_4E2E30;

typedef struct {
    u8 pad0[0x80];
    f32 x;
    f32 y;
    u8 pad88[0x10];
    f32 angle;
    u8 pad9C[0x350 - 0x9C];
    f32 z;
    u8 pad354[0x9C8 - 0x354];
    u16 counter;
} G_004E5840;

typedef struct {
    u8 pad0[0x80];
    f32 x;
    f32 y;
    u8 pad88[0x110 - 0x88];
    f32 vx;
    f32 vy;
    u8 pad118[0x350 - 0x118];
    f32 z;
    u8 pad354[0x9C6 - 0x354];
    s16 counter;
    u8 pad9C8[0x2848 - 0x9C8];
    f32 amount;
} Emit_004E5A20;

INCLUDE_ASM("asm/levels", func_L01_004DF428);

INCLUDE_ASM("asm/levels", func_L01_004DF840);

/* localdecomp:start func_L01_004DFCC8 */




extern void func_L01_0043C8F8(S_4DBFE8_Ent **, S_4DBFE8_Ent *, s32, s32);
extern void func_0038CD28(s32, S_4DBFE8_Ent *, s32);
extern void func_0011F0A0(s32);

s32 func_L01_004DFCC8(S_4DBFE8_Obj *obj, s32 a, s32 b, s32 out) {
    S_4DBFE8_Tbl *tbl = obj->tbl;
    S_4DBFE8_Hdr *hdr = tbl->hdrs[a];
    S_4DBFE8_Ent *ent = hdr->entries[b];
    if ((u32)ent & 0xF0000000) {
        func_L01_0043C8F8(&hdr->entries[hdr->b10] + hdr->b13, ent, out, tbl->b8);
    } else {
        func_0038CD28(out, ent, (ent->h6 + 1) << 4);
    }
    func_0011F0A0(0);
    return out;
}
/* localdecomp:end func_L01_004DFCC8 */

/* localdecomp:start func_L01_004DFD60 */
extern s32 D_001A7430[];
extern s32 D_00142668[];

/* hero_low_health: whether health (D_001A7430) over the most health (D_00142668) is 0.2 or
   less: the idle then stands hurt. */
s32 func_L01_004DFD60(void) {
    return (f32)D_001A7430[0] / (f32)D_00142668[0] <= 0.2f;
}
/* localdecomp:end func_L01_004DFD60 */

/* localdecomp:start func_L01_004DFDB0 */
typedef struct {
    u8 pad0[0x1474];
    u8 strafe;
    u8 pad1475[0x25E4 - 0x1475];
    u8 critter_mode;
    u8 pad25E5[0x25EB - 0x25E5];
    u8 firing_held;
    u8 pad25EC[0x2874 - 0x25EC];
    s16 gun_arm_raised;
} H_4DFDB0;
typedef struct {
    u8 pad0[0x24];
    s32 fire_sequence;
    u8 pad28[0xF0 - 0x28];
} GunRow_4DFDB0;
extern G_4DD4B0 D_001A4BE0;
extern s32 D_L01_001DBD54;
extern u8 D_001425C0[];
extern GunRow_4DFDB0 D_L01_002C5600[];
extern s32 func_L01_004E9238(s32 slot);
extern s32 func_L01_004DFD60(void);

/* hero_idle_sequence: the idle's sequence: 20 or 29 in critter mode 1, 1 in mode 3; a held
   gun's whole-body firing sequence while firing; 74 at low health; 85 strafing, else 0. */
s32 func_L01_004DFDB0(s32 firing) {
    switch ((*(H_4DFDB0 *)&D_001A4BE0).critter_mode) {
    case 1:
        return D_L01_001DBD54 == 0 ? 20 : 29;
    case 3:
        return 1;
    }
    if (firing && (*(H_4DFDB0 *)&D_001A4BE0).firing_held && (*(H_4DFDB0 *)&D_001A4BE0).gun_arm_raised == 0) {
        s32 item = func_L01_004E9238(0);
        GunRow_4DFDB0 *gun = D_L01_002C5600 + D_001425C0[item];
        return gun->fire_sequence;
    }
    if (func_L01_004DFD60()) {
        return 74;
    }
    if ((*(H_4DFDB0 *)&D_001A4BE0).strafe) {
        return 85;
    }
    return 0;
}
/* localdecomp:end func_L01_004DFDB0 */

/* localdecomp:start func_L01_004DFE80 */
s32 func_L01_004DFE80(s32 arg0) {
    return arg0;
}
/* localdecomp:end func_L01_004DFE80 */

INCLUDE_ASM("asm/levels", func_L01_004DFE88);

/* localdecomp:start func_L01_004DFEA0 */
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
extern f32 func_L01_004DFE88(s32 armor); /* the armor's damage factor */
extern s32 func_L01_00400390(s32 level, s32 area);
extern void func_L01_0047B388(s32 frames);

/* hero_damage: health -= damage x the armor's factor x the help measure's, rounded, at least
   1; never below 0. */
void func_L01_004DFEA0(s32 damage) {
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
    factor = func_L01_004DFE88(armor);
    /* where he keeps dying: less over a measure of 250 and 6 deaths */
    if ((*(H_4DFEA0 *)&D_001A4BE0).critter_mode == 0 &&
        !(D_001BBC40[D_001D545C][(*(H_4DFEA0 *)&D_001A4BE0).area & 0xF] & 0x80)) {
        deaths = D_001C5290[D_001D545C][(*(H_4DFEA0 *)&D_001A4BE0).area & 0xF];
        if (func_L01_00400390(D_001D545C, (*(H_4DFEA0 *)&D_001A4BE0).area) > 250 && deaths > 6) {
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
        if (func_L01_00400390(D_001D545C, (*(H_4DFEA0 *)&D_001A4BE0).area) < 50 && deaths < 2) {
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
    func_L01_0047B388(300);
}
/* localdecomp:end func_L01_004DFEA0 */

/* localdecomp:start func_L01_004E0100 */
extern s32 D_001A71A0[];
extern s32 D_001A5ED4[];
extern s32 D_001A5DE0[];

s32 func_L01_004E0100(s32 a0) {
    if (a0 == 0 || a0 == 2 || a0 == 3 || a0 == 4 || a0 == 6) {
        return D_001A71A0[0];
    }
    if (a0 == 1) {
        return D_001A5ED4[0];
    }
    if (a0 == 7) {
        return D_001A5DE0[0];
    }
    return 0;
}
/* localdecomp:end func_L01_004E0100 */

INCLUDE_ASM("asm/levels", func_L01_004E0160);

/* localdecomp:start func_L01_004E04A0 */
extern S_4DC790 D_L01_002F4540[];
void func_L01_004E0160(S_4DC790 *);
void func_L01_004E04A0(void) {
    s32 i;
    for (i = 0; i < 43; i++) func_L01_004E0160(&D_L01_002F4540[i]);
}
/* localdecomp:end func_L01_004E04A0 */

INCLUDE_ASM("asm/levels", func_L01_004E04E8);

INCLUDE_ASM("asm/levels", func_L01_004E0580);

/* localdecomp:start func_L01_004E0618 */
/* Ps2EeAs reaches these tables through $gp only if it knows before the use that they are small
   data (retail's own file defined them there); gcc gives no size for them. */
__asm__(".extern D_L01_001DBE98, 0");
__asm__(".extern D_L01_001DBE68, 0");
typedef int u128_4E0618 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x60];
    f32 target_x;
    f32 target_y;
    f32 target_z;
    u8 pad6C[0xB0 - 0x6C];
} Spring_4E0618;
/* the hero's joint springs (43, from D_L01_002F4540) */
typedef struct {
    Spring_4E0618 others[3];
    Spring_4E0618 neck;
    Spring_4E0618 others2[8];
    Spring_4E0618 eyes;
} Springs_4E0618;
/* a joint turn record (func_L01_0043A430) on one of his eyelid joints */
typedef struct {
    u8 joint;
    u8 active;
    u8 pad2;
    u8 set;
    u8 pad4[0xC - 4];
    f32 amount;
    u128_4E0618 a;
    u128_4E0618 b;
    u128_4E0618 c;
} Lid_4E0618;
typedef struct {
    u8 pad0[0x43];
    u8 seq;
} Moby_4E0618;
typedef struct {
    u8 pad0[0xEA0];
    Lid_4E0618 lids[7];
    u8 pad1060[0x1160 - 0x1060];
    s32 blink;
    u8 pad1164[0x25C0 - 0x1164];
    Moby_4E0618 *moby;
} H_4E0618;
extern S_4DC790 D_L01_002F4540[];
extern s32 D_L01_001DBE98[] __attribute__((section(".sdata")));
extern f32 D_L01_001DBE68[] __attribute__((section(".sdata")));
extern u128_4E0618 D_L01_002F6670[];
extern u128_4E0618 D_L01_002F66E0[];
extern u128_4E0618 D_L01_002F6750[];
extern void func_L01_004E0580(void);
extern void func_L01_0043A430(Moby_4E0618 *moby, s32 joint, Lid_4E0618 *lid);
extern void func_L01_0043A4B8(Moby_4E0618 *moby, Lid_4E0618 *lid);

/* hero_eyes_follow: spring 12 (the eyes' parent) takes the neck's targets: pitch / 2.8
   within -10..17 deg, yaw x 0.25 within +-8.5 deg (+-7 and +-2 deg in sequences 1 and 2);
   then the blink: its frames turn his eyelids, and they let go when it ends. */
void func_L01_004E0618(void) {
    f32 yaw;
    f32 pitch;
    s32 i;
    s32 j;
    s32 k;

    yaw = (*(Springs_4E0618 *)D_L01_002F4540).neck.target_z * 0.25f;
    (*(Springs_4E0618 *)D_L01_002F4540).eyes.target_z = yaw;
    if (yaw > 0.148352981f) {
        (*(Springs_4E0618 *)D_L01_002F4540).eyes.target_z = 0.148352981f;
    } else if (yaw < -0.148352981f) {
        (*(Springs_4E0618 *)D_L01_002F4540).eyes.target_z = -0.148352981f;
    }
    pitch = (*(Springs_4E0618 *)D_L01_002F4540).neck.target_y / 2.79999995f;
    (*(Springs_4E0618 *)D_L01_002F4540).eyes.target_y = pitch;
    if (pitch > 0.296705961f) {
        (*(Springs_4E0618 *)D_L01_002F4540).eyes.target_y = 0.296705961f;
    }
    if ((*(Springs_4E0618 *)D_L01_002F4540).eyes.target_y < -0.17453292f) {
        (*(Springs_4E0618 *)D_L01_002F4540).eyes.target_y = -0.17453292f;
    }
    if ((u8)((*(H_4E0618 *)&D_001A4BE0).moby->seq - 1) < 2) {
        if ((*(Springs_4E0618 *)D_L01_002F4540).eyes.target_z > 0.0349065848f) {
            (*(Springs_4E0618 *)D_L01_002F4540).eyes.target_z = 0.0349065848f;
        }
        if ((*(Springs_4E0618 *)D_L01_002F4540).eyes.target_z < -0.0349065848f) {
            (*(Springs_4E0618 *)D_L01_002F4540).eyes.target_z = -0.0349065848f;
        }
        if ((*(Springs_4E0618 *)D_L01_002F4540).eyes.target_y > 0.122173049f) {
            (*(Springs_4E0618 *)D_L01_002F4540).eyes.target_y = 0.122173049f;
        }
        if ((*(Springs_4E0618 *)D_L01_002F4540).eyes.target_y < -0.122173049f) {
            (*(Springs_4E0618 *)D_L01_002F4540).eyes.target_y = -0.122173049f;
        }
    }
    func_L01_004E0580();
    if ((*(H_4E0618 *)&D_001A4BE0).blink == 0) {
        return;
    }
    if (++(*(H_4E0618 *)&D_001A4BE0).blink >= 12) {
        (*(H_4E0618 *)&D_001A4BE0).blink = 0;
    }
    if ((*(H_4E0618 *)&D_001A4BE0).blink == 0) {
        /* the blink is over: the lids let go */
        for (i = 0; i < 7; i++) {
            if ((*(H_4E0618 *)&D_001A4BE0).lids[i].active) {
                func_L01_0043A4B8((*(H_4E0618 *)&D_001A4BE0).moby, &(*(H_4E0618 *)&D_001A4BE0).lids[i]);
            }
        }
        return;
    }
    for (j = 0; j < 7; j++) {
        if (!(*(H_4E0618 *)&D_001A4BE0).lids[j].active) {
            func_L01_0043A430((*(H_4E0618 *)&D_001A4BE0).moby, D_L01_001DBE98[j], &(*(H_4E0618 *)&D_001A4BE0).lids[j]);
            (*(H_4E0618 *)&D_001A4BE0).lids[j].set = 1;
            (*(H_4E0618 *)&D_001A4BE0).lids[j].a = D_L01_002F6670[j];
            (*(H_4E0618 *)&D_001A4BE0).lids[j].b = D_L01_002F66E0[j];
            (*(H_4E0618 *)&D_001A4BE0).lids[j].c = D_L01_002F6750[j];
        }
    }
    for (k = 0; k < 7; k++) {
        (*(H_4E0618 *)&D_001A4BE0).lids[k].amount = D_L01_001DBE68[(*(H_4E0618 *)&D_001A4BE0).blink];
    }
}
/* localdecomp:end func_L01_004E0618 */

INCLUDE_ASM("asm/levels", func_L01_004E0920);

INCLUDE_ASM("asm/levels", func_L01_004E0C18);

/* localdecomp:start func_L01_004E0CB0 */
extern s32 D_001A6634[];
extern void func_L01_004E3268(void);

void func_L01_004E0CB0(void) {
    if (D_001A6634[0]) {
        func_L01_004E3268();
    }
}
/* localdecomp:end func_L01_004E0CB0 */

INCLUDE_ASM("asm/levels", func_L01_004E0CD8);

INCLUDE_ASM("asm/levels", func_L01_004E1020);

/* localdecomp:start func_L01_004E1180 */
extern u8 D_001A605F[];
extern void func_L01_004E11C0(s32, s32, s32, s32);
extern void func_L01_004F4FC0(s32, s32, s32);

void func_L01_004E1180(void) {
    func_L01_004E11C0(D_001A605F[0], 0, 1, 0x32);
    func_L01_004F4FC0(0x1B, 6, 0);
}
/* localdecomp:end func_L01_004E1180 */

/* localdecomp:start func_L01_004E11C0 */
extern G_4DD4B0 D_001A4BE0;
extern void func_L01_004AAF20(s32, s32, s32, s32, s32, s32);
void func_L01_004E11C0(s32 a0, s32 a1, s32 a2, s32 a3) {
    u8 buf[32];
    if (a2 != 0) {
        s32 f = 0;
        if (D_001A4BE0.f1250 != 0) {
            f = D_001A4BE0.f1278 == 13;
        }
        a3 = (a3 << 10) / 30;
        func_L01_004AAF20(a0, a1, f, 0, D_001A4BE0.f25C0, a3);
    }
}
/* localdecomp:end func_L01_004E11C0 */

/* localdecomp:start func_L01_004E1218 */
extern s32 func_L01_004EE7F8(f32);

void func_L01_004E1218(void) {
    s32 selector;

    if ((*(S_004E1218 *)&D_001A4BE0).f25C4 == 2) {
        if ((*(S_004E1218 *)&D_001A4BE0).f1B8 < 12)
            return;
    }

    selector = (*(S_004E1218 *)&D_001A4BE0).b147F;

    switch ((*(S_004E1218 *)&D_001A4BE0).f25C0[67]) {
    case 3:
        if ((*(S_004E1218 *)&D_001A4BE0).fC0C != 0)
            return;
        if (func_L01_004EE7F8(49.5f) != 0)
            func_L01_004E11C0(selector, 0, 1, 30);
        if (func_L01_004EE7F8(17.0f) != 0)
            func_L01_004E11C0(selector, 1, 1, 30);
        return;
    case 4:
        if ((*(S_004E1218 *)&D_001A4BE0).fC0C != 0)
            return;
        if (func_L01_004EE7F8(12.5f) != 0)
            func_L01_004E11C0(selector, 0, 1, 30);
        if (func_L01_004EE7F8(1.0f) != 0)
            func_L01_004E11C0(selector, 1, 1, 30);
        return;
    case 20:
        if ((*(S_004E1218 *)&D_001A4BE0).fC0C != 0)
            return;
        if (func_L01_004EE7F8(8.0f) != 0)
            func_L01_004E11C0(selector, 0, 1, 30);
        if (func_L01_004EE7F8(21.0f) != 0)
            func_L01_004E11C0(selector, 1, 1, 30);
        return;
    }
}
/* localdecomp:end func_L01_004E1218 */

INCLUDE_ASM("asm/levels", func_L01_004E13A0);

INCLUDE_ASM("asm/levels", func_L01_004E1560);

INCLUDE_ASM("asm/levels", func_L01_004E1638);

INCLUDE_ASM("asm/levels", func_L01_004E1F00);

INCLUDE_ASM("asm/levels", func_L01_004E20E8);

/* localdecomp:start func_L01_004E26A0 */
extern s32 D_001D545C;
extern s32 func_L01_005143C0(s32);

s32 func_L01_004E26A0(void) {
    s32 r = 0;

    switch (D_001D545C) {
    case 9:
        r = func_L01_005143C0(4) != 0;
        break;
    case 19:
        if (func_L01_005143C0(1) || func_L01_005143C0(2)) {
            r = 1;
        }
        break;
    }
    return r;
}
/* localdecomp:end func_L01_004E26A0 */

/* localdecomp:start func_L01_004E2720 */
void func_L01_004E2720(void)
{
    u8 *base = (u8 *)&D_001A4BE0;
    s32 i;
    s32 j;

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 3; j++) {
            u8 *p = *(u8 **)(base + 0x1200 + i * 80);

            if (j == 1)
                p = *(u8 **)(base + 0x1204 + i * 80);
            else if (j == 2)
                p = *(u8 **)(base + 0x1208 + i * 80);
            if (p != 0)
                *(u64l *)(p + 0x38) = *(u64l *)(*(u8 **)(base + 0x25C0) + 0x38);
        }
    }
}
/* localdecomp:end func_L01_004E2720 */

/* localdecomp:start func_L01_004E27A0 */
void func_L01_004E27A0(void) {

}
/* localdecomp:end func_L01_004E27A0 */

INCLUDE_ASM("asm/levels", func_L01_004E27A8);

INCLUDE_ASM("asm/levels", func_L01_004E2988);

INCLUDE_ASM("asm/levels", func_L01_004E2C48);

/* localdecomp:start func_L01_004E2DC8 */
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);

void func_L01_004E2DC8(void) {
    u8 *b = (u8 *)&D_001A4BE0;
    s32 x = ((S_4E09A8 *)b)->f25C4;

    if (x != 0x81 && x != 0x50) {
        return;
    }
    func_L01_0044EAE0(((S_4E09A8 *)b)->f25C0, b + 0x738, b + 0x73C, 0.3f, 0.139626354f, -1.0f);
}
/* localdecomp:end func_L01_004E2DC8 */

/* localdecomp:start func_L01_004E2E30 */
extern void func_L01_0044EBA0(u8 *, f32 *, f32 *, f32, f32, f32);

void func_L01_004E2E30(void) {
    if ((*(S_4E2E30 *)&D_001A4BE0).f25C4 == 0x81 || (*(S_4E2E30 *)&D_001A4BE0).f25C4 == 0x50) {
        func_L01_0044EBA0((*(S_4E2E30 *)&D_001A4BE0).f25C0, (f32 *)((u8 *)&D_001A4BE0 + 0x740),
                          (f32 *)((u8 *)&D_001A4BE0 + 0x744), 0.1745329252f, 0.031415927f, 0.0418879053f);
    }
    if ((*(S_4E2E30 *)&D_001A4BE0).h65C == 0) {
        return;
    }
    if ((*(S_4E2E30 *)&D_001A4BE0).f600 != 0) {
        return;
    }
    *(f32 *)((*(S_4E2E30 *)&D_001A4BE0).f25C0 + 0xF4) = (*(S_4E2E30 *)&D_001A4BE0).f650;
}
/* localdecomp:end func_L01_004E2E30 */

INCLUDE_ASM("asm/levels", func_L01_004E2ED0);

INCLUDE_ASM("asm/levels", func_L01_004E3148);

/* localdecomp:start func_L01_004E3268 */
extern G_4DD4B0 D_001A4BE0;
extern char func_L01_004E32A8[];
extern void func_L01_00404808(char *, s32);
void func_L01_004E3268(void) {
    u8 *b = ((u8 *)&D_001A4BE0);
    if (*(s16 *)(b + 9170) == 0) {
        *(s16 *)(b + 9170) = 1;
        func_L01_00404808(func_L01_004E32A8, *(s32 *)(b + 9664));
    }
}
/* localdecomp:end func_L01_004E3268 */

INCLUDE_ASM("asm/levels", func_L01_004E32A8);

/* localdecomp:start func_L01_004E35D0 */
extern G_4DD4B0 D_001A4BE0;


extern void func_L01_004E3268(void);

void func_L01_004E35D0(u128_t *v, s32 n, f32 x, f32 y) {
    S_4DF808 *s = &(*(S_4DF808 *)&D_001A4BE0);

    if (s->count < 8) {
        s->q[s->count] = *v;
        s->i[s->count] = n;
        s->a[s->count] = x;
        s->b[s->count] = y;
        func_L01_004E3268();
        s->count++;
    }
}
/* localdecomp:end func_L01_004E35D0 */

INCLUDE_ASM("asm/levels", func_L01_004E3650);

/* localdecomp:start func_L01_004E45C8 */
extern G_4DD4B0 D_001A4BE0;


extern void func_L01_004E2DC8(void);
extern void func_L01_004E2E30(void);
extern void func_0038CC88(void *, void *, s32);
extern void func_003C7C38(void *);
extern void func_L01_00511158(s128 *, s128 *, f32);
extern void func_L01_00439790(void *, s32, s128 *, f32, f32);
extern s32 func_L01_004E9308(void);

void func_L01_004E45C8(void) {
    s128 v;
    u8 *o;
    f32 d;
    f32 f;

    (*(S_001A4BE0 *)&D_001A4BE0).obj[168] = 255;
    *(s128 *)((*(S_001A4BE0 *)&D_001A4BE0).obj + 16) = (*(S_001A4BE0 *)&D_001A4BE0).v128;
    func_L01_004E2DC8();
    *(s128 *)((*(S_001A4BE0 *)&D_001A4BE0).obj + 240) = (*(S_001A4BE0 *)&D_001A4BE0).v144;
    func_L01_004E2E30();
    func_0038CC88((*(S_001A4BE0 *)&D_001A4BE0).obj + 192, &(*(S_001A4BE0 *)&D_001A4BE0), 48);
    func_003C7C38((*(S_001A4BE0 *)&D_001A4BE0).obj);
    o = (*(S_001A4BE0 *)&D_001A4BE0).obj;
    if (*(u8 **)(o + 36) != 0 && (*(u8 **)(o + 36))[6] != 0) {
        o[99] = 16;
    } else {
        (*(S_001A4BE0 *)&D_001A4BE0).obj[99] = 16;
    }
    if ((*(S_001A4BE0 *)&D_001A4BE0).h496 != 0) {
        return;
    }
    if (*(s32 *)((*(S_001A4BE0 *)&D_001A4BE0).obj + 152) == 0) {
        return;
    }
    v = (*(S_001A4BE0 *)&D_001A4BE0).v128;
    func_L01_00511158(&v, &v, (*(S_001A4BE0 *)&D_001A4BE0).f628);
    d = (*(S_001A4BE0 *)&D_001A4BE0).f624 - (*(S_001A4BE0 *)&D_001A4BE0).f628;
    if (d < 0.05f) {
        d = 0.05f;
    }
    func_L01_00439790((*(S_001A4BE0 *)&D_001A4BE0).obj, 0, &v, (*(S_001A4BE0 *)&D_001A4BE0).f644, d);
    f = (*(S_001A4BE0 *)&D_001A4BE0).f644 + 0.05f;
    if ((*(S_001A4BE0 *)&D_001A4BE0).w9676 == 4) {
        f += 0.15f;
    }
    if (func_L01_004E9308() != 0) {
        f = (*(S_001A4BE0 *)&D_001A4BE0).f628;
    }
    v = (*(S_001A4BE0 *)&D_001A4BE0).v128;
    func_L01_00511158(&v, &v, f);
    d = (*(S_001A4BE0 *)&D_001A4BE0).f624 - f;
    if (d < 0.05f) {
        d = 0.05f;
    }
    func_L01_00439790((*(S_001A4BE0 *)&D_001A4BE0).obj, 1, &v, (*(S_001A4BE0 *)&D_001A4BE0).f644, d);
}
/* localdecomp:end func_L01_004E45C8 */

/* localdecomp:start func_L01_004E4770 */
extern void func_L01_00439790(void *, s32, s128 *, f32, f32);
extern void func_003C7C38(void *);
extern G_4DD4B0 D_001A4BE0;
extern void func_L01_00510C28(void);
extern void func_L01_00510C60(void);
extern void func_0038CC88(void *, void *, s32);
extern void func_L01_00511158(u128_t *, u128_t *, f32);
void func_L01_004E4770(void) {
    S_4E09A8 *p;
    u128_t v;
    f32 r;

    if ((*(S_4E09A8 *)&D_001A4BE0).b25E5 != 0) {
        func_L01_00510C28();
    } else {
        func_L01_00510C60();
    }
    p = &(*(S_4E09A8 *)&D_001A4BE0);
    p->f25C0->bA8 = 255;
    p->f25C0->q10 = p->q80;
    p->f25C0->qF0 = p->q90;
    func_0038CC88(p->f25C0->fC0, p, 48);
    ((void (*)(Obj_4E09A8 *))func_003C7C38)(p->f25C0);
    if (p->h1F0 != 0) {
        return;
    }
    if (p->f25C0->f98 == 0) {
        return;
    }
    v = p->q80;
    func_L01_00511158(&v, &v, p->f274);
    ((void (*)(Obj_4E09A8 *, s32, u128_t *, f32, f32))func_L01_00439790)(p->f25C0, 0, &v, p->f284, p->f270 - p->f274);
    r = p->f284 + 0.05f;
    v = p->q80;
    func_L01_00511158(&v, &v, r);
    ((void (*)(Obj_4E09A8 *, s32, u128_t *, f32, f32))func_L01_00439790)(p->f25C0, 1, &v, p->f284, p->f270 - r);
    if (p->f25C4 == 163) {
        ((void (*)(Obj_4E09A8 *, s32, u128_t *, f32, f32))func_L01_00439790)(p->f25C0, 0, &v, p->f284, p->f270 - r);
    }
}
/* localdecomp:end func_L01_004E4770 */

INCLUDE_ASM("asm/levels", func_L01_004E48C8);

/* localdecomp:start func_L01_004E4F30 */
extern G_4DD4B0 D_001A4BE0;


extern f32 func_003C4138(f32 *, f32, f32);

void func_L01_004E4F30(f32 *out, f32 *st, f32 k) {
    f32 buf[2];

    buf[0] = -(*(S_004E1168 *)&D_001A4BE0).x2260;
    buf[1] = -(*(S_004E1168 *)&D_001A4BE0).x2264;
    func_003C4138(&st[2], buf[0], k);
    if (st[2] > 1.0f) {
        st[2] = 1.0f;
    }
    if (st[2] < -1.0f) {
        st[2] = -1.0f;
    }
    out[0] = st[2];
    func_003C4138(&st[1], buf[1], k);
    if (st[1] > 1.0f) {
        st[1] = 1.0f;
    }
    if (st[1] < -1.0f) {
        st[1] = -1.0f;
    }
    out[1] = st[1];
}
/* localdecomp:end func_L01_004E4F30 */

/* localdecomp:start func_L01_004E5030 */
typedef struct {
    u8 pad0[0x10];
    u8 frames;
} AnimSeq_4E5030;
typedef struct {
    u8 pad0[0x48];
    AnimSeq_4E5030 *seqs[1];
} AnimClass_4E5030;
typedef struct {
    u8 pad0[0x24];
    AnimClass_4E5030 *cls;
    u8 pad28[0x43 - 0x28];
    u8 seq;
    u8 pad44[0x5C - 0x44];
    f32 *blend_rate;
} Moby_4E5030;
typedef struct {
    u8 pad0[0xC00];
    f32 anim_rate;
    f32 anim_key_rate;
    s32 anim_flags;
    s32 anim_blending;
    u8 padC10[0xC18 - 0xC10];
    f32 anim_frame;
    u8 padC1C[0x25C0 - 0xC1C];
    Moby_4E5030 *moby;
} H_4E5030;
extern void func_L01_004481F8(f32 *value, f32 target, f32 step);

/* hero_anim_rate_to_frame: the animation rate that reaches `frame` in `ticks`: factor x
   frames left / (ticks x the keyframe's rate), a frame passed counting round the sequence's
   end; with a step other than -1 the rate approaches it by that much a tick. */
void func_L01_004E5030(f32 frame, f32 ticks, f32 factor, f32 step) {
    f32 now = (*(H_4E5030 *)&D_001A4BE0).anim_frame;
    f32 left;
    f32 key_rate;
    f32 rate;
    if (now < frame) {
        left = frame - now;
    } else {
        /* a frame passed: round the sequence's end, its keyframes in frames */
        f32 scale = 2.0f;
        if ((*(H_4E5030 *)&D_001A4BE0).anim_blending == 0) {
            scale = 0.5f / (*(H_4E5030 *)&D_001A4BE0).anim_key_rate;
        }
        left = frame + (scale * (*(H_4E5030 *)&D_001A4BE0).moby->cls->seqs[(*(H_4E5030 *)&D_001A4BE0).moby->seq]->frames - now);
    }
    if (ticks > 0.0f) {
        key_rate = (*(H_4E5030 *)&D_001A4BE0).anim_key_rate;
        if ((*(H_4E5030 *)&D_001A4BE0).anim_blending != 0) {
            key_rate = *(*(H_4E5030 *)&D_001A4BE0).moby->blend_rate;
        }
        rate = (factor * left) / (ticks * key_rate);
        if (step == -1.0f) {
            (*(H_4E5030 *)&D_001A4BE0).anim_rate = rate;
        } else {
            func_L01_004481F8(&(*(H_4E5030 *)&D_001A4BE0).anim_rate, rate, step);
        }
    }
}
/* localdecomp:end func_L01_004E5030 */

INCLUDE_ASM("asm/levels", func_L01_004E5130);

INCLUDE_ASM("asm/levels", func_L01_004E51A0);

INCLUDE_ASM("asm/levels", func_L01_004E5290);

/* localdecomp:start func_L01_004E52E0 */
/* Ps2EeAs reaches the joint numbers through $gp only if it knows before the use that the
   symbol is small data (retail's own file defined it there); gcc gives no size for it. */
__asm__(".extern D_L01_001DBFE8, 0");
typedef int u128_4E52E0 __attribute__((mode(TI)));
typedef struct {
    s32 count;
    u8 *joints[1];
} JointList_4E52E0;
typedef struct {
    u8 pad0[8];
    u8 joint_count;
    u8 pad9[0x1C - 9];
    JointList_4E52E0 *joint_list;
} MobyClass_4E52E0;
typedef struct {
    u8 pad0[0x10];
    u128_4E52E0 pos;
    u8 pad20[0x24 - 0x20];
    MobyClass_4E52E0 *cls;
    u8 pad28[0x2C - 0x28];
    f32 scale;
    u8 pad30[0xC0 - 0x30];
    u8 rotation[0x30];
} Moby_4E52E0;
typedef struct {
    u128_4E52E0 rows[4];
} Mtx_4E52E0;
extern s32 D_001A71A0[];
extern s32 D_L01_001E14E0[9] __attribute__((section(".sdata")));
extern s32 D_L01_001DBFE8[] __attribute__((section(".sdata")));
extern s32 D_L01_001D6694;
extern Mtx_4E52E0 D_L01_00251420[];
extern u128_4E52E0 D_L01_002F4820[];
extern E_4E1758 D_L01_00251A80[];
extern Mtx_4E52E0 D_001A5810[];
extern void func_L01_0040E388(void *mtx);
extern void func_L01_00440AD8(Moby_4E52E0 *moby);
extern void func_L01_00441740(void *anim, void *out, s32 joint_count);
extern void func_L01_00441558(s32 joint_count, Mtx_4E52E0 *world, f32 scale);
extern void func_0038CF68(void *dst, void *src, f32 scale);
extern void func_0038D570(void *dst, void *src);

/* hero_attach_matrices: poses the hero (his moby, or `moby`) into the scratchpad and copies
   nine of its joint matrices (joints 56, 55, 99, 93, 7, 5, 54, 3, 5, from D_L01_001DBFE8) to
   hero_attach_mats (D_001A5810), where his item mobys are placed. */
void func_L01_004E52E0(Moby_4E52E0 *moby) {
    u128_4E52E0 saved[2];
    Mtx_4E52E0 world;
    s32 i;

    if (moby == 0) {
        moby = (Moby_4E52E0 *)D_001A71A0[0];
    }
    /* the joints' matrix numbers, looked up once */
    if (D_L01_001E14E0[0] == 0) {
        u8 **joints = moby->cls->joint_list->joints;
        s32 j;
        for (j = 0; j < 9; j++) {
            u8 *joint = joints[D_L01_001DBFE8[j]];
            D_L01_001E14E0[j] = joint[joint[0] + 4];
        }
    }
    if (D_L01_001D6694 == 2 || D_L01_001D6694 == 6 || D_L01_001D6694 == 5) {
        func_L01_0040E388(&D_L01_00251420[0]);
        func_L01_0040E388(&D_L01_00251420[1]);
    } else {
        u128_4E52E0 *first = &D_L01_002F4820[0];
        u128_4E52E0 *second = &D_L01_002F4820[11];
        saved[0] = *first;
        saved[1] = *second;
        func_L01_0040E388(first);
        func_L01_0040E388(second);
    }
    func_L01_00440AD8(moby);
    /* his joint matrices, into the scratchpad */
    func_L01_00441740(D_L01_00251A80, (void *)0x70000000, moby->cls->joint_count);
    if (D_L01_001D6694 == 2 || D_L01_001D6694 == 6 || D_L01_001D6694 == 5) {
        func_0038CF68(&D_L01_00251420[0], &D_L01_00251420[0], 0.00999999978f);
        func_0038CF68(&D_L01_00251420[1], &D_L01_00251420[1], 0.00999999978f);
    } else {
        D_L01_002F4820[0] = saved[0];
        D_L01_002F4820[11] = saved[1];
    }
    /* to the world: his rotation, his position, his scale (1/1024 units) */
    func_0038D570(&world, moby->rotation);
    world.rows[3] = moby->pos;
    func_L01_00441558(moby->cls->joint_count, &world, moby->scale * 0.0009765625f);
    for (i = 0; i < 9; i++) {
        func_0038CD28((s32)&D_001A5810[i], (S_4DBFE8_Ent *)((Mtx_4E52E0 *)0x70000000 + D_L01_001E14E0[i]),
                      0x40);
    }
}
/* localdecomp:end func_L01_004E52E0 */

/* localdecomp:start func_L01_004E5520 */



extern E_4E1758 D_L01_00251A80[];
extern E_4E1758 D_L01_00251A88[];
extern E_4E1758 D_L01_00251A90[];
extern u64l func_L01_0040E8B0(u8 *, f32);

void func_L01_004E5520(s32 *list, H_4E1758 *out, u8 *src, s32 pad) {
    u64l *p;
    u64l *q;
    s32 n, nb, nc, j, k, sz, i, tot;
    u64l v;

    out->x10 = 0x7FFF000000000000;
    p = out->data;
    for (n = 1; list[n] >= 0; n++) {
        *p++ = D_L01_00251A80[list[n]].a;
    }
    for (i = 0; i < pad; i++, n++) {
        *p++ = 0x7FFF000000000000;
    }
    nb = 0;
    k = 1;
    sz = n * 8;
    for (; list[k] >= 0; k++) {
        u64l w = D_L01_00251A88[list[k]].a;
        if (w != 0x100010001000) {
            *p = w;
            nb++;
            ((u16 *)p)[3] = k | 0x8000;
            p++;
        }
    }
    tot = n + nb;
    nc = 0;
    for (j = 1; list[j] >= 0; j++) {
        v = D_L01_00251A90[list[j]].a;
        if (v != (func_L01_0040E8B0(*(u8 **)(src + 24) + j * 16, 1.0f) & 0xFFFFFFFFFFFF)) {
            *p = v;
            nc++;
            ((u16 *)p)[3] = j;
            p++;
        }
    }
    if ((s32)p & 0xF) {
        *p++ = 0;
    }
    out->h0 = 0;
    out->h2 = 0;
    out->h4 = 0;
    q = p - 2;
    out->h6 = ((s32)q - (s32)out) >> 4;
    out->h8 = sz;
    out->hA = nb;
    out->hC = tot * 8;
    out->hE = nc;
}
/* localdecomp:end func_L01_004E5520 */

INCLUDE_ASM("asm/levels", func_L01_004E5748);

/* localdecomp:start func_L01_004E5840 */
extern G_4DD4B0 D_001A4BE0;
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_L01_0046ABC0(f32 *, f32 *, f32 *, f32, f32);

void func_L01_004E5840(char *self, int arg1)
{
    f32 v[4] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    f32 f;
    f32 r;
    f32 g;
    int n;
    int i;

    n = (*(G_004E5840 *)&D_001A4BE0).counter + 1;
    (*(G_004E5840 *)&D_001A4BE0).counter = n;
    if (arg1 < (s16)n) {
        for (i = 0; i < 2; i++) {
            if (i == 0)
                f = func_0038DAB8((*(G_004E5840 *)&D_001A4BE0).angle, 0.785398006f);
            else
                f = func_0038DB00((*(G_004E5840 *)&D_001A4BE0).angle, 0.785398006f);
            v[0] = func_0038D098(f) * 0.0120000007f;
            v[1] = func_0038D0B0(f) * 0.0120000007f;
            w[0] = (*(G_004E5840 *)&D_001A4BE0).x + v[0] * 18.0f;
            w[1] = (*(G_004E5840 *)&D_001A4BE0).y + v[1] * 18.0f;
            w[2] = (*(G_004E5840 *)&D_001A4BE0).z;
            v[2] = 0.0f;
            v[0] = v[0] - func_0038D098((*(G_004E5840 *)&D_001A4BE0).angle) * 0.0300000012f;
            v[1] = v[1] - func_0038D0B0((*(G_004E5840 *)&D_001A4BE0).angle) * 0.0300000012f;
            r = func_003824E0(0.4f, 0.5f);
            g = i == 0 ? 2.0f : -2.0f;
            func_L01_0046ABC0(w, v, &(*(G_004E5840 *)&D_001A4BE0).z, r, g);
            (*(G_004E5840 *)&D_001A4BE0).counter = self == 0 ? 0 : func_00382468((int)self);
        }
    }
}
/* localdecomp:end func_L01_004E5840 */

/* localdecomp:start func_L01_004E5A20 */
extern Emit_004E5A20 D_001A4BE0_004E5A20;
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern void func_L01_00468A68(f32 *, f32 *, s32, s32);

void func_L01_004E5A20(int period, int threshold)
{
    Emit_004E5A20 *state = &D_001A4BE0_004E5A20;
    f32 position[4];
    f32 velocity[4];
    f32 angle;
    f32 radius;
    int lifetime;
    state->counter++;
    if (threshold < state->counter) {
        position[0] = state->x + func_003824E0(-0.15f, 0.15f) + state->vx * 8.0f;
        position[1] = state->y + func_003824E0(-0.15f, 0.15f) + state->vy * 8.0f;
        position[2] = state->z + 0.1f;
        angle = func_00382538();
        radius = func_003824E0(0.0f, 0.0600000024f);
        velocity[0] = func_0038D098(angle) * radius + state->vx * 0.75f;
        velocity[1] = func_0038D0B0(angle) * radius + state->vy * 0.75f;
        velocity[2] = func_003824E0(0.0600000024f,0.1300000101f);
        lifetime = func_00382498(90, 120);
        if (state->amount < 0.25f)
            func_L01_00468A68(position, velocity, 3, lifetime);
        else
            func_L01_00468A68(position, velocity, 1, lifetime);
        D_001A4BE0_004E5A20.counter = func_00382468(period);
    }
}
/* localdecomp:end func_L01_004E5A20 */

INCLUDE_ASM("asm/levels", func_L01_004E5C08);

INCLUDE_ASM("asm/levels", func_L01_004E5EB8);

INCLUDE_ASM("asm/levels", func_L01_004E60E8);

/* localdecomp:start func_L01_004E6390 */
extern S_4DC790 D_L01_002F4540[];
void func_L01_004E6390(f32 a, f32 b) {
    (*(S_004E25C8 *)&D_L01_002F4540).a = a;
    (*(S_004E25C8 *)&D_L01_002F4540).b = b;
}
/* localdecomp:end func_L01_004E6390 */

/* localdecomp:start func_L01_004E63A8 */
extern S_4DC790 D_L01_002F4540[];
void func_L01_004E63A8(f32 a, f32 b) {
    (*(S_004E25E0 *)&D_L01_002F4540).a = a;
    (*(S_004E25E0 *)&D_L01_002F4540).b = b;
}
/* localdecomp:end func_L01_004E63A8 */

/* localdecomp:start func_L01_004E63C0 */
extern S_4DC790 D_L01_002F4540[];
void func_L01_004E63C0(f32 a, f32 b) {
    (*(S_004E25F8 *)&D_L01_002F4540).a = a;
    (*(S_004E25F8 *)&D_L01_002F4540).b = b;
}
/* localdecomp:end func_L01_004E63C0 */

/* localdecomp:start func_L01_004E63D8 */
extern S_4DC790 D_L01_002F4540[];
void func_L01_004E63D8(f32 a, f32 b) {
    (*(S_004E2610 *)&D_L01_002F4540).a = a;
    (*(S_004E2610 *)&D_L01_002F4540).b = b;
}
/* localdecomp:end func_L01_004E63D8 */

/* localdecomp:start func_L01_004E63F0 */
extern void func_L01_00511038(char *target, int mode, float value, float zero, float scale);
extern int func_003D3CB0(char *first, char *second, int mode, int flag, int extra);
extern float func_0038CF00(char *source, short *table);
extern short D_L01_001EAA20[];
extern float D_001A4E64 __attribute__((section(".data")));

/* from rac2-decomp's func_L00_002AB108, renamed */
int func_L01_004E63F0(float *out, float scale, float amount)
{
    char buffer[32];
    func_L01_00511038(buffer, 1, D_001A4E64 - 0.02f, 0.0f, scale);
    func_L01_00511038(buffer + 16, 1, amount, 0.0f, scale);
    if (func_003D3CB0(buffer, buffer + 16, 2, 0, 0)) {
        if (out)
            *out = func_0038CF00(buffer, D_L01_001EAA20);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_004E63F0 */

/* localdecomp:start func_L01_004E64C0 */
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
/* the hero's joint springs (43, from D_L01_002F4540) */
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
extern s32 D_L01_001EAA18[];
extern s32 func_003C4B50(s32 moby);
extern int func_L01_004E63F0(float *out, float scale, float amount);

/* hero_gun_arm_raise: with a gun in hand, a ray 0.57 u up (0.7 firing) to 1.3 u ahead; a hit
   raises the gun arm by -70 deg x 1.25 x (1.3 - d) / 1.3, clamped to -30..-70 deg, and sets
   gun_arm_raised. In lock-strafe the arm follows the camera pitch (-80..45 deg) instead. Past
   35 deg the waist bends back for the rest; items 0x3F and 0x97 roll the arm too. */
void func_L01_004E64C0(void) {
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
    if (func_L01_004E63F0(0, height, 1.29999995f)) {
        /* firing with a target that passes func_003C4B50, the arm stays level but raised */
        if (!(*(H_4E64C0 *)&D_001A4BE0).firing || D_L01_001EAA18[0] == 0 || !func_003C4B50(D_L01_001EAA18[0])) {
            f32 d = func_0038CF00((char *)&D_001A4C60, D_L01_001EAA20) - D_001A4C60.radius;
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
        (*(Springs_4E64C0 *)D_L01_002F4540).waist.gain = 0.0720000044f;
        (*(Springs_4E64C0 *)D_L01_002F4540).waist.damping = 0.432000041f;
        (*(Springs_4E64C0 *)D_L01_002F4540).waist.target_y = func_0038DB00(pitch, -0.610865235f);
        pitch = -0.610865235f;
    }
    (*(Springs_4E64C0 *)D_L01_002F4540).gun_clavicle.gain = 0.0720000044f;
    (*(Springs_4E64C0 *)D_L01_002F4540).gun_clavicle.damping = 0.432000041f;
    roll = 0.0f;
    item = func_L01_004E9238(0);
    /* items 0x3F and 0x97 roll the arm too */
    if (item == 0x3F || item == 0x97) {
        roll = pitch * 0.00997330993f;
        if (roll > 0.69813168f) {
            roll = 0.69813168f;
        }
    }
    (*(Springs_4E64C0 *)D_L01_002F4540).gun_clavicle.target_y = pitch;
    (*(Springs_4E64C0 *)D_L01_002F4540).gun_clavicle.target_x = roll;
    /* a gun in both hands: the other clavicle too */
    if ((*(H_4E64C0 *)&D_001A4BE0).hold_type == 2) {
        (*(Springs_4E64C0 *)D_L01_002F4540).other_clavicle.gain = (*(Springs_4E64C0 *)D_L01_002F4540).gun_clavicle.gain;
        (*(Springs_4E64C0 *)D_L01_002F4540).other_clavicle.damping = (*(Springs_4E64C0 *)D_L01_002F4540).gun_clavicle.damping;
        (*(Springs_4E64C0 *)D_L01_002F4540).other_clavicle.target_y = pitch;
        (*(Springs_4E64C0 *)D_L01_002F4540).other_clavicle.target_x = roll;
    }
}
/* localdecomp:end func_L01_004E64C0 */

INCLUDE_ASM("asm/levels", func_L01_004E67C0);

/* localdecomp:start func_L01_004E67F8 */
typedef struct {
    u8 pad0[0x60];
    f32 target_x;
    f32 target_y;
    f32 target_z;
    u8 pad6C[0xA4 - 0x6C];
    f32 gain;
    f32 damping;
    f32 one; /* the joint's scale */
} Spring_4E67F8;
/* the hero's joint springs (43, from D_L01_002F4540) */
typedef struct {
    Spring_4E67F8 root;
    Spring_4E67F8 waist;
    Spring_4E67F8 chest;
    Spring_4E67F8 neck;
    Spring_4E67F8 others[13];
    Spring_4E67F8 head;
    Spring_4E67F8 clank;
} Springs_4E67F8;
typedef struct {
    u8 pad0[0x43];
    u8 sequence;
} Moby_4E67F8;
typedef struct {
    u8 pad0[0x1E8];
    s32 idle_time;
    u8 pad1EC[0x208 - 0x1EC];
    s16 fidget_gap;
    u8 pad20A[0x298 - 0x20A];
    f32 wall_height;
    u8 pad29C[0x2A8 - 0x29C];
    f32 wall_distance;
    f32 wall_clearance;
    s32 wall_valid;
    u8 pad2B4[0xBD8 - 0x2B4];
    s32 gun_target;
    u8 padBDC[0x1174 - 0xBDC];
    f32 glance_pitch;
    f32 glance_yaw;
    u8 pad117C[0x1180 - 0x117C];
    s32 glance_timer;
    f32 glance_gain;
    f32 glance_damping;
    u8 pad118C[0x12F4 - 0x118C];
    s32 back_clank;
    u8 pad12F8[0x25C0 - 0x12F8];
    Moby_4E67F8 *hero_moby;
    s32 state;
    u8 pad25C8[0x25E9 - 0x25C8];
    u8 firing;
    u8 pad25EA[0x27FC - 0x25EA];
    s32 look_at;
} H_4E67F8;
extern u8 D_001D5470; /* a cheat: a big Clank */
extern u8 D_001D5472; /* a cheat: a big head */
__asm__(".extern D_L01_001DBD38, 4");
extern f32 D_L01_001DBD38 __attribute__((section(".sdata"))); /* the head's scale */
extern f32 D_L01_001DBD3C __attribute__((section(".sdata"))); /* Clank's scale */
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L01_004E67C0(void);
extern void func_L01_004E63A8(f32 a, f32 b);
extern void func_L01_004E63D8(f32 a, f32 b);
extern s32 func_00382498(s32, s32);
extern s32 func_L01_004E9238(s32 slot);
extern s32 func_0038CAD0(s32 *timer);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32 a, f32 b);
extern f32 func_003C4088(f32 a, f32 b, f32 t);

/* hero_idle_glance: idle glances on the neck and waist springs at random targets and times;
   firing or with a gun target, zeroes them (gains 0.0432, 0.288); facing a wall close ahead,
   looks up at it. */
void func_L01_004E67F8(void) {
    s32 turn_waist;
    f32 pitch;
    f32 cap;
    f32 t;
    s32 timer;

    if (D_001D5470 != 0 && (*(H_4E67F8 *)&D_001A4BE0).back_clank != 0) {
        (*(Springs_4E67F8 *)D_L01_002F4540).clank.one = D_L01_001DBD3C;
    }
    (*(Springs_4E67F8 *)D_L01_002F4540).head.one = D_L01_001DBD38;
    if (D_001D5472 != 0) {
        func_003C4138(&D_L01_001DBD38, 1.57000005f, 0.0500000007f);
    } else {
        func_003C4138(&D_L01_001DBD38, 0.875f, 0.0500000007f);
    }
    if ((*(H_4E67F8 *)&D_001A4BE0).idle_time <= 16) {
        return;
    }
    if ((*(H_4E67F8 *)&D_001A4BE0).firing != 0 || (*(H_4E67F8 *)&D_001A4BE0).gun_target != 0) {
        func_L01_004E67C0();
        func_L01_004E63D8(0.0432000011f, 0.288000017f);
        func_L01_004E63A8(0.0432000011f, 0.288000017f);
        (*(H_4E67F8 *)&D_001A4BE0).glance_timer = func_00382498(75, 100);
        (*(H_4E67F8 *)&D_001A4BE0).fidget_gap = func_00382498(75, 100);
        return;
    }
    /* a wall close ahead: looks up at it */
    if ((*(H_4E67F8 *)&D_001A4BE0).wall_valid != 0 && (*(H_4E67F8 *)&D_001A4BE0).wall_distance > 1.39999998f &&
        (*(H_4E67F8 *)&D_001A4BE0).wall_height > 1.0f) {
        func_L01_004E63D8(0.0216000006f, 0.432000041f);
        /* 11 deg and 1.5 deg a unit away, at most 27 deg */
        pitch = (*(H_4E67F8 *)&D_001A4BE0).wall_distance * 1.5f * 0.0174532924f + 0.191986218f;
        if (pitch > 0.471238881f) {
            pitch = 0.471238881f;
        }
        cap = (1.0f - (*(H_4E67F8 *)&D_001A4BE0).wall_clearance) * 35.0f * 0.0174532924f;
        if (cap < pitch) {
            pitch = cap;
        }
        (*(Springs_4E67F8 *)D_L01_002F4540).neck.target_y = pitch;
        func_L01_004E63A8(0.0115200011f, 0.432000041f);
        (*(Springs_4E67F8 *)D_L01_002F4540).waist.target_y = (*(Springs_4E67F8 *)D_L01_002F4540).neck.target_y * 0.699999988f;
        return;
    }
    turn_waist = func_L01_004E9238(0) != 0x2F;
    if ((*(H_4E67F8 *)&D_001A4BE0).state != 0) {
        return;
    }
    if (!((*(H_4E67F8 *)&D_001A4BE0).hero_moby->sequence < 3 || (*(H_4E67F8 *)&D_001A4BE0).hero_moby->sequence == 0x35) ||
        (*(H_4E67F8 *)&D_001A4BE0).look_at != 0) {
        return;
    }
    if ((*(H_4E67F8 *)&D_001A4BE0).hero_moby->sequence == 1 || (*(H_4E67F8 *)&D_001A4BE0).hero_moby->sequence == 2) {
        (*(H_4E67F8 *)&D_001A4BE0).glance_timer = func_00382498(33, 58);
    }
    /* a new glance when the timer runs out */
    if (func_0038CAD0(&(*(H_4E67F8 *)&D_001A4BE0).glance_timer) != 0) {
        (*(H_4E67F8 *)&D_001A4BE0).glance_pitch = -func_003824E0(-0.157079637f, 0.436332315f);
        if ((*(H_4E67F8 *)&D_001A4BE0).wall_height < 1.5f) {
            (*(H_4E67F8 *)&D_001A4BE0).glance_yaw = func_L01_00443A18(0.872664630f, 1.22173047f);
        } else {
            (*(H_4E67F8 *)&D_001A4BE0).glance_yaw = func_L01_00443A18(0.349065840f, 0.994837642f);
        }
        t = func_003824E0(0.0f, 1.0f);
        (*(H_4E67F8 *)&D_001A4BE0).glance_gain = func_003C4088(0.0149999997f, 0.00700000022f, t);
        (*(H_4E67F8 *)&D_001A4BE0).glance_damping = func_003C4088(0.289999992f, 0.300000012f, t);
        /* 75-167 frames to the next, and up to 67 more the longer it lasts */
        timer = func_00382498(75, 167);
        t *= 67.0f;
        (*(H_4E67F8 *)&D_001A4BE0).glance_timer = timer + (s32)t;
    }
    if ((*(H_4E67F8 *)&D_001A4BE0).hero_moby->sequence == 1 || (*(H_4E67F8 *)&D_001A4BE0).hero_moby->sequence == 2) {
        if ((*(H_4E67F8 *)&D_001A4BE0).glance_yaw > 0.349065840f) {
            (*(H_4E67F8 *)&D_001A4BE0).glance_yaw = 0.349065840f;
        } else if ((*(H_4E67F8 *)&D_001A4BE0).glance_yaw < -0.349065840f) {
            (*(H_4E67F8 *)&D_001A4BE0).glance_yaw = -0.349065840f;
        }
        if ((*(H_4E67F8 *)&D_001A4BE0).glance_pitch > 0.261799395f) {
            (*(H_4E67F8 *)&D_001A4BE0).glance_pitch = 0.261799395f;
        }
        if ((*(H_4E67F8 *)&D_001A4BE0).glance_pitch < 0.0f) {
            (*(H_4E67F8 *)&D_001A4BE0).glance_pitch = 0.0f;
        }
    }
    func_L01_004E63D8((*(H_4E67F8 *)&D_001A4BE0).glance_gain, (*(H_4E67F8 *)&D_001A4BE0).glance_damping);
    (*(Springs_4E67F8 *)D_L01_002F4540).neck.target_z = (*(H_4E67F8 *)&D_001A4BE0).glance_yaw;
    (*(Springs_4E67F8 *)D_L01_002F4540).neck.target_y = (*(H_4E67F8 *)&D_001A4BE0).glance_pitch;
    if (turn_waist) {
        func_L01_004E63A8(0.0115200011f, 0.432000041f);
        (*(Springs_4E67F8 *)D_L01_002F4540).waist.target_z = (*(Springs_4E67F8 *)D_L01_002F4540).neck.target_z * 0.519999981f;
        (*(Springs_4E67F8 *)D_L01_002F4540).waist.target_y = (*(Springs_4E67F8 *)D_L01_002F4540).neck.target_y * 0.550000012f;
    }
}
/* localdecomp:end func_L01_004E67F8 */

/* localdecomp:start func_L01_004E6D10 */
void func_L01_004E6D10(void) {

}
/* localdecomp:end func_L01_004E6D10 */

INCLUDE_ASM("asm/levels", func_L01_004E6D18);
