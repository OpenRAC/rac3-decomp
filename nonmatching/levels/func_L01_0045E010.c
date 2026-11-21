/* PAL port of the NTSC-U draft (Sonnet worker b15-z4, 2026-11-18): the file's own line already works (@ps2as); one word differs. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0045E010 */
extern float func_L01_00451700(void*,void*,int);
extern void func_L01_00448890(void*,void*,int,float,float,float,float);
extern void func_0038D308(void*,void*);
extern void func_0038D5F0(void*,void*,void*);
float func_L01_0045E010(char *m,char *state,vu0_v4 *input,int mode) {
 vu0_v4 v; float matrix[12] __attribute__((aligned(16)));int zero;float angle;
 v=*input;
 angle=func_L01_00451700(m,&v,mode);
 zero=0;
 func_L01_00448890(&zero,state+0xb4,0,angle,0.005026548635214567f,0.005026548635214567f,0.3574434518814087f);
 qzero(&v);
 v.z=*(float*)(state+0xb4);
 func_0038D308(matrix,&v);
 func_0038D5F0(m+0xc0,m+0xc0,matrix);
 return fabs_asm(angle)-fabs_asm(*(float*)(state+0xb4));
}
/* localdecomp:end func_L01_0045E010 */
