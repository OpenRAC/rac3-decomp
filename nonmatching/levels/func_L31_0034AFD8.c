/* P06 wave 3 first reconstruction from PAL retail; not a confirmed match.
 * File flags: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 * -mno-check-zero-division @ps2as.
 * Stock check.py: 301 positional differing words. Two missing nop pairs
 * before the progress divisions shift the body, with additional control-flow,
 * declaration/address, and allocation differences. Proposed coordinator-owned
 * divs_nops row: 0 0 2 0 0 2 (not applied or tested).
 * qzero is used for retail's bare quadword clears. INCLUDE_ASM remains.
 */
#include "common.h"
#include "vu0.h"
typedef struct { u8 bytes[16]; } Packed_34AFD8;
typedef struct {
 u8 p0[0x30]; f32 f30; s16 h34; u8 p36[0x3A]; Packed_34AFD8 f70;
 u8 p80[0x54]; s32 timer; u8 pD8[0x10]; s32 idxE8,idxEC,idxF0;
 u8 pF4[8]; s32 handle; u8 p100[0x18]; s32 total;
 u8 p11C[0x38]; s32 special; void *owner; s32 idx15C; s32 idx160;
} V_34AFD8;
typedef struct { u8 p0[0x20]; u8 state; u8 p21[0x47]; V_34AFD8 *vars; } O_34AFD8;
typedef struct { u8 p0[0xD0]; u8 active; u8 pD1[0xB]; void *owner; } Slot_34AFD8;
extern f32 D_001DD25C_sda,D_001DD260_sda;
extern s32 D_001DD250_sda,D_001DD254_sda,D_001DD240_sda,D_001DD2A0_sda;
__asm__(".extern D_001DD25C_sda, 4");
__asm__(".extern D_001DD260_sda, 4");
__asm__(".extern D_001DD250_sda, 4");
__asm__(".extern D_001DD254_sda, 4");
__asm__(".extern D_001DD240_sda, 4");
__asm__(".extern D_001DD2A0_sda, 4");
extern f32 D_L31_001E12B4;
extern u8 D_00142732,D_001426D7,D_001A6718;
extern void *D_001A71A0;
extern u8 D_001A4C60[],D_L31_00284110[];
extern u8 *D_L31_001DF79C;
extern Slot_34AFD8 D_001A30B0[];
extern s32 func_L01_004561B8(void *);
extern void func_L31_0034D088(void *);
extern f32 func_003C4088(f32,f32,f32);
extern void func_L31_0034C5A0(void *,f32);
extern s32 func_0038CAD0(s32 *);
extern void func_L01_004AAC98(s32,s32,void *,s32);
extern void func_L31_0034CC30(void *);
extern s32 func_003A52A0(s32,s32,void *);
extern void func_L01_0043B9E8(void *,s32,s32,s32);
extern void *func_L31_003B3D38(s32,void *,s32,s32,s32,f32,f32);
extern void func_003A4F28(s32);
extern void func_L01_004450F0(void *,s32,s32);
extern void func_L31_0034BCA8(void *);
extern void func_L31_0034ACA8();
extern void func_L31_0034CB80(void *);
extern s32 func_00382380(void *,s32,s32);
extern void func_003C2C98(void *,void *);
extern void func_L01_0043A430(void *,s32,void *);
extern void func_L31_0034B580(void *);
extern void func_L30_004CF4B0(s32,s32);
extern vu0_q D_001A4CD0[];
extern void func_L31_0034D390(void *,s32);
extern void func_L01_00456230(void *,s32);
extern void func_L01_0045F1E8(s32,s32);
extern void func_L31_0034BF90(void *);
extern void func_L31_0034CA18(void *);
void func_L31_0034AFD8(void *arg) {
 O_34AFD8 *m=arg; V_34AFD8 *v=m->vars;
 Packed_34AFD8 packed; s32 params[14]; s32 i; u8 *p; Slot_34AFD8 *s;
 switch(m->state) {
 case 1: func_L31_0034D088(m); break;
 case 2:
  if(func_L01_004561B8(m)) {
   v->total=(s32)(D_L31_001E12B4/func_003C4088(D_001DD25C_sda,D_001DD260_sda,1.0f-v->f30/(f32)v->h34));
   v->timer=v->total;
  }
  if(v->timer>v->total) v->timer=v->total;
  func_L31_0034C5A0(m,(f32)(v->total-v->timer)/(f32)v->total);
  if(func_0038CAD0(&v->timer)) {
   if(v->special) goto finished;
   func_L01_004450F0(m,4,-1);
  }
  break;
 case 3:
  if(func_L01_004561B8(m)) {
   v->total=(s32)(D_L31_001E12B4/func_003C4088(D_001DD25C_sda,D_001DD260_sda,1.0f-v->f30/(f32)v->h34));
   v->timer=v->total;
  }
  if(v->timer>v->total) v->timer=v->total;
  func_L31_0034C5A0(m,(f32)(v->total-v->timer)/(f32)v->total);
  if(func_0038CAD0(&v->timer)) func_L01_004450F0(m,1,-1);
  break;
 case 66:
  if(func_L01_004561B8(m)) func_L01_004AAC98(0,0,D_001A71A0,0x165E);
  if(func_0038CAD0(&v->timer)) {
   p=*(u8 **)((u8 *)v->owner+0x68);
   if(p) p[0x4B]=1;
   if(!v->special) D_00142732=1;
finished:
   func_L31_0034CC30(m);
  }
  break;
 case 4:
  if(func_L01_004561B8(m)) {
   v->timer=D_001DD250_sda;
   func_L01_004AAC98(3,0,D_001A71A0,0x165E);
   if(v->handle==-1 || (s=(Slot_34AFD8 *)((u8 *)D_001A30B0+(v->handle<<7)))->owner!=m || !s->active)
    v->handle=func_003A52A0(5,4,m);
   packed=v->f70;
   func_L01_0043B9E8(m,packed.bytes[4],packed.bytes[5],packed.bytes[6]);
   for(i=13;i>=0;i--) params[i]=0;
   params[0]=(s32)m;
   v->owner=func_L31_003B3D38(14,params,100,7,5,1.0f,280.0f);
  }
  if(func_0038CAD0(&v->timer)) {
   v->timer=D_001DD254_sda;
   if(v->handle!=-1) {
    s=(Slot_34AFD8 *)((u8 *)D_001A30B0+(v->handle<<7));
    if(s->owner==m && s->active) func_003A4F28(v->handle);
   }
   v->handle=-1;
   func_L01_004450F0(m,66,-1);
  }
  func_L31_0034BCA8(m);
  func_L31_0034ACA8(m);
  break;
 case 0:
  func_L31_0034CB80(m);
  if(D_001426D7&0x10) func_L01_004450F0(m,66,-1);
  else func_L01_004450F0(m,5,-1);
  break;
 case 5:
  if(func_00382380(D_001A4C60,v->idxF0,0)) {
   for(i=0,p=D_L31_00284110;i<31;i++,p+=0x40) {
    if(p[1]) func_003C2C98(m,p);
    func_L01_0043A430(m,i,p);
   }
   if(!v->special) func_L01_004450F0(m,6,-1);
   else if(!(D_001A6718&1)) func_L31_0034B580(m);
  }
  break;
 case 6:
  if(func_L01_004561B8(m)) {
   func_L30_004CF4B0(0x74,1);
   *(s32 *)((u8 *)D_001A4CD0+0x90)=0;
   qzero(&D_001A4CD0[0]); qzero(&D_001A4CD0[2]); qzero(&D_001A4CD0[3]); qzero(&D_001A4CD0[4]); qzero(&D_001A4CD0[7]);
   func_L31_0034D390(m,1);
   func_L01_00456230(D_L31_001DF79C+(v->idxE8<<8),1);
   func_L01_00456230(D_L31_001DF79C+(v->idxEC<<8),1);
   v->timer=D_001DD240_sda;
   func_L01_0045F1E8(v->idx160,-1);
  }
  if(func_0038CAD0(&v->timer)) {
   func_L30_004CF4B0(0x9A,1);
   func_L31_0034B580(m);
  }
  break;
 }
 if(D_001DD2A0_sda) v->timer++;
 if((u8)(m->state+3)>=3) {
  func_L31_0034BF90(m);
  func_L31_0034CA18(m);
 }
}
