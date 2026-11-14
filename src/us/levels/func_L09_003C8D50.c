#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L09_003C8D50 */
typedef struct { u8 pad[0x200]; f32 x,y,z; } Scale133;
typedef struct {u8 pad0[0x10]; f32 rotation[4], scale[4]; u8 pad30[0x10];} Transform133;
typedef struct {u8 pad0[0x1E0]; Transform133 parts[19]; u8 pad6a0[0x10]; f32 current[4],previous[4]; u8 pad6d0[0x10]; f32 a,b,c,d;} Anim133;
extern void func_00389018(void *,s32,f32);
extern void func_L01_004455F0(f32 *,f32 *,s32,f32,f32,f32,f32);
void func_L09_003C8D50(Anim133 *obj,s32 axis) {
    f32 value=obj->current[axis];
    f32 sign;
    f32 angle;
    f32 *b,*a;
    s32 part;
    if (fabs_asm(value-obj->previous[axis])<0.001f) return;
    sign=1.0f; part=0; a=0; b=0;
    if(axis==2) {a=&obj->a;b=&obj->b;}
    else if(axis==3) {sign=-1.0f;part=4;a=&obj->c;b=&obj->d;}
    obj->previous[axis]=obj->current[axis];
    angle=value*sign;
    func_00389018(obj->parts[part].rotation,0,angle);
    func_L01_004455F0(a,b,0,angle*sign,0.035f,0.05f,0.0f);
    func_00389018(obj->parts[part+1].rotation,2,*a);
    func_00389018(obj->parts[part+2].rotation,1,value*0.32f);
    { Scale133 *scale=(Scale133 *)((u8 *)obj+((part+2)*0x40));
    scale->x=1.0f;
    scale->y=1.0f;
    scale->z=1.0f-value*1.15f; }
}
/* localdecomp:end func_L09_003C8D50 */
