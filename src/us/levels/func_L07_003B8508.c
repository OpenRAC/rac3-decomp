#include "common.h"

/* NTSC-U counterpart of func_L07_003B9DF8 (src/levels/07_annihilation_nation/L07_003B9A90.c) */
extern s32 func_003883C8(void *);
#include "vu0.h"

/* localdecomp:start func_L07_003B8508 */
typedef struct { u8 pad[0x6C]; s32 flags,index,other; u8 toggle,delay; s16 timer; u8 pad7C[0x14]; vu0_q saved; vu0_v4 motion; } State_003B9DF8;
typedef struct { u8 pad[0x35C]; u8 *object; s32 mode; } Hero_003B9DF8;
extern Hero_003B9DF8 D_001A4BE0;
void func_L07_003B8508(u8 *obj) {
    extern s32 func_L07_003B9310(s32,s32);
    extern void func_L01_00441FB8(u8 *,s32,s32);
    extern void func_0039FE80(s32,s32,u8 *);
    extern s32 func_L01_00452EC8(u8 *);
    extern void func_L01_00440A88(void *,f32,f32);
    extern void func_L07_003B87A8(u8 *);
    State_003B9DF8 *s=*(State_003B9DF8 **)(obj+0x68);
    vu0_v4 offset;
    if (obj[0x20]!=0 && s->other!=0) {
        if (!func_L07_003B9310(s->other,s->index)) return;
    }
    switch(obj[0x20]) {
    case 0:
        obj[0x30]=255;
        *(s16 *)(obj+0x32)=64;
        obj[0x31]=0;
        s->other=0;
        s->index=-1;
        func_L01_00441FB8(obj,1,-1);
        break;
    case 1:
        if(s->index!=-1) func_L01_00441FB8(obj,2,-1);
        break;
    case 2:
        if(D_001A4BE0.object==obj && D_001A4BE0.mode>=2) {
            func_0039FE80(0,0,obj);
            func_L01_00441FB8(obj,3,-1);
        }
        break;
    case 3:
        if(func_L01_00452EC8(obj)) s->timer=s->delay;
        if(func_003883C8(&s->timer)) {
            func_L01_00441FB8(obj,4,-1);
        } else if(s->toggle) {
            s->saved=*(vu0_q *)(obj+0x10);
            func_L01_00440A88(&offset,0.0f,0.1f);
            __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*(vu0_v4 *)(obj+0x10)) : "m"(*(vu0_v4 *)(obj+0x10)),"m"(offset) : "vf1","vf2");
            s->toggle=0;
        } else {
            *(vu0_q *)(obj+0x10)=s->saved;
            s->toggle=1;
        }
        break;
    case 4:
        if(func_L01_00452EC8(obj)) {
            s->flags&=~1;
            *(vu0_q *)(obj+0x10)=s->saved;
            s->toggle=1;
        }
        s->motion.z+=0.0027777778f;
        *(f32 *)(obj+0x18)-=s->motion.z;
        if(*(f32 *)(obj+0x18)<200.0f) func_L07_003B87A8(obj);
        break;
    case 5:
        break;
    }
}
/* localdecomp:end func_L07_003B8508 */
