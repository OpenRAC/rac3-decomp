/* functional: high. Near-miss draft (compiles under file flags); 1 diff word: retail has move a0,s2 in a delay slot before a call to the empty func_L01_0034F7E8, no effect */
/* localdecomp:start func_L01_0034E808 */
#include "vu0.h"
typedef struct { u8 pad0[0x10]; s128 pos; u8 state; u8 pad21[0xAA-0x21]; s16 cls; u8 padAC[0xE0-0xAC]; f32 axis[4]; } Obj_0034E808;
typedef struct { u8 pad0[0x18]; s32 slot; u8 pad1C[2]; s16 timer; Obj_0034E808 *owner; u8 pad24[12]; s128 pos; Obj_0034E808 *target; s32 joint; } State_0034E808;
typedef struct { u8 pad[0x80]; s128 pos; u8 pad90[0x25C0-0x90]; Obj_0034E808 *obj; } Hero_0034E808;
static __inline__ s32 cls_0034E808(Obj_0034E808 *t) { s32 value=t->cls; return value; }
extern Hero_0034E808 D_001A4BE0;
extern u8 D_001A30B0[];
void func_L01_0034E808(char *obj) {
    extern void func_003C2880(char *);
    extern void func_003C2F58(Obj_0034E808 *,s32,s128 *);
    extern void *func_00382348(Obj_0034E808 *);
    extern void func_L01_0034F7E8(void);
    extern void func_L01_0034EAA0(char *);
    extern void func_003A4F28(s32);
    vu0_v4 temp;
    State_0034E808 *s=*(State_0034E808 **)(obj+0x68);
    Obj_0034E808 *t;
    if(func_0038CB00(&s->timer)) {
        func_003C2880(obj);
        return;
    }
    t=s->target;
    if(!t) goto fallback;
    { s32 cls=t->cls; s32 state;
    if(cls==0xDC1) goto fallback;
    state=t->state;
    if(state==0xFE) goto joint;
    if(state==0xFD) goto joint;
    if(cls==0x186B) {
        *(s128 *)(obj+0x10)=t->pos;
        goto positioned;
    }
    }
joint:
    t=s->target;
    if(!t) goto fallback;
    if(t->state==0xFE) goto fallback;
    if(t->state==0xFD) goto fallback;
    if(cls_0034E808(t)==0x184E || cls_0034E808(t)==0x186D) {
        func_003C2F58(t,s->joint,(s128 *)(obj+0x10));
        goto positioned;
    }
fallback:
    func_0038CE20((f32 *)&temp,D_001A4BE0.obj->axis,0.75f);
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*(s128 *)(obj+0x10)) : "m"(D_001A4BE0.pos),"m"(temp) : "vf1","vf2");
positioned:
    if(s->owner) {
        if(s->owner->state==0xFE) goto clear_owner;
        if(s->owner->state==0xFD) {
clear_owner:
            s->owner=0;
        }
        if(s->owner) {
            void *info;
            s->pos=s->owner->pos;
            info=func_00382348(s->owner);
            if(info) {
                func_0038CE20((f32 *)&temp,s->owner->axis,*(f32 *)((u8 *)info+0x10));
                __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(s->pos) : "m"(s->pos),"m"(temp) : "vf1","vf2");
            }
        }
    }
    if((u8)obj[0x20]==1) {
        func_L01_0034F7E8();
        func_L01_0034EAA0(obj);
    } else if(s->slot>=0) {
        if(s->slot!=-1) {
            u8 *row=D_001A30B0+(s->slot<<7);
            if(*(char **)(row+0xDC)==obj && row[0xD0]) func_003A4F28(s->slot);
        }
        s->slot=-1;
    }
}
/* localdecomp:end func_L01_0034E808 */
