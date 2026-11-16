/* NTSC-U draft (Codex wave 3): C of func_L09_003C6758, the NTSC-U twin of func_L09_003C8158, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 220 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2") (NTSC-U twin "func_L09_003C6758", whose code is not the PAL one).
 * Worker's note: 220 diff with in-memory divs row; improved shared draft 353 to 220 by existing corrected layouts and loop addressing; residual prologue/VU scheduling and spilled loop-pointer slots after 12 compiles; best log w120/func_L09_003C6758.09.log; NEEDS divs row ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L09_003C6758 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_C6758;
typedef int Q_C6758 __attribute__((mode(TI)));
extern V_C6758 D_L09_001D9BA0[];
extern float D_L09_001E2338;
__asm__(".extern D_L09_001E2338, 16");
extern float D_L09_001DEA08[];
extern float D_L09_001DE9F8[];
extern V_C6758 D_001DE910_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001DE910_sda, 8");
typedef struct { u8 pad[0x18]; u8 *object; u8 pad1c[4]; V_C6758 point; } Hit_C6758;
extern Hit_C6758 D_L09_001E9940[];
extern V_C6758 D_L09_001E9960[];
extern V_C6758 D_L09_001E9980[];
typedef struct { u8 pad[0x19E0]; u8 *object; short index; u8 pad19e6[0x25C0-0x19E6]; u8 *player; u8 pad25c4[0x280C-0x25C4]; int state; } Game_C6758;
extern Game_C6758 D_001A4BE0[];
extern void func_003886E8(float, void *, void *);
extern void func_003888C8(void *, void *, void *);
extern int func_003CE740(void *, void *, int, void *, int);
extern int func_003D00C0(void);
extern void func_L01_00443938(void *, void *, int, void *, void *, float);
extern void func_L01_004EA040(void);
extern void func_L09_003C6188(void *);
extern void func_00388BD0(void *, void *);
extern void func_L01_00441FB8(void *, int, int);
extern void func_00388830(void *, void *, float);
extern float func_00388770(void *);
extern void func_003888F0(void *, void *, void *);
extern float func_003BEBF8(void *, float, float);
static __inline__ void add21_C6758(V_C6758 *d, V_C6758 *a, V_C6758 *b) {
 __asm__("lqc2 vf2,%1\n lqc2 vf1,%2\n vadd.xyz vf2,vf2,vf1\n sqc2 vf2,%0":"=m"(*d):"m"(*a),"m"(*b):"vf1","vf2");
}
static __inline__ void add12_C6758(V_C6758 *d, V_C6758 *a, V_C6758 *b) {
 __asm__("lqc2 vf2,%2\n lqc2 vf1,%1\n vadd.xyz vf1,vf1,vf2\n sqc2 vf1,%0":"=m"(*d):"m"(*a),"m"(*b):"vf1","vf2");
}
static __inline__ void addab_C6758(V_C6758 *d, V_C6758 *a, V_C6758 *b) {
 __asm__("lqc2 vf1,%1\n lqc2 vf2,%2\n vadd.xyz vf1,vf1,vf2\n sqc2 vf1,%0":"=m"(*d):"m"(*a),"m"(*b):"vf1","vf2");
}
static __inline__ void sub_C6758(V_C6758 *d, V_C6758 *a, V_C6758 *b) {
 __asm__("lqc2 vf1,%2\n lqc2 vf2,%1\n vsub.xyz vf2,vf2,vf1\n sqc2 vf2,%0":"=m"(*d):"m"(*a),"m"(*b):"vf1","vf2");
}
void func_L09_003C6758(u8 *h) {
 V_C6758 start, end, force, sample, gravity, local;
 int i, offset, was;
 V_C6758 *probe;
 float *height, *angle;
 void *matrix;
 V_C6758 *endp;
 u8 *params, *body;
 float total=0.0f;
 float grav=-0.002f;
 params=*(u8 **)(h+0x6D0);
 body=*(u8 **)(params+0x100);
 was=h[0x713];
 func_003886E8(grav,&gravity,D_L09_001D9BA0);
 qzero(&force);
 if(*(int *)(h+0x7A8)) {
  *(float *)(body+0x18)+=*(float *)(h+0x7A4);
  *(int *)(h+0x7A8)=0;
 }
 h[0x713]=0;
 *(short *)(params+0x128)=1;
 matrix=body+0xC0;
 height=&D_L09_001E2338;
 angle=(float *)(h+0x6B0);
 probe=D_001DE910_sda;
 for(i=0,offset=0;i<4;i++,offset+=4,probe++,height++,angle++) {
  int material, type;
  float distance, depth, fraction, strength;
  u8 *obj;
  sample=*probe;
  func_003888C8(&start,&sample,matrix);
  add21_C6758(&start,&start,(V_C6758 *)(body+0x10));
  end=start;
  start.z+=1.5f;
  end.z-=*height;
  if(func_003CE740(&start,&end,0xC24,body,0)) {
   material=func_003D00C0();
   type=-1;
   obj=D_L09_001E9940[0].object;
   if(obj)type=*(short *)(obj+0xAA);
   if(type>=0) {
    if(type==0x1ADE)goto missed;
    if(type==0x1BAE)
     func_L01_00443938(obj,body,1,&D_L09_001E9940[0].point,params+0xC0,
       *(float *)(params+0x138)/(*(float **)(h+0x720))[3]*40.0f+60.0f);
   }
   if(!D_L09_001E9940[0].object || type!=0x10C4) {
    if(material==1 || material==13 || material==3 || material==11) {
     if(*(float *)(params+0x130)>0.0f) {
      *(u16 *)(h+0x710)|=8;
      if(D_001A4BE0[0].object==body) {
       u8 *p;
       D_001A4BE0[0].state=0;
       D_001A4BE0[0].index=-1;
       D_001A4BE0[0].object=0;
       p=D_001A4BE0[0].player;
       *(int *)(p+0x98)=*(int *)(*(u8 **)(p+0x24)+0x10);
       func_L01_004EA040();
      }
      func_L09_003C6188(body);
      *(Q_C6758 *)(body+0x10)=*(Q_C6758 *)(params+0xE0);
      *(Q_C6758 *)(body+0xF0)=*(Q_C6758 *)(params+0xF0);
      func_00388BD0(matrix,body+0xF0);
      func_L01_00441FB8(body,1,-1);
      return;
     }
    }
   }
   sample=D_L09_001E9980[0];
   func_00388830(&force,&sample,1.0f);
   if(force.z<0.7070000171661377f)continue;
   if(h[0x715]==1 && *(short *)(h+0x71A)>=46 && material==5)h[0x713]=1;
   *(short *)(params+0x128)=0;
   sub_C6758(&sample,D_L09_001E9960,&start);
   distance=func_00388770(&sample)-1.5f;
   if(distance<0.0f) {
    *(float *)(body+0x18)-=distance;
    distance=0.0f;
   }
   depth=D_L09_001DEA08[i]-distance;
   func_003888F0(&local,&force,params);
   strength=*height-distance;
   fraction=strength / *height;
   strength*=0.025f;
   if(h[0x713] && i>=2 && *(short *)(h+0x71A)>=46)strength*=0.5f;
   func_003886E8(strength,&sample,&local);
   add12_C6758((V_C6758 *)(h+0x660+i*16),(V_C6758 *)(h+0x660+i*16),&sample);
   func_003886E8(strength*(fraction*0.2750000059604645f*fraction),&sample,D_L09_001D9BA0);
   add21_C6758((V_C6758 *)(h+0x6A0),(V_C6758 *)(h+0x6A0),&sample);
   *(float *)(h+0x6B0+offset)=depth;
  } else {
missed:
   if(!was || *(short *)(params+0x12A)>=11)
    addab_C6758((V_C6758 *)(h+0x660+i*16),(V_C6758 *)(h+0x660+i*16),&gravity);
   func_003BEBF8(angle,*(float *)((u8 *)D_L09_001DE9F8+offset),0.03333333507180214f);
  }
  total+=*height-*(float *)(h+0x6B0+offset);
 }
 if(was && *(short *)(params+0x128) && *(short *)(params+0x12A)<45)h[0x713]=1;
 if(*(short *)(h+0x754)==0) {
  *(int *)(h+0x7A8)=1;
  func_003BEBF8((float *)(h+0x7A4),(1.0f-(total*0.25f)/D_L09_001E2338)*-0.8f,0.03333333507180214f);
  *(float *)(body+0x18)-=*(float *)(h+0x7A4);
 }
}
/* localdecomp:end func_L09_003C6758 */
