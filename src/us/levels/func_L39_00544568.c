#include "common.h"

/* NTSC-U counterpart of func_L39_00544DF8 (src/levels/shared/L39_00544580.c) */
#include "vu0.h"

/* localdecomp:start func_L39_00544568 */
typedef int u128_00544DF8 __attribute__((mode(TI)));
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) V_00544DF8;

extern f32 func_003893C8(f32, f32);
extern void func_003BDA38(void *, s32, void *);
extern void func_003BF6A8(void *, f32);
extern f32 func_L39_005B2510(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_L39_005CD310(void *, void *, void *, void *, s32);
extern void func_003886E8(void *, void *, f32);
__asm__(".extern D_L39_0024AFF0_00544568, 8");
extern V_00544DF8 D_L39_0024AFF0_00544568[][3] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B020_00544568, 4");
extern f32 D_L39_0024B020_00544568;
__asm__(".extern D_L39_0024B024, 4");
extern f32 D_L39_0024B024;
__asm__(".extern D_L39_0024B028, 4");
extern f32 D_L39_0024B028;
__asm__(".extern D_L39_0024B02C, 4");
extern f32 D_L39_0024B02C;
__asm__(".extern D_L39_0024B030, 4");
extern f32 D_L39_0024B030;

void func_L39_00544568(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    f32 a;
    f32 b;
    f32 s;
    s32 i;
    s32 k;
    V_00544DF8 vec;
    V_00544DF8 v1;
    V_00544DF8 v2;
    V_00544DF8 v3;
    V_00544DF8 v4;

    a = func_003893C8(*(f32 *)(a0 + 0xF4), *(f32 *)(st + 0x2C4));
    b = *(f32 *)(st + 0x2C8);
    *(u128_00544DF8 *)&vec = 0;
    s = *(f32 *)(*(u8 **)(st + 0x384) + 0x310) / 0.40000003576278687f;
    if (s > 1.0f) {
        s = 1.0f;
    } else if (s < 0.5f) {
        s = 0.5f;
    }
    k = 0;
    for (i = 0; i < 2; i++) {
        func_003BDA38(a0, i == 0 ? 6 : 7, &v1);
        v1.v[3] = 0.0f;
        *(u128_00544DF8 *)&v2 = *(u128_00544DF8 *)&v1;
        *(u128_00544DF8 *)&v3 = *(u128_00544DF8 *)&v1;
        *(u128_00544DF8 *)&v4 = *(u128_00544DF8 *)&v1;
        func_003BF6A8(&v2, D_L39_0024B020_00544568);
        func_003BF6A8(&v3, D_L39_0024B020_00544568);
        func_003BF6A8(&v4, D_L39_0024B020_00544568);
        func_0037E4B8(&vec, -(func_L39_005B2510(D_L39_0024B024, D_L39_0024B028) * 0.0166666675f) * s, b, a);
        func_L39_005CD310(a0, &v2, &vec, &D_L39_0024AFF0_00544568[k][0], 1);
        func_003886E8(&vec, &vec, func_L39_005B2510(D_L39_0024B02C, D_L39_0024B030));
        func_L39_005CD310(a0, &v3, &vec, &D_L39_0024AFF0_00544568[k][1], 1);
        func_003886E8(&vec, &vec, func_L39_005B2510(D_L39_0024B02C, D_L39_0024B030));
        func_L39_005CD310(a0, &v4, &vec, &D_L39_0024AFF0_00544568[k][2], 1);
    }
}
/* localdecomp:end func_L39_00544568 */
