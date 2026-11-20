#include "common.h"

/* localdecomp:start func_L20_003EBA98 */
typedef struct UV_003EBA98 { f32 u,v; } UV_003EBA98;
typedef struct Quad_003EBA98 {
    u8 vertices[0x50];
    UV_003EBA98 uv[4];
    unsigned long regs[4];
} Quad_003EBA98;
typedef struct Context_003EBA98 { u8 bytes[0x40]; } Context_003EBA98;
typedef struct State_003EBA98 { s32 timer; } State_003EBA98;
typedef struct Moby_003EBA98 {
    u8 pad0[0x20]; u8 state;
    u8 pad21[0x47]; State_003EBA98 *data;
    u8 pad6C[0x84]; f32 angle;
} Moby_003EBA98;
extern s32 D_L20_001DF288;
__asm__(".extern D_L20_001DF288, 4");
extern s32 D_L20_001DF2C8;
__asm__(".extern D_L20_001DF2C8, 4");
extern f32 D_L20_001DF2CC;
__asm__(".extern D_L20_001DF2CC, 4");
extern f32 D_L20_001DF2F8[], D_L20_001DF2FC[];
extern void func_0038D2A0(Context_003EBA98 *);
extern unsigned long func_00389598(s32);
extern void func_L06_00359C38(Quad_003EBA98 *,u32,u32,f32);
extern void func_L06_00359B60(State_003EBA98 *,Quad_003EBA98 *,f32,f32);
extern void func_003D2DA0(Quad_003EBA98 *,Context_003EBA98 *,s32);
extern void func_L06_00359CA8(Quad_003EBA98 *,u32);
void func_L20_003EBA98(Moby_003EBA98 *m) {
    Quad_003EBA98 q;
    Context_003EBA98 ctx;
    State_003EBA98 *d;
    f32 t, blend, fade;
    s32 i;
    d = m->data;
    if (m->state < 3) return;
    if (m->state == 3) t = 1.0f - (f32)d->timer / (f32)D_L20_001DF288;
    else t = 1.0f;
    func_0038D2A0(&ctx);
    q.regs[1] = func_00389598(D_L20_001DF2C8);
    q.regs[2] = 0xFF9000000260UL;
    q.regs[3] = 0x8000000048UL;
    q.regs[0] = 0;
    for (i = 0; i < 4; i++) {
        q.uv[i].u = D_L20_001DF2F8[i * 2];
        q.uv[i].v = D_L20_001DF2FC[i * 2];
    }
    switch (m->state) {
    case 3:
        if (t >= 0.0f && t < 0.5f) {
            blend = (t - 0.0f) * 2.0f;
            func_L06_00359C38(&q,0x20C03030,0x80C03030,blend);
            fade = 1.0f - blend;
            func_L06_00359B60(d,&q,D_L20_001DF2CC + fade * D_L20_001DF2CC * 0.5f,m->angle + fade * 0.7853981852531433f);
            func_003D2DA0(&q,&ctx,0);
            func_L06_00359B60(d,&q,D_L20_001DF2CC - fade * D_L20_001DF2CC * 0.5f,m->angle + fade * -0.7853981852531433f);
            func_003D2DA0(&q,&ctx,0);
        }
        if (t >= 0.5f && t < 0.9f) {
            blend = (t - 0.5f) / 0.3999999761581421f;
            func_L06_00359C38(&q,0x6000F0F0,0x0000F0F0,blend);
            func_L06_00359B60(d,&q,D_L20_001DF2CC + blend * D_L20_001DF2CC * 0.05f,m->angle);
            func_003D2DA0(&q,&ctx,0);
        }
        if (t >= 0.5f && t < 1.0f) {
            blend = (t - 0.5f) * 2.0f;
            func_L06_00359C38(&q,0x80800080,0x04F00060,blend);
            func_L06_00359B60(d,&q,D_L20_001DF2CC + blend * D_L20_001DF2CC * 0.25f,m->angle + blend * 0.2617993950843811f);
            func_003D2DA0(&q,&ctx,0);
            func_L06_00359B60(d,&q,D_L20_001DF2CC - blend * D_L20_001DF2CC * 0.25f,m->angle + blend * -0.2617993950843811f);
            func_003D2DA0(&q,&ctx,0);
        }
        if (t >= 0.5f && t < 0.7f) {
            func_L06_00359C38(&q,0x102040D0,0x802050F0,(t - 0.5f) / 0.19999998807907104f);
            func_L06_00359B60(d,&q,D_L20_001DF2CC,m->angle);
            func_003D2DA0(&q,&ctx,0);
        }
        if (t < 0.7f) break;
    case 4:
    case 5:
        func_L06_00359CA8(&q,0x802050F0);
        func_L06_00359B60(d,&q,D_L20_001DF2CC,m->angle);
        func_003D2DA0(&q,&ctx,0);
        break;
    }
}
/* localdecomp:end func_L20_003EBA98 */
