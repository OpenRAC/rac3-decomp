/* Near miss for func_L01_0035BF48 (open-rac-engine names it n60_bullet_spawn), file
   src/levels/shared/L01_0035BF48.c (needs @ps2as: 35.0 and 80 degrees inline). 5 words
   differ: retail loads the velocity (lq $v1) before the life store and keeps it in $v1,
   this C loads it after (lq $v0); and retail sets a1 (pos) before the 80-degree constant,
   this C after f12. Storing velocity before life gives the lq and $v1 but swaps the
   velocity and life parameters' callee-saved registers ($s2/$s3), as in enemy_bullet_spawn.
   Tried: all 24 orders of the pos/velocity/life/gun stores, a vector struct type for pos or
   velocity, an f32[4] velocity field, an inline copy helper: no change. */
#include "common.h"

typedef int s128 __attribute__((mode(TI)));

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
extern void func_L01_004CAC78(f32 speed, f32 range, f32 max_angle, void *out, void *from);
extern s32 func_L01_004C85C8(u8 *moby, s32 a1, f32 x, f32 y, f32 z);
extern void func_L01_004AA7E8(u8 *moby, s32 a1);
extern u8 D_001A4BE0[];

/* n60_bullet_spawn: an N60 Storm bullet (class 0x1851) at pos with velocity, the row's damage
   and the gun as attacker; in the aiming camera modes it bends toward the aim point. */
u8 *func_L01_0035BF48(s32 gun, s128 *pos, s128 *velocity, s32 life, s32 tracer, f32 damage, f32 size)
{
    u8 *bullet = func_003C24B0(0x1851, 0x80);
    N60Bullet_0035BF48 *vars;

    if (bullet != 0) {
        bullet[0x20] = 0;
        *(u16 *)(bullet + 0x32) = 0xFF;
        bullet[0x30] = 0xFF;
        vars = *(N60Bullet_0035BF48 **)(bullet + 0x68);
        *(s128 *)(bullet + 0x10) = *pos;
        vars->life = life;
        vars->velocity = *velocity;
        vars->gun = gun;
        vars->roll = func_00382538();
        vars->damage = damage;
        vars->tracer = tracer;
        vars->bounces = 0;
        vars->flown = 0.0f;
        /* the hero's camera mode: not the follow camera */
        if (*(s32 *)(D_001A4BE0 + 0x16B0) != 0) {
            /* within 35 u, turned at most 80 degrees */
            func_L01_004CAC78(func_0038CEA8(vars), 35.0f, 1.3962634f, vars, pos);
        }
        vars->shadow = func_L01_004C85C8(bullet, 0, size, 1.0f, 1.0f);
        *(s32 *)(bullet + 0x98) = 0;
        *(u16 *)(bullet + 0x34) = (*(u16 *)(bullet + 0x34) | 0x41) & ~0x1000;
        func_L01_004AA7E8(bullet, 1);
    }
    return bullet;
}
