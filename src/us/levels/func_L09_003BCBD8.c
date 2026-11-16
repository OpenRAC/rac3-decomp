#include "common.h"

/* NTSC-U counterpart of func_L09_003BE450 (src/levels/09_tyhrranosis/L09_003BE450.c) */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
extern s32 func_003883C8(void *);
extern f32 func_003BE6A8(f32, f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_003BEA80(void *, void *);

/* localdecomp:start func_L09_003BCBD8 */
extern s32 func_003883C8(void *);
extern f32 func_00389468(f32, f32);
extern f32 func_003BE6A8(f32, f32, f32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_L01_00445758(void *, void *, s32, f32, f32, f32, f32);
extern void func_003BEA80(void *, void *);
extern u128_t D_L09_001D66B0_003BCBD8;

s32 func_L09_003BCBD8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 v[4];
    if (p[0xD41] == 1) {
        p[0xD41] = 2;
        *(s16 *)(p + 0xD3A) = 60;
        *(f32 *)(p + 0xD3C) = 0.016666668f;
    }
    if (func_003883C8(p + 0xD3A) != 0 && func_00389468(*(f32 *)(p + 0xCDC), 0.0f) < 0.017453292f ||
        p[0xD41] == 0) {
        p[0xD41] = 0;
        return 1;
    }
    if (p[0xD41] == 2) {
        *(f32 *)(p + 0xC30) = func_003BE6A8(0.0f, -(*(f32 *)(a0 + 0x18) - 332.0f + -2.0f),
                                            (f32)*(s16 *)(p + 0xD3A) * *(f32 *)(p + 0xD3C));
        func_003886E8(p + 0xC30, p + 0xC30, 1024.0f);
        *(u128_t *)v = D_L09_001D66B0_003BCBD8;
        v[1] = 0.0f;
        v[0] = *(f32 *)(p + 0xCDC);
        func_L01_00445758(v, p + 0xCD8, 0, 0.0f, 0.0034906587097793818f, 0.0034906587097793818f, 0.41887906193733215f);
        *(f32 *)(p + 0xCDC) = v[0];
        func_003BEA80(p + 0xC50, v);
    }
    return 0;
}
/* localdecomp:end func_L09_003BCBD8 */
