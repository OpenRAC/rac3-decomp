/* NTSC-U draft (Codex wave 3): C of func_L09_003C6D40, the NTSC-U twin of func_L09_003C8740, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 650 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2") (NTSC-U twin "func_L09_003C6D40", whose code is not the PAL one).
 * Worker's note: 650 diff (699 inherited); best log w82/func_L09_003C6D40.08.log; 10 checks; frame 0x170 vs 0x160, VU scheduling, unresolved _sda offsets; return-by-value vector copy and site load order improve score; j form fails permitted flags (vf17), log .09; unexplained ...
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L09_003C6D40 */
extern float D_001DE950_sda;
extern u8 D_L09_001DE980[],D_L09_001DE970[],D_L09_001DE960[];
extern u8 D_L09_001E9940[], D_L09_001E9970[];
extern vu0_v4 D_L09_001D66B0;
extern float D_L09_002F1DD0[];
extern float D_001DAA30_sda;
extern s32 D_001D545C_sda;
extern u8 D_0014275B[];
extern void *D_001A71A0;
__asm__(".extern D_001D545C_sda, 4");
__asm__(".extern D_001DAA30_sda, 4");
__asm__(".extern D_001DE950_sda, 4");
extern void func_003888C8(void *,void *,void *);
extern void func_00388830(void *,void *,float);
extern void func_003886E8(void *,void *,float);
extern float func_00388730(void *,void *);
extern float func_00388770(void *);
extern void func_003888F0(void *,void *,void *);
extern float func_L01_00443D00(void *,void *,int,void *,float);
extern s32 func_L01_003F9498(void *,int,void *,float);
extern s32 func_003BF5E0(void *);
extern void func_L01_00443938(void *,void *,int,void *,void *,float);
extern s32 func_L01_00417EA0(void);
extern float *func_0037E0B8(void *);
extern void func_L01_00443628(void *,void *,int,void *,float);
extern void func_L01_00443840(void *,void *);
static __inline__ void add_6D40(void *d,void *a,void *b) {
 __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void add_ab_6D40(void *d,void *a,void *b) {
 __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void sub_6D40(void *d,void *a,void *b) {
 __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void copy_6D40(void *d,void *a) {
 __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a) : "vf1");
}
static __inline__ vu0_v4 copyvalue_6D40(void *a) {
 vu0_v4 r;
 __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(r) : "m"(*(vu0_v4 *)a) : "vf1");
 return r;
}
int func_L09_003C6D40(u8 *m,vu0_v4 *result,vu0_v4 *velocity,vu0_v4 *hit,s32 *unused,s32 side,vu0_v4 *origin,float speed,float unusedf,float radius) {
 vu0_v4 delta,pos,end,tmp,normal,nearpos;
 u8 record[0x30] __attribute__((aligned(16)));
 
 u8 *d=*(u8 **)(m+0x68);
 u8 *aux=*(u8 **)(d+0x6d0);
 u8 *collision=D_L09_001E9940;
 u8 *object;
 int touched=0,pass=0,damaged=0;
 float frac,damage,dotx,doty,dotz,length,oldmax;
 float *hp;
 func_003888C8(&tmp,(vu0_v4 *)&D_001DE950_sda+side,m+0xc0);
 add_6D40(&pos,&tmp,m+0x10);
 *(vu0_q *)origin=*(vu0_q *)&pos;
 add_ab_6D40(&tmp,&pos,velocity);
 *unused=0;
 *(vu0_q *)&delta=*(vu0_q *)velocity;
 add_ab_6D40(&end,&pos,&delta);
 frac=func_L01_00443D00(&pos,&end,0x84,m,1.0f);
 if(frac<=0.0f) {
  if(!func_L01_003F9498(&pos,4,m,1.0f)) goto final;
  { vu0_v4 savedpos; vu0_v4 *savedresultptr; vu0_v4 savedresult;
  copy_6D40(&savedpos,&pos);
  savedresultptr=&savedresult;
  *savedresultptr=copyvalue_6D40(result);
  sub_6D40(&tmp,D_L09_001E9970,&savedpos);
  add_6D40(result,&savedresult,&tmp);
  }
  goto final;
 }
 if(!(frac<1.0f)) goto final;
again:
 if(m[0x20]==3) { qzero(aux+0xc0); *(s32 *)(aux+0x138)=0; }
 touched=1;
 *(vu0_q *)hit=*(vu0_q *)(collision+0x20);
 d[0x714]=touched;
 object=*(u8 **)(collision+0x18);
 if(object) {
  if(func_003BF5E0(object)) {
   func_L01_00443938(*(void **)(collision+0x18),m,0x10000,collision+0x20,&D_L09_001D66B0,5.0f);
   damaged=1;
  } else if(!pass) {
   object=*(u8 **)(collision+0x18);
   if(*(s16 *)(object+0xaa)==0x1bae || *(s16 *)(object+0xaa)==0x1e58) {
    damage=speed / *(float *)(*(u8 **)(d+0x720)+0xc)*40.0f+60.0f;
    if(func_L01_00417EA0()) {
     if(D_001D545C_sda==7 && D_0014275B[0]!=0) damage*=D_001DAA30_sda;
     else damage*=D_L09_002F1DD0[D_001D545C_sda];
    }
    func_L01_00443938(*(void **)(collision+0x18),m,1,collision+0x20,velocity,damage);
    damaged=1;
   } else if(*(u8 **)(object+0x24) && (*(u8 **)(object+0x24))[0x46]==5) {
    hp=func_0037E0B8(object);
    if(hp && *hp>0.0f) {
     if(D_001D545C_sda==9) damage=speed / (*(float *)(*(u8 **)(d+0x720)+0xc)*0.0166666675f)*17.0f+3.0f;
     else damage=speed / (*(float *)(*(u8 **)(d+0x720)+0xc)*0.0166666675f)*80.0f+20.0f;
     if(func_L01_00417EA0()) {
      if(D_001D545C_sda==7 && D_0014275B[0]!=0) damage*=D_001DAA30_sda;
      else damage*=D_L09_002F1DD0[D_001D545C_sda];
     }
     *(vu0_q *)&tmp=*(vu0_q *)velocity; tmp.z=0;
     func_003886E8(&tmp,&tmp,5.0f);
     sub_6D40(&nearpos,*(u8 **)(collision+0x18)+0x10,m+0x10);
     func_00388830(&nearpos,&nearpos,1.0f);
     if(func_00388730(m+0xd0,&nearpos)>0.0f) func_003886E8(&nearpos,m+0xd0,0.5f);
     else func_003886E8(&nearpos,m+0xd0,-0.5f);
     add_6D40(&tmp,&nearpos,&tmp);
     tmp.w=5627.9248f;
     func_L01_00443628(record,D_001A71A0,0x10000,&tmp,damage);
     damaged=1;
     record[0x18]=10; record[0x19]=2; *(u16 *)(record+0x1a)=*(u16 *)(m+0xaa);
     func_L01_00443840(*(void **)(collision+0x18),record);
     *hp-=damage; if(*hp<0) *hp=0;
    }
   }
  }
  *(float *)(collision+0x48)=0;
 }
 if(*(float *)(collision+0x48)>0 && D_001D545C_sda!=24) *(float *)(collision+0x48)=0;
 func_00388830(&normal,collision+0x40,1.0f);
 dotx=func_00388730(&normal,m+0xc0);
 doty=func_00388730(&normal,m+0xd0);
 dotz=func_00388730(&normal,m+0xe0);
 if(side==0) {
  if(dotx<0 && doty>0 && *(float *)(m+0xe8)<0.707f) func_003886E8(&normal,m+0xc0,-1.0f);
  else if(dotx>0 && doty<0) func_003886E8(&normal,m+0xd0,-1.0f);
  else if(dotz>0.5f && doty>0) *(vu0_q *)&normal=*(vu0_q *)(m+0xe0);
 } else if(side==2) {
  if(dotx>0 && doty>0) func_003886E8(&normal,m+0xc0,1.0f);
  else if(dotx<0 && doty<0) func_003886E8(&normal,m+0xd0,-1.0f);
  else if(dotz>0.5f && doty>0) *(vu0_q *)&normal=*(vu0_q *)(m+0xe0);
 } else if(side==1) {
  if(dotx<0 && doty<0 && *(float *)(m+0xe8)<0.707f) func_003886E8(&normal,m+0xc0,-1.0f);
  else if(dotx>0 && doty>0) func_003886E8(&normal,m+0xd0,1.0f);
  else if(dotz>0.5f && doty<0) *(vu0_q *)&normal=*(vu0_q *)(m+0xe0);
 } else if(side==3) {
  if(dotx>0 && doty<0) func_003886E8(&normal,m+0xc0,1.0f);
  else if(dotx<0 && doty>0) func_003886E8(&normal,m+0xd0,1.0f);
  else if(dotz>0.5f && doty<0) *(vu0_q *)&normal=*(vu0_q *)(m+0xe0);
 }
 damage=func_00388730(&delta,&normal)*-1.01f;
 func_003886E8(&end,&delta,frac);
 add_6D40(&pos,&pos,&end);
 func_003886E8(&tmp,&normal,damage*(1.0f-frac));
 add_6D40(result,result,&tmp);
 func_003886E8(&tmp,&normal,damage);
 if(!damaged) add_ab_6D40(velocity,velocity,&tmp);
 length=func_00388770(velocity);
 oldmax=speed;
 if(speed<length) { func_003886E8(velocity,velocity,speed/length); length=speed; }
 else if(length<speed) speed=length;
 if(*(float *)(aux+0x138)>0) *(float *)(aux+0x138)=length;
 else if(length<speed) *(float *)(aux+0x138)=-length;
 func_003888F0(&tmp,&normal,aux);
 func_003886E8(&tmp,&tmp,length*0.01f);
 add_6D40(d+0x660+side*16,d+0x660+side*16,&tmp);
 if(!pass) {
  func_003886E8(&delta,velocity,1.0f-frac);
  add_ab_6D40(&end,&pos,&delta);
  frac=func_L01_00443D00(&pos,&end,0x84,m,radius);
  if(frac<1.0f && frac>=0.0f) { pass=1; goto again; }
 }
final:
 *(vu0_q *)record=*(vu0_q *)&pos;
 switch(side) {
 case 0:func_003888C8(&tmp,D_L09_001DE980,m+0xc0);break;
 case 1:func_003888C8(&tmp,D_L09_001DE970,m+0xc0);break;
 case 2:func_003888C8(&tmp,D_L09_001DE960,m+0xc0);break;
 case 3:func_003888C8(&tmp,&D_001DE950_sda,m+0xc0);break;
 }
 add_ab_6D40(&nearpos,&tmp,m+0x10);
 frac=func_L01_00443D00(&nearpos,record,0x84,m,1.0f);
 if(frac>0) {
  sub_6D40(&tmp,&nearpos,record);
  func_003886E8(&tmp,&tmp,1.0f-frac);
  add_6D40(result,result,&tmp);
 }
 return touched;
}
/* localdecomp:end func_L09_003C6D40 */
