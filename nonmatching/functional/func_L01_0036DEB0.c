/* functional: high. Draft near miss (32 words, VU/scalar scheduling); both particle loops, rand/negate/type-shift logic, constants and field stores verified against PAL asm. Local extern prototype of func_L01_004669B0 differs per caller (float/int arg slots), compile-clean in isolation. */
#include "common.h"
/* localdecomp:start func_L01_0036DEB0 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_0036DEB0;
void func_L01_0036DEB0(u8 *self)
{
    extern void func_L01_0040E020(u8 *);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_004669B0(void *, f32, f32, f32, s32, void *, u32, f32, s32);
    V_0036DEB0 pos,offset,velocity;
    s32 i,angle,type;
    s32 j;
    f32 life;
    if (!self[0xBC]) return;
    func_L01_0040E020(self+0xBC);
    func_0038CE20(&pos,self+0xD0,0.1f);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(pos) : "m"(pos), "m"(*(V_0036DEB0 *)(self+0x10)) : "vf1","vf2");
    func_0038CE20(&offset,self+0xC0,0.275f);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(pos) : "m"(pos), "m"(offset) : "vf1","vf2");
    func_0038CE20(&velocity,self+0xD0,0.12000000476837158f);
    for (j=3;j>=0;j--) {
        u8 *p;
        angle=func_00382468(16);
        if (func_00382468(2)) angle=-angle;
        p=func_L01_004669B0(&pos,0.04f,1.0f,0.9f,angle,&velocity,0x7F204080,84000.0f,0);
        if (p) {
            u8 *d=p+0x20;
            *(u16 *)(p+0xA)=7;
            p[9]=((*(s16 *)(self+0x32)>>5)<<4)+4;
            *(s32 *)(d+4)=2;
            d[0xA]=127;
            d[0xB]=p[0xA];
        }
    }
    angle=16;
    life=15750.0009765625f;
    type=2;
    for(i=2;i>=0;i--) {
        u8 *p=func_L01_004669B0(&pos,0.02f,1.0f,1.0f,angle,&velocity,0x7FFFFFFF,life,0);
        if(p) {
            u8 *d;
            *(u16 *)(p+0xA)=type;
            d=p+0x20;
            p[9]=((*(s16 *)(self+0x32)>>5)<<4)+4;
            p[8]=func_00382468(255);
            *(s32 *)(d+4)=2;
            d[0xA]=127;
            d[0xB]=p[0xA];
        }
        angle=-angle;
        type<<=1;
        life-=3150.0f;
    }
}
/* localdecomp:end func_L01_0036DEB0 */
