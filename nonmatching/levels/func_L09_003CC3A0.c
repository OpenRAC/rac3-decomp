/* NTSC-U draft (2026-11-14, Codex worker): C of func_L09_003CA908, the NTSC-U twin of func_L09_003CC3A0, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 2 words differ with its file's flags.
 */
#include "common.h"
/* localdecomp:start func_L09_003CA908 */
typedef int V4 __attribute__((mode(TI)));
extern s32 func_L01_00448E90(void *),func_L01_00452EC8(void *),func_L01_00452EF0(void *);
extern void func_L01_00441FB8(void *,s32,s32),func_L09_003C52C0(void *),func_L09_00512408(s32,s32);
extern s32 func_003883C8(void *),func_00388398(void *);
extern void func_L01_003EAB30(void *);
extern void func_L09_003CA758(void *,s32,f32,f32,f32,f32,s32,s32);
extern f32 func_0037E250(f32,f32);
extern s32 func_0037E208(s32,s32);
extern void func_L01_0044ED60(void *,s32,void *,f32,f32,f32,f32,f32,s32,s32,f32,f32,f32,s32,s32,s32,s32,s32);
extern void func_L01_0044F1E8(void *,s32,s32),func_0039FE80(s32,s32,void *);
extern s32 func_L01_00417EA0(void);
extern void func_L01_0032FE90(void *,f32,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
extern void func_L09_00403338(void *),func_L09_00317280(void *,s32,s32,s32),func_003BDA38(void *,s32,void *);
extern f32 func_00388A28(f32,f32),func_00388960(f32),func_00388978(f32);
extern void func_L09_0034FFC0(void *,void *,void *,f32,s32);
extern f32 func_L01_00440918(f32,f32),func_00389380(f32,f32),func_00389468(f32,f32);
extern void func_L01_00445758(void *,void *,f32,f32,f32,f32,s32),func_L01_004A6D70(s32,void *);
extern s32 D_001D545C,D_001D545C_sda;
extern u8 D_001BBC40[],D_L09_001D66B0[8];
typedef struct {u8 a[0x1DC];s16 timer;u8 b[0x1802];void *obj;} Hero;
extern Hero D_001A4BE0;
typedef struct {u8 a[0x20];f32 x; s32 b,c,d;} Effect;
extern Effect D_L09_001E2C00;
extern s16 D_001A4DBC[];
extern u8 D_0014275B[];
extern f32 D_001DAA30_sda,D_L09_002F1DD0[];
extern u8 *D_L09_001E011C;

__asm__(".extern D_001D545C_sda, 4");
__asm__(".extern D_001DAA30_sda, 4");
__asm__(".extern D_001A4BE0, 16");
__asm__(".extern D_L09_001E2C00, 16");
void func_L09_003CA908(u8 *m) {
    u8 pos[16] __attribute__((aligned(16)));
    u8 vel[16] __attribute__((aligned(16)));
    u8 *p;
    s32 active;
    f32 x,t,y;
    if (!func_L01_00448E90(m+0x10)) return;
    active=1;
    p=*(u8 **)(m+0x68);
    switch(m[0x20]) {
    case 0:
        m[0x30]=255;
        if (!func_L01_00452EC8(m)) {
            if (D_001BBC40[m[0xB0]+(D_001D545C<<4)]&0x80) {
                *(u16 *)(m+0x34)|=0x41; func_L01_00441FB8(m,6,-1);
            } else func_L01_00441FB8(m,1,-1);
        } else *(f32 *)(p+0x10)=*(f32 *)(m+0xF8);
        return;
    case 2:
        if(func_L01_00452EC8(m)) {
            *(s16 *)(p+8)=60;
            if(D_001A4BE0.obj) func_L09_003C52C0(D_001A4BE0.obj);
            D_001A4BE0.timer=60; func_L09_00512408(116,1);
        }
        if(func_003883C8(p+8)) { func_L01_003EAB30(*(void **)p); func_L01_00441FB8(m,3,-1); }
        break;
    case 3: {
        f32 y;
        s32 n;
        if(func_L01_00452EC8(m)) { *(s16 *)(p+8)=120;D_001A4DBC[0]=120; }
        if(*(s16 *)(p+8)%20==0) func_L09_003CA758(m,10,7,2,4,1,128,2);
        if(func_003883C8(p+8)) {
            D_L09_001E2C00.c=45;
            D_L09_001E2C00.x=0.8f;
            D_L09_001E2C00.d=0;
            *(u16 *)(m+0x34)|=0x41; *(s32 *)(m+0x98)=0;
            y=func_0037E250(10,20);
            n=func_0037E208(90,150);
            func_L01_0044ED60(m,0x1FFF,D_L09_001D66B0,2,3,5,7,6,255,n,y,1,1,0,0,35,0,3);
            func_L01_0044F1E8(m,0x1EF4,0);
            func_0039FE80(0,16,m);func_0039FE80(3,16,m);
            *(s16 *)(p+8)=130;D_001A4DBC[0]=180;m[0xBC]=0;
            *(V4 *)pos=*(V4 *)(m+0x10);*(f32 *)(pos+8)+=7;
            if(func_L01_00417EA0()) {
                s32 index=D_001D545C_sda;
                if(index!=7 || !D_0014275B[0]) t=D_L09_002F1DD0[index]*30;
                else t=D_001DAA30_sda*30;
            } else t=30;
            func_L01_0032FE90(pos,8,0,30,20,20,20,15,4,0,t,15,0,1,1,1,0,0,0x1010000,0,0x388EF7,0x63F7,0x407FFF,0x20FF,0x8FFF,0x3064FF,0x7F60A0FF,0x280000FF,0x3064FF,0);
            active=0;func_L01_00441FB8(m,4,-1);
        }
        break;
    }
    case 4:
        if(m[0xBC]==0) {
            if(*(s16 *)(p+8)%3==0) func_L09_003CA758(m,10,10,4,4,1,128,2);
            if(func_003883C8(p+8)) { *(s16 *)(p+8)=50;m[0xBC]=1; }
        } else if(m[0xBC]==1) { if(func_003883C8(p+8)) func_L01_00441FB8(m,5,-1); }
        active=0;break;
    case 5:
        D_001A4DBC[0]=30;func_L09_00512408(0,1);
        if(*(s32 *)(p+4)!=-1) {
            func_L09_00403338(*(void **)p);
            func_L09_00317280(D_L09_001E011C+(*(s32 *)(p+4)<<8),*(s32 *)(p+12),m[0xB0],*(s32 *)(p+0x20));
        }
        active=0;func_L01_00441FB8(m,6,-1);break;
    case 6: *(u16 *)(m+0x34)|=2;active=0;break;
    }
    if(active) {
        if(func_003883C8(p+10)) {
            f32 y,x,z;
            *(s16 *)(p+10)=func_0037E208(45,80); func_003BDA38(m,0,pos);
            x=func_00388960(func_00388A28(*(f32 *)pos-*(f32 *)(m+16),*(f32 *)(pos+4)-*(f32 *)(m+20)));
            x*=func_0037E250(62,66)*0.0166666675f;
            *(f32 *)vel=x;
            z=func_00388978(func_00388A28(*(f32 *)pos-*(f32 *)(m+16),*(f32 *)(pos+4)-*(f32 *)(m+20)));
            z*=func_0037E250(62,66)*0.0166666675f;
            *(f32 *)(vel+4)=z;
            *(s32 *)(vel+8)=0;func_0039FE80(1,0,m);func_L09_0034FFC0(m,vel,pos,0,0);
        }
        if(func_00388398(p+0x1C)) {
            *(s32 *)(p+0x1C)=(s32)(func_0037E208(5,10)*60.0f);
            *(f32 *)(p+0x14)=func_00389380(*(f32 *)(p+0x10),func_L01_00440918(10,40)*0.0174532924f);
        }
        func_L01_00445758(m+0xF8,p+0x18,*(f32 *)(p+0x14),0.000277777785f,0.000277777785f,0.0833333358f,0);
        if(func_00389468(*(f32 *)(m+0xF8),*(f32 *)(p+0x14))>0.0349065848f) {
            if(func_L01_00452EF0(m)) func_0039FE80(2,4,m);
        } else {m[0xBE]&=0xFD;func_L01_004A6D70(2,m);}
    } else func_L01_004A6D70(2,m);
}
/* localdecomp:end func_L09_003CA908 */
