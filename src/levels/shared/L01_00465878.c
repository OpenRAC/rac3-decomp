#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00465878 */
extern s32 D_L01_001D673C;
extern u32 D_L01_001DFB40;
typedef struct {
    vu0_v4 velocity;
    s32 color_start, color_end;
    s16 duration, emit;
    f32 gravity;
} Vars_00465878;
void func_L01_00465878(u8 *self) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern s32 func_L01_00447470_00465878(s32, s32, f32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_004CAB30(void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_00382498(s32,s32);
    extern void func_L01_00465738(void *,void *,s32,s32,s32,s32,s32,s32,s32,f32);
    Vars_00465878 *s = (Vars_00465878 *)(self+0x20);
    vu0_v4 *pos;
    struct { vu0_v4 copy,gravity,jitter,random; } v;
    f32 length;
    if (func_0038CB00(self+0xA)) {
        func_003CD250(self);
        return;
    }
    pos=(vu0_v4 *)(self+0x10);
    *(f32 *)(self+0xC)=(f32)*(s16 *)(self+0xA)*s->gravity/(f32)s->duration;
    *(s32 *)(self+4)=func_L01_00447470_00465878(s->color_end,s->color_start,(f32)*(s16 *)(self+0xA)/(f32)s->duration);
    vec_add_ab(pos,pos,&s->velocity);
    if (D_L01_001D673C) {
        func_003C5180(pos,&v.gravity,0);
        func_0038CE20(&v.gravity,&v.gravity,s->velocity.w);
        vec_add_ab(&s->velocity,&s->velocity,&v.gravity);
    } else {
        s->velocity.z -= s->velocity.w;
    }
    v.copy=*(vu0_v4 *)(self+0x10);
    if (*(f32 *)(self+0x1C) != 0.0f) {
        if (*(f32 *)(self+0x1C) == 2.0f) func_L01_004CAB30(pos,pos);
        *(f32 *)(self+0x1C)=2.0f;
    }
    if (s->emit && (D_L01_001DFB40 & 1)) {
        *(vu0_q *)&v.random=0;
        v.random.x=func_003824E0(-1.0f,1.0f);
        v.random.y=func_003824E0(-1.0f,1.0f);
        v.random.z=func_003824E0(-1.0f,1.0f);
        v.jitter=v.random;
        length=func_0038CEA8(s);
        func_0038CF68(&v.jitter,&v.jitter,length*func_003824E0(0.15f,0.25f));
        vec_add_ab(&v.jitter,&v.jitter,&s->velocity);
        func_0038CE20(&v.jitter,&v.jitter,func_003824E0(0.75f,0.95f));
        func_L01_00465738(pos,&v.jitter,*(s32 *)(self+4),s->color_end,(func_00382498(15,30)*5+2)/6,0,self[2],self[3],(s32)*(f32 *)(self+0x1C),*(f32 *)(self+0xC));
    } else {
        func_0038CE20(s,s,0.96f);
    }
}
/* localdecomp:end func_L01_00465878 */

/* localdecomp:start func_L01_00465B30 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    s128 v;
    s32 w16;
    s32 w20;
    s16 h24;
    s16 h26;
    f32 f28;
} Sub_00462578;

extern f32 D_L01_001DFB4C;
extern u8 *D_L01_002210D8[];
extern s32 func_00382468(s32);
extern u8 *func_L01_004618E0(s32);
extern u8 func_0013D3E0(void);

u8 *func_L01_00465B30(s128 *a0, s128 *a1, s32 a2, s32 a3, s32 t0, s32 t1, f32 f12) {
    u8 *o;
    Sub_00462578 *e;
    u8 *p;

    if (t0 == 0) {
        return 0;
    }
    {
        if (0.9f < D_L01_001DFB4C) {
            if (func_00382468(3) == 0) {
                return 0;
            }
        }
        if (0.95f < D_L01_001DFB4C) {
            if (func_00382468(2) == 0) {
                return 0;
            }
        }
        if (1.0f < D_L01_001DFB4C) {
            if (func_00382468(1) == 0) {
                return 0;
            }
        }
    }
    o = func_L01_004618E0(16);
    if (o != 0) {
        *(s128 *)(o + 16) = *a0;
        *(s32 *)(o + 4) = a2;
        o[1] = 0;
        *(f32 *)(o + 12) = f12;
        o[9] = 68;
        o[3] = 68;
        o[8] = func_0013D3E0();
        p = D_L01_002210D8[0] + t1;
        if (t1 == 3) {
            p = D_L01_002210D8[0];
        }
        e = (Sub_00462578 *)(o + 32);
        o[2] = *p;
        *(s16 *)(o + 10) = t0;
        e->h24 = t0;
        e->f28 = f12;
        e->w16 = a2;
        e->w20 = a3;
        e->h26 = t1;
        e->v = *a1;
        ((f32 *)e)[3] = ((f32 *)a0)[2] - 0.5f;
    }
    return o;
}
/* localdecomp:end func_L01_00465B30 */

INCLUDE_ASM("asm/levels", func_L01_00465CD0);

/* localdecomp:start func_L01_00465F88 */
void func_L01_00465F88(void) {

}
/* localdecomp:end func_L01_00465F88 */

/* localdecomp:start func_L01_00465F90 */
extern s32 func_0038CB00(u8 *);
extern void func_003CD250(u8 *);

void func_L01_00465F90(u8 *o)
{
    f32 *p = (f32 *)(o + 32);
    f32 f;
    f32 y;

    f = p[1] + p[3] * 0.0156000007f;
    p[1] = f;
    if (f <= 0.0f || func_0038CB00(o + 10) != 0) {
        func_003CD250(o);
    } else {
        f = p[1];
        if (0.22f <= f) {
            y = p[3];
            y = -y;
            p[3] = y;
            p[1] = f + y * 0.0156000007f;
        }
        *(f32 *)(o + 12) = *(f32 *)(o + 12) + 9828.0f;
        *(u32 *)(o + 4) = (*(u32 *)(o + 4) & 0xFFFFFFu) | ((s32)(p[1] * 255.0f) << 24);
        p[2] = p[2] + 0.0144000009f;
        if (p[2] > 1.0f)
            p[2] = p[2] - 1.0f;
        *(u8 *)(o + 8) = (u8)(p[2] * 255.0f);
        *(f32 *)(o + 24) = *(f32 *)(o + 24) - 0.02f;
    }
}
/* localdecomp:end func_L01_00465F90 */

/* localdecomp:start func_L01_004660F8 */
#include "vu0.h"
extern u8 *D_L01_002210E4[];
u8 *func_L01_004660F8(vu0_q *pos, vu0_q *end) {
    extern u8 *func_L01_004618E0(s32);
    extern s32 func_00382468(s32);
    u8 *p = func_L01_004618E0(19);
    if (p != 0) {
        u32 color = ((func_00382468(6) * 6) + 64) | 0x78404000;
        p[9] = 0x22;
        p[3] = 0x48;
        p[1] = 3;
        *(u32 *)(p + 4) = color;
        *(u32 *)(p + 12) = color;
        p[2] = *D_L01_002210E4[0];
        *(vu0_q *)(p + 16) = *pos;
        *(vu0_q *)(p + 48) = *end;
        vec_sub_ba(p + 32, pos, p + 48);
        vec_sub_ab(p + 32, p + 32, p + 48);
        *(f32 *)(p + 60) = 6.0f;
        *(f32 *)(p + 28) = 0.09f;
        *(f32 *)(p + 44) = 0.5f;
    }
    return p;
}
/* localdecomp:end func_L01_004660F8 */

/* localdecomp:start func_L01_004661F0 */
extern void func_L01_004CAB30(void *, void *);
extern void func_003CD250(u8 *);

void func_L01_004661F0(u8 *self) {
    u8 *pos = self + 0x10;
    u8 *rot = self + 0x20;
    u8 *vel = self + 0x30;
    s32 v;

    vec_add_ba(pos, pos, vel);
    vec_add_ba(rot, rot, vel);
    func_L01_004CAB30(pos, pos);
    func_L01_004CAB30(rot, rot);
    v = *(s32 *)(self + 4) - ((s32)*(f32 *)(vel + 0xC) << 24);
    *(s32 *)(self + 4) = v;
    *(s32 *)(self + 0xC) = v;
    if (v < 0) {
        func_003CD250(self);
    }
}
/* localdecomp:end func_L01_004661F0 */

/* localdecomp:start func_L01_00466290 */
#include "vu0.h"
void func_L01_00466290(u8 *self)
{
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D098(f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003C2F58(void *, s32, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_L01_00448EC0(void *, void *, void *, s32);
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    vu0_v4 target, local, delta;
    vu0_q matrix[4];
    u8 *state = self + 0x20;
    f32 f;
    if (*(f32 *)(state + 0x10) != 0.0f) {
        u8 *source = *(u8 **)state;
        u8 *position = self + 0x10;
        matrix[0] = *(vu0_q *)source;
        matrix[1] = *(vu0_q *)(source + 0x10);
        matrix[2] = *(vu0_q *)(source + 0x20);
        local.y = func_0038D0B0(*(f32 *)(state + 0x14)) * *(f32 *)(state + 0x10);
        local.z = func_0038D098(*(f32 *)(state + 0x14)) * *(f32 *)(state + 0x10);
        local.x = 0.0f;
        local.w = 0.0f;
        func_0038D028(&delta, &local, matrix);
        vec_sub_ba(position, position, &delta);
        *(f32 *)(state + 0x1C) += 0.07201200723648071f;
        func_003C2F58(*(void **)(state + 0x18), 0, &target);
        vec_sub_ab(&local, &target, position);
        func_0038CF68(&local, &local, *(f32 *)(state + 0x1C));
        vec_add_ba(position, position, &local);
        *(f32 *)(state + 0x14) = func_0038DAB8(*(f32 *)(state + 0x14), 0.6283185482025146f);
        *(f32 *)(state + 0x10) *= 0.88f;
        local.y = func_0038D0B0(*(f32 *)(state + 0x14)) * *(f32 *)(state + 0x10);
        local.z = func_0038D098(*(f32 *)(state + 0x14)) * *(f32 *)(state + 0x10);
        local.x = 0.0f;
        local.w = 0.0f;
        func_0038D028(&delta, &local, matrix);
        vec_add_ab(position, position, &delta);
        if (func_L01_00448EC0(&target, *(u8 **)(state + 0x18) + 0xC0, position, 1) > 0.0f) {
            func_003CD250(self);
            return;
        }
    }
    *(f32 *)(state + 4) += *(f32 *)(state + 0xC) * 0.013200000859797f;
    if (*(f32 *)(state + 4) <= 0.0f || func_0038CB00(self + 0xA)) {
        func_003CD250(self);
    } else {
        f = *(f32 *)(state + 4);
        if (f >= 1.0f) {
            f32 step = -*(f32 *)(state + 0xC);
            *(f32 *)(state + 0xC) = step;
            *(f32 *)(state + 4) = f + step * 0.013200000859797f;
        }
        *(f32 *)(self + 0xC) += -3528.000244140625f;
        *(u32 *)(self + 4) = (*(u32 *)(self + 4) & 0xFFFFFF) | ((s32)(*(f32 *)(state + 4) * 255.0f) << 24);
        *(f32 *)(state + 8) += 0.007200000341981649f;
        if (*(f32 *)(state + 8) > 1.0f) *(f32 *)(state + 8) -= 1.0f;
        self[8] = (s32)(*(f32 *)(state + 8) * 255.0f);
    }
}
/* localdecomp:end func_L01_00466290 */

/* localdecomp:start func_L01_00466588 */
extern u8 *func_L01_004618E0(s32);
typedef int s128_00462FD0 __attribute__((mode(TI)));
typedef struct {
    s128_00462FD0 v;
    s32 f10;
    s32 f14;
    s16 f18;
    s16 f1A;
    f32 f1C;
} Sub_00462FD0;
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
    s128_00462FD0 f10;
    Sub_00462FD0 sub;
} Part_00462FD0;
extern u8 *D_L01_002210EC[];
extern u8 func_0013D3E0(void);
Part_00462FD0 *func_L01_00466588(s128_00462FD0 *pos, s128_00462FD0 *v2, s32 a2, s32 a3, s32 t0, s32 t1, f32 f) {
    Part_00462FD0 *p;
    Sub_00462FD0 *q;
    if (t0 == 0) {
        return 0;
    }
    p = ((Part_00462FD0 * (*)(s32))func_L01_004618E0)(21);
    if (p != 0) {
        p->f10 = *pos;
        p->f4 = a2;
        p->f1 = 0;
        p->fC = f;
        p->f9 = 164;
        p->f3 = 72;
        p->f8 = func_0013D3E0();
        p->f2 = *D_L01_002210EC[0];
        q = &p->sub;
        p->fA = t0;
        q->f18 = t0;
        q->f1C = f;
        q->f10 = a2;
        q->f14 = a3;
        q->f1A = t1;
        q->v = *v2;
    }
    return p;
}
/* localdecomp:end func_L01_00466588 */

/* localdecomp:start func_L01_00466678 */
#include "vu0.h"
extern u32 D_L01_001DFB40;
void func_L01_00466678(u8 *p) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern s32 func_L01_00447470_00466678(s32, s32, f32);
    extern f32 func_003824E0(f32 low, f32 high);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern Part_00462FD0 *func_L01_00466588(s128_00462FD0 *, s128_00462FD0 *, s32, s32, s32, s32, f32);
    vu0_v4 old;
    vu0_v4 velocity;
    vu0_v4 random;
    u8 *v = p + 0x20;
    f32 ratio;
    if (func_0038CB00(p + 0xA)) {
        func_003CD250(p);
        return;
    }
    ratio = 1.0f / *(s16 *)(v + 0x18);
    *(f32 *)(p + 0xC) = *(s16 *)(p + 0xA) * *(f32 *)(v + 0x1C) * ratio;
    *(s32 *)(p + 4) = func_L01_00447470_00466678(*(s32 *)(v + 0x14), *(s32 *)(v + 0x10), *(s16 *)(p + 0xA) * ratio);
    vec_add_ab(p + 0x10, p + 0x10, v);
    *(f32 *)(v + 8) -= 0.001440000138245523f;
    old = *(vu0_v4 *)(p + 0x10);
    if (*(s16 *)(v + 0x1A) && (D_L01_001DFB40 & 1)) {
        f32 speed;
        *(vu0_q *)&random = 0;
        random.x = func_003824E0(-1.0f, 1.0f);
        random.y = func_003824E0(-1.0f, 1.0f);
        random.z = func_003824E0(-1.0f, 1.0f);
        velocity = random;
        speed = func_0038CEA8(v);
        func_0038CF68(&velocity, &velocity, speed * func_003824E0(0.21f, 0.25f));
        vec_add_ab(&velocity, &velocity, v);
        func_0038CE20(&velocity, &velocity, func_003824E0(0.75f, 0.95f));
        func_L01_00466588((s128_00462FD0 *)(p + 0x10), (s128_00462FD0 *)&velocity, *(s32 *)(p + 4), *(s32 *)(v + 0x14), (func_00382498(15,20) * 5 + 2) / 6, 0, *(f32 *)(p + 0xC));
    } else {
        func_0038CE20(v, v, 0.96f);
    }
}
/* localdecomp:end func_L01_00466678 */

/* localdecomp:start func_L01_004668A0 */
typedef int Q_004668A0 __attribute__((mode(TI)));
typedef struct { Q_004668A0 vel; s32 color, value; s16 life, pad; f32 delta; } Vars_004668A0;
extern u8 *D_L01_002210F0[];
void func_L01_004668A0(Q_004668A0 *pos, Q_004668A0 *vel, s32 color, s32 value, s32 life, f32 size) {
    extern u8 *func_L01_004618E0(s32);
    extern u8 func_0013D3E0(void);
    u8 *p = func_L01_004618E0(0x16);
    Vars_004668A0 *v;
    if (p != 0) {
        *(s32 *)(p + 4) = color;
        p[1] = 0;
        p[9] = 0x74;
        p[3] = 0x44;
        *(f32 *)(p + 0xC) = size * 0.2f;
        p[8] = func_0013D3E0();
        p[2] = *D_L01_002210F0[0];
        v = (Vars_004668A0 *)(p + 0x20);
        *(s16 *)(p + 0xA) = life;
        v->life = life;
        v->delta = (size - *(f32 *)(p + 0xC)) / life;
        v->color = color;
        v->value = value;
        *(Q_004668A0 *)(p + 0x20) = *vel;
        *(Q_004668A0 *)(p + 0x10) = *pos;
        ((f32 *)&v->vel)[3] = 0.0004960000514984131f;
    }
}
/* localdecomp:end func_L01_004668A0 */

/* localdecomp:start func_L01_004669B0 */
typedef int Quad_4669B0 __attribute__((mode(TI)));
typedef struct {
    u32 rgba;                      /* 0x20: the colour it fades from */
    s32 pad_24;                    /* 0x24 */
    s16 spin_rate;                 /* 0x28: turn a frame, random sign */
    u8 pad_2A[2];
    f32 grow;                      /* 0x2C: size factor a frame */
    Quad_4669B0 drift;             /* 0x30: w is 25.0 */
} Cloud_4669B0;
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
    f32 x;                         /* 0x10: the position */
    f32 y;                         /* 0x14 */
    f32 z;                         /* 0x18 */
    f32 fade_start;                /* 0x1C */
    Cloud_4669B0 cloud;            /* 0x20 */
} Smoke_4669B0;

extern u8 *D_L01_002210F4[];
extern u8 *func_L01_004618E0(s32);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);

/* particle_spawn_smoke: a type 0x17 particle, the dark smoke: it appears at position jittered by up
 * to jitter, grows by a factor from grow_min to grow_max a frame and fades in before it fades out. */
Smoke_4669B0 *func_L01_004669B0(Quad_4669B0 *position, s32 spin_rate, Quad_4669B0 *drift, u32 rgba, s32 fade_start,
                                f32 jitter, f32 grow_min, f32 grow_max, f32 size) {
    Smoke_4669B0 *p = (Smoke_4669B0 *)func_L01_004618E0(0x17);
    Cloud_4669B0 *cloud;

    if (p != 0) {
        *(Quad_4669B0 *)&p->x = *position;
        p->flags = 0;
        p->render2 = 0x74;
        p->render = 0x48;
        p->rgba = rgba | 0x20000000;
        cloud = &p->cloud;
        p->size = size;
        p->spin = 0;
        p->texture = *D_L01_002210F4[0];
        p->x += func_L01_00443A18(0.0f, jitter);
        p->y += func_L01_00443A18(0.0f, jitter);
        p->z += func_L01_00443A18(0.0f, jitter);
        p->fade_start = fade_start;
        p->life = 8;
        cloud->pad_24 = 0;
        cloud->rgba = rgba;
        if (func_00382468(2) != 0) cloud->spin_rate = spin_rate * 1.2f;
        else cloud->spin_rate = -spin_rate * 1.2f;
        cloud->grow = func_003824E0(grow_min, grow_max);
        cloud->drift = *drift;
        ((f32 *)&cloud->drift)[3] = 25.0f;
    }
    return p;
}
/* localdecomp:end func_L01_004669B0 */

/* localdecomp:start func_L01_00466B78 */
#include "vu0.h"
void func_L01_00466B78(u8 *self) {
 extern void func_L01_004CAB30(void *,void *);
 extern s32 func_0038CB00(u8 *);
 extern void func_003CD250(u8 *);
 u8 *s=self+0x20;
 f32 blend;
 s32 elapsed;
 self[8]+=s[8];
 vec_add_ab(self+0x10,self+0x10,self+0x30);
 if(*(f32 *)(self+0x1c)!=0.0f) {
  if(*(f32 *)(self+0x1c)==2.0f) func_L01_004CAB30(self+0x10,self+0x10);
  *(f32 *)(self+0x1c)=2.0f;
 }
 *(f32 *)(self+0xc)*=(*(f32 *)(s+0xc)-1.0f)*1.2f+1.0f;
 if(*(s32 *)(s+4)==0) {
  if(func_0038CB00(self+0xa)) {
   *(s32 *)(s+4)=1;
   *(s16 *)(self+0xa)=17;
   *(s32 *)(self+4)=*(s32 *)s|0x7f000000;
  } else {
   *(s32 *)(self+4)=(((s32)((8-*(s16 *)(self+0xa))*12.0f)+32)<<24)|*(s32 *)s;
  }
 } else if(*(s32 *)(s+4)==2) {
  if(func_0038CB00(self+0xa)) {
   func_003CD250(self);
  } else {
   *(s32 *)(self+4)=((s32)(s[10]*((f32)*(s16 *)(self+0xa)/s[11])+0.0f)<<24)|(*(s32 *)s&0xffffff);
  }
 } else if(*(s32 *)(s+4)==3) {
  func_0038CB00(self+0xa);
  elapsed=s[11]-*(s16 *)(self+0xa);
  blend=(f32)elapsed / *(f32 *)(s+0x1c);
  if(blend>1.0f) blend=1.0f;
  *(s32 *)(self+4)=((s32)(s[10]*blend+0.0f)<<24)|(*(s32 *)s&0xffffff);
  if(s[11]-*(s16 *)(self+0xa)>=(s32)*(f32 *)(s+0x1c)) {
   s[11]-=(s32)*(f32 *)(s+0x1c);
   *(s32 *)(s+4)=2;
  }
 } else {
  if(func_0038CB00(self+0xa)) {
   func_003CD250(self);
  } else {
   *(s32 *)(self+4)=((s32)(*(s16 *)(self+0xa)*7.470588207244873f)<<24)|*(s32 *)s;
  }
 }
}
/* localdecomp:end func_L01_00466B78 */

LINKER_REMNANT("asm/levels", func_L01_00466E38);

/* localdecomp:start func_L01_00466E40 */
typedef int Q_00466E40 __attribute__((mode(TI)));
void func_L01_00466E40(u8 *self) {
    extern void func_003CD250(u8 *);
    u8 *source;
    f32 *p;
    if (self != 0) {
        source = *(u8 **)(self + 0x20);
        p = (f32 *)(self + 0x20);
        if (source == 0 || (source[1] & 0x80)) {
            func_003CD250(self);
        } else {
            *(Q_00466E40 *)(self + 0x10) = *(Q_00466E40 *)(source + 0x10);
            self[8] = source[8];
            *(f32 *)(self + 0xC) = *(f32 *)(source + 0xC) * p[1] + p[2];
            p[3] += p[5];
            if (p[3] < 0.0f) {
                p[3] = 0.0f;
            } else {
                if (p[3] > 1.0f) p[3] = 1.0f;
                *(u32 *)(self + 4) = (*(u32 *)(self + 4) & 0xFFFFFF) |
                    ((s32)(((*(u8 **)(self + 0x20))[7] * (p[4] * 0.00390625f) + p[3]) * 256.0f) << 24);
            }
        }
    }
}
/* localdecomp:end func_L01_00466E40 */

/* localdecomp:start func_L01_00466F50 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_466F50;
typedef struct {
    Vec_466F50 velocity;           /* 0x20: w is the gravity (0: 22.7 u/s^2) */
    f32 red_fade;                  /* 0x30: 1 white to yellow to red, -1 to green */
    f32 green_fade;                /* 0x34 */
    f32 blue_fade;                 /* 0x38 */
    f32 alpha;                     /* 0x3C */
} Spark_466F50;
typedef struct {
    u8 type;                       /* 0x00 */
    s8 flags;                      /* 0x01 */
    u8 texture;                    /* 0x02 */
    u8 render;                     /* 0x03 */
    u32 rgba;                      /* 0x04 */
    u8 spin;                       /* 0x08 */
    u8 render2;                    /* 0x09 */
    s16 life;                      /* 0x0A */
    f32 size;                      /* 0x0C: world units x 210000 */
    Vec_466F50 position;           /* 0x10 */
    Spark_466F50 spark;            /* 0x20 */
} Particle_466F50;

extern u8 *D_L01_002210FC[];
extern u8 *func_L01_004618E0(s32);
extern u32 func_L01_00448CC0(f32 r, f32 g, f32 b, f32 a);
extern f32 func_003824E0(f32 low, f32 high);

/* particle_spawn_spark: a type 0x19 particle, a drop or spark at position moving at velocity
 * that falls by gravity, shrinks and stops where it meets the world: white at alpha 0.6 going
 * to red, or to green if green is set; a negative size is a random 5000-30000. */
void func_L01_00466F50(Vec_466F50 *position, Vec_466F50 *velocity, s32 green, f32 size, f32 gravity) {
    Particle_466F50 *p = (Particle_466F50 *)func_L01_004618E0(0x19);

    if (p != 0) {
        Spark_466F50 *spark;

        p->position = *position;
        spark = &p->spark;
        if (!green) {
            p->rgba = func_L01_00448CC0(1.0f, 1.0f, 1.0f, 0.6f);
            spark->red_fade = 1.0f;
            spark->green_fade = 1.0f;
            spark->blue_fade = 1.0f;
        } else {
            p->rgba = func_L01_00448CC0(1.0f, 1.0f, 1.0f, 0.6f);
            spark->red_fade = -1.0f;
            spark->green_fade = -1.0f;
            spark->blue_fade = -1.0f;
        }
        p->render2 = 0x44;
        p->render = 0x48;
        p->flags = 0;
        if (size < 0.0f) p->size = func_003824E0(5000.0f, 30000.0f);
        else p->size = size;
        p->spin = 0;
        p->texture = *D_L01_002210FC[0];
        spark->alpha = 0.6f;
        p->life = 0x43;
        spark->velocity = *velocity;
        spark->velocity.w = gravity;
    }
}
/* localdecomp:end func_L01_00466F50 */

INCLUDE_ASM("asm/levels", func_L01_004670C8);

LINKER_REMNANT("asm/levels", func_L01_004674D0);

/* localdecomp:start func_L01_004674D8 */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
void func_L01_004674D8(u8 *p) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern s32 func_00382498(s32, s32);
    extern void func_003C2F58(void *, s32, void *);
    extern void func_0038CF68(void *, void *, f32);
    u8 *v;
    vu0_v4 pos, delta;
    if (p) {
        v = p+0x20;
        if (func_0038CB00(p+0x24) || !*(u8 **)(p+0x20) || *(s8 *)(*(u8 **)(p+0x20)+0x20)<0) {
            func_003CD250(p);
            return;
        }
        if (*(s16 *)(v+4) < *(s32 *)(v+8)/5) {
            *(u32 *)(p+4) = (*(u32 *)(p+4)&0xFFFFFF) + ((*(s32 *)(v+12) * *(s16 *)(v+4) / (*(s32 *)(v+8)/3)) << 24);
        }
        p[8] = func_00382498(0,255);
        if (*(s16 *)(v+6) == -1) {
            *(vu0_q *)(p+0x10) = *(vu0_q *)(*(u8 **)(p+0x20)+0x10);
        } else {
            func_003C2F58(*(u8 **)(p+0x20),*(s16 *)(v+6),&pos);
            vec_sub_ba(&delta,&D_L01_001E29C0,&pos);
            func_0038CF68(&delta,&delta,0.4f);
            vec_add_ab(p+0x10,&pos,&delta);
        }
    }
}
/* localdecomp:end func_L01_004674D8 */

/* localdecomp:start func_L01_00467608 */
extern s32 func_0038CAD0(void *);
extern void func_003CD250(u8 *);

void func_L01_00467608(u8 *a0) {
    u8 *q = a0 + 0x20;
    s32 n;
    vec_add_ab(a0 + 0x10, a0 + 0x10, q);
    n = *(s32 *)(q + 0x18) * *(s32 *)(q + 0x10) / *(s32 *)(q + 0x14);
    *(u32 *)(a0 + 4) = (*(u32 *)(a0 + 4) & 0xFFFFFF) + (n << 24);
    if (func_0038CAD0(a0 + 0x30) != 0) {
        func_003CD250(a0);
    }
}
/* localdecomp:end func_L01_00467608 */

/* localdecomp:start func_L01_00467688 */
#include "vu0.h"
extern u8 *D_L01_00221108[];
void func_L01_00467688(void *position, void *orientation, f32 spread) {
    extern u8 *func_L01_004618E0(s32);
    extern f32 func_003824E0(f32, f32);
    extern u8 func_0013D3E0(void);
    extern void func_0038D570(void *, void *);
    extern void func_0038D028(void *, void *, void *);
    extern void func_0038D000(void *, void *, void *);
    vu0_v4 transformed, delta, velocity;
    vu0_v4 matrix[4];
    u8 *particle = func_L01_004618E0(0x1C);
    u8 *state;
    s32 r, g, b;
    if (particle) {
        f32 low = -0.03f;
        state = particle + 0x20;
        delta.x = func_003824E0(low, 0.03f);
        delta.y = func_003824E0(low, 0.03f);
        delta.z = 0;
        if (orientation) {
            func_0038D570(matrix, orientation);
            func_0038D028(&transformed, &delta, matrix);
            vec_add_ba(particle + 0x10, &transformed, position);
        } else {
            vec_add_ba(particle + 0x10, &delta, position);
        }
        *(f32 *)(particle + 0x18) -= 0.05f;
        /* The divisor sign does not change the remainder. */
        r = (s32)func_0013D3E0() % -96;
        if (!r) r = 1;
        g = ((s32)func_0013D3E0() % r) % 64;
        if (!g) g = 1;
        b = ((s32)func_0013D3E0() % g) % 48;
        *(s32 *)(particle + 4) = (r + 143) | ((g + 143) << 8) | ((b + 111) << 16);
        particle[9] = 0x44;
        particle[3] = 0x48;
        particle[1] = 0;
        particle[8] = 0;
        particle[2] = *D_L01_00221108[0];
        *(f32 *)(state + 4) = func_003824E0(0.0f, 0.0223456006f) + 0.00001f;
        *(f32 *)(particle + 0xC) = func_003824E0(10080.0f, 19950.0f);
        *(f32 *)(state + 8) = 0;
        *(s16 *)(particle + 0xA) = 210;
        *(f32 *)(state + 0xC) = 1.0f;
        qzero(&velocity);
        if (orientation) {
            velocity.x = spread;
            velocity.z = -0.0025f;
            func_0038D000(state + 0x10, &velocity, orientation);
        } else {
            *(f32 *)(state + 0x10) = func_003824E0(-spread, spread);
            *(f32 *)(state + 0x14) = func_003824E0(-spread, spread);
            *(f32 *)(state + 0x18) = -0.0025f;
        }
    }
}
/* localdecomp:end func_L01_00467688 */

/* localdecomp:start func_L01_00467910 */
#include "vu0.h"
void func_L01_00467910(u8 *self) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    f32 *p = (f32 *)(self + 0x20);
    if (p[3] > 0.0f) {
        p[1] += p[3] * 0.008400000631809235f;
    } else if (p[1] > 0.03f) {
        p[1] += p[3] * 0.008400000631809235f;
    } else {
        p[1] += p[3] * 0.008400000631809235f * 0.2f;
        *(f32 *)(self + 0xC) += 6552.00048828125f;
    }
    if (p[1] <= 0.024399999529123306f || func_0038CB00(self + 0xA)) {
        func_003CD250(self);
    } else {
        if (p[1] >= 0.12f) {
            p[3] = -p[3];
            p[1] += p[3] * 0.008400000631809235f;
        }
        *(f32 *)(self + 0xC) += 6552.00048828125f;
        *(u32 *)(self + 4) = (*(u32 *)(self + 4) & 0xFFFFFFu) | ((s32)(p[1] * 255.0f) << 24);
        p[2] += 0.002400000113993883f;
        if (p[2] > 1.0f) p[2] -= 1.0f;
        self[8] = (s32)(p[2] * 255.0f);
        vec_add_ba(self + 0x10, self + 0x10, p + 4);
    }
}
/* localdecomp:end func_L01_00467910 */

INCLUDE_ASM("asm/levels", func_L01_00467B20);

LINKER_REMNANT("asm/levels", func_L01_00467DC0);

/* localdecomp:start func_L01_00467DC8 */
#include "vu0.h"
typedef struct {
    vu0_v4 velocity;
    u8 *anchor, *next;
    s16 a18, a1A, collision, flags;
} Chain_00467DC8;
extern vu0_v4 D_L01_001E29C0;
extern vu0_v4 D_L01_001EAA30, D_L01_001EAA40;
void func_L01_00467DC8(u8 *self) {
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038CE20(void *,void *,f32);
    extern f32 func_0038CEA8(void *);
    extern s32 func_L01_003FB640(void *,s32,s32,f32);
    extern void func_L01_0040E790(void *,void *,void *);
    extern void func_003CD250(u8 *);
    extern void func_0038D028(void *,void *,void *);
    extern f32 func_0038D160(f32,f32);
    vu0_v4 position, delta, sum;
    Chain_00467DC8 *state = (Chain_00467DC8 *)(self + 0x20);
    Chain_00467DC8 *prior;
    u8 *p;
    f32 distance, damping, gain, angle;
    s32 alpha;
    if (state->flags != 255) {
        if (((*(u8 *)&state->flags ^ 1) & 1)) {
            prior = 0;
            p = state->next;
            qzero(&sum);
            distance = 2.0f;
            damping = 0.15f;
            if (p) prior = (Chain_00467DC8 *)(p + 0x20);
            if (!state->collision) {
                while (p && !(*(unsigned long *)((u8 *)prior + 0x18) & 0x1FFFF00000000UL)) {
                    vec_sub_ab(&position,p + 0x10,self + 0x10);
                    func_0038CF68(&position,&position,0.2f / (distance * distance));
                    distance += 1.0f;
                    damping *= 0.9990000128746033f;
                    vec_add_ab(&sum,&sum,&position);
                    p = prior->next;
                    if (p) prior = (Chain_00467DC8 *)(p + 0x20);
                }
            }
            damping = (0.15f - damping) + 1.0700000524520874f;
            if (!prior || !prior->collision) vec_add_ab(state,state,&sum);
            else func_0038CE20(state,state,0.5f);
            if (state->next) func_0038CE20(state,state,damping);
            else func_0038CE20(state,state,0.9700000286102295f);
            state->velocity.z -= 0.028800001367926598f;
            vec_add_ab(&position,self + 0x10,state);
        } else {
            *(vu0_q *)&position = *(vu0_q *)(self + 0x10);
        }
        if (state->anchor) {
            vec_sub_ba(&sum,&position,state->anchor + 0x10);
            if (fabs_asm(func_0038CEA8(&sum) - 0.15f) > 0.1f) {
                func_0038CF68(&sum,&sum,0.15f);
                vec_add_ab(&position,&sum,state->anchor + 0x10);
            }
            if (func_L01_003FB640(&position,0,0,0.15f)) {
                if (!state->collision) *(vu0_q *)&position = *(vu0_q *)&D_L01_001EAA30;
                else *(vu0_q *)&position = *(vu0_q *)(self + 0x10);
                state->collision = 1;
            } else state->collision = 0;
            if (state->collision) {
                func_L01_0040E790(state,state,&D_L01_001EAA40);
                func_0038CE20(state,state,0.95f);
            } else {
                vec_sub_ba(&delta,&position,self + 0x10);
                vec_add_ab(state,state,&delta);
                func_0038CE20(state,state,0.5f);
            }
            vec_sub_ba(&delta,&position,self + 0x10);
            vec_add_ab(state,state,&delta);
            func_0038CE20(state,state,0.5f);
        }
        *(vu0_q *)(self + 0x10) = *(vu0_q *)&position;
        if (state->flags & 2) {
            alpha = (*(u32 *)(self + 4) >> 24) - 2;
            if (alpha > 0) *(u32 *)(self + 4) = (*(u32 *)(self + 4) & 0xFFFFFF) | (alpha << 24);
            else if (!state->next) {
                if (state->anchor) *(s32 *)(state->anchor + 0x34) = 0;
                func_003CD250(self);
                return;
            }
        }
    }
    if (state->anchor) {
        vec_sub_ab(&position,state->anchor + 0x10,&D_L01_001E29C0);
        func_0038D028(&position,&position,(u8 *)&D_L01_001E29C0 - 0x80);
        func_0038CE20(&position,&position,1.0f / position.w);
        vec_sub_ba(&delta,self + 0x10,&D_L01_001E29C0);
        func_0038D028(&delta,&delta,(u8 *)&D_L01_001E29C0 - 0x80);
        func_0038CE20(&delta,&delta,1.0f / delta.w);
        vec_sub_ab(&position,&position,&delta);
        angle = func_0038D160(position.x,position.y);
        self[8] = (s32)(angle * 128.0f / 3.1415927410125732f) - 32;
    }
}
/* localdecomp:end func_L01_00467DC8 */

LINKER_REMNANT("asm/levels", func_L01_004682B0);

/* localdecomp:start func_L01_004682B8 */
#include "vu0.h"
__asm__(".extern D_L01_001D7F14, 4");
__asm__(".extern D_L01_001D7F18, 4");
extern f32 D_L01_001D7F14 __attribute__((section(".sdata")));
extern f32 D_L01_001D7F18 __attribute__((section(".sdata")));
void func_L01_004682B8(u8 *self) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CF00(void *, void *);
    vu0_v4 v[2], temp;
    u8 *pos, *old;
    if (!*(u8 **)(self+0x30) || (*(u8 **)(self+0x30))[0x20] == 254 || (*(u8 **)(self+0x30))[0x20] == 253 || func_0038CB00(self+0xA)) {
        func_003CD250(self);
        return;
    }
    vec_sub_ba(&temp, *(u8 **)(self+0x30)+0x10, self+0x10);
    pos=self+0x10;
    old=self+0x20;
    v[0]=v[1]=temp;
    func_0038CE20(v,v,(D_L01_001D7F14-1.0f)*1.2f+1.0f);
    vec_add_ab(&temp,v,*(u8 **)(self+0x30)+0x10);
    *(vu0_v4 *)(self+0x10)=v[1]=temp;
    vec_sub_ba(&temp,*(u8 **)(self+0x30)+0x10,self+0x20);
    v[0]=v[1]=temp;
    func_0038CE20(v,v,(D_L01_001D7F18-1.0f)*1.2f+1.0f);
    vec_add_ab(&temp,v,*(u8 **)(self+0x30)+0x10);
    *(vu0_v4 *)(self+0x20)=v[1]=temp;
    if (func_0038CF00(pos,old)<0.1f || func_0038CF00(pos,*(u8 **)(self+0x30)+0x10)<1.0f) func_003CD250(self);
}
/* localdecomp:end func_L01_004682B8 */

LINKER_REMNANT("asm/levels", func_L01_00468460);

/* localdecomp:start func_L01_00468468 */
typedef int Q_00468468 __attribute__((mode(TI)));

void func_L01_00468468(void *arg0) {
    extern void func_003CD250(u8 *);
    extern u32 func_L01_00448CC0(f32 r, f32 g, f32 b, f32 a);
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f1;
    f32 temp_f3;
    void *temp_16;
    void *temp_4;

    if (arg0 != 0) {
        temp_4 = (*(void **)((u8 *)(arg0) + (0x20)));
        temp_16 = arg0 + 0x20;
        if ((temp_4 == 0) || (((*(u8 *)((u8 *)(temp_4) + (0x20))) & 0xF0) == 0xF0) || ((*(Q_00468468 *)((u8 *)(arg0) + (0x10))) = (Q_00468468) (*(Q_00468468 *)((u8 *)(temp_4) + (0x10))), temp_f3 = (*(f32 *)((u8 *)(temp_16) + (8))), temp_f1 = (*(f32 *)((u8 *)(temp_16) + (4))) + temp_f3, (*(f32 *)((u8 *)(temp_16) + (4))) = temp_f1, (temp_f1 < 0.0f))) {
            func_003CD250(arg0);
            return;
        }
        if (temp_f1 > 0.6f) {
            temp_f0 = -temp_f3;
            (*(f32 *)((u8 *)(temp_16) + (8))) = temp_f0;
            (*(f32 *)((u8 *)(temp_16) + (4))) = (f32) (temp_f1 + temp_f0);
        }
        temp_f0_2 = (*(f32 *)((u8 *)(temp_16) + (0x10))) + -0.02088f;
        (*(f32 *)((u8 *)(temp_16) + (0x10))) = temp_f0_2;
        if (temp_f0_2 < 0.0f) {
            (*(f32 *)((u8 *)(temp_16) + (0x10))) = 0.0f;
        }
        temp_f0_3 = (*(f32 *)((u8 *)(temp_16) + (0x14))) + -0.017352002f;
        (*(f32 *)((u8 *)(temp_16) + (0x14))) = temp_f0_3;
        if (temp_f0_3 < 0.0f) {
            (*(f32 *)((u8 *)(temp_16) + (0x14))) = 0.0f;
        }
        temp_f0_4 = (*(f32 *)((u8 *)(temp_16) + (0x18))) + -0.0018000001f;
        (*(f32 *)((u8 *)(temp_16) + (0x18))) = temp_f0_4;
        if (temp_f0_4 < 0.0f) {
            (*(f32 *)((u8 *)(temp_16) + (0x18))) = 0.0f;
        }
        (*(s32 *)((u8 *)(arg0) + (4))) = func_L01_00448CC0((*(f32 *)((u8 *)(temp_16) + (0x10))), (*(f32 *)((u8 *)(temp_16) + (0x14))), (*(f32 *)((u8 *)(temp_16) + (0x18))), (*(f32 *)((u8 *)(temp_16) + (4))));
        temp_f0_5 = (*(f32 *)((u8 *)(temp_16) + (0xC))) + 0.00132f;
        (*(f32 *)((u8 *)(temp_16) + (0xC))) = temp_f0_5;
        if (temp_f0_5 > 1.0f) {
            (*(f32 *)((u8 *)(temp_16) + (0xC))) = (f32) (temp_f0_5 - 1.0f);
        }
        (*(s8 *)((u8 *)(arg0) + (8))) = (s8) (s32) ((*(f32 *)((u8 *)(temp_16) + (0xC))) * 255.0f);
        (*(f32 *)((u8 *)(arg0) + (0xC))) = (f32) (((*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + (0x20)))) + (0x2C))) * 100000.0f * 30.0f) + 50000.0f);
    }
}
/* localdecomp:end func_L01_00468468 */

/* localdecomp:start func_L01_00468640 */
extern s32 func_0038CB00(u8 *);
extern void func_003CD250(u8 *);
void func_L01_00468640(u8 *a0) {
    if (func_0038CB00(a0 + 10)) {
        func_003CD250(a0);
    }
}
/* localdecomp:end func_L01_00468640 */

/* localdecomp:start func_L01_00468678 */
#include "structs/hero.h"
typedef int Quad_468678 __attribute__((mode(TI)));
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
    Quad_468678 position;          /* 0x10 */
} Bubble_468678;
typedef struct {
    f32 velocity[3];               /* 0x20 */
    f32 wobble_size;               /* 0x2C */
    f32 surface_z;                 /* 0x30: the water height it pops at */
    f32 wobble_phase;              /* 0x34 */
    f32 wobble_speed;              /* 0x38 */
    f32 wobble_amp;                /* 0x3C */
    f32 rise;                      /* 0x40 */
} Rise_468678;

extern u8 *D_L01_00221120[];
extern struct Hero D_001A4BE0;
extern u8 *func_L01_004618E0(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);

/* particle_spawn_bubble: a type 0x22 particle, a bubble rising from position at velocity; surface_z
 * is where it pops (-1 for the hero's water height, or his z + 0.4 in state 0x30). */
Bubble_468678 *func_L01_00468678(Quad_468678 *position, f32 *velocity, u32 rgba, f32 scale, f32 surface_z) {
    Bubble_468678 *p = (Bubble_468678 *)func_L01_004618E0(0x22);
    Rise_468678 *r;

    if (p != 0) {
        p->rgba = rgba;
        p->flags = 0;
        r = (Rise_468678 *)((u8 *)p + 0x20);
        p->render2 = 0x44;
        p->render = 0x44;
        r->wobble_size = func_003824E0(0.75f, 1.25f) * scale;
        p->size = 5250.0f;
        p->spin = func_00382498(-10, 10) - 0x80;
        p->texture = *D_L01_00221120[0];
        p->life = func_00382498(0x3A, 0x75);
        if (surface_z == -1.0f) {
            if (D_001A4BE0.state == 0x30) r->surface_z = D_001A4BE0.pos.z + 0.4f;
            else r->surface_z = D_001A4BE0.water_height;
        } else {
            r->surface_z = surface_z;
        }
        r->wobble_phase = func_00382538();
        r->wobble_speed = func_003824E0(0.03490659f /* 2 degrees */, 0.13962636f /* 8 degrees */);
        r->wobble_amp = func_003824E0(0.010000001f, 0.028f);
        r->velocity[0] = velocity[0];
        r->velocity[1] = velocity[1];
        r->velocity[2] = velocity[2];
        p->position = *position;
    }
    return p;
}
/* localdecomp:end func_L01_00468678 */

/* localdecomp:start func_L01_00468828 */
#include "vu0.h"
extern f32 D_L01_001E29D8[];
void func_L01_00468828(u8 *self) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern s32 func_00382468(s32);
    extern f32 func_0038CED8(void *);
    extern void func_0038CFB8(void *, void *, f32);
    extern void func_003C4138(f32 *, f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D098(f32);
    u8 *vars = self + 0x20;
    f32 velocity[4] __attribute__((aligned(16)));
    f32 angle, radius;
    s32 alpha;
    if (func_0038CB00(self + 0xA)) { func_003CD250(self); return; }
    if (*(f32 *)(self + 0x18) > *(f32 *)(vars + 0x10)) {
        *(s32 *)(vars + 8) = 0;
        if (*(s16 *)(self + 0xA) > 10) *(s16 *)(self + 0xA) = 10;
    }
    if (*(f32 *)(self + 0x18) + 1.0399999618530273f > *(f32 *)(vars + 0x10)) {
        if (func_00382468(20) == 0 && *(s16 *)(self + 0xA) > 10) *(s16 *)(self + 0xA) = 10;
    }
    if (*(s16 *)(self + 0xA) < 12) {
        alpha = *(u32 *)(self + 4) >> 24;
        *(u32 *)(self + 4) = ((alpha * *(s16 *)(self + 0xA) / 12) << 24) | (*(u32 *)(self + 4) & 0xFFFFFF);
    }
    *(f32 *)(self + 0xC) += 1008.0001220703125f;
    if (*(f32 *)(self + 0xC) > *(f32 *)(vars + 0xC)) *(f32 *)(self + 0xC) = *(f32 *)(vars + 0xC);
    velocity[0] = *(f32 *)(vars + 0);
    velocity[1] = *(f32 *)(vars + 4);
    velocity[2] = *(f32 *)(vars + 8);
    func_0038CFB8(velocity, velocity, func_0038CED8(velocity) * 0.9640000462532043f);
    vec_add_ba(self + 0x10, self + 0x10, velocity);
    func_003C4138(&velocity[2], 0.026000000536441803f, 0.0020000000949949026f);
    *(f32 *)(vars + 4) = velocity[1];
    *(f32 *)(vars + 0) = velocity[0];
    *(f32 *)(vars + 8) = velocity[2];
    *(f32 *)(vars + 0x14) = func_0038DAB8(*(f32 *)(vars + 0x14), *(f32 *)(vars + 0x18));
    angle = func_0038DAB8(D_L01_001E29D8[0], 1.5707963705062866f);
    radius = func_0038D0B0(*(f32 *)(vars + 0x14)) * *(f32 *)(vars + 0x1C);
    velocity[0] = func_0038D098(angle) * radius;
    velocity[1] = func_0038D0B0(angle) * radius;
    velocity[2] = 0.0f;
    vec_add_ab(self + 0x10, self + 0x10, velocity);
}
/* localdecomp:end func_L01_00468828 */

/* localdecomp:start func_L01_00468A68 */
typedef int Q_00468A68 __attribute__((mode(TI)));
extern u8 *D_L01_00221124[];

u8 *func_L01_00468A68(Q_00468A68 *pos, Q_00468A68 *dir, s32 type, s32 arg3) {
    extern u8 *func_L01_004618E0(s32);
    extern f32 func_003824E0(f32 low, f32 high);
    u8 *p = func_L01_004618E0(0x23);
    u8 *vars;

    if (p != 0) {
        vars = p + 0x20;
        *(Q_00468A68 *)(p + 0x10) = *pos;
        p[1] = 0;
        *(u32 *)(p + 4) = 0x80808080;
        p[9] = 0x12;
        p[3] = 0x44;
        *(f32 *)(p + 0xC) = func_003824E0(10500.0f, 16800.0f);
        p[2] = *D_L01_00221124[0];
        *(Q_00468A68 *)(p + 0x20) = *dir;
        *(s32 *)(vars + 0x14) = arg3;
        *(s32 *)(vars + 0x10) = type;
        *(f32 *)(vars + 0x18) = *(f32 *)(p + 0x18);
        if (type == 2) {
            *(s32 *)(vars + 0x18) = 0;
        }
        *(f32 *)(vars + 0x1C) = func_003824E0(0.0042000003f, 0.0072000003f);
    }
    return p;
}
/* localdecomp:end func_L01_00468A68 */

/* localdecomp:start func_L01_00468B70 */
extern f32 D_001A4F30[];
extern s32 D_L01_001D7BE4;
extern u8 D_L01_001EAA20[];
typedef struct { u8 pad[0x20]; vu0_v4 pos; } Hit_00468B70;
extern Hit_00468B70 D_L01_001EAA00[];
void func_L01_00468B70(u8 *self) {
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern s32 func_003D5630(void);
    extern void func_L01_0046A938(void *, f32, s32, f32, s32);
    extern void func_L01_0046D250(void *, s32, f32, f32);
    vu0_q next;
    u8 *vars=self+0x20;
    s32 type=*(s32 *)(vars+0x10);
    if (type==0) {
        vec_add_ab(self+0x10,self+0x10,self+0x20);
        goto update;
    } else if (type==1) {
        vec_add_ab(&next,self+0x10,self+0x20);
        if (func_003D3CB0(self+0x10,&next,2,0,0)) {
            if (!func_003D5630()) func_L01_0046A938(D_L01_001EAA20,0.2f,D_L01_001D7BE4,5250.0f,-1);
            goto destroy;
        }
        goto moved;
    } else if (type==3) {
        vec_add_ab(self+0x10,self+0x10,self+0x20);
        if (*(f32 *)(self+0x18)<D_001A4F30[0]) {
            s32 effect=D_L01_001D7BE4;
            *(f32 *)(self+0x18)=D_001A4F30[0];
            func_L01_0046A938(self+0x10,0.2f,effect,5250.0f,-1);
            goto destroy;
        }
        goto update;
    } else {
        vec_add_ab(&next,self+0x10,self+0x20);
        if (func_003D3CB0(self+0x10,&next,2,0,0)) {
            if (func_003D5630()) {
                Hit_00468B70 *hit=D_L01_001EAA00;
                hit->pos.z+=0.05f;
                func_L01_0046D250(&hit->pos,-1,0.25f,3150.0f);
            }
            goto destroy;
        }
        goto moved;
    }
    goto update;
destroy:
    func_003CD250(self);
    return;
moved:
    *(vu0_q *)(self+0x10)=next;
update:
    *(f32 *)(vars+8)-=*(f32 *)(vars+0x1C);
    self[8]+=2;
    if (--*(s32 *)(vars+0x14)<=0 || *(f32 *)(self+0x18)<*(f32 *)(vars+0x18)) {
        s32 color=*(s32 *)(self+4)+0xF0000000;
        *(s32 *)(self+4)=color;
        if (color<0) {
            func_003CD250(self);
        }
    }
}
/* localdecomp:end func_L01_00468B70 */

INCLUDE_ASM("asm/levels", func_L01_00468D98);

LINKER_REMNANT("asm/levels", func_L01_00468F00);

/* localdecomp:start func_L01_00468F08 */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
void func_L01_00468F08(u8 *self) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_L01_00447470_00468F08(s32, s32, f32);
    extern s32 abs(s32);
    vu0_v4 delta;
    u8 *vars = self + 0x20;
    s32 total;
    if (func_0038CB00(self + 0xA)) {
        func_003CD250(self);
        return;
    }
    vec_sub_ba(&delta, &D_L01_001E29C0, vars);
    if (func_0038CEA8(&delta) > 5.0f) {
        func_0038CF68(&delta, &delta, 1.25f);
    } else {
        func_0038CE20(&delta, &delta, 0.25f);
    }
    vec_add_ab(self + 0x10, vars, &delta);
    total = *(s32 *)(vars + 0x14);
    *(s32 *)(self + 4) = func_L01_00447470_00468F08(0, *(s32 *)(vars + 0x10), (f32)(total - abs(*(s16 *)(self + 0xA) - total)) / (f32)total);
}
/* localdecomp:end func_L01_00468F08 */

LINKER_REMNANT("asm/levels", func_L01_00469010);

/* localdecomp:start func_L01_00469018 */
#include "vu0.h"
void func_L01_00469018(u8 *self) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern void func_0038CE20(void *, void *, f32);
    u8 *vars = self + 0x20;
    if (func_0038CB00(self + 0xA)) goto destroy;
    *(f32 *)(self + 0xC) += *(f32 *)(vars + 0x10);
    self[8]++;
    *(f32 *)(vars + 0x14) -= 0.012f;
    *(f32 *)(vars + 0x14) = *(f32 *)(vars + 0x14) < 0.0f ? 0.0f : *(f32 *)(vars + 0x14);
    *(u32 *)(self + 4) &= 0xFFFFFF;
    *(u32 *)(self + 4) |= (s32)(*(f32 *)(vars + 0x14) * 255.0f) << 24;
    if (*(f32 *)(vars + 0x14) <= 0.0f) {
destroy:
        func_003CD250(self);
    } else {
        vec_add_ab(self + 0x10, self + 0x10, self + 0x20);
        func_0038CE20(vars, vars, 0.976f);
    }
}
/* localdecomp:end func_L01_00469018 */

LINKER_REMNANT("asm/levels", func_L01_00469128);

/* localdecomp:start func_L01_00469130 */
#include "vu0.h"
__asm__(".extern D_L01_001D7F24, 4");
__asm__(".extern D_L01_001D7F20, 4");
__asm__(".extern D_L01_001D7F2C, 1");
__asm__(".extern D_L01_001D7F28, 4");
extern s32 D_L01_001D7F24 __attribute__((section(".sdata")));
extern f32 D_L01_001D7F20 __attribute__((section(".sdata")));
extern u8 D_L01_001D7F2C __attribute__((section(".sdata")));
extern f32 D_L01_001D7F28 __attribute__((section(".sdata")));
extern vu0_v4 D_L01_001E29C0;
extern u8 *D_L01_00221134[];
typedef struct {
    u8 type, flags, texture, render;
    s32 rgba;
    u8 spin, render2;
    s16 life;
    f32 size;
    vu0_v4 position;
} Particle_00469130;
void func_L01_00469130(u8 *self) {
    extern void func_0038CF68(void *, void *, f32);
    vu0_v4 delta;
    Particle_00469130 *p = (Particle_00469130 *)self;
    u8 *vars = self + 0x20;
    p->rgba = D_L01_001D7F24;
    p->size = D_L01_001D7F20;
    p->spin += D_L01_001D7F2C;
    vec_sub_ba(&delta, *(u8 **)(vars + 4) + 0x10, &D_L01_001E29C0);
    func_0038CF68(&delta, &delta, D_L01_001D7F28);
    vec_add_ba(self + 0x10, *(u8 **)(vars + 4) + 0x10, &delta);
    p->texture = D_L01_00221134[0][*(s32 *)(vars + 8) / 2];
    if (++*(s32 *)(vars + 8) >= 31) *(s32 *)(vars + 8) = 0;
    if (p->life == 0) func_003CD250(self);
}
/* localdecomp:end func_L01_00469130 */

INCLUDE_ASM("asm/levels", func_L01_00469210);

INCLUDE_ASM("asm/levels", func_L01_004693D8);

/* localdecomp:start func_L01_00469BD0 */
extern void func_003CD250(u8 *);
extern s32 func_0038CB00(u8 *);
typedef struct { u8 pad[0xA]; s16 h; } S_466558;

void func_L01_00469BD0(S_466558 *p) {
    if (p->h != -1 && ((s32 (*)(s16 *))func_0038CB00)(&p->h) != 0) {
        ((void (*)(S_466558 *))func_003CD250)(p);
    }
}
/* localdecomp:end func_L01_00469BD0 */

/* localdecomp:start func_L01_00469C18 */
typedef int Q_00469C18 __attribute__((mode(TI)));
typedef struct {
    Q_00469C18 velocity;
    f32 phase;
    s16 h14, h16;
    u8 type;
    u8 pad[3];
    s32 value;
} Vars_00469C18;
extern u8 *D_L01_002210C8[];

static __inline__ s32 remainder_00469C18(s32 value, s32 divisor) {
    return value % divisor;
}
u8 *func_L01_00469C18(Q_00469C18 *pos, Q_00469C18 *vel, u8 type, s32 value) {
    extern u8 *func_L01_004618E0(s32);
    extern u32 func_L01_00448CC0(f32, f32, f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern u8 func_0013D3E0(void);
    u8 *p = func_L01_004618E0(42);
    Vars_00469C18 *v;
    if (p != 0) {
        *(Q_00469C18 *)(p + 0x10) = *pos;
        v = (Vars_00469C18 *)(p + 0x20);
        *(Q_00469C18 *)(p + 0x20) = *vel;
        *(u32 *)(p + 4) = func_L01_00448CC0(0.7f, 0.7f, 0.7f, 0.08f);
        p[1] = 0;
        p[9] = 0x44;
        p[3] = 0x44;
        v->phase = func_003824E0(0.0f, 1.0f);
        p[8] = (s32)(v->phase * 256.0f);
        p[2] = D_L01_002210C8[0][func_0013D3E0() & 7];
        v->type = type;
        v->h14 = 0;
        v->h16 = 0;
        if (type < 5) {
            *(f32 *)(p + 0xC) = func_003824E0(7000.0f, 10000.0f);
            *(s16 *)(p + 0xA) = 15 - remainder_00469C18(func_0013D3E0(), 12);
        } else {
            *(s16 *)(p + 0xA) = 15;
            *(f32 *)(p + 0xC) = 10000.0f;
        }
        v->value = value;
    }
    return p;
}
/* localdecomp:end func_L01_00469C18 */

INCLUDE_ASM("asm/levels", func_L01_00469D88);

LINKER_REMNANT("asm/levels", func_L01_0046A428);

/* localdecomp:start func_L01_0046A430 */
#include "vu0.h"
void func_L01_0046A430(u8 *self)
{
    extern void func_003CD250(u8 *);
    u8 *vars = self + 0x20;
    s32 time, life;
    f32 factor, r, g, b, total;
    u8 blue, green, red, alpha;
    ++*(s16 *)(self + 0xA);
    time = *(s16 *)(self + 0xA);
    life = *(s16 *)(vars + 0x18);
    if (time > life) {
        func_003CD250(self);
        return;
    }
    total = life;
    factor = (f32)time / total;
    factor = 1.0f - factor;
    g = vars[0x14] + -0.001f * factor;
    b = vars[0x15] + -0.0011f * factor;
    r = vars[0x16] + -0.00111f * factor;
    red = r;
    green = g;
    blue = b;
    if (time < 25) {
        factor = (f32)time / 25.0f;
        alpha = vars[0x17] * factor;
    } else {
        factor = (f32)(time - 25) / (f32)(life - 25);
        factor = 1.0f - factor;
        alpha = vars[0x17] * factor;
    }
    *(u32 *)(self + 4) = (alpha << 24) | (red << 16) | (blue << 8) | green;
    self[8]++;
    vec_add_ab(self + 0x10, self + 0x10, vars);
    *(f32 *)(vars + 8) += 0.0007200000691227615f;
}
/* localdecomp:end func_L01_0046A430 */

/* localdecomp:start func_L01_0046A610 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_46A610;
typedef struct {
    f32 velocity[3];               /* 0x20 */
    f32 gravity;                   /* 0x2C */
    u8 spin_step;                  /* 0x30: a frame, x 1.2 for 50 Hz */
    u8 rgb[3];                     /* 0x31: the colour it starts from */
    f32 size_step;                 /* 0x34: a frame, x 1.2 */
    f32 drag;                      /* 0x38: velocity kept a frame, 1.0 for none */
    s16 life_start;                /* 0x3C */
    s16 alpha_start;               /* 0x3E */
} Ember_46A610;
typedef struct {
    u8 type;                       /* 0x00 */
    s8 flags;                      /* 0x01 */
    u8 texture;                    /* 0x02 */
    u8 render;                     /* 0x03 */
    u32 rgba;                      /* 0x04 */
    u8 spin;                       /* 0x08 */
    u8 render2;                    /* 0x09 */
    s16 life;                      /* 0x0A */
    f32 size;                      /* 0x0C: world units x 210000 */
    Vec_46A610 position;           /* 0x10 */
    Ember_46A610 ember;            /* 0x20 */
} Particle_46A610;

extern u8 *D_L01_00221148[];
extern u8 *func_L01_004618E0(s32);
extern s32 func_00382468(s32);

/* particle_spawn_ember: a type 0x2C particle, an ember or spark that fades to nothing over its
 * life, grows a set step a frame, keeps drag of its velocity and falls by gravity; the per-frame
 * rates are scaled by 1.2 for PAL's 50 Hz. */
Particle_46A610 *func_L01_0046A610(Vec_46A610 *position, f32 *velocity, s32 life, s32 alpha, s32 rgb, s32 spin_step,
                                   f32 size, f32 size_step, f32 drag, f32 gravity, f32 w) {
    Particle_46A610 *p = (Particle_46A610 *)func_L01_004618E0(0x2C);

    if (p != 0) {
        Ember_46A610 *ember;

        p->position = *position;
        p->size = size;
        p->position.w = w;
        p->flags = 0;
        p->rgba = (alpha << 24) | rgb;
        p->render2 = 0x44;
        p->render = 0x48;
        p->spin = func_00382468(0xFF);
        p->texture = *D_L01_00221148[0];
        p->life = life;
        ember = &p->ember;
        ember->velocity[0] = velocity[0];
        ember->velocity[1] = velocity[1];
        ember->velocity[2] = velocity[2];
        ember->spin_step = spin_step * 1.2f;
        ember->size_step = size_step * 1.2f;
        ember->drag = (drag - 1.0f) * 1.2f + 1.0f;
        ember->rgb[0] = rgb;
        ember->rgb[1] = rgb >> 8;
        ember->rgb[2] = rgb >> 16;
        ember->life_start = life;
        ember->alpha_start = alpha;
        ember->gravity = gravity;
    }
    return p;
}
/* localdecomp:end func_L01_0046A610 */

/* localdecomp:start func_L01_0046A798 */
#include "vu0.h"
extern f32 D_001A4EC0[];
void func_L01_0046A798(u8 *p) {
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    u8 *e;
    f32 ratio;
    f32 v[4] __attribute__((aligned(16)));
    f32 g[4] __attribute__((aligned(16)));
    if (func_0038CB00(p + 10)) {
        func_003CD250(p);
        return;
    }
    e = p + 0x20;
    ratio = (f32)*(s16 *)(p + 10) / (f32)*(s16 *)(e + 0x1C);
    *(u32 *)(p + 4) = ((s32)((f32)*(s16 *)(e + 0x1E) * ratio) << 24) | (e[0x13] << 16) | (e[0x12] << 8) | e[0x11];
    v[0] = *(f32 *)(p + 0x20);
    v[3] = 0.0f;
    v[1] = *(f32 *)(e + 4);
    v[2] = *(f32 *)(e + 8);
    vec_add_ab(p + 0x10, p + 0x10, v);
    if (*(f32 *)(p + 0x1C) != 0.0f) {
        if (*(f32 *)(p + 0x1C) == 2.0f) func_L01_004CAB30(p + 0x10, p + 0x10);
        *(f32 *)(p + 0x1C) = 2.0f;
    }
    func_0038CE20(g, D_001A4EC0, *(f32 *)(e + 0xC));
    vec_add_ab(v, v, g);
    func_0038CE20(v, v, *(f32 *)(e + 0x18));
    *(f32 *)(e + 0) = v[0];
    *(f32 *)(e + 4) = v[1];
    *(f32 *)(e + 8) = v[2];
    p[8] += e[0x10];
    *(f32 *)(p + 0xC) += *(f32 *)(e + 0x14);
}
/* localdecomp:end func_L01_0046A798 */
