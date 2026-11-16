/* PAL near miss (Codex wave 10): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: Contract-only snippet MATCH (.05-contract.log), NOT ordinary proof: .all.log COMPILE ERROR S_0030CD20 unknown. Existing func_0038CF68 exact signature requires S_0030CD20 typedef currently later at func_L01_0030CFC0; hoist that existing typedef ahead of this ...
 */
#include "common.h"
/* localdecomp:start func_L01_00308E88 */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
extern vu0_v4 D_001A4C90;
extern s32 D_L01_001D673C;
extern f32 D_L01_001DC614, D_L01_001DC618, D_L01_001DC61C, D_L01_001DC620, D_L01_001DC624, D_L01_001DC628;
__asm__(".extern D_L01_001DC614, 4");
__asm__(".extern D_L01_001DC618, 4");
__asm__(".extern D_L01_001DC61C, 4");
__asm__(".extern D_L01_001DC620, 4");
__asm__(".extern D_L01_001DC624, 4");
__asm__(".extern D_L01_001DC628, 4");
void func_L01_00308E88(vu0_v4 *position, s32 count, f32 scale)
{
    extern void func_0038CF68(S_0030CD20 *, S_0030CD20 *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382468(s32);
    extern void func_0038D890(void *, void *, void *, f32);
    extern u8 *func_L01_0046B458(void *, f32, s32, f32, s32, s32, s32, void *, f32, s32);
    vu0_v4 velocity, direction, axis, projection;
    s32 i;
    vec_sub_ab(&direction,&D_L01_001E29C0,position);
    if(D_L01_001D673C==0) {
        direction.z=0.0f;
        axis.x=0.0f;
        axis.y=0.0f;
        axis.z=1.0f;
        axis.w=1.0f;
    } else {
        vec_sub_ab(&projection,position,&D_001A4C90);
        func_0038CF68((S_0030CD20 *)&axis,(S_0030CD20 *)&projection,1.0f);
        func_0038CE20((f32 *)&projection,(f32 *)&axis,func_0038CE68(&axis,&direction));
        vec_sub_ab(&direction,&direction,&projection);
    }
    for(i=0;i<count;i++) {
        f32 size=func_003824E0(D_L01_001DC624,D_L01_001DC628);
        s32 spin=func_00382468(2);
        f32 angle;
        u8 *particle;
        if(spin==0) spin--;
        angle=func_003824E0(-1.0471976f,1.0471976f);
        func_0038D890(&velocity,&direction,&axis,angle);
        func_0038CF68((S_0030CD20 *)&velocity,(S_0030CD20 *)&velocity,func_003824E0(D_L01_001DC614,D_L01_001DC618)*0.020000001f);
        velocity.z=func_003824E0(D_L01_001DC61C,D_L01_001DC620)*0.020000001f;
        qzero(&velocity);
        particle=func_L01_0046B458(position,size*0.1f,50,size,0x7F7F2020,0,spin,&velocity,scale*1.44f,1);
        if(particle) particle[9]=116;
        particle=func_L01_0046B458(position,size*0.07f,50,size*0.7f,0x7FFF4040,1,-spin,&velocity,scale*1.44f,1);
        if(particle) particle[9]=116;
    }
}
/* localdecomp:end func_L01_00308E88 */
