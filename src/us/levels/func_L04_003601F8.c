#include "common.h"
/* localdecomp:start func_L04_003601F8 */
typedef int Quad __attribute__((mode(TI)));
typedef struct {
    u8 pad000[0x30];
    f32 f030;
    s16 f034;
    u8 pad036[0x2];
    u8 f038;
    u8 f039;
    u8 pad03A[0x4];
    u8 f03E;
    u8 f03F;
    f32 f040;
    u8 pad044[0x14];
    u8 f058;
    u8 pad059[0x1];
    u8 f05A;
    u8 pad05B[0x3];
    u8 f05E;
    u8 f05F;
    u8 pad060[0x10];
    f32 f070;
    f32 f074;
    f32 f078;
    f32 f07C;
    f32 f080;
    u8 pad084[0x18];
    f32 f09C;
    f32 f0A0;
    u8 pad0A4[0x4];
    s32 f0A8;
    u8 pad0AC[0x10];
    void *f0BC;
    u8 pad0C0[0xB0];
    u8 f170;
    u8 f171;
    u8 f172;
    u8 pad173[0x3];
    u8 f176;
    u8 pad177[0x5];
    f32 f17C;
    f32 f180;
    f32 f184;
    f32 f188;
    f32 f18C;
    f32 f190;
    f32 f194;
    u8 pad198[0x4];
    f32 f19C;
    f32 f1A0;
    u8 pad1A4[0x4];
    u8 f1A8;
    u8 f1A9;
    s16 f1AA;
    u8 pad1AC[0x20];
    u8 f1CC;
    u8 f1CD;
    u8 f1CE;
    u8 f1CF;
    u8 pad1D0[0x7];
    u8 f1D7;
    u8 f1D8;
    u8 f1D9;
    u8 f1DA;
    u8 f1DB;
    s32 f1DC;
    u8 pad1E0[0x30];
    f32 f210;
    u8 pad214[0x2C];
    u8 *f240;
    u8 pad244[0xC];
    s32 f250;
    u8 pad254[0xA];
    u8 f25E;
    u8 f25F;
    u8 pad260[0x90];
    s32 f2F0;
    s16 f2F4;
    u8 pad2F6[0x2];
    s32 f2F8;
    u8 *f2FC;
    s32 f300;
    s32 f304;
    u8 pad308[0x4];
    s32 f30C;
    long f310;
    s32 f318;
    u8 pad31C[0x4];
    Quad f320;
    Quad f330;
    u8 pad340[0x20];
    s32 f360;
    s32 f364;
    u8 pad368[0x4];
    f32 f36C;
    u8 pad370[0x4];
    s32 f374;
    u8 pad378[0x8];
    s32 f380;
    u8 pad384[0xC];
    Quad f390;
    u8 pad3A0[0xF0];
    Quad f490;
    s32 f4A0;
    s32 f4A4;
    u8 pad4A8[0x8];
    u8 *objects[8];
    u8 pad4D0[0x8];
    s32 f4D8;
    s32 f4DC;
    s32 f4E0;
    s32 f4E4;
    u8 pad4E8[0x8];
    s32 f4F0;
    u8 pad4F4[0x18];
    s32 f50C;
} State;
extern s32 D_001DD708_sda,D_001D545C,D_001D545C_sda_003601F8;
extern u8 *D_L04_001DFE1C,*D_L04_001DFE20,*D_001DFF00_sda;
extern Quad D_L04_001E9620;
extern void func_L01_00442F20(void *,s32,s32),func_L01_004A6DF8(void *,s32);
extern s32 func_0037E1D8(s32);
extern void func_00388830(void *,void *,f32);
extern void func_L01_00458A70(void *,f32,f32,f32,f32);
extern u8 *func_003BCFB0(s32,s32);
extern void func_L01_00452E70(void *,void *);
extern void **func_L01_00438468(s32,s32);
extern void func_003BE4F0(void *,s32,s32,s32),func_003BD360(void *),func_L01_00441FB8(void *,s32,s32),func_L04_00361DE8(void *);
extern s32 func_003CE740(void *,void *,s32,void *,void *);
__asm__(".extern D_001DD708_sda, 4");
__asm__(".extern D_001D545C_sda_003601F8, 4");
__asm__(".extern D_001DFF00_sda, 4");
s32 func_L04_003601F8(u8 *m) {
    Quad a,b;
    s32 count=0;
    State *p=*(State **)(m+0x68);
    u8 *q,*r;
    void **iface;
    s32 i;
    Quad *basis;
    u8 **objects;
    D_001DD708_sda=0;
    p->f50C=0;
    if(p->f4E4) p->f4A4=1;
    p->f4D8=0;
    objects=p->objects;
    p->f03F=0;
    basis=&p->f390;
    i=7;
    while(i>=0) objects[i--]=0;
    if(*(s16 *)(m+0xAA)==0x1BA2) {
        p->f364=0x1BA2;func_L01_00442F20(m,0x1BA2,0x16E5);
    } else p->f364=0x16E5;
    for(q=D_L04_001DFE1C;q<D_L04_001DFE20;q+=256) {
        if(*(s16 *)(q+0xAA)==0x1BAF) {
            objects[count]=q;
            *(s32 *)(q+0x98)=0;
            *(u16 *)(q+0x34)=(*(u16 *)(q+0x34)|0x41)&0xEFFF;
            count++;func_L01_004A6DF8(q,1);
            if(count>=8) break;
        }
    }
    if((func_0037E1D8(2) || p->f4F0) && p->f4F0!=-1) *(u16 *)(m+0x34)|=0x8000;
    *(f32 *)(m+0x2C)=*(f32 *)(*(u8 **)(m+0x24)+0x24);
    p->f490=*(Quad *)(m+0x10);
    if(p->f304!=-1) {
        u8 *q=D_001DFF00_sda;
        q+=p->f304<<7;
        p->f320=*(Quad *)(q+0x30);
        func_00388830((u8 *)p+0x330,q+0x10,1);
        p->f36C=*(f32 *)(q+0x78);
    } else {
        p->f320=*(Quad *)(m+0x10);
        p->f330=*(Quad *)(m+0xD0);
        p->f36C=*(f32 *)(m+0xF8);
    }
    if(p->f30C!=-1) p->f318=1;
    if(p->f4E4) p->f318=1;
    p->f170=25;p->f1A8=5;p->f171=15;p->f1D8=0;p->f1DB=20;p->f172=17;p->f1CE=6;p->f1CF=12;p->f176=18;
    p->f1CC=0;p->f1CD=0;p->f1D9=0;p->f1DA=0;p->f1D7=1;p->f1A9=1;
    p->f17C=0.25f;p->f180=0.0166666675f;p->f184=0.0069444445f;
    p->f188=0.00972222257406f;p->f18C=0.000555555569f;p->f190=2.5f;
    p->f194=0.75f;p->f19C=0.35f;
    if(D_001D545C==12) p->f1AA=0x280B;
    p->f1A0=*(f32 *)(m+0x18)-10;
    if(p->f250) p->f210=1;
    if(D_001D545C==12) p->f210=0.5f;
    p->f1DC=p->f4DC;
    if(D_001D545C==13) p->f1A0=*(f32 *)(m+0x18)-30;
    p->f0BC=basis;
    p->f070=0.7f;p->f074=0.3f;p->f078=1;p->f07C=2;
    p->f080=1.48352980614f;p->f0A0=0.349065840244f;p->f09C=0.00555555569f;
    func_L01_00458A70(m,0.00444444455f,0.100000009f,0.00698131741956f,0.209439530969f);
    p->f058=20;p->f05A=14;
    if(p->f4E4) {
        p->f078=0.7f;p->f07C=0.7f;p->f0A8|=4;
        *(u16 *)(m+0x34)|=0x100;p->f080=12.566371f;
        p->f318=1;p->f0A8|=1;
    }
    if(!p->f034) {p->f034=20;p->f030=20;}
    p->f040=1.2f;p->f038=1;p->f039=1;
    if(!p->f4E0) {
        u8 *q=func_003BCFB0(0x194E,128);p->f2FC=q;
        if(q) {
            func_L01_00452E70(q,m);
            *(u16 *)(p->f2FC+0x32)=*(u16 *)(m+0x32);
            p->f240=p->f2FC;
        }
    }
    p->f03E=1;p->f05E=0;p->f05F=0;p->f2F0=0;p->f2F4=0;
    p->f2F8=0;p->f360=0;
    if(p->f250>0) {
        iface=func_L01_00438468(0x19E1,108);p->f250=-1;
        if(m[0x43]) func_003BE4F0(m,0,0,0);
        p->f25E=28;p->f25F=9;((void (*)(void *))iface[0])(m);
        if(p->f2FC) {
            func_003BD360(p->f2FC);p->f2FC=0;p->f240=0;
        }
        return 0;
    }
    if(p->f374) {
        if(p->f380) p->f320=*(Quad *)(m+0x10);
        func_L01_00441FB8(m,26,7);
        *(s32 *)(m+0x98)=0;*(u16 *)(m+0x34)=(*(u16 *)(m+0x34)|0x41)&0xEFFF;
        func_L01_004A6DF8(m,1);
        if(p->f2FC) {
            *(u16 *)(p->f2FC+0x34)|=0x41;
            *(u16 *)(p->f2FC+0x34)&=0xEFFF;
            *(s32 *)(p->f2FC+0x98)=0;
            func_L01_004A6DF8(p->f2FC,1);
        }
    } else if(p->f4E0) func_L04_00361DE8(m);
    else {
        func_L01_00441FB8(m,1,1);
        if(m[0x43]) func_003BE4F0(m,0,0,0);
        if(p->f4A0 && m[0x43]!=4) func_003BE4F0(m,4,0,0);
        if(p->f310!=-1) func_L01_00441FB8(m,5,6);
        if(p->f300!=-1) func_L01_00441FB8(m,2,-1);
        else if(!p->f318) func_L01_00441FB8(m,4,-1);
    }
    if(D_001D545C==16 && p->f4E4) {
        func_00388830(&a,m+0xE0,2);func_00388830(&a,m+0xE0,-1);
        if(func_003CE740(&a,&b,0,m,0)) *(Quad *)(m+0x10)=D_L04_001E9620;
    }
    return 1;
}
/* localdecomp:end func_L04_003601F8 */
