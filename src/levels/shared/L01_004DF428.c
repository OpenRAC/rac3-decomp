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

/* localdecomp:start func_L01_004DFE88 */
extern f32 D_L01_001DBF90[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DBF90, 8");
f32 func_L01_004DFE88(s32 armor) {
    return D_L01_001DBF90[armor];
}
/* localdecomp:end func_L01_004DFE88 */

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
extern void func_003E4D10(s32 frames);

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
    func_003E4D10(300);
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

/* localdecomp:start func_L01_004E04E8 */
#include "vu0.h"
/* one of the hero's joint springs (43 of them at D_L01_002F4540) */
typedef struct {
    u8 p0;
    u8 active;
    u8 p2[0x40 - 2];
    vu0_q v40;
    u8 p50[0x60 - 0x50];
    vu0_q v60;
    u8 p70[0x90 - 0x70];
    vu0_q v90;
    u8 pA0[2];
    s16 kind;
    u8 pA4[0xAC - 0xA4];
    f32 fAC;
} R_004E04E8;
extern void func_003C2C98_004E04E8(void *moby, void *spring);

/* from rac2-decomp's func_L00_002A53B8 */
void func_L01_004E04E8(void) {
    s32 i;
    s32 moby;

    for (i = 0; i < 43; i++) {
        if (((R_004E04E8 *)D_L01_002F4540)[i].active != 0) {
            moby = func_L01_004E0100(((R_004E04E8 *)D_L01_002F4540)[i].kind);
            if (moby != 0) {
                func_003C2C98_004E04E8((void *)moby, &((R_004E04E8 *)D_L01_002F4540)[i]);
            }
        }
        qzero(&((R_004E04E8 *)D_L01_002F4540)[i].v40);
        qzero(&((R_004E04E8 *)D_L01_002F4540)[i].v60);
        qzero(&((R_004E04E8 *)D_L01_002F4540)[i].v90);
        ((R_004E04E8 *)D_L01_002F4540)[i].fAC = 1.0f;
    }
}
/* localdecomp:end func_L01_004E04E8 */

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
extern void func_003C2C98(Moby_4E0618 *moby, Lid_4E0618 *lid);

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
                func_003C2C98((*(H_4E0618 *)&D_001A4BE0).moby, &(*(H_4E0618 *)&D_001A4BE0).lids[i]);
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

/* localdecomp:start func_L01_004E0920 */
typedef struct {
    u8 p0[0x34];
    u16 flags;
    u8 p36[0x43 - 0x36];
    u8 seq;
    u8 p44[0x78 - 0x44];
    s32 color;
} Moby_4E0920;
typedef struct {
    u8 p0[0x20E];
    s16 fade;
    u8 p210[0x116C - 0x210];
    s16 timer;
    s16 flash;
    u8 p1170[0x12F4 - 0x1170];
    Moby_4E0920 *other;
    u8 p12F8[0x25C0 - 0x12F8];
    Moby_4E0920 *moby;
    s32 state;
    u8 p25C8[0x25E4 - 0x25C8];
    u8 critter;
    u8 p25E5[0x2884 - 0x25E5];
    s16 h2884;
} Hero_4E0920;
extern u8 D_001D5470;
extern s32 D_L01_001DFB40;
extern f32 D_L01_001DBD3C __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DBD3C, 4");
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_0038CB00(void *);
extern f32 func_0038D0B0(f32);
extern s32 func_00382498(s32, s32);
extern s32 func_L01_004DFD60(void);

/* hero_glow_color: the hero's moby colour, red 0x38 (0x88 at low health) and a green and blue that
   pulse with a 92-frame sine; while `fade` (0x20E) runs, the colour fades in over its first 17
   and out over its last 4 of 37 frames. Then the flash timer (0x116C/0x116E) in sequence 1. */
void func_L01_004E0920(void) {
    Moby_4E0920 *moby;
    s32 period;
    s32 wave_r;
    s32 wave_g;
    s32 red;
    s32 green;
    s32 blue;
    s32 alpha;
    s32 dr;
    f32 s;
    f32 f;
    s32 fade;
    s32 len;
    s32 in;
    s32 out;

    if (D_001D5470) {
        func_003C4138(&D_L01_001DBD3C, 1.8f, 0.05f);
    } else {
        func_003C4138(&D_L01_001DBD3C, 1.0f, 0.05f);
    }
    if ((u8)((*(Hero_4E0920 *)&D_001A4BE0).critter - 1) < 2) {
        moby = (*(Hero_4E0920 *)&D_001A4BE0).moby;
    } else if ((*(Hero_4E0920 *)&D_001A4BE0).h2884 != 0) {
        return;
    } else {
        moby = (*(Hero_4E0920 *)&D_001A4BE0).other;
    }
    if (moby == 0) {
        return;
    }
    moby->flags |= 0x10;
    alpha = 0x80;
    red = 0x38;
    green = 0x88;
    if (func_L01_004DFD60()) {
        red = 0x88;
    }
    period = 92;
    s = func_0038D0B0((f32)(D_L01_001DFB40 % period) / (f32)period * 2.0f * 3.14159274f + -3.14159274f);
    wave_r = (s32)(s * 24.0f) + 12;
    wave_g = (s32)(s * 48.0f) + 24;
    red += wave_r;
    blue = wave_r + 64;
    green += wave_g;
    fade = (*(Hero_4E0920 *)&D_001A4BE0).fade;
    if (fade != 0) {
        len = 37;
        in = 17;
        out = 4;
        f = 1.0f;
        if (fade > len - out) {
            f = (f32)(len - fade) / (f32)out;
        }
        if (fade < in) {
            f = (f32)fade / (f32)in;
        }
        dr = (s32)((f32)wave_r * f);
        red -= dr;
        green -= (s32)((f32)wave_g * f);
        blue -= dr;
        red += (s32)(f * 112.0f);
        green -= (s32)(f * 72.0f);
    }
    moby->color = (alpha << 24) | (blue << 16) | (green << 8) | red;
    if ((*(Hero_4E0920 *)&D_001A4BE0).critter != 0) {
        return;
    }
    if ((*(Hero_4E0920 *)&D_001A4BE0).state == 0x81) {
        return;
    }
    if (func_0038CB00(&(*(Hero_4E0920 *)&D_001A4BE0).timer)) {
        if (moby->seq == 1) {
            (*(Hero_4E0920 *)&D_001A4BE0).timer = func_00382498(42, 167);
            (*(Hero_4E0920 *)&D_001A4BE0).flash = 1;
        }
    }
    if ((*(Hero_4E0920 *)&D_001A4BE0).flash != 0) {
        if (++(*(Hero_4E0920 *)&D_001A4BE0).flash >= 22) {
            (*(Hero_4E0920 *)&D_001A4BE0).flash = 0;
        }
    }
}
/* localdecomp:end func_L01_004E0920 */

/* localdecomp:start func_L01_004E0C18 */
typedef struct {
    u8 pad0[0x1A58];
    u8 *p1A58;
    u8 pad1A5C[0x25C0 - 0x1A5C];
    u8 *p25C0;
} V_004E0C18;

__asm__(".extern D_L01_001DBD54, 4");
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_0044FD88(u8 *, u8 *, s32, s32);
extern void func_L01_004E9C08(void *, s32);
extern u8 D_001A65F0[];

void func_L01_004E0C18(void) {
    if (D_L01_001DBD54 != 0) {
        if ((*(V_004E0C18 *)&D_001A4BE0).p1A58 == 0) {
            (*(V_004E0C18 *)&D_001A4BE0).p1A58 = func_003C24B0(0x1AB5, 0x80);
            if ((*(V_004E0C18 *)&D_001A4BE0).p1A58 == 0) {
                goto done;
            }
            func_L01_00456160((*(V_004E0C18 *)&D_001A4BE0).p1A58, (*(V_004E0C18 *)&D_001A4BE0).p25C0);
            if ((*(V_004E0C18 *)&D_001A4BE0).p1A58 == 0) {
                goto done;
            }
        }
        func_L01_0044FD88((*(V_004E0C18 *)&D_001A4BE0).p25C0, (*(V_004E0C18 *)&D_001A4BE0).p1A58, 2, 0);
        (**(void (**)(u8 *))((*(V_004E0C18 *)&D_001A4BE0).p1A58 + 0x64))((*(V_004E0C18 *)&D_001A4BE0).p1A58);
done:
        func_L01_004E9C08(D_001A65F0, 1);
    }
}
/* localdecomp:end func_L01_004E0C18 */

/* localdecomp:start func_L01_004E0CB0 */
extern s32 D_001A6634[];
extern void func_L01_004E3268(void);

void func_L01_004E0CB0(void) {
    if (D_001A6634[0]) {
        func_L01_004E3268();
    }
}
/* localdecomp:end func_L01_004E0CB0 */

/* localdecomp:start func_L01_004E0CD8 */
typedef struct {
    u8 pad0[0x80]; u128_t pos; u128_t rot;
    u8 padA0[0x1A24-0xA0]; u8 *effect; f32 phase;
    u8 pad1A2C[0x22C0-0x1A2C]; u128_t joint;
    u8 pad22D0[0x25C0-0x22D0]; u8 *moby;
    u8 pad25C4[0x28A8-0x25C4]; s16 timer; s16 type; s32 color;
} Hero_004E0CD8;
typedef struct { unsigned char active:1; } Flag_004E0CD8;
extern G_4DD4B0 D_001A4BE0;
extern u8 D_001D5470;
void func_L01_004E0CD8(void) {
    extern u8 *func_003C24B0(s32, s32);
    extern void func_003C7C38(void *);
    extern void func_003C2F58(u8 *, s32, void *);
    extern void func_003C2EC0(u8 *, s32, void *);
    extern void func_0038D590(void *, void *);
    extern void func_L01_004E3268(void);
    extern f32 func_003C4138(f32 *, f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern s32 func_0038CB00(void *);
    extern void func_003A52A0(s32, s32, u8 *);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    struct { u128_t joint; u128_t matrix[4]; } work;
    s32 color0, color1, color;
    f32 scale;
    if ((*(Hero_004E0CD8 *)&D_001A4BE0).effect == 0) {
        (*(Hero_004E0CD8 *)&D_001A4BE0).effect = func_003C24B0(0x4B4, 0x80);
        if ((*(Hero_004E0CD8 *)&D_001A4BE0).effect) {
            *(s32 *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x78) = 0x801432D7;
            (*(Hero_004E0CD8 *)&D_001A4BE0).color = 0x301432D7;
            *(u128_t *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x10) = (*(Hero_004E0CD8 *)&D_001A4BE0).pos;
            *(u128_t *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0xF0) = (*(Hero_004E0CD8 *)&D_001A4BE0).rot;
            *(s16 *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x32) = 64;
            (*(Hero_004E0CD8 *)&D_001A4BE0).effect[0x31] = 1;
            (*(Hero_004E0CD8 *)&D_001A4BE0).effect[0x30] = 0;
            *(s16 *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x34) = 0;
            *(f32 *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x2C) *= 1.7f;
            *(u16 *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x34) |= 0x10;
            func_003C7C38((*(Hero_004E0CD8 *)&D_001A4BE0).effect);
        }
    }
    if (((*(Hero_004E0CD8 *)&D_001A4BE0).moby[0x34] ^ 1) & 1) {
        func_003C2F58((*(Hero_004E0CD8 *)&D_001A4BE0).moby, 7, &work.joint);
        (*(Hero_004E0CD8 *)&D_001A4BE0).joint = work.joint;
        func_L01_004E3268();
        if ((*(Hero_004E0CD8 *)&D_001A4BE0).effect) {
            u128_t *mat = work.matrix;
            func_003C2EC0((*(Hero_004E0CD8 *)&D_001A4BE0).moby, 7, mat);
            *(u128_t *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x10) = work.matrix[3];
            func_0038D590((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0xC0, mat);
            func_003C7C38((*(Hero_004E0CD8 *)&D_001A4BE0).effect);
            scale = 1.7f;
            if (D_001D5470) scale = 3.1f;
            if ((*(Hero_004E0CD8 *)&D_001A4BE0).timer) scale *= 1.4f;
            func_003C4138((f32 *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x2C), *(f32 *)(*(u8 **)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x24) + 0x24) * scale, 0.02f);
        }
    }
    (*(Hero_004E0CD8 *)&D_001A4BE0).phase = func_0038DAB8((*(Hero_004E0CD8 *)&D_001A4BE0).phase, 0.059341195f);
    color0 = 0x281414C8;
    color1 = 0x1E00004B;
    if (!func_0038CB00(&(*(Hero_004E0CD8 *)&D_001A4BE0).timer)) {
        (*(Hero_004E0CD8 *)&D_001A4BE0).phase = func_0038DAB8((*(Hero_004E0CD8 *)&D_001A4BE0).phase, 0.2443461f);
        switch ((*(Hero_004E0CD8 *)&D_001A4BE0).type) {
            case 1: color0 = 0x2814C814; color1 = 0x1E004B00; break;
            case 2: color0 = 0x2814C8C8; color1 = 0x1E004B4B; break;
            case 3: color0 = 0x323232FA; color1 = 0x1E000078; break;
            case 4: color0 = 0x28F01414; color1 = 0x1E4B0000; break;
        }
        if ((*(Hero_004E0CD8 *)&D_001A4BE0).timer >= 41 && ((*(Hero_004E0CD8 *)&D_001A4BE0).timer & 1)) {
            func_003A52A0((*(Hero_004E0CD8 *)&D_001A4BE0).type + 16, 0, (*(Hero_004E0CD8 *)&D_001A4BE0).moby);
        }
    }
    color = func_0038DBD8(color0, color1, func_0038D0B0((*(Hero_004E0CD8 *)&D_001A4BE0).phase) * 0.5f + 0.5f);
    if ((*(Hero_004E0CD8 *)&D_001A4BE0).effect) {
        *(s32 *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x78) = func_0038DBD8(*(s32 *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x78), color, 0.12000000476837158f);
    }
    (*(Hero_004E0CD8 *)&D_001A4BE0).color = func_0038DBD8((*(Hero_004E0CD8 *)&D_001A4BE0).color, color, 0.12000000476837158f);
}
/* localdecomp:end func_L01_004E0CD8 */

/* localdecomp:start func_L01_004E1020 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x80]; u128_t pos; u128_t rot;
    u8 padA0[0x1A20-0xA0]; u8 *effect;
    u8 pad1A24[0x25C0-0x1A24]; u8 *moby; s32 state;
} Hero_004E1020;
extern G_4DD4B0 D_001A4BE0;
void func_L01_004E1020(void) {
    extern u8 *func_003C24B0(s32, s32);
    extern void func_003C7C38(void *);
    extern void func_003C2EC0(u8 *, s32, void *);
    extern void func_0038D328(void *, void *);
    extern void func_0038D640(void *, void *, void *);
    extern void func_0038D590(void *, void *);
    extern void func_003C3A10(u8 *, s32, s32, s32);
    u128_t matrix[4];
    union { u128_t q; f32 v[4]; } rotation;
    u128_t rotate_matrix[4];
    if ((*(Hero_004E1020 *)&D_001A4BE0).effect == 0) {
        (*(Hero_004E1020 *)&D_001A4BE0).effect = func_003C24B0(0x47A, 0x80);
        if ((*(Hero_004E1020 *)&D_001A4BE0).effect == 0) return;
        *(u128_t *)((*(Hero_004E1020 *)&D_001A4BE0).effect+0x10) = (*(Hero_004E1020 *)&D_001A4BE0).pos;
        *(u128_t *)((*(Hero_004E1020 *)&D_001A4BE0).effect+0xF0) = (*(Hero_004E1020 *)&D_001A4BE0).rot;
        *(s16 *)((*(Hero_004E1020 *)&D_001A4BE0).effect+0x32) = 64;
        (*(Hero_004E1020 *)&D_001A4BE0).effect[0x31] = 1;
        (*(Hero_004E1020 *)&D_001A4BE0).effect[0x30] = 0;
        *(s16 *)((*(Hero_004E1020 *)&D_001A4BE0).effect+0x34) = 0;
        func_003C7C38((*(Hero_004E1020 *)&D_001A4BE0).effect);
    }
    if ((*(Hero_004E1020 *)&D_001A4BE0).effect) {
        func_003C2EC0((*(Hero_004E1020 *)&D_001A4BE0).moby, 5, matrix);
        *(u128_t *)((*(Hero_004E1020 *)&D_001A4BE0).effect+0x10) = matrix[3];
        func_003C7C38((*(Hero_004E1020 *)&D_001A4BE0).effect);
        qzero(&rotation);
        rotation.v[2] = -((f32 *)&(*(Hero_004E1020 *)&D_001A4BE0).rot)[2];
        func_0038D328(rotate_matrix, &rotation);
        func_0038D640(matrix, matrix, rotate_matrix);
        func_0038D590((*(Hero_004E1020 *)&D_001A4BE0).effect+0xC0, matrix);
        *(unsigned long *)((*(Hero_004E1020 *)&D_001A4BE0).effect+0x38) = *(unsigned long *)((*(Hero_004E1020 *)&D_001A4BE0).moby+0x38);
        if ((*(Hero_004E1020 *)&D_001A4BE0).state == 75) {
            if ((*(Hero_004E1020 *)&D_001A4BE0).effect[0x43] != 1) func_003C3A10((*(Hero_004E1020 *)&D_001A4BE0).effect, 1, 0, 8);
        } else if ((*(Hero_004E1020 *)&D_001A4BE0).effect[0x43] != 0) func_003C3A10((*(Hero_004E1020 *)&D_001A4BE0).effect, 0, 0, 14);
    }
}
/* localdecomp:end func_L01_004E1020 */

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

/* localdecomp:start func_L01_004E13A0 */
typedef struct {
    u8 p0[0x238]; s32 mode;
    u8 p23C[0x25C0-0x23C]; u8 *moby;
    u8 p25C4[0x25E4-0x25C4]; u8 critter;
    u8 p25E5[0x25F8-0x25E5]; s32 active;
    u8 p25FC[0x286C-0x25FC]; u8 *effect;
    u8 p2870[0x2888-0x2870]; s16 a, b, c;
    u8 p288E[0x28A8-0x288E]; s16 timer, type;
} Hero_004E13A0;
extern G_4DD4B0 D_001A4BE0;
extern f32 D_L01_001DBD3C __attribute__((section(".sdata")));
extern f32 D_L01_002F571C __attribute__((section(".data")));
__asm__(".extern D_L01_001DBD3C, 4");
void func_L01_004E13A0(void) {
    extern void func_L01_0050FF00(void);
    extern void func_L01_004EE4E0(void);
    extern void func_L01_004E7CB8(void);
    extern void func_L01_004E8318(void *, void *, void *);
    extern void func_L01_004F3BE0(void);
    extern void func_L01_004E0C18(void);
    extern void func_L01_004E0CB0(void);
    extern void func_L01_00507AF8(void);
    extern void func_L01_004E9450_004E13A0(void);
    extern void func_L01_004F5010(void);
    extern void func_L01_004E04A0(void);
    extern void func_L01_004E4770(void);
    extern void func_L01_004E3148(void);
    extern void func_L01_00512E68(void);
    extern void func_L01_004E2ED0(void);
    extern void func_L01_004E0920(void);
    extern void func_L01_004E0CD8(void);
    extern void func_L01_004E1020(void);
    extern void func_003A52A0(s32, s32, u8 *);
    extern void func_L01_00430118(void *);
    extern void func_L01_004E48C8(void);
    extern void func_L01_004436F4(u8 *);
    func_L01_0050FF00();
    func_L01_004EE4E0();
    func_L01_004E7CB8();
    if ((*(Hero_004E13A0 *)&D_001A4BE0).critter == 1) {
        func_L01_004E8318((u8 *)&D_001A4BE0 + 0x80, (u8 *)&D_001A4BE0 + 0x90, (u8 *)&D_001A4BE0 + 0x500);
        func_L01_004F3BE0();
        if ((*(Hero_004E13A0 *)&D_001A4BE0).critter == 1) {
            func_L01_004E0C18();
            func_L01_004E0CB0();
        }
    }
    (*(Hero_004E13A0 *)&D_001A4BE0).mode = 3;
    func_L01_00507AF8();
    func_L01_004E9450_004E13A0();
    if ((*(Hero_004E13A0 *)&D_001A4BE0).critter == 0) return;
    func_L01_004F5010();
    func_L01_004E04A0();
    if ((*(Hero_004E13A0 *)&D_001A4BE0).critter == 0) return;
    func_L01_004E4770();
    func_L01_004E3148();
    func_L01_00512E68();
    func_L01_004E2ED0();
    if ((*(Hero_004E13A0 *)&D_001A4BE0).critter == 1) {
        D_L01_002F571C = D_L01_001DBD3C;
        func_L01_004E0920();
        func_L01_004E0CD8();
        func_L01_004E1020();
        if ((*(Hero_004E13A0 *)&D_001A4BE0).effect) {
            func_003A52A0((s32)((*(Hero_004E13A0 *)&D_001A4BE0).effect + 0x10), 0, (*(Hero_004E13A0 *)&D_001A4BE0).moby);
            (*(Hero_004E13A0 *)&D_001A4BE0).timer = 47;
            (*(Hero_004E13A0 *)&D_001A4BE0).type = *(u16 *)&(*(Hero_004E13A0 *)&D_001A4BE0).effect;
        }
        (*(Hero_004E13A0 *)&D_001A4BE0).effect = 0;
    }
    func_L01_00430118((u8 *)&D_001A4BE0 + 0x80);
    if ((*(Hero_004E13A0 *)&D_001A4BE0).critter == 3) {
        if ((*(Hero_004E13A0 *)&D_001A4BE0).active == 0 || (*(Hero_004E13A0 *)&D_001A4BE0).active == 30) {
            goto clear_active;
        } else if ((*(Hero_004E13A0 *)&D_001A4BE0).c == 0) {
            (*(Hero_004E13A0 *)&D_001A4BE0).a = 1;
            (*(Hero_004E13A0 *)&D_001A4BE0).c = 18;
            (*(Hero_004E13A0 *)&D_001A4BE0).b = 1;
        }
        goto after_active;
clear_active:
        (*(Hero_004E13A0 *)&D_001A4BE0).active = 0;
    }
after_active:
    func_L01_004E48C8();
    func_L01_004436F4((*(Hero_004E13A0 *)&D_001A4BE0).moby);
}
/* localdecomp:end func_L01_004E13A0 */

/* localdecomp:start func_L01_004E1560 */
typedef struct { u8 pad[0xD0]; u8 active; u8 padD1[11]; s32 owner; } Entry_004E1560;
typedef struct { u8 pad[0x25C0]; s32 moby; u8 pad25C4[0x278C-0x25C4]; s32 ids[9]; s32 owners[9]; } Hero_004E1560;
extern u8 D_001A30B0[];
void func_L01_004E1560(void) {
    extern void func_003A4F28(s32);
    Hero_004E1560 *hero = (Hero_004E1560 *)&D_001A4BE0;
    s32 *p = hero->ids;
    s32 i;
    for (i = 8; i >= 0; i--, p++) {
        s32 owner = p[9];
        s32 remove;
        if (owner != 0) {
            s32 id = p[0];
            Entry_004E1560 *entry;
            if (id == -1) goto clear;
            entry = (Entry_004E1560 *)(D_001A30B0 + (id << 7));
            if (entry->owner != owner || entry->active == 0) goto clear;
            remove = id;
        } else {
            s32 id = p[0];
            Entry_004E1560 *entry;
            if (id == -1) goto clear;
            entry = (Entry_004E1560 *)(D_001A30B0 + (id << 7));
            if (entry->owner != hero->moby || entry->active == 0) goto clear;
            remove = id;
        }
        func_003A4F28(remove);
clear:
        p[0] = -1;
    }
}
/* localdecomp:end func_L01_004E1560 */

INCLUDE_ASM("asm/levels", func_L01_004E1638);

/* localdecomp:start func_L01_004E1F00 */
typedef struct {
    u128_t matrix[4]; /* 0x0: his matrix rows */
    u8 pad_40[0x40];
    u128_t pos; /* 0x80: position */
    u128_t rot; /* 0x90: roll, pitch, yaw */
    u8 pad_A0[0x10];
    u128_t xB0; /* 0xB0 */
    u8 pad_C0[0x20];
    u128_t pickup_point; /* 0xE0: 0.7 u above his feet */
    u8 pad_F0[0x60];
    u128_t carried; /* 0x150: what the platform carry moved him */
    u8 pad_160[0x10];
    f32 speed_own_a; /* 0x170 */
    f32 speed_own_b; /* 0x174 */
    u8 pad_178[0xA2];
    s16 x21A; /* 0x21A */
    u8 pad_21C[0xC4];
    u128_t down; /* 0x2E0 */
    u8 pad_2F0[0x4C];
    f32 height_above_ground; /* 0x33C */
    u8 pad_340[0x10];
    f32 water_height; /* 0x350 */
    u8 pad_354[0x8];
    s32 ground_moby; /* 0x35C */
    s32 ground_frames; /* 0x360 */
    u8 pad_364[0x4];
    u16 x368; /* 0x368 */
    u8 pad_36A[0x2];
    u16 frames_off_any; /* 0x36C */
    u16 air_frames; /* 0x36E */
    u8 pad_370[0xFE];
    u8 past_apex; /* 0x46E */
    u8 pad_46F[0xF];
    u16 frames_to_land; /* 0x47E */
    u8 pad_480[0x70];
    u128_t x4F0; /* 0x4F0 */
    u8 pad_500[0x24];
    f32 ledge_wall_yaw; /* 0x524 */
    u8 pad_528[0x4FC];
    s32 xA24; /* 0xA24 */
    u8 pad_A28[0x2C];
    s32 xA54; /* 0xA54 */
    u8 pad_A58[0x8];
    f32 xA60; /* 0xA60 */
    u8 pad_A64[0x8];
    f32 xA6C; /* 0xA6C */
    u8 pad_A70[0x9C4];
    u16 lockon_strafing; /* 0x1434 */
    u8 pad_1436[0x40];
    u8 in_puddle; /* 0x1476 */
    u8 x1477; /* 0x1477 */
    u8 x1478; /* 0x1478 */
    u8 pad_1479[0x4];
    u8 x147D; /* 0x147D */
    u8 x147E; /* 0x147E */
    u8 pad_147F[0xC1];
    u128_t look_cam_matrix[3]; /* 0x1540: free-look camera matrix */
    u128_t look_cam_pos; /* 0x1570 */
    u8 pad_1580[0x130];
    u8 hero_camera_mode; /* 0x16B0 */
    u8 pad_16B1[0x32F];
    s32 x19E0; /* 0x19E0 */
    u8 pad_19E4[0xBDC];
    s32 hero_moby; /* 0x25C0 */
    s32 state; /* 0x25C4 */
    u8 pad_25C8[0x4];
    s32 state_type; /* 0x25CC */
    s32 prev_state; /* 0x25D0 */
    u8 pad_25D4[0x10];
    u8 critter_mode; /* 0x25E4 */
    u8 pad_25E5[0x227];
    s32 camera_request; /* 0x280C */
} Hero_4E1F00;

typedef struct {
    u128_t matrix[4]; /* 0x0 */
    u128_t pos; /* 0x40 */
    u128_t rot; /* 0x50 */
    u128_t pickup_point; /* 0x60 */
    u128_t carried; /* 0x70 */
    u128_t down; /* 0x80 */
    u128_t x90; /* 0x90 */
    u128_t xA0; /* 0xA0 */
    u128_t look_cam_matrix[3]; /* 0xB0 */
    u128_t look_cam_pos; /* 0xE0 */
    s32 hero_moby; /* 0xF0 */
    s32 xF4; /* 0xF4 */
    s32 ground_moby; /* 0xF8 */
    s32 camera_request; /* 0xFC */
    s32 state; /* 0x100 */
    s32 state_type; /* 0x104 */
    s32 prev_state; /* 0x108 */
    f32 speed_own_a; /* 0x10C */
    f32 speed_own_b; /* 0x110 */
    f32 height_above_ground; /* 0x114 */
    f32 water_height; /* 0x118 */
    s32 ground_frames; /* 0x11C */
    u16 frames_off_any; /* 0x120 */
    u16 air_frames; /* 0x122 */
    u16 x368; /* 0x124 */
    u16 lockon_strafing; /* 0x126 */
    u16 frames_to_land; /* 0x128 */
    u8 past_apex; /* 0x12A */
    u8 critter_mode; /* 0x12B */
    u8 x12C; /* 0x12C */
    u8 hero_camera_mode; /* 0x12D */
    u8 x1477; /* 0x12E */
    u8 x147D; /* 0x12F */
    u8 x1478; /* 0x130 */
    u8 x147E; /* 0x131 */
    u8 in_puddle; /* 0x132 */
    u8 x133; /* 0x133 */
    s32 x134; /* 0x134 */
    s32 x138; /* 0x138 */
    f32 x13C; /* 0x13C */
    f32 x140; /* 0x140 */
    s32 x144; /* 0x144 */
    f32 ledge_wall_yaw; /* 0x148 */
    u8 pad_14C[0x460 - 0x14C];
} CameraHero_4E1F00;

extern G_4DD4B0 D_001A4BE0;
extern CameraHero_4E1F00 D_L01_001E2B90[];
extern s32 D_001D52FC;
extern void func_0038CC88(void *dst, void *src, s32 n);

/* camera_hero_copy: copies the hero into camera `camera`'s CameraHeroData */
void func_L01_004E1F00(s32 camera)
{
    CameraHero_4E1F00 *copy = &D_L01_001E2B90[camera];

    copy->matrix[0] = ((Hero_4E1F00 *)&D_001A4BE0)->matrix[0];
    copy->matrix[1] = ((Hero_4E1F00 *)&D_001A4BE0)->matrix[1];
    copy->matrix[2] = ((Hero_4E1F00 *)&D_001A4BE0)->matrix[2];
    copy->matrix[3] = ((Hero_4E1F00 *)&D_001A4BE0)->matrix[3];
    copy->pos = ((Hero_4E1F00 *)&D_001A4BE0)->pos;
    copy->rot = ((Hero_4E1F00 *)&D_001A4BE0)->rot;
    copy->pickup_point = ((Hero_4E1F00 *)&D_001A4BE0)->pickup_point;
    copy->carried = ((Hero_4E1F00 *)&D_001A4BE0)->carried;
    copy->down = ((Hero_4E1F00 *)&D_001A4BE0)->down;
    copy->x90 = ((Hero_4E1F00 *)&D_001A4BE0)->x4F0;
    copy->xA0 = ((Hero_4E1F00 *)&D_001A4BE0)->xB0;
    copy->look_cam_pos = ((Hero_4E1F00 *)&D_001A4BE0)->look_cam_pos;
    func_0038CC88(copy->look_cam_matrix, ((Hero_4E1F00 *)&D_001A4BE0)->look_cam_matrix, 0x30);
    copy->hero_moby = ((Hero_4E1F00 *)&D_001A4BE0)->hero_moby;
    copy->xF4 = ((Hero_4E1F00 *)&D_001A4BE0)->x19E0;
    copy->ground_moby = ((Hero_4E1F00 *)&D_001A4BE0)->ground_moby;
    copy->camera_request = ((Hero_4E1F00 *)&D_001A4BE0)->camera_request;
    copy->state = ((Hero_4E1F00 *)&D_001A4BE0)->state;
    copy->state_type = ((Hero_4E1F00 *)&D_001A4BE0)->state_type;
    copy->prev_state = ((Hero_4E1F00 *)&D_001A4BE0)->prev_state;
    copy->speed_own_a = ((Hero_4E1F00 *)&D_001A4BE0)->speed_own_a;
    copy->speed_own_b = ((Hero_4E1F00 *)&D_001A4BE0)->speed_own_b;
    copy->height_above_ground = ((Hero_4E1F00 *)&D_001A4BE0)->height_above_ground;
    copy->water_height = ((Hero_4E1F00 *)&D_001A4BE0)->water_height;
    copy->ground_frames = ((Hero_4E1F00 *)&D_001A4BE0)->ground_frames;
    copy->frames_off_any = ((Hero_4E1F00 *)&D_001A4BE0)->frames_off_any;
    copy->air_frames = ((Hero_4E1F00 *)&D_001A4BE0)->air_frames;
    copy->x368 = ((Hero_4E1F00 *)&D_001A4BE0)->x368;
    copy->lockon_strafing = ((Hero_4E1F00 *)&D_001A4BE0)->lockon_strafing;
    copy->frames_to_land = ((Hero_4E1F00 *)&D_001A4BE0)->frames_to_land;
    copy->past_apex = ((Hero_4E1F00 *)&D_001A4BE0)->past_apex;
    copy->critter_mode = ((Hero_4E1F00 *)&D_001A4BE0)->critter_mode;
    copy->x12C = 0;
    copy->hero_camera_mode = ((Hero_4E1F00 *)&D_001A4BE0)->hero_camera_mode;
    copy->x1477 = ((Hero_4E1F00 *)&D_001A4BE0)->x1477;
    copy->x147D = ((Hero_4E1F00 *)&D_001A4BE0)->x147D;
    copy->x1478 = ((Hero_4E1F00 *)&D_001A4BE0)->x1478;
    copy->x147E = ((Hero_4E1F00 *)&D_001A4BE0)->x147E;
    copy->in_puddle = ((Hero_4E1F00 *)&D_001A4BE0)->in_puddle;
    copy->x133 = 0;
    copy->x134 = D_001D52FC;
    if (((Hero_4E1F00 *)&D_001A4BE0)->state_type == 14) {
        copy->x138 = ((Hero_4E1F00 *)&D_001A4BE0)->xA54;
        copy->x13C = ((Hero_4E1F00 *)&D_001A4BE0)->xA6C;
        copy->x140 = ((Hero_4E1F00 *)&D_001A4BE0)->xA60;
    } else if (((Hero_4E1F00 *)&D_001A4BE0)->state_type == 13) {
        copy->x138 = ((Hero_4E1F00 *)&D_001A4BE0)->xA24;
    }
    copy->x144 = ((Hero_4E1F00 *)&D_001A4BE0)->x21A;
    copy->ledge_wall_yaw = ((Hero_4E1F00 *)&D_001A4BE0)->ledge_wall_yaw;
}
/* localdecomp:end func_L01_004E1F00 */

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
