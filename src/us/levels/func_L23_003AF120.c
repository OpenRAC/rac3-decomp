#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef int u128_t __attribute__((mode(TI)));
typedef struct { s32 x0; void *x4; s32 x8; s32 xC; V4 pos; } Vars_3AF120;
typedef struct { u8 pad0[0x18]; u8 b18; u8 b19; s16 h1A; u8 pad1C[4]; s32 x20; u8 pad24[0xC]; } Hit_3AF120;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 pad20[0x48]; Vars_3AF120 *vars; u8 pad6C[0x2A]; u16 x96; u8 pad98[0x12]; s16 xAA;
} M_3AF120;

extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern s32 func_L01_0032FE90(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 D_L23_001DECC0;
__asm__(".extern D_L23_001DECC0, 16");

/* NTSC-U counterpart of func_L23_003B0A20. */
/* localdecomp:start func_L23_003AF120 */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern void func_003BEB58(void *, void *, void *, f32);
extern void func_L01_00443610(void *, void *, s32, f32);
extern s32 func_003CF790(void *, f32, s32, void *, void *);
extern void func_003BD360(void *);
extern void func_L01_00402498(void *, void *);
void func_L23_003AF3D8(u8 *o);

void func_L23_003AF120(M_3AF120 *o)
{
    Vars_3AF120 *v = o->vars;
    V4 d;
    V4 n;
    Hit_3AF120 hit;
    f32 t;
    V4 *pos;

    if (v->xC != 0) {
        vec_sub_ba(&d, &D_001A4BE0.pickup_point, &o->pos);
        func_00388830(&d, &d, func_00388770(&v->pos));
        t = (f32)o->x96 / 60.0f;
        n = v->pos;
        func_003BEB58(&v->pos, &n, &d, 0.5f < t ? 0.5f : t);
    }
    pos = &o->pos;
    d = *pos;
    vec_add_ab(&n, &d, &v->pos);
    func_L01_00443610(&hit, o, 0x10003, v->xC != 0 ? 10.0f : 5.0f);
    hit.b18 = 3;
    hit.b19 = 3;
    hit.h1A = o->xAA;
    hit.x20 = 0;
    if (func_003CE740(&d, &n, 0, v->x4, &hit) != 0 ||
        func_003CF790(&n, 0.2f, 0, v->x4, &hit) != 0) {
        func_L01_0032FE90(pos, v->xC != 0 ? 1.0f : 0.2f, 1, 2, 0x14, 2, 0x14, 0x14, (s16)(v->xC * 8), 0.0f, 0.0f, 2.0f,
                          (s16)v->xC, (s16)v->xC, (s16)v->xC, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003BD360(o);
        return;
    }
    *(u128_t *)pos = *(u128_t *)&n;
    o->x96++;
    if (v->x8 < D_L23_001DECC0)
        func_003BD360(o);
    else
        func_L01_00402498(func_L23_003AF3D8, o);
}
/* localdecomp:end func_L23_003AF120 */
