#include "common.h"
#include "vu0.h"
__asm__(".extern D_L30_001DD44C, 4");
__asm__(".extern D_L30_001DD450, 4");
__asm__(".extern D_L30_001DD454, 4");
__asm__(".extern D_L30_001DD45C_00349F90, 4");
__asm__(".extern D_L30_001DD460_00349F90, 4");
__asm__(".extern D_L30_001DD468, 4");
__asm__(".extern D_L30_001DD46C, 4");
__asm__(".extern D_L30_001DD470, 4");
__asm__(".extern D_L30_001DD474, 4");
__asm__(".extern D_L30_001DD478_00349F90, 4");
__asm__(".extern D_L30_001DD47C_00349F90, 4");
/* localdecomp:start func_L30_00349F90 */
extern float D_L30_001DD45C_00349F90,D_L30_001DD460_00349F90,D_L30_001DD44C,D_L30_001DD474,D_L30_001DD454,D_L30_001DD46C,D_L30_001DD47C_00349F90;
extern int D_L30_001DD470,D_L30_001DD450,D_L30_001DD468,D_L30_001DD478_00349F90;
extern void func_L24_00439040(void *,int,int,int,float,float);
extern int func_L30_0034A450(void *),func_L01_00452EC8(void *),func_00388398(void *);
extern void func_L01_00441FB8(void *,int,int),func_00388BD0(void *,void *),func_00388830(void *,void *,float),func_L30_0034A7E8(void *),func_003BE4F0(void *,int,int,int),func_L30_0034A600(void *),func_L30_0034A698(void *),func_L01_004A6DF8(void *,int);
extern float func_0037E250(float,float);
extern int func_L01_0044AF40(void *,float);
void func_L30_00349F90(u8 *m) {
 u8 *v=*(u8 **)(m+0x68);
 func_L24_00439040(m,-1,0,0,D_L30_001DD45C_00349F90,D_L30_001DD460_00349F90);
 if(func_L30_0034A450(m)) func_L01_00441FB8(m,66,-1);
 *(float *)(m+0x48)=D_L30_001DD44C;
 func_00388BD0(m+0xc0,m+0xf0);
 func_00388830(m+0xd0,m+0xd0,D_L30_001DD474);
 switch(m[0x20]) {
 case 0: func_L30_0034A7E8(m); break;
 case 1: {
  int a,b,c;
  if(func_L01_00452EC8(m)) {
   *(int *)(v+0x190)=D_L30_001DD470;
   if(*(int *)(v+0x194)) {if(m[0x43]!=2) func_003BE4F0(m,2,0,D_L30_001DD450);}
   else if(m[0x43]!=0) func_003BE4F0(m,0,0,D_L30_001DD450);
  }
  func_L30_0034A600(m);
  a=func_00388398(v+0x190)!=0; b=*(short *)(v+0x44)==1;
  if(*(float *)(m+0x10)<*(float *)(v+0x30)) c=fabs_asm(*(float *)(m+0xf8))<D_L30_001DD454;
  else c=fabs_asm(3.141592741f-*(float *)(m+0xf8))<D_L30_001DD454;
  if(a && b && c) func_L01_00441FB8(m,2,-1);
  break;
 }
 case 2:
  if(func_L01_00452EC8(m)) {
   int old=*(int *)(v+0x194), b=*(float *)(v+0x198)<func_0037E250(0.0f,1.0f);
   *(int *)(v+0x194)=b;
   if(b!=old) {
    if(b) {if(m[0x43]!=1) func_003BE4F0(m,1,0,D_L30_001DD450);}
    else if(m[0x43]!=3) func_003BE4F0(m,3,0,D_L30_001DD450);
   } else func_L01_00441FB8(m,3,-1);
  }
  if(m[0x60]&2) func_L01_00441FB8(m,3,-1);
  break;
 case 3:
  if(func_L01_00452EC8(m)) {
   if(*(int *)(v+0x194)) {if(m[0x43]!=8) func_003BE4F0(m,8,0,D_L30_001DD450);}
   else if(m[0x43]!=4) func_003BE4F0(m,4,0,D_L30_001DD450);
  }
  if(m[0x60]&2) func_L01_00441FB8(m,4,-1);
  break;
 case 4:
  if(func_L01_00452EC8(m)) {
   if(*(int *)(v+0x194)) {if(m[0x43]!=9) func_003BE4F0(m,9,0,D_L30_001DD450); *(int *)(v+0x190)=D_L30_001DD468;}
   else {if(m[0x43]!=5) func_003BE4F0(m,5,0,D_L30_001DD450); *(int *)(v+0x190)=D_L30_001DD478_00349F90;}
  }
  if(func_00388398(v+0x190)) func_L01_00441FB8(m,5,-1);
  break;
 case 5:
  if(func_L01_00452EC8(m)) {
   if(*(int *)(v+0x194)) {if(m[0x43]!=10) func_003BE4F0(m,10,0,D_L30_001DD450);}
   else if(m[0x43]!=6) func_003BE4F0(m,6,0,D_L30_001DD450);
  }
  if(func_L01_0044AF40(m,*(int *)(v+0x194)?D_L30_001DD46C:D_L30_001DD47C_00349F90)) func_L30_0034A698(m);
  if(m[0x60]&2) func_L01_00441FB8(m,6,-1);
  break;
 case 6:
  if(func_L01_00452EC8(m)) {
   if(*(int *)(v+0x194)) {if(m[0x43]!=11) func_003BE4F0(m,11,0,D_L30_001DD450);}
   else if(m[0x43]!=7) func_003BE4F0(m,7,0,D_L30_001DD450);
  }
  if(m[0x60]&2) func_L01_00441FB8(m,1,-1);
  break;
 case 66:
  if(func_L01_00452EC8(m)) {*(int *)(m+0x98)=0; *(unsigned short *)(m+0x34)=(*(unsigned short *)(m+0x34)|0x41)&0xefff; func_L01_004A6DF8(m,1);}
  break;
 }
}
/* localdecomp:end func_L30_00349F90 */
