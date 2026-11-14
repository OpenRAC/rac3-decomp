/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_0033ED90, the NTSC-U twin of func_L01_0033F530, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses" (src/levels/shared/L01_0033E0C8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses").
 */
#include "common.h"
/* localdecomp:start func_L01_0033ED90 */
typedef struct {float x,y,z,w;} __attribute__((aligned(16))) V;
typedef struct {V verts[4];unsigned colors[4];float uv[8];unsigned long zero,texture,alpha,prim;} Packet;
typedef struct {u8 pad[8];s16 age;} P;
typedef struct {u8 pad[0x10];V pos;u8 state;u8 pad21[0x68 - 0x21];P *p;} M;
typedef struct {s16 a,b,age,c,active,pad;} Trail;
extern int D_001DD080_sda,D_001DD0D8_sda,D_001DD0DC_sda,D_001DD12C_sda,D_001DD130_sda;
extern float D_001DD120_sda,D_001DD124_sda,D_001DD128_sda,D_001DD134_sda;
extern float D_001DD0E0_sda;
extern V D_L01_001E2A40[];
extern V D_001A4EC0[];
extern float D_L01_001E194C[];
extern Trail D_L01_00278E20[];
extern unsigned long func_00384EC0(int);
extern void func_00388830(void *,void *,float);
extern void func_003886E8(void *,float,void *);
extern void func_00388758(void *,void *,void *);
extern void func_003888F0(void *,void *,void *);
extern void func_003CD830(void *,int,int);
extern float func_L01_00440918(float,float);
extern void func_L01_0033F150(void *,float);
extern void func_L01_0033FDA8(void);
void func_L01_0033ED90(M *m){
 Packet packet;
 V normal,tangent,bitangent,pos,tmp;
 V *posptr;
 int i,j,next;
 V *source,*dest;
 unsigned color;
 float fade,ratio,size;
 P *p=m->p;
 if(m->state!=2){
  if(p->age>=D_001DD080_sda-30)fade=(float)(D_001DD080_sda-p->age)/30.0f;
  else fade=1.0f;
  packet.texture=func_00384EC0(8);
  __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,0(%2)\n\tvsub.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0":"=m"(normal):"m"(m->pos),"r"(D_L01_001E2A40),"m"(D_L01_001E2A40[0]):"vf1","vf2");
  packet.prim=0x8000000048UL;packet.alpha=0xff9000000260UL;packet.zero=0;
  packet.uv[0]=0;packet.uv[1]=0;packet.uv[2]=0;packet.uv[3]=1;
  packet.uv[4]=1;packet.uv[5]=0;packet.uv[6]=1;packet.uv[7]=1;
  func_00388830(&normal,&normal,1.0f);
  pos=m->pos;
  func_003886E8(&bitangent,-1.0f,D_001A4EC0);
  func_00388758(&tangent,&normal,&bitangent);
  func_00388830(&tangent,&tangent,1.0f);
  func_00388758(&bitangent,&tangent,&normal);
  posptr=&pos;
  i=0;
  do {
   next=i+1;
   if(D_L01_00278E20[i].active){
    ratio=(float)D_L01_00278E20[i].age*D_L01_001E194C[0];
    if(ratio>1.0f)ratio=1.0f;
    color=(D_001DD0DC_sda&0xffffff)|((int)(fade*((float)D_001DD0D8_sda+(0.0f-(float)D_001DD0D8_sda)*ratio))<<24);
    size=D_001DD120_sda+(D_001DD124_sda-D_001DD120_sda)*ratio;
    packet.colors[0]=color;packet.colors[3]=color;packet.colors[2]=color;packet.colors[1]=color;
    source=(V *)&D_001DD0E0_sda;dest=packet.verts;j=3;
    do {
     func_003886E8(&tmp,size,source++);
     func_003888F0(dest++,&tmp,&normal);
    }while(--j>=0);
    func_003CD830(&packet,0,0);
   }
   i=next;
  }while(i<10);
  packet.texture=func_00384EC0(11);
  color=(D_001DD130_sda&0xffffff)|D_001DD12C_sda;
  packet.prim=0x8000000044UL;
  packet.colors[0]=color;packet.colors[3]=color;packet.colors[2]=color;packet.colors[1]=color;
  func_00388830(posptr,&normal,D_001DD134_sda);
  __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0":"=m"(pos):"m"(pos),"m"(m->pos):"vf1","vf2");
  size=D_001DD128_sda+func_L01_00440918(0.0f,0.1f);
  source=(V *)&D_001DD0E0_sda;dest=packet.verts;j=3;
  do {
   func_003886E8(&tmp,size,source++);
   func_003888F0(dest++,&tmp,&normal);
  }while(--j>=0);
  func_003CD830(&packet,0,0);
  func_L01_0033F150(m,fade);
 }
 func_L01_0033FDA8();
}
/* localdecomp:end func_L01_0033ED90 */
