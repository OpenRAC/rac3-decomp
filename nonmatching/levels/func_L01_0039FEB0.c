/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_0039E8A0, the NTSC-U twin of func_L01_0039FEB0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L01_0039E1B0.c's current line.
 * Worker's note: 374 diff; best log func_L01_0039E8A0.01.log; allowed default assembler emits float literal pool loads (e.g. 0.37f lwc1 -0x4000(gp)) where retail materializes lui/ori/mtc1; VU0 sequences retained as real operand asm; stack 0x160 correct 374 diff; best log func_L01_0039E8A0.01.log; verified allowed fl
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_0039E8A0 */
extern int D_L01_001DDBCC,D_L01_001DB02C;
extern u8 D_L01_001E2900[],D_001425C0[],D_L01_002C5640[];
extern u8 *D_L01_001EEB00[];
extern void func_0039FE80(int,int,void *);
extern float func_0037E250(float,float),func_0037E2A8(void),func_L01_00440918(float,float),func_00388A28(float,float),func_00389380(float,float),func_00388960(float),func_00388978(float);
extern int func_0037E208(int,int);
extern void func_0037E4B8(void *,float,float,float);
extern void func_L01_004632D8(void *,void *,int,int,float,int);
extern void func_L01_00471248(void *,void *,int);
extern void func_L01_003D46A8(void *,int,int,int,int,float,float);
extern void func_L01_00300250(void *,void *,void *);
extern u8 *func_L01_0032FE90(void *,int,int,int,int,int,int,int,float,float,float,float,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
extern int func_003CF790(void *,int,void *,int,float);
extern void func_00388830(void *,void *,float);
extern void func_L01_00443628(void *,void *,int,void *,float);
extern void func_L01_00443840(void *,void *),func_L01_003D2CF0(void *),func_003BD360(void *);
static __inline__ void add_vec(void *d,void *a,void *b) {
 __asm__("lqc2 $vf2,%2\n lqc2 $vf1,%1\n vadd.xyz $vf1,$vf1,$vf2\n sqc2 $vf1,%0" : "=m"(*(vu0_v4 *)d):"m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b):"vf1","vf2");
}
static __inline__ void delta_vec(void *d,void *a,void *b) {
 __asm__("lqc2 $vf1,%2\n lqc2 $vf2,%1\n vsub.xyz $vf2,$vf2,$vf1\n sqc2 $vf2,%0" : "=m"(*(vu0_v4 *)d):"m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b):"vf1","vf2");
}
void func_L01_0039E8A0(u8 *m) {
 vu0_v4 v90,va0;
 struct {vu0_v4 v; u8 pad10[8];u8 b18,b19;u16 h1a;u8 pad1c[4];int w20;} hit;
 int i,n;u8 *spawn;u8 **items;
 float a,b,c,angle,speed;
 if(m) func_0039FE80(1,0,m);
 for(i=0;i<25-D_L01_001DDBCC;i++) {
  a=func_0037E250(0.0f,0.37f);b=func_0037E2A8();c=func_0037E2A8();func_0037E4B8(&va0,a,b,c);
  va0.z+=func_0037E250(0.35f,0.6f);add_vec(&va0,&va0,m+0x10);
  a=func_0037E250(0.00250000018f,0.0200000014f);b=func_0037E2A8();c=func_0037E2A8();func_0037E4B8(&v90,a,b,c);
  func_L01_004632D8(&va0,&v90,0x4f7f7f7f,0x202020,150000.0f,func_0037E208(30,57));
 }
 for(i=0;i<30-D_L01_001DDBCC;i++) {
  angle=func_00388A28(*(float *)(D_L01_001E2900+0x140)-*(float *)(m+0x10),*(float *)(D_L01_001E2900+0x144)-*(float *)(m+0x14));
  func_L01_00440918(1.0f,2.0f);
  v90.x=*(float *)(m+0x10)+func_L01_00440918(0.0f,0.15f);
  v90.y=*(float *)(m+0x14)+func_L01_00440918(0.0f,0.15f);
  v90.z=*(float *)(m+0x18)+func_L01_00440918(0.0f,0.15f);
  speed=func_0037E250(3.0f,7.0f)*0.0166666675f;
  angle=func_00389380(angle,func_L01_00440918(0.0f,2.61799383f));
  va0.x=func_00388960(angle)*speed;va0.y=func_00388978(angle)*speed;va0.z=0.0f;
  va0.z=func_0037E250(5.0f,10.0f)*0.0166666675f;
  func_L01_00471248(&v90,&va0,170);
 }
 func_L01_003D46A8(m,78,79,10,1,1.5f,1.2f);
 for(i=9;i>=0;i--) {
  a=func_0037E250(0.0f,0.35f);b=func_0037E2A8();c=func_0037E2A8();func_0037E4B8(&va0,a,b,c);
  va0.z+=0.25f;add_vec(&va0,&va0,m+0x10);
  a=func_0037E250(0.0500000045f,0.100000009f);b=func_0037E2A8();func_0037E4B8(&v90,a,b,1.22173047f);
  v90.z=func_0037E250(3.0f,5.0f)*0.0166666675f;
  func_L01_00300250(m,&va0,&v90);
 }
 spawn=func_L01_0032FE90(m+0x10,1,25,20,20,20,45,2,0.8f,0.0f,0.0f,0.0f,0,1,1,0,0,0,0x10000,D_L01_001DB02C,0x388ef7,0x63f7,0x407fff,0x20ff,0x8fff,0x3064ff,0x7f60a0ff,0x280000ff,0x3064ff,0);
 if(spawn) *(int *)(spawn+0xb8)=*(int *)(m+0xb8);
 n=func_003CF790(m+0x10,0,m,0,3.0f);
 items=D_L01_001EEB00;
 while(n>0) {
  u8 *o=*items;
  if((*(u8 **)(o+0x24))[0x46]==5 || (*(u16 *)(o+0x34)&0x4000)) {
   delta_vec(&v90,o+0x10,m+0x10);func_00388830(&v90,&v90,1.0f);func_00388830(&hit,&hit,1.0f);
   func_L01_00443628(&hit,m,0x1010000,&v90,*(float *)(D_L01_002C5640+D_001425C0[0x8f]*240+0x6c)*0.2f);
   hit.v=v90;hit.v.w=5627.9248f;hit.w20=1;hit.b18=5;hit.b19=3;hit.h1a=*(u16 *)(o+0xaa);
   func_L01_00443840(o,&hit);
  }
  n--;items++;
 }
 D_L01_001DDBCC--;func_L01_003D2CF0(m);func_003BD360(m);
}
/* localdecomp:end func_L01_0039E8A0 */
