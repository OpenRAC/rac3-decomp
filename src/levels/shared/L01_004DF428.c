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

INCLUDE_ASM("asm/levels", func_L01_004E0920);

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
typedef int Q_004E1F00 __attribute__((mode(TI)));
typedef struct {
    Q_004E1F00 f0;
    Q_004E1F00 f10;
    Q_004E1F00 f20;
    Q_004E1F00 f30;
    u8 pad40[0x40];
    Q_004E1F00 f80;
    Q_004E1F00 f90;
    u8 padA0[0x10];
    Q_004E1F00 fB0;
    u8 padC0[0x20];
    Q_004E1F00 fE0;
    u8 padF0[0x60];
    Q_004E1F00 f150;
    u8 pad160[0x10];
    f32 f170;
    f32 f174;
    u8 pad178[0xA2];
    s16 f21A;
    u8 pad21C[0xC4];
    Q_004E1F00 f2E0;
    u8 pad2F0[0x4C];
    f32 f33C;
    u8 pad340[0x10];
    f32 f350;
    u8 pad354[0x8];
    s32 f35C;
    s32 f360;
    u8 pad364[0x4];
    u16 f368;
    u8 pad36A[0x2];
    u16 f36C;
    u16 f36E;
    u8 pad370[0xFE];
    u8 f46E;
    u8 pad46F[0xF];
    u16 f47E;
    u8 pad480[0x70];
    Q_004E1F00 f4F0;
    u8 pad500[0x24];
    f32 f524;
    u8 pad528[0x4FC];
    s32 fA24;
    u8 padA28[0x2C];
    s32 fA54;
    u8 padA58[0x8];
    f32 fA60;
    u8 padA64[0x8];
    f32 fA6C;
    u8 padA70[0x9C4];
    u16 f1434;
    u8 pad1436[0x40];
    u8 f1476;
    u8 f1477;
    u8 f1478;
    u8 pad1479[0x4];
    u8 f147D;
    u8 f147E;
    u8 pad147F[0xF1];
    Q_004E1F00 f1570;
    u8 pad1580[0x130];
    u8 f16B0;
    u8 pad16B1[0x32F];
    s32 f19E0;
    u8 pad19E4[0xBDC];
    s32 f25C0;
    s32 f25C4;
    u8 pad25C8[0x4];
    s32 f25CC;
    s32 f25D0;
    u8 pad25D4[0x10];
    u8 f25E4;
    u8 pad25E5[0x227];
    s32 f280C;
} Hero_004E1F00;
typedef struct {
    Q_004E1F00 f0;
    Q_004E1F00 f10;
    Q_004E1F00 f20;
    Q_004E1F00 f30;
    Q_004E1F00 f40;
    Q_004E1F00 f50;
    Q_004E1F00 f60;
    Q_004E1F00 f70;
    Q_004E1F00 f80;
    Q_004E1F00 f90;
    Q_004E1F00 fA0;
    u8 padB0[0x30];
    Q_004E1F00 fE0;
    s32 fF0;
    s32 fF4;
    s32 fF8;
    s32 fFC;
    s32 f100;
    s32 f104;
    s32 f108;
    f32 f10C;
    f32 f110;
    f32 f114;
    f32 f118;
    s32 f11C;
    u16 f120;
    u16 f122;
    u16 f124;
    u16 f126;
    u16 f128;
    u8 f12A;
    u8 f12B;
    u8 f12C;
    u8 f12D;
    u8 f12E;
    u8 f12F;
    u8 f130;
    u8 f131;
    u8 f132;
    u8 f133;
    s32 f134;
    s32 f138;
    f32 f13C;
    f32 f140;
    s32 f144;
    f32 f148;
    u8 pad14C[0x314];
} Save_004E1F00;
extern G_4DD4B0 D_001A4BE0;
extern Save_004E1F00 D_L01_001E2B90[];
extern s32 D_001D52FC;
void func_L01_004E1F00(s32 slot) {
    extern void func_0038CC88(void *, void *, s32);
    Save_004E1F00 *d = &D_L01_001E2B90[slot];
    s32 moby;
    Hero_004E1F00 *h = (Hero_004E1F00 *)&D_001A4BE0;
    d->f0 = h->f0;
    d->f10 = h->f10;
    d->f20 = h->f20;
    d->f30 = h->f30;
    d->f40 = h->f80;
    d->f50 = h->f90;
    d->f60 = h->fE0;
    d->f70 = h->f150;
    d->f80 = h->f2E0;
    d->f90 = h->f4F0;
    d->fA0 = h->fB0;
    d->fE0 = h->f1570;
    func_0038CC88((u8 *)d + 0xB0, (u8 *)h + 0x1540, 0x30);
    moby = D_001A4BE0.f25C0;
    d->fF0 = moby;
    d->fF4 = h->f19E0;
    d->fF8 = h->f35C;
    d->fFC = h->f280C;
    d->f100 = h->f25C4;
    d->f104 = h->f25CC;
    d->f108 = h->f25D0;
    d->f11C = h->f360;
    d->f120 = h->f36C;
    d->f122 = h->f36E;
    d->f124 = h->f368;
    d->f10C = h->f170;
    d->f110 = h->f174;
    d->f114 = h->f33C;
    d->f118 = h->f350;
    d->f126 = h->f1434;
    d->f128 = h->f47E;
    d->f12A = h->f46E;
    d->f12B = h->f25E4;
    d->f12D = h->f16B0;
    d->f12E = h->f1477;
    d->f12F = h->f147D;
    d->f130 = h->f1478;
    d->f131 = h->f147E;
    d->f132 = h->f1476;
    d->f12C = 0;
    d->f133 = 0;
    d->f134 = D_001D52FC;
    if (h->f25CC == 14) {
        d->f138 = h->fA54;
        d->f13C = h->fA6C;
        d->f140 = h->fA60;
    } else if (h->f25CC == 13) {
        d->f138 = h->fA24;
    }
    d->f144 = ((Hero_004E1F00 *)&D_001A4BE0)->f21A;
    d->f148 = ((Hero_004E1F00 *)&D_001A4BE0)->f524;
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

INCLUDE_ASM("asm/levels", func_L01_004E27A8);

/* localdecomp:start func_L01_004E2988 */
#include "vu0.h"
typedef struct { u8 pad[0x20E]; s16 mode; u8 pad210[0x1A28-0x210]; f32 phase; } Hero_004E2988;
extern G_4DD4B0 D_001A4BE0;
extern Lid_4E0618 D_L01_001E1420[] __attribute__((section(".sdata")));
extern Lid_4E0618 D_L01_001E1460[] __attribute__((section(".sdata")));
extern u8 D_001D5470;
extern f32 D_L01_001DBD3C __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DBD3C, 4");
extern s32 D_L01_001DBFA8;
__asm__(".extern D_L01_001DBFA8, 4");
extern s32 D_L01_001DBFAC;
__asm__(".extern D_L01_001DBFAC, 4");
extern s32 D_L01_001DBFB0;
__asm__(".extern D_L01_001DBFB0, 4");
extern s32 D_L01_001DBFB4;
__asm__(".extern D_L01_001DBFB4, 4");
extern s32 D_L01_001DBFB8;
__asm__(".extern D_L01_001DBFB8, 4");
extern s32 D_L01_001DBFBC;
__asm__(".extern D_L01_001DBFBC, 4");
extern s32 D_L01_001DBFC0;
__asm__(".extern D_L01_001DBFC0, 4");
extern s32 D_L01_001DBFC4;
__asm__(".extern D_L01_001DBFC4, 4");
void func_L01_004E2988(u8 *obj) {
    extern void func_L01_004E27A8(u8 *,s32,s32,s32,s32,s32,s32,s32,s32);
    extern void func_003C2F58(u8 *,s32,u128_t *);
    extern f32 func_0038DAB8(f32,f32);
    extern f32 func_0038D0B0(f32);
    extern void func_L01_004E35D0(u128_t *,s32,f32,f32);
    extern void func_L01_0043A430(Moby_4E0618 *,s32,Lid_4E0618 *);
    union { u128_t q; f32 f[4]; } point;
    Lid_4E0618 *lid;
    s32 cls;
    *(u16 *)(obj+0x34) |= 0x10;
    if ((*(Hero_004E2988 *)&D_001A4BE0).mode) {
        func_L01_004E27A8(obj,D_L01_001DBFAC,D_L01_001DBFB0,D_L01_001DBFB4,D_L01_001DBFB8,D_L01_001DBFBC,D_L01_001DBFC0,D_L01_001DBFC4,D_L01_001DBFA8);
    } else {
        func_L01_004E27A8(obj,0x38,0x88,0x40,0x80,0x18,0x3C,0x18,0x64);
    }
    if (*(s16 *)(obj+0xAA)==0x1159 || *(s16 *)(obj+0xAA)==0x19C9) {
        func_003C2F58(obj,6,&point.q);
        if (fabs_asm(*(f32 *)(obj+0x18)-point.f[2])>2.0f) {
            func_L01_004E35D0(&point.q,0x200000C0,0.25f,0.15f);
        }
    } else if (*(s16 *)(obj+0xAA)==0x57) {
        func_003C2F58(obj,7,&point.q);
        (*(Hero_004E2988 *)&D_001A4BE0).phase=func_0038DAB8((*(Hero_004E2988 *)&D_001A4BE0).phase,0.0802851543f);
        func_L01_004E35D0(&point.q,(((s32)((func_0038D0B0((*(Hero_004E2988 *)&D_001A4BE0).phase)*0.5f+0.5f)*13.0f)+0x17)<<24)|0xC0,0.04f,0.07f);
    } else if (*(s16 *)(obj+0xAA)==10 || *(s16 *)(obj+0xAA)==0x1F6B) {
        func_003C2F58(obj,1,&point.q);
        (*(Hero_004E2988 *)&D_001A4BE0).phase=func_0038DAB8((*(Hero_004E2988 *)&D_001A4BE0).phase,0.0802851543f);
        func_L01_004E35D0(&point.q,(((s32)((func_0038D0B0((*(Hero_004E2988 *)&D_001A4BE0).phase)*0.5f+0.5f)*13.0f)+0x17)<<24)|0xC0,0.04f,0.07f);
    }
    cls=*(s16 *)(obj+0xAA);
    lid=D_L01_001E1420;
    if (cls==0x27D) lid=D_L01_001E1460;
    if (D_001D5470 && !lid->active) {
        if (cls==0x27D) {
            func_L01_0043A430((Moby_4E0618 *)obj,1,lid);
        } else {
            func_L01_0043A430((Moby_4E0618 *)obj,cls==0x57 ? 5:2,lid);
        }
        { f32 angle = D_L01_001DBD3C;
        ((f32 *)&lid->b)[0]=angle;
        ((f32 *)&lid->b)[1]=angle;
        ((f32 *)&lid->b)[2]=angle; }
    }
}
/* localdecomp:end func_L01_004E2988 */

/* localdecomp:start func_L01_004E2C48 */
typedef struct {
    u8 pad0[0x1B8]; s32 timer;
    u8 pad1BC[0x1200 - 0x1BC]; u8 *attachment;
    u8 pad1204[0x1228 - 0x1204]; s32 weapon;
    u8 pad122C[0x25C0 - 0x122C]; u8 *moby; s32 state;
    u8 pad25C8[0x2818 - 0x25C8]; unsigned long saved_color; s32 flashing;
} Hero_004E2C48;
typedef struct {
    u8 b0; u8 active;
    u8 pad2[0xF0 - 2];
} Gun_004E2C48;
extern G_4DD4B0 D_001A4BE0;

void func_L01_004E2C48(void) {
    extern void func_003C6FB0(u8 *, s32 *, s32 *, s32 *);
    extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
    extern void func_L01_004E2720(void);
    extern void func_L01_004E27A0_004E2C48(u8 *, u8 *);
    s32 r, g, b;
    s32 flash = 0;

    if ((*(Hero_004E2C48 *)&D_001A4BE0).state == 0x82 ||
        (*(Hero_004E2C48 *)&D_001A4BE0).state == 0xB1 ||
        (*(Hero_004E2C48 *)&D_001A4BE0).state == 0x84) {
        flash = (*(Hero_004E2C48 *)&D_001A4BE0).timer < 25;
    }
    if (flash) {
        if (!(*(Hero_004E2C48 *)&D_001A4BE0).flashing) {
            (*(Hero_004E2C48 *)&D_001A4BE0).saved_color =
                *(unsigned long *)((*(Hero_004E2C48 *)&D_001A4BE0).moby + 0x38);
            (*(Hero_004E2C48 *)&D_001A4BE0).flashing = 1;
        }
        func_003C6FB0((*(Hero_004E2C48 *)&D_001A4BE0).moby, &r, &g, &b);
        if ((*(Hero_004E2C48 *)&D_001A4BE0).timer % 4 < 3) {
            r = 0;
            g = 0;
            b = 0;
        } else {
            r = 0x90;
            g = 0x90;
            b = 0xF0;
        }
        func_L01_0043B9E8((*(Hero_004E2C48 *)&D_001A4BE0).moby, r, g, b);
        func_L01_004E2720();
    } else if ((*(Hero_004E2C48 *)&D_001A4BE0).flashing) {
        *(unsigned long *)((*(Hero_004E2C48 *)&D_001A4BE0).moby + 0x38) =
            (*(Hero_004E2C48 *)&D_001A4BE0).saved_color;
        (*(Hero_004E2C48 *)&D_001A4BE0).flashing = 0;
    }
    if ((*(Hero_004E2C48 *)&D_001A4BE0).weapon >= 0 &&
        ((Gun_004E2C48 *)D_L01_002C5600)[D_001425C0[(*(Hero_004E2C48 *)&D_001A4BE0).weapon]].active &&
        (*(Hero_004E2C48 *)&D_001A4BE0).attachment) {
        func_L01_004E27A0_004E2C48((*(Hero_004E2C48 *)&D_001A4BE0).attachment,
                          (*(Hero_004E2C48 *)&D_001A4BE0).moby);
    }
}
/* localdecomp:end func_L01_004E2C48 */

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

/* localdecomp:start func_L01_004E3148 */
extern f32 D_L01_001DF950;
extern f32 D_L01_001DBD10[2];
extern s32 D_L01_001DBD18[2];
extern s32 D_L01_001DBD20[2];
__asm__(".extern D_L01_001DBD10, 8");
__asm__(".extern D_L01_001DBD18, 8");
__asm__(".extern D_L01_001DBD20, 8");
void func_L01_004E3148(void) {
    extern f32 func_003C4138(f32 *,f32,f32);
    s32 i;
    for(i=0;i<1;i++) {
        if(D_L01_001DBD18[i]) {
            if(D_L01_001DBD20[i]==0) {
                func_003C4138((&D_L01_001DF950+i),1.0f,D_L01_001DBD10[i]);
                if((&D_L01_001DF950)[i]==1.0f) D_L01_001DBD20[i]=1;
            } else if(D_L01_001DBD20[i]==1) {
                D_L01_001DBD20[i]=2;
            } else if(D_L01_001DBD20[i]==2) {
                func_003C4138((&D_L01_001DF950+i),0.0f,D_L01_001DBD10[i]);
                if((&D_L01_001DF950)[i]==0.0f) D_L01_001DBD18[i]=0;
            }
        }
    }
}
/* localdecomp:end func_L01_004E3148 */

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
extern f32 func_003C4138(f32 *, f32, f32);

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
            func_003C4138(&(*(H_4E5030 *)&D_001A4BE0).anim_rate, rate, step);
        }
    }
}
/* localdecomp:end func_L01_004E5030 */

INCLUDE_ASM("asm/levels", func_L01_004E5130);

INCLUDE_ASM("asm/levels", func_L01_004E51A0);

/* localdecomp:start func_L01_004E5290 */
#include "vu0.h"
extern u8 D_001A71C4[];
extern void func_L01_004E51A0(void *);

void func_L01_004E5290(void) {
    vu0_v4 v;
    f32 f = 0.6f;
    qzero(&v);
    if (D_001A71C4[0] == 1) {
        f = 0.35f;
    }
    v.z = f;
    func_L01_004E51A0(&v);
}
/* localdecomp:end func_L01_004E5290 */

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

/* localdecomp:start func_L01_004E5748 */
typedef struct {
 u8 pad0[0x80]; f32 x; f32 y;
 u8 pad88[0x350-0x88]; f32 z;
 u8 pad354[0x9C4-0x354]; s16 counter;
} Hero_004E5748;
extern G_4DD4B0 D_001A4BE0;
void func_L01_004E5748(s32 period, s32 threshold) {
 extern f32 func_003824E0(f32, f32);
 extern s32 func_00382468(s32);
 extern void func_L01_0046A938(f32 *, f32 *, s32, f32, f32);
 f32 position[4];
 f32 random;

 Hero_004E5748 *hero = (Hero_004E5748 *)&D_001A4BE0;
 hero->counter++;
 if (threshold < hero->counter) {
  f32 low = -0.05f;
  f32 high = 0.05f;
  position[0] = hero->x + func_003824E0(low, high);
  position[1] = hero->y + func_003824E0(low, high);
  position[2] = hero->z;
  random = func_003824E0(0.4f, 0.6f);
  func_L01_0046A938(position, &hero->z, -1, random, 5250.0f);
  hero->counter = func_00382468(period);
 }
}
/* localdecomp:end func_L01_004E5748 */

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

/* localdecomp:start func_L01_004E5C08 */
typedef struct {
    u8 pad0[0x80]; f32 pos[4];
    u8 pad90[0x110-0x90]; f32 velocity[4];
    u8 pad120[0x170-0x120]; f32 speed;
    u8 pad174[0x25C0-0x174]; u8 *moby; s32 state;
} Hero_004E5C08;
void func_L01_004E5C08(s32 count, s32 kind, s32 special)
{
    extern f32 func_003824E0(f32, f32);
    extern void func_003C2F58(u8 *, s32, u128_t *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_L01_00467688(f32 *, void *, f32);
    extern void func_L01_00468678(f32 *, f32 *, f32, f32, s32);
    f32 pos[4];
    f32 vel[4];
    s32 i = 0;
    Hero_004E5C08 *hero;
    f32 *v;
    for (; i < count; i++) {
        hero = (Hero_004E5C08 *)&D_001A4BE0;
        if (kind == 0) {
            pos[0] = hero->pos[0] + func_003824E0(-0.1f, 0.1f);
            pos[1] = hero->pos[1] + func_003824E0(-0.1f, 0.1f);
            pos[2] = hero->pos[2] + func_003824E0(-0.5f, 0.1f);
        } else if (kind == 1) {
            if ((i & 1) == 0) func_003C2F58(hero->moby, 0, (u128_t *)pos);
            else func_003C2F58(hero->moby, 14, (u128_t *)pos);
        } else if (kind == 2) {
            if ((i & 1) == 0) func_003C2F58(hero->moby, 23, (u128_t *)pos);
            else func_003C2F58(hero->moby, 22, (u128_t *)pos);
        }
        *(u128_t *)vel = *(u128_t *)((u8 *)&D_001A4BE0 + 0x110);
        if (hero->state == 51) func_0038CE20(vel, vel, 1.15f);
        else func_0038CE20(vel, vel, 0.7f);
        v = vel;
        vel[0] += func_003824E0(-0.008f, 0.008f);
        vel[1] += func_003824E0(-0.008f, 0.008f);
        vel[2] += func_003824E0(-0.020000001f, 0.0f);
        if (special) {
            void *matrix = hero->moby + 0xC0;
            f32 r = func_003824E0(0.7f, 1.1f);
            func_L01_00467688(pos, matrix, hero->speed * r);
        } else {
            f32 r = func_003824E0(4200.0f, 7350.0f);
            func_L01_00468678(pos, v, r, -1.0f, 0x88A0A0A0);
        }
    }
}
/* localdecomp:end func_L01_004E5C08 */

/* localdecomp:start func_L01_004E5EB8 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_004E5EB8;
extern G_4DD4B0 D_001A4BE0;
void func_L01_004E5EB8(s32 first, s32 second, s32 flash) {
    extern void func_L01_003016B0(void *, s32, f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_0046A938(f32 *, f32 *, s32, f32, f32);
    extern void func_L01_00468A68(f32 *, f32 *, s32, s32);
    f32 v[4] __attribute__((aligned(16)));
    Vec_004E5EB8 position;
    f32 angle, radius, random;
    s32 kind, life;
    s32 n;
    if(flash) {
        f32 *p=(f32 *)((u8 *)&D_001A4BE0+0x80);
        *(u128_t *)v=*(u128_t *)p;
        v[2]=p[0x2D0/4];
        func_L01_003016B0(v,3,2.25f,1.025f);
    }
    if(first>0) {
        G_004E5840 *h=(G_004E5840 *)&D_001A4BE0;
        do {
            v[0]=h->x+func_003824E0(-0.3f,0.3f);
            v[1]=h->y+func_003824E0(-0.3f,0.3f);
            v[2]=h->z;
            random=func_003824E0(0.3f,0.6f);
            func_L01_0046A938(v,&h->z,-1,random,5250.0f);
            first--;
        } while(first);
    }
    {
        for(n=0;n<second;n++) {
            G_004E5840 *h=(G_004E5840 *)&D_001A4BE0;
            angle=func_00382538();
            radius=func_003824E0(0.0f,0.0600000024f);
            v[0]=func_0038D098(angle)*radius;
            v[1]=func_0038D0B0(angle)*radius;
            v[2]=func_003824E0(0.0600000024f,0.1600000113f);
            position.x=h->x+v[0]*8.0f;
            position.y=h->y+v[0]*8.0f;
            position.z=h->z-func_003824E0(0.0f,0.2f);
            kind=func_00382468(2);
            life=func_00382498(90,120);
            func_L01_00468A68((f32 *)&position,v,kind,life);
        }
    }
}
/* localdecomp:end func_L01_004E5EB8 */

/* localdecomp:start func_L01_004E60E8 */
typedef struct {
    u8 p0[0x80]; s128 position; f32 rotation[4];
    u8 pA0[0x1B8-0xA0]; s32 timer;
    u8 p1BC[0x4EC-0x1BC]; s16 emit; s16 trail;
} Hero_004E60E8;
extern s16 D_001A50CE[];
void func_L01_004E60E8(void) {
    extern s32 func_0038CB00(void *);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_L01_00466F50(f32 *, f32 *, s32, f32, f32);
    extern void func_00382760(f32 *, f32, f32, f32);
    extern void func_L01_004637C8(f32 *, f32 *, s32, s32, s32, s32, s32, s32);
    f32 position[4] __attribute__((aligned(16)));
    f32 velocity[4] __attribute__((aligned(16)));
    s16 *trail = D_001A50CE;
    f32 angle, radius, factor, alpha, r1, r2;
    s32 color, a, b, i;
    s32 intensity;
    if (func_0038CB00(trail)) {
        Hero_004E60E8 *hero = (Hero_004E60E8 *)((u8 *)trail - 0x4EE);
        *(s128 *)position = *(s128 *)((u8 *)trail - 0x46E);
        angle = func_0038DAB8(hero->rotation[2], 1.5707964f);
        radius = func_L01_00443A18(0.004f, 0.014f);
        velocity[0] = func_0038D098(angle) * radius;
        velocity[1] = func_0038D0B0(angle) * radius;
        velocity[2] = 0.0f;
        velocity[3] = -0.003200000152f;
        func_L01_00466F50(position, velocity, 0, -1.0f, velocity[2]);
        hero->trail = func_00382498(2, 3);
    }
    if (func_0038CB00(trail - 1)) {
        s128 *origin;
        f32 *out;
        factor = (f32)(33 - *(s32 *)((u8 *)trail - 0x336)) / 33.0f;
        if (factor > 1.0f) factor = 1.0f;
        if (factor < 0.0f) factor = 0.0f;
        intensity = (s32)(factor * 240.0f);
        if (intensity > 160) intensity = 160;
        if (intensity < 32) intensity = 32;
        color = (intensity << 24) | 0xC0F0;
        origin = (s128 *)((u8 *)trail - 0x46E);
        out = velocity;
        for (i = 56; i >= 0; i--) {
            a = (s32)(func_003824E0(4200.0f, 7350.0f) / 1000.0f);
            b = (s32)(func_003824E0(21000.0f, 31500.001953125f) / 1000.0f);
            alpha = func_003824E0(0.003000000259f, 0.01140000112f);
            *(s128 *)position = *origin;
            r1 = func_00382538();
            r2 = func_00382538();
            func_00382760(out, alpha, r1, r2);
            func_L01_004637C8(position, out, color, 0x70F0, 33, a, b, 1);
        }
        ((Hero_004E60E8 *)&D_001A4BE0)->emit = func_00382498(2, 6);
    }
}
/* localdecomp:end func_L01_004E60E8 */

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

/* localdecomp:start func_L01_004E67C0 */
void func_L01_004E67C0(void) {
    u8 *h = (u8 *)&D_001A4BE0;
    u8 *p;
    s32 i;

    *(s32 *)(h + 0x1174) = 0;
    *(s32 *)(h + 0x1178) = 0;
    p = h;
    for (i = 3; i >= 0; i--) {
        *(s32 *)(p + 0x1194) = 0;
        *(s32 *)(p + 0x1198) = 0;
        p += 0x10;
    }
}
/* localdecomp:end func_L01_004E67C0 */

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

/* localdecomp:start func_L01_004E6D18 */
/* The pitch's fabs is the game's fabs_asm (include/vu0.h): retail loads the 50 deg limit before
   the abs.s and keeps it out of the delay slot. */
#include "vu0.h"
typedef union {
    s128 q;
    struct {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    } v;
} V_4E6D18;
typedef struct {
    u8 pad0[0x60];
    f32 target_x;
    f32 target_y;
    f32 target_z;
    u8 pad6C[0xB0 - 0x6C];
} Spring_4E6D18;
/* the hero's joint springs (43, from D_L01_002F4540) */
typedef struct {
    Spring_4E6D18 root;
    Spring_4E6D18 waist;
    Spring_4E6D18 chest;
    Spring_4E6D18 neck;
} Springs_4E6D18;
/* a moby's damage record (func_00382348) */
typedef struct {
    u8 pad0[0x10];
    f32 height;
    u8 pad14[0x28 - 0x14];
    u8 range;
    u8 priority;
    u8 height8; /* in eighths of a unit */
} Damage_4E6D18;
typedef struct {
    u8 pad0[0x10];
    V_4E6D18 pos;
    u8 pad20[0x43 - 0x20];
    u8 sequence;
} Moby_4E6D18;
typedef struct {
    u8 pad0[0x80];
    V_4E6D18 pos;
    V_4E6D18 rot;
    u8 padA0[0x1DC - 0xA0];
    s16 timer_1fc;
    u8 pad1DE[0xBD8 - 0x1DE];
    Moby_4E6D18 *gun_target;
    u8 padBDC[0x1430 - 0xBDC];
    Moby_4E6D18 *lockon_target;
    u8 pad1434[0x25C0 - 0x1434];
    Moby_4E6D18 *hero_moby;
    s32 state;
    u8 pad25C8[0x25CC - 0x25C8];
    s32 state_type;
    u8 pad25D0[0x25E9 - 0x25D0];
    u8 firing;
    u8 pad25EA[0x27FC - 0x25EA];
    Moby_4E6D18 *look_at;
} H_4E6D18;
extern s32 D_L01_001DFB40; /* the frame counter */
extern Moby_4E6D18 *D_L01_0021E860[]; /* what he may look at, to a 0 */
extern Damage_4E6D18 *func_00382348(Moby_4E6D18 *moby);
extern f32 func_0038CF38(void *a, void *b);
extern f32 func_0038D160(f32 x, f32 y);
extern f32 func_0038DBA0(f32 a, f32 b);
extern f32 func_0038DB00(f32, f32);
extern void func_L01_005110E8(f32 forward, f32 left, f32 up, V_4E6D18 *out, s32 add_position);
extern void func_L01_00511158(s128 *, s128 *, f32);
extern int func_003D3CB0(char *first, char *second, int mode, int flag, int extra);
extern void func_L01_004E63A8(f32 a, f32 b);
extern void func_L01_004E63C0(f32 a, f32 b);
extern void func_L01_004E63D8(f32 a, f32 b);

/* hero_head_look: in state types 0, 1, 2, 4 and 7, turns the upper chest and waist to the
   gun's target (yaw within 59 deg, pitch from 25 deg up to 35 deg down), or the neck to the
   nearest thing on the look-at list, picked every 7th frame. */
void func_L01_004E6D18(void) {
    s32 gun;
    s32 i;
    Moby_4E6D18 *moby;
    Moby_4E6D18 *best;
    Damage_4E6D18 *record;
    Moby_4E6D18 *aim;
    Damage_4E6D18 *aim_record;
    f32 best_score;
    f32 best_priority;
    f32 distance;
    f32 yaw;
    f32 pitch;
    f32 score;
    f32 turn;
    f32 tilt;
    f32 priority;
    V_4E6D18 target;
    V_4E6D18 eye;

    /* a gun target, unless locked on to something */
    gun = (*(H_4E6D18 *)&D_001A4BE0).gun_target != 0 && (*(H_4E6D18 *)&D_001A4BE0).lockon_target == 0;
    if ((*(H_4E6D18 *)&D_001A4BE0).state_type != 1 && (*(H_4E6D18 *)&D_001A4BE0).state_type != 4 &&
        (*(H_4E6D18 *)&D_001A4BE0).state_type != 2 && (*(H_4E6D18 *)&D_001A4BE0).state_type != 7 &&
        (*(H_4E6D18 *)&D_001A4BE0).state_type != 0) {
        (*(H_4E6D18 *)&D_001A4BE0).gun_target = 0;
        (*(H_4E6D18 *)&D_001A4BE0).look_at = 0;
        return;
    }
    if ((*(H_4E6D18 *)&D_001A4BE0).state == 0x2E) {
        return;
    }
    if ((*(H_4E6D18 *)&D_001A4BE0).firing != 0) {
        (*(H_4E6D18 *)&D_001A4BE0).look_at = 0;
    }
    if (!gun) {
        if ((*(H_4E6D18 *)&D_001A4BE0).hero_moby->sequence == 0x4A) {
            return;
        }
        /* every 7th frame, the best thing to look at */
        if (D_L01_001DFB40 % 7 == 0) {
            best_score = 100000000.0f;
            best_priority = 0.0f;
            best = 0;
            for (i = 0; (moby = D_L01_0021E860[i]) != 0; i++) {
                record = func_00382348(moby);
                if (record == 0) {
                    continue;
                }
                distance = func_0038CF38(&(*(H_4E6D18 *)&D_001A4BE0).pos, &moby->pos);
                if (distance > record->range) {
                    continue;
                }
                /* within 90 deg of where he faces */
                yaw = func_0038DBA0(func_0038D160(moby->pos.v.x - (*(H_4E6D18 *)&D_001A4BE0).pos.v.x,
                                                  moby->pos.v.y - (*(H_4E6D18 *)&D_001A4BE0).pos.v.y),
                                    (*(H_4E6D18 *)&D_001A4BE0).rot.v.z);
                if (yaw > 1.57079637f) {
                    continue;
                }
                /* and 50 deg up or down */
                pitch = func_0038D160(func_0038CF38(&moby->pos, &(*(H_4E6D18 *)&D_001A4BE0).pos),
                                      (*(H_4E6D18 *)&D_001A4BE0).pos.v.z - moby->pos.v.z);
                if (fabs_asm(pitch) > 0.872664630f) {
                    continue;
                }
                score = yaw * distance + distance;
                /* the one he looks at already is 1.5 u nearer */
                if (moby == (*(H_4E6D18 *)&D_001A4BE0).look_at) {
                    score -= 1.5f;
                    if (score < 0.0f) {
                        score = 0.0f;
                    }
                }
                priority = record->priority;
                if (priority > best_priority || score < best_score) {
                    if (best_priority < priority) {
                        best_priority = priority;
                    }
                    best_score = score;
                    best = moby;
                }
            }
            (*(H_4E6D18 *)&D_001A4BE0).look_at = best;
        }
        /* within 50 u, and nothing between */
        if ((*(H_4E6D18 *)&D_001A4BE0).look_at != 0 &&
            func_0038CF38(&(*(H_4E6D18 *)&D_001A4BE0).pos, &(*(H_4E6D18 *)&D_001A4BE0).look_at->pos) < 50.0f) {
            func_L01_005110E8(0.0f, 0.0f, 1.20000005f, &target, 1);
            eye = (*(H_4E6D18 *)&D_001A4BE0).look_at->pos;
            func_L01_00511158(&eye.q, &eye.q, 0.5f);
            if (func_003D3CB0((char *)&target, (char *)&eye, 2, 0, 0) != 0) {
                (*(H_4E6D18 *)&D_001A4BE0).look_at = 0;
            }
        }
    }
    if ((*(H_4E6D18 *)&D_001A4BE0).look_at != 0 || gun) {
        aim = (*(H_4E6D18 *)&D_001A4BE0).look_at;
        if (gun) {
            aim = (*(H_4E6D18 *)&D_001A4BE0).gun_target;
        }
        target = aim->pos;
        /* raised by its damage record's height */
        aim_record = func_00382348(aim);
        if (aim_record != 0) {
            if (gun) {
                target.v.z += aim_record->height;
            } else {
                target.v.z += aim_record->height8 * 0.125f;
            }
        }
        if (gun) {
            func_L01_005110E8(0.5f, 0.0f, 0.550000012f, &eye, 1);
        } else {
            func_L01_005110E8(0.300000012f, 0.0f, 0.850000024f, &eye, 1);
        }
        turn = func_0038DB00(func_0038D160(target.v.x - eye.v.x, target.v.y - eye.v.y), (*(H_4E6D18 *)&D_001A4BE0).rot.v.z);
        tilt = func_0038D160(func_0038CF38(&target, &eye), eye.v.z - target.v.z);
        if (turn > 1.02974427f) {
            turn = 1.02974427f; /* 59 deg */
        } else if (turn < -1.02974427f) {
            turn = -1.02974427f;
        }
        if (tilt > 0.610865235f) {
            tilt = 0.610865235f; /* 35 deg down */
        }
        if (tilt < -0.436332315f) {
            tilt = -0.436332315f; /* 25 deg up */
        }
        if ((*(H_4E6D18 *)&D_001A4BE0).timer_1fc >= 23) {
            if (turn > 0.296705961f) {
                turn = 0.296705961f; /* 17 deg */
            } else if (turn < -0.296705961f) {
                turn = -0.296705961f;
            }
            tilt = 0.0f;
        }
        if (gun) {
            func_L01_004E63C0(0.0532800034f, 0.432000041f);
            (*(Springs_4E6D18 *)D_L01_002F4540).chest.target_z = turn;
            func_L01_004E63A8(0.0532800034f, 0.432000041f);
            (*(Springs_4E6D18 *)D_L01_002F4540).waist.target_y = tilt;
        } else {
            func_L01_004E63D8(0.0302400012f, 0.388800025f);
            (*(Springs_4E6D18 *)D_L01_002F4540).neck.target_y = tilt;
            (*(Springs_4E6D18 *)D_L01_002F4540).neck.target_z = turn * 0.75f;
            func_L01_004E63C0(0.0201600008f, 0.432000041f);
            (*(Springs_4E6D18 *)D_L01_002F4540).chest.target_z = (*(Springs_4E6D18 *)D_L01_002F4540).neck.target_z * 0.25f;
        }
    }
    (*(H_4E6D18 *)&D_001A4BE0).gun_target = 0;
}
/* localdecomp:end func_L01_004E6D18 */
