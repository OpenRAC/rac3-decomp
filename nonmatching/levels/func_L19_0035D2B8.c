/* NTSC-U draft (2026-11-14, Codex worker): C of func_L19_0035C238, the NTSC-U twin of func_L19_0035D2B8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/19_thran_asteroid_belt/L19_0035D238.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
/* localdecomp:start func_L19_0035C238 */
typedef int Q __attribute__((mode(TI)));
typedef struct {float x,y,z,w;} __attribute__((aligned(16))) V;
extern unsigned char D_001A4BE0[], D_L19_0021EED8[], D_L19_001D66F0[], D_L19_0035C708[];
extern unsigned char *D_L19_001ECEC0[];
extern V D_L19_70000000[];
extern int D_001DD928_sda;
extern int func_003BD668(void*,int);
extern void func_0037E2F0(float,float,void*);
extern float func_L01_00440918(float,float),func_0037E250(float,float);
extern int func_0037E208(int,int);
extern unsigned char *func_L01_0046DCB8(void*,void*,int,int,int,int,int,int,float,float,float);
extern void func_003886C0(float,void*,void*,void*);
extern int func_003CF790(float,void*,int,void*,int);
extern int func_0037E0B8(void*);
extern void func_00388830(float,void*,void*);
extern void func_L01_00443628(float,void*,void*,int,void*);
extern void func_L01_00443840(void*,void*);
extern void func_003BEBF8(float,float,void*);
extern void func_L01_004026A0(void*,void*);
void func_L19_0035C238(unsigned char *m,int *colors){
V a,b,c;
unsigned char hit[48] __attribute__((aligned(16)));
V *v=D_L19_70000000;
unsigned char *fx,*obj,**list;
int count,i,n,r;
float scale;
count=func_003BD668(*(void**)(D_001A4BE0+0x25c0),0);
if(count)for(i=count;i>0;i--,v+=2){
if(v[1].w==0.0f){
a=*v;a.w=1.0f;
func_0037E2F0(0.0f,v->w,&b);
__asm__("lqc2 $vf2, %1
	lqc2 $vf1, %2
	vadd.xyz $vf2, $vf2, $vf1
	sqc2 $vf2, %0" : "=m"(a) : "m"(a),"m"(b) : "vf1","vf2");
n=(int)func_L01_00440918(2.0f,5.0f);
scale=func_0037E250(0.7f,1.0f)*v->w;
r=func_0037E208(10,15);
func_L01_0046DCB8(&a,D_L19_001D66F0,r,colors[0],n,127,127,1,scale*210000.0f,2100.0f,-0.000833333354f);
n=-(n*2);
r=func_0037E208(10,15);
scale*=6.0f;
fx=func_L01_0046DCB8(&a,D_L19_001D66F0,r,colors[1],n,48,48,0,scale*210000.0f,4200.0f,-0.000833333354f);
}else{
a=*v;b=v[1];a.w=1.0f;b.w=1.0f;
scale=func_0037E250(0.0f,1.0f);
func_003886C0(scale,&c,&a,&b);
c.x+=func_0037E250(-v->w*0.4f,v->w*0.4f);
c.y+=func_0037E250(-v->w*0.4f,v->w*0.4f);
c.z+=func_0037E250(-v->w*0.4f,v->w*0.4f);
n=(int)func_L01_00440918(2.0f,5.0f);
scale=func_0037E250(0.7f,1.0f)*v->w;
r=func_0037E208(10,15);
func_L01_0046DCB8(&c,D_L19_001D66F0,r,colors[0],n,127,127,1,scale*210000.0f,2100.0f,-0.000833333354f);
n=-(n*2);r=func_0037E208(10,15);scale*=6.0f;
fx=func_L01_0046DCB8(&c,D_L19_001D66F0,r,colors[1],n,48,48,0,scale*210000.0f,4200.0f,-0.000833333354f);
}
if(fx)fx[2]=**(unsigned char**)(D_L19_0021EED8+0xd4);
}
if(D_001DD928_sda==2){
float *radius=(float*)(*(unsigned char**)(m+0x68)+0x2c);
count=func_003CF790(*radius*0.5f,m+0x10,0,m,0);
if(count>0)for(list=D_L19_001ECEC0,i=count;i;i--,list++){
obj=*list;
if((func_0037E0B8(obj)||(*(unsigned short*)(obj+0x34)&0x4000))&&obj!=*(unsigned char**)(D_001A4BE0+0x25c0)){
__asm__("lqc2 $vf2, %1
	lqc2 $vf1, %2
	vsub.xyz $vf2, $vf2, $vf1
	sqc2 $vf2, %0" : "=m"(a) : "m"(*(V*)(obj+0x10)),"m"(*(V*)(D_001A4BE0+0xe0)) : "vf1","vf2");
func_00388830(2.0f,&a,&a);
func_L01_00443628(2.0f,hit,m,0x410000,&a);
*(Q*)hit=*(Q*)&a;
*(int*)(hit+0x20)=1;*(float*)(hit+0xc)=5627.9248f;
hit[0x18]=10;hit[0x19]=3;
*(unsigned short*)(hit+0x1a)=*(unsigned short*)(obj+0xaa);
*(void**)(hit+0x10)=m;
func_L01_00443840(obj,hit);
}}
func_003BEBF8(16.0f,0.266666681f,radius);
}
func_L01_004026A0(D_L19_0035C708,m);
}
/* localdecomp:end func_L19_0035C238 */
