/* NTSC-U draft (Codex wave 3): C of func_L03_00396818, the NTSC-U twin of func_L03_00397E90, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 22 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L03_00396818", whose code is not the PAL one).
 * Worker's note: 22 diff; seven checks; inline bit getter/setter, explicit inverted bit, direct flag load and sized globals do not improve; loop constant/register/branch shape plus store scheduling and post-call flag load remain; switch evidence L03-switch-table.txt; best log ...
 */
#include "common.h"

typedef int Q96818 __attribute__((mode(TI)));

/* localdecomp:start func_L03_00396818 */
extern void func_L03_00396E88(void *);
extern void func_L01_0044C1D0(void *, void *);
extern u8 *D_L03_001DFB00;
extern u8 D_001426E8[], D_001A30B0[], D_001A4C60[];
extern int D_L03_002D09F0[];
extern u8 *D_001D52FC;
extern short D_001A4DF2[];
extern unsigned short D_001A801C[], D_001A8538[];
extern int D_001A74A4[];
extern u8 D_001D5534[], D_00142660[], D_001426E0[], D_001426F4[];
extern int func_0039FE80(int, int, void *);
extern void func_0039FB08(int);
extern int func_0037E0F0(void *, int, int);
extern void func_L01_00441FB8(void *, int, int);
extern void func_L03_003977B8(void *, int, int);
extern void func_L03_00397998(void *, int, int);
extern int func_L01_0044F2E8(int,int,int,int,int,int,int);
extern void func_L01_004FC518(int,int);
extern int func_L01_00452EC8(void *);
extern void func_L01_003F15C8(int);
extern void func_L01_003F15F0(int);
extern int func_00388398(void *);
extern void func_L01_00417F60(int,int);
extern float func_003BEC60(float *,void *,float,float,float,float);
extern int func_00399F90(void);
extern void func_L01_00419718(int,int);
static __inline__ int flag96818(u8 *p) {return *p;}
extern void func_L03_00397288(void *);
static __inline__ int above96818(u8 *p,int i) {return *(short *)(p+0x40)<i;}
extern void func_L03_00397400(void *);
extern void func_L03_003976D8(void *);

void func_L03_00396818(u8 *a) {
    u8 *d;
    int i;
    func_L03_00396E88(a);
    d=*(u8 **)(a+0x68);
    func_L01_0044C1D0(a,d);
    *(Q96818 *)(D_L03_001DFB00+(*(int *)(d+0x4D8)<<7)+0x30)=*(Q96818 *)(a+0x10);
    switch(a[0x20]) {
    case 1:
        if(D_001426E8[0]) {
            { int h=*(int *)(d+0x4E8); u8 *p;
            if(h==-1 || ((p=D_001A30B0+(h<<7)), (*(u8 **)(p+0xDC)!=a || p[0xD0]==0)))
                *(int *)(d+0x4E8)=func_0039FE80(1,4,a); }
            func_L01_00441FB8(a,2,-1);
        }
        break;
    case 2:
        func_L03_003977B8(a,0,3);
        break;
    case 3:
        if(func_0037E0F0(D_001A4C60,*(int *)(d+0x4D8),0)) func_L01_00441FB8(a,4,-1);
        break;
    case 4:
        if(!func_0037E0F0(D_001A4C60,*(int *)(d+0x4D8),0)) {
            func_L01_00441FB8(a,3,-1);
            break;
        }
        func_L01_0044F2E8(0,11,0xA26,1,0,0,0);
        if(D_L03_002D09F0[0]==11 && (*(int *)(D_001D52FC+0x1A4)&16)) {
            *(int *)(D_001A4C60+0x2844)=1;
            func_L01_004FC518(0x74,1);
            { int h=*(int *)(d+0x4E8); u8 *p;
            if(h==-1 || ((p=D_001A30B0+(h<<7)), (*(u8 **)(p+0xDC)!=a || p[0xD0]==0)))
                *(int *)(d+0x4E8)=func_0039FE80(1,4,a); }
            func_L01_00441FB8(a,5,-1);
        }
        break;
    case 5:
        func_L03_00397998(a,0,6);
        break;
    case 6:
        if(func_L01_00452EC8(a)) {
            func_L01_003F15C8(0);
            *(int *)(d+0x4E4)=150;
        }
        D_001A4DF2[0]=4;
        if(func_00388398(d+0x4E4) && !D_001A801C[0]) func_L01_00417F60(0xB88,0x2B);
        func_003BEC60((float *)(a+0x14),d+0x4DC,325.0f,0.002222222276f,0.002222222276f,0.2666666806f);
        if(*(float *)(a+0x14)==325.0f) {
            { int h=*(int *)(d+0x4E8); u8 *p;
            if(h!=-1 && ((p=D_001A30B0+(h<<7)), (*(u8 **)(p+0xDC)==a && p[0xD0]))) func_0039FB08(h); }
            *(int *)(d+0x4E8)=-1;
            *(int *)(d+0x4E8)=func_0039FE80(1,4,a);
            func_L01_003F15F0(0);
            func_L01_00441FB8(a,7,-1);
        }
        break;
    case 7:
        func_L03_003977B8(a,1,9);
        break;
    case 9:
        if(func_0037E0F0(D_001A4C60,*(int *)(d+0x4D8),0)) func_L01_00441FB8(a,10,-1);
        break;
    case 10:
        func_L01_0044F2E8(0,11,0xA27,1,0,0,0);
        if(D_L03_002D09F0[0]==11 && (*(int *)(D_001D52FC+0x1A4)&16)) {
            D_001A74A4[0]=1;
            func_L01_004FC518(0x74,1);
            { int h=*(int *)(d+0x4E8); u8 *p;
            if(h==-1 || ((p=D_001A30B0+(h<<7)), (*(u8 **)(p+0xDC)!=a || p[0xD0]==0)))
                *(int *)(d+0x4E8)=func_0039FE80(1,4,a); }
            func_L01_00441FB8(a,11,-1);
        } else if(!func_0037E0F0(D_001A4C60,*(int *)(d+0x4D8),0)) func_L01_00441FB8(a,9,-1);
        break;
    case 11:
        func_L03_00397998(a,1,12);
        break;
    case 12:
        if(func_L01_00452EC8(a)) func_L01_003F15C8(0);
        if(flag96818(D_001D5534) && !D_001A8538[0]) func_L01_00417F60(0xCF1,0x98);
        D_001A4DF2[0]=4;
        func_003BEC60((float *)(a+0x14),d+0x4DC,*(float *)(d+0x4E0),0.002222222276f,0.002222222276f,0.2666666806f);
        if(*(float *)(a+0x14)==*(float *)(d+0x4E0)) {
            for(i=1;i<5;i++) {
                unsigned char enable;
                if((enable=(u32)i<8) && ((D_001426E0[0x3E]>>i)&1) && !((D_001426E0[0x75]>>i)&1) && above96818(D_00142660,i)) {
                    D_001426E0[0x75]|=enable<<i;
                    func_00399F90();
                    func_L01_00417F60(0xC9A,0x5D);
                    switch(i) { case 2: func_L01_00419718(0x15FA,0x131); break; case 3: func_L01_00419718(0x15FB,0x132); break; }
                }
            }
            { int h=*(int *)(d+0x4E8); u8 *p;
            if(h!=-1 && ((p=D_001A30B0+(h<<7)), (*(u8 **)(p+0xDC)==a && p[0xD0]))) func_0039FB08(h); }
            *(int *)(d+0x4E8)=-1;
            *(int *)(d+0x4E8)=func_0039FE80(1,4,a);
            func_L01_00441FB8(a,2,-1);
            func_L01_003F15F0(0);
        }
        break;
    case 13:
        if(D_001426F4[0]) {
            func_L03_00397288(a);
            func_L03_00397400(a);
            func_L03_003976D8(a);
            func_L01_00441FB8(a,9,-1);
        }
        break;
    }
}
/* localdecomp:end func_L03_00396818 */
