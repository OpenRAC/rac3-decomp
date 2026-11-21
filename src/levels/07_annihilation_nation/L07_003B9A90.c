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

/* localdecomp:start func_L07_003BA0E8 */
extern u8 *D_L07_001DE508;
__asm__(".extern D_L07_001DE508, 4");
extern f32 D_L07_001DED50;
extern f32 D_001DED50_sda;
__asm__(".extern D_001DED50_sda, 4");
extern s32 D_L07_001F2140 __attribute__((section(".data")));
extern s32 D_001D545C;
extern u32 D_001A8018 __attribute__((section(".data")));
extern u32 D_001A8060 __attribute__((section(".data")));
extern u32 D_001A7F4C __attribute__((section(".data")));
extern u16 D_001A7D00 __attribute__((section(".data")));
extern u16 D_001A7DA8 __attribute__((section(".data")));
extern u8 D_001A4C60[];
extern s32 D_001D4C38, D_L07_001D7B20, D_L07_001DF518;
extern s32 D_001A7430 __attribute__((section(".data")));
extern f32 D_L07_001E0540 __attribute__((section(".sdata")));
__asm__(".extern D_L07_001E0540, 16");
void func_L07_003BA0E8(u8 *obj) {
    extern void func_L01_004450F0(u8 *, s32, s32);
    extern void func_L01_005003D0(s32, s32);
    extern void func_L01_0045F1E8(s32, s32);
    extern void func_L01_00479280(void);
    extern void func_L01_0047B420(void);
    extern void func_L01_0047B990(void);
    extern s32 func_L01_004561B8(u8 *);
    extern void func_003A52A0(s32, s32, u8 *);
    extern void func_L07_003BB360(u8 *);
    extern void func_L07_003BB410(u8 *);
    extern void func_L01_0041A5B0(s32, s32);
    extern s32 func_L01_00513EF0(void);
    extern s32 func_00382380(void *, s32, s32);
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_L07_003A2380(s32, u8 *, s32, s32);
    extern void func_L07_003BA970(u8 *);
    u8 *s=*(u8 **)(obj+0x68);
    s32 i;
    s32 *slot;
    f32 health;
    switch(obj[0x20]) {
    case 0:
        D_L07_001DE508=obj;
        obj[0x30]=255;
        s[0xAE]=255;
        s[0xAF]=0;
        *(u16 *)(obj+0x34)|=1;
        func_L01_004450F0(obj,1,-1);
        break;
    case 1:
        break;
    case 2:
        if(D_L07_001DED50<=0.0f) {
            D_L07_001DED50=0.0f;
            func_L01_005003D0(0,1);
            s[0xB0]=1;
            func_L01_0045F1E8(*(s32 *)(s+0x90),-1);
            func_L01_00479280();
            func_L01_0047B420();
            func_L01_0047B990();
            func_L01_004450F0(obj,3,-1);
        } else D_001DED50_sda=D_L07_001DED50-0.0960000008f;
        break;
    case 3:
        if(!D_L07_001F2140 && func_L01_004561B8(obj)) {
            func_003A52A0(0,4,obj);
            func_003A52A0(1,4,obj);
        }
        func_L07_003BB360(obj);
        func_L07_003BB410(obj);
        if(++*(u16 *)(obj+0x96)>900) {
            if(!(D_001A8018&((u32)1<<D_001D545C)) && !D_001A7D00) func_L01_0041A5B0(0xB87,0x2A);
        }
        if(!func_L01_00513EF0()) {
            if(func_00382380(D_001A4C60,*(s32 *)(s+0x48),0) && !D_001A7DA8 && !(D_001A8060&((u32)1<<D_001D545C))) func_L01_0041A5B0(0xB8D,0x30);
        }
        D_L07_001D7B20=s[0xAE]+0x21;
        D_L07_001DF518=D_001D4C38;
        for(i=0;i<8;i++) {
            slot=(s32 *)(s+i*4);
            if(slot[0]!=-1 && slot[8]!=-1) {
                if(func_00382380(D_001A4C60,slot[0],0)) s[0xAF]|=1<<i;
                else s[0xAF]&=~(1<<i);
            }
        }
        if(s[0xB0]==1) {
            health=(f32)D_001A7430+D_L07_001E0540;
            if(*(f32 *)(s+0x9C)<health) *(f32 *)(s+0x9C)=health;
            else if(health<*(f32 *)(s+0x9C)) s[0xB0]=0;
        }
        if(!func_L01_00513EF0()) {
            if(*(s32 *)(s+0xBC)!=-1 && func_00382380(D_001A4C60,*(s32 *)(s+0xBC),0) && !(D_001A7F4C&((u32)1<<D_001D545C))) func_L01_0041A5B0(0xB76,0x19);
        }
        if(*(s16 *)(s+0xA0)&0x8080) {
            switch(func_00382468(4)) {
            case 0: func_L07_003A2380(0x4F,obj,0,100); break;
            case 1: func_L07_003A2380(0x50,obj,0,100); break;
            default: func_L07_003A2380(func_00382498(0x67,0x69)&255,obj,0,100); break;
            }
            func_L07_003BA970(obj);
        }
        break;
    }
}
/* localdecomp:end func_L07_003BA0E8 */

/* localdecomp:start func_L07_003BA500 */
typedef struct { u8 pad[0x2850]; s32 health; } Hero_003BA500;
extern s16 *D_L07_0021C020[];
extern u8 *D_L07_001DF41C;
extern u8 *D_L07_001DF420;
extern s32 D_L07_001DF458;
extern s32 D_00142660[];
void func_L07_003BA500(u8 *obj, s32 state) {
    extern void func_L07_003C0638(u8 *, s32);
    extern void func_L07_003B2870(u8 *);
    extern void func_L07_003A8D58(u8 *, s32, u8 *);
    extern void func_L07_003B91C8(u8 *, s32, u8 *);
    extern void func_L07_003BCCD0(u8 *, s32, u8 *);
    extern void func_L07_003C8608(u8 *, s32, u8 *);
    extern void func_L07_003BE2A0(u8 *, s32, u8 *);
    extern void func_L07_003B04C8(u8 *, s32, u8 *);
    extern void func_L07_003510B8(u8 *, s32, u8 *);
    extern void func_L07_003CCD40(u8 *, s32, u8 *);
    extern void func_L07_003D2B98(u8 *, s32, u8 *);
    extern void func_L07_003B9948(u8 *, s32);
    extern void func_L07_003E3458(u8 *, s32);
    extern s32 func_00382468(s32);
    extern void func_L07_003BB768(u8 *);
    extern void func_L01_004450F0(u8 *, s32, s32);
    u8 *vars = *(u8 **)(obj + 0x68);
    u8 *m;
    s32 index = *(s32 *)(vars + 0x40);
    s16 *list;
    vars[0xAE] = state;
    list = D_L07_0021C020[index];
    while ((*(s32 *)(vars + 0x40) & 0xFF) != 0xFF &&
           *(s32 *)(vars + 0x40) <= D_L07_001DF458 &&
           list != 0 &&
           (list[-1] >= 0 || list == D_L07_0021C020[*(s32 *)(vars + 0x40)])) {
        m = D_L07_001DF41C + ((list[0] & 0x7FFF) << 8);
        if (m == 0) break;
        func_L07_003C0638(m, vars[0xAE]);
        list++;
    }
    { s16 *second = D_L07_0021C020[*(s32 *)(vars + 0x44)];
    while ((*(s32 *)(vars + 0x44) & 0xFF) != 0xFF &&
           *(s32 *)(vars + 0x44) <= D_L07_001DF458 &&
           second != 0 &&
           (second[-1] >= 0 || second == D_L07_0021C020[*(s32 *)(vars + 0x44)])) {
        m = D_L07_001DF41C + ((second[0] & 0x7FFF) << 8);
        if (m == 0) break;
        func_L07_003B2870(m);
        second++;
    }
    }
    for (m = D_L07_001DF41C; m < D_L07_001DF420; m += 0x100) {
        if (m[0xB0] == *(s32 *)(vars + 0x4C)) continue;
        switch (*(s16 *)(m + 0xAA)) {
        case 0x1982: func_L07_003A8D58(m, vars[0xAE], obj); break;
        case 0x1A4A: func_L07_003B91C8(m, vars[0xAE], obj); break;
        case 0x19D2:
        case 0x1A85:
        case 0x1D88: func_L07_003BCCD0(m, vars[0xAE], obj); break;
        case 0x19BD:
        case 0x1ADB:
        case 0x1D8A: func_L07_003C8608(m, vars[0xAE], obj); break;
        case 0x19BE:
        case 0x1A9B:
        case 0x1D89: func_L07_003BE2A0(m, vars[0xAE], obj); break;
        case 0x19DA: func_L07_003B04C8(m, vars[0xAE], obj); break;
        case 0x161E: func_L07_003510B8(m, vars[0xAE], obj); break;
        case 0x1769:
        case 0x1B36:
        case 0x1D8B: func_L07_003CCD40(m, vars[0xAE], obj); break;
        case 0x1C34: func_L07_003D2B98(m, vars[0xAE], obj); break;
        case 0x1A58: func_L07_003B9948(m, vars[0xAE]); break;
        case 0x1E26: func_L07_003E3458(m, vars[0xAE]); break;
        }
    }
    *(s16 *)(vars + 0xA0) = 0;
    *(s16 *)(vars + 0xA2) = 0;
    *(s16 *)(vars + 0xA4) = 0;
    *(s32 *)(vars + 0x94) = 0;
    *(s32 *)(vars + 0x98) = 0;
    *(s16 *)(vars + 0xA6) = 0;
    *(s16 *)(vars + 0xAA) = 0;
    *(s16 *)(vars + 0xA8) = func_00382468(50) + 100;
    *(s16 *)(vars + 0xAC) = 0;
    (*(Hero_003BA500 *)&D_001A4BE0).health = D_00142660[2];
    func_L07_003BB768(obj);
    func_L01_004450F0(obj, 2, -1);
}
/* localdecomp:end func_L07_003BA500 */

/* localdecomp:start func_L07_003BA970 */
extern void func_L07_003A8D70(u8 *);
extern void func_L07_003B94E0(u8 *);
extern void func_L07_003BCD80(u8 *);
extern void func_L07_003C86D0(u8 *);
extern void func_L07_003BE368(u8 *);
extern void func_L07_003B0530(u8 *);
extern void func_L07_00351148(u8 *);
extern void func_L07_003CCDF8(u8 *);
extern void func_L07_003D2BE0(u8 *);
extern void func_L07_003B98E0(u8 *);
extern void func_L07_003E34D8(u8 *);
extern void func_L01_00459C50(s32);
extern void func_L01_004AA760(s32, u8 *);
void func_L07_003BA970(u8 *obj) {
    u8 *vars = *(u8 **)(obj + 0x68);
    u8 *m;
    vars[0xAE] = 0;
    for (m = D_L07_001DF41C; m < D_L07_001DF420; m += 0x100) {
        if (m[0xB0] == *(s32 *)(vars + 0x4C)) continue;
        switch (*(s16 *)(m + 0xAA)) {
        case 0x1982: func_L07_003A8D70(m); break;
        case 0x1A4A: func_L07_003B94E0(m); break;
        case 0x19D2:
        case 0x1A85:
        case 0x1D88: func_L07_003BCD80(m); break;
        case 0x19BD:
        case 0x1ADB:
        case 0x1D8A: func_L07_003C86D0(m); break;
        case 0x19BE:
        case 0x1A9B:
        case 0x1D89: func_L07_003BE368(m); break;
        case 0x19DA: func_L07_003B0530(m); break;
        case 0x161E: func_L07_00351148(m); break;
        case 0x1769:
        case 0x1B36:
        case 0x1D8B: func_L07_003CCDF8(m); break;
        case 0x1C34: func_L07_003D2BE0(m); break;
        case 0x1A58: func_L07_003B98E0(m); break;
        case 0x1E26: func_L07_003E34D8(m); break;
        }
    }
    if (vars[0xB0]) {
        func_L01_00459C50(10);
    }
    func_L01_004AA760(0, obj);
    func_L01_004AA760(1, obj);
    func_L01_004450F0(obj, 0, -1);
}
/* localdecomp:end func_L07_003BA970 */
