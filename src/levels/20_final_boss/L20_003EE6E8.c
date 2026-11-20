#include "common.h"

/* localdecomp:start func_L20_003EE6E8 */
/* from rac2-decomp's func_0032C700 */
#include "vu0.h"
typedef struct { vu0_v4 pos; u8 pad10[0x10]; f32 f20; u8 pad24[4]; s32 w28; s32 w2C; u8 pad30[0x350]; vu0_v4 v380; u8 pad390[0xD0]; } C_003EE6E8;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    s16 h10;
    s16 h12;
    s16 h14;
    s16 h16;
    s16 h18;
    s16 h1A;
    s16 h1C;
    s16 h1E;
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w2C;
    s16 h30;
    s16 h32;
    u8 pad34[2];
    s16 h36;
    s32 w38;
    s16 h3C;
    s16 h3E;
    s32 w40;
    s32 w44;
    s32 w48;
    s32 w4C;
    s32 w50;
    s32 w54;
    s32 w58;
    s32 w5C;
    s32 w60;
    s32 w64;
    f32 f68;
    f32 f6C;
} V_003EE6E8;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[0x30 - 0x21];
    u8 b30;
    u8 pad31;
    s16 h32;
    u8 pad34[0x68 - 0x34];
    V_003EE6E8 *vars;
    u8 pad6C[0xC0 - 0x6C];
    vu0_v4 m[3];
} M_003EE6E8;
extern s32 D_001D52F0;
extern C_003EE6E8 D_L20_001E2E80_003EE6E8[];
extern u8 *func_003C24B0(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_L01_0044C870(u8 *, s32, u8 *, void *);
extern s32 func_L01_00459590(void *, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern void func_L20_003EF550(u8 *, void *, void *, f32);

void *func_L20_003EE6E8(vu0_q *pos, s32 notify, s32 w20, s32 w24, s32 w28, s32 w2C, s16 h32, s16 h30,
                        f32 scale, f32 last, f32 f6C, f32 f68,
                        s16 h18, s16 h1C, s16 h1A, s16 h1E, s16 h16, s16 h3C, s32 w64, s32 owner,
                        s32 u0, s32 u1, s32 u2, s32 u3, s32 u4, s32 u5,
                        s32 w58, s32 w5C, s32 w60, s16 h36)
{
    vu0_v4 delta;
    vu0_v4 axis;
    vu0_v4 zero;
    vu0_v4 sphere;
    vu0_v4 diff;
    M_003EE6E8 *self = (M_003EE6E8 *)func_003C24B0(0x1D46, 0x80);
    V_003EE6E8 *v;
    f32 a;

    if (self != 0) {
        self->b30 = 0xFF;
        self->state = 0;
        self->h32 = 0xFF;
        v = self->vars;
        *(vu0_q *)&self->pos = *pos;
        self->pos.w = 1.0f;
        vec_sub_ba(&delta, &D_L20_001E2E80_003EE6E8[D_001D52F0].pos, &self->pos);
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
        v->h32 = h32;
        v->h1C = h1C;
        v->fC = scale;
        v->h30 = h30;
        v->h12 = v->h10 = 50;
        v->f0 = scale * 2.0f;
        v->f4 = scale * 4.0f;
        v->w38 = owner;
        v->w40 = 0xDF;
        v->w44 = 0;
        v->w4C = 0;
        v->w50 = 0xDF;
        v->h1A = h1A;
        v->h1E = h1E;
        v->h18 = h18;
        v->h16 = h16;
        v->h3C = h3C;
        v->w54 = 0xDF;
        v->w48 = 0xFF;
        v->h3E = 7;
        v->w58 = w58;
        v->w5C = w5C;
        v->w60 = w60;
        v->f6C = f6C;
        v->f68 = f68;
        v->w64 = w64;
        v->h36 = h36;
        qzero(&zero);
        if (owner != 0) {
            func_L01_0044C870((u8 *)self, owner, (u8 *)&self->pos, &zero);
        }
        *(vu0_q *)&sphere = *(vu0_q *)&self->pos;
        sphere.w = scale * 3.0f;
        if (func_L01_00459590(&sphere, 0, 128.0f) == 1) {
            v->h14 = 8;
            v->f8 = 0.125f;
            if (notify != 0 && func_L01_0040E548(pos, &D_L20_001E2E80_003EE6E8[D_001D52F0]) < 2304.0f) {
                D_L20_001E2E80_003EE6E8[0].w28 = 0x21;
                D_L20_001E2E80_003EE6E8[0].f20 = 0.075f;
                D_L20_001E2E80_003EE6E8[0].w2C = 0;
            }
            if (v->h18 != 0) {
                vec_sub_ab(&diff, &self->pos, &D_L20_001E2E80_003EE6E8[D_001D52F0].pos);
                func_0038CF68(&diff, &diff, 1.0f);
                a = 1.5707964f - func_0038D0C8(func_0038CE68(&diff, &D_L20_001E2E80_003EE6E8[D_001D52F0].v380));
                v->h18 = 0;
                if (a < 0.45378560f) {
                    v->h18 = 1;
                }
            }
        } else {
            v->h14 = 0;
            v->h18 = 0;
        }
        func_L20_003EF550((u8 *)self, &axis, &zero, last);
    }
    return self;
}
/* localdecomp:end func_L20_003EE6E8 */
