#include "common.h"
/* localdecomp:start func_L03_003B7270 */
extern float func_0037E250(float,float);
extern int func_0037E1D8(int);
extern u8 D_L03_001D66B0_003B7270;
extern u8 *func_L01_00467DA8(void *,int,float,float,u32,int,int,void *,float,int);
void func_L03_003B7270(u8 *o) {
 float f=func_0037E250(1.0f,2.0f);
 int n=func_0037E1D8(2);
 if(!n)--n;
 func_L01_00467DA8(o+0x10,20,f*0.3f,f,0x88202080,0,n,&D_L03_001D66B0_003B7270,0.0f,0);
}
/* localdecomp:end func_L03_003B7270 */
