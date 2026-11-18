/* PAL port of the NTSC-U draft (Codex wave 3, func_L40_003F4FF8), 23 diff on PAL with the file's flags (Sonnet Y1, round 7).
 * Ported: callee names through config/us/map.tsv, the 50 Hz hit-stun argument 8 (was 10), the (n * 5 + 2) / 6 rescale of the
 * 300/90 frame limit and D_L40_0024112C (was ...12AC). Everything up to the tail matches retail's 968 bytes, the n limit sits in
 * $v1 as retail's. Left: the tail. Retail computes `slt $v0,$v0,$v1` and drops it: `move $v0,$zero` is the one shared
 * epilogue (the a[0x77] test jumps to it, no branch after the slt). `if (expired) return !expired;` gives bnez + xori and a
 * duplicated epilogue; `if (expired) return 0;` (38), `if (abs_asm(d) > lim) return 0;` (38), `return expired & 0;` (50), an
 * if/else with two `return 0` (34: gcc deletes the whole computation) and `expired - 1` / u8 expired (23) do not reach it. */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L40_003F54B8 */
extern void func_L01_0044ABD0(void *);
extern void func_L39_0066C470(void *);
extern u8 *func_L01_00447490(void *, int, int);
extern int func_0038CB00(void *);
extern u8 *func_L39_005C1018(void *);
extern void func_003C4A40(void *, void *);
extern float func_L01_004474E8(void *,void *);
extern int func_L40_0053F018(void *);
extern void func_003C3A10(void *,int,int,int);
extern void func_L01_00455E18(void *,void *,void *);
extern u8 *D_001DCD4C_sda;
extern int D_L40_0024112C;
int func_L40_003F54B8(u8 *m,u8 *a,void *arg,int unused,int flag) {
 u8 *v=*(u8 **)(m+0x68), *x=*(u8 **)(m+0x90), *p=*(u8 **)v, *q=*(u8 **)(v+0x20), *hit;
 float damage;
 func_L01_0044ABD0(m);
 if (*(float *)(v+0x30)<=0.0f) (*(int *)(v+0x2e4))++;
 if (*(int *)(v+0x2e4)>200) func_L39_0066C470(arg);
 if(flag) hit=func_L01_00447490(m,1,0); else hit=func_L01_00447490(m,65536,0);
 if(!func_0038CB00(p+6)) hit=0;
 if(hit) {
  u8 *o=*(u8 **)(hit+0x20);
  if(o && x) {
   u8 *r=o, *obj;
   while(*(u8 **)(r+0xb8)) r=*(u8 **)(r+0xb8);
   obj=((u8 *(*)(void *))*(void **)(func_L39_005C1018(r)+4))(r);
   if(obj && ((int (*)(void *,int))*(void **)(*(u8 **)(obj+0x14)+0x1c))(obj,*(int *)(x+0x18))) {hit=0; m[0xa8]=255;}
  }
  if(hit) {
   v[0x137]=128; func_003C4A40(m,v+0x130);
   { float f=*(float *)(hit+0x2c);
   if(*(float *)(a+0xa8)!=0.0f) {
    if(*(u8 **)(hit+0x20) && *(short *)(m+0xaa)==*(short *)(*(u8 **)(hit+0x20)+0xaa)) *(float *)(hit+0x2c)=f**(float *)(a+0xa8);
   }
   }
  }
 }
 damage=func_L01_004474E8(m,hit); m[0xa8]=255;
 *(float *)p-=damage;
 if(*(float *)(v+0x30)<=0.0f && func_L40_0053F018(m) && m[0x20]!=a[0x10]) func_L39_0066C470(arg);
 else if(hit && *(float *)(v+0x30)*0.01f<damage && m[0x43]!=4) func_003C3A10(m,4,0,8);
 if(q) func_L01_00455E18(m,q,p);
 if(damage==0.0f) {
  if((m[0x42]==4 || m[0x43]==4) && (m[0x60]&2)) {
   if(m[0x20]==4) {if(m[0x43]!=3) {func_003C3A10(m,3,0,8);}}
   else if(m[0x43]!=2) {func_003C3A10(m,2,0,8);}
  }
  return 0;
 }
 {
  int n;
  *(short *)(a+0x70)=-1;
  if(hit && *(u8 **)(hit+0x20)) *(short *)(a+0x70)=(*(u8 **)(hit+0x20)-D_001DCD4C_sda)>>8;
  n=300;
  if(*(short *)(p+4)**(float *)(a+0x58)<=0.0f) n=90;
  if(!a[0x77]) {int lim=(n*5+2)/6; int d=D_L40_0024112C-*(int *)(a+0x44); int expired=abs_asm(d)>lim; if(expired) return !expired;}
 }
 return 0;
}
/* localdecomp:end func_L40_003F54B8 */
