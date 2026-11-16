/* P06 wave 3 first reconstruction from PAL retail; far from a match.
 * File flags: -O2 -G8 -fopt-stack -mno-check-zero-division
 * -mno-split-addresses @ps2as.
 * Stock check.py: 807 positional differing words. An extra saved register,
 * inlined group-walk shape, state-tail sharing, dispatch, and address forms
 * still differ. This is a behavioural reconstruction for future matching,
 * not a fully verified semantic port. INCLUDE_ASM remains in the owner.
 */
#include "common.h"
typedef struct {
 u8 b0,b1,b2,b3; u8 p4[4]; u8 b8,b9,bA; u8 pB[5]; u8 b10,b11,b12;
 u8 p13[5]; u8 b18,b19; s16 h1A; u8 p1C[4]; s32 region,child,group28,group2C;
 u8 p30[0x28]; s32 group58,idx5C; u8 p60[0x18]; s16 timer;
 u8 b7A,p7B,b7C,b7D,b7E,b7F; u8 p80[0x4C];
 s32 message,rangeD0,musicD4,musicD8;
} V_336EF0;
typedef struct O_336EF0 {
 u8 p0[0x20]; u8 state; u8 p21[0x13]; u16 flags34; u8 p36[0x32]; V_336EF0 *vars;
 u8 p6C[0x29]; u8 substate; u8 p96[0x22]; void *owner; u8 stage;
} O_336EF0;
typedef struct {
 s32 (*f0)(void *,s32); void (*f4)(void *); void *f8,*fC,*f10;
 void (*f14)(void *,s32); void *f18; s32 (*f1C)(void *);
 void *p20[4]; s32 (*f30)(void *); void *p34[3]; s32 (*f40)(void *);
} Calls_336EF0;
typedef struct {
 u8 p0[0x24]; s32 f24; u8 p28[0x14]; s16 h3C; u8 p3E[0xA]; s16 h48;
 u8 p4A[0x22]; s32 f6C; u8 p70[6]; s16 h76; u8 p78[0x1C]; s32 f94;
 s16 p98; u8 p9A[4]; s16 h9E;
} Game_336EF0;
typedef struct { u8 p0[0x1DC]; s16 timer; u8 p1DE[0x23E6]; s32 state; u8 p25C8[0x288]; s32 health; } Hero_336EF0;
extern O_336EF0 *D_L21_001DED9C;
extern u16 *D_L21_0021B860[];
extern s32 D_L21_001DEDD8,D_001DEDD8_sda;
extern Game_336EF0 D_001CCFD0;
extern Hero_336EF0 D_001A4BE0;
extern u8 D_001A4C60[];
extern s32 D_00142668,D_001A7430;
extern u8 D_001427B5,D_0014270D;
extern s32 D_001D6694_sda,D_001D6690_sda,D_001E0654_sda;
extern f32 D_001E0650_sda,D_001DE9B0;
__asm__(".extern D_001DEDD8_sda, 4");
__asm__(".extern D_001D6694_sda, 4");
__asm__(".extern D_001D6690_sda, 4");
__asm__(".extern D_001E0654_sda, 4");
__asm__(".extern D_001E0650_sda, 4");
extern s32 func_L21_00337BB8(void *);
extern Calls_336EF0 *func_L01_0043B568(s32,s32,s32);
extern void func_L21_00337BF0(void *);
extern s32 func_00382380(void *,s32,s32);
extern void func_L01_0045F1E8(s32,s32);
extern void func_L01_00459AF8(void);
extern void func_L01_004450F0(s32,s32,s32);
extern s32 func_L01_004561B8(void *);
extern void func_L21_00339088(void *);
extern s32 func_0038CB00(s16 *);
extern void func_L21_00338150(void *);
extern void func_L21_003383A8(void *,s32);
extern void func_L21_00338638(void *,s32);
extern void func_L21_003387B0(void *);
extern void func_L21_00338B00(void *);
extern s32 func_L21_00338C20(void *);
extern s32 func_00382498(s32,s32);
extern void func_L21_00338090(void *);
extern s32 func_L21_003AA090(void *);
extern s32 func_L21_00338CC8(void *,void *);
extern s32 func_L21_00338D38(void *);
extern s32 func_L21_00338D60(void *,void *);
extern s32 func_L21_003AA068(void *);
extern void func_L21_003381D8(void *);
extern void func_L01_00456230(void *,s32);
extern void func_003A1C28(void);
extern s32 func_L01_004BA800(void);
extern void func_0039EF28(void);
extern s32 func_L01_004561E0(void *);
extern void func_L01_00445170(void *,s32);
extern void func_003A2B68(s32,void *);
extern void func_003A1798(void);
extern void func_L01_003609D0(void *);
static __inline__ void group_flags_336EF0(s32 *id,u16 bits,s32 clear) {
 u16 *p=D_L21_0021B860[*id];
 while((u8)*id!=255 && *id<=D_001DEDD8_sda && p) {
  O_336EF0 *o=(O_336EF0 *)((u8 *)D_L21_001DED9C+((*p&0x7FFF)<<8));
  if(!o) break;
  if(clear) o->flags34&=~bits; else o->flags34|=bits;
  p++;
  if((s16)p[-1]<0 && p!=D_L21_0021B860[*id]) break;
 }
}
void func_L21_00336EF0(void *arg) {
 O_336EF0 *m=arg,*child,*o;
 V_336EF0 *v; Calls_336EF0 *c; u16 *p; s32 r;
 if(func_L21_00337BB8(m)) return;
 child=0;
 c=0;
 v=m->vars;
 if(m->state!=8) {
  child=(O_336EF0 *)((u8 *)D_L21_001DED9C+(v->child<<8));
  c=func_L01_0043B568(0x1BC5,0,0x44);
  if(!child || !c) return;
  func_L21_00337BF0(m);
 }
 switch(m->state) {
 case 1:
  if(v->region==-1 || !func_00382380(D_001A4C60,v->region,0)) break;
  if((D_001CCFD0.h3C!=-1 ? D_001CCFD0.h3C : D_001CCFD0.h48)!=v->musicD8) func_L01_0045F1E8(v->musicD8,-1);
  D_001A7430=D_00142668;
  if(D_001427B5&1) func_L01_00459AF8();
  if(v->group58!=-1) group_flags_336EF0(&v->group58,2,0);
  p=D_L21_0021B860[v->group28];
  while((u8)v->group28!=255 && v->group28<=D_L21_001DEDD8 && p) {
   o=(O_336EF0 *)((u8 *)D_L21_001DED9C+((*p&0x7FFF)<<8));
   if(!o) break;
   o->owner=m;
   p++;
   if((s16)p[-1]<0 && p!=D_L21_0021B860[v->group28]) break;
  }
  child->owner=m;
  p=D_L21_0021B860[v->group2C];
  while((u8)v->group2C!=255 && v->group2C<=D_L21_001DEDD8 && p) {
   o=(O_336EF0 *)((u8 *)D_L21_001DED9C+((*p&0x7FFF)<<8));
   if(!o) break;
   *(s32 *)((u8 *)o->vars+0x58)=1;
   p++;
   if((s16)p[-1]<0 && p!=D_L21_0021B860[v->group2C]) break;
  }
  func_L01_004450F0((s32)m,2,-1);
  break;
 case 2:
  if(func_L01_004561B8(m)) {
   func_L21_00339088(m); v->timer=100; c->f14(child,v->b2);
  }
  if(func_0038CB00(&v->timer)) {
   func_L21_00338150(m);
   func_L21_003383A8(m,v->b0); func_L21_00338638(m,v->b1);
   func_L21_003387B0(m); func_L21_00338B00(m);
   if(func_L21_00338C20(m)) func_L01_004450F0((s32)m,3,-1);
  }
  goto deadcheck;
 case 3:
  if(func_L01_004561B8(m)) {
   func_L21_00339088(m); v->timer=(f32)func_00382498(45,55)*50.0f; c->f14(child,v->b2);
  }
  if(c->f30(child)) { v->b19=0; func_L21_00338090(m); }
  else if(c->f40(child)) {
   if(v->b19<v->b3) { v->b19++; c->f0(child,1); }
   else if(v->b19&1) { v->b19++; c->f4(child); }
   else func_L21_00338150(m);
  }
  if(!func_L21_003AA090(child) && (func_0038CB00(&v->timer) || func_L21_00338CC8(m,&v->b2) || func_L21_00338D38(m)))
   func_L01_004450F0((s32)m,4,-1);
  goto deadcheck;
 case 4:
  if(func_L01_004561B8(m)) { v->b7D=0; func_L21_00339088(m); c->f14(child,v->bA); }
  func_L21_00338150(m);
  func_L21_003383A8(m,v->b8); func_L21_00338638(m,v->b9);
  func_L21_003387B0(m); func_L21_00338B00(m);
  goto phasecheck;
 case 5:
  if(func_L01_004561B8(m)) {
   func_L21_00339088(m); v->timer=(f32)func_00382498(45,55)*50.0f;
   m->stage=1; c->f14(child,v->bA);
  }
  if(func_L01_004561B8(m)) v->timer=func_00382498(45,55);
  if(c->f30(child)) { v->b19=0; func_L21_00338090(m); }
  else if(c->f40(child)) {
   if(v->b19<func_L21_00338D60(m,&v->bA)) { v->b19++; c->f0(child,m->stage); }
   else if(v->b19&1) { v->b19++; c->f4(child); }
   else {
    if(++m->stage>=3) m->stage=1;
    func_L21_00338150(m);
   }
  }
  if(func_0038CB00(&v->timer) || func_L21_00338D38(m)) func_L01_004450F0((s32)m,6,-1);
  if(!func_L21_003AA090(child) && func_L21_00338CC8(m,&v->bA)) func_L01_004450F0((s32)m,7,-1);
  goto deadcheck;
 case 6:
  if(func_L01_004561B8(m)) { v->b7D=0; func_L21_00339088(m); }
  func_L21_003383A8(m,v->b10); func_L21_00338638(m,v->b11);
  func_L21_003387B0(m); func_L21_00338B00(m);
  if(!func_L21_003AA090(child) && func_L21_00338CC8(m,&v->bA)) {
   if(func_L21_00338C20(m)) func_L01_004450F0((s32)m,7,-1);
   else goto tail;
  }
  if(!v->b7A || c->f1C(child)==2) {
   if(c->f30(child)) { v->b18=0; func_L21_00338090(m); }
   else if(c->f40(child)) c->f4(child);
  } else func_L21_00338150(m);
phasecheck:
  if(func_L21_00338C20(m)) func_L01_004450F0((s32)m,5,-1);
deadcheck:
  if(func_L21_003AA068(child)) func_L01_004450F0((s32)m,8,-1);
  break;
 case 7:
  if(func_L01_004561B8(m)) {
   func_L21_00339088(m); m->stage=0; v->b18=0; c->f14(child,v->b12);
  }
  if(func_L21_003AA068(child)) func_L01_004450F0((s32)m,8,-1);
  r=c->f1C(child);
  if(!r) { v->b19=0; v->b7F=0; func_L21_003381D8(m); }
  else if(r==2) func_L21_00338150(m);
  else if(c->f40(child)) {
   if(v->b19<func_L21_00338D60(m,&v->b12)) v->b19+=c->f0(child,m->stage);
   else if(!v->b7F) v->b7F=c->f0(child,3);
   else {
    if(func_L21_00338D38(m)) c->f4(child);
    if(++m->stage>v->b18) m->stage=0;
    if(++v->b18>=3) v->b18=0;
    func_L21_00338150(m);
   }
  }
  break;
 case 8:
  if(func_L01_004561B8(m)) { v->timer=50; m->stage=0; }
  if(!m->stage) {
   if(func_0038CB00(&v->timer) && !m->substate && D_001A4BE0.health>0 && D_001A4BE0.state!=0x79) {
    m->stage=1; D_001A4BE0.timer=150;
    func_L01_00456230((u8 *)D_L21_001DED9C+(v->idx5C<<8),1);
    func_003A1C28();
   }
  } else if(D_001D6694_sda!=2 && D_001D6690_sda!=2 && !func_L01_004BA800()) {
   if(v->group58!=-1) group_flags_336EF0(&v->group58,2,1);
   D_0014270D=1; func_0039EF28();
   if((D_001CCFD0.h3C!=-1 ? D_001CCFD0.h3C : D_001CCFD0.h48)!=v->musicD4) func_L01_0045F1E8(v->musicD4,-1);
  }
  break;
 }
 if(m->substate==1) {
  if(func_L01_004561E0(m)) v->h1A=250;
  else if(func_0038CB00(&v->h1A)) func_L01_00445170(m,0);
  if(!D_001CCFD0.f6C && D_001CCFD0.f24==-1 && !D_001CCFD0.f94) func_003A2B68(v->message+2000,child);
  if(!D_001CCFD0.h76 && D_001CCFD0.h9E==3 && D_001CCFD0.p98<7000) {
   func_003A1798(); func_L01_00445170(m,2);
  }
 } else if(m->substate==2) {
  if(func_L01_004561E0(m)) v->h1A=500;
  if(D_001CCFD0.f6C || D_001CCFD0.f24!=-1 || D_001CCFD0.f94 || func_0038CB00(&v->h1A)) func_L01_00445170(m,0);
 }
tail:
 func_L01_003609D0(m);
 if(!D_001E0654_sda) { D_001E0654_sda=1; D_001E0650_sda=D_001DE9B0; }
 if(v->rangeD0!=-1 && func_00382380(D_001A4C60,v->rangeD0,0)) D_001DE9B0=1000.0f;
 else D_001DE9B0=D_001E0650_sda;
}
