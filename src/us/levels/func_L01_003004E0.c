#include "common.h"

/* NTSC-U counterpart of func_L01_00300550 (src/levels/shared/L01_003002A8.c): 0.004 -> 0.00277778; 25 -> 30 */
#include "vu0.h"

/* localdecomp:start func_L01_003004E0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00300550;
typedef struct {
    f32 x0;
    f32 x4;
    f32 f8;
    u8 padC[0x1C - 0xC];
    s32 w1C;
    f32 f20;
    s32 w24;
    f32 f28;
    f32 f2C;
} G_00300550;
typedef struct {
    u8 pad0[0x10];
    V_00300550 pos;
    u8 pad20[3];
    u8 b23;
    u8 pad24[0x31 - 0x24];
    u8 b31;
    u8 pad32[0x68 - 0x32];
    G_00300550 *x68;
    u8 pad6C[0xF0 - 0x6C];
    f32 fF0;
    u8 padF4[4];
    f32 fF8;
} O_00300550;

extern f32 D_L01_001DC49C;
__asm__(".extern D_L01_001DC49C, 4");
extern f32 func_00389380(f32, f32);
extern s32 func_00388398(void *);
extern s32 func_L01_0040BAF0(void *);
extern void func_003BD360(u8 *);

void func_L01_003004E0(O_00300550 *o) {
    G_00300550 *g = o->x68;
    f32 t;

    vec_add_ab(&o->pos, &o->pos, g);
    g->f8 = g->f8 - 0.00277777785f;
    g->x0 = g->x0 * D_L01_001DC49C;
    g->x4 = g->x4 * D_L01_001DC49C;
    if (g->f8 < g->f20) {
        g->f8 = g->f20;
    }
    o->fF8 = func_00389380(o->fF8, g->f28);
    t = func_00389380(o->fF0, g->f2C * (f32)g->w24);
    o->fF0 = t;
    if (0.7853982f < fabs_asm(t)) {
        g->w24 = -g->w24;
    }
    if (func_00388398(&g->w1C) != 0 || o->b31 == 0) {
        func_003BD360((u8 *)o);
        return;
    }
    if (g->w1C < 30 && func_L01_0040BAF0(&o->b23) != 0) {
        func_003BD360((u8 *)o);
    }
}
/* localdecomp:end func_L01_003004E0 */
