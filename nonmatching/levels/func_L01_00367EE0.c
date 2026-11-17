/* PAL near miss (Codex wave 8): near miss: 3 words differ with the file's flags.
 * Worker's note: 3/357 words differ, same size: build/codex/w402/func_L01_00367EE0.01.log with divs 2 (no exact metadata proof). lui a1 for vector source precedes float constant instead of following it. Struct/array global and quadword local forms unchanged; contract compiles ...
 */
#include "common.h"
/* localdecomp:start func_L01_00367EE0 */
extern s32 D_L01_001E1D00;
extern f32 D_L01_001E1C64;
extern f32 D_L01_001E1C70;
extern f32 D_L01_001E1C68;
extern f32 D_L01_001E1C20;
extern s128 D_L01_001E1C40;
extern S_38C110v D_L01_001E1C50;
void func_L01_00367EE0(void *m) {
 extern void func_L01_0043A800(void *,s32,S_38C110v *);
 extern void func_0038CE20(s128 *,s128 *,f32);
 extern f32 func_003824E0(f32,f32);
 extern s32 func_0038DBD8(s32,s32,f32);
 extern void func_L01_00470150(void *,void *,u32,s32,s32,f32,f32,s32,s32,s32,f32,s32,s32);
 S_38C110v point;
 S_38C110v ground;
 s32 color;
 s32 mode;
 func_L01_0043A800(m,0,&point);
 point.y-=0.2f;
 mode=D_L01_001E1D00;
 if(mode==1) {
  f32 amount=D_L01_001E1C70;
  if(D_L01_001E1C64>0.0f) {
   func_0038CE20((s128 *)&ground,(s128 *)&D_L01_001E1C50,0.75f);
   __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*(S_38C110v *)&ground) : "m"(*(S_38C110v *)&ground),"i"(&D_L01_001E1C40) : "vf1","vf2","memory");
   amount=D_L01_001E1C70;
  }
  if(amount<1.0f) {
   s32 mask=0xFFFFFF;
   color=((s32)(amount*64.0f)<<24)+0xFF2020;
   if(D_L01_001E1C64<1.0f)
    func_L01_00470150(&point,m,color,-1,1,func_003824E0(1.0f,1.0375f)*0.5625f*210000.0f,0.5f,2,5,-1,1.0f,mode,0);
   if(D_L01_001E1C64>0.0f) {
    color=(color & mask)+((s32)((f32)(s32)((u32)color>>24)*D_L01_001E1C64)<<24);
    func_L01_00470150(&ground,0,color,-1,1,func_003824E0(1.0f,1.0375f)*1.125f*210000.0f,0.0f,2,0,-1,1.0f,mode,0);
   }
  } else {
   if(D_L01_001E1C64<1.0f)
    func_L01_00470150(&point,m,0x60FF2020,-1,1,func_003824E0(1.0f,1.0375f)*0.5625f*210000.0f,0.5f,2,5,-1,1.0f,mode,0);
   if(D_L01_001E1C64>0.0f) {
    color=((s32)(D_L01_001E1C64*96.0f)<<24)+0xFF2020;
    func_L01_00470150(&ground,0,color,-1,1,func_003824E0(1.0f,1.0375f)*1.125f*210000.0f,0.0f,2,0,-1,1.0f,mode,0);
   }
   if(D_L01_001E1C64<1.0f)
    func_L01_00470150(&point,m,0x50FF4050,-1,0,func_003824E0(1.0f,1.0375f)*0.5625f*210000.0f,0.5f,2,5,-1,1.0f,0,0);
   if(D_L01_001E1C64>0.0f) {
    color=((s32)(D_L01_001E1C64*80.0f)<<24)+0xFF4050;
    func_L01_00470150(&ground,0,color,-1,0,func_003824E0(1.0f,1.0375f)*1.8f*210000.0f,0.0f,2,0,-1,1.0f,mode,0);
   }
  }
 }
 if(D_L01_001E1C68>1.0f) {
  color=0x28FF2020;
  if(D_L01_001E1C20>0.0f) color=0x38D020FF;
  if(D_L01_001E1C68<14.0f) color=func_0038DBD8(color&-16777216,color,D_L01_001E1C68/14.0f);
  point.y-=0.3f;
  func_L01_00470150(&point,m,color,-1,1,(func_003824E0(1.0f,1.0375f)+D_L01_001E1C64*0.25f)*0.61875f*210000.0f,0.0f,2,0,-1,1.0f,1,0);
 }
}
/* localdecomp:end func_L01_00367EE0 */
