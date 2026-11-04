#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

extern f32 D_L31_001DD018;
extern float D_L31_001DD09C;
extern float D_L31_001DD0A0;
extern u8 D_L31_001D66B0[];
extern void func_L30_0034CB68(s32, u8 *, s32, s32, s32, s32, float, float);


/* localdecomp:start func_L31_00349D18 */
__asm__(".extern D_L31_001DD0EC, 4");
__asm__(".extern D_L31_001DD0E8, 4");
extern f32 D_L31_001DD0EC;
extern f32 D_L31_001DD0E8;
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D0B0(f32);

void func_L31_00349D18(Obj_00349D18 *o, f32 *out1, f32 *out2, f32 t) {
    Vec_00349D18 *p;
    f32 g;
    f32 s;
    f32 r;
    p = o->w68;
    out1[0] = func_003C4088(p->f10, p->f0, t);
    s = func_003C4088(p->f18, p->f8, t);
    out1[2] = s;
    s = s + p->f24 * 4.0f * t * (1.0f - t);
    g = D_L31_001DD0EC * t;
    out1[2] = s;
    r = func_0038DB48(g);
    out2[0] = D_L31_001DD0E8 * func_0038D0B0(r);
}
/* localdecomp:end func_L31_00349D18 */
