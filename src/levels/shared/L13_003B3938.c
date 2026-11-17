#include "common.h"

typedef int Quad_3B4618 __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L13_003B3938);

/* localdecomp:start func_L13_003B3DA8 */
#include "vu0.h"

extern f32 D_L13_001DE8C4;
__asm__(".extern D_L13_001DE8C4, 4");
extern f32 D_L13_001DE8C8;
__asm__(".extern D_L13_001DE8C8, 4");
extern f32 D_L13_001DE8CC;
__asm__(".extern D_L13_001DE8CC, 4");
extern f32 D_L13_001DE8D0;
__asm__(".extern D_L13_001DE8D0, 4");
extern s32 D_L13_001DE8D4;
__asm__(".extern D_L13_001DE8D4, 4");
extern u32 D_L13_001DE8D8;
__asm__(".extern D_L13_001DE8D8, 4");
extern void func_L01_00451290(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, u32, u32, u32, u32, f32, f32, f32);

void func_L13_003B3DA8(void *a0) {
    vu0_v4 m0, m1, m2, m3, m4, m5, m6;
    f32 t;
    u8 *v;

    v = *(u8 **)((u8 *)a0 + 0x68);
    func_L01_00451290(a0, &m0, 1);
    *(Quad_3B4618 *)&m2 = *(Quad_3B4618 *)v;
    func_0038CF68(&m0, &m0, 1.0f);
    func_0038CF68(&m2, &m2, -1.0f);
    func_0038CE90(&m1, &m0, &m2);
    func_0038CF68(&m1, &m1, 1.0f);
    *(Quad_3B4618 *)&m3 = *(Quad_3B4618 *)(v + 0x10);
    func_0038CE20(&m0, &m0, D_L13_001DE8C8 * *(f32 *)(v + 0x2C));
    func_0038CE20(&m1, &m1, D_L13_001DE8D0 * *(f32 *)(v + 0x2C));
    func_0038CE20(&m2, &m2, D_L13_001DE8CC);
    func_0038CE20(&m4, &m2, -1.0f);
    vec_add_ab(&m3, &m3, &m4);
    t = *(f32 *)(v + 0x28) + D_L13_001DE8C4 * 1.2f;
    *(f32 *)(v + 0x28) = t;
    if (1.0f < t) {
        *(f32 *)(v + 0x28) = t - 1.0f;
    }
    func_0038CF68(&m5, v, *(f32 *)(v + 0x30));
    vec_add_ab(&m5, v + 0x10, &m5);
    *(Quad_3B4618 *)&m6 = *(Quad_3B4618 *)(v + 0x10);
    func_L01_0040A8C0(&m6, &m5, D_L13_001DE8D4, 0, D_L13_001DE8D8, D_L13_001DE8D8, D_L13_001DE8D8, D_L13_001DE8D8,
                      *(f32 *)(v + 0x2C), *(f32 *)(v + 0x2C) * 1.5f, *(f32 *)(v + 0x28));
}
/* localdecomp:end func_L13_003B3DA8 */

/* localdecomp:start func_L13_003B3F58 */
#include "vu0.h"

extern void func_L01_00443B88(f32 *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_0046B458(f32 *, s32, s32, s32, s32, f32 *, f32, f32, f32, s32);

void func_L13_003B3F58(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    f32 vel[4];
    f32 pos[4];
    s32 i;
    f32 f20;
    f32 f21;

    for (i = 5; i >= 0; i--) {
        func_L01_00443B88(vel, 0.120000005f, 0.20000002f);
        f20 = func_003824E0(1.0f, 2.0f);
        func_0038CF68(pos, p, *(f32 *)(p + 0x30));
        vec_add_ba(pos, p + 0x10, pos);
        ((void (*)(f32 *, s32, f32, f32, s32, s32, s32, f32 *, f32, s32))func_L01_0046B458)(pos, 8, f20, f20, 0x7F076007, 0, func_00382498(-3, 3), vel, 0.0f, 0);
        f21 = f20 * 0.5f;
        ((void (*)(f32 *, s32, f32, f32, s32, s32, s32, f32 *, f32, s32))func_L01_0046B458)(pos, 8, f21, f21, 0x7F075F07, 0, func_00382498(-3, 3), vel, 0.0f, 0);
    }
}
/* localdecomp:end func_L13_003B3F58 */

INCLUDE_ASM("asm/levels", func_L13_003B40A0);
