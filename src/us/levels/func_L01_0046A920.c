#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_0046DFD0 (src/levels/shared/L01_0046A938.c): gravity -0.00013888889f (60 Hz) for -0.0002f, data at NTSC-U addresses */
/* localdecomp:start func_L01_0046A920 */
typedef struct {
    f32 target;
    f32 base;
    s32 b;
    s32 a;
    f32 scale;
} Sub_0046A920;
typedef struct {
    char pad0[0x4];
    s32 result;
    char pad8[0xA - 0x8];
    s16 timer;
    f32 out;
    char vec[0x20 - 0x10];
    Sub_0046A920 sub;
} Obj_0046A920;
typedef struct {
    u8 pad_00[0x10];
    vu0_v4 pos;
    vu0_v4 vel;
} O_0046A920;

extern f32 D_L01_001E0320;
__asm__(".extern D_L01_001E0320, 16");
extern f32 D_L01_001E0328;
extern void func_003C7CE0(Obj_0046A920 *);

void func_L01_0046A920(O_0046A920 *o)
{
    vu0_v4 g;
    vu0_v4 *p = &o->vel;
    f32 w = p->w;

    if (*(f32 *)((u8 *)o + 0x18) < w) {
        func_003C7CE0((Obj_0046A920 *)o);
        return;
    }
    g = o->vel;
    g.w = 0.0f;
    vec_add_ba(&o->pos, &o->pos, &g);
    g.z = -0.00013888889f;
    g.x = 0.0f;
    g.y = 0.0f;
    vec_add_ba(&o->pos, &o->pos, &D_L01_001E0320);
    g.w = 0.0f;
    vec_add_ba(&o->vel, &g, &o->vel);
    p->w = w + D_L01_001E0328;
}
/* localdecomp:end func_L01_0046A920 */
