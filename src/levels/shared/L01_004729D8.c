#include "common.h"

typedef struct {
    s32 n;
    s32 done;
    s32 pad[2];
} Tab_00477BC0;

INCLUDE_ASM("asm/levels", func_L01_004729D8);

INCLUDE_ASM("asm/levels", func_L01_00472C98);

INCLUDE_ASM("asm/levels", func_L01_00472F58);

INCLUDE_ASM("asm/levels", func_L01_004730F8);

/* localdecomp:start func_L01_00473268 */
#include "vu0.h"
typedef int Q_00473268 __attribute__((mode(TI)));
typedef union { Q_00473268 q; f32 f[4]; } V_00473268;
extern u8 *D_L01_00221250[];
u8 *func_L01_00473268(u8 *obj, u8 *pos, s32 render, s32 minlife, s32 maxlife, f32 scale)
{
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_L01_004C7D98(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    V_00473268 v;
    u8 *p=(u8 *)func_L01_004618E0(110);
    u8 *s;
    s32 n, c;
    if (p != 0) {
        p[3]=render;
        p[1]=0;
        p[9]=68;
        s=p+32;
        p[8]=func_00382468(255);
        p[2]=*D_L01_00221250[0];
        *(s16 *)(p+10)=(func_00382498(minlife,maxlife)*5+2)/6;
        *(s32 *)(s+24)=*(s16 *)(p+10);
        *(f32 *)(p+12)=scale*3.0f*210000.0f;
        if (*(f32 *)(pos+12)==-1.0f) {
            qzero(&v);
            v.f[3]=1.0f;
            v.f[0]=-0.3f;
            func_0038D000(&v,&v,obj+192);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*(V_00473268 *)(p+16)) : "m"(v), "m"(*(V_00473268 *)(obj+16)) : "vf1", "vf2");
        } else {
            *(Q_00473268 *)(p+16)=*(Q_00473268 *)pos;
        }
        *(f32 *)(p+16)+=func_003824E0(-0.015f,0.015f);
        *(f32 *)(p+20)+=func_003824E0(-0.015f,0.015f);
        *(f32 *)(p+24)+=func_003824E0(-0.015f,0.015f);
        func_L01_004C7D98(obj+16,&v);
        func_0038CE20(s,&v,func_003824E0(0.01f,0.015f));
        *(s32 *)(s+16)=func_00382498(80,200);
        c=func_00382498(96,128);
        n=c+(c<<8)+(c<<16);
        *(s32 *)(s+20)=n;
        *(s32 *)(p+4)=n|(*(s32 *)(s+16)<<24);
    }
    return p;
}
/* localdecomp:end func_L01_00473268 */

/* localdecomp:start func_L01_004734A8 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_004734A8;
void func_L01_004734A8(u8 *arg0)
{
    extern s32 func_0038DBD8(s32, s32, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_L01_004CAC40(void *, void *);
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    u8 *p = arg0 + 0x20;
    u8 *pos = arg0 + 0x10;
    f32 t = (f32)*(s16 *)(arg0 + 0xA) / (f32)*(s32 *)(p + 0x18);
    s32 alpha = (s32)((f32)*(s32 *)(p + 0x10) * t);
    s32 color = func_0038DBD8(0, *(s32 *)(p + 0x14), t * 0.5f);
    arg0[8]++;
    *(f32 *)(arg0 + 0xC) += func_003824E0(0.004f, 0.012f) * 210000.0f;
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "+m"(*(V_004734A8 *)(arg0 + 0x10)) : "m"(*(V_004734A8 *)(arg0 + 0x20)) : "vf1", "vf2");
    func_0038CE20(p, p, 0.99f);
    func_L01_004CAB30(pos, pos);
    func_L01_004CAC40(p, p);
    *(s32 *)(arg0 + 4) = color | (alpha << 24);
    if (func_0038CB00(arg0 + 0xA))
        func_003CD250(arg0);
}
/* localdecomp:end func_L01_004734A8 */

/* localdecomp:start func_L01_004735F0 */
typedef int Quad_4735F0 __attribute__((mode(TI)));
typedef struct {
    u8 type;                       /* 0x00 */
    s8 flags;                      /* 0x01 */
    u8 texture;                    /* 0x02 */
    u8 render;                     /* 0x03 */
    u32 rgba;                      /* 0x04: R in the low byte */
    u8 spin;                       /* 0x08 */
    u8 render2;                    /* 0x09 */
    s16 life;                      /* 0x0A: frames */
    u32 end_rgba;                  /* 0x0C */
    Quad_4735F0 head;              /* 0x10: w is the half width */
    u8 pad_20[0xC];
    f32 drag;                      /* 0x2C: velocity kept a frame, 1.0 for none */
    Quad_4735F0 tail;              /* 0x30: w is the scale */
} Ray_4735F0;

extern u8 *D_L01_00221254[];
/* func_L01_004618E0, under an alias: a later block declares it with its own particle type */
extern Ray_4735F0 *func_L01_004618E0_004735F0(s32 type);

/* particle_spawn_ray: a type 0x6F particle, a ray from head to tail for life frames: white at
 * 0x64 at scale 1, else blue (0x20, 0x20, 0xFF), added, half width scale x 0.013. */
Ray_4735F0 *func_L01_004735F0(Quad_4735F0 *head, Quad_4735F0 *tail, s32 life, f32 scale) {
    Ray_4735F0 *ray = func_L01_004618E0_004735F0(0x6F);

    if (ray != 0) {
        if (scale != 1.0f) ray->rgba = 0x64FF2020;
        else ray->rgba = 0x64FFFFFF;
        ray->end_rgba = ray->rgba;
        ray->render2 = 0x22;
        ray->render = 0x48;
        ray->flags = 3;
        ray->texture = *D_L01_00221254[0];
        ray->tail = *tail;
        ((f32 *)&ray->tail)[3] = scale;
        ray->head = *head;
        ray->life = life;
        ((f32 *)&ray->head)[3] = scale * 0.013f;
        ray->drag = 1.0f;
        ray->spin = (u8)ray->life - 12;
    }
    return ray;
}
/* localdecomp:end func_L01_004735F0 */

INCLUDE_ASM("asm/levels", func_L01_004736F0);

LINKER_REMNANT("asm/levels", func_L01_00473858);

INCLUDE_ASM("asm/levels", func_L01_00473860);

/* localdecomp:start func_L01_004739D0 */
void func_L01_004739D0(void) {

}
/* localdecomp:end func_L01_004739D0 */

/* localdecomp:start func_L01_004739D8 */
typedef int s128_00470258 __attribute__((mode(TI)));
typedef struct {
    s128_00470258 v;
    s32 f10;
    s32 f14;
    s16 f18;
    u8 f1A;
} Sub_00470258;
typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    s32 f4;
    u8 f8;
    u8 f9;
    s16 fA;
    f32 fC;
    s128_00470258 f10;
    Sub_00470258 sub;
} Part_00470258;
extern u8 *D_L01_002210FC[];
extern Part_00470258 *func_L01_004618E0(s32);
extern u8 func_00382498(s32, s32);
void func_L01_004739D8(s128_00470258 *pos, s128_00470258 *v2, s32 a2, s32 a3, s16 t0, u8 t1, f32 f) {
    Part_00470258 *p;
    Sub_00470258 *q;
    p = func_L01_004618E0(114);
    if (p != 0) {
        p->f10 = *pos;
        p->f9 = 68;
        p->f3 = 72;
        p->fC = f;
        p->f1 = 0;
        p->f8 = 0;
        p->f2 = *D_L01_002210FC[0];
        q = &p->sub;
        p->fA = t0;
        q->f18 = t0;
        p->f4 = a2;
        q->f10 = a2;
        q->f14 = a3;
        q->f1A = t1;
        p->f8 = func_00382498(0, 255);
        q->v = *v2;
    }
}
/* localdecomp:end func_L01_004739D8 */

INCLUDE_ASM("asm/levels", func_L01_00473AC8);

INCLUDE_ASM("asm/levels", func_L01_00474068);

/* localdecomp:start func_L01_00474078 */
typedef int Q_00474078 __attribute__((mode(TI)));
extern u8 *D_L01_00221268[];
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00474078;
typedef struct { u8 f0,f1,f2,f3; s32 f4; u8 f8,f9; s16 fA; s32 fC; Q_00474078 f10; V_00474078 f20; f32 f30,f34,f38; s16 f3C; } P_00474078;
P_00474078 *func_L01_00474078(u8 *pos, u8 *dir, f32 width, s32 life, s32 color, s32 end, s32 spin, s32 texture, f32 scale, f32 drag, f32 tail)
{
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    V_00474078 v;
    P_00474078 *p = (P_00474078 *)func_L01_004618E0(116);
    f32 *s;
    if (p != 0) {
        p->f4=color;
        p->fC=end;
        p->f9=34;
        p->f3=72;
        p->f1=3;
        p->f2=D_L01_00221268[0][texture];
        s=&p->f30;
        p->f30=func_0038CEA8(dir);
        p->f10=*(Q_00474078 *)pos;
        func_0038CF68(&v,dir,drag);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(p->f20) : "m"(*(V_00474078 *)pos), "m"(v) : "vf1", "vf2");
        p->fA=life;
        p->f20.w=scale;
        p->f8=spin;
        ((f32 *)&p->f10)[3]=width;
        s[1]=width;
        s[2]=tail;
        *(s16 *)&s[3]=p->fA;
    }
    return p;
}
/* localdecomp:end func_L01_00474078 */

INCLUDE_ASM("asm/levels", func_L01_004741B8);

LINKER_REMNANT("asm/levels", func_L01_00474320);

/* localdecomp:start func_L01_00474328 */
typedef struct Ops_45E458 Ops_45E458;
typedef struct {
    s32 pad;
    Ops_45E458 *ops;
} Sub_45E458;
struct Ops_45E458 {
    s32 pad[5];
    void (*fn)(u8 *a0, Sub_45E458 *s);
};

extern s32 func_0038CB00(void *p);
extern void func_003CD250(u8 *a0);

void func_L01_00474328(u8 *a0)
{
    Sub_45E458 *s = (Sub_45E458 *)(a0 + 32);

    if (s != 0) {
        if (func_0038CB00(a0 + 10)) {
            func_003CD250(a0);
        } else if (s->ops != 0) {
            s->ops->fn(a0, s);
        }
    }
}
/* localdecomp:end func_L01_00474328 */

/* localdecomp:start func_L01_00474390 */
typedef int Q_00474390 __attribute__((mode(TI)));
extern u8 *D_L01_00221270[];
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00474390;
typedef struct { u8 f0,f1,f2,f3; s32 f4; u8 f8,f9; s16 fA; s32 fC; Q_00474390 f10; V_00474390 f20; f32 f30,f34,f38; s16 f3C; } P_00474390;
P_00474390 *func_L01_00474390(u8 *pos, u8 *dir, f32 width, s32 life, s32 color, s32 end, s32 spin, s32 texture, f32 scale, f32 drag, f32 tail)
{
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    V_00474390 v;
    P_00474390 *p = (P_00474390 *)func_L01_004618E0(118);
    f32 *s;
    if (p != 0) {
        p->f4=color;
        p->fC=end;
        p->f9=34;
        p->f3=72;
        p->f1=3;
        p->f2=D_L01_00221270[0][texture];
        s=&p->f30;
        p->f30=func_0038CEA8(dir);
        p->f10=*(Q_00474390 *)pos;
        func_0038CF68(&v,dir,drag);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(p->f20) : "m"(*(V_00474390 *)pos), "m"(v) : "vf1", "vf2");
        p->fA=life;
        p->f20.w=scale;
        p->f8=spin;
        ((f32 *)&p->f10)[3]=width;
        s[1]=width;
        s[2]=tail;
        *(s16 *)&s[3]=p->fA;
    }
    return p;
}
/* localdecomp:end func_L01_00474390 */

INCLUDE_ASM("asm/levels", func_L01_004744D0);

INCLUDE_ASM("asm/levels", func_L01_00474680);

INCLUDE_ASM("asm/levels", func_L01_004747C0);

/* localdecomp:start func_L01_00474968 */
extern s32 func_0038CB00(void *p);
extern void func_003CD250(u8 *a0);
void func_L01_00474968(u8 *a0) {
    u8 *s1 = a0 + 48;
    if (s1 != 0) {
        if (((s32 (*)(u8 *a0))func_0038CB00)(a0 + 10) != 0) {
            func_003CD250(a0);
        } else {
            (*(void (**)(u8 *, u8 *))(*(u8 **)(s1 + 4) + 20))(a0, s1);
        }
    }
}
/* localdecomp:end func_L01_00474968 */

/* localdecomp:start func_L01_004749C8 */
typedef int Q_004749C8 __attribute__((mode(TI)));
extern u8 *D_L01_0022127C[];
u8 *func_L01_004749C8(Q_004749C8 *pos, Q_004749C8 *vel, s32 life)
{
    extern Part_00470258 *func_L01_004618E0(s32);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    extern u8 func_00382498(s32, s32);
    extern f32 func_00382538(void);
    u8 *p = (u8 *)func_L01_004618E0(121);
    u8 *s;
    if (p != 0) {
        p[9] = 66;
        p[3] = func_00382468(4) ? 72 : 68;
        p[1] = 0;
        s = p + 32;
        p[2] = *D_L01_0022127C[0];
        *(f32 *)(p + 12) = func_003824E0(0.05f, 0.15f) * 210000.0f;
        p[8] = func_00382468(255);
        *(s16 *)(p + 10) = (life * 5 + 2) / 6;
        *(Q_004749C8 *)(p + 16) = *pos;
        *(Q_004749C8 *)s = *vel;
        *(f32 *)(s + 12) = func_003824E0(0.6f, 2.6f) * 0.00040000002f;
        *(f32 *)(s + 24) = *(f32 *)(p + 12) * 2.0f;
        *(s16 *)(s + 22) = func_00382498(0, 3);
        *(s16 *)(s + 20) = ((life / 2) * 5 + 2) / 6;
        *(f32 *)(s + 28) = func_00382538();
    }
    return p;
}
/* localdecomp:end func_L01_004749C8 */

INCLUDE_ASM("asm/levels", func_L01_00474B48);

LINKER_REMNANT("asm/levels", func_L01_00474DD8);

/* localdecomp:start func_L01_00474DE0 */
#include "vu0.h"
void func_L01_00474DE0(u8 *particle) {
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    extern void func_003C2EC0(void *,s32,void *);
    extern void func_003C2F58(void *,s32,void *);
    extern void func_0038CF68(void *,void *,f32);
    vu0_v4 matrix[4],delta;
    u8 *p=particle+0x20;
    u8 *m;
    f32 t,start;
    s32 life,fade;
    if(func_0038CB00(particle+0xA) || !(m=*(u8 **)p) || m[0x20]==254 || m[0x20]==253) {
        func_003CD250(particle);
        return;
    }
    if(*(f32 *)(p+0x10)!=0.0f) {
        func_003C2EC0(m,p[0x14],matrix);
        func_0038CF68(&delta,&matrix[p[0x17]],*(f32 *)(p+0x10));
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*(vu0_v4 *)(particle+0x10)) : "m"(matrix[3]), "m"(delta) : "vf1", "vf2");
    } else {
        func_003C2F58(m,p[0x14],particle+0x10);
    }
    life=*(s16 *)(particle+0xA);
    t=(f32)life/(f32)*(s16 *)(p+0xE);
    start=*(f32 *)(p+8);
    *(f32 *)(particle+0xC)=start+(*(f32 *)(p+4)-start)*t;
    fade=*(s16 *)(p+0xC);
    if(life<fade) {
        *(u32 *)(particle+4)=(*(u32 *)(particle+4)&0xFFFFFF)|((s32)((f32)p[0x16]*(f32)life/(f32)fade)<<24);
    }
}
/* localdecomp:end func_L01_00474DE0 */

INCLUDE_ASM("asm/levels", func_L01_00474F38);

INCLUDE_ASM("asm/levels", func_L01_00475128);

/* localdecomp:start func_L01_00475278 */
typedef int Q_00475278 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00475278;
extern u8 D_L01_001D7FC0_00475278;
extern s32 D_L01_001D7FBC_00475278;
extern s32 D_L01_001D7FB4_00475278;
extern s32 D_L01_001D7FB8_00475278;
extern f32 D_L01_001D7FAC_00475278;
extern f32 D_L01_001D7FB0_00475278;
extern f32 D_L01_001D7FA8_00475278;
#include "structs/hero.h"
extern struct Hero D_001A4BE0;

extern u8 *D_L01_001EEA80[];
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D7FB4_00475278, 4");
__asm__(".extern D_L01_001D7FB8_00475278, 4");
__asm__(".extern D_L01_001D7FAC_00475278, 4");
__asm__(".extern D_L01_001D7FB0_00475278, 4");
__asm__(".extern D_L01_001D7FA8_00475278, 4");
void func_L01_00475278(u8 *p) {
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    extern s32 func_00382468(s32);
    extern u8 func_00382498(s32,s32);
    extern f32 func_003824E0(f32,f32);
    extern f32 func_0038D160(f32,f32);
    extern f32 func_0038DAB8(f32,f32);
    extern f32 func_0038CED8(void *);
    extern void func_003C4C18(void *,f32);
    extern void func_00382760(void *,f32,f32,f32);
    extern u8 *func_L01_00475128(s32,void *,void *,s32,f32,s32,s32,s32,s32,f32,f32);
    extern s32 func_003D4D00(void *,s32,s32,s32,f32);
    extern void func_L01_00446A70(void *,s32,s32,void *,void *,f32);
    extern void func_L01_00456230(s32,s32);
    u8 *s;
    f32 t, scale, old, limit, speed, angle, a, b, range;
    u32 alpha;
    s32 n;
    u8 **objects, *created;
    V_00475278 pos, vel;
    if (func_0038CB00(p+10)) {func_003CD250(p);return;}
    s=p+32;
    p[8]+=D_L01_001D7FC0_00475278;
    old=*(f32 *)(p+28);
    t=(f32)*(s16 *)(p+10)*old;
    alpha=(u8)(s32)((f32)s[28]*t);
    *(s32 *)(p+4)=(*(s32 *)(p+4)&0xFFFFFF)|(alpha<<24);
    *(f32 *)(p+12)=*(f32 *)(s+24)+(*(f32 *)(s+20)-*(f32 *)(s+24))*t;
    scale=*(f32 *)(p+12)/500000.0f;
    if (0.0f < *(f32 *)(s+12) && *(f32 *)(s+8)<0.0f) {
        f32 delta;
        limit=*(f32 *)(s+12)+scale;
        delta=limit-*(f32 *)(p+24);
        if (*(f32 *)(s+8)*5.0f<delta)
            *(f32 *)(s+8)=delta/5.0f;
        __asm__("lqc2 $vf1, %0
	lqc2 $vf2, %1
	vadd.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
           : "+m"(*(V_00475278 *)(p+16)) : "m"(*(V_00475278 *)(p+32)) : "vf1","vf2");
        if (*(f32 *)(p+24)<limit) *(f32 *)(p+24)=limit;
    } else {
        __asm__("lqc2 $vf1, %0
	lqc2 $vf2, %1
	vadd.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
           : "+m"(*(V_00475278 *)(p+16)) : "m"(*(V_00475278 *)s) : "vf1","vf2");
    }
    if (s[30] && !func_00382468(s[30])) {
        if (!func_00382468(D_L01_001D7FBC_00475278)) {
            *(Q_00475278 *)&pos=0;
            pos.z=scale*0.20000002f;
            created=func_L01_00475128(*(s32 *)(s+16),p+16,&pos,((s32)(t*64.0f)<<24)|0x202020,0.0f,33,0,0,1,*(f32 *)(p+12),*(f32 *)(p+12)*0.8f);
            if(created) created[3]=68;
        } else {
            V_00475278 *vp;
            *(Q_00475278 *)&pos=*(Q_00475278 *)(p+16);
            func_003C4C18(&pos,scale);
            vp=&vel;
            speed=D_L01_001D7FAC_00475278*1.2f*scale;
            angle=func_0038D160(*(f32 *)s,*(f32 *)(s+4));
            a=func_0038DAB8(angle,func_003824E0(-(D_L01_001D7FB0_00475278*0.017453292f),D_L01_001D7FB0_00475278*0.017453292f));
            b=func_0038DAB8(func_0038D160(func_0038CED8(s),*(f32 *)(s+8)),func_003824E0(0.0f,D_L01_001D7FB0_00475278*0.017453292f));
            func_00382760(vp,speed,a,b);
            created=func_L01_00475128(*(s32 *)(s+16),&pos,vp,*(s32 *)(p+4),0.0f,func_00382498((D_L01_001D7FB4_00475278*5+2)/6,(D_L01_001D7FB8_00475278*5+2)/6),0,0,0,*(f32 *)(p+12),*(f32 *)(p+12)*D_L01_001D7FA8_00475278);
            if(created) created[2]=p[2];
        }
    }
    if(s[29] && alpha>=15) {
        n=func_003D4D00(p+16,1,*(s32 *)(s+16),0,scale);
        if(n>0) {
            objects=D_L01_001EEA80;
            { s32 count=n;
            do {
                if(*objects==(u8 *)D_001A4BE0.hero_moby) {
                    func_L01_00446A70(*objects,*(s32 *)(s+16),1,*objects+16,D_L01_001D66B0,(f32)s[29]);
                    func_L01_00456230(*(s32 *)(s+16),1);
                }
                --count; ++objects;
            }while(count); }
        }
    }
    *(f32 *)(p+28)=old;
}
/* localdecomp:end func_L01_00475278 */

/* localdecomp:start func_L01_004756D0 */
extern s32 func_0038CB00(void *p);
extern void func_003CD250(u8 *);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 D_L01_001D7FC4;

void func_L01_004756D0(u8 *a0) {
    if (((s32 (*)(u8 *))func_0038CB00)(a0 + 10) != 0 || *(f32 *)(a0 + 12) < D_L01_001D7FC4 * 210000.0f) {
        func_003CD250(a0);
    } else {
        u8 *p = a0 + 32;
        *(s32 *)(a0 + 4) = func_0038DBD8(*(s32 *)(p + 8), *(s32 *)(p + 4),
                                         (f32)*(s16 *)(a0 + 10) * *(f32 *)(p + 12));
        *(f32 *)(a0 + 12) = *(f32 *)(a0 + 12) + *(f32 *)(a0 + 32);
    }
}
/* localdecomp:end func_L01_004756D0 */

/* localdecomp:start func_L01_00475770 */
typedef int Q_00475770 __attribute__((mode(TI)));
extern u8 *D_L01_00221230[];
extern u8 *D_L01_002210F4[];
extern u8 *D_L01_0022121C[];
u8 *func_L01_00475770(Q_00475770 *pos, Q_00475770 *vel, s32 unused, u8 alpha, f32 size, f32 endsize) {
    extern Part_00470258 *func_L01_004618E0(s32);
    extern u8 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    u8 *p = (u8 *)func_L01_004618E0(126);
    u8 *s;
    s32 n;
    if (p != 0) {
        p[1] = 0;
        p[9] = 0x42;
        p[3] = 0x44;
        s = p + 0x20;
        n = func_00382498(0,2);
        if (n == 0) p[2] = *D_L01_00221230[0];
        else if (n == 1) p[2] = *D_L01_002210F4[0];
        else if (n == 2) p[2] = D_L01_0022121C[0][10];
        *(f32 *)(p + 0xC) = size * 210000.0f;
        p[8] = func_00382468(255);
        *(s16 *)(p + 0xA) = (func_00382498(100,120)*5+2)/6;
        s[0x1C] = 0;
        *(f32 *)(s + 0x10) = 1.0f / *(s16 *)(p + 0xA);
        *(f32 *)(s + 0x14) = endsize;
        s[0x1D] = alpha;
        *(Q_00475770 *)(p + 0x10) = *pos;
        *(Q_00475770 *)s = *vel;
        *(f32 *)(s + 0xC) = func_003824E0(1.6f,6.0f) * 0.0004000000189989805f;
    }
    return p;
}
/* localdecomp:end func_L01_00475770 */

/* localdecomp:start func_L01_00475910 */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
typedef struct { u8 pad[0x140]; f32 x, y; } View_00475910;
extern u8 D_L01_001E2880[];
extern u8 *D_L01_002210F4[];
void func_L01_00475910(u8 *p) {
    extern void func_L01_004CAB30(void *, void *);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern u8 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    f32 pos[4], vel[4];
    f32 *velocity;
    u8 *s = p + 0x20;
    u8 *created;
    f32 angle, random;
    s32 life, spin;
    func_L01_004CAB30(p + 0x10, p + 0x10);
    if (s[0x1C] == 0) {
        *(s32 *)(p + 4) = func_0038DBD8(0x7F232323, 0x7F373737, (f32)*(s16 *)(p + 0xA) * *(f32 *)(s + 0x10));
    } else if (s[0x1C] == 1) {
        if (*(f32 *)(p + 0x18) > *(f32 *)(s + 0x14)) {
            __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "+m"(*(vu0_v4 *)(p + 0x10)) : "m"(*(vu0_v4 *)(p + 0x20)) : "vf1", "vf2");
            *(f32 *)(s + 8) -= *(f32 *)(s + 0xC);
        } else if (s[0x1D]) {
            angle = func_0038D160(D_001A4BE0.pos.x - ((View_00475910 *)D_L01_001E2880)->x, D_001A4BE0.pos.y - ((View_00475910 *)D_L01_001E2880)->y);
            func_L01_00443A18(1.0f, 2.0f);
            pos[0] = *(f32 *)(p + 0x10) + func_L01_00443A18(0.0f, 0.15f);
            pos[1] = *(f32 *)(p + 0x14) + func_L01_00443A18(0.0f, 0.15f);
            pos[2] = *(f32 *)(p + 0x18) + 0.1f;
            random = func_0038DAB8(angle, func_L01_00443A18(0.0f, -6.2831855f));
            vel[0] = func_0038D098(random) * 0.040000003f;
            vel[1] = func_0038D0B0(random) * 0.040000003f;
            velocity = vel;
            vel[2] = 0.0f;
            life = (func_00382498(10, 30) * 5 + 2) / 6;
            spin = func_00382498(-2, -4);
            created = func_L01_004713C8(pos, velocity, life, 0x202020, spin, 127, 0, 0, 189000.0f, 84000.0f, 0.0f);
            if (created) {
                created[2] = D_L01_002210F4[0][0];
                created[3] = func_00382468(6) ? 72 : 68;
            }
            s[0x1D] = 0;
        }
    } else if (s[0x1C] == 2) {
        *(s32 *)(p + 4) = func_0038DBD8(0x00232323, 0x7F232323, (f32)*(s16 *)(p + 0xA) * *(f32 *)(s + 0x10));
    }
    if (func_0038CB00(p + 0xA) && s[0x1C] == 0) {
        s[0x1C] = 1;
        *(s16 *)(p + 0xA) = 250;
    } else if (func_0038CB00(p + 0xA) && s[0x1C] == 1) {
        s[0x1C] = 2;
        *(s16 *)(p + 0xA) = 125;
        *(f32 *)(s + 0x10) = 0.008f;
    } else if (func_0038CB00(p + 0xA) && s[0x1C] == 2) {
        func_003CD250(p);
    }
}
/* localdecomp:end func_L01_00475910 */

INCLUDE_ASM("asm/levels", func_L01_00475C60);

INCLUDE_ASM("asm/levels", func_L01_00475DC8);

/* localdecomp:start func_L01_00475F28 */
typedef int Q_00475F28 __attribute__((mode(TI)));
extern u8 *D_L01_00221298[];
u8 *func_L01_00475F28(Q_00475F28 *pos, Q_00475F28 *vel, s32 unused, u8 flag, f32 scale, f32 value) {
    extern Part_00470258 *func_L01_004618E0(s32);
    extern u8 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    u8 *p = (u8 *)func_L01_004618E0(128);
    u8 *s;
    s32 choice;
    if (p != 0) {
        p[3]=72;
        p[1]=0;
        p[9]=66;
        s=p+32;
        choice=func_00382498(0,3);
        if (choice==0) p[2]=D_L01_00221298[0][0];
        else if (choice==1) p[2]=D_L01_00221298[0][1];
        else if (choice>=2) p[2]=D_L01_00221298[0][2];
        *(f32 *)(p+12)=scale*210000.0f;
        p[8]=func_00382468(255);
        *(s16 *)(p+10)=(func_00382498(100,120)*5+2)/6;
        s[28]=0;
        *(f32 *)(s+16)=1.0f / *(s16 *)(p+10);
        *(f32 *)(s+20)=value;
        s[29]=flag;
        *(Q_00475F28 *)(p+16)=*pos;
        *(Q_00475F28 *)s=*vel;
        *(f32 *)(s+12)=func_003824E0(1.6f,6.0f)*0.0004000000189989805f;
    }
    return p;
}
/* localdecomp:end func_L01_00475F28 */

/* localdecomp:start func_L01_004760C8 */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
typedef struct { u8 pad[0x140]; f32 x, y; } Target_004760C8;
extern u8 D_L01_001E2880[];
extern u8 *D_L01_002210F4[];
void func_L01_004760C8(u8 *particle)
{
    extern void func_L01_004CAB30(void *, void *);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern u8 func_00382498(s32, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    vu0_v4 pos, velocity;
    vu0_v4 *vp;
    u8 *state = particle + 0x20;
    f32 angle, heading;
    s32 life, spin;
    u8 *created;
    func_L01_004CAB30(particle + 0x10, particle + 0x10);
    if (state[0x1C] == 0) {
        *(s32 *)(particle + 4) = func_0038DBD8(0x4FBF2323, 0x4F202020, (f32)*(s16 *)(particle + 10) * *(f32 *)(state + 0x10));
    } else if (state[0x1C] == 1) {
        if (*(f32 *)(particle + 0x18) > *(f32 *)(state + 0x14)) {
            __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "+m"(*(vu0_v4 *)(particle + 0x10)) : "m"(*(vu0_v4 *)(particle + 0x20)) : "vf1", "vf2");
            *(f32 *)(state + 8) -= *(f32 *)(state + 12);
        } else if (state[0x1D]) {
            heading = func_0038D160(D_001A4BE0.pos.x - ((Target_004760C8 *)D_L01_001E2880)->x, D_001A4BE0.pos.y - ((Target_004760C8 *)D_L01_001E2880)->y);
            func_L01_00443A18(1.0f, 2.0f);
            pos.x = *(f32 *)(particle + 0x10) + func_L01_00443A18(0.0f, 0.15f);
            pos.y = *(f32 *)(particle + 0x14) + func_L01_00443A18(0.0f, 0.15f);
            pos.z = *(f32 *)(particle + 0x18) + 0.1f;
            angle = func_0038DAB8(heading, func_L01_00443A18(0.0f, -6.2831855f));
            velocity.x = func_0038D098(angle) * 0.040000003f;
            velocity.y = func_0038D0B0(angle) * 0.040000003f;
            vp = &velocity;
            velocity.z = 0.0f;
            life = (func_00382498(10, 30) * 5 + 2) / 6;
            spin = func_00382498(-2, -4);
            created = func_L01_004713C8(&pos, vp, life, 0x303030, spin, 127, 0, 0, 189000.0f, 84000.0f, 0.0f);
            if (created) {
                u8 texture = D_L01_002210F4[0][0];
                created[3] = 0x48;
                created[2] = texture;
            }
            state[0x1D] = 0;
        }
    } else if (state[0x1C] == 2) {
        *(s32 *)(particle + 4) = func_0038DBD8(0x232323, 0x7F232323, (f32)*(s16 *)(particle + 10) * *(f32 *)(state + 0x10));
    }
    if (func_0038CB00(particle + 10) && state[0x1C] == 0) {
        state[0x1C] = 1;
        *(s16 *)(particle + 10) = 250;
    } else if (func_0038CB00(particle + 10) && state[0x1C] == 1) {
        state[0x1C] = 2;
        *(s16 *)(particle + 10) = 125;
        *(f32 *)(state + 0x10) = 0.008f;
    } else if (func_0038CB00(particle + 10) && state[0x1C] == 2) {
        func_003CD250(particle);
    }
}
/* localdecomp:end func_L01_004760C8 */

LINKER_REMNANT("asm/levels", func_L01_00476408);

/* localdecomp:start func_L01_00476440 */
s32 func_L01_00476440(const s32 *count, s32 index, s32 delta, s32 wrap) {
    if (wrap != 0) {
        index = (index + delta + *count) % *count;
    } else {
        index += delta;
        if (delta < 0) {
            if (index < 0) index = 0;
        } else if (index > *count - 1) {
            index = *count - 1;
        }
    }
    return index;
}
/* localdecomp:end func_L01_00476440 */

INCLUDE_ASM("asm/levels", func_L01_00476498);

/* localdecomp:start func_L01_004766E0 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern void func_0038CF38(Vec4 *a0, Vec4 *a1);
extern void func_0038CF00(Vec4 *a0, Vec4 *a1);

void func_L01_004766E0(Vec4 *a0, Vec4 *a1, f32 r) {
    Vec4 a;
    Vec4 b;
    Vec4 *pa = &a;
    Vec4 *pb = &b;
    a.q = a0->q;
    b.q = a1->q;
    if (0.0f < r && __builtin_fabsf(pa->f[2] - pb->f[2]) < r) {
        func_0038CF38(pa, pb);
    } else {
        func_0038CF00(pa, pb);
    }
}
/* localdecomp:end func_L01_004766E0 */

INCLUDE_ASM("asm/levels", func_L01_00476750);

INCLUDE_ASM("asm/levels", func_L01_00476920);

INCLUDE_ASM("asm/levels", func_L01_00476B98);

INCLUDE_ASM("asm/levels", func_L01_00476F10);

INCLUDE_ASM("asm/levels", func_L01_00477190);

INCLUDE_ASM("asm/levels", func_L01_00477488);

INCLUDE_ASM("asm/levels", func_L01_00477668);

INCLUDE_ASM("asm/levels", func_L01_00477890);

LINKER_REMNANT("asm/levels", func_L01_00477990);

INCLUDE_ASM("asm/levels", func_L01_00477998);

/* localdecomp:start func_L01_00477BC0 */
extern int D_L01_0021F6C0[];


void func_L01_00477BC0(s32 a0, s32 a1) {
    Tab_00477BC0 *p;
    s32 next;
    s32 off;
    s32 i;

    if (a0 != -1) {
        p = (Tab_00477BC0 *)D_L01_0021F6C0[a0];
        if (p->done == 0 || a1 != 0) {
            for (i = 0; i < p->n - 1; i = next) {
                next = i + 1;
                off = i * 16;
                *(f32 *)((u8 *)p + off + 0x1C) = ((f32 (*)(void *, void *))func_0038CF00)((u8 *)p + (off + 16), (u8 *)p + ((next % p->n) * 16 + 16));
            }
            p->done = 1;
        }
    }
}
/* localdecomp:end func_L01_00477BC0 */

/* localdecomp:start func_L01_00477C80 */
extern int D_L01_0021F6C0[];

int func_L01_00477C80(int first, int second, int *firstIndex, int *secondIndex) {
    extern void func_0038CF38(Vec4 *a0, Vec4 *a1);
    char *a = (char *)D_L01_0021F6C0[first];
    char *b = (char *)D_L01_0021F6C0[second];
    int j, i, previousA, previousB;
    char *nextA, *nextB, *priorA, *priorB;
    for (i = 0; i < *(int *)a - 1; ++i) {
        for (j = 0; j < *(int *)b - 1; ++j) {
            if (((f32 (*)(const void *, const void *))func_0038CF38)(a + ((i << 4) + 0x10), b + ((j << 4) + 0x10)) < 0.5f) {
                if (i == 0) previousA = *(int *)a - 2;
                else previousA = i - 1;
                if (j == 0) previousB = *(int *)b - 2;
                else previousB = j - 1;
                nextA = a + (((i + 1) << 4) + 0x10);
                nextB = b + (((j + 1) << 4) + 0x10);
                if (((f32 (*)(const void *, const void *))func_0038CF38)(nextA, nextB) < 0.5f) {
                    *firstIndex = i; *secondIndex = j; return 1;
                }
                priorA = a + ((previousA << 4) + 0x10);
                if (((f32 (*)(const void *, const void *))func_0038CF38)(priorA, nextB) < 0.5f) {
                    *firstIndex = previousA; *secondIndex = j; return 1;
                }
                priorB = b + ((previousB << 4) + 0x10);
                if (((f32 (*)(const void *, const void *))func_0038CF38)(nextA, priorB) < 0.5f) {
                    *firstIndex = i; *secondIndex = previousB; return 1;
                }
                if (((f32 (*)(const void *, const void *))func_0038CF38)(priorA, priorB) < 0.5f) {
                    *firstIndex = previousA; *secondIndex = previousB; return 1;
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L01_00477C80 */

/* localdecomp:start func_L01_00477ED0 */
extern int D_L01_0021F6C0[];
extern float func_L01_00477F20(int a);

float func_L01_00477ED0(int a0)
{
    if (a0 != -1) {
        int v = D_L01_0021F6C0[a0];
        if (v != 0) {
            return func_L01_00477F20(v);
        }
    }
    return -1.0f;
}
/* localdecomp:end func_L01_00477ED0 */

INCLUDE_ASM("asm/levels", func_L01_00477F20);

LINKER_REMNANT("asm/levels", func_L01_004781A0);

/* localdecomp:start func_L01_004781D0 */
extern u8 D_L01_001D672E;
__asm__(".extern D_L01_001D672E, 16");
extern s32 D_001D5528_sda;
__asm__(".extern D_001D5528_sda, 4");
extern s32 D_001D5528;
__asm__(".extern D_001D5528, 16");
extern s32 D_00143950[];

void func_L01_004781D0(void) {
    s32 old;
    s32 n;

    if (D_L01_001D672E == 0) {
        old = D_001D5528_sda;
        n = old + 1;
        D_001D5528_sda = n;
        if (n % 50 == 0) {
            if (D_00143950[0] != 0) {
                D_001D5528 = old + 11;
            }
        }
    }
}
/* localdecomp:end func_L01_004781D0 */
