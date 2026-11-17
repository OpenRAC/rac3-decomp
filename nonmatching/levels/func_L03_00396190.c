/* near miss (level 3, Starship Phoenix): 28 differences, scheduling only (every instruction is right, the quad struct of func_L01_00307058 with its colour, uv and GS words): the first vector add's load of a->pos goes before the centre copy's in retail, the call's a2/a1 zero moves and the x6C/x68 uv stores are in another order; 64 random orders of the uv stores and 200 of the middle stores tried, all 28 or worse */
#include "common.h"

/* localdecomp:start func_L03_00396190 */
#include "vu0.h"
typedef struct {
    vu0_v4 v[4];
    s32 color[4];
    f32 x50;
    s32 x54;
    f32 x58, x5C, x60;
    s32 x64;
    f32 x68, x6C;
    long x70, x78, x80, x88;
    vu0_v4 c;
} Q_00396190;
typedef struct { u8 pad0[0x20]; s32 i20; u8 pad24[0x58 - 0x24]; f32 f58; u8 pad5C[0x61 - 0x5C]; u8 b61; } S_00396190;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_00396190 *p68; } A_00396190;
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern u8 D_L03_001E2840[];
extern f32 D_001DE2E0_sda;
__asm__(".extern D_001DE2E0_sda, 4");
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, s32, s32);

void func_L03_00396190(void *arg, f32 r) {
    A_00396190 *a = arg;
    S_00396190 *s = a->p68;
    u8 *e = D_L03_001DF99C + (s->i20 << 8);
    vu0_v4 dir;
    vu0_v4 d;
    Q_00396190 q;
    if (e != 0) {
        vec_sub_ba(&dir, e + 0x10, &a->pos);
        func_0038CE90(&d, &dir, D_L03_001E2840);
        func_0038CF68(&d, &d, r);
        q.x78 = func_00389598(s->b61 + 0x64);
        q.x80 = 0xFF9000000260L;
        q.x88 = 0x6000000062L;
        q.x70 = 0;
        q.color[3] = 0x60408040;
        q.color[2] = 0x60408040;
        q.color[1] = 0x60408040;
        q.color[0] = 0x60408040;
        vec_copy(&q.c, &a->pos);
        vec_add_ab(&q.v[0], &a->pos, &d);
        vec_sub_ba(&q.v[1], &q.c, &d);
        vec_add_ba(&q.v[2], e + 0x10, &d);
        vec_sub_ab(&q.v[3], e + 0x10, &d);
        q.x50 = -D_001DE2E0_sda + s->f58;
        q.x54 = 0;
        q.x58 = -D_001DE2E0_sda + s->f58;
        q.x5C = 1.0f;
        q.x60 = s->f58 + D_001DE2E0_sda;
        q.x64 = 0;
        q.x68 = s->f58 + D_001DE2E0_sda;
        q.x6C = 1.0f;
        func_003D2DA0(&q, 0, 0);
    }
}
/* localdecomp:end func_L03_00396190 */
