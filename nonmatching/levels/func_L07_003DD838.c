/* P06 wave 3 reconstruction from PAL retail.
 * File flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * Stock check.py: 12 differing words. Case 4's selected index, pointer-global
 * high half, and flag update have different registers/scheduling.
 * Typed indexing, scalar hint removal, and integer address arithmetic left
 * the same residual. Stop budget reached; INCLUDE_ASM remains in the owner.
 */
#include "common.h"
typedef struct {
 s32 idx0,idx4; u8 states[8]; f32 progress,phase,angle; u8 index;
} V_3DD838;
typedef struct { u8 p0[0xBE]; u8 flags; u8 pBF[0x41]; } Target_3DD838;
typedef struct {
 u8 p0[0x20]; u8 state; u8 p21[0x13]; u16 flags;
 u8 p36[0x32]; V_3DD838 *vars; u8 p6C[0xC]; s32 color;
 u8 p7C[0x42]; u8 bBE; u8 pBF[0x31]; f32 rot;
} O_3DD838;
extern s32 D_001DE968_sda,D_001DE96C_sda;
extern f32 D_001DE960_sda,D_001DE970_sda;
__asm__(".extern D_001DE968_sda, 4");
__asm__(".extern D_001DE96C_sda, 4");
__asm__(".extern D_001DE960_sda, 4");
__asm__(".extern D_001DE970_sda, 4");
extern Target_3DD838 *D_L07_001DF41C;
extern void func_L01_004450F0(void *,s32,s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_004AAC98(s32,s32,void *,s32);
extern void func_L01_004AA760(s32,void *);
extern f32 func_003C3BE8(f32,f32,f32);
extern f32 func_0038DB48(f32);
extern s32 func_0038DBD8(s32,s32,f32);
void func_L07_003DD838(void *arg) {
 O_3DD838 *m=arg; V_3DD838 *v=m->vars;
 f32 t; s32 idx; Target_3DD838 *p;
 if(m->state==0) {
  m->color=D_001DE968_sda;
  m->flags|=0x10;
  func_L01_004450F0(m,1,-1);
 }
 switch(m->state) {
 case 1: break;
 case 2:
  if(m->bBE&4) func_L01_004450F0(m,3,-1);
  break;
 case 3:
  if(func_L01_004561B8(m)) func_L01_004AAC98(0,0x114,m,0x1D6B);
  v->progress+=D_001DE960_sda*1.2f;
  if(v->progress>=1.0f) {
   v->progress=1.0f;
   func_L01_004AA760(0,m);
   func_L01_004450F0(m,4,-1);
  }
  m->rot=func_0038DB48(func_003C3BE8(0.0f,v->angle,v->progress));
  break;
 case 4:
  if(v->states[v->index]==1) idx=v->idx0; else idx=v->idx4;
  p=(Target_3DD838 *)((s32)D_L07_001DF41C+(idx<<8));
  p->flags|=4;
  v->phase=0;
  func_L01_004450F0(m,5,-1);
  break;
 case 5:
  v->phase+=D_001DE970_sda*1.2f;
  if(v->phase>=2.0f) v->phase-=2.0f;
  if(v->phase>1.0f) t=2.0f-v->phase; else t=v->phase;
  m->color=func_0038DBD8(D_001DE968_sda,D_001DE96C_sda,t);
  break;
 }
}
