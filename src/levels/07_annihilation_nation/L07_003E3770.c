#include "common.h"

typedef struct R_003E3770 {
    f32 f0;
    f32 f4;
    f32 f8;
} R_003E3770;
typedef struct S_003E3770 {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[4];
    u8 b20;
    u8 pad2[0x47];
    R_003E3770 *p68;
} S_003E3770;

/* localdecomp:start func_L07_003E3770 */
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);

void func_L07_003E3770(S_003E3770 *a) {
    R_003E3770 *p;
    f32 v;

    p = a->p68;
    if (a->b20 == 0) {
        ((s32 *)p)[1] = 0;
        p->f0 = func_00382538();
        p->f8 = func_003824E0(0.04188790545f, 0.0837758109f);
        a->b20 = 1;
    }
    a->f18 = a->f18 - p->f4;
    v = func_0038DAB8(p->f0, p->f8);
    p->f0 = v;
    p->f4 = func_0038D0B0(v) * 0.2f;
    a->f18 = a->f18 + p->f4;
}
/* localdecomp:end func_L07_003E3770 */

/* localdecomp:start func_L07_003E3820 */
struct S_003E3AB0;
typedef struct { u8 pad0[0x80]; f32 x,y; } Hero_003E3820;
extern u8 *D_L07_001DF500;
extern u8 D_001A4C60[];
extern u8 D_L07_003E3B30[];
__asm__(".extern D_L07_001DF500, 4");
void func_L07_003E3820(u8 *obj) {
    extern void func_L07_003E3AB0(struct S_003E3AB0 *);
    extern s32 func_L01_004BA800(void);
    extern f32 func_L01_0040E570(void *,void *);
    extern f32 func_0038D160(f32,f32);
    extern f32 func_0038DB00(f32,f32);
    extern s32 func_0038CB00(void *);
    extern f32 func_003824E0(f32,f32);
    extern s32 func_00382468(s32);
    extern f32 func_0038DB48(f32);
    extern void func_L01_00448890(f32,f32,f32,f32,f32 *,f32 *,s32);
    extern f32 func_0038D098(f32);
    extern s32 func_0038DBD8(s32,s32,f32);
    extern void func_L01_00404808(u8 *,u8 *);
    u8 *state;
    void *pos;
    f32 delta,phase;
    if(!obj[0x20]) func_L07_003E3AB0((struct S_003E3AB0 *)obj);
    state=*(u8 **)(obj+0x68);
    if(*(s32 *)state!=-1) pos=D_L07_001DF500+(*(s32 *)state<<7)+0x30;
    else pos=obj+0x10;
    if(func_L01_004BA800()) delta=0.0f;
    else if(func_L01_0040E570(pos,D_001A4C60)<*(f32 *)(state+4)**(f32 *)(state+4)) {
        delta=func_0038DB00(func_0038D160(((Hero_003E3820 *)(D_001A4C60-0x80))->x-*(f32 *)(obj+0x10),((Hero_003E3820 *)(D_001A4C60-0x80))->y-*(f32 *)(obj+0x14)),*(f32 *)(state+0x10));
        if(delta>*(f32 *)(state+8)*0.01745329238f) delta=*(f32 *)(state+8)*0.01745329238f;
        else if(delta<-(*(f32 *)(state+0xC)*0.01745329238f)) delta=-(*(f32 *)(state+0xC)*0.01745329238f);
        *(f32 *)(state+0x20)+=0.036000002175569534f;
        if(*(f32 *)(state+0x20)>=2.0f) *(f32 *)(state+0x20)-=2.0f;
    } else {
        if(func_0038CB00(state+0x1C)) {
            *(f32 *)(state+0x18)=func_003824E0(-*(f32 *)(state+0xC),*(f32 *)(state+8))*0.01745329238f*0.75f;
            *(s16 *)(state+0x1C)=func_00382468(50)+100;
        }
        *(f32 *)(state+0x20)*=0.9880000352859497f;
        delta=*(f32 *)(state+0x18);
    }
    delta=func_0038DB48(*(f32 *)(state+0x10)+delta+3.141592741f);
    func_L01_00448890(delta,0.00031415928970091045f,0.00031415928970091045f,0.015707964f,(f32 *)(obj+0xF8),(f32 *)(state+0x14),0);
    phase=*(f32 *)(state+0x20);
    phase=func_0038D098(phase>1.0f ? 2.0f-phase : phase);
    *(s32 *)(obj+0x78)=func_0038DBD8(0x202020,0xFF0000FF,(1.0f-phase)*0.5f);
    if(obj[0x31]) func_L01_00404808(D_L07_003E3B30,obj);
}
/* localdecomp:end func_L07_003E3820 */

/* localdecomp:start func_L07_003E3AB0 */
typedef struct T_003E3AB0 {
    u8 pad0[0x24];
    f32 f24;
} T_003E3AB0;

typedef struct R_003E3AB0 {
    u8 pad0[0x10];
    f32 f10;
    u8 pad1[0xA];
    u8 b1E;
} R_003E3AB0;

typedef struct S_003E3AB0 {
    u8 pad0[0x24];
    T_003E3AB0 *p24;
    u8 pad1[4];
    f32 f2C;
    u8 pad2[0x38];
    R_003E3AB0 *p68;
    u8 pad3[0x8C];
    f32 fF8;
} S_003E3AB0;

extern void func_L01_004450F0(void *, s32, s32);

void func_L07_003E3AB0(S_003E3AB0 *a) {
    R_003E3AB0 *p;

    p = a->p68;
    if (p->b1E != 0) {
        a->f2C = a->p24->f24 * 0.65f;
    }
    p->f10 = func_0038DAB8(a->fF8, 3.14159274f);
    func_L01_004450F0(a, 1, -1);
}
/* localdecomp:end func_L07_003E3AB0 */

/* localdecomp:start func_L07_003E3B30 */
#include "vu0.h"
extern vu0_v4 D_L07_001E1EC0[];
void func_L07_003E3B30(u8 *obj) {
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_003C2F58(void *, s32, void *);
    extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
    vu0_v4 delta, position;
    f32 intensity;
    vec_sub_ab(&delta, obj + 0x10, &D_L07_001E1EC0[0]);
    func_0038CF68(&delta, &delta, 1.0f);
    intensity = func_0038CE68(&delta, (u8 *)D_L07_001E1EC0 + 0x380);
    if (intensity > 0.0f) {
        func_003C2F58(obj, 0, &position);
        func_003D9508(&position, 0x31, 0x40605050, 1, intensity * 0.6f, 0.08f, 0.0f);
        func_003C2F58(obj, 1, &position);
        func_003D9508(&position, 0x31, 0x40605050, 1, intensity * 0.15f, 0.08f, 0.0f);
        func_003C2F58(obj, 2, &position);
        func_003D9508(&position, 0x31, 0x40605050, 1, intensity * 0.2f, 0.08f, 0.0f);
    }
}
/* localdecomp:end func_L07_003E3B30 */
