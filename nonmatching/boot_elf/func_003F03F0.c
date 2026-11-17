/* PAL near miss (Codex wave 7): near miss: 79 words differ with the file's flags.
 * Worker's note: 79 diff, w355/func_003F03F0.03.log; context-compatible func_0038EBC8 prototype first integer is s32 (38E488.c), forces lw where retail lwu. Needs unsigned-long texture parameter correction; remaining FP scheduling. Contract compiles.
 */
#include "common.h"
/* localdecomp:start func_003F03F0 */
typedef struct Obj_003F03F0 Obj_003F03F0;
typedef struct Vtable_003F03F0 { u8 pad[0x20]; void (*bounds)(Obj_003F03F0 *,s32,f32 *,s32); } Vtable_003F03F0;
struct Obj_003F03F0 { u8 pad0[8]; Vtable_003F03F0 *vt; u8 padC[0x14]; f32 x,y; u32 color; u8 pad2C[0x10]; s32 image; u8 pad40[0x10]; u32 texture; u8 pad54[8]; f32 f5C, f60; };
extern f32 D_001D96B4;
void func_003F03F0(Obj_003F03F0 *p,s32 arg)
{
 extern void func_0038EBC8(f32,f32,f32,f32,s32,s32,s32,s32,s32,unsigned long,f32,f32);
 f32 rect[4];
 f32 y,x,w,h,zero,scale,adjust,z;
 unsigned long texture,color; s32 image;
 s32 has;
 if (p->image) {
  w=0.0f;has=0;
  p->vt->bounds(p,arg,rect,1);
  func_003EE0A8(p,rect);
  zero=w;h=w;
  y=rect[1]+(rect[3]-rect[1])*0.5f;
  x=rect[0]+(rect[2]-rect[0])*0.5f;
  if (func_003EDEB0(p,0x40)) { w=p->x;h=p->y;has=1; }
  scale=p->f60;
  adjust=D_001D96B4*scale;
  texture=p->texture; color=p->color;image=p->image; z=p->f5C;
  if (has) {
   func_0038EBC8((f32)(s32)(x*D_001D9698),(f32)(s32)((y-adjust)*D_001D969C),z,scale*1.076923131942749f,texture,image,-1,1,has,color,w*D_001D9698,h*D_001D969C);
  } else {
   func_0038EBC8((f32)(s32)(x*D_001D9698),(f32)(s32)((y-adjust)*D_001D969C),z,scale*1.076923131942749f,texture,image,-1,1,0,color,zero,zero);
  }
 }
}
/* localdecomp:end func_003F03F0 */
