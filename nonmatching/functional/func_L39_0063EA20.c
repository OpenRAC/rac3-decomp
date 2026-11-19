/* functional: high. PAL port of the NTSC-U draft: callees renamed, and retail multiplies gain and damping by 1.44 before passing them (NTSC-U draft did not). */
#include "vu0.h"
typedef struct {
    u8 reserved0;u8 active;u8 reserved2[14];
    vu0_v4 transform[3];
    float angles[4],rates[4];
    vu0_v4 acceleration;
    u8 reserved70[0x30];s16 joint,selector;
    float gain,damping,scale;
} JointEA20;
extern void *func_L39_0063E9E8(void *,int);
extern void func_003C2C98(void *,void *),func_L01_0043A430(void *,int,void *),func_003C3FC0(void *,void *);
extern float func_L01_00448728(void *,float,void *,float,float,float,int);
void func_L39_0063EA20(void *owner,JointEA20 *p) {
    void *model=func_L39_0063E9E8(owner,p->selector);
    if(!model)return;
    if(p->acceleration.x==0.0f && p->acceleration.y==0.0f && p->acceleration.z==0.0f && p->scale==1.0f && fabs_asm(p->angles[0])<0.005f && fabs_asm(p->angles[1])<0.005f && fabs_asm(p->angles[2])<0.005f) {
        if(p->active)func_003C2C98(model,p);
    }else {
        func_L01_00448728(&p->angles[0],p->acceleration.x,&p->rates[0],p->gain*1.44f,p->damping*1.44f,0.0f,2);
        func_L01_00448728(&p->angles[1],p->acceleration.y,&p->rates[1],p->gain*1.44f,p->damping*1.44f,0.0f,2);
        func_L01_00448728(&p->angles[2],p->acceleration.z,&p->rates[2],p->gain*1.44f,p->damping*1.44f,0.0f,2);
        if(!p->active)func_L01_0043A430(model,p->joint,p);
        func_003C3FC0(p->transform,p->angles);
        p->transform[1].x=p->scale;p->transform[1].y=p->scale;p->transform[1].z=p->scale;
    }
    qzero(&p->acceleration);
    p->scale=1.0f;
}
