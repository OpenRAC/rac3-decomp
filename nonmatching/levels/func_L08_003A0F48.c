/* NTSC-U draft (2026-11-14, Codex worker): C of func_L08_0039F378, the NTSC-U twin of func_L08_003A0F48, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/08_aquatos/L08_003A0F48.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L08_0039F378 */
typedef struct { float x,y,z,w; } __attribute__((aligned(16))) V4_39F378;
extern int func_0037E1D8(int);
extern float func_0037E2A8(void);
extern float func_0037E250(float,float);
extern float func_00388960(float);
extern float func_00388978(float);
extern void func_L01_00467BD8(void*,int,int,int,float,float);
void func_L08_0039F378(char *m) {
 V4_39F378 pos;
 float angle,r,a,b;
 int life;
 if (!*(unsigned char *)(m+0x31)) return;
 if (!func_0037E1D8(14)) {
  angle=func_0037E2A8();
  r=func_0037E250(0.0f,0.1f);
  a=func_0037E250(0.0f,1.0f)*0.5f;
  b=func_0037E250(1.0f,2.0f)*0.5f;
  life=(int)func_0037E250(180.0f,240.0f);
  pos.x=func_00388960(angle)*r;
  pos.y=func_00388978(angle)*r;
  pos.z=0.0f;
  __asm__("lqc2 vf2,%2\n\tlqc2 vf1,%1\n\tvadd.xyz vf1,vf1,vf2\n\tsqc2 vf1,%0" : "=m"(pos) : "m"(pos),"m"(*(V4_39F378 *)(m+0x10)) : "vf1","vf2");
  func_L01_00467BD8(&pos,0x40005840,0x5840,life,a,b);
 }
 if (!func_0037E1D8(4)) {
  angle=func_0037E2A8();
  r=func_0037E250(0.0f,0.1f);
  a=func_0037E250(0.0f,3.5f)*0.5f;
  b=func_0037E250(3.5f,4.5f)*0.5f;
  life=(int)func_0037E250(180.0f,240.0f);
  pos.x=func_00388960(angle)*r;
  pos.y=func_00388978(angle)*r;
  pos.z=0.0f;
  __asm__("lqc2 vf2,%2\n\tlqc2 vf1,%1\n\tvadd.xyz vf1,vf1,vf2\n\tsqc2 vf1,%0" : "=m"(pos) : "m"(pos),"m"(*(V4_39F378 *)(m+0x10)) : "vf1","vf2");
  func_L01_00467BD8(&pos,0x30005840,0x7040,life,a,b);
 }
}
/* localdecomp:end func_L08_0039F378 */
