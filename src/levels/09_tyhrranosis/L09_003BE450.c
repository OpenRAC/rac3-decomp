#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L09_003BE330.c, which this file was cut from */
extern s32 func_0038CB00(void *);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C3FC0(void *, void *);

/* localdecomp:start func_L09_003BE450 */
extern s32 func_0038CB00(void *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern void func_003C3FC0(void *, void *);
extern u128_t D_001D66B0;

s32 func_L09_003BE450(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 v[4];
    if (p[0xD41] == 1) {
        p[0xD41] = 2;
        *(s16 *)(p + 0xD3A) = 50;
        *(f32 *)(p + 0xD3C) = 0.02f;
    }
    if (func_0038CB00(p + 0xD3A) != 0 && func_0038DBA0(*(f32 *)(p + 0xCDC), 0.0f) < 0.017453292f ||
        p[0xD41] == 0) {
        p[0xD41] = 0;
        return 1;
    }
    if (p[0xD41] == 2) {
        *(f32 *)(p + 0xC30) = func_003C3BE8(0.0f, -(*(f32 *)(a0 + 0x18) - 332.0f + -2.0f),
                                            (f32)*(s16 *)(p + 0xD3A) * *(f32 *)(p + 0xD3C));
        func_0038CE20(p + 0xC30, p + 0xC30, 1024.0f);
        *(u128_t *)v = D_001D66B0;
        v[1] = 0.0f;
        v[0] = *(f32 *)(p + 0xCDC);
        func_L01_00448890(v, p + 0xCD8, 0, 0.0f, 0.00502654864f, 0.00502654864f, 0.50265485f);
        *(f32 *)(p + 0xCDC) = v[0];
        func_003C3FC0(p + 0xC50, v);
    }
    return 0;
}
/* localdecomp:end func_L09_003BE450 */
