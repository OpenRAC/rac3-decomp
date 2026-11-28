#include "common.h"

typedef struct {
    s32 n;
    s32 done;
    s32 pad[2];
} Tab_00477BC0;

/* localdecomp:start func_L01_00472C98 */
#include "vu0.h"
void func_L01_00472C98(u8 *p) {
    extern void func_L01_004CAB30(void *, void *);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern f32 func_L01_004451A0(f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    vu0_v4 movement, accel, velocity, impulse;
    u8 *d = p + 0x20;
    s32 extra = (s32)p + 0x30;
    s32 rgb, alpha, mode, spin;
    f32 scale0, scale1, base0, base1, size0, size1, speed, t, applied;
    accel.w = 0.0f;
    accel.x = *(f32 *)(p + 0x20);
    accel.y = *(f32 *)(d + 4);
    accel.z = *(f32 *)(d + 8);
    velocity.x = *(f32 *)(extra + 0);
    velocity.y = *(f32 *)(extra + 4);
    velocity.z = *(f32 *)(extra + 8);
    velocity.w = 0.0f;
    base0 = (f32)d[0x1E] * 0.0078125f;
    base1 = (f32)d[0x1F] * 0.0078125f;
    scale0 = (f32)d[0x1C] * 0.0078125f;
    scale1 = (f32)d[0x1D] * 0.0078125f;
    rgb = d[0xC] & 15;
    rgb = rgb | ((rgb << 16) | (rgb << 8));
    alpha = (d[0xC] >> 4) | 0x70;
    spin = d[0xD] >> 4;
    mode = d[0xD] & 15;
    speed = (f32)d[0xF] * 0.0078125f;
    size0 = base0 * 210000.0f;
    size1 = base1 * 210000.0f;

    func_L01_004CAB30(p + 0x10, p + 0x10);
    t = 1.0f - (f32)*(s16 *)(p + 0xA) / (f32)d[0xE];
    if (mode == 0) {
        *(s32 *)(p + 4) = func_0038DBD8(0x103080, rgb, t) | (alpha << 24);
        *(f32 *)(p + 0xC) = size0 + (size1 - size0) * t;
        applied = scale0 + (scale1 - scale0) * t;
        func_0038CE20(&movement, &velocity, speed * func_L01_004451A0(t));
    } else {
        f32 fade = func_L01_004451A0(t);
        applied = scale1;
        *(s32 *)(p + 4) = rgb | ((s32)((f32)alpha - (f32)alpha * fade) << 24);
        func_0038CE20(&movement, &velocity, speed);
    }
    func_0038CF68(&impulse, &accel, applied);
    vec_add_ba(p + 0x10, p + 0x10, &impulse);
    vec_add_ab(p + 0x10, &movement, p + 0x10);
    p[8] += spin;
    if (func_0038CB00(p + 0xA)) {
        if (mode == 0) {
            d[0xE] = 17;
            d[0xD] |= 1;
            *(s16 *)(p + 0xA) = 17;
        } else func_003CD250(p);
    }
}
/* localdecomp:end func_L01_00472C98 */

/* localdecomp:start func_L01_00472F58 */
typedef int Quad_472F58 __attribute__((mode(TI)));
typedef struct {
    Quad_472F58 velocity;          /* 0x20 */
    s32 alpha;                     /* 0x30: the alpha, kept until the colour is made */
} Drift_472F58;
typedef struct {
    u8 type;                       /* 0x00 */
    s8 flags;                      /* 0x01 */
    u8 texture;                    /* 0x02 */
    u8 render;                     /* 0x03 */
    u32 rgba;                      /* 0x04 */
    u8 spin;                       /* 0x08 */
    u8 render2;                    /* 0x09 */
    s16 life;                      /* 0x0A */
    f32 size;                      /* 0x0C */
    Quad_472F58 position;          /* 0x10 */
    Drift_472F58 drift;            /* 0x20 */
} Smoke_472F58;
typedef struct {
    u8 pad_0[1];
    u8 level;                      /* 0x01: weapon level of the stream */
    u8 pad_2[0xEE];
} Stream_472F58;

extern Stream_472F58 D_L01_002C5600[];
extern u8 D_001425D1[];
extern u8 *D_L01_0022124C[];
/* a later block of the file declares it u8; the casts here read the full word */
extern u8 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern Smoke_472F58 *func_L01_004618E0_00472F58(s32 type);

/* particle_spawn_darkening_smoke: a type 0x6D particle, the Lava Gun stream's smoke: it starts
 * orange (blue-shifted at V5) and darkens, its size scale x 2.5. */
Smoke_472F58 *func_L01_00472F58(Quad_472F58 *position, Quad_472F58 *velocity, f32 scale, s32 render) {
    Smoke_472F58 *p = func_L01_004618E0_00472F58(0x6D);
    Drift_472F58 *d;

    if (p != 0) {
        d = &p->drift;
        p->position = *position;
        p->render = render;
        p->flags = 0;
        p->render2 = 0x44;
        p->spin = func_00382468(0xFF);
        p->life = (((s32 (*)(s32, s32))func_00382498)(5, 0x32) * 5 + 2) / 6;
        d->velocity = *velocity;
        p->size = scale * 210000.0f * 2.5f;
        if ((D_L01_002C5600 + D_001425D1[0])->level >= 4) {
            d->alpha = ((s32 (*)(s32, s32))func_00382498)(0xA0, 0xC0);
            p->texture = *D_L01_0022124C[0];
            p->rgba = func_0038DBD8(0x803030, 0x7F7F7F, func_003824E0(0.0f, 0.5f)) | (d->alpha << 24);
        } else {
            d->alpha = ((s32 (*)(s32, s32))func_00382498)(0x40, 0x80);
            p->texture = *D_L01_0022124C[0];
            p->rgba = func_0038DBD8(0x103080, 0, func_003824E0(0.0f, 0.5f)) | (d->alpha << 24);
        }
    }
    return p;
}
/* localdecomp:end func_L01_00472F58 */

/* localdecomp:start func_L01_004730F8 */
#include "vu0.h"
extern u8 D_001425D1[];
typedef struct { u8 pad0; u8 kind; u8 pad[0xEE]; } Entry_004730F8;
extern Entry_004730F8 D_L01_002C5600_004730F8[];
void func_L01_004730F8(u8 *obj) {
    extern void func_L01_004CAB30(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_004C7D98(void *, void *);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_003CD250(u8 *);
    vu0_v4 noise;
    u8 *state;
    u8 *pos;
    s32 brightness;
    u32 color;
    func_L01_004CAB30(obj + 0x10, obj + 0x10);
    state = obj + 0x20;
    if (((Entry_004730F8 *)((D_001425D1[0] * 0xF0) + (s32)D_L01_002C5600_004730F8))->kind >= 4) *(s32 *)(state + 0x10) -= 2;
    else *(s32 *)(state + 0x10) -= 1;
    if (*(s32 *)(state + 0x10) < 0) *(s32 *)(state + 0x10) = 0;
    obj[8]++;
    pos = obj + 0x10;
    vec_add_ba(pos, state, pos);
    *(f32 *)(obj + 0xC) += 1575.0f;
    func_0038CE20(state, state, 0.99f);
    func_L01_004C7D98(pos, &noise);
    brightness = obj[4];
    if (brightness < 32) {
        func_0038CE20(&noise, &noise, 0.0015f);
        vec_add_ab(state, state, &noise);
    } else {
        func_0038CE20(&noise, &noise, -0.00075f);
        vec_add_ab(state, state, &noise);
    }
    color = *(u32 *)(obj + 4);
    color &= 0xFFFFFF;
    color = func_0038DBD8(color, 0, 0.025f);
    *(s32 *)(obj + 4) = color | (*(s32 *)(state + 0x10) << 24);
    if (*(s32 *)(state + 0x10) == 0) func_003CD250(obj);
}
/* localdecomp:end func_L01_004730F8 */

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

/* localdecomp:start func_L01_004736F0 */
#include "vu0.h"
extern s32 func_0038CB00(void *);
extern void func_003CD250(u8 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004CAB30(void *, void *);

void func_L01_004736F0(Ray_4735F0 *r) {
    vu0_v4 c;
    vu0_v4 b;
    Quad_4735F0 *tail = &r->tail;
    s32 alpha;

    if (func_0038CB00(&r->life)) {
        func_003CD250(r);
    } else {
        r->texture = *D_L01_00221254[0];
        *(Quad_4735F0 *)&c = r->head;
        vec_add_ba(&r->head, &r->head, tail);
        vec_sub_ab(&b, &r->head, &c);
        func_0038CF68(&b, &b, ((f32 *)tail)[3] * 1.35f);
        vec_sub_ba(r->pad_20, &r->head, &b);
        func_L01_004CAB30(&r->head, &r->head);
        func_L01_004CAB30(r->pad_20, r->pad_20);
        if (r->life < r->spin) {
            alpha = (f32)r->life / (f32)r->spin * 127.0f;
            r->rgba = (alpha << 24) | (r->rgba & 0xFFFFFF);
            r->end_rgba = (alpha << 24) | (r->end_rgba & 0xFFFFFF);
        }
    }
}
/* localdecomp:end func_L01_004736F0 */

LINKER_REMNANT("asm/levels", func_L01_00473858);

/* localdecomp:start func_L01_00473860 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vector_00473860;
typedef struct {
    f32 vx, vy, vz, gravity, growth;
    u8 alpha, spin;
} Motion_00473860;
typedef struct {
    u8 pad[4];
    s32 color;
    u8 spin, flags;
    s16 life;
    f32 size;
    Vector_00473860 position;
    Motion_00473860 motion;
} Particle_00473860;
void func_L01_00473860(u8 *raw) {
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    extern s32 func_00382468(s32);
    extern void func_L01_0046A938(void *, f32, f32, s32, s32);
    extern void func_L01_004CAB30(void *, void *);
    Particle_00473860 *p = (Particle_00473860 *)raw;
    Motion_00473860 *m;
    Vector_00473860 v;
    if (func_0038CB00(&p->life)) {
        func_003CD250(raw);
        if (func_00382468(10) == 1) {
            func_L01_0046A938(&p->position, 0.4f, 31500.001953125f, 0, -1);
        }
    } else {
        m = &p->motion;
        p->color = (p->color & 0xFFFFFF) | (((p->color >> 24) + m->alpha) << 24);
        v.x = m->vx;
        v.y = m->vy;
        v.z = m->vz;
        v.w = 0.0f;
        {
            vu0_q qa, qb;
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(p->position));
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(v));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(qa) : "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(p->position) : "j"(qa));
        }
        func_L01_004CAB30(&p->position, &p->position);
        m->vz -= m->gravity;
        if (p->position.w != 0.0f) {
            if (p->position.w == 2.0f) {
                func_L01_004CAB30(&p->position, &p->position);
            }
            p->position.w = 2.0f;
        }
        p->spin += m->spin;
        p->size += m->growth;
    }
}
/* localdecomp:end func_L01_00473860 */

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

/* localdecomp:start func_L01_00473AC8 */
typedef int Q_00473AC8 __attribute__((mode(TI)));
extern u8 *D_001A71A0[];
extern Q_00473AC8 D_L01_001EAA20[];
extern s32 D_L01_001D673C;
extern vu0_v4 D_001A4EC0_00473AC8;
void func_L01_00473AC8(Part_00470258 *particle) {
    extern void func_L01_004CAB30(void *, void *);
    extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382468(s32);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_L01_0046A938(void *, f32, f32, s32, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
    extern void func_003C5180(void *, void *, s32);
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    vu0_v4 next, at, velocity;
    Sub_00470258 *s;
    u8 *p = (u8 *)particle;
    s32 hit;

    if (particle == 0) return;
    s = &particle->sub;
    func_L01_004CAB30(&particle->f10, &particle->f10);
    particle->fC += -120.00001f;
    vec_add_ba(&next, &particle->f10, &s->v);
    hit = func_003D3CB0(&particle->f10, &next, 2, D_001A71A0[0], 0) != 0;
    particle->f4 = func_0038DBD8(s->f10, s->f14, 1.0f - (f32)particle->fA / (f32)s->f18);
    if (((f32 *)&s->v)[0] != 0.0f || ((f32 *)&s->v)[1] != 0.0f || ((f32 *)&s->v)[2] != 0.0f) {
        if (hit) {
            u8 r, g, b;
            u32 alpha;
            u8 max;
            f32 scale;
            s32 color;
            particle->f10 = D_L01_001EAA20[0];
            qzero(&s->v);
            color = particle->f4;
            particle->fC += particle->fC;
            g = color >> 8;
            alpha = (u32)color >> 24;
            b = color >> 16;
            r = p[4];
            if (g < r) {
                max = b < r ? r : b;
            } else {
                max = b < g ? g : b;
            }
            scale = 255.0f / (f32)max;
            s->f10 = (alpha << 24) | ((s32)((f32)(s32)b * scale) << 16) | ((s32)((f32)(s32)g * scale) << 8) |
                     (s32)((f32)(s32)r * scale);
            s->f18 = particle->fA;
            switch (s->f1A) {
            case 0: break;
            case 1: {
                vu0_v4 *pos = &at;
                f32 size;
                at.x = ((f32 *)&particle->f10)[0];
                at.y = ((f32 *)&particle->f10)[1];
                at.z = ((f32 *)&particle->f10)[2] + 0.01f;
                size = func_003824E0(0.01f, 0.15f);
                func_L01_0046A938(pos, size, 5250.0f, 0, ((func_00382468(6) + 20) << 24) | 0xFF8040);
                break;
            }
            case 2: {
                vu0_v4 *pos = &at;
                vu0_v4 *vel = &velocity;
                s32 i, spin;
                u8 *created;
                f32 speed, size;
                at.x = ((f32 *)&particle->f10)[0];
                at.y = ((f32 *)&particle->f10)[1];
                at.z = ((f32 *)&particle->f10)[2] + 0.02f;
                for (i = 0; i < 5; i++) {
                    speed = func_003824E0(0.1f, 0.2f) * 0.020000001f;
                    func_0038CE20(vel, &D_001A4EC0_00473AC8, -speed);
                    spin = (s32)func_L01_00443A18(1.0f, 2.0f);
                    size = func_003824E0(0.15f, 0.25f) * 210000.0f;
                    created = func_L01_004669B0(pos, 0.0f, 1.0f, 1.01f, size, spin, vel, 0x7F202020, 0);
                    if (created) {
                        u8 *extra = created + 0x20;
                        created[3] = 0x44;
                        *(s16 *)(created + 10) = 75;
                        created[9] = 0x44;
                        *(f32 *)(extra + 0x1C) = 4.0f;
                        *(s32 *)(extra + 4) = 3;
                        extra[10] = 48;
                        extra[11] = created[10];
                    }
                }
                break;
            }
            }
        } else {
            particle->f10 = *(Q_00473AC8 *)&next;
            if (D_L01_001D673C) {
                f32 accel;
                func_003C5180(&particle->f10, &at, 0);
                accel = ((f32 *)&s->v)[3];
                if (accel != 0.0f) {
                    func_0038CE20(&at, &at, -accel);
                    vec_add_ab(&s->v, &s->v, &at);
                } else {
                    func_0038CE20(&at, &at, 0.009072f);
                    vec_add_ab(&s->v, &s->v, &at);
                }
            } else {
                f32 accel = ((f32 *)&s->v)[3];
                if (accel != 0.0f) {
                    ((f32 *)&s->v)[2] += accel;
                } else {
                    ((f32 *)&s->v)[2] += -0.009072f;
                }
            }
        }
    }
    if (func_0038CB00(&particle->fA) || particle->fC < 0.0f || next.x < 0.01f || next.y < 0.01f || next.z < 0.01f) {
        func_003CD250(p);
    } else {
        particle->f8--;
    }
}
/* localdecomp:end func_L01_00473AC8 */

LINKER_REMNANT("asm/levels", func_L01_00474068);

/* localdecomp:start func_L01_00474070 */
void func_L01_00474070(void) {
}
/* localdecomp:end func_L01_00474070 */

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

/* localdecomp:start func_L01_004741B8 */
#include "vu0.h"
typedef struct {
    u8 b0, b1, b2, b3;
    u32 w4;
    u8 b8, b9;
    s16 hA;
    u32 wC;
    vu0_v4 v10;
    vu0_v4 v20;
    f32 f30, f34, f38;
    s16 h3C;
} P_4741B8;
void func_L01_004741B8(P_4741B8 *p) {
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_004CAB30(void *, void *);
    vu0_v4 d;
    f32 *q = &p->f30;
    f32 h;
    s32 a;
    if (func_0038CB00(&p->hA)) {
        func_003CD250((u8 *)p);
        return;
    }
    vec_sub_ba(&d, &p->v10, &p->v20);
    d.w = 0.0f;
    func_0038CF68(&d, &d, q[0]);
    vec_add_ba(&p->v10, &p->v10, &d);
    vec_add_ba(&p->v20, &p->v20, &d);
    func_L01_004CAB30(&p->v10, &p->v10);
    func_L01_004CAB30(&p->v20, &p->v20);
    h = (f32)p->hA;
    p->v10.w = q[1] * ((q[2] - 1.0f) * (h / (f32)*(s16 *)&q[3]) + 1.0f);
    if (p->hA < p->b8) {
        a = (s32)(h / (f32)p->b8 * 127.0f);
        p->w4 = (a << 24) | (p->w4 & 0xFFFFFF);
        p->wC = (a << 24) | (p->wC & 0xFFFFFF);
    }
}
/* localdecomp:end func_L01_004741B8 */

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

/* localdecomp:start func_L01_004744D0 */
#include "vu0.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_004744D0;
void func_L01_004744D0(u8 *p)
{
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_L01_004CAB30(void *,void *);
    V_004744D0 v;
    u8 *s=p+48;
    u8 *b,*a;
    f32 t;
    s32 alpha;
    if (func_0038CB00(p+10)) {func_003CD250(p);return;}
    if (*(s16 *)(p+10)<10) *(f32 *)(p+48)-=0.1f;
    vec_sub_ba(&v, (V_004744D0 *)(p+16), (V_004744D0 *)(p+32));
    v.w=0;
    func_0038CF68(&v,&v,*(f32 *)(p+48));
    a=p+16;
    vec_add_ba(a, a, &v);
    func_0038CF68(&v,&v,*(f32 *)(p+48));
    b=p+32;
    vec_add_ba(b, b, &v);
    func_L01_004CAB30(a,a);
    func_L01_004CAB30(b,b);
    t=(f32)*(s16 *)(p+10)/(f32)*(s16 *)(s+12);
    *(f32 *)(p+28)=*(f32 *)(s+4)*(1.0f+(*(f32 *)(s+8)-1.0f)*t);
    if (*(s16 *)(p+10)<p[8]) {
        alpha=(s32)(((f32)*(s16 *)(p+10)/(f32)p[8])*127.0f)<<24;
        *(s32 *)(p+4)=alpha|(*(s32 *)(p+4)&0xFFFFFF);
        *(s32 *)(p+12)=alpha|(*(s32 *)(p+12)&0xFFFFFF);
    }
}
/* localdecomp:end func_L01_004744D0 */

/* localdecomp:start func_L01_00474680 */
#include "vu0.h"
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern u8 *D_L01_00221204[];
typedef struct { f32 f0; f32 f4; f32 f8; s16 hC; } Q_474680;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    s16 hA;
    s32 wC;
    vu0_v4 v10;
    vu0_v4 v20;
    Q_474680 q;
} P_474680;
P_474680 *func_L01_00474680(vu0_v4 *a0, vu0_v4 *a1, s32 a2, s32 a3, s32 a4, s32 a5, f32 f12, f32 f13, f32 f14, f32 f15, s32 a6) {
    vu0_v4 tmp;
    P_474680 *p = (P_474680 *)func_L01_004618E0(0x77);
    Q_474680 *q;
    if (p != 0) {
        p->w4 = a3;
        p->wC = a4;
        p->b9 = 0x22;
        p->b3 = 0x48;
        p->b1 = 3;
        p->b2 = D_L01_00221204[0][a6];
        q = &p->q;
        p->q.f0 = func_0038CEA8(a1);
        *(vu0_q *)&p->v10 = *(vu0_q *)a0;
        func_0038CF68(&tmp, a1, f14);
        vec_sub_ab(&p->v20, a0, &tmp);
        p->v20.w = f13;
        p->b8 = a5;
        p->v10.w = f12;
        p->hA = a2;
        q->hC = a2;
        q->f4 = f12;
        q->f8 = f15;
    }
    return p;
}
/* localdecomp:end func_L01_00474680 */

/* localdecomp:start func_L01_004747C0 */
#include "vu0.h"
extern f32 D_L01_001D7F88;
__asm__(".extern D_L01_001D7F88, 4");
void func_L01_004747C0(u8 *p) {
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_004CAB30(void *, void *);
    vu0_v4 delta;
    u8 *s = p + 0x30;
    u8 *pos;
    u8 *tail;
    f32 t, blend;
    s32 alpha;
    if (func_0038CB00(p + 0xA)) { func_003CD250(p); return; }
    t = (f32)*(s16 *)(p + 0xA) / (f32)*(s16 *)(s + 0xC);
    blend = *(f32 *)(s + 8) + (1.0f - *(f32 *)(s + 8)) * t;
    pos = p + 0x10;
    *(f32 *)(p + 0x1C) = *(f32 *)(s + 4) * blend;
    *(f32 *)s -= 0.014f;
    tail = p + 0x20;
    vec_sub_ba(&delta, pos, tail);
    delta.w = 0;
    func_0038CF68(&delta, &delta, *(f32 *)s);
    vec_add_ba(pos, pos, &delta);
    func_0038CF68(&delta, &delta, *(f32 *)s * D_L01_001D7F88);
    vec_add_ba(tail, tail, &delta);
    func_L01_004CAB30(pos, pos);
    func_L01_004CAB30(tail, tail);
    if (*(s16 *)(p + 0xA) < p[8]) {
        alpha = (s32)((f32)*(s16 *)(p + 0xA) / (f32)p[8] * 127.0f);
        *(u32 *)(p + 4) = (alpha << 24) | (*(u32 *)(p + 4) & 0xFFFFFF);
        *(u32 *)(p + 0xC) = (alpha << 24) | (*(u32 *)(p + 0xC) & 0xFFFFFF);
    }
}
/* localdecomp:end func_L01_004747C0 */

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

/* localdecomp:start func_L01_00474B48 */
#include "vu0.h"
typedef int Q_00474B48 __attribute__((mode(TI)));
extern u8 D_001A4C60[];
extern s32 D_L01_001DFB40;
extern f32 D_L01_001E2880_00474B48[];

void func_L01_00474B48(u8 *p)
{
    extern void func_L01_004CAB30(void *,void *);
    extern void func_0038CE20(void *,void *,f32);
    extern f32 func_0038CF00_00474B48(void *,void *);
    extern f32 func_003824E0(f32,f32);
    extern void func_0038CF68(void *,void *,f32);
    extern f32 func_0038DAB8(f32,f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    vu0_v4 delta,hero;
    u8 *s=p+0x20;
    u8 *pos=p+0x10;
    u8 *h;
    func_L01_004CAB30(pos,pos);
    func_0038CE20(s,s,0.9f);
    *(f32 *)(s+8)-=*(f32 *)(s+12);
    vec_add_ba((vu0_v4 *)(pos), (vu0_v4 *)(pos), (vu0_v4 *)(s));
    func_L01_004CAB30(pos,pos);
    if(func_0038CF00_00474B48(pos,D_001A4C60)<1.05f) {
        h=D_001A4C60-0x80;
        if(*(f32 *)(h+0x170)!=0.0f) {
            *(Q_00474B48 *)&hero=*(Q_00474B48 *)D_001A4C60;
            vec_sub_ab((vu0_v4 *)(&delta), (vu0_v4 *)(pos), (vu0_v4 *)(&hero));
            func_0038CF68(&delta,&delta,*(f32 *)(h+0x170)*0.2f+func_003824E0(0.1f,2.0f)*0.020000001f*0.15f);
            p[8]+=(s32)((f32)*(s16 *)(s+0x16)**(f32 *)(h+0x170)*0.5f);
            vec_add_ba((vu0_v4 *)(pos), (vu0_v4 *)(pos), (vu0_v4 *)(&delta));
        }
    }
    if(D_L01_001DFB40%10==0) {
        *(f32 *)(s+0x1c)=func_0038DAB8(*(f32 *)(s+0x1c),1.0f);
        { f32 k=func_0038D0B0(*(f32 *)(s+0x1c))*0.0075f;
        func_0038CF68(&delta,D_L01_001E2880_00474B48,k); }
        vec_add_ab((vu0_v4 *)(s), (vu0_v4 *)(s), (vu0_v4 *)(&delta));
    }
    if(*(s16 *)(p+0xa)<*(s16 *)(s+0x14))
        *(s32 *)(p+4)=((s32)((f32)*(s16 *)(p+0xa)/(f32)*(s16 *)(s+0x14)*128.0f)<<24)|0x204040;
    else *(s32 *)(p+4)=0x4f204040;
    p[8]+=s[0x16];
    if(func_0038CB00(p+0xa)) func_003CD250(p);
}
/* localdecomp:end func_L01_00474B48 */

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

/* localdecomp:start func_L01_00474F38 */
#include "vu0.h"
typedef struct {
    vu0_v4 velocity;
    s16 timer, duration;
    u8 phase, first, second, third;
    f32 scale;
} State_00474F38;


__asm__(".extern D_L01_001D7FA0, 4");
extern s32 D_L01_001D7FA0;
__asm__(".extern D_L01_001D7FA4, 4");
extern s32 D_L01_001D7FA4;
__asm__(".extern D_L01_001D7F94, 4");
extern s32 D_L01_001D7F94;
__asm__(".extern D_L01_001D7F90, 4");
extern s32 D_L01_001D7F90;
__asm__(".extern D_L01_001D7F98, 4");
extern s32 D_L01_001D7F98;
__asm__(".extern D_L01_001D7F9C, 4");
extern f32 D_L01_001D7F9C;
typedef struct {
    s32 type, color;
    u8 spin, pad9[3];
    f32 scale;
    vu0_v4 pos;
    State_00474F38 state;
} Particle_00474F38;
void func_L01_00474F38(Particle_00474F38 *p) {
    extern s32 func_0038CB00(void *);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_L01_00448070(s32, s32, f32);
    extern f32 func_003C4088(f32, f32, f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_003CD250(u8 *);
    State_00474F38 *s = &p->state;
    vu0_v4 step;
    f32 ratio;

    if (func_0038CB00(&s->timer)) {
        s32 phase = (s32)++s->phase + 1;
        s32 duration;
        if (phase == 0) duration = s->first;
        else if (phase == 1) duration = s->second;
        else duration = s->third;
        s->timer = duration;
        s->duration = duration;
    }
    if (s->phase == 0) {
        s32 spin;
        s32 result;
        vec_add_ba(&p->pos, &p->pos, &s->velocity);
        spin = p->spin;
        if (!(((s32)p >> 8) & 1)) result = spin - D_L01_001D7FA0;
        else result = spin + D_L01_001D7FA0;
        p->spin = result;
    } else if (s->phase == 1) {
        s32 n;
        s32 spin;
        ratio = (f32)s->timer;
        ratio /= (f32)s->duration;
        func_0038CE20(&step, s, ratio);
        n = func_L01_00448070(D_L01_001D7FA4, D_L01_001D7FA0, ratio);
        vec_add_ba(&p->pos, &p->pos, &step);
        spin = p->spin + n;
        if (!(((s32)p >> 8) & 1)) spin = p->spin - n;
        p->spin = spin;
        p->scale = func_003C4088(s->scale, D_L01_001D7F9C, ratio);
        p->color = func_0038DBD8(D_L01_001D7F94, D_L01_001D7F90, ratio);
    } else if (s->phase == 2) {
        s32 n;
        s32 spin;
        ratio = (f32)s->timer;
        ratio /= (f32)s->duration;
        n = func_L01_00448070(0, D_L01_001D7FA4, ratio);
        spin = p->spin + n;
        if (!(((s32)p >> 8) & 1)) spin = p->spin - n;
        p->spin = spin;
        p->scale = func_003C4088(s->scale * 0.5f, s->scale, ratio);
        p->color = func_0038DBD8(D_L01_001D7F98, D_L01_001D7F94, ratio);
    } else {
        func_003CD250((u8 *)p);
    }
}
/* localdecomp:end func_L01_00474F38 */

/* localdecomp:start func_L01_00475128 */
typedef int Quad_00475128 __attribute__((mode(TI)));
typedef struct {
    Quad_00475128 v;
    s32 owner;
    f32 scale, speed;
    u8 alpha, mode, flag;
} Sub_00475128;
typedef struct {
    u8 type, flags, texture, render;
    s32 rgba;
    u8 spin, render2;
    s16 life;
    f32 age;
    Quad_00475128 position;
    Sub_00475128 sub;
} Part_00475128;
extern u8 *D_L01_00221288[];
Part_00475128 *func_L01_00475128(s32 owner, Quad_00475128 *pos, Quad_00475128 *vel,
                                s32 color, s32 life, u8 flag, u8 mode, u8 texture,
                                f32 width, f32 age, f32 speed)
{
    extern Part_00470258 *func_L01_004618E0(s32);
    extern s32 func_00382468(s32);
    Part_00475128 *p;
    Sub_00475128 *q;
    p = (Part_00475128 *)func_L01_004618E0(0x7C);
    if (p) {
        p->flags=0;
        p->render2=0x44;
        p->render=0x48;
        p->spin=func_00382468(0x100);
        p->age=age;
        p->texture=D_L01_00221288[0][texture];
        p->rgba=color;
        p->life=life;
        p->position=*pos;
        ((f32 *)&p->position)[3]=1.0f/(f32)life;
        q=&p->sub;
        q->owner=owner;
        q->v=*vel;
        /* The store order is a scheduling lever: gcc issues the last store of the
         * run to one base first and the rest in source order, so writing these
         * backwards of retail is what reproduces retail's at 0x00475210. */
        ((f32 *)&q->v)[3]=width;
        q->scale=age;
        q->speed=speed;
        q->alpha=color>>24;
        q->flag=flag;
        q->mode=mode;
    }
    return p;
}
/* localdecomp:end func_L01_00475128 */

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
    extern u8 *func_L01_00475128_00475278(s32,void *,void *,s32,f32,s32,s32,s32,s32,f32,f32);
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
            created=func_L01_00475128_00475278(*(s32 *)(s+16),p+16,&pos,((s32)(t*64.0f)<<24)|0x202020,0.0f,33,0,0,1,*(f32 *)(p+12),*(f32 *)(p+12)*0.8f);
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
            created=func_L01_00475128_00475278(*(s32 *)(s+16),&pos,vp,*(s32 *)(p+4),0.0f,func_00382498((D_L01_001D7FB4_00475278*5+2)/6,(D_L01_001D7FB8_00475278*5+2)/6),0,0,0,*(f32 *)(p+12),*(f32 *)(p+12)*D_L01_001D7FA8_00475278);
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

/* localdecomp:start func_L01_00475C60 */
typedef struct {
    s128_00470258 v;
    f32 delta;
    u8 mode;
    u8 pad15;
    s16 scale;
    s32 first;
    s32 second;
} Sub_00475C60;
extern u8 *D_L01_00221294[];
Part_00470258 *func_L01_00475C60(s128_00470258 *pos, s128_00470258 *vec,
    s32 life, s32 mode, s32 first, s32 second, s32 texture,
    f32 start, f32 end, f32 scale) {
    extern Part_00470258 *func_L01_004618E0(s32);
    extern s32 fe_func_00443948(s32);
    Part_00470258 *p = func_L01_004618E0(127);
    Sub_00475C60 *q;
    if (p != 0) {
        p->f10 = *pos;
        p->f9 = 68;
        p->f3 = 72;
        p->f1 = 0;
        p->fC = start;
        p->f8 = fe_func_00443948(255);
        p->f2 = D_L01_00221294[0][texture];
        p->fA = life;
        q = (Sub_00475C60 *)&p->sub;
        q->v = *vec;
        ((f32 *)&q->v)[3] = 1.0f / (f32)(s16)life;
        q->delta = (end - start) / life;
        q->first = first;
        q->second = second;
        q->scale = scale * 128.0f;
        q->mode = mode;
    }
    return p;
}
/* localdecomp:end func_L01_00475C60 */

/* localdecomp:start func_L01_00475DC8 */
#include "vu0.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00475DC8;
extern s32 D_L01_001D673C;
void func_L01_00475DC8(u8 *p)
{
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    extern s32 func_0038DBD8(s32,s32,f32);
    extern void func_L01_004CAB30(void *,void *);
    extern void func_L01_004C7D98(void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    u8 *s;
    u8 *pos;
    V_00475DC8 v;
    if (func_0038CB00(p+10)) {
        func_003CD250(p);
        return;
    }
    s=p+32;
    pos=p+16;
    *(s32 *)(p+4)=func_0038DBD8(*(s32 *)(s+28),*(s32 *)(s+24),(f32)*(s16 *)(p+10)**(f32 *)(s+12));
    vec_add_ab(p+16, p+16, s);
    func_L01_004CAB30(pos,pos);
    if (!D_L01_001D673C) {
        *(f32 *)(s+8)-=(f32)*(s16 *)(s+22)*0.0078125f*0.00040000002f;
    } else {
        func_L01_004C7D98(pos,&v);
        func_0038CF68(&v,&v,-((f32)*(s16 *)(s+22)*0.0078125f*0.00040000002f));
        vec_add_ab(p+16, p+16, &v);
    }
    p[8]+=s[20];
    *(f32 *)(p+12)+=*(f32 *)(s+16);
}
/* localdecomp:end func_L01_00475DC8 */

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

/* localdecomp:start func_L01_00476498 */
#include "vu0.h"
typedef struct { s32 count; s32 pad[3]; V_004734A8 nodes[1]; } Path_00476498;
s32 func_L01_00476498(u8 *path, s128_00470258 *out, s32 *index, f32 *offset, s32 wrap, f32 distance) {
    extern void func_0038CF68(void *, void *, f32);
    s32 direction = 1;
    s32 crossed = 0;
    s32 next;
    s32 n;
    f32 old;
    s32 beyond;
    s32 following;
    V_004734A8 delta;
    if (distance < 0.0f) {
        distance = -distance;
        direction = -1;
    }
    next = *index;
    while (distance != 0.0f) {
        if (next == *(s32 *)path - 1 && !wrap) break;
        beyond = direction == 1 ? ((Path_00476498 *)path)->nodes[next].w < *offset + distance : *offset < distance;
        old = *offset;
        next += direction;
        if (beyond) {
            if (next >= *(s32 *)path || next < 0) next = (next + *(s32 *)path) % *(s32 *)path;
            if (direction == 1) {
                distance -= ((Path_00476498 *)path)->nodes[*index].w - old;
                *offset = 0.0f;
                if (distance < *offset) distance = *offset;
            } else {
                distance -= old;
                *offset = ((Path_00476498 *)path)->nodes[next].w;
            }
            if ((direction == 1 && *index == *(s32 *)path - 1) || (direction == -1 && *index == 0)) crossed = 1;
            *index = next;
        } else {
            *offset = direction == 1 ? old + distance : old - distance;
            distance = 0.0f;
        }
        next = *index;
    }
    *out = *(s128_00470258 *)(path + next * 16 + 0x10);
    if (*index == *(s32 *)path - 1 && !wrap) {
        if (direction == -1) {
            *index = 0;
            *out = *(s128_00470258 *)(path + 0x10);
            *offset = 0.0f;
        }
        return 1;
    }
    n = *(s32 *)path;
    following = *index + 1;
    if (following >= n) following %= n;
    vec_sub_ab(&delta, path + following * 16 + 0x10, path + *index * 16 + 0x10);
    func_0038CF68(&delta, &delta, *offset);
    vec_add_ab(out, out, &delta);
    return crossed;
}
/* localdecomp:end func_L01_00476498 */

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

/* localdecomp:start func_L01_00476750 */
#include "vu0.h"
f32 func_L01_00476750(Vec4 *out, Vec4 *point, Vec4 *a, Vec4 *b) {
    extern void func_0038CFB8(Vec4 *, Vec4 *, f32);
    extern f32 func_0038CE68(Vec4 *, Vec4 *);
    extern void func_0038CF38(Vec4 *, Vec4 *);
    Vec4 delta, normal, start;
    Vec4 *n = &normal;
    f32 d, t;
    s32 i;
    vec_sub_ba(&delta, a, b);
    start.q = a->q;
    normal.f[1] = delta.f[0];
    normal.f[2] = 0;
    normal.f[0] = -delta.f[1];
    start.f[2] = 0;
    func_0038CFB8(n, n, 1.0f);
    d = -func_0038CE68(n, &start);
    t = d + (normal.f[0] * point->f[0] + normal.f[1] * point->f[1]);
    out->f[0] = point->f[0] - t * normal.f[0];
    out->f[1] = point->f[1] - t * normal.f[1];
    out->f[2] = 0;
    {
    f32 *ap, *op, *bp;
    i=0; bp=b->f; op=out->f; ap=a->f;
    do {
        if (*ap+0.001f < *op && *bp+0.001f < *op) break;
        if (*op < *ap-0.001f && *op < *bp-0.001f) break;
        i++; bp++; op++; ap++;
    } while(i<2);
    }
    if(i<2) {
        f32 dist = ((f32 (*)(Vec4 *, Vec4 *))func_0038CF38)(out,a);
        if(dist < ((f32 (*)(Vec4 *, Vec4 *))func_0038CF38)(out,b)) out->q=a->q;
        else out->q=b->q;
        out->f[2]=0;
    }
    return ((f32 (*)(Vec4 *, Vec4 *))func_0038CF38)(point,out);
}
/* localdecomp:end func_L01_00476750 */

/* localdecomp:start func_L01_00476920 */
#include "vu0.h"
f32 func_L01_00476920(Vec4 *out, Vec4 *point, Vec4 *a, Vec4 *b, f32 height) {
    extern void func_L01_004766E0_00476920(Vec4 *, Vec4 *, f32);
    extern f32 func_L01_00476750_00476920(Vec4 *, Vec4 *, Vec4 *, Vec4 *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C4098(Vec4 *, Vec4 *, Vec4 *, f32);
    extern f32 func_0038CE68(Vec4 *, Vec4 *);
    extern void func_0038CF38(Vec4 *, Vec4 *);
    extern f32 func_0038CF00_00476920(Vec4 *, Vec4 *);
    Vec4 direction, start, normal, first, second;
    f32 result, length, projection, distance;
    f32 *op, *ap, *bp;
    s32 i;
    if (height > 0.0f && fabs_asm(point->f[2] - a->f[2]) < height &&
        fabs_asm(point->f[2] - b->f[2]) < height) {
        f32 along;
        result = func_L01_00476750_00476920(out, point, a, b);
        along = ((f32 (*)(Vec4 *, Vec4 *))func_0038CF38)(a, out);
        length = ((f32 (*)(Vec4 *, Vec4 *))func_0038CF38)(a, b);
        direction.q = a->q;
        start.q = b->q;
        func_003C4098(out, &direction, &start, along / length);
        return result;
    }
    vec_sub_ba(&direction, b, a);
    start.q = a->q;
    func_0038CF68(&direction, &direction, 1.0f);
    normal.q = direction.q;
    projection = -func_0038CE68(point, &direction);
    distance = func_0038CE68(&start, &normal);
    func_0038CE20(out, &direction, -(projection + distance) / func_0038CE68(&direction, &normal));
    vec_add_ab(out, out, &start);
    i = 0; bp = b->f; ap = a->f; op = out->f;
    do {
        if (*op > *ap && *op > *bp) break;
        if (*op < *ap && *op < *bp) break;
        i++; bp++; ap++; op++;
    } while (i < 3);
    if (i < 3) {
        f32 near = func_0038CF00_00476920(out, a);
        if (near < func_0038CF00_00476920(out, b)) out->q = a->q;
        else out->q = b->q;
    }
    first.q = point->q;
    second.q = out->q;
    return ((f32 (*)(Vec4 *, Vec4 *, f32))func_L01_004766E0_00476920)(&first, &second, 0.0f);
}
/* localdecomp:end func_L01_00476920 */

/* localdecomp:start func_L01_00476B98 */
#include "vu0.h"
typedef int Q_00476B98 __attribute__((mode(TI)));
typedef union { Q_00476B98 q; f32 f[4]; s32 count; } V_00476B98;

extern s32 func_L01_00476440(const s32 *count, s32 index, s32 delta, s32 wrap);
extern s32 func_L01_00476498_00476B98(V_00476B98 *path, V_00476B98 *out, s32 *idx, f32 *t, f32 step, s32 wrap);
extern f32 func_L01_004766E0_00476B98(V_00476B98 *a, V_00476B98 *b, f32 r);
extern f32 func_L01_00476920_00476B98(V_00476B98 *out, V_00476B98 *pos, V_00476B98 *a, V_00476B98 *b, f32 r);

s32 func_L01_00476B98(V_00476B98 *path, V_00476B98 *pos, V_00476B98 *out, s32 *outIdx, f32 *outT, s32 wrap, f32 range, f32 step, f32 r) {
    V_00476B98 cur;
    V_00476B98 tmp;
    V_00476B98 a;
    V_00476B98 b;
    s32 idx;
    f32 t;
    s32 lo;
    s32 hi;
    s32 best;
    f32 bestT;
    f32 bestD;
    f32 d;
    s32 done;

    cur.q = path[1].q;
    tmp.q = pos->q;
    idx = 0;
    t = 0.0f;
    best = 0;
    bestT = 0.0f;
    bestD = func_L01_004766E0_00476B98(&cur, &tmp, r);
    if (path->count == 0) {
        qzero(out);
        return 0;
    }
    do {
        done = func_L01_00476498_00476B98(path, &cur, &idx, &t, step, wrap);
        tmp.q = pos->q;
        d = func_L01_004766E0_00476B98(&cur, &tmp, r);
        if (d < bestD) {
            best = idx;
            bestD = d;
            bestT = t;
        }
    } while (!done);
    if (step + range < bestD) {
        return 0;
    }
    lo = best;
    t = bestT;
    func_L01_00476498_00476B98(path, &cur, &lo, &t, -step, wrap);
    bestD = 1e9f;
    t = bestT;
    hi = best;
    func_L01_00476498_00476B98(path, &cur, &hi, &t, step, wrap);
    hi = func_L01_00476440(&path->count, hi, 1, wrap);
    idx = lo;
    while (1) {
        tmp.q = path[idx + 1].q;
        a.q = pos->q;
        d = func_L01_004766E0_00476B98(&tmp, &a, r);
        if (d < bestD) {
            best = idx;
            bestD = d;
        }
        if (idx == hi) break;
        idx = (idx + 1) % path->count;
    }
    bestD = 1e9f;
    if (best > 0 || wrap) {
        s32 prev = (best - 1 + path->count) % path->count;
        f32 e = func_L01_00476920_00476B98(out, pos, &path[prev + 1], &path[best + 1], r);
        *outIdx = prev;
        tmp.q = path[prev + 1].q;
        a.q = out->q;
        *outT = func_L01_004766E0_00476B98(&tmp, &a, 0.0f);
        bestD = e;
    }
    if (best < path->count - 1 || wrap) {
        s32 next = (best + 1) % path->count;
        d = func_L01_00476920_00476B98(&tmp, pos, &path[best + 1], &path[next + 1], r);
        if (d < bestD) {
            out->q = tmp.q;
            *outIdx = best;
            a.q = path[best + 1].q;
            b.q = out->q;
            *outT = func_L01_004766E0_00476B98(&a, &b, 0.0f);
        }
    }
    return 1;
}
/* localdecomp:end func_L01_00476B98 */

/* localdecomp:start func_L01_00476F10 */
#include "vu0.h"
extern int D_L01_0021F6C0[];
s32 func_L01_00476F10(s32 index, vu0_v4 *src, vu0_v4 *out, f32 radius) {
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_0038CEA8(void *);
    extern f32 func_0038CE68_00476F10(void *, void *);
    vu0_v4 delta, temp, pos, dir, norm, cross, closest;
    s32 changed=0;
    s32 i;
    u8 *point;
    f32 len, projection;
    *(vu0_q *)&pos=*(vu0_q *)src;
    for(i=0;i<*(s32 *)D_L01_0021F6C0[index]-1;i++) {
        point=(u8 *)D_L01_0021F6C0[index]+(i<<4);
        if(*(f32 *)(point+0x1C)!=0.0f) {
            vec_sub_ab(&delta,&pos,point+0x10);
            delta.z=0.0f;
            vec_sub_ab(&dir,point+0x20,point+0x10);
            dir.z=0.0f;
            func_0038CF68(&norm,&dir,1.0f);
            func_0038CE90(&cross,&delta,&norm);
            if(!(radius<fabs_asm(cross.z))) {
                len=func_0038CEA8(&dir);
                projection=func_0038CE68_00476F10(&delta,&norm);
                if(projection>len || projection<0.0f) {
                    if(func_0038CEA8(&delta)<radius) {
                        func_0038CF68(&temp,&delta,radius);
                        changed=1;
                        vec_add_ab(&pos,&temp,(u8 *)D_L01_0021F6C0[index]+((i<<4)+0x10));
                        pos.z=src->z;
                    }
                } else {
                    func_0038CF68(&closest,&norm,projection);
                    changed=1;
                    vec_sub_ab(&temp,&delta,&closest);
                    func_0038CF68(&temp,&temp,radius);
                    vec_add_ba(&temp,&temp,&closest);
                    vec_add_ba(&pos,&temp,(u8 *)D_L01_0021F6C0[index]+((i<<4)+0x10));
                    pos.z=src->z;
                }
            }
        }
    }
    if(changed) *(vu0_q *)out=*(vu0_q *)&pos;
    return changed;
}
/* localdecomp:end func_L01_00476F10 */

/* localdecomp:start func_L01_00477190 */
#include "vu0.h"
typedef int Q_00477190 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00477190;
extern int D_L01_0021F6C0[];
extern V_00477190 D_001A4EC0;
s32 func_L01_00477190(s32 index, Q_00477190 *position, Q_00477190 *output, f32 radius) {
    extern f32 func_0038CE68_00477190(void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038CE90(void *,void *,void *);
    extern f32 func_0038CEA8(void *);
    V_00477190 delta, correction, point, edge, direction, cross, temp;
    u8 *path=(u8 *)D_L01_0021F6C0[index];
    s32 hit=0, i, next;
    f32 height, len, projection;
    *(Q_00477190 *)&point=*position;
    height=func_0038CE68_00477190(&point,&D_001A4EC0);
    for(i=0;i<*(s32 *)path-1;i=next) {
        u8 *p=path+(i<<4);
        next=i+1;
        if (*(f32 *)(p+0x1c)==0.0f && *(f32 *)(path+(next<<4)+0x1c)==0.0f) continue;
        vec_sub_ab(&delta, &point, (V_00477190 *)(p+16));
        vec_sub_ba(&edge, (V_00477190 *)(p+32), (V_00477190 *)(p+16));
        len=func_0038CE68_00477190(&delta,&D_001A4EC0);
        func_0038CF68(&temp,&D_001A4EC0,len);
        vec_sub_ba(&delta, &delta, &temp);
        func_0038CF68(&temp,&D_001A4EC0,func_0038CE68_00477190(&edge,&D_001A4EC0));
        vec_sub_ab(&edge, &edge, &temp);
        func_0038CF68(&direction,&edge,1.0f);
        func_0038CE90(&cross,&delta,&direction);
        if(radius<__builtin_fabsf(func_0038CE68_00477190(&cross,&D_001A4EC0))) continue;
        len=func_0038CEA8(&edge);
        projection=func_0038CE68_00477190(&delta,&direction);
        if(len<projection || projection<0.0f) {
            if(func_0038CEA8(&delta)<radius) {
                func_0038CF68(&correction,&delta,radius);
                hit=1;
            } else continue;
        } else {
            hit=1;
            func_0038CF68(&temp,&direction,projection);
            vec_sub_ab(&correction, &delta, &temp);
            func_0038CF68(&correction,&correction,radius);
            vec_add_ba(&correction, &correction, &temp);
        }
        vec_add_ba(&point, &correction, (V_00477190 *)(p+16));
    }
    if(hit) {
        len=height-func_0038CE68_00477190(&point,&D_001A4EC0);
        func_0038CF68(&edge,&D_001A4EC0,len);
        vec_add_ab((V_00477190 *)output, &point, &edge);
    }
    return hit;
}
/* localdecomp:end func_L01_00477190 */

/* localdecomp:start func_L01_00477488 */
#include "vu0.h"
extern int D_L01_0021F6C0[];
s32 func_L01_00477488(s32 index, Vec4 *start, Vec4 *end) {
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038D000(void *, void *, void *);
    Vec4 basis[3];
    Vec4 prev;
    Vec4 current;
    s32 i;
    f32 x;
    f32 one = 1.0f;
    vec_sub_ab(&(basis[0]), end, start);
    basis[0].f[2] = 0;
    func_0038CF68(&basis[0], &basis[0], one / func_0038CEA8(&basis[0]));
    qzero(&basis[1]);
    qzero(&basis[2]);
    basis[1].f[0] = basis[0].f[1];
    basis[1].f[1] = -basis[0].f[0];
    basis[2].f[2] = one;
    vec_sub_ba(&(prev), (Vec4 *)(D_L01_0021F6C0[index] + 16), start);
    func_0038D000(&prev, &prev, basis);
    for (i = 1; i < *(s32 *)D_L01_0021F6C0[index]; i++) {
        vec_sub_ba(&(current), (Vec4 *)(D_L01_0021F6C0[index] + i * 16 + 16), start);
        func_0038D000(&current, &current, basis);
        if (prev.f[3] == 0.0f && current.f[3] == 0.0f) {
            prev.q = current.q;
            continue;
        }
        if (current.f[1] * prev.f[1] < 0.0f) {
            x = ((prev.f[0] - current.f[0]) / (prev.f[1] - current.f[1])) * -current.f[1] + current.f[0];
            if (x > 0.0f && x < one) return 1;
        }
        prev.q = current.q;
    }
    return 0;
}
/* localdecomp:end func_L01_00477488 */

/* localdecomp:start func_L01_00477668 */
#include "vu0.h"
extern int D_L01_0021F6C0[];
s32 func_L01_00477668(s32 index, Vec4 *start, Vec4 *end, Vec4 *out) {
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038CDF8(void *, void *, void *, f32);
    Vec4 basis[3];
    Vec4 prev;
    Vec4 current;
    s32 i;
    s32 hit = 0;
    f32 x;
    f32 one = 1.0f;
    f32 closest;
    vec_sub_ab(&(basis[0]), end, start);
    basis[0].f[2] = 0;
    func_0038CF68(&basis[0], &basis[0], one / func_0038CEA8(&basis[0]));
    qzero(&basis[1]);
    qzero(&basis[2]);
    basis[1].f[0] = basis[0].f[1];
    basis[1].f[1] = -basis[0].f[0];
    basis[2].f[2] = one;
    vec_sub_ba(&(prev), (Vec4 *)(D_L01_0021F6C0[index] + 16), start);
    func_0038D000(&prev, &prev, basis);
    closest = one;
    for (i = 1; i < *(s32 *)D_L01_0021F6C0[index]; i++) {
        vec_sub_ba(&(current), (Vec4 *)(D_L01_0021F6C0[index] + i * 16 + 16), start);
        func_0038D000(&current, &current, basis);
        if (prev.f[3] == 0.0f && current.f[3] == 0.0f) {
            prev.q = current.q;
            continue;
        }
        if (current.f[1] * prev.f[1] < 0.0f) {
            x = ((prev.f[0] - current.f[0]) / (prev.f[1] - current.f[1])) * -current.f[1] + current.f[0];
            if (x > 0.0f && x < closest) {
                closest = x;
                hit = 1;
            }
        }
        prev.q = current.q;
    }
    func_0038CDF8(out, start, end, closest);
    return hit;
}
/* localdecomp:end func_L01_00477668 */

/* localdecomp:start func_L01_00477890 */
#include "vu0.h"
typedef struct { s32 n; s32 pad[3]; vu0_v4 p[1]; } P_477890;
extern void func_0038CF68(void *dst, void *src, f32 s);
void func_L01_00477890(P_477890 *a0, s32 *a1, f32 *a2, vu0_v4 *a3, f32 t, f32 d) {
    vu0_v4 r, s;
    s32 n;
    *a1 = (s32)(t / d);
    n = a0->n - 1;
    if (!(*a1 < n)) {
        *a1 = n;
    } else {
        if (*a1 >= 0) goto body;
        *a1 = 0;
    }
    *a2 = 0.0f;
    *a3 = *(vu0_v4 *)((u8 *)a0->p + (*a1 << 4));
    return;
body:
    *a2 = t - (f32)*a1 * d;
    vec_sub_ba(&s, &a0->p[*a1 + 1], &a0->p[*a1]);
    *a3 = r = s;
    func_0038CF68(a3, a3, *a2);
    vec_add_ab(&s, a3, &a0->p[*a1]);
    *a3 = r = s;
}
/* localdecomp:end func_L01_00477890 */

LINKER_REMNANT("asm/levels", func_L01_00477990);

/* localdecomp:start func_L01_00477998 */
#include "vu0.h"
void func_L01_00477998(s32 *table, s32 wrap, Vec4 *out, Vec4 *angles, s32 flags, f32 frame) {
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    Vec4 a, b, c, tangent, d, e, extra, tmp;
    s32 clamped = 0;
    s32 index = (s32)frame;
    s32 i;
    s32 j, k;
    f32 t;
    if (!wrap && index >= table[0] - 2) {
        index = table[0] - 2;
        clamped = 1;
    }
    t = frame - (f32)index;
    if (clamped && t > 1.0f) t = 1.0f;
    i = index;
    j = i + 1;
    k = i + 2;
    if (k >= table[0]) {
        i %= table[0];
        j %= table[0];
        k %= table[0];
    }
    a.q = ((Vec4 *)(table + 4))[i].q;
    b.q = ((Vec4 *)(table + 4))[j].q;
    func_0038CDF8(out, &a, &b, t);
    if (flags & 1) return;
    if (clamped) {
        vec_sub_ab(&tangent, &b, &a);
    } else {
        if ((flags & 2) && k < j) {
            vec_sub_ba(&tmp, &b, &a);
            c.q = tmp.q;
            extra.q = c.q;
            {
                vu0_q qa, qb, qr;
                __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(c));
                __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(b));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
                __asm__("sqc2 %1, %0" : "=m"(c) : "j"(qr));
                *(vu0_q *)&extra = qr;
            }
        } else c.q = ((Vec4 *)(table + 4))[k].q;
        vec_sub_ba(&d, &b, &a);
        vec_sub_ab(&e, &c, &b);
        func_0038CDF8(&tangent, &d, &e, t);
    }
    angles->f[1] = -func_0038D160(func_0038CED8(&tangent), tangent.f[2]);
    angles->f[2] = func_0038D160(tangent.f[0], tangent.f[1]);
    angles->f[3] = a.f[3] * (1.0f - t) + b.f[3] * t;
}
/* localdecomp:end func_L01_00477998 */

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
extern float func_L01_00477F20(f32 *s, s32 dir, f32 x, f32 pos, f32 limit);

float func_L01_00477ED0(int a0, s32 dir, f32 x, f32 pos, f32 limit)
{
    if (a0 != -1) {
        int v = D_L01_0021F6C0[a0];
        if (v != 0) {
            return func_L01_00477F20((f32 *)v, dir, x, pos, limit);
        }
    }
    return -1.0f;
}
/* localdecomp:end func_L01_00477ED0 */

/* localdecomp:start func_L01_00477F20 */
float func_L01_00477F20(f32 *s, s32 dir, f32 x, f32 pos, f32 limit)
{
    f32 sum = 0.0f;
    f32 frac;
    s32 i;

    if (dir > 0) {
        if (pos < 0.0f) {
            if (0.0f < x) {
                frac = -pos;
                sum += x * frac;
                if (limit <= sum) {
                    return limit;
                }
            }
            i = (s32)pos;
        } else {
            i = (s32)pos;
            if (0.0f < *(f32 *)((u8 *)s + (i << 4) + 0x1C)) {
                frac = pos - (f32)i;
                if (1.0f <= frac) {
                    frac -= 1.0f;
                    i++;
                }
                frac = 1.0f - frac;
                sum += *(f32 *)((u8 *)s + (i << 4) + 0x1C) * frac;
                if (limit <= sum) {
                    return limit;
                }
            }
        }
        while (++i < *(s32 *)s) {
            if (0.0f < s[i * 4 + 7]) {
                sum += s[i * 4 + 7];
                if (limit <= sum) {
                    return limit;
                }
            }
        }
    } else if (pos < 0.0f) {
        if (0.0f < x) {
            frac = -pos;
            sum += x * (1.0f - frac);
            if (limit <= sum) {
                return limit;
            }
        }
    } else {
        i = (s32)pos;
        if (0.0f < *(f32 *)((u8 *)s + (i << 4) + 0x1C)) {
            frac = pos - (f32)i;
            if (1.0f <= frac) {
                frac -= 1.0f;
                i++;
            }
            sum += *(f32 *)((u8 *)s + (i << 4) + 0x1C) * frac;
            if (limit <= sum) {
                return limit;
            }
        }
        while (--i >= 0) {
            if (0.0f < s[i * 4 + 7]) {
                sum += s[i * 4 + 7];
                if (limit <= sum) {
                    return limit;
                }
            }
        }
        if (0.0f < x) {
            sum += x;
            if (limit <= sum) {
                return limit;
            }
        }
    }
    return sum;
}
/* localdecomp:end func_L01_00477F20 */

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
