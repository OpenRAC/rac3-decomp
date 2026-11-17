#include "common.h"

typedef struct Obj_003C0638 {
    s32 f0;
    s32 f4;
    f32 f8;
    u8 fC;
} Obj_003C0638;

/* localdecomp:start func_L07_003C0458 */
typedef struct { Obj_003C0638 base; s32 color,timer; } Vars_003C0458;
typedef struct {u8 pad0[0x18];f32 z;u8 pad1c[4];u8 state;u8 pad21[0x13];u16 flags;u8 pad36[0x32];Obj_003C0638 *p;u8 pad6c[0xc];u32 color;} M_003C0458;
typedef struct {u8 pad0[0x35c];M_003C0458 *owner;s32 active;} Hero_003C0458;
extern s32 D_L07_001DE538;
extern u8 *D_L07_001DF41C;
extern Hero_003C0458 D_001A4BE0;
extern s32 D_001DE53C_sda;
extern f32 D_001DE540_sda;
__asm__(".extern D_L07_001DE538, 4");
__asm__(".extern D_001DE53C_sda, 4");
__asm__(".extern D_001DE540_sda, 4");
void func_L07_003C0458(u8 *arg) {
 extern void func_L01_004450F0(u8 *,s32,s32);
 extern void func_L01_004AAC98(s32,s32,void *,s32);
 extern s32 func_0038CAD0(s32 *);
 extern f32 func_0038D0B0(f32);
 extern u32 func_L01_0040F598(s32,u32);
 extern u32 func_0038DBD8(u32,u32,f32);
 M_003C0458 *m=(M_003C0458 *)arg;
 Vars_003C0458 *o=(Vars_003C0458 *)m->p;
 u8 *p;
 f32 blend;
 u32 a,b;
 if(m->state==0) {
  o->base.f8=m->z;
  m->flags|=0x10;
  func_L01_004450F0(arg,1,-1);
 }
 switch(m->state) {
 case 1: o->color=D_L07_001DE538; break;
 case 2:
  if(D_001A4BE0.active && D_001A4BE0.owner==m) {
   o->color=D_001DE53C_sda;
   m->z=o->base.f8-D_001DE540_sda;
   func_L01_004450F0(arg,3,-1);
  }
  break;
 case 3:
  func_L01_004AAC98(0,0,m,0x1acf);
  p=D_L07_001DF41C+(o->base.f0<<8); p[0xbe]|=4;
  if(o->base.f4!=-1) {p=D_L07_001DF41C+(o->base.f4<<8);p[0xbe]|=4;}
  func_L01_004450F0(arg,4,-1);
  break;
 }
 if(func_0038CAD0(&o->timer)) o->timer=50;
 blend=func_0038D0B0((f32)o->timer*6.283185482025146484375f/50.0f)*0.5f+0.5f;
 a=func_L01_0040F598(o->color,0x80b0b0b0);
 b=func_L01_0040F598(o->color,0x80505050);
 m->color=func_0038DBD8(a,b,blend);
}
/* localdecomp:end func_L07_003C0458 */

/* localdecomp:start func_L07_003C0638 */
/* Ps2EeAs only uses $gp for these if it knows they are small before the use. */
__asm__(".extern D_L07_001DE538, 4");
extern s32 D_L07_001DE538;
extern u8 *D_L07_001DF41C;
extern void func_L07_003DDA38(u8 *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L07_003C0638(u8 *a0, s32 a1) {
    u8 b;
    Obj_003C0638 *o;
    u8 *p;
    u8 *base;

    b = a1;
    o = *(Obj_003C0638 **)(a0 + 0x68);
    o->fC = b;
    base = D_L07_001DF41C;
    *(s32 *)((u8 *)o + 0x10) = D_L07_001DE538;
    *(f32 *)(a0 + 0x18) = o->f8;
    p = base + (o->f0 << 8);
    p[0xBE] &= 0xFB;
    func_L07_003DDA38(p, b);
    if (o->f4 != -1) {
        p = D_L07_001DF41C + (o->f4 << 8);
        p[0xBE] &= 0xFB;
        func_L07_003DDA38(p, b);
    }
    func_L01_004450F0(a0, 2, -1);
}
/* localdecomp:end func_L07_003C0638 */
