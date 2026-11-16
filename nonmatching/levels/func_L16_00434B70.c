/* PAL near miss (Codex wave 8): near miss: 33 words differ with the file's flags.
 * Worker's note: 32 diff / 40 words; build/codex/w448/func_L16_00434B70.01.log. Fixed default assembler emits 0.01f in .lit4 (lwc1 gp) versus retail inline lui/ori/mtc1; pointer address hoisted across first call and delta uses s1. Three C wordings produced unchanged bytes; no ...
 */
#include "common.h"
/* localdecomp:start func_L16_00434B70 */
typedef struct { f32 x,y,z,w; } V_00434B70;
extern s32 D_L16_001D6C88;
extern s32 D_L16_001E6EF4 __attribute__((section(".data")));
extern V_00434B70 D_L16_001DFF70[];
void func_L16_00434B70(void *o) {
    extern void func_003C2EC0(void *,s32,void *);
    extern void func_0038CF68(void *,void *,f32);
    s32 delta=D_L16_001E6EF4-D_L16_001D6C88;
    V_00434B70 *v;
    s32 i;
    if(o) {
        func_003C2EC0(o,0,D_L16_001DFF70);
        v=D_L16_001DFF70;
        for(i=2;i>=0;i--) {
            f32 dt=(f32)delta;
            func_0038CF68(v,v,dt*0.01f);
            v++;
        }
    }
}
/* localdecomp:end func_L16_00434B70 */
