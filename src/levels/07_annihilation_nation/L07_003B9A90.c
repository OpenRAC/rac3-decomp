#include "common.h"

/* localdecomp:start func_L07_003B9A90 */
typedef struct {
    u8 pad0[0x24];
    f32 f24;
} S_003B9A90_B;

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    s32 f10;
    s32 f14;
    f32 f18;
    f32 f1C;
    s16 f20;
    s16 f22;
    u8 f24;
    u8 pad25[3];
} S_003B9A90_P;

typedef struct {
    u8 pad0[0x23];
    u8 f23;
    S_003B9A90_B *f24;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[0x38];
    S_003B9A90_P *f68;
    u8 pad6C[0x74];
} S_003B9A90;

extern s32 func_0038CB00(void *);
extern void func_003C2880(s32);
extern f32 func_0038D098(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0044E820(void *, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_0038CF68(s32, s32, f32);

void func_L07_003B9A90(S_003B9A90 *arg0) {
    S_003B9A90_P *p = arg0->f68;
    if (func_0038CB00(&p->f20) != 0) {
        func_003C2880((s32)arg0);
        return;
    }
    if ((p->f24 & 7) != 7) {
        f32 a = 1.0f - (f32)p->f20 * p->f18;
        f32 t = (1.0f - func_0038D098(a * 3.1415927f)) * 0.5f;
        f32 u;
        if ((p->f24 ^ 1) & 1) {
            func_L01_0044E820(arg0, func_0038DBD8(p->f10, p->f14, t));
        }
        if (!(p->f24 & 2)) {
            u = func_003C4088(p->f0, p->f4, a);
            arg0->f2C = arg0->f24->f24 * u;
        } else {
            u = p->f0;
        }
        if (!(p->f24 & 4)) {
            f32 r = func_003C4088(p->f8, p->fC, t) / u;
            func_0038CF68((s32)arg0 + 0xE0, (s32)arg0 + 0xE0, r);
        }
    }
    if (p->f20 < p->f22) {
        arg0->f23 = (u8)(s32)(p->f1C * (f32)p->f20 * 128.0f);
    }
}
/* localdecomp:end func_L07_003B9A90 */

/* localdecomp:start func_L07_003B9C28 */
#include "vu0.h"
typedef struct { f32 base, speed, low, high; s32 from,to; f32 inv_total, inv_part; s16 total,part; u8 flags; } State_003B9C28;
typedef struct { u8 pad0[0x10]; vu0_q pos; u8 pad20[4]; u8 *model; u8 pad28[4]; f32 scale; u8 opacity,kind; s16 mode; u16 flags; u8 pad36[0x32]; State_003B9C28 *state; u8 pad6C[0x84]; union { vu0_q zero; struct { u8 pad[8]; f32 phase; } f; } motion; } Obj_003B9C28;
Obj_003B9C28 *func_L07_003B9C28(vu0_q *pos, s16 delay, s16 duration, s32 from, s32 to, f32 base, f32 speed, f32 low, f32 high) {
    extern Obj_003B9C28 *func_003C24B0(s32,s32);
    extern void func_L01_0044A7D0(void *);
    extern f32 func_00382538(void);
    extern void func_L01_0044E820(void *,s32);
    extern void func_003C7C38(void *);
    Obj_003B9C28 *o=func_003C24B0(0x1A64,0x80);
    State_003B9C28 *s;
    if(o!=0) {
        o->kind=1;
        o->opacity=255;
        o->mode=64;
        func_L01_0044A7D0(o);
        o->pos=*pos;
        qzero(&o->motion.zero);
        o->motion.f.phase=func_00382538();
        s=o->state;
        s->total=delay+duration;
        s->part=duration;
        s->from=from;
        s->to=to;
        s->inv_part=1.0f/(f32)duration;
        s->inv_total=1.0f/(f32)s->total;
        if(from==to) {
            func_L01_0044E820(o,from);
            s->flags|=1;
        }
        s->base=base;
        s->speed=speed;
        if(speed<0.0f) {
            o->scale=*(f32 *)(o->model+0x24)*base;
            s->flags|=2;
        }
        s->low=low;
        s->high=high;
        if(low<0.0f || high<0.0f) s->flags|=4;
        func_003C7C38(o);
        o->flags|=0x100;
    }
    return o;
}
/* localdecomp:end func_L07_003B9C28 */

/* localdecomp:start func_L07_003B9DF8 */
typedef struct { u8 pad[0x6C]; s32 flags,index,other; u8 toggle,delay; s16 timer; u8 pad7C[0x14]; vu0_q saved; vu0_v4 motion; } State_003B9DF8;
typedef struct { u8 pad[0x35C]; u8 *object; s32 mode; } Hero_003B9DF8;
extern Hero_003B9DF8 D_001A4BE0;
void func_L07_003B9DF8(u8 *obj) {
    extern s32 func_L07_003BAC00(s32,s32);
    extern void func_L01_004450F0(u8 *,s32,s32);
    extern void func_003A52A0(s32,s32,u8 *);
    extern s32 func_L01_004561B8(u8 *);
    extern void func_L01_00443B88(void *,f32,f32);
    extern void func_L07_003BA098(u8 *);
    State_003B9DF8 *s=*(State_003B9DF8 **)(obj+0x68);
    vu0_v4 offset;
    if (obj[0x20]!=0 && s->other!=0) {
        if (!func_L07_003BAC00(s->other,s->index)) return;
    }
    switch(obj[0x20]) {
    case 0:
        obj[0x30]=255;
        *(s16 *)(obj+0x32)=64;
        obj[0x31]=0;
        s->other=0;
        s->index=-1;
        func_L01_004450F0(obj,1,-1);
        break;
    case 1:
        if(s->index!=-1) func_L01_004450F0(obj,2,-1);
        break;
    case 2:
        if(D_001A4BE0.object==obj && D_001A4BE0.mode>=2) {
            func_003A52A0(0,0,obj);
            func_L01_004450F0(obj,3,-1);
        }
        break;
    case 3:
        if(func_L01_004561B8(obj)) s->timer=s->delay;
        if(func_0038CB00(&s->timer)) {
            func_L01_004450F0(obj,4,-1);
        } else if(s->toggle) {
            s->saved=*(vu0_q *)(obj+0x10);
            func_L01_00443B88(&offset,0.0f,0.1f);
            __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*(vu0_v4 *)(obj+0x10)) : "m"(*(vu0_v4 *)(obj+0x10)),"m"(offset) : "vf1","vf2");
            s->toggle=0;
        } else {
            *(vu0_q *)(obj+0x10)=s->saved;
            s->toggle=1;
        }
        break;
    case 4:
        if(func_L01_004561B8(obj)) {
            s->flags&=~1;
            *(vu0_q *)(obj+0x10)=s->saved;
            s->toggle=1;
        }
        s->motion.z+=0.004f;
        *(f32 *)(obj+0x18)-=s->motion.z;
        if(*(f32 *)(obj+0x18)<200.0f) func_L07_003BA098(obj);
        break;
    case 5:
        break;
    }
}
/* localdecomp:end func_L07_003B9DF8 */

/* localdecomp:start func_L07_003BA000 */
typedef int Q_003BA000 __attribute__((mode(TI)));
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
s32 func_L07_003BA000(u8 *arg0, u8 *arg1, u8 arg2, s32 arg3, s32 arg4) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    if (*(s32 *)(p + 0x70) != -1) {
        return 0;
    }
    arg0[0x30] = 0x40;
    *(u16 *)(arg0 + 0x32) = 0x40;
    arg0[0x31] = 1;
    *(f32 *)(arg0 + 0x2C) = *(f32 *)(*(u8 **)(arg0 + 0x24) + 0x24);
    *(u16 *)(arg0 + 0x34) |= 0x40;
    *(Q_003BA000 *)(p + 0x80) = *(Q_003BA000 *)(arg0 + 0x10);
    *(Q_003BA000 *)(arg0 + 0x10) = *(Q_003BA000 *)arg1;
    *(Q_003BA000 *)(p + 0xA0) = *(Q_003BA000 *)D_L07_001D66B0;
    *(s32 *)(p + 0x6C) |= 1;
    p[0x79] = arg2;
    p[0x78] = 1;
    *(s32 *)(p + 0x74) = arg3;
    *(s32 *)(p + 0x70) = arg4;
    return 1;
}
/* localdecomp:end func_L07_003BA000 */

/* localdecomp:start func_L07_003BA098 */
typedef int Q_003BA098 __attribute__((mode(TI)));
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
extern void func_L01_004450F0(u8 *, s32, s32);
void func_L07_003BA098(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    if (*(s32 *)(p + 0x70) != -1) {
        *(Q_003BA098 *)(arg0 + 0x10) = *(Q_003BA098 *)(p + 0x80);
        *(Q_003BA098 *)(p + 0x80) = *(Q_003BA098 *)D_L07_001D66B0;
        *(s32 *)(p + 0x70) = -1;
        func_L01_004450F0(arg0, 0, -1);
    }
}
/* localdecomp:end func_L07_003BA098 */

INCLUDE_ASM("asm/levels", func_L07_003BA0E8);

INCLUDE_ASM("asm/levels", func_L07_003BA500);

INCLUDE_ASM("asm/levels", func_L07_003BA970);
