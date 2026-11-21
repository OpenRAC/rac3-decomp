/* functional: low. Near miss with 261 word diffs; not independently re-read against the assembly. */
#include "common.h"
/* localdecomp:start func_L01_003D52A8 */
#include "vu0.h"
extern vu0_v4 D_L01_001D66E0;
void func_L01_003D52A8(u8 *m)
{
    extern f32 func_0038D160(f32,f32);
    extern s32 func_00382498(s32,s32);
    extern void func_0038CE20(f32 *,f32 *,f32);
    extern s32 func_0038CAD0(void *);
    extern f32 func_L01_0044AE78(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_003824E0(f32,f32);
    extern void func_L01_003D57E8(vu0_v4 *);
    extern void func_L01_004450F0(u8 *,int,int);
    extern void func_003C2880(u8 *);
    extern void func_L01_003D5F28(Moby_003D4478 *);
    extern void func_L01_00404808(void (*)(Moby_003D4478 *),u8 *);
    vu0_v4 origin,temp;
    s32 i=0,finished;
    u8 *p=*(u8 **)(m+0x68);
    origin=*(vu0_v4 *)(m+0x10);
    origin.w=*(f32 *)(p+0x3D8)*3.0f;
    finished=0;
    for(;i<p[0x3D2] && i<10;i++) {
        f32 w=*(f32 *)(p+i*0x60+0xC);
        f32 radius=*(f32 *)(p+i*0x60+0x4C);
        f32 fall=*(f32 *)(p+i*0x60+0x1C);
        switch(p[i*0x60+0x54]) {
        case 0: {
            u8 *q=p+i*0x60;
            *(f32 *)(q+0x48)=func_0038D160(*(f32 *)(q+0x10),*(f32 *)(q+0x14));
            *(f32 *)(q+0x44)=3.1415927410125732f;
            q[0x54]=1;
            *(s32 *)(q+0x50)=(func_00382498(10,20)*5+2)/6;
            break;
        }
        case 1: {
            u8 *q=p+i*0x60;
            vec_add_ba(q,q+0x10,q);
            func_0038CE20((f32 *)(q+0x10),(f32 *)(q+0x10),0.9040000438690186f);
            if(func_0038CAD0(q+0x50)) {
                func_0038CE20((f32 *)&temp,(f32 *)(q+0x30),-radius);
                vec_add_ab(q+0x20,&temp,q);
                *(f32 *)(q+0x28)-=radius*0.5f;
                *(f32 *)(q+0x58)=1.5707963705062866f;
                *(f32 *)(q+0x5C)=3.1415927410125732f/(w+w);
                q[0x54]=2;
                *(s32 *)(q+0x50)=1000;
            }
            break;
        }
        case 2: {
            f32 angle,sine,root,height,vertical,linear;
            u8 *q;
            *(f32 *)(p+i*0x60+0x28)-=fall;
            angle=func_L01_0044AE78(*(f32 *)(p+i*0x60+0x5C)*w);
            sine=func_0038D0B0(angle);
            linear=sine*3.0f;
            if(sine>=0.0f) { root=sqrt_asm(sine); height=radius*(root+linear)*0.25f; }
            else { root=-sqrt_asm(-sine); height=radius*(root+linear)*0.25f; }
            q=p+i*0x60;
            vertical=radius*sine*sine*(*(f32 *)(q+0x58)/1.5707963705062866f)*0.5f;
            *(f32 *)(q+0x44)=-(*(f32 *)(q+0x58)*sine+1.5707963705062866f);
            *(f32 *)(q+0x48)=-( *(f32 *)(q+0x58)*func_0038D0B0(func_L01_0044AE78((*(f32 *)(q+0x5C)*w)*2.0f))+1.5707963705062866f);
            if(p[0x3D1]) func_L01_003D57E8((vu0_v4 *)(q+0x20));
            func_0038CE20((f32 *)&temp,(f32 *)&D_L01_001D66E0,vertical);
            vec_add_ab(q,&temp,q+0x20);
            func_0038CE20((f32 *)&temp,(f32 *)(q+0x30),height);
            vec_add_ab(q,&temp,q);
            if(fabs_asm(angle)<0.1f) *(f32 *)(q+0x58)=func_003824E0(30.0f,60.0f)*0.01745329238474369f;
            if(*(f32 *)(q+8)<*(f32 *)(p+0x3D4) || func_0038CAD0(q+0x50)) {
                q[0x54]=3;
                *(s32 *)(q+0x50)=50;
            }
            break;
        }
        case 3: {
            u8 *q=p+i*0x60;
            *(f32 *)(q+0x44)=(*(f32 *)(q+0x44)+1.5707963705062866f)*0.94f-1.5707963705062866f;
            q[0x55]=((f32)*(s32 *)(q+0x50)/50.0f)*127.0f;
            if(func_0038CAD0(q+0x50)) {
                *(s32 *)(q+0x50)=0;
                q[0x54]=4;
            }
            break;
        }
        case 4: finished++; break;
        }
        {
            u8 *q=p+i*0x60;
            *(f32 *)(q+0xC)=w;
            *(f32 *)(q+0x4C)=radius;
            *(f32 *)(q+0x1C)=fall;
            *(f32 *)(q+0x5C)+=1.0f;
        }
    }
    func_L01_004450F0(m,1,-1);
    if(finished==p[0x3D2]) {
        func_L01_004450F0(m,4,-1);
        func_003C2880(m);
    } else if(m[0x20]!=0 && m[0x20]!=4) {
        func_L01_00404808(func_L01_003D5F28,m);
    }
}
/* localdecomp:end func_L01_003D52A8 */
