#include "common.h"

/* NTSC-U counterpart of func_L02_0039F7D8 (src/levels/02_florana/L02_0039EF28.c) */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
extern void func_L02_0039DA50(void *);

/* localdecomp:start func_L02_0039DA50 */
extern void func_00389158(void *, void *, void *, f32);

void func_L02_0039DA50(void *arg) {
    u8 *self = arg;
    u8 *d;
    vu0_v4 axis;
    vu0_v4 *p;
    s32 i;

    if (self[0x20] != 0) return;
    d = *(u8 **)(self + 0x68);
    *(u128_t *)&axis = 0;
    for (i = 0; i < 4; i++) {
        p = (vu0_v4 *)(d + 0x10) + i;
        p->y = 0.0f;
        p->w = 0.0f;
        p->x = 1.0f;
        p->z = 3.0f;
        axis.z = 1.0f;
        func_00389158(p, p, &axis, *(f32 *)(self + 0xF8) + -0.7853982f + (f32)i * 1.5707964f);
        axis.z = 0.0f;
        if (*(f32 *)(self + 0xF4) != 0.0f) {
            axis.y = 1.0f;
            func_00389158(p, p, &axis, *(f32 *)(self + 0xF4));
            axis.y = 0.0f;
            p->x += 0.3f;
            p->y += 0.3f;
        }
        vec_add_ab(p, p, self + 0x10);
    }
    self[0x20] = d[0xB] ? 2 : 1;
    self[0x30] = 0xFF;
    *(s16 *)d = *(u16 *)(d + 8);
}
/* localdecomp:end func_L02_0039DA50 */
