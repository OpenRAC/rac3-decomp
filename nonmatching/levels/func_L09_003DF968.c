/* PAL near miss (Codex wave 7): near miss: 198 words differ with the file's flags.
 * Worker's note: 198 diff: build/codex/w356/func_L09_003DF968.check5.log and check6.log; complete PAL bullet update; collision pointer decoded at hit position minus 8; saved registers and block scheduling remain; no alternate flags
 */
#include "common.h"
/* localdecomp:start func_L09_003DF968 */
#include "vu0.h"
typedef struct { u8 p0[0x10]; u8 *owner; u8 p14[4]; u8 zero, flag; u16 id; u8 p1C[0x14]; } Hit_003DF968;
typedef struct { vu0_v4 hitpos; u8 *hit; u8 p14[4]; } Collision_003DF968;
extern vu0_v4 D_L09_001E98E0;
extern u8 *D_L09_001E98D8[];
void func_L09_003DF968(u8 *bullet)
{
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_00446760(void *, u8 *, s32, void *, f32);
    extern f32 *func_00382348(u8 *);
    extern s32 func_003D4D00(void *, s32, void *, void *, f32);
    extern void func_L09_003E0140(f32 *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    extern void func_003C2880(void *);
    extern s32 func_0038DC20(void *, f32);
    extern void func_L01_00404A10(void *, void *);
    extern void func_L09_003DFF48(u8 *);
    extern void func_L09_003E0360(M_003E0360 *, vu0_v4 *, vu0_v4 *);
    s32 state = bullet[0x20];
    BulletVars_003DF890 *vars = *(BulletVars_003DF890 **)(bullet + 0x68);
    vu0_v4 previous, temp;
    union { Hit_003DF968 hit; vu0_v4 current; } work;
    u8 *target;
    f32 *health;
    switch (state) {
    case 0:
        previous = ((M_003E0360 *)bullet)->pos;
        vec_add_ba(&((M_003E0360 *)bullet)->pos, vars, &((M_003E0360 *)bullet)->pos);
        if (((M_003E0360 *)bullet)->pos.x < 2.0f || ((M_003E0360 *)bullet)->pos.x > 1021.0f || ((M_003E0360 *)bullet)->pos.y < 2.0f || ((M_003E0360 *)bullet)->pos.y > 1021.0f || ((M_003E0360 *)bullet)->pos.z < 2.0f || ((M_003E0360 *)bullet)->pos.z > 1021.0f) goto destroy;
        vars->ticks++;
        if (func_003D3CB0(&previous, &((M_003E0360 *)bullet)->pos, 0, bullet, 0)) {
            bullet[0x20] = 1;
            ((M_003E0360 *)bullet)->pos = D_L09_001E98E0;
            temp = *(vu0_v4 *)vars;
            func_0038CE20(&temp, &temp, 0.5f);
            temp.w = 5627.9248046875f;
            func_L01_00446760(&work.hit, bullet, vars->flags, &temp, vars->damage);
            target = ((u8 **)&D_L09_001E98E0)[-2];
            work.hit.owner = (u8 *)vars->owner;
            work.hit.flag = 1;
            work.hit.id = *(u16 *)(bullet + 0xAA);
            work.hit.zero = 0;
            if (target && (*(s16 *)(target + 0xAA) == 0x18BE || *(s16 *)(target + 0xAA) == 0x1ADE || *(s16 *)(target + 0xAA) == 0 || target == (u8 *)vars->owner)) {
                vec_add_ab(&((M_003E0360 *)bullet)->pos, vars, &((M_003E0360 *)bullet)->pos);
                bullet[0x20] = 0;
                break;
            }
            if (target) {
                if (vars->owner && *(s16 *)((u8 *)vars->owner + 0xAA) == 0x1A17) {
                    health = func_00382348(target);
                    if (health && *health <= vars->damage) {
                        u8 *owner_vars = *(u8 **)((u8 *)vars->owner + 0x68);
                        (*(u16 *)(owner_vars + 0x78E))++;
                    }
                }
                func_003D4D00(&D_L09_001E98E0, 0, bullet, &work.hit, 1.0f);
            } else func_003D4D00(&D_L09_001E98E0, 0, bullet, &work.hit, 0.6f);
            func_L09_003E0140(&((M_003E0360 *)bullet)->pos.x);
            goto destroy;
        }
        break;
    case 1:
        func_0038CF68(vars, vars, -0.1f);
        vec_add_ba(&temp, &((M_003E0360 *)bullet)->pos, vars);
        func_L01_003303B8(&temp, 0, 5, 2, 2, 2, 2, 0, 0.14f, 0.0f, 0.0f, 0.0f,
            0, state, 0, 0, state, 0, 0x1010000, 0, 0x399EF7, 0x93F7, 0x409FFF, 0x90FF, 0x9FFF, 0x3094FF, 0x7F205F7F, 0x28005F7F, 0x30DFFF, 0);
    destroy:
        func_003C2880(bullet);
        return;
    }
    temp = ((M_003E0360 *)bullet)->pos;
    temp.w = 0.5f;
    if (func_0038DC20(&temp, 96.0f) > 0) {
        func_L01_00404A10(func_L09_003DFF48, bullet);
        work.current = ((M_003E0360 *)bullet)->pos;
        func_L09_003E0360((M_003E0360 *)bullet, &work.current, &previous);
    }
    return;
}
/* localdecomp:end func_L09_003DF968 */
