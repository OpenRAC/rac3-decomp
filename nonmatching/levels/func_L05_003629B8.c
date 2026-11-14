/* NTSC-U draft (2026-11-14, Codex worker): C of func_L05_00361680, the NTSC-U twin of func_L05_003629B8, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 4 words differ with its file's flags.
 */
#include "common.h"
/* localdecomp:start func_L05_00361680 */
typedef int Q __attribute__((mode(TI)));
typedef struct {float x,y,z,w;} __attribute__((aligned(16))) V;
typedef struct { V origin,pos,dir; u8 pad30[4]; float distance,age,damage; } P;
typedef struct {u8 pad[0x68];P *p;u8 pad6c[0xaa - 0x6c];s16 kind;u8 padac[12];void *owner;} M;
typedef struct {u8 pad[0x18];M *obj;u8 gap[4];V pos;} HitGlobal;
typedef struct {u8 pad[0x1a];u16 kind;u8 rest[0x14];} Hit;
extern float D_001DDA80_sda,D_001DDA84_sda,D_001DDA88_sda,D_001DDA8C_sda,D_001DDA90_sda,D_001DDA94_sda,D_001DDA98_sda;
extern int D_001DDA9C_sda,D_001DDAA0_sda;
__asm__(".extern D_001DDA80_sda,4");
__asm__(".extern D_001DDA84_sda,4");
__asm__(".extern D_001DDA88_sda,4");
__asm__(".extern D_001DDA8C_sda,4");
__asm__(".extern D_001DDA90_sda,4");
__asm__(".extern D_001DDA94_sda,4");
__asm__(".extern D_001DDA98_sda,4");
__asm__(".extern D_001DDA9C_sda,4");
__asm__(".extern D_001DDAA0_sda,4");
extern M *D_L05_001EA758[];
extern HitGlobal D_L05_001EA740[];
extern u8 D_L05_00361BA8[];
extern void func_00388830(void *,void *,float);
extern float func_00388800(void *,void *);
extern void func_L01_00443628(void *,M *,int,float,void *);
extern void func_L01_004C76B8(void);
extern void func_L01_004C76F0(void);
extern int func_003CE740(void *,void *,int,void *,void *);
extern int func_L01_00452F60(void *);
extern void func_L05_00361FF8(void *,int);
extern void func_L01_00452F40(void *,int);
extern void func_003BD360(void *);
extern int func_0037E1D8(int);
extern float func_0037E250(float,float);
extern u8 *func_L01_00467288(void *,void *,int,float,float);
extern void func_L01_004026A0(void *,void *);
static __inline__ void add_ba(V *d,V *a,V *b){
 __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0":"=m"(*d):"m"(*a),"m"(*b):"vf1","vf2");
}
static __inline__ void add_ab(V *d,V *a,V *b){
 __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0":"=m"(*d):"m"(*a),"m"(*b):"vf1","vf2");
}
void func_L05_00361680(M *m){
 V start;
 V step;
 Hit hit;
 V mid;
 V retreat;
 P *p=m->p;
 int collided;
 HitGlobal *g;
 V *point;
 u8 *particle;
 float damage;
 p->age+=1.0f;
 if(p->age>2.0f)start=p->pos;
 else start=p->origin;
 damage=p->damage;
 if(p->age<D_001DDA88_sda){
  p->distance+=D_001DDA80_sda*0.016666668f;
  func_00388830(&p->pos,&p->dir,p->distance);
  func_00388830(&step,&p->dir,0.06666667f);
  func_L01_00443628(&hit,m,0x10001,damage,&step);
  hit.kind=m->kind;
  add_ba(&p->pos,&p->origin,&p->pos);
  func_00388830(&mid,&p->dir,-(D_001DDA80_sda*0.016666668f));
  add_ab(&mid,&mid,&p->pos);
  func_L01_004C76B8();
  collided=func_003CE740(&start,&p->pos,0,m,&hit);
  if(collided && D_L05_001EA758[0] && D_L05_001EA758[0]->kind==0x186d && ((u8 *)D_L05_001EA758[0])[0x20]!=2 && ((u8 *)D_L05_001EA758[0])[0x20]!=5)((u8 *)D_L05_001EA758[0])[0x20]=4;
  func_L01_004C76F0();
  if(collided && (g=D_L05_001EA740, g->obj!=m->owner) && (!g->obj || g->obj->kind!=0x1625))goto impact;
 }else if(p->age>=D_001DDA88_sda && p->age<D_001DDA8C_sda){
  if(func_00388800(&p->origin,&p->pos)>D_001DDA80_sda*0.016666668f){
   p->distance+=D_001DDA80_sda*0.016666668f;
   func_00388830(&p->pos,&p->dir,p->distance);
   func_00388830(&step,&p->dir,0.06666667f);
   func_L01_00443628(&hit,m,0x10001,damage,&step);
   hit.kind=m->kind;
   add_ba(&p->pos,&p->origin,&p->pos);
   func_00388830(&mid,&p->dir,-(D_001DDA80_sda*0.016666668f));
   add_ab(&mid,&mid,&p->pos);
   func_L01_004C76B8();
   collided=func_003CE740(&start,&p->pos,0,m,&hit);
   if(collided && D_L05_001EA758[0] && D_L05_001EA758[0]->kind==0x186d && ((u8 *)D_L05_001EA758[0])[0x20]!=2 && ((u8 *)D_L05_001EA758[0])[0x20]!=5)((u8 *)D_L05_001EA758[0])[0x20]=4;
   func_L01_004C76F0();
   if(collided && (g=D_L05_001EA740, g->obj!=m->owner) && (!g->obj || g->obj->kind!=0x1625)){
impact:
 point=&g->pos;
 p->pos=*point;
 if(!func_L01_00452F60(m)){
  func_L05_00361FF8(point,20);
  func_L01_00452F40(m,1);
 }
 func_003BD360(m);
 return;
   }
   func_00388830(&retreat,&p->dir,D_001DDA84_sda*0.016666668f);
   add_ab(&p->origin,&p->origin,&retreat);
  }else return;
 }else{
  goto expired;
 }
 if(!func_0037E1D8(D_001DDAA0_sda)){
  float f=func_0037E250(D_001DDA90_sda,D_001DDA94_sda);
  particle=func_L01_00467288(&p->pos,0,D_001DDA9C_sda,f,D_001DDA98_sda*210000.0f);
  if(particle)particle[1]=0;
 }
 func_L01_004026A0(D_L05_00361BA8,m);
 return;
expired:
 func_L05_00361FF8(&p->pos,20);
 func_003BD360(m);
}
/* localdecomp:end func_L05_00361680 */
