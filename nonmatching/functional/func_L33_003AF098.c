/* functional: high. Verified against PAL asm: 4 timed noise samples (func_L03_0034B440) feeding colour/UV lerps, every gp global and offset checked. Differs from retail only in FPU register for (s32)f and constant stores (148 diffs). */
#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 D_L33_001DF6C0;
extern f32 D_L33_001DEE14;
extern f32 D_L33_001DEE10;
extern f32 D_L33_001DEE0C;
extern f32 D_L33_001DEE08;
extern f32 D_L33_001DEE04;
extern s32 D_L33_001DEE1C;
extern s32 D_L33_001DEE50;
extern s32 D_L33_001DEE4C;
extern s32 D_L33_001DEE5C;
extern s32 D_L33_001DEE58;
extern f32 D_L33_001DEE18;
extern f32 D_L33_001DEE30;
extern f32 D_L33_001DEE2C;
extern f32 D_L33_001DEE28;
extern f32 D_L33_001DEE24;
extern f32 D_L33_001DEE20;
extern f32 D_L33_001DEE44;
extern f32 D_L33_001DEE40;
extern f32 D_L33_001DEE3C;
extern f32 D_L33_001DEE38;
extern f32 D_L33_001DEE34;
extern f32 D_L33_001E21BC[];
extern f32 D_L33_001E21C0[];
extern f32 D_L33_001E21AC[];
extern f32 D_L33_001E21B0[];
extern f32 D_L33_001E21B4[];
extern f32 D_L33_001E21B8[];

void func_L33_003AF098(char *obj) {
    char *p = *(char **)(obj + 0x68);
    u128_t a = *(u128_t *)p;
    u128_t b = *(u128_t *)(p + 0x10);
    f32 f;

    *(u128_t *)(p + 0x30) = a;
    *(u128_t *)(p + 0x40) = b;
    f = *(f32 *)(p + 0xE4) + func_L03_0034B440(0, 0, 5, (f32)D_L33_001DF6C0, D_L33_001DEE14, 1.0f);
    f -= (f32)(s32)f;
    D_L33_001E21BC[0] = func_003C4088(D_L33_001DEE10, D_L33_001DEE0C, f);
    D_L33_001E21C0[0] = func_003C4088(D_L33_001DEE08, D_L33_001DEE04, f);
    f = *(f32 *)(p + 0xE0) + func_L03_0034B440(0, 0, 5, (f32)D_L33_001DF6C0, (f32)D_L33_001DEE1C, 1.0f);
    f -= (f32)(s32)f;
    *(s32 *)(p + 0x50) = func_0038DBD8(D_L33_001DEE50, D_L33_001DEE4C, f);
    *(s32 *)(p + 0x58) = func_0038DBD8(D_L33_001DEE5C, D_L33_001DEE58, f);
    f += D_L33_001DEE18;
    f -= (f32)(s32)f;
    *(s32 *)(p + 0x54) = func_0038DBD8(D_L33_001DEE50, D_L33_001DEE4C, f);
    *(s32 *)(p + 0x5C) = func_0038DBD8(D_L33_001DEE5C, D_L33_001DEE58, f);
    f = *(f32 *)(p + 0xEC) + func_L03_0034B440(0, 0, 5, (f32)D_L33_001DF6C0, D_L33_001DEE30, 1.0f);
    f -= (f32)(s32)f;
    D_L33_001E21AC[0] = func_003C4088(D_L33_001DEE2C, D_L33_001DEE28, f);
    D_L33_001E21B0[0] = func_003C4088(D_L33_001DEE24, D_L33_001DEE20, f);
    f = *(f32 *)(p + 0xEC) + func_L03_0034B440(0, 0, 5, (f32)D_L33_001DF6C0, D_L33_001DEE44, 1.0f);
    f -= (f32)(s32)f;
    D_L33_001E21B4[0] = func_003C4088(D_L33_001DEE40, D_L33_001DEE3C, f);
    D_L33_001E21B8[0] = func_003C4088(D_L33_001DEE38, D_L33_001DEE34, f);
}
