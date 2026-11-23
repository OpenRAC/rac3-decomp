/* PAL near miss (haiku-w1): 171 words differ with the file's flags; first difference is the flag test in the !target branch (register of the D_001D52FC field load), then the VU0 sequences interleave ordinary constants and argument moves that the one-block asm form cannot place. Block-scope extern of func_0038CE20 uses the file's void * prototype so the draft compiles in context. */
#include "common.h"
/* localdecomp:start func_L01_0038AD40 */
#include "structs/hero.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_0038AD40;
extern struct Hero D_001A4BE0;
extern s32 D_001D6740_sda;
__asm__(".extern D_001D6740_sda,4");
extern u8 *D_001D52FC __attribute__((section(".data")));
extern V_0038AD40 D_L01_001E29E0[];
void func_L01_0038AD40(V_0038AD40 *out,V_0038AD40 *start,u8 *target,u8 *source,f32 minimum,f32 maximum,f32 speed,f32 gravity) {
    extern void func_0038CE20(void *,void *,f32);
    extern void func_003C5180(void *,void *,s32);
    extern void func_L01_005003D0(s32,s32);
    extern s32 func_003A3BB8(s32,s32);
    extern void func_0038CF68(void *,void *,f32);
    extern f32 func_0038CE68(void *,void *);
    extern void func_0038CE90(void *,void *,void *);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D098(f32);
    extern void func_0038D810(void *,void *);
    extern void func_0038D5F0(void *,void *,void *);
    extern f32 func_0038CEA8(void *);
    extern f32 func_L01_004451A8(f32);
    extern void func_0038D000(void *,void *,void *);
    V_0038AD40 delta,projection,up,targetPos,difference,correction,startProj,targetProj,fall,impulse;
    V_0038AD40 origin,basis[3],quat,axis,look,rotated[3],matrix[3],endpoint;
    f32 reach,angle,offset,denom,time,invtime;
    if(source) {
        *(s128 *)&origin=*(s128 *)(source+0x10);
        *(s128 *)&basis[0]=*(s128 *)(source+0xc0);
        *(s128 *)&basis[1]=*(s128 *)(source+0xd0);
        *(s128 *)&basis[2]=*(s128 *)(source+0xe0);
    } else {
        u8 *heroMoby=(u8 *)D_001A4BE0.hero_moby;
        *(s128 *)&origin=*(s128 *)(heroMoby+16);
        *(s128 *)&basis[0]=*(s128 *)&D_001A4BE0.aim_matrix[0];
        *(s128 *)&basis[1]=*(s128 *)&D_001A4BE0.aim_matrix[1];
        *(s128 *)&basis[2]=*(s128 *)&D_001A4BE0.aim_matrix[2];
    }
    out->x=1.0f;out->y=0;out->z=0;out->w=0;
    { struct Hero *hero=&D_001A4BE0;
    if(*(s16 *)hero->pad_368 && !D_001D6740_sda) {
        func_0038CE20((s128 *)&up,(s128 *)((u8 *)hero->hero_moby+0xe0),-1.0f);
    } else func_003C5180(&origin,&up,0);
    }
    reach=maximum;
    if(!target) {
        struct Hero *hero=&D_001A4BE0;
        if(hero->state==1) func_L01_005003D0(29,1);
        if((func_003A3BB8(4,0)&*(s32 *)(D_001D52FC+0x1a0)) && !hero->no_firing) {
            func_0038CF68(&look,D_L01_001E29E0,1.0f);
            func_0038CE20((s128 *)&projection,(s128 *)&up,func_0038CE68(&look,&up));
            __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(delta) : "m"(look),"m"(projection) : "vf1","vf2");
            func_0038CF68(&delta,&delta,1.0f);
            func_0038CE90(&axis,&look,&delta);
            angle=func_0038CE68(&look,&delta)*0.5f;
            func_0038CE20((s128 *)&quat,(s128 *)&axis,func_0038D0B0(angle));
            quat.w=func_0038D098(angle);
            func_0038D810(&quat,matrix);
            func_0038D5F0(rotated,matrix,D_L01_001E29E0);
            offset=-func_0038CE68(&origin,&up);
            func_0038CF68(&endpoint,D_L01_001E29E0,1.0f);
            denom=func_0038CE68(&up,&endpoint);
            if(denom>0.0f) {
                func_0038CE20((s128 *)&endpoint,(s128 *)&endpoint,(func_0038CE68(&up,D_L01_001E29E0-2)+offset)/denom);
                __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(endpoint) : "m"(D_L01_001E29E0[-2]),"m"(endpoint) : "vf1","vf2");
                __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(endpoint) : "m"(endpoint),"m"(D_L01_001E29E0[-2]) : "vf1","vf2");
                func_0038CE20((s128 *)&projection,(s128 *)&up,func_0038CE68(&endpoint,&up));
                __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(delta) : "m"(endpoint),"m"(projection) : "vf1","vf2");
                reach=func_0038CEA8(&delta);
                if(maximum<reach) reach=maximum;
                else if(reach<minimum) reach=minimum;
            }
            reach=maximum*func_L01_004451A8(reach/maximum);
            func_0038D000(out,out,rotated);
        } else func_0038D000(out,out,basis);
        func_0038CF68(out,out,reach);
        __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(targetPos) : "m"(*out),"m"(origin) : "vf1","vf2");
    } else *(s128 *)&targetPos=*(s128 *)(target+16);
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(difference) : "m"(targetPos),"m"(*start) : "vf1","vf2");
    func_0038CE20((s128 *)&projection,(s128 *)&up,func_0038CE68(&difference,&up));
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(delta) : "m"(difference),"m"(projection) : "vf1","vf2");
    func_0038CF68(out,&delta,speed);
    time=func_0038CEA8(&delta)/speed;
    invtime=1.0f/time;
    func_0038CE20((s128 *)&startProj,(s128 *)&up,func_0038CE68(start,&up));
    func_0038CE20((s128 *)&targetProj,(s128 *)&up,func_0038CE68(&targetPos,&up));
    time=time*time;
    func_0038CE20((s128 *)&fall,(s128 *)&up,(gravity*time)*0.5f);
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(impulse) : "m"(startProj),"m"(targetProj) : "vf1","vf2");
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(impulse) : "m"(impulse),"m"(fall) : "vf1","vf2");
    func_0038CE20((s128 *)&impulse,(s128 *)&impulse,-1.0f);
    func_0038CE20((s128 *)&correction,(s128 *)&impulse,invtime);
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*out) : "m"(*out),"m"(correction) : "vf1","vf2");
}
/* localdecomp:end func_L01_0038AD40 */
