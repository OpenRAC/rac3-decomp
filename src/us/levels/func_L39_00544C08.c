#include "common.h"

/* NTSC-U counterpart of func_L39_00545498 (src/levels/shared/L39_00545498.c) */
/* localdecomp:start func_L39_00544C08 */
#include "vu0.h"

extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_0044B920(void *, void *, void *, f32, f32, f32);
extern void func_L18_0045DD38(void *, void *, void *, f32, f32, f32);

void func_L39_00544C08(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 t;

    *(f32 *)(s + 0x358) = func_00389380(*(f32 *)(s + 0x358), 0.02036217600107193f);
    t = func_00388978(*(f32 *)(s + 0x358)) * 0.02f;
    *(f32 *)(s + 0x35C) = t;
    if (*(s32 *)(s + 0x3BC) != 0) {
        vu0_v4 old;
        *(f32 *)(a0 + 0x18) = *(f32 *)(s + 0x368) + t;
        old = *(vu0_v4 *)(a0 + 0xF0);
        func_L01_0044B920(a0, s + 0x360, s + 0x364, 0.02617994f, 0.008144870400428772f, 0.03723369166254997f);
        if (*(s32 *)(*(u8 **)(s + 0x384) + 0x2D8) != 0) {
            *(f32 *)(a0 + 0xF0) = func_00389380(*(f32 *)(a0 + 0xF0), old.x);
            *(f32 *)(a0 + 0xF4) = func_00389380(*(f32 *)(a0 + 0xF4), old.y);
        }
    } else {
        vu0_v4 tmp;
        vu0_q qa, qb;
        func_003886E8(&tmp, s + 0x3C0, t);
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(s + 0x420)));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(tmp));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(a0 + 0x10)) : "j"(qa));
        func_L18_0045DD38(a0, s + 0x360, s + 0x364, 0.02617994f, 0.008144870400428772f, 0.03723369166254997f);
    }
}
/* localdecomp:end func_L39_00544C08 */
