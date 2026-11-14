#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L03_003CE5D8 */
extern void func_003BF6A8(void *,float);
extern void func_00388830(void *,void *,float);
extern void func_003886E8(void *,void *,float);
extern float func_0037E250(float,float);
extern void func_L01_0046CF70(void *,void *,int,float);
static __inline__ void copy83(void *dst, const void *src) { *(vu0_q *)dst = *(const vu0_q *)src; }
void func_L03_003CE5D8(char *p, short slot,int n,float speed,float up,float angle,float spread,float unused,float upvar,float size) {
 vu0_v4 w,pos,v; int i;
 for(i=0;i<n;i++) {
  pos=*(vu0_v4*)(p+0x10);
  func_003BF6A8(&pos,angle);
  copy83(&v,p+0xc0+slot*16);
  func_00388830(&v,&v,*(float*)(p+0x2c)/ *(float*)(*(char**)(p+0x24)+0x24)*speed);
  pos.z += *(float*)(p+0x2c)/ *(float*)(*(char**)(p+0x24)+0x24)*up;
  __asm__ ("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "+m"(pos) : "m"(v) : "vf1", "vf2");
  copy83(&w,((vu0_q *)(p+0xc0)+slot));
  func_003886E8(&w,&w,func_0037E250(upvar*0.5f,upvar)*0.0166666675f);
  w.x+=func_0037E250(-spread,spread);
  w.y+=func_0037E250(-spread,spread);
  func_L01_0046CF70(&pos,&w,60,size*0.000277777785f);
 }
}
/* localdecomp:end func_L03_003CE5D8 */
