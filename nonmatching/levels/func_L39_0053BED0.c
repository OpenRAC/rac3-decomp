/* NTSC-U draft (Codex wave 3): C of func_L39_0053B738, the NTSC-U twin of func_L39_0053BED0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 15 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_0053B738", whose code is not the PAL one).
 * Worker's note: 15 diff; 8 checks; table-address/shift register order at both player lookups, flags-store/argument order and three constant-load positions remain; pointer/struct-entry/integer-table forms stall; cases decoded directly as 16/32/64, no jump table; best log ...
 */
#include "common.h"
/* localdecomp:start func_L39_0053B738 */
typedef struct { float position[3]; int tick; unsigned int command; int player; unsigned int key; } Message_53B738;
typedef struct Object_53B738 Object_53B738;
typedef struct Player_53B738 Player_53B738;
typedef struct { char pad[0x10]; Object_53B738 *(*get)(Player_53B738 *); } Vtable_53B738;
struct Player_53B738 { char pad[0x14]; Vtable_53B738 *vt; };
typedef struct { char pad[0x30]; int tick; char pad34[0xc]; int reset; char pad44[4]; int state; char pad4c[6]; short active; Object_53B738 *target; int timer; int marker; } State_53B738;
struct Object_53B738 { char pad[0x10]; float position[4]; unsigned char flags; char pad21[0xf]; unsigned char type; char pad31[0x37]; State_53B738 *state; char pad6c[0x50]; unsigned char dead; };
extern Object_53B738 *func_L39_0053B6B8(int,int);
extern Player_53B738 *D_L39_0024CF20[];
extern void func_L39_00644110(Player_53B738 *,int);
extern Player_53B738 *func_L39_0061AA60(int);
extern float func_003887C8(float *,float *);
extern float func_L01_0040C018(float *,float *);
extern void func_L39_005F0CE0(int,int,Object_53B738 *);
void func_L39_0053B738(Message_53B738 *msg) {
 Object_53B738 *m,*target;
 State_53B738 *s;
 unsigned int hi,lo;
 unsigned int key=msg->key;
 hi=key>>16;
 lo=key&0xffff;
 m=func_L39_0053B6B8(hi,lo);
 if(!m) {
  if(msg->command==64) {
   Player_53B738 *p=D_L39_0024CF20[hi];
   if(p)func_L39_00644110(p,lo);
  }
  return;
 }
 s=m->state;
 switch(msg->command) {
 case 16:
  if(!msg->player)m->dead=1;
  else s->marker=-1;
  m->type=255;
  break;
 case 32: {
  Player_53B738 *p;
  if(s->tick && s->tick < msg->tick)return;
  s->tick=msg->tick;
  p=func_L39_0061AA60(msg->player);
  target=p->vt->get(p);
  if(!target || target->flags==254 || target->flags==253)break;
  if(func_003887C8(m->position,target->position)>20.0f)return;
  if(m->flags&16) {
   s->target=target;
   s->timer=600;
  } else {
   m->flags|=16;
   func_L39_005F0CE0(0,0,m);
   *(Object_53B738 **)((char *)s+0x54)=target;
   *(int *)((char *)s+0x48)=7;
   *(int *)((char *)s+0x58)=600;
   *(short *)((char *)s+0x52)=1;
   *(int *)((char *)s+0x40)=0;
  }
  break;
 }
 case 64: {
  float position[4];
  position[0]=msg->position[0];
  position[1]=msg->position[1];
  position[2]=msg->position[2];
  position[3]=0.0f;
  if(func_L01_0040C018(m->position,position)>15.0f) {
   Player_53B738 *p;
   m->dead=1;
   m->type=255;
   p=D_L39_0024CF20[hi];
   if(p)func_L39_00644110(p,lo);
  }
  break;
 }
 }
}
/* localdecomp:end func_L39_0053B738 */
