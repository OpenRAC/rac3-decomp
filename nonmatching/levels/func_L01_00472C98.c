/* PAL near miss (Codex wave 10): near miss: 154 words differ with the file's flags.
 * Worker's note: 154 diff; build/codex/w502/func_L01_00472C98.05.log; legal best retains prologue/initial vector stores/register allocation and VU scheduling differences; helper and field forms unchanged; pointer form worsened to 178; 129-diff experiment had invalid array asm ...
 */
#include "common.h"
/* localdecomp:start func_L01_00472C98 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00472C98;
void func_L01_00472C98(u8 *p) {
    extern void func_L01_004CAB30(void *,void *);
    extern s32 func_0038DBD8(s32,s32,f32);
    extern f32 func_L01_004451A0(f32);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_0038CF68(void *,void *,f32);
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    V_00472C98 movement, accel, velocity, impulse;
    u8 *d=p+0x20;
    f32 *v=(f32 *)(p+0x30);
    s32 rgb, alpha, mode, spin;
    f32 scale0,scale1,size0,size1,speed,t,applied;
    accel.w=0.0f;
    accel.x=*(f32 *)(p+0x20);
    accel.y=*(f32 *)(d+4);
    accel.z=*(f32 *)(d+8);
    velocity.x=v[0];
    velocity.y=v[1];
    velocity.z=v[2];
    velocity.w=0.0f;
    size0=(f32)d[0x1E]*0.0078125f;
    size1=(f32)d[0x1F]*0.0078125f;
    scale0=(f32)d[0x1C]*0.0078125f;
    scale1=(f32)d[0x1D]*0.0078125f;
    rgb=d[0xC]&15;
    rgb=rgb|((rgb<<16)|(rgb<<8));
    alpha=(d[0xC]>>4)|0x70;
    mode=d[0xD]&15;
    spin=d[0xD]>>4;
    speed=(f32)d[0xF]*0.0078125f;
    size0*=210000.0f;
    size1*=210000.0f;

    func_L01_004CAB30(p+0x10,p+0x10);
    t=1.0f-(f32)*(s16 *)(p+0xA)/(f32)d[0xE];
    if (mode==0) {
        *(s32 *)(p+4)=func_0038DBD8(0x103080,rgb,t)|(alpha<<24);
        *(f32 *)(p+0xC)=size0+(size1-size0)*t;
        { f32 shape;
        applied=scale0+(scale1-scale0)*t;
        shape=func_L01_004451A0(t);
        func_0038CE20(&movement,&velocity,speed*shape); }
    } else {
        f32 fade=func_L01_004451A0(t);
        applied=scale1;
        *(s32 *)(p+4)=rgb|((s32)((f32)alpha-(f32)alpha*fade)<<24);
        func_0038CE20(&movement,&velocity,speed);
    }
    func_0038CF68(&impulse,&accel,applied);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tlqc2 $vf2, %2\n\tsqc2 $vf1, %0\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
      : "+m"(*(V_00472C98 *)(p+0x10)) : "m"(impulse),"m"(movement) : "vf1","vf2");
    p[8]+=spin;
    if (func_0038CB00(p+0xA)) {
        if (mode==0) {
            d[0xE]=17;
            d[0xD]|=1;
            *(s16 *)(p+0xA)=17;
        } else func_003CD250(p);
    }
}
/* localdecomp:end func_L01_00472C98 */
