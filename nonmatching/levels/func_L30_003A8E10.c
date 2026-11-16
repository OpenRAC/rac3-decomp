/* NTSC-U draft (Codex wave 3): C of func_L30_003A7318, the NTSC-U twin of func_L30_003A8E10, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 266 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L30_003A7318", whose code is not the PAL one).
 * Worker's note: 266 diff; NEEDS divs row 'func_L30_003A7318 1' verified in-memory (retail 1 nop); separate counters/block-local hero improve 359 to 266; loop/prologue allocation and mixed gp/lui tail unresolved; 12 checks; best log func_L30_003A7318.07.log
 */
#include "common.h"
#include "vu0.h"
__asm__(".extern D_L30_001DEAF0, 4");
__asm__(".extern D_L30_001DEAF4, 4");
__asm__(".extern D_L30_001DEAF8, 4");
__asm__(".extern D_L30_001DEAFC, 4");
__asm__(".extern D_L30_001DEB00, 4");
__asm__(".extern D_L30_001DEB04, 4");
__asm__(".extern D_L30_001DEB08, 4");
__asm__(".extern D_L30_001DEB0C, 4");
__asm__(".extern D_L30_001DEB18, 4");
__asm__(".extern D_L30_001DF2C0, 4");
__asm__(".extern D_L30_001E1BC0, 4");
__asm__(".extern D_L30_001E1BC4, 4");
__asm__(".extern D_L30_001E1BC8, 4");
__asm__(".extern D_L30_001E1BCC, 4");
/* localdecomp:start func_L30_003A7318 */
extern u8 D_001A4BE0[],D_001A4C60[];
extern vu0_q D_L30_002A2560[];
extern int D_L30_001DF2C0,D_L30_001DEAF0,D_L30_001DEAF4;
extern float D_L30_001DEB18,D_L30_001DEB08,D_L30_001DEB04,D_L30_001DEB0C,D_L30_001DEAF8,D_L30_001DEAFC,D_L30_001DEB00,D_L30_001E1BC4,D_L30_001E1BC0,D_L30_001E1BCC,D_L30_001E1BC8;
extern int func_L01_00453210(void *,int),func_L30_0034C9F8(void *,float);
extern void func_L30_003A7A28(void *,void *,void *);
extern float func_L30_003A7E48(int,void *);
extern void func_003886E8(void *,void *,float);
extern void func_L01_00445168(void *,void *,float,float,float,float);
extern void func_L30_0034BEE0(float *,float *,float *,float *,float);
extern float func_L30_0034CB90(int,float,float,float);
static __inline__ void add_vec(void *d,void *a,void *b) {
 __asm__("lqc2 $vf1,%1\n lqc2 $vf2,%2\n vadd.xyz $vf1,$vf1,$vf2\n sqc2 $vf1,%0" : "=m"(*(vu0_v4 *)d):"m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b):"vf1","vf2");
}
static __inline__ void delta_vec(void *d,void *a,void *b) {
 __asm__("lqc2 $vf1,%2\n lqc2 $vf2,%1\n vsub.xyz $vf2,$vf2,$vf1\n sqc2 $vf2,%0" : "=m"(*(vu0_v4 *)d):"m"(*(vu0_v4 *)a),"m"(*(vu0_v4 *)b):"vf1","vf2");
}
void func_L30_003A7318(u8 *m,vu0_v4 *out,vu0_v4 *input,u8 *other) {
 vu0_v4 original,tmp,delta;
 float a,b,c,d,e,f,g,h;
 float *weights;
 int state=*(int *)(D_001A4BE0+0x25c4);
 u8 *v=*(u8 **)(m+0x68),*row,*row2;
 vu0_q *vec;
 vu0_v4 *acc;
 int i,j,k;
 *out=*input; *(float *)(v+0x2c)=0; original=*input;
 if(state==159 || state==161 || state==160) return;
 row=v+0x30;row2=row;vec=D_L30_002A2560; weights=(float *)(row+0x1c);acc=(vu0_v4 *)(v+0x10);
 for(i=0;i<32;row2+=32,weights+=8,row+=32,i++) {
  if(*(int *)row!=-1 && func_L01_00453210(D_001A4C60,*(int *)row) && *weights>0.0f) {
   float weight,blend;
   func_L30_003A7A28(row2,&tmp,&D_L30_002A2560[i]);
   weight=*weights*func_L30_003A7E48(*(int *)row,D_001A4C60);
   blend=weight/(weight+*(float *)(v+0x2c));
   func_003886E8(&tmp,&tmp,blend);
   func_003886E8(acc,acc,1.0f-blend);
   add_vec(v+0x10,v+0x10,&tmp);
   *(float *)(v+0x2c)+=weight;
  }
 }
 row=v+0x30;vec=D_L30_002A2560;
 for(j=0;j<32;vec++,row+=32,j++) if(*(int *)row!=-1 && !func_L01_00453210(D_001A4C60,*(int *)row)) *vec=*(vu0_q *)(v+0x10);
 if(!func_L30_0034C9F8(D_001A4C60,D_L30_001DEB18) || D_L30_001DF2C0<20) {
  *out=*(vu0_v4 *)(v+0x10); *(float *)(v+0x20)=0;*(float *)(v+0x24)=0;*(float *)(v+0x28)=0;
 } else {
  func_L01_00445168(&out->x,v+0x20,*(float *)(v+0x10),D_L30_001DEB08,D_L30_001DEB04,D_L30_001DEB0C);
  func_L01_00445168(&out->y,v+0x24,*(float *)(v+0x14),D_L30_001DEB08,D_L30_001DEB04,D_L30_001DEB0C);
  func_L01_00445168(&out->z,v+0x28,*(float *)(v+0x18),D_L30_001DEB08,D_L30_001DEB04,D_L30_001DEB0C);
 }
 if(D_L30_001DEAF0 && D_L30_001DF2C0>20) {
  float x,z,scale; u8 *hero=D_001A4BE0;
  func_L30_0034BEE0(&a,&b,&c,&d,D_L30_001DEAF8);
  func_L30_0034BEE0(&e,&f,&g,&h,D_L30_001DEAFC);
  x=out->x-(e+f)*0.5f; z=out->z-(g+h)*0.5f;
  a+=x;e+=x;f+=x;h+=z;b+=x;c+=z;d+=z;g+=z;tmp=*out;
  if(*(float *)(hero+0x80)<a) {
   scale=1.0f+(D_L30_001DEB00-1.0f)*func_L30_0034CB90(0,*(float *)(hero+0x80),e,a);
   func_L01_00445168(&out->x,v+0x20,out->x-(a-*(float *)(hero+0x80)),scale*D_L30_001DEB08,scale*D_L30_001DEB04,scale*D_L30_001DEB0C);
  }
  if(*(float *)(hero+0x88)<c && *(float *)(hero+0x2f8)>2.0f && *(int *)(hero+0x25c4)!=161) {
   scale=1.0f+(D_L30_001DEB00-1.0f)*func_L30_0034CB90(0,*(float *)(hero+0x88),g,c);
   func_L01_00445168(&out->z,v+0x28,out->z-(c-*(float *)(hero+0x88)),scale*D_L30_001DEB08,scale*D_L30_001DEB04,scale*D_L30_001DEB0C);
  }
  if(b<*(float *)(hero+0x80)) {
   scale=1.0f+(D_L30_001DEB00-1.0f)*func_L30_0034CB90(1,*(float *)(hero+0x80),b,f);
   func_L01_00445168(&out->x,v+0x20,out->x+(*(float *)(hero+0x80)-b),scale*D_L30_001DEB08,scale*D_L30_001DEB04,scale*D_L30_001DEB0C);
  }
  if(d<*(float *)(hero+0x88)) {
   scale=1.0f+(D_L30_001DEB00-1.0f)*func_L30_0034CB90(1,*(float *)(hero+0x88),d,h);
   func_L01_00445168(&out->z,v+0x28,out->z+(*(float *)(hero+0x88)-d),scale*D_L30_001DEB08,scale*D_L30_001DEB04,scale*D_L30_001DEB0C);
  }
  delta_vec(&delta,out,&tmp);row=v+0x30;vec=D_L30_002A2560;
  for(k=0;k<32;vec++,row+=32,k++) if(*(int *)row!=-1 && func_L01_00453210(D_001A4C60,*(int *)row)) add_vec(vec,vec,&delta);
 }
 if(D_L30_001DEAF4 && other && *(u8 **)(other+0x68)) {
  *out=*(vu0_v4 *)(*(u8 **)(other+0x68)+0xc0);*(float *)(v+0x20)=0;*(float *)(v+0x24)=0;*(float *)(v+0x28)=0;
 }
 if(D_L30_001E1BC4>0.0f) {if(out->x<D_L30_001E1BC4) out->x=D_L30_001E1BC4;D_L30_001E1BC4=0.0f;}
 if(D_L30_001E1BC0>0.0f) {if(out->x>D_L30_001E1BC0) out->x=D_L30_001E1BC0;D_L30_001E1BC0=0.0f;}
 if(D_L30_001E1BCC>0.0f) {if(out->z<D_L30_001E1BCC) out->z=D_L30_001E1BCC;D_L30_001E1BCC=0.0f;}
 if(D_L30_001E1BC8>0.0f) {if(out->z>D_L30_001E1BC8) out->z=D_L30_001E1BC8;D_L30_001E1BC8=0.0f;}
 *input=*out;*(vu0_v4 *)v=*(vu0_v4 *)D_001A4C60;
}
/* localdecomp:end func_L30_003A7318 */
