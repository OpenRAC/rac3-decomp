#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L31_0034B368 */
extern u8 *func_L01_00444358(void *,s32,s32);
extern void func_L01_004479A8(void *,void *);
extern s32 func_L01_004A72A8(s32,s32,void *,s32);
extern void func_003BF4F8(void *,void *);
extern void func_L01_00372988(void *,void *);
extern void func_003BE4F0(void *,s32,s32,s32);
extern void func_003BDA38(void *,s32,void *);
extern s32 func_L30_0034C9F8_0034B368(void *,f32);
extern f32 func_003887C8(void *,void *);
extern void func_L01_00441FB8(void *,s32,s32);
extern s32 func_00388398(void *);
extern void func_00388830(void *,void *,f32);
extern void func_L30_0034BC88(void *,void *,s32,s32,void *,s32,f32,f32);
extern void func_L31_00346DD8(void *,void *,void *,f32,f32,f32,f32,f32,f32,f32,s32);
extern void func_00388BD0(void *,void *);
extern void func_L31_0040FFB0(void *);
extern s32 D_001DD298_sda_0034B368;
extern s32 D_001DD1F0_sda;
extern f32 D_001DD254_sda_0034B368;
extern f32 D_001DD2DC_sda;
__asm__(".extern D_001DD298_sda_0034B368, 4");
__asm__(".extern D_001DD1F0_sda, 4");
__asm__(".extern D_001DD254_sda_0034B368, 4");
__asm__(".extern D_001DD2DC_sda, 4");
extern vu0_v4 D_001A4C60[];
extern f32 D_001E1340_sda;
extern f32 D_L31_001E1344;
extern f32 D_L31_001E1348;
extern f32 D_001E1570_sda;
extern f32 D_001E1574_sda;
extern f32 D_001E1578_sda;
extern f32 D_L31_001E157C;
extern f32 D_001E1580_sda;
extern f32 D_L31_001E1584;
void func_L31_0034B368(u8 *m) {
    vu0_v4 p0,p10,dir,p30;
    u8 *v=*(u8 **)(m+0x68);
    u8 *hit=func_L01_00444358(m,0x10000,0);
    s32 i;
    func_L01_004479A8(m,v+0x70);
    if(hit) {
        if(*(f32 *)(hit+0x2C)>0.0f && m[0x20]!=0x42 && *(u8 **)(hit+0x20)) {
            u8 *owner=*(u8 **)(hit+0x20);
            if((*(s16 *)(owner+0xAA)==0x1363 || *(s16 *)(owner+0xAA)==0x1EF9 || *(s16 *)(owner+0xAA)==0x15C6) && !*(s32 *)(v+0xD8)) {
                *(f32 *)(v+0x30)-=*(f32 *)(hit+0x2C);
                if(!(*(f32 *)(v+0x30)<=0.0f)) {
                    u8 *attacker=*(u8 **)(hit+0x20);
                    if(!attacker) attacker=m;
                    func_L01_004A72A8(2,0,attacker,0x165E);
                    v[0x77]=255;
                    func_003BF4F8(m,v+0x70);
                    *(s32 *)(v+0xD8)=D_001DD298_sda_0034B368;
                    func_L01_00372988(m,hit);
                    if(m[0x43]!=1) func_003BE4F0(m,1,0,D_001DD1F0_sda);
                }
            }
        }
        m[0xA8]=255;
    }
    func_003BDA38(m,0,&p0);
    if(func_L30_0034C9F8_0034B368(&p0,1.5f)) *(s32 *)(v+0x11C)=1;
    else {
        if(*(s32 *)(v+0x11C) && func_003887C8(&p0,D_001A4C60)<30.0f)
            func_L01_004A72A8(6,0,*(void **)((u8 *)D_001A4C60+0x2540),0x165E);
        *(s32 *)(v+0x11C)=0;
    }
    func_003BDA38(m,30,&p10);
    if(m[0x20]!=0x42 && m[0x20]!=4 && m[0x20]!=254 && m[0x20]!=253 && *(f32 *)(v+0x30)<=0.0f) {
        if(func_L30_0034C9F8_0034B368(&p0,1.5f) && func_L30_0034C9F8_0034B368(&p10,1.5f))
            func_L01_00441FB8(m,4,-1);
    }
    func_00388398(v+0xD8);
    func_00388398(v+0x110);
    if(m[0x20]!=0x42 && m[0x20]!=4 && m[0x20]!=1 && m[0x20]!=5 && m[0x20]!=6 && m[0x20]!=253 && m[0x20]!=254 && !*(s32 *)(v+0xD8)) {
        for(i=0;i<31;i++) {
            func_003BDA38(m,i,&p30);
            vec_sub_ba(&dir,D_001A4C60,&p30);
            func_00388830(&dir,&dir,1.0f);
            func_L30_0034BC88(m,&dir,1,-1,&p30,0,(f32)v[0x44],D_001DD254_sda_0034B368 * *(f32 *)(m+0x2C) / *(f32 *)(*(u8 **)(m+0x24)+0x24));
        }
    }
    if(*(u8 **)(v+0x150)) {
        u8 *other=*(u8 **)(v+0x150);
        if((u8)(other[0x20]+3)<2) *(u8 **)(v+0x150)=0;
        else func_L31_00346DD8(other,other+0x10,v+0x140,-0.009499999694526196f,0.5f,0.07000000029802322f,0.05000000074505806f,0.05000000074505806f,0.07999999821186066f,0.0f,0);
    }
    if(m[0x60]&2) {
        if(m[0x20]==4 || m[0x20]==0x42) {
            if(m[0x43]!=1) func_003BE4F0(m,1,0,D_001DD1F0_sda);
        } else if(m[0x43]) func_003BE4F0(m,0,0,D_001DD1F0_sda);
    }
    if(!*(s32 *)(v+0x154)) {
        if(m[0x20]!=0x42 && m[0x20]!=4 && m[0x20]!=0 && m[0x20]!=5 && m[0x20]!=6) {
            s32 third=*(s16 *)(v+0x34)/3;
            f32 two=(f32)*(s16 *)(v+0x34);
            f32 one=(f32)third;
            f32 health=*(f32 *)(v+0x30);
            two-=one;
            two-=one;
            D_001E1574_sda=one;
            D_L31_001E157C=one;
            D_L31_001E1584=two;
            D_001E1570_sda=health-one-two;
            if(D_001E1570_sda<0.0f) D_001E1570_sda=0.0f;
            D_001E1578_sda=health-two;
            if(one<D_001E1578_sda) D_001E1578_sda=one;
            else if(D_001E1578_sda<0.0f) D_001E1578_sda=0.0f;
            D_001E1580_sda=*(f32 *)(v+0x30);
            if(D_L31_001E1584<D_001E1580_sda) D_001E1580_sda=D_L31_001E1584;
            else if(D_001E1580_sda<0.0f) D_001E1580_sda=0.0f;
        } else if(!*(s32 *)(v+0x154)) D_001E1574_sda=0.0f;
    }
    {
    f32 alpha=D_001DD2DC_sda*1024.0f;
    *(f32 *)(m+0)=D_001E1340_sda*1024.0f;
    *(f32 *)(m+4)=D_L31_001E1344*1024.0f;
    *(f32 *)(m+8)=D_L31_001E1348*1024.0f;
    *(f32 *)(m+0xC)=alpha;
    }
    func_00388BD0(m+0xC0,m+0xF0);
    func_L31_0040FFB0(m);
}
/* localdecomp:end func_L31_0034B368 */
