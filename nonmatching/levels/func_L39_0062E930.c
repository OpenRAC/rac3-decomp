/* NTSC-U draft (2026-11-14, Codex worker): C of func_L39_0062C118, the NTSC-U twin of func_L39_0062E930, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 7 words differ with its file's flags.
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L39_0062C118 */
extern u8 D_L39_004998A0[];
extern void func_L39_0062FD10(void *,void *,void *,float),func_L39_006301D8(void *,void *,void *,float),func_L39_00630140(void *,void *,void *,float);
extern float func_L39_0062FE30(void *,void *);
extern int func_L39_005C2098(int,int);
extern void func_003BEBF8(float *,float,float);
void func_L39_0062C118(u8 *g) {
 union {vu0_v4 vec;u32 buf[2];} work;
 vu0_v4 spare1,spare2;
 float speed;
 u8 *p;
 int state;
 { u8 *ip=g+0x19e4;
 if(!g[0x19e4]) state=0;
 else {
  int n=g[0x19e4],k=((int)ip-n)&7,j,base=n+1;u8 *d=(u8 *)work.buf;
  for(j=0;j<40;j+=5) *d++=D_L39_004998A0[base+((k+j)&7)*255];
  work.buf[0]^=(u32)ip;work.buf[1]^=work.buf[0];state=work.buf[1];
 }
}
 p=g+0x19e4;
 if((state^27)!=0 || *(int *)(g+0x2f0)>=10) {
  if(*(int *)(g+0x2f0)<*(short *)(g+0x14bc)) {
   func_L39_0062FD10(g,(g+0x120),(g+0x120),0.0f);func_L39_006301D8(g,(g+0x120),(g+0x120),0.013333333656191826f);
  } else if(g[0x14ac]) {
   func_L39_0062FD10(g,(g+0x120),(g+0x120),0.0f);func_L39_006301D8(g,(g+0x120),(g+0x120),0.015000000596046448f);
  } else {
   float x,limit;
   func_L39_006301D8(g,(g+0x120),(g+0x120),*(float *)(g+0x1530));
   x=func_L39_0062FE30(g,(g+0x120));limit=-*(float *)(g+0x14b0);if(x<limit)x=limit;
   func_L39_0062FD10(g,(g+0x120),(g+0x120),x);
  }
 }
 { u8 *ip=p;
 if(!g[0x19e4]) state=0;
 else {
  int n=g[0x19e4],k=((int)ip-n)&7,j,base=n+1;u8 *d=(u8 *)work.buf;
  for(j=0;j<40;j+=5) *d++=D_L39_004998A0[base+((k+j)&7)*255];
  work.buf[0]^=(u32)ip;work.buf[1]^=work.buf[0];state=work.buf[1];
 }
}
 if((state^14)==0) {
  float x,target;
  __asm__("lqc2 $vf1,%1\n lqc2 $vf2,%2\n vsub.xyz $vf1,$vf1,$vf2\n sqc2 $vf1,%0":"=m"(work.vec):"m"(*(vu0_v4 *)(g+0xa0)),"m"(*(vu0_v4 *)(g+0x1470)):"vf1","vf2");
  x=func_L39_0062FE30(g,&work.vec);target=0.11666667461395264f;
  if(x>2.1f) target=0.05250000208616257f;else if(x>1.7f)target=0.08166667073965073f;
  if(*(int *)(g+0x2f0)<8) {
   speed=func_L39_0062FE30(g,(g+0x120));
   if(speed<target)func_003BEBF8(&speed,target,0.0416666679084301f);
   func_L39_0062FD10(g,(g+0x120),(g+0x120),speed);
  }
 } else {
  int zero=*(float *)(g+0x14c0)==0.0f && *(float *)(g+0x14c4)==0.0f;
  int mask=func_L39_005C2098(64,*(int *)(g+0x2544));
  u8 *o=*(u8 **)(g+0x2534);
  if((*(int *)(o+0x1a0)&mask) || zero) goto accelerate;
  { u8 *ip=p;
 if(!g[0x19e4]) state=0;
 else {
  int n=g[0x19e4],k=((int)ip-n)&7,j,base=n+1;u8 *d=(u8 *)work.buf;
  for(j=0;j<40;j+=5) *d++=D_L39_004998A0[base+((k+j)&7)*255];
  work.buf[0]^=(u32)ip;work.buf[1]^=work.buf[0];state=work.buf[1];
 }
}
  if((state^18)==0) {
accelerate:
   {
   if(*(float *)(g+0x14b8)<(*(float *)(g+0x151c)) && *(int *)(g+0x2f0)<=*(short *)(g+0x1528)) {
    float x;
    *(float *)(g+0x14b8)+=((*(float *)(g+0x151c))-*(float *)(g+0x1518))/(float)*(short *)(g+0x1528);
    if((*(float *)(g+0x151c))<*(float *)(g+0x14b8)) *(float *)(g+0x14b8)=(*(float *)(g+0x151c));
    x=*(float *)(g+0x14b8);x=x+x;x=x**(float *)(g+0x1530);
    x=sqrt_asm(x);x=x-*(float *)(g+0x14c4);x=x-*(float *)(g+0x14c0);
    *(float *)(g+0x14c0)=*(float *)(g+0x14c0)+x;
   }
  }
  }
  if(*(int *)(g+0x2f0)>=*(short *)(g+0x14bc)) {
   if(*(float *)(g+0x14c0)>0.0f) {
    func_L39_00630140(g,(g+0x120),(g+0x120),*(float *)(g+0x14c0));
    *(float *)(g+0x14c4)=*(float *)(g+0x14c4)+*(float *)(g+0x14c0);*(float *)(g+0x14c0)=0.0f;
   }
  }
  if(g[0x14ad] && *(int *)(g+0x2f0)>=*(int *)(g+0x1440) && *(int *)(g+0x2f0)<*(int *)(g+0x1444)) {
   typedef struct {float initial,delta;int duration,pad;} Step;
   typedef struct {int a,b,c,d,e;Step *steps;int index,tick;float value;} Track;
   Track *t=(Track *)(g+0x1440);Step *s;
   t->tick++;
   while(t->index==-1 || t->tick>=t->steps[t->index].duration) {
     t->index++;t->tick=0;
     if(t->steps[t->index].initial!=-999999.0f)t->value=t->steps[t->index].initial*0.00027777778450399637f;

   }
   if(t->tick>0)t->value+=t->steps[t->index].delta*0.00027777778450399637f;
   func_L39_00630140(g,(g+0x120),(g+0x120),t->value);
  }
 }
}
/* localdecomp:end func_L39_0062C118 */
