/* PAL near miss (Codex wave 6): near miss: 20 words differ with the file's flags.
 * Worker's note: 21 diff in func_L20_003D8248.wrap1.log: loop saved-register allocation and call-argument scheduling. for/do/while source wordings produce identical remaining differences (check4/7/8). Tail vector construction matches.
 */
#include "common.h"
/* localdecomp:start func_L20_003D8248 */
typedef int Q_003D8248 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003D8248;
extern s16 D_L20_001E2650[] __attribute__((section(".sdata")));
extern s16 D_L20_001E2660[] __attribute__((section(".sdata")));
extern u8 D_L20_002A2E40[];
extern f32 D_L20_001E2694;
extern V_003D8248 D_001A4EC0;
__asm__(".extern D_L20_001E2694,16");
void func_L20_003D8248(u8 *a) {
    extern void func_L01_00409658(void*,s32,s32,s32,s32,s32,s32,f32,f32,f32);
    extern void func_0038CE20(void*,void*,f32);
    extern void func_0038CE90(void*,void*,void*);
    extern void func_0038CF68(void*,void*,f32);
    extern void func_003D9740(void*,s32,u32,s32,s32,f32);
    V_003D8248 forward,side,up,pos,neg;
    u8 *p=*(u8**)(a+0x68);
    s32 i=4;
    s32 rgb=0x7F7F7F;
    for(;i>=0;i--) {
        if(D_L20_001E2650[4-i]) {
            s32 color=((s32)((f32)D_L20_001E2660[4-i]*D_L20_001E2694)<<24)|rgb;
            func_L01_00409658(D_L20_002A2E40+(4-i)*0xA0,15,14,10,color,color,1,0.0f,4.0f,0.0f);
        }

    }
    *(f32*)(p+0x64C)+=0.1f;
    if(*(f32*)(p+0x64C)>=7.0f) *(f32*)(p+0x64C)-=7.0f;
    *(Q_003D8248*)&pos=*(Q_003D8248*)(a+0x10);
    pos.z+=2.0f;pos.w=1.0f;
    *(Q_003D8248*)&forward=*(Q_003D8248*)(a+0xC0);
    func_0038CE20(&neg,&D_001A4EC0,-1.0f);
    func_0038CE90(&side,&forward,&neg);
    func_0038CF68(&side,&side,2.5f);
    func_0038CE90(&up,&side,&forward);
    func_003D9740(&forward,23,0x1FA06565,10,1,*(f32*)(p+0x64C));
}
/* localdecomp:end func_L20_003D8248 */
