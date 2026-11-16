#include "common.h"

/* NTSC-U counterpart of func_L01_003691D8 (src/levels/shared/L01_00363E68.c) */
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;

/* localdecomp:start func_L01_003683D8 */
typedef struct { u8 pad0[0x24]; f32 scale; } Class_003691D8;
typedef struct {
 u8 pad0[0x10]; s128 pos; u8 state; u8 pad21[3]; Class_003691D8 *cls;
 u8 pad28[4]; f32 scale; u8 pad30[4]; u16 flags;
 u8 pad36[0x62]; s32 data; u8 pad9C[0x24]; s128 rot[3]; f32 angles[4];
} Moby_003691D8;
extern s128 D_L01_001E2AC0[];
void func_L01_003683D8(Moby_003691D8 *m) {
 extern void func_L01_003685F8(void *);
 extern s32 func_003894E8(void *,f32);
 extern f32 func_00389380(f32,f32);
 extern void func_00388BD0(void *,void *);
 extern void func_L01_004026A0_003683D8(void *,void *);
 extern f32 func_L01_0040C018(void *,void *);
 extern void func_L01_004A6DF8(void *,s32);
 extern void func_L01_0032FE90_003683D8(void *,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32,f32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
 S_38C110v v;
 if(m->flags & 0x80) return;
 switch(m->state) {
 case 3: break;
 case 1:
  *(s128 *)&v=m->pos;
  v.w=m->scale/m->cls->scale/1.5f*1.4f;
  if(func_003894E8(&v,40.0f)==-1) return;
  m->angles[2]=func_00389380(m->angles[2],0.02617994137108326f);
  func_00388BD0(m->rot,m->angles);
  func_L01_004026A0_003683D8(func_L01_003685F8,m);
  break;
 case 2:
  if(func_L01_0040C018(D_L01_001E2AC0,&m->pos)<1600.0f) {
   func_L01_0032FE90_003683D8(&m->pos,0,25,20,20,20,0,0,0.2f,0.0f,0.0f,2.0f,
    1,1,1,0,0,1,0,0,0xF78E38,0xF76300,0xFF7F40,0xFF2000,0xFF8F00,0xFF6430,0x7FFFA060,0x28FF0000,0xFF6430,0);
  }
  m->data=0;
  m->state=3;
  m->flags=(m->flags|0x41)&0xEFFF;
  func_L01_004A6DF8(m,1);
  break;
 }
}
/* localdecomp:end func_L01_003683D8 */
