/* functional: high. Written from the PAL asm using the NTSC-U twin draft as a layout guide; every constant/offset/callee re-checked against PAL (PAL differs: slot values 0x32/8/0.125/0x21, callees func_003C24B0/0038CF68/003C5180/0038CE90/0038DC20/0038CF00/0038CE68/0038D0C8). Compiles with --flags '-mvu0-use-vf0-vf2 @ps2as' (162 diffs); the file's own line lacks those flags and has -fopt-stack, retail saves s0-s7 with sq so it needs the draft's flag change. */
#include "vu0.h"
typedef struct {
    s16 h0;
    s16 h2;
    s16 h4;
    u8 pad6[2];
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    s32 w18;
    s32 w1C;
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w2C;
    s32 w30;
    s32 w34;
} S_0034AC60;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 v10;
    u8 b20;
    u8 pad21[0xF];
    u8 b30;
    u8 pad31;
    s16 h32;
    u8 pad34[0x34];
    S_0034AC60 *p68;
    u8 pad6C[0x54];
    vu0_v4 vC0;
    vu0_v4 vD0;
    vu0_v4 vE0;
} O_0034AC60;

extern s32 D_001D52F0;
extern u8 D_L07_001E1EC0[];
extern O_0034AC60 *func_003C24B0(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CE90(void *, void *, void *);
extern s32 func_0038DC20(void *, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern void func_L07_0034B180(void *, void *);

O_0034AC60 *func_L07_0034AC60(f32 size, vu0_v4 *src, s32 flag, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 st0,
                              s32 st1) {
    O_0034AC60 *o;
    S_0034AC60 *s;
    vu0_v4 d;
    vu0_v4 t;
    vu0_v4 q;
    vu0_v4 e;
    u8 *tbl;
    f32 dist;
    f32 ang;

    o = func_003C24B0(0xEAE, 0x80);
    if (o != 0) {
        o->b30 = 0xFF;
        o->h32 = 0xFF;
        o->b20 = 0;
        tbl = D_L07_001E1EC0;
        s = o->p68;
        o->v10 = *src;
        o->v10.w = 1.0f;
        vec_sub_ba(&d, tbl + D_001D52F0 * 0x460, &o->v10);
        func_0038CF68(&d, &d, 1.0f);
        func_003C5180(&o->v10, &t, 1);
        o->vC0 = d;
        func_0038CE90(&o->vD0, &o->vC0, &t);
        func_0038CF68(&o->vD0, &o->vD0, 1.0f);
        func_0038CE90(&o->vE0, &o->vD0, &o->vC0);
        o->vC0.w = 0.0f;
        o->vE0.w = 0.0f;
        o->vD0.w = 0.0f;
        s->w20 = a2;
        s->w24 = a3;
        s->w28 = a4;
        s->w2C = a5;
        s->w30 = a6;
        s->h2 = 0x32;
        s->f8 = size + size;
        s->fC = size * 4.0f;
        s->w34 = st0;
        s->w1C = st1;
        s->h0 = 0x32;
        s->w18 = a7;
        s->f14 = size;
        q = o->v10;
        q.w = size * 3.0f;
        if (func_0038DC20(&q, 128.0f) != 1) {
            s->w18 = 0;
            s->h4 = 0;
        } else {
            s->h4 = 8;
            s->f10 = 0.125f;
            if (flag != 0) {
                dist = func_0038CF00(src, tbl + D_001D52F0 * 0x460);
                if (dist < 48.0f) {
                    *(s32 *)(tbl + 0x28) = 0x21;
                    *(f32 *)(tbl + 0x20) = 0.075f;
                    *(s32 *)(tbl + 0x2C) = 0;
                }
            }
            if (s->w18 != 0) {
                vec_sub_ab(&e, &o->v10, tbl + D_001D52F0 * 0x460);
                func_0038CF68(&e, &e, 1.0f);
                ang = func_0038D0C8(func_0038CE68(&e, tbl + 0x380 + D_001D52F0 * 0x460));
                if (1.5707964f - ang < 0.4537856f) {
                    s->w18 = 1;
                } else {
                    s->w18 = 0;
                }
            }
        }
        func_L07_0034B180(o, &t);
    }
    return o;
}
