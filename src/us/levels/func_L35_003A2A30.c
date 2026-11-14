#include "common.h"

/* NTSC-U counterpart of func_L35_003A42F8 (src/levels/35_vidcomic_5/L35_003A29A8.c) */
/* localdecomp:start func_L35_003A2A30 */
#include "vu0.h"
extern f32 D_L35_001DEA58;
__asm__(".extern D_L35_001DEA58, 4");
extern f32 D_L35_001DEA28;
__asm__(".extern D_L35_001DEA28, 4");
extern f32 D_L35_001DEA2C;
__asm__(".extern D_L35_001DEA2C, 4");
extern f32 D_L35_001DEA48;
__asm__(".extern D_L35_001DEA48, 4");

extern u8 D_001A4C60[];
extern void func_L35_003A28B8(u8 *,s32);
extern s32 func_L01_00452EC8(u8 *);
extern f32 func_L01_00436500(u8 *);
extern s32 func_00388398(void *);
extern f32 func_003893C8(f32,f32);
extern f32 func_003BEB48(f32,f32,f32);
extern void func_003BDA38(u8 *,s32,void *);
extern void func_0039FE80(s32,s32,u8 *);
extern s32 func_L35_003A3E68(f32 *,f32);
extern f32 func_0037E250(f32,f32);
extern void func_L35_003A2460(u8 *);
extern s32 func_L31_00345C88(u8 *,f32,f32,f32);
extern s32 func_L01_00453210(void *,s32);
typedef struct { u8 pad[0x1C]; s32 mode; } Row;
typedef struct { u8 pad[0x100]; Row rows[4]; } State;
void func_L35_003A2A30(u8 *obj) {
 u8 *s=*(u8 **)(obj+0x68);
 u8 *row;
 f32 angle;
 f32 a,b;
 f32 vec[4];
 if (*(s32 *)(s+0x180)<0 || *(s32 *)(s+0x180)>=*(s32 *)(s+0x188)) {
  func_L35_003A28B8(obj,5); return;
 }
 row=s+0x100+*(s32 *)(s+0x180)*32;
 if(func_L01_00452EC8(obj)) *(s32 *)(s+0xF8)=*(s32 *)(row+0x10);
 if(D_L35_001DEA58<func_L01_00436500(obj)) *(s32 *)(obj+0x48)=0;
 if(!func_00388398(s+0x198)) return;
 if(!func_00388398(s+0x19C)) {
  a=fabs_asm(func_003893C8(D_L35_001DEA28,*(f32 *)(obj+0xF8)));
  b=fabs_asm(func_003893C8(D_L35_001DEA2C,*(f32 *)(obj+0xF8)));
  { s32 closer = a < b;
  angle=0.7853982f;
  if(closer) angle=2.3561945f;
  }
  if(*(s32 *)(row+0x1C)==1)
   *(f32 *)(s+0x190)=func_003BEB48(*(f32 *)(row+8),*(f32 *)(row+12),1.0f-(f32)*(s32 *)(s+0x19C)/(f32)*(s32 *)(row+0x18));
  *(f32 *)(s+0xB0)=func_003893C8(*(f32 *)(s+0x190),angle);
  if(func_00388398(s+0xF8)) {
   func_003BDA38(obj,0,vec);
   vec[1]=*(f32 *)(D_001A4C60+4);
   *(s32 *)(s+0xF8)=*(s32 *)(row+0x10);
   func_0039FE80(0,0,obj);
   func_L35_003A3E68(vec,*(f32 *)(s+0x190));
   if(!((Row *)row)->mode) *(f32 *)(s+0x190)=func_0037E250(*(f32 *)(row+8),*(f32 *)(row+12));
  }
 } else {
  *(s32 *)(s+0x198)=*(s32 *)(row+0x14);
  func_L35_003A2460(obj);
  if(!func_L31_00345C88(obj,D_L35_001DEA28,D_L35_001DEA2C,D_L35_001DEA48)) {func_L35_003A28B8(obj,8);return;}
  if(*(s32 *)(s+0x18C)!=-1 && !func_L01_00453210(D_001A4C60,*(s32 *)(s+0x18C))) {func_L35_003A28B8(obj,2);return;}
  if(((State *)s)->rows[*(s32 *)(s+0x180)].mode==2) func_L35_003A28B8(obj,7);
  else func_L35_003A28B8(obj,6);
 }
}
/* localdecomp:end func_L35_003A2A30 */
