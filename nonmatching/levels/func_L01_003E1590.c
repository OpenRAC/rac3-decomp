/* NTSC-U draft (Codex wave 3): C of func_L01_003DF888, the NTSC-U twin of func_L01_003E1590, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 208 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_003DF888", whose code is not the PAL one).
 * Worker's note: 208 diff; confirmed allowed-flags inline-literal assembler blocker: float literals emit lwc1 gp while retail constructs inline lui/ori/mtc1; real VU add helper retained; best log w120/func_L01_003DF888.01.log
 */
#include "common.h"
/* localdecomp:start func_L01_003DF888 */
typedef struct { float f[4]; } __attribute__((aligned(16))) V_DF888;
extern int func_0037E1D8(int);
extern void func_0037E2F0(void *,float,float);
extern void func_003886E8(void *,void *,float);
extern int func_0037E208(int,int);
extern float func_0037E250(float,float);
extern void func_00388830(void *,void *,float);
extern u8 *func_L01_0046DCB8(void *,void *,int,int,int,int,int,int,float,float,float);
extern void func_L01_004C41E8(void *,void *);
extern void func_L01_00463938(void *,void *,int,float,float);
extern u8 *D_L01_00221174[];
extern u8 *D_L01_002212BC[];
extern u8 *D_L01_002211A0[];
static __inline__ void add_DF888(V_DF888 *d,V_DF888 *a,V_DF888 *b) {
 __asm__("lqc2 vf1,%1\n lqc2 vf2,%2\n vadd.xyz vf1,vf1,vf2\n sqc2 vf1,%0" : "=m"(*d):"m"(*a),"m"(*b):"vf1","vf2");
}
void func_L01_003DF888(u8 *p) {
 V_DF888 pos,dir,scaled,other;
 u8 *particle;
 int n,k;
 if(!func_0037E1D8(3)) {
  func_0037E2F0(&dir,0.03500000014901161f,0.05000000074505806f);
  func_003886E8(&scaled,&dir,10.0f);
  add_DF888(&pos,&scaled,(V_DF888 *)(p+0x10));
  n=func_0037E208(10,30);
  k=func_0037E208(-1,-3);
  particle=func_L01_0046DCB8(&pos,&dir,n,0x5A182,k,64,0,0,126000.0078125f,231000.0f,0.006666666828095913f);
  if(particle) {
   particle[3]=func_0037E1D8(2)?72:68;
   particle[2]=D_L01_00221174[0][0];
  }
 }
 if(!func_0037E1D8(3)) {
  func_0037E2F0(&dir,0.009999999776482582f,0.03999999910593033f);
  func_003886E8(&scaled,&dir,10.0f);
  add_DF888(&pos,&scaled,(V_DF888 *)(p+0x10));
  n=func_0037E208(10,30);
  k=func_0037E208(-1,-3);
  particle=func_L01_0046DCB8(&pos,&dir,n,0x5A182,k,64,0,0,105000.0f,84000.0f,0.006666666828095913f);
  if(particle) {
   particle[3]=func_0037E1D8(2)?72:68;
   particle[2]=D_L01_002212BC[0][0];
  }
 }
 if(!func_0037E1D8(3)) {
  func_0037E2F0(&dir,0.009999999776482582f,0.029999999329447746f);
  func_003886E8(&scaled,&dir,10.0f);
  add_DF888(&pos,&scaled,(V_DF888 *)(p+0x10));
  n=func_0037E208(10,30);
  k=func_0037E208(-1,-3);
  particle=func_L01_0046DCB8(&pos,&dir,n,0x5A182,k,64,0,0,84000.0f,42000.0f,0.006666666828095913f);
  if(particle) {
   particle[3]=func_0037E1D8(2)?72:68;
   particle[2]=D_L01_002211A0[0][0];
  }
 }
 if(!func_0037E1D8(3)) {
  func_0037E2F0(&dir,0.01f,0.03f);
  func_003886E8(&scaled,&dir,20.0f);
  add_DF888(&pos,&scaled,(V_DF888 *)(p+0x10));
  func_L01_004C41E8(p+0x10,&other);
  func_00388830(&other,&other,-func_0037E250(0.01f,0.05f));
  func_L01_00463938(&pos,&other,0x4005A182,-1.0f,-0.004166666883975267f);
 }
}
/* localdecomp:end func_L01_003DF888 */
