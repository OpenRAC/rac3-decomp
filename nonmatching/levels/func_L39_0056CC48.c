/* NTSC-U draft (2026-11-14, Codex worker): C of func_L39_0056BF58, the NTSC-U twin of func_L39_0056CC48, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L39_0056CC48.c's current line.
 * Worker's note: 161 diff; permitted GNU assembler emits .lit4 lwc1 for 0.35/0.05/0.075/0.2, retail inline lui/ori/mtc1; flags blocker plus VU scheduling; div row likely 2; best log w102/func_L39_0056BF58.01.log
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L39_0056BF58 */
typedef int Q_BF58 __attribute__((mode(TI)));
typedef union { Q_BF58 q; float f[4]; } V_BF58;
typedef struct { u8 pad[0x70]; u8 *data; u8 pad74[0x20]; int index; } M_BF58;
typedef struct { u8 pad[0x150]; u8 sub[0x310]; } S_BF58;
extern S_BF58 D_L39_0024DF80[];
extern int D_L39_0024145C[];
extern int D_L39_0024B968[];
extern V_BF58 D_L39_0025F860[];
extern void func_00388830(void *,void *,float);
extern float func_00388730(void *,void *);
extern void func_003886E8(void *,void *,float);
extern int func_L01_003E2378(void *);
extern int func_L01_003F9498(void *,int,int,float);
extern int func_L01_003E60C8(M_BF58 *,int,void *,float);
extern int func_L01_003E5D00(M_BF58 *,void *,int,float,float);
static __inline__ void sub_BF58(V_BF58 *d,V_BF58 *a,V_BF58 *b) {
 __asm__("lqc2 vf2,%1\n lqc2 vf1,%2\n vsub.xyz vf2,vf2,vf1\n sqc2 vf2,%0" : "=m"(*d) : "m"(*a),"m"(*b) : "vf1","vf2");
}
static __inline__ void add_BF58(V_BF58 *d,V_BF58 *a,V_BF58 *b) {
 __asm__("lqc2 vf2,%1\n lqc2 vf1,%2\n vadd.xyz vf2,vf2,vf1\n sqc2 vf2,%0" : "=m"(*d) : "m"(*a),"m"(*b) : "vf1","vf2");
}
int func_L39_0056BF58(M_BF58 *m) {
 V_BF58 origin,pos,step,hit,hitpos,temp;
 u8 *base=m->data+0x60;
 u8 *motion=m->data+0x180;
 u8 *state=m->data+0x210;
 S_BF58 *hero=&D_L39_0024DF80[m->index];
 u8 *sub=hero->sub;
 int result=0,changed=0,i;
 float speed=0.35f,total=0.0f;
 origin.q=*(Q_BF58 *)motion;
 pos.q=*(Q_BF58 *)(m->data+0xB0);
 func_00388830(&step,&origin,1.0f);
 if(D_L39_0024145C[0]==48 || D_L39_0024145C[0]==28) {
  if(!(D_L39_0024B968[m->index]&32)){changed=1;D_L39_0024B968[m->index]|=32;}
 }
 for(i=0;i<(int)(*(float *)(state+0x40)-1.0f);i++) {
  if(i>0 && !func_L01_003E2378(&pos) && func_L01_003F9498(&pos,D_L39_0024B968[m->index],*(int *)(sub+0xF0),speed) && !func_L01_003E60C8(m,i,&pos,speed)) {
   hit.q=D_L39_0025F860[0].q;
   hitpos.q=pos.q;
   if(func_L01_003E5D00(m,&pos,i,total,speed)) {
    result=1;
    if(fabs_asm(*(float *)(*(u8 **)(sub+0x134)+0x100))>0.05f) {
     sub_BF58(&temp,&hit,&hitpos);
     func_00388830(&temp,&temp,1.0f);
     if(fabs_asm(func_00388730((u8 *)hero+0x90,&temp))<0.75f) {
      *(u16 *)(state+0x34)=0x884;
      *(float *)(state+0x30)+=0.075f;
      if(*(float *)(motion+0x2C)-*(float *)(state+0x30)<0.2f) *(float *)(state+0x30)=*(float *)(motion+0x2C)-0.2f;
     }
    }
    sub_BF58(&temp,&pos,(V_BF58 *)(base+0x50));
    func_00388830(motion,&temp,*(float *)(motion+0x2C)-*(float *)(state+0x30));
    func_00388830(&step,motion,1.0f);
   }
  }
  { float f=*(float *)(motion+0x2C); float factor=(f-*(float *)(state+0x30))/f;
    speed+=*(float *)(state+0x44)* *(float *)(state+0x3C);
    total+=speed;
    func_003886E8(&hit,&step,speed*factor);
  }
  add_BF58(&pos,&pos,&hit);
 }
 if(D_L39_0024145C[0]==48 || D_L39_0024145C[0]==28) {if(changed)D_L39_0024B968[m->index]&=~32;}
 return result;
}
/* localdecomp:end func_L39_0056BF58 */
