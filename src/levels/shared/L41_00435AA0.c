#include "common.h"

/* localdecomp:start func_L41_00435AA0 */
typedef int u128_00435AA0 __attribute__((mode(TI)));
typedef union V_00435AA0 {
    u128_00435AA0 q;
    f32 f[4];
} V_00435AA0;

extern u8 D_001DC5F8_sda;
extern f32 D_001DC5FC_sda;
__asm__(".extern D_L41_00242930, 16");
extern u8 D_L41_00242930;
extern s32 func_L01_004561B8(u8 *);
extern u8 *func_L01_00447490(u8 *, s32, s32);
extern s32 func_L39_005BE900(void *, s32, f32);
extern void func_L39_005F33E0(s32, s32, void *);
/* parameter order as func_L01_00452310 (L01_00451A68.c) declares it */
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32,
                              s32, s32, s32, s32, f32, f32, s32, s32);
extern void *func_L01_00452460(void *, s32, s32);
extern void func_003C2880(void *);

void func_L41_00435AA0(u8 *a0) {
    u8 *p;
    V_00435AA0 tmp;

    if (func_L01_004561B8(a0)) {
        a0[0x30] = D_001DC5F8_sda;
    }
    p = func_L01_00447490(a0, -1, 0);
    if (p != 0 && 5.0f <= *(f32 *)(p + 0x2C)) {
        tmp.q = *(u128_00435AA0 *)(a0 + 0x10);
        tmp.f[3] = D_001DC5FC_sda;
        if (func_L39_005BE900(&tmp, 0, (f32)D_001DC5F8_sda) >= 0) {
            func_L39_005F33E0(0, 0, a0);
            func_L01_00451FE0(a0, 0x3FFF, &D_L41_00242930, 2.0f, 4.0f, 2.0f, 4.0f, 255, 22.0f, -1.0f,
                              180, 0, 0, 35, 1.0f, 1.0f, 0, 3);
        }
        func_L01_00452460(a0, 0x1E43, 0);
        func_003C2880(a0);
    } else {
        a0[0xA8] = 0xFF;
    }
}
/* localdecomp:end func_L41_00435AA0 */
