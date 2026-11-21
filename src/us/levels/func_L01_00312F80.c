#include "common.h"

/* NTSC-U counterpart of func_L01_00313270 (src/levels/shared/L01_00312DD8.c) */
#include "vu0.h"
typedef vu0_v4 V;
typedef struct { V axis,dir,pos; char p30[8]; int active; float size; int n0,n1; } Source;
typedef struct { V pos,dir; float f20,f24,f28,f2c,f30,f34,f38,f3c,f40,f44,f48,f4c; int f50,f54,f58,f5c,f60,color64,color68,color6c,mode,f74,type; Source *owner; } Particle;
extern Particle *D_L01_001E17B4;
extern int func_0037E208(int,int);
extern void func_0038D890(void *,void *,void *,float),func_00388830(void *,void *,float);

/* localdecomp:start func_L01_00312F80 */
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

extern f32 func_L01_00442068(f32);
extern f32 func_L01_00442070(f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_003BFC18(void *, void *, s32);
extern f32 func_00389380(f32, f32);
extern s32 func_00388398(void *);

void func_L01_00312F80(Source *owner) {
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
        p = (Particle *)(i * 0x80 + (s32)D_L01_001E17B4);
        if (p->owner != owner) {
            continue;
        }
        t = 1.0f - (f32)p->f54 / (f32)p->f58;
        if (p->f74 != 0) {
            if (p->f74 != 1) {
                goto common;
            }
            r = func_L01_00442068(t);
            p->f60 = (s32)((f32)p->f5c - (f32)p->f5c * r);
            if (p->type == 2) {
                goto special;
            }
        }
        p->color68 = func_003894A0(p->color64, p->color6c, t);
        p->f2c = p->f28 + (p->f30 - p->f28) * t;
        p->f3c = p->f38 + (p->f40 - p->f38) * t;
        p->f48 = p->f44 + (p->f4c - p->f44) * t;
        func_00388830(v0, &p->dir, p->f24 * func_L01_00442070(t));
        goto common;
    special:
        func_00388830(v0, &p->dir, p->f24);
    common:
        func_003BFC18((u8 *)*(H_313270 **)owner->p30 + 0x10, a, 1);
        func_00388830(b, a, p->f3c);
        vec_add_ab(&p->pos, &p->pos, b);
        if (p->type != 1) {
            vec_add_ab(&p->pos, v0, &p->pos);
        }
        h = *(H_313270 **)p->owner->p30;
        tt = h->w68;
        p->f34 = func_00389380(p->f34, p->f2c);
        if (h->b20 == 2 && tt->w14 < 0x26 && p->type != 2) {
            p->f74 = 1;
            n = func_0037E208(0x1E, 0x2D);
            p->f54 = n;
            p->f58 = n;
            p->f44 = p->f48;
            p->color64 = p->color68;
            p->f38 = p->f3c;
            p->f5c = p->f60;
            p->f28 = p->f2c;
        }
        if (func_00388398(&p->f54) != 0) {
            if (p->f74 == 0) {
                p->f74 = 1;
                if (p->type == 1) {
                    p->f58 = 0x1E;
                    p->f54 = 0x1E;
                } else {
                    p->f58 = 0x37;
                    p->f54 = 0x37;
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
/* localdecomp:end func_L01_00312F80 */
