/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_003F5B38, the NTSC-U twin of func_L01_003F7CE0, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 5 words differ with its file's flags.
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_003F5B38 */
extern int func_L01_004369B8(void *,void *,int,int);
extern void func_L01_004367E8(void *,int,void *);
extern void func_003BFAF8(void *,void *,void *,int);
extern void func_003886E8(void *,void *,float);
static __inline__ void sub_5B38(void *d,void *a,void *b) {
 __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b));
}
void func_L01_003F5B38(u8 *m,int mode,int index,vu0_q *a,vu0_q *b,int byte,int half,float f) {
 u8 *d=*(u8 **)(m+0x68);
 vu0_v4 tmp;
 f*=0.00027777778450399637f;
 *(int *)(m+0x98)=0;
 *(u16 *)(m+0x34)|=0x100;
 *(vu0_q *)d=*a; *(vu0_q *)(d+0x10)=*b;
 *(float *)(d+0x38)=0.45f;
 *(float *)(d+0x3c)=0.033333335f;
 *(float *)(d+0x40)=0.5f;
 *(float *)(d+0x44)=0.01308997068554163f;
 *(float *)(d+0x48)=f;
 *(float *)(d+0x4c)=0.0017453293548896909f;
 *(s16 *)(d+0x34)=half; d[0x5e]=byte; d[0x5d]=mode; d[0x58]=0; d[0x5c]=0; *(int *)(d+0x30)=0;
 switch(mode) {
 case 2:
  *(s16 *)(d+0x36)=index; *(u16 *)(m+0x7c)=(1<<index)|0x8000;
  d[0x58]=func_L01_004369B8(m,d+0x20,*(int *)(d+0x30),index);
  sub_5B38(d+0x20,d+0x20,m+0x10);
  func_003BFAF8(m,d+0x20,d+0x20,0); break;
 case 0: case 3:
  func_003886E8(d+0x20,m,0.0009765625f);
  *(float *)(d+0x2c)=*(float *)(m+0xc)*0.0009765625f;
  sub_5B38(d+0x20,d+0x20,m+0x10);
  func_003BFAF8(m,d+0x20,d+0x20,0); break;
 case 1:
  *(s16 *)(d+0x36)=index; *(u16 *)(m+0x7c)=(1<<index)|0x8000;
  func_L01_004367E8(m,index,&tmp);
  sub_5B38(d+0x20,&tmp,m+0x10);
  func_003BFAF8(m,d+0x20,d+0x20,0); break;
 }
}
/* localdecomp:end func_L01_003F5B38 */
