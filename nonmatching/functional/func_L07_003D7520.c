/* functional: high. PAL near-miss draft; constants (pi/6 step, radii 1.2 and 2.5, z lift 0.45), segment/ring split and callees match PAL asm; only float register allocation differs. */
#include "common.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003D7520;
void func_L07_003D7520(u8 *obj,V_003D7520 *out,s32 index) {
    extern f32 func_0038DB48(f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    V_003D7520 delta;
    s32 ring;
    u8 segment;
    f32 angle, radius;
    if(index>=6) { segment=index-6;ring=1; }
    else { segment=index;ring=0; }
    angle=(f32)segment;
    angle+=angle;
    angle+=(f32)ring;
    angle*=0.5235988f;
    angle+=*(f32 *)(obj+0xf8);
    angle=func_0038DB48(angle);
    radius=1.2f;
    if(ring) radius=2.5f;
    delta.x=func_0038D098(angle)*radius;
    delta.y=func_0038D0B0(angle)*radius;
    delta.z=0;
    __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(*out):"m"(*(V_003D7520 *)(obj+16)),"m"(delta):"vf1","vf2");
    out->z+=0.45f;
}
