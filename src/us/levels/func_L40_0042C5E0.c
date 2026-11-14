#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L40_0042C5E0 */
typedef int Q __attribute__((mode(TI)));
typedef struct { float x,y,z,w; } __attribute__((aligned(16))) V;
typedef struct { char p0[12]; float strength; int timer; int p14; int handle; char p1c[20]; V target,control; } State;
typedef struct { char p0[16]; V pos; u8 state; char p21[71]; State *p; char p6c[76]; char *parent; } Obj;
typedef struct { char p0[0x98]; int value; } Other;
typedef struct { Other *other; char gap[4]; Q value; } __attribute__((packed)) Const;
extern float D_001DC220_sda[2];
__asm__(".extern D_001DC220_sda, 8");
extern float D_001DC214_sda;
__asm__(".extern D_001DC214_sda, 4");
extern int D_001DC210_sda_0042C5E0;
__asm__(".extern D_001DC210_sda_0042C5E0, 4");
extern Q D_L40_0025BB20[];

typedef struct { char pad[0x64]; u8 *data; } Table;
extern Table D_L40_0029B0D8[];
extern int D_L40_00242AB0;
__asm__(".extern D_L40_00242AB0, 16");
extern void func_003888C8(void*,void*,void*),func_003BDA38(void*,int,void*);
extern void func_L39_005BA378(void*,void*,int);
extern void func_00388830(void*,void*,float);
extern float func_00388A28(float,float),func_L39_005B2510(float,float);
extern void func_00389158(void*,void*,void*,float);
extern int func_003CE740(void*,void*,int,void*,int);
extern void func_L01_00443648(float,float,float,void*,void*,int,int,int,int);
extern void func_L40_0042CBA0(void*,int,int);
extern float func_00388770(void*);
extern int func_L39_0059CF60(void*,float,float,float,float,float);
extern int func_00388398(int*);
extern void func_L01_00421FE0(int),func_003BD360(void*);
extern u8 *func_L01_0046C468(void*,void*,int,int,int,int,int,float,float,int,float);
extern void func_L01_003989D8(void*),func_L40_0042CA90(void*);
extern void func_L01_004026A0(void(*)(void*),void*);
void func_L40_0042C5E0(Obj *o) {
 V a,b,c,d,e,f; State *p=o->p; float angle,t; int i; u8 *r;
 func_003888C8(&a,D_001DC220_sda,o->parent+0xc0);
 func_003BDA38(o->parent,3,&o->pos);
 vec_add_ba(&o->pos,&o->pos,&a); *(Q*)&b=*(Q*)&o->pos;
 func_L39_005BA378(&o->pos,&c,1);
 *(Q*)&d=*(Q*)&o->pos; vec_sub_ba(&e,&p->target,&o->pos);
 func_00388830(&e,&e,1.0f);
 angle=func_00388A28(p->target.x-o->pos.x,p->target.y-o->pos.y);
 if(angle<1.57079637f) angle=func_L39_005B2510(0,-0.785398185f);else angle=func_L39_005B2510(0,0.785398185f);
 *(Q*)&p->control=*(Q*)&o->pos;p->control.z-=D_001DC214_sda;
 vec_sub_ba(&p->control,&p->control,&o->pos);
 func_00389158(&p->control,&p->control,&e,angle);
 vec_add_ab(&p->control,&o->pos,&p->control);
 switch(o->state) {
 case 0:
 if(func_003CE740(&o->pos,&p->target,0,o->parent,0)) {
 *(Q*)&f=D_L40_0025BB20[0];
 func_L01_00443648(1.5f,p->strength,1,o,&f,0x210001,1,1,0);
 if(!(*(Other **)((char *)D_L40_0025BB20 - 8)))func_L40_0042CBA0(&f,15,0);
 else if((*(Other **)((char *)D_L40_0025BB20 - 8))->value)func_L40_0042CBA0(&f,10,0);
 o->state=1;p->timer=D_001DC210_sda_0042C5E0;
 }else {o->state=1;p->timer=D_001DC210_sda_0042C5E0;}
 vec_sub_ba(&f,&p->target,&o->pos);t=func_00388770(&f);func_00388830(&f,&f,t*0.5f);
 vec_add_ba(&f,&o->pos,&f);
 p->handle=func_L39_0059CF60(&f,10,0,0.1f,0.1f,1);
 break;
 case 1:
 if(func_00388398(&p->timer)) {if(p->handle!=-1)func_L01_00421FE0(p->handle);func_003BD360(o);return;}
 for(i=0;i<10;i++) {
 t=func_L39_005B2510(0.25f,0.4f)*210000.0f;
 r=func_L01_0046C468(&o->pos,&D_L40_00242AB0,2,0x804020,2,127,16,t,t,0,0);
 if(r)r[2]=*D_L40_0029B0D8->data;
 r=func_L01_0046C468(&o->pos,&D_L40_00242AB0,2,0xff8040,-1,127,16,t,t,0,0);
 if(r)r[2]=*D_L40_0029B0D8->data;
 }
 func_L01_003989D8(o);func_L01_004026A0(func_L40_0042CA90,o);break;
 }
 if(o->pos.x<2 || o->pos.x>1021 || o->pos.y<2 || o->pos.y>1021 || o->pos.z<2 || o->pos.z>1021)func_003BD360(o);
}
/* localdecomp:end func_L40_0042C5E0 */
