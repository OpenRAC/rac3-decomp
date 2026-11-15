#include "common.h"

/* localdecomp:start func_L39_0056DF80 */
typedef struct { u8 p0[0x100]; f32 f100; f32 f104; } H_0056DF80;
typedef struct { u8 p0[0x134]; H_0056DF80 *w134; u8 p138[0x460 - 0x138]; } E_0056DF80;
typedef struct { u8 p0[0x10]; s32 w10; f32 f14; u8 p18[4]; f32 f1C; u8 p20[4]; f32 f24; } Q_0056DF80;
typedef struct { u8 p0[0x1E0]; Q_0056DF80 q; } W_0056DF80;
typedef struct { u8 p0[0x70]; W_0056DF80 *w70; u8 p74[0x20]; s32 w94; } O_0056DF80;
typedef struct { u8 pad[0xA4]; u8 flags[0x100]; } Tab_0056DF80;
extern E_0056DF80 D_L39_0024DFD0[];
extern Tab_0056DF80 D_001A5810;
extern s32 D_001A5930[][8];
extern s32 D_001A58D0[][8];
extern f32 D_L39_00242398[];
extern u8 *func_L39_0061BF38(s32);

void func_L39_0056DF80(O_0056DF80 *o, f32 *a1, f32 *a2) {
    Q_0056DF80 *q = &o->w70->q;
    E_0056DF80 *e = &D_L39_0024DFD0[o->w94];
    s32 idx = *(s32 *)(func_L39_0061BF38(o->w94) + 0x2544);
    f32 f;
    f32 k = 0.6981317f;

    if (q->w10 & 1) {
        *a1 = 0;
    } else {
        *a1 = e->w134->f100;
        if (D_001A5930[D_001A5810.flags[idx]][idx] == 0) *a1 = -*a1;
    }
    if (*a1 == 0) {
        if (q->f1C != 0) *a1 = q->f1C;
    } else {
        q->f14 = D_L39_00242398[o->w94];
    }
    if (q->w10 & 2) {
        *a2 = 0;
        if (*a2 == 0) *a2 = q->f24 / k;
    } else {
        f = e->w134->f104;
        *a2 = -f;
        if (D_001A58D0[D_001A5810.flags[idx]][idx] == 0) *a2 = f;
        if (*a2 == 0) *a2 = q->f24 / 0.6981317f;
    }
}
/* localdecomp:end func_L39_0056DF80 */

/* localdecomp:start func_L39_0056E140 */
typedef struct S_0056E140_Obj {
    u8 pad00[0x22];
    s16 f22;
    u8 pad24[0x15C];
    f32 v180[0x34 / 4];
    f32 f1B4;
    f32 f1B8;
    u8 pad1BC[0x24];
    f32 a1E0[9];
    u8 pad204[0x44];
    s16 f248;
} S_0056E140_Obj;

typedef struct S_0056E140_Vec {
    f32 v0[0xD];
    f32 f34;
    f32 f38;
} S_0056E140_Vec;

typedef struct S_0056E140_Ctl {
    u8 pad00[0x70];
    S_0056E140_Obj *obj;
    u8 pad74[0x20];
    s32 idx;
} S_0056E140_Ctl;

typedef struct S_0056E140_Ent {
    u8 pad00[0x20];
    f32 v20[4];
    u8 pad30[0x430];
} S_0056E140_Ent;

extern S_0056E140_Ent D_L39_0024DEE0[];
extern s32 *D_L39_00241120;
extern s32 D_L39_0024111C;
extern f32 D_L39_0024B6F0[2];
extern f32 func_L39_00578EA0(f32, f32 *, f32, f32, f32, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);

void func_L39_0056E140(S_0056E140_Ctl *p, f32 a, f32 b) {
    S_0056E140_Obj *obj;
    S_0056E140_Ent *e;
    f32 *w;
    S_0056E140_Vec *v;
    f32 *vec;
    f32 f21;
    f32 f23;
    f32 t;
    f32 sp[4];
    f32 *tab;

    e = &D_L39_0024DEE0[p->idx];
    obj = p->obj;
    w = &obj->a1E0[0];
    f21 = w[5];
    v = (S_0056E140_Vec *)obj->v180;
    obj->a1E0[0] = func_L39_00578EA0(obj->a1E0[0], &obj->a1E0[1], a, 2.0f, 4.0f, 0.0f);
    if (*D_L39_00241120 >= 2 && D_L39_0024111C == 1) {
        f21 = f21 * 60.0f / 30.0f;
    }
    v->f34 = f21 * w[0];
    if (b < -0.3f) {
        b = (b + 0.3f) * 1.4285715f;
    } else if (b > 0.3f) {
        b = (b - 0.3f) * 1.4285715f;
    } else {
        b = 0.0f;
    }
    if (b == 0.0f || (__builtin_fabsf(b) < __builtin_fabsf(w[2]) && ((b > 0.0f && w[2] > 0.0f) || (b < 0.0f && w[2] < 0.0f)))) {
        f23 = 0.01f;
    } else {
        f23 = 0.02f;
    }
    w[2] = func_L39_00578EA0(w[2], &w[3], b, 2.0f, 4.0f, f23);
    t = w[2] * 0.6981317f;
    if (a == 0.0f) {
        func_0038D890(v, v, e->v20, w[8]);
        vec = e->v20;
    } else {
        vec = e->v20;
        func_0038D890(v, v, vec, v->f34);
    }
    f21 = func_0038CE68(v, vec);
    b = func_0038CEA8(v);
    func_0038CE90(sp, vec, v);
    func_0038CF68(sp, sp, 1.0f);
    b = func_0038D160(b, f21);
    if (__builtin_fabsf(b) < __builtin_fabsf(t)) {
        if (f23 == 0.01f) {
            w[2] = b / 0.6981317f;
        }
    }
    if (b < t) {
        tab = D_L39_0024B6F0;
        if (t < func_0038DAB8(b, tab[D_L39_0024111C])) {
            v->f38 = func_0038DB00(t, b);
        } else {
            v->f38 = tab[D_L39_0024111C];
        }
    } else if (t < b) {
        if (p->obj->f248 >= 0) {
            tab = D_L39_0024B6F0;
            if (func_0038DAB8(b, -tab[D_L39_0024111C]) < t) {
                v->f38 = func_0038DB00(t, b);
            } else {
                v->f38 = -tab[D_L39_0024111C];
            }
        } else {
            v->f38 = 0.0f;
        }
    } else {
        v->f38 = 0.0f;
    }
    if (t < 0.0f) {
        p->obj->f22 = 1;
    }
    func_0038D890(v, v, sp, v->f38);
}
/* localdecomp:end func_L39_0056E140 */
