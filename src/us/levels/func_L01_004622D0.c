#include "common.h"

/* NTSC-U counterpart of func_L01_00465878 (src/levels/shared/L01_00465878.c) */
#include "vu0.h"

/* localdecomp:start func_L01_004622D0 */
extern s32 D_L01_001D673C_004622D0;
extern u32 D_L01_001DFBC0_004622D0;
typedef struct {
    vu0_v4 velocity;
    s32 color_start, color_end;
    s16 duration, emit;
    f32 gravity;
} Vars_00465878;
void func_L01_004622D0(u8 *self) {
    extern s32 func_003883C8(u8 *);
    extern void func_003C7CE0(u8 *);
    extern s32 func_L01_00444338_004622D0(s32, s32, f32);
    extern void func_003BFC18(void *, void *, s32);
    extern void func_003886E8(void *, void *, f32);
    extern void func_L01_004C6EC8(void *, void *);
    extern f32 func_0037E250(f32, f32);
    extern f32 func_00388770(void *);
    extern void func_00388830(void *, void *, f32);
    extern s32 func_0037E208(s32,s32);
    extern void func_L01_00462190(void *,void *,s32,s32,s32,s32,s32,s32,s32,f32);
    Vars_00465878 *s = (Vars_00465878 *)(self+0x20);
    vu0_v4 *pos;
    struct { vu0_v4 copy,gravity,jitter,random; } v;
    f32 length;
    if (func_003883C8(self+0xA)) {
        func_003C7CE0(self);
        return;
    }
    pos=(vu0_v4 *)(self+0x10);
    *(f32 *)(self+0xC)=(f32)*(s16 *)(self+0xA)*s->gravity/(f32)s->duration;
    *(s32 *)(self+4)=func_L01_00444338_004622D0(s->color_end,s->color_start,(f32)*(s16 *)(self+0xA)/(f32)s->duration);
    vec_add_ab(pos,pos,&s->velocity);
    if (D_L01_001D673C_004622D0) {
        func_003BFC18(pos,&v.gravity,0);
        func_003886E8(&v.gravity,&v.gravity,s->velocity.w);
        vec_add_ab(&s->velocity,&s->velocity,&v.gravity);
    } else {
        s->velocity.z -= s->velocity.w;
    }
    v.copy=*(vu0_v4 *)(self+0x10);
    if (*(f32 *)(self+0x1C) != 0.0f) {
        if (*(f32 *)(self+0x1C) == 2.0f) func_L01_004C6EC8(pos,pos);
        *(f32 *)(self+0x1C)=2.0f;
    }
    if (s->emit && (D_L01_001DFBC0_004622D0 & 1)) {
        *(vu0_q *)&v.random=0;
        v.random.x=func_0037E250(-1.0f,1.0f);
        v.random.y=func_0037E250(-1.0f,1.0f);
        v.random.z=func_0037E250(-1.0f,1.0f);
        v.jitter=v.random;
        length=func_00388770(s);
        func_00388830(&v.jitter,&v.jitter,length*func_0037E250(0.15f,0.25f));
        vec_add_ab(&v.jitter,&v.jitter,&s->velocity);
        func_003886E8(&v.jitter,&v.jitter,func_0037E250(0.75f,0.95f));
        func_L01_00462190(pos,&v.jitter,*(s32 *)(self+4),s->color_end,func_0037E208(15,30),0,self[2],self[3],(s32)*(f32 *)(self+0x1C),*(f32 *)(self+0xC));
    } else {
        func_003886E8(s,s,0.96f);
    }
}
/* localdecomp:end func_L01_004622D0 */
