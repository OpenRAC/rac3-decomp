/* functional: high. Read against the PAL asm end to end (all branches, callee mapping, vector ops, vars offsets match). gp-relative globals renamed from the _sda symbols to the level names D_L01_001DF5xx so they are retail's addresses. Bytes differ only in register allocation and VU0 temp ordering. */
#include "common.h"
/* localdecomp:start func_L01_003DC780 */
#include "vu0.h"
extern s32 D_001A71A0[];
typedef struct { u8 pad[0xD0]; vu0_v4 pos; u8 padE0[0x25C0-0xE0]; u8 *target; u8 pad25C4[0x2850-0x25C4]; s32 alive; } Hero_003DC780;
extern Hero_003DC780 D_001A4BE0_003DC780;
extern f32 D_L01_001DF520 __attribute__((section(".sdata")));
extern f32 D_L01_001DF524 __attribute__((section(".sdata")));
extern s32 D_L01_001DF510 __attribute__((section(".sdata")));
extern s32 D_L01_001DF50C __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DF520, 4");
__asm__(".extern D_L01_001DF524, 4");
__asm__(".extern D_L01_001DF510, 4");
__asm__(".extern D_L01_001DF50C, 4");
typedef struct { vu0_v4 dir; f32 life; s32 ticks; u8 *target; s32 state; f32 speed; } Vars_003DC780;
void func_L01_003DC780(u8 *obj, Vars_003DC780 *vars) {
    extern void func_L01_00448690(void *, f32, f32, s32);
    extern void func_0038D308(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_0038CE68(void *, void *);
    extern u8 *func_00382348(u8 *);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_003DC690(void *, void *, void *, f32);
    vu0_v4 gravity, delta, target, copy, half;
    vu0_v4 temp0, temp1, temp2, temp3;
    u8 *state;
    if (vars->target == 0) {
        f32 rate = D_001A71A0[0] ? D_L01_001DF524 : D_L01_001DF520;
        func_L01_00448690(obj + 0xF4, -1.5707964f, rate * 0.5f, 0);
        func_0038D308(obj + 0xC0, obj + 0xF0);
        func_0038CE20(vars, obj + 0xC0, vars->speed);
        return;
    }
    if (vars->target == D_001A4BE0_003DC780.target) {
        if (D_001A4BE0_003DC780.alive <= 0) {
            vars->target = 0;
            return;
        }
        qzero(&gravity);
        gravity.z = -0.120000005f;
        { f32 distance=func_0038CF00(&D_001A4BE0_003DC780.pos,obj + 0x10);
        func_0038CE20(&delta,&gravity,distance / vars->speed); }
        vec_add_ba(&target,&D_001A4BE0_003DC780.pos,&delta);
        func_0038CE20(&half,D_001A4BE0_003DC780.target + 0xC0,0.5f);
        vec_add_ba(&target,&half,&target);
        vec_copy(&temp0,obj + 0x10);
        vec_copy(&temp3,&D_001A4BE0_003DC780.pos);
        vec_copy(&temp1,obj + 0x10);
        vec_sub_ba(&temp2,&target,&temp0);
        vec_sub_ab(&temp3,&temp3,&temp1);
        vec_copy(&delta,&temp2);
        vec_copy(&gravity,&temp3);
        if (func_0038CE68(&delta,&gravity) < 0.3f) {
            *(vu0_q *)&target = *(vu0_q *)(&D_001A4BE0_003DC780.pos);
        }
    } else {
        state=func_00382348(vars->target);
        if (state && *(f32 *)state <= 0.0f) {
            vars->target = 0;
            return;
        }
        if (vars->target == 0 || (vars->target)[0x20] == 0xFE || (vars->target)[0x20] == 0xFD) {
            vars->target = 0;
            return;
        }
        *(vu0_q *)&target=*(vu0_q *)(vars->target + 0x10);
        if (state) target.z += *(f32 *)(state + 0x10);
        qzero(&gravity);
        gravity.z = -0.120000005f;
        { f32 distance=func_0038CF00(&target,obj + 0x10);
        func_0038CE20(&delta,&gravity,distance / vars->speed); }
        vec_add_ab(&target,&target,&delta);
    }
    vec_sub_ab(&delta,&target,obj + 0x10);
    if (*(f32 *)(vars->target + 0x18) - 10.0f < *(f32 *)(obj + 0x18)) {
        if (vars->ticks > D_L01_001DF510) vars->ticks=func_00382498(D_L01_001DF50C,D_L01_001DF510);
    } else if (target.z < *(f32 *)(obj + 0x18)) {
        vars->target = 0;
    }
    *(vu0_q *)&copy=*(vu0_q *)&target;
    { f32 rate;
    if (vars->target == D_001A4BE0_003DC780.target) rate=D_L01_001DF520; else rate=D_L01_001DF524;
    func_L01_003DC690(obj,vars,&copy,rate); }
}
/* localdecomp:end func_L01_003DC780 */
