/* functional: high. Verified vs PAL asm branch by branch (init, category->0x7C, aim offset, target search, state 29 vs normal, fire gate, D_1E1D34/D_1E1D50 gp-relative aliases, sound-handle p+0x58 cleanup); hero struct offsets checked in hero.h. */
#include "structs/hero.h"
typedef int Q_003739C0 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003739C0;
extern struct Hero D_001A4BE0;
extern u8 D_001425C0[];
extern u8 D_00142A60[];
extern u8 D_L01_002C5600[][240];
extern u8 *D_001D52FC;
extern s32 D_L01_001E1D30;
extern s32 D_L01_001E1D34;
extern s32 D_L01_001E1D50;
extern u8 D_L01_001DDA10[] __attribute__((section(".sdata")));
extern u8 D_L01_001DDA20[] __attribute__((section(".sdata")));
extern V_003739C0 D_L01_001E29E0;
extern u8 D_L01_002B3A40[];
void func_L01_003739C0(u8 *obj)
{
    extern void func_L01_005003D0(s32,s32);
    extern s32 func_0038CAD0(void *);
    extern void func_0038D000(void *,void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern u8 *func_L01_00450BB0(void *,void *,s32,f32,f32,f32,f32,f32);
    extern u8 *func_00382348(void *);
    extern void func_0038CE20(void *,void *,f32);
    extern s32 func_L01_004CB1F0(f32,f32);
    extern void func_L01_003F6F20(s32,void *,s32,s32,s32,s32,s32,f32,f32,f32,f32,f32,f32,f32);
    extern s32 func_L01_005118D0(s32,s32);
    extern void func_L01_004EA7D8(s32);
    extern s32 func_L01_003F2058(void *,s32);
    extern f32 func_003824E0(f32,f32);
    extern void func_003A52A0(s32,s32,void *);
    extern void func_L01_00374790(void *,void *,void *,f32);
    extern void func_L01_00404A10(void (*)(u8 *),void *);
    extern void func_L01_00374630(u8 *);
    extern void func_L01_00373F78(u8 *);
    extern void func_L01_004EAA80(void);
    extern s32 func_L01_005119E0(s32);
    extern void func_L01_003F2278(s32,s32);
    extern s32 func_L01_003F1FC0(s32,s32);
    V_003739C0 pos,delta;
    u8 *p=*(u8 **)(obj+0x68);
    u8 *target,*data;
    u8 category;
    if(obj[0x20]==0) {
        obj[0x30]=255;
        D_L01_001E1D34=0;
        *(s32 *)(p+0x58)=-1;
        obj[0x20]=1;
    }
    if(D_001A4BE0.state==1) func_L01_005003D0(29,1);
    if(D_L01_002C5600[D_001425C0[0x5F]][1]>=2)D_00142A60[0x5F]|=32;
    if(D_001A4BE0.lockon_target)D_001A4BE0.gun_target_now_=D_001A4BE0.lockon_target;
    func_0038CAD0(&D_L01_001E1D30);
    category=D_L01_002C5600[D_001425C0[0x5F]][1];
    if(category==3)*(s16 *)(obj+0x7C)=7;
    if(category==2)*(s16 *)(obj+0x7C)=3;
    else if(category==1)*(s16 *)(obj+0x7C)=1;
    if(D_L01_002C5600[D_001425C0[0x5F]][1]>=4)
        func_0038D000(&pos,D_L01_001DDA10,obj+0xC0);
    else func_0038D000(&pos,D_L01_001DDA20,obj+0xC0);
    __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "+m"(pos) : "m"(*(V_003739C0 *)(obj+16)) : "vf1","vf2");
    *(Q_003739C0 *)(p+0x10)=*(Q_003739C0 *)&pos;
    func_0038CF68(p+0x40,obj+0xD0,-20.0f);
    func_0038CF68(p+0x30,obj+0xD0,-20.0f);
    func_0038CF68(p+0x30,p+0x30,1.0f);
    if(D_001A4BE0.lockon_target)target=D_001A4BE0.gun_target_now_;
    else target=func_L01_00450BB0(p+0x10,p+0x30,1,0.034906585f,0.034906585f,35.0f,0.05235988f,0.05235988f);
    if(target) {
        *(Q_003739C0 *)&delta=*(Q_003739C0 *)(target+16);
        data=func_00382348(target);
        if(data) {
            func_0038CE20(&delta,target+0xE0,*(f32 *)(data+16));
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "+m"(delta) : "m"(*(V_003739C0 *)(target+16)) : "vf1","vf2");
        }
    }
    if(D_001A4BE0.state==29) {
        func_0038CF68(p+0x30,&D_L01_001E29E0,20.0f);
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(*(V_003739C0 *)p) : "m"(*(V_003739C0 *)(p+0x30)), "m"(pos) : "vf1","vf2");
        func_L01_003F6F20(0,obj,func_L01_004CB1F0(1.0f,150.0f),0,33,-1,4,0.8f,0.0f,90.0f,0.5f,0.5f,40.0f,40.0f);
    } else {
        *(s32 *)((u8 *)&D_001A4BE0+0x16D4)=0;
        *(s32 *)((u8 *)&D_001A4BE0+0x16D8)=0;
        func_0038CF68(p+0x30,(u8 *)D_001A4BE0.hero_moby+0xC0,20.0f);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*(V_003739C0 *)p) : "m"(*(V_003739C0 *)(p+0x30)), "m"(pos) : "vf1","vf2");
    }
    if((*(s32 *)(D_001D52FC+0x1A4)&*(s32 *)((u8 *)&D_001A4BE0+0x1210)) ||
       ((*(s32 *)(D_001D52FC+0x1A0)&8) && D_001A4BE0.state==29)) {
        D_L01_001E1D34++;
        *(s32 *)(p+0x54)=17;
        if(D_L01_001E1D30<=0) {
            if(func_L01_005118D0(-1,1)) {
                D_L01_001E1D50=1;
                func_L01_004EA7D8(-1);
                *(s32 *)(p+0x58)=func_L01_003F2058(D_L01_002B3A40,0);
                func_0038CF68(&delta,p+0x30,func_003824E0(60.0f,80.0f)*0.020000001f);
                func_003A52A0(1,0,obj);
                if(*(s32 *)((u8 *)&D_001A4BE0+0x16B0))
                    func_0038CF68(&delta,&D_L01_001E29E0,func_003824E0(60.0f,80.0f)*0.020000001f);
                func_L01_00374790(obj,p+0x10,&delta,0.5f);
                D_L01_001E1D30=25;
                func_L01_00404A10(func_L01_00374630,obj);
                func_L01_00373F78(obj);
            } else if((*(s32 *)(D_001D52FC+0x1A4)&*(s32 *)((u8 *)&D_001A4BE0+0x1210)) || D_L01_001E1D50==1) {
                func_003A52A0(5,0,obj);
                D_L01_001E1D50=0;
            }
        }
    } else {
        func_L01_004EAA80();
        if(*(s32 *)(p+0x54)<=0)D_L01_001E1D34=0;
    }
    if(!(*(s32 *)(D_001D52FC+0x1A0)&*(s32 *)((u8 *)&D_001A4BE0+0x1210)) || !func_L01_005119E0(-1) || !D_001A4BE0.firing) {
        if(*(s32 *)(p+0x58)<0)return;
        func_L01_003F2278(*(s32 *)(p+0x58),0);
        *(s32 *)(p+0x58)=-1;
    }
    if(*(s32 *)(p+0x58)>0 && !func_L01_003F1FC0(*(s32 *)(p+0x58)-1,0))
        *(s32 *)(p+0x58)=-1;
}
