#include "common.h"
#include "vu0.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x28];
    s32 w28;
} S_311A18m;
typedef struct {
    u8 pad0[0x10];
    s128 q10;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    S_311A18m *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} S_311A18;


/* localdecomp:start func_L01_00312DD8 */
typedef vu0_v4 V;
typedef vu0_q Q;
typedef struct { V axis,dir,pos; char p30[8]; int active; float size; int n0,n1; } Source;
typedef struct { V pos,dir; float f20,f24,f28,f2c,f30,f34,f38,f3c,f40,f44,f48,f4c; int f50,f54,f58,f5c,f60,color64,color68,color6c,mode,f74,type; Source *owner; } Particle;
extern Particle *D_L01_001E1734;
__asm__(".extern D_L01_001E1734, 16");
extern int func_00382498(int,int);
extern float func_00382538(void),func_003824E0(float,float),func_L01_00443A18(float,float);
extern void func_0038D890(void *,void *,void *,float),func_0038CF68(void *,void *,float);

Particle *func_L01_00312DD8(Source *source,int type,V *point,float angle) {
    V temp,temp2;
    int i,c0,c1,c2;
    Particle *p;
    for(i=0;i<320;i++) {
        if(D_L01_001E1734[i].owner)continue;
        switch(type) {
        case 0:
            if(++source->n0==150) {source->n0--;return 0;}
            break;
        case 1:
            if(++source->n1==150) {source->n1--;return 0;}
            break;
        }
        p=&D_L01_001E1734[i];
        p->owner=source;
        source->active++;
        p->f5c=p->f60=func_00382498(95,127);p->type=type;
        if(type==0) {
            func_0038D890(&p->dir,&source->dir,&source->axis,func_00382538());
            p->f3c=p->f38=source->size*func_003824E0(0,1.25f);
            p->f40=0;
            c0=func_00382498(0,13);
            p->color6c=(c0<<16)+(c0<<8)+c0;
            p->f48=p->f44=func_003824E0(0.25f,0.35f);
            p->f4c=func_003824E0(0.75f,1);
            p->f24=0;
            p->f58=p->f54=func_00382498(83,100);
            *(Q*)&p->pos=*(Q*)&p->owner->pos;
            func_0038CF68(&temp,&p->dir,func_003824E0(0.15f,0.75f));
            vec_add_ab(&p->pos,&temp,&p->pos);
            p->mode=2;p->f30=0;
        } else if(type==1) {
            func_0038D890(&p->dir,&source->dir,&source->axis,func_00382538());
            p->f40=p->f3c=p->f38=0.0f;
            c1=func_00382498(0,13);
            p->color6c=(c1<<16)+(c1<<8)+c1;
            p->f48=p->f44=func_003824E0(0.25f,0.5f);
            p->f4c=func_003824E0(1,1.5f);
            p->f24=func_003824E0(0.080000006f,0.10000001f);
            p->f58=p->f54=func_00382498(83,100);
            *(Q*)&p->pos=*(Q*)point;p->mode=2;p->f30=0;
        } else if(type==2) {
            func_0038D890(&p->dir,&source->dir,&source->axis,angle);
            p->f40=p->f3c=p->f38=0.0f;
            c2=func_00382498(1,10);
            p->color6c=(c2<<16)+(c2<<8)+c2;
            p->f48=p->f44=func_003824E0(0.15f,0.25f)*0.5f;
            p->f4c=func_003824E0(0.5f,0.8f)*1.15f;
            p->f24=0.07000001f;
            p->f58=p->f54=75;
            func_0038CF68(&temp,p->owner,0.2f);
            vec_add_ba(&p->pos,&p->owner->pos,&temp);
            func_0038CF68(&temp2,&p->dir,0.75f);
            vec_add_ab(&p->pos,&temp2,&p->pos);
            p->f30=func_L01_00443A18(0.06283186f,0.12566371f);
            p->mode=type;
        }
        p->color68=p->color64=0x103080;
        p->f20=0.00080000004f;
        p->f2c=p->f28=func_L01_00443A18(0.37699115f,0.4276057f);
        p->f34=func_00382538();
        p->f74=0;
        return p;
    }
    return 0;
}
/* localdecomp:end func_L01_00312DD8 */

/* localdecomp:start func_L01_00313270 */
typedef struct {
    u8 p0[0x14];
    s32 w14;
} T_313270;

typedef struct {
    u8 p0[0x10];
    f32 pos[4];
    u8 b20;
    u8 p21[0x47];
    T_313270 *w68;
} H_313270;

extern f32 func_L01_004451A0(f32);
extern f32 func_L01_004451A8(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003C5180(void *, void *, s32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CAD0(void *);

void func_L01_00313270(Source *owner) {
    f32 v0[4];
    f32 a[4];
    f32 b[4];
    Particle *p;
    f32 t;
    f32 r;
    s32 i;
    H_313270 *h;
    T_313270 *tt;
    s32 n;

    qzero(v0);
    for (i = 0; i < 0x140; i++) {
        p = (Particle *)(i * 0x80 + (s32)D_L01_001E1734);
        if (p->owner != owner) {
            continue;
        }
        t = 1.0f - (f32)p->f54 / (f32)p->f58;
        if (p->f74 != 0) {
            if (p->f74 != 1) {
                goto common;
            }
            r = func_L01_004451A0(t);
            p->f60 = (s32)((f32)p->f5c - (f32)p->f5c * r);
            if (p->type == 2) {
                goto special;
            }
        }
        p->color68 = func_0038DBD8(p->color64, p->color6c, t);
        p->f2c = p->f28 + (p->f30 - p->f28) * t;
        p->f3c = p->f38 + (p->f40 - p->f38) * t;
        p->f48 = p->f44 + (p->f4c - p->f44) * t;
        func_0038CF68(v0, &p->dir, p->f24 * func_L01_004451A8(t));
        goto common;
    special:
        func_0038CF68(v0, &p->dir, p->f24);
    common:
        func_003C5180((u8 *)*(H_313270 **)owner->p30 + 0x10, a, 1);
        func_0038CF68(b, a, p->f3c);
        vec_add_ab(&p->pos, &p->pos, b);
        if (p->type != 1) {
            vec_add_ab(&p->pos, v0, &p->pos);
        }
        h = *(H_313270 **)p->owner->p30;
        tt = h->w68;
        p->f34 = func_0038DAB8(p->f34, p->f2c);
        if (h->b20 == 2 && tt->w14 < 0x20 && p->type != 2) {
            p->f74 = 1;
            n = (func_00382498(0x1E, 0x2D) * 5 + 2) / 6;
            p->f54 = n;
            p->f44 = p->f48;
            p->color64 = p->color68;
            p->f38 = p->f3c;
            p->f5c = p->f60;
            p->f28 = p->f2c;
            p->f58 = n;
        }
        if (func_0038CAD0(&p->f54) != 0) {
            if (p->f74 == 0) {
                p->f74 = 1;
                if (p->type == 1) {
                    p->f58 = 0x19;
                    p->f54 = 0x19;
                } else {
                    p->f58 = 0x2E;
                    p->f54 = 0x2E;
                }
            } else if (p->f60 > 0) {
                p->f74 = 2;
                p->f60 = p->f60 - 1;
            } else {
                p->owner->active--;
                switch (p->type) {
                case 0:
                    p->owner->n0--;
                    break;
                case 1:
                    p->owner->n1--;
                    break;
                }
                p->owner = 0;
            }
        }
    }
}
/* localdecomp:end func_L01_00313270 */
