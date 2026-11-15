#include "common.h"

/* localdecomp:start func_L39_00545498 */
#include "vu0.h"

extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0044EBA0(void *, void *, void *, f32, f32, f32);
extern void func_L18_004614F8(void *, void *, void *, f32, f32, f32);

void func_L39_00545498(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 t;

    *(f32 *)(s + 0x358) = func_0038DAB8(*(f32 *)(s + 0x358), 0.024434611f);
    t = func_0038D0B0(*(f32 *)(s + 0x358)) * 0.02f;
    *(f32 *)(s + 0x35C) = t;
    if (*(s32 *)(s + 0x3BC) != 0) {
        vu0_v4 old;
        *(f32 *)(a0 + 0x18) = *(f32 *)(s + 0x368) + t;
        old = *(vu0_v4 *)(a0 + 0xF0);
        func_L01_0044EBA0(a0, s + 0x360, s + 0x364, 0.02617994f, 0.009773845f, 0.04468043f);
        if (*(s32 *)(*(u8 **)(s + 0x384) + 0x2D8) != 0) {
            *(f32 *)(a0 + 0xF0) = func_0038DAB8(*(f32 *)(a0 + 0xF0), old.x);
            *(f32 *)(a0 + 0xF4) = func_0038DAB8(*(f32 *)(a0 + 0xF4), old.y);
        }
    } else {
        vu0_v4 tmp;
        vu0_q qa, qb;
        func_0038CE20(&tmp, s + 0x3C0, t);
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(s + 0x420)));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(tmp));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(a0 + 0x10)) : "j"(qa));
        func_L18_004614F8(a0, s + 0x360, s + 0x364, 0.02617994f, 0.009773845f, 0.04468043f);
    }
}
/* localdecomp:end func_L39_00545498 */

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
