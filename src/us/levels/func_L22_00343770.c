#include "common.h"

/* NTSC-U counterpart of func_L22_00344050 (src/levels/22_mylon/L22_00343800.c): 75 -> 90 */
/* localdecomp:start func_L22_00343770 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00452E70(void *, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(f32 *);
extern u8 *func_00382348(s32);
extern f32 D_L22_001DD0FC;
__asm__(".extern D_L22_001DD0FC, 4");
u8 *func_L22_00343770(s32 a0, u128_t *a1, f32 *a2, s32 a3, s32 a4, s32 a5, f32 fa, f32 fb) {
    u8 *o = func_003C24B0(0xA72, 0x80);
    u8 *st;
    u8 *q;
    if (o != 0) {
        st = *(u8 **)(o + 0x68);
        func_L01_00452E70(o, a0);
        *(u128_t *)(o + 0x10) = *a1;
        *(f32 *)(o + 0xF8) = func_0038D160(a2[0], a2[1]);
        *(f32 *)(o + 0xF4) = -func_0038D160(func_0038CED8(a2), a2[2]);
        *(u128_t *)st = *(u128_t *)a2;
        *(u16 *)(st + 0x10) = 0x5A;
        *(s32 *)(st + 0x14) = a0;
        *(s32 *)(st + 0x18) = a3;
        *(s32 *)(st + 0x1C) = a4;
        *(f32 *)(st + 0x28) = fb;
        *(u16 *)(st + 0x12) = 0;
        *(f32 *)(st + 0x20) = fa;
        if (a5 != 0) {
            q = func_00382348(a5);
            if (q != 0) {
                *(u16 *)(q + 0x1E) = *(u16 *)(q + 0x1E) | 0x80;
                if (q[0xB] != 0) {
                    *(s32 *)(st + 0x24) = 0;
                } else {
                    *(s32 *)(st + 0x24) = a5;
                }
            } else {
                *(s32 *)(st + 0x24) = a5;
            }
        }
        if (fa == 1.0f) {
            *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * D_L22_001DD0FC;
        } else {
            *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * fa;
        }
    }
    return o;
}
/* localdecomp:end func_L22_00343770 */
