#include "common.h"

/* localdecomp:start func_L01_00344A88 */
#include "structs/moby.h"
typedef int u128_344A88 __attribute__((mode(TI)));
/* The small missile's pvars (class 0xA82). Named from open-rac-engine docs/research/weapons.md,
   "The small missile", and from what this spawner and its update (func_L01_00343BD8) do with them;
   unk_ fields are ones neither says more about. */
typedef struct {
    Vec4f velocity;                /* 0x00: the direction times speed / 50 */
    u8 pad_10[0x50 - 0x10];
    struct Moby *target;           /* 0x50: the first target (the Decimator passes its parent missile) */
    s32 unk_54;                    /* 0x54 */
    f32 wander_a;                  /* 0x58: probably the aim point's wander angles */
    f32 wander_b;                  /* 0x5C */
    f32 speed;                     /* 0x60 */
    u8 pad_64[0x68 - 0x64];
    f32 unk_68;                    /* 0x68 */
    u8 pad_6C[0x6E - 0x6C];
    s16 light;                     /* 0x6E: func_L01_004C85C8's handle (effects.md: a light on the missile) */
    f32 unk_70;                    /* 0x70 */
    f32 unk_74;                    /* 0x74 */
    u8 rgba[4];                    /* 0x78 */
    u8 search;                     /* 0x7C: set when it is spawned without a target */
    u8 pad_7D[0x7E - 0x7D];
    u16 flags;                     /* 0x7E */
    u8 weave;                      /* 0x80: also picks the scale, 0.025 when set, else 0.015 */
    u8 unk_81;                     /* 0x81 */
    u8 pad_82[0x84 - 0x82];
    f32 weave_phase;               /* 0x84: weapons.md: a phase moving 3-5 degrees a frame */
    f32 weave_rate;                /* 0x88 */
} SmallMissile_344A88;
extern s32 D_L01_001DFF40;
/* small_missile_spawn: spawns a class-0xA82 small missile, the Decimator's seekers and the
   missiles of the V5 agents and the Megaturret (open-rac-engine docs/research/weapons.md). */
struct Moby *func_L01_00344A88(u128_344A88 *position, Vec4f *direction, u8 r, u8 g, u8 b, u8 a, u16 flags, struct Moby *target, f32 speed, f32 unk_68, f32 unk_70, f32 unk_74, s32 weave, s32 unk_81)
{
    extern struct Moby *func_003C24B0(s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_00382538(void);
    extern f32 func_L01_00443A18(f32, f32);
    extern s32 func_L01_004C85C8(void *, s32, f32, f32, f32);
    extern void func_003C7C38(void *);
    struct Moby *missile;
    SmallMissile_344A88 *vars;
    if (D_L01_001DFF40 < 17) return 0;
    missile = func_003C24B0(0xA82, 0xC0);
    if (missile) {
        vars = missile->pvar;
        *(u128_344A88 *)&missile->position = *position;
        func_0038CF68(&vars->velocity, direction, speed * 0.020000001f);
        missile->state = 0;
        {
            s32 full = 0xFF;
            missile->draw_dist = full;
            ((u8 *)missile)[0x30] = full;
        }
        vars->target = target;
        vars->unk_54 = 0;
        missile->mode_flags |= 0x100;
        vars->speed = speed;
        vars->unk_68 = unk_68;
        vars->unk_70 = unk_70;
        vars->rgba[0] = r;
        vars->rgba[1] = g;
        vars->rgba[2] = b;
        vars->rgba[3] = a;
        vars->unk_74 = unk_74;
        vars->flags = flags;
        vars->wander_b = 0;
        vars->wander_a = 0;
        vars->unk_81 = unk_81;
        vars->weave = weave;
        missile->scale = weave ? 0.025f : 0.015f;
        *(u16 *)((u8 *)missile + 0x96) = 0;
        vars->weave_phase = func_00382538();
        vars->weave_rate = func_L01_00443A18(3.0f, 5.0f);
        if (target == 0) vars->search = 1;
        else vars->search = 0;
        vars->light = func_L01_004C85C8(missile, 0, 1.0f, 1.0f, 1.0f);
        func_003C7C38(missile);
    }
    return missile;
}
/* localdecomp:end func_L01_00344A88 */
