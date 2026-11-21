#include "common.h"

/* localdecomp:start func_L09_00350CB0 */
#include "vu0.h"
typedef struct { f32 x, y; } P2_350CB0;
typedef struct {
    vu0_v4 pos[4];
    u32 col[4];
    P2_350CB0 uv[4];
    long f70;
    u8 pad78[8];
    unsigned long tag;
} G_350CB0;
typedef struct {
    vu0_v4 v0;
    f32 p10[3];
    f32 f1C;
    u8 p20[8];
    f32 f28;
} V_350CB0;
typedef struct {
    u8 p00[0x10];
    vu0_v4 pos;
    u8 p20[0x48];
    V_350CB0 *vars;
} O_350CB0;
extern vu0_v4 D_L09_001E2B00;
extern f32 D_L09_001DD3E8 __attribute__((section(".data")));
extern void func_L01_0034D840(void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L09_00350CB0(u8 *a0, s32 a1, f32 a2, s32 a3, f32 a4, f32 a5, s32 a6, s32 a7, u8 *moby)
{
    G_350CB0 g;
    vu0_v4 v90, vA0, vB0, vC0, vD0;
    O_350CB0 *o = (O_350CB0 *)moby;
    V_350CB0 *vars = o->vars;
    f32 ang, s, c;
    s32 i;
    s32 j;

    func_L01_0034D840(&g);
    func_003D93B0(&g, 0x1C, 1, 0x80);
    g.col[0] = g.col[1] = 0xFF1414FF;
    g.col[2] = g.col[3] = 0x80204080;
    g.uv[0].x = 0; g.uv[0].y = 0;
    g.uv[1].x = 0; g.uv[1].y = 1.0f;
    g.uv[2].x = 1.0f; g.uv[2].y = 0;
    g.uv[3].x = 1.0f; g.uv[3].y = 1.0f;
    for (i = 0; i < 4; i++) {
        g.uv[i].x -= vars->f28;
        if (g.uv[i].x <= 7.0f) {
            g.uv[i].x += 7.0f;
        }
    }
    vars->f28 += 0.1f;
    if (4.0f <= vars->f28) {
        vars->f28 -= 4.0f;
    }
    vec_sub_ab(&v90, &o->pos, &D_L09_001E2B00);
    func_0038CF68(&vA0, vars, -2.0f);
    vec_add_ba(&vB0, &o->pos, &vA0);
    func_0038CE90(&vC0, &v90, &vA0);
    func_0038CF68(&vC0, &vC0, 0.2f);
    func_0038CF68(&vD0, vars, D_L09_001DD3E8);
    vec_add_ba(&vD0, &o->pos, &vD0);
    vec_add_ab(&g.pos[0], &vD0, &vC0);
    vec_sub_ab(&g.pos[1], &vD0, &vC0);
    vec_add_ab(&g.pos[2], &vB0, &vC0);
    vec_sub_ba(&g.pos[3], &vB0, &vC0);
    func_003D2DA0(&g, 0, 0);
    g.col[0] = g.col[2];
    g.col[1] = g.col[3];
    g.col[2] = g.col[3] = 0x801010;
    g.pos[0] = g.pos[2];
    g.pos[1] = g.pos[3];
    vec_add_ba(&g.pos[2], &g.pos[2], &vA0);
    vec_add_ab(&g.pos[3], &g.pos[3], &vA0);
    func_003D2DA0(&g, 0, 0);
    func_0038CF68(&vA0, vars, -4.0f);
    g.uv[0].x = 0; g.uv[0].y = 0;
    g.uv[1].x = 0; g.uv[1].y = 1.0f;
    g.uv[2].x = 1.0f; g.uv[2].y = 0;
    g.uv[3].x = 1.0f; g.uv[3].y = 1.0f;
    ang = vars->f1C;
    s = func_0038D098(ang);
    c = func_0038D0B0(ang);
    for (j = 0; j < 4; j++) {
        f32 t[2];
        t[0] = g.uv[j].x - 0.5f;
        t[1] = g.uv[j].y - 0.5f;
        g.uv[j].x = t[0] * s - t[1] * c;
        g.uv[j].y = t[0] * c + t[1] * s;
        g.uv[j].x += 0.5f;
        g.uv[j].y += 0.5f;
    }
    vars->f1C = func_0038DAB8(vars->f1C, 0.17453292f);
    func_003D93B0(&g, 8, 1, 0x80);
    g.f70 = 5;
    g.col[0] = g.col[1] = 0x5A141480;
    g.col[2] = g.col[3] = 0x808080;
    func_0038CF68(&vC0, &vC0, 0.2f);
    func_0038CF68(&vD0, vars, D_L09_001DD3E8);
    vec_add_ba(&vD0, &o->pos, &vD0);
    vec_add_ab(&g.pos[0], &vD0, &vC0);
    vec_sub_ab(&g.pos[1], &vD0, &vC0);
    vec_add_ab(&vB0, &vD0, &vA0);
    vec_add_ab(&vB0, &vB0, &vA0);
    vec_add_ab(&g.pos[2], &vB0, &vC0);
    vec_sub_ba(&g.pos[3], &vB0, &vC0);
    func_003D2DA0(&g, 0, 0);
    g.col[0] = g.col[1] = 0x5A141480;
    g.col[2] = g.col[3] = 0x808080;
    func_0038CF68(&vC0, &vC0, 0.1f);
    func_0038CF68(&vD0, vars, 0.75f);
    vec_add_ba(&vD0, &o->pos, &vD0);
    vec_add_ab(&g.pos[0], &vD0, &vC0);
    vec_sub_ab(&g.pos[1], &vD0, &vC0);
    vec_add_ab(&vB0, &vD0, &vA0);
    vec_add_ab(&vB0, &vB0, &vA0);
    vec_add_ab(&g.pos[2], &vB0, &vC0);
    vec_sub_ba(&g.pos[3], &vB0, &vC0);
    func_003D2DA0(&g, 0, 0);
    g.col[0] = g.col[1] = 0x3C141480;
    g.col[2] = g.col[3] = 0x808080;
    func_0038CF68(&vC0, &vC0, 0.4f);
    func_0038CF68(&vD0, vars, 0.75f);
    vec_add_ba(&vD0, &o->pos, &vD0);
    vec_add_ab(&g.pos[0], &vD0, &vC0);
    vec_sub_ab(&g.pos[1], &vD0, &vC0);
    vec_add_ab(&vB0, &vD0, &vA0);
    vec_add_ab(&vB0, &vB0, &vA0);
    vec_add_ab(&g.pos[2], &vB0, &vC0);
    vec_sub_ba(&g.pos[3], &vB0, &vC0);
    func_003D2DA0(&g, 0, 0);
    g.col[0] = g.col[1] = 0x64FFFFFF;
    g.col[2] = g.col[3] = 0x808080;
    func_0038CF68(&vC0, &vC0, 0.2f);
    func_0038CF68(&vD0, vars, 0.0f);
    vec_add_ba(&vD0, &o->pos, &vD0);
    vec_add_ab(&g.pos[0], &vD0, &vC0);
    vec_sub_ab(&g.pos[1], &vD0, &vC0);
    func_0038CF68(&vA0, vars, -0.6f);
    vec_add_ab(&vB0, &vD0, &vA0);
    vec_add_ab(&vB0, &vB0, &vA0);
    vec_add_ab(&g.pos[2], &vB0, &vC0);
    vec_sub_ab(&g.pos[3], &vB0, &vC0);
    func_003D2DA0(&g, 0, 0);
    func_003D9508(&o->pos, 0x10, 0x202020B0, 1, 1.0f, 0.08f, func_00382538());
    func_003D9508(&o->pos, 0x10, 0x80808080, 1, 0.4f, 0.08f, func_00382538());
}
/* localdecomp:end func_L09_00350CB0 */
