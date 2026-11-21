/* functional: high. PAL port of the NTSC-U draft: callees renamed to PAL addresses (0038CED8, 0038D160, 0038CE20, 0013D528); constants 0.15, 0.8726646 (50 deg) and 0.0432 read from the PAL assembly (NTSC-U used 0.03). */
#include "vu0.h"

typedef struct V_00633748 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00633748;

extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_0013D528(void *, void *);
extern void func_0038CE20(void *, void *, f32);

void func_L39_00633748(u8 *o) {
    V_00633748 v;
    f32 f;

    if (*(s16 *)(o + 0x2DE) == 0) {
        return;
    }
    if (!(*(f32 *)(o + 0x2AC) < 0.15f)) {
        return;
    }
    if (!(0.0f < *(f32 *)(o + 0x148))) {
        return;
    }
    if (o[0x216] == 0) {
        return;
    }
    if (!(0.0f < *(f32 *)(o + 0x1C8))) {
        return;
    }
    f = func_0038D160(*(f32 *)(o + 0x1C8), func_0038CED8(o + 0x1C0));
    if (0.87266463f <= f) {
        *(u128_t *)&v = *(u128_t *)(o + 0x1C0);
        v.z = 0.0f;
        func_0013D528(&v, &v);
        f = -*(f32 *)(o + 0x120) * v.x - *(f32 *)(o + 0x124) * v.y;
        if (0.0f < f) {
            func_0038CE20(&v, &v, f);
            vec_add_ab(o + 0x120, o + 0x120, &v);
            *(f32 *)(o + 0x128) = *(f32 *)(o + 0x128) - 0.0432f;
        }
    }
}
