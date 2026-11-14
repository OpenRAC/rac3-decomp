/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_0033E068, the NTSC-U twin of func_L01_0033E760, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses" when tried; not with src/levels/shared/L01_0033E0C8.c's current line.
 * Worker's note: 321 diff; best log w125/func_L01_0033E068.02.log; allowed GNU assembler uses .lit4 loads for 0.00027777778 and 1021 instead of inline lui/ori/mtc1 (documented assembler literal mismatch); hero field address anchors and VU0 scheduling also differ; retail states 1/2/3/90; div nop counts 2 2 needed, no
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_0033E068 */
typedef struct {float x,y,z,w;} __attribute__((aligned(16))) V;
typedef struct {u8 pad[4];s16 timer4,timer6,timer8,timera;float anglex,angley;int timer14;u8 gap[8];V initial,velocity;} P;
typedef struct {u8 pad[0x10];V pos;u8 state;u8 pad21[0x34 - 0x21];u16 flags;u8 pad36[0x68 - 0x36];P *p;u8 pad6c[0xaa - 0x6c];s16 kind;u8 padac[0xf0 - 0xac];float anglex,angley;} M;
typedef struct {u8 pad[0x1200];M *obj;u8 gap[0x25c0 - 0x1204];void *target;u8 gap2[0x25e4 - 0x25c4];u8 b25e4,b25e5;u8 gap3[10];u8 b25f0;} Hero;
extern Hero D_001A4BE0[];
extern V D_001A4EC0[];
extern V D_L01_001D66B0[];
extern V D_L01_001EAAB0[];
extern float D_001DD064_sda,D_001DD084_sda,D_001DD088_sda;
extern s16 D_001DD06C_sda;
extern int D_001DD07C_sda,D_001DD080_sda;
extern M *D_001DD08C_sda;
extern void func_003BFD10(void *,void *,void *,float);
extern float func_00389380(float,float);
extern void func_L01_0033E5C8(void *);
extern int func_003883C8(void *);
extern float func_00388730(void *,void *);
extern void func_L01_0033FA68(void *);
extern void func_003886C0(void *,void *,void *,float);
extern void func_L01_0033FAD8(void *);
extern void func_L01_004026A0(void *,void *);
extern void func_L01_0033ED90(void *);
extern int func_L01_003F9498(void *,int,void *,float);
extern void func_003BD360(void *);
extern void func_L01_0033EA68(void *);
extern void func_L01_0033EC00(void *);
extern void func_L01_0033E828(void *);
extern void func_00388398(void *);
extern void func_L01_0033E6E8(void *);
extern void func_L01_00447D00(void *,void *,void *,int,int,int,int,int,int,int,int,int,float,float,float,float,float,float,float);
static __inline__ void add_ba(V *d,V *a,V *b){
 __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0":"=m"(*d):"m"(*a),"m"(*b):"vf1","vf2");
}
static __inline__ void add_ab(V *d,V *a,V *b){
 __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0":"=m"(*d):"m"(*a),"m"(*b):"vf1","vf2");
}
void func_L01_0033E068(M *m){
 V oldpos;
 P *p=m->p;
 if((!D_001A4BE0[0].obj || D_001A4BE0[0].obj->kind!=0xc0) && m->state==0)goto destroy;
 if(D_001A4BE0[0].b25e4 && m->state==0)goto destroy;
 if((D_001A4BE0[0].b25e5 || D_001A4BE0[0].b25f0) && m->state==0)m->flags|=0x41;
 else m->flags&=0xffbe;
 switch(m->state){
 case 1:
  oldpos=m->pos;
  add_ba(&m->pos,&p->velocity,&m->pos);
  func_003BFD10(&m->pos,&p->velocity,&p->velocity,D_001DD064_sda*0.00027777778f);
  m->anglex=func_00389380(m->anglex,p->anglex);
  m->angley=func_00389380(m->angley,p->angley);
  func_L01_0033E5C8(m);
  if(func_003883C8(&p->timer4))goto destroy;
  if(m->pos.x<2.0f || m->pos.x>1021.0f || m->pos.y<2.0f || m->pos.y>1021.0f || m->pos.z<2.0f || m->pos.z>1021.0f)goto destroy;
  if(func_00388730(D_001A4EC0,&p->velocity)>0.0f && func_003883C8(&p->timer6)){
   m->state=2;
   p->timer8=D_001DD06C_sda;
   p->timera=D_001DD07C_sda;
   p->initial=p->velocity;
   func_L01_0033FA68(m);
  }
  break;
 case 2:
  func_003886C0(&p->velocity,D_L01_001D66B0,&p->initial,(float)p->timera/(float)D_001DD07C_sda);
  add_ab(&m->pos,&m->pos,&p->velocity);
  m->anglex=func_00389380(m->anglex,p->anglex);
  m->angley=func_00389380(m->angley,p->angley);
  func_L01_0033FAD8(m);
  func_L01_004026A0(func_L01_0033ED90,m);
  if(func_L01_003F9498(&m->pos,0,D_001A4BE0[0].target,0.25f))m->pos=D_L01_001EAAB0[0];
  if(m->pos.x<2.0f || m->pos.x>1021.0f || m->pos.y<2.0f || m->pos.y>1021.0f || m->pos.z<2.0f || m->pos.z>1021.0f){
destroy:
   func_003BD360(m);return;
  }
  if(func_003883C8(&p->timera) && !D_001DD08C_sda){
   m->state=3;p->timer14=D_001DD080_sda;D_001DD08C_sda=m;func_L01_0033EA68(m);
  }
  break;
 case 3:
  m->anglex=func_00389380(m->anglex,p->anglex);
  m->angley=func_00389380(m->angley,p->angley);
  func_L01_0033FAD8(m);func_L01_0033EC00(m);
  if(p->timer8>=60)func_L01_0033E828(m);
  func_L01_004026A0(func_L01_0033ED90,m);
  func_00388398(&p->timer14);
  if(p->timer14){
   float radius=D_001DD088_sda+(D_001DD084_sda-D_001DD088_sda)*((float)p->timer14/(float)D_001DD080_sda);
   if(func_L01_003F9498(&m->pos,2,D_001A4BE0[0].target,radius))m->pos=D_L01_001EAAB0[0];
  }
  func_L01_0033E6E8(m);
  if(func_003883C8(&p->timer8)){
   qzero(&oldpos);
   func_L01_00447D00(m,&oldpos,&m->pos,5,2,4,-1,1,5,-1,0,0x1010001,0.0f,0.0f,4.0f,2.0f,9.0f,1.0f,15.0f);
   D_001DD08C_sda=0;m->state=90;
  }
  break;
 case 90:
  func_003BD360(m);
  break;
 }
}
/* localdecomp:end func_L01_0033E068 */
