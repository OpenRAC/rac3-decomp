/* functional: high. Written from the retail asm; compiles with file flags (near miss on scheduling only). Uses vsub/vadd.xyz via inline VU0 asm (vec_*_ab stand-ins for vu0.h, which this file's flags can't use). hero struct offsets 0x368/0x6C0/0x25C0/0x25C4/0x25ED checked. */
#include "common.h"
typedef struct { float x,y,z,w; } __attribute__((aligned(16))) V_VH;
#define VOP(NAME,OP) static __inline__ void NAME(void *d, void *a, void *b) { \
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\t" OP " $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*(V_VH *)d) : "m"(*(V_VH *)a), "m"(*(V_VH *)b) : "vf1","vf2"); }
VOP(vec_sub_ab,"vsub.xyz")
VOP(vec_add_ab,"vadd.xyz")
typedef int s128_vh __attribute__((mode(TI)));
static __inline__ void vec_copy(void *d, void *s) { *(s128_vh *)d = *(s128_vh *)s; }
#include "structs/hero.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_0038AD40;
extern struct Hero D_001A4BE0;
extern s32 D_001D6740_sda;
__asm__(".extern D_001D6740_sda,4");
extern u8 *D_001D52FC __attribute__((section(".data")));
extern V_0038AD40 D_L01_001E29E0[];
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
void func_L01_0038AD40(V_0038AD40 *out,V_0038AD40 *start,u8 *target,u8 *source,f32 minimum,f32 maximum,f32 speed,f32 gravity) {
    V_0038AD40 delta,projection,up,targetPos,difference,correction,startProj,targetProj,fall,impulse;
    V_0038AD40 origin,basis[3],quat,axis,look,rotated[3],matrix[3],endpoint;
    f32 reach,angle,offset,denom,time,invtime;
    if(source) {
        vec_copy(&origin,source+0x10);
        vec_copy(&basis[0],source+0xc0);
        vec_copy(&basis[1],source+0xd0);
        vec_copy(&basis[2],source+0xe0);
    } else {
        u8 *heroMoby=(u8 *)D_001A4BE0.hero_moby;
        vec_copy(&origin,heroMoby+16);
        vec_copy(&basis[0],&D_001A4BE0.aim_matrix[0]);
        vec_copy(&basis[1],&D_001A4BE0.aim_matrix[1]);
        vec_copy(&basis[2],&D_001A4BE0.aim_matrix[2]);
    }
    out->x=1.0f;out->y=0;out->z=0;out->w=0;
    { struct Hero *hero=&D_001A4BE0;
    if(*(s16 *)hero->pad_368 && !D_001D6740_sda) {
        func_0038CE20(&up,(u8 *)hero->hero_moby+0xe0,-1.0f);
    } else func_003C5180(&origin,&up,0);
    }
    reach=maximum;
    if(!target) {
        struct Hero *hero=&D_001A4BE0;
        if(hero->state==1) func_L01_005003D0(29,1);
        if((func_003A3BB8(4,0)&*(s32 *)(D_001D52FC+0x1a0)) && !hero->no_firing) {
            func_0038CF68(&look,D_L01_001E29E0,1.0f);
            func_0038CE20(&projection,&up,func_0038CE68(&look,&up));
            vec_sub_ab(&delta,&look,&projection);
            func_0038CF68(&delta,&delta,1.0f);
            func_0038CE90(&axis,&look,&delta);
            angle=func_0038CE68(&look,&delta)*0.5f;
            func_0038CE20(&quat,&axis,func_0038D0B0(angle));
            quat.w=func_0038D098(angle);
            func_0038D810(&quat,matrix);
            func_0038D5F0(rotated,matrix,D_L01_001E29E0);
            offset=-func_0038CE68(&origin,&up);
            func_0038CF68(&endpoint,D_L01_001E29E0,1.0f);
            denom=func_0038CE68(&up,&endpoint);
            if(denom>0.0f) {
                func_0038CE20(&endpoint,&endpoint,(func_0038CE68(&up,D_L01_001E29E0-2)+offset)/denom);
                vec_sub_ab(&endpoint,&D_L01_001E29E0[-2],&endpoint);
                vec_sub_ab(&endpoint,&endpoint,&D_L01_001E29E0[-2]);
                func_0038CE20(&projection,&up,func_0038CE68(&endpoint,&up));
                vec_sub_ab(&delta,&endpoint,&projection);
                reach=func_0038CEA8(&delta);
                if(maximum<reach) reach=maximum;
                else if(reach<minimum) reach=minimum;
            }
            reach=maximum*func_L01_004451A8(reach/maximum);
            func_0038D000(out,out,rotated);
        } else func_0038D000(out,out,basis);
        func_0038CF68(out,out,reach);
        vec_add_ab(&targetPos,out,&origin);
    } else vec_copy(&targetPos,target+16);
    vec_sub_ab(&difference,&targetPos,start);
    func_0038CE20(&projection,&up,func_0038CE68(&difference,&up));
    vec_sub_ab(&delta,&difference,&projection);
    func_0038CF68(out,&delta,speed);
    time=func_0038CEA8(&delta)/speed;
    invtime=1.0f/time;
    func_0038CE20(&startProj,&up,func_0038CE68(start,&up));
    func_0038CE20(&targetProj,&up,func_0038CE68(&targetPos,&up));
    time=time*time;
    func_0038CE20(&fall,&up,(gravity*time)*0.5f);
    vec_sub_ab(&impulse,&startProj,&targetProj);
    vec_add_ab(&impulse,&impulse,&fall);
    func_0038CE20(&impulse,&impulse,-1.0f);
    func_0038CE20(&correction,&impulse,invtime);
    vec_add_ab(out,out,&correction);
}
