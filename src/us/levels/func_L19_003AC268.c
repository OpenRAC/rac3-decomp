#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L19_003AC268 */
typedef int Q __attribute__((mode(TI)));
typedef struct {u8 pad[0x30]; Q pos; u8 tail[0x40];} Rec;
extern Rec *D_L19_001DF800_003AC268;
extern u8 D_001A30B0[];
extern void func_L01_00441FB8(void *,int,int);
extern void func_L19_003AC4B8(void *);
extern void func_L19_003AC958(void *);
extern int func_L01_00452EC8(void *);
extern void func_0039FB08(int);
void func_L19_003AC268(u8 *o) {
 u8 *p=*(u8 **)(o+0x68); int i;
 switch(o[0x20]) {
 case 0:
 *(Q *)(o+0x10)=D_L19_001DF800_003AC268[*(int *)(p+0x20)].pos;
 *(Q *)(p+0x40)=D_L19_001DF800_003AC268[*(int *)(p+0x28)].pos;
 if (*(int *)(p+4)<10) *(int *)(p+4)=(int)((float)*(int *)(p+4)*60.0f);
 if(abs_asm(*(int *)(p+0x1c))<10) *(int *)(p+0x1c)=(int)((float)*(int *)(p+0x1c)*60.0f);
 *(int *)(p+0x14)=0; *(int *)(p+8)=-1; *(float *)(p+0xc)=0; *(int *)(o+0x98)=0;
 func_L01_00441FB8(o,1,-1); break;
 case 1: func_L19_003AC4B8(o);func_L19_003AC958(o); break;
 case 2:
 if(func_L01_00452EC8(o)) {
 i=*(int *)(p+8);
 if(i!=-1) {u8 *slot=D_001A30B0+(i<<7); if(*(u8 **)(slot+0xdc)==o && slot[0xd0])func_0039FB08(i);}
 *(int *)(p+8)=-1;
 } break;
 case 3: {
 float t=(float)*(u16 *)(o+0x96)/30.0f;
 float sum = *(float *)(p+0xc) + (t>1.0f ? 1.0f : t);
 *(float *)(p+0xc)=sum;
 if(sum>=1.0f) {--*(int *)(p+0x1c); *(float *)(p+0xc)=sum-1.0f;}
 func_L19_003AC4B8(o);func_L19_003AC958(o);
 if(*(u16 *)(o+0x96)>=30)func_L01_00441FB8(o,2,-1);
 break;
 }
 }
 ++*(u16 *)(o+0x96);
}
/* localdecomp:end func_L19_003AC268 */
