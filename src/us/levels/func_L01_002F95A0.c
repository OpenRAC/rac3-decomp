#include "common.h"

/* NTSC-U counterpart of func_L01_002F9578 (src/levels/shared/L01_002F7800.c) */
/* localdecomp:start func_L01_002F95A0 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_2F9578;

typedef struct {
    Vec_2F9578 origin; /* 0x00: the spawner's second point (explosion_spawn: the blast raised) */
    void *owner;       /* 0x10: the moby it is for, or 0 */
    s32 life;          /* 0x14: ticks it lives */
    f32 scale;         /* 0x18: its full scale */
    s16 timer;         /* 0x1C: ticks left */
    s16 opacity;       /* 0x1E: its opacity while it holds */
} DomeVars_2F9578;

typedef struct {
    u8 pad_0[0x10];
    Vec_2F9578 position; /* 0x10 */
    u8 state;            /* 0x20 */
    u8 pad_21[0x23 - 0x21];
    u8 opacity;          /* 0x23 */
    u8 pad_24[0x2C - 0x24];
    f32 scale;           /* 0x2C */
    u8 update_dist;      /* 0x30: names for 0x30-0x32 from Horizon Private Server's libuya */
    u8 drawn;            /* 0x31 */
    s16 draw_dist;       /* 0x32 */
    u8 pad_34[0x68 - 0x34];
    DomeVars_2F9578 *vars; /* 0x68 */
    u8 pad_6C[0xF0 - 0x6C];
    Vec_2F9578 rotation; /* 0xF0: angles x, y, z */
} DomeMoby_2F9578;

extern DomeMoby_2F9578 *func_003BCFB0_002F95A0(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00438908(u8 *, s32, s32, s32);
extern void func_003C26C8(u8 *);

/* explosion_dome_spawn: spawns the explosions' dome (class 0x70) at place, at its class's scale
 * times factor, turned at random on all three axes, tinted (r, g, b), for life ticks. */
DomeMoby_2F9578 *func_L01_002F95A0(f32 factor, void *owner, Vec_2F9578 *place, Vec_2F9578 *origin,
                                   s32 life, u8 r, u8 g, u8 b, u8 opacity)
{
    DomeMoby_2F9578 *moby;
    DomeVars_2F9578 *vars;
    Vec_2F9578 rotation;

    moby = func_003BCFB0_002F95A0(0x70, 0x80);
    if (moby != 0) {
        vars = moby->vars;
        {
            Vec_2F9578 turn = { 0 }; /* -pi to pi on each axis */
            turn.x = func_0037E250(-3.1415927f, 3.1415927f);
            turn.y = func_0037E250(-3.1415927f, 3.1415927f);
            turn.z = func_0037E250(-3.1415927f, 3.1415927f);
            rotation = turn;
        }
        moby->state = 0;
        moby->opacity = opacity;
        moby->update_dist = 0xFF;
        moby->draw_dist = 0x1FF;
        moby->drawn = 1;
        func_L01_00438908((u8 *)moby, r, g, b);
        vars->scale = moby->scale * factor;
        moby->scale = 0.0f;
        vars->owner = owner;
        moby->position = *place;
        vars->origin = *origin;
        moby->rotation = rotation;
        vars->life = life;
        vars->timer = vars->life - 4; /* it starts with 4 ticks gone (NTSC-U) */
        moby->scale = (f32)(life - vars->timer) * vars->scale / (f32)life;
        vars->opacity = opacity;
        func_003C26C8((u8 *)moby);
    }
    return moby;
}
/* localdecomp:end func_L01_002F95A0 */
