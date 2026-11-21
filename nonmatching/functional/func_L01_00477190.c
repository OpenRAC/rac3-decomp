/* functional: high. Read block by block against the PAL asm: vertical-component removal against D_001A4EC0 (up vector), segment tests and final height restore match; only VU0 scheduling differs. */
#include "common.h"
typedef int Q_00477190 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00477190;
extern int D_L01_0021F6C0[];
extern V_00477190 D_001A4EC0;
s32 func_L01_00477190(s32 index, Q_00477190 *position, Q_00477190 *output, f32 radius) {
    extern f32 func_0038CE68(void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038CE90(void *,void *,void *);
    extern f32 func_0038CEA8(void *);
    V_00477190 delta, correction, point, edge, direction, cross, temp;
    u8 *path=(u8 *)D_L01_0021F6C0[index];
    s32 hit=0, i, next;
    f32 height, len, projection;
    *(Q_00477190 *)&point=*position;
    height=func_0038CE68(&point,&D_001A4EC0);
    for(i=0;i<*(s32 *)path-1;i=next) {
        u8 *p=path+(i<<4);
        next=i+1;
        if (*(f32 *)(p+0x1c)==0.0f && *(f32 *)(path+(next<<4)+0x1c)==0.0f) continue;
        __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvsub.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(delta) : "m"(point),"m"(*(V_00477190 *)(p+16)):"vf1","vf2");
        __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(edge) : "m"(*(V_00477190 *)(p+16)),"m"(*(V_00477190 *)(p+32)):"vf1","vf2");
        func_0038CF68(&temp,&D_001A4EC0,func_0038CE68(&delta,&D_001A4EC0));
        __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%0\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "+m"(delta) : "m"(temp):"vf1","vf2");
        func_0038CF68(&temp,&D_001A4EC0,func_0038CE68(&edge,&D_001A4EC0));
        __asm__("lqc2 $vf1,%0\n\tlqc2 $vf2,%1\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "+m"(edge) : "m"(temp):"vf1","vf2");
        func_0038CF68(&direction,&edge,1.0f);
        func_0038CE90(&cross,&delta,&direction);
        if(radius<__builtin_fabsf(func_0038CE68(&cross,&D_001A4EC0))) continue;
        len=func_0038CEA8(&edge);
        projection=func_0038CE68(&delta,&direction);
        if(len<projection || projection<0.0f) {
            if(func_0038CEA8(&delta)<radius) {
                func_0038CF68(&correction,&delta,radius);
                hit=1;
            } else continue;
        } else {
            hit=1;
            func_0038CF68(&temp,&direction,projection);
            __asm__("lqc2 $vf1,%2\n\tlqc2 $vf2,%1\n\tvsub.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(correction) : "m"(delta),"m"(temp):"vf1","vf2");
            func_0038CF68(&correction,&correction,radius);
            __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%0\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "+m"(correction) : "m"(temp):"vf1","vf2");
        }
        __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(point) : "m"(correction),"m"(*(V_00477190 *)(p+16)):"vf1","vf2");
    }
    if(hit) {
        func_0038CF68(&edge,&D_001A4EC0,height-func_0038CE68(&point,&D_001A4EC0));
        __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*(V_00477190 *)output) : "m"(point),"m"(edge):"vf1","vf2");
    }
    return hit;
}
