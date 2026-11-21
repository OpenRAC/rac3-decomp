/* functional: high. Codex near miss, 83 words differ: induction pointer/hoisted-zero register allocation and instruction order only. Uses fabs_asm from vu0.h for retail's abs.s. */
#include "common.h"
/* localdecomp:start func_L01_003DEC20 */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
typedef struct { f32 phase[4], step[4]; s32 timer[4]; f32 size[4]; } State_003DEC20;
void func_L01_003DEC20(u8 *obj) {
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_0038CAD0(s32 *);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_L01_0046C2E8(void *, s32, s32, s32, s32, s32, s32, s32, f32);
    vu0_v4 pos, delta;
    State_003DEC20 *vars;
    f32 *p;
    f32 *end;
    s32 *timer;
    s32 offset;
    s32 color;
    vec_sub_ab(&pos,&D_L01_001E29C0,obj+0x10);
    vars=*(State_003DEC20 **)(obj+0x68);
    p=(f32 *)vars;
    func_0038CF68(&pos,&pos,-0.3f);
    func_0038CF68(&delta,&pos,0.1f);
    end=vars->step;
    timer=vars->timer;
    vec_add_ba(&pos,&pos,obj+0x10);
    offset=0;
    do {
        f32 value=*p + end[offset];
        *p=value;
        if (value >= 255.0f) *p=value-255.0f;
        else if (value <= 0.0f) *p=value+255.0f;
        if (func_0038CAD0(timer)) vars->timer[offset]=212;

        timer++;
        color=func_0038DBD8(0x4040FFFF,0x1040FFFF,fabs_asm(0.5f-(f32)(212-vars->timer[offset])/212.0f));
        func_L01_0046C2E8(&pos,color,((s32)*p)&255,53,1,2,0,0,vars->size[offset]);
        p++;
        vec_add_ab(&pos,&pos,&delta);
        offset++;
    } while((s32)p<(s32)end);
}
/* localdecomp:end func_L01_003DEC20 */
