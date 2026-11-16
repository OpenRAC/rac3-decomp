/* NTSC-U draft (Codex wave 3): C of func_L01_003EC0B0, the NTSC-U twin of func_L01_003EDFF0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 99 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_003EC0B0", whose code is not the PAL one).
 * Worker's note: 99 diff (256 inherited); best log w82/func_L01_003EC0B0.10.log; 10 checks; cached input table pointer removes duplicate load; typed hero layout and scalar zero order improve; real VF clobbers added; remaining hero s0/s1 allocation, VU interleaving and one ...
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_003EC0B0 */
typedef int Q_C0B0 __attribute__((mode(TI)));
extern u8 D_L01_001E2AC0[];
extern u8 *D_L01_001DF884;
extern u8 *D_001DF884_sda;
extern s32 D_001DFBC8_sda;
typedef struct {
 u8 prefix[0x20]; vu0_v4 axis; u8 p30[0x50]; vu0_v4 position;
 u8 p90[8]; float angle; u8 p9c[0x1680-0x9c]; u8 camera[0x4c]; float speed;
} Hero_C0B0;
extern Hero_C0B0 D_001A4BE0;

extern u8 D_001A6120[];
extern s32 D_001A4E18[];
extern u8 *D_001D52FC;
extern s32 func_L01_003EBE48(void *);
extern void func_L01_003E6C58(void *);
extern s32 func_L01_003E6CA8(void *);
extern void func_00388830(void *,void *,float);
extern void func_L01_004109B0(void *,void *,float,float);
extern s32 func_0039E928(s32,s32);
extern float func_00388A28(float,float);
extern float func_00389468(float,float);
extern float func_003893C8(float,float);
extern float func_00388730(void *,void *);
extern void func_003886E8(void *,void *,float);
extern float func_00388770(void *);
extern float func_00388978(float);
extern float func_00388960(float);
extern void func_L01_003E6D50(s32,s32,float,float);
extern void func_L01_003E6FF0(s32);
extern void func_L01_003E6DA8(s32,float,float);
extern void func_L01_003E6DF0(s32,s32,float,float);
extern void func_L01_003E6EC8(s32,float);
extern void func_L01_003E6F00(s32,s32);
extern void func_L01_003E6E60(s32,float,float,float);
static __inline__ void add_C0B0(void *d,void *a,void *b) {
 __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(vu0_v4 *)d): "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void sub_C0B0(void *d,void *a,void *b) {
 __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d): "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
void func_L01_003EC0B0(u8 *m) {
 u8 *owner=D_L01_001E2AC0+*(s32 *)(m+0x94)*0x460;
 u8 *state=owner+0x150;
 u8 *d=*(u8 **)(D_L01_001DF884+*(s16 *)(m+0x84)*32+28);
 vu0_v4 a,b,c,e;
 float f,g;
 u8 *obj,*sub,*move,*rot,*misc,*other;
 if(!func_L01_003EBE48(m)) {
  if(*(s32 *)(d+0x20)) *(s16 *)(d+0x26)=1;
  *(s32 *)(d+0x20)=0;
  func_L01_003E6C58(m);
  func_00388830(&a,&D_001A4BE0.axis,D_001A4BE0.speed);
  add_C0B0(&a,&a,&D_001A4BE0.position);
  func_L01_004109B0((u8 *)&D_001A4BE0+0x1540,&a,D_001A4BE0.angle,0.0f);
  return;
 }
 if(func_L01_003E6CA8(m)<=0) {
  if(*(s32 *)(d+0x20)) *(s16 *)(d+0x26)=1;
  *(s32 *)(d+0x20)=0; return;
 }
 if((*(s32 *)(D_001D52FC+0x1a0)&func_0039E928(4,0)) && D_001DFBC8_sda>=11) {
  if(*(s32 *)(d+0x20)) *(s16 *)(d+0x26)=1;
  *(s32 *)(d+0x20)=0;
  func_L01_003E6C58(m);
  func_L01_004109B0(D_001A6120,D_001A6120-0x14c0,*(float *)(D_001A6120-0x14a8),0.0f); return;
 }
 if(*(s32 *)(d+0x20)<2) {
  if(*(float *)(d+0x2c)==0.0f && *(float *)(d+0x30)==0.0f) {
   u8 *input=D_001DF884_sda;
   *(float *)(d+0x2c)=*(float *)(input+*(s16 *)(m+0x84)*32+0x14);
   *(float *)(d+0x30)=*(float *)(input+*(s16 *)(m+0x84)*32+0x18);
  }
  f=func_00388A28(*(float *)(state+0x40)-*(float *)(D_L01_001DF884+*(s16 *)(m+0x84)*32),*(float *)(state+0x44)-*(float *)(D_L01_001DF884+*(s16 *)(m+0x84)*32+4));
  if(func_00389468(*(float *)(d+0x30),f)>0.034906585f) *(float *)(d+0x44)=func_003893C8(*(float *)(d+0x30),f);
  a.x=*(float *)(D_L01_001DF884+*(s16 *)(m+0x84)*32);
  a.w=0;
  a.y=*(float *)(D_L01_001DF884+*(s16 *)(m+0x84)*32+4);
  a.z=*(float *)(D_L01_001DF884+*(s16 *)(m+0x84)*32+8);
  sub_C0B0(&b,&a,state+0x40);
  f=func_00388730(&b,state+0x80);
  func_003886E8(&c,state+0x80,f);
  sub_C0B0(&e,&b,&c);
  g=func_00388770(&e);
  f=-f;
  *(float *)(d+0x38)=g; *(float *)(d+0x3c)=f;
  g=*(float *)(d+0x2c);
  if(__builtin_fabsf(g)==1.57079637f) *(float *)(d+0x40)=0;
  else { f=func_00388978(g); f=f/func_00388960(g); *(float *)(d+0x40)=*(float *)(d+0x3c)-*(float *)(d+0x38)*f; }
  obj=*(u8 **)(owner+0x50); *(Q_C0B0 *)(obj+0x30)=*(Q_C0B0 *)&a;
  sub=*(u8 **)(obj+0x70); move=sub+0x180; rot=sub+0x20; misc=sub+0x60; other=sub+0x210;
  *(float *)(move+0x2c)=*(float *)(d+0x38); *(float *)(move+0x30)=*(float *)(d+0x3c);
  *(float *)(rot+0x28)=*(float *)(d+0x44); *(float *)(misc+0xd0)=*(float *)(d+0x40);
  func_003886E8(&c,state+0x80,-*(float *)(move+0x30)); add_C0B0(sub+0xb0,state+0x40,&c);
  sub_C0B0(sub+0x180,&a,sub+0xb0); *(Q_C0B0 *)(sub+0x190)=*(Q_C0B0 *)(sub+0x180);
  func_003886E8(&c,state+0x80,-*(float *)(misc+0xd0)); add_C0B0(sub+0xa0,state+0x40,&c);
  *(Q_C0B0 *)(sub+0x110)=*(Q_C0B0 *)(sub+0xa0);
  *(Q_C0B0 *)(sub+0xc0)=*(Q_C0B0 *)(state+0x40); *(Q_C0B0 *)(sub+0x60)=*(Q_C0B0 *)(state+0x40);
  *(Q_C0B0 *)sub=*(Q_C0B0 *)(obj+0x30); *(Q_C0B0 *)(sub+0x230)=*(Q_C0B0 *)(obj+0x30);
  *(float *)(other+0x30)=0; *(float *)(rot+0x14)=0;
  *(float *)(rot+4)=*(float *)(misc+0xd0); *(float *)(rot+0xc)=*(float *)(rot+0x14);
  *(float *)(rot+8)=*(float *)(move+0x30); *(s16 *)(rot+2)=0;
  *(float *)(rot+0x18)=*(float *)(rot+0x14); *(float *)(rot+0x10)=*(float *)(rot+0x14);
 }
 if(++*(s32 *)(d+0x20)>200) *(s32 *)(d+0x20)=200;
 if(*(float *)(d+0x38)!=0) { func_L01_003E6D50(*(s32 *)(m+0x94),0,*(float *)(d+0x38),0.003f); func_L01_003E6FF0(*(s32 *)(m+0x94)); }
 if(*(float *)(d+0x3c)!=0) func_L01_003E6DA8(*(s32 *)(m+0x94),*(float *)(d+0x3c),0.003f);
 if(*(float *)(d+0x40)!=0) func_L01_003E6DF0(*(s32 *)(m+0x94),0,*(float *)(d+0x40),0.005f);
 if(*(float *)(d+0x28)!=0) func_L01_003E6EC8(*(s32 *)(m+0x94),*(float *)(d+0x28)*0.017453292f);
 if(!*(s16 *)(d+0x24)) func_L01_003E6F00(*(s32 *)(m+0x94),0);
 if(*(float *)(d+0x44)!=0) func_L01_003E6E60(*(s32 *)(m+0x94),*(float *)(d+0x44),60.0f,60.0f);
 D_001A4E18[0]=10;
}
/* localdecomp:end func_L01_003EC0B0 */
