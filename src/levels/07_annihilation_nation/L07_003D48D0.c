#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003D48D0 */
/* Adapted from func_L07_003D48D0, the level 6 sibling. */
typedef struct UV_003D48D0 { f32 u, v; } UV_003D48D0;
typedef struct Quad_003D48D0 {
    u8 vertices[0x50];
    UV_003D48D0 uv[4];
    unsigned long regs[4];
} Quad_003D48D0;
typedef struct Context_003D48D0 { u8 bytes[0x40]; } Context_003D48D0;
typedef struct State_003D48D0 { s32 timer; } State_003D48D0;
typedef struct Moby_003D48D0 {
    u8 pad0[0x20]; u8 state;
    u8 pad21[0x47]; State_003D48D0 *data;
    u8 pad6C[0x3E]; s16 type;
    u8 padAC[0x44]; f32 angle;
} Moby_003D48D0;
extern f32 D_L07_001DE7C8[] __attribute__((section(".sdata")));
__asm__(".extern D_L07_001DE7C8, 32");
extern f32 D_L07_001DE7CC[] __attribute__((section(".sdata")));
__asm__(".extern D_L07_001DE7CC, 28");
extern void func_0038D2A0(Context_003D48D0 *);
extern unsigned long func_00389598(s32);
extern void func_L06_00359C38(u8 *a0, s32 a1, s32 a2, f32 f);
extern void func_L06_00359B60(u8 *a0, u8 *a1, f32 scale, f32 angle);
extern void func_003D2DA0(Quad_003D48D0 *, Context_003D48D0 *, s32);
extern void func_L06_00359CA8(s32 arg0, s32 arg1);
void func_L07_003D48D0(Moby_003D48D0 *m) {
    Quad_003D48D0 q;
    Context_003D48D0 ctx;
    State_003D48D0 *d;
    f32 t, blend, fade;
    s32 i;
    if (!m || m->state == 0xFE || m->state == 0xFD) return;
    if (m->type != 0x1C81) return;
    d = m->data;
    if (m->state < 3) return;
    if (m->state == 3) t = 1.0f - (f32)d->timer / 60.0f;
    else t = 1.0f;
    func_0038D2A0(&ctx);
    q.regs[1] = func_00389598(0x27);
    q.regs[2] = 0xFF9000000260UL;
    q.regs[3] = 0x8000000044UL;
    q.regs[0] = 0;
    for (i = 0; i < 4; i++) {
        q.uv[i].u = D_L07_001DE7C8[i * 2];
        q.uv[i].v = D_L07_001DE7CC[i * 2];
    }
    switch (m->state) {
    case 3:
        if (t >= 0.0f && t < 0.5f) {
            blend = (t - 0.0f) * 2.0f;
            func_L06_00359C38((u8 *)&q, 0x20A0A0A0, 0x80A0A0A0, blend);
            fade = 1.0f - blend;
            func_L06_00359B60((u8 *)d, (u8 *)&q, 0.8f + fade * 0.8f * 0.5f, m->angle + fade * 0.7853981852531433f);
            func_003D2DA0(&q, &ctx, 0);
            func_L06_00359B60((u8 *)d, (u8 *)&q, 0.8f - fade * 0.8f * 0.5f, m->angle + fade * -0.7853981852531433f);
            func_003D2DA0(&q, &ctx, 0);
        }
        if (t >= 0.5f && t < 0.9f) {
            blend = (t - 0.5f) / 0.3999999761581421f;
            func_L06_00359C38((u8 *)&q, 0x60A0A0A0, 0x00A0A0A0, blend);
            func_L06_00359B60((u8 *)d, (u8 *)&q, 0.8f + blend * 0.8f * 0.05f, m->angle);
            func_003D2DA0(&q, &ctx, 0);
        }
        if (t >= 0.5f && t < 1.0f) {
            blend = (t - 0.5f) * 2.0f;
            func_L06_00359C38((u8 *)&q, 0x80FFFFFF, 0x00808080, blend);
            func_L06_00359B60((u8 *)d, (u8 *)&q, 0.8f + blend * 0.8f * 0.25f, m->angle + blend * 0.2617993950843811f);
            func_003D2DA0(&q, &ctx, 0);
            func_L06_00359B60((u8 *)d, (u8 *)&q, 0.8f - blend * 0.8f * 0.25f, m->angle + blend * -0.2617993950843811f);
            func_003D2DA0(&q, &ctx, 0);
        }
        if (t >= 0.5f && t < 0.7f) {
            func_L06_00359C38((u8 *)&q, 0x10808080, 0x800000FF, (t - 0.5f) / 0.19999998807907104f);
            func_L06_00359B60((u8 *)d, (u8 *)&q, 0.8f, m->angle);
            func_003D2DA0(&q, &ctx, 0);
        }
        if (t < 0.7f) break;
    case 4:
    case 5:
        func_L06_00359CA8((s32)&q, 0x800000FF);
        func_L06_00359B60((u8 *)d, (u8 *)&q, 0.8f, m->angle);
        func_003D2DA0(&q, &ctx, 0);
        break;
    }
}
/* localdecomp:end func_L07_003D48D0 */

/* localdecomp:start func_L07_003D4DB8 */
typedef struct { s32 id; u8 pad4[4]; u8 stage; u8 pad9[0x24 - 9]; s32 index; f32 progress; } Vars_003D4DB8;
extern u8 *D_L07_001DF41C_003D4DB8[] __attribute__((section(".sdata")));
extern void func_L07_003D5008(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_00456230(u8 *, s32);
extern s32 func_L07_00334868(s32);
extern void func_L07_003D51D8(u8 *);

void func_L07_003D4DB8(u8 *moby) {
    Vars_003D4DB8 *vars;
    func_L07_003D5008(moby);
    vars = *(Vars_003D4DB8 **)(moby + 0x68);
    switch (moby[0x20]) {
    case 1:
        if (vars->stage >= 2) func_L01_004450F0(moby, 4, -1);
        break;
    case 2:
        if (vars->stage >= 3) func_L01_004450F0(moby, 6, -1);
        if (vars->stage < 2) func_L01_004450F0(moby, 5, -1);
        break;
    case 3:
        if (func_L01_004561B8(moby)) func_L01_00456230(D_L07_001DF41C_003D4DB8[0] + (vars->index << 8), 1);
        if (func_L07_00334868(vars->id) != 4) func_L01_00456230(D_L07_001DF41C_003D4DB8[0] + (vars->index << 8), 0);
        if (vars->stage < 3) {
            func_L01_00456230(D_L07_001DF41C_003D4DB8[0] + (vars->index << 8), 0);
            func_L01_004450F0(moby, 7, -1);
        }
        break;
    case 4:
        vars->progress += 0.012f;
        if (vars->progress >= 1.0f) {
            vars->progress = 1.0f;
            func_L01_004450F0(moby, 2, -1);
        }
        func_L07_003D51D8(moby);
        break;
    case 5:
        vars->progress -= 0.012f;
        if (vars->progress <= 0.0f) {
            vars->progress = 0.0f;
            func_L01_004450F0(moby, 1, -1);
        }
        func_L07_003D51D8(moby);
        break;
    case 6:
        vars->progress += 0.012f;
        if (vars->progress >= 2.0f) {
            vars->progress = 2.0f;
            func_L01_004450F0(moby, 3, -1);
        }
        func_L07_003D51D8(moby);
        break;
    case 7:
        vars->progress -= 0.012f;
        if (vars->progress <= 1.0f) {
            vars->progress = 1.0f;
            func_L01_004450F0(moby, 2, -1);
        }
        func_L07_003D51D8(moby);
        break;
    }
}
/* localdecomp:end func_L07_003D4DB8 */
