/* NTSC-U draft (2026-11-14, Codex worker): C of func_L35_003BA758, the NTSC-U twin of func_L35_003BC4B8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/35_vidcomic_5/L35_003BC4B8.c's current line.
 * Worker's note: 162 diff; best log func_L35_003BA758-02.log; default assembler emits lit4 loads for inline retail literals (Matching-Patterns.md:139); also VU scheduling/table addressing; retained .near.c 162 diff; best log w60/func_L35_003BA758-01.log; confirmed default assembler lit4 versus retail inline literals
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L35_003BA758 */
typedef struct { float x,y,z,w; } __attribute__((aligned(16))) V;
typedef struct { V v, vel; int f20; float pad24, f28; } P;
typedef struct { char p0[16]; V pos; unsigned char state; char p21[3]; char *model; char p28[4]; float scale; char p30[56]; P *p; char p6c[132]; float x,y,z; } O;
extern float D_001DEED4_sda, D_001DEED0_sda;
extern V D_L35_001E9360[];
extern char D_L35_0021F2D8[], D_L35_001D66B0[];
extern int func_L01_003F9498(V*,int,O*,float);
extern float func_00388730(V*,V*);
extern int func_L30_0034C9F8(V*,float);
extern void func_L01_00441FB8(O*,int,int);
extern int func_L01_00452EC8(O*);
extern void func_0039FE80(int,int,O*);
extern void func_L30_0034BD48(void*,O*,P*,int,int,float);
extern void func_003CF790(V*,int,O*,void*,float);
extern void func_0037E2F0(V*,float,float);
extern int func_0037E208(int,int),func_0037E1D8(int);
extern char *func_L01_00472438(V*,V*,int,int,int,int,int,float,float,float);
extern void func_L01_0044ED60(O*,int,void*,int,int,int,int,int,float,float,float,float,float,float,float,float,int,int);
extern void func_003BD360(O*);
static __inline__ void add(V*d,V*a,V*b) { __asm__("lqc2 $vf2, %2\n lqc2 $vf1, %1\n vadd.xyz $vf1,$vf1,$vf2\n sqc2 $vf1,%0":"=m"(*d):"m"(*a),"m"(*b):"vf1","vf2"); }
static __inline__ void sub(V*d,V*a,V*b) { __asm__("lqc2 $vf2, %2\n lqc2 $vf1, %1\n vsub.xyz $vf1,$vf1,$vf2\n sqc2 $vf1,%0":"=m"(*d):"m"(*a),"m"(*b):"vf1","vf2"); }
void func_L35_003BA758(O *o) {
 V a,b; int info[12]; P *p=o->p; int i; char *r;
 switch(o->state) {
 case 0:
 o->x+=p->vel.x; o->y+=p->vel.y; o->z+=p->vel.z;
 qzero(&b); b.z=p->f28; add(&p->v,&p->v,&b); add(&o->pos,&o->pos,&p->v);
 if(func_L01_003F9498(&o->pos,0,o,D_001DEED4_sda*o->scale/(*(float*)(o->model+36)))) {
 sub(&a,D_L35_001E9360,&o->pos);
 if(func_00388730(&a,&b)>0.0f) { func_L01_00441FB8(o,1,-1); break; }
 }
 if(!func_L30_0034C9F8(&o->pos,D_001DEED0_sda)) func_L01_00441FB8(o,1,-1);
 break;
 case 1:
 if(func_L01_00452EC8(o)) {
 func_0039FE80(0,0,o); func_L30_0034BD48(info,o,p,1,0,20.0f);
 if(p->f20) info[5]|=0x30000;
 func_003CF790(&o->pos,1,o,info,D_001DEED4_sda*o->scale/(*(float*)(o->model+36)));
 for(i=19;i>=0;i--) {
 func_0037E2F0(&b,0.050000004f,0.13333334f); func_0037E2F0(&a,0,0.013333334f);
 add(&a,&a,&o->pos);
 r=func_L01_00472438(&a,&b,30,func_0037E208(-3,3),0x7ffff38f,0x10fff38f,0,147000.0f,42000.0f,10.0f);
 if(r) { unsigned char v; if(func_0037E1D8(3)) { int n=func_0037E208(1,3); v=(*(unsigned char**)(D_L35_0021F2D8+0x1fc))[n]; } else v=**(unsigned char**)(D_L35_0021F2D8+0xd4); r[2]=v; r[3]=func_0037E1D8(2)?0x44:0x48; }
 }
 func_L01_0044ED60(o,63,D_L35_001D66B0,255,80,0,0,35,3,6,3,6,-1,-1,1,1,0,3);
 func_003BD360(o);
 }
 break;
 }
}
/* localdecomp:end func_L35_003BA758 */
