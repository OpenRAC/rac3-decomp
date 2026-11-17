/* NTSC-U draft (2026-11-14, Codex worker): C of func_L09_003BE1C8, the NTSC-U twin of func_L09_003BFA48, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/09_tyhrranosis/L09_003B8580.c's line: "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
/* localdecomp:start func_L09_003BE1C8 */
typedef struct {f32 x,y,z,w;} V_3BE1C8 __attribute__((aligned(16)));
typedef struct {char p0[0x20];f32 f20;s32 f24,f28,f2c;char p30[0x10];f32 f40;s32 f44,f48;} Params_3BE1C8;
extern Params_3BE1C8 D_L09_001E2C00;
extern char D_L09_00220098[];
extern s32 func_L01_0044AF40(void *,f32);
extern f32 func_0037E250(f32,f32);
extern f32 func_L01_00440918(f32,f32);
extern s32 func_0037E208(s32,s32),func_0037E1D8(s32);
extern u8 *func_L01_0046C468(void *,void *,s32,s32,s32,s32,s32,s32,f32,f32,f32);
void func_L09_003BE1C8(char *obj){
 V_3BE1C8 vel,pos;
 f32 size;
 s32 i,n,sign;
 u8 *p;
 if(func_L01_0044AF40(obj,16.0f)){
  D_L09_001E2C00.f20=0.2f;
  D_L09_001E2C00.f40=0.1f;
  D_L09_001E2C00.f48=100;
  D_L09_001E2C00.f2c=0;
  D_L09_001E2C00.f28=100;
  for(i=29;i>=0;--i){
   size=func_0037E250(5.0f,10.0f)*210000.0f;
   vel.x=func_L01_00440918(1.0f/12.0f,1.0f/6.0f);
   vel.y=func_L01_00440918(1.0f/12.0f,1.0f/6.0f);
   vel.z=func_0037E250(0.25f,0.8f)*(1.0f/60.0f);
   pos=*(V_3BE1C8*)(obj+0x10);
   pos.x+=func_L01_00440918(0.0f,0.6f);
   pos.y+=func_L01_00440918(0.0f,0.6f);
   pos.z+=func_L01_00440918(0.0f,0.2f);
   n=func_0037E208(35,120);
   sign=func_0037E1D8(2)?1:-1;
   p=func_L01_0046C468(&pos,&vel,n,0x10909090,sign,50,0,0,size,size,0.0f);
   if(p){p[3]=0x44;p[2]=**(u8**)(D_L09_00220098+0x5c);}
  }
 }
}
/* localdecomp:end func_L09_003BE1C8 */
