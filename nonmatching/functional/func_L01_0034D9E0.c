/* functional: medium. Near-miss draft (compiles under file flags); 86 diff words (frame 0x230 vs retail); description inferred from draft and callee inventory, not every branch re-read */
/* localdecomp:start func_L01_0034D9E0 */
#include "vu0.h"
void func_L01_0034D9E0(s32 arg, Entry_0034CC80 *entry)
{
    extern void func_L01_0034D8C8(f32 *, f32 *, f32 *, f32 *, f32 *, f32);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern void func_L01_0034DBE8(s32, s32, void *, s32);
    vu0_v4 points[25];
    vu0_v4 a,b,r,c;
    s32 i;
    u8 *p = (u8 *)entry;
    for (i=0; i<24; i++) {
        a = *(vu0_v4 *)p;
        b = *(vu0_v4 *)(p+16);
        __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(c) : "m"(*(vu0_v4 *)(p+48)) : "vf1");
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "+m"(a) : "m"(*(vu0_v4 *)(p+32)) : "vf1", "vf2");
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "+m"(b) : "m"(c) : "vf1", "vf2");
        func_L01_0034D8C8((f32 *)&points[i], (f32 *)(p+32), (f32 *)(p+48), (f32 *)&a, (f32 *)&b, (f32)i/23.0f);
        r.w=0;
        r.x=func_003824E0(-1.0f,1.0f);
        r.y=func_003824E0(-1.0f,1.0f);
        r.z=func_003824E0(-1.0f,1.0f);
        func_0038CF68((f32 *)&r,(f32 *)&r,0.075f);
        __asm__("lqc2 $vf2, %0\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "+m"(points[i]) : "m"(r) : "vf1", "vf2");
    }
    if (*(s32 *)(p+0xA8)>=8) func_L01_0034DBE8(arg,func_00382498(64,128),points,25);
    else func_L01_0034DBE8(arg,func_00382498(0,64),points,25);
}
/* localdecomp:end func_L01_0034D9E0 */
