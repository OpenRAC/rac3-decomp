/* NTSC-U draft (Codex wave 3): C of func_L02_00317890, the NTSC-U twin of func_L02_00317D28, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 497 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L02_00317890", whose code is not the PAL one).
 * Worker's note: 497 diff; 10 checks; swapped equal 0.8 stores and separate life sum improve499; remaining global vector stores, VU0 interleaving and particle allocation; NEEDS divs row 'func_L02_00317890 2 0' injected by native_divs.py; switch evidence ...
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L02_00317890 */
typedef union {int i[24];float f[24];} W51Vars;
extern void *D_001A71A0[];
__asm__(".extern D_001A71A0,16");
extern char D_L02_0026F820[];
extern unsigned char D_001BBC40[];
extern int D_001D545C_sda;
extern int D_001D545C;
extern char D_001A4BE0[];
extern unsigned char *D_001D52FC;
extern int D_L02_002CF1F0[];
extern int D_001D6694_sda;
extern int D_L02_001D673C;
extern int D_001D673C_sda;
extern int D_001DC6F0_sda;
extern unsigned char *D_L02_001DEA1C;
__asm__(".extern D_L02_001DEA1C,16");
extern vu0_v4 D_L02_001DE650;

extern vu0_v4 D_001A4C90;
extern float D_L02_001DE358;
extern char D_L02_0021E158[];
extern unsigned char D_001A71C5[];
extern void func_L02_003B8810(void*,void*);
extern void func_L01_004A6DF8(void*,int);
extern float func_00388800(void*,void*);
extern void func_L02_00318460(void*);
extern void func_0039FE80(int,int,void*);
extern void func_L01_00441FB8(void*,int,int);
extern float func_0037E2A8(void);
extern void func_L02_004DDCE8(void*,void*,int);
extern void func_L01_0050DA68(void*,int,float);
extern void func_L01_00443648(void*,void*,int,float,float,float,int,int,int);
extern void func_L02_003189C0(void*);
extern void func_L02_003187D0(int);
extern void func_L02_00318578(void*,void*);
extern int func_L01_0050DAC0(void);
extern void func_L02_004CF3B8(int,int);
extern void func_003BFC18(void*,void*,int);
extern void func_L01_0044E358(void*,void*,void*);
extern void func_00388830(void*,void*,float);
extern void func_L01_004F12C0(void*,void*,int,int);
extern int func_L01_00452EC8(void*);
extern float func_00388978(float);
extern float func_00388960(float);
extern float func_0037E250(float,float);
extern int func_0037E208(int,int);
extern int func_0037E1D8(int);
extern unsigned char *func_L01_0046C468(void*,void*,int,int,int,int,int,int,float,float,float);
extern float func_00389380(float,float);
extern void func_L02_00319540(void*);
extern void func_003BEBF8(void*,float,float);
extern void func_L02_00318910(void);
extern void func_L02_004D31B8(int);
extern void func_L01_004026A0(void*,void*);
extern char D_L02_00318528[];
extern void func_L01_004282C0(int,int);
extern int func_00388398(void*);
extern int func_003894A0(unsigned int,unsigned int,float);
extern int D_001DC6F8_sda;
__asm__(".extern D_001DC6F8_sda,4");
extern int D_001DC6FC_sda;
__asm__(".extern D_001DC6FC_sda,4");
extern int D_001DC700_sda;
__asm__(".extern D_001DC700_sda,4");
extern float D_001DC704_sda;
__asm__(".extern D_001DC704_sda,4");
extern float D_001DC708_sda;
__asm__(".extern D_001DC708_sda,4");
extern float D_001DC70C_sda;
__asm__(".extern D_001DC70C_sda,4");
extern float D_001DC710_sda;
__asm__(".extern D_001DC710_sda,4");
extern float D_001DC714_sda;
__asm__(".extern D_001DC714_sda,4");
extern float D_001DC718_sda;
__asm__(".extern D_001DC718_sda,4");
extern float D_001DC71C_sda;
__asm__(".extern D_001DC71C_sda,4");
extern float D_001DC720_sda;
__asm__(".extern D_001DC720_sda,4");
extern float D_001DC724_sda;
__asm__(".extern D_001DC724_sda,4");
__asm__(".extern D_001D545C_sda,4");
__asm__(".extern D_001D6694_sda,4");
__asm__(".extern D_001D673C_sda,4");
__asm__(".extern D_001DC6F0_sda,4");
static __inline__ void w51sub6(vu0_v4 *d,vu0_v4 *a,vu0_v4 *b) {
 __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*d):"m"(*a),"m"(*b):"vf1","vf2");
}
static __inline__ void w51add6(vu0_v4 *d,vu0_v4 *a,vu0_v4 *b) {
 __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*d):"m"(*a),"m"(*b):"vf1","vf2");
}
typedef struct W66Moby {
 char pad0[0x10]; vu0_v4 position; unsigned char state; char pad21[3]; unsigned char *data;
 char pad28[8]; unsigned char opacity; char pad31[3]; unsigned short flags;
 char pad36[0x32]; W51Vars *vars; char pad6c[0xc]; int color;
 char pad7c[0x1c]; int flags98; char pad9c[0x24]; char matrix[0x20];vu0_v4 rotation;
 char padf0[8];float angle;
} W66Moby;
void func_L02_00317890(W66Moby *m) {
 vu0_v4 pos,temp;float matrix[12] __attribute__((aligned(16)));
 W51Vars *p=m->vars,*q;

 switch(m->state) {
 case 0:
  m->opacity=255;
  func_L02_003B8810(D_001A71A0[0],D_L02_0026F820);
  func_L01_00441FB8(m,1,-1);
  break;
 case 1: {
 unsigned char *hero;
  if((p->i[2]>=0 && !(D_001BBC40[p->i[2]+D_001D545C_sda*16]&128)) ||
     (p->i[3]>=0 && (D_001BBC40[p->i[3]+D_001D545C_sda*16]&128) && p->i[1]==-1)) {
   m->flags98=0;
   m->flags=(m->flags|0x41)&0xefff;
   func_L01_004A6DF8(m,1);break;
  }
  m->flags&=0xffbe;
  m->flags|=*(unsigned short*)(m->data+0x44)&0x1000;
  m->flags98=*(int*)(m->data+0x10);
  if(p->i[0]==-1)break;
  hero=D_001A4BE0;
  if( *(unsigned char**)(hero+0x35c)!=m || *(short*)(hero+0x36e) || *(int*)(hero+0x25c4)==20 || hero[0x25e4])break;
  if(!(func_00388800((unsigned char*)m+0x10,hero+0x80)<0.5f) || *(int*)(hero+0x25c4)==128)break;
  func_L02_00318460(m);
  if(!(*(int*)(D_001D52FC+0x1a4)&16) || D_L02_002CF1F0[0]!=12 || D_001D6694_sda==2)break;
  func_0039FE80(0,0,m);
  *(unsigned short*)(*(unsigned char**)(hero+0x25c0)+0x34)|=0x2000;
  func_L01_00441FB8(m,2,-1);
  p->f[0x44/4]=func_0037E2A8();
  p->f[0x48/4]=0.02908882312476635f;
  p->f[0x4c/4]=0.8f;p->f[0x18/4]=0.8f;p->f[0x1c/4]=1.0f;p->f[0x14/4]=0.3f;
  if(D_L02_001D673C) {
   w51sub6(&pos,(vu0_v4*)((unsigned char*)m+0x10),(vu0_v4*)(hero+0x80));
   func_L02_004DDCE8((unsigned char*)m+0x10,&pos,0);
  } else func_L01_0050DA68((unsigned char*)m+0x10,0,m->angle);
  func_L01_00443648(m,(unsigned char*)m+0x10,0x10000,1.5f,20.0f,1.0f,0,1,0);
  break;
 }
 case 2: {int n;
  func_L02_003189C0(m);
  func_L02_003187D0(-1);
  func_L02_00318578(m,&D_001DC6F0_sda);
  n=func_L01_0050DAC0();
  if(n==2) {
   func_L02_004CF3B8(116,1);
   p->f[0x24/4]=1.95f;
   func_L01_00441FB8(m,3,-1);
  } else if(n==0)func_L01_00441FB8(m,4,-1);
  break;
 }
 case 3: {
 unsigned char *hero,*target; vu0_v4 *targetpos;
  hero=D_001A4BE0;
  if(*(unsigned char*)(*(unsigned char**)(hero+0x25c0)+0x23)>=13) {
   func_L02_003187D0(-1);func_L02_00318578(m,&D_001DC6F0_sda);func_L02_003189C0(m);break;
  }
  hero[0x25e5]=1;
  if(p->i[0x28/4]>=0) {func_L01_00441FB8(m,5,-1);break;}
  target=D_L02_001DEA1C+p->i[0]*256;
  if(p->i[1]!=-1 && (D_001BBC40[p->i[3]+D_001D545C*16]&128))target=D_L02_001DEA1C+p->i[1]*256;
  q=*(W51Vars**)(target+0x68);
  targetpos=(vu0_v4*)(target+0x10); pos=*targetpos;
  if(p->i[0x50/4]==1) {
   D_L02_001DE650.z=200.0f;D_L02_001DE650.y=400.0f;D_L02_001DE650.x=200.0f;
   D_001A4C90=D_L02_001DE650;
   func_003BFC18((unsigned char*)m+0x10,&temp,0);func_L01_0044E358((unsigned char*)m+0xc0,&temp,matrix);
   func_003BFC18(targetpos,&temp,0);func_L01_0044E358(target+0xc0,&temp,matrix);
  } else if(p->i[0x50/4]==2) {
   D_L02_001DE650.x=526.9219970703125f;D_L02_001DE650.y=200.0f;D_L02_001DE650.z=819.2620239257812f;
   D_001A4C90=D_L02_001DE650;
   func_003BFC18((unsigned char*)m+0x10,&temp,0);func_L01_0044E358((unsigned char*)m+0xc0,&temp,matrix);
   func_003BFC18(targetpos,&temp,0);func_L01_0044E358(target+0xc0,&temp,matrix);
  }
  if(!D_L02_001D673C)pos.z+=0.2f;
  else {func_00388830(&temp,target+0xe0,0.75f);w51add6(&pos,&temp,&pos);}
  func_L01_004F12C0(&pos,target+0xf0,0,1);
  p->f[0x40/4]=0.6f;
  if(p->i[0x28/4]<0)D_L02_001DE358=0.6f;
  target[0x20]=4;q->i[0x24/4]=0;
  q->f[0x44/4]=p->f[0x44/4];q->f[0x48/4]=p->f[0x48/4];q->f[0x4c/4]=p->f[0x4c/4];
  q->f[0x14/4]=p->f[0x14/4];q->f[0x18/4]=p->f[0x18/4];q->f[0x1c/4]=p->f[0x1c/4];
  func_0039FE80(1,0,target);func_L01_00441FB8(m,1,-1);p->f[0x24/4]=1.95f;
  break;
 }
 case 4: {
 unsigned char *particle; float angle,step,size,life;int i,n,extra;
  if(func_L01_00452EC8(m)) {
   p->f[0x40/4]=0.6f;angle=0.0f;step=6.2831854820251465f/(float)D_001DC6F8_sda;
   for(i=0;i<D_001DC6F8_sda;i++) {
    *(vu0_q*)&temp=0;extra=0;
    temp.x=D_001DC71C_sda*func_00388978(angle);
    temp.y=D_001DC71C_sda*func_00388960(angle);
    temp.z=D_001DC720_sda;
    pos=temp;temp=*(vu0_v4*)((unsigned char*)m+0x10);
    temp.z+=func_0037E250(0.3f,1.6f);
    pos.z=0.0f;
    func_00388830(&pos,&pos,(D_001DC704_sda+func_0037E250(-D_001DC708_sda,D_001DC708_sda))*0.0166666675f);
    n=func_0037E208(D_001DC6FC_sda,D_001DC700_sda);
    size=D_001DC70C_sda+func_0037E250(-D_001DC710_sda,D_001DC710_sda);
    life=D_001DC714_sda+func_0037E250(-D_001DC718_sda,D_001DC718_sda);
    {int variant=func_0037E1D8(2);
    life*=0.000277777785f;
    particle=func_L01_0046C468(&temp,&pos,n,0x108f10,variant?-1:1,64,32,0,size*210000.0f,size*210000.0f,life);
    if(particle) {extra=(unsigned char)particle[8]+32;particle[2]=**(unsigned char**)(D_L02_0021E158+0x164);}
    particle=func_L01_0046C468(&temp,&pos,n,0xf7f7f7,func_0037E1D8(2)?-1:1,48,48,0,size*D_001DC724_sda*210000.0f,size*D_001DC724_sda*210000.0f,life);
    if(particle) {particle[8]=extra;particle[2]=**(unsigned char**)(D_L02_0021E158+0x164);}
    angle=func_00389380(angle,step);}
   }
  }
  p->f[0x40/4]-=0.075f;if(p->f[0x40/4]<0.0f)p->f[0x40/4]=0.0f;
  if(p->i[0x28/4]<0)D_L02_001DE358=p->f[0x40/4];
  if(p->f[0x24/4]<1.95f && *(unsigned char*)((char*)D_001A71A0[0]+0x23)<110) {
   func_L02_003187D0(1);func_L02_00318578(m,&D_001DC6F0_sda);func_L02_00319540(m);
   func_003BEBF8(&p->f[0x24/4],1.95f,0.0166666675f);
  } else {func_L02_00318910();func_L01_00441FB8(m,1,-1);}
  break;
 }
 case 6:
  if(func_L01_00452EC8(m))p->i[0x2c/4]=0;
  p->f[0x2c/4]+=0.02f;D_001A71C5[0]=1;
  if(p->f[0x2c/4]>=1.2f) {
   func_L02_004D31B8(0);func_L01_00441FB8(m,4,-1);p->i[0x24/4]=0;func_0039FE80(1,0,m);
  }
  func_L01_004026A0(D_L02_00318528,m);
  break;
 case 5: {unsigned char *target;
  if(func_L01_00452EC8(m))p->f[0x2c/4]=1.0f;
  p->f[0x2c/4]-=0.02f;D_001A71C5[0]=1;
  if(p->f[0x2c/4]<=-0.2f) {
   target=D_L02_001DEA1C+p->i[0]*256;
   target[0x20]=6;func_L01_00441FB8(m,1,-1);p->f[0x24/4]=1.95f;
   func_L01_004282C0(p->i[0x28/4],p->i[0x30/4]>=0?p->i[0x30/4]:0);
   pos=*(vu0_v4*)(target+0x10);pos.z+=0.2f;
   func_L01_004F12C0(&pos,target+0xf0,116,1);
   func_L01_00441FB8(m,1,-1);
  }
  func_L01_004026A0(D_L02_00318528,m);
  break;
 }
 }
 if(func_00388398(&p->i[0x38/4]))p->i[0x38/4]=60;
 m->color=func_003894A0(0x80b0b0b0,0x80505050,func_00388978((float)p->i[0x38/4]*6.2831854820251465f/60.0f)*0.5f+0.5f);
}
/* localdecomp:end func_L02_00317890 */
