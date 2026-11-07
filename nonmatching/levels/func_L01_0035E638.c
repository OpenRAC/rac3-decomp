/* Near miss for func_L01_0035E638 (open-rac-engine names it enemy_bullet_spawn), file
   src/levels/shared/L01_0035E450.c. 4 words differ: the velocity pointer (a2) and the
   damage flags (a3) swap callee-saved registers (retail: flags in $s3, velocity in $s4;
   this C: the reverse). Both have equal global-alloc priority (2 refs, live 16) and the tie
   goes to the lower pseudo, velocity. Storing flags before the velocity copy gives the
   registers but puts the sw before the lq; store orders (120 permutations), a velocity or
   flags copy, a vector struct type for velocity: no change. */
#include "common.h"

typedef int s128 __attribute__((mode(TI)));

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

extern u8 *func_003C24B0(s32, s32);
extern f32 func_00382538(void);
extern void func_L01_004AA7E8(u8 *a0, s32 a1);

/* enemy_bullet_spawn: a small bullet (class 0x1855), the agents' and the Nitro Eruptor's,
   at pos flying at velocity, owned by owner, doing a flat damage with these flags. */
u8 *func_L01_0035E638(s32 owner, s128 *pos, s128 *velocity, s32 flags, f32 damage)
{
    u8 *bullet = func_003C24B0(0x1855, 0x80);
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
