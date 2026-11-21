#include "common.h"

/* NTSC-U counterpart of func_00383C10 (boot_elf). */
typedef struct { u8 pad0[0x50]; void *f50; u8 pad54[0x460 - 0x54]; } S_00222500_0037E7D8;
extern S_00222500_0037E7D8 D_U_00222500[];
extern void func_U_0038D290(s32 a, s32 b, f32 x);
extern void func_U_0038D290(s32 a, s32 b, f32 x);
extern void func_U_003838B8();
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_U_00383C18 */
typedef struct { f32 f0,f4,f8,fC,f10,f14,f18,f1C; } Floats_00383C10;
typedef struct { s32 pad[3]; s32 ticks; f32 rate; s32 counter; } Rate_00383C10;
typedef struct { s16 state; u8 previous, mode; u8 pad[12]; Floats_00383C10 a; u128_t q30,q40,q50,q60; Rate_00383C10 r; } State_00383C10;
void func_U_00383C18(u8 *obj) {
    extern void func_U_00383AB0(s32);
    extern void func_U_00383B88(s32);
    extern void func_U_00383BE0(s32);
    extern void func_U_0038D290(s32, s32, f32);
    extern void func_U_003838B8();
    extern void func_U_003C4A60(void *, void *);
    u128_t v[3];
    s32 idx = *(s32 *)(obj+0x94);
    u8 *p = (u8 *)&D_U_00222500[idx];
    State_00383C10 *s = (State_00383C10 *)(p+0x2A0);
    if (s->state == 1) {
        if (s->mode == 0) {
            *(u128_t *)(p+0x2F0)=*(u128_t *)(obj+0x30);
            func_U_003C4A60(p+0x300,obj);
        } else if (s->mode == 2) {
            *(u128_t *)(p+0x360)=*(u128_t *)(obj+0x30);
            func_U_003C4A60(p+0x370,obj);
            func_U_00383AB0(idx);
        } else {
            func_U_0038D290((s32)&v[0],*(s32 *)(p+0x240)+0xC0,1.0f);
            func_U_0038D290((s32)&v[1],*(s32 *)(p+0x240)+0xD0,1.0f);
            func_U_0038D290((s32)&v[2],*(s32 *)(p+0x240)+0xE0,1.0f);
            func_U_003838B8(p+0x310,obj+0x30,*(s32 *)(p+0x50)+0x30,&v[0],&v[1],&v[2]);
            func_U_003C4A60(p+0x350,obj);
            *(u128_t *)(p+0x370)=*(u128_t *)(p+0x350);
        }
    } else {
        if (s->mode==2) {
            func_U_00383B88(idx);
            func_U_00383AB0(idx);
        } else if (s->mode==1) {
            func_U_00383B88(idx);
            *(u128_t *)(p+0x350)=*(u128_t *)(p+0x370);
        } else if (s->mode==0) {
            func_U_00383BE0(idx);
        }
    }
    s->state=3;
    s->previous=s->mode;
    if(s->mode==0) {
        Floats_00383C10 *a=&s->a;
        a->f10=a->f1C;
        a->f14=a->f18;
        a->f1C=0;
        s->q40=s->q50;
        s->a.f0=a->fC;
        a->fC=0;
        a->f4=a->f8;
        s->q30=s->q60;
    } else {
        Rate_00383C10 *r=&s->r;
        r->counter++;
        r->ticks=r->counter;
        r->rate=1.0f/r->ticks;
    }
}
/* localdecomp:end func_U_00383C18 */
