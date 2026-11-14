#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00545498);

/* localdecomp:start func_L39_005455C8 */
#include "vu0.h"

extern f32 D_L39_0024AECC;
__asm__(".extern D_L39_0024AECC, 4");
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_L39_00537998(void *, void *, void *, void *, s32, u32);
extern s32 func_L39_0066E010(void *, s32, void *, s32, void *);

void func_L39_005455C8(u8 *o, u8 *v, u32 t) {
    u8 *ex;
    u8 *r;
    f32 p[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 f;
    f32 spd;
    f32 s;
    f32 *dp;

    ex = *(u8 **)(o + 0x68);
    if (*(s32 *)(*(u8 **)(ex + 0x384) + 0x2DC) != 0) {
        func_003C2F58(o, ex[0x381] + 0xD, p);
        f = p[2] - ((f32 *)v)[2];
        vec_sub_ba(d, v, p);
        d[2] = 0.0f;
        spd = sqrt_asm((f + f) / D_L39_0024AECC);
        f = func_0038CEA8(d);
        s = f / spd;
        if (0.0f < f) {
            s = s / f;
            func_0038CE20(d, d, s);
        } else {
            qzero(d);
        }
        r = func_L39_00537998(o, *(u8 **)(*(u8 **)(ex + 0x384) + 0x2DC), p, d, 1, t);
        if (r != 0) {
            if (t == 0xFFFFFFFF) {
                if (*(s32 *)(*(u8 **)(ex + 0x384) + 0x2DC) != 0) {
                    *(s32 *)(*(u8 **)(r + 0x68) + 0x74) = func_L39_0066E010(*(u8 **)(*(u8 **)(ex + 0x384) + 0x2DC), 9, r, 0, v);
                }
                *(s32 *)(ex + 0x3B8) = 0x25;
            }
            ex[0x381] ^= 1;
        }
    }
}
/* localdecomp:end func_L39_005455C8 */
