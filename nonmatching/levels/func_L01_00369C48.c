/* PAL near miss (Codex wave 6): near miss: 7 words differ with the file's flags.
 * Worker's note: 7 instruction diffs, VU0/scalar scheduling. Existing j-form helper cannot compile with fixed file flags (02.log); retained real VU0 block. Best build/codex/w305/func_L01_00369C48.final.log
 */
#include "common.h"
/* localdecomp:start func_L01_00369C48 */
#include "vu0.h"
void func_L01_00369C48(vu0_v4 *pos) {
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_0046B288(void *, s32, s32, s32, f32, f32);
    vu0_v4 v;
    s32 i;
    f32 angle, radius, a, b;
    s32 n;
    u8 *p;
    for (i=0; i>=0; i--) {
        angle=func_00382538();
        radius=func_003824E0(0.0f,0.6f);
        a=func_003824E0(0.0f,1.2f);
        b=func_003824E0(1.0f,4.0f);
        n=func_00382498(70,130);
        v.x=func_0038D098(angle)*radius;
        v.y=func_0038D0B0(angle)*radius;
        v.z=0.0f;
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "+m"(v) : "m"(*pos) : "vf1", "vf2");
        p=func_L01_0046B288(&v,0x5005B182,0x5B182,n,a,b);
        if(p) p[3]=68;
    }
}
/* localdecomp:end func_L01_00369C48 */
