/* NTSC-U draft (Codex wave 3): C of func_L40_003F4FF8, the NTSC-U twin of func_L40_003F54B8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 23 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L40_003F4FF8", whose code is not the PAL one).
 * Worker's note: 23 diff; boolean expiry result fixes final integer registers; remaining extra conditional/xori and shifted epilogue; ten checks without improvement after .06; 16 checks total; best log func_L40_003F4FF8.06.log
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L40_003F4FF8 */
extern void func_L01_004479A8(void *);
extern void func_L39_00669B68(void *);
extern u8 *func_L01_00444358(void *, int, int);
extern int func_003883C8(void *);
extern u8 *func_L39_005BF058(void *);
extern void func_003BF4F8(void *, void *);
extern float func_L01_004443B0(void *,void *);
extern int func_L40_0053C768(void *);
extern void func_003BE4F0(void *,int,int,int);
extern void func_L01_00452B20(void *,void *,void *);
extern u8 *D_001DCD4C_sda;
extern int D_L40_002412AC;
int func_L40_003F4FF8(u8 *m,u8 *a,void *arg,int unused,int flag) {
 u8 *v=*(u8 **)(m+0x68), *x=*(u8 **)(m+0x90), *p=*(u8 **)v, *q=*(u8 **)(v+0x20), *hit;
 float damage;
 func_L01_004479A8(m);
 if (*(float *)(v+0x30)<=0.0f) (*(int *)(v+0x2e4))++;
 if (*(int *)(v+0x2e4)>200) func_L39_00669B68(arg);
 if(flag) hit=func_L01_00444358(m,1,0); else hit=func_L01_00444358(m,65536,0);
 if(!func_003883C8(p+6)) hit=0;
 if(hit) {
  u8 *o=*(u8 **)(hit+0x20);
  if(o && x) {
   u8 *r=o, *obj;
   while(*(u8 **)(r+0xb8)) r=*(u8 **)(r+0xb8);
   obj=((u8 *(*)(void *))*(void **)(func_L39_005BF058(r)+4))(r);
   if(obj && ((int (*)(void *,int))*(void **)(*(u8 **)(obj+0x14)+0x1c))(obj,*(int *)(x+0x18))) {hit=0; m[0xa8]=255;}
  }
  if(hit) {
   v[0x137]=128; func_003BF4F8(m,v+0x130);
   { float f=*(float *)(hit+0x2c);
   if(*(float *)(a+0xa8)!=0.0f) {
    if(*(u8 **)(hit+0x20) && *(short *)(m+0xaa)==*(short *)(*(u8 **)(hit+0x20)+0xaa)) *(float *)(hit+0x2c)=f**(float *)(a+0xa8);
   }
   }
  }
 }
 damage=func_L01_004443B0(m,hit); m[0xa8]=255;
 *(float *)p-=damage;
 if(*(float *)(v+0x30)<=0.0f && func_L40_0053C768(m) && m[0x20]!=a[0x10]) func_L39_00669B68(arg);
 else if(hit && *(float *)(v+0x30)*0.01f<damage && m[0x43]!=4) func_003BE4F0(m,4,0,10);
 if(q) func_L01_00452B20(m,q,p);
 if(damage==0.0f) {
  if((m[0x42]==4 || m[0x43]==4) && (m[0x60]&2)) {
   if(m[0x20]==4) {if(m[0x43]!=3) {func_003BE4F0(m,3,0,10);}}
   else if(m[0x43]!=2) {func_003BE4F0(m,2,0,10);}
  }
  return 0;
 }
 {
  int n;
  *(short *)(a+0x70)=-1;
  if(hit && *(u8 **)(hit+0x20)) *(short *)(a+0x70)=(*(u8 **)(hit+0x20)-D_001DCD4C_sda)>>8;
  n=300;
  if(*(short *)(p+4)**(float *)(a+0x58)<=0.0f) n=90;
  if(!a[0x77]) {int d=D_L40_002412AC-*(int *)(a+0x44); int expired=abs_asm(d)>n; if(expired) return !expired;}
 }
 return 0;
}
/* localdecomp:end func_L40_003F4FF8 */
