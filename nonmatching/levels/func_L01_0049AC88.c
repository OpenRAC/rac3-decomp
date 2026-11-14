/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_00497448, the NTSC-U twin of func_L01_0049AC88, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/shared/L01_00499C80.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
/* localdecomp:start func_L01_00497448 */
typedef struct { char pad[0x144]; float axis0,axis1,axis2; char p[0x74]; int buttons; } Input;
typedef struct { char pad[0x24]; char *model; char p28[4]; float scale; char p30[0xc0]; float x,y,z; } Obj;
typedef struct { int a,b,mode,text; } Row;
extern Input *D_001D52FC[];
extern Obj *D_001D9370_sda[1];
extern int D_001D93B0_sda;
extern int D_001D93B4_sda;
extern float D_001D9404_sda;
extern float D_001D9408_sda;
extern float D_001D940C_sda;
extern float D_001D9400_sda;
extern float D_001D93F0_sda;
extern float D_001D93F4_sda;
extern float D_001D93FC_sda;
extern Row D_L01_002EBE38[];
extern int func_L01_0047B380(void);
extern void func_L01_00513758(int),func_L01_005120B8(void*);
extern int func_L01_00497BC8(int),func_L01_00497C30(int);
extern float func_00389380(float,float),func_003893C8(float,float);
extern void *func_0037DF98(int);
extern void func_L01_00512FE8(int,void*),func_L01_00512D70(int,int);
void func_L01_00497448(void *arg) {
 Obj *o; float v,max,scale,r;
 if(D_001D52FC[0]->buttons&0x910) { func_L01_00513758(func_L01_0047B380());func_L01_005120B8(arg); }
 if(D_001D52FC[0]->buttons&4) { D_001D93B0_sda=D_001D93B4_sda;D_001D93B4_sda=func_L01_00497BC8(D_001D93B4_sda); }
 else if(D_001D52FC[0]->buttons&8) { D_001D93B0_sda=D_001D93B4_sda;D_001D93B4_sda=func_L01_00497C30(D_001D93B4_sda); }
 if(D_001D93B4_sda!=-1) {
 o=D_001D9370_sda[D_001D93B4_sda];
 if(o) {
 if(D_L01_002EBE38[D_001D93B4_sda].mode==0) {
 o->x=func_00389380(o->x,D_001D52FC[0]->axis1*(-(D_001D9404_sda*0.017453292f*0.016666668f)));
 v=func_003893C8(o->y,1.57079637f);
 v=func_00389380(v,D_001D52FC[0]->axis2*(-D_001D9408_sda*0.017453292f*0.016666668f));
 max=D_001D940C_sda*0.017453292f; if(v>max)v=max;else if(v< -max)v= -max;
 o->y=func_00389380(1.57079637f,v);
 scale=*(float*)(o->model+36);r=o->scale/scale+D_001D52FC[0]->axis0*(-D_001D9400_sda);
 if(r>D_001D93F4_sda)r=D_001D93F4_sda;if(r<D_001D93F0_sda)r=D_001D93F0_sda;o->scale=scale*r;
 } else {
 o->z=func_00389380(o->z,D_001D52FC[0]->axis1*(D_001D9404_sda*0.017453292f*0.016666668f));
 o->y=func_00389380(o->y,D_001D52FC[0]->axis2*(-D_001D9408_sda*0.017453292f*0.016666668f));
 max=D_001D940C_sda*0.017453292f;if(o->y>max)o->y=max;else if(o->y< -max)o->y= -max;
 scale=*(float*)(o->model+36)*D_001D93FC_sda;r=o->scale/scale+D_001D52FC[0]->axis0*(-D_001D9400_sda);
 if(r>D_001D93F4_sda)r=D_001D93F4_sda;if(r<D_001D93F0_sda)r=D_001D93F0_sda;o->scale=scale*r;
 }
 }
 func_L01_00512FE8(0x4d0003,func_0037DF98(D_L01_002EBE38[D_001D93B4_sda].text));func_L01_00512D70(0x4d0003,1);
 } else func_L01_00512D70(0x4d0003,0);
}
/* localdecomp:end func_L01_00497448 */
