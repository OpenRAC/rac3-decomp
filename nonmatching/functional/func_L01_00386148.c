/* functional: medium. Signature changed to the file's own prototype (void *points, ... s32 colour) with casts inside; 9 jals identical, instruction multiset same except frame size 0x190 vs 0x170 and constant loads; VU0 blocks hand-merged in inline asm so scheduling differs; packet layout offsets (0x40..0x6C) not independently re-derived beyond the draft */
#include "common.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00386148;
extern V_00386148 D_L01_001E29C0;
void func_L01_00386148(void *pts, s32 unused, s32 texture, s32 count, s32 unused2, s32 colorS, f32 unused3, f32 width, f32 v) {
    V_00386148 *points = (V_00386148 *)pts;
    u32 color = (u32)colorS;
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern void func_003D2DA0(void *, s32, s32);
    u8 packet[0x90];
    V_00386148 cross, scaled, camera, tangent, delta, prev, spare, temp;
    s32 i = 1;
    s32 alpha = color >> 24;
    f32 endv;
    func_003D93B0(packet, texture, 1, 128);
    *(s32 *)(packet+0x50)=0;
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(temp): "m"(*points): "vf1");
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(delta): "m"(D_L01_001E29C0), "m"(temp): "vf1","vf2");
    *(u32 *)(packet+0x4C)=color;
    endv=v+1.0f;
    *(f32 *)(packet+0x60)=endv;
    v += *(f32 *)(packet+0x50);
    *(f32 *)(packet+0x50)=v;
    *(u32 *)(packet+0x48)=color;
    *(u32 *)(packet+0x44)=color;
    *(u32 *)(packet+0x40)=color;
    *(s32 *)(packet+0x54)=0;
    *(f32 *)(packet+0x5C)=1.0f;
    *(s32 *)(packet+0x64)=0;
    *(f32 *)(packet+0x6C)=1.0f;
    *(f32 *)(packet+0x58)=v;
    *(f32 *)(packet+0x68)=endv;
    __asm__("lqc2 $vf2, %3\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tlqc2 $vf1, %4\n\tsqc2 $vf1, %0\n\tsqc2 $vf2, %1" : "=m"(camera), "=m"(tangent): "m"(points[0]), "m"(points[1]), "m"(delta): "vf1","vf2");
    func_0038CE90(&cross,&tangent,&camera);
    func_0038CF68(&scaled,&cross,points->w);
    func_0038CE20((u128_384E68 *)&scaled,(u128_384E68 *)&scaled,width);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %3\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0\n\tlqc2 $vf2, %3\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %1" : "=m"(*(V_00386148 *)packet), "=m"(*(V_00386148 *)(packet+0x10)): "m"(scaled), "m"(*points): "vf1","vf2");
    points++;
    for (; i<count; i++,points++) {
        f32 t;
        s32 a;
        u32 c;
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %3\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0\n\tlqc2 $vf2, %4\n\tlqc2 $vf1, %2\n\tsqc2 $vf2, %1" : "=m"(temp), "=m"(prev): "m"(*points),"m"(D_L01_001E29C0),"m"(points[-1]):"vf1","vf2");
        __asm__("lqc2 $vf2, %2\n\tsqc2 $vf2, %0\n\tlqc2 $vf1, %3\n\tlqc2 $vf2, %4\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %1" : "=m"(camera),"=m"(tangent):"m"(temp),"m"(*points),"m"(prev):"vf1","vf2");
        func_0038CE90(&cross,&tangent,&camera);
        func_0038CF68(&scaled,&cross,points->w);
        func_0038CE20((u128_384E68 *)&scaled,(u128_384E68 *)&scaled,width);
        t=1.0f-(f32)i/(f32)count;
        a=(s32)((f32)alpha*t);
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %3\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0\n\tlqc2 $vf2, %3\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf2, $vf1\n\tsqc2 $vf1, %1" : "=m"(*(V_00386148 *)(packet+0x20)), "=m"(*(V_00386148 *)(packet+0x30)): "m"(scaled), "m"(*points): "vf1","vf2");
        c=func_0038DBD8(0x2020FF,color&0x2F2FAF,t)|(a<<24);
        *(u32 *)(packet+0x48)=c; *(u32 *)(packet+0x4C)=c;
        func_003D2DA0(packet,0,0);
        *(u128_384E68 *)packet=*(u128_384E68 *)(packet+0x20);
        *(u128_384E68 *)(packet+0x10)=*(u128_384E68 *)(packet+0x30);
        *(u32 *)(packet+0x40)=*(u32 *)(packet+0x48);
        *(u32 *)(packet+0x44)=*(u32 *)(packet+0x4C);
    }
}
