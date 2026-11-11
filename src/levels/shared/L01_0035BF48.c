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

/* localdecomp:start func_L01_0035BF48 */
typedef struct {
    s128 velocity;  /* 0x00: u a frame */
    f32 roll;       /* 0x10: a random start; n60_bullet_draw turns it */
    s32 bounces;    /* 0x14 */
    s32 gun;        /* 0x18: the attacker */
    f32 damage;     /* 0x1C */
    s32 life;       /* 0x20: frames */
    s32 tracer;     /* 0x24: draws the tracer */
    f32 flown;      /* 0x28: u */
    s32 shadow;     /* 0x2C */
} N60Bullet_0035BF48;

extern u8 *func_003C24B0(s32 class, s32 vars_size);
extern f32 func_00382538(void);
extern f32 func_0038CEA8(void *);
extern void func_L01_004CAC78(void *out, void *from, f32 speed, f32 range, f32 max_angle);
extern s32 func_L01_004C85C8(u8 *moby, s32 a1, f32 x, f32 y, f32 z);
extern void func_L01_004AA7E8(u8 *moby, s32 a1);
extern u8 D_001A4BE0[];

/* n60_bullet_spawn: an N60 Storm bullet (class 0x1851) at pos with velocity, the row's damage
   and the gun as attacker; in the aiming camera modes it bends toward the aim point. */
u8 *func_L01_0035BF48(s32 gun, s128 *pos, s128 *velocity, f32 damage, s32 life, s32 tracer, f32 size)
{
    u8 *bullet = func_003C24B0(0x1851, 0x80);
    N60Bullet_0035BF48 *vars;

    if (bullet != 0) {
        bullet[0x20] = 0;
        *(u16 *)(bullet + 0x32) = 0xFF;
        bullet[0x30] = 0xFF;
        vars = *(N60Bullet_0035BF48 **)(bullet + 0x68);
        *(s128 *)(bullet + 0x10) = *pos;
        vars->velocity = *velocity;
        vars->life = life;
        vars->gun = gun;
        vars->roll = func_00382538();
        vars->damage = damage;
        vars->tracer = tracer;
        vars->bounces = 0;
        vars->flown = 0.0f;
        /* the hero's camera mode: not the follow camera */
        if (*(s32 *)(D_001A4BE0 + 0x16B0) != 0) {
            /* within 35 u, turned at most 80 degrees */
            func_L01_004CAC78(vars, pos, func_0038CEA8(vars), 35.0f, 1.3962634f);
        }
        vars->shadow = func_L01_004C85C8(bullet, 0, size, 1.0f, 1.0f);
        *(s32 *)(bullet + 0x98) = 0;
        *(u16 *)(bullet + 0x34) = (*(u16 *)(bullet + 0x34) | 0x41) & ~0x1000;
        func_L01_004AA7E8(bullet, 1);
    }
    return bullet;
}
/* localdecomp:end func_L01_0035BF48 */

INCLUDE_ASM("asm/levels", func_L01_0035C098);

/* localdecomp:start func_L01_0035C6B0 */
extern void func_L01_004C8668(int);
extern void func_003C2880(void *);
void func_L01_0035C6B0(char *m)
{
    char *v = *(char **)(m + 104);
    if (v != 0) {
        func_L01_004C8668(*(int *)(v + 44));
    }
    func_003C2880(m);
}
/* localdecomp:end func_L01_0035C6B0 */

INCLUDE_ASM("asm/levels", func_L01_0035C6F0);

/* localdecomp:start func_L01_0035C8D0 */
typedef struct {
    s128 velocity;  /* 0x00: u a frame */
    f32 roll;       /* 0x10: grows by 1 degree a frame */
    u8 pad14[0x10];
    s32 tracer;     /* 0x24: draws the tracer */
    f32 flown;      /* 0x28: u */
} N60Draw_0035C8D0;

extern f32 func_0038DAB8(f32 a, f32 b);
extern void func_003D9508(u8 *pos, s32 texture, u32 colour, s32 blend, f32 half, f32 push, f32 roll);
extern f32 func_00382538(void);
extern f32 func_0038CEA8(void *);
extern void func_L01_0035C6F0(u8 *bullet);

/* n60_bullet_draw: an N60 Storm bullet in flight, additive: three stars (57) rolling at -1.5,
   0.5 and 2.5 times its roll, two yellow flames (49) at +-0.5 times it, a glow (47) at a new
   roll each frame; with the tracer, it starts once the bullet has flown 2 u. */
void func_L01_0035C8D0(u8 *bullet)
{
    N60Draw_0035C8D0 *vars = *(N60Draw_0035C8D0 **)(bullet + 0x68);
    u8 *pos;

    if (vars == 0) {
        return;
    }
    pos = bullet + 0x10;
    /* 1 degree a frame */
    vars->roll = func_0038DAB8(vars->roll, 0.017453292f);
    /* grey 0x7F at alpha 0x20 */
    func_003D9508(pos, 0x39, 0x207F7F7F, 1, 0.75f, 0.08f, func_0038DAB8(-vars->roll * 1.5f, 0.0f));
    func_003D9508(pos, 0x39, 0x207F7F7F, 1, 0.75f, 0.08f, vars->roll * 0.5f);
    func_003D9508(pos, 0x39, 0x207F7F7F, 1, 0.75f, 0.08f, func_0038DAB8(vars->roll * 2.5f, 0.0f));
    /* yellow (0xFF, 0xFF, 0) at alpha 0x10 */
    func_003D9508(pos, 0x31, 0x1000FFFF, 1, 0.5f, 0.08f, vars->roll * 0.5f);
    func_003D9508(pos, 0x31, 0x1000FFFF, 1, 0.5f, 0.08f, vars->roll * -0.5f);
    /* grey at alpha 0x50 */
    func_003D9508(pos, 0x2F, 0x507F7F7F, 1, 0.2f, 0.08f, func_00382538());
    if (vars->tracer != 0) {
        vars->flown += func_0038CEA8(vars);
        if (vars->flown > 2.0f) {
            func_L01_0035C6F0(bullet);
        }
    }
}
/* localdecomp:end func_L01_0035C8D0 */

INCLUDE_ASM("asm/levels", func_L01_0035CAD0);

INCLUDE_ASM("asm/levels", func_L01_0035CFC8);

INCLUDE_ASM("asm/levels", func_L01_0035D358);

INCLUDE_ASM("asm/levels", func_L01_0035D738);

/* localdecomp:start func_L01_0035DAF0 */
typedef struct {
    u8 pad0[0x10];
    f32 normal[4];  /* 0x10: the surface where the throw lands */
    s32 aiming;     /* 0x20 */
    s32 active;     /* 0x24: the glove is in his hand */
    s32 can_go;     /* 0x28: flat ground agents can walk */
    s32 material;   /* 0x2C: what the throw lands on */
} AgentsVars_0035DAF0;

typedef struct {
    u8 rgba[2][4];
} AgentsColours_0035DAF0;

extern s32 D_L01_001DD6E8;
extern AgentsColours_0035DAF0 D_L01_001DD6E0[];
extern void func_L01_004C7D98(u8 *point, f32 *up);
extern s32 func_L01_004CB018(s32 material);
extern f32 func_0038CE68(void *a, void *b);
extern s32 func_L01_005119E0(s32 item);
extern void func_L01_004C70A8(void *vars, f32 *pos, AgentsColours_0035DAF0 *colours, s32 a3, f32 scale);

/* agents_marker_draw: the Agents of Doom glove's landing marker while it aims (textures 17 and
   18), red (0x7F, 0x10, 0x10 / 0xAF, 0, 0) where agents can't go. */
void func_L01_0035DAF0(u8 *glove)
{
    AgentsVars_0035DAF0 *vars = *(AgentsVars_0035DAF0 **)(glove + 0x68);
    f32 up[4];
    AgentsColours_0035DAF0 red;

    func_L01_004C7D98(glove + 0x10, up);
    /* under 8 agents out */
    if (D_L01_001DD6E8 < 8) {
        if (vars->material != 0) {
            /* not on a liquid or class-1 material */
            if ((u32)(func_L01_004CB018(vars->material) - 1) < 2) {
                vars->can_go = 0;
            } else if (vars->active == 0 || func_0038CE68(vars->normal, up) <= 0.9f) {
                /* a normal's height of 0.9 or less is a slope too steep */
                vars->can_go = 0;
            } else {
                vars->can_go = 1;
            }
        }
        red = D_L01_001DD6E0[0];
        if (vars->active != 0 && func_L01_005119E0(-1) != 0) {
            if (vars->can_go != 0) {
                func_L01_004C70A8(vars, vars->normal, 0, 0, 1.0f);
            } else {
                func_L01_004C70A8(vars, vars->normal, &red, 0, 1.0f);
            }
        }
    }
}
/* localdecomp:end func_L01_0035DAF0 */

INCLUDE_ASM("asm/levels", func_L01_0035DC18);

/* localdecomp:start func_L01_0035DEC8 */
typedef struct {
    s128 velocity;  /* 0x00 */
    u8 pad10[0x10];
    s32 bounces;    /* 0x20 */
    s32 landed;     /* 0x24 */
    s32 countdown;  /* 0x28: frames until it lets its agents out */
    s32 shadow;     /* 0x2C */
    s32 sound;      /* 0x30 */
} __attribute__((aligned(16))) PodVars_0035DEC8;

extern u8 *func_003C24B0(s32 class, s32 vars_size);
extern f32 func_003824E0(f32 low, f32 high);
extern void func_003C7C38(u8 *moby);
extern s32 func_L01_004C85C8(u8 *moby, s32 a1, f32 x, f32 y, f32 z);
extern void func_L01_0035E598(u8 *pod);

/* agent_pod_spawn: the Agents of Doom's pod (class 0x1853) at pos with velocity, turned at
   random, letting its agents out after 250 frames (the US's 300). */
u8 *func_L01_0035DEC8(s128 *pos, s128 *velocity)
{
    u8 *pod = func_003C24B0(0x1853, 0x80);
    PodVars_0035DEC8 *vars;

    if (pod != 0) {
        pod[0x30] = 0xFF;
        *(u16 *)(pod + 0x32) = 0x1FF;
        pod[0x31] = 1;
        pod[0x20] = 0;
        vars = *(PodVars_0035DEC8 **)(pod + 0x68);
        *(s128 *)(pod + 0x10) = *pos;
        vars->velocity = *velocity;
        vars->landed = 0;
        vars->bounces = 25;
        vars->countdown = 250;
        /* any turn, -pi to pi, about each axis */
        *(f32 *)(pod + 0xF0) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(pod + 0xF4) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(pod + 0xF8) = func_003824E0(-3.1415927f, 3.1415927f);
        *(s32 *)(pod + 0xFC) = 0;
        /* 1.2 x its class's scale */
        *(f32 *)(pod + 0x2C) = *(f32 *)(*(u8 **)(pod + 0x24) + 0x24) * 1.2f;
        func_003C7C38(pod);
        vars->shadow = func_L01_004C85C8(pod, 0, 1.0f, 1.0f, 1.0f);
        vars->sound = 0x3A;
        func_L01_0035E598(pod);
    }
    return pod;
}
/* localdecomp:end func_L01_0035DEC8 */

INCLUDE_ASM("asm/levels", func_L01_0035E010);
