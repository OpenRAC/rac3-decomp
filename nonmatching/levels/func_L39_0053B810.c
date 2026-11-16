/* NTSC-U draft (Codex wave 3): C of func_L39_0053B078, the NTSC-U twin of func_L39_0053B810, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 33 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_0053B078", whose code is not the PAL one).
 * Worker's note: 33 diff; five compiles; baseline, commuted table addition and unsigned-int index yield identical bytes; table register allocation/final VU scheduling remain; NEEDS divs row 'func_L39_0053B078 2' tested via native_runner.py (retail padding reproduced, no ...
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L39_0053B078 */
typedef union { vu0_q q; float f[4]; } V;
extern unsigned char *D_L39_0024CF20[];
extern unsigned char D_L39_0025F860[];
extern void *D_001DF628_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DF628_sda, 4");
extern float func_L39_005B2510(float,float);
extern void func_00388830(void *,void *,float);
extern int func_003BF7E8(void *);
extern void func_L39_005FC9F8(void *,void *,void *);
extern int func_003CE740(void *,void *,void *,void *,int);
extern void func_L01_0040C260(void *,void *,void *);
extern void func_003886E8(void *,void *,float);
void func_L39_0053B078(void *pos,unsigned char *m,void *offset) {
 V b,a,c;
 unsigned char *p=*(unsigned char **)(m+0x68);
 unsigned char *o=0;
 { unsigned short index=*(unsigned short *)(p+0x7c); if(index<8) o=*((unsigned char **)((short)index*4 + (unsigned char *)D_L39_0024CF20)); }
 if(o) {
  a.q=0;
  a.f[0]=func_L39_005B2510(-1,1);
  a.f[1]=func_L39_005B2510(-1,1);
  a.f[2]=func_L39_005B2510(-1,1);
  *(float *)(m+0x2c)/=0.65f;
  b.q=a.q;
  m[0x20]=1;
  func_00388830(&b,&b,func_L39_005B2510(0.00016666666f,0.0016666668234393f));
  __asm__("lqc2 $vf2, %2
 lqc2 $vf1, %1
 vadd.xyz $vf1, $vf1, $vf2
 sqc2 $vf1, %0" : "=m"(*(vu0_v4 *)p) : "m"(b),"m"(*(vu0_v4 *)offset) : "vf1","vf2");
  if(*(void **)(o+0x2cc) && func_003BF7E8(*(void **)(o+0x2cc))) {
   __asm__("lqc2 $vf1, %1
 lqc2 $vf2, %2
 vadd.xyz $vf1, $vf1, $vf2
 sqc2 $vf1, %0" : "=m"(*(vu0_v4 *)p) : "m"(*(vu0_v4 *)p),"m"(*(vu0_v4 *)(o+0x140)) : "vf1","vf2");
  }
  *(short *)(p+0x34)=120;
  *(vu0_q *)(m+0x10)=*(vu0_q *)pos;
  *(short *)(p+0x36)=(o && *(short *)(o+0x2d8))?-1:1;
  func_L39_005FC9F8(o,m+0x10,p+0x20);
  func_00388830(p+0x20,p+0x20,0.0032777779269963503f);
  a.q=*(vu0_q *)(*(unsigned char **)(o+0x2524)+0x10);
  a.f[2]=((float *)pos)[2];
  if(func_003CE740(&a,pos,D_001DF628_sda,*(void **)(o+0x2524),0)) {
   unsigned char *v=D_L39_0025F860;
   *(vu0_q *)(m+0x10)=*(vu0_q *)v;
   func_00388830(&c,v+0x20,0.0026944445f);
   v+=0x20;
   __asm__("lqc2 $vf1, %1
 lqc2 $vf2, %2
 vadd.xyz $vf1, $vf1, $vf2
 sqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(m+0x10)) : "m"(*(vu0_v4 *)(m+0x10)),"m"(c) : "vf1","vf2");
   func_L01_0040C260(p,p,v);
   func_003886E8(p,p,0.6f);
  }
 }
}
/* localdecomp:end func_L39_0053B078 */
