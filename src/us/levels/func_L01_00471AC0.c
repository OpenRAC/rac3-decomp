#include "common.h"

/* NTSC-U counterpart of func_L01_00475278 (src/levels/shared/L01_004729D8.c) */
#include "vu0.h"
extern u8 func_0037E208(s32, s32);
extern s32 func_003883C8(void *p);
extern s32 func_003883C8(void *p);
#include "vu0.h"

/* localdecomp:start func_L01_00471AC0 */
typedef int Q_00475278 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00475278;
extern u8 D_L01_001D7FC0_00471AC0;
extern s32 D_L01_001D7FBC_00471AC0;
extern s32 D_L01_001D7FB4_00471AC0;
extern s32 D_L01_001D7FB8_00471AC0;
extern f32 D_L01_001D7FAC_00471AC0;
extern f32 D_L01_001D7FB0_00471AC0;
extern f32 D_L01_001D7FA8_00471AC0;
#include "structs/hero.h"
extern struct Hero D_001A4BE0;

extern u8 *D_L01_001EEB00[];
extern u8 D_L01_001D66B0_00471AC0[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D7FB4_00471AC0, 4");
__asm__(".extern D_L01_001D7FB8_00471AC0, 4");
__asm__(".extern D_L01_001D7FAC_00471AC0, 4");
__asm__(".extern D_L01_001D7FB0_00471AC0, 4");
__asm__(".extern D_L01_001D7FA8_00471AC0, 4");
void func_L01_00471AC0(u8 *p) {
    extern s32 func_003883C8(void *);
    extern void func_003C7CE0(u8 *);
    extern s32 func_0037E1D8(s32);
    extern u8 func_0037E208(s32,s32);
    extern f32 func_0037E250(f32,f32);
    extern f32 func_00388A28(f32,f32);
    extern f32 func_00389380(f32,f32);
    extern f32 func_003887A0(void *);
    extern void func_003BF6A8(void *,f32);
    extern void func_0037E4B8(void *,f32,f32,f32);
    extern u8 *func_L01_00471970(s32,void *,void *,s32,f32,s32,s32,s32,s32,f32,f32);
    extern s32 func_003CF790(void *,s32,s32,s32,f32);
    extern void func_L01_00443938(void *,s32,s32,void *,void *,f32);
    extern void func_L01_00452F40(s32,s32);
    u8 *s;
    f32 t, scale, old, limit, speed, angle, a, b, range;
    u32 alpha;
    s32 n;
    u8 **objects, *created;
    V_00475278 pos, vel;
    if (func_003883C8(p+10)) {func_003C7CE0(p);return;}
    s=p+32;
    p[8]+=D_L01_001D7FC0_00471AC0;
    old=*(f32 *)(p+28);
    t=(f32)*(s16 *)(p+10)*old;
    alpha=(u8)(s32)((f32)s[28]*t);
    *(s32 *)(p+4)=(*(s32 *)(p+4)&0xFFFFFF)|(alpha<<24);
    *(f32 *)(p+12)=*(f32 *)(s+24)+(*(f32 *)(s+20)-*(f32 *)(s+24))*t;
    scale=*(f32 *)(p+12)/500000.0f;
    if (0.0f < *(f32 *)(s+12) && *(f32 *)(s+8)<0.0f) {
        f32 delta;
        limit=*(f32 *)(s+12)+scale;
        delta=limit-*(f32 *)(p+24);
        if (*(f32 *)(s+8)*5.0f<delta)
            *(f32 *)(s+8)=delta/5.0f;
        __asm__("lqc2 $vf1, %0
	lqc2 $vf2, %1
	vadd.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
           : "+m"(*(V_00475278 *)(p+16)) : "m"(*(V_00475278 *)(p+32)) : "vf1","vf2");
        if (*(f32 *)(p+24)<limit) *(f32 *)(p+24)=limit;
    } else {
        __asm__("lqc2 $vf1, %0
	lqc2 $vf2, %1
	vadd.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
           : "+m"(*(V_00475278 *)(p+16)) : "m"(*(V_00475278 *)s) : "vf1","vf2");
    }
    if (s[30] && !func_0037E1D8(s[30])) {
        if (!func_0037E1D8(D_L01_001D7FBC_00471AC0)) {
            *(Q_00475278 *)&pos=0;
            pos.z=scale*0.1666666716337204f;
            created=func_L01_00471970(*(s32 *)(s+16),p+16,&pos,((s32)(t*64.0f)<<24)|0x202020,0.0f,40,0,0,1,*(f32 *)(p+12),*(f32 *)(p+12)*0.8f);
            if(created) created[3]=68;
        } else {
            V_00475278 *vp;
            *(Q_00475278 *)&pos=*(Q_00475278 *)(p+16);
            func_003BF6A8(&pos,scale);
            vp=&vel;
            speed=D_L01_001D7FAC_00471AC0*scale;
            angle=func_00388A28(*(f32 *)s,*(f32 *)(s+4));
            a=func_00389380(angle,func_0037E250(-(D_L01_001D7FB0_00471AC0*0.017453292f),D_L01_001D7FB0_00471AC0*0.017453292f));
            b=func_00389380(func_00388A28(func_003887A0(s),*(f32 *)(s+8)),func_0037E250(0.0f,D_L01_001D7FB0_00471AC0*0.017453292f));
            func_0037E4B8(vp,speed,a,b);
            created=func_L01_00471970(*(s32 *)(s+16),&pos,vp,*(s32 *)(p+4),0.0f,func_0037E208(D_L01_001D7FB4_00471AC0,D_L01_001D7FB8_00471AC0),0,0,0,*(f32 *)(p+12),*(f32 *)(p+12)*D_L01_001D7FA8_00471AC0);
            if(created) created[2]=p[2];
        }
    }
    if(s[29] && alpha>=15) {
        n=func_003CF790(p+16,1,*(s32 *)(s+16),0,scale);
        if(n>0) {
            objects=D_L01_001EEB00;
            { s32 count=n;
            do {
                if(*objects==(u8 *)D_001A4BE0.hero_moby) {
                    func_L01_00443938(*objects,*(s32 *)(s+16),1,*objects+16,D_L01_001D66B0_00471AC0,(f32)s[29]);
                    func_L01_00452F40(*(s32 *)(s+16),1);
                }
                --count; ++objects;
            }while(count); }
        }
    }
    *(f32 *)(p+28)=old;
}
/* localdecomp:end func_L01_00471AC0 */
