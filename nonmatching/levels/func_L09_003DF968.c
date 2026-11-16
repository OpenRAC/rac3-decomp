/*
 * P03 PAL near miss, base eb302969 (2026-11-16).
 * Owning file: src/levels/shared/L09_003DF890.c.
 * Flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as
 *        -mvu0-use-vf0-vf2.
 * Stock check.py at canonical level 09: 168 positional differences.
 * Five compiles: 183, 224, 168, 168, 168. Last three checker logs identical:
 * typed pvars, typed moby fields, then TI rather than aligned-struct copies.
 * Stopped under the three-identical-formulations rule.
 * Remaining: saved register allocation (moby/state/temporary), branch delay
 * slots and shared-tail scheduling; initial collision argument/store ordering.
 * Collision globals are represented by a containing-layout pointer derived
 * from its named position member; values at other placements not verified.
 * Other PAL placements 18,20,24,29, full builds and NTSC-U carry not run.
 * No match claimed; later in-file prototypes also need integration review.
 */
#include "common.h"
#include "vu0.h"
typedef struct {
    vu0_v4 dir;
    s32 owner;
    u8 pad14[4];
    u8 b18, b19;
    s16 classid;
    s32 flags;
    u8 pad24[0xC];
} Hit_F968;
typedef struct {
    vu0_v4 velocity;
    f32 phase;
    s32 ticks;
    u8 *owner;
    f32 damage;
    s32 flags;
    s32 tracer;
    f32 flown;
} Vars_F968;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[0x68-0x21];
    Vars_F968 *vars;
    u8 pad6C[0xAA-0x6C];
    u16 classid;
} Moby_F968;
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern f32 *func_00382348(void *);
extern void func_L09_003E0140(void *);
extern void func_003C2880(void *);
extern s32 func_0038DC20(void *, f32);
extern void func_L01_00404A10(void *, void *);
extern void func_L09_003DFF48(u8 *);
extern void func_L09_003E0360(void *, void *, void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
typedef struct {
    u8 pad0[8];
    u8 *object;
    u8 padC[4];
    vu0_v4 pos;
} Collision_F968;
extern vu0_v4 D_L09_001E98E0[];
void func_L09_003DF968(u8 *m) {
    Moby_F968 *bullet = (Moby_F968 *)m;
    vu0_v4 old;
    vu0_v4 pos;
    Hit_F968 hit;
    vu0_v4 *pp;
    Vars_F968 *vars = bullet->vars;
    u8 *obj;
    u8 *owner;
    f32 *health;
    switch (bullet->state) {
    case 0:
        *(vu0_q *)&old = *(vu0_q *)&bullet->pos;
        vec_add_ba(&bullet->pos, &vars->velocity, &bullet->pos);
        if (bullet->pos.x < 2.0f || bullet->pos.x > 1021.0f ||
            bullet->pos.y < 2.0f || bullet->pos.y > 1021.0f ||
            bullet->pos.z < 2.0f || bullet->pos.z > 1021.0f) {
            func_003C2880(m);
            return;
        }
        vars->ticks += 1;
        if (func_003D3CB0(&old, m+0x10, 0, m, 0)) {
            bullet->state = 1;
            *(vu0_q *)&bullet->pos = *(vu0_q *)&D_L09_001E98E0[0];
            *(vu0_q *)&pos = *(vu0_q *)&vars->velocity;
            pp = &pos;
            func_0038CE20(pp, pp, 0.5f);
            pos.w = 5627.925f;
            func_L01_00446760(&hit, m, vars->flags, &pos, vars->damage);
            hit.owner = (s32)vars->owner;
            hit.b19 = 1;
            hit.classid = bullet->classid;
            hit.b18 = 0;
            obj = ((Collision_F968 *)((u8 *)D_L09_001E98E0 - 0x10))->object;
            if (obj != 0) {
                if (*(s16 *)(obj+0xAA) == 0x18BE || *(s16 *)(obj+0xAA) == 0x1ADE ||
                    *(s16 *)(obj+0xAA) == 0 || obj == vars->owner) {
                    vec_add_ab(&bullet->pos, &vars->velocity, &bullet->pos);
                    bullet->state = 0;
                    break;
                }
            }
            if (obj != 0) {
                owner = vars->owner;
                if (owner != 0 && *(s16 *)(owner+0xAA) == 0x1A17) {
                    health = func_00382348(obj);
                    if (health != 0 && health[0] <= vars->damage) {
                        u8 *ov = *(u8 **)(vars->owner + 0x68);
                        *(u16 *)(ov+0x78E) += 1;
                    }
                }
                func_003D4D00(D_L09_001E98E0, 0, m, &hit, 1.0f);
            } else {
                func_003D4D00(D_L09_001E98E0, 0, m, &hit, 0.6f);
            }
            func_L09_003E0140(m+0x10);
            func_003C2880(m);
            return;
        }
        break;
    case 1:
        func_0038CF68(vars, vars, -0.1f);
        vec_add_ba(&pos, m+0x10, vars);
        func_L01_003303B8(&pos, 0, 5, 2, 2, 2, 2, 0, 0.14f, 0.0f, 0.0f, 0.0f,
            0, 1, 0, 0, 1, 0, 0x01010000, 0, 0x399EF7, 0x93F7, 0x409FFF, 0x90FF,
            0x9FFF, 0x3094FF, 0x7F205F7F, 0x28005F7F, 0x30DFFF, 0);
        func_003C2880(m);
        return;
    }
    pp = &pos;
    *(vu0_q *)&pos = *(vu0_q *)&bullet->pos;
    pos.w = 0.5f;
    if (func_0038DC20(pp, 96.0f) > 0) {
        func_L01_00404A10(func_L09_003DFF48, m);
        *(vu0_q *)&hit.dir = *(vu0_q *)&bullet->pos;
        func_L09_003E0360(m, &hit.dir, &old);
    }
}
