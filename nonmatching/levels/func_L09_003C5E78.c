/* NTSC-U draft (Codex wave 3): C of func_L09_003C4550, the NTSC-U twin of func_L09_003C5E78, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 249 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2") (NTSC-U twin "func_L09_003C4550", whose code is not the PAL one).
 * Worker's note: 249 diff; allowed flags reproduce prior best; reversed branch/common active rewrite gives 251 diff; call tails cross-jumped at states 7/8 and VU0 block cannot interleave a0=6 before sqc2 without unavailable j class; state table preserved in .switch.txt; best ...
 */
#include "common.h"
/* localdecomp:start func_L09_003C4550 */
typedef struct {float x,y,z,w;} __attribute__((aligned(16))) Vec;
extern unsigned char *D_L09_001E011C;
extern Vec D_L09_001DEA20;
extern void func_L01_004A6DF8(void*,int);
extern void func_003BD9A0(void*,int,void*);
extern void func_003890D8(void*,void*);
extern void func_00388EB8(void*,void*,void*);
extern void func_003888C8(void*,void*,void*);
extern void func_003BE4F0(void*,int,int,int);
extern int func_L01_00441FB8(void*,int,int);
extern int func_0037E208(int,int);
extern float func_L01_00436500(void*);
void func_L09_003C4550(unsigned char *m) {
 Vec joints[4]; float matrix[12] __attribute__((aligned(16))); Vec point;
 unsigned char *v=*(unsigned char**)(m+0x68),*a;
 int active;
 if(*(int*)(v+0x758)==-1)return;
 a=D_L09_001E011C+(*(int*)(v+0x758)<<8);
 if(*(float*)(v+0x30)<=0.0f && m[0xbc]!=9){
 *(int*)(a+0x98)=0;
 *(unsigned short*)(a+0x34)=(*(unsigned short*)(a+0x34)|0x41)&0xefff;
 func_L01_004A6DF8(a,1);
 }
 func_003BD9A0(m,14,joints);
 func_003890D8(v+0x570,matrix);
 func_00388EB8(a+0xc0,m+0xc0,matrix);
 func_003888C8(&point,&D_L09_001DEA20,a+0xc0);
 __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec*)(a+0x10)) : "m"(joints[3]),"m"(point) : "vf1","vf2");
 active=(a[0x20]==7 || a[0x20]==8);
 if(a[0x20]!=6 && *(unsigned short*)(a+0x96)>20 && *(short*)(v+0x78e)>=2){
 if(*(short*)(v+0x78e)>=4){func_003BE4F0(a,8,0,2);active=1;func_L01_00441FB8(a,8,-1);*(short*)(v+0x78e)=0;}
 else {func_003BE4F0(a,7,0,2);func_L01_00441FB8(a,7,-1);*(short*)(v+0x78e)=0;active=1;}
 }
 if(!active && v[0x7ae] && a[0x20]!=6){func_003BE4F0(a,6,0,2);func_L01_00441FB8(a,6,-1);}
 if(!active && v[0x7af] && *(float*)(*(unsigned char**)(v+0x6d0)+0x138)>0.0333333351f && (*(unsigned long*)(v+0x7a8)&0xF00000000000000UL)){
 func_003BE4F0(a,3,0,2);active=1;func_L01_00441FB8(a,3,-1);
 }
 if(!active && *(float*)(*(unsigned char**)(v+0x6d0)+0xd8)>0.02036217600107193f){func_003BE4F0(a,4,0,6);active=1;func_L01_00441FB8(a,4,-1);}
 if(!active && *(float*)(*(unsigned char**)(v+0x6d0)+0xd8)<-0.02036217600107193f){func_003BE4F0(a,5,0,6);active=1;func_L01_00441FB8(a,5,-1);}
 if(!active && a[0x20]!=9 && *(short*)(*(unsigned char**)(v+0x6d0)+0x12a)>=16){func_003BE4F0(a,9,0,2);func_L01_00441FB8(a,9,-1);}
 v[0x7ae]=0;
 switch(a[0x20]){
 case 1:
 if(*(unsigned short*)(a+0x96)>*(short*)(v+0x7ac)){
 func_003BE4F0(a,2,0,10);*(short*)(v+0x7ac)=func_0037E208(170,300);func_L01_00441FB8(a,2,-1);
 }break;
 case 2:
 if(*(unsigned short*)(a+0x96)>*(short*)(v+0x7ac)){
 func_003BE4F0(a,1,0,10);*(short*)(v+0x7ac)=func_0037E208(150,300);func_L01_00441FB8(a,1,-1);
 }break;
 case 6:
 *(float*)(a+0x48)=1.5f;
 if(a[0x60]&2){*(float*)(a+0x48)=1.0f;func_003BE4F0(a,1,0,10);func_L01_00441FB8(a,1,-1);}break;
 case 9:
 if(*(short*)(*(unsigned char**)(v+0x6d0)+0x128)){
 if(func_L01_00436500(a)>=4.0f)*(float*)(a+0x48)=0.0f;
 else *(float*)(a+0x48)=0.15f;
 } else *(float*)(a+0x48)=1.0f;
 case 7:case 8:
 if(a[0x60]&2){func_003BE4F0(a,1,0,10);func_L01_00441FB8(a,1,-1);}break;
 case 3:case 4:case 5:
 if(*(unsigned short*)(a+0x96)>30){func_003BE4F0(a,1,0,10);func_L01_00441FB8(a,1,-1);}break;
 }
 ++*(unsigned short*)(a+0x96);
}
/* localdecomp:end func_L09_003C4550 */
