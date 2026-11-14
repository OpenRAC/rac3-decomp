#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L05_00359E80 */
static __inline__ void offset_direction_359E80(vu0_v4 *position, vu0_v4 *offset, vu0_v4 *target, vu0_v4 *source, vu0_v4 *direction) {
    vu0_q delta, sum;
    __asm__("lqc2 %0, %1" : "=j"(delta) : "m"(*offset));
    __asm__("lqc2 %0, %1" : "=j"(sum) : "m"(*position));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(sum) : "j"(delta));
    __asm__("lqc2 %0, %1" : "=j"(delta) : "m"(*source));
    __asm__("sqc2 %1, %0" : "=m"(*target) : "j"(delta));
    __asm__("sqc2 %1, %0" : "=m"(*position) : "j"(sum));
    __asm__("lqc2 %0, %2\n\tlqc2 %1, %3"
        : "=&j"(delta), "=&j"(sum) : "m"(*position), "m"(*target));
    __asm__("vsub.xyz %0, %1, %0" : "+j"(delta) : "j"(sum));
    __asm__("sqc2 %1, %0" : "=m"(*direction) : "j"(delta));
}
extern vu0_v4 D_L05_001E2700_00359E80[];
extern char D_001DD6B0_sda_00359E80[8],D_001DD690_sda[8];
__asm__(".extern D_001DD6B0_sda_00359E80, 8");
__asm__(".extern D_001DD690_sda, 8");
extern void func_003BDA38(void *,int,void *),func_003BD9A0(void *,int,void *),func_003888F0(void *,void *,void *),func_00388830(void *,void *,float),func_003BF6A8(void *,float),func_003888C8(void *,void *,void *);
extern float func_0037E250(float,float);
extern int func_0037E1D8(int);
extern void func_L05_00465110(void *,void *,void *,int,int);
void func_L05_00359E80(void *moby) {
    vu0_v4 velocity={0,0,0,0}; vu0_v4 position; vu0_v4 matrix[4]; vu0_v4 transformed,direction,target;
    void *data=*(void **)((char *)moby+0x68); int i,j,a; void *scratch=&transformed;
    for(i=0;i<2;i++) {
        func_003BDA38(*(void **)((char *)data+0x3ec),2,&position);
        func_003BD9A0(*(void **)((char *)data+0x3ec),2,matrix);
        func_003888F0(scratch,(vu0_v4 *)D_001DD6B0_sda_00359E80+i,matrix);
        offset_direction_359E80(&position,&transformed,&target,&D_L05_001E2700_00359E80[0],&direction);
        func_00388830(&direction,&direction,0.0f);
        vec_add_ab(&position,&position,&direction);
        for(j=4;j>=0;j--) {
            func_003BF6A8(&position,0.0f);
            velocity.x=func_0037E250(0.0f,0.0f)*0.016666668f;
            velocity.y=func_0037E250(0.0f,0.0f)*0.016666668f;
            velocity.z=func_0037E250(-15.0f,-16.0f)*0.016666668f;
            func_003888C8(&velocity,&velocity,(char *)moby+0xc0);
            a=func_0037E1D8(2);
            func_L05_00465110(&position,&velocity,D_001DD690_sda,a,func_0037E1D8(3)-1);
        }
    }
}
/* localdecomp:end func_L05_00359E80 */
