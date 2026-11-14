#include "common.h"
/* localdecomp:start func_L08_0039EEF0 */
typedef int Q __attribute__((mode(TI)));
extern void func_00388BD0(void*,void*);
extern float func_0037E2A8(void);
extern void func_L01_00458A70(void*,float,float,float,float);
extern void func_L01_00441FB8(void*,int,int);
extern void func_003BE4F0(void*,int,int,int);
extern void func_L01_004A6DF8(void*,int);
extern float func_003BE7F0(float,void*,int,int);
extern int D_001D545C_sda_0039EEF0;
__asm__(".extern D_001D545C_sda_0039EEF0, 4");
int func_L08_0039EEF0(unsigned char *m) {
unsigned char *p=*(unsigned char**)(m+0x68);
float f;
*(Q*)(p+0x1a0)=*(Q*)(m+0x10);
if(!*(short*)(m+0xb2)){*(int*)(p+0x1c0)=-1;*(int*)(p+0x1c8)=-1;}
*(int*)(m+0xb8)=0;
*(int*)(m+0xf0)=0;*(int*)(m+0xf4)=0;
func_00388BD0(m+0xc0,m+0xf0);
*(float*)(p+0x1d0)=func_0037E2A8();
*(float*)(p+0x74)=0.25f;*(float*)(p+0x70)=0.4f;*(float*)(p+0x78)=1.25f;*(float*)(p+0x7c)=1.5f;
*(float*)(p+0x80)=1.39626336f;*(float*)(p+0xa0)=0.34906584f;*(float*)(p+0x9c)=0.00272222236f;
func_L01_00458A70(m,0.00444444455f,0.0666666701f,0.00698131742f,0.209439531f);
p[0x58]=20;p[0x5a]=14;
if(!*(short*)(p+0x34)){*(short*)(p+0x34)=1;*(float*)(p+0x30)=1.0f;}
if(!p[0x44]){p[0x44]=3;p[0x45]=3;p[0x46]=3;}
*(float*)(p+0x40)=0.25f;
p[0x39]=1;p[0x3f]=1;p[0x64]=1;p[0x3e]=1;
func_L01_00441FB8(m,3,0);
if(m[0x43]!=1)func_003BE4F0(m,1,0,0);
if((*(int*)(p+0x1c0)!=-1 || *(int*)(p+0x1c8)!=-1) && D_001D545C_sda_0039EEF0!=8) {
func_L01_00441FB8(m,10,4);
*(unsigned short*)(m+0x34)=(*(unsigned short*)(m+0x34)|0x41)&0xefff;
*(int*)(m+0x98)=0;
func_L01_004A6DF8(m,1);
}else if(*(int*)(p+0x1c4)==1){
f=func_003BE7F0(0.5f,m+0x10,0,0);
if(*(float*)(m+0x18)-f>3.0f) f=*(float*)(m+0x18);
*(float*)(m+0x18)=f-1.0f;
*(unsigned short*)(m+0x34)=(*(unsigned short*)(m+0x34)|0x41)&0xefff;
*(int*)(m+0x98)=0;
func_L01_004A6DF8(m,1);
}
return 0;
}
/* localdecomp:end func_L08_0039EEF0 */
