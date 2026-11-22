#include "common.h"

/* localdecomp:start func_L03_003D0598 */
extern s32 func_L01_00447490(u8 *, s32, s32);
extern void func_L03_003D02A0(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);
void func_L03_003D0598(u8 *a0) {
    if (func_L01_00447490(a0, -1, 0)) {
        func_L03_003D02A0(a0, 31, 1, 7888, 1, 1, 1, 0, 0xC050C020, -1.0f, 2.5f);
    }
}
/* localdecomp:end func_L03_003D0598 */

/* localdecomp:start func_L03_003D0608 */
#include "vu0.h"
typedef int Q_3D0608 __attribute__((mode(TI)));
typedef union { f32 f[4]; Q_3D0608 q; } V_3D0608_003D0608;
extern void func_003C4C18(void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00470668_003D0608(void *, void *, s32, f32);

static inline void copy_3D0608(V_3D0608_003D0608 *d, V_3D0608_003D0608 *s) { d->q = s->q; }

void func_L03_003D0608(u8 *m, s32 row, s32 count, f32 a, f32 b, f32 c, f32 d, f32 e, f32 g, f32 h) {
    V_3D0608_003D0608 vel;
    V_3D0608_003D0608 pos;
    V_3D0608_003D0608 off;
    s16 r = row;
    s32 i;

    for (i = 0; i < count; i++) {
        pos.q = ((Q_3D0608 *)m)[1];
        func_003C4C18(&pos, c);
        copy_3D0608(&off, &((V_3D0608_003D0608 *)m)[r + 12]);
        func_0038CF68(&off, &off, *(f32 *)(m + 0x2C) / (*(f32 **)(m + 0x24))[0x24/4] * a);
        pos.f[2] += *(f32 *)(m + 0x2C) / (*(f32 **)(m + 0x24))[0x24/4] * b;
        vec_add_ab(&pos, &pos, &off);
        copy_3D0608(&vel, &((V_3D0608_003D0608 *)m)[r + 12]);
        func_0038CE20(&vel, &vel, func_003824E0(g * 0.5f, g) * 0.0200000014f);
        vel.f[0] += func_003824E0(-d, d);
        vel.f[1] += func_003824E0(-d, d);
        func_L01_00470668_003D0608(&pos, &vel, 0x32, h * 0.000400000019f);
    }
}
/* localdecomp:end func_L03_003D0608 */

/* localdecomp:start func_L03_003D07E0 */
extern void func_L03_003D0608(u8 *, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_00382498(s32, s32);

void func_L03_003D07E0(u8 *obj)
{
    if (*(u16 *)(obj + 150) == 0) {
        func_L03_003D0608(obj, 1, 3, -0.3f, 2.5f, 0.15f, 0.03f, 1.0f, -8.0f, 7.0f);
        *(u16 *)(obj + 150) = func_00382498(50, 400);
    }
    *(u16 *)(obj + 150) -= 1;
}
/* localdecomp:end func_L03_003D07E0 */
