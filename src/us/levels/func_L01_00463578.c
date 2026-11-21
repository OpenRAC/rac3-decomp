#include "common.h"

/* NTSC-U counterpart of func_L01_00466B78 (src/levels/shared/L01_00465878.c) */
#include "vu0.h"
extern s32 func_003883C8(u8 *);
#include "vu0.h"
extern void func_L01_004C6EC8(void *, void *);
#include "vu0.h"
#include "vu0.h"

/* localdecomp:start func_L01_00463578 */
#include "vu0.h"
void func_L01_00463578(u8 *self) {
 extern void func_L01_004C6EC8(void *,void *);
 extern s32 func_003883C8(u8 *);
 extern void func_003C7CE0(u8 *);
 u8 *s=self+0x20;
 f32 blend;
 s32 elapsed;
 self[8]+=s[8];
 vec_add_ab(self+0x10,self+0x10,self+0x30);
 if(*(f32 *)(self+0x1c)!=0.0f) {
  if(*(f32 *)(self+0x1c)==2.0f) func_L01_004C6EC8(self+0x10,self+0x10);
  *(f32 *)(self+0x1c)=2.0f;
 }
 *(f32 *)(self+0xc)*=*(f32 *)(s+0xc);
 if(*(s32 *)(s+4)==0) {
  if(func_003883C8(self+0xa)) {
   *(s32 *)(s+4)=1;
   *(s16 *)(self+0xa)=20;
   *(s32 *)(self+4)=*(s32 *)s|0x7f000000;
  } else {
   *(s32 *)(self+4)=(((s32)((10-*(s16 *)(self+0xa))*9.6f)+32)<<24)|*(s32 *)s;
  }
 } else if(*(s32 *)(s+4)==2) {
  if(func_003883C8(self+0xa)) {
   func_003C7CE0(self);
  } else {
   *(s32 *)(self+4)=((s32)(s[10]*((f32)*(s16 *)(self+0xa)/s[11])+0.0f)<<24)|(*(s32 *)s&0xffffff);
  }
 } else if(*(s32 *)(s+4)==3) {
  func_003883C8(self+0xa);
  elapsed=s[11]-*(s16 *)(self+0xa);
  blend=(f32)elapsed / *(f32 *)(s+0x1c);
  if(blend>1.0f) blend=1.0f;
  *(s32 *)(self+4)=((s32)(s[10]*blend+0.0f)<<24)|(*(s32 *)s&0xffffff);
  if(s[11]-*(s16 *)(self+0xa)>=(s32)*(f32 *)(s+0x1c)) {
   s[11]-=(s32)*(f32 *)(s+0x1c);
   *(s32 *)(s+4)=2;
  }
 } else {
  if(func_003883C8(self+0xa)) {
   func_003C7CE0(self);
  } else {
   *(s32 *)(self+4)=((s32)(*(s16 *)(self+0xa)*6.35f)<<24)|*(s32 *)s;
  }
 }
}
/* localdecomp:end func_L01_00463578 */
