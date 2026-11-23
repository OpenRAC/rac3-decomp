#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_0034AC60 */
typedef struct { vu0_v4 pos; u8 pad10[0x10]; f32 f20; u8 pad24[4]; s32 w28; s32 w2C; u8 pad30[0x350]; vu0_v4 v380; u8 pad390[0xD0]; } C_0034AC60;
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
} V_0034AC60;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[0x30 - 0x21];
    u8 b30;
    u8 pad31;
    s16 h32;
    u8 pad34[0x68 - 0x34];
    V_0034AC60 *vars;
    u8 pad6C[0xC0 - 0x6C];
    vu0_v4 m[3];
} M_0034AC60;
extern s32 D_001D52F0;
extern C_0034AC60 D_L07_001E1EC0[];

void *func_L07_0034AC60(f32 size, vu0_q *pos, s32 notify, s32 w20, s32 w24, s32 w28, s32 w2C, s32 w30, s32 w18,
                        s32 w34, s32 w1C)
{
    extern u8 *func_003C24B0(s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CE90(void *, void *, void *);
    extern s32 func_0038DC20(void *, f32);
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038D0C8(f32);
    extern void func_L07_0034B180(void *, void *);
    vu0_v4 delta;
    vu0_v4 axis;
    vu0_v4 sphere;
    vu0_v4 diff;
    M_0034AC60 *self = (M_0034AC60 *)func_003C24B0(0xEAE, 0x80);
    V_0034AC60 *v;

    if (self != 0) {
        self->b30 = 0xFF;
        self->h32 = 0xFF;
        self->state = 0;
        v = self->vars;
        *(vu0_q *)&self->pos = *pos;
        self->pos.w = 1.0f;
        vec_sub_ba(&delta, &D_L07_001E1EC0[D_001D52F0].pos, &self->pos);
        func_0038CF68(&delta, &delta, 1.0f);
        func_003C5180(&self->pos, &axis, 1);
        *(vu0_q *)&self->m[0] = *(vu0_q *)&delta;
        func_0038CE90(&self->m[1], &self->m[0], &axis);
        func_0038CF68(&self->m[1], &self->m[1], 1.0f);
        func_0038CE90(&self->m[2], &self->m[1], &self->m[0]);
        self->m[0].w = self->m[1].w = self->m[2].w = 0.0f;
        v->w20 = w20;
        v->w24 = w24;
        v->w28 = w28;
        v->w2C = w2C;
        v->w30 = w30;
        v->w34 = w34;
        v->h2 = v->h0 = 50;
        v->f8 = size + size;
        v->fC = size * 4.0f;
        v->w1C = w1C;
        v->w18 = w18;
        v->f14 = size;
        *(vu0_q *)&sphere = *(vu0_q *)&self->pos;
        sphere.w = size * 3.0f;
        if (func_0038DC20(&sphere, 128.0f) == 1) {
            v->h4 = 8;
            v->f10 = 0.125f;
            if (notify != 0) {
                if (func_0038CF00(pos, &D_L07_001E1EC0[D_001D52F0]) < 48.0f) {
                    D_L07_001E1EC0[0].w28 = 0x21;
                    D_L07_001E1EC0[0].f20 = 0.075f;
                    D_L07_001E1EC0[0].w2C = 0;
                }
            }
            if (v->w18 != 0) {
                vec_sub_ab(&diff, &self->pos, &D_L07_001E1EC0[D_001D52F0].pos);
                func_0038CF68(&diff, &diff, 1.0f);
                if (1.5707964f - func_0038D0C8(func_0038CE68(&diff, &D_L07_001E1EC0[D_001D52F0].v380)) < 0.4537856f) {
                    v->w18 = 1;
                } else {
                    v->w18 = 0;
                }
            }
        } else {
            v->h4 = 0;
            v->w18 = 0;
        }
        func_L07_0034B180(self, &axis);
    }
    return self;
}
/* localdecomp:end func_L07_0034AC60 */
