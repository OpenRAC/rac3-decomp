/* functional: high. 206 diff = scheduling only. Fully re-read against asm incl. all constants/offsets and every branch (switch 0/1/2/6, fallthrough 0->1, destroy path); drafts' D_001A4BE0/D_L01_002C5600 externs replaced by casts of file-context decls */
#include "common.h"
#include "vu0.h"
typedef struct {
    u8 pad0[0x10]; f32 angle; s32 timer; f32 speed; s32 alpha;
    u8 pad20[4]; s32 range; s32 handle;
} Vars_00392328;
typedef struct {
    V_003919E0 vector;
    u8 pad10[8]; u8 kind; u8 mode; u16 cls;
    u8 pad1C[4]; s32 active; u8 pad24[12];
} Hit_00392328;
typedef struct { u8 pad0[0x6C]; f32 damage; u8 pad70[0x80]; } Gun_00392328;
typedef struct { u8 pad[0x25C0]; u8 *moby; } Hero_00392328;
extern u8 *D_L01_001E2018;
extern S_393258 *D_L01_001E201C;
extern s32 *D_L01_001E2020;
extern f32 D_L01_001DDFF8;
extern f32 D_L01_001DDFFC;
extern u8 D_001425C0[];
extern u8 *D_L01_001EEA80[];
typedef struct { u8 pad[0x20]; f32 strength; s32 pad24; s32 time; s32 mode; } Effect_00392328;
extern Effect_00392328 D_L01_001E2A40;
__asm__(".extern D_L01_001DDFF8, 4");
__asm__(".extern D_L01_001DDFFC, 4");
void func_L01_00392328(u8 *m)
{
    extern s32 func_L01_00457458(s32, s32);
    extern void func_L01_004CAB30(void *, void *);
    extern s32 func_L01_004572B0(void *, s32, s32 *);
    extern u8 *func_L01_00457480(s32, s32);
    extern s32 func_L01_003922E0(s32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_L01_0044BB30(void *, void *, f32, f32, s32);
    extern void func_L01_00393C80(void *, s32, void *, void *, f32);
    extern void func_L01_00392A90(void *, void *);
    extern s32 func_L01_00459590(V_003919E0 *, s32, f32);
    extern s32 func_003D4D00(void *, s32, f32, void *, void *);
    extern void *func_00382348(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern void func_L01_00446978(void *, void *);
    extern void func_L01_0031B090(void *, s32, s32);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_00392A80(void);
    extern void func_003C2880(u8 *);
    extern void func_L01_00393DA8(s32);
    extern void func_L01_00392E28(u8 *);
    extern void func_L01_00404A10(void (*)(u8 *), u8 *);
    V_003919E0 origin, normal, sphere, delta;
    Hit_00392328 hit;
    s32 allocation;
    Vars_00392328 *p = *(Vars_00392328 **)(m + 0x68);
    V_003919E0 *position;
    void *source;
    s32 i, count;
    s32 remaining;
    f32 fade;
    if (m[0x20] && !func_L01_00457458(*(s16 *)(m+0xAA),p->handle)) goto destroy;
    position=(V_003919E0 *)(m+0x10);
    func_L01_004CAB30(position,position);
    source=position;
    switch(m[0x20]) {
    case 0:
        m[0x20]=1;
        p->angle=0.0f;
        p->speed=0.8000000715255737f;
        p->timer=17;
        p->alpha=127;
        p->range=111;
        p->handle=func_L01_004572B0(m,0,&allocation);
        D_L01_001E2018=func_L01_00457480(*(s16 *)(m+0xAA),p->handle);
        D_L01_001E201C=(S_393258 *)func_L01_003922E0((s32)D_L01_001E2018+0x50);
        D_L01_001E2020=(s32 *)func_L01_003922E0((s32)D_L01_001E201C+0x9600);
        for(i=0;i<144;i++) D_L01_001E2020[i]=0;
        for(i=299;i>=0;i--) D_L01_001E201C[i].w7C=0;
        *(s32 *)(D_L01_001E2018+0x30)=0;
        origin.q=*(s128 *)(m+0x10);
        func_003C5180(source,&normal,1);
        __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
            : "=m"(origin) : "m"(normal), "m"(*(vu0_v4 *)(m+0x10)) : "vf1", "vf2");
        func_L01_0044BB30(m,&origin,2.0f,20.0f,-1);
        func_L01_00393C80(m,17,source,p,0.20000001788139343f);
        func_L01_00392A90(m,source);
        position=&sphere;
        sphere.q=origin.q;
        sphere.f[3]=2.0f;
        if(func_L01_00459590((V_003919E0 *)position,0,100.0f)!=-1) {
            D_L01_001E2A40.strength=0.45f;
            D_L01_001E2A40.time=33;
            D_L01_001E2A40.mode=0;
        }
    case 1:
        p->range-=5;
        if(p->range<0) p->range=0;
        p->angle+=p->speed;
        count=func_003D4D00(source,0,(1.0f-(f32)p->timer/17.0f)*8.0f+0.001f,m,0);
        if(count>0) {
        source=D_L01_001EEA80;
        remaining=count;
        do {
            if(func_00382348(*(u8 **)source)==0 && !(*(u16 *)((*(u8 **)source)+0x34)&0x4000)) goto next;
            if(*(u8 **)source==((Hero_00392328 *)D_001A4BE0)->moby) goto next;
            if(*(s16 *)((*(u8 **)source)+0xAA)==0xA5A) goto next;
            __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0"
                : "=m"(delta) : "m"(*(vu0_v4 *)(m+0x10)), "m"(*(vu0_v4 *)((*(u8 **)source)+0x10)) : "vf1", "vf2");
            func_0038CF68(&delta,&delta,1.0f);
            func_0038CF68(&hit,&hit,2.0f);
            func_L01_00446760(&hit,m,0x1030000,&delta,((Gun_00392328 *)((s32)D_L01_002C5600 + D_001425C0[0x57]*240))->damage);
            hit.vector.q=delta.q;
            hit.active=1;
            hit.mode=3;
            hit.vector.f[3]=5627.9248046875f;
            hit.kind=5;
            hit.cls=*(u16 *)((*(u8 **)source)+0xAA);
            func_L01_00446978(*(u8 **)source,&hit);
            func_L01_0031B090(*(u8 **)source,0x57,*(s32 *)(m+0xB8));
next:
            remaining--; source=(u8 *)source+4;
        } while(remaining);
        }
        if(func_0038CAD0(&p->timer)) {m[0x20]=2;p->timer=33;}
        break;
    case 2:
        p->angle+=p->speed;
        fade=(f32)p->timer/40.0f;
        if(p->timer==20) func_L01_00392A90(m,source);
        if(func_0038CAD0(&p->timer)) {
            if(p->alpha) p->alpha--;
            else {p->alpha=0;m[0x20]=6;}
        } else p->alpha=(s32)(fade*127.0f);
        break;
    case 6:
        p->speed-=0.020000001415610313f;
        if(p->speed<0.10000000894069672f) p->speed=0.10000000894069672f;
        p->angle+=p->speed;
        if(!*(s32 *)(D_L01_001E2018+0x38)) {
destroy:
            func_L01_00392A80();
            func_003C2880(m);
            return;
        }
        break;
    }
    D_L01_001DDFFC-=0.04f;
    if(D_L01_001DDFF8< -8.0f) D_L01_001DDFF8+=8.0f;
    if(D_L01_001DDFFC< -8.0f) D_L01_001DDFFC+=8.0f;
    func_L01_00393DA8((s32)m);
    func_L01_00404A10(func_L01_00392E28,m);
}
