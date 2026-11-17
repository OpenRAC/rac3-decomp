/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_003004E0, the NTSC-U twin of func_L01_00300550, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as" (src/levels/shared/L01_002FEA20.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses").
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_002FEA20 (src/levels/shared/L01_002FEA20.c) */
/* localdecomp:start func_L01_003004E0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003004E0;
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
} G_003004E0;
typedef struct {
    u8 pad0[0x10];
    V_003004E0 pos;
    u8 pad20[3];
    u8 b23;
    u8 pad24[0x31 - 0x24];
    u8 b31;
    u8 pad32[0x68 - 0x32];
    G_003004E0 *x68;
    u8 pad6C[0xF0 - 0x6C];
    f32 fF0;
    u8 padF4[4];
    f32 fF8;
} O_003004E0;

extern f32 D_001DC49C_sda;
__asm__(".extern D_001DC49C_sda, 4");
extern f32 func_00389380(f32, f32);
extern s32 func_00388398(void *);
extern s32 func_L01_0040BAF0(void *);
extern void func_003BD360(void *);

void func_L01_003004E0(O_003004E0 *o) {
    G_003004E0 *g = o->x68;
    f32 t;

    vec_add_ab(&o->pos, &o->pos, g);
    g->f8 = g->f8 - 0.0027777778f;
    g->x0 = g->x0 * D_001DC49C_sda;
    g->x4 = g->x4 * D_001DC49C_sda;
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
        func_003BD360(o);
        return;
    }
    if (g->w1C < 0x1E && func_L01_0040BAF0(&o->b23) != 0) {
        func_003BD360(o);
    }
}
/* localdecomp:end func_L01_003004E0 */
