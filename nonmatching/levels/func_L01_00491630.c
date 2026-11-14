/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_0048DE38, the NTSC-U twin of func_L01_00491630, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L01_00491290.c's current line.
 * Worker's note: 180 diff; flags blocker: .lit4 loads for 0.49/1.2/0.035/0.97 vs retail inline lui/ori/mtc1; div nops also differ; no alternative allowed; best log w102/func_L01_0048DE38.01.log
 */
#include "common.h"
/* localdecomp:start func_L01_0048DE38 */
extern int D_001D8E50_sda;
extern int D_L01_001D8E34[];
extern int D_001D8E18_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001D8E18_sda, 8");
extern float D_L01_001DC128[];
extern u8 D_L01_002EB398[];
extern void func_L01_0048E5D8(void);
extern void func_00389920(int);
extern int func_0037DF98(int);
extern int func_00389D18(float,int,int);
extern float func_003BEB48(float,float,float);
extern void func_003B3DB8(int,float,int,int,int,int,int,int,int,int,int,int,int,int,int);
extern void func_003E3A80(int,int,int,float,float,float,float);
extern void func_003E29B8(int,int);
extern void func_003E34A0(int,int,int);
extern void func_L01_0048E2F8(void *);
extern void func_003E2DE0(int,int);
extern int func_003AED40(int);
extern void func_003E31A8(int,int);
extern void func_L01_0048E948(void);
extern void func_L01_0048EC60(void);
extern void func_L01_00512D70(int,int);
extern int func_003E3250(int,int,int);
extern int func_003B46F0(int);
extern int func_L01_00513698(void);
extern void func_L01_00494E68(void *,int);
void func_L01_0048DE38(void) {
 int i,*q;
 int result;
 float x,r;
 float lo=0.0f,hi=0.49f;
 float a=6.0f,b=11.0f;
 D_001D8E50_sda=0;
 for(i=3,q=D_L01_001D8E34;i>=0;i--)*q--=-1;
 func_L01_0048E5D8();
 func_00389920(0);
 x=(float)func_00389D18(1.2f,func_0037DF98(0x107),-1)/D_L01_001DC128[0];
 if(hi<x)x=hi;
 x=(x-lo)/(hi-lo);
 r=func_003BEB48(a,b,x);
 if(b<r)r=b;else if(r<a)r=a;
 func_003B3DB8(0x10,r,0xD000B,0xD0000,0xD0001,0xD0002,0xD0003,0xD0004,0xD0005,0xD0008,func_0037DF98(0x107),0xD0006,0x124,0xD0007,0xCD5);
 func_003E3A80(0xD0009,func_0037DF98(0x1B80),0x8066CCFF,0.035f,0.5f,1.0f,1.0f);
 func_003E29B8(0xD0009,1);
 func_003E3A80(0xD000A,func_0037DF98(0x1B81),0x8066CCFF,0.97f,0.5f,1.0f,1.0f);
 func_003E29B8(0xD000A,1);
 func_003E34A0(0xD000B,0xD0009,0xD000A);
 func_L01_0048E2F8(D_L01_002EB398);
 func_003E2DE0(0x11,0x1C0000);
 func_003E31A8(0x1C0003,func_003AED40(0));
 func_L01_0048E948();
 func_L01_0048EC60();
 func_L01_00512D70(0x1C0003,0);
 func_003E3250(0x1C0003,1,10);
 result=func_003B46F0(func_L01_00513698());
 func_L01_00494E68((void *)result,D_001D8E18_sda[func_L01_00513698()]);
}
/* localdecomp:end func_L01_0048DE38 */
