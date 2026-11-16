/* NTSC-U draft (Codex wave 3): C of func_L01_00409448, the NTSC-U twin of func_L01_0040B858, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 222 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_00409448", whose code is not the PAL one).
 * Worker's note: 222 diff; baseline plus cached-state and switch forms give identical 222; default-pointer movn and VU0/EE interleaving remain; NEEDS divs row 'func_L01_00409448 0 0 0 2 2 2 2 0 2 2 2 2 2 2'; best log func_L01_00409448.01.log
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_00409448 */
typedef struct {vu0_v4 from,to; int state,time;} W51Line;
typedef struct {
 int fadein,fadeout; float fade; int a,b; float width,widthScale,first;
 float p0,p1,p2,p3,step;int count; char pad[8];
 void *a40,*a44,*a48;int texture;
} W51Params;
typedef struct {void *a,*b,*cross;float length,width,other;float *f0,*f1,*f2,*f3;int a28,b2c;} W51Draw;
extern W51Params D_L01_002C54F0;
extern int D_L01_001DFBC0;
__asm__(".extern D_L01_001DFBC0,16");
extern int D_001DFBC0_sda;
extern int D_001D6430_sda;
__asm__(".extern D_001D6430_sda,4");
extern int D_001D6450_sda;
__asm__(".extern D_001D6450_sda,4");
extern int D_001D6410_sda;
__asm__(".extern D_001D6410_sda,4");
extern vu0_v4 D_L01_001E2A40;
extern float func_00388770(void*);
extern void func_00388830(void*,void*,float);
extern void func_00388758(void*,void*,void*);
extern float func_L01_0040CFE8(float,float);
extern void func_003A3EF0(int,unsigned long);
extern unsigned long func_00384EC0(int);
extern void func_00388018(void);
extern void func_003886E8(void*,void*,float);
extern void func_L01_00408FB0(void*,void*);
static __inline__ void w51sub(vu0_v4 *d,vu0_v4 *a,vu0_v4 *b) {
 __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*d):"m"(*a),"m"(*b):"vf1","vf2");
}
static __inline__ void w51add(vu0_v4 *d,vu0_v4 *a,vu0_v4 *b) {
 __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*d):"m"(*a),"m"(*b):"vf1","vf2");
}
static __inline__ void w51add2(vu0_v4 *d,vu0_v4 *a,vu0_v4 *b) {
 __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(*d):"m"(*a),"m"(*b):"vf1","vf2");
}
void func_L01_00409448(W51Line *line,W51Params *p) {
 vu0_v4 dir,cam,cross,from,to; W51Draw draw; float vals[4];
 float wide,total,current,firstWide,seg,end,next,r,inv; int elapsed;
 if(!line->state)return;
 if(!p)p=&D_L01_002C54F0;
 if(line->state==2) {
  elapsed=D_L01_001DFBC0-line->time;
  if(elapsed>=p->fadeout) {line->state=0;line->time=0;return;}
  wide=1.0f-(float)elapsed/(float)p->fadeout;
 } else if(line->time>0) {
  elapsed=D_001DFBC0_sda-line->time;
  if(elapsed>=p->fadein) {line->time=0;wide=1.0f;}
  else wide=(float)elapsed/(float)p->fadein*p->fade;
 } else wide=1.0f;
 wide=wide*p->width;firstWide=wide*p->widthScale;
 w51sub(&dir,&line->to,&line->from);
 total=func_00388770(&dir);
 current=0.0f;
 func_00388830(&dir,&dir,1.0f);
 w51sub(&cam,&D_L01_001E2A40,&line->from);
 func_00388758(&cross,&cam,&dir);
 func_00388830(&cross,&cross,1.0f);
 if(!p->a40)p->a40=&D_001D6430_sda;
 if(!p->a44)p->a44=&D_001D6450_sda;
 if(!p->a48)p->a48=&D_001D6410_sda;
 r=func_L01_0040CFE8((float)D_L01_001DFBC0,1.0f/p->p0);
 inv=1.0f/p->p1;
 vals[1]=r/(1.0f/p->p0)-8.0f;
 r=func_L01_0040CFE8((float)D_L01_001DFBC0,inv);
 inv=1.0f/(p->p0*p->p2);
 vals[0]=r/(1.0f/p->p1)-8.0f;
 r=func_L01_0040CFE8((float)D_L01_001DFBC0,inv);
 inv=1.0f/(p->p1*p->p3);
 vals[3]=r/(1.0f/(p->p0*p->p2))-8.0f;
 r=func_L01_0040CFE8((float)D_L01_001DFBC0,inv);
 vals[2]=r/(1.0f/(p->p1*p->p3))-8.0f;
 draw.a=&from;draw.b=&to;draw.cross=&cross;
 draw.other=wide;draw.width=wide;draw.f0=&vals[0];draw.f1=&vals[1];draw.f2=&vals[2];draw.f3=&vals[3];draw.a28=p->a;draw.b2c=p->b;
 func_003A3EF0(8,0);
 func_003A3EF0(20,0xff9000000260UL);
 func_003A3EF0(71,0x513f1);
 func_003A3EF0(6,func_00384EC0(p->texture));
 func_00388018();
 seg=p->first;
 if(seg>0.0f) {
  if(total<seg)seg=total;
  from=line->from;
  func_003886E8(&to,&dir,seg);
  current=seg+current;
  w51add(&to,&to,&line->from);
  draw.width=firstWide;draw.length=seg;
  func_L01_00408FB0(p,&draw);
  draw.width=wide;
 }
 end=total-0.05f;
 while(current<end) {
  seg=total-current;
  if(p->step*(float)p->count<seg)seg=p->step*(float)p->count;
  func_003886E8(&from,&dir,current);
  next=current+seg;
  w51add2(&from,&from,&line->from);
  func_003886E8(&to,&dir,next);
  current=next;
  w51add2(&to,&to,&line->from);
  draw.length=seg;
  func_L01_00408FB0(p,&draw);
 }
 func_003A3EF0(71,0x5360b);
}
/* localdecomp:end func_L01_00409448 */
