#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_00469928 */
typedef struct {vu0_v4 velocity; f32 r,g,b,a;} Vars_469928;
typedef struct {u32 f0,color;u8 life,p9;s16 time;f32 value;vu0_v4 position; Vars_469928 vars;} Obj_469928;
extern vu0_v4 D_L01_001EAAA0;
extern s32 func_003CE740(void *,void *,s32,void *,s32);
extern s32 func_003883C8(s16 *);
extern void func_003C7CE0(void *);
extern u32 func_L01_00445B88(f32,f32,f32,f32);
void func_L01_00469928(Obj_469928 *o) {
    vu0_v4 position;
    Vars_469928 *v;
    if(o) {
        v=&o->vars;
        v->a+=0.0f;
        o->value+=-100.0f;
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(position) : "m"(o->position),"m"(v->velocity));
        if(v->velocity.x!=0.0f || v->velocity.y!=0.0f || v->velocity.z!=0.0f) {
            if(func_003CE740(&o->position,&position,2,o,0)) {
                o->position=D_L01_001EAAA0;
                qzero(&v->velocity);
                o->value+=o->value;
            } else {
                o->position=position;
                if(v->velocity.w!=0.0f) v->velocity.z+=v->velocity.w;
                else v->velocity.z+=-0.0063f;
            }
        }
        if(v->a<=0.0f || func_003883C8(&o->time) || o->value<0.0f || position.x<0.01f || position.y<0.01f || position.z<0.01f) {
            func_003C7CE0(o);
            return;
        }
        v->r+=-0.01f;
        if(v->r<0.0f) v->r=0.0f;
        v->g+=-0.03001f;
        if(v->g<0.0f) v->g=0.0f;
        v->b+=-0.05f;
        if(v->b<0.0f) v->b=0.0f;
        v->a+=0.0f;
        if(v->a<0.0f) v->a=0.0f;
        o->color=func_L01_00445B88(v->r,v->g,v->b,v->a);
        o->life--;
    }
}
/* localdecomp:end func_L01_00469928 */
