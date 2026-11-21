#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

typedef int Q __attribute__((mode(TI)));
typedef struct {u8 pad[0x30]; Q pos; u8 tail[0x40];} Rec;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad14[0xC];
    s32 ids[8];
    u8 quads[0x80];
} P_003AD358;

/* localdecomp:start func_L19_003ADE70 */
/* PAL port of the NTSC-U match src/us/levels/func_L19_003AC268.c */
#include "vu0.h"

extern Rec *D_L19_001DF800_003AC268;
extern u8 D_1A30B0[];
extern void func_L01_004450F0(void *, int, int);
extern void func_L19_003AE108(void *);
extern void func_L19_003AE5A8(void *);
extern int func_L01_004561B8(void *);
extern void func_003A4F28(int);
void func_L19_003ADE70(u8 *o) {
 u8 *p=*(u8 **)(o+0x68); int i;
 switch(o[0x20]) {
 case 0:
 *(Q *)(o+0x10)=D_L19_001DF800_003AC268[*(int *)(p+0x20)].pos;
 *(Q *)(p+0x40)=D_L19_001DF800_003AC268[*(int *)(p+0x28)].pos;
 if (*(int *)(p+4)<10) *(int *)(p+4)=(int)((float)*(int *)(p+4)*50.0f);
 else *(int *)(p+4)=(*(int *)(p+4)*5+2)/6;
 if(abs_asm(*(int *)(p+0x1c))<10) *(int *)(p+0x1c)=(int)((float)*(int *)(p+0x1c)*50.0f);
 else *(int *)(p+0x1c)=(*(int *)(p+0x1c)*5+2)/6;
 *(int *)(p+0x14)=0; *(int *)(p+8)=-1; *(float *)(p+0xc)=0; *(int *)(o+0x98)=0;
 func_L01_004450F0(o,1,-1); break;
 case 1: func_L19_003AE108(o);func_L19_003AE5A8(o); break;
 case 2:
 if(func_L01_004561B8(o)) {
 i=*(int *)(p+8);
 if(i!=-1) {u8 *slot=D_1A30B0+(i<<7); if(*(u8 **)(slot+0xdc)==o && slot[0xd0])func_003A4F28(i);}
 *(int *)(p+8)=-1;
 } break;
 case 3: {
 float t=(float)*(u16 *)(o+0x96)/25.0f;
 float sum = *(float *)(p+0xc) + (t>1.0f ? 1.0f : t);
 *(float *)(p+0xc)=sum;
 if(sum>=1.0f) {--*(int *)(p+0x1c); *(float *)(p+0xc)=sum-1.0f;}
 func_L19_003AE108(o);func_L19_003AE5A8(o);
 if(*(u16 *)(o+0x96)>=25)func_L01_004450F0(o,2,-1);
 break;
 }
 }
 ++*(u16 *)(o+0x96);
}
/* localdecomp:end func_L19_003ADE70 */
