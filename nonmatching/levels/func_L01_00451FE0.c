/* NTSC-U draft (Codex wave 3): C of func_L01_0044ED60, the NTSC-U twin of func_L01_00451FE0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 148 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_0044ED60", whose code is not the PAL one).
 * Worker's note: 148 diff; allowed flags verified once; frame 0x140 vs retail 0x190, sd/ld 8-byte slots vs sq/lq 16-byte slots; documented compiler profile mismatch; additional VU/loop scheduling; no unlisted flags tried; best log func_L01_0044ED60.01.log
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_0044ED60 */
extern void func_L01_004367A0(void *, int *, int *);
extern float func_0037E2A8(void);
extern float func_0037E250(float,float);
extern float func_00388960(float);
extern float func_00388978(float);
extern void func_003888C8(void *,void *,void *);
extern int D_L01_001D673C;
extern int func_0037E208(int,int);
extern int func_L01_003F5830(void *,int,int,int,void *,void *,void *,int,int,int,int,float,float);
typedef void (*Callback)(int,void *,int,int,int,float,float);
extern Callback *func_L01_00438468(int,int);
extern void func_L01_003D31A8(int,void *,int,int,int,float);
void func_L01_0044ED60(unsigned char *m,int mask,void *pos,float x,float y,float z,float w,
 unsigned char type,float speed,float angle,int life,int v,int enable,int arg,float f,float g,int tail,int tailarg) {
 int ids[15]; vu0_v4 vec; int unused1,unused2; int count=0; int i;
 for(i=0;i<15;i++) {
  if(((mask>>i)^1)&1) continue;
  {
   float a,b,scale;
   func_L01_004367A0(m,&unused1,&unused2);
   a=func_0037E2A8();
   scale=func_0037E250(x,y)*0.0166666675f;
   vec.x=func_00388960(a)*scale;
   vec.y=func_00388978(a)*scale;
   vec.z=0;
   vec.z=func_0037E250(z,w)*0.0166666675f;
   if(D_L01_001D673C) func_003888C8(&vec,&vec,m+0xc0);
   __asm__("lqc2 $vf1, %1
 lqc2 $vf2, %2
 vadd.xyz $vf1, $vf1, $vf2
 sqc2 $vf1, %0" : "=m"(vec) : "m"(vec),"m"(*(vu0_v4 *)pos) : "vf1","vf2");
   if(angle==-1.0f) angle=func_0037E250(90.0f,270.0f);
   if(speed==-1.0f) b=func_0037E250(10.0f,20.0f);
   else b=func_0037E250(speed*0.7f,speed*1.3f);
   speed=b;
   life=life>180?func_0037E208(180,life):life;
   ids[i]=func_L01_003F5830(m,2,*(short *)(m+0xaa),i,m+0x10,m+0xf0,&vec,type,life,v,128,angle,b);
   if(ids[i]) count++;
  }
 }
 if(enable) { Callback *cb=func_L01_00438468(0x1cd7,4); if(cb) (*cb)(count,ids,arg,7,5,f,-100000.0f); }
 if(tail) func_L01_003D31A8(count,ids,tail,tailarg,30,g);
}
/* localdecomp:end func_L01_0044ED60 */
