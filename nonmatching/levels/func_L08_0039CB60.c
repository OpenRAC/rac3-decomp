/* NTSC-U draft (2026-11-14, Codex worker): C of func_L08_0039B108, the NTSC-U twin of func_L08_0039CB60, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/08_aquatos/L08_0039C930.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L08_0039B108 */
typedef struct { float x,y,z,w; } __attribute__((aligned(16))) V4_39B108;
extern int D_001DE07C_sda, D_001DE084_sda, D_001DE088_sda;
extern int D_001DE030_sda, D_001DE034_sda, D_001DE038_sda, D_001DE050_sda;
extern int D_001DE068_sda, D_001DE06C_sda, D_001DE070_sda, D_001DE074_sda, D_001DE078_sda;
extern float D_001DE080_sda, D_001DE08C_sda, D_001DE090_sda, D_001DE094_sda, D_001DE098_sda, D_001DE09C_sda, D_001DE0A0_sda;
extern float D_001DE03C_sda, D_001DE040_sda, D_001DE044_sda, D_001DE048_sda, D_001DE04C_sda, D_001DE054_sda, D_001DE058_sda, D_001DE05C_sda, D_001DE060_sda, D_001DE064_sda;
extern float func_0037E250(float,float);
extern int func_0037E208(int,int);
extern float func_0037E2A8(void);
extern float func_00388960(float);
extern float func_00388978(float);
extern void func_00388830(void *,void *,float);
extern void func_003BF6A8(void *,float);
extern int func_003894A0(int,int,float);
extern void func_L01_00470258(void*,void*,int,int,short,int,float);
extern void func_L01_0045FEC8(void*,void*,void*,int,int,int,int,int,int);
void func_L08_0039B108(char *m) {
 V4_39B108 base, pos, vel, other;
 int i,j,a,b;
 float r, angle, speed, z;
 base=*(V4_39B108 *)(m+0xe0);
 for(i=0;i<D_001DE07C_sda;i++) {
  func_00388830(&pos,&base,func_0037E250(D_001DE08C_sda,D_001DE090_sda)*0.0166666675f);
  func_003BF6A8(&pos,D_001DE0A0_sda*0.0166666675f);
  func_00388830(&vel,&base,D_001DE080_sda);
  __asm__("lqc2 vf2,%1\n\tlqc2 vf1,%2\n\tvadd.xyz vf2,vf2,vf1\n\tsqc2 vf2,%0" : "=m"(vel) : "m"(vel), "m"(*(V4_39B108 *)(m+0x10)) : "vf1","vf2");
  func_003BF6A8(&vel,D_001DE09C_sda);
  r=func_0037E250(D_001DE094_sda,D_001DE098_sda)*210000.0f;
  a=(short)func_0037E208(120,240);
  func_L01_00470258(&vel,&pos,D_001DE084_sda,D_001DE088_sda,a,0,r);
 }
 for(i=0;i<D_001DE030_sda;i++) {
  pos=*(V4_39B108 *)(m+0x10);
  func_003BF6A8(&pos,D_001DE04C_sda);
  pos.z+=1.3f;
  angle=func_0037E2A8();
  speed=func_0037E250(D_001DE05C_sda,D_001DE040_sda)*0.0166666675f;
  z=func_0037E250(D_001DE044_sda,D_001DE048_sda);
  qzero(&vel);
  vel.x+=func_00388960(angle)*speed;
  vel.y+=func_00388978(angle)*speed;
  vel.z+=z*0.0166666675f;
  other=vel;
  other.z-=func_0037E250(D_001DE03C_sda*0.7f,D_001DE03C_sda*1.3f)*0.000277777785f*D_001DE034_sda;
  for(j=0;j<D_001DE050_sda;j++) {
   r=func_0037E250(0.5f,1.5f);
   vel.w=r*D_001DE060_sda;
   other.w=r*D_001DE064_sda;
   func_003BF6A8(&pos,D_001DE054_sda);
   func_003BF6A8(&other,D_001DE058_sda*0.0166666675f);
   a=func_003894A0(D_001DE068_sda,D_001DE070_sda,func_0037E250(0.0f,1.0f));
   b=func_003894A0(D_001DE06C_sda,D_001DE074_sda,func_0037E250(0.0f,1.0f));
   func_L01_0045FEC8(&pos,&vel,&other,a,b,D_001DE078_sda,D_001DE034_sda,(int)func_0037E250(D_001DE038_sda*0.5f,D_001DE038_sda*2.5f),-1);
  }
 }
}
/* localdecomp:end func_L08_0039B108 */
