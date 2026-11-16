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
typedef struct {
    f32 x, y, z, w;
} Vec_3E3820;

typedef struct {
    s32 idx;
    f32 radius, right, left, angle, speed, turn;
    s16 timer;
    u8 p1E[2];
    f32 phase;
} Vars_3E3820;

typedef struct {
    u8 p0[0x10];
    Vec_3E3820 pos;
    u8 state;
    u8 p21[0x10];
    u8 b31;
    u8 p32[0x36];
    Vars_3E3820 *vars;
    u8 p6C[0xC];
    s32 color;
    u8 p7C[0x7C];
    f32 rot;
} Obj_3E3820;

typedef struct {
    u8 p0[0x30];
    Vec_3E3820 pos;
    u8 p40[0x40];
} Slot_3E3820;

typedef struct {
    u8 p0[0x80];
    Vec_3E3820 pos;
} Hero_3E3820;

extern Slot_3E3820 *D_001DF500_sda;
__asm__(".extern D_001DF500_sda, 4");
extern Hero_3E3820 D_001A4BE0;
extern void func_L07_003E3AB0();
extern s32 func_L01_004BA800(void);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern s32 func_0038CB00(s16 *);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_0038DB48(f32);
extern void func_L01_00448890(void *, void *, f32, f32, f32, f32, s32);
extern f32 func_0038D098(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L07_003E3B30();
extern void func_L01_00404808(void (*)(), void *);

void func_L07_003E3820(void *arg)
{
    Obj_3E3820 *m = arg;
    Vars_3E3820 *v;
    Vec_3E3820 *pos;
    f32 t, a, b;

    if (m->state == 0) func_L07_003E3AB0(m);
    v = m->vars;
    if (v->idx != -1) pos = &D_001DF500_sda[v->idx].pos;
    else pos = &m->pos;
    if (func_L01_004BA800()) {
        t = 0;
    } else {
        if (func_L01_0040E570(pos, &D_001A4BE0.pos) < v->radius * v->radius) {
            t = func_0038DB00(func_0038D160(D_001A4BE0.pos.x - m->pos.x,
                                         D_001A4BE0.pos.y - m->pos.y), v->angle);
            if (t > v->right * 0.017453292f) t = v->right * 0.017453292f;
            else if (t < -(v->left * 0.017453292f)) t = -(v->left * 0.017453292f);
            v->phase += 0.036000002175569534f;
            if (v->phase >= 2.0f) v->phase -= 2.0f;
        } else {
            if (func_0038CB00(&v->timer)) {
                v->turn = func_003824E0(-v->left, v->right) * 0.017453292f * 0.75f;
                v->timer = func_00382468(50) + 100;
            }
            v->phase *= 0.9880000352859497f;
            t = v->turn;
        }
    }
    a = func_0038DB48(v->angle + t + 3.1415927f);
    func_L01_00448890(&m->rot, &v->speed, a, 0.00031415928970091045f,
                     0.00031415928970091045f, 0.015707964077591896f, 0);
    if (v->phase > 1.0f) b = 2.0f - v->phase;
    else b = v->phase;
    m->color = func_0038DBD8(0x202020, 0xFF0000FF, (1.0f - func_0038D098(b)) * 0.5f);
    if (m->b31) func_L01_00404808(func_L07_003E3B30, m);
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

INCLUDE_ASM("asm/levels", func_L07_003E3B30);
