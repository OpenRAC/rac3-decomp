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

/* declared by functions of L01_0035BF48.c, which this file was cut from */
extern u8 *func_003C24B0(s32 class, s32 vars_size);
extern f32 func_00382538(void);
extern f32 func_0038CEA8(void *);
extern s32 func_L01_004C85C8(u8 *moby, s32 a1, f32 x, f32 y, f32 z);
extern u8 D_001A4BE0[];

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

/* localdecomp:start func_L01_0035D738 */
typedef struct {
    u8 a;
    u8 b;
    u8 pad[0xEE];
} Row_0035D738;

typedef struct {
    u8 pad0[0x20];
    s32 timer;   /* 0x20 */
    s32 w24;     /* 0x24 */
    s32 armed;   /* 0x28 */
    u8 pad2C[4];
    s32 delay;   /* 0x30 */
} Vars_0035D738;

typedef struct {
    u8 pad0[0x1210];
    s32 f1210;
    u8 pad1[0x16B0 - 0x1214];
    s32 f16B0;
    u8 pad2[0x25C4 - 0x16B4];
    s32 f25C4;
    u8 pad3[0x25ED - 0x25C8];
    u8 b25ED;
    u8 pad4[0x28BC - 0x25EE];
    s32 f28BC;
} G_0035D738;

extern u8 *D_001D52FC;
extern u8 D_00142617[];
extern Row_0035D738 D_L01_002C5600[];
extern f32 D_L01_002F4D7C[];
extern s32 D_L01_001DD6E8;

extern void func_003C2F58(void *, s32, void *);
extern void func_L01_004C7438(void *out, void *in, s32 a, s32 b, f32 c, f32 d, f32 e, f32 f);
extern s32 func_L01_004C7A18(f32 h, void *a, void *b, void *c, void *d, void *e, s32 f, s32 g);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_005119E0(s32 item);
extern void func_L01_004EA7D8(s32);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_L01_005118D0(s32, s32);
extern s32 func_L01_003C2E10(void);
extern u8 *func_L01_003C27E0(void *, void *);
extern u8 D_001A4C60[];
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L01_0035DEC8(s128 *pos, s128 *velocity);
extern void func_L01_004EAA80(void);
extern void func_L01_0035DAF0(u8 *glove);
extern void func_L01_00404A10_0035D738(void *, void *);

/* agents_glove_update: the Agents of Doom glove's update */
void func_L01_0035D738(u8 *glove)
{
    Vars_0035D738 *vars = *(Vars_0035D738 **)(glove + 0x68);
    f32 v[8];
    f32 *pos;
    f32 speed;
    s32 ready;
    s32 level;
    s32 i;
    u8 *pod;

    func_003C2F58(glove, 0, &v[0]);
    pos = &v[4];
    speed = 4.5f;
    if ((*(G_0035D738 *)&D_001A4BE0).f16B0 == 2) {
        speed = 11.0f;
    }
    func_L01_004C7438(pos, &v[0], 0, 0, 1.5f, speed, 0.3f, 0.0044f);
    ready = 1;
    vars->w24 = func_L01_004C7A18(0.0044f, &v[0], pos, vars, (u8 *)vars + 0x10, glove, 0, (s32)((u8 *)vars + 0x2C));
    if ((*(G_0035D738 *)&D_001A4BE0).f25C4 == 0x1D) {
        if (func_0038CAD0(&(*(G_0035D738 *)&D_001A4BE0).f28BC) == 0) {
            ready = 0;
        }
    } else {
        (*(G_0035D738 *)&D_001A4BE0).f28BC = 0x21;
    }
    level = (D_L01_002C5600 + D_00142617[0])->b;
    if (glove[0x31] != 0) {
        D_L01_002F4D7C[0] = 0.1f;
    }
    func_0038CAD0(&vars->delay);
    switch (glove[0x20]) {
    case 0:
        glove[0x20] = 1;
        vars->armed = 1;
        vars->w24 = 0;
    case 1:
        if (((*(s32 *)(D_001D52FC + 0x1A4) & (*(G_0035D738 *)&D_001A4BE0).f1210) ||
             ((*(s32 *)(D_001D52FC + 0x1A4) & 8) && (*(G_0035D738 *)&D_001A4BE0).f25C4 == 0x1D)) &&
            (*(G_0035D738 *)&D_001A4BE0).b25ED == 0 && ready && vars->armed != 0 && D_L01_001DD6E8 < 8 && vars->delay == 0) {
            if (func_L01_005119E0(-1)) {
                func_L01_004EA7D8(-1);
                glove[0x20] = 2;
                vars->timer = 0x11;
                vars->delay = 0x25;
            } else {
                func_003A52A0(0, 0, glove);
            }
        } else if (!func_L01_005119E0(-1) || D_L01_001DD6E8 >= 8) {
            if (*(s32 *)(D_001D52FC + 0x1A4) & (*(G_0035D738 *)&D_001A4BE0).f1210) {
                func_003A52A0(0, 0, glove);
            }
        }
        break;
    case 2:
        if (func_0038CAD0(&vars->timer)) {
            func_L01_005118D0(-1, 1);
            if (level >= 3 && func_L01_003C2E10()) {
                for (i = 3; i >= 0; i--) {
                    if (func_L01_003C2E10()) {
                        func_L01_003C27E0(glove, D_001A4C60);
                        D_L01_001DD6E8++;
                    }
                }
                func_L01_004EAA80();
                glove[0x20] = 3;
                vars->timer = 8;
            } else {
                if (func_0038CEA8(pos) > 0.40000003576278687f) {
                    func_0038CF68(pos, pos, 0.40000003576278687f);
                }
                pod = func_L01_0035DEC8((s128 *)&v[0], (s128 *)pos);
                *(u8 **)(pod + 0xB8) = glove;
                func_L01_004EAA80();
                glove[0x20] = 3;
                vars->timer = 8;
            }
        }
        break;
    case 3:
        if (func_0038CAD0(&vars->timer)) {
            glove[0x20] = 1;
        }
        break;
    }
    func_L01_00404A10_0035D738(func_L01_0035DAF0, glove);
}
/* localdecomp:end func_L01_0035D738 */

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
