/* NTSC-U draft (2026-11-14, Codex worker): C of func_L22_003B4E48, the NTSC-U twin of func_L22_003B6698, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/shared/L22_003B3228.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
/* localdecomp:start func_L22_003B4E48 */
typedef unsigned int Q __attribute__((mode(TI)));
extern int func_0037E1D8(int);
extern float func_L01_00440918(float,float);
extern void func_L01_00458A70(void*,float,float,float,float);
extern void *func_003BCFB0(int,int);
extern void func_L01_00452E70(void*,void*);
extern void func_003BE4F0(void*,int,int,int);
extern void func_L01_00441FB8(void*,int,int);
extern unsigned char D_L22_00236640[];
extern unsigned char D_001BBE90[];
extern int D_001D545C;
int func_L22_003B4E48(unsigned char *m) {
unsigned char *p;
int n, b;
m[0x30]=64;
(*(float *)(m + 0x2c))=(*(float *)((*(unsigned char * *)(m + 0x24)) + 0x24))*1.25f;
p=(*(unsigned char * *)(m + 0x68));
if(func_0037E1D8(2)) (*(unsigned short *)(m + 0x34))|=0x8000;
(*(Q *)(p + 0x4e0))=(*(Q *)(m + 0x10));
(*(Q *)(p + 0x4f0))=(*(Q *)(m + 0x10));
(*(float *)(p + 0x448))=func_L01_00440918(0.0f,20.0f)*0.017453292f;
p[0x170]=17;
(*(int *)(p + 0x390))=120; (*(int *)(p + 0x394))=200;
(*(float *)(p + 0x35c))=2.7925267f; (*(float *)(p + 0x358))=-2.7925267f; (*(float *)(p + 0x354))=1.5707964f;
p[0x1a8]=4;
(*(float *)(p + 0x194))=0.5f; (*(float *)(p + 0x19c))=0.15f;
p[0x1d7]=1; (*(float *)(p + 0x190))=0.5f;
if(func_0037E1D8(2)){p[0x176]=9;p[0x1d3]=17;p[0x1d2]=11;}
else {p[0x1d3]=19;p[0x1d2]=10;p[0x176]=10;}
(*(float *)(p + 0x180))=0.016666668f; (*(float *)(p + 0x184))=0.0069444445f; (*(float *)(p + 0x18c))=0.00055555557f;
p[0x1db]=255;p[0x1a9]=1;(*(float *)(p + 0x188))=0.009722222f;p[0x1da]=4;(*(float *)(p + 0x17c))=0.25f;p[0x1d8]=0;p[0x1d9]=0;
(*(float *)(p + 0x1a0))=(*(float *)(m + 0x18))-10.0f;
(*(float *)(p + 0x7c))=1.0f; (*(float *)(p + 0x70))=0.5f;(*(float *)(p + 0x74))=0.25f;(*(float *)(p + 0x78))=0.65f;(*(float *)(p + 0x80))=1.553343f;
(*(float *)(p + 0xa0))=0.17453292f;(*(float *)(p + 0x9c))=0.0013888889f;(*(float *)(p + 0xa4))=0.3f;
func_L01_00458A70(m,0.0022222223f,0.041666668f,0.0034906585f,0.104719765f);
p[0x58]=20;p[0x5a]=14;
if(!(*(short *)(p + 0x34))){(*(float *)(p + 0x30))=1.0f;(*(unsigned short *)(p + 0x34))=1;}
n=(*(short *)(m + 0xb2));
if(D_L22_00236640[0x464+n]) b=1;
else {b=D_001BBE90[(n>>1)+(D_001D545C<<10)];if(n&1)b>>=4;b=(b&7)?1:3;}
p[0x3e]=b;p[0x39]=1;(*(float *)(p + 0x40))=0.5f;
if(D_001D545C==22){p[0x64]=0;p[0x3f]=0;}
(*(int *)(p + 0x450))=0;(*(int *)(p + 0x4ac))=-1;(*(int *)(p + 0x454))=0;(*(int *)(p + 0x458))=0;(*(int *)(p + 0x45c))=0;(*(int *)(p + 0x490))=0;(*(int *)(p + 0x494))=0;(*(int *)(p + 0x498))=0;(*(int *)(p + 0x49c))=0;(*(int *)(p + 0x4a0))=0;(*(int *)(p + 0x4a4))=0;(*(int *)(p + 0x460))=0;(*(int *)(p + 0x480))=0;(*(int *)(p + 0x484))=0;(*(int *)(p + 0x48c))=0;(*(int *)(p + 0x47c))=0;
n=(*(short *)(m + 0xb2));
if(D_L22_00236640[0x464+n]) (*(int *)(p + 0x4a0))++;
else {b=D_001BBE90[(n>>1)+(D_001D545C<<10)];if(n&1)b>>=4;if(b&7)(*(int *)(p + 0x4a0))++;}
if((*(int *)(p + 0x488))){
(*(unsigned char * *)(p + 0x48c))=func_003BCFB0(0x1a3c,128);
if((*(unsigned char * *)(p + 0x48c))){
func_L01_00452E70((*(unsigned char * *)(p + 0x48c)),m);
((unsigned char*)(*(unsigned char * *)(p + 0x48c)))[0x30]=0;
(*(unsigned short *)((*(unsigned char **)(p+0x48c))+0x32))=(*(unsigned short *)(m + 0x32));
(*(int *)((*(unsigned char **)(p+0x48c))+0x98))=0;
(*(unsigned short *)((*(unsigned char **)(p+0x48c))+0x34))|=2;
}}
func_0037E1D8(10);
if((*(int *)(p + 0x470))!=-1){
func_003BE4F0(m,0,func_0037E1D8(((unsigned char*)(*(unsigned char **)((*(unsigned char **)(m+0x24))+0x48)))[0x10]),0);
func_L01_00441FB8(m,1,0);
}else{
func_003BE4F0(m,0,func_0037E1D8(((unsigned char*)(*(unsigned char **)((*(unsigned char **)(m+0x24))+0x48)))[0x10]),0);
func_L01_00441FB8(m,4,1);
}
return 0;
}
/* localdecomp:end func_L22_003B4E48 */
