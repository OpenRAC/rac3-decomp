#include "common.h"

/* NTSC-U counterpart of func_L01_0045E010 (src/levels/shared/L01_0045D248.c): other turn-rate constants (0.0034906587f, 0.29786953f) */
/* localdecomp:start func_L01_0045AD08 */
#include "vu0.h"

extern float func_L01_0044E480(void*,void*,int);
extern float func_L01_00445758(void*,void*,int,float,float,float,float);
extern void func_00388BD0(void*,void*);
extern void func_00388EB8(void*,void*,void*);
float func_L01_0045AD08(char *m,char *state,vu0_v4 *input,int mode) {
 vu0_v4 v; float matrix[12] __attribute__((aligned(16)));int zero;float angle;
 v=*input;
 angle=func_L01_0044E480(m,&v,mode);
 zero=0;
 func_L01_00445758(&zero,state+0xb4,0,angle,0.0034906587097793818f,0.0034906587097793818f,0.2978695333003998f);
 qzero(&v);
 v.z=*(float*)(state+0xb4);
 func_00388BD0(matrix,&v);
 func_00388EB8(m+0xc0,m+0xc0,matrix);
 return fabs_asm(angle)-fabs_asm(*(float*)(state+0xb4));
}
/* localdecomp:end func_L01_0045AD08 */
