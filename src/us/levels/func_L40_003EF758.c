#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L40_003EF758 */
extern float D_001DB684_sda;
__asm__(".extern D_001DB684_sda, 4");
extern int D_001A5F78[];
extern void func_003886E8(void*,void*,float);
extern float func_00388770(void*),func_00388A28(float,float);
extern void func_L40_003F1988(void*,void*,float);
void func_L40_003EF758(unsigned char *m){
 unsigned char *v=*(unsigned char**)(m+0x68);
 vu0_v4 d;
 int n;
 float angle;
 vec_sub_ba(&d,v+0x2d0,m+0x10);
 n=*(int*)(v+0x2b4)+(int)D_001DB684_sda-D_001A5F78[0];
 n=(int)(n*0.06f);
 d.z=0.0f;
 if(n<=0)n=0;
 ++n;
 func_003886E8(v+0x110,&d,1.0f/n);
 if(func_00388770(v+0x110)==0.0f){--*(int*)(v+0x250);}
 else {
 angle=func_00388A28(*(float*)(v+0x2d0)-*(float*)(m+0x10),*(float*)(v+0x2d4)-*(float*)(m+0x14));
 if(n!=1){func_L40_003F1988(m,v+0x2d0,angle);}
 else {func_L40_003F1988(m,v+0x2d0,angle);}
 --*(int*)(v+0x250);
 }
}
/* localdecomp:end func_L40_003EF758 */
