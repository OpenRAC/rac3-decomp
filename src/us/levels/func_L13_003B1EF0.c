#include "common.h"

typedef int Quad_3B4618 __attribute__((mode(TI)));

/* localdecomp:start func_L13_003B1EF0 */
#include "vu0.h"

extern f32 D_L13_001DE8F4;
__asm__(".extern D_L13_001DE8F4, 4");
extern f32 D_L13_001DE8F8;
__asm__(".extern D_L13_001DE8F8, 4");
extern f32 D_L13_001DE8FC;
__asm__(".extern D_L13_001DE8FC, 4");
extern f32 D_L13_001DE900;
__asm__(".extern D_L13_001DE900, 4");
extern s32 D_L13_001DE904;
__asm__(".extern D_L13_001DE904, 4");
extern u32 D_L13_001DE908;
__asm__(".extern D_L13_001DE908, 4");
extern void func_L01_0044E010(void *, void *, s32);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_004084B0(void *, void *, s32, s32, u32, u32, u32, u32, f32, f32, f32);

void func_L13_003B1EF0(void *a0) {
    vu0_v4 m0, m1, m2, m3, m4, m5, m6;
    f32 t;
    u8 *v;

    v = *(u8 **)((u8 *)a0 + 0x68);
    func_L01_0044E010(a0, &m0, 1);
    *(Quad_3B4618 *)&m2 = *(Quad_3B4618 *)v;
    func_00388830(&m0, &m0, 1.0f);
    func_00388830(&m2, &m2, -1.0f);
    func_00388758(&m1, &m0, &m2);
    func_00388830(&m1, &m1, 1.0f);
    *(Quad_3B4618 *)&m3 = *(Quad_3B4618 *)(v + 0x10);
    func_003886E8(&m0, &m0, D_L13_001DE8F8 * *(f32 *)(v + 0x2C));
    func_003886E8(&m1, &m1, D_L13_001DE900 * *(f32 *)(v + 0x2C));
    func_003886E8(&m2, &m2, D_L13_001DE8FC);
    func_003886E8(&m4, &m2, -1.0f);
    vec_add_ab(&m3, &m3, &m4);
    t = *(f32 *)(v + 0x28) + D_L13_001DE8F4;
    *(f32 *)(v + 0x28) = t;
    if (1.0f < t) {
        *(f32 *)(v + 0x28) = t - 1.0f;
    }
    func_00388830(&m5, v, *(f32 *)(v + 0x30));
    vec_add_ab(&m5, v + 0x10, &m5);
    *(Quad_3B4618 *)&m6 = *(Quad_3B4618 *)(v + 0x10);
    func_L01_004084B0(&m6, &m5, D_L13_001DE904, 0, D_L13_001DE908, D_L13_001DE908, D_L13_001DE908, D_L13_001DE908,
                      *(f32 *)(v + 0x2C), *(f32 *)(v + 0x2C) * 1.5f, *(f32 *)(v + 0x28));
}
/* localdecomp:end func_L13_003B1EF0 */
