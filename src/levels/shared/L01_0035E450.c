#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;

typedef struct {
    s32 a[12];
} S_0035E418;

extern void func_L01_004C8668(int);
extern void func_003C2880(void *);


/* localdecomp:start func_L01_0035E450 */
/* small for gcc (retail builds its address with one la, which Ps2EeAs expands in place) */
extern S_0035E418 D_L01_001E1A70 __attribute__((section(".sdata")));

/* Takes m out of the 12-slot list at D_L01_001E1A70 (func_L01_0035E418 tests whether it is
 * full): clears the first slot that holds it. */
void func_L01_0035E450(u8 *m)
{
    s32 i;

    for (i = 0; i < 12; i++) {
        if (D_L01_001E1A70.a[i] == (s32)m) {
            D_L01_001E1A70.a[i] = 0;
            return;
        }
    }
}
/* localdecomp:end func_L01_0035E450 */

/* localdecomp:start func_L01_0035E488 */
extern void func_003C2880(void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004C8668(s32);
extern void func_L01_0035E450(u8 *);

void func_L01_0035E488(u8 *m) {
    u8 *pv = *(u8 **)(m + 0x68);

    if (*(s32 *)(pv + 0x24) == 0) {
        func_L01_003303B8(m + 16, 0, 0, 0, 0, 30, 0, 0, 0.75f, 0.0f, 0.0f, 2.0f,
                      0, 0, 0, 0, 0, 0, 0x10000, 0, 0xF78E38, 0xF76300, 0xFF7F40, 0xFF2000, 0xFF8F00, 0xFF6430, 0x7FFFA060, 0x28FF0000, 0xFF6430, 0);
    }
    func_L01_004C8668(*(s32 *)(pv + 0x2C));
    func_L01_0035E450(m);
    ((void (*)(u8 *))func_003C2880)(m);
}
/* localdecomp:end func_L01_0035E488 */

/* localdecomp:start func_L01_0035E598 */
extern S_0035E418 D_L01_001E1A70 __attribute__((section(".sdata")));
extern s32 func_L01_0035E418(void);
extern s32 func_00382468(s32);
extern void func_L01_0035E488(u8 *m);

/* Puts m in the 12-slot list at D_L01_001E1A70: in its first free slot, or, when it is full,
 * in a random one, ending what was there (func_L01_0035E488). */
void func_L01_0035E598(u8 *m)
{
    s32 i;
    s32 *slot;

    if (func_L01_0035E418() == 0) {
        for (i = 0; i < 12; i++) {
            if (D_L01_001E1A70.a[i] == 0) {
                D_L01_001E1A70.a[i] = (s32)m;
                return;
            }
        }
        return;
    }
    slot = &D_L01_001E1A70.a[func_00382468(12)];
    func_L01_0035E488((u8 *)*slot);
    *slot = (s32)m;
}
/* localdecomp:end func_L01_0035E598 */

LINKER_REMNANT("asm/levels", func_L01_0035E630);

/* localdecomp:start func_L01_0035E638 */
typedef struct {
    s128 velocity; /* u a frame */
    f32 phase;     /* a random start */
    s32 ticks;
    s32 x18;
    s32 owner;     /* who fired it */
    s32 x20;
    f32 damage;    /* a flat damage */
    s32 flags;     /* its damage flags */
} BulletVars_0035E638;

/* moby_spawn; an alias, because a later block of this file declares it with its own moby type */
extern u8 *func_003C24B0_0035E638(s32, s32);
extern f32 func_00382538(void);
extern void func_L01_004AA7E8(u8 *a0, s32 a1);

/* enemy_bullet_spawn: a small bullet (class 0x1855), the agents' and the Nitro Eruptor's,
   at pos flying at velocity, owned by owner, doing a flat damage with these flags. */
u8 *func_L01_0035E638(s32 owner, s128 *pos, s128 *velocity, f32 damage, s32 flags)
{
    u8 *bullet = func_003C24B0_0035E638(0x1855, 0x80);
    BulletVars_0035E638 *vars;

    if (bullet != 0) {
        s32 opaque = 0xFF;

        bullet[0x20] = 0;
        *(u16 *)(bullet + 0x32) = opaque;
        bullet[0x30] = opaque;
        vars = *(BulletVars_0035E638 **)(bullet + 0x68);
        *(s128 *)(bullet + 0x10) = *pos;
        vars->velocity = *velocity;
        vars->flags = flags;
        vars->owner = owner;
        vars->phase = func_00382538();
        vars->damage = damage;
        vars->ticks = 0;
        vars->x18 = 0;
        *(void **)(bullet + 0x98) = 0;
        *(u16 *)(bullet + 0x34) = (*(u16 *)(bullet + 0x34) | 0x41) & ~0x1000;
        func_L01_004AA7E8(bullet, 1);
    }
    return bullet;
}
/* localdecomp:end func_L01_0035E638 */

INCLUDE_ASM("asm/levels", func_L01_0035E710);

LINKER_REMNANT("asm/levels", func_L01_0035EB18);

INCLUDE_ASM("asm/levels", func_L01_0035EB20);

INCLUDE_ASM("asm/levels", func_L01_0035ED40);

/* localdecomp:start func_L01_0035EF20 */
typedef struct {
    f32 step[4];  /* 0x00: its move a frame */
    f32 spin;     /* 0x10: the glows' roll */
    u8 pad_14[4];
    f32 flown;    /* 0x18: how far it has gone */
} BulletVars_35EF20;

__asm__(".extern D_L01_001DD6EC, 4");
extern s32 D_L01_001DD6EC;
__asm__(".extern D_L01_001DD6F0, 4");
extern u32 D_L01_001DD6F0;
__asm__(".extern D_L01_001DD6F4, 4");
extern f32 D_L01_001DD6F4;
__asm__(".extern D_L01_001DD6F8, 4");
extern f32 D_L01_001DD6F8;
__asm__(".extern D_L01_001DD6FC, 4");
extern f32 D_L01_001DD6FC;
__asm__(".extern D_L01_001DD700, 4");
extern f32 D_L01_001DD700;
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038CEA8(void *);
extern void func_L01_0035ED40(u8 *);

/* agent_bullet_draw: the agents' small bullet (class 0x1855): two glows (texture 57) turning
 * opposite ways, one of 47 at a random roll, all added; its tracer once it has flown far enough. */
void func_L01_0035EF20(u8 *moby)
{
    BulletVars_35EF20 *vars = *(BulletVars_35EF20 **)(moby + 0x68);
    u8 *position = moby + 0x10;
    f32 height = 0.08f;

    /* D_L01_001DD6F4: degrees a frame */
    vars->spin = func_0038DAB8(vars->spin, D_L01_001DD6F4 * 0.017453292f);
    func_003D9508(position, D_L01_001DD6EC, D_L01_001DD6F0, 1, D_L01_001DD6FC, height,
                  func_0038DAB8(-vars->spin * 1.5f, 0.0f));
    func_003D9508(position, D_L01_001DD6EC, D_L01_001DD6F0, 1, D_L01_001DD6FC, height,
                  vars->spin * 0.5f);
    func_003D9508(position, 0x2F, 0x507F7F7F, 1, D_L01_001DD6F8, height, func_00382538());
    vars->flown += func_0038CEA8(vars);
    if (D_L01_001DD700 < vars->flown) {
        func_L01_0035ED40(moby);
    }
}
/* localdecomp:end func_L01_0035EF20 */

INCLUDE_ASM("asm/levels", func_L01_0035F048);

INCLUDE_ASM("asm/levels", func_L01_0035F340);

INCLUDE_ASM("asm/levels", func_L01_0035F480);

/* localdecomp:start func_L01_0035FEB8 */
void func_L01_0035FEB8(u8 *a) {
    a[32] = 3;
}
/* localdecomp:end func_L01_0035FEB8 */

INCLUDE_ASM("asm/levels", func_L01_0035FEC8);

INCLUDE_ASM("asm/levels", func_L01_00360170);

INCLUDE_ASM("asm/levels", func_L01_00360398);

/* localdecomp:start func_L01_003609D0 */
extern void func_L01_00361D60_003609D0(void *);
extern void func_L01_003609D0(void *);

extern void func_L01_00361AC0_003609D0();
void func_L01_003609D0(void *p) {
    func_L01_00361AC0_003609D0(p);
    func_L01_00361D60_003609D0(p);
}
/* localdecomp:end func_L01_003609D0 */

/* localdecomp:start func_L01_00360A00 */
extern void func_003A9440(s32, s32);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern s16 D_001CFEC0[];

void func_L01_00360A00(void) {
    func_003A9440(66, 72);
    func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], (s32)0x80808080);
}
/* localdecomp:end func_L01_00360A00 */

INCLUDE_ASM("asm/levels", func_L01_00360A48);

INCLUDE_ASM("asm/levels", func_L01_003612E0);

/* localdecomp:start func_L01_00361568 */


extern void func_0038D328(s128 *, S_38C110v *);
extern void func_0038D640(s128 *, void *, s128 *);
extern void func_0038CE20(s128 *, s128 *, f32);
extern void func_L01_003612E0(s128 *, f32, f32, f32, s32, f32, s32, s32);

void func_L01_00361568(S_38C110v *a0, void *a1, s32 a2, s32 a3, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16, f32 f17) {
    S_38C110v v;
    s128 m1[4];
    s128 m2[4];

    v.x = 0.0f;
    v.y = 0.0f;
    v.z = f12;
    v.w = 1.0f;
    func_0038D328(m1, &v);
    func_0038D640(m2, a1, m1);
    func_0038CE20(&m2[0], &m2[0], f13);
    func_0038CE20(&m2[1], &m2[1], f13);
    func_0038CE20(&m2[2], &m2[2], f13);
    *(S_38C110v *)&m2[3] = *a0;
    func_L01_003612E0(m2, f17, f14, f15, a2, f16, a3, 1);
}
/* localdecomp:end func_L01_00361568 */

INCLUDE_ASM("asm/levels", func_L01_00361690);

INCLUDE_ASM("asm/levels", func_L01_00361AC0);

INCLUDE_ASM("asm/levels", func_L01_00361D60);

INCLUDE_ASM("asm/levels", func_L01_00361FA8);

/* localdecomp:start func_L01_00362600 */
void func_L01_00362600(u8 *a) {
    a[32] = 3;
}
/* localdecomp:end func_L01_00362600 */

/* localdecomp:start func_L01_00362610 */
typedef struct {
    s128 velocity;        /* 0x00 */
    u8 pad_10[0x40 - 0x10];
    s32 ticks;            /* 0x40 */
    u8 pad_44[4];
    s32 timer;            /* 0x48 */
    u8 pad_4C[4];
    s32 eruptor;          /* 0x50: the Nitro Eruptor's charge (1) */
    void *target;         /* 0x54 */
    s32 flag_58;          /* 0x58 */
} NitroVars_362610;

typedef struct {
    u8 pad_0[0x10];
    s128 position;        /* 0x10 */
    u8 state;             /* 0x20 */
    u8 pad_21[0x24 - 0x21];
    u8 *pclass;           /* 0x24 */
    u8 pad_28[0x2C - 0x28];
    f32 scale;            /* 0x2C */
    u8 update_dist;       /* 0x30: names for 0x30-0x32 from Horizon Private Server's libuya */
    u8 drawn;             /* 0x31 */
    s16 draw_dist;        /* 0x32 */
    u8 pad_34[0x68 - 0x34];
    NitroVars_362610 *vars; /* 0x68 */
    u8 pad_6C[0xF0 - 0x6C];
    f32 rotation[4];      /* 0xF0 */
} NitroMoby_362610;

extern NitroMoby_362610 *func_003C24B0(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_003C7C38(u8 *);
extern NitroMoby_362610 *D_L01_001E10F8;

/* nitro_charge_spawn: spawns a Nitro charge (class 0x185A) at position with its velocity,
 * turned at random, with its timer. */
NitroMoby_362610 *func_L01_00362610(s128 *position, s128 *velocity, void *target,
                                    s32 eruptor, s32 flag_58)
{
    NitroMoby_362610 *moby;
    NitroVars_362610 *vars;

    moby = func_003C24B0(0x185A, 0x80);
    if (moby != 0) {
        moby->update_dist = 0xFF;
        moby->draw_dist = 0x1FF;
        moby->drawn = 1;
        moby->state = 0;
        vars = moby->vars;
        moby->position = *position;
        vars->velocity = *velocity;
        vars->ticks = 0;
        moby->rotation[0] = func_003824E0(-3.1415927f, 3.1415927f);
        moby->rotation[1] = func_003824E0(-3.1415927f, 3.1415927f);
        moby->rotation[2] = func_003824E0(-3.1415927f, 3.1415927f);
        moby->rotation[3] = 0.0f;
        moby->scale = *(f32 *)(moby->pclass + 0x24) * 1.25f;
        vars->flag_58 = flag_58;
        func_003C7C38((u8 *)moby);
        D_L01_001E10F8 = moby;
        vars->timer = 42; /* NTSC-U's 50 frames at 60 Hz */
        vars->eruptor = eruptor;
        vars->target = target;
    }
    return moby;
}
/* localdecomp:end func_L01_00362610 */

INCLUDE_ASM("asm/levels", func_L01_00362758);

/* localdecomp:start func_L01_00363138 */
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F160[];
s32 func_L01_00363138(void) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        if (D_L01_0028F160[i] != 0) n++;
    }
    return n;
}
/* localdecomp:end func_L01_00363138 */

/* localdecomp:start func_L01_00363170 */
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F0C0[];
extern s32 D_L01_0028F160[];
s32 func_L01_00363170(s32 *out) {
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        s32 v = D_L01_0028F160[i];
        if (v != 0) {
            D_L01_0028F160[i] = 0;
            *out = D_L01_0028F0C0[i];
            D_L01_0028F0C0[i] = 0;
            return v;
        }
    }
    return -1;
}
/* localdecomp:end func_L01_00363170 */

/* localdecomp:start func_L01_003631C8 */
typedef struct {
    u8 pad_0[0x18];
    u8 b18;            /* 0x18 */
    u8 b19;            /* 0x19 */
    s16 source_class;  /* 0x1A: the class of what hit */
    u8 pad_1C[0x30 - 0x1C];
} DamageInfo_3631C8;

typedef struct {
    u8 pad_0[0x4];
    s16 health;        /* 0x04 */
    u8 pad_6[0xF - 0x6];
    u8 takes_hits;     /* 0x0F */
} DamageRecord_3631C8;

typedef struct Moby_3631C8 {
    u8 pad_0[0x24];
    u8 *pclass;        /* 0x24 */
    u8 pad_28[0x68 - 0x28];
    u8 *vars;          /* 0x68 */
    u8 pad_6C[0x98 - 0x6C];
    void *coll_record; /* 0x98 */
    u8 pad_9C[0xAA - 0x9C];
    s16 class_id;      /* 0xAA */
} Moby_3631C8;

typedef struct {
    u8 pad_0[0x18];
    Moby_3631C8 *moby; /* 0x18: the moby the last test met */
} CollHit_3631C8;

typedef struct {
    u8 pos[0x20];      /* every other point of the vortex */
} SuckPoint_3631C8;

extern u8 D_001A4BE0[];
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F0C0[];
extern s32 D_L01_0028F160[];
extern SuckPoint_3631C8 D_L01_0028E3C0[];
extern CollHit_3631C8 D_L01_001EAA00;
extern u8 D_L01_001D66B0[8];
extern s32 func_L01_003FB640(void *position, s32 mask, u8 *skip, f32 radius);
extern s32 func_003C4B50(Moby_3631C8 *moby);
extern DamageRecord_3631C8 *func_00382348(Moby_3631C8 *moby);
extern void func_L01_00446760(DamageInfo_3631C8 *info, u8 *attacker, s32 flags, void *push, f32 damage);
extern void func_L01_00446978(Moby_3631C8 *moby, DamageInfo_3631C8 *info);
extern s32 func_L01_00363E10(s32 value);

/* suck_crate_grab: as the Suck Cannon sucks, balls of 1.2, 1.4, 1.7 and 1.9 u at every other
 * point of its vortex look for a crate or a damageable moby to take in, into a free slot of
 * the held list (D_L01_0028F160: classes, D_L01_0028F0C0: mobys). */
void func_L01_003631C8(u8 *moby)
{
    DamageInfo_3631C8 info;
    Moby_3631C8 *hit;
    DamageRecord_3631C8 *record;
    u8 *hero = D_001A4BE0;
    s32 class_id;
    s32 i;

    /* not in states 0x35 and 0x36 */
    if ((u32)(*(s32 *)(hero + 0x25C4) - 0x35) < 2) {
        return;
    }
    for (i = 0; i < D_L01_001DD790; i++) {
        u8 *player = D_001A4BE0; /* the hero again: a second pointer, as retail */

        if (D_L01_0028F160[i] != 0) {
            continue;
        }
        /* the hero's moby out of the tests; its class's record is put back after */
        (*(Moby_3631C8 **)(player + 0x25C0))->coll_record = 0;
        if (func_L01_003FB640(&D_L01_0028E3C0[0], 1, moby, 1.2f) ||
            func_L01_003FB640(&D_L01_0028E3C0[1], 1, moby, 1.4f) ||
            func_L01_003FB640(&D_L01_0028E3C0[2], 1, moby, 1.7f) ||
            func_L01_003FB640(&D_L01_0028E3C0[3], 1, moby, 1.9f)) {
            /* what the ball met: an enemy (class category 5) or a crate (func_003C4B50) */
            if (D_L01_001EAA00.moby != 0 && D_L01_001EAA00.moby->class_id != 0 &&
                ((D_L01_001EAA00.moby->pclass != 0 && D_L01_001EAA00.moby->pclass[0x46] == 5) ||
                 func_003C4B50(D_L01_001EAA00.moby))) {
                class_id = D_L01_001EAA00.moby->class_id;
                /* never classes 0x1F8 and 0x1F7 */
                if (class_id != 0x1F8) {
                    if (class_id != 0x1F7) {
                        record = func_00382348(D_L01_001EAA00.moby);
                        /* a 1-damage hit with flag 0x8000000 */
                        func_L01_00446760(&info, moby, 0x8000000, D_L01_001D66B0, 1.0f);
                        info.b19 = 1;
                        info.source_class = *(s16 *)(moby + 0xAA);
                        info.b18 = 0;
                        if (func_003C4B50(D_L01_001EAA00.moby)) {
                            hit = D_L01_001EAA00.moby;
                            if (!func_L01_00363E10((s32)hit)) { /* not held yet */
                                *(s32 *)(hit->vars + 0xDC) |= 0x14;
                                D_L01_0028F0C0[i] = (s32)hit;
                                D_L01_0028F160[i] = hit->class_id;
                            }
                        } else if (record != 0 && record->takes_hits != 0) {
                            if (record->health >= 2) { /* only if it outlives it */
                                func_L01_00446978(D_L01_001EAA00.moby, &info);
                            }
                            if (!func_L01_00363E10((s32)D_L01_001EAA00.moby)) {
                                D_L01_0028F0C0[i] = (s32)D_L01_001EAA00.moby;
                                D_L01_0028F160[i] = D_L01_001EAA00.moby->class_id;
                            }
                        }
                    }
                }
            }
        }
        (*(Moby_3631C8 **)(player + 0x25C0))->coll_record =
            *(void **)((*(Moby_3631C8 **)(player + 0x25C0))->pclass + 0x10);
    }
}
/* localdecomp:end func_L01_003631C8 */

/* localdecomp:start func_L01_00363468 */
extern u8 D_L01_001D66B0[8];
extern u8 *func_L01_0046B458(u8 *position, s32 life, s32 colour, s32 roll_kind, s32 spin, void *velocity,
                             s32 delay, f32 size, f32 start_size, f32 unk);
extern u8 *func_L01_00470C78(u8 *position, s32 life, s32 colour, s32 a3, s32 spin, void *velocity, s32 t2,
                             s32 t3, s16 arg8, s32 arg9, f32 size, f32 start_size);

/* suck_take_in_sparkles: the Suck Cannon taking something in: at the muzzle four orange 0x35
 * sparkles (the Flux's muzzle sparkles) and three 0x5C bursts; D_L01_001D66B0 is a zero vector. */
void func_L01_00363468(u8 *moby)
{
    u8 *muzzle = *(u8 **)(moby + 0x68) + 0x10;

    func_L01_0046B458(muzzle, 14, 0xBF204080, 2, 4, D_L01_001D66B0, 1, 5.25f, 0.1f, 0.0f);
    func_L01_0046B458(muzzle, 14, 0xBF2040A0, 2, -4, D_L01_001D66B0, 1, 3.75f, 0.1f, 0.0f);
    func_L01_0046B458(muzzle, 14, 0xC0FFFFFF, 2, 4, D_L01_001D66B0, 1, 2.625f, 0.1f, 0.0f);
    func_L01_0046B458(muzzle, 14, 0xB0FFFFFF, 2, -4, D_L01_001D66B0, 1, 1.875f, 0.1f, 0.0f);
    func_L01_00470C78(muzzle, 17, 0x46787878, 2, 4, D_L01_001D66B0, 0, 2, 6, 1, 1.08f, 0.84000003f);
    func_L01_00470C78(muzzle, 17, 0x46787878, 2, -2, D_L01_001D66B0, 1, 2, 6, 1, 2.0400002f, 0.84000003f);
    func_L01_00470C78(muzzle, 17, 0x2D787878, 2, 2, D_L01_001D66B0, 1, 2, 6, 1, 2.4f, 1.8000001f);
}
/* localdecomp:end func_L01_00363468 */

INCLUDE_ASM("asm/levels", func_L01_00363690);

INCLUDE_ASM("asm/levels", func_L01_00363BF0);

/* localdecomp:start func_L01_00363D90 */
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F160[];

s32 func_L01_00363D90(void) {
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        if (D_L01_0028F160[i] != 0) return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_00363D90 */

/* localdecomp:start func_L01_00363DD0 */
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F0C0[];

s32 func_L01_00363DD0(void) {
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        if (D_L01_0028F0C0[i] != 0) return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00363DD0 */

/* localdecomp:start func_L01_00363E10 */
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F0C0[];

s32 func_L01_00363E10(s32 value) {
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        if (D_L01_0028F0C0[i] == value) return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00363E10 */

LINKER_REMNANT("asm/levels", func_L01_00363E50);
