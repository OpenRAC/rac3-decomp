#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0051C768);

/* localdecomp:start func_L39_0051CC68 */
/* from rac2-decomp's func_L04_003F9C60 */
typedef int Q_0051CC68 __attribute__((mode(TI)));
typedef union { Q_0051CC68 q; f32 f[4]; } U_0051CC68;
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005B43C8(s32, s32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_003CD250(void *);
extern void func_0038CF68_0051CC68(void *, void *, f32);
extern void func_L39_005C9A00(void *, void *, s32, s32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, s32, s32);

void func_L39_0051CC68(u8 *m, s32 sparks) {
    u8 **slot;
    s32 i = 16, j, color, sign;
    U_0051CC68 tmp;
    s32 baseColor;
    u8 *p, *d;

    slot = (u8 **)(*(u8 **)(m + 0x68) + 0x1C);
    for (; i >= 0; i--, slot++) {
        if (*slot) func_003CD250(*slot);
        *slot = 0;
    }
    if (sparks) {
        U_0051CC68 v;
        f32 *velocity = v.f;
        for (i = 4; i >= 0; i--) {
            v.q = 0;
            v.f[0] = func_L39_005B4410(-1.0f, 1.0f);
            v.f[1] = func_L39_005B4410(-1.0f, 1.0f);
            v.f[2] = func_L39_005B4410(-1.0f, 1.0f);
            tmp.q = v.q;
            func_0038CF68_0051CC68(velocity, &tmp, func_L39_005B4410(0.060000002f, 0.120000005f));
            func_L39_005C9A00(m + 0x10, velocity, 0x7F2F4F6F, func_L39_005B43C8(8, 12), 35000.0f);
        }
    }
    j = 2;
    baseColor = 0x606060;
    for (;  j >= 0; j--) {
        color = (func_L39_005B43C8(32, 128) << 24) | baseColor;
        sign = func_L39_005B4398(2) ? -1 : 1;
        tmp.q = 0;
        tmp.f[2] = 1.0f;
        tmp.f[3] = 1.0f;
        tmp.f[2] = func_L39_005B4410(0.01f, 0.025f) * 1.2f;
        p = func_L01_004669B0(m + 0x10, 0.2f, 1.0f, 1.02f, 140000.0f, sign, &tmp, color, 0);
        if (p) {
            d = p + 0x20;
            *(s16 *)(p + 0xA) = (func_L39_005B43C8(50, 80) * 5 + 2) / 6;
            *(s32 *)(d + 4) = 2;
            d[0xA] = color >> 24;
            d[0xB] = p[0xA];
            if (func_L39_005B4398(2)) p[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L39_0051CC68 */
