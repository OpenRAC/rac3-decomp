#include "common.h"

/* localdecomp:start func_L01_003298C8 */
#include "structs/moby.h"
typedef int u128_3298C8 __attribute__((mode(TI)));
/* A piece of debris's pvars (class 0x1A50, the chunk; open-rac-engine docs/research/effects.md,
   "A piece of debris"; its update is func_L01_00329AD0). */
typedef struct {
    u128_3298C8 velocity;          /* 0x00 */
    f32 spin_x;                    /* 0x10: 0.126 to 0.251 rad a frame about x */
    f32 spin_y;                    /* 0x14: and about y */
    s16 life;                      /* 0x18: frames left */
    s16 life_start;                /* 0x1A */
    s16 scale;                     /* 0x1C: the moby's scale x 128, which it shrinks from */
    s16 gravity;                   /* 0x1E: x 128 */
    u32 smoke_colours[4];          /* 0x20: the smoke puffs' colours, one picked at random */
    s32 smoke_kind;                /* 0x30: 0 none, 1 a puff in half the frames, 2 three a frame */
    s32 bounce;                    /* 0x34 */
    s32 additive;                  /* 0x38: the puffs are added (0x48), else blended (0x44) */
    s16 puff_size;                 /* 0x3C: a puff's first size, x 1000 */
    s16 puff_growth;               /* 0x3E: what a puff's size grows by, x 1000 */
} Debris_3298C8;
/* debris_spawn: spawns a piece of debris (class 0x1A50) at position, moving at velocity, drawn at
   its class's scale times scale and falling at gravity; smoke kind 3 picks one of the three at
   random; smoke_colours 0 gives four greys at alpha 0x2F. Returns the moby or 0. */
struct Moby *func_L01_003298C8(u128_3298C8 *position, u128_3298C8 *velocity, s32 life, s32 smoke_kind, s32 bounce, s32 glow, u32 *smoke_colours, s32 additive, s16 puff_size, s16 puff_growth, f32 scale, f32 gravity)
{
    extern struct Moby *func_003C24B0(s32, s32);
    extern void func_0038CC88(void *, void *, s32);
    extern void func_L01_0043B9E8(struct Moby *, s32, s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382468(s32);
    extern void func_003C7C38(struct Moby *);
    struct Moby *moby = func_003C24B0(0x1A50, 0x80);
    Debris_3298C8 *vars;
    if (moby != 0) {
        vars = moby->pvar;
        ((u8 *)moby)[0x30] = 0xFF;
        moby->draw_dist = 0xFF;
        ((u8 *)moby)[0x31] = 1;
        moby->opacity = 0x80;
        vars->bounce = bounce;
        vars->additive = additive;
        moby->scale *= scale;
        vars->puff_size = puff_size;
        vars->puff_growth = puff_growth;
        if (smoke_colours != 0) {
            func_0038CC88(vars->smoke_colours, smoke_colours, 0x10);
        } else {
            vars->smoke_colours[0] = 0x2FFFFFFF;
            vars->smoke_colours[1] = 0x2F808080;
            vars->smoke_colours[2] = 0x2FC0C0C0;
            vars->smoke_colours[3] = 0x2F404040;
        }
        func_L01_0043B9E8(moby, 0x7F, 0x7F, 0x7F);
        *(u128_3298C8 *)&moby->position = *position;
        vars->velocity = *velocity;
        vars->spin_x = func_003824E0(0.12566371262073517f, 0.25132742524147034f);
        vars->spin_y = func_003824E0(0.12566371262073517f, 0.25132742524147034f);
        vars->life = life;
        vars->life_start = life;
        vars->smoke_kind = smoke_kind;
        if (smoke_kind == 3) vars->smoke_kind = func_00382468(3);
        {
            s32 shrink = moby->scale * 128.0f;
            vars->gravity = (s32)(gravity * 128.0f);
            vars->scale = shrink;
        }
        *(s32 *)((u8 *)moby + 0x78) = glow;
        func_003C7C38(moby);
    }
    return moby;
}
/* localdecomp:end func_L01_003298C8 */
